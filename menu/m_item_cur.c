begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_item_cur                                                        * * Set and get current menus item                                           * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_item_cur.c,v 1.17 2004/12/25 21:57:38 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_current_item(MENU *menu, const ITEM *item) |    |   Description   :  Make the item the current item | |   Return Values :  E_OK                - success +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_current_item
argument_list|(
argument|MENU * menu
argument_list|,
argument|ITEM * item
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_current_item(%p,%p)"
argument_list|)
operator|,
name|menu
operator|,
name|item
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|menu
operator|&&
name|item
operator|&&
operator|(
name|item
operator|->
name|imenu
operator|==
name|menu
operator|)
condition|)
block|{
if|if
condition|(
name|menu
operator|->
name|status
operator|&
name|_IN_DRIVER
condition|)
name|RETURN
argument_list|(
name|E_BAD_STATE
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|menu
operator|->
name|curitem
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|!=
name|menu
operator|->
name|curitem
condition|)
block|{
if|if
condition|(
name|menu
operator|->
name|status
operator|&
name|_LINK_NEEDED
condition|)
block|{
comment|/* 	       * Items are available, but they are not linked together. 	       * So we have to link here. 	       */
name|_nc_Link_Items
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
name|menu
operator|->
name|pattern
argument_list|)
expr_stmt|;
name|Reset_Pattern
argument_list|(
name|menu
argument_list|)
expr_stmt|;
comment|/* adjust the window to make item visible and update the menu */
name|Adjust_Current_Item
argument_list|(
name|menu
argument_list|,
name|menu
operator|->
name|toprow
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  ITEM *current_item(const MENU *menu) |    |   Description   :  Return the menus current item | |   Return Values :  Item pointer or NULL if failure +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|ITEM *
argument_list|)
end_macro

begin_macro
name|current_item
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
literal|"current_item(%p)"
argument_list|)
operator|,
name|menu
operator|)
argument_list|)
expr_stmt|;
name|returnItem
argument_list|(
operator|(
name|menu
operator|&&
name|menu
operator|->
name|items
operator|)
condition|?
name|menu
operator|->
name|curitem
else|:
operator|(
name|ITEM
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int item_index(const ITEM *) |    |   Description   :  Return the logical index of this item. | |   Return Values :  The index or ERR if this is an invalid item pointer +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|item_index
argument_list|(
argument|const ITEM * item
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"item_index(%p)"
argument_list|)
operator|,
name|item
operator|)
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
operator|(
name|item
operator|&&
name|item
operator|->
name|imenu
operator|)
condition|?
name|item
operator|->
name|index
else|:
name|ERR
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_item_cur.c ends here */
end_comment

end_unit

