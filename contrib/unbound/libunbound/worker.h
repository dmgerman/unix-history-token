begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libunbound/worker.h - prototypes for worker methods.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file declares the methods any worker has to implement.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBUNBOUND_WORKER_H
end_ifndef

begin_define
define|#
directive|define
name|LIBUNBOUND_WORKER_H
end_define

begin_include
include|#
directive|include
file|"ldns/sbuffer.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_comment
comment|/* for enum sec_status */
end_comment

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Worker service routine to send serviced queries to authoritative servers.  * @param qname: query name. (host order)  * @param qnamelen: length in bytes of qname, including trailing 0.  * @param qtype: query type. (host order)  * @param qclass: query class. (host order)  * @param flags: host order flags word, with opcode and CD bit.  * @param dnssec: if set, EDNS record will have DO bit set.  * @param want_dnssec: signatures needed.  * @param addr: where to.  * @param addrlen: length of addr.  * @param zone: delegation point name.  * @param zonelen: length of zone name wireformat dname.  * @param q: wich query state to reactivate upon return.  * @return: false on failure (memory or socket related). no query was  *      sent.  */
end_comment

begin_function_decl
name|struct
name|outbound_entry
modifier|*
name|libworker_send_query
parameter_list|(
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
name|struct
name|module_qstate
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** process incoming replies from the network */
end_comment

begin_function_decl
name|int
name|libworker_handle_reply
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
comment|/** process incoming serviced query replies from the network */
end_comment

begin_function_decl
name|int
name|libworker_handle_service_reply
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
comment|/** handle control command coming into server */
end_comment

begin_function_decl
name|void
name|libworker_handle_control_cmd
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|uint8_t
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|err
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** mesh callback with fg results */
end_comment

begin_function_decl
name|void
name|libworker_fg_done_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|rcode
parameter_list|,
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|enum
name|sec_status
name|s
parameter_list|,
name|char
modifier|*
name|why_bogus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** mesh callback with bg results */
end_comment

begin_function_decl
name|void
name|libworker_bg_done_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|rcode
parameter_list|,
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|enum
name|sec_status
name|s
parameter_list|,
name|char
modifier|*
name|why_bogus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** mesh callback with event results */
end_comment

begin_function_decl
name|void
name|libworker_event_done_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|rcode
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|enum
name|sec_status
name|s
parameter_list|,
name|char
modifier|*
name|why_bogus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Worker signal handler function. User argument is the worker itself.  * @param sig: signal number.  * @param arg: the worker (main worker) that handles signals.  */
end_comment

begin_function_decl
name|void
name|worker_sighandler
parameter_list|(
name|int
name|sig
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Worker service routine to send serviced queries to authoritative servers.  * @param qname: query name. (host order)  * @param qnamelen: length in bytes of qname, including trailing 0.  * @param qtype: query type. (host order)  * @param qclass: query class. (host order)  * @param flags: host order flags word, with opcode and CD bit.  * @param dnssec: if set, EDNS record will have DO bit set.  * @param want_dnssec: signatures needed.  * @param addr: where to.  * @param addrlen: length of addr.  * @param zone: wireformat dname of the zone.  * @param zonelen: length of zone name.  * @param q: wich query state to reactivate upon return.  * @return: false on failure (memory or socket related). no query was  *      sent.  */
end_comment

begin_function_decl
name|struct
name|outbound_entry
modifier|*
name|worker_send_query
parameter_list|(
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
name|struct
name|module_qstate
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * process control messages from the main thread. Frees the control   * command message.  * @param tube: tube control message came on.  * @param msg: message contents.  Is freed.  * @param len: length of message.  * @param error: if error (NETEVENT_*) happened.  * @param arg: user argument  */
end_comment

begin_function_decl
name|void
name|worker_handle_control_cmd
parameter_list|(
name|struct
name|tube
modifier|*
name|tube
parameter_list|,
name|uint8_t
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|error
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** handles callbacks from listening event interface */
end_comment

begin_function_decl
name|int
name|worker_handle_request
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
name|repinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** process incoming replies from the network */
end_comment

begin_function_decl
name|int
name|worker_handle_reply
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
comment|/** process incoming serviced query replies from the network */
end_comment

begin_function_decl
name|int
name|worker_handle_service_reply
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
comment|/** cleanup the cache to remove all rrset IDs from it, arg is worker */
end_comment

begin_function_decl
name|void
name|worker_alloc_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** statistics timer callback handler */
end_comment

begin_function_decl
name|void
name|worker_stat_timer_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** probe timer callback handler */
end_comment

begin_function_decl
name|void
name|worker_probe_timer_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** start accept callback handler */
end_comment

begin_function_decl
name|void
name|worker_start_accept
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** stop accept callback handler */
end_comment

begin_function_decl
name|void
name|worker_stop_accept
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** handle remote control accept callbacks */
end_comment

begin_function_decl
name|int
name|remote_accept_callback
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
end_function_decl

begin_comment
comment|/** handle remote control data callbacks */
end_comment

begin_function_decl
name|int
name|remote_control_callback
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
end_function_decl

begin_comment
comment|/** routine to printout option values over SSL */
end_comment

begin_function_decl
name|void
name|remote_get_opt_ssl
parameter_list|(
name|char
modifier|*
name|line
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBUNBOUND_WORKER_H */
end_comment

end_unit

