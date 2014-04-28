begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2010 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_win                                                             * * Menus window association routines                                        * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_win.c,v 1.17 2010/01/23 21:20:11 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int set_menu_win(MENU *menu, WINDOW *win) |    |   Description   :  Sets the window of the menu. | |   Return Values :  E_OK               - success |                    E_POSTED           - menu is already posted +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|set_menu_win
argument_list|(
argument|MENU * menu
argument_list|,
argument|WINDOW *win
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"set_menu_win(%p,%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|menu
operator|,
operator|(
name|void
operator|*
operator|)
name|win
operator|)
argument_list|)
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
name|RETURN
argument_list|(
name|E_POSTED
argument_list|)
expr_stmt|;
else|else
if|#
directive|if
name|NCURSES_SP_FUNCS
block|{
comment|/* We ensure that userwin is never null. So even if a null 	     WINDOW parameter is passed, we store the SCREENS stdscr. 	     The only MENU that can have a null userwin is the static 	     _nc_default_Menu. 	   */
name|SCREEN
modifier|*
name|sp
init|=
name|_nc_screen_of
argument_list|(
name|menu
operator|->
name|userwin
argument_list|)
decl_stmt|;
name|menu
operator|->
name|userwin
operator|=
name|win
condition|?
name|win
else|:
name|sp
operator|->
name|_stdscr
expr_stmt|;
name|_nc_Calculate_Item_Length_and_Width
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|menu
operator|->
name|userwin
operator|=
name|win
expr_stmt|;
endif|#
directive|endif
block|}
else|else
name|_nc_Default_Menu
operator|.
name|userwin
operator|=
name|win
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  WINDOW* menu_win(const MENU*) |    |   Description   :  Returns pointer to the window of the menu | |   Return Values :  NULL on error, otherwise pointer to window +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_macro
name|menu_win
argument_list|(
argument|const MENU * menu
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|MENU
modifier|*
name|m
init|=
name|Normalize_Menu
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"menu_win(%p)"
argument_list|)
operator|,
operator|(
specifier|const
name|void
operator|*
operator|)
name|menu
operator|)
argument_list|)
expr_stmt|;
name|returnWin
argument_list|(
name|Get_Menu_UserWin
argument_list|(
name|m
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_win.c ends here */
end_comment

end_unit

