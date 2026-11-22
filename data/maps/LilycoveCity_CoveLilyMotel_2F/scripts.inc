LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0


LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
# 4 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_GOT_SHINY_CHARM, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaWithMessage
# 5 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma_Text_0
# 14 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	giveitem ITEM_SHINY_CHARM
# 15 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_GOT_SHINY_CHARM
# 16 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma_Text_1
# 26 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaNoMessage
	end


LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaNoMessage::
# 31 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 32 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
	end


LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaWithMessage::
# 37 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaWithMessage_Text_0
# 42 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaNoMessage
	end


# 46 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 47 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 48 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
# 49 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 50 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 51 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 52 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 53 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 54 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 55 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 56 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 57 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 58 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
# 59 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 60 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 61 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 62 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
# 63 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 64 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call(Common_EventScript_PlayGymBadgeFanfare)
# 65 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 66 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 67 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 68 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 69 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 70 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 71 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 72 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 73 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 74 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 75 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 76 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 77 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 78 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 79 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 80 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 81 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 82 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 83 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 84 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 85 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 86 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 87 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 88 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 89 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 90 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 91 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 92 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 93 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 94 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 95 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 96 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 97 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 98 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 99 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 100 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 101 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 102 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 103 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 104 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 105 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 106 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 107 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 108 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 109 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 110 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 111 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 112 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 113 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 114 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 115 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 116 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 117 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 118 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 119 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 120 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 121 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 122 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 123 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 124 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 125 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 126 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 127 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 128 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 129 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 130 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 131 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 132 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 133 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 134 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 135 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 136 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 137 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 138 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 139 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 140 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 141 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 142 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 143 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 144 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 145 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 146 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 147 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 148 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 149 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 150 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 151 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 152 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 153 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 154 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 155 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 156 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 157 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 158 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 159 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 160 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma_Text_0:
# 5 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\n"
	.string "Let me give you something in\l"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma_Text_1:
# 16 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That charm is very special.\n"
	.string "It will attract rare, shiny\l"
	.string "POKéMON.\p"
	.string "If you encounter one, be sure to\n"
	.string "capture it! You might never see\l"
	.string "one like that again!\p"
	.string "By the way, I have one more thing to\n"
	.string "show you...$"

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiplomaWithMessage_Text_0:
# 37 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Congratulations on completing\n"
	.string "the POKéDEX!\p"
	.string "I have something for you to\n"
	.string "commend you for it...$"
