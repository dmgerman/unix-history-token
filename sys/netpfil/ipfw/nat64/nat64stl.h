begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Yandex LLC  * Copyright (c) 2015-2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_FW_NAT64STL_H_
end_ifndef

begin_define
define|#
directive|define
name|_IP_FW_NAT64STL_H_
end_define

begin_struct
struct|struct
name|nat64stl_cfg
block|{
name|struct
name|named_object
name|no
decl_stmt|;
name|uint16_t
name|map64
decl_stmt|;
comment|/* table with 6to4 mapping */
name|uint16_t
name|map46
decl_stmt|;
comment|/* table with 4to6 mapping */
name|struct
name|in6_addr
name|prefix6
decl_stmt|;
comment|/* IPv6 prefix */
name|uint8_t
name|plen6
decl_stmt|;
comment|/* prefix length */
name|uint8_t
name|flags
decl_stmt|;
comment|/* flags for internal use */
define|#
directive|define
name|NAT64STL_KIDX
value|0x0100
define|#
directive|define
name|NAT64STL_46T
value|0x0200
define|#
directive|define
name|NAT64STL_64T
value|0x0400
define|#
directive|define
name|NAT64STL_FLAGSMASK
value|(NAT64_LOG)
comment|/* flags to pass to userland */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|nat64_stats_block
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|uint16_t
argument_list|,
name|nat64stl_eid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_nat64stl_eid
value|VNET(nat64stl_eid)
end_define

begin_define
define|#
directive|define
name|IPFW_TLV_NAT64STL_NAME
value|IPFW_TLV_EACTION_NAME(V_nat64stl_eid)
end_define

begin_function_decl
name|int
name|ipfw_nat64stl
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|chain
parameter_list|,
name|struct
name|ip_fw_args
modifier|*
name|args
parameter_list|,
name|ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

