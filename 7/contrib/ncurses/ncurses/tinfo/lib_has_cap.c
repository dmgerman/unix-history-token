begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2000,2003 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-2003               *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_has_cap.c ** **	The routines to query terminal capabilities ** */
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
literal|"$Id: lib_has_cap.c,v 1.4 2003/10/25 19:43:55 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|has_ic
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
literal|"has_ic()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|cur_term
operator|&&
operator|(
name|insert_character
operator|||
name|parm_ich
operator|||
operator|(
name|enter_insert_mode
operator|&&
name|exit_insert_mode
operator|)
operator|)
operator|&&
operator|(
name|delete_character
operator|||
name|parm_dch
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|has_il
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
literal|"has_il()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|returnCode
argument_list|(
name|cur_term
operator|&&
operator|(
name|insert_line
operator|||
name|parm_insert_line
operator|)
operator|&&
operator|(
name|delete_line
operator|||
name|parm_delete_line
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

