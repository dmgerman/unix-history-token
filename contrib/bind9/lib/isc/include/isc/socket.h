begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009, 2011-2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
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
comment|/*! \file isc/socket.h  * \brief Provides TCP and UDP sockets for network I/O.  The sockets are event  * sources in the task system.  *  * When I/O completes, a completion event for the socket is posted to the  * event queue of the task which requested the I/O.  *  * \li MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *	Clients of this module must not be holding a socket's task's lock when  *	making a call that affects that socket.  Failure to follow this rule  *	can result in deadlock.  *	The caller must ensure that isc_socketmgr_destroy() is called only  *	once for a given manager.  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	TBS  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  *	None.  */
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

begin_include
include|#
directive|include
file|<isc/xml.h>
end_include

begin_decl_stmt
name|ISC_LANG_BEGINDECLS
comment|/***  *** Constants  ***/
comment|/*%  * Maximum number of buffers in a scatter/gather read/write.  The operating  * system in use must support at least this number (plus one on some.)  */
define|#
directive|define
name|ISC_SOCKET_MAXSCATTERGATHER
value|8
comment|/*%  * In isc_socket_bind() set socket option SO_REUSEADDR prior to calling  * bind() if a non zero port is specified (AF_INET and AF_INET6).  */
define|#
directive|define
name|ISC_SOCKET_REUSEADDRESS
value|0x01U
comment|/*%  * Statistics counters.  Used as isc_statscounter_t values.  */
name|enum
type|{
name|isc_sockstatscounter_udp4open
init|=
literal|0
decl_stmt|,
name|isc_sockstatscounter_udp6open
init|=
literal|1
decl_stmt|,
name|isc_sockstatscounter_tcp4open
init|=
literal|2
decl_stmt|,
name|isc_sockstatscounter_tcp6open
init|=
literal|3
decl_stmt|,
name|isc_sockstatscounter_unixopen
init|=
literal|4
decl_stmt|,
name|isc_sockstatscounter_udp4openfail
init|=
literal|5
decl_stmt|,
name|isc_sockstatscounter_udp6openfail
init|=
literal|6
decl_stmt|,
name|isc_sockstatscounter_tcp4openfail
init|=
literal|7
decl_stmt|,
name|isc_sockstatscounter_tcp6openfail
init|=
literal|8
decl_stmt|,
name|isc_sockstatscounter_unixopenfail
init|=
literal|9
decl_stmt|,
name|isc_sockstatscounter_udp4close
init|=
literal|10
decl_stmt|,
name|isc_sockstatscounter_udp6close
init|=
literal|11
decl_stmt|,
name|isc_sockstatscounter_tcp4close
init|=
literal|12
decl_stmt|,
name|isc_sockstatscounter_tcp6close
init|=
literal|13
decl_stmt|,
name|isc_sockstatscounter_unixclose
init|=
literal|14
decl_stmt|,
name|isc_sockstatscounter_fdwatchclose
init|=
literal|15
decl_stmt|,
name|isc_sockstatscounter_udp4bindfail
init|=
literal|16
decl_stmt|,
name|isc_sockstatscounter_udp6bindfail
init|=
literal|17
decl_stmt|,
name|isc_sockstatscounter_tcp4bindfail
init|=
literal|18
decl_stmt|,
name|isc_sockstatscounter_tcp6bindfail
init|=
literal|19
decl_stmt|,
name|isc_sockstatscounter_unixbindfail
init|=
literal|20
decl_stmt|,
name|isc_sockstatscounter_fdwatchbindfail
init|=
literal|21
decl_stmt|,
name|isc_sockstatscounter_udp4connect
init|=
literal|22
decl_stmt|,
name|isc_sockstatscounter_udp6connect
init|=
literal|23
decl_stmt|,
name|isc_sockstatscounter_tcp4connect
init|=
literal|24
decl_stmt|,
name|isc_sockstatscounter_tcp6connect
init|=
literal|25
decl_stmt|,
name|isc_sockstatscounter_unixconnect
init|=
literal|26
decl_stmt|,
name|isc_sockstatscounter_fdwatchconnect
init|=
literal|27
decl_stmt|,
name|isc_sockstatscounter_udp4connectfail
init|=
literal|28
decl_stmt|,
name|isc_sockstatscounter_udp6connectfail
init|=
literal|29
decl_stmt|,
name|isc_sockstatscounter_tcp4connectfail
init|=
literal|30
decl_stmt|,
name|isc_sockstatscounter_tcp6connectfail
init|=
literal|31
decl_stmt|,
name|isc_sockstatscounter_unixconnectfail
init|=
literal|32
decl_stmt|,
name|isc_sockstatscounter_fdwatchconnectfail
init|=
literal|33
decl_stmt|,
name|isc_sockstatscounter_tcp4accept
init|=
literal|34
decl_stmt|,
name|isc_sockstatscounter_tcp6accept
init|=
literal|35
decl_stmt|,
name|isc_sockstatscounter_unixaccept
init|=
literal|36
decl_stmt|,
name|isc_sockstatscounter_tcp4acceptfail
init|=
literal|37
decl_stmt|,
name|isc_sockstatscounter_tcp6acceptfail
init|=
literal|38
decl_stmt|,
name|isc_sockstatscounter_unixacceptfail
init|=
literal|39
decl_stmt|,
name|isc_sockstatscounter_udp4sendfail
init|=
literal|40
decl_stmt|,
name|isc_sockstatscounter_udp6sendfail
init|=
literal|41
decl_stmt|,
name|isc_sockstatscounter_tcp4sendfail
init|=
literal|42
decl_stmt|,
name|isc_sockstatscounter_tcp6sendfail
init|=
literal|43
decl_stmt|,
name|isc_sockstatscounter_unixsendfail
init|=
literal|44
decl_stmt|,
name|isc_sockstatscounter_fdwatchsendfail
init|=
literal|45
decl_stmt|,
name|isc_sockstatscounter_udp4recvfail
init|=
literal|46
decl_stmt|,
name|isc_sockstatscounter_udp6recvfail
init|=
literal|47
decl_stmt|,
name|isc_sockstatscounter_tcp4recvfail
init|=
literal|48
decl_stmt|,
name|isc_sockstatscounter_tcp6recvfail
init|=
literal|49
decl_stmt|,
name|isc_sockstatscounter_unixrecvfail
init|=
literal|50
decl_stmt|,
name|isc_sockstatscounter_fdwatchrecvfail
init|=
literal|51
decl_stmt|,
name|isc_sockstatscounter_max
init|=
literal|52
end_decl_stmt

begin_comment
unit|};
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
comment|/*%< OK, EOF, whatever else */
name|unsigned
name|int
name|minimum
decl_stmt|;
comment|/*%< minimum i/o for event */
name|unsigned
name|int
name|n
decl_stmt|;
comment|/*%< bytes read or written */
name|unsigned
name|int
name|offset
decl_stmt|;
comment|/*%< offset into buffer list */
name|isc_region_t
name|region
decl_stmt|;
comment|/*%< for single-buffer i/o */
name|isc_bufferlist_t
name|bufferlist
decl_stmt|;
comment|/*%< list of buffers */
name|isc_sockaddr_t
name|address
decl_stmt|;
comment|/*%< source address */
name|isc_time_t
name|timestamp
decl_stmt|;
comment|/*%< timestamp of packet recv */
name|struct
name|in6_pktinfo
name|pktinfo
decl_stmt|;
comment|/*%< ipv6 pktinfo */
name|isc_uint32_t
name|attributes
decl_stmt|;
comment|/*%< see below */
name|isc_eventdestructor_t
name|destroy
decl_stmt|;
comment|/*%< original destructor */
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
comment|/*%< OK, EOF, whatever else */
name|isc_sockaddr_t
name|address
decl_stmt|;
comment|/*%< source address */
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
comment|/*%< OK, EOF, whatever else */
block|}
struct|;
end_struct

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * _ATTACHED:	Internal use only.  * _TRUNC:	Packet was truncated on receive.  * _CTRUNC:	Packet control information was truncated.  This can  *		indicate that the packet is not complete, even though  *		all the data is valid.  * _TIMESTAMP:	The timestamp member is valid.  * _PKTINFO:	The pktinfo member is valid.  * _MULTICAST:	The UDP packet was received via a multicast transmission.  */
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

begin_comment
comment|/*@}*/
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
block|,
name|isc_sockettype_unix
init|=
literal|3
block|,
name|isc_sockettype_fdwatch
init|=
literal|4
block|}
name|isc_sockettype_t
typedef|;
end_typedef

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * How a socket should be shutdown in isc_socket_shutdown() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_RECV
value|0x00000001
end_define

begin_comment
comment|/*%< close read side */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_SEND
value|0x00000002
end_define

begin_comment
comment|/*%< close write side */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKSHUT_ALL
value|0x00000003
end_define

begin_comment
comment|/*%< close them all */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * What I/O events to cancel in isc_socket_cancel() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_RECV
value|0x00000001
end_define

begin_comment
comment|/*%< cancel recv */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_SEND
value|0x00000002
end_define

begin_comment
comment|/*%< cancel send */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_ACCEPT
value|0x00000004
end_define

begin_comment
comment|/*%< cancel accept */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_CONNECT
value|0x00000008
end_define

begin_comment
comment|/*%< cancel connect */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKCANCEL_ALL
value|0x0000000f
end_define

begin_comment
comment|/*%< cancel everything */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * Flags for isc_socket_send() and isc_socket_recv() calls.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFLAG_IMMEDIATE
value|0x00000001
end_define

begin_comment
comment|/*%< send event only if needed */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFLAG_NORETRY
value|0x00000002
end_define

begin_comment
comment|/*%< drop failed UDP sends */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * Flags for fdwatchcreate.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFDWATCH_READ
value|0x00000001
end_define

begin_comment
comment|/*%< watch for readable */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKFDWATCH_WRITE
value|0x00000002
end_define

begin_comment
comment|/*%< watch for writable */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*% Socket and socket manager methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_socketmgrmethods
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_socketmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|socketcreate
function_decl|)
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
name|isc_result_t
function_decl|(
modifier|*
name|fdwatchcreate
function_decl|)
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|manager
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|flags
parameter_list|,
name|isc_sockfdwatch_t
name|callback
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
block|}
name|isc_socketmgrmethods_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_socketmethods
block|{
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|bind
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|sendto
function_decl|)
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
name|isc_result_t
function_decl|(
modifier|*
name|sendto2
function_decl|)
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
name|isc_result_t
function_decl|(
modifier|*
name|connect
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addr
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|recv
function_decl|)
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
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|recv2
function_decl|)
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
name|void
function_decl|(
modifier|*
name|cancel
function_decl|)
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
name|isc_result_t
function_decl|(
modifier|*
name|getsockname
function_decl|)
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
name|isc_sockettype_t
function_decl|(
modifier|*
name|gettype
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ipv6only
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_boolean_t
name|yes
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|fdwatchpoke
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|dup
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|getfd
function_decl|)
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|)
function_decl|;
block|}
name|isc_socketmethods_t
typedef|;
end_typedef

begin_comment
comment|/*%  * This structure is actually just the common prefix of a socket manager  * object implementation's version of an isc_socketmgr_t.  * \brief  * Direct use of this structure by clients is forbidden.  socket implementations  * may change the structure.  'magic' must be ISCAPI_SOCKETMGR_MAGIC for any  * of the isc_socket_ routines to work.  socket implementations must maintain  * all socket invariants.  * In effect, this definition is used only for non-BIND9 version ("export")  * of the library, and the export version does not work for win32.  So, to avoid  * the definition conflict with win32/socket.c, we enable this definition only  * for non-Win32 (i.e. Unix) platforms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_struct
struct|struct
name|isc_socketmgr
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_socketmgrmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISCAPI_SOCKETMGR_MAGIC
value|ISC_MAGIC('A','s','m','g')
end_define

begin_define
define|#
directive|define
name|ISCAPI_SOCKETMGR_VALID
parameter_list|(
name|m
parameter_list|)
value|((m) != NULL&& \ 					 (m)->magic == ISCAPI_SOCKETMGR_MAGIC)
end_define

begin_comment
comment|/*%  * This is the common prefix of a socket object.  The same note as  * that for the socketmgr structure applies.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_struct
struct|struct
name|isc_socket
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_socketmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISCAPI_SOCKET_MAGIC
value|ISC_MAGIC('A','s','c','t')
end_define

begin_define
define|#
directive|define
name|ISCAPI_SOCKET_VALID
parameter_list|(
name|s
parameter_list|)
value|((s) != NULL&& \ 				 (s)->magic == ISCAPI_SOCKET_MAGIC)
end_define

begin_comment
comment|/***  *** Socket and Socket Manager Functions  ***  *** Note: all Ensures conditions apply only if the result is success for  *** those functions which return an isc_result.  ***/
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_fdwatchcreate
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|manager
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|flags
parameter_list|,
name|isc_sockfdwatch_t
name|callback
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a new file descriptor watch socket managed by 'manager'.  *  * Note:  *  *\li   'fd' is the already-opened file descriptor.  *\li	This function is not available on Windows.  *\li	The callback function is called "in-line" - this means the function  *	needs to return as fast as possible, as all other I/O will be suspended  *	until the callback completes.  *  * Requires:  *  *\li	'manager' is a valid manager  *  *\li	'socketp' is a valid pointer, and *socketp == NULL  *  *\li	'fd' be opened.  *  * Ensures:  *  *	'*socketp' is attached to the newly created fdwatch socket  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_NORESOURCES  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_fdwatchpoke
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Poke a file descriptor watch socket informing the manager that it  * should restart watching the socket  *  * Note:  *  *\li   'sock' is the socket returned by isc_socket_fdwatchcreate  *  *\li   'flags' indicates what the manager should watch for on the socket  *      in addition to what it may already be watching.  It can be one or  *      both of ISC_SOCKFDWATCH_READ and ISC_SOCKFDWATCH_WRITE.  To  *      temporarily disable watching on a socket the value indicating  *      no more data should be returned from the call back routine.  *  *\li	This function is not available on Windows.  *  * Requires:  *  *\li	'sock' is a valid isc socket  *  *  * Returns:  *  *\li	#ISC_R_SUCCESS  */
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
comment|/*%<  * Create a new 'type' socket managed by 'manager'.  *  * For isc_sockettype_fdwatch sockets you should use isc_socket_fdwatchcreate()  * rather than isc_socket_create().  *  * Note:  *  *\li	'pf' is the desired protocol family, e.g. PF_INET or PF_INET6.  *  * Requires:  *  *\li	'manager' is a valid manager  *  *\li	'socketp' is a valid pointer, and *socketp == NULL  *  *\li	'type' is not isc_sockettype_fdwatch  *  * Ensures:  *  *	'*socketp' is attached to the newly created socket  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_NORESOURCES  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_dup
parameter_list|(
name|isc_socket_t
modifier|*
name|sock0
parameter_list|,
name|isc_socket_t
modifier|*
modifier|*
name|socketp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Duplicate an existing socket, reusing its file descriptor.  */
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
comment|/*%<  * Cancel pending I/O of the type specified by "how".  *  * Note: if "task" is NULL, then the cancel applies to all tasks using the  * socket.  *  * Requires:  *  * \li	"socket" is a valid socket  *  * \li	"task" is NULL or a valid task  *  * "how" is a bitmask describing the type of cancelation to perform.  * The type ISC_SOCKCANCEL_ALL will cancel all pending I/O on this  * socket.  *  * \li ISC_SOCKCANCEL_RECV:  *	Cancel pending isc_socket_recv() calls.  *  * \li ISC_SOCKCANCEL_SEND:  *	Cancel pending isc_socket_send() and isc_socket_sendto() calls.  *  * \li ISC_SOCKCANCEL_ACCEPT:  *	Cancel pending isc_socket_accept() calls.  *  * \li ISC_SOCKCANCEL_CONNECT:  *	Cancel pending isc_socket_connect() call.  */
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
comment|/*%<  * Shutdown 'socket' according to 'how'.  *  * Requires:  *  * \li	'socket' is a valid socket.  *  * \li	'task' is NULL or is a valid task.  *  * \li	If 'how' is 'ISC_SOCKSHUT_RECV' or 'ISC_SOCKSHUT_ALL' then  *  *		The read queue must be empty.  *  *		No further read requests may be made.  *  * \li	If 'how' is 'ISC_SOCKSHUT_SEND' or 'ISC_SOCKSHUT_ALL' then  *  *		The write queue must be empty.  *  *		No further write requests may be made.  */
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
comment|/*%<  * Attach *socketp to socket.  *  * Requires:  *  * \li	'socket' is a valid socket.  *  * \li	'socketp' points to a NULL socket.  *  * Ensures:  *  * \li	*socketp is attached to socket.  */
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
comment|/*%<  * Detach *socketp from its socket.  *  * Requires:  *  * \li	'socketp' points to a valid socket.  *  * \li	If '*socketp' is the last reference to the socket,  *	then:  *  *		There must be no pending I/O requests.  *  * Ensures:  *  * \li	*socketp is NULL.  *  * \li	If '*socketp' is the last reference to the socket,  *	then:  *  *		The socket will be shutdown (both reading and writing)  *		for all tasks.  *  *		All resources used by the socket have been freed  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_open
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Open a new socket file descriptor of the given socket structure.  It simply  * opens a new descriptor; all of the other parameters including the socket  * type are inherited from the existing socket.  This function is provided to  * avoid overhead of destroying and creating sockets when many short-lived  * sockets are frequently opened and closed.  When the efficiency is not an  * issue, it should be safer to detach the unused socket and re-create a new  * one.  This optimization may not be available for some systems, in which  * case this function will return ISC_R_NOTIMPLEMENTED and must not be used.  *  * isc_socket_open() should not be called on sockets created by  * isc_socket_fdwatchcreate().  *  * Requires:  *  * \li	there must be no other reference to this socket.  *  * \li	'socket' is a valid and previously closed by isc_socket_close()  *  * \li  'sock->type' is not isc_sockettype_fdwatch  *  * Returns:  *	Same as isc_socket_create().  * \li	ISC_R_NOTIMPLEMENTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_close
parameter_list|(
name|isc_socket_t
modifier|*
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Close a socket file descriptor of the given socket structure.  This function  * is provided as an alternative to destroying an unused socket when overhead  * destroying/re-creating sockets can be significant, and is expected to be  * used with isc_socket_open().  This optimization may not be available for some  * systems, in which case this function will return ISC_R_NOTIMPLEMENTED and  * must not be used.  *  * isc_socket_close() should not be called on sockets created by  * isc_socket_fdwatchcreate().  *  * Requires:  *  * \li	The socket must have a valid descriptor.  *  * \li	There must be no other reference to this socket.  *  * \li	There must be no pending I/O requests.  *  * \li  'sock->type' is not isc_sockettype_fdwatch  *  * Returns:  * \li	#ISC_R_NOTIMPLEMENTED  */
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
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Bind 'socket' to '*addressp'.  *  * Requires:  *  * \li	'socket' is a valid socket  *  * \li	'addressp' points to a valid isc_sockaddr.  *  * Returns:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_NOPERM  * \li	ISC_R_ADDRNOTAVAIL  * \li	ISC_R_ADDRINUSE  * \li	ISC_R_BOUND  * \li	ISC_R_UNEXPECTED  */
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
comment|/*%<  * Inform the kernel that it should perform accept filtering.  * If filter is NULL the current filter will be removed.:w  */
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
comment|/*%<  * Set listen mode on the socket.  After this call, the only function that  * can be used (other than attach and detach) is isc_socket_accept().  *  * Notes:  *  * \li	'backlog' is as in the UNIX system call listen() and may be  *	ignored by non-UNIX implementations.  *  * \li	If 'backlog' is zero, a reasonable system default is used, usually  *	SOMAXCONN.  *  * Requires:  *  * \li	'socket' is a valid, bound TCP socket or a valid, bound UNIX socket.  *  * Returns:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_UNEXPECTED  */
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
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Queue accept event.  When a new connection is received, the task will  * get an ISC_SOCKEVENT_NEWCONN event with the sender set to the listen  * socket.  The new socket structure is sent inside the isc_socket_newconnev_t  * event type, and is attached to the task 'task'.  *  * REQUIRES:  * \li	'socket' is a valid TCP socket that isc_socket_listen() was called  *	on.  *  * \li	'task' is a valid task  *  * \li	'action' is a valid action  *  * RETURNS:  * \li	ISC_R_SUCCESS  * \li	ISC_R_NOMEMORY  * \li	ISC_R_UNEXPECTED  */
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
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Connect 'socket' to peer with address *saddr.  When the connection  * succeeds, or when an error occurs, a CONNECT event with action 'action'  * and arg 'arg' will be posted to the event queue for 'task'.  *  * Requires:  *  * \li	'socket' is a valid TCP socket  *  * \li	'addressp' points to a valid isc_sockaddr  *  * \li	'task' is a valid task  *  * \li	'action' is a valid action  *  * Returns:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_NOMEMORY  * \li	ISC_R_UNEXPECTED  *  * Posted event's result code:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_TIMEDOUT  * \li	ISC_R_CONNREFUSED  * \li	ISC_R_NETUNREACH  * \li	ISC_R_UNEXPECTED  */
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
comment|/*%<  * Get the name of the peer connected to 'socket'.  *  * Requires:  *  * \li	'socket' is a valid TCP socket.  *  * Returns:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_TOOSMALL  * \li	ISC_R_UNEXPECTED  */
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
comment|/*%<  * Get the name of 'socket'.  *  * Requires:  *  * \li	'socket' is a valid socket.  *  * Returns:  *  * \li	ISC_R_SUCCESS  * \li	ISC_R_TOOSMALL  * \li	ISC_R_UNEXPECTED  */
end_comment

begin_comment
comment|/*@{*/
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
comment|/*!  * Receive from 'socket', storing the results in region.  *  * Notes:  *  *\li	Let 'length' refer to the length of 'region' or to the sum of all  *	available regions in the list of buffers '*buflist'.  *  *\li	If 'minimum' is non-zero and at least that many bytes are read,  *	the completion event will be posted to the task 'task.'  If minimum  *	is zero, the exact number of bytes requested in the region must  * 	be read for an event to be posted.  This only makes sense for TCP  *	connections, and is always set to 1 byte for UDP.  *  *\li	The read will complete when the desired number of bytes have been  *	read, if end-of-input occurs, or if an error occurs.  A read done  *	event with the given 'action' and 'arg' will be posted to the  *	event queue of 'task'.  *  *\li	The caller may not modify 'region', the buffers which are passed  *	into this function, or any data they refer to until the completion  *	event is received.  *  *\li	For isc_socket_recvv():  *	On successful completion, '*buflist' will be empty, and the list of  *	all buffers will be returned in the done event's 'bufferlist'  *	member.  On error return, '*buflist' will be unchanged.  *  *\li	For isc_socket_recv2():  *	'event' is not NULL, and the non-socket specific fields are  *	expected to be initialized.  *  *\li	For isc_socket_recv2():  *	The only defined value for 'flags' is ISC_SOCKFLAG_IMMEDIATE.  If  *	set and the operation completes, the return value will be  *	ISC_R_SUCCESS and the event will be filled in and not sent.  If the  *	operation does not complete, the return value will be  *	ISC_R_INPROGRESS and the event will be sent when the operation  *	completes.  *  * Requires:  *  *\li	'socket' is a valid, bound socket.  *  *\li	For isc_socket_recv():  *	'region' is a valid region  *  *\li	For isc_socket_recvv():  *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.  *  *\li	'task' is a valid task  *  *\li	For isc_socket_recv() and isc_socket_recvv():  *	action != NULL and is a valid action  *  *\li	For isc_socket_recv2():  *	event != NULL  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_INPROGRESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  *  * Event results:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_UNEXPECTED  *\li	XXX needs other net-type errors  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
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
name|isc_socket_sendtov2
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
parameter_list|,
name|unsigned
name|int
name|flags
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
comment|/*!  * Send the contents of 'region' to the socket's peer.  *  * Notes:  *  *\li	Shutting down the requestor's task *may* result in any  *	still pending writes being dropped or completed, depending on the  *	underlying OS implementation.  *  *\li	If 'action' is NULL, then no completion event will be posted.  *  *\li	The caller may not modify 'region', the buffers which are passed  *	into this function, or any data they refer to until the completion  *	event is received.  *  *\li	For isc_socket_sendv() and isc_socket_sendtov():  *	On successful completion, '*buflist' will be empty, and the list of  *	all buffers will be returned in the done event's 'bufferlist'  *	member.  On error return, '*buflist' will be unchanged.  *  *\li	For isc_socket_sendto2():  *	'event' is not NULL, and the non-socket specific fields are  *	expected to be initialized.  *  *\li	For isc_socket_sendto2():  *	The only defined values for 'flags' are ISC_SOCKFLAG_IMMEDIATE  *	and ISC_SOCKFLAG_NORETRY.  *  *\li	If ISC_SOCKFLAG_IMMEDIATE is set and the operation completes, the  *	return value will be ISC_R_SUCCESS and the event will be filled  *	in and not sent.  If the operation does not complete, the return  *	value will be ISC_R_INPROGRESS and the event will be sent when  *	the operation completes.  *  *\li	ISC_SOCKFLAG_NORETRY can only be set for UDP sockets.  If set  *	and the send operation fails due to a transient error, the send  *	will not be retried and the error will be indicated in the event.  *	Using this option along with ISC_SOCKFLAG_IMMEDIATE allows the caller  *	to specify a region that is allocated on the stack.  *  * Requires:  *  *\li	'socket' is a valid, bound socket.  *  *\li	For isc_socket_send():  *	'region' is a valid region  *  *\li	For isc_socket_sendv() and isc_socket_sendtov():  *	'buflist' is non-NULL, and '*buflist' contain at least one buffer.  *  *\li	'task' is a valid task  *  *\li	For isc_socket_sendv(), isc_socket_sendtov(), isc_socket_send(), and  *	isc_socket_sendto():  *	action == NULL or is a valid action  *  *\li	For isc_socket_sendto2():  *	event != NULL  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_INPROGRESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  *  * Event results:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_UNEXPECTED  *\li	XXX needs other net-type errors  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|isc_result_t
name|isc_socketmgr_createinctx
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
name|actx
parameter_list|,
name|isc_socketmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|isc_result_t
name|isc_socketmgr_create2
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_socketmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|,
name|unsigned
name|int
name|maxsocks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a socket manager.  If "maxsocks" is non-zero, it specifies the  * maximum number of sockets that the created manager should handle.  * isc_socketmgr_create() is equivalent of isc_socketmgr_create2() with  * "maxsocks" being zero.  * isc_socketmgr_createinctx() also associates the new manager with the  * specified application context.  *  * Notes:  *  *\li	All memory will be allocated in memory context 'mctx'.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'managerp' points to a NULL isc_socketmgr_t.  *  *\li	'actx' is a valid application context (for createinctx()).  *  * Ensures:  *  *\li	'*managerp' is a valid isc_socketmgr_t.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  *\li	#ISC_R_NOTIMPLEMENTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socketmgr_getmaxsockets
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|manager
parameter_list|,
name|unsigned
name|int
modifier|*
name|nsockp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns in "*nsockp" the maximum number of sockets this manager may open.  *  * Requires:  *  *\li	'*manager' is a valid isc_socketmgr_t.  *\li	'nsockp' is not NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOTIMPLEMENTED  */
end_comment

begin_function_decl
name|void
name|isc_socketmgr_setstats
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|manager
parameter_list|,
name|isc_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set a general socket statistics counter set 'stats' for 'manager'.  *  * Requires:  * \li	'manager' is valid, hasn't opened any socket, and doesn't have  *	stats already set.  *  *\li	stats is a valid statistics supporting socket statistics counters  *	(see above).  */
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
comment|/*%<  * Destroy a socket manager.  *  * Notes:  *  *\li	This routine blocks until there are no sockets left in the manager,  *	so if the caller holds any socket references using the manager, it  *	must detach them before calling isc_socketmgr_destroy() or it will  *	block forever.  *  * Requires:  *  *\li	'*managerp' is a valid isc_socketmgr_t.  *  *\li	All sockets managed by this manager are fully detached.  *  * Ensures:  *  *\li	*managerp == NULL  *  *\li	All resources used by the manager have been freed.  */
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
comment|/*%<  * Returns the socket type for "sock."  *  * Requires:  *  *\li	"sock" is a valid socket.  */
end_comment

begin_comment
comment|/*@{*/
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
comment|/*%<  * If the socket is an IPv6 socket set/clear the IPV6_IPV6ONLY socket  * option if the host OS supports this option.  *  * Requires:  *\li	'sock' is a valid socket.  */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|void
name|isc_socket_cleanunix
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|addr
parameter_list|,
name|isc_boolean_t
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cleanup UNIX domain sockets in the file-system.  If 'active' is true  * then just unlink the socket.  If 'active' is false try to determine  * if there is a listener of the socket or not.  If no listener is found  * then unlink socket.  *  * Prior to unlinking the path is tested to see if it a socket.  *  * Note: there are a number of race conditions which cannot be avoided  *       both in the filesystem and any application using UNIX domain  *	 sockets (e.g. socket is tested between bind() and listen(),  *	 the socket is deleted and replaced in the file-system between  *	 stat() and unlink()).  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_socket_permunix
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|isc_uint32_t
name|perm
parameter_list|,
name|isc_uint32_t
name|owner
parameter_list|,
name|isc_uint32_t
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set ownership and file permissions on the UNIX domain socket.  *  * Note: On Solaris and SunOS this secures the directory containing  *       the socket as Solaris and SunOS do not honour the filesystem  *	 permissions on the socket.  *  * Requires:  * \li	'sockaddr' to be a valid UNIX domain sockaddr.  *  * Returns:  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_FAILURE  */
end_comment

begin_function_decl
name|void
name|isc_socket_setname
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the name and optional tag for a socket.  This allows tracking of the  * owner or purpose for this socket, and is useful for tracing and statistics  * reporting.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_socket_getname
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the name associated with a socket, if any.  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc_socket_gettag
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the tag associated with a socket, if any.  */
end_comment

begin_function_decl
name|int
name|isc_socket_getfd
parameter_list|(
name|isc_socket_t
modifier|*
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the file descriptor associated with a socket  */
end_comment

begin_function_decl
name|void
name|isc__socketmgr_setreserved
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|mgr
parameter_list|,
name|isc_uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Temporary.  For use by named only.  */
end_comment

begin_function_decl
name|void
name|isc__socketmgr_maxudp
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|mgr
parameter_list|,
name|int
name|maxudp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Test interface. Drop UDP packet> 'maxudp'.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBXML2
end_ifdef

begin_function_decl
name|int
name|isc_socketmgr_renderxml
parameter_list|(
name|isc_socketmgr_t
modifier|*
name|mgr
parameter_list|,
name|xmlTextWriterPtr
name|writer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Render internal statistics and other state into the XML document.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LIBXML2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SOCKETIMPREGISTER
end_ifdef

begin_comment
comment|/*%<  * See isc_socketmgr_create() above.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_socketmgrcreatefunc_t
function_decl|)
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
end_typedef

begin_function_decl
name|isc_result_t
name|isc_socket_register
parameter_list|(
name|isc_socketmgrcreatefunc_t
name|createfunc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a new socket I/O implementation and add it to the list of  * supported implementations.  This function must be called when a different  * event library is used than the one contained in the ISC library.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc__socket_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * A short cut function that specifies the socket I/O module in the ISC  * library for isc_socket_register().  An application that uses the ISC library  * usually do not have to care about this function: it would call  * isc_lib_register(), which internally calls this function.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SOCKETIMPREGISTER */
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

