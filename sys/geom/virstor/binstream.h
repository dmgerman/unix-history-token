begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Ivan Voras<ivoras@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|// $Id: binstream.h,v 1.1 2006/07/05 10:47:54 ivoras Exp $
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BIN_STREAM_
end_ifndef

begin_define
define|#
directive|define
name|_BIN_STREAM_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|uint8_t
end_ifndef

begin_define
define|#
directive|define
name|uint8_t
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|int
name|pos
decl_stmt|;
block|}
name|bin_stream_t
typedef|;
end_typedef

begin_comment
comment|/* "Open" a binary stream for reading */
end_comment

begin_function_decl
name|void
name|bs_open
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* "Reset" position in binary stream to zero */
end_comment

begin_function_decl
name|void
name|bs_reset
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a zero-terminated string; return next position */
end_comment

begin_function_decl
name|unsigned
name|bs_write_str
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write an arbitrary buffer; return next position */
end_comment

begin_function_decl
name|unsigned
name|bs_write_buf
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|data_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a 8bit uint; return next position. */
end_comment

begin_function_decl
name|unsigned
name|bs_write_u8
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|uint8_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a 16bit uint; return next position. */
end_comment

begin_function_decl
name|unsigned
name|bs_write_u16
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a 32bit uint; return next position. */
end_comment

begin_function_decl
name|unsigned
name|bs_write_u32
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|uint32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a 64bit uint; return next position. */
end_comment

begin_function_decl
name|unsigned
name|bs_write_u64
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|uint64_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read a null-terminated string from stream into a buffer; buf_size is size  * of the buffer, including the final \0. Returns buf pointer or NULL if  * garbage input.  */
end_comment

begin_function_decl
name|char
modifier|*
name|bs_read_str
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read an arbitrary buffer. */
end_comment

begin_function_decl
name|void
name|bs_read_buf
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a 8bit uint * return it */
end_comment

begin_function_decl
name|uint8_t
name|bs_read_u8
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a 16bit uint * return it */
end_comment

begin_function_decl
name|uint16_t
name|bs_read_u16
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a 8bit uint * return it */
end_comment

begin_function_decl
name|uint32_t
name|bs_read_u32
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a 8bit uint * return it */
end_comment

begin_function_decl
name|uint64_t
name|bs_read_u64
parameter_list|(
name|bin_stream_t
modifier|*
name|bs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

