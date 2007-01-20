begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-2003               *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_initscr.c ** **	The routines initscr(), and termname(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

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
literal|"$Id: lib_initscr.c,v 1.34 2005/10/22 20:30:38 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|WINDOW *
argument_list|)
end_macro

begin_macro
name|initscr
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
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
name|START_TRACE
argument_list|()
expr_stmt|;
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
ifdef|#
directive|ifdef
name|__CYGWIN__
comment|/* 	 * 2002/9/21 	 * Work around a bug in Cygwin.  Full-screen subprocesses run from 	 * bash, in turn spawned from another full-screen process, will dump 	 * core when attempting to write to stdout.  Opening /dev/tty 	 * explicitly seems to fix the problem. 	 */
if|if
condition|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|)
condition|)
block|{
name|FILE
modifier|*
name|fp
init|=
name|fopen
argument_list|(
literal|"/dev/tty"
argument_list|,
literal|"w"
argument_list|)
decl_stmt|;
if|if
condition|(
name|fp
operator|!=
literal|0
operator|&&
name|isatty
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|)
condition|)
block|{
name|fclose
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|dup2
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|,
name|STDOUT_FILENO
argument_list|)
expr_stmt|;
name|stdout
operator|=
name|fdopen
argument_list|(
name|STDOUT_FILENO
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
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
end_block

end_unit

