begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  colors.h -- color attribute definitions  *  *  AUTHOR: Savio Lam (lam836@cs.cuhk.hk)  *  *  This program is free software; you can redistribute it and/or  *  modify it under the terms of the GNU General Public License  *  as published by the Free Software Foundation; either version 2  *  of the License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  *   Default color definitions  *  *   *_FG = foreground  *   *_BG = background  *   *_HL = highlight?  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_FG
value|COLOR_CYAN
end_define

begin_define
define|#
directive|define
name|SCREEN_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|SCREEN_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|SHADOW_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|SHADOW_BG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|SHADOW_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|DIALOG_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DIALOG_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DIALOG_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|TITLE_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|TITLE_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|TITLE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|BORDER_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BORDER_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BORDER_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|BUTTON_ACTIVE_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BUTTON_ACTIVE_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|BUTTON_ACTIVE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|BUTTON_INACTIVE_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|BUTTON_INACTIVE_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BUTTON_INACTIVE_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_ACTIVE_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_ACTIVE_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_ACTIVE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_INACTIVE_FG
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_INACTIVE_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BUTTON_KEY_INACTIVE_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_ACTIVE_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_ACTIVE_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_ACTIVE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_INACTIVE_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_INACTIVE_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|BUTTON_LABEL_INACTIVE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|INPUTBOX_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|INPUTBOX_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|INPUTBOX_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|INPUTBOX_BORDER_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|INPUTBOX_BORDER_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|INPUTBOX_BORDER_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_TITLE_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_TITLE_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_TITLE_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_BORDER_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_BORDER_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|SEARCHBOX_BORDER_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|POSITION_INDICATOR_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|POSITION_INDICATOR_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|POSITION_INDICATOR_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|MENUBOX_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|MENUBOX_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|MENUBOX_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|MENUBOX_BORDER_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|MENUBOX_BORDER_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|MENUBOX_BORDER_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|ITEM_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|ITEM_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|ITEM_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|ITEM_SELECTED_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|ITEM_SELECTED_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|ITEM_SELECTED_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|TAG_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|TAG_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|TAG_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|TAG_SELECTED_FG
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|TAG_SELECTED_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|TAG_SELECTED_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|TAG_KEY_FG
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|TAG_KEY_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|TAG_KEY_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|TAG_KEY_SELECTED_FG
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|TAG_KEY_SELECTED_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|TAG_KEY_SELECTED_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|CHECK_FG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|CHECK_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|CHECK_HL
value|FALSE
end_define

begin_define
define|#
directive|define
name|CHECK_SELECTED_FG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|CHECK_SELECTED_BG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|CHECK_SELECTED_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|UARROW_FG
value|COLOR_GREEN
end_define

begin_define
define|#
directive|define
name|UARROW_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|UARROW_HL
value|TRUE
end_define

begin_define
define|#
directive|define
name|DARROW_FG
value|COLOR_GREEN
end_define

begin_define
define|#
directive|define
name|DARROW_BG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DARROW_HL
value|TRUE
end_define

begin_comment
comment|/* End of default color definitions */
end_comment

begin_define
define|#
directive|define
name|C_ATTR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x ? A_BOLD : 0) | COLOR_PAIR((y)))
end_define

begin_define
define|#
directive|define
name|COLOR_NAME_LEN
value|10
end_define

begin_define
define|#
directive|define
name|COLOR_COUNT
value|8
end_define

begin_comment
comment|/*  * Global variables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|name
index|[
name|COLOR_NAME_LEN
index|]
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|color_names_st
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__DIALOG_MAIN__
end_ifdef

begin_comment
comment|/*  * For matching color names with color values  */
end_comment

begin_decl_stmt
name|color_names_st
name|color_names
index|[]
init|=
block|{
block|{
literal|"BLACK"
block|,
name|COLOR_BLACK
block|}
block|,
block|{
literal|"RED"
block|,
name|COLOR_RED
block|}
block|,
block|{
literal|"GREEN"
block|,
name|COLOR_GREEN
block|}
block|,
block|{
literal|"YELLOW"
block|,
name|COLOR_YELLOW
block|}
block|,
block|{
literal|"BLUE"
block|,
name|COLOR_BLUE
block|}
block|,
block|{
literal|"MAGENTA"
block|,
name|COLOR_MAGENTA
block|}
block|,
block|{
literal|"CYAN"
block|,
name|COLOR_CYAN
block|}
block|,
block|{
literal|"WHITE"
block|,
name|COLOR_WHITE
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color names */
end_comment

begin_comment
comment|/*  * Table of color values  */
end_comment

begin_decl_stmt
name|int
name|color_table
index|[]
index|[
literal|3
index|]
init|=
block|{
block|{
name|SCREEN_FG
block|,
name|SCREEN_BG
block|,
name|SCREEN_HL
block|}
block|,
block|{
name|SHADOW_FG
block|,
name|SHADOW_BG
block|,
name|SHADOW_HL
block|}
block|,
block|{
name|DIALOG_FG
block|,
name|DIALOG_BG
block|,
name|DIALOG_HL
block|}
block|,
block|{
name|TITLE_FG
block|,
name|TITLE_BG
block|,
name|TITLE_HL
block|}
block|,
block|{
name|BORDER_FG
block|,
name|BORDER_BG
block|,
name|BORDER_HL
block|}
block|,
block|{
name|BUTTON_ACTIVE_FG
block|,
name|BUTTON_ACTIVE_BG
block|,
name|BUTTON_ACTIVE_HL
block|}
block|,
block|{
name|BUTTON_INACTIVE_FG
block|,
name|BUTTON_INACTIVE_BG
block|,
name|BUTTON_INACTIVE_HL
block|}
block|,
block|{
name|BUTTON_KEY_ACTIVE_FG
block|,
name|BUTTON_KEY_ACTIVE_BG
block|,
name|BUTTON_KEY_ACTIVE_HL
block|}
block|,
block|{
name|BUTTON_KEY_INACTIVE_FG
block|,
name|BUTTON_KEY_INACTIVE_BG
block|,
name|BUTTON_KEY_INACTIVE_HL
block|}
block|,
block|{
name|BUTTON_LABEL_ACTIVE_FG
block|,
name|BUTTON_LABEL_ACTIVE_BG
block|,
name|BUTTON_LABEL_ACTIVE_HL
block|}
block|,
block|{
name|BUTTON_LABEL_INACTIVE_FG
block|,
name|BUTTON_LABEL_INACTIVE_BG
block|,
name|BUTTON_LABEL_INACTIVE_HL
block|}
block|,
block|{
name|INPUTBOX_FG
block|,
name|INPUTBOX_BG
block|,
name|INPUTBOX_HL
block|}
block|,
block|{
name|INPUTBOX_BORDER_FG
block|,
name|INPUTBOX_BORDER_BG
block|,
name|INPUTBOX_BORDER_HL
block|}
block|,
block|{
name|SEARCHBOX_FG
block|,
name|SEARCHBOX_BG
block|,
name|SEARCHBOX_HL
block|}
block|,
block|{
name|SEARCHBOX_TITLE_FG
block|,
name|SEARCHBOX_TITLE_BG
block|,
name|SEARCHBOX_TITLE_HL
block|}
block|,
block|{
name|SEARCHBOX_BORDER_FG
block|,
name|SEARCHBOX_BORDER_BG
block|,
name|SEARCHBOX_BORDER_HL
block|}
block|,
block|{
name|POSITION_INDICATOR_FG
block|,
name|POSITION_INDICATOR_BG
block|,
name|POSITION_INDICATOR_HL
block|}
block|,
block|{
name|MENUBOX_FG
block|,
name|MENUBOX_BG
block|,
name|MENUBOX_HL
block|}
block|,
block|{
name|MENUBOX_BORDER_FG
block|,
name|MENUBOX_BORDER_BG
block|,
name|MENUBOX_BORDER_HL
block|}
block|,
block|{
name|ITEM_FG
block|,
name|ITEM_BG
block|,
name|ITEM_HL
block|}
block|,
block|{
name|ITEM_SELECTED_FG
block|,
name|ITEM_SELECTED_BG
block|,
name|ITEM_SELECTED_HL
block|}
block|,
block|{
name|TAG_FG
block|,
name|TAG_BG
block|,
name|TAG_HL
block|}
block|,
block|{
name|TAG_SELECTED_FG
block|,
name|TAG_SELECTED_BG
block|,
name|TAG_SELECTED_HL
block|}
block|,
block|{
name|TAG_KEY_FG
block|,
name|TAG_KEY_BG
block|,
name|TAG_KEY_HL
block|}
block|,
block|{
name|TAG_KEY_SELECTED_FG
block|,
name|TAG_KEY_SELECTED_BG
block|,
name|TAG_KEY_SELECTED_HL
block|}
block|,
block|{
name|CHECK_FG
block|,
name|CHECK_BG
block|,
name|CHECK_HL
block|}
block|,
block|{
name|CHECK_SELECTED_FG
block|,
name|CHECK_SELECTED_BG
block|,
name|CHECK_SELECTED_HL
block|}
block|,
block|{
name|UARROW_FG
block|,
name|UARROW_BG
block|,
name|UARROW_HL
block|}
block|,
block|{
name|DARROW_FG
block|,
name|DARROW_BG
block|,
name|DARROW_HL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color_table */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|color_names_st
name|color_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|color_table
index|[]
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DIALOG_MAIN__ */
end_comment

end_unit

