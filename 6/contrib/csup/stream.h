begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STREAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_STREAM_H_
end_define

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_comment
comment|/* Stream filters. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|STREAM_FILTER_NULL
block|,
name|STREAM_FILTER_ZLIB
block|,
name|STREAM_FILTER_MD5
block|}
name|stream_filter_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|stream
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|ssize_t
name|stream_readfn_t
parameter_list|(
name|void
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
name|stream_writefn_t
parameter_list|(
name|void
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

begin_typedef
typedef|typedef
name|int
name|stream_closefn_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Convenience functions for handling file descriptors. */
end_comment

begin_decl_stmt
name|stream_readfn_t
name|stream_read_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|stream_writefn_t
name|stream_write_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|stream_closefn_t
name|stream_close_fd
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|stream
modifier|*
name|stream_open
parameter_list|(
name|void
modifier|*
parameter_list|,
name|stream_readfn_t
modifier|*
parameter_list|,
name|stream_writefn_t
modifier|*
parameter_list|,
name|stream_closefn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|stream
modifier|*
name|stream_open_fd
parameter_list|(
name|int
parameter_list|,
name|stream_readfn_t
modifier|*
parameter_list|,
name|stream_writefn_t
modifier|*
parameter_list|,
name|stream_closefn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|stream
modifier|*
name|stream_open_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_fileno
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|stream_read
parameter_list|(
name|struct
name|stream
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
name|ssize_t
name|stream_write
parameter_list|(
name|struct
name|stream
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
name|char
modifier|*
name|stream_getln
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_printf
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|stream_flush
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_sync
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_truncate
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_truncate_rel
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_rewind
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_eof
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_close
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stream_filter_start
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
name|stream_filter_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stream_filter_stop
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STREAM_H_ */
end_comment

end_unit

