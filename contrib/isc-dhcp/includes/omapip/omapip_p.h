begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* omapip_p.h     Private master include file for the OMAPI library. */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-2001 Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about the Internet Software Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OMAPIP_OMAPIP_P_H__
end_ifndef

begin_define
define|#
directive|define
name|__OMAPIP_OMAPIP_P_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__CYGWIN32__
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fd_set
value|cygwin_fd_set
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_include
include|#
directive|include
file|"osdep.h"
end_include

begin_include
include|#
directive|include
file|<isc-dhcp/dst.h>
end_include

begin_include
include|#
directive|include
file|<isc-dhcp/result.h>
end_include

begin_include
include|#
directive|include
file|<omapip/convert.h>
end_include

begin_include
include|#
directive|include
file|<omapip/hash.h>
end_include

begin_include
include|#
directive|include
file|<omapip/omapip.h>
end_include

begin_include
include|#
directive|include
file|<omapip/trace.h>
end_include

begin_comment
comment|/* OMAPI protocol header, version 1.00 */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|authlen
decl_stmt|;
comment|/* Length of authenticator. */
name|u_int32_t
name|authid
decl_stmt|;
comment|/* Authenticator object ID. */
name|u_int32_t
name|op
decl_stmt|;
comment|/* Opcode. */
name|omapi_handle_t
name|handle
decl_stmt|;
comment|/* Handle of object being operated on,                                    or zero. */
name|u_int32_t
name|id
decl_stmt|;
comment|/* Transaction ID. */
name|u_int32_t
name|rid
decl_stmt|;
comment|/* ID of transaction to which this is a response. */
block|}
name|omapi_protocol_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OMAPI_PROTOCOL_VERSION
value|100
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_REFRESH
value|2
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_UPDATE
value|3
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_NOTIFY
value|4
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_STATUS
value|5
end_define

begin_define
define|#
directive|define
name|OMAPI_OP_DELETE
value|6
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|omapi_connection_unconnected
block|,
name|omapi_connection_connecting
block|,
name|omapi_connection_connected
block|,
name|omapi_connection_disconnecting
block|,
name|omapi_connection_closed
block|}
name|omapi_connection_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|omapi_protocol_intro_wait
block|,
name|omapi_protocol_header_wait
block|,
name|omapi_protocol_signature_wait
block|,
name|omapi_protocol_name_wait
block|,
name|omapi_protocol_name_length_wait
block|,
name|omapi_protocol_value_wait
block|,
name|omapi_protocol_value_length_wait
block|}
name|omapi_protocol_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_message_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|struct
name|__omapi_message_object
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|omapi_object_t
modifier|*
name|object
decl_stmt|;
name|omapi_object_t
modifier|*
name|notify_object
decl_stmt|;
name|struct
name|__omapi_protocol_object
modifier|*
name|protocol_object
decl_stmt|;
name|u_int32_t
name|authlen
decl_stmt|;
name|omapi_typed_data_t
modifier|*
name|authenticator
decl_stmt|;
name|u_int32_t
name|authid
decl_stmt|;
name|omapi_object_t
modifier|*
name|id_object
decl_stmt|;
name|u_int32_t
name|op
decl_stmt|;
name|u_int32_t
name|h
decl_stmt|;
name|u_int32_t
name|id
decl_stmt|;
name|u_int32_t
name|rid
decl_stmt|;
block|}
name|omapi_message_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_remote_auth
block|{
name|struct
name|__omapi_remote_auth
modifier|*
name|next
decl_stmt|;
name|omapi_handle_t
name|remote_handle
decl_stmt|;
name|omapi_object_t
modifier|*
name|a
decl_stmt|;
block|}
name|omapi_remote_auth_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_protocol_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|u_int32_t
name|header_size
decl_stmt|;
name|u_int32_t
name|protocol_version
decl_stmt|;
name|u_int32_t
name|next_xid
decl_stmt|;
name|omapi_protocol_state_t
name|state
decl_stmt|;
comment|/* Input state. */
name|int
name|reading_message_values
decl_stmt|;
comment|/* True if reading message-specific 					   values. */
name|omapi_message_object_t
modifier|*
name|message
decl_stmt|;
comment|/* Incoming message. */
name|omapi_data_string_t
modifier|*
name|name
decl_stmt|;
comment|/* Incoming name. */
name|omapi_typed_data_t
modifier|*
name|value
decl_stmt|;
comment|/* Incoming value. */
name|isc_result_t
name|verify_result
decl_stmt|;
name|omapi_remote_auth_t
modifier|*
name|default_auth
decl_stmt|;
comment|/* Default authinfo to use. */
name|omapi_remote_auth_t
modifier|*
name|remote_auth_list
decl_stmt|;
comment|/* Authenticators active on 						   this connection. */
name|isc_boolean_t
name|insecure
decl_stmt|;
comment|/* Set to allow unauthenticated 					   messages. */
name|isc_result_t
function_decl|(
modifier|*
name|verify_auth
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|omapi_auth_key_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|omapi_protocol_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|isc_boolean_t
name|insecure
decl_stmt|;
comment|/* Set to allow unauthenticated 					   messages. */
name|isc_result_t
function_decl|(
modifier|*
name|verify_auth
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|omapi_auth_key_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|omapi_protocol_listener_object_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<omapip/buffer.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|__omapi_listener_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|int
name|socket
decl_stmt|;
comment|/* Connection socket. */
name|int
name|index
decl_stmt|;
name|struct
name|sockaddr_in
name|address
decl_stmt|;
name|isc_result_t
function_decl|(
modifier|*
name|verify_addr
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|,
name|omapi_addr_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|omapi_listener_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_connection_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|int
name|socket
decl_stmt|;
comment|/* Connection socket. */
name|int32_t
name|index
decl_stmt|;
name|omapi_connection_state_t
name|state
decl_stmt|;
name|struct
name|sockaddr_in
name|remote_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|local_addr
decl_stmt|;
name|omapi_addr_list_t
modifier|*
name|connect_list
decl_stmt|;
comment|/* List of addresses to which 						   to connect. */
name|int
name|cptr
decl_stmt|;
comment|/* Current element we are connecting to. */
name|u_int32_t
name|bytes_needed
decl_stmt|;
comment|/* Bytes of input needed before wakeup. */
name|u_int32_t
name|in_bytes
decl_stmt|;
comment|/* Bytes of input already buffered. */
name|omapi_buffer_t
modifier|*
name|inbufs
decl_stmt|;
name|u_int32_t
name|out_bytes
decl_stmt|;
comment|/* Bytes of output in buffers. */
name|omapi_buffer_t
modifier|*
name|outbufs
decl_stmt|;
name|omapi_listener_object_t
modifier|*
name|listener
decl_stmt|;
comment|/* Listener that accepted this 						   connection, if any. */
name|DST_KEY
modifier|*
name|in_key
decl_stmt|;
comment|/* Authenticator signing incoming 				   data. */
name|void
modifier|*
name|in_context
decl_stmt|;
comment|/* Input hash context. */
name|DST_KEY
modifier|*
name|out_key
decl_stmt|;
comment|/* Authenticator signing outgoing 				   data. */
name|void
modifier|*
name|out_context
decl_stmt|;
comment|/* Output hash context. */
block|}
name|omapi_connection_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_io_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|struct
name|__omapi_io_object
modifier|*
name|next
decl_stmt|;
name|int
function_decl|(
modifier|*
name|readfd
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|writefd
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|reader
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|writer
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|reaper
function_decl|)
parameter_list|(
name|omapi_object_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|omapi_io_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_generic_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|omapi_value_t
modifier|*
modifier|*
name|values
decl_stmt|;
name|u_int8_t
modifier|*
name|changed
decl_stmt|;
name|int
name|nvalues
decl_stmt|,
name|va_max
decl_stmt|;
block|}
name|omapi_generic_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__omapi_waiter_object
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|int
name|ready
decl_stmt|;
name|isc_result_t
name|waitstatus
decl_stmt|;
name|struct
name|__omapi_waiter_object
modifier|*
name|next
decl_stmt|;
block|}
name|omapi_waiter_object_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OMAPI_HANDLE_TABLE_SIZE
value|120
end_define

begin_typedef
typedef|typedef
struct|struct
name|__omapi_handle_table
block|{
name|omapi_handle_t
name|first
decl_stmt|,
name|limit
decl_stmt|;
name|omapi_handle_t
name|next
decl_stmt|;
name|int
name|leafp
decl_stmt|;
union|union
block|{
name|omapi_object_t
modifier|*
name|object
decl_stmt|;
name|struct
name|__omapi_handle_table
modifier|*
name|table
decl_stmt|;
block|}
name|children
index|[
name|OMAPI_HANDLE_TABLE_SIZE
index|]
union|;
block|}
name|omapi_handle_table_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<omapip/alloc.h>
end_include

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_protocol
argument_list|,
argument|omapi_protocol_object_t
argument_list|,
argument|omapi_type_protocol
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_protocol_listener
argument_list|,
argument|omapi_protocol_listener_object_t
argument_list|,
argument|omapi_type_protocol_listener
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_connection
argument_list|,
argument|omapi_connection_object_t
argument_list|,
argument|omapi_type_connection
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_listener
argument_list|,
argument|omapi_listener_object_t
argument_list|,
argument|omapi_type_listener
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_io
argument_list|,
argument|omapi_io_object_t
argument_list|,
argument|omapi_type_io_object
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_waiter
argument_list|,
argument|omapi_waiter_object_t
argument_list|,
argument|omapi_type_waiter
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_generic
argument_list|,
argument|omapi_generic_object_t
argument_list|,
argument|omapi_type_generic
argument_list|)
end_macro

begin_macro
name|OMAPI_OBJECT_ALLOC_DECL
argument_list|(
argument|omapi_message
argument_list|,
argument|omapi_message_object_t
argument_list|,
argument|omapi_type_message
argument_list|)
end_macro

begin_function_decl
name|isc_result_t
name|omapi_connection_sign_data
parameter_list|(
name|int
name|mode
parameter_list|,
name|DST_KEY
modifier|*
name|key
parameter_list|,
name|void
modifier|*
modifier|*
name|context
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
specifier|const
name|unsigned
name|len
parameter_list|,
name|omapi_typed_data_t
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|omapi_listener_connect
parameter_list|(
name|omapi_connection_object_t
modifier|*
modifier|*
name|obj
parameter_list|,
name|omapi_listener_object_t
modifier|*
name|listener
parameter_list|,
name|int
name|socket
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|remote_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omapi_listener_trace_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omapi_connection_trace_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omapi_buffer_trace_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|omapi_connection_register
parameter_list|(
name|omapi_connection_object_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trace_mr_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|OMAPI_ARRAY_TYPE_DECL
argument_list|(
name|omapi_listener
argument_list|,
name|omapi_listener_object_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OMAPI_ARRAY_TYPE_DECL
argument_list|(
name|omapi_connection
argument_list|,
name|omapi_connection_object_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_priority
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_perror
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|log_cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|log_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|log_info
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|log_debug
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|do_percentm
parameter_list|(
name|char
modifier|*
name|obuf
parameter_list|,
specifier|const
name|char
modifier|*
name|ibuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|uerr2isc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_rcode_to_isc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|omapi_message_object_t
modifier|*
name|omapi_registered_messages
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OMAPIP_OMAPIP_P_H__ */
end_comment

end_unit

