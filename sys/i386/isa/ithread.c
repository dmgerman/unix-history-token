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
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

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

begin_struct
struct|struct
name|int_entropy
block|{
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|int
name|irq
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* 	 * If this interrupt is marked as being a source of entropy, use 	 * the current timestamp to feed entropy to the PRNG. 	 */
if|if
condition|(
name|harvest
operator|.
name|interrupt
operator|&&
name|ir
operator|!=
name|NULL
operator|&&
operator|(
name|ir
operator|->
name|it_flags
operator|&
name|IT_ENTROPY
operator|)
condition|)
block|{
name|struct
name|int_entropy
name|entropy
decl_stmt|;
name|entropy
operator|.
name|irq
operator|=
name|irq
expr_stmt|;
name|entropy
operator|.
name|p
operator|=
name|curproc
expr_stmt|;
name|random_harvest
argument_list|(
operator|&
name|entropy
argument_list|,
sizeof|sizeof
argument_list|(
name|entropy
argument_list|)
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|RANDOM_INTERRUPT
argument_list|)
expr_stmt|;
block|}
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
name|mtx_lock_spin
argument_list|(
operator|&
name|sched_lock
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
if|if
condition|(
operator|!
name|cold
condition|)
block|{
if|if
condition|(
name|curproc
operator|!=
name|PCPU_GET
argument_list|(
name|idleproc
argument_list|)
condition|)
name|setrunqueue
argument_list|(
name|curproc
argument_list|)
expr_stmt|;
name|curproc
operator|->
name|p_stats
operator|->
name|p_ru
operator|.
name|ru_nvcsw
operator|++
expr_stmt|;
name|mi_switch
argument_list|()
expr_stmt|;
block|}
else|else
name|need_resched
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
name|mtx_unlock_spin
argument_list|(
operator|&
name|sched_lock
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

