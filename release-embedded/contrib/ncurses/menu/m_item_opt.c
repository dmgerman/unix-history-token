begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_item_opt                                                        * * Menus item option routines                                               * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_item_opt.c,v 1.17 2004/12/25 21:32:54 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_item_opts(ITEM *item, Item_Options opts)   |    |   Description   :  Set the options of the item. If there are relevant |                    changes, the item is connected and the menu is posted, |                    the menu will be redisplayed. | |   Return Values :  E_OK            - success |                    E_BAD_ARGUMENT  - invalid item options +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_item_opts
argument_list|(
argument|ITEM * item
argument_list|,
argument|Item_Options opts
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_menu_opts(%p,%d)"
argument_list|)
operator|,
name|item
operator|,
name|opts
operator|)
argument_list|)
expr_stmt|;
name|opts
operator|&=
name|ALL_ITEM_OPTS
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_ITEM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
condition|)
block|{
if|if
condition|(
name|item
operator|->
name|opt
operator|!=
name|opts
condition|)
block|{
name|MENU
modifier|*
name|menu
init|=
name|item
operator|->
name|imenu
decl_stmt|;
name|item
operator|->
name|opt
operator|=
name|opts
expr_stmt|;
if|if
condition|(
operator|(
operator|!
operator|(
name|opts
operator|&
name|O_SELECTABLE
operator|)
operator|)
operator|&&
name|item
operator|->
name|value
condition|)
name|item
operator|->
name|value
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|menu
operator|&&
operator|(
name|menu
operator|->
name|status
operator|&
name|_POSTED
operator|)
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
else|else
name|_nc_Default_Item
operator|.
name|opt
operator|=
name|opts
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int item_opts_off(ITEM *item, Item_Options opts)    |    |   Description   :  Switch of the options for this item. | |   Return Values :  E_OK            - success |                    E_BAD_ARGUMENT  - invalid options +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|item_opts_off
argument_list|(
argument|ITEM * item
argument_list|,
argument|Item_Options opts
argument_list|)
end_macro

begin_block
block|{
name|ITEM
modifier|*
name|citem
init|=
name|item
decl_stmt|;
comment|/* use a copy because set_item_opts must detect  				   NULL item itself to adjust its behavior */
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"item_opts_off(%p,%d)"
argument_list|)
operator|,
name|item
operator|,
name|opts
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_ITEM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
else|else
block|{
name|Normalize_Item
argument_list|(
name|citem
argument_list|)
expr_stmt|;
name|opts
operator|=
name|citem
operator|->
name|opt
operator|&
operator|~
operator|(
name|opts
operator|&
name|ALL_ITEM_OPTS
operator|)
expr_stmt|;
name|returnCode
argument_list|(
name|set_item_opts
argument_list|(
name|item
argument_list|,
name|opts
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int item_opts_on(ITEM *item, Item_Options opts)    |    |   Description   :  Switch on the options for this item. | |   Return Values :  E_OK            - success |                    E_BAD_ARGUMENT  - invalid options +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|item_opts_on
argument_list|(
argument|ITEM * item
argument_list|,
argument|Item_Options opts
argument_list|)
end_macro

begin_block
block|{
name|ITEM
modifier|*
name|citem
init|=
name|item
decl_stmt|;
comment|/* use a copy because set_item_opts must detect  				   NULL item itself to adjust its behavior */
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"item_opts_on(%p,%d)"
argument_list|)
operator|,
name|item
operator|,
name|opts
operator|)
argument_list|)
expr_stmt|;
name|opts
operator|&=
name|ALL_ITEM_OPTS
expr_stmt|;
if|if
condition|(
name|opts
operator|&
operator|~
name|ALL_ITEM_OPTS
condition|)
name|RETURN
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
else|else
block|{
name|Normalize_Item
argument_list|(
name|citem
argument_list|)
expr_stmt|;
name|opts
operator|=
name|citem
operator|->
name|opt
operator||
name|opts
expr_stmt|;
name|returnCode
argument_list|(
name|set_item_opts
argument_list|(
name|item
argument_list|,
name|opts
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  Item_Options item_opts(const ITEM *item)    |    |   Description   :  Switch of the options for this item. | |   Return Values :  Items options +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|Item_Options
argument_list|)
end_macro

begin_macro
name|item_opts
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
literal|"item_opts(%p)"
argument_list|)
operator|,
name|item
operator|)
argument_list|)
expr_stmt|;
name|returnItemOpts
argument_list|(
name|ALL_ITEM_OPTS
operator|&
name|Normalize_Item
argument_list|(
name|item
argument_list|)
operator|->
name|opt
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_item_opt.c ends here */
end_comment

end_unit

