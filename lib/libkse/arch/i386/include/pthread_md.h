begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Daniel Eischen<deischen@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine-dependent thread prototypes/definitions for the thread kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_MD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_MD_H_
end_define

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_function_decl
specifier|extern
name|int
name|_thr_setcontext
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_thr_getcontext
parameter_list|(
name|ucontext_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These are needed to ensure an application doesn't attempt to jump  * between stacks of different threads.  They return the stack of  * jmp_buf, sigjmp_buf, and ucontext respectively.  */
end_comment

begin_define
define|#
directive|define
name|GET_STACK_JB
parameter_list|(
name|jb
parameter_list|)
value|((unsigned long)((jb)[0]._jb[2]))
end_define

begin_define
define|#
directive|define
name|GET_STACK_SJB
parameter_list|(
name|sjb
parameter_list|)
value|((unsigned long)((sjb)[0]._sjb[2]))
end_define

begin_define
define|#
directive|define
name|GET_STACK_UC
parameter_list|(
name|ucp
parameter_list|)
value|((unsigned long)((ucp)->uc_mcontext.mc_esp))
end_define

begin_define
define|#
directive|define
name|THR_GETCONTEXT
parameter_list|(
name|ucp
parameter_list|)
value|_thr_getcontext(ucp)
end_define

begin_define
define|#
directive|define
name|THR_SETCONTEXT
parameter_list|(
name|ucp
parameter_list|)
value|_thr_setcontext(ucp)
end_define

begin_define
define|#
directive|define
name|THR_ALIGNBYTES
value|15
end_define

begin_define
define|#
directive|define
name|THR_ALIGN
parameter_list|(
name|td
parameter_list|)
value|(((unsigned)(td) + THR_ALIGNBYTES)& ~THR_ALIGNBYTES)
end_define

begin_comment
comment|/*  * KSE Specific Data.  */
end_comment

begin_struct
struct|struct
name|ksd
block|{
name|int
name|ldt
decl_stmt|;
define|#
directive|define
name|KSDF_INITIALIZED
value|0x01
name|long
name|flags
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
name|long
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

