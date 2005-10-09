begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOINET6
end_ifndef

begin_define
define|#
directive|define
name|IPV6CP_MAXCODE
value|CODE_CODEREJ
end_define

begin_define
define|#
directive|define
name|TY_TOKEN
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
name|IPV6CP_IFIDLEN
value|8
end_define

begin_comment
comment|/* RFC2472 */
end_comment

begin_struct
struct|struct
name|ipv6cp
block|{
name|struct
name|fsm
name|fsm
decl_stmt|;
comment|/* The finite state machine */
struct|struct
block|{
name|struct
name|fsm_retry
name|fsm
decl_stmt|;
comment|/* frequency to resend requests */
block|}
name|cfg
struct|;
name|unsigned
name|peer_tokenreq
range|:
literal|1
decl_stmt|;
comment|/* Any TY_TOKEN REQs from the peer ? */
name|u_char
name|my_ifid
index|[
name|IPV6CP_IFIDLEN
index|]
decl_stmt|;
comment|/* Local Interface Identifier */
name|u_char
name|his_ifid
index|[
name|IPV6CP_IFIDLEN
index|]
decl_stmt|;
comment|/* Peer Interface Identifier */
name|struct
name|ncpaddr
name|myaddr
decl_stmt|;
comment|/* Local address */
name|struct
name|ncpaddr
name|hisaddr
decl_stmt|;
comment|/* Peer address */
name|u_int32_t
name|his_reject
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
literal|2
index|]
decl_stmt|;
comment|/* Output packet queues */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fsm2ipv6cp
parameter_list|(
name|fp
parameter_list|)
value|(fp->proto == PROTO_IPV6CP ? (struct ipv6cp *)fp : NULL)
end_define

begin_define
define|#
directive|define
name|IPV6CP_QUEUES
parameter_list|(
name|ipv6cp
parameter_list|)
value|(sizeof ipv6cp->Queue / sizeof ipv6cp->Queue[0])
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

begin_struct_decl
struct_decl|struct
name|iface_addr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ipv6cp_Init
parameter_list|(
name|struct
name|ipv6cp
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
name|ipv6cp_Destroy
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipv6cp_Setup
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipv6cp_SetLink
parameter_list|(
name|struct
name|ipv6cp
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
name|ipv6cp_Show
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
name|ipv6cp_Input
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
name|ipv6cp_AddInOctets
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipv6cp_AddOutOctets
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ipv6cp_IfaceAddrAdded
parameter_list|(
name|struct
name|ipv6cp
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
name|ipv6cp_IfaceAddrDeleted
parameter_list|(
name|struct
name|ipv6cp
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
name|int
name|ipv6cp_InterfaceUp
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ipv6cp_QueueLen
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipv6cp_PushPacket
parameter_list|(
name|struct
name|ipv6cp
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

