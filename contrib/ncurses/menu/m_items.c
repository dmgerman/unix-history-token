begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_items                                                           * * Connect and disconnect items to and from menus                           * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_items.c,v 1.16 2005/01/16 01:02:23 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_items(MENU *menu, ITEM **items) |    |   Description   :  Sets the item pointer array connected to menu. | |   Return Values :  E_OK           - success |                    E_POSTED       - menu is already posted |                    E_CONNECTED    - one or more items are already connected |                                     to another menu. |                    E_BAD_ARGUMENT - An incorrect menu or item array was |                                     passed to the function +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_menu_items
argument_list|(
argument|MENU * menu
argument_list|,
argument|ITEM ** items
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_menu_items(%p,%p)"
argument_list|)
operator|,
name|menu
operator|,
name|items
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|menu
operator|||
operator|(
name|items
operator|&&
operator|!
operator|(
operator|*
name|items
operator|)
operator|)
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|menu
operator|->
name|status
operator|&
name|_POSTED
condition|)
name|RETURN
argument_list|(
name|E_POSTED
argument_list|)
expr_stmt|;
if|if
condition|(
name|menu
operator|->
name|items
condition|)
name|_nc_Disconnect_Items
argument_list|(
name|menu
argument_list|)
expr_stmt|;
if|if
condition|(
name|items
condition|)
block|{
if|if
condition|(
operator|!
name|_nc_Connect_Items
argument_list|(
name|menu
argument_list|,
name|items
argument_list|)
condition|)
name|RETURN
argument_list|(
name|E_CONNECTED
argument_list|)
expr_stmt|;
block|}
name|menu
operator|->
name|items
operator|=
name|items
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  ITEM **menu_items(const MENU *menu) |    |   Description   :  Returns a pointer to the item pointer array of the menu | |   Return Values :  NULL on error +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|ITEM **
argument_list|)
end_macro

begin_macro
name|menu_items
argument_list|(
argument|const MENU * menu
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"menu_items(%p)"
argument_list|)
operator|,
name|menu
operator|)
argument_list|)
expr_stmt|;
name|returnItemPtr
argument_list|(
name|menu
condition|?
name|menu
operator|->
name|items
else|:
operator|(
name|ITEM
operator|*
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int item_count(const MENU *menu) |    |   Description   :  Get the number of items connected to the menu. If the |                    menu pointer is NULL we return -1.          | |   Return Values :  Number of items or -1 to indicate error. +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|item_count
argument_list|(
argument|const MENU * menu
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"item_count(%p)"
argument_list|)
operator|,
name|menu
operator|)
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|menu
condition|?
name|menu
operator|->
name|nitems
else|:
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_items.c ends here */
end_comment

end_unit

