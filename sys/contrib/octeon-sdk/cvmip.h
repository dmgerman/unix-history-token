begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Cavium Inc. Internet Protocol (IP)  *  * Definitions for the Internet Protocol (IP) support.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMIP_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMIP_H__
end_define

begin_comment
comment|/*  * IP protocol values (1 byte)  *  */
end_comment

begin_define
define|#
directive|define
name|CVMIP_PROTO_ICMP
value|1
end_define

begin_comment
comment|/* Internet Control Message Protocol */
end_comment

begin_define
define|#
directive|define
name|CVMIP_PROTO_TCP
value|6
end_define

begin_comment
comment|/* Transmission Control Protocol */
end_comment

begin_define
define|#
directive|define
name|CVMIP_PROTO_UDP
value|17
end_define

begin_comment
comment|/* User Datagram Protocol */
end_comment

begin_define
define|#
directive|define
name|CVMIP_PROTO_ESP
value|50
end_define

begin_comment
comment|/* Encapsulated Security Payload */
end_comment

begin_define
define|#
directive|define
name|CVMIP_PROTO_AH
value|51
end_define

begin_comment
comment|/* Authentication Header */
end_comment

begin_comment
comment|/**  * network packet header definitions  * (originally from octane_hw.h)  *  */
end_comment

begin_comment
comment|/**  * UDP Packet header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|int32_t
name|s32
decl_stmt|;
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|src_prt
decl_stmt|;
name|uint16_t
name|dst_prt
decl_stmt|;
block|}
name|s
struct|;
block|}
name|prts
union|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|chksum
decl_stmt|;
block|}
name|cvmip_udp_hdr_t
typedef|;
end_typedef

begin_comment
comment|/**  * TCP Packet header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|src_prt
decl_stmt|;
name|uint16_t
name|dst_prt
decl_stmt|;
name|uint32_t
name|seq
decl_stmt|;
name|uint32_t
name|ack_seq
decl_stmt|;
name|uint32_t
name|hlen
range|:
literal|4
decl_stmt|;
name|uint32_t
name|rsvd
range|:
literal|6
decl_stmt|;
name|uint32_t
name|urg
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ack
range|:
literal|1
decl_stmt|;
name|uint32_t
name|psh
range|:
literal|1
decl_stmt|;
name|uint32_t
name|rst
range|:
literal|1
decl_stmt|;
name|uint32_t
name|syn
range|:
literal|1
decl_stmt|;
name|uint32_t
name|fin
range|:
literal|1
decl_stmt|;
name|uint16_t
name|win_sz
decl_stmt|;
name|uint16_t
name|chksum
decl_stmt|;
name|uint16_t
name|urg_ptr
decl_stmt|;
name|uint32_t
name|junk
decl_stmt|;
block|}
name|cvmip_tcp_hdr_t
typedef|;
end_typedef

begin_comment
comment|/**  * L4 Packet header  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|cvmip_udp_hdr_t
name|udphdr
decl_stmt|;
name|cvmip_tcp_hdr_t
name|tcphdr
decl_stmt|;
struct|struct
block|{
union|union
block|{
name|int32_t
name|s32
decl_stmt|;
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|src_prt
decl_stmt|;
name|uint16_t
name|dst_prt
decl_stmt|;
block|}
name|s
struct|;
block|}
name|prts
union|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|chksum
decl_stmt|;
name|char
name|dat
index|[
literal|48
index|]
decl_stmt|;
comment|// 48 for IPv6 with no extension hdrs, 64 for IPv4 without options
block|}
name|udp
struct|;
struct|struct
block|{
name|uint16_t
name|src_prt
decl_stmt|;
name|uint16_t
name|dst_prt
decl_stmt|;
name|uint32_t
name|seq
decl_stmt|;
name|uint32_t
name|ack_seq
decl_stmt|;
name|uint32_t
name|hlen
range|:
literal|4
decl_stmt|;
name|uint32_t
name|rsvd
range|:
literal|6
decl_stmt|;
name|uint32_t
name|urg
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ack
range|:
literal|1
decl_stmt|;
name|uint32_t
name|psh
range|:
literal|1
decl_stmt|;
name|uint32_t
name|rst
range|:
literal|1
decl_stmt|;
name|uint32_t
name|syn
range|:
literal|1
decl_stmt|;
name|uint32_t
name|fin
range|:
literal|1
decl_stmt|;
name|uint16_t
name|win_sz
decl_stmt|;
name|uint16_t
name|chksum
decl_stmt|;
name|uint16_t
name|urg_ptr
decl_stmt|;
name|char
name|dat
index|[
literal|36
index|]
decl_stmt|;
comment|// 36 for IPv6 with no extension hdrs, 52 for IPv6 without options
block|}
name|tcp
struct|;
block|}
name|cvmip_l4_info_t
typedef|;
end_typedef

begin_comment
comment|/**  * Special struct to add a pad to IPv4 header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|pad
decl_stmt|;
name|uint32_t
name|version
range|:
literal|4
decl_stmt|;
name|uint32_t
name|hl
range|:
literal|4
decl_stmt|;
name|uint8_t
name|tos
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|uint32_t
name|mbz
range|:
literal|1
decl_stmt|;
name|uint32_t
name|df
range|:
literal|1
decl_stmt|;
name|uint32_t
name|mf
range|:
literal|1
decl_stmt|;
name|uint32_t
name|off
range|:
literal|13
decl_stmt|;
name|uint8_t
name|ttl
decl_stmt|;
name|uint8_t
name|protocol
decl_stmt|;
name|uint16_t
name|chksum
decl_stmt|;
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|src
decl_stmt|;
name|uint32_t
name|dst
decl_stmt|;
block|}
name|s
struct|;
block|}
name|src_dst
union|;
block|}
name|cvmip_ipv4_hdr_t
typedef|;
end_typedef

begin_comment
comment|/**  * IPv6 Packet header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|version
range|:
literal|4
decl_stmt|;
name|uint32_t
name|v6class
range|:
literal|8
decl_stmt|;
name|uint32_t
name|flow
range|:
literal|20
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
comment|// includes extension headers plus payload (add 40 to be equiv to v4 len field)
name|uint8_t
name|next_hdr
decl_stmt|;
comment|// equivalent to the v4 protocol field
name|uint8_t
name|hop_lim
decl_stmt|;
comment|// equivalent to the v4 TTL field
union|union
block|{
name|uint64_t
name|u64
index|[
literal|4
index|]
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|src
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|dst
index|[
literal|2
index|]
decl_stmt|;
block|}
name|s
struct|;
block|}
name|src_dst
union|;
block|}
name|cvmip_ipv6_hdr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMIP_H__ */
end_comment

end_unit

