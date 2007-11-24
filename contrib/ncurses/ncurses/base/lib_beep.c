begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2000,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	beep.c  *  *	The routine beep().  *  */
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

begin_comment
comment|/* beep, flash */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_beep.c,v 1.10 2005/04/09 15:20:04 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  *	beep()  *  *	Sound the current terminal's audible bell if it has one.   If not,  *	flash the screen if possible.  *  */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|beep
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|int
name|res
init|=
name|ERR
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"beep()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/* FIXME: should make sure that we are not in altchar mode */
if|if
condition|(
name|cur_term
operator|==
literal|0
condition|)
block|{
name|res
operator|=
name|ERR
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bell
condition|)
block|{
name|TPUTS_TRACE
argument_list|(
literal|"bell"
argument_list|)
expr_stmt|;
name|res
operator|=
name|putp
argument_list|(
name|bell
argument_list|)
expr_stmt|;
name|_nc_flush
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|flash_screen
condition|)
block|{
name|TPUTS_TRACE
argument_list|(
literal|"flash_screen"
argument_list|)
expr_stmt|;
name|res
operator|=
name|putp
argument_list|(
name|flash_screen
argument_list|)
expr_stmt|;
name|_nc_flush
argument_list|()
expr_stmt|;
block|}
name|returnCode
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

