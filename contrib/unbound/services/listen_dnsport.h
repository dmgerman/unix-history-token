begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/listen_dnsport.h - listen on port 53 for incoming DNS queries.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file has functions to get queries from clients.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LISTEN_DNSPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LISTEN_DNSPORT_H
end_define

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

begin_struct_decl
struct_decl|struct
name|listen_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|addrinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Listening for queries structure.  * Contains list of query-listen sockets.  */
end_comment

begin_struct
struct|struct
name|listen_dnsport
block|{
comment|/** Base for select calls */
name|struct
name|comm_base
modifier|*
name|base
decl_stmt|;
comment|/** buffer shared by UDP connections, since there is only one 	    datagram at any time. */
name|struct
name|sldns_buffer
modifier|*
name|udp_buff
decl_stmt|;
comment|/** list of comm points used to get incoming events */
name|struct
name|listen_list
modifier|*
name|cps
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Single linked list to store event points.  */
end_comment

begin_struct
struct|struct
name|listen_list
block|{
comment|/** next in list */
name|struct
name|listen_list
modifier|*
name|next
decl_stmt|;
comment|/** event info */
name|struct
name|comm_point
modifier|*
name|com
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * type of ports  */
end_comment

begin_enum
enum|enum
name|listen_type
block|{
comment|/** udp type */
name|listen_type_udp
block|,
comment|/** tcp type */
name|listen_type_tcp
block|,
comment|/** udp ipv6 (v4mapped) for use with ancillary data */
name|listen_type_udpancil
block|,
comment|/** ssl over tcp type */
name|listen_type_ssl
block|}
enum|;
end_enum

begin_comment
comment|/**  * Single linked list to store shared ports that have been   * opened for use by all threads.  */
end_comment

begin_struct
struct|struct
name|listen_port
block|{
comment|/** next in list */
name|struct
name|listen_port
modifier|*
name|next
decl_stmt|;
comment|/** file descriptor, open and ready for use */
name|int
name|fd
decl_stmt|;
comment|/** type of file descriptor, udp or tcp */
name|enum
name|listen_type
name|ftype
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create shared listening ports  * Getaddrinfo, create socket, bind and listen to zero or more   * interfaces for IP4 and/or IP6, for UDP and/or TCP.  * On the given port number. It creates the sockets.  * @param cfg: settings on what ports to open.  * @param reuseport: set to true if you want reuseport, or NULL to not have it,  *   set to false on exit if reuseport failed to apply (because of no  *   kernel support).  * @return: linked list of ports or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|listen_port
modifier|*
name|listening_ports_open
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|int
modifier|*
name|reuseport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close and delete the (list of) listening ports.  */
end_comment

begin_function_decl
name|void
name|listening_ports_free
parameter_list|(
name|struct
name|listen_port
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create commpoints with for this thread for the shared ports.  * @param base: the comm_base that provides event functionality.  *	for default all ifs.  * @param ports: the list of shared ports.  * @param bufsize: size of datagram buffer.  * @param tcp_accept_count: max number of simultaneous TCP connections   * 	from clients.  * @param sslctx: nonNULL if ssl context.  * @param cb: callback function when a request arrives. It is passed  *	  the packet and user argument. Return true to send a reply.  * @param cb_arg: user data argument for callback function.  * @return: the malloced listening structure, ready for use. NULL on error.  */
end_comment

begin_function_decl
name|struct
name|listen_dnsport
modifier|*
name|listen_create
parameter_list|(
name|struct
name|comm_base
modifier|*
name|base
parameter_list|,
name|struct
name|listen_port
modifier|*
name|ports
parameter_list|,
name|size_t
name|bufsize
parameter_list|,
name|int
name|tcp_accept_count
parameter_list|,
name|void
modifier|*
name|sslctx
parameter_list|,
name|comm_point_callback_t
modifier|*
name|cb
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * delete the listening structure  * @param listen: listening structure.  */
end_comment

begin_function_decl
name|void
name|listen_delete
parameter_list|(
name|struct
name|listen_dnsport
modifier|*
name|listen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * delete listen_list of commpoints. Calls commpointdelete() on items.  * This may close the fds or not depending on flags.  * @param list: to delete.  */
end_comment

begin_function_decl
name|void
name|listen_list_delete
parameter_list|(
name|struct
name|listen_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * get memory size used by the listening structs  * @param listen: listening structure.  * @return: size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|listen_get_mem
parameter_list|(
name|struct
name|listen_dnsport
modifier|*
name|listen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * stop accept handlers for TCP (until enabled again)  * @param listen: listening structure.  */
end_comment

begin_function_decl
name|void
name|listen_stop_accept
parameter_list|(
name|struct
name|listen_dnsport
modifier|*
name|listen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * start accept handlers for TCP (was stopped before)  * @param listen: listening structure.  */
end_comment

begin_function_decl
name|void
name|listen_start_accept
parameter_list|(
name|struct
name|listen_dnsport
modifier|*
name|listen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and bind nonblocking UDP socket  * @param family: for socket call.  * @param socktype: for socket call.  * @param addr: for bind call.  * @param addrlen: for bind call.  * @param v6only: if enabled, IP6 sockets get IP6ONLY option set.  * 	if enabled with value 2 IP6ONLY option is disabled.  * @param inuse: on error, this is set true if the port was in use.  * @param noproto: on error, this is set true if cause is that the 	IPv6 proto (family) is not available.  * @param rcv: set size on rcvbuf with socket option, if 0 it is not set.  * @param snd: set size on sndbuf with socket option, if 0 it is not set.  * @param listen: if true, this is a listening UDP port, eg port 53, and   * 	set SO_REUSEADDR on it.  * @param reuseport: if nonNULL and true, try to set SO_REUSEPORT on  * 	listening UDP port.  Set to false on return if it failed to do so.  * @return: the socket. -1 on error.  */
end_comment

begin_function_decl
name|int
name|create_udp_sock
parameter_list|(
name|int
name|family
parameter_list|,
name|int
name|socktype
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|int
name|v6only
parameter_list|,
name|int
modifier|*
name|inuse
parameter_list|,
name|int
modifier|*
name|noproto
parameter_list|,
name|int
name|rcv
parameter_list|,
name|int
name|snd
parameter_list|,
name|int
name|listen
parameter_list|,
name|int
modifier|*
name|reuseport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and bind TCP listening socket  * @param addr: address info ready to make socket.  * @param v6only: enable ip6 only flag on ip6 sockets.  * @param noproto: if error caused by lack of protocol support.  * @param reuseport: if nonNULL and true, try to set SO_REUSEPORT on  * 	listening UDP port.  Set to false on return if it failed to do so.  * @return: the socket. -1 on error.  */
end_comment

begin_function_decl
name|int
name|create_tcp_accept_sock
parameter_list|(
name|struct
name|addrinfo
modifier|*
name|addr
parameter_list|,
name|int
name|v6only
parameter_list|,
name|int
modifier|*
name|noproto
parameter_list|,
name|int
modifier|*
name|reuseport
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LISTEN_DNSPORT_H */
end_comment

end_unit

