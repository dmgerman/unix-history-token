begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	 $SourceForge: netflow.h,v 1.8 2004/09/16 17:05:11 glebius Exp $  *	 $FreeBSD$  */
end_comment

begin_comment
comment|/* netflow timeouts in seconds */
end_comment

begin_define
define|#
directive|define
name|ACTIVE_TIMEOUT
value|(30*60)
end_define

begin_comment
comment|/* maximum flow lifetime is 30 min */
end_comment

begin_define
define|#
directive|define
name|INACTIVE_TIMEOUT
value|15
end_define

begin_comment
comment|/*  * More info can be found in these Cisco documents:  *  * Cisco IOS NetFlow, White Papers.  * http://www.cisco.com/en/US/products/ps6601/prod_white_papers_list.html  *  * Cisco CNS NetFlow Collection Engine User Guide, 5.0.2, NetFlow Export  * Datagram Formats.  * http://www.cisco.com/en/US/products/sw/netmgtsw/ps1964/products_user_guide_chapter09186a00803f3147.html#wp26453  *  */
end_comment

begin_define
define|#
directive|define
name|NETFLOW_V1
value|1
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5
value|5
end_define

begin_struct
struct|struct
name|netflow_v1_header
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NetFlow version */
name|uint16_t
name|count
decl_stmt|;
comment|/* Number of records in flow */
name|uint32_t
name|sys_uptime
decl_stmt|;
comment|/* System uptime */
name|uint32_t
name|unix_secs
decl_stmt|;
comment|/* Current seconds since 0000 UTC 1970 */
name|uint32_t
name|unix_nsecs
decl_stmt|;
comment|/* Remaining nanoseconds since 0000 UTC 1970 */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|netflow_v5_header
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* NetFlow version */
name|uint16_t
name|count
decl_stmt|;
comment|/* Number of records in flow */
name|uint32_t
name|sys_uptime
decl_stmt|;
comment|/* System uptime */
name|uint32_t
name|unix_secs
decl_stmt|;
comment|/* Current seconds since 0000 UTC 1970 */
name|uint32_t
name|unix_nsecs
decl_stmt|;
comment|/* Remaining nanoseconds since 0000 UTC 1970 */
name|uint32_t
name|flow_seq
decl_stmt|;
comment|/* Sequence number of the first record */
name|uint8_t
name|engine_type
decl_stmt|;
comment|/* Type of flow switching engine (RP,VIP,etc.) */
name|uint8_t
name|engine_id
decl_stmt|;
comment|/* Slot number of the flow switching engine */
name|uint16_t
name|pad
decl_stmt|;
comment|/* Pad to word boundary */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|netflow_v1_record
block|{
name|uint32_t
name|src_addr
decl_stmt|;
comment|/* Source IP address */
name|uint32_t
name|dst_addr
decl_stmt|;
comment|/* Destination IP address */
name|uint32_t
name|next_hop
decl_stmt|;
comment|/* Next hop IP address */
name|uint16_t
name|in_ifx
decl_stmt|;
comment|/* Source interface index */
name|uint16_t
name|out_ifx
decl_stmt|;
comment|/* Destination interface index */
name|uint32_t
name|packets
decl_stmt|;
comment|/* Number of packets in a flow */
name|uint32_t
name|octets
decl_stmt|;
comment|/* Number of octets in a flow */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port */
name|uint16_t
name|pad1
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags */
name|uint8_t
name|pad2
decl_stmt|;
comment|/* Pad to word boundary */
name|uint16_t
name|pad3
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|reserved
index|[
literal|5
index|]
decl_stmt|;
comment|/* Reserved for future use */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|netflow_v5_record
block|{
name|uint32_t
name|src_addr
decl_stmt|;
comment|/* Source IP address */
name|uint32_t
name|dst_addr
decl_stmt|;
comment|/* Destination IP address */
name|uint32_t
name|next_hop
decl_stmt|;
comment|/* Next hop IP address */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* Source interface index */
name|uint16_t
name|o_ifx
decl_stmt|;
comment|/* Destination interface index */
name|uint32_t
name|packets
decl_stmt|;
comment|/* Number of packets in a flow */
name|uint32_t
name|octets
decl_stmt|;
comment|/* Number of octets in a flow */
name|uint32_t
name|first
decl_stmt|;
comment|/* System uptime at start of a flow */
name|uint32_t
name|last
decl_stmt|;
comment|/* System uptime at end of a flow */
name|uint16_t
name|s_port
decl_stmt|;
comment|/* Source port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* Destination port */
name|uint8_t
name|pad1
decl_stmt|;
comment|/* Pad to word boundary */
name|uint8_t
name|flags
decl_stmt|;
comment|/* Cumulative OR of tcp flags */
name|uint8_t
name|prot
decl_stmt|;
comment|/* IP protocol */
name|uint8_t
name|tos
decl_stmt|;
comment|/* IP type of service */
name|uint16_t
name|src_as
decl_stmt|;
comment|/* Src peer/origin Autonomous System */
name|uint16_t
name|dst_as
decl_stmt|;
comment|/* Dst peer/origin Autonomous System */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* Source route's mask bits */
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* Destination route's mask bits */
name|uint16_t
name|pad2
decl_stmt|;
comment|/* Pad to word boundary */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|NETFLOW_V1_MAX_RECORDS
value|24
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5_MAX_RECORDS
value|30
end_define

begin_define
define|#
directive|define
name|NETFLOW_V1_MAX_SIZE
value|(sizeof(netflow_v1_header)+ \ 			     sizeof(netflow_v1_record)*NETFLOW_V1_MAX_RECORDS)
end_define

begin_define
define|#
directive|define
name|NETFLOW_V5_MAX_SIZE
value|(sizeof(netflow_v5_header)+ \ 			     sizeof(netflow_v5_record)*NETFLOW_V5_MAX_RECORDS)
end_define

end_unit

