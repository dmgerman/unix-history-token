begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_slklab.c  *	Soft key routines.  *      Fetch the label text.  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_slklab.c,v 1.4 1998/02/11 12:13:54 tom Exp $"
argument_list|)
end_macro

begin_function
name|char
modifier|*
name|slk_label
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"slk_label(%d)"
argument_list|)
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SP
operator|==
name|NULL
operator|||
name|SP
operator|->
name|_slk
operator|==
name|NULL
operator|||
name|n
operator|<
literal|1
operator|||
name|n
operator|>
name|SP
operator|->
name|_slk
operator|->
name|labcnt
condition|)
name|returnPtr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|returnPtr
argument_list|(
name|SP
operator|->
name|_slk
operator|->
name|ent
index|[
name|n
operator|-
literal|1
index|]
operator|.
name|text
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

