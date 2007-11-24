begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 Alexander Kabaev.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RTLD_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_RTLD_LOCK_H_
end_define

begin_define
define|#
directive|define
name|RTLI_VERSION
value|0x01
end_define

begin_struct
struct|struct
name|RtldLockInfo
block|{
name|unsigned
name|int
name|rtli_version
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|lock_create
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lock_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lock_release
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|thread_set_flag
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|thread_clr_flag
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|at_fork
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|_rtld_thread_init
parameter_list|(
name|struct
name|RtldLockInfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IN_RTLD
end_ifdef

begin_struct_decl
struct_decl|struct
name|rtld_lock
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|rtld_lock
modifier|*
name|rtld_lock_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|rtld_lock_t
name|rtld_bind_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtld_lock_t
name|rtld_libc_lock
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rlock_acquire
parameter_list|(
name|rtld_lock_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wlock_acquire
parameter_list|(
name|rtld_lock_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rlock_release
parameter_list|(
name|rtld_lock_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wlock_release
parameter_list|(
name|rtld_lock_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_RTLD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

