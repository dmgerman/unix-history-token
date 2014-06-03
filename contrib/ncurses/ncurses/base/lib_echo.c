begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2008,2009 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  *     and: Juergen Pfeifer                         2009                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	echo.c  *  *	Routines:  *		echo()  *		noecho()  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_echo.c,v 1.8 2009/10/24 22:02:14 tom Exp $"
argument_list|)
end_macro

begin_function
name|NCURSES_EXPORT
function|(
name|int
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|echo
argument_list|)
parameter_list|(
name|NCURSES_SP_DCL0
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"echo(%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|SP_PARM
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|SP_PARM
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
name|SP_PARM
operator|->
name|_echo
operator|=
name|TRUE
expr_stmt|;
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|echo
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|NCURSES_SP_NAME
argument_list|(
name|echo
argument_list|)
argument_list|(
name|CURRENT_SCREEN
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|NCURSES_EXPORT
function|(
name|int
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|noecho
argument_list|)
parameter_list|(
name|NCURSES_SP_DCL0
parameter_list|)
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"noecho(%p)"
argument_list|)
operator|,
operator|(
name|void
operator|*
operator|)
name|SP_PARM
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|SP_PARM
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
name|SP_PARM
operator|->
name|_echo
operator|=
name|FALSE
expr_stmt|;
name|returnCode
argument_list|(
name|OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|noecho
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|NCURSES_SP_NAME
argument_list|(
name|noecho
argument_list|)
argument_list|(
name|CURRENT_SCREEN
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

