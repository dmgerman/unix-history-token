begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1997                        *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_dft_fgbg.c,v 1.3 1998/02/11 12:13:54 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  * Modify the behavior of color-pair 0 so that the library doesn't assume that  * it is black on white.  This is an extension to XSI curses.  *  * Invoke this function after 'start_color()'.  */
end_comment

begin_function
name|int
name|use_default_colors
parameter_list|(
name|void
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"use_default_colors()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|SP
operator|->
name|_coloron
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|orig_pair
operator|&&
operator|!
name|orig_colors
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
if|if
condition|(
name|initialize_pair
condition|)
comment|/* don't know how to handle this */
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
name|SP
operator|->
name|_default_color
operator|=
name|TRUE
expr_stmt|;
name|SP
operator|->
name|_color_pairs
index|[
literal|0
index|]
operator|=
name|PAIR_OF
argument_list|(
name|C_MASK
argument_list|,
name|C_MASK
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

