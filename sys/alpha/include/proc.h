begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: proc.h,v 1.3 1997/04/06 08:47:36 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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
comment|/*  * Machine-dependent part of the proc struct for the Alpha.  */
end_comment

begin_struct
struct|struct
name|mdbpt
block|{
name|vm_offset_t
name|addr
decl_stmt|;
name|u_int32_t
name|contents
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdthread
block|{
name|u_long
name|md_flags
decl_stmt|;
name|struct
name|pcb
modifier|*
name|md_pcbpaddr
decl_stmt|;
comment|/* phys addr of the pcb */
name|struct
name|mdbpt
name|md_sstep
index|[
literal|2
index|]
decl_stmt|;
comment|/* two single step breakpoints */
name|u_int64_t
name|md_hae
decl_stmt|;
comment|/* user HAE register value */
name|void
modifier|*
name|osf_sigtramp
decl_stmt|;
comment|/* user-level signal trampoline */
name|u_int
name|md_kernnest
decl_stmt|;
comment|/* nesting level in the kernel */
name|register_t
name|md_savecrit
decl_stmt|;
comment|/* save PSL for critical section */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MDP_FPUSED
value|0x0001
end_define

begin_comment
comment|/* Process used the FPU */
end_comment

begin_define
define|#
directive|define
name|MDP_STEP1
value|0x0002
end_define

begin_comment
comment|/* Single step normal instruction */
end_comment

begin_define
define|#
directive|define
name|MDP_STEP2
value|0x0004
end_define

begin_comment
comment|/* Single step branch instruction */
end_comment

begin_define
define|#
directive|define
name|MDP_HAEUSED
value|0x0008
end_define

begin_comment
comment|/* Process used the HAE */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_NOPRINT
value|0x0010
end_define

begin_comment
comment|/* Don't print unaligned traps */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_NOFIX
value|0x0020
end_define

begin_comment
comment|/* Don't fixup unaligned traps */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_SIGBUS
value|0x0040
end_define

begin_comment
comment|/* Deliver SIGBUS upon 					   unaligned access */
end_comment

begin_define
define|#
directive|define
name|MDP_UAC_MASK
value|(MDP_UAC_NOPRINT | MDP_UAC_NOFIX | MDP_UAC_SIGBUS)
end_define

begin_struct
struct|struct
name|mdproc
block|{ }
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

