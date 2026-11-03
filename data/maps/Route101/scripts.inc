Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 5 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
	return

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0


Route101_EventScript_HideMapNamePopup::
# 11 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 12 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
	end


Route101_EventScript_StartBirchRescue::
# 17 "data/maps/Route101/scripts.pory"
	lockall
# 18 "data/maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 19 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_StartBirchRescue_Text_0
# 20 "data/maps/Route101/scripts.pory"
	closemessage
# 21 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
# 22 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
# 23 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
# 24 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
# 25 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 26 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 27 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 28 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
# 29 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 30 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 31 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 32 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 33 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_StartBirchRescue_Text_1
# 39 "data/maps/Route101/scripts.pory"
	closemessage
# 40 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 41 "data/maps/Route101/scripts.pory"
	releaseall
	end


Route101_EventScript_PreventExitSouth::
# 46 "data/maps/Route101/scripts.pory"
	lockall
# 47 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_PreventExitSouth_Text_0
# 49 "data/maps/Route101/scripts.pory"
	closemessage
# 50 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 51 "data/maps/Route101/scripts.pory"
	releaseall
	end


Route101_EventScript_PreventExitWest::
# 56 "data/maps/Route101/scripts.pory"
	lockall
# 57 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_PreventExitSouth_Text_0
# 59 "data/maps/Route101/scripts.pory"
	closemessage
# 60 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 61 "data/maps/Route101/scripts.pory"
	releaseall
	end


Route101_EventScript_PreventExitNorth::
# 66 "data/maps/Route101/scripts.pory"
	lockall
# 67 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_PreventExitSouth_Text_0
# 69 "data/maps/Route101/scripts.pory"
	closemessage
# 70 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 71 "data/maps/Route101/scripts.pory"
	releaseall
	end


Route101_Movement_PreventExitSouth::
# 76 "data/maps/Route101/scripts.pory"
	walk_up
# 77 "data/maps/Route101/scripts.pory"
	step_end
	return


Route101_Movement_PreventExitWest::
# 81 "data/maps/Route101/scripts.pory"
	walk_right
# 82 "data/maps/Route101/scripts.pory"
	step_end
	return


Route101_Movement_PreventExitNorth::
# 86 "data/maps/Route101/scripts.pory"
	walk_down
# 87 "data/maps/Route101/scripts.pory"
	step_end
	return


# 90 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 91 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 92 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 93 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 94 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 95 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 96 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 97 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 98 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 99 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 100 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 101 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 102 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 103 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 104 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 105 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 106 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 107 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 108 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 109 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 110 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 111 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 113 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 114 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 115 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 116 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 117 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 118 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 119 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 120 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 121 "data/maps/Route101/scripts.pory"
	step_end

# 124 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 125 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 126 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 127 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 128 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 129 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 130 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 131 "data/maps/Route101/scripts.pory"
	step_end

# 134 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 135 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 136 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 137 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 138 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 139 "data/maps/Route101/scripts.pory"
	step_end

# 142 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 143 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 145 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 146 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 147 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 148 "data/maps/Route101/scripts.pory"
	step_end

# 151 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 152 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 153 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 154 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 155 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 156 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 157 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 158 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 159 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 160 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 161 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 162 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 163 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 164 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 165 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 166 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 167 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 168 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 169 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 170 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 171 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 172 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 173 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 174 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 175 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 176 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 177 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 178 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 179 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 180 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 181 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 182 "data/maps/Route101/scripts.pory"
	step_end

# 185 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 186 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 187 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 188 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 189 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 190 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 191 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 192 "data/maps/Route101/scripts.pory"
	step_end

# 195 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 196 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 197 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 198 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 199 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 200 "data/maps/Route101/scripts.pory"
	step_end

# 203 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused1:
# 204 "data/maps/Route101/scripts.pory"
	walk_up
# 205 "data/maps/Route101/scripts.pory"
	walk_up
# 206 "data/maps/Route101/scripts.pory"
	step_end

# 209 "data/maps/Route101/scripts.pory"
Route101_Movement_Unused2:
# 210 "data/maps/Route101/scripts.pory"
	walk_up
# 211 "data/maps/Route101/scripts.pory"
	walk_left
# 212 "data/maps/Route101/scripts.pory"
	walk_up
# 213 "data/maps/Route101/scripts.pory"
	step_end

Route101_EventScript_Youngster::
# 217 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_Youngster_Text_0
# 222 "data/maps/Route101/scripts.pory"
	closemessage
	end


Route101_EventScript_Boy::
# 227 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_Boy_Text_0
# 232 "data/maps/Route101/scripts.pory"
	closemessage
	end


Route101_EventScript_RouteSign::
# 237 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_RouteSign_Text_0
# 239 "data/maps/Route101/scripts.pory"
	closemessage
	end


Route101_EventScript_BirchsBag::
# 244 "data/maps/Route101/scripts.pory"
	lock
# 245 "data/maps/Route101/scripts.pory"
	faceplayer
# 246 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 247 "data/maps/Route101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 248 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 249 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE101_ZIGZAGOON
# 250 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_PLAYER, 6, 13
# 251 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 252 "data/maps/Route101/scripts.pory"
	special ChooseStarter
# 253 "data/maps/Route101/scripts.pory"
	applywaitmovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchApproachPlayer
# 254 "data/maps/Route101/scripts.pory"
	msgbox Route101_EventScript_BirchsBag_Text_0
# 266 "data/maps/Route101/scripts.pory"
	special HealPlayerParty
# 267 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 268 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 269 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 270 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 271 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 272 "data/maps/Route101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 273 "data/maps/Route101/scripts.pory"
	checkplayergender
# 274 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 275 "data/maps/Route101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 276 "data/maps/Route101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 277 "data/maps/Route101/scripts.pory"
	waitstate
# 278 "data/maps/Route101/scripts.pory"
	release
	end


Route101_EventScript_HideMayInBedroom::
# 283 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return


Route101_EventScript_HideBrendanInBedroom::
# 288 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return


# 292 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 293 "data/maps/Route101/scripts.pory"
	walk_right
# 294 "data/maps/Route101/scripts.pory"
	step_end

Route101_EventScript_StartBirchRescue_Text_0:
# 19 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"

Route101_EventScript_StartBirchRescue_Text_1:
# 34 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_EventScript_PreventExitSouth_Text_0:
# 47 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_EventScript_Youngster_Text_0:
# 217 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_EventScript_Boy_Text_0:
# 227 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_EventScript_RouteSign_Text_0:
# 237 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_EventScript_BirchsBag_Text_0:
# 254 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\n"
	.string "I was in the tall grass studying wild\l"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\n"
	.string "This is not the place to chat, so come\l"
	.string "by my POKéMON LAB later, okay?$"
