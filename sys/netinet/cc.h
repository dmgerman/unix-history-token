begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008  * 	Swinburne University of Technology, Melbourne, Australia.  * Copyright (c) 2009-2010 Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed at the Centre for Advanced Internet  * Architectures, Swinburne University of Technology, by Lawrence Stewart and  * James Healy, made possible in part by a grant from the Cisco University  * Research Program Fund at Community Foundation Silicon Valley.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by David Hayes under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This software was first released in 2007 by James Healy and Lawrence Stewart  * whilst working on the NewTCP research project at Swinburne University of  * Technology's Centre for Advanced Internet Architectures, Melbourne,  * Australia, which was made possible in part by a grant from the Cisco  * University Research Program Fund at Community Foundation Silicon Valley.  * More details are available at:  *   http://caia.swin.edu.au/urp/newtcp/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_CC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_CC_H_
end_define

begin_comment
comment|/* XXX: TCP_CA_NAME_MAX define lives in tcp.h for compat reasons. */
end_comment

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_comment
comment|/* Global CC vars. */
end_comment

begin_extern
extern|extern STAILQ_HEAD(cc_head
operator|,
extern|cc_algo
end_extern

begin_expr_stmt
unit|)
name|cc_list
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|tcprexmtthresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cc_algo
name|newreno_cc_algo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Per-netstack bits. */
end_comment

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|cc_algo
operator|*
argument_list|,
name|default_cc_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_default_cc_ptr
value|VNET(default_cc_ptr)
end_define

begin_comment
comment|/* Define the new net.inet.tcp.cc sysctl tree. */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp_cc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* CC housekeeping functions. */
end_comment

begin_function_decl
name|int
name|cc_register_algo
parameter_list|(
name|struct
name|cc_algo
modifier|*
name|add_cc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cc_deregister_algo
parameter_list|(
name|struct
name|cc_algo
modifier|*
name|remove_cc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wrapper around transport structs that contain same-named congestion  * control variables. Allows algos to be shared amongst multiple CC aware  * transprots.  */
end_comment

begin_struct
struct|struct
name|cc_var
block|{
name|void
modifier|*
name|cc_data
decl_stmt|;
comment|/* Per-connection private CC algorithm data. */
name|int
name|bytes_this_ack
decl_stmt|;
comment|/* # bytes acked by the current ACK. */
name|tcp_seq
name|curack
decl_stmt|;
comment|/* Most recent ACK. */
name|uint32_t
name|flags
decl_stmt|;
comment|/* Flags for cc_var (see below) */
name|int
name|type
decl_stmt|;
comment|/* Indicates which ptr is valid in ccvc. */
union|union
name|ccv_container
block|{
name|struct
name|tcpcb
modifier|*
name|tcp
decl_stmt|;
name|struct
name|sctp_nets
modifier|*
name|sctp
decl_stmt|;
block|}
name|ccvc
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* cc_var flags. */
end_comment

begin_define
define|#
directive|define
name|CCF_ABC_SENTAWND
value|0x0001
end_define

begin_comment
comment|/* ABC counted cwnd worth of bytes? */
end_comment

begin_define
define|#
directive|define
name|CCF_CWND_LIMITED
value|0x0002
end_define

begin_comment
comment|/* Are we currently cwnd limited? */
end_comment

begin_define
define|#
directive|define
name|CCF_DELACK
value|0x0004
end_define

begin_comment
comment|/* Is this ack delayed? */
end_comment

begin_define
define|#
directive|define
name|CCF_ACKNOW
value|0x0008
end_define

begin_comment
comment|/* Will this ack be sent now? */
end_comment

begin_define
define|#
directive|define
name|CCF_IPHDR_CE
value|0x0010
end_define

begin_comment
comment|/* Does this packet set CE bit? */
end_comment

begin_define
define|#
directive|define
name|CCF_TCPHDR_CWR
value|0x0020
end_define

begin_comment
comment|/* Does this packet set CWR bit? */
end_comment

begin_comment
comment|/* ACK types passed to the ack_received() hook. */
end_comment

begin_define
define|#
directive|define
name|CC_ACK
value|0x0001
end_define

begin_comment
comment|/* Regular in sequence ACK. */
end_comment

begin_define
define|#
directive|define
name|CC_DUPACK
value|0x0002
end_define

begin_comment
comment|/* Duplicate ACK. */
end_comment

begin_define
define|#
directive|define
name|CC_PARTIALACK
value|0x0004
end_define

begin_comment
comment|/* Not yet. */
end_comment

begin_define
define|#
directive|define
name|CC_SACK
value|0x0008
end_define

begin_comment
comment|/* Not yet. */
end_comment

begin_comment
comment|/*  * Congestion signal types passed to the cong_signal() hook. The highest order 8  * bits (0x01000000 - 0x80000000) are reserved for CC algos to declare their own  * congestion signal types.  */
end_comment

begin_define
define|#
directive|define
name|CC_ECN
value|0x00000001
end_define

begin_comment
comment|/* ECN marked packet received. */
end_comment

begin_define
define|#
directive|define
name|CC_RTO
value|0x00000002
end_define

begin_comment
comment|/* RTO fired. */
end_comment

begin_define
define|#
directive|define
name|CC_RTO_ERR
value|0x00000004
end_define

begin_comment
comment|/* RTO fired in error. */
end_comment

begin_define
define|#
directive|define
name|CC_NDUPACK
value|0x00000008
end_define

begin_comment
comment|/* Threshold of dupack's reached. */
end_comment

begin_define
define|#
directive|define
name|CC_SIGPRIVMASK
value|0xFF000000
end_define

begin_comment
comment|/* Mask to check if sig is private. */
end_comment

begin_comment
comment|/*  * Structure to hold data and function pointers that together represent a  * congestion control algorithm.  */
end_comment

begin_struct
struct|struct
name|cc_algo
block|{
name|char
name|name
index|[
name|TCP_CA_NAME_MAX
index|]
decl_stmt|;
comment|/* Init global module state on kldload. */
name|int
function_decl|(
modifier|*
name|mod_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Cleanup global module state on kldunload. */
name|int
function_decl|(
modifier|*
name|mod_destroy
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Init CC state for a new control block. */
name|int
function_decl|(
modifier|*
name|cb_init
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
comment|/* Cleanup CC state for a terminating control block. */
name|void
function_decl|(
modifier|*
name|cb_destroy
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
comment|/* Init variables for a newly established connection. */
name|void
function_decl|(
modifier|*
name|conn_init
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
comment|/* Called on receipt of an ack. */
name|void
function_decl|(
modifier|*
name|ack_received
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|,
name|uint16_t
name|type
parameter_list|)
function_decl|;
comment|/* Called on detection of a congestion signal. */
name|void
function_decl|(
modifier|*
name|cong_signal
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|,
name|uint32_t
name|type
parameter_list|)
function_decl|;
comment|/* Called after exiting congestion recovery. */
name|void
function_decl|(
modifier|*
name|post_recovery
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
comment|/* Called when data transfer resumes after an idle period. */
name|void
function_decl|(
modifier|*
name|after_idle
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
comment|/* Called for an additional ECN processing apart from RFC3168. */
name|void
function_decl|(
modifier|*
name|ecnpkt_handler
function_decl|)
parameter_list|(
name|struct
name|cc_var
modifier|*
name|ccv
parameter_list|)
function_decl|;
name|STAILQ_ENTRY
argument_list|(
argument|cc_algo
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macro to obtain the CC algo's struct ptr. */
end_comment

begin_define
define|#
directive|define
name|CC_ALGO
parameter_list|(
name|tp
parameter_list|)
value|((tp)->cc_algo)
end_define

begin_comment
comment|/* Macro to obtain the CC algo's data ptr. */
end_comment

begin_define
define|#
directive|define
name|CC_DATA
parameter_list|(
name|tp
parameter_list|)
value|((tp)->ccv->cc_data)
end_define

begin_comment
comment|/* Macro to obtain the system default CC algo's struct ptr. */
end_comment

begin_define
define|#
directive|define
name|CC_DEFAULT
parameter_list|()
value|V_default_cc_ptr
end_define

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|cc_list_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CC_LIST_LOCK_INIT
parameter_list|()
value|rw_init(&cc_list_lock, "cc_list")
end_define

begin_define
define|#
directive|define
name|CC_LIST_LOCK_DESTROY
parameter_list|()
value|rw_destroy(&cc_list_lock)
end_define

begin_define
define|#
directive|define
name|CC_LIST_RLOCK
parameter_list|()
value|rw_rlock(&cc_list_lock)
end_define

begin_define
define|#
directive|define
name|CC_LIST_RUNLOCK
parameter_list|()
value|rw_runlock(&cc_list_lock)
end_define

begin_define
define|#
directive|define
name|CC_LIST_WLOCK
parameter_list|()
value|rw_wlock(&cc_list_lock)
end_define

begin_define
define|#
directive|define
name|CC_LIST_WUNLOCK
parameter_list|()
value|rw_wunlock(&cc_list_lock)
end_define

begin_define
define|#
directive|define
name|CC_LIST_LOCK_ASSERT
parameter_list|()
value|rw_assert(&cc_list_lock, RA_LOCKED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_CC_H_ */
end_comment

end_unit

