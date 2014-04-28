begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2009,2013 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  *     and: Juergen Pfeifer                         2009                    *  ****************************************************************************/
end_comment

begin_comment
comment|/*  *	beep.c  *  *	The routine beep().  *  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CUR
end_ifndef

begin_define
define|#
directive|define
name|CUR
value|SP_TERMTYPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_beep.c,v 1.16 2013/01/12 17:26:25 tom Exp $"
argument_list|)
end_macro

begin_comment
comment|/*  *	beep()  *  *	Sound the current terminal's audible bell if it has one.   If not,  *	flash the screen if possible.  *  */
end_comment

begin_function
name|NCURSES_EXPORT
function|(
name|int
function|)
name|NCURSES_SP_NAME
argument_list|(
argument|beep
argument_list|)
parameter_list|(
name|NCURSES_SP_DCL0
parameter_list|)
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
literal|"beep(%p)"
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
ifdef|#
directive|ifdef
name|USE_TERM_DRIVER
if|if
condition|(
name|SP_PARM
operator|!=
literal|0
condition|)
name|res
operator|=
name|CallDriver_1
argument_list|(
name|SP_PARM
argument_list|,
name|doBeepOrFlash
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
else|#
directive|else
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
name|res
operator|=
name|NCURSES_PUTP2_FLUSH
argument_list|(
literal|"bell"
argument_list|,
name|bell
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|flash_screen
condition|)
block|{
name|res
operator|=
name|NCURSES_PUTP2_FLUSH
argument_list|(
literal|"flash_screen"
argument_list|,
name|flash_screen
argument_list|)
expr_stmt|;
name|_nc_flush
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
name|returnCode
argument_list|(
name|res
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
name|beep
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|NCURSES_SP_NAME
argument_list|(
name|beep
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

