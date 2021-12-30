#include "constants/scrcmd.h"
	.include "asm/macros/script.inc"

	.rodata

	scrdef scr_seq_0773_T05R0401_0006 ; 000
	scrdef_end

scr_seq_0773_T05R0401_0006:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	npc_msg 0
	touchscreen_menu_hide
	getmenuchoice VAR_SPECIAL_x800C
	touchscreen_menu_show
	comparevartovalue VAR_SPECIAL_x800C, 0
	gotoif eq, scr_seq_0773_T05R0401_002E
	goto scr_seq_0773_T05R0401_00B3

scr_seq_0773_T05R0401_002C:
	.byte 0x02, 0x00
scr_seq_0773_T05R0401_002E:
	npc_msg 1
	scrcmd_049
	closemsg
	fade_screen 6, 1, 0, 0x00
	wait_fade
	scrcmd_349
	scrcmd_351 32780
	scrcmd_150
	fade_screen 6, 1, 1, 0x00
	wait_fade
	comparevartovalue VAR_SPECIAL_x800C, 255
	gotoif eq, scr_seq_0773_T05R0401_00B3
	copyvar VAR_SPECIAL_x8005, VAR_SPECIAL_x800C
	get_partymon_species VAR_SPECIAL_x8005, VAR_SPECIAL_x800C
	comparevartovalue VAR_SPECIAL_x800C, 0
	gotoif eq, scr_seq_0773_T05R0401_00BE
	partymon_is_mine VAR_SPECIAL_x8005, VAR_SPECIAL_x800C
	comparevartovalue VAR_SPECIAL_x800C, 1
	gotoif eq, scr_seq_0773_T05R0401_00C9
	bufferpartymonnick 0, VAR_SPECIAL_x8005
	npc_msg 2
	touchscreen_menu_hide
	getmenuchoice VAR_SPECIAL_x800C
	touchscreen_menu_show
	comparevartovalue VAR_SPECIAL_x800C, 0
	gotoif eq, scr_seq_0773_T05R0401_00D9
	goto scr_seq_0773_T05R0401_00B3

scr_seq_0773_T05R0401_00B1:
	.byte 0x02, 0x00
scr_seq_0773_T05R0401_00B3:
	npc_msg 5
	waitbutton
	closemsg
	releaseall
	end

scr_seq_0773_T05R0401_00BE:
	npc_msg 8
	waitbutton
	closemsg
	releaseall
	end

scr_seq_0773_T05R0401_00C9:
	bufferpartymonnick 0, VAR_SPECIAL_x8005
	npc_msg 7
	waitbutton
	closemsg
	releaseall
	end

scr_seq_0773_T05R0401_00D9:
	npc_msg 3
	closemsg
	setvar VAR_SPECIAL_x800C, 0
	fade_screen 6, 1, 0, 0x00
	wait_fade
	nickname_input VAR_SPECIAL_x8005, VAR_SPECIAL_x800C
	fade_screen 6, 1, 1, 0x00
	wait_fade
	comparevartovalue VAR_SPECIAL_x800C, 1
	gotoif eq, scr_seq_0773_T05R0401_011F
	bufferpartymonnick 0, VAR_SPECIAL_x8005
	npc_msg 4
	waitbutton
	closemsg
	releaseall
	end

scr_seq_0773_T05R0401_011F:
	bufferpartymonnick 0, VAR_SPECIAL_x8005
	npc_msg 6
	waitbutton
	closemsg
	releaseall
	end
	.balign 4, 0
