begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/outside_network.h - listen to answers from the network  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file has functions to send queries to authoritative servers,  * and wait for the pending answer, with timeouts.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OUTSIDE_NETWORK_H
end_ifndef

begin_define
define|#
directive|define
name|OUTSIDE_NETWORK_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

begin_struct_decl
struct_decl|struct
name|pending
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pending_timeout
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pending_tcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|waiting_tcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|waiting_udp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|infra_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|port_comm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|port_if
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Send queries to outside servers and wait for answers from servers.  * Contains answer-listen sockets.  */
end_comment

begin_struct
struct|struct
name|outside_network
block|{
comment|/** Base for select calls */
name|struct
name|comm_base
modifier|*
name|base
decl_stmt|;
comment|/** pointer to time in seconds */
name|time_t
modifier|*
name|now_secs
decl_stmt|;
comment|/** pointer to time in microseconds */
name|struct
name|timeval
modifier|*
name|now_tv
decl_stmt|;
comment|/** buffer shared by UDP connections, since there is only one 	    datagram at any time. */
name|struct
name|sldns_buffer
modifier|*
name|udp_buff
decl_stmt|;
comment|/** serviced_callbacks malloc overhead when processing multiple 	 * identical serviced queries to the same server. */
name|size_t
name|svcd_overhead
decl_stmt|;
comment|/** use x20 bits to encode additional ID random bits */
name|int
name|use_caps_for_id
decl_stmt|;
comment|/** outside network wants to quit. Stop queued msgs from sent. */
name|int
name|want_to_quit
decl_stmt|;
comment|/** number of unwanted replies received (for statistics) */
name|size_t
name|unwanted_replies
decl_stmt|;
comment|/** cumulative total of unwanted replies (for defense) */
name|size_t
name|unwanted_total
decl_stmt|;
comment|/** threshold when to take defensive action. If 0 then never. */
name|size_t
name|unwanted_threshold
decl_stmt|;
comment|/** what action to take, called when defensive action is needed */
name|void
function_decl|(
modifier|*
name|unwanted_action
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** user param for action */
name|void
modifier|*
name|unwanted_param
decl_stmt|;
comment|/** linked list of available commpoints, unused file descriptors, 	 * for use as outgoing UDP ports. cp.fd=-1 in them. */
name|struct
name|port_comm
modifier|*
name|unused_fds
decl_stmt|;
comment|/** if udp is done */
name|int
name|do_udp
decl_stmt|;
comment|/** if udp is delay-closed (delayed answers do not meet closed port)*/
name|int
name|delayclose
decl_stmt|;
comment|/** timeout for delayclose */
name|struct
name|timeval
name|delay_tv
decl_stmt|;
comment|/** array of outgoing IP4 interfaces */
name|struct
name|port_if
modifier|*
name|ip4_ifs
decl_stmt|;
comment|/** number of outgoing IP4 interfaces */
name|int
name|num_ip4
decl_stmt|;
comment|/** array of outgoing IP6 interfaces */
name|struct
name|port_if
modifier|*
name|ip6_ifs
decl_stmt|;
comment|/** number of outgoing IP6 interfaces */
name|int
name|num_ip6
decl_stmt|;
comment|/** pending udp queries waiting to be sent out, waiting for fd */
name|struct
name|pending
modifier|*
name|udp_wait_first
decl_stmt|;
comment|/** last pending udp query in list */
name|struct
name|pending
modifier|*
name|udp_wait_last
decl_stmt|;
comment|/** pending udp answers. sorted by id, addr */
name|rbtree_t
modifier|*
name|pending
decl_stmt|;
comment|/** serviced queries, sorted by qbuf, addr, dnssec */
name|rbtree_t
modifier|*
name|serviced
decl_stmt|;
comment|/** host cache, pointer but not owned by outnet. */
name|struct
name|infra_cache
modifier|*
name|infra
decl_stmt|;
comment|/** where to get random numbers */
name|struct
name|ub_randstate
modifier|*
name|rnd
decl_stmt|;
comment|/** ssl context to create ssl wrapped TCP with DNS connections */
name|void
modifier|*
name|sslctx
decl_stmt|;
comment|/** 	 * Array of tcp pending used for outgoing TCP connections. 	 * Each can be used to establish a TCP connection with a server. 	 * The file descriptors are -1 if they are free, and need to be  	 * opened for the tcp connection. Can be used for ip4 and ip6. 	 */
name|struct
name|pending_tcp
modifier|*
modifier|*
name|tcp_conns
decl_stmt|;
comment|/** number of tcp communication points. */
name|size_t
name|num_tcp
decl_stmt|;
comment|/** list of tcp comm points that are free for use */
name|struct
name|pending_tcp
modifier|*
name|tcp_free
decl_stmt|;
comment|/** list of tcp queries waiting for a buffer */
name|struct
name|waiting_tcp
modifier|*
name|tcp_wait_first
decl_stmt|;
comment|/** last of waiting query list */
name|struct
name|waiting_tcp
modifier|*
name|tcp_wait_last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Outgoing interface. Ports available and currently used are tracked  * per interface  */
end_comment

begin_struct
struct|struct
name|port_if
block|{
comment|/** address ready to allocate new socket (except port no). */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr field */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** the available ports array. These are unused. 	 * Only the first total-inuse part is filled. */
name|int
modifier|*
name|avail_ports
decl_stmt|;
comment|/** the total number of available ports (size of the array) */
name|int
name|avail_total
decl_stmt|;
comment|/** array of the commpoints currently in use.  	 * allocated for max number of fds, first part in use. */
name|struct
name|port_comm
modifier|*
modifier|*
name|out
decl_stmt|;
comment|/** max number of fds, size of out array */
name|int
name|maxout
decl_stmt|;
comment|/** number of commpoints (and thus also ports) in use */
name|int
name|inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Outgoing commpoint for UDP port.  */
end_comment

begin_struct
struct|struct
name|port_comm
block|{
comment|/** next in free list */
name|struct
name|port_comm
modifier|*
name|next
decl_stmt|;
comment|/** which port number (when in use) */
name|int
name|number
decl_stmt|;
comment|/** interface it is used in */
name|struct
name|port_if
modifier|*
name|pif
decl_stmt|;
comment|/** index in the out array of the interface */
name|int
name|index
decl_stmt|;
comment|/** number of outstanding queries on this port */
name|int
name|num_outstanding
decl_stmt|;
comment|/** UDP commpoint, fd=-1 if not in use */
name|struct
name|comm_point
modifier|*
name|cp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A query that has an answer pending for it.  */
end_comment

begin_struct
struct|struct
name|pending
block|{
comment|/** redblacktree entry, key is the pending struct(id, addr). */
name|rbnode_t
name|node
decl_stmt|;
comment|/** the ID for the query. int so that a value out of range can 	 * be used to signify a pending that is for certain not present in 	 * the rbtree. (and for which deletion is safe). */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/** remote address. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr field in use. */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** comm point it was sent on (and reply must come back on). */
name|struct
name|port_comm
modifier|*
name|pc
decl_stmt|;
comment|/** timeout event */
name|struct
name|comm_timer
modifier|*
name|timer
decl_stmt|;
comment|/** callback for the timeout, error or reply to the message */
name|comm_point_callback_t
modifier|*
name|cb
decl_stmt|;
comment|/** callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** the outside network it is part of */
name|struct
name|outside_network
modifier|*
name|outnet
decl_stmt|;
comment|/*---- filled if udp pending is waiting -----*/
comment|/** next in waiting list. */
name|struct
name|pending
modifier|*
name|next_waiting
decl_stmt|;
comment|/** timeout in msec */
name|int
name|timeout
decl_stmt|;
comment|/** The query itself, the query packet to send. */
name|uint8_t
modifier|*
name|pkt
decl_stmt|;
comment|/** length of query packet. */
name|size_t
name|pkt_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Pending TCP query to server.  */
end_comment

begin_struct
struct|struct
name|pending_tcp
block|{
comment|/** next in list of free tcp comm points, or NULL. */
name|struct
name|pending_tcp
modifier|*
name|next_free
decl_stmt|;
comment|/** the ID for the query; checked in reply */
name|uint16_t
name|id
decl_stmt|;
comment|/** tcp comm point it was sent on (and reply must come back on). */
name|struct
name|comm_point
modifier|*
name|c
decl_stmt|;
comment|/** the query being serviced, NULL if the pending_tcp is unused. */
name|struct
name|waiting_tcp
modifier|*
name|query
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Query waiting for TCP buffer.  */
end_comment

begin_struct
struct|struct
name|waiting_tcp
block|{
comment|/**  	 * next in waiting list. 	 * if pkt==0, this points to the pending_tcp structure. 	 */
name|struct
name|waiting_tcp
modifier|*
name|next_waiting
decl_stmt|;
comment|/** timeout event; timer keeps running whether the query is 	 * waiting for a buffer or the tcp reply is pending */
name|struct
name|comm_timer
modifier|*
name|timer
decl_stmt|;
comment|/** the outside network it is part of */
name|struct
name|outside_network
modifier|*
name|outnet
decl_stmt|;
comment|/** remote address. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr field in use. */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/**  	 * The query itself, the query packet to send. 	 * allocated after the waiting_tcp structure. 	 * set to NULL when the query is serviced and it part of pending_tcp. 	 * if this is NULL, the next_waiting points to the pending_tcp. 	 */
name|uint8_t
modifier|*
name|pkt
decl_stmt|;
comment|/** length of query packet. */
name|size_t
name|pkt_len
decl_stmt|;
comment|/** callback for the timeout, error or reply to the message */
name|comm_point_callback_t
modifier|*
name|cb
decl_stmt|;
comment|/** callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** if it uses ssl upstream */
name|int
name|ssl_upstream
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Callback to party interested in serviced query results.  */
end_comment

begin_struct
struct|struct
name|service_callback
block|{
comment|/** next in callback list */
name|struct
name|service_callback
modifier|*
name|next
decl_stmt|;
comment|/** callback function */
name|comm_point_callback_t
modifier|*
name|cb
decl_stmt|;
comment|/** user argument for callback function */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** fallback size for fragmentation for EDNS in IPv4 */
end_comment

begin_define
define|#
directive|define
name|EDNS_FRAG_SIZE_IP4
value|1472
end_define

begin_comment
comment|/** fallback size for EDNS in IPv6, fits one fragment with ip6-tunnel-ids */
end_comment

begin_define
define|#
directive|define
name|EDNS_FRAG_SIZE_IP6
value|1232
end_define

begin_comment
comment|/**  * Query service record.  * Contains query and destination. UDP, TCP, EDNS are all tried.  * complete with retries and timeouts. A number of interested parties can  * receive a callback.  */
end_comment

begin_struct
struct|struct
name|serviced_query
block|{
comment|/** The rbtree node, key is this record */
name|rbnode_t
name|node
decl_stmt|;
comment|/** The query that needs to be answered. Starts with flags u16, 	 * then qdcount, ..., including qname, qtype, qclass. Does not include 	 * EDNS record. */
name|uint8_t
modifier|*
name|qbuf
decl_stmt|;
comment|/** length of qbuf. */
name|size_t
name|qbuflen
decl_stmt|;
comment|/** If an EDNS section is included, the DO/CD bit will be turned on. */
name|int
name|dnssec
decl_stmt|;
comment|/** We want signatures, or else the answer is likely useless */
name|int
name|want_dnssec
decl_stmt|;
comment|/** tcp upstream used, use tcp, or ssl_upstream for SSL */
name|int
name|tcp_upstream
decl_stmt|,
name|ssl_upstream
decl_stmt|;
comment|/** where to send it */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr field in use. */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** zone name, uncompressed domain name in wireformat */
name|uint8_t
modifier|*
name|zone
decl_stmt|;
comment|/** length of zone name */
name|size_t
name|zonelen
decl_stmt|;
comment|/** qtype */
name|int
name|qtype
decl_stmt|;
comment|/** current status */
enum|enum
name|serviced_query_status
block|{
comment|/** initial status */
name|serviced_initial
block|,
comment|/** UDP with EDNS sent */
name|serviced_query_UDP_EDNS
block|,
comment|/** UDP without EDNS sent */
name|serviced_query_UDP
block|,
comment|/** TCP with EDNS sent */
name|serviced_query_TCP_EDNS
block|,
comment|/** TCP without EDNS sent */
name|serviced_query_TCP
block|,
comment|/** probe to test EDNS lameness (EDNS is dropped) */
name|serviced_query_PROBE_EDNS
block|,
comment|/** probe to test noEDNS0 (EDNS gives FORMERRorNOTIMP) */
name|serviced_query_UDP_EDNS_fallback
block|,
comment|/** probe to test TCP noEDNS0 (EDNS gives FORMERRorNOTIMP) */
name|serviced_query_TCP_EDNS_fallback
block|,
comment|/** send UDP query with EDNS1480 (or 1280) */
name|serviced_query_UDP_EDNS_FRAG
block|}
comment|/** variable with current status */
name|status
enum|;
comment|/** true if serviced_query is scheduled for deletion already */
name|int
name|to_be_deleted
decl_stmt|;
comment|/** number of UDP retries */
name|int
name|retry
decl_stmt|;
comment|/** time last UDP was sent */
name|struct
name|timeval
name|last_sent_time
decl_stmt|;
comment|/** rtt of last (UDP) message */
name|int
name|last_rtt
decl_stmt|;
comment|/** do we know edns probe status already, for UDP_EDNS queries */
name|int
name|edns_lame_known
decl_stmt|;
comment|/** outside network this is part of */
name|struct
name|outside_network
modifier|*
name|outnet
decl_stmt|;
comment|/** list of interested parties that need callback on results. */
name|struct
name|service_callback
modifier|*
name|cblist
decl_stmt|;
comment|/** the UDP or TCP query that is pending, see status which */
name|void
modifier|*
name|pending
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create outside_network structure with N udp ports.  * @param base: the communication base to use for event handling.  * @param bufsize: size for network buffers.  * @param num_ports: number of udp ports to open per interface.  * @param ifs: interface names (or NULL for default interface).  *    These interfaces must be able to access all authoritative servers.  * @param num_ifs: number of names in array ifs.  * @param do_ip4: service IP4.  * @param do_ip6: service IP6.  * @param num_tcp: number of outgoing tcp buffers to preallocate.  * @param infra: pointer to infra cached used for serviced queries.  * @param rnd: stored to create random numbers for serviced queries.  * @param use_caps_for_id: enable to use 0x20 bits to encode id randomness.  * @param availports: array of available ports.   * @param numavailports: number of available ports in array.  * @param unwanted_threshold: when to take defensive action.  * @param unwanted_action: the action to take.  * @param unwanted_param: user parameter to action.  * @param do_udp: if udp is done.  * @param sslctx: context to create outgoing connections with (if enabled).  * @param delayclose: if not 0, udp sockets are delayed before timeout closure.  * 	msec to wait on timeouted udp sockets.  * @return: the new structure (with no pending answers) or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|outside_network
modifier|*
name|outside_network_create
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|size_t
name|num_ports
parameter_list|,
name|char
modifier|*
modifier|*
name|ifs
parameter_list|,
name|int
name|num_ifs
parameter_list|,
name|int
name|do_ip4
parameter_list|,
name|int
name|do_ip6
parameter_list|,
name|size_t
name|num_tcp
parameter_list|,
name|struct
name|infra_cache
modifier|*
name|infra
parameter_list|,
name|struct
name|ub_randstate
modifier|*
name|rnd
parameter_list|,
name|int
name|use_caps_for_id
parameter_list|,
name|int
modifier|*
name|availports
parameter_list|,
name|int
name|numavailports
parameter_list|,
name|size_t
name|unwanted_threshold
parameter_list|,
name|void
function_decl|(
modifier|*
name|unwanted_action
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|unwanted_param
parameter_list|,
name|int
name|do_udp
parameter_list|,
name|void
modifier|*
name|sslctx
parameter_list|,
name|int
name|delayclose
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete outside_network structure.  * @param outnet: object to delete.  */
end_comment

begin_function_decl
name|void
name|outside_network_delete
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prepare for quit. Sends no more queries, even if queued up.  * @param outnet: object to prepare for removal  */
end_comment

begin_function_decl
name|void
name|outside_network_quit_prepare
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send UDP query, create pending answer.  * Changes the ID for the query to be random and unique for that destination.  * @param outnet: provides the event handling  * @param packet: wireformat query to send to destination.  * @param addr: address to send to.  * @param addrlen: length of addr.  * @param timeout: in milliseconds from now.  * @param callback: function to call on error, timeout or reply.  * @param callback_arg: user argument for callback function.  * @return: NULL on error for malloc or socket. Else the pending query object.  */
end_comment

begin_function_decl
name|struct
name|pending
modifier|*
name|pending_udp_query
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|packet
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|int
name|timeout
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
comment|/**  * Send TCP query. May wait for TCP buffer. Selects ID to be random, and   * checks id.  * @param outnet: provides the event handling.  * @param packet: wireformat query to send to destination. copied from.  * @param addr: address to send to.  * @param addrlen: length of addr.  * @param timeout: in seconds from now.  *    Timer starts running now. Timer may expire if all buffers are used,  *    without any query been sent to the server yet.  * @param callback: function to call on error, timeout or reply.  * @param callback_arg: user argument for callback function.  * @param ssl_upstream: if the tcp connection must use SSL.  * @return: false on error for malloc or socket. Else the pending TCP object.  */
end_comment

begin_function_decl
name|struct
name|waiting_tcp
modifier|*
name|pending_tcp_query
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|packet
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|int
name|timeout
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|ssl_upstream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete pending answer.  * @param outnet: outside network the pending query is part of.  *    Internal feature: if outnet is NULL, p is not unlinked from rbtree.  * @param p: deleted  */
end_comment

begin_function_decl
name|void
name|pending_delete
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|,
name|struct
name|pending
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Perform a serviced query to the authoritative servers.  * Duplicate efforts are detected, and EDNS, TCP and UDP retry is performed.  * @param outnet: outside network, with rbtree of serviced queries.  * @param qname: what qname to query.  * @param qnamelen: length of qname in octets including 0 root label.  * @param qtype: rrset type to query (host format)  * @param qclass: query class. (host format)  * @param flags: flags u16 (host format), includes opcode, CD bit.  * @param dnssec: if set, DO bit is set in EDNS queries.  *	If the value includes BIT_CD, CD bit is set when in EDNS queries.  *	If the value includes BIT_DO, DO bit is set when in EDNS queries.  * @param want_dnssec: signatures are needed, without EDNS the answer is  * 	likely to be useless.  * @param tcp_upstream: use TCP for upstream queries.  * @param ssl_upstream: use SSL for upstream queries.  * @param callback: callback function.  * @param callback_arg: user argument to callback function.  * @param addr: to which server to send the query.  * @param addrlen: length of addr.  * @param zone: name of the zone of the delegation point. wireformat dname. 	This is the delegation point name for which the server is deemed 	authoritative.  * @param zonelen: length of zone.  * @param buff: scratch buffer to create query contents in. Empty on exit.  * @return 0 on error, or pointer to serviced query that is used to answer  *	this serviced query may be shared with other callbacks as well.  */
end_comment

begin_function_decl
name|struct
name|serviced_query
modifier|*
name|outnet_serviced_query
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|int
name|dnssec
parameter_list|,
name|int
name|want_dnssec
parameter_list|,
name|int
name|tcp_upstream
parameter_list|,
name|int
name|ssl_upstream
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|size_t
name|zonelen
parameter_list|,
name|comm_point_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove service query callback.  * If that leads to zero callbacks, the query is completely cancelled.  * @param sq: serviced query to adjust.  * @param cb_arg: callback argument of callback that needs removal.  *	same as the callback_arg to outnet_serviced_query().  */
end_comment

begin_function_decl
name|void
name|outnet_serviced_query_stop
parameter_list|(
name|struct
name|serviced_query
modifier|*
name|sq
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory size in use by outside network.  * Counts buffers and outstanding query (serviced queries) malloced data.  * @param outnet: outside network structure.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|outnet_get_mem
parameter_list|(
name|struct
name|outside_network
modifier|*
name|outnet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory size in use by serviced query while it is servicing callbacks.  * This takes into account the pre-deleted status of it; it will be deleted  * when the callbacks are done.  * @param sq: serviced query.   * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|serviced_get_mem
parameter_list|(
name|struct
name|serviced_query
modifier|*
name|sq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for incoming udp answers from the network */
end_comment

begin_function_decl
name|int
name|outnet_udp_cb
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|reply_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for pending tcp connections */
end_comment

begin_function_decl
name|int
name|outnet_tcp_cb
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|reply_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for udp timeout */
end_comment

begin_function_decl
name|void
name|pending_udp_timer_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for udp delay for timeout */
end_comment

begin_function_decl
name|void
name|pending_udp_timer_delay_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for outgoing TCP timer event */
end_comment

begin_function_decl
name|void
name|outnet_tcptimer
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for serviced query UDP answers */
end_comment

begin_function_decl
name|int
name|serviced_udp_callback
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** TCP reply or error callback for serviced queries */
end_comment

begin_function_decl
name|int
name|serviced_tcp_callback
parameter_list|(
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare function of pending rbtree */
end_comment

begin_function_decl
name|int
name|pending_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|key1
parameter_list|,
specifier|const
name|void
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare function of serviced query rbtree */
end_comment

begin_function_decl
name|int
name|serviced_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|key1
parameter_list|,
specifier|const
name|void
modifier|*
name|key2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OUTSIDE_NETWORK_H */
end_comment

end_unit

