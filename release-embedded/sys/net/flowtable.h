begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2008-2010, BitGravity Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the BitGravity Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_FLOWTABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_FLOWTABLE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|FL_HASH_ALL
value|(1<<0)
end_define

begin_comment
comment|/* hash 4-tuple + protocol */
end_comment

begin_define
define|#
directive|define
name|FL_PCPU
value|(1<<1)
end_define

begin_comment
comment|/* pcpu cache */
end_comment

begin_define
define|#
directive|define
name|FL_NOAUTO
value|(1<<2)
end_define

begin_comment
comment|/* don't automatically add flentry on miss */
end_comment

begin_define
define|#
directive|define
name|FL_IPV6
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FL_TCP
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FL_SCTP
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|FL_UDP
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FL_DEBUG
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|FL_DEBUG_ALL
value|(1<<15)
end_define

begin_struct_decl
struct_decl|struct
name|flowtable
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|flentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|route_in6
struct_decl|;
end_struct_decl

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|flowtable
operator|*
argument_list|,
name|ip_ft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ip_ft
value|VNET(ip_ft)
end_define

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|flowtable
operator|*
argument_list|,
name|ip6_ft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ip6_ft
value|VNET(ip6_ft)
end_define

begin_function_decl
name|struct
name|flowtable
modifier|*
name|flowtable_alloc
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|nentry
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given a flow table, look up the L3 and L2 information and  * return it in the route.  *  */
end_comment

begin_function_decl
name|struct
name|flentry
modifier|*
name|flowtable_lookup_mbuf
parameter_list|(
name|struct
name|flowtable
modifier|*
name|ft
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|flentry
modifier|*
name|flowtable_lookup
parameter_list|(
name|struct
name|flowtable
modifier|*
name|ft
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|ssa
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|dsa
parameter_list|,
name|uint32_t
name|fibnum
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_flowtable_insert
parameter_list|(
name|struct
name|flowtable
modifier|*
name|ft
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|ssa
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|dsa
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|uint32_t
name|fibnum
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flow_invalidate
parameter_list|(
name|struct
name|flentry
modifier|*
name|fl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flowtable_route_flush
parameter_list|(
name|struct
name|flowtable
modifier|*
name|ft
parameter_list|,
name|struct
name|rtentry
modifier|*
name|rt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flow_to_route
parameter_list|(
name|struct
name|flentry
modifier|*
name|fl
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flow_to_route_in6
parameter_list|(
name|struct
name|flentry
modifier|*
name|fl
parameter_list|,
name|struct
name|route_in6
modifier|*
name|ro
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

