begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2002-2004,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  * Author: Thomas Dickey                                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_in_wch.c ** **	The routine win_wch(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_in_wch.c,v 1.4 2006/09/03 15:41:22 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|win_wch
argument_list|(
argument|WINDOW *win
argument_list|,
argument|cchar_t *wcval
argument_list|)
end_macro

begin_block
block|{
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
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
literal|"win_wch(%p,%p)"
argument_list|)
operator|,
name|win
operator|,
name|wcval
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
operator|!=
literal|0
operator|&&
name|wcval
operator|!=
literal|0
condition|)
block|{
name|getyx
argument_list|(
name|win
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
expr_stmt|;
operator|*
name|wcval
operator|=
name|win
operator|->
name|_line
index|[
name|row
index|]
operator|.
name|text
index|[
name|col
index|]
expr_stmt|;
name|TR
argument_list|(
name|TRACE_CCALLS
argument_list|,
operator|(
literal|"data %s"
operator|,
name|_tracecchar_t
argument_list|(
name|wcval
argument_list|)
operator|)
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
name|TR
argument_list|(
name|TRACE_CCALLS
argument_list|,
operator|(
name|T_RETURN
argument_list|(
literal|"%d"
argument_list|)
operator|,
name|code
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|code
operator|)
return|;
block|}
end_block

end_unit

