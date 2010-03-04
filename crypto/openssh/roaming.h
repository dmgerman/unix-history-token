begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: roaming.h,v 1.4 2009/06/27 09:32:43 andreas Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004-2009 AppGate Network Security AB  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ROAMING_H
end_ifndef

begin_define
define|#
directive|define
name|ROAMING_H
end_define

begin_define
define|#
directive|define
name|DEFAULT_ROAMBUF
value|65536
end_define

begin_decl_stmt
specifier|extern
name|int
name|resume_in_progress
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|get_snd_buf_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_recv_buf_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_recv_bytes
parameter_list|(
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_out_buffer_size
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|roaming_write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|roaming_read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|roaming_atomicio
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|get_recv_bytes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|get_sent_bytes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roam_set_bytes
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resend_bytes
parameter_list|(
name|int
parameter_list|,
name|u_int64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|resume_kex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ROAMING */
end_comment

end_unit

