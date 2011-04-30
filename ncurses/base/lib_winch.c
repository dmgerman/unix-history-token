begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2009,2010 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1998                        *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_winch.c ** **	The routine winch(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_winch.c,v 1.8 2010/12/19 01:22:58 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|chtype
argument_list|)
end_macro

begin_macro
name|winch
argument_list|(
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
literal|"winch(%p)"
argument_list|)
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
name|win
operator|!=
literal|0
condition|)
block|{
name|returnChtype
argument_list|(
operator|(
name|chtype
operator|)
name|CharOf
argument_list|(
name|win
operator|->
name|_line
index|[
name|win
operator|->
name|_cury
index|]
operator|.
name|text
index|[
name|win
operator|->
name|_curx
index|]
argument_list|)
operator||
name|AttrOf
argument_list|(
name|win
operator|->
name|_line
index|[
name|win
operator|->
name|_cury
index|]
operator|.
name|text
index|[
name|win
operator|->
name|_curx
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|returnChtype
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

