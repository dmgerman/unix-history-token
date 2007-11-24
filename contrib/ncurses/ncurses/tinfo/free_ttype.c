begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1999-2005,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey                    1999-on                     *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * free_ttype.c -- allocation functions for TERMTYPE  *  *	_nc_free_termtype()  *	use_extended_names()  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<tic.h>
end_include

begin_include
include|#
directive|include
file|<term_entry.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: free_ttype.c,v 1.13 2006/06/25 10:46:02 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_free_termtype
argument_list|(
argument|TERMTYPE *ptr
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
literal|"_nc_free_termtype(%s)"
operator|,
name|ptr
operator|->
name|term_names
operator|)
argument_list|)
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|str_table
argument_list|)
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|Booleans
argument_list|)
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|Numbers
argument_list|)
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|Strings
argument_list|)
expr_stmt|;
if|#
directive|if
name|NCURSES_XNAMES
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|ext_str_table
argument_list|)
expr_stmt|;
name|FreeIfNeeded
argument_list|(
name|ptr
operator|->
name|ext_Names
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|memset
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|TERMTYPE
argument_list|)
argument_list|)
expr_stmt|;
name|_nc_free_entry
argument_list|(
name|_nc_head
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|NCURSES_XNAMES
end_if

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|bool
argument_list|)
end_macro

begin_expr_stmt
name|_nc_user_definable
operator|=
name|TRUE
expr_stmt|;
end_expr_stmt

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|use_extended_names
argument_list|(
argument|bool flag
argument_list|)
end_macro

begin_block
block|{
name|int
name|oldflag
init|=
name|_nc_user_definable
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"use_extended_names(%d)"
argument_list|)
operator|,
name|flag
operator|)
argument_list|)
expr_stmt|;
name|_nc_user_definable
operator|=
name|flag
expr_stmt|;
name|returnBool
argument_list|(
name|oldflag
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

