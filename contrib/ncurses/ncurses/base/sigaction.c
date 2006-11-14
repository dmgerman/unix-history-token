begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2002 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<SigAction.h>
end_include

begin_comment
comment|/* This file provides sigaction() emulation using sigvec() */
end_comment

begin_comment
comment|/* Use only if this is non POSIX system */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIGACTION
operator|&&
name|HAVE_SIGVEC
end_if

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: sigaction.c,v 1.13 2002/05/18 19:56:26 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigaction
argument_list|(
argument|int sig
argument_list|,
argument|sigaction_t * sigact
argument_list|,
argument|sigaction_t * osigact
argument_list|)
end_macro

begin_block
block|{
return|return
name|sigvec
argument_list|(
name|sig
argument_list|,
name|sigact
argument_list|,
name|osigact
argument_list|)
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigemptyset
argument_list|(
argument|sigset_t * mask
argument_list|)
end_macro

begin_block
block|{
operator|*
name|mask
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigprocmask
argument_list|(
argument|int mode
argument_list|,
argument|sigset_t * mask
argument_list|,
argument|sigset_t * omask
argument_list|)
end_macro

begin_block
block|{
name|sigset_t
name|current
init|=
name|sigsetmask
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|omask
condition|)
operator|*
name|omask
operator|=
name|current
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|SIG_BLOCK
condition|)
name|current
operator||=
operator|*
name|mask
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|SIG_UNBLOCK
condition|)
name|current
operator|&=
operator|~
operator|*
name|mask
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
name|SIG_SETMASK
condition|)
name|current
operator|=
operator|*
name|mask
expr_stmt|;
name|sigsetmask
argument_list|(
name|current
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigsuspend
argument_list|(
argument|sigset_t * mask
argument_list|)
end_macro

begin_block
block|{
return|return
name|sigpause
argument_list|(
operator|*
name|mask
argument_list|)
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigdelset
argument_list|(
argument|sigset_t * mask
argument_list|,
argument|int sig
argument_list|)
end_macro

begin_block
block|{
operator|*
name|mask
operator|&=
operator|~
name|sigmask
argument_list|(
name|sig
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigaddset
argument_list|(
argument|sigset_t * mask
argument_list|,
argument|int sig
argument_list|)
end_macro

begin_block
block|{
operator|*
name|mask
operator||=
name|sigmask
argument_list|(
name|sig
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|sigismember
argument_list|(
argument|sigset_t * mask
argument_list|,
argument|int sig
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
operator|*
name|mask
operator|&
name|sigmask
argument_list|(
name|sig
argument_list|)
operator|)
operator|!=
literal|0
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_sigaction
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* quiet's gcc warning */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_sigaction
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/* nonempty for strict ANSI compilers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

