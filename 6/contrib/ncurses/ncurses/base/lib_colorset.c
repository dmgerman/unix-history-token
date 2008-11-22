begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Juergen Pfeifer,  1998                                          *  *     and: Thomas E. Dickey, 2005                                          *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_colorset.c ** **	The routine wcolor_set(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_colorset.c,v 1.11 2005/01/29 21:40:51 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|wcolor_set
argument_list|(
argument|WINDOW *win
argument_list|,
argument|short color_pair_number
argument_list|,
argument|void *opts
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"wcolor_set(%p,%d)"
argument_list|)
operator|,
name|win
operator|,
name|color_pair_number
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|win
operator|&&
operator|!
name|opts
operator|&&
operator|(
name|color_pair_number
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|color_pair_number
operator|<
name|COLOR_PAIRS
operator|)
condition|)
block|{
name|TR
argument_list|(
name|TRACE_ATTRS
argument_list|,
operator|(
literal|"... current %ld"
operator|,
operator|(
name|long
operator|)
name|GET_WINDOW_PAIR
argument_list|(
name|win
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|SET_WINDOW_PAIR
argument_list|(
name|win
argument_list|,
name|color_pair_number
argument_list|)
expr_stmt|;
name|if_EXT_COLORS
argument_list|(
name|win
operator|->
name|_color
operator|=
name|color_pair_number
argument_list|)
expr_stmt|;
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

