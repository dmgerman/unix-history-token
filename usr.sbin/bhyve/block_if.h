begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013  Peter Grehan<grehan@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The block API to be used by bhyve block-device emulations. The routines  * are thread safe, with no assumptions about the context of the completion  * callback - it may occur in the caller's context, or asynchronously in  * another thread.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLOCK_IF_H_
end_ifndef

begin_define
define|#
directive|define
name|_BLOCK_IF_H_
end_define

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_define
define|#
directive|define
name|BLOCKIF_IOV_MAX
value|32
end_define

begin_comment
comment|/* not practical to be IOV_MAX */
end_comment

begin_struct
struct|struct
name|blockif_req
block|{
name|struct
name|iovec
name|br_iov
index|[
name|BLOCKIF_IOV_MAX
index|]
decl_stmt|;
name|int
name|br_iovcnt
decl_stmt|;
name|off_t
name|br_offset
decl_stmt|;
name|void
function_decl|(
modifier|*
name|br_callback
function_decl|)
parameter_list|(
name|struct
name|blockif_req
modifier|*
name|req
parameter_list|,
name|int
name|err
parameter_list|)
function_decl|;
name|void
modifier|*
name|br_param
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|blockif_ctxt
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|blockif_ctxt
modifier|*
name|blockif_open
parameter_list|(
specifier|const
name|char
modifier|*
name|optstr
parameter_list|,
specifier|const
name|char
modifier|*
name|ident
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|blockif_size
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blockif_chs
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|,
name|uint16_t
modifier|*
name|c
parameter_list|,
name|uint8_t
modifier|*
name|h
parameter_list|,
name|uint8_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_sectsz
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_queuesz
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_is_ro
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_read
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|,
name|struct
name|blockif_req
modifier|*
name|breq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_write
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|,
name|struct
name|blockif_req
modifier|*
name|breq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_flush
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|,
name|struct
name|blockif_req
modifier|*
name|breq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_cancel
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|,
name|struct
name|blockif_req
modifier|*
name|breq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blockif_close
parameter_list|(
name|struct
name|blockif_ctxt
modifier|*
name|bc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BLOCK_IF_H_ */
end_comment

end_unit

