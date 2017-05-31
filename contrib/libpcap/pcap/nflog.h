begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, Petar Alilovic,  * Faculty of Electrical Engineering and Computing, University of Zagreb  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * * Redistributions of source code must retain the above copyright notice,  *	 this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above copyright  *	 notice, this list of conditions and the following disclaimer in the  *	 documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lib_pcap_nflog_h
end_ifndef

begin_define
define|#
directive|define
name|lib_pcap_nflog_h
end_define

begin_comment
comment|/*  * Structure of an NFLOG header and TLV parts, as described at  * http://www.tcpdump.org/linktypes/LINKTYPE_NFLOG.html  *  * The NFLOG header is big-endian.  *  * The TLV length and type are in host byte order.  The value is either  * big-endian or is an array of bytes in some externally-specified byte  * order (text string, link-layer address, link-layer header, packet  * data, etc.).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nflog_hdr
block|{
name|u_int8_t
name|nflog_family
decl_stmt|;
comment|/* address family */
name|u_int8_t
name|nflog_version
decl_stmt|;
comment|/* version */
name|u_int16_t
name|nflog_rid
decl_stmt|;
comment|/* resource ID */
block|}
name|nflog_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nflog_tlv
block|{
name|u_int16_t
name|tlv_length
decl_stmt|;
comment|/* tlv length */
name|u_int16_t
name|tlv_type
decl_stmt|;
comment|/* tlv type */
comment|/* value follows this */
block|}
name|nflog_tlv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nflog_packet_hdr
block|{
name|u_int16_t
name|hw_protocol
decl_stmt|;
comment|/* hw protocol */
name|u_int8_t
name|hook
decl_stmt|;
comment|/* netfilter hook */
name|u_int8_t
name|pad
decl_stmt|;
comment|/* padding to 32 bits */
block|}
name|nflog_packet_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nflog_hwaddr
block|{
name|u_int16_t
name|hw_addrlen
decl_stmt|;
comment|/* address length */
name|u_int16_t
name|pad
decl_stmt|;
comment|/* padding to 32-bit boundary */
name|u_int8_t
name|hw_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* address, up to 8 bytes */
block|}
name|nflog_hwaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nflog_timestamp
block|{
name|u_int64_t
name|sec
decl_stmt|;
name|u_int64_t
name|usec
decl_stmt|;
block|}
name|nflog_timestamp_t
typedef|;
end_typedef

begin_comment
comment|/*  * TLV types.  */
end_comment

begin_define
define|#
directive|define
name|NFULA_PACKET_HDR
value|1
end_define

begin_comment
comment|/* nflog_packet_hdr_t */
end_comment

begin_define
define|#
directive|define
name|NFULA_MARK
value|2
end_define

begin_comment
comment|/* packet mark from skbuff */
end_comment

begin_define
define|#
directive|define
name|NFULA_TIMESTAMP
value|3
end_define

begin_comment
comment|/* nflog_timestamp_t for skbuff's time stamp */
end_comment

begin_define
define|#
directive|define
name|NFULA_IFINDEX_INDEV
value|4
end_define

begin_comment
comment|/* ifindex of device on which packet received (possibly bridge group) */
end_comment

begin_define
define|#
directive|define
name|NFULA_IFINDEX_OUTDEV
value|5
end_define

begin_comment
comment|/* ifindex of device on which packet transmitted (possibly bridge group) */
end_comment

begin_define
define|#
directive|define
name|NFULA_IFINDEX_PHYSINDEV
value|6
end_define

begin_comment
comment|/* ifindex of physical device on which packet received (not bridge group) */
end_comment

begin_define
define|#
directive|define
name|NFULA_IFINDEX_PHYSOUTDEV
value|7
end_define

begin_comment
comment|/* ifindex of physical device on which packet transmitted (not bridge group) */
end_comment

begin_define
define|#
directive|define
name|NFULA_HWADDR
value|8
end_define

begin_comment
comment|/* nflog_hwaddr_t for hardware address */
end_comment

begin_define
define|#
directive|define
name|NFULA_PAYLOAD
value|9
end_define

begin_comment
comment|/* packet payload */
end_comment

begin_define
define|#
directive|define
name|NFULA_PREFIX
value|10
end_define

begin_comment
comment|/* text string - null-terminated, count includes NUL */
end_comment

begin_define
define|#
directive|define
name|NFULA_UID
value|11
end_define

begin_comment
comment|/* UID owning socket on which packet was sent/received */
end_comment

begin_define
define|#
directive|define
name|NFULA_SEQ
value|12
end_define

begin_comment
comment|/* sequence number of packets on this NFLOG socket */
end_comment

begin_define
define|#
directive|define
name|NFULA_SEQ_GLOBAL
value|13
end_define

begin_comment
comment|/* sequence number of pakets on all NFLOG sockets */
end_comment

begin_define
define|#
directive|define
name|NFULA_GID
value|14
end_define

begin_comment
comment|/* GID owning socket on which packet was sent/received */
end_comment

begin_define
define|#
directive|define
name|NFULA_HWTYPE
value|15
end_define

begin_comment
comment|/* ARPHRD_ type of skbuff's device */
end_comment

begin_define
define|#
directive|define
name|NFULA_HWHEADER
value|16
end_define

begin_comment
comment|/* skbuff's MAC-layer header */
end_comment

begin_define
define|#
directive|define
name|NFULA_HWLEN
value|17
end_define

begin_comment
comment|/* length of skbuff's MAC-layer header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

