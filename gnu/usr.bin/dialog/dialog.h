begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  dialog.h -- common declarations for all dialog modules  *  *  AUTHOR: Savio Lam (lam836@cs.cuhk.hk)  *  *  This program is free software; you can redistribute it and/or  *  modify it under the terms of the GNU General Public License  *  as published by the Free Software Foundation; either version 2  *  of the License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCALE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Change these if you want  */
end_comment

begin_define
define|#
directive|define
name|USE_SHADOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|USE_COLORS
value|TRUE
end_define

begin_define
define|#
directive|define
name|VERSION
value|"0.4"
end_define

begin_define
define|#
directive|define
name|ESC
value|27
end_define

begin_define
define|#
directive|define
name|TAB
value|9
end_define

begin_define
define|#
directive|define
name|MAX_LEN
value|2048
end_define

begin_define
define|#
directive|define
name|BUF_SIZE
value|(10*1024)
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x< y ? x : y)
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x> y ? x : y)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_NCURSES
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_ULCORNER
end_ifndef

begin_define
define|#
directive|define
name|ACS_ULCORNER
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_LLCORNER
end_ifndef

begin_define
define|#
directive|define
name|ACS_LLCORNER
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_URCORNER
end_ifndef

begin_define
define|#
directive|define
name|ACS_URCORNER
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_LRCORNER
end_ifndef

begin_define
define|#
directive|define
name|ACS_LRCORNER
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_HLINE
end_ifndef

begin_define
define|#
directive|define
name|ACS_HLINE
value|'-'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_VLINE
end_ifndef

begin_define
define|#
directive|define
name|ACS_VLINE
value|'|'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_LTEE
end_ifndef

begin_define
define|#
directive|define
name|ACS_LTEE
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_RTEE
end_ifndef

begin_define
define|#
directive|define
name|ACS_RTEE
value|'+'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_UARROW
end_ifndef

begin_define
define|#
directive|define
name|ACS_UARROW
value|'^'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACS_DARROW
end_ifndef

begin_define
define|#
directive|define
name|ACS_DARROW
value|'v'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NCURSES */
end_comment

begin_comment
comment|/*   * Attribute names  */
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

begin_comment
comment|/*  * Global variables  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DIALOG_MAIN__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_comment
comment|/* use colors by default? */
end_comment

begin_decl_stmt
name|bool
name|use_colors
init|=
name|USE_COLORS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shadow dialog boxes by default?    Note that 'use_shadow' implies 'use_colors' */
end_comment

begin_decl_stmt
name|bool
name|use_shadow
init|=
name|USE_SHADOW
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Attribute values, default is for mono display  */
end_comment

begin_decl_stmt
name|chtype
name|attributes
index|[]
init|=
block|{
name|A_NORMAL
block|,
comment|/* screen_attr */
name|A_NORMAL
block|,
comment|/* shadow_attr */
name|A_REVERSE
block|,
comment|/* dialog_attr */
name|A_REVERSE
block|,
comment|/* title_attr */
name|A_REVERSE
block|,
comment|/* border_attr */
name|A_BOLD
block|,
comment|/* button_active_attr */
name|A_DIM
block|,
comment|/* button_inactive_attr */
name|A_UNDERLINE
block|,
comment|/* button_key_active_attr */
name|A_UNDERLINE
block|,
comment|/* button_key_inactive_attr */
name|A_NORMAL
block|,
comment|/* button_label_active_attr */
name|A_NORMAL
block|,
comment|/* button_label_inactive_attr */
name|A_REVERSE
block|,
comment|/* inputbox_attr */
name|A_REVERSE
block|,
comment|/* inputbox_border_attr */
name|A_REVERSE
block|,
comment|/* searchbox_attr */
name|A_REVERSE
block|,
comment|/* searchbox_title_attr */
name|A_REVERSE
block|,
comment|/* searchbox_border_attr */
name|A_REVERSE
block|,
comment|/* position_indicator_attr */
name|A_REVERSE
block|,
comment|/* menubox_attr */
name|A_REVERSE
block|,
comment|/* menubox_border_attr */
name|A_REVERSE
block|,
comment|/* item_attr */
name|A_NORMAL
block|,
comment|/* item_selected_attr */
name|A_REVERSE
block|,
comment|/* tag_attr */
name|A_REVERSE
block|,
comment|/* tag_selected_attr */
name|A_NORMAL
block|,
comment|/* tag_key_attr */
name|A_BOLD
block|,
comment|/* tag_key_selected_attr */
name|A_REVERSE
block|,
comment|/* check_attr */
name|A_REVERSE
block|,
comment|/* check_selected_attr */
name|A_REVERSE
block|,
comment|/* uarrow_attr */
name|A_REVERSE
comment|/* darrow_attr */
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_decl_stmt
specifier|extern
name|bool
name|use_colors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|use_shadow
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|chtype
name|attributes
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DIALOG_MAIN__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DIALOG_MAIN__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|create_rc
parameter_list|(
name|unsigned
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_rc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DIALOG_MAIN__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|Usage
parameter_list|(
name|unsigned
name|char
modifier|*
name|name
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

begin_function_decl
name|void
name|color_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|attr_clear
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|width
parameter_list|,
name|chtype
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_autowrap
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|unsigned
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_button
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|unsigned
name|char
modifier|*
name|label
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|selected
parameter_list|)
function_decl|;
end_function_decl

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NCURSES
end_ifdef

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
name|unsigned
name|char
modifier|*
modifier|*
name|items
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
name|unsigned
name|char
modifier|*
modifier|*
name|items
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_radiolist
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
name|unsigned
name|char
modifier|*
modifier|*
name|items
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
parameter_list|)
function_decl|;
end_function_decl

end_unit

