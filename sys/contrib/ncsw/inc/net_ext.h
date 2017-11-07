begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          net_ext.h   @Description   This file contains common and general netcomm headers definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NET_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__NET_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldPpp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPP_PID
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPP_COMPRESSED
value|(NET_HEADER_FIELD_PPP_PID<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPP_ALL_FIELDS
value|((NET_HEADER_FIELD_PPP_PID<< 2) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldPppoe_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_VER
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_TYPE
value|(NET_HEADER_FIELD_PPPoE_VER<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_CODE
value|(NET_HEADER_FIELD_PPPoE_VER<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_SID
value|(NET_HEADER_FIELD_PPPoE_VER<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_LEN
value|(NET_HEADER_FIELD_PPPoE_VER<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_SESSION
value|(NET_HEADER_FIELD_PPPoE_VER<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_PID
value|(NET_HEADER_FIELD_PPPoE_VER<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPoE_ALL_FIELDS
value|((NET_HEADER_FIELD_PPPoE_VER<< 7) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_PID
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_CKSUM
value|(NET_HEADER_FIELD_PPPMUX_PID<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_COMPRESSED
value|(NET_HEADER_FIELD_PPPMUX_PID<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_ALL_FIELDS
value|((NET_HEADER_FIELD_PPPMUX_PID<< 3) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_LXT
value|(NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_LEN
value|(NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_PID
value|(NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_USE_PID
value|(NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PPPMUX_SUBFRAME_ALL_FIELDS
value|((NET_HEADER_FIELD_PPPMUX_SUBFRAME_PFF<< 5) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldEth_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_DA
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_SA
value|(NET_HEADER_FIELD_ETH_DA<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_LENGTH
value|(NET_HEADER_FIELD_ETH_DA<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_TYPE
value|(NET_HEADER_FIELD_ETH_DA<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_FINAL_CKSUM
value|(NET_HEADER_FIELD_ETH_DA<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_PADDING
value|(NET_HEADER_FIELD_ETH_DA<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_ALL_FIELDS
value|((NET_HEADER_FIELD_ETH_DA<< 6) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ETH_ADDR_SIZE
value|6
end_define

begin_typedef
typedef|typedef
name|uint16_t
name|headerFieldIp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IP_VER
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IP_DSCP
value|(NET_HEADER_FIELD_IP_VER<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IP_ECN
value|(NET_HEADER_FIELD_IP_VER<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IP_PROTO
value|(NET_HEADER_FIELD_IP_VER<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IP_PROTO_SIZE
value|1
end_define

begin_typedef
typedef|typedef
name|uint16_t
name|headerFieldIpv4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_VER
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_HDR_LEN
value|(NET_HEADER_FIELD_IPv4_VER<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_TOS
value|(NET_HEADER_FIELD_IPv4_VER<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_TOTAL_LEN
value|(NET_HEADER_FIELD_IPv4_VER<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_ID
value|(NET_HEADER_FIELD_IPv4_VER<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_FLAG_D
value|(NET_HEADER_FIELD_IPv4_VER<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_FLAG_M
value|(NET_HEADER_FIELD_IPv4_VER<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_OFFSET
value|(NET_HEADER_FIELD_IPv4_VER<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_TTL
value|(NET_HEADER_FIELD_IPv4_VER<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_PROTO
value|(NET_HEADER_FIELD_IPv4_VER<< 9)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_CKSUM
value|(NET_HEADER_FIELD_IPv4_VER<< 10)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_SRC_IP
value|(NET_HEADER_FIELD_IPv4_VER<< 11)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_DST_IP
value|(NET_HEADER_FIELD_IPv4_VER<< 12)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_OPTS
value|(NET_HEADER_FIELD_IPv4_VER<< 13)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_OPTS_COUNT
value|(NET_HEADER_FIELD_IPv4_VER<< 14)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_ALL_FIELDS
value|((NET_HEADER_FIELD_IPv4_VER<< 15) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_ADDR_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv4_PROTO_SIZE
value|1
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldIpv6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_VER
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_TC
value|(NET_HEADER_FIELD_IPv6_VER<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_SRC_IP
value|(NET_HEADER_FIELD_IPv6_VER<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_DST_IP
value|(NET_HEADER_FIELD_IPv6_VER<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_NEXT_HDR
value|(NET_HEADER_FIELD_IPv6_VER<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_FL
value|(NET_HEADER_FIELD_IPv6_VER<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_HOP_LIMIT
value|(NET_HEADER_FIELD_IPv6_VER<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_ALL_FIELDS
value|((NET_HEADER_FIELD_IPv6_VER<< 7) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_ADDR_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPv6_NEXT_HDR_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_TYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_CODE
value|(NET_HEADER_FIELD_ICMP_TYPE<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_CKSUM
value|(NET_HEADER_FIELD_ICMP_TYPE<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_ID
value|(NET_HEADER_FIELD_ICMP_TYPE<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_SQ_NUM
value|(NET_HEADER_FIELD_ICMP_TYPE<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_ALL_FIELDS
value|((NET_HEADER_FIELD_ICMP_TYPE<< 5) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_CODE_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ICMP_TYPE_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IGMP_VERSION
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IGMP_TYPE
value|(NET_HEADER_FIELD_IGMP_VERSION<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IGMP_CKSUM
value|(NET_HEADER_FIELD_IGMP_VERSION<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IGMP_DATA
value|(NET_HEADER_FIELD_IGMP_VERSION<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IGMP_ALL_FIELDS
value|((NET_HEADER_FIELD_IGMP_VERSION<< 4) - 1)
end_define

begin_typedef
typedef|typedef
name|uint16_t
name|headerFieldTcp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_PORT_DST
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_SEQ
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_ACK
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_OFFSET
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_FLAGS
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_WINDOW
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_CKSUM
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_URGPTR
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_OPTS
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 9)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_OPTS_COUNT
value|(NET_HEADER_FIELD_TCP_PORT_SRC<< 10)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_ALL_FIELDS
value|((NET_HEADER_FIELD_TCP_PORT_SRC<< 11) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_TCP_PORT_SIZE
value|2
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldSctp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_PORT_DST
value|(NET_HEADER_FIELD_SCTP_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_VER_TAG
value|(NET_HEADER_FIELD_SCTP_PORT_SRC<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CKSUM
value|(NET_HEADER_FIELD_SCTP_PORT_SRC<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_ALL_FIELDS
value|((NET_HEADER_FIELD_SCTP_PORT_SRC<< 4) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_PORT_SIZE
value|2
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldDccp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_DCCP_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_DCCP_PORT_DST
value|(NET_HEADER_FIELD_DCCP_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_DCCP_ALL_FIELDS
value|((NET_HEADER_FIELD_DCCP_PORT_SRC<< 2) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_DCCP_PORT_SIZE
value|2
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldUdp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_PORT_DST
value|(NET_HEADER_FIELD_UDP_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_LEN
value|(NET_HEADER_FIELD_UDP_PORT_SRC<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_CKSUM
value|(NET_HEADER_FIELD_UDP_PORT_SRC<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ALL_FIELDS
value|((NET_HEADER_FIELD_UDP_PORT_SRC<< 4) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_PORT_SIZE
value|2
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldUdpLite_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_LITE_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_LITE_PORT_DST
value|(NET_HEADER_FIELD_UDP_LITE_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_LITE_ALL_FIELDS
value|((NET_HEADER_FIELD_UDP_LITE_PORT_SRC<< 2) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_LITE_PORT_SIZE
value|2
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldUdpEncapEsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_DST
value|(NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_LEN
value|(NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_CKSUM
value|(NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_SPI
value|(NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_SEQUENCE_NUM
value|(NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_ALL_FIELDS
value|((NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SRC<< 6) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_PORT_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_UDP_ENCAP_ESP_SPI_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_CID
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_CID_TYPE
value|(NET_HEADER_FIELD_IPHC_CID<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_HCINDEX
value|(NET_HEADER_FIELD_IPHC_CID<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_GEN
value|(NET_HEADER_FIELD_IPHC_CID<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_D_BIT
value|(NET_HEADER_FIELD_IPHC_CID<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPHC_ALL_FIELDS
value|((NET_HEADER_FIELD_IPHC_CID<< 5) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_FLAGS
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_LENGTH
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_TSN
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_STREAM_ID
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_STREAM_SQN
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_PAYLOAD_PID
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_UNORDERED
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_BEGGINING
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_END
value|(NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 9)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SCTP_CHUNK_DATA_ALL_FIELDS
value|((NET_HEADER_FIELD_SCTP_CHUNK_DATA_TYPE<< 10) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_TYPE_BIT
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_LENGTH_BIT
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_SEQUENCE_BIT
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_OFFSET_BIT
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_PRIORITY_BIT
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_VERSION
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_LEN
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_TUNNEL_ID
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_SESSION_ID
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_NS
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 9)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_NR
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 10)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_OFFSET_SIZE
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 11)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_FIRST_BYTE
value|(NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 12)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv2_ALL_FIELDS
value|((NET_HEADER_FIELD_L2TPv2_TYPE_BIT<< 13) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_LENGTH_BIT
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_SEQUENCE_BIT
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_VERSION
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_LENGTH
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_CONTROL
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_SENT
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_RECV
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_FIRST_BYTE
value|(NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_CTRL_ALL_FIELDS
value|((NET_HEADER_FIELD_L2TPv3_CTRL_TYPE_BIT<< 9) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_SESS_TYPE_BIT
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_SESS_VERSION
value|(NET_HEADER_FIELD_L2TPv3_SESS_TYPE_BIT<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_SESS_ID
value|(NET_HEADER_FIELD_L2TPv3_SESS_TYPE_BIT<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_SESS_COOKIE
value|(NET_HEADER_FIELD_L2TPv3_SESS_TYPE_BIT<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_L2TPv3_SESS_ALL_FIELDS
value|((NET_HEADER_FIELD_L2TPv3_SESS_TYPE_BIT<< 4) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldVlan_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_VPRI
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_CFI
value|(NET_HEADER_FIELD_VLAN_VPRI<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_VID
value|(NET_HEADER_FIELD_VLAN_VPRI<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_LENGTH
value|(NET_HEADER_FIELD_VLAN_VPRI<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_TYPE
value|(NET_HEADER_FIELD_VLAN_VPRI<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_ALL_FIELDS
value|((NET_HEADER_FIELD_VLAN_VPRI<< 5) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_VLAN_TCI
value|(NET_HEADER_FIELD_VLAN_VPRI | \                                                          NET_HEADER_FIELD_VLAN_CFI | \                                                          NET_HEADER_FIELD_VLAN_VID)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldLlc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_DSAP
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_SSAP
value|(NET_HEADER_FIELD_LLC_DSAP<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_CTRL
value|(NET_HEADER_FIELD_LLC_DSAP<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_ALL_FIELDS
value|((NET_HEADER_FIELD_LLC_DSAP<< 3) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_NLPID_NLPID
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_NLPID_ALL_FIELDS
value|((NET_HEADER_FIELD_NLPID_NLPID<< 1) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldSnap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SNAP_OUI
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SNAP_PID
value|(NET_HEADER_FIELD_SNAP_OUI<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_SNAP_ALL_FIELDS
value|((NET_HEADER_FIELD_SNAP_OUI<< 2) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldLlcSnap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_SNAP_TYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_LLC_SNAP_ALL_FIELDS
value|((NET_HEADER_FIELD_LLC_SNAP_TYPE<< 1) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_HTYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_PTYPE
value|(NET_HEADER_FIELD_ARP_HTYPE<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_HLEN
value|(NET_HEADER_FIELD_ARP_HTYPE<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_PLEN
value|(NET_HEADER_FIELD_ARP_HTYPE<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_OPER
value|(NET_HEADER_FIELD_ARP_HTYPE<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_SHA
value|(NET_HEADER_FIELD_ARP_HTYPE<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_SPA
value|(NET_HEADER_FIELD_ARP_HTYPE<< 6)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_THA
value|(NET_HEADER_FIELD_ARP_HTYPE<< 7)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_TPA
value|(NET_HEADER_FIELD_ARP_HTYPE<< 8)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_ARP_ALL_FIELDS
value|((NET_HEADER_FIELD_ARP_HTYPE<< 9) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_LLC
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_NLPID
value|(NET_HEADER_FIELD_RFC2684_LLC<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_OUI
value|(NET_HEADER_FIELD_RFC2684_LLC<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_PID
value|(NET_HEADER_FIELD_RFC2684_LLC<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_VPN_OUI
value|(NET_HEADER_FIELD_RFC2684_LLC<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_VPN_IDX
value|(NET_HEADER_FIELD_RFC2684_LLC<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_RFC2684_ALL_FIELDS
value|((NET_HEADER_FIELD_RFC2684_LLC<< 6) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_USER_DEFINED_SRCPORT
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_USER_DEFINED_PCDID
value|(NET_HEADER_FIELD_USER_DEFINED_SRCPORT<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_USER_DEFINED_ALL_FIELDS
value|((NET_HEADER_FIELD_USER_DEFINED_SRCPORT<< 2) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PAYLOAD_BUFFER
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PAYLOAD_SIZE
value|(NET_HEADER_FIELD_PAYLOAD_BUFFER<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MAX_FRM_SIZE
value|(NET_HEADER_FIELD_PAYLOAD_BUFFER<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MIN_FRM_SIZE
value|(NET_HEADER_FIELD_PAYLOAD_BUFFER<< 3)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PAYLOAD_TYPE
value|(NET_HEADER_FIELD_PAYLOAD_BUFFER<< 4)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_FRAME_SIZE
value|(NET_HEADER_FIELD_PAYLOAD_BUFFER<< 5)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_PAYLOAD_ALL_FIELDS
value|((NET_HEADER_FIELD_PAYLOAD_BUFFER<< 6) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldGre_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_GRE_TYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_GRE_ALL_FIELDS
value|((NET_HEADER_FIELD_GRE_TYPE<< 1) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldMinencap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MINENCAP_SRC_IP
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MINENCAP_DST_IP
value|(NET_HEADER_FIELD_MINENCAP_SRC_IP<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MINENCAP_TYPE
value|(NET_HEADER_FIELD_MINENCAP_SRC_IP<< 2)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MINENCAP_ALL_FIELDS
value|((NET_HEADER_FIELD_MINENCAP_SRC_IP<< 3) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldIpsecAh_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_AH_SPI
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_AH_NH
value|(NET_HEADER_FIELD_IPSEC_AH_SPI<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_AH_ALL_FIELDS
value|((NET_HEADER_FIELD_IPSEC_AH_SPI<< 2) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldIpsecEsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_ESP_SPI
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_ESP_SEQUENCE_NUM
value|(NET_HEADER_FIELD_IPSEC_ESP_SPI<< 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_ESP_ALL_FIELDS
value|((NET_HEADER_FIELD_IPSEC_ESP_SPI<< 2) - 1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_IPSEC_ESP_SPI_SIZE
value|4
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldMpls_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MPLS_LABEL_STACK
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MPLS_LABEL_STACK_ALL_FIELDS
value|((NET_HEADER_FIELD_MPLS_LABEL_STACK<< 1) - 1)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|headerFieldMacsec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MACSEC_SECTAG
value|(1)
end_define

begin_define
define|#
directive|define
name|NET_HEADER_FIELD_MACSEC_ALL_FIELDS
value|((NET_HEADER_FIELD_MACSEC_SECTAG<< 1) - 1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HEADER_TYPE_NONE
init|=
literal|0
block|,
name|HEADER_TYPE_PAYLOAD
block|,
name|HEADER_TYPE_ETH
block|,
name|HEADER_TYPE_VLAN
block|,
name|HEADER_TYPE_IPv4
block|,
name|HEADER_TYPE_IPv6
block|,
name|HEADER_TYPE_IP
block|,
name|HEADER_TYPE_TCP
block|,
name|HEADER_TYPE_UDP
block|,
name|HEADER_TYPE_UDP_LITE
block|,
name|HEADER_TYPE_IPHC
block|,
name|HEADER_TYPE_SCTP
block|,
name|HEADER_TYPE_SCTP_CHUNK_DATA
block|,
name|HEADER_TYPE_PPPoE
block|,
name|HEADER_TYPE_PPP
block|,
name|HEADER_TYPE_PPPMUX
block|,
name|HEADER_TYPE_PPPMUX_SUBFRAME
block|,
name|HEADER_TYPE_L2TPv2
block|,
name|HEADER_TYPE_L2TPv3_CTRL
block|,
name|HEADER_TYPE_L2TPv3_SESS
block|,
name|HEADER_TYPE_LLC
block|,
name|HEADER_TYPE_LLC_SNAP
block|,
name|HEADER_TYPE_NLPID
block|,
name|HEADER_TYPE_SNAP
block|,
name|HEADER_TYPE_MPLS
block|,
name|HEADER_TYPE_IPSEC_AH
block|,
name|HEADER_TYPE_IPSEC_ESP
block|,
name|HEADER_TYPE_UDP_ENCAP_ESP
block|,
comment|/* RFC 3948 */
name|HEADER_TYPE_MACSEC
block|,
name|HEADER_TYPE_GRE
block|,
name|HEADER_TYPE_MINENCAP
block|,
name|HEADER_TYPE_DCCP
block|,
name|HEADER_TYPE_ICMP
block|,
name|HEADER_TYPE_IGMP
block|,
name|HEADER_TYPE_ARP
block|,
name|HEADER_TYPE_CAPWAP
block|,
name|HEADER_TYPE_CAPWAP_DTLS
block|,
name|HEADER_TYPE_RFC2684
block|,
name|HEADER_TYPE_USER_DEFINED_L2
block|,
name|HEADER_TYPE_USER_DEFINED_L3
block|,
name|HEADER_TYPE_USER_DEFINED_L4
block|,
name|HEADER_TYPE_USER_DEFINED_SHIM1
block|,
name|HEADER_TYPE_USER_DEFINED_SHIM2
block|,
name|MAX_HEADER_TYPE_COUNT
block|}
name|e_NetHeaderType
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NET_EXT_H */
end_comment

end_unit

