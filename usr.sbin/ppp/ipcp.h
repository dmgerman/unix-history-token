begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|IPCP_MAXCODE
value|CODE_CODEREJ
end_define

begin_define
define|#
directive|define
name|TY_IPADDRS
value|1
end_define

begin_define
define|#
directive|define
name|TY_COMPPROTO
value|2
end_define

begin_define
define|#
directive|define
name|TY_IPADDR
value|3
end_define

begin_comment
comment|/* Domain NameServer and NetBIOS NameServer options */
end_comment

begin_define
define|#
directive|define
name|TY_PRIMARY_DNS
value|129
end_define

begin_define
define|#
directive|define
name|TY_PRIMARY_NBNS
value|130
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_DNS
value|131
end_define

begin_define
define|#
directive|define
name|TY_SECONDARY_NBNS
value|132
end_define

begin_define
define|#
directive|define
name|TY_ADJUST_NS
value|119
end_define

begin_comment
comment|/* subtract from NS val for REJECT bit */
end_comment

begin_struct_decl
struct_decl|struct
name|sticky_route
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|in_range
block|{
name|struct
name|in_addr
name|ipaddr
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
name|int
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|port_range
block|{
name|unsigned
name|nports
decl_stmt|;
comment|/* How many ports */
name|unsigned
name|maxports
decl_stmt|;
comment|/* How many allocated (malloc) ports */
name|u_short
modifier|*
name|port
decl_stmt|;
comment|/* The actual ports */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipcp
block|{
name|struct
name|fsm
name|fsm
decl_stmt|;
comment|/* The finite state machine */
struct|struct
block|{
struct|struct
block|{
name|int
name|slots
decl_stmt|;
comment|/* Maximum VJ slots */
name|unsigned
name|slotcomp
range|:
literal|1
decl_stmt|;
comment|/* Slot compression */
name|unsigned
name|neg
range|:
literal|2
decl_stmt|;
comment|/* VJ negotiation */
block|}
name|vj
struct|;
name|struct
name|in_range
name|my_range
decl_stmt|;
comment|/* MYADDR spec */
name|struct
name|in_addr
name|netmask
decl_stmt|;
comment|/* Iface netmask (unused by most OSs) */
name|struct
name|in_range
name|peer_range
decl_stmt|;
comment|/* HISADDR spec */
name|struct
name|iplist
name|peer_list
decl_stmt|;
comment|/* Ranges of HISADDR values */
name|u_long
name|sendpipe
decl_stmt|;
comment|/* route sendpipe size */
name|u_long
name|recvpipe
decl_stmt|;
comment|/* route recvpipe size */
name|struct
name|in_addr
name|TriggerAddress
decl_stmt|;
comment|/* Address to suggest in REQ */
name|unsigned
name|HaveTriggerAddress
range|:
literal|1
decl_stmt|;
comment|/* Trigger address specified */
struct|struct
block|{
name|struct
name|in_addr
name|dns
index|[
literal|2
index|]
decl_stmt|;
comment|/* DNS addresses offered */
name|unsigned
name|dns_neg
range|:
literal|2
decl_stmt|;
comment|/* dns negotiation */
name|struct
name|in_addr
name|nbns
index|[
literal|2
index|]
decl_stmt|;
comment|/* NetBIOS NS addresses offered */
block|}
name|ns
struct|;
struct|struct
block|{
name|struct
name|port_range
name|tcp
decl_stmt|,
name|udp
decl_stmt|;
comment|/* The range of urgent ports */
name|unsigned
name|tos
range|:
literal|1
decl_stmt|;
comment|/* Urgent IPTOS_LOWDELAY packets ? */
block|}
name|urgent
struct|;
name|struct
name|fsm_retry
name|fsm
decl_stmt|;
comment|/* How often/frequently to resend requests */
block|}
name|cfg
struct|;
struct|struct
block|{
name|struct
name|slcompress
name|cslc
decl_stmt|;
comment|/* VJ state */
name|struct
name|slstat
name|slstat
decl_stmt|;
comment|/* VJ statistics */
block|}
name|vj
struct|;
struct|struct
block|{
name|unsigned
name|resolver
range|:
literal|1
decl_stmt|;
comment|/* Found resolv.conf ? */
name|unsigned
name|writable
range|:
literal|1
decl_stmt|;
comment|/* Can write resolv.conf ? */
name|struct
name|in_addr
name|dns
index|[
literal|2
index|]
decl_stmt|;
comment|/* Current DNS addresses */
name|char
modifier|*
name|resolv
decl_stmt|;
comment|/* Contents of resolv.conf */
name|char
modifier|*
name|resolv_nons
decl_stmt|;
comment|/* Contents of resolv.conf without ns */
block|}
name|ns
struct|;
name|struct
name|sticky_route
modifier|*
name|route
decl_stmt|;
comment|/* List of dynamic routes */
name|unsigned
name|heis1172
range|:
literal|1
decl_stmt|;
comment|/* True if he is speaking rfc1172 */
name|unsigned
name|peer_req
range|:
literal|1
decl_stmt|;
comment|/* Any TY_IPADDR REQs from the peer ? */
name|struct
name|in_addr
name|peer_ip
decl_stmt|;
comment|/* IP address he's willing to use */
name|u_int32_t
name|peer_compproto
decl_stmt|;
comment|/* VJ params he's willing to use */
name|struct
name|in_addr
name|ifmask
decl_stmt|;
comment|/* Interface netmask */
name|struct
name|in_addr
name|my_ip
decl_stmt|;
comment|/* IP address I'm willing to use */
name|u_int32_t
name|my_compproto
decl_stmt|;
comment|/* VJ params I'm willing to use */
name|struct
name|in_addr
name|dns
index|[
literal|2
index|]
decl_stmt|;
comment|/* DNSs to REQ/ACK */
name|u_int32_t
name|peer_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_int32_t
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|struct
name|pppThroughput
name|throughput
decl_stmt|;
comment|/* throughput statistics */
name|struct
name|mqueue
name|Queue
index|[
literal|3
index|]
decl_stmt|;
comment|/* Output packet queues */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fsm2ipcp
parameter_list|(
name|fp
parameter_list|)
value|(fp->proto == PROTO_IPCP ? (struct ipcp *)fp : NULL)
end_define

begin_define
define|#
directive|define
name|IPCP_QUEUES
parameter_list|(
name|ipcp
parameter_list|)
value|(sizeof ipcp->Queue / sizeof ipcp->Queue[0])
end_define

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_Init
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_parent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_Destroy
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_Setup
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_SetLink
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_Show
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|ipcp_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_AddInOctets
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_AddOutOctets
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_UseHisIPaddr
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_UseHisaddr
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_vjset
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_CleanInterface
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_InterfaceUp
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_IsUrgentPort
parameter_list|(
name|struct
name|port_range
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_AddUrgentPort
parameter_list|(
name|struct
name|port_range
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_RemoveUrgentPort
parameter_list|(
name|struct
name|port_range
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_ClearUrgentPorts
parameter_list|(
name|struct
name|port_range
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|in_addr
name|addr2mask
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipcp_WriteDNS
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_RestoreDNS
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipcp_LoadDNS
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ipcp_IsUrgentTcpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|ipcp_IsUrgentPort(&(ipcp)->cfg.urgent.tcp, p1, p2)
end_define

begin_define
define|#
directive|define
name|ipcp_IsUrgentUdpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|ipcp_IsUrgentPort(&(ipcp)->cfg.urgent.udp, p1, p2)
end_define

begin_define
define|#
directive|define
name|ipcp_AddUrgentTcpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p
parameter_list|)
define|\
value|ipcp_AddUrgentPort(&(ipcp)->cfg.urgent.tcp, p)
end_define

begin_define
define|#
directive|define
name|ipcp_AddUrgentUdpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p
parameter_list|)
define|\
value|ipcp_AddUrgentPort(&(ipcp)->cfg.urgent.udp, p)
end_define

begin_define
define|#
directive|define
name|ipcp_RemoveUrgentTcpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p
parameter_list|)
define|\
value|ipcp_RemoveUrgentPort(&(ipcp)->cfg.urgent.tcp, p)
end_define

begin_define
define|#
directive|define
name|ipcp_RemoveUrgentUdpPort
parameter_list|(
name|ipcp
parameter_list|,
name|p
parameter_list|)
define|\
value|ipcp_RemoveUrgentPort(&(ipcp)->cfg.urgent.udp, p)
end_define

begin_define
define|#
directive|define
name|ipcp_ClearUrgentTcpPorts
parameter_list|(
name|ipcp
parameter_list|)
define|\
value|ipcp_ClearUrgentPorts(&(ipcp)->cfg.urgent.tcp)
end_define

begin_define
define|#
directive|define
name|ipcp_ClearUrgentUdpPorts
parameter_list|(
name|ipcp
parameter_list|)
define|\
value|ipcp_ClearUrgentPorts(&(ipcp)->cfg.urgent.udp)
end_define

begin_define
define|#
directive|define
name|ipcp_ClearUrgentTOS
parameter_list|(
name|ipcp
parameter_list|)
value|(ipcp)->cfg.urgent.tos = 0;
end_define

begin_define
define|#
directive|define
name|ipcp_SetUrgentTOS
parameter_list|(
name|ipcp
parameter_list|)
value|(ipcp)->cfg.urgent.tos = 1;
end_define

end_unit

