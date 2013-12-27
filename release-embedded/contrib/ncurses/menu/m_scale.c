begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * Module m_scale                                                           * * Menu scaling routine                                                     * ***************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"menu.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: m_scale.c,v 1.9 2004/12/11 23:29:34 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------------- |   Facility      :  libnmenu   |   Function      :  int scale_menu(const MENU *menu) |    |   Description   :  Returns the minimum window size necessary for the |                    subwindow of menu.   | |   Return Values :  E_OK                  - success |                    E_BAD_ARGUMENT        - invalid menu pointer |                    E_NOT_CONNECTED       - no items are connected to menu +--------------------------------------------------------------------------*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|scale_menu
argument_list|(
argument|const MENU * menu
argument_list|,
argument|int *rows
argument_list|,
argument|int *cols
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"scale_menu(%p,%p,%p)"
argument_list|)
operator|,
name|menu
operator|,
name|rows
operator|,
name|cols
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|menu
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
name|items
operator|&&
operator|*
operator|(
name|menu
operator|->
name|items
operator|)
condition|)
block|{
if|if
condition|(
name|rows
condition|)
operator|*
name|rows
operator|=
name|menu
operator|->
name|height
expr_stmt|;
if|if
condition|(
name|cols
condition|)
operator|*
name|cols
operator|=
name|menu
operator|->
name|width
expr_stmt|;
name|RETURN
argument_list|(
name|E_OK
argument_list|)
expr_stmt|;
block|}
else|else
name|RETURN
argument_list|(
name|E_NOT_CONNECTED
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* m_scale.c ends here */
end_comment

end_unit

