begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 David Xu<davidxu@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * from: src/lib/libthr/arch/arm/include/pthread_md.h,v 1.3 2005/10/29 13:40:31 davidxu  * $FreeBSD$  */
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
file|<machine/tls.h>
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
comment|/*  * Variant I tcb. The structure layout is fixed, don't blindly  * change it!  */
end_comment

begin_struct
struct|struct
name|tcb
block|{
name|void
modifier|*
name|tcb_dtv
decl_stmt|;
name|struct
name|pthread
modifier|*
name|tcb_thread
decl_stmt|;
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
name|sysarch
argument_list|(
name|MIPS_SET_TLS
argument_list|,
name|tcb
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get the current tcb.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TLS_USE_SYSARCH
end_ifdef

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
block|{ 	struct
name|tcb
operator|*
name|tcb
block|;
name|sysarch
argument_list|(
name|MIPS_GET_TLS
argument_list|,
operator|&
name|tcb
argument_list|)
block|;
return|return
name|tcb
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! TLS_USE_SYSARCH */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

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
name|uint64_t
name|_rv
block|;
name|__asm__
specifier|__volatile__
operator|(
literal|".set\tpush\n\t"
literal|".set\tmips64r2\n\t"
literal|"rdhwr\t%0, $29\n\t"
literal|".set\tpop"
operator|:
literal|"=r"
operator|(
name|_rv
operator|)
operator|)
block|;
comment|/* 	 * XXXSS See 'git show c6be4f4d2d1b71c04de5d3bbb6933ce2dbcdb317' 	 * 	 * Remove the offset since this really a request to get the TLS 	 * pointer via sysarch() (in theory).  Of course, this may go away 	 * once the TLS code is rewritten. 	 */
return|return
operator|(
expr|struct
name|tcb
operator|*
operator|)
operator|(
name|_rv
operator|-
name|TLS_TP_OFFSET
operator|-
name|TLS_TCB_SIZE
operator|)
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* mips 32 */
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
name|uint32_t
name|_rv
block|;
name|__asm__
specifier|__volatile__
operator|(
literal|".set\tpush\n\t"
literal|".set\tmips32r2\n\t"
literal|"rdhwr\t%0, $29\n\t"
literal|".set\tpop"
operator|:
literal|"=r"
operator|(
name|_rv
operator|)
operator|)
block|;
comment|/* 	 * XXXSS See 'git show c6be4f4d2d1b71c04de5d3bbb6933ce2dbcdb317' 	 * 	 * Remove the offset since this really a request to get the TLS 	 * pointer via sysarch() (in theory).  Of course, this may go away 	 * once the TLS code is rewritten. 	 */
return|return
operator|(
expr|struct
name|tcb
operator|*
operator|)
operator|(
name|_rv
operator|-
name|TLS_TP_OFFSET
operator|-
name|TLS_TCB_SIZE
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __mips_n64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TLS_USE_SYSARCH */
end_comment

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
end_expr_stmt

begin_return
return|return
operator|(
name|NULL
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PTHREAD_MD_H_ */
end_comment

end_unit

