begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2002,2003 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-2003               *  ****************************************************************************/
end_comment

begin_comment
comment|/* This file provides sigaction() emulation using sigvec() */
end_comment

begin_comment
comment|/* Use only if this is non POSIX system */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: sigaction.c,v 1.14 2003/12/07 01:06:52 tom Exp $"
argument_list|)
end_macro

begin_function
specifier|static
name|int
name|_nc_sigaction
parameter_list|(
name|int
name|sig
parameter_list|,
name|sigaction_t
modifier|*
name|sigact
parameter_list|,
name|sigaction_t
modifier|*
name|osigact
parameter_list|)
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
end_function

begin_function
specifier|static
name|int
name|_nc_sigemptyset
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|)
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
end_function

begin_function
specifier|static
name|int
name|_nc_sigprocmask
parameter_list|(
name|int
name|mode
parameter_list|,
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|sigset_t
modifier|*
name|omask
parameter_list|)
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
end_function

begin_function
specifier|static
name|int
name|_nc_sigaddset
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|int
name|sig
parameter_list|)
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
end_function

begin_comment
comment|/* not used in lib_tstp.c */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int _nc_sigsuspend(sigset_t * mask) {     return sigpause(*mask); }  static int _nc_sigdelset(sigset_t * mask, int sig) {     *mask&= ~sigmask(sig);     return 0; }  static int _nc_sigismember(sigset_t * mask, int sig) {     return (*mask& sigmask(sig)) != 0; }
endif|#
directive|endif
end_endif

end_unit

