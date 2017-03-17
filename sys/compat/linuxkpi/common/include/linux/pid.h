begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_PID_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_PID_H_
end_define

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

begin_enum
enum|enum
name|pid_type
block|{
name|PIDTYPE_PID
block|,
name|PIDTYPE_PGID
block|,
name|PIDTYPE_SID
block|,
name|PIDTYPE_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|pid_nr
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|pid_vnr
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|from_kuid_munged
parameter_list|(
name|a
parameter_list|,
name|uid
parameter_list|)
value|(uid)
end_define

begin_define
define|#
directive|define
name|pid_task
parameter_list|(
name|pid
parameter_list|,
name|type
parameter_list|)
value|({			\ 	struct task_struct *__ts;		\ 	CTASSERT((type) == PIDTYPE_PID);	\ 	__ts = linux_pid_task(pid);		\ 	__ts;					\ })
end_define

begin_define
define|#
directive|define
name|get_pid_task
parameter_list|(
name|pid
parameter_list|,
name|type
parameter_list|)
value|({		\ 	struct task_struct *__ts;		\ 	CTASSERT((type) == PIDTYPE_PID);	\ 	__ts = linux_get_pid_task(pid);		\ 	__ts;					\ })
end_define

begin_struct_decl
struct_decl|struct
name|task_struct
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|struct
name|task_struct
modifier|*
name|linux_pid_task
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|task_struct
modifier|*
name|linux_get_pid_task
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_PID_H_ */
end_comment

end_unit

