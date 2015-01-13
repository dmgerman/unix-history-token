begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2014 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HOST_SYSCALL_H
end_ifndef

begin_define
define|#
directive|define
name|_HOST_SYSCALL_H
end_define

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_function_decl
name|ssize_t
name|host_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbyte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|host_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbyte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|host_seek
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|host_open
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|host_close
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|host_mmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|host_getmem
parameter_list|(
name|size
parameter_list|)
value|host_mmap(0, size, 3
comment|/* RW */
value|, 0x22
comment|/* ANON */
value|, -1, 0);
end_define

begin_struct
struct|struct
name|host_timeval
block|{
name|int
name|tv_sec
decl_stmt|;
name|int
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|host_gettimeofday
parameter_list|(
name|struct
name|host_timeval
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|host_select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|long
modifier|*
name|readfds
parameter_list|,
name|long
modifier|*
name|writefds
parameter_list|,
name|long
modifier|*
name|exceptfds
parameter_list|,
name|struct
name|host_timeval
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kexec_load
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|int
name|nsegs
parameter_list|,
name|void
modifier|*
name|segs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|host_reboot
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|host_getdents
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|dirp
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

