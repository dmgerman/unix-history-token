begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_initscr.c ** **	The routines initscr(), and termname(). ** */
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

begin_comment
comment|/* for MAX_ALIAS */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_TERMIO_H
end_if

begin_include
include|#
directive|include
file|<sys/termio.h>
end_include

begin_comment
comment|/* needed for ISC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_initscr.c,v 1.26 1998/12/19 23:10:09 tom Exp $"
argument_list|)
end_macro

begin_function
name|WINDOW
modifier|*
name|initscr
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|bool
name|initialized
init|=
name|FALSE
decl_stmt|;
name|NCURSES_CONST
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"initscr()"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/* Portable applications must not call initscr() more than once */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
operator|(
name|name
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
operator|)
operator|==
literal|0
operator|||
operator|*
name|name
operator|==
literal|'\0'
condition|)
name|name
operator|=
literal|"unknown"
expr_stmt|;
if|if
condition|(
name|newterm
argument_list|(
name|name
argument_list|,
name|stdout
argument_list|,
name|stdin
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error opening terminal: %s.\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
comment|/* allow user to set maximum escape delay from the environment */
if|if
condition|(
operator|(
name|value
operator|=
name|_nc_getenv_num
argument_list|(
literal|"ESCDELAY"
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
name|ESCDELAY
operator|=
name|value
expr_stmt|;
block|}
comment|/* def_shell_mode - done in newterm/_nc_setupscreen */
name|def_prog_mode
argument_list|()
expr_stmt|;
block|}
name|returnWin
argument_list|(
name|stdscr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

