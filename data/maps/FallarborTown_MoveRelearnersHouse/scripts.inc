FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0


FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	applywaitmovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner_Text_0
# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end


FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner_Text_0:
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Did you know?\n"
	.string "POKéMON can learn moves they forgot.\p"
	.string "Once they've learned a move,\n"
	.string "they can relearn it at any time.\p"
	.string "Isn't that neat?$"
