begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCHED_H_
end_define

begin_comment
comment|/* sched.h: POSIX 1003.1b Process Scheduling header */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  *	and Jukka Antero Ukkonen.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* For pid_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* Per P1003.4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Scheduling policies  */
end_comment

begin_define
define|#
directive|define
name|SCHED_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|SCHED_OTHER
value|2
end_define

begin_define
define|#
directive|define
name|SCHED_RR
value|3
end_define

begin_struct
struct|struct
name|sched_param
block|{
name|int
name|sched_priority
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|sched_setparam
parameter_list|(
name|pid_t
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_getparam
parameter_list|(
name|pid_t
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_setscheduler
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_getscheduler
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_get_priority_max
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_get_priority_min
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sched_rr_get_interval
parameter_list|(
name|pid_t
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCHED_H_ */
end_comment

end_unit

