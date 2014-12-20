begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2001-2007 Niels Provos<provos@citi.umich.edu>  * Copyright 2007-2012 Niels Provos and Nick Mathewson  *  * This header file contains definitions for dealing with HTTP requests  * that are internal to libevent.  As user of the library, you should not  * need to know about these.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HTTP_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|HTTP_INTERNAL_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|"event2/event_struct.h"
end_include

begin_include
include|#
directive|include
file|"util-internal.h"
end_include

begin_include
include|#
directive|include
file|"defer-internal.h"
end_include

begin_define
define|#
directive|define
name|HTTP_CONNECT_TIMEOUT
value|45
end_define

begin_define
define|#
directive|define
name|HTTP_WRITE_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|HTTP_READ_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|HTTP_PREFIX
value|"http://"
end_define

begin_define
define|#
directive|define
name|HTTP_DEFAULTPORT
value|80
end_define

begin_enum
enum|enum
name|message_read_status
block|{
name|ALL_DATA_READ
init|=
literal|1
block|,
name|MORE_DATA_EXPECTED
init|=
literal|0
block|,
name|DATA_CORRUPTED
init|=
operator|-
literal|1
block|,
name|REQUEST_CANCELED
init|=
operator|-
literal|2
block|,
name|DATA_TOO_LONG
init|=
operator|-
literal|3
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|evbuffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|addrinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|evhttp_request
struct_decl|;
end_struct_decl

begin_comment
comment|/* Indicates an unknown request method. */
end_comment

begin_define
define|#
directive|define
name|EVHTTP_REQ_UNKNOWN_
value|(1<<15)
end_define

begin_enum
enum|enum
name|evhttp_connection_state
block|{
name|EVCON_DISCONNECTED
block|,
comment|/**< not currently connected not trying either*/
name|EVCON_CONNECTING
block|,
comment|/**< tries to currently connect */
name|EVCON_IDLE
block|,
comment|/**< connection is established */
name|EVCON_READING_FIRSTLINE
block|,
comment|/**< reading Request-Line (incoming conn) or 				 **< Status-Line (outgoing conn) */
name|EVCON_READING_HEADERS
block|,
comment|/**< reading request/response headers */
name|EVCON_READING_BODY
block|,
comment|/**< reading request/response body */
name|EVCON_READING_TRAILER
block|,
comment|/**< reading request/response chunked trailer */
name|EVCON_WRITING
comment|/**< writing request/response headers/body */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/* A client or server connection. */
end_comment

begin_struct
struct|struct
name|evhttp_connection
block|{
comment|/* we use this tailq only if this connection was created for an http 	 * server */
name|TAILQ_ENTRY
argument_list|(
argument|evhttp_connection
argument_list|)
name|next
expr_stmt|;
name|evutil_socket_t
name|fd
decl_stmt|;
name|struct
name|bufferevent
modifier|*
name|bufev
decl_stmt|;
name|struct
name|event
name|retry_ev
decl_stmt|;
comment|/* for retrying connects */
name|char
modifier|*
name|bind_address
decl_stmt|;
comment|/* address to use for binding the src */
name|u_short
name|bind_port
decl_stmt|;
comment|/* local port for binding the src */
name|char
modifier|*
name|address
decl_stmt|;
comment|/* address to connect to */
name|u_short
name|port
decl_stmt|;
name|size_t
name|max_headers_size
decl_stmt|;
name|ev_uint64_t
name|max_body_size
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|EVHTTP_CON_INCOMING
value|0x0001
comment|/* only one request on it ever */
define|#
directive|define
name|EVHTTP_CON_OUTGOING
value|0x0002
comment|/* multiple requests possible */
define|#
directive|define
name|EVHTTP_CON_CLOSEDETECT
value|0x0004
comment|/* detecting if persistent close */
name|struct
name|timeval
name|timeout
decl_stmt|;
comment|/* timeout for events */
name|int
name|retry_cnt
decl_stmt|;
comment|/* retry count */
name|int
name|retry_max
decl_stmt|;
comment|/* maximum number of retries */
name|struct
name|timeval
name|initial_retry_timeout
decl_stmt|;
comment|/* Timeout for low long to wait 					       * after first failing attempt 					       * before retry */
name|enum
name|evhttp_connection_state
name|state
decl_stmt|;
comment|/* for server connections, the http server they are connected with */
name|struct
name|evhttp
modifier|*
name|http_server
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|evcon_requestq
argument_list|,
argument|evhttp_request
argument_list|)
name|requests
expr_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_arg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|closecb
function_decl|)
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|closecb_arg
decl_stmt|;
name|struct
name|event_callback
name|read_more_deferred_cb
decl_stmt|;
name|struct
name|event_base
modifier|*
name|base
decl_stmt|;
name|struct
name|evdns_base
modifier|*
name|dns_base
decl_stmt|;
comment|/* Saved conn_addr, to extract IP address from it. 	 * 	 * Because some servers may reset/close connection without waiting clients, 	 * in that case we can't extract IP address even in close_cb. 	 * So we need to save it, just after we connected to remote server. */
name|struct
name|sockaddr_storage
modifier|*
name|conn_address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A callback for an http server */
end_comment

begin_struct
struct|struct
name|evhttp_cb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evhttp_cb
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|what
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
name|req
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|cbarg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* both the http server as well as the rpc system need to queue connections */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|evconq
argument_list|,
name|evhttp_connection
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* each bound socket is stored in one of these */
end_comment

begin_struct
struct|struct
name|evhttp_bound_socket
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evhttp_bound_socket
argument_list|)
name|next
expr_stmt|;
name|struct
name|evconnlistener
modifier|*
name|listener
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* server alias list item. */
end_comment

begin_struct
struct|struct
name|evhttp_server_alias
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evhttp_server_alias
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|alias
decl_stmt|;
comment|/* the server alias. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|evhttp
block|{
comment|/* Next vhost, if this is a vhost. */
name|TAILQ_ENTRY
argument_list|(
argument|evhttp
argument_list|)
name|next_vhost
expr_stmt|;
comment|/* All listeners for this host */
name|TAILQ_HEAD
argument_list|(
argument|boundq
argument_list|,
argument|evhttp_bound_socket
argument_list|)
name|sockets
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|httpcbq
argument_list|,
argument|evhttp_cb
argument_list|)
name|callbacks
expr_stmt|;
comment|/* All live connections on this host. */
name|struct
name|evconq
name|connections
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|vhostsq
argument_list|,
argument|evhttp
argument_list|)
name|virtualhosts
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|aliasq
argument_list|,
argument|evhttp_server_alias
argument_list|)
name|aliases
expr_stmt|;
comment|/* NULL if this server is not a vhost */
name|char
modifier|*
name|vhost_pattern
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|size_t
name|default_max_headers_size
decl_stmt|;
name|ev_uint64_t
name|default_max_body_size
decl_stmt|;
specifier|const
name|char
modifier|*
name|default_content_type
decl_stmt|;
comment|/* Bitmask of all HTTP methods that we accept and pass to user 	 * callbacks. */
name|ev_uint16_t
name|allowed_methods
decl_stmt|;
comment|/* Fallback callback if all the other callbacks for this connection 	   don't match. */
name|void
function_decl|(
modifier|*
name|gencb
function_decl|)
parameter_list|(
name|struct
name|evhttp_request
modifier|*
name|req
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|gencbarg
decl_stmt|;
name|struct
name|bufferevent
modifier|*
function_decl|(
modifier|*
name|bevcb
function_decl|)
parameter_list|(
name|struct
name|event_base
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|bevcbarg
decl_stmt|;
name|struct
name|event_base
modifier|*
name|base
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX most of these functions could be static. */
end_comment

begin_comment
comment|/* resets the connection; can be reused for more requests */
end_comment

begin_function_decl
name|void
name|evhttp_connection_reset_
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* connects if necessary */
end_comment

begin_function_decl
name|int
name|evhttp_connection_connect_
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum_decl
enum_decl|enum
name|evhttp_request_error
enum_decl|;
end_enum_decl

begin_comment
comment|/* notifies the current request that it failed; resets connection */
end_comment

begin_function_decl
name|void
name|evhttp_connection_fail_
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|,
name|enum
name|evhttp_request_error
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_enum_decl
enum_decl|enum
name|message_read_status
enum_decl|;
end_enum_decl

begin_function_decl
name|enum
name|message_read_status
name|evhttp_parse_firstline_
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|struct
name|evbuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|message_read_status
name|evhttp_parse_headers_
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|struct
name|evbuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evhttp_start_read_
parameter_list|(
name|struct
name|evhttp_connection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* response sending HTML the data in the buffer */
end_comment

begin_function_decl
name|void
name|evhttp_response_code_
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evhttp_send_page_
parameter_list|(
name|struct
name|evhttp_request
modifier|*
parameter_list|,
name|struct
name|evbuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|evhttp_decode_uri_internal
parameter_list|(
specifier|const
name|char
modifier|*
name|uri
parameter_list|,
name|size_t
name|length
parameter_list|,
name|char
modifier|*
name|ret
parameter_list|,
name|int
name|decode_plus
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HTTP_H */
end_comment

end_unit

