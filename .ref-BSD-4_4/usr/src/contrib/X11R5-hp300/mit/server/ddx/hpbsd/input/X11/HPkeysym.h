begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: HPkeysym.h,v 1.13 89/12/12 16:23:30 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|hpXK_ClearLine
value|0x1000FF6F
end_define

begin_define
define|#
directive|define
name|hpXK_InsertLine
value|0x1000FF70
end_define

begin_define
define|#
directive|define
name|hpXK_DeleteLine
value|0x1000FF71
end_define

begin_define
define|#
directive|define
name|hpXK_InsertChar
value|0x1000FF72
end_define

begin_define
define|#
directive|define
name|hpXK_DeleteChar
value|0x1000FF73
end_define

begin_define
define|#
directive|define
name|hpXK_BackTab
value|0x1000FF74
end_define

begin_define
define|#
directive|define
name|hpXK_KP_BackTab
value|0x1000FF75
end_define

begin_define
define|#
directive|define
name|hpXK_Modelock1
value|0x1000FF48
end_define

begin_define
define|#
directive|define
name|hpXK_Modelock2
value|0x1000FF49
end_define

begin_define
define|#
directive|define
name|hpXK_Reset
value|0x1000FF6C
end_define

begin_define
define|#
directive|define
name|hpXK_System
value|0x1000FF6D
end_define

begin_define
define|#
directive|define
name|hpXK_User
value|0x1000FF6E
end_define

begin_define
define|#
directive|define
name|hpXK_mute_acute
value|0x100000A8
end_define

begin_define
define|#
directive|define
name|hpXK_mute_grave
value|0x100000A9
end_define

begin_define
define|#
directive|define
name|hpXK_mute_asciicircum
value|0x100000AA
end_define

begin_define
define|#
directive|define
name|hpXK_mute_diaeresis
value|0x100000AB
end_define

begin_define
define|#
directive|define
name|hpXK_mute_asciitilde
value|0x100000AC
end_define

begin_define
define|#
directive|define
name|hpXK_lira
value|0x100000AF
end_define

begin_define
define|#
directive|define
name|hpXK_guilder
value|0x100000BE
end_define

begin_define
define|#
directive|define
name|hpXK_Ydiaeresis
value|0x100000EE
end_define

begin_define
define|#
directive|define
name|hpXK_IO
value|0x100000EE
end_define

begin_define
define|#
directive|define
name|hpXK_longminus
value|0x100000F6
end_define

begin_define
define|#
directive|define
name|hpXK_block
value|0x100000FC
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_OSF_Keysyms
end_ifndef

begin_define
define|#
directive|define
name|_OSF_Keysyms
end_define

begin_define
define|#
directive|define
name|osfXK_Copy
value|0x1004FF02
end_define

begin_define
define|#
directive|define
name|osfXK_Cut
value|0x1004FF03
end_define

begin_define
define|#
directive|define
name|osfXK_Paste
value|0x1004FF04
end_define

begin_define
define|#
directive|define
name|osfXK_BackTab
value|0x1004FF07
end_define

begin_define
define|#
directive|define
name|osfXK_BackSpace
value|0x1004FF08
end_define

begin_define
define|#
directive|define
name|osfXK_Clear
value|0x1004FF0B
end_define

begin_define
define|#
directive|define
name|osfXK_Escape
value|0x1004FF1B
end_define

begin_define
define|#
directive|define
name|osfXK_AddMode
value|0x1004FF31
end_define

begin_define
define|#
directive|define
name|osfXK_PrimaryPaste
value|0x1004FF32
end_define

begin_define
define|#
directive|define
name|osfXK_QuickPaste
value|0x1004FF33
end_define

begin_define
define|#
directive|define
name|osfXK_PageLeft
value|0x1004FF40
end_define

begin_define
define|#
directive|define
name|osfXK_PageUp
value|0x1004FF41
end_define

begin_define
define|#
directive|define
name|osfXK_PageDown
value|0x1004FF42
end_define

begin_define
define|#
directive|define
name|osfXK_PageRight
value|0x1004FF43
end_define

begin_define
define|#
directive|define
name|osfXK_Activate
value|0x1004FF44
end_define

begin_define
define|#
directive|define
name|osfXK_MenuBar
value|0x1004FF45
end_define

begin_define
define|#
directive|define
name|osfXK_Left
value|0x1004FF51
end_define

begin_define
define|#
directive|define
name|osfXK_Up
value|0x1004FF52
end_define

begin_define
define|#
directive|define
name|osfXK_Right
value|0x1004FF53
end_define

begin_define
define|#
directive|define
name|osfXK_Down
value|0x1004FF54
end_define

begin_define
define|#
directive|define
name|osfXK_EndLine
value|0x1004FF57
end_define

begin_define
define|#
directive|define
name|osfXK_BeginLine
value|0x1004FF58
end_define

begin_define
define|#
directive|define
name|osfXK_EndData
value|0x1004FF59
end_define

begin_define
define|#
directive|define
name|osfXK_BeginData
value|0x1004FF5A
end_define

begin_define
define|#
directive|define
name|osfXK_PrevMenu
value|0x1004FF5B
end_define

begin_define
define|#
directive|define
name|osfXK_NextMenu
value|0x1004FF5C
end_define

begin_define
define|#
directive|define
name|osfXK_PrevField
value|0x1004FF5D
end_define

begin_define
define|#
directive|define
name|osfXK_NextField
value|0x1004FF5E
end_define

begin_define
define|#
directive|define
name|osfXK_Select
value|0x1004FF60
end_define

begin_define
define|#
directive|define
name|osfXK_Insert
value|0x1004FF63
end_define

begin_define
define|#
directive|define
name|osfXK_Undo
value|0x1004FF65
end_define

begin_define
define|#
directive|define
name|osfXK_Menu
value|0x1004FF67
end_define

begin_define
define|#
directive|define
name|osfXK_Cancel
value|0x1004FF69
end_define

begin_define
define|#
directive|define
name|osfXK_Help
value|0x1004FF6A
end_define

begin_define
define|#
directive|define
name|osfXK_SelectAll
value|0x1004FF71
end_define

begin_define
define|#
directive|define
name|osfXK_DeselectAll
value|0x1004FF72
end_define

begin_define
define|#
directive|define
name|osfXK_Reselect
value|0x1004FF73
end_define

begin_define
define|#
directive|define
name|osfXK_Extend
value|0x1004FF74
end_define

begin_define
define|#
directive|define
name|osfXK_Restore
value|0x1004FF78
end_define

begin_define
define|#
directive|define
name|osfXK_Delete
value|0x1004FFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSF_Keysyms */
end_comment

begin_comment
comment|/**************************************************************  * The use of the following macros is deprecated.  * They are listed below only for backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|XK_Reset
value|0x1000FF6C
end_define

begin_define
define|#
directive|define
name|XK_System
value|0x1000FF6D
end_define

begin_define
define|#
directive|define
name|XK_User
value|0x1000FF6E
end_define

begin_define
define|#
directive|define
name|XK_ClearLine
value|0x1000FF6F
end_define

begin_define
define|#
directive|define
name|XK_InsertLine
value|0x1000FF70
end_define

begin_define
define|#
directive|define
name|XK_DeleteLine
value|0x1000FF71
end_define

begin_define
define|#
directive|define
name|XK_InsertChar
value|0x1000FF72
end_define

begin_define
define|#
directive|define
name|XK_DeleteChar
value|0x1000FF73
end_define

begin_define
define|#
directive|define
name|XK_BackTab
value|0x1000FF74
end_define

begin_define
define|#
directive|define
name|XK_KP_BackTab
value|0x1000FF75
end_define

begin_define
define|#
directive|define
name|XK_Ext16bit_L
value|0x1000FF76
end_define

begin_define
define|#
directive|define
name|XK_Ext16bit_R
value|0x1000FF77
end_define

begin_define
define|#
directive|define
name|XK_mute_acute
value|0x100000a8
end_define

begin_define
define|#
directive|define
name|XK_mute_grave
value|0x100000a9
end_define

begin_define
define|#
directive|define
name|XK_mute_asciicircum
value|0x100000aa
end_define

begin_define
define|#
directive|define
name|XK_mute_diaeresis
value|0x100000ab
end_define

begin_define
define|#
directive|define
name|XK_mute_asciitilde
value|0x100000ac
end_define

begin_define
define|#
directive|define
name|XK_lira
value|0x100000af
end_define

begin_define
define|#
directive|define
name|XK_guilder
value|0x100000be
end_define

begin_define
define|#
directive|define
name|XK_Ydiaeresis
value|0x100000ee
end_define

begin_define
define|#
directive|define
name|XK_IO
value|0x100000ee
end_define

begin_define
define|#
directive|define
name|XK_longminus
value|0x100000f6
end_define

begin_define
define|#
directive|define
name|XK_block
value|0x100000fc
end_define

end_unit

