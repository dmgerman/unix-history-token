begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T3_CPL_H
end_ifndef

begin_define
define|#
directive|define
name|T3_CPL_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__BIG_ENDIAN_BITFIELD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<asm/byteorder.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|CPL_opcode
block|{
name|CPL_PASS_OPEN_REQ
init|=
literal|0x1
block|,
name|CPL_PASS_ACCEPT_RPL
init|=
literal|0x2
block|,
name|CPL_ACT_OPEN_REQ
init|=
literal|0x3
block|,
name|CPL_SET_TCB
init|=
literal|0x4
block|,
name|CPL_SET_TCB_FIELD
init|=
literal|0x5
block|,
name|CPL_GET_TCB
init|=
literal|0x6
block|,
name|CPL_PCMD
init|=
literal|0x7
block|,
name|CPL_CLOSE_CON_REQ
init|=
literal|0x8
block|,
name|CPL_CLOSE_LISTSRV_REQ
init|=
literal|0x9
block|,
name|CPL_ABORT_REQ
init|=
literal|0xA
block|,
name|CPL_ABORT_RPL
init|=
literal|0xB
block|,
name|CPL_TX_DATA
init|=
literal|0xC
block|,
name|CPL_RX_DATA_ACK
init|=
literal|0xD
block|,
name|CPL_TX_PKT
init|=
literal|0xE
block|,
name|CPL_RTE_DELETE_REQ
init|=
literal|0xF
block|,
name|CPL_RTE_WRITE_REQ
init|=
literal|0x10
block|,
name|CPL_RTE_READ_REQ
init|=
literal|0x11
block|,
name|CPL_L2T_WRITE_REQ
init|=
literal|0x12
block|,
name|CPL_L2T_READ_REQ
init|=
literal|0x13
block|,
name|CPL_SMT_WRITE_REQ
init|=
literal|0x14
block|,
name|CPL_SMT_READ_REQ
init|=
literal|0x15
block|,
name|CPL_TX_PKT_LSO
init|=
literal|0x16
block|,
name|CPL_PCMD_READ
init|=
literal|0x17
block|,
name|CPL_BARRIER
init|=
literal|0x18
block|,
name|CPL_TID_RELEASE
init|=
literal|0x1A
block|,
name|CPL_CLOSE_LISTSRV_RPL
init|=
literal|0x20
block|,
name|CPL_ERROR
init|=
literal|0x21
block|,
name|CPL_GET_TCB_RPL
init|=
literal|0x22
block|,
name|CPL_L2T_WRITE_RPL
init|=
literal|0x23
block|,
name|CPL_PCMD_READ_RPL
init|=
literal|0x24
block|,
name|CPL_PCMD_RPL
init|=
literal|0x25
block|,
name|CPL_PEER_CLOSE
init|=
literal|0x26
block|,
name|CPL_RTE_DELETE_RPL
init|=
literal|0x27
block|,
name|CPL_RTE_WRITE_RPL
init|=
literal|0x28
block|,
name|CPL_RX_DDP_COMPLETE
init|=
literal|0x29
block|,
name|CPL_RX_PHYS_ADDR
init|=
literal|0x2A
block|,
name|CPL_RX_PKT
init|=
literal|0x2B
block|,
name|CPL_RX_URG_NOTIFY
init|=
literal|0x2C
block|,
name|CPL_SET_TCB_RPL
init|=
literal|0x2D
block|,
name|CPL_SMT_WRITE_RPL
init|=
literal|0x2E
block|,
name|CPL_TX_DATA_ACK
init|=
literal|0x2F
block|,
name|CPL_ABORT_REQ_RSS
init|=
literal|0x30
block|,
name|CPL_ABORT_RPL_RSS
init|=
literal|0x31
block|,
name|CPL_CLOSE_CON_RPL
init|=
literal|0x32
block|,
name|CPL_ISCSI_HDR
init|=
literal|0x33
block|,
name|CPL_L2T_READ_RPL
init|=
literal|0x34
block|,
name|CPL_RDMA_CQE
init|=
literal|0x35
block|,
name|CPL_RDMA_CQE_READ_RSP
init|=
literal|0x36
block|,
name|CPL_RDMA_CQE_ERR
init|=
literal|0x37
block|,
name|CPL_RTE_READ_RPL
init|=
literal|0x38
block|,
name|CPL_RX_DATA
init|=
literal|0x39
block|,
name|CPL_ACT_OPEN_RPL
init|=
literal|0x40
block|,
name|CPL_PASS_OPEN_RPL
init|=
literal|0x41
block|,
name|CPL_RX_DATA_DDP
init|=
literal|0x42
block|,
name|CPL_SMT_READ_RPL
init|=
literal|0x43
block|,
name|CPL_ACT_ESTABLISH
init|=
literal|0x50
block|,
name|CPL_PASS_ESTABLISH
init|=
literal|0x51
block|,
name|CPL_PASS_ACCEPT_REQ
init|=
literal|0x70
block|,
name|CPL_ASYNC_NOTIF
init|=
literal|0x80
block|,
comment|/* fake opcode for async notifications */
name|CPL_TX_DMA_ACK
init|=
literal|0xA0
block|,
name|CPL_RDMA_READ_REQ
init|=
literal|0xA1
block|,
name|CPL_RDMA_TERMINATE
init|=
literal|0xA2
block|,
name|CPL_TRACE_PKT
init|=
literal|0xA3
block|,
name|CPL_RDMA_EC_STATUS
init|=
literal|0xA5
block|,
name|NUM_CPL_CMDS
comment|/* must be last and previous entries must be sorted */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|CPL_error
block|{
name|CPL_ERR_NONE
init|=
literal|0
block|,
name|CPL_ERR_TCAM_PARITY
init|=
literal|1
block|,
name|CPL_ERR_TCAM_FULL
init|=
literal|3
block|,
name|CPL_ERR_CONN_RESET
init|=
literal|20
block|,
name|CPL_ERR_CONN_EXIST
init|=
literal|22
block|,
name|CPL_ERR_ARP_MISS
init|=
literal|23
block|,
name|CPL_ERR_BAD_SYN
init|=
literal|24
block|,
name|CPL_ERR_CONN_TIMEDOUT
init|=
literal|30
block|,
name|CPL_ERR_XMIT_TIMEDOUT
init|=
literal|31
block|,
name|CPL_ERR_PERSIST_TIMEDOUT
init|=
literal|32
block|,
name|CPL_ERR_FINWAIT2_TIMEDOUT
init|=
literal|33
block|,
name|CPL_ERR_KEEPALIVE_TIMEDOUT
init|=
literal|34
block|,
name|CPL_ERR_RTX_NEG_ADVICE
init|=
literal|35
block|,
name|CPL_ERR_PERSIST_NEG_ADVICE
init|=
literal|36
block|,
name|CPL_ERR_ABORT_FAILED
init|=
literal|42
block|,
name|CPL_ERR_GENERAL
init|=
literal|99
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|CPL_CONN_POLICY_AUTO
init|=
literal|0
block|,
name|CPL_CONN_POLICY_ASK
init|=
literal|1
block|,
name|CPL_CONN_POLICY_DENY
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ULP_MODE_NONE
init|=
literal|0
block|,
name|ULP_MODE_TCP_DDP
init|=
literal|1
block|,
name|ULP_MODE_ISCSI
init|=
literal|2
block|,
name|ULP_MODE_RDMA
init|=
literal|4
block|,
name|ULP_MODE_TCPDDP
init|=
literal|5
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ULP_CRC_HEADER
init|=
literal|1
operator|<<
literal|0
block|,
name|ULP_CRC_DATA
init|=
literal|1
operator|<<
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|CPL_PASS_OPEN_ACCEPT
block|,
name|CPL_PASS_OPEN_REJECT
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|CPL_ABORT_SEND_RST
init|=
literal|0
block|,
name|CPL_ABORT_NO_RST
block|,
name|CPL_ABORT_POST_CLOSE_REQ
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* TX_PKT_LSO ethernet types */
name|CPL_ETH_II
block|,
name|CPL_ETH_II_VLAN
block|,
name|CPL_ETH_802_3
block|,
name|CPL_ETH_802_3_VLAN
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* TCP congestion control algorithms */
name|CONG_ALG_RENO
block|,
name|CONG_ALG_TAHOE
block|,
name|CONG_ALG_NEWRENO
block|,
name|CONG_ALG_HIGHSPEED
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* RSS hash type */
name|RSS_HASH_NONE
init|=
literal|0
block|,
name|RSS_HASH_2_TUPLE
init|=
literal|1
operator|<<
literal|0
block|,
name|RSS_HASH_4_TUPLE
init|=
literal|1
operator|<<
literal|1
block|}
enum|;
end_enum

begin_union
union|union
name|opcode_tid
block|{
name|__be32
name|opcode_tid
decl_stmt|;
name|__u8
name|opcode
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|S_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|V_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_OPCODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_OPCODE)& 0xFF)
end_define

begin_define
define|#
directive|define
name|G_TID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFFF)
end_define

begin_define
define|#
directive|define
name|S_HASHTYPE
value|22
end_define

begin_define
define|#
directive|define
name|M_HASHTYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|G_HASHTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_HASHTYPE)& M_HASHTYPE)
end_define

begin_define
define|#
directive|define
name|S_QNUM
value|0
end_define

begin_define
define|#
directive|define
name|G_QNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QNUM)& 0xFFFF)
end_define

begin_comment
comment|/* tid is assumed to be 24-bits */
end_comment

begin_define
define|#
directive|define
name|MK_OPCODE_TID
parameter_list|(
name|opcode
parameter_list|,
name|tid
parameter_list|)
value|(V_OPCODE(opcode) | (tid))
end_define

begin_define
define|#
directive|define
name|OPCODE_TID
parameter_list|(
name|cmd
parameter_list|)
value|((cmd)->ot.opcode_tid)
end_define

begin_comment
comment|/* extract the TID from a CPL command */
end_comment

begin_define
define|#
directive|define
name|GET_TID
parameter_list|(
name|cmd
parameter_list|)
value|(G_TID(ntohl(OPCODE_TID(cmd))))
end_define

begin_struct
struct|struct
name|tcp_options
block|{
name|__be16
name|mss
decl_stmt|;
name|__u8
name|wsf
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
label|:
literal|5
expr_stmt|;
name|__u8
name|ecn
range|:
literal|1
decl_stmt|;
name|__u8
name|sack
range|:
literal|1
decl_stmt|;
name|__u8
name|tstamp
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|tstamp
range|:
literal|1
decl_stmt|;
name|__u8
name|sack
range|:
literal|1
decl_stmt|;
name|__u8
name|ecn
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|5
expr_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rss_header
block|{
name|__u8
name|opcode
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|cpu_idx
range|:
literal|6
decl_stmt|;
name|__u8
name|hash_type
range|:
literal|2
decl_stmt|;
else|#
directive|else
name|__u8
name|hash_type
range|:
literal|2
decl_stmt|;
name|__u8
name|cpu_idx
range|:
literal|6
decl_stmt|;
endif|#
directive|endif
name|__be16
name|cq_idx
decl_stmt|;
name|__be32
name|rss_hash_val
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|CHELSIO_FW
end_ifndef

begin_struct
struct|struct
name|work_request_hdr
block|{
name|__be32
name|wr_hi
decl_stmt|;
name|__be32
name|wr_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* wr_hi fields */
end_comment

begin_define
define|#
directive|define
name|S_WR_SGE_CREDITS
value|0
end_define

begin_define
define|#
directive|define
name|M_WR_SGE_CREDITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_WR_SGE_CREDITS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_SGE_CREDITS)
end_define

begin_define
define|#
directive|define
name|G_WR_SGE_CREDITS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_SGE_CREDITS)& M_WR_SGE_CREDITS)
end_define

begin_define
define|#
directive|define
name|S_WR_SGLSFLT
value|8
end_define

begin_define
define|#
directive|define
name|M_WR_SGLSFLT
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_WR_SGLSFLT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_SGLSFLT)
end_define

begin_define
define|#
directive|define
name|G_WR_SGLSFLT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_SGLSFLT)& M_WR_SGLSFLT)
end_define

begin_define
define|#
directive|define
name|S_WR_BCNTLFLT
value|16
end_define

begin_define
define|#
directive|define
name|M_WR_BCNTLFLT
value|0xF
end_define

begin_define
define|#
directive|define
name|V_WR_BCNTLFLT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_BCNTLFLT)
end_define

begin_define
define|#
directive|define
name|G_WR_BCNTLFLT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_BCNTLFLT)& M_WR_BCNTLFLT)
end_define

begin_define
define|#
directive|define
name|S_WR_DATATYPE
value|20
end_define

begin_define
define|#
directive|define
name|V_WR_DATATYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_DATATYPE)
end_define

begin_define
define|#
directive|define
name|F_WR_DATATYPE
value|V_WR_DATATYPE(1U)
end_define

begin_define
define|#
directive|define
name|S_WR_COMPL
value|21
end_define

begin_define
define|#
directive|define
name|V_WR_COMPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_COMPL)
end_define

begin_define
define|#
directive|define
name|F_WR_COMPL
value|V_WR_COMPL(1U)
end_define

begin_define
define|#
directive|define
name|S_WR_EOP
value|22
end_define

begin_define
define|#
directive|define
name|V_WR_EOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_EOP)
end_define

begin_define
define|#
directive|define
name|F_WR_EOP
value|V_WR_EOP(1U)
end_define

begin_define
define|#
directive|define
name|S_WR_SOP
value|23
end_define

begin_define
define|#
directive|define
name|V_WR_SOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_SOP)
end_define

begin_define
define|#
directive|define
name|F_WR_SOP
value|V_WR_SOP(1U)
end_define

begin_define
define|#
directive|define
name|S_WR_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_WR_OP
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_WR_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_OP)
end_define

begin_define
define|#
directive|define
name|G_WR_OP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_OP)& M_WR_OP)
end_define

begin_comment
comment|/* wr_lo fields */
end_comment

begin_define
define|#
directive|define
name|S_WR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_WR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_WR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_LEN)
end_define

begin_define
define|#
directive|define
name|G_WR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_LEN)& M_WR_LEN)
end_define

begin_define
define|#
directive|define
name|S_WR_TID
value|8
end_define

begin_define
define|#
directive|define
name|M_WR_TID
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|V_WR_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_TID)
end_define

begin_define
define|#
directive|define
name|G_WR_TID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_TID)& M_WR_TID)
end_define

begin_define
define|#
directive|define
name|S_WR_CR_FLUSH
value|30
end_define

begin_define
define|#
directive|define
name|V_WR_CR_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_CR_FLUSH)
end_define

begin_define
define|#
directive|define
name|F_WR_CR_FLUSH
value|V_WR_CR_FLUSH(1U)
end_define

begin_define
define|#
directive|define
name|S_WR_GEN
value|31
end_define

begin_define
define|#
directive|define
name|V_WR_GEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_GEN)
end_define

begin_define
define|#
directive|define
name|F_WR_GEN
value|V_WR_GEN(1U)
end_define

begin_define
define|#
directive|define
name|WR_HDR
value|struct work_request_hdr wr
end_define

begin_define
define|#
directive|define
name|RSS_HDR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WR_HDR
end_define

begin_define
define|#
directive|define
name|RSS_HDR
value|struct rss_header rss_hdr;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* option 0 lower-half fields */
end_comment

begin_define
define|#
directive|define
name|S_CPL_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_STATUS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_CPL_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_STATUS)
end_define

begin_define
define|#
directive|define
name|G_CPL_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CPL_STATUS)& M_CPL_STATUS)
end_define

begin_define
define|#
directive|define
name|S_INJECT_TIMER
value|6
end_define

begin_define
define|#
directive|define
name|V_INJECT_TIMER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_INJECT_TIMER)
end_define

begin_define
define|#
directive|define
name|F_INJECT_TIMER
value|V_INJECT_TIMER(1U)
end_define

begin_define
define|#
directive|define
name|S_NO_OFFLOAD
value|7
end_define

begin_define
define|#
directive|define
name|V_NO_OFFLOAD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NO_OFFLOAD)
end_define

begin_define
define|#
directive|define
name|F_NO_OFFLOAD
value|V_NO_OFFLOAD(1U)
end_define

begin_define
define|#
directive|define
name|S_ULP_MODE
value|8
end_define

begin_define
define|#
directive|define
name|M_ULP_MODE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_MODE)
end_define

begin_define
define|#
directive|define
name|G_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ULP_MODE)& M_ULP_MODE)
end_define

begin_define
define|#
directive|define
name|S_RCV_BUFSIZ
value|12
end_define

begin_define
define|#
directive|define
name|M_RCV_BUFSIZ
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|V_RCV_BUFSIZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RCV_BUFSIZ)
end_define

begin_define
define|#
directive|define
name|G_RCV_BUFSIZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RCV_BUFSIZ)& M_RCV_BUFSIZ)
end_define

begin_define
define|#
directive|define
name|S_TOS
value|26
end_define

begin_define
define|#
directive|define
name|M_TOS
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_TOS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TOS)
end_define

begin_define
define|#
directive|define
name|G_TOS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TOS)& M_TOS)
end_define

begin_comment
comment|/* option 0 upper-half fields */
end_comment

begin_define
define|#
directive|define
name|S_DELACK
value|0
end_define

begin_define
define|#
directive|define
name|V_DELACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DELACK)
end_define

begin_define
define|#
directive|define
name|F_DELACK
value|V_DELACK(1U)
end_define

begin_define
define|#
directive|define
name|S_NO_CONG
value|1
end_define

begin_define
define|#
directive|define
name|V_NO_CONG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NO_CONG)
end_define

begin_define
define|#
directive|define
name|F_NO_CONG
value|V_NO_CONG(1U)
end_define

begin_define
define|#
directive|define
name|S_SRC_MAC_SEL
value|2
end_define

begin_define
define|#
directive|define
name|M_SRC_MAC_SEL
value|0x3
end_define

begin_define
define|#
directive|define
name|V_SRC_MAC_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SRC_MAC_SEL)
end_define

begin_define
define|#
directive|define
name|G_SRC_MAC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SRC_MAC_SEL)& M_SRC_MAC_SEL)
end_define

begin_define
define|#
directive|define
name|S_L2T_IDX
value|4
end_define

begin_define
define|#
directive|define
name|M_L2T_IDX
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_L2T_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_IDX)
end_define

begin_define
define|#
directive|define
name|G_L2T_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_IDX)& M_L2T_IDX)
end_define

begin_define
define|#
directive|define
name|S_TX_CHANNEL
value|15
end_define

begin_define
define|#
directive|define
name|V_TX_CHANNEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_CHANNEL)
end_define

begin_define
define|#
directive|define
name|F_TX_CHANNEL
value|V_TX_CHANNEL(1U)
end_define

begin_define
define|#
directive|define
name|S_TCAM_BYPASS
value|16
end_define

begin_define
define|#
directive|define
name|V_TCAM_BYPASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCAM_BYPASS)
end_define

begin_define
define|#
directive|define
name|F_TCAM_BYPASS
value|V_TCAM_BYPASS(1U)
end_define

begin_define
define|#
directive|define
name|S_NAGLE
value|17
end_define

begin_define
define|#
directive|define
name|V_NAGLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NAGLE)
end_define

begin_define
define|#
directive|define
name|F_NAGLE
value|V_NAGLE(1U)
end_define

begin_define
define|#
directive|define
name|S_WND_SCALE
value|18
end_define

begin_define
define|#
directive|define
name|M_WND_SCALE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_WND_SCALE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WND_SCALE)
end_define

begin_define
define|#
directive|define
name|G_WND_SCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WND_SCALE)& M_WND_SCALE)
end_define

begin_define
define|#
directive|define
name|S_KEEP_ALIVE
value|22
end_define

begin_define
define|#
directive|define
name|V_KEEP_ALIVE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEEP_ALIVE)
end_define

begin_define
define|#
directive|define
name|F_KEEP_ALIVE
value|V_KEEP_ALIVE(1U)
end_define

begin_define
define|#
directive|define
name|S_MAX_RETRANS
value|23
end_define

begin_define
define|#
directive|define
name|M_MAX_RETRANS
value|0xF
end_define

begin_define
define|#
directive|define
name|V_MAX_RETRANS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_MAX_RETRANS)
end_define

begin_define
define|#
directive|define
name|G_MAX_RETRANS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_MAX_RETRANS)& M_MAX_RETRANS)
end_define

begin_define
define|#
directive|define
name|S_MAX_RETRANS_OVERRIDE
value|27
end_define

begin_define
define|#
directive|define
name|V_MAX_RETRANS_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_MAX_RETRANS_OVERRIDE)
end_define

begin_define
define|#
directive|define
name|F_MAX_RETRANS_OVERRIDE
value|V_MAX_RETRANS_OVERRIDE(1U)
end_define

begin_define
define|#
directive|define
name|S_MSS_IDX
value|28
end_define

begin_define
define|#
directive|define
name|M_MSS_IDX
value|0xF
end_define

begin_define
define|#
directive|define
name|V_MSS_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_MSS_IDX)
end_define

begin_define
define|#
directive|define
name|G_MSS_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_MSS_IDX)& M_MSS_IDX)
end_define

begin_comment
comment|/* option 1 fields */
end_comment

begin_define
define|#
directive|define
name|S_RSS_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|V_RSS_ENABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSS_ENABLE)
end_define

begin_define
define|#
directive|define
name|F_RSS_ENABLE
value|V_RSS_ENABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_RSS_MASK_LEN
value|1
end_define

begin_define
define|#
directive|define
name|M_RSS_MASK_LEN
value|0x7
end_define

begin_define
define|#
directive|define
name|V_RSS_MASK_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSS_MASK_LEN)
end_define

begin_define
define|#
directive|define
name|G_RSS_MASK_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RSS_MASK_LEN)& M_RSS_MASK_LEN)
end_define

begin_define
define|#
directive|define
name|S_CPU_IDX
value|4
end_define

begin_define
define|#
directive|define
name|M_CPU_IDX
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_CPU_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPU_IDX)
end_define

begin_define
define|#
directive|define
name|G_CPU_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CPU_IDX)& M_CPU_IDX)
end_define

begin_define
define|#
directive|define
name|S_MAC_MATCH_VALID
value|18
end_define

begin_define
define|#
directive|define
name|V_MAC_MATCH_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_MAC_MATCH_VALID)
end_define

begin_define
define|#
directive|define
name|F_MAC_MATCH_VALID
value|V_MAC_MATCH_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_CONN_POLICY
value|19
end_define

begin_define
define|#
directive|define
name|M_CONN_POLICY
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CONN_POLICY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CONN_POLICY)
end_define

begin_define
define|#
directive|define
name|G_CONN_POLICY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CONN_POLICY)& M_CONN_POLICY)
end_define

begin_define
define|#
directive|define
name|S_SYN_DEFENSE
value|21
end_define

begin_define
define|#
directive|define
name|V_SYN_DEFENSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_DEFENSE)
end_define

begin_define
define|#
directive|define
name|F_SYN_DEFENSE
value|V_SYN_DEFENSE(1U)
end_define

begin_define
define|#
directive|define
name|S_VLAN_PRI
value|22
end_define

begin_define
define|#
directive|define
name|M_VLAN_PRI
value|0x3
end_define

begin_define
define|#
directive|define
name|V_VLAN_PRI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_VLAN_PRI)
end_define

begin_define
define|#
directive|define
name|G_VLAN_PRI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_VLAN_PRI)& M_VLAN_PRI)
end_define

begin_define
define|#
directive|define
name|S_VLAN_PRI_VALID
value|24
end_define

begin_define
define|#
directive|define
name|V_VLAN_PRI_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_VLAN_PRI_VALID)
end_define

begin_define
define|#
directive|define
name|F_VLAN_PRI_VALID
value|V_VLAN_PRI_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_PKT_TYPE
value|25
end_define

begin_define
define|#
directive|define
name|M_PKT_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PKT_TYPE)
end_define

begin_define
define|#
directive|define
name|G_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PKT_TYPE)& M_PKT_TYPE)
end_define

begin_define
define|#
directive|define
name|S_MAC_MATCH
value|27
end_define

begin_define
define|#
directive|define
name|M_MAC_MATCH
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_MAC_MATCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_MAC_MATCH)
end_define

begin_define
define|#
directive|define
name|G_MAC_MATCH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_MAC_MATCH)& M_MAC_MATCH)
end_define

begin_comment
comment|/* option 2 fields */
end_comment

begin_define
define|#
directive|define
name|S_CPU_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|M_CPU_INDEX
value|0x7F
end_define

begin_define
define|#
directive|define
name|V_CPU_INDEX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPU_INDEX)
end_define

begin_define
define|#
directive|define
name|G_CPU_INDEX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CPU_INDEX)& M_CPU_INDEX)
end_define

begin_define
define|#
directive|define
name|S_CPU_INDEX_VALID
value|7
end_define

begin_define
define|#
directive|define
name|V_CPU_INDEX_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPU_INDEX_VALID)
end_define

begin_define
define|#
directive|define
name|F_CPU_INDEX_VALID
value|V_CPU_INDEX_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_COALESCE
value|8
end_define

begin_define
define|#
directive|define
name|M_RX_COALESCE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RX_COALESCE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_COALESCE)
end_define

begin_define
define|#
directive|define
name|G_RX_COALESCE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_COALESCE)& M_RX_COALESCE)
end_define

begin_define
define|#
directive|define
name|S_RX_COALESCE_VALID
value|10
end_define

begin_define
define|#
directive|define
name|V_RX_COALESCE_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_COALESCE_VALID)
end_define

begin_define
define|#
directive|define
name|F_RX_COALESCE_VALID
value|V_RX_COALESCE_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_CONG_CONTROL_FLAVOR
value|11
end_define

begin_define
define|#
directive|define
name|M_CONG_CONTROL_FLAVOR
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CONG_CONTROL_FLAVOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CONG_CONTROL_FLAVOR)
end_define

begin_define
define|#
directive|define
name|G_CONG_CONTROL_FLAVOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CONG_CONTROL_FLAVOR)& M_CONG_CONTROL_FLAVOR)
end_define

begin_define
define|#
directive|define
name|S_PACING_FLAVOR
value|13
end_define

begin_define
define|#
directive|define
name|M_PACING_FLAVOR
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PACING_FLAVOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PACING_FLAVOR)
end_define

begin_define
define|#
directive|define
name|G_PACING_FLAVOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PACING_FLAVOR)& M_PACING_FLAVOR)
end_define

begin_define
define|#
directive|define
name|S_FLAVORS_VALID
value|15
end_define

begin_define
define|#
directive|define
name|V_FLAVORS_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FLAVORS_VALID)
end_define

begin_define
define|#
directive|define
name|F_FLAVORS_VALID
value|V_FLAVORS_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_FC_DISABLE
value|16
end_define

begin_define
define|#
directive|define
name|V_RX_FC_DISABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_FC_DISABLE)
end_define

begin_define
define|#
directive|define
name|F_RX_FC_DISABLE
value|V_RX_FC_DISABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_FC_VALID
value|17
end_define

begin_define
define|#
directive|define
name|V_RX_FC_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_FC_VALID)
end_define

begin_define
define|#
directive|define
name|F_RX_FC_VALID
value|V_RX_FC_VALID(1U)
end_define

begin_struct
struct|struct
name|cpl_pass_open_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|opt0h
decl_stmt|;
name|__be32
name|opt0l
decl_stmt|;
name|__be32
name|peer_netmask
decl_stmt|;
name|__be32
name|opt1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pass_open_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__u8
name|resvd
index|[
literal|7
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pass_establish
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|tos_tid
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
name|__be16
name|tcp_opt
decl_stmt|;
name|__be32
name|snd_isn
decl_stmt|;
name|__be32
name|rcv_isn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_pass_establish.tos_tid fields */
end_comment

begin_define
define|#
directive|define
name|S_PASS_OPEN_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_PASS_OPEN_TID
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_PASS_OPEN_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PASS_OPEN_TID)
end_define

begin_define
define|#
directive|define
name|G_PASS_OPEN_TID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PASS_OPEN_TID)& M_PASS_OPEN_TID)
end_define

begin_define
define|#
directive|define
name|S_PASS_OPEN_TOS
value|24
end_define

begin_define
define|#
directive|define
name|M_PASS_OPEN_TOS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_PASS_OPEN_TOS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PASS_OPEN_TOS)
end_define

begin_define
define|#
directive|define
name|G_PASS_OPEN_TOS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PASS_OPEN_TOS)& M_PASS_OPEN_TOS)
end_define

begin_comment
comment|/* cpl_pass_establish.l2t_idx fields */
end_comment

begin_define
define|#
directive|define
name|S_L2T_IDX16
value|5
end_define

begin_define
define|#
directive|define
name|M_L2T_IDX16
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_L2T_IDX16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_IDX16)
end_define

begin_define
define|#
directive|define
name|G_L2T_IDX16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_IDX16)& M_L2T_IDX16)
end_define

begin_comment
comment|/* cpl_pass_establish.tcp_opt fields (also applies act_open_establish) */
end_comment

begin_define
define|#
directive|define
name|G_TCPOPT_WSCALE_OK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 1)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_SACK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 1)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_TSTAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 1)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_SND_WSCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_MSS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_struct
struct|struct
name|cpl_pass_accept_req
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|tos_tid
decl_stmt|;
name|struct
name|tcp_options
name|tcp_options
decl_stmt|;
name|__u8
name|dst_mac
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|vlan_tag
decl_stmt|;
name|__u8
name|src_mac
index|[
literal|6
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
label|:
literal|3
expr_stmt|;
name|__u8
name|addr_idx
range|:
literal|3
decl_stmt|;
name|__u8
name|port_idx
range|:
literal|1
decl_stmt|;
name|__u8
name|exact_match
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|exact_match
range|:
literal|1
decl_stmt|;
name|__u8
name|port_idx
range|:
literal|1
decl_stmt|;
name|__u8
name|addr_idx
range|:
literal|3
decl_stmt|;
name|__u8
label|:
literal|3
expr_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd
decl_stmt|;
name|__be32
name|rcv_isn
decl_stmt|;
name|__be32
name|rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pass_accept_rpl
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|opt0h
decl_stmt|;
name|__be32
name|opt0l_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_act_open_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|opt0h
decl_stmt|;
name|__be32
name|opt0l
decl_stmt|;
name|__be32
name|params
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_act_open_req.params fields */
end_comment

begin_define
define|#
directive|define
name|S_AOPEN_VLAN_PRI
value|9
end_define

begin_define
define|#
directive|define
name|M_AOPEN_VLAN_PRI
value|0x3
end_define

begin_define
define|#
directive|define
name|V_AOPEN_VLAN_PRI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_VLAN_PRI)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_VLAN_PRI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_VLAN_PRI)& M_AOPEN_VLAN_PRI)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_VLAN_PRI_VALID
value|11
end_define

begin_define
define|#
directive|define
name|V_AOPEN_VLAN_PRI_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_VLAN_PRI_VALID)
end_define

begin_define
define|#
directive|define
name|F_AOPEN_VLAN_PRI_VALID
value|V_AOPEN_VLAN_PRI_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_PKT_TYPE
value|12
end_define

begin_define
define|#
directive|define
name|M_AOPEN_PKT_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_AOPEN_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_PKT_TYPE)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_PKT_TYPE)& M_AOPEN_PKT_TYPE)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_MAC_MATCH
value|14
end_define

begin_define
define|#
directive|define
name|M_AOPEN_MAC_MATCH
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_AOPEN_MAC_MATCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_MAC_MATCH)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_MAC_MATCH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_MAC_MATCH)& M_AOPEN_MAC_MATCH)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_MAC_MATCH_VALID
value|19
end_define

begin_define
define|#
directive|define
name|V_AOPEN_MAC_MATCH_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_MAC_MATCH_VALID)
end_define

begin_define
define|#
directive|define
name|F_AOPEN_MAC_MATCH_VALID
value|V_AOPEN_MAC_MATCH_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_IFF_VLAN
value|20
end_define

begin_define
define|#
directive|define
name|M_AOPEN_IFF_VLAN
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_AOPEN_IFF_VLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_IFF_VLAN)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_IFF_VLAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_IFF_VLAN)& M_AOPEN_IFF_VLAN)
end_define

begin_struct
struct|struct
name|cpl_act_open_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|atid
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_act_establish
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|local_port
decl_stmt|;
name|__be16
name|peer_port
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|peer_ip
decl_stmt|;
name|__be32
name|tos_tid
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
name|__be16
name|tcp_opt
decl_stmt|;
name|__be32
name|snd_isn
decl_stmt|;
name|__be32
name|rcv_isn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_get_tcb
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|cpuno
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_get_tcb_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_set_tcb
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|reply
decl_stmt|;
name|__u8
name|cpu_idx
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_set_tcb.reply fields */
end_comment

begin_define
define|#
directive|define
name|S_NO_REPLY
value|7
end_define

begin_define
define|#
directive|define
name|V_NO_REPLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NO_REPLY)
end_define

begin_define
define|#
directive|define
name|F_NO_REPLY
value|V_NO_REPLY(1U)
end_define

begin_struct
struct|struct
name|cpl_set_tcb_field
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|reply
decl_stmt|;
name|__u8
name|cpu_idx
decl_stmt|;
name|__be16
name|word
decl_stmt|;
name|__be64
name|mask
decl_stmt|;
name|__be64
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_set_tcb_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pcmd
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|src
range|:
literal|1
decl_stmt|;
name|__u8
name|bundle
range|:
literal|1
decl_stmt|;
name|__u8
name|channel
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|5
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|5
expr_stmt|;
name|__u8
name|channel
range|:
literal|1
decl_stmt|;
name|__u8
name|bundle
range|:
literal|1
decl_stmt|;
name|__u8
name|src
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|__be32
name|pcmd_parm
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pcmd_reply
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_close_con_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_close_con_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be32
name|snd_nxt
decl_stmt|;
name|__be32
name|rcv_nxt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_close_listserv_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd0
decl_stmt|;
name|__u8
name|cpu_idx
decl_stmt|;
name|__be16
name|rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_close_listserv_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_abort_req_rss
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd0
decl_stmt|;
name|__u8
name|rsvd1
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd2
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_abort_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd0
decl_stmt|;
name|__u8
name|rsvd1
decl_stmt|;
name|__u8
name|cmd
decl_stmt|;
name|__u8
name|rsvd2
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_abort_rpl_rss
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd0
decl_stmt|;
name|__u8
name|rsvd1
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd2
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_abort_rpl
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd0
decl_stmt|;
name|__u8
name|rsvd1
decl_stmt|;
name|__u8
name|cmd
decl_stmt|;
name|__u8
name|rsvd2
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_peer_close
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rcv_nxt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tx_data_wr
block|{
name|__be32
name|wr_hi
decl_stmt|;
name|__be32
name|wr_lo
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|flags
decl_stmt|;
name|__be32
name|sndseq
decl_stmt|;
name|__be32
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* tx_data_wr.param fields */
end_comment

begin_define
define|#
directive|define
name|S_TX_PORT
value|0
end_define

begin_define
define|#
directive|define
name|M_TX_PORT
value|0x7
end_define

begin_define
define|#
directive|define
name|V_TX_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_PORT)
end_define

begin_define
define|#
directive|define
name|G_TX_PORT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_PORT)& M_TX_PORT)
end_define

begin_define
define|#
directive|define
name|S_TX_MSS
value|4
end_define

begin_define
define|#
directive|define
name|M_TX_MSS
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TX_MSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_MSS)
end_define

begin_define
define|#
directive|define
name|G_TX_MSS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_MSS)& M_TX_MSS)
end_define

begin_define
define|#
directive|define
name|S_TX_QOS
value|8
end_define

begin_define
define|#
directive|define
name|M_TX_QOS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_TX_QOS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_QOS)
end_define

begin_define
define|#
directive|define
name|G_TX_QOS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_QOS)& M_TX_QOS)
end_define

begin_define
define|#
directive|define
name|S_TX_SNDBUF
value|16
end_define

begin_define
define|#
directive|define
name|M_TX_SNDBUF
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|V_TX_SNDBUF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_SNDBUF)
end_define

begin_define
define|#
directive|define
name|G_TX_SNDBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_SNDBUF)& M_TX_SNDBUF)
end_define

begin_struct
struct|struct
name|cpl_tx_data
block|{
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be16
name|urg
decl_stmt|;
name|__be16
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_data.flags fields */
end_comment

begin_define
define|#
directive|define
name|S_TX_ULP_SUBMODE
value|6
end_define

begin_define
define|#
directive|define
name|M_TX_ULP_SUBMODE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TX_ULP_SUBMODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_ULP_SUBMODE)
end_define

begin_define
define|#
directive|define
name|G_TX_ULP_SUBMODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_ULP_SUBMODE)& M_TX_ULP_SUBMODE)
end_define

begin_define
define|#
directive|define
name|S_TX_ULP_MODE
value|10
end_define

begin_define
define|#
directive|define
name|M_TX_ULP_MODE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TX_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_ULP_MODE)
end_define

begin_define
define|#
directive|define
name|G_TX_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_ULP_MODE)& M_TX_ULP_MODE)
end_define

begin_define
define|#
directive|define
name|S_TX_SHOVE
value|14
end_define

begin_define
define|#
directive|define
name|V_TX_SHOVE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_SHOVE)
end_define

begin_define
define|#
directive|define
name|F_TX_SHOVE
value|V_TX_SHOVE(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_MORE
value|15
end_define

begin_define
define|#
directive|define
name|V_TX_MORE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_MORE)
end_define

begin_define
define|#
directive|define
name|F_TX_MORE
value|V_TX_MORE(1U)
end_define

begin_comment
comment|/* additional tx_data_wr.flags fields */
end_comment

begin_define
define|#
directive|define
name|S_TX_CPU_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_TX_CPU_IDX
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_TX_CPU_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_CPU_IDX)
end_define

begin_define
define|#
directive|define
name|G_TX_CPU_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_CPU_IDX)& M_TX_CPU_IDX)
end_define

begin_define
define|#
directive|define
name|S_TX_URG
value|16
end_define

begin_define
define|#
directive|define
name|V_TX_URG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_URG)
end_define

begin_define
define|#
directive|define
name|F_TX_URG
value|V_TX_URG(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_CLOSE
value|17
end_define

begin_define
define|#
directive|define
name|V_TX_CLOSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_CLOSE)
end_define

begin_define
define|#
directive|define
name|F_TX_CLOSE
value|V_TX_CLOSE(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_INIT
value|18
end_define

begin_define
define|#
directive|define
name|V_TX_INIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_INIT)
end_define

begin_define
define|#
directive|define
name|F_TX_INIT
value|V_TX_INIT(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_IMM_ACK
value|19
end_define

begin_define
define|#
directive|define
name|V_TX_IMM_ACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_IMM_ACK)
end_define

begin_define
define|#
directive|define
name|F_TX_IMM_ACK
value|V_TX_IMM_ACK(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_IMM_DMA
value|20
end_define

begin_define
define|#
directive|define
name|V_TX_IMM_DMA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_IMM_DMA)
end_define

begin_define
define|#
directive|define
name|F_TX_IMM_DMA
value|V_TX_IMM_DMA(1U)
end_define

begin_struct
struct|struct
name|cpl_tx_data_ack
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|ack_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_wr_ack
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|credits
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
name|__be32
name|snd_nxt
decl_stmt|;
name|__be32
name|snd_una
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rdma_ec_status
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mngt_pktsched_wr
block|{
name|__be32
name|wr_hi
decl_stmt|;
name|__be32
name|wr_lo
decl_stmt|;
name|__u8
name|mngt_opcode
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|7
index|]
decl_stmt|;
name|__u8
name|sched
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
name|__u8
name|min
decl_stmt|;
name|__u8
name|max
decl_stmt|;
name|__u8
name|binding
decl_stmt|;
name|__u8
name|rsvd1
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_iscsi_hdr
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|pdu_len_ddp
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__be16
name|urg
decl_stmt|;
name|__u8
name|rsvd
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_iscsi_hdr.pdu_len_ddp fields */
end_comment

begin_define
define|#
directive|define
name|S_ISCSI_PDU_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_ISCSI_PDU_LEN
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|V_ISCSI_PDU_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ISCSI_PDU_LEN)
end_define

begin_define
define|#
directive|define
name|G_ISCSI_PDU_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ISCSI_PDU_LEN)& M_ISCSI_PDU_LEN)
end_define

begin_define
define|#
directive|define
name|S_ISCSI_DDP
value|15
end_define

begin_define
define|#
directive|define
name|V_ISCSI_DDP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ISCSI_DDP)
end_define

begin_define
define|#
directive|define
name|F_ISCSI_DDP
value|V_ISCSI_DDP(1U)
end_define

begin_struct
struct|struct
name|cpl_rx_data
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__be16
name|urg
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|dack_mode
range|:
literal|2
decl_stmt|;
name|__u8
name|psh
range|:
literal|1
decl_stmt|;
name|__u8
name|heartbeat
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|4
expr_stmt|;
name|__u8
name|heartbeat
range|:
literal|1
decl_stmt|;
name|__u8
name|psh
range|:
literal|1
decl_stmt|;
name|__u8
name|dack_mode
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_data_ack
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|credit_dack
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_rx_data_ack.ack_seq fields */
end_comment

begin_define
define|#
directive|define
name|S_RX_CREDITS
value|0
end_define

begin_define
define|#
directive|define
name|M_RX_CREDITS
value|0x7FFFFFF
end_define

begin_define
define|#
directive|define
name|V_RX_CREDITS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_CREDITS)
end_define

begin_define
define|#
directive|define
name|G_RX_CREDITS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_CREDITS)& M_RX_CREDITS)
end_define

begin_define
define|#
directive|define
name|S_RX_MODULATE
value|27
end_define

begin_define
define|#
directive|define
name|V_RX_MODULATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_MODULATE)
end_define

begin_define
define|#
directive|define
name|F_RX_MODULATE
value|V_RX_MODULATE(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_FORCE_ACK
value|28
end_define

begin_define
define|#
directive|define
name|V_RX_FORCE_ACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_FORCE_ACK)
end_define

begin_define
define|#
directive|define
name|F_RX_FORCE_ACK
value|V_RX_FORCE_ACK(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_DACK_MODE
value|29
end_define

begin_define
define|#
directive|define
name|M_RX_DACK_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RX_DACK_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_DACK_MODE)
end_define

begin_define
define|#
directive|define
name|G_RX_DACK_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_DACK_MODE)& M_RX_DACK_MODE)
end_define

begin_define
define|#
directive|define
name|S_RX_DACK_CHANGE
value|31
end_define

begin_define
define|#
directive|define
name|V_RX_DACK_CHANGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_DACK_CHANGE)
end_define

begin_define
define|#
directive|define
name|F_RX_DACK_CHANGE
value|V_RX_DACK_CHANGE(1U)
end_define

begin_struct
struct|struct
name|cpl_rx_urg_notify
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_ddp_complete
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|ddp_report
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_data_ddp
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|urg
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
union|union
block|{
name|__be32
name|nxt_seq
decl_stmt|;
name|__be32
name|ddp_report
decl_stmt|;
block|}
name|__U
union|;
name|__be32
name|ulp_crc
decl_stmt|;
name|__be32
name|ddpvld_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_rx_data_ddp.ddpvld_status fields */
end_comment

begin_define
define|#
directive|define
name|S_DDP_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|M_DDP_STATUS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_DDP_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_STATUS)
end_define

begin_define
define|#
directive|define
name|G_DDP_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DDP_STATUS)& M_DDP_STATUS)
end_define

begin_define
define|#
directive|define
name|S_DDP_VALID
value|15
end_define

begin_define
define|#
directive|define
name|M_DDP_VALID
value|0x1FFFF
end_define

begin_define
define|#
directive|define
name|V_DDP_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_VALID)
end_define

begin_define
define|#
directive|define
name|G_DDP_VALID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DDP_VALID)& M_DDP_VALID)
end_define

begin_define
define|#
directive|define
name|S_DDP_PPOD_MISMATCH
value|15
end_define

begin_define
define|#
directive|define
name|V_DDP_PPOD_MISMATCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_PPOD_MISMATCH)
end_define

begin_define
define|#
directive|define
name|F_DDP_PPOD_MISMATCH
value|V_DDP_PPOD_MISMATCH(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_PDU
value|16
end_define

begin_define
define|#
directive|define
name|V_DDP_PDU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_PDU)
end_define

begin_define
define|#
directive|define
name|F_DDP_PDU
value|V_DDP_PDU(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_LLIMIT_ERR
value|17
end_define

begin_define
define|#
directive|define
name|V_DDP_LLIMIT_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_LLIMIT_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_LLIMIT_ERR
value|V_DDP_LLIMIT_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_PPOD_PARITY_ERR
value|18
end_define

begin_define
define|#
directive|define
name|V_DDP_PPOD_PARITY_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_PPOD_PARITY_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_PPOD_PARITY_ERR
value|V_DDP_PPOD_PARITY_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_PADDING_ERR
value|19
end_define

begin_define
define|#
directive|define
name|V_DDP_PADDING_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_PADDING_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_PADDING_ERR
value|V_DDP_PADDING_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_HDRCRC_ERR
value|20
end_define

begin_define
define|#
directive|define
name|V_DDP_HDRCRC_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_HDRCRC_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_HDRCRC_ERR
value|V_DDP_HDRCRC_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_DATACRC_ERR
value|21
end_define

begin_define
define|#
directive|define
name|V_DDP_DATACRC_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_DATACRC_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_DATACRC_ERR
value|V_DDP_DATACRC_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_INVALID_TAG
value|22
end_define

begin_define
define|#
directive|define
name|V_DDP_INVALID_TAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_INVALID_TAG)
end_define

begin_define
define|#
directive|define
name|F_DDP_INVALID_TAG
value|V_DDP_INVALID_TAG(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_ULIMIT_ERR
value|23
end_define

begin_define
define|#
directive|define
name|V_DDP_ULIMIT_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_ULIMIT_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_ULIMIT_ERR
value|V_DDP_ULIMIT_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_OFFSET_ERR
value|24
end_define

begin_define
define|#
directive|define
name|V_DDP_OFFSET_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_OFFSET_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_OFFSET_ERR
value|V_DDP_OFFSET_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_COLOR_ERR
value|25
end_define

begin_define
define|#
directive|define
name|V_DDP_COLOR_ERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_COLOR_ERR)
end_define

begin_define
define|#
directive|define
name|F_DDP_COLOR_ERR
value|V_DDP_COLOR_ERR(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_TID_MISMATCH
value|26
end_define

begin_define
define|#
directive|define
name|V_DDP_TID_MISMATCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_TID_MISMATCH)
end_define

begin_define
define|#
directive|define
name|F_DDP_TID_MISMATCH
value|V_DDP_TID_MISMATCH(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_INVALID_PPOD
value|27
end_define

begin_define
define|#
directive|define
name|V_DDP_INVALID_PPOD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_INVALID_PPOD)
end_define

begin_define
define|#
directive|define
name|F_DDP_INVALID_PPOD
value|V_DDP_INVALID_PPOD(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_ULP_MODE
value|28
end_define

begin_define
define|#
directive|define
name|M_DDP_ULP_MODE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_DDP_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_ULP_MODE)
end_define

begin_define
define|#
directive|define
name|G_DDP_ULP_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DDP_ULP_MODE)& M_DDP_ULP_MODE)
end_define

begin_comment
comment|/* cpl_rx_data_ddp.ddp_report fields */
end_comment

begin_define
define|#
directive|define
name|S_DDP_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|M_DDP_OFFSET
value|0x3FFFFF
end_define

begin_define
define|#
directive|define
name|V_DDP_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_OFFSET)
end_define

begin_define
define|#
directive|define
name|G_DDP_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DDP_OFFSET)& M_DDP_OFFSET)
end_define

begin_define
define|#
directive|define
name|S_DDP_URG
value|24
end_define

begin_define
define|#
directive|define
name|V_DDP_URG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_URG)
end_define

begin_define
define|#
directive|define
name|F_DDP_URG
value|V_DDP_URG(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_PSH
value|25
end_define

begin_define
define|#
directive|define
name|V_DDP_PSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_PSH)
end_define

begin_define
define|#
directive|define
name|F_DDP_PSH
value|V_DDP_PSH(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_BUF_COMPLETE
value|26
end_define

begin_define
define|#
directive|define
name|V_DDP_BUF_COMPLETE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_BUF_COMPLETE)
end_define

begin_define
define|#
directive|define
name|F_DDP_BUF_COMPLETE
value|V_DDP_BUF_COMPLETE(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_BUF_TIMED_OUT
value|27
end_define

begin_define
define|#
directive|define
name|V_DDP_BUF_TIMED_OUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_BUF_TIMED_OUT)
end_define

begin_define
define|#
directive|define
name|F_DDP_BUF_TIMED_OUT
value|V_DDP_BUF_TIMED_OUT(1U)
end_define

begin_define
define|#
directive|define
name|S_DDP_BUF_IDX
value|28
end_define

begin_define
define|#
directive|define
name|V_DDP_BUF_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_BUF_IDX)
end_define

begin_define
define|#
directive|define
name|F_DDP_BUF_IDX
value|V_DDP_BUF_IDX(1U)
end_define

begin_struct
struct|struct
name|cpl_tx_pkt
block|{
name|WR_HDR
expr_stmt|;
name|__be32
name|cntrl
decl_stmt|;
name|__be32
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tx_pkt_lso
block|{
name|WR_HDR
expr_stmt|;
name|__be32
name|cntrl
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be32
name|lso_info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_pkt*.cntrl fields */
end_comment

begin_define
define|#
directive|define
name|S_TXPKT_VLAN
value|0
end_define

begin_define
define|#
directive|define
name|M_TXPKT_VLAN
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_VLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_VLAN)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_VLAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_VLAN)& M_TXPKT_VLAN)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_INTF
value|16
end_define

begin_define
define|#
directive|define
name|M_TXPKT_INTF
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_INTF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_INTF)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_INTF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_INTF)& M_TXPKT_INTF)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_IPCSUM_DIS
value|20
end_define

begin_define
define|#
directive|define
name|V_TXPKT_IPCSUM_DIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_IPCSUM_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_IPCSUM_DIS
value|V_TXPKT_IPCSUM_DIS(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_L4CSUM_DIS
value|21
end_define

begin_define
define|#
directive|define
name|V_TXPKT_L4CSUM_DIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_L4CSUM_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_L4CSUM_DIS
value|V_TXPKT_L4CSUM_DIS(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_VLAN_VLD
value|22
end_define

begin_define
define|#
directive|define
name|V_TXPKT_VLAN_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_VLAN_VLD)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_VLAN_VLD
value|V_TXPKT_VLAN_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_LOOPBACK
value|23
end_define

begin_define
define|#
directive|define
name|V_TXPKT_LOOPBACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_LOOPBACK)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_LOOPBACK
value|V_TXPKT_LOOPBACK(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_TXPKT_OPCODE
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_OPCODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_OPCODE)& M_TXPKT_OPCODE)
end_define

begin_comment
comment|/* cpl_tx_pkt_lso.lso_info fields */
end_comment

begin_define
define|#
directive|define
name|S_LSO_MSS
value|0
end_define

begin_define
define|#
directive|define
name|M_LSO_MSS
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|V_LSO_MSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_MSS)
end_define

begin_define
define|#
directive|define
name|G_LSO_MSS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_MSS)& M_LSO_MSS)
end_define

begin_define
define|#
directive|define
name|S_LSO_ETH_TYPE
value|14
end_define

begin_define
define|#
directive|define
name|M_LSO_ETH_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_LSO_ETH_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_ETH_TYPE)
end_define

begin_define
define|#
directive|define
name|G_LSO_ETH_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_ETH_TYPE)& M_LSO_ETH_TYPE)
end_define

begin_define
define|#
directive|define
name|S_LSO_TCPHDR_WORDS
value|16
end_define

begin_define
define|#
directive|define
name|M_LSO_TCPHDR_WORDS
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LSO_TCPHDR_WORDS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_TCPHDR_WORDS)
end_define

begin_define
define|#
directive|define
name|G_LSO_TCPHDR_WORDS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_TCPHDR_WORDS)& M_LSO_TCPHDR_WORDS)
end_define

begin_define
define|#
directive|define
name|S_LSO_IPHDR_WORDS
value|20
end_define

begin_define
define|#
directive|define
name|M_LSO_IPHDR_WORDS
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LSO_IPHDR_WORDS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_IPHDR_WORDS)
end_define

begin_define
define|#
directive|define
name|G_LSO_IPHDR_WORDS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_IPHDR_WORDS)& M_LSO_IPHDR_WORDS)
end_define

begin_define
define|#
directive|define
name|S_LSO_IPV6
value|24
end_define

begin_define
define|#
directive|define
name|V_LSO_IPV6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_IPV6)
end_define

begin_define
define|#
directive|define
name|F_LSO_IPV6
value|V_LSO_IPV6(1U)
end_define

begin_struct
struct|struct
name|cpl_trace_pkt
block|{
ifdef|#
directive|ifdef
name|CHELSIO_FW
name|__u8
name|rss_opcode
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|err
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|7
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|7
expr_stmt|;
name|__u8
name|err
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|qid
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|4
expr_stmt|;
name|__u8
name|qid
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__be32
name|tstamp
decl_stmt|;
endif|#
directive|endif
comment|/* CHELSIO_FW */
name|__u8
name|opcode
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|4
expr_stmt|;
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd
index|[
literal|4
index|]
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_pkt
block|{
name|RSS_HDR
name|__u8
name|opcode
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
name|__u8
name|csum_valid
range|:
literal|1
decl_stmt|;
name|__u8
name|ipmi_pkt
range|:
literal|1
decl_stmt|;
name|__u8
name|vlan_valid
range|:
literal|1
decl_stmt|;
name|__u8
name|fragment
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|fragment
range|:
literal|1
decl_stmt|;
name|__u8
name|vlan_valid
range|:
literal|1
decl_stmt|;
name|__u8
name|ipmi_pkt
range|:
literal|1
decl_stmt|;
name|__u8
name|csum_valid
range|:
literal|1
decl_stmt|;
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__be16
name|csum
decl_stmt|;
name|__be16
name|vlan
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_l2t_write_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|params
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|dst_mac
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_l2t_write_req.params fields */
end_comment

begin_define
define|#
directive|define
name|S_L2T_W_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_L2T_W_IDX
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_L2T_W_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_IDX)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_IDX)& M_L2T_W_IDX)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_VLAN
value|11
end_define

begin_define
define|#
directive|define
name|M_L2T_W_VLAN
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_L2T_W_VLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_VLAN)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_VLAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_VLAN)& M_L2T_W_VLAN)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_IFF
value|23
end_define

begin_define
define|#
directive|define
name|M_L2T_W_IFF
value|0xF
end_define

begin_define
define|#
directive|define
name|V_L2T_W_IFF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_IFF)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_IFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_IFF)& M_L2T_W_IFF)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_PRIO
value|27
end_define

begin_define
define|#
directive|define
name|M_L2T_W_PRIO
value|0x7
end_define

begin_define
define|#
directive|define
name|V_L2T_W_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_PRIO)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_PRIO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_PRIO)& M_L2T_W_PRIO)
end_define

begin_struct
struct|struct
name|cpl_l2t_write_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_l2t_read_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_l2t_read_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|params
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|2
index|]
decl_stmt|;
name|__u8
name|dst_mac
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_l2t_read_rpl.params fields */
end_comment

begin_define
define|#
directive|define
name|S_L2T_R_PRIO
value|0
end_define

begin_define
define|#
directive|define
name|M_L2T_R_PRIO
value|0x7
end_define

begin_define
define|#
directive|define
name|V_L2T_R_PRIO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_R_PRIO)
end_define

begin_define
define|#
directive|define
name|G_L2T_R_PRIO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_R_PRIO)& M_L2T_R_PRIO)
end_define

begin_define
define|#
directive|define
name|S_L2T_R_VLAN
value|8
end_define

begin_define
define|#
directive|define
name|M_L2T_R_VLAN
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_L2T_R_VLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_R_VLAN)
end_define

begin_define
define|#
directive|define
name|G_L2T_R_VLAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_R_VLAN)& M_L2T_R_VLAN)
end_define

begin_define
define|#
directive|define
name|S_L2T_R_IFF
value|20
end_define

begin_define
define|#
directive|define
name|M_L2T_R_IFF
value|0xF
end_define

begin_define
define|#
directive|define
name|V_L2T_R_IFF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_R_IFF)
end_define

begin_define
define|#
directive|define
name|G_L2T_R_IFF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_R_IFF)& M_L2T_R_IFF)
end_define

begin_define
define|#
directive|define
name|S_L2T_STATUS
value|24
end_define

begin_define
define|#
directive|define
name|M_L2T_STATUS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_L2T_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_STATUS)
end_define

begin_define
define|#
directive|define
name|G_L2T_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_STATUS)& M_L2T_STATUS)
end_define

begin_struct
struct|struct
name|cpl_smt_write_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|mtu_idx
range|:
literal|4
decl_stmt|;
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
name|__u8
name|mtu_idx
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__be16
name|rsvd2
decl_stmt|;
name|__be16
name|rsvd3
decl_stmt|;
name|__u8
name|src_mac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|rsvd4
decl_stmt|;
name|__u8
name|src_mac0
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_smt_write_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_smt_read_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
label|:
literal|4
expr_stmt|;
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|__u8
name|iff
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
endif|#
directive|endif
name|__be16
name|rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_smt_read_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|mtu_idx
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|4
expr_stmt|;
name|__u8
name|mtu_idx
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|__be16
name|rsvd2
decl_stmt|;
name|__be16
name|rsvd3
decl_stmt|;
name|__u8
name|src_mac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|rsvd4
decl_stmt|;
name|__u8
name|src_mac0
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rte_delete_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* { cpl_rte_delete_req, cpl_rte_read_req }.params fields */
end_comment

begin_define
define|#
directive|define
name|S_RTE_REQ_LUT_IX
value|8
end_define

begin_define
define|#
directive|define
name|M_RTE_REQ_LUT_IX
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_REQ_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_REQ_LUT_IX)
end_define

begin_define
define|#
directive|define
name|G_RTE_REQ_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_REQ_LUT_IX)& M_RTE_REQ_LUT_IX)
end_define

begin_define
define|#
directive|define
name|S_RTE_REQ_LUT_BASE
value|19
end_define

begin_define
define|#
directive|define
name|M_RTE_REQ_LUT_BASE
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_REQ_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_REQ_LUT_BASE)
end_define

begin_define
define|#
directive|define
name|G_RTE_REQ_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_REQ_LUT_BASE)& M_RTE_REQ_LUT_BASE)
end_define

begin_define
define|#
directive|define
name|S_RTE_READ_REQ_SELECT
value|31
end_define

begin_define
define|#
directive|define
name|V_RTE_READ_REQ_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_READ_REQ_SELECT)
end_define

begin_define
define|#
directive|define
name|F_RTE_READ_REQ_SELECT
value|V_RTE_READ_REQ_SELECT(1U)
end_define

begin_struct
struct|struct
name|cpl_rte_delete_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rte_write_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
label|:
literal|6
expr_stmt|;
name|__u8
name|write_tcam
range|:
literal|1
decl_stmt|;
name|__u8
name|write_l2t_lut
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|write_l2t_lut
range|:
literal|1
decl_stmt|;
name|__u8
name|write_tcam
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|6
expr_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|lut_params
decl_stmt|;
name|__be16
name|rsvd2
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
name|__be32
name|netmask
decl_stmt|;
name|__be32
name|faddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_rte_write_req.lut_params fields */
end_comment

begin_define
define|#
directive|define
name|S_RTE_WRITE_REQ_LUT_IX
value|10
end_define

begin_define
define|#
directive|define
name|M_RTE_WRITE_REQ_LUT_IX
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_WRITE_REQ_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WRITE_REQ_LUT_IX)
end_define

begin_define
define|#
directive|define
name|G_RTE_WRITE_REQ_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_WRITE_REQ_LUT_IX)& M_RTE_WRITE_REQ_LUT_IX)
end_define

begin_define
define|#
directive|define
name|S_RTE_WRITE_REQ_LUT_BASE
value|21
end_define

begin_define
define|#
directive|define
name|M_RTE_WRITE_REQ_LUT_BASE
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_WRITE_REQ_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WRITE_REQ_LUT_BASE)
end_define

begin_define
define|#
directive|define
name|G_RTE_WRITE_REQ_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_WRITE_REQ_LUT_BASE)& M_RTE_WRITE_REQ_LUT_BASE)
end_define

begin_struct
struct|struct
name|cpl_rte_write_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rte_read_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|params
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rte_read_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__u8
name|rsvd0
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
label|:
literal|7
expr_stmt|;
name|__u8
name|select
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|select
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|7
expr_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd2
index|[
literal|3
index|]
decl_stmt|;
name|__be32
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tid_release
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_barrier
block|{
name|WR_HDR
expr_stmt|;
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rdma_read_req
block|{
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rdma_terminate
block|{
ifdef|#
directive|ifdef
name|CHELSIO_FW
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|2
index|]
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|rspq
range|:
literal|3
decl_stmt|;
name|__u8
label|:
literal|5
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|5
expr_stmt|;
name|__u8
name|rspq
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
name|__be32
name|tid_len
decl_stmt|;
endif|#
directive|endif
name|__be32
name|msn
decl_stmt|;
name|__be32
name|mo
decl_stmt|;
name|__u8
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_rdma_terminate.tid_len fields */
end_comment

begin_define
define|#
directive|define
name|S_FLIT_CNT
value|0
end_define

begin_define
define|#
directive|define
name|M_FLIT_CNT
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_FLIT_CNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FLIT_CNT)
end_define

begin_define
define|#
directive|define
name|G_FLIT_CNT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FLIT_CNT)& M_FLIT_CNT)
end_define

begin_define
define|#
directive|define
name|S_TERM_TID
value|8
end_define

begin_define
define|#
directive|define
name|M_TERM_TID
value|0xFFFFF
end_define

begin_define
define|#
directive|define
name|V_TERM_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TERM_TID)
end_define

begin_define
define|#
directive|define
name|G_TERM_TID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TERM_TID)& M_TERM_TID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T3_CPL_H */
end_comment

end_unit

