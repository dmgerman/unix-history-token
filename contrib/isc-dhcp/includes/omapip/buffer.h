begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* buffer.h     Definitions for the object management API protocol buffering... */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1996-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software has been written for Internet Systems Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about Internet Systems Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
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

