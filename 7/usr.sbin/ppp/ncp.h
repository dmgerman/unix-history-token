begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
name|ncp
block|{
struct|struct
block|{
name|u_long
name|sendpipe
decl_stmt|;
comment|/* route sendpipe size */
name|u_long
name|recvpipe
decl_stmt|;
comment|/* route recvpipe size */
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
block|}
name|cfg
struct|;
name|int
name|afq
decl_stmt|;
comment|/* Next address family to queue */
name|struct
name|sticky_route
modifier|*
name|route
decl_stmt|;
comment|/* List of dynamic routes */
name|struct
name|ipcp
name|ipcp
decl_stmt|;
comment|/* Our IPCP FSM */
ifndef|#
directive|ifndef
name|NOINET6
name|struct
name|ipv6cp
name|ipv6cp
decl_stmt|;
comment|/* Our IPV6CP FSM */
endif|#
directive|endif
name|struct
name|mp
name|mp
decl_stmt|;
comment|/* Our MP */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|ncp_Init
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_Destroy
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ncp_fsmStart
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_IfaceAddrAdded
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
specifier|const
name|struct
name|iface_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_IfaceAddrDeleted
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
specifier|const
name|struct
name|iface_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_SetLink
parameter_list|(
name|struct
name|ncp
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
name|void
name|ncp_Enqueue
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_DeleteQueues
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ncp_QueueLen
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ncp_FillPhysicalQueues
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ncp_PushPacket
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|,
name|int
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
name|ncp_IsUrgentPort
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
name|ncp_AddUrgentPort
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
name|ncp_RemoveUrgentPort
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
name|ncp_ClearUrgentPorts
parameter_list|(
name|struct
name|port_range
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ncp_Show
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
name|int
name|ncp_LayersOpen
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ncp_LayersUnfinished
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp_Close
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ncp2initial
parameter_list|(
name|struct
name|ncp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ncp_IsUrgentTcpPort
parameter_list|(
name|ncp
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|ncp_IsUrgentPort(&(ncp)->cfg.urgent.tcp, p1, p2)
end_define

begin_define
define|#
directive|define
name|ncp_IsUrgentUdpPort
parameter_list|(
name|ncp
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|ncp_IsUrgentPort(&(ncp)->cfg.urgent.udp, p1, p2)
end_define

begin_define
define|#
directive|define
name|ncp_AddUrgentTcpPort
parameter_list|(
name|ncp
parameter_list|,
name|p
parameter_list|)
define|\
value|ncp_AddUrgentPort(&(ncp)->cfg.urgent.tcp, p)
end_define

begin_define
define|#
directive|define
name|ncp_AddUrgentUdpPort
parameter_list|(
name|ncp
parameter_list|,
name|p
parameter_list|)
define|\
value|ncp_AddUrgentPort(&(ncp)->cfg.urgent.udp, p)
end_define

begin_define
define|#
directive|define
name|ncp_RemoveUrgentTcpPort
parameter_list|(
name|ncp
parameter_list|,
name|p
parameter_list|)
define|\
value|ncp_RemoveUrgentPort(&(ncp)->cfg.urgent.tcp, p)
end_define

begin_define
define|#
directive|define
name|ncp_RemoveUrgentUdpPort
parameter_list|(
name|ncp
parameter_list|,
name|p
parameter_list|)
define|\
value|ncp_RemoveUrgentPort(&(ncp)->cfg.urgent.udp, p)
end_define

begin_define
define|#
directive|define
name|ncp_ClearUrgentTcpPorts
parameter_list|(
name|ncp
parameter_list|)
define|\
value|ncp_ClearUrgentPorts(&(ncp)->cfg.urgent.tcp)
end_define

begin_define
define|#
directive|define
name|ncp_ClearUrgentUdpPorts
parameter_list|(
name|ncp
parameter_list|)
define|\
value|ncp_ClearUrgentPorts(&(ncp)->cfg.urgent.udp)
end_define

begin_define
define|#
directive|define
name|ncp_ClearUrgentTOS
parameter_list|(
name|ncp
parameter_list|)
value|(ncp)->cfg.urgent.tos = 0;
end_define

begin_define
define|#
directive|define
name|ncp_SetUrgentTOS
parameter_list|(
name|ncp
parameter_list|)
value|(ncp)->cfg.urgent.tos = 1;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOINET6
end_ifndef

begin_define
define|#
directive|define
name|isncp
parameter_list|(
name|proto
parameter_list|)
value|((proto) == PROTO_IPCP || (proto) == PROTO_IPV6CP)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isncp
parameter_list|(
name|proto
parameter_list|)
value|((proto) == PROTO_IPCP)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

