begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* buffer.h     Definitions for the object management API protocol buffering... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about the Internet Software Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_comment
comment|/* OMAPI buffers are ring buffers, which means that the beginning of the    buffer and the end of the buffer chase each other around.   As long as    the tail never catches up to the head, there's room in the buffer for    data.  	- If the tail and the head are equal, the buffer is empty.  	- If the tail is less than the head, the contents of the buffer 	  are the bytes from the head to the end of buffer, and in addition, 	  the bytes between the beginning of the buffer and the tail, not 	  including the byte addressed by the tail.  	- If the tail is greater than the head, then the buffer contains 	  valid bytes starting with the byte addressed by the head, and 	  ending with the byte before the byte addressed by the tail.     There will always be at least one byte of waste, because the tail can't    increase so that it's equal to the head (that would represent an empty    buffer. */
end_comment

begin_define
define|#
directive|define
name|OMAPI_BUF_SIZE
value|4048
end_define

begin_typedef
typedef|typedef
struct|struct
name|_omapi_buffer
block|{
name|struct
name|_omapi_buffer
modifier|*
name|next
decl_stmt|;
comment|/* Buffers can be chained. */
name|u_int32_t
name|refcnt
decl_stmt|;
comment|/* Buffers are reference counted. */
name|u_int16_t
name|head
decl_stmt|,
name|tail
decl_stmt|;
comment|/* Buffers are organized in a ring. */
name|char
name|buf
index|[
name|OMAPI_BUF_SIZE
index|]
decl_stmt|;
comment|/* The actual buffer is included in 					   the buffer data structure. */
block|}
name|omapi_buffer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUFFER_BYTES_FREE
parameter_list|(
name|x
parameter_list|)
define|\
value|((x) -> tail> (x) -> head \ 	  ? sizeof ((x) -> buf) - ((x) -> tail - (x) -> head) \ 	  : (x) -> head - (x) -> tail)
end_define

begin_define
define|#
directive|define
name|BYTES_IN_BUFFER
parameter_list|(
name|x
parameter_list|)
define|\
value|((x) -> tail> (x) -> head \ 	 ? (x) -> tail - (x) -> head - 1 \ 	 : sizeof ((x) -> buf) - ((x) -> head - (x) -> tail) - 1)
end_define

begin_function_decl
name|isc_result_t
name|omapi_connection_require
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_copyout
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|omapi_object_t
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_copyin
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_flush
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_get_uint32
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_put_uint32
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_get_uint16
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_connection_put_uint16
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

