begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: signal.c,v 1.12 2000/07/08 12:39:06 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_comment
comment|/*  * We would like to always use this signal but there is a link error  * on NEXTSTEP  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|/*  * Bugs:  *  * Do we need any extra hacks for SIGCLD and/or SIGCHLD?  */
end_comment

begin_function
name|SigAction
name|signal
parameter_list|(
name|int
name|iSig
parameter_list|,
name|SigAction
name|pAction
parameter_list|)
block|{
name|struct
name|sigaction
name|saNew
decl_stmt|,
name|saOld
decl_stmt|;
name|saNew
operator|.
name|sa_handler
operator|=
name|pAction
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|saNew
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|saNew
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|iSig
operator|==
name|SIGALRM
condition|)
block|{
ifdef|#
directive|ifdef
name|SA_INTERRUPT
name|saNew
operator|.
name|sa_flags
operator||=
name|SA_INTERRUPT
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|SA_RESTART
name|saNew
operator|.
name|sa_flags
operator||=
name|SA_RESTART
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|sigaction
argument_list|(
name|iSig
argument_list|,
operator|&
name|saNew
argument_list|,
operator|&
name|saOld
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
name|SIG_ERR
operator|)
return|;
return|return
operator|(
name|saOld
operator|.
name|sa_handler
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

