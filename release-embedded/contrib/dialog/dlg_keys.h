begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  $Id: dlg_keys.h,v 1.32 2012/12/21 21:54:30 tom Exp $  *  *  dlg_keys.h -- runtime binding support for dialog  *  *  Copyright 2005-2011,2012 Thomas E.  Dickey  *  *  This program is free software; you can redistribute it and/or modify  *  it under the terms of the GNU Lesser General Public License, version 2.1  *  as published by the Free Software Foundation.  *  *  This program is distributed in the hope that it will be useful, but  *  WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  Lesser General Public License for more details.  *  *  You should have received a copy of the GNU Lesser General Public  *  License along with this program; if not, write to  *	Free Software Foundation, Inc.  *	51 Franklin St., Fifth Floor  *	Boston, MA 02110, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DLG_KEYS_H_included
end_ifndef

begin_define
define|#
directive|define
name|DLG_KEYS_H_included
value|1
end_define

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WIDE_CURSES
end_ifdef

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_define
define|#
directive|define
name|dlg_toupper
parameter_list|(
name|ch
parameter_list|)
value|towupper((wint_t)ch)
end_define

begin_define
define|#
directive|define
name|dlg_isupper
parameter_list|(
name|ch
parameter_list|)
value|iswupper((wint_t)ch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dlg_toupper
parameter_list|(
name|ch
parameter_list|)
value|(((ch)> 0&& (ch)<= 255) ? toupper(ch) : (ch))
end_define

begin_define
define|#
directive|define
name|dlg_isupper
parameter_list|(
name|ch
parameter_list|)
value|(isalpha(ch)&& isupper(ch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
struct|struct
block|{
name|int
name|is_function_key
decl_stmt|;
name|int
name|curses_key
decl_stmt|;
name|int
name|dialog_key
decl_stmt|;
block|}
name|DLG_KEYS_BINDING
typedef|;
define|#
directive|define
name|DLG_KEYS_DATA
parameter_list|(
name|dialog
parameter_list|,
name|curses
parameter_list|)
value|{ (curses)>= KEY_MIN, curses, dialog }
define|#
directive|define
name|END_KEYS_BINDING
value|{ -1, 0, 0 }
comment|/*  * Define dialog's internal function-keys past the range used by curses.  */
typedef|typedef
enum|enum
block|{
name|DLGK_MIN
init|=
name|KEY_MAX
operator|+
literal|1
block|,
comment|/* predefined buttons */
name|DLGK_OK
block|,
name|DLGK_CANCEL
block|,
name|DLGK_EXTRA
block|,
name|DLGK_HELP
block|,
name|DLGK_ESC
block|,
comment|/* moving from screen to screen (pages) */
name|DLGK_PAGE_FIRST
block|,
name|DLGK_PAGE_LAST
block|,
name|DLGK_PAGE_NEXT
block|,
name|DLGK_PAGE_PREV
block|,
comment|/* moving within a list */
name|DLGK_ITEM_FIRST
block|,
name|DLGK_ITEM_LAST
block|,
name|DLGK_ITEM_NEXT
block|,
name|DLGK_ITEM_PREV
block|,
comment|/* moving from field to field (or buttons) */
name|DLGK_FIELD_FIRST
block|,
name|DLGK_FIELD_LAST
block|,
name|DLGK_FIELD_NEXT
block|,
name|DLGK_FIELD_PREV
block|,
comment|/* moving from form-field to form-field (or buttons) */
name|DLGK_FORM_FIRST
block|,
name|DLGK_FORM_LAST
block|,
name|DLGK_FORM_NEXT
block|,
name|DLGK_FORM_PREV
block|,
comment|/* moving within a grid */
name|DLGK_GRID_UP
block|,
name|DLGK_GRID_DOWN
block|,
name|DLGK_GRID_LEFT
block|,
name|DLGK_GRID_RIGHT
block|,
comment|/* delete */
name|DLGK_DELETE_LEFT
block|,
name|DLGK_DELETE_RIGHT
block|,
name|DLGK_DELETE_ALL
block|,
comment|/* special */
name|DLGK_ENTER
block|,
name|DLGK_BEGIN
block|,
name|DLGK_FINAL
block|,
name|DLGK_SELECT
block|,
name|DLGK_HELPFILE
block|,
name|DLGK_TRACE
block|}
name|DLG_KEYS_ENUM
typedef|;
define|#
directive|define
name|is_DLGK_MOUSE
parameter_list|(
name|code
parameter_list|)
value|((code)>= M_EVENT)
define|#
directive|define
name|DLGK_MOUSE
parameter_list|(
name|code
parameter_list|)
value|((code) + M_EVENT)
define|#
directive|define
name|HELPKEY_BINDINGS
define|\
value|DLG_KEYS_DATA( DLGK_HELPFILE,	   CHR_HELP ), \ 	DLG_KEYS_DATA( DLGK_HELPFILE,	   KEY_F(1) ), \ 	DLG_KEYS_DATA( DLGK_HELPFILE,	   KEY_HELP )
define|#
directive|define
name|ENTERKEY_BINDINGS
define|\
value|DLG_KEYS_DATA( DLGK_ENTER,	   '\n' ), \ 	DLG_KEYS_DATA( DLGK_ENTER,	   '\r' ), \ 	DLG_KEYS_DATA( DLGK_ENTER,	   KEY_ENTER )
comment|/* ^U == 21 */
define|#
directive|define
name|INPUTSTR_BINDINGS
define|\
value|DLG_KEYS_DATA( DLGK_BEGIN,	   KEY_HOME ), \ 	DLG_KEYS_DATA( DLGK_DELETE_ALL,    CHR_KILL ), \ 	DLG_KEYS_DATA( DLGK_DELETE_LEFT,   CHR_BACKSPACE ), \ 	DLG_KEYS_DATA( DLGK_DELETE_LEFT,   KEY_BACKSPACE ), \ 	DLG_KEYS_DATA( DLGK_DELETE_RIGHT,  CHR_DELETE ), \ 	DLG_KEYS_DATA( DLGK_DELETE_RIGHT,  KEY_DC ), \ 	DLG_KEYS_DATA( DLGK_FINAL,	   KEY_END ), \ 	DLG_KEYS_DATA( DLGK_GRID_LEFT,	   KEY_LEFT ), \ 	DLG_KEYS_DATA( DLGK_GRID_RIGHT,	   KEY_RIGHT )
define|#
directive|define
name|SCROLL_FKEY_BINDINGS
define|\
value|DLG_KEYS_DATA( DLGK_GRID_DOWN,	KEY_DOWN ), \ 	DLG_KEYS_DATA( DLGK_GRID_UP,	KEY_UP ), \ 	DLG_KEYS_DATA( DLGK_PAGE_FIRST,	KEY_HOME ), \ 	DLG_KEYS_DATA( DLGK_PAGE_LAST,	KEY_END ), \ 	DLG_KEYS_DATA( DLGK_PAGE_NEXT,	KEY_NPAGE ), \ 	DLG_KEYS_DATA( DLGK_PAGE_PREV,	KEY_PPAGE )
define|#
directive|define
name|SCROLLKEY_BINDINGS
define|\
value|SCROLL_FKEY_BINDINGS, \ 	DLG_KEYS_DATA( DLGK_GRID_DOWN,	'J' ), \ 	DLG_KEYS_DATA( DLGK_GRID_DOWN,	'j' ), \ 	DLG_KEYS_DATA( DLGK_GRID_UP,	'K' ), \ 	DLG_KEYS_DATA( DLGK_GRID_UP,	'k' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_FIRST,	'g' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_LAST,	'G' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_NEXT,	'F' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_NEXT,	'f' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_PREV,	'B' ), \ 	DLG_KEYS_DATA( DLGK_PAGE_PREV,	'b' )
define|#
directive|define
name|TRAVERSE_BINDINGS
define|\
value|DLG_KEYS_DATA( DLGK_ENTER,	' ' ), \ 	DLG_KEYS_DATA( DLGK_FIELD_NEXT,	KEY_DOWN ), \ 	DLG_KEYS_DATA( DLGK_FIELD_NEXT, KEY_RIGHT ), \ 	DLG_KEYS_DATA( DLGK_FIELD_NEXT, TAB ), \ 	DLG_KEYS_DATA( DLGK_FIELD_PREV,	KEY_UP ), \ 	DLG_KEYS_DATA( DLGK_FIELD_PREV, KEY_BTAB ), \ 	DLG_KEYS_DATA( DLGK_FIELD_PREV, KEY_LEFT )
specifier|extern
name|int
name|dlg_lookup_key
parameter_list|(
name|WINDOW
modifier|*
comment|/*win*/
parameter_list|,
name|int
comment|/*curses_key*/
parameter_list|,
name|int
modifier|*
comment|/*dialog_key*/
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dlg_result_key
parameter_list|(
name|int
comment|/*dialog_key*/
parameter_list|,
name|int
comment|/*fkey*/
parameter_list|,
name|int
modifier|*
comment|/*resultp*/
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dlg_register_buttons
parameter_list|(
name|WINDOW
modifier|*
comment|/*win*/
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*name*/
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
comment|/*buttons*/
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dlg_register_window
parameter_list|(
name|WINDOW
modifier|*
comment|/*win*/
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*name*/
parameter_list|,
name|DLG_KEYS_BINDING
modifier|*
comment|/*binding*/
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dlg_unregister_window
parameter_list|(
name|WINDOW
modifier|*
comment|/*win*/
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|HAVE_RC_FILE
specifier|extern
name|int
name|dlg_parse_bindkey
parameter_list|(
name|char
modifier|*
comment|/*params*/
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dlg_dump_keys
parameter_list|(
name|FILE
modifier|*
comment|/*fp*/
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dlg_dump_window_keys
parameter_list|(
name|FILE
modifier|*
comment|/*fp*/
parameter_list|,
name|WINDOW
modifier|*
comment|/*win*/
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DLG_KEYS_H_included */
end_comment

end_unit

