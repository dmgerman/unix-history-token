begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Matthew Dillon.  This code is distributed under  * the BSD copyright, /usr/src/COPYRIGHT.  *  * $FreeBSD$  */
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
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_comment
comment|/* XX */
end_comment

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_comment
comment|/* XX */
end_comment

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_comment
comment|/* XX */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_function
name|void
name|cpu_critical_enter
parameter_list|(
name|void
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
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|cpu_critical_exit
parameter_list|(
name|void
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
name|intr_restore
argument_list|(
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * cpu_critical_fork_exit() - cleanup after fork  */
end_comment

begin_function
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
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
name|td
operator|->
name|td_critnest
operator|=
literal|1
expr_stmt|;
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
operator|=
operator|(
name|ia64_get_psr
argument_list|()
operator||
name|IA64_PSR_I
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * cpu_thread_link() - thread linkup, initialize machine-dependant fields  */
end_comment

begin_function
name|void
name|cpu_thread_link
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|td
operator|->
name|td_md
operator|.
name|md_savecrit
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

