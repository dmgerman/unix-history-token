begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_NETWORK_IO_H
end_ifndef

begin_define
define|#
directive|define
name|APR_NETWORK_IO_H
end_define

begin_comment
comment|/**  * @file apr_network_io.h  * @brief APR Network library  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_inherit.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_IN_H
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/**  * @defgroup apr_network_io Network Routines  * @ingroup APR   * @{  */
ifndef|#
directive|ifndef
name|APR_MAX_SECS_TO_LINGER
comment|/** Maximum seconds to linger */
define|#
directive|define
name|APR_MAX_SECS_TO_LINGER
value|30
endif|#
directive|endif
ifndef|#
directive|ifndef
name|APRMAXHOSTLEN
comment|/** Maximum hostname length */
define|#
directive|define
name|APRMAXHOSTLEN
value|256
endif|#
directive|endif
ifndef|#
directive|ifndef
name|APR_ANYADDR
comment|/** Default 'any' address */
define|#
directive|define
name|APR_ANYADDR
value|"0.0.0.0"
endif|#
directive|endif
comment|/**  * @defgroup apr_sockopt Socket option definitions  * @{  */
define|#
directive|define
name|APR_SO_LINGER
value|1
comment|/**< Linger */
define|#
directive|define
name|APR_SO_KEEPALIVE
value|2
comment|/**< Keepalive */
define|#
directive|define
name|APR_SO_DEBUG
value|4
comment|/**< Debug */
define|#
directive|define
name|APR_SO_NONBLOCK
value|8
comment|/**< Non-blocking IO */
define|#
directive|define
name|APR_SO_REUSEADDR
value|16
comment|/**< Reuse addresses */
define|#
directive|define
name|APR_SO_SNDBUF
value|64
comment|/**< Send buffer */
define|#
directive|define
name|APR_SO_RCVBUF
value|128
comment|/**< Receive buffer */
define|#
directive|define
name|APR_SO_DISCONNECTED
value|256
comment|/**< Disconnected */
define|#
directive|define
name|APR_TCP_NODELAY
value|512
comment|/**< For SCTP sockets, this is mapped                                    * to STCP_NODELAY internally.                                    */
define|#
directive|define
name|APR_TCP_NOPUSH
value|1024
comment|/**< No push */
define|#
directive|define
name|APR_RESET_NODELAY
value|2048
comment|/**< This flag is ONLY set internally                                    * when we set APR_TCP_NOPUSH with                                    * APR_TCP_NODELAY set to tell us that                                    * APR_TCP_NODELAY should be turned on                                    * again when NOPUSH is turned off                                    */
define|#
directive|define
name|APR_INCOMPLETE_READ
value|4096
comment|/**< Set on non-blocking sockets 				   * (timeout != 0) on which the 				   * previous read() did not fill a buffer 				   * completely.  the next apr_socket_recv()                                     * will first call select()/poll() rather than 				   * going straight into read().  (Can also 				   * be set by an application to force a 				   * select()/poll() call before the next 				   * read, in cases where the app expects 				   * that an immediate read would fail.) 				   */
define|#
directive|define
name|APR_INCOMPLETE_WRITE
value|8192
comment|/**< like APR_INCOMPLETE_READ, but for write                                    * @see APR_INCOMPLETE_READ                                    */
define|#
directive|define
name|APR_IPV6_V6ONLY
value|16384
comment|/**< Don't accept IPv4 connections on an                                    * IPv6 listening socket.                                    */
define|#
directive|define
name|APR_TCP_DEFER_ACCEPT
value|32768
comment|/**< Delay accepting of new connections                                      * until data is available.                                     * @see apr_socket_accept_filter                                     */
define|#
directive|define
name|APR_SO_BROADCAST
value|65536
comment|/**< Allow broadcast                                     */
comment|/** @} */
comment|/** Define what type of socket shutdown should occur. */
typedef|typedef
enum|enum
block|{
name|APR_SHUTDOWN_READ
block|,
comment|/**< no longer allow read request */
name|APR_SHUTDOWN_WRITE
block|,
comment|/**< no longer allow write requests */
name|APR_SHUTDOWN_READWRITE
comment|/**< no longer allow read or write requests */
block|}
name|apr_shutdown_how_e
typedef|;
define|#
directive|define
name|APR_IPV4_ADDR_OK
value|0x01
comment|/**< @see apr_sockaddr_info_get() */
define|#
directive|define
name|APR_IPV6_ADDR_OK
value|0x02
comment|/**< @see apr_sockaddr_info_get() */
if|#
directive|if
operator|(
operator|!
name|APR_HAVE_IN_ADDR
operator|)
comment|/**  * We need to make sure we always have an in_addr type, so APR will just  * define it ourselves, if the platform doesn't provide it.  */
struct|struct
name|in_addr
block|{
name|apr_uint32_t
name|s_addr
decl_stmt|;
comment|/**< storage to hold the IP# */
block|}
struct|;
endif|#
directive|endif
comment|/** @def APR_INADDR_NONE  * Not all platforms have a real INADDR_NONE.  This macro replaces  * INADDR_NONE on all platforms.  */
ifdef|#
directive|ifdef
name|INADDR_NONE
define|#
directive|define
name|APR_INADDR_NONE
value|INADDR_NONE
else|#
directive|else
define|#
directive|define
name|APR_INADDR_NONE
value|((unsigned int) 0xffffffff)
endif|#
directive|endif
comment|/**  * @def APR_INET  * Not all platforms have these defined, so we'll define them here  * The default values come from FreeBSD 4.1.1  */
define|#
directive|define
name|APR_INET
value|AF_INET
comment|/** @def APR_UNSPEC  * Let the system decide which address family to use  */
ifdef|#
directive|ifdef
name|AF_UNSPEC
define|#
directive|define
name|APR_UNSPEC
value|AF_UNSPEC
else|#
directive|else
define|#
directive|define
name|APR_UNSPEC
value|0
endif|#
directive|endif
if|#
directive|if
name|APR_HAVE_IPV6
comment|/** @def APR_INET6 * IPv6 Address Family. Not all platforms may have this defined. */
define|#
directive|define
name|APR_INET6
value|AF_INET6
endif|#
directive|endif
comment|/**  * @defgroup IP_Proto IP Protocol Definitions for use when creating sockets  * @{  */
define|#
directive|define
name|APR_PROTO_TCP
value|6
comment|/**< TCP  */
define|#
directive|define
name|APR_PROTO_UDP
value|17
comment|/**< UDP  */
define|#
directive|define
name|APR_PROTO_SCTP
value|132
comment|/**< SCTP */
comment|/** @} */
comment|/**  * Enum used to denote either the local and remote endpoint of a  * connection.  */
typedef|typedef
enum|enum
block|{
name|APR_LOCAL
block|,
comment|/**< Socket information for local end of connection */
name|APR_REMOTE
comment|/**< Socket information for remote end of connection */
block|}
name|apr_interface_e
typedef|;
comment|/**  * The specific declaration of inet_addr's ... some platforms fall back  * inet_network (this is not good, but necessary)  */
if|#
directive|if
name|APR_HAVE_INET_ADDR
define|#
directive|define
name|apr_inet_addr
value|inet_addr
elif|#
directive|elif
name|APR_HAVE_INET_NETWORK
comment|/* only DGUX, as far as I know */
comment|/**  * @warning  * not generally safe... inet_network() and inet_addr() perform  * different functions */
define|#
directive|define
name|apr_inet_addr
value|inet_network
endif|#
directive|endif
comment|/** A structure to represent sockets */
typedef|typedef
name|struct
name|apr_socket_t
name|apr_socket_t
typedef|;
comment|/**  * A structure to encapsulate headers and trailers for apr_socket_sendfile  */
typedef|typedef
name|struct
name|apr_hdtr_t
name|apr_hdtr_t
typedef|;
comment|/** A structure to represent in_addr */
typedef|typedef
name|struct
name|in_addr
name|apr_in_addr_t
typedef|;
comment|/** A structure to represent an IP subnet */
typedef|typedef
name|struct
name|apr_ipsubnet_t
name|apr_ipsubnet_t
typedef|;
comment|/** @remark use apr_uint16_t just in case some system has a short that isn't 16 bits... */
typedef|typedef
name|apr_uint16_t
name|apr_port_t
typedef|;
comment|/** @remark It's defined here as I think it should all be platform safe...  * @see apr_sockaddr_t  */
typedef|typedef
name|struct
name|apr_sockaddr_t
name|apr_sockaddr_t
typedef|;
comment|/**  * APRs socket address type, used to ensure protocol independence  */
struct|struct
name|apr_sockaddr_t
block|{
comment|/** The pool to use... */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** The hostname */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/** Either a string of the port number or the service name for the port */
name|char
modifier|*
name|servname
decl_stmt|;
comment|/** The numeric port */
name|apr_port_t
name|port
decl_stmt|;
comment|/** The family */
name|apr_int32_t
name|family
decl_stmt|;
comment|/** How big is the sockaddr we're using? */
name|apr_socklen_t
name|salen
decl_stmt|;
comment|/** How big is the ip address structure we're using? */
name|int
name|ipaddr_len
decl_stmt|;
comment|/** How big should the address buffer be?  16 for v4 or 46 for v6      *  used in inet_ntop... */
name|int
name|addr_str_len
decl_stmt|;
comment|/** This points to the IP address structure within the appropriate      *  sockaddr structure.  */
name|void
modifier|*
name|ipaddr_ptr
decl_stmt|;
comment|/** If multiple addresses were found by apr_sockaddr_info_get(), this       *  points to a representation of the next address. */
name|apr_sockaddr_t
modifier|*
name|next
decl_stmt|;
comment|/** Union of either IPv4 or IPv6 sockaddr. */
union|union
block|{
comment|/** IPv4 sockaddr structure */
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
if|#
directive|if
name|APR_HAVE_IPV6
comment|/** IPv6 sockaddr structure */
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAVE_SA_STORAGE
comment|/** Placeholder to ensure that the size of this union is not          * dependent on whether APR_HAVE_IPV6 is defined. */
name|struct
name|sockaddr_storage
name|sas
decl_stmt|;
endif|#
directive|endif
block|}
name|sa
union|;
block|}
struct|;
if|#
directive|if
name|APR_HAS_SENDFILE
comment|/**   * Support reusing the socket on platforms which support it (from disconnect,  * specifically Win32.  * @remark Optional flag passed into apr_socket_sendfile()   */
define|#
directive|define
name|APR_SENDFILE_DISCONNECT_SOCKET
value|1
endif|#
directive|endif
comment|/** A structure to encapsulate headers and trailers for apr_socket_sendfile */
struct|struct
name|apr_hdtr_t
block|{
comment|/** An iovec to store the headers sent before the file. */
name|struct
name|iovec
modifier|*
name|headers
decl_stmt|;
comment|/** number of headers in the iovec */
name|int
name|numheaders
decl_stmt|;
comment|/** An iovec to store the trailers sent after the file. */
name|struct
name|iovec
modifier|*
name|trailers
decl_stmt|;
comment|/** number of trailers in the iovec */
name|int
name|numtrailers
decl_stmt|;
block|}
struct|;
comment|/* function definitions */
comment|/**  * Create a socket.  * @param new_sock The new socket that has been set up.  * @param family The address family of the socket (e.g., APR_INET).  * @param type The type of the socket (e.g., SOCK_STREAM).  * @param protocol The protocol of the socket (e.g., APR_PROTO_TCP).  * @param cont The pool for the apr_socket_t and associated storage.  * @note The pool will be used by various functions that operate on the  *       socket. The caller must ensure that it is not used by other threads  *       at the same time.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_create
argument_list|(
argument|apr_socket_t **new_sock
argument_list|,
argument|int family
argument_list|,
argument|int type
argument_list|,
argument|int protocol
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * Shutdown either reading, writing, or both sides of a socket.  * @param thesocket The socket to close   * @param how How to shutdown the socket.  One of:  *<PRE>  *            APR_SHUTDOWN_READ         no longer allow read requests  *            APR_SHUTDOWN_WRITE        no longer allow write requests  *            APR_SHUTDOWN_READWRITE    no longer allow read or write requests   *</PRE>  * @see apr_shutdown_how_e  * @remark This does not actually close the socket descriptor, it just  *      controls which calls are still valid on the socket.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_shutdown
argument_list|(
argument|apr_socket_t *thesocket
argument_list|,
argument|apr_shutdown_how_e how
argument_list|)
empty_stmt|;
comment|/**  * Close a socket.  * @param thesocket The socket to close   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_close
argument_list|(
name|apr_socket_t
operator|*
name|thesocket
argument_list|)
expr_stmt|;
comment|/**  * Bind the socket to its associated port  * @param sock The socket to bind   * @param sa The socket address to bind to  * @remark This may be where we will find out if there is any other process  *      using the selected port.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_bind
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_sockaddr_t
operator|*
name|sa
argument_list|)
expr_stmt|;
comment|/**  * Listen to a bound socket for connections.  * @param sock The socket to listen on   * @param backlog The number of outstanding connections allowed in the sockets  *                listen queue.  If this value is less than zero, the listen  *                queue size is set to zero.    */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_listen
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_int32_t backlog
argument_list|)
empty_stmt|;
comment|/**  * Accept a new connection request  * @param new_sock A copy of the socket that is connected to the socket that  *                 made the connection request.  This is the socket which should  *                 be used for all future communication.  * @param sock The socket we are listening on.  * @param connection_pool The pool for the new socket.  * @note The pool will be used by various functions that operate on the  *       socket. The caller must ensure that it is not used by other threads  *       at the same time.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_accept
argument_list|(
name|apr_socket_t
operator|*
operator|*
name|new_sock
argument_list|,
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_pool_t
operator|*
name|connection_pool
argument_list|)
expr_stmt|;
comment|/**  * Issue a connection request to a socket either on the same machine   * or a different one.  * @param sock The socket we wish to use for our side of the connection   * @param sa The address of the machine we wish to connect to.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_connect
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_sockaddr_t
operator|*
name|sa
argument_list|)
expr_stmt|;
comment|/**  * Determine whether the receive part of the socket has been closed by  * the peer (such that a subsequent call to apr_socket_read would  * return APR_EOF), if the socket's receive buffer is empty.  This  * function does not block waiting for I/O.  *  * @param sock The socket to check  * @param atreadeof If APR_SUCCESS is returned, *atreadeof is set to  *                  non-zero if a subsequent read would return APR_EOF  * @return an error is returned if it was not possible to determine the  *         status, in which case *atreadeof is not changed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_atreadeof
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|int
operator|*
name|atreadeof
argument_list|)
expr_stmt|;
comment|/**  * Create apr_sockaddr_t from hostname, address family, and port.  * @param sa The new apr_sockaddr_t.  * @param hostname The hostname or numeric address string to resolve/parse, or  *               NULL to build an address that corresponds to 0.0.0.0 or ::  * @param family The address family to use, or APR_UNSPEC if the system should   *               decide.  * @param port The port number.  * @param flags Special processing flags:  *<PRE>  *       APR_IPV4_ADDR_OK          first query for IPv4 addresses; only look  *                                 for IPv6 addresses if the first query failed;  *                                 only valid if family is APR_UNSPEC and hostname  *                                 isn't NULL; mutually exclusive with  *                                 APR_IPV6_ADDR_OK  *       APR_IPV6_ADDR_OK          first query for IPv6 addresses; only look  *                                 for IPv4 addresses if the first query failed;  *                                 only valid if family is APR_UNSPEC and hostname  *                                 isn't NULL and APR_HAVE_IPV6; mutually exclusive  *                                 with APR_IPV4_ADDR_OK  *</PRE>  * @param p The pool for the apr_sockaddr_t and associated storage.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_sockaddr_info_get
argument_list|(
argument|apr_sockaddr_t **sa
argument_list|,
argument|const char *hostname
argument_list|,
argument|apr_int32_t family
argument_list|,
argument|apr_port_t port
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Look up the host name from an apr_sockaddr_t.  * @param hostname The hostname.  * @param sa The apr_sockaddr_t.  * @param flags Special processing flags.  * @remark Results can vary significantly between platforms  * when processing wildcard socket addresses.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_getnameinfo
argument_list|(
argument|char **hostname
argument_list|,
argument|apr_sockaddr_t *sa
argument_list|,
argument|apr_int32_t flags
argument_list|)
empty_stmt|;
comment|/**  * Parse hostname/IP address with scope id and port.  *  * Any of the following strings are accepted:  *   8080                  (just the port number)  *   www.apache.org        (just the hostname)  *   www.apache.org:8080   (hostname and port number)  *   [fe80::1]:80          (IPv6 numeric address string only)  *   [fe80::1%eth0]        (IPv6 numeric address string and scope id)  *  * Invalid strings:  *                         (empty string)  *   [abc]                 (not valid IPv6 numeric address string)  *   abc:65536             (invalid port number)  *  * @param addr The new buffer containing just the hostname.  On output, *addr   *             will be NULL if no hostname/IP address was specfied.  * @param scope_id The new buffer containing just the scope id.  On output,   *                 *scope_id will be NULL if no scope id was specified.  * @param port The port number.  On output, *port will be 0 if no port was   *             specified.  *             ### FIXME: 0 is a legal port (per RFC 1700). this should  *             ### return something besides zero if the port is missing.  * @param str The input string to be parsed.  * @param p The pool from which *addr and *scope_id are allocated.  * @remark If scope id shouldn't be allowed, check for scope_id != NULL in   *         addition to checking the return code.  If addr/hostname should be   *         required, check for addr == NULL in addition to checking the   *         return code.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_parse_addr_port
argument_list|(
name|char
operator|*
operator|*
name|addr
argument_list|,
name|char
operator|*
operator|*
name|scope_id
argument_list|,
name|apr_port_t
operator|*
name|port
argument_list|,
specifier|const
name|char
operator|*
name|str
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Get name of the current machine  * @param buf A buffer to store the hostname in.  * @param len The maximum length of the hostname that can be stored in the  *            buffer provided.  The suggested length is APRMAXHOSTLEN + 1.  * @param cont The pool to use.  * @remark If the buffer was not large enough, an error will be returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_gethostname
argument_list|(
argument|char *buf
argument_list|,
argument|int len
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * Return the data associated with the current socket  * @param data The user data associated with the socket.  * @param key The key to associate with the user data.  * @param sock The currently open socket.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_data_get
argument_list|(
name|void
operator|*
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_socket_t
operator|*
name|sock
argument_list|)
expr_stmt|;
comment|/**  * Set the data associated with the current socket.  * @param sock The currently open socket.  * @param data The user data to associate with the socket.  * @param key The key to associate with the data.  * @param cleanup The cleanup to call when the socket is destroyed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_data_set
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|void
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_status_t
argument_list|(
operator|*
name|cleanup
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/**  * Send data over a network.  * @param sock The socket to send the data over.  * @param buf The buffer which contains the data to be sent.   * @param len On entry, the number of bytes to send; on exit, the number  *            of bytes sent.  * @remark  *<PRE>  * This functions acts like a blocking write by default.  To change   * this behavior, use apr_socket_timeout_set() or the APR_SO_NONBLOCK  * socket option.  *  * It is possible for both bytes to be sent and an error to be returned.  *  * APR_EINTR is never returned.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_send
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
specifier|const
name|char
operator|*
name|buf
argument_list|,
name|apr_size_t
operator|*
name|len
argument_list|)
expr_stmt|;
comment|/**  * Send multiple buffers over a network.  * @param sock The socket to send the data over.  * @param vec The array of iovec structs containing the data to send   * @param nvec The number of iovec structs in the array  * @param len Receives the number of bytes actually written  * @remark  *<PRE>  * This functions acts like a blocking write by default.  To change   * this behavior, use apr_socket_timeout_set() or the APR_SO_NONBLOCK  * socket option.  * The number of bytes actually sent is stored in argument 4.  *  * It is possible for both bytes to be sent and an error to be returned.  *  * APR_EINTR is never returned.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_sendv
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|const struct iovec *vec
argument_list|,
argument|apr_int32_t nvec
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * @param sock The socket to send from  * @param where The apr_sockaddr_t describing where to send the data  * @param flags The flags to use  * @param buf  The data to send  * @param len  The length of the data to send  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_sendto
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_sockaddr_t *where
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|const char *buf
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
comment|/**  * Read data from a socket.  On success, the address of the peer from  * which the data was sent is copied into the @a from parameter, and the  * @a len parameter is updated to give the number of bytes written to  * @a buf.  *  * @param from Updated with the address from which the data was received  * @param sock The socket to use  * @param flags The flags to use  * @param buf  The buffer to use  * @param len  The length of the available buffer  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_recvfrom
argument_list|(
argument|apr_sockaddr_t *from
argument_list|,
argument|apr_socket_t *sock
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|char *buf
argument_list|,
argument|apr_size_t *len
argument_list|)
empty_stmt|;
if|#
directive|if
name|APR_HAS_SENDFILE
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Send a file from an open file descriptor to a socket, along with   * optional headers and trailers  * @param sock The socket to which we're writing  * @param file The open file from which to read  * @param hdtr A structure containing the headers and trailers to send  * @param offset Offset into the file where we should begin writing  * @param len (input)  - Number of bytes to send from the file   *            (output) - Number of bytes actually sent,   *                       including headers, file, and trailers  * @param flags APR flags that are mapped to OS specific flags  * @remark This functions acts like a blocking write by default.  To change   *         this behavior, use apr_socket_timeout_set() or the  *         APR_SO_NONBLOCK socket option.  * The number of bytes actually sent is stored in the len parameter.  * The offset parameter is passed by reference for no reason; its  * value will never be modified by the apr_socket_sendfile() function.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_sendfile
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_file_t *file
argument_list|,
argument|apr_hdtr_t *hdtr
argument_list|,
argument|apr_off_t *offset
argument_list|,
argument|apr_size_t *len
argument_list|,
argument|apr_int32_t flags
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_SENDFILE */
comment|/**  * Read data from a network.  * @param sock The socket to read the data from.  * @param buf The buffer to store the data in.   * @param len On entry, the number of bytes to receive; on exit, the number  *            of bytes received.  * @remark  *<PRE>  * This functions acts like a blocking read by default.  To change   * this behavior, use apr_socket_timeout_set() or the APR_SO_NONBLOCK  * socket option.  * The number of bytes actually received is stored in argument 3.  *  * It is possible for both bytes to be received and an APR_EOF or  * other error to be returned.  *  * APR_EINTR is never returned.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_recv
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|char
operator|*
name|buf
argument_list|,
name|apr_size_t
operator|*
name|len
argument_list|)
expr_stmt|;
comment|/**  * Setup socket options for the specified socket  * @param sock The socket to set up.  * @param opt The option we would like to configure.  One of:  *<PRE>  *            APR_SO_DEBUG      --  turn on debugging information   *            APR_SO_KEEPALIVE  --  keep connections active  *            APR_SO_LINGER     --  lingers on close if data is present  *            APR_SO_NONBLOCK   --  Turns blocking on/off for socket  *                                  When this option is enabled, use  *                                  the APR_STATUS_IS_EAGAIN() macro to  *                                  see if a send or receive function  *                                  could not transfer data without  *                                  blocking.  *            APR_SO_REUSEADDR  --  The rules used in validating addresses  *                                  supplied to bind should allow reuse  *                                  of local addresses.  *            APR_SO_SNDBUF     --  Set the SendBufferSize  *            APR_SO_RCVBUF     --  Set the ReceiveBufferSize  *</PRE>  * @param on Value for the option.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_opt_set
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_int32_t opt
argument_list|,
argument|apr_int32_t on
argument_list|)
empty_stmt|;
comment|/**  * Setup socket timeout for the specified socket  * @param sock The socket to set up.  * @param t Value for the timeout.  *<PRE>  *   t> 0  -- read and write calls return APR_TIMEUP if specified time  *             elapsess with no data read or written  *   t == 0 -- read and write calls never block  *   t< 0  -- read and write calls block  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_timeout_set
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_interval_time_t t
argument_list|)
empty_stmt|;
comment|/**  * Query socket options for the specified socket  * @param sock The socket to query  * @param opt The option we would like to query.  One of:  *<PRE>  *            APR_SO_DEBUG      --  turn on debugging information   *            APR_SO_KEEPALIVE  --  keep connections active  *            APR_SO_LINGER     --  lingers on close if data is present  *            APR_SO_NONBLOCK   --  Turns blocking on/off for socket  *            APR_SO_REUSEADDR  --  The rules used in validating addresses  *                                  supplied to bind should allow reuse  *                                  of local addresses.  *            APR_SO_SNDBUF     --  Set the SendBufferSize  *            APR_SO_RCVBUF     --  Set the ReceiveBufferSize  *            APR_SO_DISCONNECTED -- Query the disconnected state of the socket.  *                                  (Currently only used on Windows)  *</PRE>  * @param on Socket option returned on the call.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_opt_get
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_int32_t opt
argument_list|,
argument|apr_int32_t *on
argument_list|)
empty_stmt|;
comment|/**  * Query socket timeout for the specified socket  * @param sock The socket to query  * @param t Socket timeout returned from the query.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_timeout_get
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_interval_time_t
operator|*
name|t
argument_list|)
expr_stmt|;
comment|/**  * Query the specified socket if at the OOB/Urgent data mark  * @param sock The socket to query  * @param atmark Is set to true if socket is at the OOB/urgent mark,  *               otherwise is set to false.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_atmark
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|int
operator|*
name|atmark
argument_list|)
expr_stmt|;
comment|/**  * Return an address associated with a socket; either the address to  * which the socket is bound locally or the address of the peer  * to which the socket is connected.  * @param sa The returned apr_sockaddr_t.  * @param which Whether to retrieve the local or remote address  * @param sock The socket to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_addr_get
argument_list|(
argument|apr_sockaddr_t **sa
argument_list|,
argument|apr_interface_e which
argument_list|,
argument|apr_socket_t *sock
argument_list|)
empty_stmt|;
comment|/**  * Return the IP address (in numeric address string format) in  * an APR socket address.  APR will allocate storage for the IP address   * string from the pool of the apr_sockaddr_t.  * @param addr The IP address.  * @param sockaddr The socket address to reference.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_sockaddr_ip_get
argument_list|(
name|char
operator|*
operator|*
name|addr
argument_list|,
name|apr_sockaddr_t
operator|*
name|sockaddr
argument_list|)
expr_stmt|;
comment|/**  * Write the IP address (in numeric address string format) of the APR  * socket address @a sockaddr into the buffer @a buf (of size @a buflen).  * @param sockaddr The socket address to reference.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_sockaddr_ip_getbuf
argument_list|(
argument|char *buf
argument_list|,
argument|apr_size_t buflen
argument_list|,
argument|apr_sockaddr_t *sockaddr
argument_list|)
empty_stmt|;
comment|/**  * See if the IP addresses in two APR socket addresses are  * equivalent.  Appropriate logic is present for comparing  * IPv4-mapped IPv6 addresses with IPv4 addresses.  *  * @param addr1 One of the APR socket addresses.  * @param addr2 The other APR socket address.  * @remark The return value will be non-zero if the addresses  * are equivalent.  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_sockaddr_equal
argument_list|(
specifier|const
name|apr_sockaddr_t
operator|*
name|addr1
argument_list|,
specifier|const
name|apr_sockaddr_t
operator|*
name|addr2
argument_list|)
expr_stmt|;
comment|/**  * See if the IP address in an APR socket address refers to the wildcard  * address for the protocol family (e.g., INADDR_ANY for IPv4).  *  * @param addr The APR socket address to examine.  * @remark The return value will be non-zero if the address is  * initialized and is the wildcard address.  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_sockaddr_is_wildcard
argument_list|(
specifier|const
name|apr_sockaddr_t
operator|*
name|addr
argument_list|)
expr_stmt|;
comment|/** * Return the type of the socket. * @param sock The socket to query. * @param type The returned type (e.g., SOCK_STREAM). */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_type_get
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|int
operator|*
name|type
argument_list|)
expr_stmt|;
comment|/**  * Given an apr_sockaddr_t and a service name, set the port for the service  * @param sockaddr The apr_sockaddr_t that will have its port set  * @param servname The name of the service you wish to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_getservbyname
argument_list|(
name|apr_sockaddr_t
operator|*
name|sockaddr
argument_list|,
specifier|const
name|char
operator|*
name|servname
argument_list|)
expr_stmt|;
comment|/**  * Build an ip-subnet representation from an IP address and optional netmask or  * number-of-bits.  * @param ipsub The new ip-subnet representation  * @param ipstr The input IP address string  * @param mask_or_numbits The input netmask or number-of-bits string, or NULL  * @param p The pool to allocate from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_ipsubnet_create
argument_list|(
name|apr_ipsubnet_t
operator|*
operator|*
name|ipsub
argument_list|,
specifier|const
name|char
operator|*
name|ipstr
argument_list|,
specifier|const
name|char
operator|*
name|mask_or_numbits
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Test the IP address in an apr_sockaddr_t against a pre-built ip-subnet  * representation.  * @param ipsub The ip-subnet representation  * @param sa The socket address to test  * @return non-zero if the socket address is within the subnet, 0 otherwise  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_ipsubnet_test
argument_list|(
name|apr_ipsubnet_t
operator|*
name|ipsub
argument_list|,
name|apr_sockaddr_t
operator|*
name|sa
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_SO_ACCEPTFILTER
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Set an OS level accept filter.  * @param sock The socket to put the accept filter on.  * @param name The accept filter  * @param args Any extra args to the accept filter.  Passing NULL here removes  *             the accept filter.   * @bug name and args should have been declared as const char *, as they are in  * APR 2.0  */
name|apr_status_t
name|apr_socket_accept_filter
parameter_list|(
name|apr_socket_t
modifier|*
name|sock
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/**  * Return the protocol of the socket.  * @param sock The socket to query.  * @param protocol The returned protocol (e.g., APR_PROTO_TCP).  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_socket_protocol_get
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|int
operator|*
name|protocol
argument_list|)
expr_stmt|;
comment|/**  * Get the pool used by the socket.  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|socket
argument_list|)
expr_stmt|;
comment|/**  * Set a socket to be inherited by child processes.  */
name|APR_DECLARE_INHERIT_SET
argument_list|(
name|socket
argument_list|)
expr_stmt|;
comment|/**  * Unset a socket from being inherited by child processes.  */
name|APR_DECLARE_INHERIT_UNSET
argument_list|(
name|socket
argument_list|)
expr_stmt|;
comment|/**  * @defgroup apr_mcast IP Multicast  * @{  */
comment|/**  * Join a Multicast Group  * @param sock The socket to join a multicast group  * @param join The address of the multicast group to join  * @param iface Address of the interface to use.  If NULL is passed, the   *              default multicast interface will be used. (OS Dependent)  * @param source Source Address to accept transmissions from (non-NULL   *               implies Source-Specific Multicast)  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mcast_join
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_sockaddr_t
operator|*
name|join
argument_list|,
name|apr_sockaddr_t
operator|*
name|iface
argument_list|,
name|apr_sockaddr_t
operator|*
name|source
argument_list|)
expr_stmt|;
comment|/**  * Leave a Multicast Group.  All arguments must be the same as  * apr_mcast_join.  * @param sock The socket to leave a multicast group  * @param addr The address of the multicast group to leave  * @param iface Address of the interface to use.  If NULL is passed, the   *              default multicast interface will be used. (OS Dependent)  * @param source Source Address to accept transmissions from (non-NULL   *               implies Source-Specific Multicast)  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mcast_leave
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_sockaddr_t
operator|*
name|addr
argument_list|,
name|apr_sockaddr_t
operator|*
name|iface
argument_list|,
name|apr_sockaddr_t
operator|*
name|source
argument_list|)
expr_stmt|;
comment|/**  * Set the Multicast Time to Live (ttl) for a multicast transmission.  * @param sock The socket to set the multicast ttl  * @param ttl Time to live to Assign. 0-255, default=1  * @remark If the TTL is 0, packets will only be seen by sockets on   * the local machine, and only when multicast loopback is enabled.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mcast_hops
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_byte_t ttl
argument_list|)
empty_stmt|;
comment|/**  * Toggle IP Multicast Loopback  * @param sock The socket to set multicast loopback  * @param opt 0=disable, 1=enable  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mcast_loopback
argument_list|(
argument|apr_socket_t *sock
argument_list|,
argument|apr_byte_t opt
argument_list|)
empty_stmt|;
comment|/**  * Set the Interface to be used for outgoing Multicast Transmissions.  * @param sock The socket to set the multicast interface on  * @param iface Address of the interface to use for Multicast  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_mcast_interface
argument_list|(
name|apr_socket_t
operator|*
name|sock
argument_list|,
name|apr_sockaddr_t
operator|*
name|iface
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_NETWORK_IO_H */
end_comment

end_unit

