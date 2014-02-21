begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  $Id: dlg_colors.h,v 1.17 2011/10/14 21:19:59 tom Exp $  *  *  colors.h -- color attribute definitions  *  *  Copyright 2000-2007,2011	Thomas E. Dickey  *  *  This program is free software; you can redistribute it and/or modify  *  it under the terms of the GNU Lesser General Public License, version 2.1  *  as published by the Free Software Foundation.  *  *  This program is distributed in the hope that it will be useful, but  *  WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  Lesser General Public License for more details.  *  *  You should have received a copy of the GNU Lesser General Public  *  License along with this program; if not, write to  *	Free Software Foundation, Inc.  *	51 Franklin St., Fifth Floor  *	Boston, MA 02110, USA.  *  *  An earlier version of this program lists as authors  *	Savio Lam (lam836@cs.cuhk.hk)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COLORS_H_included
end_ifndef

begin_define
define|#
directive|define
name|COLORS_H_included
value|1
end_define

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_comment
comment|/*  *   Default color definitions (DLGC means "Dialog Color")  *  *   DLGC_FG_xxx = foreground for "xxx"  *   DLGC_BG_xxx = background for "xxx"  *   DLGC_HL_xxx = highlight for "xxx"  */
end_comment

begin_define
define|#
directive|define
name|DLGC_FG_SCREEN
value|COLOR_CYAN
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SCREEN
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SCREEN
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_SHADOW
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SHADOW
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SHADOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_DIALOG
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_DIALOG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_DIALOG
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_TITLE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_TITLE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_TITLE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BORDER
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BORDER2
value|DLGC_FG_DIALOG
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BORDER2
value|DLGC_BG_DIALOG
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BORDER2
value|DLGC_HL_DIALOG
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_ACTIVE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_ACTIVE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_ACTIVE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_INACTIVE
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_INACTIVE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_INACTIVE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_KEY_ACTIVE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_KEY_ACTIVE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_KEY_ACTIVE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_KEY_INACTIVE
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_KEY_INACTIVE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_KEY_INACTIVE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_LABEL_ACTIVE
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_LABEL_ACTIVE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_LABEL_ACTIVE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_BUTTON_LABEL_INACTIVE
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_BUTTON_LABEL_INACTIVE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_BUTTON_LABEL_INACTIVE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_FORM_ITEM_READONLY
value|COLOR_CYAN
end_define

begin_define
define|#
directive|define
name|DLGC_BG_FORM_ITEM_READONLY
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_FORM_ITEM_READONLY
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_INPUTBOX
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_INPUTBOX
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_INPUTBOX
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_INPUTBOX_BORDER
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_INPUTBOX_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_INPUTBOX_BORDER
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_INPUTBOX_BORDER2
value|DLGC_FG_INPUTBOX
end_define

begin_define
define|#
directive|define
name|DLGC_BG_INPUTBOX_BORDER2
value|DLGC_BG_INPUTBOX
end_define

begin_define
define|#
directive|define
name|DLGC_HL_INPUTBOX_BORDER2
value|DLGC_HL_INPUTBOX
end_define

begin_define
define|#
directive|define
name|DLGC_FG_SEARCHBOX
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SEARCHBOX
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SEARCHBOX
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_SEARCHBOX_TITLE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SEARCHBOX_TITLE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SEARCHBOX_TITLE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_SEARCHBOX_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SEARCHBOX_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SEARCHBOX_BORDER
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_SEARCHBOX_BORDER2
value|DLGC_FG_SEARCHBOX
end_define

begin_define
define|#
directive|define
name|DLGC_BG_SEARCHBOX_BORDER2
value|DLGC_BG_SEARCHBOX
end_define

begin_define
define|#
directive|define
name|DLGC_HL_SEARCHBOX_BORDER2
value|DLGC_HL_SEARCHBOX
end_define

begin_define
define|#
directive|define
name|DLGC_FG_POSITION_INDICATOR
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_POSITION_INDICATOR
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_POSITION_INDICATOR
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_MENUBOX
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_MENUBOX
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_MENUBOX
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_MENUBOX_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_MENUBOX_BORDER
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_MENUBOX_BORDER
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_MENUBOX_BORDER2
value|DLGC_FG_MENUBOX
end_define

begin_define
define|#
directive|define
name|DLGC_BG_MENUBOX_BORDER2
value|DLGC_BG_MENUBOX
end_define

begin_define
define|#
directive|define
name|DLGC_HL_MENUBOX_BORDER2
value|DLGC_HL_MENUBOX
end_define

begin_define
define|#
directive|define
name|DLGC_FG_ITEM
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_ITEM
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_ITEM
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_ITEM_SELECTED
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_ITEM_SELECTED
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_ITEM_SELECTED
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_TAG
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_TAG
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_TAG
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_TAG_SELECTED
value|COLOR_YELLOW
end_define

begin_define
define|#
directive|define
name|DLGC_BG_TAG_SELECTED
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_TAG_SELECTED
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_TAG_KEY
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|DLGC_BG_TAG_KEY
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_TAG_KEY
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_TAG_KEY_SELECTED
value|COLOR_RED
end_define

begin_define
define|#
directive|define
name|DLGC_BG_TAG_KEY_SELECTED
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_TAG_KEY_SELECTED
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_CHECK
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_BG_CHECK
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_CHECK
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_CHECK_SELECTED
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_CHECK_SELECTED
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_CHECK_SELECTED
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_UARROW
value|COLOR_GREEN
end_define

begin_define
define|#
directive|define
name|DLGC_BG_UARROW
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_UARROW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_DARROW
value|COLOR_GREEN
end_define

begin_define
define|#
directive|define
name|DLGC_BG_DARROW
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_DARROW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_ITEMHELP
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_ITEMHELP
value|COLOR_BLACK
end_define

begin_define
define|#
directive|define
name|DLGC_HL_ITEMHELP
value|FALSE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_FORM_ACTIVE_TEXT
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_FORM_ACTIVE_TEXT
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_FORM_ACTIVE_TEXT
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_FORM_TEXT
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_FORM_TEXT
value|COLOR_CYAN
end_define

begin_define
define|#
directive|define
name|DLGC_HL_FORM_TEXT
value|TRUE
end_define

begin_define
define|#
directive|define
name|DLGC_FG_GAUGE
value|COLOR_BLUE
end_define

begin_define
define|#
directive|define
name|DLGC_BG_GAUGE
value|COLOR_WHITE
end_define

begin_define
define|#
directive|define
name|DLGC_HL_GAUGE
value|TRUE
end_define

begin_comment
comment|/* End of default color definitions */
end_comment

begin_comment
comment|/*  * Global variables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|color_names_st
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COLORS_H_included */
end_comment

end_unit

