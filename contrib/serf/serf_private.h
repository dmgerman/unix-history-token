begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 2002-2004 Justin Erenkrantz and Greg Stein  *  * Licensed under the Apache License, Version 2.0 (the "License");  * you may not use this file except in compliance with the License.  * You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SERF_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SERF_PRIVATE_H_
end_define

begin_comment
comment|/* ### what the hell? why does the APR interface have a "size" ??    ### the implication is that, if we bust this limit, we'd need to    ### stop, rebuild a pollset, and repopulate it. what suckage.  */
end_comment

begin_define
define|#
directive|define
name|MAX_CONN
value|16
end_define

begin_comment
comment|/* Windows does not define IOV_MAX, so we need to ensure it is defined. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOV_MAX
end_ifndef

begin_comment
comment|/* There is no limit for iovec count on Windows, but apr_socket_sendv    allocates WSABUF structures on stack if vecs_count<= 50. */
end_comment

begin_define
define|#
directive|define
name|IOV_MAX
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Older versions of APR do not have this macro.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APR_SIZE_MAX
end_ifdef

begin_define
define|#
directive|define
name|REQUESTED_MAX
value|APR_SIZE_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REQUESTED_MAX
value|(~((apr_size_t)0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SERF_IO_CLIENT
value|(1)
end_define

begin_define
define|#
directive|define
name|SERF_IO_CONN
value|(2)
end_define

begin_define
define|#
directive|define
name|SERF_IO_LISTENER
value|(3)
end_define

begin_comment
comment|/* Internal logging facilities, set flag to 1 to enable console logging for    the selected component. */
end_comment

begin_define
define|#
directive|define
name|SSL_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|SSL_MSG_VERBOSE
value|0
end_define

begin_comment
comment|/* logs decrypted requests and responses. */
end_comment

begin_define
define|#
directive|define
name|SOCK_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|SOCK_MSG_VERBOSE
value|0
end_define

begin_comment
comment|/* logs bytes received from or written to a socket. */
end_comment

begin_define
define|#
directive|define
name|CONN_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|AUTH_VERBOSE
value|0
end_define

begin_comment
comment|/* Older versions of APR do not have the APR_VERSION_AT_LEAST macro. Those    implementations are safe.     If the macro *is* defined, and we're on WIN32, and APR is version 1.4.0+,    then we have a broken WSAPoll() implementation.     See serf_context_create_ex() below.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APR_VERSION_AT_LEAST
argument_list|)
operator|&&
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_if
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|BROKEN_WSAPOLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|serf__authn_scheme_t
name|serf__authn_scheme_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|serf_io_baton_t
block|{
name|int
name|type
decl_stmt|;
union|union
block|{
name|serf_incoming_t
modifier|*
name|client
decl_stmt|;
name|serf_connection_t
modifier|*
name|conn
decl_stmt|;
name|serf_listener_t
modifier|*
name|listener
decl_stmt|;
block|}
name|u
union|;
block|}
name|serf_io_baton_t
typedef|;
end_typedef

begin_comment
comment|/* Holds all the information corresponding to a request/response pair. */
end_comment

begin_struct
struct|struct
name|serf_request_t
block|{
name|serf_connection_t
modifier|*
name|conn
decl_stmt|;
name|apr_pool_t
modifier|*
name|respool
decl_stmt|;
name|serf_bucket_alloc_t
modifier|*
name|allocator
decl_stmt|;
comment|/* The bucket corresponding to the request. Will be NULL once the      * bucket has been emptied (for delivery into the socket).      */
name|serf_bucket_t
modifier|*
name|req_bkt
decl_stmt|;
name|serf_request_setup_t
name|setup
decl_stmt|;
name|void
modifier|*
name|setup_baton
decl_stmt|;
name|serf_response_acceptor_t
name|acceptor
decl_stmt|;
name|void
modifier|*
name|acceptor_baton
decl_stmt|;
name|serf_response_handler_t
name|handler
decl_stmt|;
name|void
modifier|*
name|handler_baton
decl_stmt|;
name|serf_bucket_t
modifier|*
name|resp_bkt
decl_stmt|;
name|int
name|writing_started
decl_stmt|;
name|int
name|priority
decl_stmt|;
comment|/* 1 if this is a request to setup a SSL tunnel, 0 for normal requests. */
name|int
name|ssltunnel
decl_stmt|;
comment|/* This baton is currently only used for digest authentication, which        needs access to the uri of the request in the response handler.        If serf_request_t is replaced by a serf_http_request_t in the future,        which knows about uri and method and such, this baton won't be needed        anymore. */
name|void
modifier|*
name|auth_baton
decl_stmt|;
name|struct
name|serf_request_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|serf_pollset_t
block|{
comment|/* the set of connections to poll */
name|apr_pollset_t
modifier|*
name|pollset
decl_stmt|;
block|}
name|serf_pollset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|serf__authn_info_t
block|{
specifier|const
name|serf__authn_scheme_t
modifier|*
name|scheme
decl_stmt|;
name|void
modifier|*
name|baton
decl_stmt|;
name|int
name|failed_authn_types
decl_stmt|;
block|}
name|serf__authn_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|serf_context_t
block|{
comment|/* the pool used for self and for other allocations */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|void
modifier|*
name|pollset_baton
decl_stmt|;
name|serf_socket_add_t
name|pollset_add
decl_stmt|;
name|serf_socket_remove_t
name|pollset_rm
decl_stmt|;
comment|/* one of our connections has a dirty pollset state. */
name|int
name|dirty_pollset
decl_stmt|;
comment|/* the list of active connections */
name|apr_array_header_t
modifier|*
name|conns
decl_stmt|;
define|#
directive|define
name|GET_CONN
parameter_list|(
name|ctx
parameter_list|,
name|i
parameter_list|)
value|(((serf_connection_t **)(ctx)->conns->elts)[i])
comment|/* Proxy server address */
name|apr_sockaddr_t
modifier|*
name|proxy_address
decl_stmt|;
comment|/* Progress callback */
name|serf_progress_t
name|progress_func
decl_stmt|;
name|void
modifier|*
name|progress_baton
decl_stmt|;
name|apr_off_t
name|progress_read
decl_stmt|;
name|apr_off_t
name|progress_written
decl_stmt|;
comment|/* authentication info for the servers used in this context. Shared by all        connections to the same server.        Structure of the hashtable:  key: host url, e.g. https://localhost:80                                   value: serf__authn_info_t *      */
name|apr_hash_t
modifier|*
name|server_authn_info
decl_stmt|;
comment|/* authentication info for the proxy configured in this context, shared by        all connections. */
name|serf__authn_info_t
name|proxy_authn_info
decl_stmt|;
comment|/* List of authn types supported by the client.*/
name|int
name|authn_types
decl_stmt|;
comment|/* Callback function used to get credentials for a realm. */
name|serf_credentials_callback_t
name|cred_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|serf_listener_t
block|{
name|serf_context_t
modifier|*
name|ctx
decl_stmt|;
name|serf_io_baton_t
name|baton
decl_stmt|;
name|apr_socket_t
modifier|*
name|skt
decl_stmt|;
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_pollfd_t
name|desc
decl_stmt|;
name|void
modifier|*
name|accept_baton
decl_stmt|;
name|serf_accept_client_t
name|accept_func
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|serf_incoming_t
block|{
name|serf_context_t
modifier|*
name|ctx
decl_stmt|;
name|serf_io_baton_t
name|baton
decl_stmt|;
name|void
modifier|*
name|request_baton
decl_stmt|;
name|serf_incoming_request_cb_t
name|request
decl_stmt|;
name|apr_socket_t
modifier|*
name|skt
decl_stmt|;
name|apr_pollfd_t
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* States for the different stages in the lifecyle of a connection. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SERF_CONN_INIT
block|,
comment|/* no socket created yet */
name|SERF_CONN_SETUP_SSLTUNNEL
block|,
comment|/* ssl tunnel being setup, no requests sent */
name|SERF_CONN_CONNECTED
block|,
comment|/* conn is ready to send requests */
name|SERF_CONN_CLOSING
comment|/* conn is closing, no more requests,                                    start a new socket */
block|}
name|serf__connection_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|serf_connection_t
block|{
name|serf_context_t
modifier|*
name|ctx
decl_stmt|;
name|apr_status_t
name|status
decl_stmt|;
name|serf_io_baton_t
name|baton
decl_stmt|;
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|serf_bucket_alloc_t
modifier|*
name|allocator
decl_stmt|;
name|apr_sockaddr_t
modifier|*
name|address
decl_stmt|;
name|apr_socket_t
modifier|*
name|skt
decl_stmt|;
name|apr_pool_t
modifier|*
name|skt_pool
decl_stmt|;
comment|/* the last reqevents we gave to pollset_add */
name|apr_int16_t
name|reqevents
decl_stmt|;
comment|/* the events we've seen for this connection in our returned pollset */
name|apr_int16_t
name|seen_in_pollset
decl_stmt|;
comment|/* are we a dirty connection that needs its poll status updated? */
name|int
name|dirty_conn
decl_stmt|;
comment|/* number of completed requests we've sent */
name|unsigned
name|int
name|completed_requests
decl_stmt|;
comment|/* number of completed responses we've got */
name|unsigned
name|int
name|completed_responses
decl_stmt|;
comment|/* keepalive */
name|unsigned
name|int
name|probable_keepalive_limit
decl_stmt|;
comment|/* Current state of the connection (whether or not it is connected). */
name|serf__connection_state_t
name|state
decl_stmt|;
comment|/* This connection may have responses without a request! */
name|int
name|async_responses
decl_stmt|;
name|serf_bucket_t
modifier|*
name|current_async_response
decl_stmt|;
name|serf_response_acceptor_t
name|async_acceptor
decl_stmt|;
name|void
modifier|*
name|async_acceptor_baton
decl_stmt|;
name|serf_response_handler_t
name|async_handler
decl_stmt|;
name|void
modifier|*
name|async_handler_baton
decl_stmt|;
comment|/* A bucket wrapped around our socket (for reading responses). */
name|serf_bucket_t
modifier|*
name|stream
decl_stmt|;
comment|/* A reference to the aggregate bucket that provides the boundary between      * request level buckets and connection level buckets.      */
name|serf_bucket_t
modifier|*
name|ostream_head
decl_stmt|;
name|serf_bucket_t
modifier|*
name|ostream_tail
decl_stmt|;
comment|/* Aggregate bucket used to send the CONNECT request. */
name|serf_bucket_t
modifier|*
name|ssltunnel_ostream
decl_stmt|;
comment|/* The list of active requests. */
name|serf_request_t
modifier|*
name|requests
decl_stmt|;
name|serf_request_t
modifier|*
name|requests_tail
decl_stmt|;
name|struct
name|iovec
name|vec
index|[
name|IOV_MAX
index|]
decl_stmt|;
name|int
name|vec_len
decl_stmt|;
name|serf_connection_setup_t
name|setup
decl_stmt|;
name|void
modifier|*
name|setup_baton
decl_stmt|;
name|serf_connection_closed_t
name|closed
decl_stmt|;
name|void
modifier|*
name|closed_baton
decl_stmt|;
comment|/* Max. number of outstanding requests. */
name|unsigned
name|int
name|max_outstanding_requests
decl_stmt|;
name|int
name|hit_eof
decl_stmt|;
comment|/* Host url, path ommitted, syntax: https://svn.apache.org . */
specifier|const
name|char
modifier|*
name|host_url
decl_stmt|;
comment|/* Exploded host url, path ommitted. Only scheme, hostinfo, hostname&        port values are filled in. */
name|apr_uri_t
name|host_info
decl_stmt|;
comment|/* authentication info for this connection. */
name|serf__authn_info_t
name|authn_info
decl_stmt|;
comment|/* Time marker when connection begins. */
name|apr_time_t
name|connect_time
decl_stmt|;
comment|/* Calculated connection latency. Negative value if latency is unknown. */
name|apr_interval_time_t
name|latency
decl_stmt|;
comment|/* Needs to read first before we can write again. */
name|int
name|stop_writing
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*** Internal bucket functions ***/
end_comment

begin_comment
comment|/** Transform a response_bucket in-place into an aggregate bucket. Restore the     status line and all headers, not just the body.       This can only be used when we haven't started reading the body of the     response yet.       Keep internal for now, probably only useful within serf.  */
end_comment

begin_function_decl
name|apr_status_t
name|serf_response_full_become_aggregate
parameter_list|(
name|serf_bucket_t
modifier|*
name|bucket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove the header from the list, do nothing if the header wasn't added.  */
end_comment

begin_function_decl
name|void
name|serf__bucket_headers_remove
parameter_list|(
name|serf_bucket_t
modifier|*
name|headers_bucket
parameter_list|,
specifier|const
name|char
modifier|*
name|header
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*** Authentication handler declarations ***/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PROXY
block|,
name|HOST
block|}
name|peer_t
typedef|;
end_typedef

begin_comment
comment|/**  * For each authentication scheme we need a handler function of type  * serf__auth_handler_func_t. This function will be called when an  * authentication challenge is received in a session.  */
end_comment

begin_typedef
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|serf__auth_handler_func_t
function_decl|)
parameter_list|(
name|int
name|code
parameter_list|,
name|serf_request_t
modifier|*
name|request
parameter_list|,
name|serf_bucket_t
modifier|*
name|response
parameter_list|,
specifier|const
name|char
modifier|*
name|auth_hdr
parameter_list|,
specifier|const
name|char
modifier|*
name|auth_attr
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * For each authentication scheme we need an initialization function of type  * serf__init_context_func_t. This function will be called the first time  * serf tries a specific authentication scheme handler.  */
end_comment

begin_typedef
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|serf__init_context_func_t
function_decl|)
parameter_list|(
name|int
name|code
parameter_list|,
name|serf_context_t
modifier|*
name|conn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * For each authentication scheme we need an initialization function of type  * serf__init_conn_func_t. This function will be called when a new  * connection is opened.  */
end_comment

begin_typedef
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|serf__init_conn_func_t
function_decl|)
parameter_list|(
specifier|const
name|serf__authn_scheme_t
modifier|*
name|scheme
parameter_list|,
name|int
name|code
parameter_list|,
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * For each authentication scheme we need a setup_request function of type  * serf__setup_request_func_t. This function will be called when a  * new serf_request_t object is created and should fill in the correct  * authentication headers (if needed).  */
end_comment

begin_typedef
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|serf__setup_request_func_t
function_decl|)
parameter_list|(
name|peer_t
name|peer
parameter_list|,
name|int
name|code
parameter_list|,
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|serf_request_t
modifier|*
name|request
parameter_list|,
specifier|const
name|char
modifier|*
name|method
parameter_list|,
specifier|const
name|char
modifier|*
name|uri
parameter_list|,
name|serf_bucket_t
modifier|*
name|hdrs_bkt
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * This function will be called when a response is received, so that the   * scheme handler can validate the Authentication related response headers  * (if needed).  */
end_comment

begin_typedef
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|serf__validate_response_func_t
function_decl|)
parameter_list|(
specifier|const
name|serf__authn_scheme_t
modifier|*
name|scheme
parameter_list|,
name|peer_t
name|peer
parameter_list|,
name|int
name|code
parameter_list|,
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|serf_request_t
modifier|*
name|request
parameter_list|,
name|serf_bucket_t
modifier|*
name|response
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * serf__authn_scheme_t: vtable for an authn scheme provider.  */
end_comment

begin_struct
struct|struct
name|serf__authn_scheme_t
block|{
comment|/* The name of this authentication scheme. Used in headers of requests and        for logging. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Key is the name of the authentication scheme in lower case, to        facilitate case insensitive matching of the response headers. */
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Internal code used for this authn type. */
name|int
name|type
decl_stmt|;
comment|/* The context initialization function if any; otherwise, NULL */
name|serf__init_context_func_t
name|init_ctx_func
decl_stmt|;
comment|/* The connection initialization function if any; otherwise, NULL */
name|serf__init_conn_func_t
name|init_conn_func
decl_stmt|;
comment|/* The authentication handler function */
name|serf__auth_handler_func_t
name|handle_func
decl_stmt|;
comment|/* Function to set up the authentication header of a request */
name|serf__setup_request_func_t
name|setup_request_func
decl_stmt|;
comment|/* Function to validate the authentication header of a response */
name|serf__validate_response_func_t
name|validate_response_func
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Handles a 401 or 407 response, tries the different available authentication  * handlers.  */
end_comment

begin_function_decl
name|apr_status_t
name|serf__handle_auth_response
parameter_list|(
name|int
modifier|*
name|consumed_response
parameter_list|,
name|serf_request_t
modifier|*
name|request
parameter_list|,
name|serf_bucket_t
modifier|*
name|response
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the cached serf__authn_info_t object for the target server, or create one    when this is the first connection to the server.    TODO: The serf__authn_info_t objects are allocated in the context pool, so    a context that's used to connect to many different servers using Basic or     Digest authencation will hold on to many objects indefinitely. We should be    able to cleanup stale objects from time to time. */
end_comment

begin_function_decl
name|serf__authn_info_t
modifier|*
name|serf__get_authn_info_for_server
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fromt context.c */
end_comment

begin_function_decl
name|void
name|serf__context_progress_delta
parameter_list|(
name|void
modifier|*
name|progress_baton
parameter_list|,
name|apr_off_t
name|read
parameter_list|,
name|apr_off_t
name|written
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from incoming.c */
end_comment

begin_function_decl
name|apr_status_t
name|serf__process_client
parameter_list|(
name|serf_incoming_t
modifier|*
name|l
parameter_list|,
name|apr_int16_t
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|serf__process_listener
parameter_list|(
name|serf_listener_t
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from outgoing.c */
end_comment

begin_function_decl
name|apr_status_t
name|serf__open_connections
parameter_list|(
name|serf_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|serf__process_connection
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|apr_int16_t
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|serf__conn_update_pollset
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|serf_request_t
modifier|*
name|serf__ssltunnel_request_create
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|,
name|serf_request_setup_t
name|setup
parameter_list|,
name|void
modifier|*
name|setup_baton
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|serf__provide_credentials
parameter_list|(
name|serf_context_t
modifier|*
name|ctx
parameter_list|,
name|char
modifier|*
modifier|*
name|username
parameter_list|,
name|char
modifier|*
modifier|*
name|password
parameter_list|,
name|serf_request_t
modifier|*
name|request
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|authn_type
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from ssltunnel.c */
end_comment

begin_function_decl
name|apr_status_t
name|serf__ssltunnel_connect
parameter_list|(
name|serf_connection_t
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Logging functions. Use one of the [COMP]_VERBOSE flags to enable specific     logging.   **/
end_comment

begin_comment
comment|/* Logs a standard event, with filename& timestamp header */
end_comment

begin_function_decl
name|void
name|serf__log
parameter_list|(
name|int
name|verbose_flag
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Logs a standard event, but without prefix. This is useful to build up  log lines in parts. */
end_comment

begin_function_decl
name|void
name|serf__log_nopref
parameter_list|(
name|int
name|verbose_flag
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Logs a socket event, add local and remote ip address:port */
end_comment

begin_function_decl
name|void
name|serf__log_skt
parameter_list|(
name|int
name|verbose_flag
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|apr_socket_t
modifier|*
name|skt
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

