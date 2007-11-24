begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2005,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Sven Verdoolaege                        2001                    *  *     and: Thomas E. Dickey                        2005                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_chgat.c ** **	The routine wchgat(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_chgat.c,v 1.7 2006/07/15 22:07:11 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|wchgat
argument_list|(
argument|WINDOW *win
argument_list|,
argument|int n
argument_list|,
argument|attr_t attr
argument_list|,
argument|short color
argument_list|,
argument|const void *opts GCC_UNUSED
argument_list|)
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"wchgat(%p,%d,%s,%d)"
argument_list|)
operator|,
name|win
operator|,
name|n
operator|,
name|_traceattr
argument_list|(
name|attr
argument_list|)
operator|,
name|color
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
condition|)
block|{
name|struct
name|ldat
modifier|*
name|line
init|=
operator|&
operator|(
name|win
operator|->
name|_line
index|[
name|win
operator|->
name|_cury
index|]
operator|)
decl_stmt|;
name|toggle_attr_on
argument_list|(
name|attr
argument_list|,
name|COLOR_PAIR
argument_list|(
name|color
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|win
operator|->
name|_curx
init|;
name|i
operator|<=
name|win
operator|->
name|_maxx
operator|&&
operator|(
name|n
operator|==
operator|-
literal|1
operator|||
operator|(
name|n
operator|--
operator|>
literal|0
operator|)
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|SetAttr
argument_list|(
name|line
operator|->
name|text
index|[
name|i
index|]
argument_list|,
name|attr
argument_list|)
expr_stmt|;
name|SetPair
argument_list|(
name|line
operator|->
name|text
index|[
name|i
index|]
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|CHANGED_CELL
argument_list|(
name|line
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
else|else
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

