begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Hidetoshi Shimokawa  * Copyright (c) 1998-2002 Katsushi Kobayashi and Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FIREWIRE_H
end_ifndef

begin_define
define|#
directive|define
name|_FIREWIRE_H
value|1
end_define

begin_define
define|#
directive|define
name|DEV_DEF
value|0
end_define

begin_define
define|#
directive|define
name|DEV_DV
value|2
end_define

begin_struct
struct|struct
name|fw_isochreq
block|{
name|unsigned
name|char
name|ch
range|:
literal|6
decl_stmt|,
name|tag
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_isobufreq
block|{
struct|struct
name|fw_bufspec
block|{
name|unsigned
name|int
name|nchunk
decl_stmt|;
name|unsigned
name|int
name|npacket
decl_stmt|;
name|unsigned
name|int
name|psize
decl_stmt|;
block|}
name|tx
struct|,
name|rx
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_addr
block|{
name|uint32_t
name|hi
decl_stmt|;
name|uint32_t
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_asybindreq
block|{
name|struct
name|fw_addr
name|start
decl_stmt|;
name|unsigned
name|long
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_reg_req_t
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXREC
parameter_list|(
name|x
parameter_list|)
value|(2<< (x))
end_define

begin_define
define|#
directive|define
name|FWPMAX_S400
value|(2048 + 20)
end_define

begin_comment
comment|/* MAXREC plus space for control data */
end_comment

begin_define
define|#
directive|define
name|FWMAXQUEUE
value|128
end_define

begin_define
define|#
directive|define
name|FWLOCALBUS
value|0xffc0
end_define

begin_define
define|#
directive|define
name|FWTCODE_WREQQ
value|0
end_define

begin_define
define|#
directive|define
name|FWTCODE_WREQB
value|1
end_define

begin_define
define|#
directive|define
name|FWTCODE_WRES
value|2
end_define

begin_define
define|#
directive|define
name|FWTCODE_RREQQ
value|4
end_define

begin_define
define|#
directive|define
name|FWTCODE_RREQB
value|5
end_define

begin_define
define|#
directive|define
name|FWTCODE_RRESQ
value|6
end_define

begin_define
define|#
directive|define
name|FWTCODE_RRESB
value|7
end_define

begin_define
define|#
directive|define
name|FWTCODE_CYCS
value|8
end_define

begin_define
define|#
directive|define
name|FWTCODE_LREQ
value|9
end_define

begin_define
define|#
directive|define
name|FWTCODE_STREAM
value|0xa
end_define

begin_define
define|#
directive|define
name|FWTCODE_LRES
value|0xb
end_define

begin_define
define|#
directive|define
name|FWTCODE_PHY
value|0xe
end_define

begin_define
define|#
directive|define
name|FWRETRY_1
value|0
end_define

begin_define
define|#
directive|define
name|FWRETRY_X
value|1
end_define

begin_define
define|#
directive|define
name|FWRETRY_A
value|2
end_define

begin_define
define|#
directive|define
name|FWRETRY_B
value|3
end_define

begin_define
define|#
directive|define
name|FWRCODE_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|FWRCODE_ER_CONFL
value|4
end_define

begin_define
define|#
directive|define
name|FWRCODE_ER_DATA
value|5
end_define

begin_define
define|#
directive|define
name|FWRCODE_ER_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|FWRCODE_ER_ADDR
value|7
end_define

begin_define
define|#
directive|define
name|FWSPD_S100
value|0
end_define

begin_define
define|#
directive|define
name|FWSPD_S200
value|1
end_define

begin_define
define|#
directive|define
name|FWSPD_S400
value|2
end_define

begin_define
define|#
directive|define
name|FWP_TL_VALID
value|(1<< 7)
end_define

begin_struct
struct|struct
name|fw_isohdr
block|{
name|uint32_t
name|hdr
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_asyhdr
block|{
name|uint32_t
name|hdr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|BIT4x2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|uint8_t  x:4, y:4
end_define

begin_define
define|#
directive|define
name|BIT16x2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|uint32_t x:16, y:16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIT4x2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|uint8_t  y:4, x:4
end_define

begin_define
define|#
directive|define
name|BIT16x2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|uint32_t y:16, x:16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|COMMON_HDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uint32_t a:16,b:8,c:4,d:4
end_define

begin_define
define|#
directive|define
name|COMMON_RES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uint32_t a:16,b:4,c:4,d:8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMMON_HDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uint32_t d:4,c:4,b:8,a:16
end_define

begin_define
define|#
directive|define
name|COMMON_RES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|uint32_t d:8,c:4,b:4,a:16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fw_pkt
block|{
union|union
block|{
name|uint32_t
name|ld
index|[
literal|0
index|]
decl_stmt|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(, ,
name|tcode
argument_list|, )
expr_stmt|;
block|}
name|common
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|len
argument_list|,
name|chtag
argument_list|,
name|tcode
argument_list|,
name|sy
argument_list|)
expr_stmt|;
name|uint32_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|stream
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|, )
expr_stmt|;
block|}
name|hdr
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
block|}
name|rreqq
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|COMMON_RES
argument_list|(
name|src
argument_list|,
name|rtcode
argument_list|, , )
expr_stmt|;
name|uint32_t
label|:
literal|32
expr_stmt|;
block|}
name|wres
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
name|BIT16x2
argument_list|(
name|len
argument_list|,
name|extcode
argument_list|)
expr_stmt|;
block|}
name|rreqb
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
name|wreqq
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
name|cyc
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|COMMON_RES
argument_list|(
name|src
argument_list|,
name|rtcode
argument_list|, , )
expr_stmt|;
name|uint32_t
label|:
literal|32
expr_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
name|rresq
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
name|BIT16x2
argument_list|(
name|len
argument_list|,
name|extcode
argument_list|)
expr_stmt|;
name|uint32_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|wreqb
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|BIT16x2
argument_list|(
name|src
argument_list|,
name|dest_hi
argument_list|)
expr_stmt|;
name|uint32_t
name|dest_lo
decl_stmt|;
name|BIT16x2
argument_list|(
name|len
argument_list|,
name|extcode
argument_list|)
expr_stmt|;
name|uint32_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|lreq
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|COMMON_RES
argument_list|(
name|src
argument_list|,
name|rtcode
argument_list|, , )
expr_stmt|;
name|uint32_t
label|:
literal|32
expr_stmt|;
name|BIT16x2
argument_list|(
name|len
argument_list|,
name|extcode
argument_list|)
expr_stmt|;
name|uint32_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|rresb
struct|;
struct|struct
block|{
name|COMMON_HDR
argument_list|(
name|dst
argument_list|,
name|tlrt
argument_list|,
name|tcode
argument_list|,
name|pri
argument_list|)
expr_stmt|;
name|COMMON_RES
argument_list|(
name|src
argument_list|,
name|rtcode
argument_list|, , )
expr_stmt|;
name|uint32_t
label|:
literal|32
expr_stmt|;
name|BIT16x2
argument_list|(
name|len
argument_list|,
name|extcode
argument_list|)
expr_stmt|;
name|uint32_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
block|}
name|lres
struct|;
block|}
name|mode
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Response code (rtcode)  */
end_comment

begin_comment
comment|/* The node has successfully completed the command. */
end_comment

begin_define
define|#
directive|define
name|RESP_CMP
value|0
end_define

begin_comment
comment|/* A resource conflict was detected. The request may be retried. */
end_comment

begin_define
define|#
directive|define
name|RESP_CONFLICT_ERROR
value|4
end_define

begin_comment
comment|/* Hardware error, data is unavailable. */
end_comment

begin_define
define|#
directive|define
name|RESP_DATA_ERROR
value|5
end_define

begin_comment
comment|/* A field in the request packet header was set to an unsupported or incorrect  * value, or an invalid transaction was attempted (e.g., a write to a read-only  * address). */
end_comment

begin_define
define|#
directive|define
name|RESP_TYPE_ERROR
value|6
end_define

begin_comment
comment|/* The destination offset field in the request was set to an address not  * accessible in the destination node. */
end_comment

begin_define
define|#
directive|define
name|RESP_ADDRESS_ERROR
value|7
end_define

begin_comment
comment|/*  * Extended transaction code (extcode)  */
end_comment

begin_define
define|#
directive|define
name|EXTCODE_MASK_SWAP
value|1
end_define

begin_define
define|#
directive|define
name|EXTCODE_CMP_SWAP
value|2
end_define

begin_define
define|#
directive|define
name|EXTCODE_FETCH_ADD
value|3
end_define

begin_define
define|#
directive|define
name|EXTCODE_LITTLE_ADD
value|4
end_define

begin_define
define|#
directive|define
name|EXTCODE_BOUNDED_ADD
value|5
end_define

begin_define
define|#
directive|define
name|EXTCODE_WRAP_ADD
value|6
end_define

begin_struct
struct|struct
name|fw_eui64
block|{
name|uint32_t
name|hi
decl_stmt|,
name|lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_EUI64_BYTE
parameter_list|(
name|eui
parameter_list|,
name|x
parameter_list|)
define|\
value|((((x)<4)?				\ 		((eui)->hi>> (8*(3-(x)))): 	\ 		((eui)->lo>> (8*(7-(x))))	\ 	)& 0xff)
end_define

begin_define
define|#
directive|define
name|FW_EUI64_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x).hi == (y).hi&& (x).lo == (y).lo)
end_define

begin_struct
struct|struct
name|fw_asyreq
block|{
struct|struct
name|fw_asyreq_t
block|{
name|unsigned
name|char
name|sped
decl_stmt|;
name|unsigned
name|int
name|type
decl_stmt|;
define|#
directive|define
name|FWASREQNODE
value|0
define|#
directive|define
name|FWASREQEUI
value|1
define|#
directive|define
name|FWASRESTL
value|2
define|#
directive|define
name|FWASREQSTREAM
value|3
name|unsigned
name|short
name|len
decl_stmt|;
union|union
block|{
name|struct
name|fw_eui64
name|eui
decl_stmt|;
block|}
name|dst
union|;
block|}
name|req
struct|;
name|struct
name|fw_pkt
name|pkt
decl_stmt|;
name|uint32_t
name|data
index|[
literal|512
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_devinfo
block|{
name|struct
name|fw_eui64
name|eui
decl_stmt|;
name|uint16_t
name|dst
decl_stmt|;
name|uint16_t
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_MAX_DEVLST
value|70
end_define

begin_struct
struct|struct
name|fw_devlstreq
block|{
name|uint16_t
name|n
decl_stmt|;
name|uint16_t
name|info_len
decl_stmt|;
name|struct
name|fw_devinfo
name|dev
index|[
name|FW_MAX_DEVLST
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FW_SELF_ID_PORT_CONNECTED_TO_CHILD
value|3
end_define

begin_define
define|#
directive|define
name|FW_SELF_ID_PORT_CONNECTED_TO_PARENT
value|2
end_define

begin_define
define|#
directive|define
name|FW_SELF_ID_PORT_NOT_CONNECTED
value|1
end_define

begin_define
define|#
directive|define
name|FW_SELF_ID_PORT_NOT_EXISTS
value|0
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_union
union|union
name|fw_self_id
block|{
struct|struct
block|{
name|uint32_t
name|id
range|:
literal|2
decl_stmt|,
name|phy_id
range|:
literal|6
decl_stmt|,
name|sequel
range|:
literal|1
decl_stmt|,
name|link_active
range|:
literal|1
decl_stmt|,
name|gap_count
range|:
literal|6
decl_stmt|,
name|phy_speed
range|:
literal|2
decl_stmt|,
name|phy_delay
range|:
literal|2
decl_stmt|,
name|contender
range|:
literal|1
decl_stmt|,
name|power_class
range|:
literal|3
decl_stmt|,
name|port0
range|:
literal|2
decl_stmt|,
name|port1
range|:
literal|2
decl_stmt|,
name|port2
range|:
literal|2
decl_stmt|,
name|initiated_reset
range|:
literal|1
decl_stmt|,
name|more_packets
range|:
literal|1
decl_stmt|;
block|}
name|p0
struct|;
struct|struct
block|{
name|uint32_t
name|id
range|:
literal|2
decl_stmt|,
name|phy_id
range|:
literal|6
decl_stmt|,
name|sequel
range|:
literal|1
decl_stmt|,
name|sequence_num
range|:
literal|3
decl_stmt|,
range|:
literal|2
decl_stmt|,
name|porta
range|:
literal|2
decl_stmt|,
name|portb
range|:
literal|2
decl_stmt|,
name|portc
range|:
literal|2
decl_stmt|,
name|portd
range|:
literal|2
decl_stmt|,
name|porte
range|:
literal|2
decl_stmt|,
name|portf
range|:
literal|2
decl_stmt|,
name|portg
range|:
literal|2
decl_stmt|,
name|porth
range|:
literal|2
decl_stmt|,
range|:
literal|1
decl_stmt|,
name|more_packets
range|:
literal|1
decl_stmt|;
block|}
name|p1
struct|;
block|}
union|;
end_union

begin_else
else|#
directive|else
end_else

begin_union
union|union
name|fw_self_id
block|{
struct|struct
block|{
name|uint32_t
name|more_packets
range|:
literal|1
decl_stmt|,
name|initiated_reset
range|:
literal|1
decl_stmt|,
name|port2
range|:
literal|2
decl_stmt|,
name|port1
range|:
literal|2
decl_stmt|,
name|port0
range|:
literal|2
decl_stmt|,
name|power_class
range|:
literal|3
decl_stmt|,
name|contender
range|:
literal|1
decl_stmt|,
name|phy_delay
range|:
literal|2
decl_stmt|,
name|phy_speed
range|:
literal|2
decl_stmt|,
name|gap_count
range|:
literal|6
decl_stmt|,
name|link_active
range|:
literal|1
decl_stmt|,
name|sequel
range|:
literal|1
decl_stmt|,
name|phy_id
range|:
literal|6
decl_stmt|,
name|id
range|:
literal|2
decl_stmt|;
block|}
name|p0
struct|;
struct|struct
block|{
name|uint32_t
name|more_packets
range|:
literal|1
decl_stmt|,
name|reserved1
range|:
literal|1
decl_stmt|,
name|porth
range|:
literal|2
decl_stmt|,
name|portg
range|:
literal|2
decl_stmt|,
name|portf
range|:
literal|2
decl_stmt|,
name|porte
range|:
literal|2
decl_stmt|,
name|portd
range|:
literal|2
decl_stmt|,
name|portc
range|:
literal|2
decl_stmt|,
name|portb
range|:
literal|2
decl_stmt|,
name|porta
range|:
literal|2
decl_stmt|,
name|reserved2
range|:
literal|2
decl_stmt|,
name|sequence_num
range|:
literal|3
decl_stmt|,
name|sequel
range|:
literal|1
decl_stmt|,
name|phy_id
range|:
literal|6
decl_stmt|,
name|id
range|:
literal|2
decl_stmt|;
block|}
name|p1
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fw_topology_map
block|{
name|uint32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|16
decl_stmt|;
name|uint32_t
name|generation
decl_stmt|;
name|uint32_t
name|self_id_count
range|:
literal|16
decl_stmt|,
name|node_count
range|:
literal|16
decl_stmt|;
name|union
name|fw_self_id
name|self_id
index|[
literal|4
operator|*
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_speed_map
block|{
name|uint32_t
name|crc
range|:
literal|16
decl_stmt|,
name|crc_len
range|:
literal|16
decl_stmt|;
name|uint32_t
name|generation
decl_stmt|;
name|uint8_t
name|speed
index|[
literal|64
index|]
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_crom_buf
block|{
name|struct
name|fw_eui64
name|eui
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FireWire specific system requests.  */
end_comment

begin_define
define|#
directive|define
name|FW_SSTBUF
value|_IOWR('S', 86, struct fw_isobufreq)
end_define

begin_define
define|#
directive|define
name|FW_GSTBUF
value|_IOWR('S', 87, struct fw_isobufreq)
end_define

begin_define
define|#
directive|define
name|FW_SRSTREAM
value|_IOWR('S', 88, struct fw_isochreq)
end_define

begin_define
define|#
directive|define
name|FW_GRSTREAM
value|_IOWR('S', 89, struct fw_isochreq)
end_define

begin_define
define|#
directive|define
name|FW_STSTREAM
value|_IOWR('S', 90, struct fw_isochreq)
end_define

begin_define
define|#
directive|define
name|FW_GTSTREAM
value|_IOWR('S', 91, struct fw_isochreq)
end_define

begin_define
define|#
directive|define
name|FW_ASYREQ
value|_IOWR('S', 92, struct fw_asyreq)
end_define

begin_define
define|#
directive|define
name|FW_IBUSRST
value|_IOR('S', 1, unsigned int)
end_define

begin_define
define|#
directive|define
name|FW_GDEVLST
value|_IOWR('S', 2, struct fw_devlstreq)
end_define

begin_define
define|#
directive|define
name|FW_SBINDADDR
value|_IOWR('S', 3, struct fw_asybindreq)
end_define

begin_define
define|#
directive|define
name|FW_CBINDADDR
value|_IOWR('S', 4, struct fw_asybindreq)
end_define

begin_define
define|#
directive|define
name|FW_GTPMAP
value|_IOR('S', 5, struct fw_topology_map)
end_define

begin_define
define|#
directive|define
name|FW_GCROM
value|_IOWR('S', 7, struct fw_crom_buf)
end_define

begin_define
define|#
directive|define
name|FW_SDEUI64
value|_IOW('S', 20, struct fw_eui64)
end_define

begin_define
define|#
directive|define
name|FW_GDEUI64
value|_IOR('S', 21, struct fw_eui64)
end_define

begin_define
define|#
directive|define
name|FWOHCI_RDREG
value|_IOWR('S', 80, struct fw_reg_req_t)
end_define

begin_define
define|#
directive|define
name|FWOHCI_WRREG
value|_IOWR('S', 81, struct fw_reg_req_t)
end_define

begin_define
define|#
directive|define
name|FWOHCI_RDPHYREG
value|_IOWR('S', 82, struct fw_reg_req_t)
end_define

begin_define
define|#
directive|define
name|FWOHCI_WRPHYREG
value|_IOWR('S', 83, struct fw_reg_req_t)
end_define

begin_define
define|#
directive|define
name|DUMPDMA
value|_IOWR('S', 82, uint32_t)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|FWMAXNDMA
value|0x100
end_define

begin_comment
comment|/* 8 bits DMA channel id. in device No. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|dev2unit
parameter_list|(
name|x
parameter_list|)
value|((minor(x)& 0xff) | (minor(x)>> 8))
end_define

begin_define
define|#
directive|define
name|unit2minor
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff) | (((x)<< 8)& ~0xffff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAKEMINOR
parameter_list|(
name|f
parameter_list|,
name|u
parameter_list|,
name|s
parameter_list|)
define|\
value|unit2minor((f) | (((u)& 0xff)<< 8) | (s& 0xff))
end_define

begin_define
define|#
directive|define
name|DEV2UNIT
parameter_list|(
name|x
parameter_list|)
value|((dev2unit(x)& 0xff00)>> 8)
end_define

begin_define
define|#
directive|define
name|DEV2SUB
parameter_list|(
name|x
parameter_list|)
value|(dev2unit(x)& 0xff)
end_define

begin_define
define|#
directive|define
name|FWMEM_FLAG
value|0x10000
end_define

begin_define
define|#
directive|define
name|DEV_FWMEM
parameter_list|(
name|x
parameter_list|)
value|(dev2unit(x)& FWMEM_FLAG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

