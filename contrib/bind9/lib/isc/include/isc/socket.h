begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: socket.h,v 1.54.12.4 2004/03/08 09:04:53 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SOCKET_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SOCKET_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Sockets  *  * Provides TCP and UDP sockets for network I/O.  The sockets are event  * sources in the task system.  *  * When I/O completes, a completion event for the socket is posted to the  * event queue of the task which requested the I/O.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  *	Clients of this module must not be holding a socket's task's lock when  *	making a call that affects that socket.  Failure to follow this rule  *	can result in deadlock.  *  *	The caller must ensure that isc_socketmgr_destroy() is called only  *	once for a given manager.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_include
include|#
directive|include
file|<isc/time.h>
end_include

begin_include
include|#
directive|include
file|<isc/region.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Constants  ***/
end_comment

begin_comment
comment|/*  * Maximum number of buffers in a scatter/gather read/write.  The operating  * system in use must support at least this number (plus one on some.)  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKET_MAXSCATTERGATHER
value|8
end_define

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_struct
struct|struct
name|isc_socketevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
name|isc_socketevent_t
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
comment|/* OK, EOF, whatever else */
name|unsigned
name|int
name|minimum
decl_stmt|;
comment|/* minimum i/o for event */
name|unsigned
name|int
name|n
decl_stmt|;
comment|/* bytes read or written */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/* offset into buffer list */
name|isc_region_t
name|region
decl_stmt|;
comment|/* for single-buffer i/o */
name|isc_bufferlist_t
name|bufferlist
decl_stmt|;
comment|/* list of buffers */
name|isc_sockaddr_t
name|address
decl_stmt|;
comment|/* source address */
name|isc_time_t
name|timestamp
decl_stmt|;
comment|/* timestamp of packet recv */
name|struct
name|in6_pktinfo
name|pktinfo
decl_stmt|;
comment|/* ipv6 pktinfo */
name|isc_uint32_t
name|attributes
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|isc_socket_newconnev
name|isc_socket_newconnev_t
typedef|;
end_typedef

begin_struct
struct|struct
name|isc_socket_newconnev
block|{
name|ISC_EVENT_COMMON
argument_list|(
name|isc_socket_newconnev_t
argument_list|)
expr_stmt|;
name|isc_socket_t
modifier|*
name|newsocket
decl_stmt|;
name|isc_result_t
name|result
decl_stmt|;
comment|/* OK, EOF, whatever else */
name|isc_sockaddr_t
name|address
decl_stmt|;
comment|/* source address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|isc_socket_connev
name|isc_socket_connev_t
typedef|;
end_typedef

begin_struct
struct|struct
name|isc_socket_connev
block|{
name|ISC_EVENT_COMMON
argument_list|(
name|isc_socket_connev_t
argument_list|)
expr_stmt|;
name|isc_result_t
name|result
decl_stmt|;
comment|/* OK, EOF, whatever else */
block|}
struct|;
end_struct

begin_comment
comment|/*  * _ATTACHED:	Internal use only.  * _TRUNC:	Packet was truncated on receive.  * _CTRUNC:	Packet control information was truncated.  This can  *		indicate that the packet is not complete, even though  *		all the data is valid.  * _TIMESTAMP:	The timestamp member is valid.  * _PKTINFO:	The pktinfo member is valid.  * _MULTICAST:	The UDP packet was received via a multicast transmission.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_ATTACHED
value|0x80000000U
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_TRUNC
value|0x00800000U
end_define

begin_comment
comment|/* public */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_CTRUNC
value|0x00400000U
end_define

begin_comment
comment|/* public */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_TIMESTAMP
value|0x00200000U
end_define

begin_comment
comment|/* public */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_PKTINFO
value|0x00100000U
end_define

begin_comment
comment|/* public */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENTATTR_MULTICAST
value|0x00080000U
end_define

begin_comment
comment|/* public */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_ANYEVENT
value|(0)
end_define

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_RECVDONE
value|(ISC_EVENTCLASS_SOCKET + 1)
end_define

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_SENDDONE
value|(ISC_EVENTCLASS_SOCKET + 2)
end_define

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_NEWCONN
value|(ISC_EVENTCLASS_SOCKET + 3)
end_define

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_CONNECT
value|(ISC_EVENTCLASS_SOCKET + 4)
end_define

begin_comment
comment|/*  * Internal events.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_INTR
value|(ISC_EVENTCLASS_SOCKET + 256)
end_define

begin_define
define|#
directive|define
name|ISC_SOCKEVENT_INTW
value|(ISC_EVENTCLASS_SOCKET + 257)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_sockettype_udp
init|=
literal|1
block|,
name|isc_sockettype_tcp
init|=
literal|2
block|}
name|isc_sockettype_t
typedef|;
end_typedef

begin_comment
comment|/*  * How a socket should be shutdown in isc_socket_shutdown() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_RECV
value|0x00000001
end_define

begin_comment
comment|/* close read side */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_SEND
value|0x00000002
end_define

begin_comment
comment|/* close write side */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_ALL
value|0x00000003
end_define

begin_comment
comment|/* close them all */
end_comment

begin_comment
comment|/*  * What I/O events to cancel in isc_socket_cancel() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_RECV
value|0x00000001
end_define

begin_comment
comment|/* cancel recv */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_SEND
value|0x00000002
end_define

begin_comment
comment|/* cancel send */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_ACCEPT
value|0x00000004
end_define

begin_comment
comment|/* cancel accept */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_CONNECT
value|0x00000008
end_define

begin_comment
comment|/* cancel connect */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_ALL
value|0x0000000f
end_define

begin_comment
comment|/* cancel everything */
end_comment

begin_comment
comment|/*  * Flags for isc_socket_send() and isc_socket_recv() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFLAG_IMMEDIATE
value|0x00000001
end_define

begin_comment
comment|/* send event only if needed */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFLAG_NORETRY
value|0x00000002
end_define

begin_comment
comment|/* drop failed UDP sends */
end_comment

begin_comment
comment|/***  *** Socket and Socket Manager Functions  ***  *** Note: all Ensures conditions apply only if the result is success for  *** those functions which return an isc_result.  ***/
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_create
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|manager
parameter_list|,
name|int
name|pf
parameter_list|,
name|isc_sockettype_t
name|type
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new 'type' socket managed by 'manager'.  *  * Note:  *  *	'pf' is the desired protocol family, e.g. PF_INET or PF_INET6.  *  * Requires:  *  *	'manager' is a valid manager  *  *	'socketp' is a valid pointer, and *socketp == NULL  *  * Ensures:  *  *	'*socketp' is attached to the newly created socket  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_NORESOURCES  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|isc_socket_cancel
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|unsigned
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel pending I/O of the type specified by "how".  *  * Note: if "task" is NULL, then the cancel applies to all tasks using the  * socket.  *  * Requires:  *  *	"socket" is a valid socket  *  *	"task" is NULL or a valid task  *  * "how" is a bitmask describing the type of cancelation to perform.  * The type ISC_SOCKCANCEL_ALL will cancel all pending I/O on this  * socket.  *  * ISC_SOCKCANCEL_RECV:  *	Cancel pending isc_socket_recv() calls.  *  * ISC_SOCKCANCEL_SEND:  *	Cancel pending isc_socket_send() and isc_socket_sendto() calls.  *  * ISC_SOCKCANCEL_ACCEPT:  *	Cancel pending isc_socket_accept() calls.  *  * ISC_SOCKCANCEL_CONNECT:  *	Cancel pending isc_socket_connect() call.  */
end_comment

begin_function_decl
name|void
name|isc_socket_shutdown
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|unsigned
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shutdown 'socket' according to 'how'.  *  * Requires:  *  *	'socket' is a valid socket.  *  *	'task' is NULL or is a valid task.  *  *	If 'how' is 'ISC_SOCKSHUT_RECV' or 'ISC_SOCKSHUT_ALL' then  *  *		The read queue must be empty.  *  *		No further read requests may be made.  *  *	If 'how' is 'ISC_SOCKSHUT_SEND' or 'ISC_SOCKSHUT_ALL' then  *  *		The write queue must be empty.  *  *		No further write requests may be made.  */
end_comment

begin_function_decl
name|void
name|isc_socket_attach
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *socketp to socket.  *  * Requires:  *  *	'socket' is a valid socket.  *  *	'socketp' points to a NULL socket.  *  * Ensures:  *  *	*socketp is attached to socket.  */
end_comment

begin_function_decl
name|void
name|isc_socket_detach
parameter_list|(
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *socketp from its socket.  *  * Requires:  *  *	'socketp' points to a valid socket.  *  *	If '*socketp' is the last reference to the socket,  *	then:  *  *		There must be no pending I/O requests.  *  * Ensures:  *  *	*socketp is NULL.  *  *	If '*socketp' is the last reference to the socket,  *	then:  *  *		The socket will be shutdown (both reading and writing)  *		for all tasks.  *  *		All resources used by the socket have been freed  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_bind
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addressp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind 'socket' to '*addressp'.  *  * Requires:  *  *	'socket' is a valid socket  *  *	'addressp' points to a valid isc_sockaddr.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOPERM  *	ISC_R_ADDRNOTAVAIL  *	ISC_R_ADDRINUSE  *	ISC_R_BOUND  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_filter
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
specifier|const
name|char
modifier|*
name|filter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inform the kernel that it should perform accept filtering.  * If filter is NULL the current filter will be removed.:w  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_listen
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|unsigned
name|int
name|backlog
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set listen mode on the socket.  After this call, the only function that  * can be used (other than attach and detach) is isc_socket_accept().  *  * Notes:  *  *	'backlog' is as in the UNIX system call listen() and may be  *	ignored by non-UNIX implementations.  *  *	If 'backlog' is zero, a reasonable system default is used, usually  *	SOMAXCONN.  *  * Requires:  *  *	'socket' is a valid, bound TCP socket.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_accept
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Queue accept event.  When a new connection is received, the task will  * get an ISC_SOCKEVENT_NEWCONN event with the sender set to the listen  * socket.  The new socket structure is sent inside the isc_socket_newconnev_t  * event type, and is attached to the task 'task'.  *  * REQUIRES:  *	'socket' is a valid TCP socket that isc_socket_listen() was called  *	on.  *  *	'task' is a valid task  *  *	'action' is a valid action  *  * RETURNS:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_connect
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addressp
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Connect 'socket' to peer with address *saddr.  When the connection  * succeeds, or when an error occurs, a CONNECT event with action 'action'  * and arg 'arg' will be posted to the event queue for 'task'.  *  * Requires:  *  *	'socket' is a valid TCP socket  *  *	'addressp' points to a valid isc_sockaddr  *  *	'task' is a valid task  *  *	'action' is a valid action  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  *  * Posted event's result code:  *  *	ISC_R_SUCCESS  *	ISC_R_TIMEDOUT  *	ISC_R_CONNREFUSED  *	ISC_R_NETUNREACH  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_getpeername
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addressp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the name of the peer connected to 'socket'.  *  * Requires:  *  *	'socket' is a valid TCP socket.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_TOOSMALL  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_getsockname
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addressp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the name of 'socket'.  *  * Requires:  *  *	'socket' is a valid socket.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_TOOSMALL  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_recv
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|unsigned
name|int
name|minimum
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_recvv
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_bufferlist_t
modifier|*
name|buflist
parameter_list|,
name|unsigned
name|int
name|minimum
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_recv2
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|unsigned
name|int
name|minimum
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_socketevent_t
modifier|*
name|event
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Receive from 'socket', storing the results in region.  *  * Notes:  *  *	Let 'length' refer to the length of 'region' or to the sum of all  *	available regions in the list of buffers '*buflist'.  *  *	If 'minimum' is non-zero and at least that many bytes are read,  *	the completion event will be posted to the task 'task.'  If minimum  *	is zero, the exact number of bytes requested in the region must  * 	be read for an event to be posted.  This only makes sense for TCP  *	connections, and is always set to 1 byte for UDP.  *  *	The read will complete when the desired number of bytes have been  *	read, if end-of-input occurs, or if an error occurs.  A read done  *	event with the given 'action' and 'arg' will be posted to the  *	event queue of 'task'.  *  *	The caller may not modify 'region', the buffers which are passed  *	into this function, or any data they refer to until the completion  *	event is received.  *  *	For isc_socket_recvv():  *	On successful completion, '*buflist' will be empty, and the list of  *	all buffers will be returned in the done event's 'bufferlist'  *	member.  On error return, '*buflist' will be unchanged.  *  *	For isc_socket_recv2():  *	'event' is not NULL, and the non-socket specific fields are  *	expected to be initialized.  *  *	For isc_socket_recv2():  *	The only defined value for 'flags' is ISC_SOCKFLAG_IMMEDIATE.  If  *	set and the operation completes, the return value will be  *	ISC_R_SUCCESS and the event will be filled in and not sent.  If the  *	operation does not complete, the return value will be  *	ISC_R_INPROGRESS and the event will be sent when the operation  *	completes.  *  * Requires:  *  *	'socket' is a valid, bound socket.  *  *	For isc_socket_recv():  *	'region' is a valid region  *  *	For isc_socket_recvv():  *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.  *  *	'task' is a valid task  *  *	For isc_socket_recv() and isc_socket_recvv():  *	action != NULL and is a valid action  *  *	For isc_socket_recv2():  *	event != NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_INPROGRESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  *  * Event results:  *  *	ISC_R_SUCCESS  *	ISC_R_UNEXPECTED  *	XXX needs other net-type errors  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_send
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_sendto
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|address
parameter_list|,
name|struct
name|in6_pktinfo
modifier|*
name|pktinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_sendv
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_bufferlist_t
modifier|*
name|buflist
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_sendtov
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_bufferlist_t
modifier|*
name|buflist
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|address
parameter_list|,
name|struct
name|in6_pktinfo
modifier|*
name|pktinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_socket_sendto2
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_region_t
modifier|*
name|region
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|address
parameter_list|,
name|struct
name|in6_pktinfo
modifier|*
name|pktinfo
parameter_list|,
name|isc_socketevent_t
modifier|*
name|event
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Send the contents of 'region' to the socket's peer.  *  * Notes:  *  *	Shutting down the requestor's task *may* result in any  *	still pending writes being dropped or completed, depending on the  *	underlying OS implementation.  *  *	If 'action' is NULL, then no completion event will be posted.  *  *	The caller may not modify 'region', the buffers which are passed  *	into this function, or any data they refer to until the completion  *	event is received.  *  *	For isc_socket_sendv() and isc_socket_sendtov():  *	On successful completion, '*buflist' will be empty, and the list of  *	all buffers will be returned in the done event's 'bufferlist'  *	member.  On error return, '*buflist' will be unchanged.  *  *	For isc_socket_sendto2():  *	'event' is not NULL, and the non-socket specific fields are  *	expected to be initialized.  *  *	For isc_socket_sendto2():  *	The only defined values for 'flags' are ISC_SOCKFLAG_IMMEDIATE  *	and ISC_SOCKFLAG_NORETRY.  *  *	If ISC_SOCKFLAG_IMMEDIATE is set and the operation completes, the  *	return value will be ISC_R_SUCCESS and the event will be filled  *	in and not sent.  If the operation does not complete, the return  *	value will be ISC_R_INPROGRESS and the event will be sent when  *	the operation completes.  *  *	ISC_SOCKFLAG_NORETRY can only be set for UDP sockets.  If set  *	and the send operation fails due to a transient error, the send  *	will not be retried and the error will be indicated in the event.  *	Using this option along with ISC_SOCKFLAG_IMMEDIATE allows the caller  *	to specify a region that is allocated on the stack.  *  * Requires:  *  *	'socket' is a valid, bound socket.  *  *	For isc_socket_send():  *	'region' is a valid region  *  *	For isc_socket_sendv() and isc_socket_sendtov():  *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.  *  *	'task' is a valid task  *  *	For isc_socket_sendv(), isc_socket_sendtov(), isc_socket_send(), and  *	isc_socket_sendto():  *	action == NULL or is a valid action  *  *	For isc_socket_sendto2():  *	event != NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_INPROGRESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  *  * Event results:  *  *	ISC_R_SUCCESS  *	ISC_R_UNEXPECTED  *	XXX needs other net-type errors  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socketmgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_socketmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a socket manager.  *  * Notes:  *  *	All memory will be allocated in memory context 'mctx'.  *  * Requires:  *  *	'mctx' is a valid memory context.  *  *	'managerp' points to a NULL isc_socketmgr_t.  *  * Ensures:  *  *	'*managerp' is a valid isc_socketmgr_t.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|isc_socketmgr_destroy
parameter_list|(
name|isc_socketmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a socket manager.  *  * Notes:  *  *	This routine blocks until there are no sockets left in the manager,  *	so if the caller holds any socket references using the manager, it  *	must detach them before calling isc_socketmgr_destroy() or it will  *	block forever.  *  * Requires:  *  *	'*managerp' is a valid isc_socketmgr_t.  *  *	All sockets managed by this manager are fully detached.  *  * Ensures:  *  *	*managerp == NULL  *  *	All resources used by the manager have been freed.  */
end_comment

begin_function_decl
name|isc_sockettype_t
name|isc_socket_gettype
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the socket type for "sock."  *  * Requires:  *  *	"sock" is a valid socket.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_socket_isbound
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_socket_ipv6only
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_boolean_t
name|yes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the socket is an IPv6 socket set/clear the IPV6_IPV6ONLY socket  * option if the host OS supports this option.  *  * Requires:  *	'sock' is a valid socket.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SOCKET_H */
end_comment

end_unit

