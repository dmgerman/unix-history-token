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
file|<sys/bus.h>
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
file|<sys/ipl.h>
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
file|<sys/mutex.h>
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
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
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
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_decl_stmt
specifier|static
name|u_int
name|straycount
index|[
name|NHWI
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_STRAY_LOG
value|5
end_define

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
name|struct
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
comment|/* 	 * If we don't have an interrupt resource or an interrupt thread for 	 * this IRQ, log it as a stray interrupt. 	 */
if|if
condition|(
name|ir
operator|==
name|NULL
operator|||
name|ir
operator|->
name|it_proc
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|straycount
index|[
name|irq
index|]
operator|<
name|MAX_STRAY_LOG
condition|)
block|{
name|printf
argument_list|(
literal|"stray irq %d\n"
argument_list|,
name|irq
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|straycount
index|[
name|irq
index|]
operator|==
name|MAX_STRAY_LOG
condition|)
name|printf
argument_list|(
literal|"got %d stray irq %d's: not logging anymore\n"
argument_list|,
name|MAX_STRAY_LOG
argument_list|,
name|irq
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
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
name|need_resched
argument_list|()
expr_stmt|;
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
name|struct
name|ithd
modifier|*
name|me
decl_stmt|;
comment|/* our thread context */
name|struct
name|intrhand
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
comment|/* 		 * If we don't have any handlers, then we are an orphaned 		 * thread and just need to die. 		 */
if|if
condition|(
name|me
operator|->
name|it_ih
operator|==
name|NULL
condition|)
block|{
name|CTR2
argument_list|(
name|KTR_INTR
argument_list|,
literal|"ithd_loop pid %d(%s) exiting"
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
argument_list|)
expr_stmt|;
name|curproc
operator|->
name|p_ithd
operator|=
name|NULL
expr_stmt|;
name|free
argument_list|(
name|me
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
name|mtx_enter
argument_list|(
operator|&
name|Giant
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
name|kthread_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
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
name|ih_next
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
name|ih_handler
argument_list|,
name|ih
operator|->
name|ih_argument
argument_list|,
name|ih
operator|->
name|ih_flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ih
operator|->
name|ih_flags
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
name|ih_handler
argument_list|(
name|ih
operator|->
name|ih_argument
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ih
operator|->
name|ih_flags
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
name|mtx_assert
argument_list|(
operator|&
name|Giant
argument_list|,
name|MA_NOTOWNED
argument_list|)
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

end_unit

