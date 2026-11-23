Route117_PokemonDayCare_MapScripts::
# 2 "data/maps/Route117_PokemonDayCare/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0


Route117_PokemonDayCare_EventScript_NatureOverrider::
# 6 "data/maps/Route117_PokemonDayCare/scripts.pory"
	lockall
# 7 "data/maps/Route117_PokemonDayCare/scripts.pory"
	faceplayer
# 8 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_0, MSGBOX_YESNO
# 16 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_NatureOverrider_2
# 22 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_2
# 23 "data/maps/Route117_PokemonDayCare/scripts.pory"
	special ChoosePartyMon
# 24 "data/maps/Route117_PokemonDayCare/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 25 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_0x800A, PARTY_NOTHING_CHOSEN
	goto_if_eq Route117_PokemonDayCare_EventScript_NatureOverrider_5
Route117_PokemonDayCare_EventScript_NatureOverrider_4:
# 28 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_3
# 30 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NATURES
# 31 "data/maps/Route117_PokemonDayCare/scripts.pory"
	special ShowScrollableMultichoice
# 32 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq Route117_PokemonDayCare_EventScript_NatureOverrider_8
Route117_PokemonDayCare_EventScript_NatureOverrider_7:
# 35 "data/maps/Route117_PokemonDayCare/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 36 "data/maps/Route117_PokemonDayCare/scripts.pory"
	specialvar VAR_RESULT, SetPartyMonNatureOverride
# 37 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route117_PokemonDayCare_EventScript_NatureOverrider_11
# 42 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_5
# 44 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end

Route117_PokemonDayCare_EventScript_NatureOverrider_2:
# 17 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_DeclinedNatureOverrider:
# 18 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_1
# 19 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end

Route117_PokemonDayCare_EventScript_NatureOverrider_5:
# 26 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto Route117_PokemonDayCare_EventScript_DeclinedNatureOverrider
	goto Route117_PokemonDayCare_EventScript_NatureOverrider_4

Route117_PokemonDayCare_EventScript_NatureOverrider_8:
# 33 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto Route117_PokemonDayCare_EventScript_DeclinedNatureOverrider
	goto Route117_PokemonDayCare_EventScript_NatureOverrider_7

Route117_PokemonDayCare_EventScript_NatureOverrider_11:
# 38 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_EventScript_NatureOverrider_Text_4
# 39 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
	end


# 47 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 48 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_OnTransition:
# 49 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
# 50 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_0:
# 8 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Hiya! I like to help train\n"
	.string "people's POKéMON!\p"
	.string "I can train a POKéMON's stats to\n"
	.string "match a different nature!\p"
	.string "Would you like me to help train one of\n"
	.string "your POKéMON?$"

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_1:
# 18 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Alright, maybe next time!$"

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_2:
# 22 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Great! Let's get started.$"

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_3:
# 28 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Which nature should I train its\n"
	.string "stats to match?$"

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_4:
# 38 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Sorry, I can't train that POKéMON.$"

Route117_PokemonDayCare_EventScript_NatureOverrider_Text_5:
# 42 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "All done! Its stats now match\n"
	.string "the nature you chose.$"
