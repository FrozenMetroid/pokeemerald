# 1 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_MapScripts::
# 3 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
# 4 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
# 5 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnWarp:
# 8 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
# 9 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 10 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects::
# 12 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
# 14 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setobjectxy LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, 8, 7
# 15 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, DIR_SOUTH
# 16 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth::
# 17 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 18 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnFrame:
# 21 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
# 22 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom::
# 25 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
# 26 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 27 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
# 28 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
# 29 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_0x8006, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
# 31 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generaterentalmons
# 32 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 33 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 34 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 35 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 36 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 37 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 38 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 39 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 40 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 41 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 42 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_rentmons
# 43 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 44 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom::
# 45 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 47 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 48 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
# 49 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
# 50 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 6, 11
# 52 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 54 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle::
# 56 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setopponentmons
# 57 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_resethelditems
# 58 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 60 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitfanfare
# 61 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special HealPlayerParty
# 62 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 63 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
# 64 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 65 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 66 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 68 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applywaitmovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
# 69 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
# 70 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 71 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applywaitmovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
# 72 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
# 73 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 74 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	delay 16
# 75 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 76 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 77 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 78 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent::
# 79 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 80 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 81 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent::
# 82 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 83 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
# 84 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
# 85 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
# 86 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 4, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
# 87 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 5, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
# 88 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, 6, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
# 89 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 90 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 91 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 92 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 93 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 94 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 95 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 96 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 97 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 98 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 99 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord::
# 100 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 101 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 102 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 103 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 104 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 105 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 106 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle::
# 108 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
# 109 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 110 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 111 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 113 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
# 114 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 115 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 116 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle::
# 117 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 118 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 119 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 120 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge::
# 121 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 122 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 124 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
# 125 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 126 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 127 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge::
# 128 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 129 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 130 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 131 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 132 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 133 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 134 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 135 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon::
# 137 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 138 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 139 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 140 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 141 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 142 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 143 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 144 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 145 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 147 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 148 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 149 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 150 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons::
# 151 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 152 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_swapmons
# 153 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 154 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom  @ Did player keep current pokemon
# 155 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 156 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 157 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 158 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 159 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent::
# 160 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 161 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 162 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 163 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 164 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent::
# 165 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 166 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 167 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 168 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 169 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent::
# 170 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
# 171 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 172 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 173 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 174 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent::
# 175 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
# 176 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 177 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 178 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 179 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent::
# 180 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
# 181 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 182 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 183 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent::
# 185 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
# 186 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 187 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 188 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 189 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge::
# 190 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 191 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 192 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_save CHALLENGE_STATUS_PAUSED
# 193 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_SAVE
# 194 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 195 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 196 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_reset
# 197 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 198 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 199 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge::
# 200 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special SavePlayerParty
# 201 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setparties 0
# 202 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 203 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special CalculatePlayerPartyCount
# 204 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 205 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 206 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType::
# 207 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
# 208 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_NORMAL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
# 209 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIGHTING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
# 210 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FLYING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
# 211 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_POISON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
# 212 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GROUND, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
# 213 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ROCK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
# 214 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_BUG, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
# 215 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GHOST, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
# 216 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_STEEL, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
# 217 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_FIRE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
# 218 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_WATER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
# 219 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_GRASS, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
# 220 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ELECTRIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
# 221 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_PSYCHIC, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
# 222 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_ICE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
# 223 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DRAGON, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
# 224 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, TYPE_DARK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
# 225 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8005, NUMBER_OF_MON_TYPES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
# 226 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 227 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 228 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal::
# 229 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
# 230 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 231 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 232 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting::
# 233 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
# 234 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 235 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 236 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying::
# 237 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
# 238 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 239 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 240 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison::
# 241 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
# 242 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 243 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 244 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround::
# 245 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
# 246 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 247 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 248 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock::
# 249 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
# 250 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 251 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 252 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug::
# 253 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
# 254 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 255 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 256 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost::
# 257 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
# 258 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 259 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 260 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel::
# 261 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
# 262 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 263 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire::
# 265 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
# 266 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 267 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 268 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater::
# 269 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
# 270 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 271 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 272 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass::
# 273 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
# 274 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 275 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric::
# 277 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
# 278 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 279 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 280 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic::
# 281 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 283 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce::
# 285 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
# 286 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 287 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon::
# 289 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
# 290 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 291 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 292 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark::
# 293 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
# 294 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 295 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 296 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType::
# 297 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
# 298 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 299 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 300 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle::
# 301 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_NONE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
# 302 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_PREPARATION, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
# 303 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_SLOW_STEADY, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
# 304 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_ENDURANCE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
# 305 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_HIGH_RISK, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
# 306 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEAKENING, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
# 307 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
# 308 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_STYLE_WEATHER, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
# 309 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq VAR_0x8006, FACTORY_NUM_STYLES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
# 310 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 311 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained::
# 313 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
# 314 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 315 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 316 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation::
# 317 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
# 318 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 319 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 320 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady::
# 321 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
# 322 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 323 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance::
# 325 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
# 326 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 327 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk::
# 329 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
# 330 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 331 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 332 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe::
# 333 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
# 334 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 335 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 336 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict::
# 337 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
# 338 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 339 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 340 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow::
# 341 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
# 342 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 343 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 344 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible::
# 345 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
# 346 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 347 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead::
# 349 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
# 350 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 351 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 352 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
# 353 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 354 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 355 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 356 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 357 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 358 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 359 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 360 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 361 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord::
# 362 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 363 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 364 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 365 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 366 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 367 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 368 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 369 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead::
# 370 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
# 371 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 372 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 373 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 374 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 375 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 376 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50::
# 378 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
# 379 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
# 380 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 381 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen::
# 383 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_FACTORY_PRE_BATTLE_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
# 384 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
# 385 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 386 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 387 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom:
# 388 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 389 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 390 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 391 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 392 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 393 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 394 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 395 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50:
# 396 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 397 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 398 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 399 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 400 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 401 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 402 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen:
# 404 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 405 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 406 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 407 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 408 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 409 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 410 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 411 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom:
# 412 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 413 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 414 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 415 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 416 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 417 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 418 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 419 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 420 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50:
# 421 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 422 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 423 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 424 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 425 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 426 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 427 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen:
# 429 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 430 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 431 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 432 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 433 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 434 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 435 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 436 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall:
# 437 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 438 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 439 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 440 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 441 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 442 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer:
# 443 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 444 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 445 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 446 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 447 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 448 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection:
# 450 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "First, we will hold your POKéMON for\n"
# 451 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "safekeeping.\p"
# 452 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "You may then choose from our\n"
# 453 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "selection of POKéMON.$"
# 454 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons:
# 456 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you for competing!\n"
# 457 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Let us restore your POKéMON!$"
# 458 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 459 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent:
# 460 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 2nd match is next!\n"
# 461 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 462 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 463 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent:
# 464 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 3rd match is next!\n"
# 465 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 466 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent:
# 468 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 4th match is next!\n"
# 469 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 470 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 471 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent:
# 472 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 5th match is next!\n"
# 473 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 474 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 475 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent:
# 476 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 6th match is next!\n"
# 477 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 478 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 479 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent:
# 480 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Finally, the 7th match is next!\n"
# 481 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 482 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 483 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame:
# 484 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 485 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "the game?$"
# 486 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge:
# 488 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 489 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Battle Swap challenge?$"
# 490 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 491 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent:
# 492 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I've conducted a little investigation\n"
# 493 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "about your upcoming opponent.$"
# 494 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 495 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType:
# 496 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 497 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the NORMAL type.$"
# 498 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType:
# 500 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 501 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIRE type.$"
# 502 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 503 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType:
# 504 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 505 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the WATER type.$"
# 506 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType:
# 508 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 509 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ELECTRIC type.$"
# 510 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 511 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType:
# 512 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 513 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GRASS type.$"
# 514 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 515 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType:
# 516 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 517 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ICE type.$"
# 518 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 519 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType:
# 520 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 521 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIGHTING type.$"
# 522 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 523 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType:
# 524 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 525 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the POISON type.$"
# 526 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType:
# 528 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 529 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GROUND type.$"
# 530 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 531 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType:
# 532 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 533 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FLYING type.$"
# 534 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 535 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType:
# 536 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 537 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the PSYCHIC type.$"
# 538 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 539 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType:
# 540 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 541 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the BUG type.$"
# 542 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 543 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType:
# 544 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 545 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ROCK type.$"
# 546 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 547 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType:
# 548 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 549 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GHOST type.$"
# 550 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 551 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType:
# 552 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 553 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DRAGON type.$"
# 554 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 555 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType:
# 556 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 557 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DARK type.$"
# 558 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 559 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType:
# 560 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER is apparently skilled\n"
# 561 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the STEEL type.$"
# 562 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 563 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite:
# 564 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The TRAINER appears to have no clear\n"
# 565 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "favorites when it comes to type.$"
# 566 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 567 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady:
# 568 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 569 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be slow and steady.$"
# 570 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 571 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance:
# 572 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 573 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one of endurance.$"
# 574 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 575 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk:
# 576 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 577 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be high risk, high return.$"
# 578 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 579 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow:
# 580 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 581 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "depend on the battle's flow.$"
# 582 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 583 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation:
# 584 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 585 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one based on total preparation.$"
# 586 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 587 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe:
# 588 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears\n"
# 589 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "to be weakening the foe to start.$"
# 590 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 591 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible:
# 592 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 593 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be flexibly adaptable to the situation.$"
# 594 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 595 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict:
# 596 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 597 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be impossible to predict.$"
# 598 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 599 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained:
# 600 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 601 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be free-spirited and unrestrained.$"
# 602 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 603 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon:
# 604 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Before starting the battle, would you\n"
# 605 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "like to swap a POKéMON?$"
# 606 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 607 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete:
# 608 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you!\n"
# 609 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Your POKéMON swap is complete.$"
# 610 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 611 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay:
# 612 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Right this way, please!$"
# 613 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait:
# 615 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 616 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 617 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 618 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle:
# 619 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to record your latest\n"
# 620 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 621 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 622 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments:
# 623 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Excuse me! Excuse me, please!\n"
# 624 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "May I get you to wait a few moments?$"
# 625 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 626 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo:
# 627 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "…Uh-huh? What?! …Whoa!\n"
# 628 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Understood, sir! Will do!$"
# 629 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 630 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow:
# 631 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Oh, my…\n"
# 632 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Sorry to keep you waiting!\p"
# 633 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I have a message from this facility's\n"
# 634 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "boss, the FACTORY HEAD.\p"
# 635 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "He says, “We're going to do it!\n"
# 636 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Come here right now!”$"
# 637 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 638 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead:
# 639 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The FACTORY HEAD is demanding you.\n"
# 640 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you prepared to face him?$"
# 641 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 642 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead:
# 643 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I'm terribly sorry, but I can't tell you\n"
# 644 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "anything about the FACTORY HEAD.$"
