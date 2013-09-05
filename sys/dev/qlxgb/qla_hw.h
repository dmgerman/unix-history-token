begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011-2013 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qla_hw.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLA_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLA_HW_H_
end_define

begin_define
define|#
directive|define
name|Q8_MAX_NUM_MULTICAST_ADDRS
value|128
end_define

begin_define
define|#
directive|define
name|Q8_MAC_ADDR_LEN
value|6
end_define

begin_comment
comment|/*  * Firmware Interface  */
end_comment

begin_comment
comment|/*  * Command Response Interface - Commands  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qla_cdrp
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmd_arg1
decl_stmt|;
name|uint32_t
name|cmd_arg2
decl_stmt|;
name|uint32_t
name|cmd_arg3
decl_stmt|;
name|uint32_t
name|rsp
decl_stmt|;
name|uint32_t
name|rsp_arg1
decl_stmt|;
name|uint32_t
name|rsp_arg2
decl_stmt|;
name|uint32_t
name|rsp_arg3
decl_stmt|;
block|}
name|qla_cdrp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_RDS_PER_CNTXT
value|0x80000002
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_SDS_PER_CNTXT
value|0x80000003
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_RULES_PER_CNTXT
value|0x80000004
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_RX_CNTXT
value|0x80000005
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_TX_CNTXT
value|0x80000006
end_define

begin_define
define|#
directive|define
name|Q8_CMD_CREATE_RX_CNTXT
value|0x80000007
end_define

begin_define
define|#
directive|define
name|Q8_CMD_DESTROY_RX_CNTXT
value|0x80000008
end_define

begin_define
define|#
directive|define
name|Q8_CMD_CREATE_TX_CNTXT
value|0x80000009
end_define

begin_define
define|#
directive|define
name|Q8_CMD_DESTROY_TX_CNTXT
value|0x8000000A
end_define

begin_define
define|#
directive|define
name|Q8_CMD_SETUP_STATS
value|0x8000000E
end_define

begin_define
define|#
directive|define
name|Q8_CMD_GET_STATS
value|0x8000000F
end_define

begin_define
define|#
directive|define
name|Q8_CMD_DELETE_STATS
value|0x80000010
end_define

begin_define
define|#
directive|define
name|Q8_CMD_GEN_INT
value|0x80000011
end_define

begin_define
define|#
directive|define
name|Q8_CMD_SET_MTU
value|0x80000012
end_define

begin_define
define|#
directive|define
name|Q8_CMD_GET_FLOW_CNTRL
value|0x80000016
end_define

begin_define
define|#
directive|define
name|Q8_CMD_SET_FLOW_CNTRL
value|0x80000017
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_MTU
value|0x80000018
end_define

begin_define
define|#
directive|define
name|Q8_CMD_RD_MAX_LRO
value|0x80000019
end_define

begin_comment
comment|/*  * Command Response Interface - Response  */
end_comment

begin_define
define|#
directive|define
name|Q8_RSP_SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NO_HOST_MEM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NO_HOST_RSRC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NO_CARD_CRB
value|0x00000003
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NO_CARD_MEM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NO_CARD_RSRC
value|0x00000005
end_define

begin_define
define|#
directive|define
name|Q8_RSP_INVALID_ARGS
value|0x00000006
end_define

begin_define
define|#
directive|define
name|Q8_RSP_INVALID_ACTION
value|0x00000007
end_define

begin_define
define|#
directive|define
name|Q8_RSP_INVALID_STATE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NOT_SUPPORTED
value|0x00000009
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NOT_PERMITTED
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|Q8_RSP_NOT_READY
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|Q8_RSP_DOES_NOT_EXIST
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|Q8_RSP_ALREADY_EXISTS
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|Q8_RSP_BAD_SIGNATURE
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|Q8_RSP_CMD_NOT_IMPLEMENTED
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|Q8_RSP_CMD_INVALID
value|0x00000010
end_define

begin_define
define|#
directive|define
name|Q8_RSP_TIMEOUT
value|0x00000011
end_define

begin_comment
comment|/*  * Transmit Related Definitions  */
end_comment

begin_comment
comment|/*  * Transmit Context - Q8_CMD_CREATE_TX_CNTXT Command Configuration Data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cntxt_req
block|{
name|uint64_t
name|rsp_dma_addr
decl_stmt|;
comment|/* rsp from firmware is DMA'ed here */
name|uint64_t
name|cmd_cons_dma_addr
decl_stmt|;
name|uint64_t
name|rsrvd0
decl_stmt|;
name|uint32_t
name|caps
index|[
literal|4
index|]
decl_stmt|;
comment|/* capabilities  - bit vector*/
define|#
directive|define
name|CNTXT_CAP0_BASEFW
value|0x0001
define|#
directive|define
name|CNTXT_CAP0_LEGACY_MN
value|0x0004
define|#
directive|define
name|CNTXT_CAP0_LSO
value|0x0040
name|uint32_t
name|intr_mode
decl_stmt|;
comment|/* Interrupt Mode */
define|#
directive|define
name|CNTXT_INTR_MODE_UNIQUE
value|0x0000
define|#
directive|define
name|CNTXT_INTR_MODE_SHARED
value|0x0001
name|uint64_t
name|rsrvd1
decl_stmt|;
name|uint16_t
name|msi_index
decl_stmt|;
name|uint16_t
name|rsrvd2
decl_stmt|;
name|uint64_t
name|phys_addr
decl_stmt|;
comment|/* physical address of transmit ring 					 * in system memory */
name|uint32_t
name|num_entries
decl_stmt|;
comment|/* number of entries in transmit ring */
name|uint8_t
name|rsrvd3
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
name|q80_tx_cntxt_req_t
typedef|;
end_typedef

begin_comment
comment|/* 188 bytes total */
end_comment

begin_comment
comment|/*  * Transmit Context - Response from Firmware to Q8_CMD_CREATE_TX_CNTXT  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cntxt_rsp
block|{
name|uint32_t
name|cntxt_state
decl_stmt|;
comment|/* starting state */
define|#
directive|define
name|CNTXT_STATE_ALLOCATED_NOT_ACTIVE
value|0x0001
define|#
directive|define
name|CNTXT_STATE_ACTIVE
value|0x0002
define|#
directive|define
name|CNTXT_STATE_QUIESCED
value|0x0004
name|uint16_t
name|cntxt_id
decl_stmt|;
comment|/* handle for context */
name|uint8_t
name|phys_port_id
decl_stmt|;
comment|/* physical id of port */
name|uint8_t
name|virt_port_id
decl_stmt|;
comment|/* virtual or logical id of port */
name|uint32_t
name|producer_reg
decl_stmt|;
comment|/* producer register for transmit ring */
name|uint32_t
name|intr_mask_reg
decl_stmt|;
comment|/* interrupt mask register */
name|uint8_t
name|rsrvd
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
name|q80_tx_cntxt_rsp_t
typedef|;
end_typedef

begin_comment
comment|/* 144 bytes */
end_comment

begin_comment
comment|/*  * Transmit Command Descriptor  * These commands are issued on the Transmit Ring associated with a Transmit  * context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_tx_cmd
block|{
name|uint8_t
name|tcp_hdr_off
decl_stmt|;
comment|/* TCP Header Offset */
name|uint8_t
name|ip_hdr_off
decl_stmt|;
comment|/* IP Header Offset */
name|uint16_t
name|flags_opcode
decl_stmt|;
comment|/* Bits 0-6: flags; 7-12: opcode */
comment|/* flags field */
define|#
directive|define
name|Q8_TX_CMD_FLAGS_MULTICAST
value|0x01
define|#
directive|define
name|Q8_TX_CMD_FLAGS_LSO_TSO
value|0x02
define|#
directive|define
name|Q8_TX_CMD_FLAGS_VLAN_TAGGED
value|0x10
define|#
directive|define
name|Q8_TX_CMD_FLAGS_HW_VLAN_ID
value|0x40
comment|/* opcode field */
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_UDP_CHKSUM_IPV6
value|(0xC<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_CHKSUM_IPV6
value|(0xB<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_LSO_IPV6
value|(0x6<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_LSO
value|(0x5<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_UDP_CHKSUM
value|(0x3<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_TCP_CHKSUM
value|(0x2<< 7)
define|#
directive|define
name|Q8_TX_CMD_OP_XMT_ETHER
value|(0x1<< 7)
name|uint8_t
name|n_bufs
decl_stmt|;
comment|/* # of data segs in data buffer */
name|uint8_t
name|data_len_lo
decl_stmt|;
comment|/* data length lower 8 bits */
name|uint16_t
name|data_len_hi
decl_stmt|;
comment|/* data length upper 16 bits */
name|uint64_t
name|buf2_addr
decl_stmt|;
comment|/* buffer 2 address */
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
comment|/* MSS for this packet */
name|uint8_t
name|port_cntxtid
decl_stmt|;
comment|/* Bits 7-4: ContextId; 3-0: reserved */
define|#
directive|define
name|Q8_TX_CMD_PORT_CNXTID
parameter_list|(
name|c_id
parameter_list|)
value|((c_id& 0xF)<< 4)
name|uint8_t
name|total_hdr_len
decl_stmt|;
comment|/* MAC+IP+TCP Header Length for LSO */
name|uint16_t
name|rsrvd1
decl_stmt|;
name|uint64_t
name|buf3_addr
decl_stmt|;
comment|/* buffer 3 address */
name|uint64_t
name|buf1_addr
decl_stmt|;
comment|/* buffer 1 address */
name|uint16_t
name|buf1_len
decl_stmt|;
comment|/* length of buffer 1 */
name|uint16_t
name|buf2_len
decl_stmt|;
comment|/* length of buffer 2 */
name|uint16_t
name|buf3_len
decl_stmt|;
comment|/* length of buffer 3 */
name|uint16_t
name|buf4_len
decl_stmt|;
comment|/* length of buffer 4 */
name|uint64_t
name|buf4_addr
decl_stmt|;
comment|/* buffer 4 address */
name|uint32_t
name|rsrvd2
decl_stmt|;
name|uint16_t
name|rsrvd3
decl_stmt|;
name|uint16_t
name|vlan_tci
decl_stmt|;
comment|/* VLAN TCI when hw tagging is enabled*/
block|}
name|__packed
name|q80_tx_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* 64 bytes */
end_comment

begin_define
define|#
directive|define
name|Q8_TX_CMD_MAX_SEGMENTS
value|4
end_define

begin_define
define|#
directive|define
name|Q8_TX_CMD_TSO_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|Q8_TX_MAX_SEGMENTS
value|14
end_define

begin_comment
comment|/*  * Receive Related Definitions  */
end_comment

begin_comment
comment|/*  * Receive Context - Q8_CMD_CREATE_RX_CNTXT Command Configuration Data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_sds_ring
block|{
name|uint64_t
name|phys_addr
decl_stmt|;
comment|/* physical addr of status ring in system memory */
name|uint32_t
name|size
decl_stmt|;
comment|/* number of entries in status ring */
name|uint16_t
name|msi_index
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|q80_rq_sds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 16 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_rds_ring
block|{
name|uint64_t
name|phys_addr
decl_stmt|;
comment|/* physical addr of rcv ring in system memory */
name|uint64_t
name|buf_size
decl_stmt|;
comment|/* packet buffer size */
name|uint32_t
name|size
decl_stmt|;
comment|/* number of entries in ring */
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|q80_rq_rds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 24 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rq_rcv_cntxt
block|{
name|uint64_t
name|rsp_dma_addr
decl_stmt|;
comment|/* rsp from firmware is DMA'ed here */
name|uint32_t
name|caps
index|[
literal|4
index|]
decl_stmt|;
comment|/* bit vector */
define|#
directive|define
name|CNTXT_CAP0_JUMBO
value|0x0080
comment|/* Contiguous Jumbo buffers*/
define|#
directive|define
name|CNTXT_CAP0_LRO
value|0x0100
define|#
directive|define
name|CNTXT_CAP0_HW_LRO
value|0x0800
comment|/* HW LRO */
name|uint32_t
name|intr_mode
decl_stmt|;
comment|/* same as q80_tx_cntxt_req_t */
name|uint32_t
name|rds_intr_mode
decl_stmt|;
comment|/* same as q80_tx_cntxt_req_t */
name|uint32_t
name|rds_ring_offset
decl_stmt|;
comment|/* rds configuration relative to data[0] */
name|uint32_t
name|sds_ring_offset
decl_stmt|;
comment|/* sds configuration relative to data[0] */
name|uint16_t
name|num_rds_rings
decl_stmt|;
name|uint16_t
name|num_sds_rings
decl_stmt|;
name|uint8_t
name|rsrvd1
index|[
literal|132
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rq_rcv_cntxt_t
typedef|;
end_typedef

begin_comment
comment|/* 176 bytes header + rds + sds ring rqsts */
end_comment

begin_comment
comment|/*  * Receive Context - Response from Firmware to Q8_CMD_CREATE_RX_CNTXT  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_rds_ring
block|{
name|uint32_t
name|producer_reg
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|q80_rsp_rds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 8 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_sds_ring
block|{
name|uint32_t
name|consumer_reg
decl_stmt|;
name|uint32_t
name|intr_mask_reg
decl_stmt|;
block|}
name|__packed
name|q80_rsp_sds_ring_t
typedef|;
end_typedef

begin_comment
comment|/* 8 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rsp_rcv_cntxt
block|{
name|uint32_t
name|rds_ring_offset
decl_stmt|;
comment|/* rds configuration relative to data[0] */
name|uint32_t
name|sds_ring_offset
decl_stmt|;
comment|/* sds configuration relative to data[0] */
name|uint32_t
name|cntxt_state
decl_stmt|;
comment|/* starting state */
name|uint32_t
name|funcs_per_port
decl_stmt|;
comment|/* number of PCI functions sharing each port */
name|uint16_t
name|num_rds_rings
decl_stmt|;
name|uint16_t
name|num_sds_rings
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
comment|/* handle for context */
name|uint8_t
name|phys_port
decl_stmt|;
comment|/* physical id of port */
name|uint8_t
name|virt_port
decl_stmt|;
comment|/* virtual or logical id of port */
name|uint8_t
name|rsrvd
index|[
literal|128
index|]
decl_stmt|;
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rsp_rcv_cntxt_t
typedef|;
end_typedef

begin_comment
comment|/* 152 bytes header + rds + sds ring rspncs */
end_comment

begin_comment
comment|/*  * Note:  *	Transmit Context  *	188 (rq) + 144 (rsp) = 332 bytes are required  *	  *	Receive Context  *	1 RDS and 1 SDS rings: (16+24+176)+(8+8+152) = 384 bytes  *  *	3 RDS and 4 SDS rings: (((16+24)*3)+176) + (((8+8)*4)+152) =  *				= 296 + 216 = 512 bytes  *	Clearly this within the minimum PAGE size of most O.S platforms  *	(typically 4Kbytes). Hence it is simpler to simply allocate one PAGE  *	and then carve out space for each context. It is also a good idea to  * 	to throw in the shadown register for the consumer index of the transmit  *	ring in this PAGE.  */
end_comment

begin_comment
comment|/*  * Receive Descriptor corresponding to each entry in the receive ring  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_desc
block|{
name|uint16_t
name|handle
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|buf_size
decl_stmt|;
comment|/* buffer size in bytes */
name|uint64_t
name|buf_addr
decl_stmt|;
comment|/* physical address of buffer */
block|}
name|__packed
name|q80_recv_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Status Descriptor corresponding to each entry in the Status ring  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q80_stat_desc
block|{
name|uint64_t
name|data
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|q80_stat_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * definitions for data[0] field of Status Descriptor  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OWNER
parameter_list|(
name|data
parameter_list|)
value|((data>> 56)& 0x3)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OWNER_HOST
value|0x1
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OWNER_FW
value|0x2
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OWNER_MASK
value|(((uint64_t)0x3)<< 56)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_SET_OWNER
parameter_list|(
name|owner
parameter_list|)
value|(uint64_t)(((uint64_t)owner)<< 56)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE
parameter_list|(
name|data
parameter_list|)
value|((data>> 58)& 0x003F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_SYN_OFFLOAD
value|0x03
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_RCV_PKT
value|0x04
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_CTRL_MSG
value|0x05
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_OPCODE_LRO_PKT
value|0x12
end_define

begin_comment
comment|/*  * definitions for data[0] field of Status Descriptor for standard frames  * status descriptor opcode equals 0x04  */
end_comment

begin_define
define|#
directive|define
name|Q8_STAT_DESC_PORT
parameter_list|(
name|data
parameter_list|)
value|((data)& 0x000F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS
parameter_list|(
name|data
parameter_list|)
value|((data>> 4)& 0x000F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_NO_CHKSUM
value|0x01
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_CHKSUM_OK
value|0x02
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_STATUS_CHKSUM_ERR
value|0x03
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_TYPE
parameter_list|(
name|data
parameter_list|)
value|((data>> 8)& 0x000F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_TOTAL_LENGTH
parameter_list|(
name|data
parameter_list|)
value|((data>> 12)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_HANDLE
parameter_list|(
name|data
parameter_list|)
value|((data>> 28)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_PROTOCOL
parameter_list|(
name|data
parameter_list|)
value|((data>> 44)& 0x000F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_L2_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0x001F)
end_define

begin_define
define|#
directive|define
name|Q8_STAT_DESC_COUNT
parameter_list|(
name|data
parameter_list|)
value|((data>> 53)& 0x0007)
end_define

begin_comment
comment|/*  * definitions for data[0-1] fields of Status Descriptor for LRO  * status descriptor opcode equals 0x05  */
end_comment

begin_comment
comment|/* definitions for data[0] field */
end_comment

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_HANDLE
parameter_list|(
name|data
parameter_list|)
value|((data)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_PAYLOAD_LENGTH
parameter_list|(
name|data
parameter_list|)
value|((data>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_L2_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 32)& 0xFF)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_L4_OFFSET
parameter_list|(
name|data
parameter_list|)
value|((data>> 40)& 0xFF)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_TS_PRESENT
parameter_list|(
name|data
parameter_list|)
value|((data>> 48)& 0x1)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_TYPE
parameter_list|(
name|data
parameter_list|)
value|((data>> 49)& 0x7)
end_define

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_PUSH_BIT
parameter_list|(
name|data
parameter_list|)
value|((data>> 52)& 0x1)
end_define

begin_comment
comment|/* definitions for data[1] field */
end_comment

begin_define
define|#
directive|define
name|Q8_LRO_STAT_DESC_SEQ_NUM
parameter_list|(
name|data
parameter_list|)
value|(uint32_t)(data)
end_define

begin_comment
comment|/** Driver Related Definitions Begin **/
end_comment

begin_define
define|#
directive|define
name|MAX_RDS_RINGS
value|2
end_define

begin_comment
comment|/* Max# of Receive Descriptor Rings */
end_comment

begin_define
define|#
directive|define
name|MAX_SDS_RINGS
value|4
end_define

begin_comment
comment|/* Max# of Status Descriptor Rings */
end_comment

begin_define
define|#
directive|define
name|TX_SMALL_PKT_SIZE
value|128
end_define

begin_comment
comment|/* size in bytes of small packets */
end_comment

begin_comment
comment|/* The number of descriptors should be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|NUM_TX_DESCRIPTORS
value|2048
end_define

begin_define
define|#
directive|define
name|NUM_RX_DESCRIPTORS
value|8192
end_define

begin_comment
comment|//#define NUM_RX_JUMBO_DESCRIPTORS	1024
end_comment

begin_define
define|#
directive|define
name|NUM_RX_JUMBO_DESCRIPTORS
value|2048
end_define

begin_comment
comment|//#define NUM_STATUS_DESCRIPTORS		8192
end_comment

begin_define
define|#
directive|define
name|NUM_STATUS_DESCRIPTORS
value|2048
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_cntxt_req
block|{
name|q80_rq_rcv_cntxt_t
name|rx_req
decl_stmt|;
name|q80_rq_rds_ring_t
name|rds_req
index|[
name|MAX_RDS_RINGS
index|]
decl_stmt|;
name|q80_rq_sds_ring_t
name|sds_req
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rcv_cntxt_req_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q80_rcv_cntxt_rsp
block|{
name|q80_rsp_rcv_cntxt_t
name|rx_rsp
decl_stmt|;
name|q80_rsp_rds_ring_t
name|rds_rsp
index|[
name|MAX_RDS_RINGS
index|]
decl_stmt|;
name|q80_rsp_sds_ring_t
name|sds_rsp
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
block|}
name|__packed
name|q80_rcv_cntxt_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure describing various dma buffers  */
end_comment

begin_define
define|#
directive|define
name|RDS_RING_INDEX_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|RDS_RING_INDEX_JUMBO
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|qla_dmabuf
block|{
specifier|volatile
struct|struct
block|{
name|uint32_t
name|tx_ring
range|:
literal|1
decl_stmt|,
name|rds_ring
range|:
literal|1
decl_stmt|,
name|sds_ring
range|:
literal|1
decl_stmt|,
name|context
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|qla_dma_t
name|tx_ring
decl_stmt|;
name|qla_dma_t
name|rds_ring
index|[
name|MAX_RDS_RINGS
index|]
decl_stmt|;
name|qla_dma_t
name|sds_ring
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|qla_dma_t
name|context
decl_stmt|;
block|}
name|qla_dmabuf_t
typedef|;
end_typedef

begin_comment
comment|/** Driver Related Definitions End **/
end_comment

begin_comment
comment|/*  * Firmware Control Descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_hdr
block|{
name|uint64_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_FWCD_CNTRL_REQ
value|(0x13<< 23)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|cookie
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint8_t
name|response
decl_stmt|;
define|#
directive|define
name|Q8_FW_CDS_HDR_COMPLETION
value|0x1
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint8_t
name|sub_opcode
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * definitions for opcode in qla_fw_cds_hdr_t  */
end_comment

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_RSS
value|0x01
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_RSS_TABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_INTR_COALESCING
value|0x03
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_LED
value|0x04
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_MAC_ADDR
value|0x06
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_LRO_FLOW
value|0x07
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_GET_SNMP_STATS
value|0x08
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_MAC_RCV_MODE
value|0x0C
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_STATISTICS
value|0x10
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_IPADDR
value|0x12
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_LOOPBACK
value|0x13
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_LINK_EVENT_REQ
value|0x15
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_BRIDGING
value|0x17
end_define

begin_define
define|#
directive|define
name|Q8_FWCD_OPCODE_CONFIG_LRO
value|0x18
end_define

begin_comment
comment|/*  * Configure RSS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_rss
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|hash_type
decl_stmt|;
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV4_TCP
value|(0x2<< 4)
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV4_IP
value|(0x1<< 4)
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV4_TCP_IP
value|(0x3<< 4)
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV6_TCP
value|(0x2<< 6)
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV6_IP
value|(0x1<< 6)
define|#
directive|define
name|Q8_FWCD_RSS_HASH_TYPE_IPV6_TCP_IP
value|(0x3<< 6)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q8_FWCD_RSS_FLAGS_ENABLE_RSS
value|0x1
define|#
directive|define
name|Q8_FWCD_RSS_FLAGS_USE_IND_TABLE
value|0x2
name|uint8_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|ind_tbl_mask
decl_stmt|;
name|uint64_t
name|rss_key
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_rss_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure RSS Table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_rss_table
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint64_t
name|index
decl_stmt|;
name|uint8_t
name|table
index|[
literal|40
index|]
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_rss_table_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure Interrupt Coalescing  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_intr_coalesc
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|rsrvd1
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|rsrvd2
decl_stmt|;
name|uint64_t
name|rsrvd3
decl_stmt|;
name|uint16_t
name|max_rcv_pkts
decl_stmt|;
name|uint16_t
name|max_rcv_usecs
decl_stmt|;
name|uint16_t
name|max_snd_pkts
decl_stmt|;
name|uint16_t
name|max_snd_usecs
decl_stmt|;
name|uint64_t
name|rsrvd4
decl_stmt|;
name|uint64_t
name|rsrvd5
decl_stmt|;
name|uint32_t
name|usecs_to
decl_stmt|;
name|uint8_t
name|timer_type
decl_stmt|;
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_TIMER_NONE
value|0x00
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_TIMER_ONCE
value|0x01
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_TIMER_PERIODIC
value|0x02
name|uint8_t
name|sds_ring_bitmask
decl_stmt|;
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_SDS_RING_0
value|0x01
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_SDS_RING_1
value|0x02
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_SDS_RING_2
value|0x04
define|#
directive|define
name|Q8_FWCMD_INTR_COALESC_SDS_RING_3
value|0x08
name|uint16_t
name|rsrvd6
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_intr_coalesc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure LED Parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_led
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint32_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|blink_rate
decl_stmt|;
name|uint32_t
name|blink_state
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_led_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure MAC Address  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_mac_addr
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_FWCD_ADD_MAC_ADDR
value|0x1
define|#
directive|define
name|Q8_FWCD_DEL_MAC_ADDR
value|0x2
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_mac_addr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure Add/Delete LRO  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_config_lro
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint32_t
name|dst_ip_addr
decl_stmt|;
name|uint32_t
name|src_ip_addr
decl_stmt|;
name|uint16_t
name|dst_tcp_port
decl_stmt|;
name|uint16_t
name|src_tcp_port
decl_stmt|;
name|uint8_t
name|ipv6
decl_stmt|;
name|uint8_t
name|time_stamp
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|rss_hash
decl_stmt|;
name|uint32_t
name|host_handle
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_config_lro_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get SNMP Statistics  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_fw_cds_get_snmp
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint64_t
name|phys_addr
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|uint16_t
name|cntxt_id
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_fw_cds_get_snmp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_snmp_stats
block|{
name|uint64_t
name|jabber_state
decl_stmt|;
name|uint64_t
name|false_carrier
decl_stmt|;
name|uint64_t
name|rsrvd
decl_stmt|;
name|uint64_t
name|mac_cntrl
decl_stmt|;
name|uint64_t
name|align_errors
decl_stmt|;
name|uint64_t
name|chksum_errors
decl_stmt|;
name|uint64_t
name|oversize_frames
decl_stmt|;
name|uint64_t
name|tx_errors
decl_stmt|;
name|uint64_t
name|mac_rcv_errors
decl_stmt|;
name|uint64_t
name|phy_rcv_errors
decl_stmt|;
name|uint64_t
name|rcv_pause
decl_stmt|;
name|uint64_t
name|tx_pause
decl_stmt|;
block|}
name|__packed
name|qla_snmp_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Enable Link Event Requests  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_link_event_req
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|enable
decl_stmt|;
name|uint8_t
name|get_clnk_params
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
name|qla_link_event_req_t
typedef|;
end_typedef

begin_comment
comment|/*  * Set MAC Receive Mode  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_set_mac_rcv_mode
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint32_t
name|mode
decl_stmt|;
define|#
directive|define
name|Q8_MAC_RCV_RESET_PROMISC_ALLMULTI
value|0x00
define|#
directive|define
name|Q8_MAC_RCV_ENABLE_PROMISCUOUS
value|0x01
define|#
directive|define
name|Q8_MAC_RCV_ENABLE_ALLMULTI
value|0x02
name|uint8_t
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|qla_set_mac_rcv_mode_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure IP Address  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_config_ipv4
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint64_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_CONFIG_CMD_IP_ENABLE
value|0x02
define|#
directive|define
name|Q8_CONFIG_CMD_IP_DISABLE
value|0x03
name|uint64_t
name|ipv4_addr
decl_stmt|;
block|}
name|__packed
name|qla_config_ipv4_t
typedef|;
end_typedef

begin_comment
comment|/*  * Configure LRO  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_config_lro
block|{
name|qla_fw_cds_hdr_t
name|hdr
decl_stmt|;
name|uint64_t
name|cmd
decl_stmt|;
define|#
directive|define
name|Q8_CONFIG_LRO_ENABLE
value|0x08
block|}
name|__packed
name|qla_config_lro_t
typedef|;
end_typedef

begin_comment
comment|/*  * Control Messages Received on SDS Ring  */
end_comment

begin_comment
comment|/* Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_cntrl_msg_hdr
block|{
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|err_code
decl_stmt|;
name|uint8_t
name|rsp_type
decl_stmt|;
name|uint8_t
name|comp_id
decl_stmt|;
name|uint16_t
name|tag
decl_stmt|;
define|#
directive|define
name|Q8_CTRL_MSG_TAG_DESC_COUNT_MASK
value|(0x7<< 5)
define|#
directive|define
name|Q8_CTRL_MSG_TAG_OWNER_MASK
value|(0x3<< 8)
define|#
directive|define
name|Q8_CTRL_MSG_TAG_OPCODE_MASK
value|(0x3F<< 10)
block|}
name|__packed
name|qla_cntrl_msg_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * definitions for rsp_type in qla_cntrl_msg_hdr_t  */
end_comment

begin_define
define|#
directive|define
name|Q8_CTRL_CONFIG_MAC_RSP
value|0x85
end_define

begin_define
define|#
directive|define
name|Q8_CTRL_LRO_FLOW_DELETE_RSP
value|0x86
end_define

begin_define
define|#
directive|define
name|Q8_CTRL_LRO_FLOW_ADD_FAILURE_RSP
value|0x87
end_define

begin_define
define|#
directive|define
name|Q8_CTRL_GET_SNMP_STATS_RSP
value|0x88
end_define

begin_define
define|#
directive|define
name|Q8_CTRL_GET_NETWORK_STATS_RSP
value|0x8C
end_define

begin_define
define|#
directive|define
name|Q8_CTRL_LINK_EVENT_NOTIFICATION
value|0x8D
end_define

begin_comment
comment|/*  * Configure MAC Response  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_config_mac_rsp
block|{
name|uint32_t
name|rval
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_config_mac_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * LRO Flow Response (can be LRO Flow Delete and LRO Flow Add Failure)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_lro_flow_rsp
block|{
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|rss_hash
decl_stmt|;
name|uint32_t
name|dst_ip
decl_stmt|;
name|uint32_t
name|src_ip
decl_stmt|;
name|uint16_t
name|dst_tcp_port
decl_stmt|;
name|uint16_t
name|src_tcp_port
decl_stmt|;
name|uint8_t
name|ipv6
decl_stmt|;
name|uint8_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|rsrvd1
decl_stmt|;
block|}
name|__packed
name|qla_lro_flow_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get SNMP Statistics Response  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_get_snmp_stats_rsp
block|{
name|uint64_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_get_snmp_stats_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Get Network Statistics Response  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_get_net_stats_rsp
block|{
name|uint64_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_get_net_stats_rsp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Link Event Notification  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_link_event
block|{
name|uint32_t
name|cable_oui
decl_stmt|;
name|uint16_t
name|cable_length
decl_stmt|;
name|uint16_t
name|link_speed
decl_stmt|;
define|#
directive|define
name|Q8_LE_SPEED_MASK
value|0xFFF
define|#
directive|define
name|Q8_LE_SPEED_10GBPS
value|0x710
define|#
directive|define
name|Q8_LE_SPEED_1GBPS
value|0x3E8
define|#
directive|define
name|Q8_LE_SPEED_100MBPS
value|0x064
define|#
directive|define
name|Q8_LE_SPEED_10MBPS
value|0x00A
name|uint8_t
name|link_up
decl_stmt|;
comment|/* 0 = down; else up */
name|uint8_t
name|mod_info
decl_stmt|;
define|#
directive|define
name|Q8_LE_MI_MODULE_NOT_PRESENT
value|0x01
define|#
directive|define
name|Q8_LE_MI_UNKNOWN_OPTICAL_MODULE
value|0x02
define|#
directive|define
name|Q8_LE_MI_SR_LR_OPTICAL_MODULE
value|0x03
define|#
directive|define
name|Q8_LE_MI_LRM_OPTICAL_MODULE
value|0x04
define|#
directive|define
name|Q8_LE_MI_SFP_1G_MODULE
value|0x05
define|#
directive|define
name|Q8_LE_MI_UNSUPPORTED_TWINAX
value|0x06
define|#
directive|define
name|Q8_LE_MI_UNSUPPORTED_TWINAX_LENGTH
value|0x07
define|#
directive|define
name|Q8_LE_MI_SUPPORTED_TWINAX
value|0x08
name|uint8_t
name|fduplex
decl_stmt|;
comment|/* 1 = full duplex; 0 = half duplex */
name|uint8_t
name|autoneg
decl_stmt|;
comment|/* 1 = autoneg enable; 0 = disabled */
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
name|__packed
name|qla_link_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_qla_sds
block|{
name|q80_stat_desc_t
modifier|*
name|sds_ring_base
decl_stmt|;
comment|/* start of sds ring */
name|uint32_t
name|sdsr_next
decl_stmt|;
comment|/* next entry in SDS ring to process */
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|void
modifier|*
name|rxb_free
decl_stmt|;
name|uint32_t
name|rx_free
decl_stmt|;
name|void
modifier|*
name|rxjb_free
decl_stmt|;
name|uint32_t
name|rxj_free
decl_stmt|;
specifier|volatile
name|uint32_t
name|rcv_active
decl_stmt|;
block|}
name|qla_sds_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QL_FRAME_HDR_SIZE
value|(ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN +\ 		sizeof (struct ip) + sizeof (struct tcphdr) + 16)
end_define

begin_comment
comment|/*  * struct for storing hardware specific information for a given interface  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_hw
block|{
struct|struct
block|{
name|uint32_t
name|lro
range|:
literal|1
decl_stmt|,
name|init_tx_cnxt
range|:
literal|1
decl_stmt|,
name|init_rx_cnxt
range|:
literal|1
decl_stmt|,
name|fduplex
range|:
literal|1
decl_stmt|,
name|autoneg
range|:
literal|1
decl_stmt|,
name|link_up
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|uint16_t
name|link_speed
decl_stmt|;
name|uint16_t
name|cable_length
decl_stmt|;
name|uint16_t
name|cable_oui
decl_stmt|;
name|uint8_t
name|mod_info
decl_stmt|;
name|uint8_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|max_rds_per_cntxt
decl_stmt|;
name|uint32_t
name|max_sds_per_cntxt
decl_stmt|;
name|uint32_t
name|max_rules_per_cntxt
decl_stmt|;
name|uint32_t
name|max_rcv_cntxts
decl_stmt|;
name|uint32_t
name|max_xmt_cntxts
decl_stmt|;
name|uint32_t
name|max_mtu
decl_stmt|;
name|uint32_t
name|max_lro
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|num_rds_rings
decl_stmt|;
name|uint16_t
name|num_sds_rings
decl_stmt|;
name|qla_dmabuf_t
name|dma_buf
decl_stmt|;
comment|/* Transmit Side */
name|q80_tx_cmd_t
modifier|*
name|tx_ring_base
decl_stmt|;
name|q80_tx_cntxt_req_t
modifier|*
name|tx_cntxt_req
decl_stmt|;
comment|/* TX Context Request */
name|bus_addr_t
name|tx_cntxt_req_paddr
decl_stmt|;
name|q80_tx_cntxt_rsp_t
modifier|*
name|tx_cntxt_rsp
decl_stmt|;
comment|/* TX Context Response */
name|bus_addr_t
name|tx_cntxt_rsp_paddr
decl_stmt|;
name|uint32_t
modifier|*
name|tx_cons
decl_stmt|;
comment|/* tx consumer shadow reg */
name|bus_addr_t
name|tx_cons_paddr
decl_stmt|;
specifier|volatile
name|uint32_t
name|txr_free
decl_stmt|;
comment|/* # of free entries in tx ring */
specifier|volatile
name|uint32_t
name|txr_next
decl_stmt|;
comment|/* # next available tx ring entry */
specifier|volatile
name|uint32_t
name|txr_comp
decl_stmt|;
comment|/* index of last tx entry completed */
name|uint32_t
name|tx_prod_reg
decl_stmt|;
comment|/* Receive Side */
specifier|volatile
name|uint32_t
name|rx_next
decl_stmt|;
comment|/* next standard rcv ring to arm fw */
specifier|volatile
name|int32_t
name|rxj_next
decl_stmt|;
comment|/* next jumbo rcv ring to arm fw */
specifier|volatile
name|int32_t
name|rx_in
decl_stmt|;
comment|/* next standard rcv ring to add mbufs */
specifier|volatile
name|int32_t
name|rxj_in
decl_stmt|;
comment|/* next jumbo rcv ring to add mbufs */
name|q80_rcv_cntxt_req_t
modifier|*
name|rx_cntxt_req
decl_stmt|;
comment|/* Rcv Context Request */
name|bus_addr_t
name|rx_cntxt_req_paddr
decl_stmt|;
name|q80_rcv_cntxt_rsp_t
modifier|*
name|rx_cntxt_rsp
decl_stmt|;
comment|/* Rcv Context Response */
name|bus_addr_t
name|rx_cntxt_rsp_paddr
decl_stmt|;
name|qla_sds_t
name|sds
index|[
name|MAX_SDS_RINGS
index|]
decl_stmt|;
name|uint8_t
name|frame_hdr
index|[
name|QL_FRAME_HDR_SIZE
index|]
decl_stmt|;
block|}
name|qla_hw_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QL_UPDATE_RDS_PRODUCER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|WRITE_REG32(ha, ((ha->hw.rx_cntxt_rsp)->rds_rsp[i].producer_reg +\ 		0x1b2000), val)
end_define

begin_define
define|#
directive|define
name|QL_UPDATE_TX_PRODUCER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|val
parameter_list|)
define|\
value|WRITE_REG32(ha, (ha->hw.tx_prod_reg + 0x1b2000), val)
end_define

begin_define
define|#
directive|define
name|QL_UPDATE_SDS_CONSUMER_INDEX
parameter_list|(
name|ha
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|WRITE_REG32(ha, ((ha->hw.rx_cntxt_rsp)->sds_rsp[i].consumer_reg +\ 		0x1b2000), val)
end_define

begin_define
define|#
directive|define
name|QL_CLEAR_INTERRUPTS
parameter_list|(
name|ha
parameter_list|)
define|\
value|if (ha->pci_func == 0) {\ 		WRITE_REG32(ha, Q8_INT_TARGET_STATUS_F0, 0xFFFFFFFF);\ 	} else {\ 		WRITE_REG32(ha, Q8_INT_TARGET_STATUS_F1, 0xFFFFFFFF);\ 	}\  #define QL_ENABLE_INTERRUPTS(ha, sds_index) \ 	{\ 		q80_rsp_sds_ring_t *rsp_sds;\ 		rsp_sds =&((ha->hw.rx_cntxt_rsp)->sds_rsp[sds_index]);\ 		WRITE_REG32(ha, (rsp_sds->intr_mask_reg + 0x1b2000), 0x1);\ 	}
end_define

begin_define
define|#
directive|define
name|QL_DISABLE_INTERRUPTS
parameter_list|(
name|ha
parameter_list|,
name|sds_index
parameter_list|)
define|\
value|{\ 		q80_rsp_sds_ring_t *rsp_sds;\ 		rsp_sds =&((ha->hw.rx_cntxt_rsp)->sds_rsp[sds_index]);\ 		WRITE_REG32(ha, (rsp_sds->intr_mask_reg + 0x1b2000), 0x0);\ 	}
end_define

begin_define
define|#
directive|define
name|QL_BUFFER_ALIGN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLA_HW_H_ */
end_comment

end_unit

