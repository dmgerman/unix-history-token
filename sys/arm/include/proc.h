begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      from: @(#)proc.h        7.1 (Berkeley) 5/15/91  *	from: FreeBSD: src/sys/i386/include/proc.h,v 1.11 2001/06/29  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<machine/utrap.h>
end_include

begin_struct
struct|struct
name|md_utrap
block|{
name|utrap_entry_t
modifier|*
name|ut_precise
index|[
name|UT_MAX
index|]
decl_stmt|;
comment|/* must be first */
name|int
name|ut_refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdthread
block|{
name|int
name|md_spinlock_count
decl_stmt|;
comment|/* (k) */
name|register_t
name|md_saved_cspr
decl_stmt|;
comment|/* (k) */
name|register_t
name|md_spurflt_addr
decl_stmt|;
comment|/* (k) Spurious page fault address. */
name|int
name|md_ptrace_instr
decl_stmt|;
name|int
name|md_ptrace_addr
decl_stmt|;
name|int
name|md_ptrace_instr_alt
decl_stmt|;
name|int
name|md_ptrace_addr_alt
decl_stmt|;
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
name|register_t
name|md_tp
decl_stmt|;
name|void
modifier|*
name|md_ras_start
decl_stmt|;
name|void
modifier|*
name|md_ras_end
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdproc
block|{
name|struct
name|md_utrap
modifier|*
name|md_utrap
decl_stmt|;
name|void
modifier|*
name|md_sigtramp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KINFO_PROC_SIZE
value|816
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|8
end_define

begin_comment
comment|/*  * This holds the syscall state for a single system call.  * As some syscall arguments may be 64-bit aligned we need to ensure the  * args value is 64-bit aligned. The ABI will then ensure any 64-bit  * arguments are already correctly aligned, even if they were passed in  * via registers, we just need to make sure we copy them to an aligned  * buffer.  */
end_comment

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
name|MAXARGS
index|]
decl_stmt|;
name|int
name|narg
decl_stmt|;
name|u_int
name|nap
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROC_H_ */
end_comment

end_unit

