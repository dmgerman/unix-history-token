begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_SIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_SIG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_define
define|#
directive|define
name|FORREAL
value|0
end_define

begin_define
define|#
directive|define
name|JUSTLOOKING
value|1
end_define

begin_function
specifier|static
name|__inline
name|int
name|issig
parameter_list|(
name|int
name|why
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
init|=
name|curthread
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|int
name|sig
decl_stmt|;
name|ASSERT
argument_list|(
name|why
operator|==
name|FORREAL
operator|||
name|why
operator|==
name|JUSTLOOKING
argument_list|)
expr_stmt|;
if|if
condition|(
name|SIGPENDING
argument_list|(
name|td
argument_list|)
condition|)
block|{
if|if
condition|(
name|why
operator|==
name|JUSTLOOKING
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|p
operator|=
name|td
operator|->
name|td_proc
expr_stmt|;
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|p
operator|->
name|p_sigacts
operator|->
name|ps_mtx
argument_list|)
expr_stmt|;
name|sig
operator|=
name|cursig
argument_list|(
name|td
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|p
operator|->
name|p_sigacts
operator|->
name|ps_mtx
argument_list|)
expr_stmt|;
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|sig
operator|!=
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_SIG_H_ */
end_comment

end_unit

