begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_PROC_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_empty
empty|#include_next<sys/proc.h>
end_empty

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CPU
value|curcpu
end_define

begin_define
define|#
directive|define
name|minclsyspri
value|0
end_define

begin_define
define|#
directive|define
name|maxclsyspri
value|0
end_define

begin_define
define|#
directive|define
name|max_ncpus
value|mp_ncpus
end_define

begin_define
define|#
directive|define
name|boot_max_ncpus
value|mp_ncpus
end_define

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's frequency */
end_comment

begin_define
define|#
directive|define
name|TS_RUN
value|0
end_define

begin_define
define|#
directive|define
name|p0
value|proc0
end_define

begin_typedef
typedef|typedef
name|short
name|pri_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|thread
name|_kthread
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|thread
name|kthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|thread
modifier|*
name|kthread_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|proc
name|proc_t
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|kthread_t
modifier|*
name|thread_create
parameter_list|(
name|caddr_t
name|stk
parameter_list|,
name|size_t
name|stksize
parameter_list|,
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|proc_t
modifier|*
name|pp
parameter_list|,
name|int
name|state
parameter_list|,
name|pri_t
name|pri
parameter_list|)
block|{
name|proc_t
modifier|*
name|p
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* 	 * Be sure there are no surprises. 	 */
name|ASSERT
argument_list|(
name|stk
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|stksize
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|len
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|state
operator|==
name|TS_RUN
argument_list|)
expr_stmt|;
name|error
operator|=
name|kthread_create
argument_list|(
name|proc
argument_list|,
name|arg
argument_list|,
operator|&
name|p
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|"solthread %p"
argument_list|,
name|proc
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|==
literal|0
condition|?
name|FIRST_THREAD_IN_PROC
argument_list|(
name|p
argument_list|)
else|:
name|NULL
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|thread_exit
parameter_list|()
value|kthread_exit(0)
end_define

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
comment|/* _OPENSOLARIS_SYS_PROC_H_ */
end_comment

end_unit

