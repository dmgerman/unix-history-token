begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author:  Juergen Pfeifer, 1997                                          *  *     and:  Thomas E. Dickey 2005                                          *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	lib_slkattr.c  *	Soft key routines.  *      Fetch the labels attributes  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_slkattr.c,v 1.6 2005/01/08 21:44:28 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|attr_t
argument_list|)
end_macro

begin_macro
name|slk_attr
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"slk_attr()"
argument_list|)
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
condition|)
block|{
name|attr_t
name|result
init|=
name|AttrOf
argument_list|(
name|SP
operator|->
name|_slk
operator|->
name|attr
argument_list|)
operator|&
name|ALL_BUT_COLOR
decl_stmt|;
name|int
name|pair
init|=
name|GetPair
argument_list|(
name|SP
operator|->
name|_slk
operator|->
name|attr
argument_list|)
decl_stmt|;
name|result
operator||=
name|COLOR_PAIR
argument_list|(
name|pair
argument_list|)
expr_stmt|;
name|returnAttr
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
else|else
name|returnAttr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

