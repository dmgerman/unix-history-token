begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2003 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_insdel.c ** **	The routine winsdelln(win, n). **  positive n insert n lines above current line **  negative n delete n lines starting from current line ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_insdel.c,v 1.12 2003/07/26 22:40:06 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|winsdelln
argument_list|(
argument|WINDOW *win
argument_list|,
argument|int n
argument_list|)
end_macro

begin_block
block|{
name|int
name|code
init|=
name|ERR
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"winsdelln(%p,%d)"
argument_list|)
operator|,
name|win
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
condition|)
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|_nc_scroll_window
argument_list|(
name|win
argument_list|,
operator|-
name|n
argument_list|,
name|win
operator|->
name|_cury
argument_list|,
name|win
operator|->
name|_maxy
argument_list|,
name|win
operator|->
name|_nc_bkgd
argument_list|)
expr_stmt|;
name|_nc_synchook
argument_list|(
name|win
argument_list|)
expr_stmt|;
block|}
name|code
operator|=
name|OK
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

