begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dispatch.h,v 1.45.2.2.4.2 2004/03/06 08:13:55 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DISPATCH_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DISPATCH_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS Dispatch Management  *  * 	Shared UDP and single-use TCP dispatches for queries and responses.  *  * MP:  *  *     	All locking is performed internally to each dispatch.  * 	Restrictions apply to dns_dispatch_removeresponse().  *  * Reliability:  *  * Resources:  *  * Security:  *  *	Depends on the isc_socket_t and dns_message_t for prevention of  *	buffer overruns.  *  * Standards:  *  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * This event is sent to a task when a response comes in.  * No part of this structure should ever be modified by the caller,  * other than parts of the buffer.  The holy parts of the buffer are  * the base and size of the buffer.  All other parts of the buffer may  * be used.  On event delivery the used region contains the packet.  *  * "id" is the received message id,  *  * "addr" is the host that sent it to us,  *  * "buffer" holds state on the received data.  *  * The "free" routine for this event will clean up itself as well as  * any buffer space allocated from common pools.  */
end_comment

begin_struct
struct|struct
name|dns_dispatchevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
name|dns_dispatchevent_t
argument_list|)
expr_stmt|;
comment|/* standard event common */
name|isc_result_t
name|result
decl_stmt|;
comment|/* result code */
name|isc_int32_t
name|id
decl_stmt|;
comment|/* message id */
name|isc_sockaddr_t
name|addr
decl_stmt|;
comment|/* address recv'd from */
name|struct
name|in6_pktinfo
name|pktinfo
decl_stmt|;
comment|/* reply info for v6 */
name|isc_buffer_t
name|buffer
decl_stmt|;
comment|/* data buffer */
name|isc_uint32_t
name|attributes
decl_stmt|;
comment|/* mirrored from socket.h */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Attributes for added dispatchers.  *  * Values with the mask 0xffff0000 are application defined.  * Values with the mask 0x0000ffff are library defined.  *  * Insane values (like setting both TCP and UDP) are not caught.  Don't  * do that.  *  * _PRIVATE  *	The dispatcher cannot be shared.  *  * _TCP, _UDP  *	The dispatcher is a TCP or UDP socket.  *  * _IPV4, _IPV6  *	The dispatcher uses an ipv4 or ipv6 socket.  *  * _NOLISTEN  *	The dispatcher should not listen on the socket.  *  * _MAKEQUERY  *	The dispatcher can be used to issue queries to other servers, and  *	accept replies from them.  */
end_comment

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_PRIVATE
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_TCP
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_UDP
value|0x00000004U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_IPV4
value|0x00000008U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_IPV6
value|0x00000010U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_NOLISTEN
value|0x00000020U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_MAKEQUERY
value|0x00000040U
end_define

begin_define
define|#
directive|define
name|DNS_DISPATCHATTR_CONNECTED
value|0x00000080U
end_define

begin_function_decl
name|isc_result_t
name|dns_dispatchmgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
name|entropy
parameter_list|,
name|dns_dispatchmgr_t
modifier|*
modifier|*
name|mgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Creates a new dispatchmgr object.  *  * Requires:  *	"mctx" be a valid memory context.  *  *	mgrp != NULL&& *mgrp == NULL  *  *	"entropy" may be NULL, in which case an insecure random generator  *	will be used.  If it is non-NULL, it must be a valid entropy  *	source.  *  * Returns:  *	ISC_R_SUCCESS	-- all ok  *  *	anything else	-- failure  */
end_comment

begin_function_decl
name|void
name|dns_dispatchmgr_destroy
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
modifier|*
name|mgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroys the dispatchmgr when it becomes empty.  This could be  * immediately.  *  * Requires:  *	mgrp != NULL&& *mgrp is a valid dispatchmgr.  */
end_comment

begin_function_decl
name|void
name|dns_dispatchmgr_setblackhole
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|,
name|dns_acl_t
modifier|*
name|blackhole
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets the dispatcher's "blackhole list," a list of addresses that will  * be ignored by all dispatchers created by the dispatchmgr.  *  * Requires:  * 	mgrp is a valid dispatchmgr  * 	blackhole is a valid acl  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_dispatchmgr_getblackhole
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Gets a pointer to the dispatcher's current blackhole list,  * without incrementing its reference count.  *  * Requires:  * 	mgr is a valid dispatchmgr  * Returns:  *	A pointer to the current blackhole list, or NULL.  */
end_comment

begin_function_decl
name|void
name|dns_dispatchmgr_setblackportlist
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|,
name|dns_portlist_t
modifier|*
name|portlist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets a list of UDP ports that won't be used when creating a udp  * dispatch with a wildcard port.  *  * Requires:  *	mgr is a valid dispatchmgr  *	portlist to be NULL or a valid port list.  */
end_comment

begin_function_decl
name|dns_portlist_t
modifier|*
name|dns_dispatchmgr_getblackportlist
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current port list.  *  * Requires:  *	mgr is a valid dispatchmgr  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dispatch_getudp
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|sockmgr
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|localaddr
parameter_list|,
name|unsigned
name|int
name|buffersize
parameter_list|,
name|unsigned
name|int
name|maxbuffers
parameter_list|,
name|unsigned
name|int
name|maxrequests
parameter_list|,
name|unsigned
name|int
name|buckets
parameter_list|,
name|unsigned
name|int
name|increment
parameter_list|,
name|unsigned
name|int
name|attributes
parameter_list|,
name|unsigned
name|int
name|mask
parameter_list|,
name|dns_dispatch_t
modifier|*
modifier|*
name|dispp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to existing dns_dispatch_t if one is found with dns_dispatchmgr_find,  * otherwise create a new UDP dispatch.  *  * Requires:  *	All pointer parameters be valid for their respective types.  *  *	dispp != NULL&& *disp == NULL  *  *	512<= buffersize<= 64k  *  *	maxbuffers> 0  *  *	buckets< 2097169  *  *	increment> buckets  *  *	(attributes& DNS_DISPATCHATTR_TCP) == 0  *  * Returns:  *	ISC_R_SUCCESS	-- success.  *  *	Anything else	-- failure.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dispatch_createtcp
parameter_list|(
name|dns_dispatchmgr_t
modifier|*
name|mgr
parameter_list|,
name|isc_socket_t
modifier|*
name|sock
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|unsigned
name|int
name|buffersize
parameter_list|,
name|unsigned
name|int
name|maxbuffers
parameter_list|,
name|unsigned
name|int
name|maxrequests
parameter_list|,
name|unsigned
name|int
name|buckets
parameter_list|,
name|unsigned
name|int
name|increment
parameter_list|,
name|unsigned
name|int
name|attributes
parameter_list|,
name|dns_dispatch_t
modifier|*
modifier|*
name|dispp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new dns_dispatch and attach it to the provided isc_socket_t.  *  * For all dispatches, "buffersize" is the maximum packet size we will  * accept.  *  * "maxbuffers" and "maxrequests" control the number of buffers in the  * overall system and the number of buffers which can be allocated to  * requests.  *  * "buckets" is the number of buckets to use, and should be prime.  *  * "increment" is used in a collision avoidance function, and needs to be  * a prime> buckets, and not 2.  *  * Requires:  *  *	mgr is a valid dispatch manager.  *  *	sock is a valid.  *  *	task is a valid task that can be used internally to this dispatcher.  *  * 	512<= buffersize<= 64k  *  *	maxbuffers> 0.  *  *	maxrequests<= maxbuffers.  *  *	buckets< 2097169 (the next prime after 65536 * 32)  *  *	increment> buckets (and prime).  *  *	attributes includes DNS_DISPATCHATTR_TCP and does not include  *	DNS_DISPATCHATTR_UDP.  *  * Returns:  *	ISC_R_SUCCESS	-- success.  *  *	Anything else	-- failure.  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_attach
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|,
name|dns_dispatch_t
modifier|*
modifier|*
name|dispp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to a dispatch handle.  *  * Requires:  *	disp is valid.  *  *	dispp != NULL&& *dispp == NULL  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_detach
parameter_list|(
name|dns_dispatch_t
modifier|*
modifier|*
name|dispp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detaches from the dispatch.  *  * Requires:  *	dispp != NULL and *dispp be a valid dispatch.  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_starttcp
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Start processing of a TCP dispatch once the socket connects.  *  * Requires:  *	'disp' is valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dispatch_addresponse
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|dest
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
name|isc_uint16_t
modifier|*
name|idp
parameter_list|,
name|dns_dispentry_t
modifier|*
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a response entry for this dispatch.  *  * "*idp" is filled in with the assigned message ID, and *resp is filled in  * to contain the magic token used to request event flow stop.  *  * Arranges for the given task to get a callback for response packets.  When  * the event is delivered, it must be returned using dns_dispatch_freeevent()  * or through dns_dispatch_removeresponse() for another to be delivered.  *  * Requires:  *	"idp" be non-NULL.  *  *	"task" "action" and "arg" be set as appropriate.  *  *	"dest" be non-NULL and valid.  *  *	"resp" be non-NULL and *resp be NULL  *  * Ensures:  *  *<id, dest> is a unique tuple.  That means incoming messages  *	are identifiable.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *	ISC_R_NOMEMORY		-- memory could not be allocated.  *	ISC_R_NOMORE		-- no more message ids can be allocated  *				   for this destination.  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_removeresponse
parameter_list|(
name|dns_dispentry_t
modifier|*
modifier|*
name|resp
parameter_list|,
name|dns_dispatchevent_t
modifier|*
modifier|*
name|sockevent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Stops the flow of responses for the provided id and destination.  * If "sockevent" is non-NULL, the dispatch event and associated buffer is  * also returned to the system.  *  * Requires:  *	"resp" != NULL and "*resp" contain a value previously allocated  *	by dns_dispatch_addresponse();  *  *	May only be called from within the task given as the 'task'   * 	argument to dns_dispatch_addresponse() when allocating '*resp'.  */
end_comment

begin_function_decl
name|isc_socket_t
modifier|*
name|dns_dispatch_getsocket
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the socket associated with this dispatcher.  *  * Requires:  *	disp is valid.  *  * Returns:  *	The socket the dispatcher is using.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dispatch_getlocaladdress
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the local address for this dispatch.  * This currently only works for dispatches using UDP sockets.  *  * Requires:  *	disp is valid.  *	addrp to be non null.  *  * Returns:  *	ISC_R_SUCCESS	  *	ISC_R_NOTIMPLEMENTED  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_cancel
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cancel outstanding clients  *  * Requires:  *	disp is valid.  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_changeattributes
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|,
name|unsigned
name|int
name|attributes
parameter_list|,
name|unsigned
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the bits described by "mask" to the corresponding values in  * "attributes".  *  * That is:  *  *	new = (old& ~mask) | (attributes& mask)  *  * This function has a side effect when DNS_DISPATCHATTR_NOLISTEN changes.   * When the flag becomes off, the dispatch will start receiving on the  * corresponding socket.  When the flag becomes on, receive events on the  * corresponding socket will be canceled.  *  * Requires:  *	disp is valid.  *  *	attributes are reasonable for the dispatch.  That is, setting the UDP  *	attribute on a TCP socket isn't reasonable.  */
end_comment

begin_function_decl
name|void
name|dns_dispatch_importrecv
parameter_list|(
name|dns_dispatch_t
modifier|*
name|disp
parameter_list|,
name|isc_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inform the dispatcher of a socket receive.  This is used for sockets  * shared between dispatchers and clients.  If the dispatcher fails to copy  * or send the event, nothing happens.  *  * Requires:  * 	disp is valid, and the attribute DNS_DISPATCHATTR_NOLISTEN is set.  * 	event != NULL  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DISPATCH_H */
end_comment

end_unit

