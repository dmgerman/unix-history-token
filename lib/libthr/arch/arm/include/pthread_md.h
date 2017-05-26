begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 David Xu<davidxu@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|CPU_SPINWAIT
end_define

begin_define
define|#
directive|define
name|DTV_OFFSET
value|offsetof(struct tcb, tcb_dtv)
end_define

begin_comment
comment|/*  * Variant II tcb, first two members are required by rtld.  */
end_comment

begin_struct
struct|struct
name|tcb
block|{
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
comment|/* our hook */
block|}
struct|;
end_struct

begin_comment
comment|/* Called from the thread to set its private data. */
end_comment

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
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
operator|*
operator|(
operator|(
expr|struct
name|tcb
operator|*
operator|*
operator|)
name|ARM_TP_ADDRESS
operator|)
operator|=
name|tcb
expr_stmt|;
comment|/* avoids a system call */
else|#
directive|else
name|sysarch
argument_list|(
name|ARM_SET_TP
argument_list|,
name|tcb
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Get the current tcb.  */
end_comment

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
ifdef|#
directive|ifdef
name|ARM_TP_ADDRESS
return|return
operator|(
operator|*
operator|(
operator|(
expr|struct
name|tcb
operator|*
operator|*
operator|)
name|ARM_TP_ADDRESS
operator|)
operator|)
return|;
else|#
directive|else
block|struct
name|tcb
operator|*
name|tcb
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm __volatile("mrc  p15, 0, %0, c13, c0, 3"		\ 	   		 : "=r" (tcb));
end_asm

begin_return
return|return
operator|(
name|tcb
operator|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}  static
name|__inline
name|struct
name|pthread
modifier|*
name|_get_curthread
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|_thr_initial
condition|)
return|return
operator|(
name|_tcb_get
argument_list|()
operator|->
name|tcb_thread
operator|)
return|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTHREAD_MD_H_ */
end_comment

end_unit

