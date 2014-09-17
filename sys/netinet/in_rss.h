begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Juniper Networks, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson under contract  * to Juniper Networks, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_RSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_RSS_H_
end_define

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* in_addr_t */
end_comment

begin_comment
comment|/*  * Supported RSS hash functions.  */
end_comment

begin_define
define|#
directive|define
name|RSS_HASH_NAIVE
value|0x00000001
end_define

begin_comment
comment|/* Poor but fast hash. */
end_comment

begin_define
define|#
directive|define
name|RSS_HASH_TOEPLITZ
value|0x00000002
end_define

begin_comment
comment|/* Required by RSS. */
end_comment

begin_define
define|#
directive|define
name|RSS_HASH_CRC32
value|0x00000004
end_define

begin_comment
comment|/* Future; some NICs do it. */
end_comment

begin_define
define|#
directive|define
name|RSS_HASH_MASK
value|(RSS_HASH_NAIVE | RSS_HASH_TOEPLITZ)
end_define

begin_comment
comment|/*  * Instances of struct inpcbinfo declare an RSS hash type indicating what  * header fields are covered.  */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHFIELDS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RSS_HASHFIELDS_4TUPLE
value|1
end_define

begin_define
define|#
directive|define
name|RSS_HASHFIELDS_2TUPLE
value|2
end_define

begin_comment
comment|/*  * Define RSS representations of the M_HASHTYPE_* values, representing  * which particular bits are supported.  The NICs can then use this to  * calculate which hash types to enable and which not to enable.  *  * The fact that these line up with M_HASHTYPE_* is not to be relied  * upon.  */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_IPV4
value|(1<< 1)
end_define

begin_comment
comment|/* IPv4 2-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_TCP_IPV4
value|(1<< 2)
end_define

begin_comment
comment|/* TCPv4 4-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_IPV6
value|(1<< 3)
end_define

begin_comment
comment|/* IPv6 2-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_TCP_IPV6
value|(1<< 4)
end_define

begin_comment
comment|/* TCPv6 4-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_IPV6_EX
value|(1<< 5)
end_define

begin_comment
comment|/* IPv6 2-tuple + ext hdrs */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_TCP_IPV6_EX
value|(1<< 6)
end_define

begin_comment
comment|/* TCPv6 4-tiple + ext hdrs */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_UDP_IPV4
value|(1<< 7)
end_define

begin_comment
comment|/* IPv4 UDP 4-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_UDP_IPV4_EX
value|(1<< 8)
end_define

begin_comment
comment|/* IPv4 UDP 4-tuple + ext hdrs */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_UDP_IPV6
value|(1<< 9)
end_define

begin_comment
comment|/* IPv6 UDP 4-tuple */
end_comment

begin_define
define|#
directive|define
name|RSS_HASHTYPE_RSS_UDP_IPV6_EX
value|(1<< 10)
end_define

begin_comment
comment|/* IPv6 UDP 4-tuple + ext hdrs */
end_comment

begin_comment
comment|/*  * Compile-time limits on the size of the indirection table.  */
end_comment

begin_define
define|#
directive|define
name|RSS_MAXBITS
value|7
end_define

begin_define
define|#
directive|define
name|RSS_TABLE_MAXLEN
value|(1<< RSS_MAXBITS)
end_define

begin_comment
comment|/*  * Maximum key size used throughout.  It's OK for hardware to use only the  * first 16 bytes, which is all that's required for IPv4.  */
end_comment

begin_define
define|#
directive|define
name|RSS_KEYSIZE
value|40
end_define

begin_comment
comment|/*  * For RSS hash methods that do a software hash on an mbuf, the packet  * direction (ingress / egress) is required.  *  * The default direction (INGRESS) is the "receive into the NIC" - ie,  * what the hardware is hashing on.  */
end_comment

begin_define
define|#
directive|define
name|RSS_HASH_PKT_INGRESS
value|0
end_define

begin_define
define|#
directive|define
name|RSS_HASH_PKT_EGRESS
value|1
end_define

begin_comment
comment|/*  * Device driver interfaces to query RSS properties that must be programmed  * into hardware.  */
end_comment

begin_function_decl
name|u_int
name|rss_getbits
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_getbucket
parameter_list|(
name|u_int
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_get_indirection_to_bucket
parameter_list|(
name|u_int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_getcpu
parameter_list|(
name|u_int
name|bucket
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rss_getkey
parameter_list|(
name|uint8_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_gethashalgo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_getnumbuckets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_getnumcpus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_gethashconfig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Network stack interface to generate a hash for a protocol tuple.  */
end_comment

begin_function_decl
name|uint32_t
name|rss_hash_ip4_4tuple
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|u_short
name|srcport
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|,
name|u_short
name|dstport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|rss_hash_ip4_2tuple
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|rss_hash_ip6_4tuple
parameter_list|(
name|struct
name|in6_addr
name|src
parameter_list|,
name|u_short
name|srcport
parameter_list|,
name|struct
name|in6_addr
name|dst
parameter_list|,
name|u_short
name|dstport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|rss_hash_ip6_2tuple
parameter_list|(
name|struct
name|in6_addr
name|src
parameter_list|,
name|struct
name|in6_addr
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Network stack interface to query desired CPU affinity of a packet.  */
end_comment

begin_function_decl
name|struct
name|mbuf
modifier|*
name|rss_m2cpuid
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|u_int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rss_hash2cpuid
parameter_list|(
name|uint32_t
name|hash_val
parameter_list|,
name|uint32_t
name|hash_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rss_hash2bucket
parameter_list|(
name|uint32_t
name|hash_val
parameter_list|,
name|uint32_t
name|hash_type
parameter_list|,
name|uint32_t
modifier|*
name|bucket_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rss_m2bucket
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
modifier|*
name|bucket_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to calculate a software RSS hash for a given mbuf or  * packet detail.  */
end_comment

begin_function_decl
name|int
name|rss_mbuf_software_hash_v4
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|dir
parameter_list|,
name|uint32_t
modifier|*
name|hashval
parameter_list|,
name|uint32_t
modifier|*
name|hashtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rss_proto_software_hash_v4
parameter_list|(
name|struct
name|in_addr
name|src
parameter_list|,
name|struct
name|in_addr
name|dst
parameter_list|,
name|u_short
name|src_port
parameter_list|,
name|u_short
name|dst_port
parameter_list|,
name|int
name|proto
parameter_list|,
name|uint32_t
modifier|*
name|hashval
parameter_list|,
name|uint32_t
modifier|*
name|hashtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|rss_soft_m2cpuid
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uintptr_t
name|source
parameter_list|,
name|u_int
modifier|*
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_IN_RSS_H_ */
end_comment

end_unit

