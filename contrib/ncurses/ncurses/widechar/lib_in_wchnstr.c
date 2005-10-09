begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2002 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  * Author: Thomas Dickey 2002                                               *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_in_wchnstr.c ** **	The routine win_wchnstr(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_in_wchnstr.c,v 1.1 2002/04/13 19:33:57 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|win_wchnstr
argument_list|(
argument|WINDOW *win
argument_list|,
argument|NCURSES_CONST cchar_t * wchstr
argument_list|,
argument|int n
argument_list|)
end_macro

begin_block
block|{
name|int
name|code
init|=
name|OK
decl_stmt|;
name|TR
argument_list|(
name|TRACE_CCALLS
argument_list|,
operator|(
name|T_CALLED
argument_list|(
literal|"win_wchnstr(%p,%p,%d)"
argument_list|)
operator|,
name|win
operator|,
name|wchstr
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
operator|!=
literal|0
operator|&&
name|wchstr
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
name|n
operator|=
name|getmaxx
argument_list|(
name|win
argument_list|)
operator|+
literal|1
operator|-
name|getcurx
argument_list|(
name|win
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
name|win_wch
argument_list|(
name|win
argument_list|,
name|wchstr
operator|++
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|code
operator|=
name|ERR
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

