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
comment|/* 	 * The first 20 fields must match the definition of 	 * sigcontext. So that we can support sigcontext 	 * and ucontext_t at the same time. 	 */
name|register_t
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|register_t
name|mc_rdi
decl_stmt|;
comment|/* machine state (struct trapframe) */
name|register_t
name|mc_rsi
decl_stmt|;
name|register_t
name|mc_rdx
decl_stmt|;
name|register_t
name|mc_rcx
decl_stmt|;
name|register_t
name|mc_r8
decl_stmt|;
name|register_t
name|mc_r9
decl_stmt|;
name|register_t
name|mc_rax
decl_stmt|;
name|register_t
name|mc_rbx
decl_stmt|;
name|register_t
name|mc_rbp
decl_stmt|;
name|register_t
name|mc_r10
decl_stmt|;
name|register_t
name|mc_r11
decl_stmt|;
name|register_t
name|mc_r12
decl_stmt|;
name|register_t
name|mc_r13
decl_stmt|;
name|register_t
name|mc_r14
decl_stmt|;
name|register_t
name|mc_r15
decl_stmt|;
name|register_t
name|mc_trapno
decl_stmt|;
name|register_t
name|mc_err
decl_stmt|;
name|register_t
name|mc_rip
decl_stmt|;
name|register_t
name|mc_cs
decl_stmt|;
name|register_t
name|mc_rflags
decl_stmt|;
name|register_t
name|mc_rsp
decl_stmt|;
name|register_t
name|mc_ss
decl_stmt|;
name|long
name|mc_len
decl_stmt|;
comment|/* sizeof(mcontext_t) */
define|#
directive|define
name|_MC_FPFMT_NODEV
value|0x10000
comment|/* device not present or configured */
define|#
directive|define
name|_MC_FPFMT_XMM
value|0x10002
name|long
name|mc_fpformat
decl_stmt|;
define|#
directive|define
name|_MC_FPOWNED_NONE
value|0x20000
comment|/* FP state not used */
define|#
directive|define
name|_MC_FPOWNED_FPU
value|0x20001
comment|/* FP state came from FPU */
define|#
directive|define
name|_MC_FPOWNED_PCB
value|0x20002
comment|/* FP state came from PCB */
name|long
name|mc_ownedfp
decl_stmt|;
name|long
name|mc_spare1
index|[
literal|1
index|]
decl_stmt|;
comment|/* align next field to 16 bytes */
comment|/* 	 * See<machine/npx.h> for the internals of mc_fpstate[]. 	 */
name|long
name|mc_fpstate
index|[
literal|128
index|]
name|__aligned
decl|(16
decl_stmt|);
name|long
name|mc_spare2
index|[
literal|8
index|]
decl_stmt|;
block|}
name|mcontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

