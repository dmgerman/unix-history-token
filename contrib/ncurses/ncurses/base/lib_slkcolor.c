begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1998                  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_slkcolor.c  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_slkcolor.c,v 1.5 1999/05/16 17:14:13 juergen Exp $"
argument_list|)
end_macro

begin_function
name|int
name|slk_color
parameter_list|(
name|short
name|color_pair_number
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"slk_color(%d)"
argument_list|)
operator|,
name|color_pair_number
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SP
operator|!=
literal|0
operator|&&
name|SP
operator|->
name|_slk
operator|!=
literal|0
operator|&&
name|color_pair_number
operator|>=
literal|0
operator|&&
name|color_pair_number
operator|<
name|COLOR_PAIRS
condition|)
block|{
name|T
argument_list|(
operator|(
literal|"... current %ld"
operator|,
operator|(
name|long
operator|)
name|PAIR_NUMBER
argument_list|(
name|SP
operator|->
name|_slk
operator|->
name|attr
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|toggle_attr_on
argument_list|(
name|SP
operator|->
name|_slk
operator|->
name|attr
argument_list|,
name|COLOR_PAIR
argument_list|(
name|color_pair_number
argument_list|)
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
end_function

end_unit

