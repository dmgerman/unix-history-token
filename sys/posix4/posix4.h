begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_P1003_1B_P1003_1B_H_
end_ifndef

begin_define
define|#
directive|define
name|_P1003_1B_P1003_1B_H_
end_define

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_posix.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<posix4/sched.h>
end_include

begin_comment
comment|/* Generate syscall stubs for when something is optionally  * loadable as a module.  References "syscall_not_present".   * XXX Good candidate for sys/syscall.h  */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nosys_args
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|syscall_not_present
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|nosys_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SYSCALL_NOT_PRESENT_GEN
parameter_list|(
name|SC
parameter_list|)
define|\
value|int SC (struct thread *td, struct SC##_args *uap) \ { \ 	return syscall_not_present(td, #SC , (struct nosys_args *)uap); \ }
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_P31B
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|p31b_malloc
parameter_list|(
name|SIZE
parameter_list|)
value|malloc((SIZE), M_P31B, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|p31b_free
parameter_list|(
name|P
parameter_list|)
value|free((P), M_P31B)
end_define

begin_function_decl
name|int
name|p31b_proc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|pid_t
parameter_list|,
name|struct
name|proc
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p31b_setcfg
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KPOSIX_PRIORITY_SCHEDULING
end_ifdef

begin_comment
comment|/*   * KSCHED_OP_RW is a vector of read/write flags for each entry indexed  * by the enum ksched_op.  *  * 1 means you need write access, 0 means read is sufficient.  */
end_comment

begin_enum
enum|enum
name|ksched_op
block|{
define|#
directive|define
name|KSCHED_OP_RW
value|{ 1, 0, 1, 0, 0, 0, 0, 0 }
name|SCHED_SETPARAM
block|,
name|SCHED_GETPARAM
block|,
name|SCHED_SETSCHEDULER
block|,
name|SCHED_GETSCHEDULER
block|,
name|SCHED_YIELD
block|,
name|SCHED_GET_PRIORITY_MAX
block|,
name|SCHED_GET_PRIORITY_MIN
block|,
name|SCHED_RR_GET_INTERVAL
block|,
name|SCHED_OP_MAX
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ksched
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ksched_attach
parameter_list|(
name|struct
name|ksched
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_detach
parameter_list|(
name|struct
name|ksched
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_setparam
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
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
name|ksched_getparam
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|sched_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_setscheduler
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
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
name|ksched_getscheduler
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_yield
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_get_priority_max
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_get_priority_min
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ksched_rr_get_interval
parameter_list|(
name|register_t
modifier|*
parameter_list|,
name|struct
name|ksched
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KPOSIX_PRIORITY_SCHEDULING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _P1003_1B_P1003_1B_H_ */
end_comment

end_unit

