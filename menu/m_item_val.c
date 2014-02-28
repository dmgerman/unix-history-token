begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_item_val                                                        * * Set and get menus item values                                            * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_item_val.c,v 1.14 2004/12/11 23:29:34 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_item_value(ITEM *item, int value) |    |   Description   :  Programmatically set the item's selection value. This is |                    only allowed if the item is selectable at all and if |                    it is not connected to a single-valued menu. |                    If the item is connected to a posted menu, the menu |                    will be redisplayed.   | |   Return Values :  E_OK              - success |                    E_REQUEST_DENIED  - not selectable or single valued menu +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_item_value
argument_list|(
argument|ITEM * item
argument_list|,
argument|bool value
argument_list|)
end_macro

begin_block
block|{
name|MENU
modifier|*
name|menu
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_item_value(%p,%d)"
argument_list|)
operator|,
name|item
operator|,
name|value
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|menu
operator|=
name|item
operator|->
name|imenu
expr_stmt|;
if|if
condition|(
operator|(
operator|!
operator|(
name|item
operator|->
name|opt
operator|&
name|O_SELECTABLE
operator|)
operator|)
operator|||
operator|(
name|menu
operator|&&
operator|(
name|menu
operator|->
name|opt
operator|&
name|O_ONEVALUE
operator|)
operator|)
condition|)
name|RETURN
argument_list|(
name|E_REQUEST_DENIED
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|value
operator|^
name|value
condition|)
block|{
name|item
operator|->
name|value
operator|=
name|value
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
if|if
condition|(
name|menu
condition|)
block|{
if|if
condition|(
name|menu
operator|->
name|status
operator|&
name|_POSTED
condition|)
block|{
name|Move_And_Post_Item
argument_list|(
name|menu
argument_list|,
name|item
argument_list|)
expr_stmt|;
name|_nc_Show_Menu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
name|_nc_Default_Item
operator|.
name|value
operator|=
name|value
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  bool item_value(const ITEM *item) |    |   Description   :  Return the selection value of the item | |   Return Values :  TRUE   - if item is selected |                    FALSE  - if item is not selected +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|item_value
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
literal|"item_value(%p)"
argument_list|)
operator|,
name|item
operator|)
argument_list|)
expr_stmt|;
name|returnBool
argument_list|(
operator|(
name|Normalize_Item
argument_list|(
name|item
argument_list|)
operator|->
name|value
operator|)
condition|?
name|TRUE
else|:
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_item_val.c ends here */
end_comment

end_unit

