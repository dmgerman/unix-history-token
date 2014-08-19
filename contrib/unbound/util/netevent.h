begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/netevent.h - event notification  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains event notification functions.  *  * There are three types of communication points  *    o UDP socket - perthread buffer.  *    o TCP-accept socket - array of TCP-sockets, socketcount.  *    o TCP socket - own buffer, parent-TCPaccept, read/write state,  *                   number of bytes read/written, timeout.  *  * There are sockets aimed towards our clients and towards the internet.  *    o frontside - aimed towards our clients, queries come in, answers back.  *    o behind - aimed towards internet, to the authoritative DNS servers.  *  * Several event types are available:  *    o comm_base - for thread safety of the comm points, one per thread.  *    o comm_point - udp and tcp networking, with callbacks.  *    o comm_timer - a timeout with callback.  *    o comm_signal - callbacks when signal is caught.  *    o comm_reply - holds reply info during networking callback.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NET_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|NET_EVENT_H
end_define

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/* internal event notification data storage structure. */
end_comment

begin_struct_decl
struct_decl|struct
name|internal_event
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_timer
struct_decl|;
end_struct_decl

begin_comment
comment|/** callback from communication point function type */
end_comment

begin_typedef
typedef|typedef
name|int
name|comm_point_callback_t
parameter_list|(
name|struct
name|comm_point
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|comm_reply
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** to pass no_error to callback function */
end_comment

begin_define
define|#
directive|define
name|NETEVENT_NOERROR
value|0
end_define

begin_comment
comment|/** to pass closed connection to callback function */
end_comment

begin_define
define|#
directive|define
name|NETEVENT_CLOSED
value|-1
end_define

begin_comment
comment|/** to pass timeout happened to callback function */
end_comment

begin_define
define|#
directive|define
name|NETEVENT_TIMEOUT
value|-2
end_define

begin_comment
comment|/** to pass fallback from capsforID to callback function; 0x20 failed */
end_comment

begin_define
define|#
directive|define
name|NETEVENT_CAPSFAIL
value|-3
end_define

begin_comment
comment|/** timeout to slow accept calls when not possible, in msec. */
end_comment

begin_define
define|#
directive|define
name|NETEVENT_SLOW_ACCEPT_TIME
value|2000
end_define

begin_comment
comment|/**  * A communication point dispatcher. Thread specific.  */
end_comment

begin_struct
struct|struct
name|comm_base
block|{
comment|/** behind the scenes structure. with say libevent info. alloced */
name|struct
name|internal_base
modifier|*
name|eb
decl_stmt|;
comment|/** callback to stop listening on accept sockets, 	 * performed when accept() will not function properly */
name|void
function_decl|(
modifier|*
name|stop_accept
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** callback to start listening on accept sockets, performed 	 * after stop_accept() then a timeout has passed. */
name|void
function_decl|(
modifier|*
name|start_accept
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** user argument for stop_accept and start_accept functions */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Reply information for a communication point.  */
end_comment

begin_struct
struct|struct
name|comm_reply
block|{
comment|/** the comm_point with fd to send reply on to. */
name|struct
name|comm_point
modifier|*
name|c
decl_stmt|;
comment|/** the address (for UDP based communication) */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of address */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** return type 0 (none), 4(IP4), 6(IP6) */
name|int
name|srctype
decl_stmt|;
comment|/** the return source interface data */
union|union
block|{
ifdef|#
directive|ifdef
name|IPV6_PKTINFO
name|struct
name|in6_pktinfo
name|v6info
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IP_PKTINFO
name|struct
name|in_pktinfo
name|v4info
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|IP_RECVDSTADDR
argument_list|)
name|struct
name|in_addr
name|v4addr
decl_stmt|;
endif|#
directive|endif
block|}
comment|/** variable with return source data */
name|pktinfo
union|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Communication point to the network   * These behaviours can be accomplished by setting the flags  * and passing return values from the callback.  *    udp frontside: called after readdone. sendafter.  *    tcp frontside: called readdone, sendafter. close.  *    udp behind: called after readdone. No send after.  *    tcp behind: write done, read done, then called. No send after.  */
end_comment

begin_struct
struct|struct
name|comm_point
block|{
comment|/** behind the scenes structure, with say libevent info. alloced. */
name|struct
name|internal_event
modifier|*
name|ev
decl_stmt|;
comment|/** file descriptor for communication point */
name|int
name|fd
decl_stmt|;
comment|/** timeout (NULL if it does not). Malloced. */
name|struct
name|timeval
modifier|*
name|timeout
decl_stmt|;
comment|/** buffer pointer. Either to perthread, or own buffer or NULL */
name|struct
name|sldns_buffer
modifier|*
name|buffer
decl_stmt|;
comment|/* -------- TCP Handler -------- */
comment|/** Read/Write state for TCP */
name|int
name|tcp_is_reading
decl_stmt|;
comment|/** The current read/write count for TCP */
name|size_t
name|tcp_byte_count
decl_stmt|;
comment|/** parent communication point (for TCP sockets) */
name|struct
name|comm_point
modifier|*
name|tcp_parent
decl_stmt|;
comment|/** sockaddr from peer, for TCP handlers */
name|struct
name|comm_reply
name|repinfo
decl_stmt|;
comment|/* -------- TCP Accept -------- */
comment|/** the number of TCP handlers for this tcp-accept socket */
name|int
name|max_tcp_count
decl_stmt|;
comment|/** malloced array of tcp handlers for a tcp-accept,  	    of size max_tcp_count. */
name|struct
name|comm_point
modifier|*
modifier|*
name|tcp_handlers
decl_stmt|;
comment|/** linked list of free tcp_handlers to use for new queries. 	    For tcp_accept the first entry, for tcp_handlers the next one. */
name|struct
name|comm_point
modifier|*
name|tcp_free
decl_stmt|;
comment|/* -------- SSL TCP DNS ------- */
comment|/** the SSL object with rw bio (owned) or for commaccept ctx ref */
name|void
modifier|*
name|ssl
decl_stmt|;
comment|/** handshake state for init and renegotiate */
enum|enum
block|{
comment|/** no handshake, it has been done */
name|comm_ssl_shake_none
init|=
literal|0
block|,
comment|/** ssl initial handshake wants to read */
name|comm_ssl_shake_read
block|,
comment|/** ssl initial handshake wants to write */
name|comm_ssl_shake_write
block|,
comment|/** ssl_write wants to read */
name|comm_ssl_shake_hs_read
block|,
comment|/** ssl_read wants to write */
name|comm_ssl_shake_hs_write
block|}
name|ssl_shake_state
enum|;
comment|/** is this a UDP, TCP-accept or TCP socket. */
enum|enum
name|comm_point_type
block|{
comment|/** UDP socket - handle datagrams. */
name|comm_udp
block|,
comment|/** TCP accept socket - only creates handlers if readable. */
name|comm_tcp_accept
block|,
comment|/** TCP handler socket - handle byteperbyte readwrite. */
name|comm_tcp
block|,
comment|/** AF_UNIX socket - for internal commands. */
name|comm_local
block|,
comment|/** raw - not DNS format - for pipe readers and writers */
name|comm_raw
block|}
comment|/** variable with type of socket, UDP,TCP-accept,TCP,pipe */
name|type
enum|;
comment|/* ---------- Behaviour ----------- */
comment|/** if set the connection is NOT closed on delete. */
name|int
name|do_not_close
decl_stmt|;
comment|/** if set, the connection is closed on error, on timeout,  	    and after read/write completes. No callback is done. */
name|int
name|tcp_do_close
decl_stmt|;
comment|/** if set, read/write completes: 		read/write state of tcp is toggled. 		buffer reset/bytecount reset. 		this flag cleared. 	    So that when that is done the callback is called. */
name|int
name|tcp_do_toggle_rw
decl_stmt|;
comment|/** if set, checks for pending error from nonblocking connect() call.*/
name|int
name|tcp_check_nb_connect
decl_stmt|;
comment|/** number of queries outstanding on this socket, used by 	 * outside network for udp ports */
name|int
name|inuse
decl_stmt|;
comment|/** callback when done. 	    tcp_accept does not get called back, is NULL then. 	    If a timeout happens, callback with timeout=1 is called. 	    If an error happens, callback is called with error set  	    nonzero. If not NETEVENT_NOERROR, it is an errno value. 	    If the connection is closed (by remote end) then the 	    callback is called with error set to NETEVENT_CLOSED=-1. 	    If a timeout happens on the connection, the error is set to  	    NETEVENT_TIMEOUT=-2. 	    The reply_info can be copied if the reply needs to happen at a 	    later time. It consists of a struct with commpoint and address. 	    It can be passed to a msg send routine some time later. 	    Note the reply information is temporary and must be copied. 	    NULL is passed for_reply info, in cases where error happened.  	    declare as:  	    int my_callback(struct comm_point* c, void* my_arg, int error, 		struct comm_reply *reply_info);  	    if the routine returns 0, nothing is done. 	    Notzero, the buffer will be sent back to client. 	    		For UDP this is done without changing the commpoint. 			In TCP it sets write state. 	*/
name|comm_point_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/** argument to pass to callback. */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Structure only for making timeout events.  */
end_comment

begin_struct
struct|struct
name|comm_timer
block|{
comment|/** the internal event stuff */
name|struct
name|internal_timer
modifier|*
name|ev_timer
decl_stmt|;
comment|/** callback function, takes user arg only */
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Structure only for signal events.  */
end_comment

begin_struct
struct|struct
name|comm_signal
block|{
comment|/** the communication base */
name|struct
name|comm_base
modifier|*
name|base
decl_stmt|;
comment|/** the internal event stuff */
name|struct
name|internal_signal
modifier|*
name|ev_signal
decl_stmt|;
comment|/** callback function, takes signal number and user arg */
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create a new comm base.  * @param sigs: if true it attempts to create a default loop for   *   signal handling.  * @return: the new comm base. NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_base
modifier|*
name|comm_base_create
parameter_list|(
name|int
name|sigs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create comm base that uses the given event_base (underlying event  * mechanism pointer).  * @param base: underlying lib event base.  * @return: the new comm base. NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_base
modifier|*
name|comm_base_create_event
parameter_list|(
name|struct
name|event_base
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete comm base structure but not the underlying lib event base.  * All comm points must have been deleted.  * @param b: the base to delete.  */
end_comment

begin_function_decl
name|void
name|comm_base_delete_no_base
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Destroy a comm base.  * All comm points must have been deleted.  * @param b: the base to delete.  */
end_comment

begin_function_decl
name|void
name|comm_base_delete
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain two pointers. The pointers never change (until base_delete()).  * The pointers point to time values that are updated regularly.  * @param b: the communication base that will update the time values.  * @param tt: pointer to time in seconds is returned.  * @param tv: pointer to time in microseconds is returned.  */
end_comment

begin_function_decl
name|void
name|comm_base_timept
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|,
name|time_t
modifier|*
modifier|*
name|tt
parameter_list|,
name|struct
name|timeval
modifier|*
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Dispatch the comm base events.  * @param b: the communication to perform.  */
end_comment

begin_function_decl
name|void
name|comm_base_dispatch
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Exit from dispatch loop.  * @param b: the communication base that is in dispatch().  */
end_comment

begin_function_decl
name|void
name|comm_base_exit
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the slow_accept mode handlers.  You can not provide these if you do  * not perform accept() calls.  * @param b: comm base  * @param stop_accept: function that stops listening to accept fds.  * @param start_accept: function that resumes listening to accept fds.  * @param arg: callback arg to pass to the functions.  */
end_comment

begin_function_decl
name|void
name|comm_base_set_slow_accept_handlers
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|,
name|void
function_decl|(
modifier|*
name|stop_accept
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|start_accept
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Access internal data structure (for util/tube.c on windows)  * @param b: comm base  * @return event_base. Could be libevent, or internal event handler.  */
end_comment

begin_function_decl
name|struct
name|event_base
modifier|*
name|comm_base_internal
parameter_list|(
name|struct
name|comm_base
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create an UDP comm point. Calls malloc.  * setups the structure with the parameters you provide.  * @param base: in which base to alloc the commpoint.  * @param fd : file descriptor of open UDP socket.  * @param buffer: shared buffer by UDP sockets from this thread.  * @param callback: callback function pointer.  * @param callback_arg: will be passed to your callback function.  * @return: returns the allocated communication point. NULL on error.  * Sets timeout to NULL. Turns off TCP options.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_udp
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buffer
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create an UDP with ancillary data comm point. Calls malloc.  * Uses recvmsg instead of recv to get udp message.  * setups the structure with the parameters you provide.  * @param base: in which base to alloc the commpoint.  * @param fd : file descriptor of open UDP socket.  * @param buffer: shared buffer by UDP sockets from this thread.  * @param callback: callback function pointer.  * @param callback_arg: will be passed to your callback function.  * @return: returns the allocated communication point. NULL on error.  * Sets timeout to NULL. Turns off TCP options.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_udp_ancil
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buffer
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a TCP listener comm point. Calls malloc.  * Setups the structure with the parameters you provide.  * Also Creates TCP Handlers, pre allocated for you.  * Uses the parameters you provide.  * @param base: in which base to alloc the commpoint.  * @param fd: file descriptor of open TCP socket set to listen nonblocking.  * @param num: becomes max_tcp_count, the routine allocates that  *	many tcp handler commpoints.  * @param bufsize: size of buffer to create for handlers.  * @param callback: callback function pointer for TCP handlers.  * @param callback_arg: will be passed to your callback function.  * @return: returns the TCP listener commpoint. You can find the  *  	TCP handlers in the array inside the listener commpoint.  *	returns NULL on error.  * Inits timeout to NULL. All handlers are on the free list.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_tcp
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|num
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create an outgoing TCP commpoint. No file descriptor is opened, left at -1.  * @param base: in which base to alloc the commpoint.  * @param bufsize: size of buffer to create for handlers.  * @param callback: callback function pointer for the handler.  * @param callback_arg: will be passed to your callback function.  * @return: the commpoint or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_tcp_out
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create commpoint to listen to a local domain file descriptor.  * @param base: in which base to alloc the commpoint.  * @param fd: file descriptor of open AF_UNIX socket set to listen nonblocking.  * @param bufsize: size of buffer to create for handlers.  * @param callback: callback function pointer for the handler.  * @param callback_arg: will be passed to your callback function.  * @return: the commpoint or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_local
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|int
name|fd
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create commpoint to listen to a local domain pipe descriptor.  * @param base: in which base to alloc the commpoint.  * @param fd: file descriptor.  * @param writing: true if you want to listen to writes, false for reads.  * @param callback: callback function pointer for the handler.  * @param callback_arg: will be passed to your callback function.  * @return: the commpoint or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_point
modifier|*
name|comm_point_create_raw
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|writing
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close a comm point fd.  * @param c: comm point to close.  */
end_comment

begin_function_decl
name|void
name|comm_point_close
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close and deallocate (free) the comm point. If the comm point is  * a tcp-accept point, also its tcp-handler points are deleted.  * @param c: comm point to delete.  */
end_comment

begin_function_decl
name|void
name|comm_point_delete
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send reply. Put message into commpoint buffer.  * @param repinfo: The reply info copied from a commpoint callback call.  */
end_comment

begin_function_decl
name|void
name|comm_point_send_reply
parameter_list|(
name|struct
name|comm_reply
modifier|*
name|repinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Drop reply. Cleans up.  * @param repinfo: The reply info copied from a commpoint callback call.  */
end_comment

begin_function_decl
name|void
name|comm_point_drop_reply
parameter_list|(
name|struct
name|comm_reply
modifier|*
name|repinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send an udp message over a commpoint.  * @param c: commpoint to send it from.  * @param packet: what to send.  * @param addr: where to send it to.  * @param addrlen: length of addr.  * @return: false on a failure.  */
end_comment

begin_function_decl
name|int
name|comm_point_send_udp_msg
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|packet
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Stop listening for input on the commpoint. No callbacks will happen.  * @param c: commpoint to disable. The fd is not closed.  */
end_comment

begin_function_decl
name|void
name|comm_point_stop_listening
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Start listening again for input on the comm point.  * @param c: commpoint to enable again.  * @param newfd: new fd, or -1 to leave fd be.  * @param sec: timeout in seconds, or -1 for no (change to the) timeout.  */
end_comment

begin_function_decl
name|void
name|comm_point_start_listening
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|int
name|newfd
parameter_list|,
name|int
name|sec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Stop listening and start listening again for reading or writing.  * @param c: commpoint  * @param rd: if true, listens for reading.  * @param wr: if true, listens for writing.  */
end_comment

begin_function_decl
name|void
name|comm_point_listen_for_rw
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|int
name|rd
parameter_list|,
name|int
name|wr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get size of memory used by comm point.  * For TCP handlers this includes subhandlers.  * For UDP handlers, this does not include the (shared) UDP buffer.  * @param c: commpoint.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|comm_point_get_mem
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * create timer. Not active upon creation.  * @param base: event handling base.  * @param cb: callback function: void myfunc(void* myarg);  * @param cb_arg: user callback argument.  * @return: the new timer or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_timer
modifier|*
name|comm_timer_create
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * disable timer. Stops callbacks from happening.  * @param timer: to disable.  */
end_comment

begin_function_decl
name|void
name|comm_timer_disable
parameter_list|(
name|struct
name|comm_timer
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * reset timevalue for timer.  * @param timer: timer to (re)set.  * @param tv: when the timer should activate. if NULL timer is disabled.  */
end_comment

begin_function_decl
name|void
name|comm_timer_set
parameter_list|(
name|struct
name|comm_timer
modifier|*
name|timer
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * delete timer.  * @param timer: to delete.  */
end_comment

begin_function_decl
name|void
name|comm_timer_delete
parameter_list|(
name|struct
name|comm_timer
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * see if timeout has been set to a value.  * @param timer: the timer to examine.  * @return: false if disabled or not set.  */
end_comment

begin_function_decl
name|int
name|comm_timer_is_set
parameter_list|(
name|struct
name|comm_timer
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get size of memory used by comm timer.  * @param timer: the timer to examine.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|comm_timer_get_mem
parameter_list|(
name|struct
name|comm_timer
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a signal handler. Call signal_bind() later to bind to a signal.  * @param base: communication base to use.  * @param callback: called when signal is caught.  * @param cb_arg: user argument to callback  * @return: the signal struct or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|comm_signal
modifier|*
name|comm_signal_create
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Bind signal struct to catch a signal. A signle comm_signal can be bound  * to multiple signals, calling comm_signal_bind multiple times.  * @param comsig: the communication point, with callback information.  * @param sig: signal number.  * @return: true on success. false on error.  */
end_comment

begin_function_decl
name|int
name|comm_signal_bind
parameter_list|(
name|struct
name|comm_signal
modifier|*
name|comsig
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete the signal communication point.  * @param comsig: to delete.  */
end_comment

begin_function_decl
name|void
name|comm_signal_delete
parameter_list|(
name|struct
name|comm_signal
modifier|*
name|comsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * perform accept(2) with error checking.  * @param c: commpoint with accept fd.  * @param addr: remote end returned here.  * @param addrlen: length of remote end returned here.  * @return new fd, or -1 on error.  *	if -1, error message has been printed if necessary, simply drop  *	out of the reading handler.  */
end_comment

begin_function_decl
name|int
name|comm_point_perform_accept
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**** internal routines ****/
end_comment

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for udp comm point.  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_udp_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for udp ancillary data comm point.  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_udp_ancil_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for tcp accept comm point  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_tcp_accept_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for tcp data comm point  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_tcp_handle_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for timer comm.  * @param fd: file descriptor (always -1).  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_timer structure.  */
end_comment

begin_function_decl
name|void
name|comm_timer_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * handle libevent callback for signal comm.  * @param fd: file descriptor (used for the signal number).  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the internal commsignal structure.  */
end_comment

begin_function_decl
name|void
name|comm_signal_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * libevent callback for AF_UNIX fds  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_local_handle_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * libevent callback for raw fd access.  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_point_raw_handle_callback
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This routine is published for checks and tests, and is only used internally.  * libevent callback for timeout on slow accept.  * @param fd: file descriptor.  * @param event: event bits from libevent:   *	EV_READ, EV_WRITE, EV_SIGNAL, EV_TIMEOUT.  * @param arg: the comm_point structure.  */
end_comment

begin_function_decl
name|void
name|comm_base_handle_slow_accept
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_WINSOCK
end_ifdef

begin_comment
comment|/**  * Callback for openssl BIO to on windows detect WSAEWOULDBLOCK and notify  * the winsock_event of this for proper TCP nonblocking implementation.  * @param c: comm_point, fd must be set its struct event is registered.  * @param ssl: openssl SSL, fd must be set so it has a bio.  */
end_comment

begin_function_decl
name|void
name|comm_point_tcp_win_bio_cb
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** see if errno for tcp connect has to be logged or not. This uses errno */
end_comment

begin_function_decl
name|int
name|tcp_connect_errno_needs_log
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NET_EVENT_H */
end_comment

end_unit

