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
name|int
name|md_upte
index|[
name|KSTACK_PAGES
operator|-
literal|1
index|]
decl_stmt|;
comment|/* ptes for mapping u pcb */
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
name|vm_offset_t
name|md_realstack
decl_stmt|;
name|void
modifier|*
name|md_tls
decl_stmt|;
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

begin_struct
struct|struct
name|mdproc
block|{
comment|/* empty */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|mips_cpu_switch
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_cpu_throw
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROC_H_ */
end_comment

end_unit

