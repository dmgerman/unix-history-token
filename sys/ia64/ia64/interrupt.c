begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: interrupt.c,v 1.23 1998/02/24 07:38:01 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Keith Bostic, Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Additional Copyright (c) 1997 by Matthew Jacob for NASA/Ames Research Center.  * Redistribute and modify at will, leaving only this additional copyright  * notice.  */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* RCS ID& Copyright macro defns */
end_comment

begin_comment
comment|/* __KERNEL_RCSID(0, "$NetBSD: interrupt.c,v 1.23 1998/02/24 07:38:01 thorpej Exp $");*/
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EVCNT_COUNTERS
end_ifdef

begin_decl_stmt
name|struct
name|evcnt
name|clock_intr_evcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event counter for clock intrs. */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/intrcnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|volatile
name|int
name|mc_expected
decl_stmt|,
name|mc_received
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|dummy_perf
parameter_list|(
name|unsigned
name|long
name|vector
parameter_list|,
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|printf
argument_list|(
literal|"performance interrupt!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
name|perf_irq
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
init|=
name|dummy_perf
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|u_int
name|schedclk2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|interrupt
parameter_list|(
name|a0
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|framep
parameter_list|)
name|unsigned
name|long
name|a0
decl_stmt|,
name|a1
decl_stmt|,
name|a2
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|framep
decl_stmt|;
block|{
if|#
directive|if
literal|0
comment|/* 	 * Find our per-cpu globals. 	 */
block|globalp = (struct globaldata *) alpha_pal_rdval();  	atomic_add_int(&PCPU_GET(intr_nesting_level), 1); 	{ 		struct proc* p = curproc; 		if (!p) p =&proc0; 		if ((caddr_t) framep< (caddr_t) p->p_addr + 1024) { 			mtx_enter(&Giant, MTX_DEF); 			panic("possible stack overflow\n"); 		} 	}  	framep->tf_regs[FRAME_TRAPARG_A0] = a0; 	framep->tf_regs[FRAME_TRAPARG_A1] = a1; 	framep->tf_regs[FRAME_TRAPARG_A2] = a2; 	switch (a0) { 	case ALPHA_INTR_XPROC:
comment|/* interprocessor interrupt */
block|CTR0(KTR_INTR|KTR_SMP, "interprocessor interrupt"); 		smp_handle_ipi(framep);
comment|/* note: lock not taken */
block|break; 		 	case ALPHA_INTR_CLOCK:
comment|/* clock interrupt */
block|CTR0(KTR_INTR, "clock interrupt"); 		if (PCPU_GET(cpuno) != hwrpb->rpb_primary_cpu_id) { 			CTR0(KTR_INTR, "ignoring clock on secondary"); 			return; 		} 			 		mtx_enter(&Giant, MTX_DEF); 		cnt.v_intr++;
ifdef|#
directive|ifdef
name|EVCNT_COUNTERS
block|clock_intr_evcnt.ev_count++;
else|#
directive|else
block|intrcnt[INTRCNT_CLOCK]++;
endif|#
directive|endif
block|if (platform.clockintr){ 			(*platform.clockintr)(framep);
comment|/* divide hz (1024) by 8 to get stathz (128) */
block|if((++schedclk2& 0x7) == 0) 				statclock((struct clockframe *)framep); 		} 		mtx_exit(&Giant, MTX_DEF); 		break;  	case  ALPHA_INTR_ERROR:
comment|/* Machine Check or Correctable Error */
block|mtx_enter(&Giant, MTX_DEF); 		a0 = alpha_pal_rdmces(); 		if (platform.mcheck_handler) 			(*platform.mcheck_handler)(a0, framep, a1, a2); 		else 			machine_check(a0, framep, a1, a2); 		mtx_exit(&Giant, MTX_DEF); 		break;  	case ALPHA_INTR_DEVICE:
comment|/* I/O device interrupt */
block|mtx_enter(&Giant, MTX_DEF); 		cnt.v_intr++; 		if (platform.iointr) 			(*platform.iointr)(framep, a1); 		mtx_exit(&Giant, MTX_DEF); 		break;  	case ALPHA_INTR_PERF:
comment|/* interprocessor interrupt */
block|mtx_enter(&Giant, MTX_DEF); 		perf_irq(a1, framep); 		mtx_exit(&Giant, MTX_DEF); 		break;  	case ALPHA_INTR_PASSIVE:
if|#
directive|if
literal|0
block|printf("passive release interrupt vec 0x%lx (ignoring)\n", a1);
endif|#
directive|endif
block|break;  	default: 		mtx_enter(&Giant, MTX_DEF); 		panic("unexpected interrupt: type 0x%lx vec 0x%lx a2 0x%lx\n", 		    a0, a1, a2);
comment|/* NOTREACHED */
block|} 	atomic_subtract_int(&PCPU_GET(intr_nesting_level), 1);
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|badaddr
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
name|void
modifier|*
name|addr
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|{
return|return
operator|(
name|badaddr_read
argument_list|(
name|addr
argument_list|,
name|size
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|badaddr_read
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|,
name|rptr
parameter_list|)
name|void
modifier|*
name|addr
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|void
modifier|*
name|rptr
decl_stmt|;
block|{
return|return
operator|(
literal|1
operator|)
return|;
comment|/* XXX implement */
block|}
end_function

end_unit

