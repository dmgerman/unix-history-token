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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
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
file|<sys/interrupt.h>
end_include

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
name|u_int64_t
name|vector
parameter_list|,
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|atomic_add_int
argument_list|(
operator|&
name|td
operator|->
name|td_intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|vector
condition|)
block|{
case|case
literal|240
case|:
comment|/* clock interrupt */
name|CTR0
argument_list|(
name|KTR_INTR
argument_list|,
literal|"clock interrupt"
argument_list|)
expr_stmt|;
name|cnt
operator|.
name|v_intr
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|EVCNT_COUNTERS
name|clock_intr_evcnt
operator|.
name|ev_count
operator|++
expr_stmt|;
else|#
directive|else
name|intrcnt
index|[
name|INTRCNT_CLOCK
index|]
operator|++
expr_stmt|;
endif|#
directive|endif
name|handleclock
argument_list|(
name|framep
argument_list|)
expr_stmt|;
comment|/* divide hz (1024) by 8 to get stathz (128) */
if|if
condition|(
operator|(
operator|++
name|schedclk2
operator|&
literal|0x7
operator|)
operator|==
literal|0
condition|)
name|statclock
argument_list|(
operator|(
expr|struct
name|clockframe
operator|*
operator|)
name|framep
argument_list|)
expr_stmt|;
break|break;
default|default:
name|mtx_lock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"unexpected interrupt: vec %ld\n"
argument_list|,
name|vector
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
name|atomic_subtract_int
argument_list|(
operator|&
name|td
operator|->
name|td_intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
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

