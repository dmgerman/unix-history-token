begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_attribs                                                         * * Control menus display attributes                                         * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_attribs.c,v 1.14 2004/12/11 23:29:12 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/* Macro to redraw menu if it is posted and changed */
end_comment

begin_define
define|#
directive|define
name|Refresh_Menu
parameter_list|(
name|menu
parameter_list|)
define|\
value|if ( (menu)&& ((menu)->status& _POSTED) )\    {\       _nc_Draw_Menu( menu );\       _nc_Show_Menu( menu );\    }
end_define

begin_comment
comment|/* "Template" macro to generate a function to set a menus attribute */
end_comment

begin_define
define|#
directive|define
name|GEN_MENU_ATTR_SET_FCT
parameter_list|(
name|name
parameter_list|)
define|\
value|NCURSES_IMPEXP int NCURSES_API set_menu_ ## name (MENU * menu, chtype attr)\ {\    T((T_CALLED("set_menu_" #name "(%p,%s)"), menu, _traceattr(attr)));\    if (!(attr==A_NORMAL || (attr& A_ATTRIBUTES)==attr))\       RETURN(E_BAD_ARGUMENT);\    if (menu&& ( menu -> name != attr))\      {\        (menu -> name) = attr;\        Refresh_Menu(menu);\      }\    Normalize_Menu( menu ) -> name = attr;\    RETURN(E_OK);\ }
end_define

begin_comment
comment|/* "Template" macro to generate a function to get a menu's attribute */
end_comment

begin_define
define|#
directive|define
name|GEN_MENU_ATTR_GET_FCT
parameter_list|(
name|name
parameter_list|)
define|\
value|NCURSES_IMPEXP chtype NCURSES_API menu_ ## name (const MENU * menu)\ {\    T((T_CALLED("menu_" #name "(%p)"), menu));\    returnAttr(Normalize_Menu( menu ) -> name);\ }
end_define

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_fore(MENU *menu, chtype attr) |    |   Description   :  Set the attribute for selectable items. In single- |                    valued menus this is used to highlight the current |                    item ((i.e. where the cursor is), in multi-valued |                    menus this is used to highlight the selected items. | |   Return Values :  E_OK              - success |                    E_BAD_ARGUMENT    - an invalid value has been passed    +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_SET_FCT
argument_list|(
argument|fore
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  chtype menu_fore(const MENU* menu) |    |   Description   :  Return the attribute used for selectable items that |                    are current (single-valued menu) or selected (multi- |                    valued menu).    | |   Return Values :  Attribute value +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_GET_FCT
argument_list|(
argument|fore
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_back(MENU *menu, chtype attr) |    |   Description   :  Set the attribute for selectable but not yet selected |                    items. | |   Return Values :  E_OK             - success   |                    E_BAD_ARGUMENT   - an invalid value has been passed +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_SET_FCT
argument_list|(
argument|back
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  chtype menu_back(const MENU *menu) |    |   Description   :  Return the attribute used for selectable but not yet |                    selected items.  | |   Return Values :  Attribute value +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_GET_FCT
argument_list|(
argument|back
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_grey(MENU *menu, chtype attr) |    |   Description   :  Set the attribute for unselectable items. | |   Return Values :  E_OK             - success |                    E_BAD_ARGUMENT   - an invalid value has been passed     +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_SET_FCT
argument_list|(
argument|grey
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  chtype menu_grey(const MENU *menu) |    |   Description   :  Return the attribute used for non-selectable items | |   Return Values :  Attribute value +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|GEN_MENU_ATTR_GET_FCT
argument_list|(
argument|grey
argument_list|)
end_macro

begin_comment
comment|/* m_attribs.c ends here */
end_comment

end_unit

