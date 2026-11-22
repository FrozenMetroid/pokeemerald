BattleFrontier_Lounge6_MapScripts::
	.byte 0


BattleFrontier_Lounge6_BottleCapGuy::
# 4 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	lockall
# 5 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	faceplayer
# 6 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_0
# 8 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	checkitem ITEM_SILVER_CAP, 1
# 9 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge6_EventScript_CheckGoldBottleCaps
# 11 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	checkitem ITEM_GOLD_CAP, 1
# 12 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge6_EventScript_ChooseBottleCap
# 14 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_TEMP_0, ITEM_SILVER_CAP
# 15 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_1
# 16 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_YesNoGiveBottleCap:
# 17 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_2, MSGBOX_YESNO
# 19 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, BattleFrontier_Lounge6_EventScript_DeclineBottleCap
# 21 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	removeitem VAR_TEMP_0, 1
# 22 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_3
# 26 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special ChoosePartyMon
# 27 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 28 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_0x800A, PARTY_NOTHING_CHOSEN
	goto_if_eq BattleFrontier_Lounge6_BottleCapGuy_2
BattleFrontier_Lounge6_BottleCapGuy_1:
# 33 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_TEMP_0, ITEM_GOLD_CAP
	goto_if_eq BattleFrontier_Lounge6_BottleCapGuy_5
# 45 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_TEMP_0, ITEM_SILVER_CAP
	goto_if_eq BattleFrontier_Lounge6_BottleCapGuy_6
# 75 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_10
# 76 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_GiveBackBottleCap
BattleFrontier_Lounge6_BottleCapGuy_4:
# 78 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_End:
# 79 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 80 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 82 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_DeclineBottleCap:
# 83 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_10
# 84 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
	end

BattleFrontier_Lounge6_BottleCapGuy_2:
# 29 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_4
# 30 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_GiveBackBottleCap
# 31 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_End
	goto BattleFrontier_Lounge6_BottleCapGuy_1

BattleFrontier_Lounge6_BottleCapGuy_5:
# 34 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bottlecapaction CHECK_ALL_IVS, VAR_0x800A, 0
# 35 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge6_BottleCapGuy_11
BattleFrontier_Lounge6_BottleCapGuy_10:
# 41 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bottlecapaction SET_ALL_IVS, VAR_0x800A, 0
# 42 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_StatTrainedJingle
# 43 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_6
# 44 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_End
	goto BattleFrontier_Lounge6_BottleCapGuy_4

BattleFrontier_Lounge6_BottleCapGuy_6:
# 46 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_7
# 48 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	multichoice 22, 0, MULTI_STAT_SELECTION, TRUE
# 49 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	switch VAR_0x8004
# 50 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 0, BattleFrontier_Lounge6_BottleCapGuy_15
# 52 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 1, BattleFrontier_Lounge6_BottleCapGuy_16
# 54 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 2, BattleFrontier_Lounge6_BottleCapGuy_17
# 56 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 3, BattleFrontier_Lounge6_BottleCapGuy_18
# 58 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 4, BattleFrontier_Lounge6_BottleCapGuy_19
# 60 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 5, BattleFrontier_Lounge6_BottleCapGuy_20
BattleFrontier_Lounge6_BottleCapGuy_13:
# 63 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bottlecapaction CHECK_SINGLE_IV, VAR_0x800A, VAR_0x8004
# 64 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge6_BottleCapGuy_21
# 69 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bottlecapaction SET_SINGLE_IV, VAR_0x800A, VAR_0x8004
# 70 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_StatTrainedJingle
# 71 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_9
# 72 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_End
	goto BattleFrontier_Lounge6_BottleCapGuy_4

BattleFrontier_Lounge6_BottleCapGuy_11:
# 36 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_5
# 38 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_GiveBackBottleCap
# 39 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_End
	goto BattleFrontier_Lounge6_BottleCapGuy_10

BattleFrontier_Lounge6_BottleCapGuy_15:
# 51 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 5
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_16:
# 53 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 4
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_17:
# 55 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 3
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_18:
# 57 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 2
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_19:
# 59 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 1
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_20:
# 61 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8004, 0
	goto BattleFrontier_Lounge6_BottleCapGuy_13

BattleFrontier_Lounge6_BottleCapGuy_21:
# 65 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_BottleCapGuy_Text_8
# 66 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	call BattleFrontier_Lounge6_EventScript_GiveBackBottleCap
# 67 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_End
	goto BattleFrontier_Lounge6_BottleCapGuy_4


BattleFrontier_Lounge6_EventScript_CheckGoldBottleCaps::
# 89 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	checkitem ITEM_GOLD_CAP, 1
# 90 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge6_EventScript_NoBottleCaps
# 92 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_TEMP_0, ITEM_GOLD_CAP
# 93 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_EventScript_CheckGoldBottleCaps_Text_0
# 94 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_YesNoGiveBottleCap
	return


BattleFrontier_Lounge6_EventScript_NoBottleCaps::
# 98 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_EventScript_NoBottleCaps_Text_0
# 100 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
	end


BattleFrontier_Lounge6_EventScript_ChooseBottleCap::
# 105 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_EventScript_ChooseBottleCap_Text_0
# 107 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	multichoice 22, 6, MULTI_BOTTLE_CAP_TYPE, TRUE
# 108 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 109 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 0, BattleFrontier_Lounge6_EventScript_ChooseBottleCap_2
# 114 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	case 1, BattleFrontier_Lounge6_EventScript_ChooseBottleCap_3
# 119 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_EventScript_ChooseBottleCap_Text_1
# 120 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
	end

BattleFrontier_Lounge6_EventScript_ChooseBottleCap_2:
# 111 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_TEMP_0, ITEM_SILVER_CAP
# 112 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_YesNoGiveBottleCap
	return

BattleFrontier_Lounge6_EventScript_ChooseBottleCap_3:
# 115 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_TEMP_0, ITEM_GOLD_CAP
# 116 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto BattleFrontier_Lounge6_EventScript_YesNoGiveBottleCap
	return


BattleFrontier_Lounge6_EventScript_StatTrainedJingle::
# 126 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 127 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	waitfanfare
	return


BattleFrontier_Lounge6_EventScript_GiveBackBottleCap::
# 137 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_GiveBackCap
# 138 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	giveitem VAR_TEMP_0, 1
	return


# 142 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 143 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 144 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_Trader::
# 145 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	lock
# 146 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	faceplayer
# 147 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
# 148 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
# 149 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 150 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 151 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 152 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
# 153 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
# 154 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special ChoosePartyMon
# 155 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 156 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
# 157 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 158 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 159 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 160 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
# 161 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 162 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 163 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special CreateInGameTradePokemon
# 164 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special DoInGameTradeScene
# 165 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
# 166 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
# 167 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 168 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 169 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 170 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_DeclineTrade::
# 171 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
# 172 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 173 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 174 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 175 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_NotRequestedMon::
# 176 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 177 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
# 178 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 179 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 180 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 181 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_TradeCompleted::
# 182 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
# 183 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 184 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 185 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 186 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
# 187 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "My POKéMON is a {STR_VAR_2}.\n"
# 188 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Do you know it?\l"
# 189 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "It's quite cute and rather nice.\p"
# 190 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "This little one, I could trade with\n"
# 191 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "pride!\p"
# 192 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Would you like to trade me a {STR_VAR_1}\n"
# 193 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "for my {STR_VAR_2}?$"
# 194 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 195 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
# 196 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, it's adorable!\n"
# 197 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Thank you!\l"
# 198 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I promise I'll be good to it!\p"
# 199 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh! I hope you'll be good to\n"
# 200 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "my {STR_VAR_2}, too!$"
# 201 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 202 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
# 203 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, I'm sorry!\n"
# 204 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I don't intend to trade for anything\l"
# 205 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "but a {STR_VAR_1}.$"
# 206 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 207 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WellThatsFineToo:
# 208 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, you won't?\n"
# 209 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Well, that's fine, too.\l"
# 210 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Please come visit us again.$"
# 211 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 212 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
# 213 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Giggle!\n"
# 214 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "A SKITTY is so much cuter than I had\l"
# 215 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "imagined. I'm delighted!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_0:
# 6 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Hello! I am a bottle cap fanatic!\n"
	.string "Have you brought me any?$"

BattleFrontier_Lounge6_BottleCapGuy_Text_1:
# 15 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Ah! You have brought me a silver cap!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_2:
# 17 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Would you like to give me the \n"
	.string "bottle cap?$"

BattleFrontier_Lounge6_BottleCapGuy_Text_3:
# 22 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Thank you! I will cherish it!\p"
	.string "Now, which POKéMON would you like me \n"
	.string "to train?$"

BattleFrontier_Lounge6_BottleCapGuy_Text_4:
# 29 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Awh, you didn't choose a POKéMON!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_5:
# 36 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Your POKéMON is already fully trained!\n"
	.string "I can't help it anymore!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_6:
# 43 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Your POKéMON has been fully trained!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_7:
# 46 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Great! I will train your POKéMON now!\n"
	.string "What stat should I train?$"

BattleFrontier_Lounge6_BottleCapGuy_Text_8:
# 65 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "This stat is already maxed out!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_9:
# 71 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Your POKéMON's stat has been trained!$"

BattleFrontier_Lounge6_BottleCapGuy_Text_10:
# 75 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, that's too bad!$"

BattleFrontier_Lounge6_EventScript_CheckGoldBottleCaps_Text_0:
# 93 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Ah! You have brought me a gold cap!$"

BattleFrontier_Lounge6_EventScript_NoBottleCaps_Text_0:
# 98 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "You haven't brought me any bottle caps.\n"
	.string "That's disappointing!$"

BattleFrontier_Lounge6_EventScript_ChooseBottleCap_Text_0:
# 105 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh! You have brought me a bottle cap!\n"
	.string "What kind is it?$"

BattleFrontier_Lounge6_EventScript_ChooseBottleCap_Text_1:
# 119 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Awh, really? No way!$"

BattleFrontier_Lounge6_Text_GiveBackCap::
# 131 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Let me give you back your\n"
	.string "bottle cap…$"
