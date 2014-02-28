begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2000,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* p_move.c  * Move a panel to a new location  */
end_comment

begin_include
include|#
directive|include
file|"panel.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: p_move.c,v 1.9 2005/02/19 16:46:49 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|move_panel
argument_list|(
argument|PANEL * pan
argument_list|,
argument|int starty
argument_list|,
argument|int startx
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"move_panel(%p,%d,%d)"
argument_list|)
operator|,
name|pan
operator|,
name|starty
operator|,
name|startx
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pan
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
if|if
condition|(
name|IS_LINKED
argument_list|(
name|pan
argument_list|)
condition|)
block|{
name|Touchpan
argument_list|(
name|pan
argument_list|)
expr_stmt|;
name|PANEL_UPDATE
argument_list|(
name|pan
argument_list|,
operator|(
name|PANEL
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|mvwin
argument_list|(
name|pan
operator|->
name|win
argument_list|,
name|starty
argument_list|,
name|startx
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

