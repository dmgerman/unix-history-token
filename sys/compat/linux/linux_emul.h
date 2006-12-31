begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Roman Divacky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EMUL_H_
end_define

begin_struct
struct|struct
name|linux_emuldata_shared
block|{
name|int
name|refs
decl_stmt|;
name|pid_t
name|group_pid
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|linux_emuldata
argument_list|)
name|threads
expr_stmt|;
comment|/* head of list of linux threads */
block|}
struct|;
end_struct

begin_comment
comment|/*  * modeled after similar structure in NetBSD  * this will be extended as we need more functionality  */
end_comment

begin_struct
struct|struct
name|linux_emuldata
block|{
name|pid_t
name|pid
decl_stmt|;
name|int
modifier|*
name|child_set_tid
decl_stmt|;
comment|/* in clone(): Child's TID to set on clone */
name|int
modifier|*
name|child_clear_tid
decl_stmt|;
comment|/* in clone(): Child's TID to clear on exit */
name|struct
name|linux_emuldata_shared
modifier|*
name|shared
decl_stmt|;
name|int
name|pdeath_signal
decl_stmt|;
comment|/* parent death signal */
name|LIST_ENTRY
argument_list|(
argument|linux_emuldata
argument_list|)
name|threads
expr_stmt|;
comment|/* list of linux threads */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|linux_emuldata
modifier|*
name|em_find
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|int
name|locked
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EMUL_LOCK
parameter_list|(
name|l
parameter_list|)
value|sx_xlock(l)
end_define

begin_define
define|#
directive|define
name|EMUL_UNLOCK
parameter_list|(
name|l
parameter_list|)
value|sx_xunlock(l)
end_define

begin_define
define|#
directive|define
name|EMUL_SHARED_RLOCK
parameter_list|(
name|l
parameter_list|)
value|sx_slock(l)
end_define

begin_define
define|#
directive|define
name|EMUL_SHARED_RUNLOCK
parameter_list|(
name|l
parameter_list|)
value|sx_sunlock(l)
end_define

begin_define
define|#
directive|define
name|EMUL_SHARED_WLOCK
parameter_list|(
name|l
parameter_list|)
value|sx_xlock(l)
end_define

begin_define
define|#
directive|define
name|EMUL_SHARED_WUNLOCK
parameter_list|(
name|l
parameter_list|)
value|sx_xunlock(l)
end_define

begin_comment
comment|/* for em_find use */
end_comment

begin_define
define|#
directive|define
name|EMUL_LOCKED
value|1
end_define

begin_define
define|#
directive|define
name|EMUL_UNLOCKED
value|0
end_define

begin_function_decl
name|int
name|linux_proc_init
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_proc_exit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_schedtail
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_proc_exec
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|emul_shared_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|emul_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_EMUL_H_ */
end_comment

end_unit

