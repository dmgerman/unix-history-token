begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UCONTEXT_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|__mcontext
block|{
comment|/* 	 * These fields must match the definition 	 * of struct sigcontext. That way we can support 	 * struct sigcontext and ucontext_t at the same 	 * time. 	 */
name|long
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|unsigned
name|long
name|mc_regs
index|[
literal|37
index|]
decl_stmt|;
name|unsigned
name|long
name|mc_fpregs
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|long
name|mc_fpcr
decl_stmt|;
name|unsigned
name|long
name|mc_fp_control
decl_stmt|;
define|#
directive|define
name|_MC_FPOWNED_NONE
value|0
comment|/* FP state not used */
define|#
directive|define
name|_MC_FPOWNED_FPU
value|1
comment|/* FP state came from FPU */
define|#
directive|define
name|_MC_FPOWNED_PCB
value|2
comment|/* FP state came from PCB */
name|long
name|mc_ownedfp
decl_stmt|;
define|#
directive|define
name|_MC_REV0_SIGFRAME
value|1
comment|/* context is a signal frame */
define|#
directive|define
name|_MC_REV0_TRAPFRAME
value|2
comment|/* context is a trap frame */
name|long
name|mc_format
decl_stmt|;
name|long
name|mc_thrptr
decl_stmt|;
comment|/* Thread pointer */
name|long
name|mc_spare
index|[
literal|5
index|]
decl_stmt|;
block|}
name|mcontext_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_FREEBSD4
argument_list|)
end_if

begin_struct
struct|struct
name|mcontext4
block|{
name|long
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|unsigned
name|long
name|mc_regs
index|[
literal|37
index|]
decl_stmt|;
name|unsigned
name|long
name|mc_fpregs
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|long
name|mc_fpcr
decl_stmt|;
name|unsigned
name|long
name|mc_fp_control
decl_stmt|;
name|long
name|mc_ownedfp
decl_stmt|;
name|long
name|__spare__
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

