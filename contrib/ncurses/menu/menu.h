begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2002,2003 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: menu.h,v 1.18 2003/11/08 20:48:24 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETI_MENU
end_ifndef

begin_define
define|#
directive|define
name|ETI_MENU
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_define
define|#
directive|define
name|TEXT
value|TEXT_ncurses
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<eti.h>
end_include

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
name|int
name|Menu_Options
typedef|;
typedef|typedef
name|int
name|Item_Options
typedef|;
comment|/* Menu options: */
define|#
directive|define
name|O_ONEVALUE
value|(0x01)
define|#
directive|define
name|O_SHOWDESC
value|(0x02)
define|#
directive|define
name|O_ROWMAJOR
value|(0x04)
define|#
directive|define
name|O_IGNORECASE
value|(0x08)
define|#
directive|define
name|O_SHOWMATCH
value|(0x10)
define|#
directive|define
name|O_NONCYCLIC
value|(0x20)
comment|/* Item options: */
define|#
directive|define
name|O_SELECTABLE
value|(0x01)
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
name|unsigned
name|short
name|length
decl_stmt|;
block|}
name|TEXT
typedef|;
typedef|typedef
struct|struct
name|tagITEM
block|{
name|TEXT
name|name
decl_stmt|;
comment|/* name of menu item                         */
name|TEXT
name|description
decl_stmt|;
comment|/* description of item, optional in display  */
name|struct
name|tagMENU
modifier|*
name|imenu
decl_stmt|;
comment|/* Pointer to parent menu                    */
name|void
modifier|*
name|userptr
decl_stmt|;
comment|/* Pointer to user defined per item data     */
name|Item_Options
name|opt
decl_stmt|;
comment|/* Item options                              */
name|short
name|index
decl_stmt|;
comment|/* Item number if connected to a menu        */
name|short
name|y
decl_stmt|;
comment|/* y and x location of item in menu          */
name|short
name|x
decl_stmt|;
name|bool
name|value
decl_stmt|;
comment|/* Selection value                           */
name|struct
name|tagITEM
modifier|*
name|left
decl_stmt|;
comment|/* neighbor items                            */
name|struct
name|tagITEM
modifier|*
name|right
decl_stmt|;
name|struct
name|tagITEM
modifier|*
name|up
decl_stmt|;
name|struct
name|tagITEM
modifier|*
name|down
decl_stmt|;
block|}
name|ITEM
typedef|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|Menu_Hook
function_decl|)
parameter_list|(
name|struct
name|tagMENU
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|tagMENU
block|{
name|short
name|height
decl_stmt|;
comment|/* Nr. of chars high               */
name|short
name|width
decl_stmt|;
comment|/* Nr. of chars wide               */
name|short
name|rows
decl_stmt|;
comment|/* Nr. of items high               */
name|short
name|cols
decl_stmt|;
comment|/* Nr. of items wide               */
name|short
name|frows
decl_stmt|;
comment|/* Nr. of formatted items high     */
name|short
name|fcols
decl_stmt|;
comment|/* Nr. of formatted items wide     */
name|short
name|arows
decl_stmt|;
comment|/* Nr. of items high (actual)      */
name|short
name|namelen
decl_stmt|;
comment|/* Max. name length                */
name|short
name|desclen
decl_stmt|;
comment|/* Max. description length         */
name|short
name|marklen
decl_stmt|;
comment|/* Length of mark, if any          */
name|short
name|itemlen
decl_stmt|;
comment|/* Length of one item              */
name|short
name|spc_desc
decl_stmt|;
comment|/* Spacing for descriptor          */
name|short
name|spc_cols
decl_stmt|;
comment|/* Spacing for columns             */
name|short
name|spc_rows
decl_stmt|;
comment|/* Spacing for rows                */
name|char
modifier|*
name|pattern
decl_stmt|;
comment|/* Buffer to store match chars     */
name|short
name|pindex
decl_stmt|;
comment|/* Index into pattern buffer       */
name|WINDOW
modifier|*
name|win
decl_stmt|;
comment|/* Window containing menu          */
name|WINDOW
modifier|*
name|sub
decl_stmt|;
comment|/* Subwindow for menu display      */
name|WINDOW
modifier|*
name|userwin
decl_stmt|;
comment|/* User's window                   */
name|WINDOW
modifier|*
name|usersub
decl_stmt|;
comment|/* User's subwindow                */
name|ITEM
modifier|*
modifier|*
name|items
decl_stmt|;
comment|/* array of items                  */
name|short
name|nitems
decl_stmt|;
comment|/* Nr. of items in menu            */
name|ITEM
modifier|*
name|curitem
decl_stmt|;
comment|/* Current item                    */
name|short
name|toprow
decl_stmt|;
comment|/* Top row of menu                 */
name|chtype
name|fore
decl_stmt|;
comment|/* Selection attribute             */
name|chtype
name|back
decl_stmt|;
comment|/* Nonselection attribute          */
name|chtype
name|grey
decl_stmt|;
comment|/* Inactive attribute              */
name|unsigned
name|char
name|pad
decl_stmt|;
comment|/* Pad character                   */
name|Menu_Hook
name|menuinit
decl_stmt|;
comment|/* User hooks                      */
name|Menu_Hook
name|menuterm
decl_stmt|;
name|Menu_Hook
name|iteminit
decl_stmt|;
name|Menu_Hook
name|itemterm
decl_stmt|;
name|void
modifier|*
name|userptr
decl_stmt|;
comment|/* Pointer to menus user data      */
name|char
modifier|*
name|mark
decl_stmt|;
comment|/* Pointer to marker string        */
name|Menu_Options
name|opt
decl_stmt|;
comment|/* Menu options                    */
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* Internal state of menu          */
block|}
name|MENU
typedef|;
comment|/* Define keys */
define|#
directive|define
name|REQ_LEFT_ITEM
value|(KEY_MAX + 1)
define|#
directive|define
name|REQ_RIGHT_ITEM
value|(KEY_MAX + 2)
define|#
directive|define
name|REQ_UP_ITEM
value|(KEY_MAX + 3)
define|#
directive|define
name|REQ_DOWN_ITEM
value|(KEY_MAX + 4)
define|#
directive|define
name|REQ_SCR_ULINE
value|(KEY_MAX + 5)
define|#
directive|define
name|REQ_SCR_DLINE
value|(KEY_MAX + 6)
define|#
directive|define
name|REQ_SCR_DPAGE
value|(KEY_MAX + 7)
define|#
directive|define
name|REQ_SCR_UPAGE
value|(KEY_MAX + 8)
define|#
directive|define
name|REQ_FIRST_ITEM
value|(KEY_MAX + 9)
define|#
directive|define
name|REQ_LAST_ITEM
value|(KEY_MAX + 10)
define|#
directive|define
name|REQ_NEXT_ITEM
value|(KEY_MAX + 11)
define|#
directive|define
name|REQ_PREV_ITEM
value|(KEY_MAX + 12)
define|#
directive|define
name|REQ_TOGGLE_ITEM
value|(KEY_MAX + 13)
define|#
directive|define
name|REQ_CLEAR_PATTERN
value|(KEY_MAX + 14)
define|#
directive|define
name|REQ_BACK_PATTERN
value|(KEY_MAX + 15)
define|#
directive|define
name|REQ_NEXT_MATCH
value|(KEY_MAX + 16)
define|#
directive|define
name|REQ_PREV_MATCH
value|(KEY_MAX + 17)
define|#
directive|define
name|MIN_MENU_COMMAND
value|(KEY_MAX + 1)
define|#
directive|define
name|MAX_MENU_COMMAND
value|(KEY_MAX + 17)
comment|/*  * Some AT&T code expects MAX_COMMAND to be out-of-band not  * just for menu commands but for forms ones as well.  */
if|#
directive|if
name|defined
argument_list|(
name|MAX_COMMAND
argument_list|)
if|#
directive|if
operator|(
name|MAX_MENU_COMMAND
operator|>
name|MAX_COMMAND
operator|)
error|#
directive|error
error|Something is wrong -- MAX_MENU_COMMAND is greater than MAX_COMMAND
elif|#
directive|elif
operator|(
name|MAX_COMMAND
operator|!=
operator|(
name|KEY_MAX
operator|+
literal|128
operator|)
operator|)
error|#
directive|error
error|Something is wrong -- MAX_COMMAND is already inconsistently defined.
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|MAX_COMMAND
value|(KEY_MAX + 128)
endif|#
directive|endif
comment|/* --------- prototypes for libmenu functions ----------------------------- */
extern|extern NCURSES_EXPORT(ITEM **
block|)
name|menu_items
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT(ITEM *
end_extern

begin_expr_stmt
unit|)
name|current_item
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(ITEM *
end_extern

begin_expr_stmt
unit|)
name|new_item
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(MENU *
end_extern

begin_expr_stmt
unit|)
name|new_menu
argument_list|(
name|ITEM
operator|*
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Item_Options
end_extern

begin_expr_stmt
unit|)
name|item_opts
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Menu_Options
end_extern

begin_expr_stmt
unit|)
name|menu_opts
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Menu_Hook
end_extern

begin_expr_stmt
unit|)
name|item_init
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Menu_Hook
end_extern

begin_expr_stmt
unit|)
name|item_term
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Menu_Hook
end_extern

begin_expr_stmt
unit|)
name|menu_init
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Menu_Hook
end_extern

begin_expr_stmt
unit|)
name|menu_term
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(WINDOW *
end_extern

begin_expr_stmt
unit|)
name|menu_sub
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(WINDOW *
end_extern

begin_expr_stmt
unit|)
name|menu_win
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|item_description
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|item_name
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|menu_mark
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|menu_request_name
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|menu_pattern
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|menu_userptr
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|item_userptr
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(chtype
end_extern

begin_expr_stmt
unit|)
name|menu_back
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(chtype
end_extern

begin_expr_stmt
unit|)
name|menu_fore
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(chtype
end_extern

begin_expr_stmt
unit|)
name|menu_grey
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|free_item
argument_list|(
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|free_menu
argument_list|(
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|item_count
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|item_index
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|item_opts_off
argument_list|(
name|ITEM
operator|*
argument_list|,
name|Item_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|item_opts_on
argument_list|(
name|ITEM
operator|*
argument_list|,
name|Item_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_driver
argument_list|(
name|MENU
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_opts_off
argument_list|(
name|MENU
operator|*
argument_list|,
name|Menu_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_opts_on
argument_list|(
name|MENU
operator|*
argument_list|,
name|Menu_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_pad
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|pos_menu_cursor
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|post_menu
argument_list|(
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|scale_menu
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_current_item
argument_list|(
name|MENU
operator|*
name|menu
argument_list|,
name|ITEM
operator|*
name|item
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_item_init
argument_list|(
name|MENU
operator|*
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|MENU
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_item_opts
argument_list|(
name|ITEM
operator|*
argument_list|,
name|Item_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_item_term
argument_list|(
name|MENU
operator|*
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|MENU
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_item_userptr
argument_list|(
name|ITEM
operator|*
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_item_value
argument_list|(
name|ITEM
operator|*
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_back
argument_list|(
name|MENU
operator|*
argument_list|,
name|chtype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_fore
argument_list|(
name|MENU
operator|*
argument_list|,
name|chtype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_format
argument_list|(
name|MENU
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_grey
argument_list|(
name|MENU
operator|*
argument_list|,
name|chtype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_init
argument_list|(
name|MENU
operator|*
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|MENU
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_items
argument_list|(
name|MENU
operator|*
argument_list|,
name|ITEM
operator|*
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_mark
argument_list|(
name|MENU
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_opts
argument_list|(
name|MENU
operator|*
argument_list|,
name|Menu_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_pad
argument_list|(
name|MENU
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_pattern
argument_list|(
name|MENU
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_sub
argument_list|(
name|MENU
operator|*
argument_list|,
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_term
argument_list|(
name|MENU
operator|*
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|MENU
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_userptr
argument_list|(
name|MENU
operator|*
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_win
argument_list|(
name|MENU
operator|*
argument_list|,
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_top_row
argument_list|(
name|MENU
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|top_row
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|unpost_menu
argument_list|(
name|MENU
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_request_by_name
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_menu_spacing
argument_list|(
name|MENU
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|menu_spacing
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|item_value
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|item_visible
argument_list|(
specifier|const
name|ITEM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|menu_format
argument_list|(
specifier|const
name|MENU
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETI_MENU */
end_comment

end_unit

