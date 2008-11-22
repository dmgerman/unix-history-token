begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 2004 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                                                *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_pecho_wchar.c,v 1.1 2004/01/03 21:42:01 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|pecho_wchar
argument_list|(
argument|WINDOW *pad
argument_list|,
argument|const cchar_t * wch
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"pecho_wchar(%p, %s)"
argument_list|)
operator|,
name|pad
operator|,
name|_tracech_t
argument_list|(
name|wch
argument_list|)
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|pad
operator|==
literal|0
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|pad
operator|->
name|_flags
operator|&
name|_ISPAD
operator|)
condition|)
name|returnCode
argument_list|(
name|wecho_wchar
argument_list|(
name|pad
argument_list|,
name|wch
argument_list|)
argument_list|)
expr_stmt|;
name|wadd_wch
argument_list|(
name|pad
argument_list|,
name|wch
argument_list|)
expr_stmt|;
name|prefresh
argument_list|(
name|pad
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_y
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_x
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_top
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_left
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_bottom
argument_list|,
name|pad
operator|->
name|_pad
operator|.
name|_pad_right
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

