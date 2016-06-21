begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Alexander Motin<mav@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * MPPC decompression library.  * Version 1.0  *  * Note that Hi/Fn (later acquired by Exar Corporation) held US patents  * on some implementation-critical aspects of MPPC compression.  * These patents lapsed due to non-payment of fees in 2007 and by 2015  * expired altogether.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_MPPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_MPPC_H_
end_define

begin_define
define|#
directive|define
name|MPPC_MANDATORY_COMPRESS_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|MPPC_MANDATORY_DECOMPRESS_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|MPPC_SAVE_HISTORY
value|1
end_define

begin_define
define|#
directive|define
name|MPPC_OK
value|5
end_define

begin_define
define|#
directive|define
name|MPPC_EXPANDED
value|8
end_define

begin_define
define|#
directive|define
name|MPPC_RESTART_HISTORY
value|16
end_define

begin_define
define|#
directive|define
name|MPPC_DEST_EXHAUSTED
value|32
end_define

begin_function_decl
specifier|extern
name|size_t
name|MPPC_SizeOfCompressionHistory
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|MPPC_SizeOfDecompressionHistory
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MPPC_InitCompressionHistory
parameter_list|(
name|char
modifier|*
name|history
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MPPC_InitDecompressionHistory
parameter_list|(
name|char
modifier|*
name|history
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MPPC_Compress
parameter_list|(
name|u_char
modifier|*
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
modifier|*
name|dst
parameter_list|,
name|u_long
modifier|*
name|srcCnt
parameter_list|,
name|u_long
modifier|*
name|dstCnt
parameter_list|,
name|char
modifier|*
name|history
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|undef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MPPC_Decompress
parameter_list|(
name|u_char
modifier|*
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
modifier|*
name|dst
parameter_list|,
name|u_long
modifier|*
name|srcCnt
parameter_list|,
name|u_long
modifier|*
name|dstCnt
parameter_list|,
name|char
modifier|*
name|history
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

