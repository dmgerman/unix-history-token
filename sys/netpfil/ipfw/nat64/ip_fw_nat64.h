begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Yandex LLC  * Copyright (c) 2015-2016 Andrey V. Elsukov<ae@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_FW_NAT64_H_
end_ifndef

begin_define
define|#
directive|define
name|_IP_FW_NAT64_H_
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|mask
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if (nat64_debug& (mask))	\ 	printf("NAT64: %s: " fmt "\n", __func__, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DP_GENERIC
value|0x0001
end_define

begin_define
define|#
directive|define
name|DP_OBJ
value|0x0002
end_define

begin_define
define|#
directive|define
name|DP_JQUEUE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DP_STATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|DP_DROPS
value|0x0010
end_define

begin_define
define|#
directive|define
name|DP_ALL
value|0xFFFF
end_define

begin_decl_stmt
specifier|extern
name|int
name|nat64_debug
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|NAT64NOINLINE
value|__noinline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NAT64NOINLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|nat64stl_init
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64stl_uninit
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nat64lsn_init
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nat64lsn_uninit
parameter_list|(
name|struct
name|ip_fw_chain
modifier|*
name|ch
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ip_fw_nat64_stats
block|{
name|counter_u64_t
name|opcnt64
decl_stmt|;
comment|/* 6to4 of packets translated */
name|counter_u64_t
name|opcnt46
decl_stmt|;
comment|/* 4to6 of packets translated */
name|counter_u64_t
name|ofrags
decl_stmt|;
comment|/* number of fragments generated */
name|counter_u64_t
name|ifrags
decl_stmt|;
comment|/* number of fragments received */
name|counter_u64_t
name|oerrors
decl_stmt|;
comment|/* number of output errors */
name|counter_u64_t
name|noroute4
decl_stmt|;
name|counter_u64_t
name|noroute6
decl_stmt|;
name|counter_u64_t
name|nomatch4
decl_stmt|;
comment|/* No addr/port match */
name|counter_u64_t
name|noproto
decl_stmt|;
comment|/* Protocol not supported */
name|counter_u64_t
name|nomem
decl_stmt|;
comment|/* mbufs allocation failed */
name|counter_u64_t
name|dropped
decl_stmt|;
comment|/* number of packets silently 					 * dropped due to some errors/ 					 * unsupported/etc. 					 */
name|counter_u64_t
name|jrequests
decl_stmt|;
comment|/* number of jobs requests queued */
name|counter_u64_t
name|jcalls
decl_stmt|;
comment|/* number of jobs handler calls */
name|counter_u64_t
name|jhostsreq
decl_stmt|;
comment|/* number of hosts requests */
name|counter_u64_t
name|jportreq
decl_stmt|;
name|counter_u64_t
name|jhostfails
decl_stmt|;
name|counter_u64_t
name|jportfails
decl_stmt|;
name|counter_u64_t
name|jmaxlen
decl_stmt|;
name|counter_u64_t
name|jnomem
decl_stmt|;
name|counter_u64_t
name|jreinjected
decl_stmt|;
name|counter_u64_t
name|screated
decl_stmt|;
name|counter_u64_t
name|sdeleted
decl_stmt|;
name|counter_u64_t
name|spgcreated
decl_stmt|;
name|counter_u64_t
name|spgdeleted
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPFW_NAT64_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NAT64STATS
value|(sizeof(struct ip_fw_nat64_stats) / sizeof(uint64_t))
end_define

begin_typedef
typedef|typedef
struct|struct
name|_nat64_stats_block
block|{
name|counter_u64_t
name|stats
index|[
name|NAT64STATS
index|]
decl_stmt|;
block|}
name|nat64_stats_block
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NAT64STAT_ADD
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|counter_u64_add((s)->stats[		\ 	offsetof(struct ip_fw_nat64_stats, f) / sizeof(uint64_t)], (v))
end_define

begin_define
define|#
directive|define
name|NAT64STAT_INC
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|NAT64STAT_ADD(s, f, 1)
end_define

begin_define
define|#
directive|define
name|NAT64STAT_FETCH
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|counter_u64_fetch((s)->stats[	\ 	offsetof(struct ip_fw_nat64_stats, f) / sizeof(uint64_t)])
end_define

begin_define
define|#
directive|define
name|L3HDR
parameter_list|(
name|_ip
parameter_list|,
name|_t
parameter_list|)
value|((_t)((u_int32_t *)(_ip) + (_ip)->ip_hl))
end_define

begin_define
define|#
directive|define
name|TCP
parameter_list|(
name|p
parameter_list|)
value|((struct tcphdr *)(p))
end_define

begin_define
define|#
directive|define
name|UDP
parameter_list|(
name|p
parameter_list|)
value|((struct udphdr *)(p))
end_define

begin_define
define|#
directive|define
name|ICMP
parameter_list|(
name|p
parameter_list|)
value|((struct icmphdr *)(p))
end_define

begin_define
define|#
directive|define
name|ICMP6
parameter_list|(
name|p
parameter_list|)
value|((struct icmp6_hdr *)(p))
end_define

begin_define
define|#
directive|define
name|NAT64SKIP
value|0
end_define

begin_define
define|#
directive|define
name|NAT64RETURN
value|1
end_define

begin_define
define|#
directive|define
name|NAT64MFREE
value|-1
end_define

begin_comment
comment|/* Well-known prefix 64:ff9b::/96 */
end_comment

begin_define
define|#
directive|define
name|IPV6_ADDR_INT32_WKPFX
value|htonl(0x64ff9b)
end_define

begin_define
define|#
directive|define
name|IN6_IS_ADDR_WKPFX
parameter_list|(
name|a
parameter_list|)
define|\
value|((a)->s6_addr32[0] == IPV6_ADDR_INT32_WKPFX&& \ 	(a)->s6_addr32[1] == 0&& (a)->s6_addr32[2] == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

