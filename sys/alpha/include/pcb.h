begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: pcb.h,v 1.6 1997/04/06 08:47:33 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_comment
comment|/*  * PCB: process control block  *  * In this case, the hardware structure that is the defining element  * for a process, and the additional state that must be saved by software  * on a context switch.  Fields marked [HW] are mandated by hardware; fields  * marked [SW] are for the software.  *  * It's said in the VMS PALcode section of the AARM that the pcb address  * passed to the swpctx PALcode call has to be a physical address.  Not  * knowing this (and trying a virtual) address proved this correct.  * So we cache the physical address of the pcb in the md_proc struct.  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|alpha_pcb
name|pcb_hw
decl_stmt|;
comment|/* PALcode defined */
name|unsigned
name|long
name|pcb_context
index|[
literal|9
index|]
decl_stmt|;
comment|/* s[0-6], ra, ps	[SW] */
name|struct
name|fpreg
name|pcb_fp
decl_stmt|;
comment|/* FP registers		[SW] */
name|u_int64_t
name|pcb_fp_control
decl_stmt|;
comment|/* IEEE control word	[SW] */
name|unsigned
name|long
name|pcb_onfault
decl_stmt|;
comment|/* for copy faults	[SW] */
name|unsigned
name|long
name|pcb_accessaddr
decl_stmt|;
comment|/* for [fs]uswintr	[SW] */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the Alpha, that's a trap frame and the floating  * point registers.  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|struct
name|trapframe
name|md_tf
decl_stmt|;
name|struct
name|fpreg
name|md_fpstate
decl_stmt|;
block|}
struct|;
end_struct

end_unit

