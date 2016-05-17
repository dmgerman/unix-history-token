begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Nuxi, https://nuxi.nl/  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<sys/umtx.h>
end_include

begin_include
include|#
directive|include
file|<contrib/cloudabi/cloudabi_types_common.h>
end_include

begin_include
include|#
directive|include
file|<compat/cloudabi/cloudabi_proto.h>
end_include

begin_function
name|int
name|cloudabi_sys_thread_exit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cloudabi_sys_thread_exit_args
modifier|*
name|uap
parameter_list|)
block|{
name|struct
name|cloudabi_sys_lock_unlock_args
name|cloudabi_sys_lock_unlock_args
init|=
block|{
operator|.
name|lock
operator|=
name|uap
operator|->
name|lock
block|,
operator|.
name|scope
operator|=
name|uap
operator|->
name|scope
block|, 	}
decl_stmt|;
name|umtx_thread_exit
argument_list|(
name|td
argument_list|)
expr_stmt|;
comment|/* Wake up joining thread. */
name|cloudabi_sys_lock_unlock
argument_list|(
name|td
argument_list|,
operator|&
name|cloudabi_sys_lock_unlock_args
argument_list|)
expr_stmt|;
comment|/* 	 * Attempt to terminate the thread. Terminate the process if 	 * it's the last thread. 	 */
name|kern_thr_exit
argument_list|(
name|td
argument_list|)
expr_stmt|;
name|exit1
argument_list|(
name|td
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_function
name|int
name|cloudabi_sys_thread_tcb_set
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cloudabi_sys_thread_tcb_set_args
modifier|*
name|uap
parameter_list|)
block|{
return|return
operator|(
name|cpu_set_user_tls
argument_list|(
name|td
argument_list|,
name|uap
operator|->
name|tcb
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|cloudabi_sys_thread_yield
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|cloudabi_sys_thread_yield_args
modifier|*
name|uap
parameter_list|)
block|{
name|sched_relinquish
argument_list|(
name|td
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

