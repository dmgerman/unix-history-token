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

begin_comment
comment|/* Keep _MC_* values similar to amd64 */
end_comment

begin_define
define|#
directive|define
name|_MC_HASSEGS
value|0x1
end_define

begin_define
define|#
directive|define
name|_MC_HASBASES
value|0x2
end_define

begin_define
define|#
directive|define
name|_MC_HASFPXSTATE
value|0x4
end_define

begin_define
define|#
directive|define
name|_MC_FLAG_MASK
value|(_MC_HASSEGS | _MC_HASBASES | _MC_HASFPXSTATE)
end_define

begin_typedef
typedef|typedef
struct|struct
name|__mcontext
block|{
comment|/* 	 * The first 20 fields must match the definition of 	 * sigcontext. So that we can support sigcontext 	 * and ucontext_t at the same time. 	 */
name|__register_t
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|__register_t
name|mc_gs
decl_stmt|;
comment|/* machine state (struct trapframe) */
name|__register_t
name|mc_fs
decl_stmt|;
name|__register_t
name|mc_es
decl_stmt|;
name|__register_t
name|mc_ds
decl_stmt|;
name|__register_t
name|mc_edi
decl_stmt|;
name|__register_t
name|mc_esi
decl_stmt|;
name|__register_t
name|mc_ebp
decl_stmt|;
name|__register_t
name|mc_isp
decl_stmt|;
name|__register_t
name|mc_ebx
decl_stmt|;
name|__register_t
name|mc_edx
decl_stmt|;
name|__register_t
name|mc_ecx
decl_stmt|;
name|__register_t
name|mc_eax
decl_stmt|;
name|__register_t
name|mc_trapno
decl_stmt|;
name|__register_t
name|mc_err
decl_stmt|;
name|__register_t
name|mc_eip
decl_stmt|;
name|__register_t
name|mc_cs
decl_stmt|;
name|__register_t
name|mc_eflags
decl_stmt|;
name|__register_t
name|mc_esp
decl_stmt|;
name|__register_t
name|mc_ss
decl_stmt|;
name|int
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
name|_MC_FPFMT_387
value|0x10001
define|#
directive|define
name|_MC_FPFMT_XMM
value|0x10002
name|int
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
name|int
name|mc_ownedfp
decl_stmt|;
name|__register_t
name|mc_flags
decl_stmt|;
comment|/* 	 * See<machine/npx.h> for the internals of mc_fpstate[]. 	 */
name|int
name|mc_fpstate
index|[
literal|128
index|]
name|__aligned
decl|(16
decl_stmt|);
name|__register_t
name|mc_fsbase
decl_stmt|;
name|__register_t
name|mc_gsbase
decl_stmt|;
name|__register_t
name|mc_xfpustate
decl_stmt|;
name|__register_t
name|mc_xfpustate_len
decl_stmt|;
name|int
name|mc_spare2
index|[
literal|4
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
name|__register_t
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|__register_t
name|mc_gs
decl_stmt|;
comment|/* machine state (struct trapframe) */
name|__register_t
name|mc_fs
decl_stmt|;
name|__register_t
name|mc_es
decl_stmt|;
name|__register_t
name|mc_ds
decl_stmt|;
name|__register_t
name|mc_edi
decl_stmt|;
name|__register_t
name|mc_esi
decl_stmt|;
name|__register_t
name|mc_ebp
decl_stmt|;
name|__register_t
name|mc_isp
decl_stmt|;
name|__register_t
name|mc_ebx
decl_stmt|;
name|__register_t
name|mc_edx
decl_stmt|;
name|__register_t
name|mc_ecx
decl_stmt|;
name|__register_t
name|mc_eax
decl_stmt|;
name|__register_t
name|mc_trapno
decl_stmt|;
name|__register_t
name|mc_err
decl_stmt|;
name|__register_t
name|mc_eip
decl_stmt|;
name|__register_t
name|mc_cs
decl_stmt|;
name|__register_t
name|mc_eflags
decl_stmt|;
name|__register_t
name|mc_esp
decl_stmt|;
comment|/* machine state */
name|__register_t
name|mc_ss
decl_stmt|;
name|__register_t
name|mc_fpregs
index|[
literal|28
index|]
decl_stmt|;
comment|/* env87 + fpacc87 + u_long */
name|__register_t
name|__spare__
index|[
literal|17
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

