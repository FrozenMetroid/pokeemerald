#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

    // Don't set Pokédex flag for MON_CANT_GIVE
    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }

    SetScriptedWildMonLearnset(&gEnemyParty[0], species); // give them their scripted learnset
}

void SetScriptedWildMonLearnset(struct Pokemon *mon, u16 species)
{
    u16 moves[MAX_MON_MOVES];
    s32 i;

    switch (species)
    {
        case SPECIES_VOLTORB: // New Mauville
        case SPECIES_ELECTRODE: // Aqua Hideout
            moves[0] = MOVE_ROLLOUT;
            moves[1] = MOVE_SHOCK_WAVE;
            moves[2] = MOVE_SONIC_BOOM;
            moves[3] = MOVE_SCREECH;
            break;
        case SPECIES_SUDOWOODO: // Battle Frontier
            moves[0] = MOVE_ROCK_SLIDE;
            moves[1] = MOVE_BODY_SLAM;
            moves[2] = MOVE_MIMIC;
            moves[3] = MOVE_BLOCK;
            break;
        case SPECIES_REGIROCK: // Desert Ruins
            moves[0] = MOVE_ROCK_SLIDE;
            moves[1] = MOVE_EARTHQUAKE;
            moves[2] = MOVE_SANDSTORM;
            moves[3] = MOVE_SUPERPOWER;
            break;
        case SPECIES_REGICE: // Island Cave
            moves[0] = MOVE_ICE_BEAM;
            moves[1] = MOVE_HAIL;
            moves[2] = MOVE_THUNDERBOLT;
            moves[3] = MOVE_SUPERPOWER;
            break;
        case SPECIES_REGISTEEL: // Ancient Tomb
            moves[0] = MOVE_METEOR_MASH;
            moves[1] = MOVE_SLAM;
            moves[2] = MOVE_IRON_DEFENSE;
            moves[3] = MOVE_SUPERPOWER;
            break;
        case SPECIES_LATIAS: // Unused
            moves[0] = MOVE_DRAGON_CLAW;
            moves[1] = MOVE_MIST_BALL;
            moves[2] = MOVE_RECOVER;
            moves[3] = MOVE_CALM_MIND;
            break;
        case SPECIES_LATIOS: // Unused
            moves[0] = MOVE_DRAGON_CLAW;
            moves[1] = MOVE_LUSTER_PURGE;
            moves[2] = MOVE_RECOVER;
            moves[3] = MOVE_CALM_MIND;
            break;
        case SPECIES_KYOGRE: // Marine Cave
            moves[0] = MOVE_WATER_PULSE;
            moves[1] = MOVE_ICE_BEAM;
            moves[2] = MOVE_CALM_MIND;
            moves[3] = MOVE_REST;
            break;
        case SPECIES_GROUDON: // Terra Cave
            moves[0] = MOVE_EARTHQUAKE;
            moves[1] = MOVE_ROCK_SLIDE;
            moves[2] = MOVE_BULK_UP;
            moves[3] = MOVE_REST;
            break;
        case SPECIES_RAYQUAZA: // Sky Pillar
            moves[0] = MOVE_DRAGON_CLAW;
            moves[1] = MOVE_AERIAL_ACE;
            moves[2] = MOVE_CRUNCH;
            moves[3] = MOVE_REST;
            break;
        case SPECIES_DEOXYS: // Unused
            moves[0] = MOVE_PSYCHIC;
            moves[1] = MOVE_RECOVER;
            moves[2] = MOVE_SWIFT;
            moves[3] = MOVE_AGILITY;
            break;
        case SPECIES_JIRACHI: // Unused
            moves[0] = MOVE_PSYCHIC;
            moves[1] = MOVE_METEOR_MASH;
            moves[2] = MOVE_REFRESH;
            moves[3] = MOVE_WISH;
            break;
        default:
            return;
    }

    for (i = 0; i < MAX_MON_MOVES; i++) {
        SetMonMoveSlot(mon, moves[i], i);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
// Allows monIndex to go out of bounds of gPlayerParty. Doesn't occur in vanilla
#ifdef BUGFIX
    if (monIndex >= PARTY_SIZE)
#else
    if (monIndex > PARTY_SIZE)
#endif
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected Pokémon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}
