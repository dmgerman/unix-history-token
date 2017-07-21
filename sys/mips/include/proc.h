begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: proc.h,v 1.2 1998/09/15 10:50:12 pefo Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.1 (Berkeley) 6/10/93  *	JNPR: proc.h,v 1.7.2.1 2007/09/10 06:25:24 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_CNMIPS
end_ifdef

begin_include
include|#
directive|include
file|<machine/octeon_cop2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Machine-dependent part of the proc structure.  */
end_comment

begin_struct
struct|struct
name|mdthread
block|{
name|int
name|md_flags
decl_stmt|;
comment|/* machine-dependent flags */
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
comment|/*  PHYSADDR_64_BIT */
name|uint64_t
name|md_upte
index|[
name|KSTACK_PAGES
index|]
decl_stmt|;
comment|/* ptes for mapping u pcb */
else|#
directive|else
name|int
name|md_upte
index|[
name|KSTACK_PAGES
index|]
decl_stmt|;
endif|#
directive|endif
name|int
name|md_ss_addr
decl_stmt|;
comment|/* single step address for ptrace */
name|int
name|md_ss_instr
decl_stmt|;
comment|/* single step instruction for ptrace */
name|register_t
name|md_saved_intr
decl_stmt|;
name|u_int
name|md_spinlock_count
decl_stmt|;
comment|/* The following is CPU dependent, but kept in for compatibility */
name|int
name|md_pc_ctrl
decl_stmt|;
comment|/* performance counter control */
name|int
name|md_pc_count
decl_stmt|;
comment|/* performance counter */
name|int
name|md_pc_spill
decl_stmt|;
comment|/* performance counter spill */
name|void
modifier|*
name|md_tls
decl_stmt|;
ifdef|#
directive|ifdef
name|CPU_CNMIPS
name|struct
name|octeon_cop2_state
modifier|*
name|md_cop2
decl_stmt|;
comment|/* kernel context */
name|struct
name|octeon_cop2_state
modifier|*
name|md_ucop2
decl_stmt|;
comment|/* userland context */
define|#
directive|define
name|COP2_OWNER_USERLAND
value|0x0000
comment|/* Userland owns COP2 */
define|#
directive|define
name|COP2_OWNER_KERNEL
value|0x0001
comment|/* Kernel owns COP2 */
name|int
name|md_cop2owner
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* md_flags */
end_comment

begin_define
define|#
directive|define
name|MDTD_FPUSED
value|0x0001
end_define

begin_comment
comment|/* Process used the FPU */
end_comment

begin_define
define|#
directive|define
name|MDTD_COP2USED
value|0x0002
end_define

begin_comment
comment|/* Process used the COP2 */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
comment|/* empty */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|syscall_args
block|{
name|u_int
name|code
decl_stmt|;
name|struct
name|sysent
modifier|*
name|callp
decl_stmt|;
name|register_t
name|args
index|[
literal|8
index|]
decl_stmt|;
name|int
name|narg
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|trapframe
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|1088
end_define

begin_define
define|#
directive|define
name|KINFO_PROC32_SIZE
value|816
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|816
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROC_H_ */
end_comment

end_unit

