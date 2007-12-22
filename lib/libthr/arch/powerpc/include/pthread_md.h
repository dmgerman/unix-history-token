begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|TP_OFFSET
value|0x7008
end_define

begin_comment
comment|/*  * Variant I tcb. The structure layout is fixed, don't blindly  * change it.  * %r2 points to end of the structure.  */
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
specifier|register
name|uint8_t
modifier|*
name|_tp
name|__asm__
argument_list|(
literal|"%r2"
argument_list|)
decl_stmt|;
asm|__asm __volatile("mr %0,%1" : "=r"(_tp) :
literal|"r"
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|tcb
operator|+
name|TP_OFFSET
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|struct
name|tcb
modifier|*
name|_tcb_get
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|uint8_t
modifier|*
name|_tp
name|__asm__
argument_list|(
literal|"%r2"
argument_list|)
decl_stmt|;
return|return
operator|(
operator|(
expr|struct
name|tcb
operator|*
operator|)
operator|(
name|_tp
operator|-
name|TP_OFFSET
operator|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|struct
name|pthread
modifier|*
name|_thr_initial
decl_stmt|;
end_decl_stmt

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

