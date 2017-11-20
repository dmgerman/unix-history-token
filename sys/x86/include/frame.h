begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003 Peter Wemm.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)frame.h	5.2 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FRAME_H_
value|1
end_define

begin_comment
comment|/*  * System stack frames.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/*  * Exception/Trap Stack Frame  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|int
name|tf_fs
decl_stmt|;
name|int
name|tf_es
decl_stmt|;
name|int
name|tf_ds
decl_stmt|;
name|int
name|tf_edi
decl_stmt|;
name|int
name|tf_esi
decl_stmt|;
name|int
name|tf_ebp
decl_stmt|;
name|int
name|tf_isp
decl_stmt|;
name|int
name|tf_ebx
decl_stmt|;
name|int
name|tf_edx
decl_stmt|;
name|int
name|tf_ecx
decl_stmt|;
name|int
name|tf_eax
decl_stmt|;
name|int
name|tf_trapno
decl_stmt|;
comment|/* below portion defined in 386 hardware */
name|int
name|tf_err
decl_stmt|;
name|int
name|tf_eip
decl_stmt|;
name|int
name|tf_cs
decl_stmt|;
name|int
name|tf_eflags
decl_stmt|;
comment|/* below only when crossing rings (user to kernel) */
name|int
name|tf_esp
decl_stmt|;
name|int
name|tf_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Superset of trap frame, for traps from virtual-8086 mode */
end_comment

begin_struct
struct|struct
name|trapframe_vm86
block|{
name|int
name|tf_fs
decl_stmt|;
name|int
name|tf_es
decl_stmt|;
name|int
name|tf_ds
decl_stmt|;
name|int
name|tf_edi
decl_stmt|;
name|int
name|tf_esi
decl_stmt|;
name|int
name|tf_ebp
decl_stmt|;
name|int
name|tf_isp
decl_stmt|;
name|int
name|tf_ebx
decl_stmt|;
name|int
name|tf_edx
decl_stmt|;
name|int
name|tf_ecx
decl_stmt|;
name|int
name|tf_eax
decl_stmt|;
name|int
name|tf_trapno
decl_stmt|;
comment|/* below portion defined in 386 hardware */
name|int
name|tf_err
decl_stmt|;
name|int
name|tf_eip
decl_stmt|;
name|int
name|tf_cs
decl_stmt|;
name|int
name|tf_eflags
decl_stmt|;
comment|/* below only when crossing rings (user (including vm86) to kernel) */
name|int
name|tf_esp
decl_stmt|;
name|int
name|tf_ss
decl_stmt|;
comment|/* below only when crossing from vm86 mode to kernel */
name|int
name|tf_vm86_es
decl_stmt|;
name|int
name|tf_vm86_ds
decl_stmt|;
name|int
name|tf_vm86_fs
decl_stmt|;
name|int
name|tf_vm86_gs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This alias for the MI TRAPF_USERMODE() should be used when we don't  * care about user mode itself, but need to know if a frame has stack  * registers.  The difference is only logical, but on i386 the logic  * for using TRAPF_USERMODE() is complicated by sometimes treating vm86  * bioscall mode (which is a special ring 3 user mode) as kernel mode.  */
end_comment

begin_define
define|#
directive|define
name|TF_HAS_STACKREGS
parameter_list|(
name|tf
parameter_list|)
value|TRAPF_USERMODE(tf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_comment
comment|/*  * Exception/Trap Stack Frame  *  * The ordering of this is specifically so that we can take first 6  * the syscall arguments directly from the beginning of the frame.  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|register_t
name|tf_rdi
decl_stmt|;
name|register_t
name|tf_rsi
decl_stmt|;
name|register_t
name|tf_rdx
decl_stmt|;
name|register_t
name|tf_rcx
decl_stmt|;
name|register_t
name|tf_r8
decl_stmt|;
name|register_t
name|tf_r9
decl_stmt|;
name|register_t
name|tf_rax
decl_stmt|;
name|register_t
name|tf_rbx
decl_stmt|;
name|register_t
name|tf_rbp
decl_stmt|;
name|register_t
name|tf_r10
decl_stmt|;
name|register_t
name|tf_r11
decl_stmt|;
name|register_t
name|tf_r12
decl_stmt|;
name|register_t
name|tf_r13
decl_stmt|;
name|register_t
name|tf_r14
decl_stmt|;
name|register_t
name|tf_r15
decl_stmt|;
name|uint32_t
name|tf_trapno
decl_stmt|;
name|uint16_t
name|tf_fs
decl_stmt|;
name|uint16_t
name|tf_gs
decl_stmt|;
name|register_t
name|tf_addr
decl_stmt|;
name|uint32_t
name|tf_flags
decl_stmt|;
name|uint16_t
name|tf_es
decl_stmt|;
name|uint16_t
name|tf_ds
decl_stmt|;
comment|/* below portion defined in hardware */
name|register_t
name|tf_err
decl_stmt|;
name|register_t
name|tf_rip
decl_stmt|;
name|register_t
name|tf_cs
decl_stmt|;
name|register_t
name|tf_rflags
decl_stmt|;
comment|/* the amd64 frame always has the stack registers */
name|register_t
name|tf_rsp
decl_stmt|;
name|register_t
name|tf_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TF_HASSEGS
value|0x1
end_define

begin_define
define|#
directive|define
name|TF_HASBASES
value|0x2
end_define

begin_define
define|#
directive|define
name|TF_HASFPXSTATE
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __amd64__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FRAME_H_ */
end_comment

end_unit

