begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHED_QUERY_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHED_QUERY_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"cachelib.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_struct_decl
struct_decl|struct
name|query_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|configuration
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|configuration_entry
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|query_process_func
function_decl|)
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|query_destroy_func
function_decl|)
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ssize_t
function_decl|(
modifier|*
name|query_read_func
function_decl|)
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ssize_t
function_decl|(
modifier|*
name|query_write_func
function_decl|)
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The query state structure contains the information to process all types of  * requests and to send all types of responses.  */
end_comment

begin_struct
struct|struct
name|query_state
block|{
name|struct
name|timeval
name|creation_time
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|struct
name|comm_element
name|request
decl_stmt|;
name|struct
name|comm_element
name|response
decl_stmt|;
name|struct
name|configuration_entry
modifier|*
name|config_entry
decl_stmt|;
name|void
modifier|*
name|mdata
decl_stmt|;
name|query_process_func
name|process_func
decl_stmt|;
comment|/* called on each event */
name|query_destroy_func
name|destroy_func
decl_stmt|;
comment|/* called on destroy */
comment|/* 	 * By substituting these functions we can opaquely send and received 	 * very large buffers 	 */
name|query_write_func
name|write_func
decl_stmt|;
comment|/* data write function */
name|query_read_func
name|read_func
decl_stmt|;
comment|/* data read function */
name|char
modifier|*
name|eid_str
decl_stmt|;
comment|/* the user-identifying string (euid_egid_) */
name|size_t
name|eid_str_length
decl_stmt|;
name|uid_t
name|euid
decl_stmt|;
comment|/* euid of the caller, received via getpeereid */
name|uid_t
name|uid
decl_stmt|;
comment|/* uid of the caller, received via credentials */
name|gid_t
name|egid
decl_stmt|;
comment|/* egid of the caller, received via getpeereid */
name|gid_t
name|gid
decl_stmt|;
comment|/* gid of the caller received via credentials */
name|size_t
name|io_buffer_size
decl_stmt|;
name|size_t
name|io_buffer_watermark
decl_stmt|;
name|size_t
name|kevent_watermark
decl_stmt|;
comment|/* bytes to be sent/received */
name|int
name|sockfd
decl_stmt|;
comment|/* the unix socket to read/write */
name|int
name|kevent_filter
decl_stmt|;
comment|/* EVFILT_READ or EVFILT_WRITE */
name|int
name|socket_failed
decl_stmt|;
comment|/* set to 1 if the socket doesn't work correctly */
comment|/* 	 * These fields are used to opaquely proceed sending/receiving of 	 * the large buffers 	 */
name|char
modifier|*
name|io_buffer
decl_stmt|;
name|char
modifier|*
name|io_buffer_p
decl_stmt|;
name|int
name|io_buffer_filter
decl_stmt|;
name|int
name|use_alternate_io
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|check_query_eids
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|query_io_buffer_read
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|query_io_buffer_write
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|query_socket_read
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|query_socket_write
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|query_state
modifier|*
name|init_query_state
parameter_list|(
name|int
parameter_list|,
name|size_t
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_query_state
parameter_list|(
name|struct
name|query_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

