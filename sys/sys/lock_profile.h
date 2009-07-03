begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy kmacy@FreeBSD.org  * Copyright (c) 2006 Kris Kennaway kris@FreeBSD.org  * Copyright (c) 2006 Dag-Erling Smorgrav des@des.no  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR   * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHAL THE AUTHORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCK_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCK_PROFILE_H_
end_define

begin_struct_decl
struct_decl|struct
name|lock_profile_object
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|lpohead
argument_list|,
name|lock_profile_object
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|LOCK_PROFILING
end_ifdef

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USE_CPU_NANOSECONDS
end_ifndef

begin_function_decl
name|u_int64_t
name|nanoseconds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|lock_prof_enable
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lock_profile_obtain_lock_success
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lo
parameter_list|,
name|int
name|contested
parameter_list|,
name|uint64_t
name|waittime
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_profile_release_lock
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_profile_thread_exit
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|lock_profile_obtain_lock_failed
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lo
parameter_list|,
name|int
modifier|*
name|contested
parameter_list|,
name|uint64_t
modifier|*
name|waittime
parameter_list|)
block|{
if|if
condition|(
operator|!
name|lock_prof_enable
operator|||
operator|(
name|lo
operator|->
name|lo_flags
operator|&
name|LO_NOPROFILE
operator|)
operator|||
operator|*
name|contested
condition|)
return|return;
operator|*
name|waittime
operator|=
name|nanoseconds
argument_list|()
expr_stmt|;
operator|*
name|contested
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LOCK_PROFILING */
end_comment

begin_define
define|#
directive|define
name|lock_profile_release_lock
parameter_list|(
name|lo
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|lock_profile_obtain_lock_failed
parameter_list|(
name|lo
parameter_list|,
name|contested
parameter_list|,
name|waittime
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|lock_profile_obtain_lock_success
parameter_list|(
name|lo
parameter_list|,
name|contested
parameter_list|,
name|waittime
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|lock_profile_thread_exit
parameter_list|(
name|td
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCK_PROFILING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_LOCK_PROFILE_H_ */
end_comment

end_unit

