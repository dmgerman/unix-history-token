begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2017 Nuxi, https://nuxi.nl/  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOUDABI_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CLOUDABI_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<contrib/cloudabi/cloudabi_types_common.h>
end_include

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysentvec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_comment
comment|/* Fetches the time value of a clock. */
end_comment

begin_function_decl
name|int
name|cloudabi_clock_time_get
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_clockid_t
parameter_list|,
name|cloudabi_timestamp_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a FreeBSD errno to a CloudABI errno. */
end_comment

begin_function_decl
name|cloudabi_errno_t
name|cloudabi_convert_errno
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a file descriptor to a CloudABI file descriptor type. */
end_comment

begin_function_decl
name|cloudabi_filetype_t
name|cloudabi_convert_filetype
parameter_list|(
specifier|const
name|struct
name|file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts CloudABI rights to a set of Capsicum capabilities. */
end_comment

begin_function_decl
name|int
name|cloudabi_convert_rights
parameter_list|(
name|cloudabi_rights_t
parameter_list|,
name|cap_rights_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Removes rights that conflict with the file descriptor type. */
end_comment

begin_function_decl
name|void
name|cloudabi_remove_conflicting_rights
parameter_list|(
name|cloudabi_filetype_t
parameter_list|,
name|cloudabi_rights_t
modifier|*
parameter_list|,
name|cloudabi_rights_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts a struct timespec to a CloudABI timestamp. */
end_comment

begin_function_decl
name|int
name|cloudabi_convert_timespec
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
name|cloudabi_timestamp_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Blocking futex functions.  *  * These functions are called by CloudABI's polling system calls to  * sleep on a lock or condition variable.  */
end_comment

begin_function_decl
name|int
name|cloudabi_futex_condvar_wait
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_condvar_t
modifier|*
parameter_list|,
name|cloudabi_scope_t
parameter_list|,
name|cloudabi_lock_t
modifier|*
parameter_list|,
name|cloudabi_scope_t
parameter_list|,
name|cloudabi_clockid_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cloudabi_futex_lock_rdlock
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_lock_t
modifier|*
parameter_list|,
name|cloudabi_scope_t
parameter_list|,
name|cloudabi_clockid_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cloudabi_futex_lock_wrlock
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_lock_t
modifier|*
parameter_list|,
name|cloudabi_scope_t
parameter_list|,
name|cloudabi_clockid_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|,
name|cloudabi_timestamp_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Socket operations. */
end_comment

begin_function_decl
name|int
name|cloudabi_sock_recv
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_fd_t
parameter_list|,
name|struct
name|iovec
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|cloudabi_fd_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|cloudabi_riflags_t
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|cloudabi_roflags_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cloudabi_sock_send
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|cloudabi_fd_t
parameter_list|,
name|struct
name|iovec
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|cloudabi_fd_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vDSO setup and teardown. */
end_comment

begin_function_decl
name|void
name|cloudabi_vdso_init
parameter_list|(
name|struct
name|sysentvec
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cloudabi_vdso_destroy
parameter_list|(
name|struct
name|sysentvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

