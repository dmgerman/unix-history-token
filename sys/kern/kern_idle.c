begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000, All rights reserved.  See /usr/src/COPYRIGHT  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_ktrace.h"
end_include

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KTRACE
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktrace.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SMP_DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/intr_machdep.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|idle_setup
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|SYSINIT
argument_list|(
argument|idle_setup
argument_list|,
argument|SI_SUB_SCHED_IDLE
argument_list|,
argument|SI_ORDER_FIRST
argument_list|,
argument|idle_setup
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_function_decl
specifier|static
name|void
name|idle_proc
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * setup per-cpu idle process contexts  */
end_comment

begin_function
specifier|static
name|void
name|idle_setup
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|struct
name|globaldata
modifier|*
name|gd
decl_stmt|;
name|int
name|error
decl_stmt|;
name|SLIST_FOREACH
argument_list|(
argument|gd
argument_list|,
argument|&cpuhead
argument_list|,
argument|gd_allcpu
argument_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
name|error
operator|=
name|kthread_create
argument_list|(
name|idle_proc
argument_list|,
name|NULL
argument_list|,
operator|&
name|gd
operator|->
name|gd_idleproc
argument_list|,
name|RFSTOPPED
operator||
name|RFHIGHPID
argument_list|,
literal|"idle: cpu%d"
argument_list|,
name|gd
operator|->
name|gd_cpuid
argument_list|)
expr_stmt|;
else|#
directive|else
name|error
operator|=
name|kthread_create
argument_list|(
name|idle_proc
argument_list|,
name|NULL
argument_list|,
operator|&
name|gd
operator|->
name|gd_idleproc
argument_list|,
name|RFSTOPPED
operator||
name|RFHIGHPID
argument_list|,
literal|"idle"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error
condition|)
name|panic
argument_list|(
literal|"idle_setup: kthread_create error %d\n"
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|gd
operator|->
name|gd_idleproc
operator|->
name|p_stat
operator|=
name|SRUN
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * idle process context  */
end_comment

begin_function
specifier|static
name|void
name|idle_proc
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|int
name|count
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* 		 * Clear switchtime, which prevents the idle process's time 		 * from being counted. 		switchtime.tv_usec = 0; 		switchtime.tv_sec = 0; 		 */
name|mtx_assert
argument_list|(
operator|&
name|Giant
argument_list|,
name|MA_NOTOWNED
argument_list|)
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|count
operator|>=
literal|0
operator|&&
name|procrunnable
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|/* 		 * This is a good place to put things to be done in 		 * the background, including sanity checks. 		 */
if|if
condition|(
name|count
operator|++
operator|<
literal|0
condition|)
name|CTR0
argument_list|(
name|KTR_PROC
argument_list|,
literal|"idle_proc: timed out waiting"
literal|" for a process"
argument_list|)
expr_stmt|;
block|}
name|mtx_enter
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
name|mi_switch
argument_list|()
expr_stmt|;
name|mtx_exit
argument_list|(
operator|&
name|sched_lock
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
name|spl0
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

