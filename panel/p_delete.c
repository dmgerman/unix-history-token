begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2000,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* p_delete.c  * Remove a panel from stack, if in it, and free struct  */
end_comment

begin_include
include|#
directive|include
file|"panel.priv.h"
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: p_delete.c,v 1.8 2005/02/19 16:38:45 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|del_panel
argument_list|(
argument|PANEL * pan
argument_list|)
end_macro

begin_block
block|{
name|int
name|err
init|=
name|OK
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"del_panel(%p)"
argument_list|)
operator|,
name|pan
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pan
condition|)
block|{
name|dBug
argument_list|(
operator|(
literal|"--> del_panel %s"
operator|,
name|USER_PTR
argument_list|(
name|pan
operator|->
name|user
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|HIDE_PANEL
argument_list|(
name|pan
argument_list|,
name|err
argument_list|,
name|OK
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|pan
argument_list|)
expr_stmt|;
block|}
else|else
name|err
operator|=
name|ERR
expr_stmt|;
name|returnCode
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

