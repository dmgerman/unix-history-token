begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_DIALOG_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_DIALOG_H_INCLUDE
end_define

begin_comment
comment|/*  *  dialog.h -- common declarations for all dialog modules  *  *  AUTHOR: Savio Lam (lam836@cs.cuhk.hk)  *  *	Substantial rennovation:  12/18/95, Jordan K. Hubbard  *  *  This program is free software; you can redistribute it and/or  *  modify it under the terms of the GNU General Public License  *  as published by the Free Software Foundation; either version 2  *  of the License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NCURSES
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_include
include|#
directive|include
file|<cursesX.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* special return codes for `fire' actions */
end_comment

begin_define
define|#
directive|define
name|DITEM_STATUS
parameter_list|(
name|flag
parameter_list|)
value|((flag)& 0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|DITEM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|DITEM_FAILURE
value|1
end_define

begin_comment
comment|/* Flags - returned in upper 16 bits of return status */
end_comment

begin_define
define|#
directive|define
name|DITEM_LEAVE_MENU
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DITEM_REDRAW
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|DITEM_RECREATE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DITEM_RESTORE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DITEM_CONTINUE
value|(1<< 20)
end_define

begin_comment
comment|/* Attributes as used by entry fields right now */
end_comment

begin_define
define|#
directive|define
name|DITEM_NO_ECHO
value|0x0001
end_define

begin_comment
comment|/* negative offsets for buttons in item lists, if specified */
end_comment

begin_define
define|#
directive|define
name|OK_BUTTON
value|-2
end_define

begin_define
define|#
directive|define
name|CANCEL_BUTTON
value|-1
end_define

begin_comment
comment|/* for use in describing more exotic behaviors */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dmenu_item
block|{
name|char
modifier|*
name|prompt
decl_stmt|;
name|char
modifier|*
name|title
decl_stmt|;
name|int
function_decl|(
modifier|*
name|checked
function_decl|)
parameter_list|(
name|struct
name|_dmenu_item
modifier|*
name|self
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fire
function_decl|)
parameter_list|(
name|struct
name|_dmenu_item
modifier|*
name|self
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|selected
function_decl|)
parameter_list|(
name|struct
name|_dmenu_item
modifier|*
name|self
parameter_list|,
name|int
name|is_selected
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
decl_stmt|;
name|char
name|lbra
decl_stmt|,
name|mark
decl_stmt|,
name|rbra
decl_stmt|;
name|long
name|aux
decl_stmt|;
block|}
name|dialogMenuItem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VERSION
value|"0.4"
end_define

begin_define
define|#
directive|define
name|MAX_LEN
value|2048
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|DialogX
decl_stmt|,
name|DialogY
decl_stmt|,
name|DialogInputAttrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Attribute names  */
end_comment

begin_define
define|#
directive|define
name|screen_attr
value|attributes[0]
end_define

begin_define
define|#
directive|define
name|shadow_attr
value|attributes[1]
end_define

begin_define
define|#
directive|define
name|dialog_attr
value|attributes[2]
end_define

begin_define
define|#
directive|define
name|title_attr
value|attributes[3]
end_define

begin_define
define|#
directive|define
name|border_attr
value|attributes[4]
end_define

begin_define
define|#
directive|define
name|button_active_attr
value|attributes[5]
end_define

begin_define
define|#
directive|define
name|button_inactive_attr
value|attributes[6]
end_define

begin_define
define|#
directive|define
name|button_key_active_attr
value|attributes[7]
end_define

begin_define
define|#
directive|define
name|button_key_inactive_attr
value|attributes[8]
end_define

begin_define
define|#
directive|define
name|button_label_active_attr
value|attributes[9]
end_define

begin_define
define|#
directive|define
name|button_label_inactive_attr
value|attributes[10]
end_define

begin_define
define|#
directive|define
name|inputbox_attr
value|attributes[11]
end_define

begin_define
define|#
directive|define
name|inputbox_border_attr
value|attributes[12]
end_define

begin_define
define|#
directive|define
name|searchbox_attr
value|attributes[13]
end_define

begin_define
define|#
directive|define
name|searchbox_title_attr
value|attributes[14]
end_define

begin_define
define|#
directive|define
name|searchbox_border_attr
value|attributes[15]
end_define

begin_define
define|#
directive|define
name|position_indicator_attr
value|attributes[16]
end_define

begin_define
define|#
directive|define
name|menubox_attr
value|attributes[17]
end_define

begin_define
define|#
directive|define
name|menubox_border_attr
value|attributes[18]
end_define

begin_define
define|#
directive|define
name|item_attr
value|attributes[19]
end_define

begin_define
define|#
directive|define
name|item_selected_attr
value|attributes[20]
end_define

begin_define
define|#
directive|define
name|tag_attr
value|attributes[21]
end_define

begin_define
define|#
directive|define
name|tag_selected_attr
value|attributes[22]
end_define

begin_define
define|#
directive|define
name|tag_key_attr
value|attributes[23]
end_define

begin_define
define|#
directive|define
name|tag_key_selected_attr
value|attributes[24]
end_define

begin_define
define|#
directive|define
name|check_attr
value|attributes[25]
end_define

begin_define
define|#
directive|define
name|check_selected_attr
value|attributes[26]
end_define

begin_define
define|#
directive|define
name|uarrow_attr
value|attributes[27]
end_define

begin_define
define|#
directive|define
name|darrow_attr
value|attributes[28]
end_define

begin_comment
comment|/* number of attributes */
end_comment

begin_define
define|#
directive|define
name|ATTRIBUTE_COUNT
value|29
end_define

begin_decl_stmt
specifier|extern
name|chtype
name|attributes
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_decl_stmt
specifier|extern
name|bool
name|use_shadow
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|draw_shadow
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|draw_box
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|chtype
name|box
parameter_list|,
name|chtype
name|border
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|line_edit
parameter_list|(
name|WINDOW
modifier|*
name|dialog
parameter_list|,
name|int
name|box_y
parameter_list|,
name|int
name|box_x
parameter_list|,
name|int
name|flen
parameter_list|,
name|int
name|box_width
parameter_list|,
name|chtype
name|attrs
parameter_list|,
name|int
name|first
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|,
name|int
name|attr_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strheight
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strwidth
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_create_rc
parameter_list|(
name|unsigned
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_yesno
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_noyes
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_prgbox
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|line
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|pause
parameter_list|,
name|int
name|use_shell
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_msgbox
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|pause
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_textbox
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|file
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_menu
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|menu_height
parameter_list|,
name|int
name|item_no
parameter_list|,
name|void
modifier|*
name|itptr
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|,
name|int
modifier|*
name|ch
parameter_list|,
name|int
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_checklist
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|list_height
parameter_list|,
name|int
name|item_no
parameter_list|,
name|void
modifier|*
name|itptr
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_radiolist
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|list_height
parameter_list|,
name|int
name|item_no
parameter_list|,
name|void
modifier|*
name|itptr
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_inputbox
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_clear_norefresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_dialog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|end_dialog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Additions to libdialog */
end_comment

begin_function_decl
name|char
modifier|*
name|dialog_fselect
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|fmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_dselect
parameter_list|(
name|char
modifier|*
name|dir
parameter_list|,
name|char
modifier|*
name|fmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_notify
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_mesgbox
parameter_list|(
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|use_helpfile
parameter_list|(
name|char
modifier|*
name|helpfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|use_helpline
parameter_list|(
name|char
modifier|*
name|helpline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_helpline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restore_helpline
parameter_list|(
name|char
modifier|*
name|helpline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_gauge
parameter_list|(
name|char
modifier|*
name|title
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|perc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Display a tree menu from file  *  * filename	- file with like find(1) output  * FS		- fields separator  * title	- title of dialog box  * prompt	- prompt text into dialog box  * height	- height of dialog box  * width	- width of dialog box  * menu_height	- height of menu box  * result	- pointer to char array  *  * return values:  * -1		- ESC pressed  * 0		- Ok, result set (must be freed later)  * 1		- Cancel  */
end_comment

begin_function_decl
name|int
name|dialog_ftree
parameter_list|(
name|unsigned
name|char
modifier|*
name|filename
parameter_list|,
name|unsigned
name|char
name|FS
parameter_list|,
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|menu_height
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Display a tree menu from array  *  * names	- array with like find(1) output  * size		- size of array  * FS		- fields separator  * title	- title of dialog box  * prompt	- prompt text into dialog box  * height	- height of dialog box  * width	- width of dialog box  * menu_height	- height of menu box  * result	- pointer to char array  *  * return values:  * -1		- ESC pressed  * 0		- Ok, result set  * 1		- Cancel  */
end_comment

begin_function_decl
name|int
name|dialog_tree
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|names
parameter_list|,
name|int
name|size
parameter_list|,
name|unsigned
name|char
name|FS
parameter_list|,
name|unsigned
name|char
modifier|*
name|title
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|menu_height
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIALOG_H_INCLUDE */
end_comment

end_unit

