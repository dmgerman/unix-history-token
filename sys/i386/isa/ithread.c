begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From BSDI: intr.c,v 1.6.2.5 1999/07/06 19:16:52 cp Exp  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Interrupt thread code. */
end_comment

begin_include
include|#
directive|include
file|"opt_auto_eoi.h"
end_include

begin_include
include|#
directive|include
file|"isa.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_comment
comment|/* change this name XXX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_include
include|#
directive|include
file|<machine/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/smptests.h>
end_include

begin_comment
comment|/** FAST_HI */
end_comment

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/pc98_machdep.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/epsonio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_if
if|#
directive|if
name|NISA
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i386/isa/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mca.h"
end_include

begin_if
if|#
directive|if
name|NMCA
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<i386/isa/mca_machdep.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

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
name|u_long
name|softintrcnt
index|[
name|NSWI
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|SYSINIT
argument_list|(
argument|start_softintr
argument_list|,
argument|SI_SUB_SOFTINTR
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|start_softintr
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/*  * Schedule a heavyweight interrupt process.  This function is called  * from the interrupt handlers Xintr<num>.  */
end_comment

begin_function
name|void
name|sched_ithd
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
block|{
name|int
name|irq
init|=
operator|(
name|int
operator|)
name|cookie
decl_stmt|;
comment|/* IRQ we're handling */
name|ithd
modifier|*
name|ir
init|=
name|ithds
index|[
name|irq
index|]
decl_stmt|;
comment|/* and the process that does it */
comment|/* This used to be in icu_vector.s */
comment|/* 	 * We count software interrupts when we process them.  The 	 * code here follows previous practice, but there's an 	 * argument for counting hardware interrupts when they're 	 * processed too. 	 */
if|if
condition|(
name|irq
operator|<
name|NHWI
condition|)
comment|/* real interrupt, */
name|atomic_add_long
argument_list|(
name|intr_countp
index|[
name|irq
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* one more for this IRQ */
name|atomic_add_int
argument_list|(
operator|&
name|cnt
operator|.
name|v_intr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* one more global interrupt */
name|CTR3
argument_list|(
name|KTR_INTR
argument_list|,
literal|"sched_ithd pid %d(%s) need=%d"
argument_list|,
name|ir
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|,
name|ir
operator|->
name|it_proc
operator|->
name|p_comm
argument_list|,
name|ir
operator|->
name|it_need
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* 	 * If we are in the debugger, we can't use interrupt threads to 	 * process interrupts since the threads are scheduled.  Instead, 	 * call the interrupt handlers directly.  This should be able to 	 * go away once we have light-weight interrupt handlers. 	 */
block|if (db_active) { 		intrec	*ih;
comment|/* and our interrupt handler chain */
if|#
directive|if
literal|0
block|membar_unlock();
comment|/* push out "it_need=0" */
endif|#
directive|endif
block|for (ih = ir->it_ih; ih != NULL; ih = ih->next) { 			if ((ih->flags& INTR_MPSAFE) == 0) 				mtx_enter(&Giant, MTX_DEF); 			ih->handler(ih->argument); 			if ((ih->flags& INTR_MPSAFE) == 0) 				mtx_exit(&Giant, MTX_DEF); 		}  		INTREN (1<< ir->irq);
comment|/* reset the mask bit */
block|return; 	}
endif|#
directive|endif
comment|/* 	 * Set it_need so that if the thread is already running but close 	 * to done, it will do another go-round.  Then get the sched lock 	 * and see if the thread is on whichkqs yet.  If not, put it on 	 * there.  In any case, kick everyone so that if the new thread 	 * is higher priority than their current thread, it gets run now. 	 */
name|ir
operator|->
name|it_need
operator|=
literal|1
expr_stmt|;
name|mtx_enter
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
if|if
condition|(
name|ir
operator|->
name|it_proc
operator|->
name|p_stat
operator|==
name|SWAIT
condition|)
block|{
comment|/* not on run queue */
name|CTR1
argument_list|(
name|KTR_INTR
argument_list|,
literal|"sched_ithd: setrunqueue %d"
argument_list|,
name|ir
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|)
expr_stmt|;
comment|/*		membar_lock(); */
name|ir
operator|->
name|it_proc
operator|->
name|p_stat
operator|=
name|SRUN
expr_stmt|;
name|setrunqueue
argument_list|(
name|ir
operator|->
name|it_proc
argument_list|)
expr_stmt|;
name|aston
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|irq
operator|<
name|NHWI
operator|&&
operator|(
name|irq
operator|&
literal|7
operator|)
operator|!=
literal|0
condition|)
name|CTR3
argument_list|(
name|KTR_INTR
argument_list|,
literal|"sched_ithd %d: it_need %d, state %d"
argument_list|,
name|ir
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|,
name|ir
operator|->
name|it_need
argument_list|,
name|ir
operator|->
name|it_proc
operator|->
name|p_stat
argument_list|)
expr_stmt|;
block|}
name|mtx_exit
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|aston();
comment|/* ??? check priorities first? */
else|#
directive|else
name|need_resched
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * This is the main code for all interrupt threads.  It gets put on  * whichkqs by setrunqueue above.  */
end_comment

begin_function
name|void
name|ithd_loop
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|ithd
modifier|*
name|me
decl_stmt|;
comment|/* our thread context */
name|intrec
modifier|*
name|ih
decl_stmt|;
comment|/* and our interrupt handler chain */
name|me
operator|=
name|curproc
operator|->
name|p_ithd
expr_stmt|;
comment|/* point to myself */
comment|/* 	 * As long as we have interrupts outstanding, go through the 	 * list of handlers, giving each one a go at it. 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
name|CTR3
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d(%s) need=%d"
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_comm
argument_list|,
name|me
operator|->
name|it_need
argument_list|)
expr_stmt|;
while|while
condition|(
name|me
operator|->
name|it_need
condition|)
block|{
comment|/* 			 * Service interrupts.  If another interrupt 			 * arrives while we are running, they will set 			 * it_need to denote that we should make 			 * another pass. 			 */
name|me
operator|->
name|it_need
operator|=
literal|0
expr_stmt|;
if|#
directive|if
literal|0
block|membar_unlock();
comment|/* push out "it_need=0" */
endif|#
directive|endif
for|for
control|(
name|ih
operator|=
name|me
operator|->
name|it_ih
init|;
name|ih
operator|!=
name|NULL
condition|;
name|ih
operator|=
name|ih
operator|->
name|next
control|)
block|{
name|CTR5
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d ih=%p: %p(%p) flg=%x"
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|,
operator|(
name|void
operator|*
operator|)
name|ih
argument_list|,
operator|(
name|void
operator|*
operator|)
name|ih
operator|->
name|handler
argument_list|,
name|ih
operator|->
name|argument
argument_list|,
name|ih
operator|->
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ih
operator|->
name|flags
operator|&
name|INTR_MPSAFE
operator|)
operator|==
literal|0
condition|)
name|mtx_enter
argument_list|(
operator|&
name|Giant
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
name|ih
operator|->
name|handler
argument_list|(
name|ih
operator|->
name|argument
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ih
operator|->
name|flags
operator|&
name|INTR_MPSAFE
operator|)
operator|==
literal|0
condition|)
name|mtx_exit
argument_list|(
operator|&
name|Giant
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 		 * Processed all our interrupts.  Now get the sched 		 * lock.  This may take a while and it_need may get 		 * set again, so we have to check it again. 		 */
name|mtx_enter
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|me
operator|->
name|it_need
condition|)
block|{
name|INTREN
argument_list|(
literal|1
operator|<<
name|me
operator|->
name|irq
argument_list|)
expr_stmt|;
comment|/* reset the mask bit */
name|me
operator|->
name|it_proc
operator|->
name|p_stat
operator|=
name|SWAIT
expr_stmt|;
comment|/* we're idle */
ifdef|#
directive|ifdef
name|APIC_IO
name|CTR1
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d: done"
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|)
expr_stmt|;
else|#
directive|else
name|CTR2
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d: done, imen=%x"
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|,
name|imen
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mi_switch
argument_list|()
expr_stmt|;
name|CTR1
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d: resumed"
argument_list|,
name|me
operator|->
name|it_proc
operator|->
name|p_pid
argument_list|)
expr_stmt|;
block|}
name|mtx_exit
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Start soft interrupt thread.  */
end_comment

begin_function
name|void
name|start_softintr
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|ithd
modifier|*
name|softintr
decl_stmt|;
comment|/* descriptor for the "IRQ" */
name|intrec
modifier|*
name|idesc
decl_stmt|;
comment|/* descriptor for this handler */
name|char
modifier|*
name|name
init|=
literal|"sintr"
decl_stmt|;
comment|/* name for idesc */
name|int
name|i
decl_stmt|;
if|if
condition|(
name|ithds
index|[
name|SOFTINTR
index|]
condition|)
block|{
comment|/* we already have a thread */
name|printf
argument_list|(
literal|"start_softintr: already running"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* first handler for this irq. */
name|softintr
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ithd
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|softintr
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"Can't create soft interrupt thread"
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|softintr
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ithd
argument_list|)
argument_list|)
expr_stmt|;
name|softintr
operator|->
name|irq
operator|=
name|SOFTINTR
expr_stmt|;
name|ithds
index|[
name|SOFTINTR
index|]
operator|=
name|softintr
expr_stmt|;
name|error
operator|=
name|kthread_create
argument_list|(
name|intr_soft
argument_list|,
name|NULL
argument_list|,
operator|&
name|p
argument_list|,
name|RFSTOPPED
operator||
name|RFHIGHPID
argument_list|,
literal|"softinterrupt"
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|panic
argument_list|(
literal|"start_softintr: kthread_create error %d\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|p
operator|->
name|p_rtprio
operator|.
name|type
operator|=
name|RTP_PRIO_ITHREAD
expr_stmt|;
name|p
operator|->
name|p_rtprio
operator|.
name|prio
operator|=
name|PI_SOFT
expr_stmt|;
comment|/* soft interrupt */
name|p
operator|->
name|p_stat
operator|=
name|SWAIT
expr_stmt|;
comment|/* we're idle */
comment|/* Put in linkages. */
name|softintr
operator|->
name|it_proc
operator|=
name|p
expr_stmt|;
name|p
operator|->
name|p_ithd
operator|=
name|softintr
expr_stmt|;
comment|/* reverse link */
name|idesc
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|intrec
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|idesc
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"Can't create soft interrupt thread"
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|idesc
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|intrec
argument_list|)
argument_list|)
expr_stmt|;
name|idesc
operator|->
name|ithd
operator|=
name|softintr
expr_stmt|;
name|idesc
operator|->
name|name
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
literal|1
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|idesc
operator|->
name|name
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"Can't create soft interrupt thread"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|idesc
operator|->
name|name
argument_list|,
name|name
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|NHWI
init|;
name|i
operator|<
name|NHWI
operator|+
name|NSWI
condition|;
name|i
operator|++
control|)
name|intr_countp
index|[
name|i
index|]
operator|=
operator|&
name|softintrcnt
index|[
name|i
operator|-
name|NHWI
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Software interrupt process code.  */
end_comment

begin_function
name|void
name|intr_soft
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|ithd
modifier|*
name|me
decl_stmt|;
comment|/* our thread context */
name|me
operator|=
name|curproc
operator|->
name|p_ithd
expr_stmt|;
comment|/* point to myself */
comment|/* Main loop */
for|for
control|(
init|;
condition|;
control|)
block|{
if|#
directive|if
literal|0
block|CTR3(KTR_INTR, "intr_soft pid %d(%s) need=%d", 		    me->it_proc->p_pid, me->it_proc->p_comm, 		     me->it_need);
endif|#
directive|endif
comment|/* 		 * Service interrupts.  If another interrupt arrives 		 * while we are running, they will set it_need to 		 * denote that we should make another pass. 		 */
name|me
operator|->
name|it_need
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|i
operator|=
name|ffs
argument_list|(
name|spending
argument_list|)
operator|)
condition|)
block|{
name|i
operator|--
expr_stmt|;
name|atomic_add_long
argument_list|(
name|intr_countp
index|[
name|i
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spending
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
name|mtx_enter
argument_list|(
operator|&
name|Giant
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
if|if
condition|(
name|ihandlers
index|[
name|i
index|]
operator|==
name|swi_generic
condition|)
name|swi_dispatcher
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
operator|(
name|ihandlers
index|[
name|i
index|]
operator|)
operator|(
operator|)
expr_stmt|;
name|mtx_exit
argument_list|(
operator|&
name|Giant
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * Processed all our interrupts.  Now get the sched 		 * lock.  This may take a while and it_need may get 		 * set again, so we have to check it again. 		 */
name|mtx_enter
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|me
operator|->
name|it_need
condition|)
block|{
if|#
directive|if
literal|0
block|CTR1(KTR_INTR, "intr_soft pid %d: done", 			    me->it_proc->p_pid);
endif|#
directive|endif
name|me
operator|->
name|it_proc
operator|->
name|p_stat
operator|=
name|SWAIT
expr_stmt|;
comment|/* we're idle */
name|mi_switch
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|CTR1(KTR_INTR, "intr_soft pid %d: resumed", 			    me->it_proc->p_pid);
endif|#
directive|endif
block|}
name|mtx_exit
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

