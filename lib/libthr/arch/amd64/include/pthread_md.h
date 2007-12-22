begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2003 David Xu<davidxu@freebsd.org>  * Copyright (c) 2001 Daniel Eischen<deischen@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine-dependent thread prototypes/definitions.  */
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
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_define
define|#
directive|define
name|CPU_SPINWAIT
value|__asm __volatile("pause")
end_define

begin_define
define|#
directive|define
name|DTV_OFFSET
value|offsetof(struct tcb, tcb_dtv)
end_define

begin_comment
comment|/*  * Variant II tcb, first two members are required by rtld,  * %fs points to the structure.  */
end_comment

begin_struct
struct|struct
name|tcb
block|{
name|struct
name|tcb
modifier|*
name|tcb_self
decl_stmt|;
comment|/* required by rtld */
name|void
modifier|*
name|tcb_dtv
decl_stmt|;
comment|/* required by rtld */
name|struct
name|pthread
modifier|*
name|tcb_thread
decl_stmt|;
name|void
modifier|*
name|tcb_spare
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Evaluates to the byte offset of the per-tcb variable name.  */
end_comment

begin_define
define|#
directive|define
name|__tcb_offset
parameter_list|(
name|name
parameter_list|)
value|__offsetof(struct tcb, name)
end_define

begin_comment
comment|/*  * Evaluates to the type of the per-tcb variable name.  */
end_comment

begin_define
define|#
directive|define
name|__tcb_type
parameter_list|(
name|name
parameter_list|)
value|__typeof(((struct tcb *)0)->name)
end_define

begin_comment
comment|/*  * Evaluates to the value of the per-tcb variable name.  */
end_comment

begin_define
define|#
directive|define
name|TCB_GET64
parameter_list|(
name|name
parameter_list|)
value|({					\ 	__tcb_type(name) __result;				\ 								\ 	u_long __i;						\ 	__asm __volatile("movq %%fs:%1, %0"			\ 	    : "=r" (__i)					\ 	    : "m" (*(u_long *)(__tcb_offset(name))));		\ 	__result = (__tcb_type(name))__i;			\ 								\ 	__result;						\ })
end_define

begin_function_decl
name|struct
name|tcb
modifier|*
name|_tcb_ctor
parameter_list|(
name|struct
name|pthread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcb_dtor
parameter_list|(
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|_tcb_set
parameter_list|(
name|struct
name|tcb
modifier|*
name|tcb
parameter_list|)
block|{
name|amd64_set_fsbase
argument_list|(
name|tcb
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|tcb
operator|*
name|_tcb_get
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|TCB_GET64
argument_list|(
name|tcb_self
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|pthread
operator|*
name|_get_curthread
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|(
name|TCB_GET64
argument_list|(
name|tcb_thread
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

