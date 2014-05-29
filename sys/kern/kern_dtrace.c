begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008 John Birrell<jb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_kdb.h"
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
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/dtrace_bsd.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_define
define|#
directive|define
name|KDTRACE_PROC_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|KDTRACE_THREAD_SIZE
value|256
end_define

begin_expr_stmt
name|FEATURE
argument_list|(
name|kdtrace_hooks
argument_list|,
literal|"Kernel DTrace hooks which are required to load DTrace kernel modules"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_KDTRACE
argument_list|,
literal|"kdtrace"
argument_list|,
literal|"DTrace hooks"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Hooks used in the machine-dependent trap handlers. */
end_comment

begin_decl_stmt
name|dtrace_trap_func_t
name|dtrace_trap_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dtrace_doubletrap_func_t
name|dtrace_doubletrap_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dtrace_pid_probe_ptr_t
name|dtrace_pid_probe_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dtrace_return_probe_ptr_t
name|dtrace_return_probe_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|systrace_probe_func_t
name|systrace_probe_func
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the DTrace process data size compiled in the kernel hooks. */
end_comment

begin_function
name|size_t
name|kdtrace_proc_size
parameter_list|()
block|{
return|return
operator|(
name|KDTRACE_PROC_SIZE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|kdtrace_proc_ctor
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|p_dtrace
operator|=
name|malloc
argument_list|(
name|KDTRACE_PROC_SIZE
argument_list|,
name|M_KDTRACE
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|kdtrace_proc_dtor
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|p
operator|->
name|p_dtrace
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|p
operator|->
name|p_dtrace
argument_list|,
name|M_KDTRACE
argument_list|)
expr_stmt|;
name|p
operator|->
name|p_dtrace
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Return the DTrace thread data size compiled in the kernel hooks. */
end_comment

begin_function
name|size_t
name|kdtrace_thread_size
parameter_list|()
block|{
return|return
operator|(
name|KDTRACE_THREAD_SIZE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|kdtrace_thread_ctor
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|td
operator|->
name|td_dtrace
operator|=
name|malloc
argument_list|(
name|KDTRACE_THREAD_SIZE
argument_list|,
name|M_KDTRACE
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|kdtrace_thread_dtor
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
if|if
condition|(
name|td
operator|->
name|td_dtrace
operator|!=
name|NULL
condition|)
block|{
name|free
argument_list|(
name|td
operator|->
name|td_dtrace
argument_list|,
name|M_KDTRACE
argument_list|)
expr_stmt|;
name|td
operator|->
name|td_dtrace
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  *  Initialise the kernel DTrace hooks.  */
end_comment

begin_function
specifier|static
name|void
name|init_dtrace
parameter_list|(
name|void
modifier|*
name|dummy
name|__unused
parameter_list|)
block|{
name|EVENTHANDLER_REGISTER
argument_list|(
name|process_ctor
argument_list|,
name|kdtrace_proc_ctor
argument_list|,
name|NULL
argument_list|,
name|EVENTHANDLER_PRI_ANY
argument_list|)
expr_stmt|;
name|EVENTHANDLER_REGISTER
argument_list|(
name|process_dtor
argument_list|,
name|kdtrace_proc_dtor
argument_list|,
name|NULL
argument_list|,
name|EVENTHANDLER_PRI_ANY
argument_list|)
expr_stmt|;
name|EVENTHANDLER_REGISTER
argument_list|(
name|thread_ctor
argument_list|,
name|kdtrace_thread_ctor
argument_list|,
name|NULL
argument_list|,
name|EVENTHANDLER_PRI_ANY
argument_list|)
expr_stmt|;
name|EVENTHANDLER_REGISTER
argument_list|(
name|thread_dtor
argument_list|,
name|kdtrace_thread_dtor
argument_list|,
name|NULL
argument_list|,
name|EVENTHANDLER_PRI_ANY
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|kdtrace
argument_list|,
name|SI_SUB_KDTRACE
argument_list|,
name|SI_ORDER_FIRST
argument_list|,
name|init_dtrace
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

