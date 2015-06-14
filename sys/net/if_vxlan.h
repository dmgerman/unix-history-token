begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014, Bryan Venteicher<bryanv@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_VXLAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_VXLAN_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_struct
struct|struct
name|vxlan_header
block|{
name|uint32_t
name|vxlh_flags
decl_stmt|;
name|uint32_t
name|vxlh_vni
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VXLAN_HDR_FLAGS_VALID_VNI
value|0x08000000
end_define

begin_define
define|#
directive|define
name|VXLAN_HDR_VNI_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|VXLAN_VNI_MAX
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|VXLAN_VNI_MASK
value|(VXLAN_VNI_MAX - 1)
end_define

begin_comment
comment|/*  * The port assigned by IANA is 4789, but some early implementations  * (like Linux) use 8472 instead. If not specified, we default to  * the IANA port.  */
end_comment

begin_define
define|#
directive|define
name|VXLAN_PORT
value|4789
end_define

begin_define
define|#
directive|define
name|VXLAN_LEGACY_PORT
value|8472
end_define

begin_struct
struct|struct
name|ifvxlanparam
block|{
name|uint64_t
name|vxlp_with
decl_stmt|;
define|#
directive|define
name|VXLAN_PARAM_WITH_VNI
value|0x0001
define|#
directive|define
name|VXLAN_PARAM_WITH_LOCAL_ADDR4
value|0x0002
define|#
directive|define
name|VXLAN_PARAM_WITH_LOCAL_ADDR6
value|0x0004
define|#
directive|define
name|VXLAN_PARAM_WITH_REMOTE_ADDR4
value|0x0008
define|#
directive|define
name|VXLAN_PARAM_WITH_REMOTE_ADDR6
value|0x0010
define|#
directive|define
name|VXLAN_PARAM_WITH_LOCAL_PORT
value|0x0020
define|#
directive|define
name|VXLAN_PARAM_WITH_REMOTE_PORT
value|0x0040
define|#
directive|define
name|VXLAN_PARAM_WITH_PORT_RANGE
value|0x0080
define|#
directive|define
name|VXLAN_PARAM_WITH_FTABLE_TIMEOUT
value|0x0100
define|#
directive|define
name|VXLAN_PARAM_WITH_FTABLE_MAX
value|0x0200
define|#
directive|define
name|VXLAN_PARAM_WITH_MULTICAST_IF
value|0x0400
define|#
directive|define
name|VXLAN_PARAM_WITH_TTL
value|0x0800
define|#
directive|define
name|VXLAN_PARAM_WITH_LEARN
value|0x1000
name|uint32_t
name|vxlp_vni
decl_stmt|;
name|struct
name|in_addr
name|vxlp_local_in4
decl_stmt|;
name|struct
name|in6_addr
name|vxlp_local_in6
decl_stmt|;
name|struct
name|in_addr
name|vxlp_remote_in4
decl_stmt|;
name|struct
name|in6_addr
name|vxlp_remote_in6
decl_stmt|;
name|uint16_t
name|vxlp_local_port
decl_stmt|;
name|uint16_t
name|vxlp_remote_port
decl_stmt|;
name|uint16_t
name|vxlp_min_port
decl_stmt|;
name|uint16_t
name|vxlp_max_port
decl_stmt|;
name|char
name|vxlp_mc_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|uint32_t
name|vxlp_ftable_timeout
decl_stmt|;
name|uint32_t
name|vxlp_ftable_max
decl_stmt|;
name|uint8_t
name|vxlp_ttl
decl_stmt|;
name|uint8_t
name|vxlp_learn
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|vxlan_sockaddr
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|in4
decl_stmt|;
name|struct
name|sockaddr_in6
name|in6
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|VXLAN_SOCKADDR_IS_IPV4
parameter_list|(
name|_vxsin
parameter_list|)
value|((_vxsin)->sa.sa_family == AF_INET)
end_define

begin_define
define|#
directive|define
name|VXLAN_SOCKADDR_IS_IPV6
parameter_list|(
name|_vxsin
parameter_list|)
value|((_vxsin)->sa.sa_family == AF_INET6)
end_define

begin_define
define|#
directive|define
name|VXLAN_SOCKADDR_IS_IPV46
parameter_list|(
name|_vxsin
parameter_list|)
define|\
value|(VXLAN_SOCKADDR_IS_IPV4(_vxsin) || VXLAN_SOCKADDR_IS_IPV6(_vxsin))
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_GET_CONFIG
value|0
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_VNI
value|1
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_LOCAL_ADDR
value|2
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_REMOTE_ADDR
value|4
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_LOCAL_PORT
value|5
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_REMOTE_PORT
value|6
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_PORT_RANGE
value|7
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_FTABLE_TIMEOUT
value|8
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_FTABLE_MAX
value|9
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_MULTICAST_IF
value|10
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_TTL
value|11
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_SET_LEARN
value|12
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_FTABLE_ENTRY_ADD
value|13
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_FTABLE_ENTRY_REM
value|14
end_define

begin_define
define|#
directive|define
name|VXLAN_CMD_FLUSH
value|15
end_define

begin_struct
struct|struct
name|ifvxlancfg
block|{
name|uint32_t
name|vxlc_vni
decl_stmt|;
name|union
name|vxlan_sockaddr
name|vxlc_local_sa
decl_stmt|;
name|union
name|vxlan_sockaddr
name|vxlc_remote_sa
decl_stmt|;
name|uint32_t
name|vxlc_mc_ifindex
decl_stmt|;
name|uint32_t
name|vxlc_ftable_cnt
decl_stmt|;
name|uint32_t
name|vxlc_ftable_max
decl_stmt|;
name|uint32_t
name|vxlc_ftable_timeout
decl_stmt|;
name|uint16_t
name|vxlc_port_min
decl_stmt|;
name|uint16_t
name|vxlc_port_max
decl_stmt|;
name|uint8_t
name|vxlc_learn
decl_stmt|;
name|uint8_t
name|vxlc_ttl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifvxlancmd
block|{
name|uint32_t
name|vxlcmd_flags
decl_stmt|;
define|#
directive|define
name|VXLAN_CMD_FLAG_FLUSH_ALL
value|0x0001
define|#
directive|define
name|VXLAN_CMD_FLAG_LEARN
value|0x0002
name|uint32_t
name|vxlcmd_vni
decl_stmt|;
name|uint32_t
name|vxlcmd_ftable_timeout
decl_stmt|;
name|uint32_t
name|vxlcmd_ftable_max
decl_stmt|;
name|uint16_t
name|vxlcmd_port
decl_stmt|;
name|uint16_t
name|vxlcmd_port_min
decl_stmt|;
name|uint16_t
name|vxlcmd_port_max
decl_stmt|;
name|uint8_t
name|vxlcmd_mac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|vxlcmd_ttl
decl_stmt|;
name|union
name|vxlan_sockaddr
name|vxlcmd_sa
decl_stmt|;
name|char
name|vxlcmd_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_VXLAN_H_ */
end_comment

end_unit

