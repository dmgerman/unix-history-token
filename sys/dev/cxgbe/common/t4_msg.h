begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2016 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|T4_MSG_H
end_ifndef

begin_define
define|#
directive|define
name|T4_MSG_H
end_define

begin_enum
enum|enum
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
name|CPL_TAG_WRITE_REQ
init|=
literal|0x16
block|,
name|CPL_BARRIER
init|=
literal|0x18
block|,
name|CPL_TID_RELEASE
init|=
literal|0x1A
block|,
name|CPL_TAG_READ_REQ
init|=
literal|0x1B
block|,
name|CPL_SRQ_TABLE_REQ
init|=
literal|0x1C
block|,
name|CPL_TX_PKT_FSO
init|=
literal|0x1E
block|,
name|CPL_TX_DATA_ISO
init|=
literal|0x1F
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
name|CPL_PASS_OPEN_RPL
init|=
literal|0x24
block|,
name|CPL_ACT_OPEN_RPL
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
name|CPL_RX_URG_PKT
init|=
literal|0x29
block|,
name|CPL_TAG_WRITE_RPL
init|=
literal|0x2A
block|,
name|CPL_ABORT_REQ_RSS
init|=
literal|0x2B
block|,
name|CPL_RX_URG_NOTIFY
init|=
literal|0x2C
block|,
name|CPL_ABORT_RPL_RSS
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
name|CPL_RX_PHYS_ADDR
init|=
literal|0x30
block|,
name|CPL_PCMD_READ_RPL
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
name|CPL_SET_TCB_RPL
init|=
literal|0x3A
block|,
name|CPL_RX_PKT
init|=
literal|0x3B
block|,
name|CPL_TAG_READ_RPL
init|=
literal|0x3C
block|,
name|CPL_HIT_NOTIFY
init|=
literal|0x3D
block|,
name|CPL_PKT_NOTIFY
init|=
literal|0x3E
block|,
name|CPL_RX_DDP_COMPLETE
init|=
literal|0x3F
block|,
name|CPL_ACT_ESTABLISH
init|=
literal|0x40
block|,
name|CPL_PASS_ESTABLISH
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
name|CPL_PASS_ACCEPT_REQ
init|=
literal|0x44
block|,
name|CPL_RX_ISCSI_CMP
init|=
literal|0x45
block|,
name|CPL_RX_FCOE_DDP
init|=
literal|0x46
block|,
name|CPL_FCOE_HDR
init|=
literal|0x47
block|,
name|CPL_T5_TRACE_PKT
init|=
literal|0x48
block|,
name|CPL_RX_ISCSI_DDP
init|=
literal|0x49
block|,
name|CPL_RX_FCOE_DIF
init|=
literal|0x4A
block|,
name|CPL_RX_DATA_DIF
init|=
literal|0x4B
block|,
name|CPL_ERR_NOTIFY
init|=
literal|0x4D
block|,
name|CPL_RX_TLS_CMP
init|=
literal|0x4E
block|,
name|CPL_RDMA_READ_REQ
init|=
literal|0x60
block|,
name|CPL_RX_ISCSI_DIF
init|=
literal|0x60
block|,
name|CPL_SET_LE_REQ
init|=
literal|0x80
block|,
name|CPL_PASS_OPEN_REQ6
init|=
literal|0x81
block|,
name|CPL_ACT_OPEN_REQ6
init|=
literal|0x83
block|,
name|CPL_TX_TLS_PDU
init|=
literal|0x88
block|,
name|CPL_TX_TLS_SFO
init|=
literal|0x89
block|,
name|CPL_TX_SEC_PDU
init|=
literal|0x8A
block|,
name|CPL_TX_TLS_ACK
init|=
literal|0x8B
block|,
name|CPL_RDMA_TERMINATE
init|=
literal|0xA2
block|,
name|CPL_RDMA_WRITE
init|=
literal|0xA4
block|,
name|CPL_SGE_EGR_UPDATE
init|=
literal|0xA5
block|,
name|CPL_SET_LE_RPL
init|=
literal|0xA6
block|,
name|CPL_FW2_MSG
init|=
literal|0xA7
block|,
name|CPL_FW2_PLD
init|=
literal|0xA8
block|,
name|CPL_T5_RDMA_READ_REQ
init|=
literal|0xA9
block|,
name|CPL_RDMA_ATOMIC_REQ
init|=
literal|0xAA
block|,
name|CPL_RDMA_ATOMIC_RPL
init|=
literal|0xAB
block|,
name|CPL_RDMA_IMM_DATA
init|=
literal|0xAC
block|,
name|CPL_RDMA_IMM_DATA_SE
init|=
literal|0xAD
block|,
name|CPL_RX_MPS_PKT
init|=
literal|0xAF
block|,
name|CPL_TRACE_PKT
init|=
literal|0xB0
block|,
name|CPL_RX2TX_DATA
init|=
literal|0xB1
block|,
name|CPL_TLS_DATA
init|=
literal|0xB1
block|,
name|CPL_ISCSI_DATA
init|=
literal|0xB2
block|,
name|CPL_FCOE_DATA
init|=
literal|0xB3
block|,
name|CPL_FW4_MSG
init|=
literal|0xC0
block|,
name|CPL_FW4_PLD
init|=
literal|0xC1
block|,
name|CPL_FW4_ACK
init|=
literal|0xC3
block|,
name|CPL_SRQ_TABLE_RPL
init|=
literal|0xCC
block|,
name|CPL_RX_PHYS_DSGL
init|=
literal|0xD0
block|,
name|CPL_FW6_MSG
init|=
literal|0xE0
block|,
name|CPL_FW6_PLD
init|=
literal|0xE1
block|,
name|CPL_TX_TNL_LSO
init|=
literal|0xEC
block|,
name|CPL_TX_PKT_LSO
init|=
literal|0xED
block|,
name|CPL_TX_PKT_XT
init|=
literal|0xEE
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
name|CPL_ERR_TCAM_MISS
init|=
literal|2
block|,
name|CPL_ERR_TCAM_FULL
init|=
literal|3
block|,
name|CPL_ERR_BAD_LENGTH
init|=
literal|15
block|,
name|CPL_ERR_BAD_ROUTE
init|=
literal|18
block|,
name|CPL_ERR_CONN_RESET
init|=
literal|20
block|,
name|CPL_ERR_CONN_EXIST_SYNRECV
init|=
literal|21
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
name|CPL_ERR_KEEPALV_NEG_ADVICE
init|=
literal|37
block|,
name|CPL_ERR_WAIT_ARP_RPL
init|=
literal|41
block|,
name|CPL_ERR_ABORT_FAILED
init|=
literal|42
block|,
name|CPL_ERR_IWARP_FLM
init|=
literal|50
block|,
name|CPL_CONTAINS_READ_RPL
init|=
literal|60
block|,
name|CPL_CONTAINS_WRITE_RPL
init|=
literal|61
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Some of the error codes above implicitly indicate that there is no TID  * allocated with the result of an ACT_OPEN.  We use this predicate to make  * that explicit.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|act_open_has_tid
parameter_list|(
name|int
name|status
parameter_list|)
block|{
return|return
operator|(
name|status
operator|!=
name|CPL_ERR_TCAM_PARITY
operator|&&
name|status
operator|!=
name|CPL_ERR_TCAM_MISS
operator|&&
name|status
operator|!=
name|CPL_ERR_TCAM_FULL
operator|&&
name|status
operator|!=
name|CPL_ERR_CONN_EXIST_SYNRECV
operator|&&
name|status
operator|!=
name|CPL_ERR_CONN_EXIST
operator|)
return|;
block|}
end_function

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
name|CPL_CONN_POLICY_FILTER
init|=
literal|2
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
block|,
name|ULP_MODE_FCOE
init|=
literal|6
block|,
name|ULP_MODE_TLS
init|=
literal|8
block|, }
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
block|,
name|CPL_PASS_OPEN_ACCEPT_TNL
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
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* TX_PKT_XT checksum types */
name|TX_CSUM_TCP
init|=
literal|0
block|,
name|TX_CSUM_UDP
init|=
literal|1
block|,
name|TX_CSUM_CRC16
init|=
literal|4
block|,
name|TX_CSUM_CRC32
init|=
literal|5
block|,
name|TX_CSUM_CRC32C
init|=
literal|6
block|,
name|TX_CSUM_FCOE
init|=
literal|7
block|,
name|TX_CSUM_TCPIP
init|=
literal|8
block|,
name|TX_CSUM_UDPIP
init|=
literal|9
block|,
name|TX_CSUM_TCPIP6
init|=
literal|10
block|,
name|TX_CSUM_UDPIP6
init|=
literal|11
block|,
name|TX_CSUM_IP
init|=
literal|12
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* packet type in CPL_RX_PKT */
name|PKTYPE_XACT_UCAST
init|=
literal|0
block|,
name|PKTYPE_HASH_UCAST
init|=
literal|1
block|,
name|PKTYPE_XACT_MCAST
init|=
literal|2
block|,
name|PKTYPE_HASH_MCAST
init|=
literal|3
block|,
name|PKTYPE_PROMISC
init|=
literal|4
block|,
name|PKTYPE_HPROMISC
init|=
literal|5
block|,
name|PKTYPE_BCAST
init|=
literal|6
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* DMAC type in CPL_RX_PKT */
name|DATYPE_UCAST
block|,
name|DATYPE_MCAST
block|,
name|DATYPE_BCAST
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
comment|/* no hash computed */
name|RSS_HASH_IP
init|=
literal|1
block|,
comment|/* IP or IPv6 2-tuple hash */
name|RSS_HASH_TCP
init|=
literal|2
block|,
comment|/* TCP 4-tuple hash */
name|RSS_HASH_UDP
init|=
literal|3
comment|/* UDP 4-tuple hash */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* LE commands */
name|LE_CMD_READ
init|=
literal|0x4
block|,
name|LE_CMD_WRITE
init|=
literal|0xb
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* LE request size */
name|LE_SZ_NONE
init|=
literal|0
block|,
name|LE_SZ_33
init|=
literal|1
block|,
name|LE_SZ_66
init|=
literal|2
block|,
name|LE_SZ_132
init|=
literal|3
block|,
name|LE_SZ_264
init|=
literal|4
block|,
name|LE_SZ_528
init|=
literal|5
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
name|S_CPL_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|V_CPL_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_OPCODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CPL_OPCODE)& 0xFF)
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
value|(V_CPL_OPCODE(opcode) | (tid))
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

begin_define
define|#
directive|define
name|GET_OPCODE
parameter_list|(
name|cmd
parameter_list|)
value|((cmd)->ot.opcode)
end_define

begin_comment
comment|/* partitioning of TID fields that also carry a queue id */
end_comment

begin_define
define|#
directive|define
name|S_TID_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_TID_TID
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_TID_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TID_TID)
end_define

begin_define
define|#
directive|define
name|G_TID_TID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TID_TID)& M_TID_TID)
end_define

begin_define
define|#
directive|define
name|S_TID_QID
value|14
end_define

begin_define
define|#
directive|define
name|M_TID_QID
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_TID_QID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TID_QID)
end_define

begin_define
define|#
directive|define
name|G_TID_QID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TID_QID)& M_TID_QID)
end_define

begin_union
union|union
name|opcode_info
block|{
name|__be64
name|opcode_info
decl_stmt|;
name|__u8
name|opcode
decl_stmt|;
block|}
union|;
end_union

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
literal|4
expr_stmt|;
name|__u8
name|unknown
range|:
literal|1
decl_stmt|;
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
name|unknown
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|4
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
name|channel
range|:
literal|2
decl_stmt|;
name|__u8
name|filter_hit
range|:
literal|1
decl_stmt|;
name|__u8
name|filter_tid
range|:
literal|1
decl_stmt|;
name|__u8
name|hash_type
range|:
literal|2
decl_stmt|;
name|__u8
name|ipv6
range|:
literal|1
decl_stmt|;
name|__u8
name|send2fw
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|send2fw
range|:
literal|1
decl_stmt|;
name|__u8
name|ipv6
range|:
literal|1
decl_stmt|;
name|__u8
name|hash_type
range|:
literal|2
decl_stmt|;
name|__u8
name|filter_tid
range|:
literal|1
decl_stmt|;
name|__u8
name|filter_hit
range|:
literal|1
decl_stmt|;
name|__u8
name|channel
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
name|__be16
name|qid
decl_stmt|;
name|__be32
name|hash_val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_HASHTYPE
value|20
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
name|M_QNUM
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|G_QNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QNUM)& M_QNUM)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RSS_HDR_VLD
argument_list|)
operator|||
name|defined
argument_list|(
name|CHELSIO_FW
argument_list|)
end_if

begin_define
define|#
directive|define
name|RSS_HDR
value|struct rss_header rss_hdr;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RSS_HDR
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|wr_mid
decl_stmt|;
name|__be64
name|wr_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* wr_mid fields */
end_comment

begin_define
define|#
directive|define
name|S_WR_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_WR_LEN16
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WR_LEN16)
end_define

begin_define
define|#
directive|define
name|G_WR_LEN16
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WR_LEN16)& M_WR_LEN16)
end_define

begin_comment
comment|/* wr_hi fields */
end_comment

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
value|((__u64)(x)<< S_WR_OP)
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

begin_define
define|#
directive|define
name|WR_HDR
value|struct work_request_hdr wr
end_define

begin_define
define|#
directive|define
name|WR_HDR_SIZE
value|sizeof(struct work_request_hdr)
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
name|WR_HDR_SIZE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* option 0 fields */
end_comment

begin_define
define|#
directive|define
name|S_ACCEPT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|M_ACCEPT_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_ACCEPT_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ACCEPT_MODE)
end_define

begin_define
define|#
directive|define
name|G_ACCEPT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ACCEPT_MODE)& M_ACCEPT_MODE)
end_define

begin_define
define|#
directive|define
name|S_TX_CHAN
value|2
end_define

begin_define
define|#
directive|define
name|M_TX_CHAN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_TX_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_CHAN)
end_define

begin_define
define|#
directive|define
name|G_TX_CHAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_CHAN)& M_TX_CHAN)
end_define

begin_define
define|#
directive|define
name|S_NO_CONG
value|4
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
name|S_DELACK
value|5
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
name|S_NON_OFFLOAD
value|7
end_define

begin_define
define|#
directive|define
name|V_NON_OFFLOAD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NON_OFFLOAD)
end_define

begin_define
define|#
directive|define
name|F_NON_OFFLOAD
value|V_NON_OFFLOAD(1U)
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
value|0x3FFU
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
name|S_DSCP
value|22
end_define

begin_define
define|#
directive|define
name|M_DSCP
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_DSCP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DSCP)
end_define

begin_define
define|#
directive|define
name|G_DSCP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DSCP)& M_DSCP)
end_define

begin_define
define|#
directive|define
name|S_SMAC_SEL
value|28
end_define

begin_define
define|#
directive|define
name|M_SMAC_SEL
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_SMAC_SEL
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_SMAC_SEL)
end_define

begin_define
define|#
directive|define
name|G_SMAC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMAC_SEL)& M_SMAC_SEL)
end_define

begin_define
define|#
directive|define
name|S_L2T_IDX
value|36
end_define

begin_define
define|#
directive|define
name|M_L2T_IDX
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_L2T_IDX
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_L2T_IDX)
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
name|S_TCAM_BYPASS
value|48
end_define

begin_define
define|#
directive|define
name|V_TCAM_BYPASS
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TCAM_BYPASS)
end_define

begin_define
define|#
directive|define
name|F_TCAM_BYPASS
value|V_TCAM_BYPASS(1ULL)
end_define

begin_define
define|#
directive|define
name|S_NAGLE
value|49
end_define

begin_define
define|#
directive|define
name|V_NAGLE
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_NAGLE)
end_define

begin_define
define|#
directive|define
name|F_NAGLE
value|V_NAGLE(1ULL)
end_define

begin_define
define|#
directive|define
name|S_WND_SCALE
value|50
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
value|((__u64)(x)<< S_WND_SCALE)
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
value|54
end_define

begin_define
define|#
directive|define
name|V_KEEP_ALIVE
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_KEEP_ALIVE)
end_define

begin_define
define|#
directive|define
name|F_KEEP_ALIVE
value|V_KEEP_ALIVE(1ULL)
end_define

begin_define
define|#
directive|define
name|S_MAX_RT
value|55
end_define

begin_define
define|#
directive|define
name|M_MAX_RT
value|0xF
end_define

begin_define
define|#
directive|define
name|V_MAX_RT
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_MAX_RT)
end_define

begin_define
define|#
directive|define
name|G_MAX_RT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_MAX_RT)& M_MAX_RT)
end_define

begin_define
define|#
directive|define
name|S_MAX_RT_OVERRIDE
value|59
end_define

begin_define
define|#
directive|define
name|V_MAX_RT_OVERRIDE
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_MAX_RT_OVERRIDE)
end_define

begin_define
define|#
directive|define
name|F_MAX_RT_OVERRIDE
value|V_MAX_RT_OVERRIDE(1ULL)
end_define

begin_define
define|#
directive|define
name|S_MSS_IDX
value|60
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
value|((__u64)(x)<< S_MSS_IDX)
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
name|S_SYN_RSS_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|V_SYN_RSS_ENABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_RSS_ENABLE)
end_define

begin_define
define|#
directive|define
name|F_SYN_RSS_ENABLE
value|V_SYN_RSS_ENABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_SYN_RSS_USE_HASH
value|1
end_define

begin_define
define|#
directive|define
name|V_SYN_RSS_USE_HASH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_RSS_USE_HASH)
end_define

begin_define
define|#
directive|define
name|F_SYN_RSS_USE_HASH
value|V_SYN_RSS_USE_HASH(1U)
end_define

begin_define
define|#
directive|define
name|S_SYN_RSS_QUEUE
value|2
end_define

begin_define
define|#
directive|define
name|M_SYN_RSS_QUEUE
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_SYN_RSS_QUEUE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_RSS_QUEUE)
end_define

begin_define
define|#
directive|define
name|G_SYN_RSS_QUEUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SYN_RSS_QUEUE)& M_SYN_RSS_QUEUE)
end_define

begin_define
define|#
directive|define
name|S_LISTEN_INTF
value|12
end_define

begin_define
define|#
directive|define
name|M_LISTEN_INTF
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_LISTEN_INTF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LISTEN_INTF)
end_define

begin_define
define|#
directive|define
name|G_LISTEN_INTF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LISTEN_INTF)& M_LISTEN_INTF)
end_define

begin_define
define|#
directive|define
name|S_LISTEN_FILTER
value|20
end_define

begin_define
define|#
directive|define
name|V_LISTEN_FILTER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LISTEN_FILTER)
end_define

begin_define
define|#
directive|define
name|F_LISTEN_FILTER
value|V_LISTEN_FILTER(1U)
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
name|S_CONN_POLICY
value|22
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
name|S_T5_FILT_INFO
value|24
end_define

begin_define
define|#
directive|define
name|M_T5_FILT_INFO
value|0xffffffffffULL
end_define

begin_define
define|#
directive|define
name|V_T5_FILT_INFO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_FILT_INFO)
end_define

begin_define
define|#
directive|define
name|G_T5_FILT_INFO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T5_FILT_INFO)& M_T5_FILT_INFO)
end_define

begin_define
define|#
directive|define
name|S_FILT_INFO
value|28
end_define

begin_define
define|#
directive|define
name|M_FILT_INFO
value|0xfffffffffULL
end_define

begin_define
define|#
directive|define
name|V_FILT_INFO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FILT_INFO)
end_define

begin_define
define|#
directive|define
name|G_FILT_INFO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FILT_INFO)& M_FILT_INFO)
end_define

begin_comment
comment|/* option 2 fields */
end_comment

begin_define
define|#
directive|define
name|S_RSS_QUEUE
value|0
end_define

begin_define
define|#
directive|define
name|M_RSS_QUEUE
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_RSS_QUEUE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSS_QUEUE)
end_define

begin_define
define|#
directive|define
name|G_RSS_QUEUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RSS_QUEUE)& M_RSS_QUEUE)
end_define

begin_define
define|#
directive|define
name|S_RSS_QUEUE_VALID
value|10
end_define

begin_define
define|#
directive|define
name|V_RSS_QUEUE_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RSS_QUEUE_VALID)
end_define

begin_define
define|#
directive|define
name|F_RSS_QUEUE_VALID
value|V_RSS_QUEUE_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_COALESCE_VALID
value|11
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
name|S_RX_COALESCE
value|12
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
name|S_CONG_CNTRL
value|14
end_define

begin_define
define|#
directive|define
name|M_CONG_CNTRL
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CONG_CNTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CONG_CNTRL)
end_define

begin_define
define|#
directive|define
name|G_CONG_CNTRL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CONG_CNTRL)& M_CONG_CNTRL)
end_define

begin_define
define|#
directive|define
name|S_PACE
value|16
end_define

begin_define
define|#
directive|define
name|M_PACE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_PACE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PACE)
end_define

begin_define
define|#
directive|define
name|G_PACE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_PACE)& M_PACE)
end_define

begin_define
define|#
directive|define
name|S_CONG_CNTRL_VALID
value|18
end_define

begin_define
define|#
directive|define
name|V_CONG_CNTRL_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CONG_CNTRL_VALID)
end_define

begin_define
define|#
directive|define
name|F_CONG_CNTRL_VALID
value|V_CONG_CNTRL_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_T5_ISS
value|18
end_define

begin_define
define|#
directive|define
name|V_T5_ISS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_ISS)
end_define

begin_define
define|#
directive|define
name|F_T5_ISS
value|V_T5_ISS(1U)
end_define

begin_define
define|#
directive|define
name|S_PACE_VALID
value|19
end_define

begin_define
define|#
directive|define
name|V_PACE_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_PACE_VALID)
end_define

begin_define
define|#
directive|define
name|F_PACE_VALID
value|V_PACE_VALID(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_FC_DISABLE
value|20
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
name|S_RX_FC_DDP
value|21
end_define

begin_define
define|#
directive|define
name|V_RX_FC_DDP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_FC_DDP)
end_define

begin_define
define|#
directive|define
name|F_RX_FC_DDP
value|V_RX_FC_DDP(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_FC_VALID
value|22
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

begin_define
define|#
directive|define
name|S_TX_QUEUE
value|23
end_define

begin_define
define|#
directive|define
name|M_TX_QUEUE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_TX_QUEUE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_QUEUE)
end_define

begin_define
define|#
directive|define
name|G_TX_QUEUE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_QUEUE)& M_TX_QUEUE)
end_define

begin_define
define|#
directive|define
name|S_RX_CHANNEL
value|26
end_define

begin_define
define|#
directive|define
name|V_RX_CHANNEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_CHANNEL)
end_define

begin_define
define|#
directive|define
name|F_RX_CHANNEL
value|V_RX_CHANNEL(1U)
end_define

begin_define
define|#
directive|define
name|S_CCTRL_ECN
value|27
end_define

begin_define
define|#
directive|define
name|V_CCTRL_ECN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CCTRL_ECN)
end_define

begin_define
define|#
directive|define
name|F_CCTRL_ECN
value|V_CCTRL_ECN(1U)
end_define

begin_define
define|#
directive|define
name|S_WND_SCALE_EN
value|28
end_define

begin_define
define|#
directive|define
name|V_WND_SCALE_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WND_SCALE_EN)
end_define

begin_define
define|#
directive|define
name|F_WND_SCALE_EN
value|V_WND_SCALE_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_TSTAMPS_EN
value|29
end_define

begin_define
define|#
directive|define
name|V_TSTAMPS_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TSTAMPS_EN)
end_define

begin_define
define|#
directive|define
name|F_TSTAMPS_EN
value|V_TSTAMPS_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_SACK_EN
value|30
end_define

begin_define
define|#
directive|define
name|V_SACK_EN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SACK_EN)
end_define

begin_define
define|#
directive|define
name|F_SACK_EN
value|V_SACK_EN(1U)
end_define

begin_define
define|#
directive|define
name|S_T5_OPT_2_VALID
value|31
end_define

begin_define
define|#
directive|define
name|V_T5_OPT_2_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_OPT_2_VALID)
end_define

begin_define
define|#
directive|define
name|F_T5_OPT_2_VALID
value|V_T5_OPT_2_VALID(1U)
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
name|__be64
name|opt0
decl_stmt|;
name|__be64
name|opt1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pass_open_req6
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
name|__be64
name|local_ip_hi
decl_stmt|;
name|__be64
name|local_ip_lo
decl_stmt|;
name|__be64
name|peer_ip_hi
decl_stmt|;
name|__be64
name|peer_ip_lo
decl_stmt|;
name|__be64
name|opt0
decl_stmt|;
name|__be64
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
name|cpl_pass_establish
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be32
name|tos_stid
decl_stmt|;
name|__be16
name|mac_idx
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
comment|/* cpl_pass_establish.tos_stid fields */
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
comment|/* cpl_pass_establish.tcp_opt fields (also applies to act_open_establish) */
end_comment

begin_define
define|#
directive|define
name|S_TCPOPT_WSCALE_OK
value|5
end_define

begin_define
define|#
directive|define
name|M_TCPOPT_WSCALE_OK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_TCPOPT_WSCALE_OK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCPOPT_WSCALE_OK)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_WSCALE_OK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCPOPT_WSCALE_OK)& M_TCPOPT_WSCALE_OK)
end_define

begin_define
define|#
directive|define
name|S_TCPOPT_SACK
value|6
end_define

begin_define
define|#
directive|define
name|M_TCPOPT_SACK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_TCPOPT_SACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCPOPT_SACK)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_SACK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCPOPT_SACK)& M_TCPOPT_SACK)
end_define

begin_define
define|#
directive|define
name|S_TCPOPT_TSTAMP
value|7
end_define

begin_define
define|#
directive|define
name|M_TCPOPT_TSTAMP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_TCPOPT_TSTAMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCPOPT_TSTAMP)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_TSTAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCPOPT_TSTAMP)& M_TCPOPT_TSTAMP)
end_define

begin_define
define|#
directive|define
name|S_TCPOPT_SND_WSCALE
value|8
end_define

begin_define
define|#
directive|define
name|M_TCPOPT_SND_WSCALE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TCPOPT_SND_WSCALE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCPOPT_SND_WSCALE)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_SND_WSCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCPOPT_SND_WSCALE)& M_TCPOPT_SND_WSCALE)
end_define

begin_define
define|#
directive|define
name|S_TCPOPT_MSS
value|12
end_define

begin_define
define|#
directive|define
name|M_TCPOPT_MSS
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TCPOPT_MSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCPOPT_MSS)
end_define

begin_define
define|#
directive|define
name|G_TCPOPT_MSS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCPOPT_MSS)& M_TCPOPT_MSS)
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
name|rsvd
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|hdr_len
decl_stmt|;
name|__be16
name|vlan
decl_stmt|;
name|__be16
name|l2info
decl_stmt|;
name|__be32
name|tos_stid
decl_stmt|;
name|struct
name|tcp_options
name|tcpopt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_pass_accept_req.hdr_len fields */
end_comment

begin_define
define|#
directive|define
name|S_SYN_RX_CHAN
value|0
end_define

begin_define
define|#
directive|define
name|M_SYN_RX_CHAN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_SYN_RX_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_RX_CHAN)
end_define

begin_define
define|#
directive|define
name|G_SYN_RX_CHAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SYN_RX_CHAN)& M_SYN_RX_CHAN)
end_define

begin_define
define|#
directive|define
name|S_TCP_HDR_LEN
value|10
end_define

begin_define
define|#
directive|define
name|M_TCP_HDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_TCP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TCP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_TCP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TCP_HDR_LEN)& M_TCP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_T6_TCP_HDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|V_T6_TCP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_TCP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_T6_TCP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T6_TCP_HDR_LEN)& M_TCP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_IP_HDR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|M_IP_HDR_LEN
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_IP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_IP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_IP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_IP_HDR_LEN)& M_IP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_T6_IP_HDR_LEN
value|14
end_define

begin_define
define|#
directive|define
name|V_T6_IP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_IP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_T6_IP_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T6_IP_HDR_LEN)& M_IP_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_ETH_HDR_LEN
value|26
end_define

begin_define
define|#
directive|define
name|M_ETH_HDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_ETH_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ETH_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_ETH_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ETH_HDR_LEN)& M_ETH_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_T6_ETH_HDR_LEN
value|24
end_define

begin_define
define|#
directive|define
name|M_T6_ETH_HDR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_T6_ETH_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_ETH_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_T6_ETH_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T6_ETH_HDR_LEN)& M_T6_ETH_HDR_LEN)
end_define

begin_comment
comment|/* cpl_pass_accept_req.l2info fields */
end_comment

begin_define
define|#
directive|define
name|S_SYN_MAC_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_SYN_MAC_IDX
value|0x1FF
end_define

begin_define
define|#
directive|define
name|V_SYN_MAC_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_MAC_IDX)
end_define

begin_define
define|#
directive|define
name|G_SYN_MAC_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SYN_MAC_IDX)& M_SYN_MAC_IDX)
end_define

begin_define
define|#
directive|define
name|S_SYN_XACT_MATCH
value|9
end_define

begin_define
define|#
directive|define
name|V_SYN_XACT_MATCH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_XACT_MATCH)
end_define

begin_define
define|#
directive|define
name|F_SYN_XACT_MATCH
value|V_SYN_XACT_MATCH(1U)
end_define

begin_define
define|#
directive|define
name|S_SYN_INTF
value|12
end_define

begin_define
define|#
directive|define
name|M_SYN_INTF
value|0xF
end_define

begin_define
define|#
directive|define
name|V_SYN_INTF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SYN_INTF)
end_define

begin_define
define|#
directive|define
name|G_SYN_INTF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SYN_INTF)& M_SYN_INTF)
end_define

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
name|__be64
name|opt0
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_t5_pass_accept_rpl
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
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
union|union
block|{
name|__be32
name|rsvd
decl_stmt|;
comment|/* T5 */
name|__be32
name|opt3
decl_stmt|;
comment|/* T6 */
block|}
name|u
union|;
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
name|__be64
name|opt0
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

begin_define
define|#
directive|define
name|S_FILTER_TUPLE
value|24
end_define

begin_define
define|#
directive|define
name|M_FILTER_TUPLE
value|0xFFFFFFFFFF
end_define

begin_define
define|#
directive|define
name|V_FILTER_TUPLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FILTER_TUPLE)
end_define

begin_define
define|#
directive|define
name|G_FILTER_TUPLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FILTER_TUPLE)& M_FILTER_TUPLE)
end_define

begin_struct
struct|struct
name|cpl_t5_act_open_req
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
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be64
name|params
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_t6_act_open_req
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
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be64
name|params
decl_stmt|;
name|__be32
name|rsvd2
decl_stmt|;
name|__be32
name|opt3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_{t5,t6}_act_open_req.params field */
end_comment

begin_define
define|#
directive|define
name|S_AOPEN_FCOEMASK
value|0
end_define

begin_define
define|#
directive|define
name|V_AOPEN_FCOEMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_FCOEMASK)
end_define

begin_define
define|#
directive|define
name|F_AOPEN_FCOEMASK
value|V_AOPEN_FCOEMASK(1U)
end_define

begin_struct
struct|struct
name|cpl_act_open_req6
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
name|__be64
name|local_ip_hi
decl_stmt|;
name|__be64
name|local_ip_lo
decl_stmt|;
name|__be64
name|peer_ip_hi
decl_stmt|;
name|__be64
name|peer_ip_lo
decl_stmt|;
name|__be64
name|opt0
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

begin_struct
struct|struct
name|cpl_t5_act_open_req6
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
name|__be64
name|local_ip_hi
decl_stmt|;
name|__be64
name|local_ip_lo
decl_stmt|;
name|__be64
name|peer_ip_hi
decl_stmt|;
name|__be64
name|peer_ip_lo
decl_stmt|;
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be64
name|params
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_t6_act_open_req6
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
name|__be64
name|local_ip_hi
decl_stmt|;
name|__be64
name|local_ip_lo
decl_stmt|;
name|__be64
name|peer_ip_hi
decl_stmt|;
name|__be64
name|peer_ip_lo
decl_stmt|;
name|__be64
name|opt0
decl_stmt|;
name|__be32
name|iss
decl_stmt|;
name|__be32
name|opt2
decl_stmt|;
name|__be64
name|params
decl_stmt|;
name|__be32
name|rsvd2
decl_stmt|;
name|__be32
name|opt3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_act_open_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|atid_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_act_open_rpl.atid_status fields */
end_comment

begin_define
define|#
directive|define
name|S_AOPEN_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|M_AOPEN_STATUS
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_AOPEN_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_STATUS)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_STATUS)& M_AOPEN_STATUS)
end_define

begin_define
define|#
directive|define
name|S_AOPEN_ATID
value|8
end_define

begin_define
define|#
directive|define
name|M_AOPEN_ATID
value|0xFFFFFF
end_define

begin_define
define|#
directive|define
name|V_AOPEN_ATID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AOPEN_ATID)
end_define

begin_define
define|#
directive|define
name|G_AOPEN_ATID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AOPEN_ATID)& M_AOPEN_ATID)
end_define

begin_struct
struct|struct
name|cpl_act_establish
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be32
name|tos_atid
decl_stmt|;
name|__be16
name|mac_idx
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
name|reply_ctrl
decl_stmt|;
name|__be16
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_get_tcb.reply_ctrl fields */
end_comment

begin_define
define|#
directive|define
name|S_QUEUENO
value|0
end_define

begin_define
define|#
directive|define
name|M_QUEUENO
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_QUEUENO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_QUEUENO)
end_define

begin_define
define|#
directive|define
name|G_QUEUENO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_QUEUENO)& M_QUEUENO)
end_define

begin_define
define|#
directive|define
name|S_REPLY_CHAN
value|14
end_define

begin_define
define|#
directive|define
name|V_REPLY_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_REPLY_CHAN)
end_define

begin_define
define|#
directive|define
name|F_REPLY_CHAN
value|V_REPLY_CHAN(1U)
end_define

begin_define
define|#
directive|define
name|S_NO_REPLY
value|15
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
name|cpl_get_tcb_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|cookie
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
name|__be16
name|reply_ctrl
decl_stmt|;
name|__be16
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

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
name|__be16
name|reply_ctrl
decl_stmt|;
name|__be16
name|word_cookie
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
name|cpl_set_tcb_field_core
block|{
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|reply_ctrl
decl_stmt|;
name|__be16
name|word_cookie
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

begin_comment
comment|/* cpl_set_tcb_field.word_cookie fields */
end_comment

begin_define
define|#
directive|define
name|S_WORD
value|0
end_define

begin_define
define|#
directive|define
name|M_WORD
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_WORD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_WORD)
end_define

begin_define
define|#
directive|define
name|G_WORD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_WORD)& M_WORD)
end_define

begin_define
define|#
directive|define
name|S_COOKIE
value|5
end_define

begin_define
define|#
directive|define
name|M_COOKIE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_COOKIE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_COOKIE)
end_define

begin_define
define|#
directive|define
name|G_COOKIE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_COOKIE)& M_COOKIE)
end_define

begin_struct
struct|struct
name|cpl_set_tcb_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
name|__u8
name|cookie
decl_stmt|;
name|__u8
name|status
decl_stmt|;
name|__be64
name|oldval
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
name|cpl_close_listsvr_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|reply_ctrl
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* additional cpl_close_listsvr_req.reply_ctrl field */
end_comment

begin_define
define|#
directive|define
name|S_LISTSVR_IPV6
value|14
end_define

begin_define
define|#
directive|define
name|V_LISTSVR_IPV6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LISTSVR_IPV6)
end_define

begin_define
define|#
directive|define
name|F_LISTSVR_IPV6
value|V_LISTSVR_IPV6(1U)
end_define

begin_struct
struct|struct
name|cpl_close_listsvr_rpl
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
name|cpl_abort_req_rss6
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u32
name|srqidx_status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_ABORT_RSS_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|M_ABORT_RSS_STATUS
value|0xff
end_define

begin_define
define|#
directive|define
name|V_ABORT_RSS_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ABORT_RSS_STATUS)
end_define

begin_define
define|#
directive|define
name|G_ABORT_RSS_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ABORT_RSS_STATUS)& M_ABORT_RSS_STATUS)
end_define

begin_define
define|#
directive|define
name|S_ABORT_RSS_SRQIDX
value|8
end_define

begin_define
define|#
directive|define
name|M_ABORT_RSS_SRQIDX
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_ABORT_RSS_SRQIDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ABORT_RSS_SRQIDX)
end_define

begin_define
define|#
directive|define
name|G_ABORT_RSS_SRQIDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ABORT_RSS_SRQIDX)& M_ABORT_RSS_SRQIDX)
end_define

begin_comment
comment|/* cpl_abort_req status command code in case of T6,  * bit[0] specifies whether to send RST (0) to remote peer or suppress it (1)  * bit[1] indicates ABORT_REQ was sent after a CLOSE_CON_REQ  * bit[2] specifies whether to disable the mmgr (1) or not (0)  */
end_comment

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
name|cpl_abort_rpl_rss6
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u32
name|srqidx_status
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
comment|/* tx_data_wr.flags fields */
end_comment

begin_define
define|#
directive|define
name|S_TX_ACK_PAGES
value|21
end_define

begin_define
define|#
directive|define
name|M_TX_ACK_PAGES
value|0x7
end_define

begin_define
define|#
directive|define
name|V_TX_ACK_PAGES
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_ACK_PAGES)
end_define

begin_define
define|#
directive|define
name|G_TX_ACK_PAGES
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TX_ACK_PAGES)& M_TX_ACK_PAGES)
end_define

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
name|__be32
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
name|S_TX_PROXY
value|5
end_define

begin_define
define|#
directive|define
name|V_TX_PROXY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_PROXY)
end_define

begin_define
define|#
directive|define
name|F_TX_PROXY
value|V_TX_PROXY(1U)
end_define

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
value|0x7
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
name|S_TX_FORCE
value|13
end_define

begin_define
define|#
directive|define
name|V_TX_FORCE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_FORCE)
end_define

begin_define
define|#
directive|define
name|F_TX_FORCE
value|V_TX_FORCE(1U)
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
name|S_TX_FLUSH
value|17
end_define

begin_define
define|#
directive|define
name|V_TX_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_FLUSH)
end_define

begin_define
define|#
directive|define
name|F_TX_FLUSH
value|V_TX_FLUSH(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_SAVE
value|18
end_define

begin_define
define|#
directive|define
name|V_TX_SAVE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_SAVE)
end_define

begin_define
define|#
directive|define
name|F_TX_SAVE
value|V_TX_SAVE(1U)
end_define

begin_define
define|#
directive|define
name|S_TX_TNL
value|19
end_define

begin_define
define|#
directive|define
name|V_TX_TNL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TX_TNL)
end_define

begin_define
define|#
directive|define
name|F_TX_TNL
value|V_TX_TNL(1U)
end_define

begin_define
define|#
directive|define
name|S_T6_TX_FORCE
value|20
end_define

begin_define
define|#
directive|define
name|V_T6_TX_FORCE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_TX_FORCE)
end_define

begin_define
define|#
directive|define
name|F_T6_TX_FORCE
value|V_T6_TX_FORCE(1U)
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
name|snd_una
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_wr_ack
block|{
comment|/* XXX */
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
name|cpl_tx_pkt_core
block|{
name|__be32
name|ctrl0
decl_stmt|;
name|__be16
name|pack
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be64
name|ctrl1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tx_pkt
block|{
name|WR_HDR
expr_stmt|;
name|struct
name|cpl_tx_pkt_core
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cpl_tx_pkt_xt
value|cpl_tx_pkt
end_define

begin_comment
comment|/* cpl_tx_pkt_core.ctrl0 fields */
end_comment

begin_define
define|#
directive|define
name|S_TXPKT_VF
value|0
end_define

begin_define
define|#
directive|define
name|M_TXPKT_VF
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_VF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_VF)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_VF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_VF)& M_TXPKT_VF)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_PF
value|8
end_define

begin_define
define|#
directive|define
name|M_TXPKT_PF
value|0x7
end_define

begin_define
define|#
directive|define
name|V_TXPKT_PF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_PF)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_PF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_PF)& M_TXPKT_PF)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_VF_VLD
value|11
end_define

begin_define
define|#
directive|define
name|V_TXPKT_VF_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_VF_VLD)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_VF_VLD
value|V_TXPKT_VF_VLD(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_OVLAN_IDX
value|12
end_define

begin_define
define|#
directive|define
name|M_TXPKT_OVLAN_IDX
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_OVLAN_IDX)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_OVLAN_IDX)& M_TXPKT_OVLAN_IDX)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_T5_OVLAN_IDX
value|12
end_define

begin_define
define|#
directive|define
name|M_TXPKT_T5_OVLAN_IDX
value|0x7
end_define

begin_define
define|#
directive|define
name|V_TXPKT_T5_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_T5_OVLAN_IDX)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_T5_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_T5_OVLAN_IDX)& \ 				M_TXPKT_T5_OVLAN_IDX)
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
name|S_TXPKT_SPECIAL_STAT
value|20
end_define

begin_define
define|#
directive|define
name|V_TXPKT_SPECIAL_STAT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_SPECIAL_STAT)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_SPECIAL_STAT
value|V_TXPKT_SPECIAL_STAT(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_T5_FCS_DIS
value|21
end_define

begin_define
define|#
directive|define
name|V_TXPKT_T5_FCS_DIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_T5_FCS_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_T5_FCS_DIS
value|V_TXPKT_T5_FCS_DIS(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_INS_OVLAN
value|21
end_define

begin_define
define|#
directive|define
name|V_TXPKT_INS_OVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_INS_OVLAN)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_INS_OVLAN
value|V_TXPKT_INS_OVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_T5_INS_OVLAN
value|15
end_define

begin_define
define|#
directive|define
name|V_TXPKT_T5_INS_OVLAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_T5_INS_OVLAN)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_T5_INS_OVLAN
value|V_TXPKT_T5_INS_OVLAN(1U)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_STAT_DIS
value|22
end_define

begin_define
define|#
directive|define
name|V_TXPKT_STAT_DIS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_STAT_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_STAT_DIS
value|V_TXPKT_STAT_DIS(1U)
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
name|S_TXPKT_TSTAMP
value|23
end_define

begin_define
define|#
directive|define
name|V_TXPKT_TSTAMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_TSTAMP)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_TSTAMP
value|V_TXPKT_TSTAMP(1U)
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
comment|/* cpl_tx_pkt_core.ctrl1 fields */
end_comment

begin_define
define|#
directive|define
name|S_TXPKT_SA_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_TXPKT_SA_IDX
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_SA_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_SA_IDX)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_SA_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_SA_IDX)& M_TXPKT_SA_IDX)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_CSUM_END
value|12
end_define

begin_define
define|#
directive|define
name|M_TXPKT_CSUM_END
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_CSUM_END
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_CSUM_END)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_CSUM_END
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_CSUM_END)& M_TXPKT_CSUM_END)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_CSUM_START
value|20
end_define

begin_define
define|#
directive|define
name|M_TXPKT_CSUM_START
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_CSUM_START
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TXPKT_CSUM_START)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_CSUM_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_CSUM_START)& M_TXPKT_CSUM_START)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_IPHDR_LEN
value|20
end_define

begin_define
define|#
directive|define
name|M_TXPKT_IPHDR_LEN
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_IPHDR_LEN)& M_TXPKT_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|M_T6_TXPKT_IPHDR_LEN
value|0xFFF
end_define

begin_define
define|#
directive|define
name|G_T6_TXPKT_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_TXPKT_IPHDR_LEN)& M_T6_TXPKT_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_CSUM_LOC
value|30
end_define

begin_define
define|#
directive|define
name|M_TXPKT_CSUM_LOC
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_CSUM_LOC
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_CSUM_LOC)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_CSUM_LOC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_CSUM_LOC)& M_TXPKT_CSUM_LOC)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_ETHHDR_LEN
value|34
end_define

begin_define
define|#
directive|define
name|M_TXPKT_ETHHDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_TXPKT_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_ETHHDR_LEN)& M_TXPKT_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_T6_TXPKT_ETHHDR_LEN
value|32
end_define

begin_define
define|#
directive|define
name|M_T6_TXPKT_ETHHDR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_T6_TXPKT_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_T6_TXPKT_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_T6_TXPKT_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_T6_TXPKT_ETHHDR_LEN)& M_T6_TXPKT_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_CSUM_TYPE
value|40
end_define

begin_define
define|#
directive|define
name|M_TXPKT_CSUM_TYPE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_TXPKT_CSUM_TYPE
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_CSUM_TYPE)
end_define

begin_define
define|#
directive|define
name|G_TXPKT_CSUM_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TXPKT_CSUM_TYPE)& M_TXPKT_CSUM_TYPE)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_VLAN
value|44
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
value|((__u64)(x)<< S_TXPKT_VLAN)
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
name|S_TXPKT_VLAN_VLD
value|60
end_define

begin_define
define|#
directive|define
name|V_TXPKT_VLAN_VLD
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_VLAN_VLD)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_VLAN_VLD
value|V_TXPKT_VLAN_VLD(1ULL)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_IPSEC
value|61
end_define

begin_define
define|#
directive|define
name|V_TXPKT_IPSEC
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_IPSEC)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_IPSEC
value|V_TXPKT_IPSEC(1ULL)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_IPCSUM_DIS
value|62
end_define

begin_define
define|#
directive|define
name|V_TXPKT_IPCSUM_DIS
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_IPCSUM_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_IPCSUM_DIS
value|V_TXPKT_IPCSUM_DIS(1ULL)
end_define

begin_define
define|#
directive|define
name|S_TXPKT_L4CSUM_DIS
value|63
end_define

begin_define
define|#
directive|define
name|V_TXPKT_L4CSUM_DIS
parameter_list|(
name|x
parameter_list|)
value|((__u64)(x)<< S_TXPKT_L4CSUM_DIS)
end_define

begin_define
define|#
directive|define
name|F_TXPKT_L4CSUM_DIS
value|V_TXPKT_L4CSUM_DIS(1ULL)
end_define

begin_struct
struct|struct
name|cpl_tx_pkt_lso_core
block|{
name|__be32
name|lso_ctrl
decl_stmt|;
name|__be16
name|ipid_ofst
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be32
name|seqno_offset
decl_stmt|;
name|__be32
name|len
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT, TX_PKT_XT or TX_DATA) follows here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tx_pkt_lso
block|{
name|WR_HDR
expr_stmt|;
name|struct
name|cpl_tx_pkt_lso_core
name|c
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT, TX_PKT_XT or TX_DATA) follows here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tx_pkt_ufo_core
block|{
name|__be16
name|ethlen
decl_stmt|;
name|__be16
name|iplen
decl_stmt|;
name|__be16
name|udplen
decl_stmt|;
name|__be16
name|mss
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|r1
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT, TX_PKT_XT or TX_DATA) follows here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tx_pkt_ufo
block|{
name|WR_HDR
expr_stmt|;
name|struct
name|cpl_tx_pkt_ufo_core
name|c
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT, TX_PKT_XT or TX_DATA) follows here */
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_pkt_lso_core.lso_ctrl fields */
end_comment

begin_define
define|#
directive|define
name|S_LSO_TCPHDR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_LSO_TCPHDR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LSO_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_LSO_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_TCPHDR_LEN)& M_LSO_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_LSO_IPHDR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|M_LSO_IPHDR_LEN
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_LSO_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_LSO_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_IPHDR_LEN)& M_LSO_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_LSO_ETHHDR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|M_LSO_ETHHDR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LSO_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_LSO_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_ETHHDR_LEN)& M_LSO_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_LSO_IPV6
value|20
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

begin_define
define|#
directive|define
name|S_LSO_OFLD_ENCAP
value|21
end_define

begin_define
define|#
directive|define
name|V_LSO_OFLD_ENCAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_OFLD_ENCAP)
end_define

begin_define
define|#
directive|define
name|F_LSO_OFLD_ENCAP
value|V_LSO_OFLD_ENCAP(1U)
end_define

begin_define
define|#
directive|define
name|S_LSO_LAST_SLICE
value|22
end_define

begin_define
define|#
directive|define
name|V_LSO_LAST_SLICE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_LAST_SLICE)
end_define

begin_define
define|#
directive|define
name|F_LSO_LAST_SLICE
value|V_LSO_LAST_SLICE(1U)
end_define

begin_define
define|#
directive|define
name|S_LSO_FIRST_SLICE
value|23
end_define

begin_define
define|#
directive|define
name|V_LSO_FIRST_SLICE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_FIRST_SLICE)
end_define

begin_define
define|#
directive|define
name|F_LSO_FIRST_SLICE
value|V_LSO_FIRST_SLICE(1U)
end_define

begin_define
define|#
directive|define
name|S_LSO_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_LSO_OPCODE
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_LSO_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_LSO_OPCODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_OPCODE)& M_LSO_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_LSO_T5_XFER_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_LSO_T5_XFER_SIZE
value|0xFFFFFFF
end_define

begin_define
define|#
directive|define
name|V_LSO_T5_XFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_T5_XFER_SIZE)
end_define

begin_define
define|#
directive|define
name|G_LSO_T5_XFER_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LSO_T5_XFER_SIZE)& M_LSO_T5_XFER_SIZE)
end_define

begin_comment
comment|/* cpl_tx_pkt_lso_core.mss fields */
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
name|S_LSO_IPID_SPLIT
value|15
end_define

begin_define
define|#
directive|define
name|V_LSO_IPID_SPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LSO_IPID_SPLIT)
end_define

begin_define
define|#
directive|define
name|F_LSO_IPID_SPLIT
value|V_LSO_IPID_SPLIT(1U)
end_define

begin_struct
struct|struct
name|cpl_tx_pkt_fso
block|{
name|WR_HDR
expr_stmt|;
name|__be32
name|fso_ctrl
decl_stmt|;
name|__be16
name|seqcnt_ofst
decl_stmt|;
name|__be16
name|mtu
decl_stmt|;
name|__be32
name|param_offset
decl_stmt|;
name|__be32
name|len
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT or TX_PKT_XT) follows here */
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_pkt_fso.fso_ctrl fields different from cpl_tx_pkt_lso.lso_ctrl */
end_comment

begin_define
define|#
directive|define
name|S_FSO_XCHG_CLASS
value|21
end_define

begin_define
define|#
directive|define
name|V_FSO_XCHG_CLASS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FSO_XCHG_CLASS)
end_define

begin_define
define|#
directive|define
name|F_FSO_XCHG_CLASS
value|V_FSO_XCHG_CLASS(1U)
end_define

begin_define
define|#
directive|define
name|S_FSO_INITIATOR
value|20
end_define

begin_define
define|#
directive|define
name|V_FSO_INITIATOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FSO_INITIATOR)
end_define

begin_define
define|#
directive|define
name|F_FSO_INITIATOR
value|V_FSO_INITIATOR(1U)
end_define

begin_define
define|#
directive|define
name|S_FSO_FCHDR_LEN
value|12
end_define

begin_define
define|#
directive|define
name|M_FSO_FCHDR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_FSO_FCHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FSO_FCHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_FSO_FCHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_FSO_FCHDR_LEN)& M_FSO_FCHDR_LEN)
end_define

begin_struct
struct|struct
name|cpl_iscsi_hdr_no_rss
block|{
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

begin_struct
struct|struct
name|cpl_tx_data_iso
block|{
name|__be32
name|op_to_scsi
decl_stmt|;
name|__u8
name|reserved1
decl_stmt|;
name|__u8
name|ahs_len
decl_stmt|;
name|__be16
name|mpdu
decl_stmt|;
name|__be32
name|burst_size
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be32
name|reserved2_seglen_offset
decl_stmt|;
name|__be32
name|datasn_offset
decl_stmt|;
name|__be32
name|buffer_offset
decl_stmt|;
name|__be32
name|reserved3
decl_stmt|;
comment|/* encapsulated CPL_TX_DATA follows here */
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_data_iso.op_to_scsi fields */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_OP)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_OP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_OP)& M_CPL_TX_DATA_ISO_OP)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_FIRST
value|23
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_FIRST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_FIRST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_FIRST)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_FIRST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_FIRST)& M_CPL_TX_DATA_ISO_FIRST)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_FIRST
value|V_CPL_TX_DATA_ISO_FIRST(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_LAST
value|22
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_LAST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_LAST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_LAST)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_LAST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_LAST)& M_CPL_TX_DATA_ISO_LAST)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_LAST
value|V_CPL_TX_DATA_ISO_LAST(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_CPLHDRLEN
value|21
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_CPLHDRLEN
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_CPLHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_CPLHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_CPLHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_CPLHDRLEN)& M_CPL_TX_DATA_ISO_CPLHDRLEN)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_CPLHDRLEN
value|V_CPL_TX_DATA_ISO_CPLHDRLEN(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_HDRCRC
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_HDRCRC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_HDRCRC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_HDRCRC)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_HDRCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_HDRCRC)& M_CPL_TX_DATA_ISO_HDRCRC)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_HDRCRC
value|V_CPL_TX_DATA_ISO_HDRCRC(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_PLDCRC
value|19
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_PLDCRC
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_PLDCRC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_PLDCRC)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_PLDCRC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_PLDCRC)& M_CPL_TX_DATA_ISO_PLDCRC)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_PLDCRC
value|V_CPL_TX_DATA_ISO_PLDCRC(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_IMMEDIATE
value|18
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_IMMEDIATE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_IMMEDIATE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_IMMEDIATE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_IMMEDIATE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_IMMEDIATE)& M_CPL_TX_DATA_ISO_IMMEDIATE)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_DATA_ISO_IMMEDIATE
value|V_CPL_TX_DATA_ISO_IMMEDIATE(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_SCSI
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_SCSI
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_SCSI
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_DATA_ISO_SCSI)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_SCSI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_SCSI)& M_CPL_TX_DATA_ISO_SCSI)
end_define

begin_comment
comment|/* cpl_tx_data_iso.reserved2_seglen_offset fields */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_DATA_ISO_SEGLEN_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_DATA_ISO_SEGLEN_OFFSET
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_DATA_ISO_SEGLEN_OFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_DATA_ISO_SEGLEN_OFFSET)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_DATA_ISO_SEGLEN_OFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_DATA_ISO_SEGLEN_OFFSET)& \      M_CPL_TX_DATA_ISO_SEGLEN_OFFSET)
end_define

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
name|cpl_iscsi_data
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd0
index|[
literal|2
index|]
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
name|rsvd1
decl_stmt|;
name|__u8
name|status
decl_stmt|;
block|}
struct|;
end_struct

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
name|ddp_off
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|3
expr_stmt|;
else|#
directive|else
name|__u8
label|:
literal|3
expr_stmt|;
name|__u8
name|ddp_off
range|:
literal|1
decl_stmt|;
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
name|cpl_fcoe_hdr
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|oxid
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|rctl_fctl
decl_stmt|;
name|__u8
name|cs_ctl
decl_stmt|;
name|__u8
name|df_ctl
decl_stmt|;
name|__u8
name|sof
decl_stmt|;
name|__u8
name|eof
decl_stmt|;
name|__be16
name|seq_cnt
decl_stmt|;
name|__u8
name|seq_id
decl_stmt|;
name|__u8
name|type
decl_stmt|;
name|__be32
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_fcoe_hdr.rctl_fctl fields */
end_comment

begin_define
define|#
directive|define
name|S_FCOE_FCHDR_RCTL
value|24
end_define

begin_define
define|#
directive|define
name|M_FCOE_FCHDR_RCTL
value|0xff
end_define

begin_define
define|#
directive|define
name|V_FCOE_FCHDR_RCTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FCOE_FCHDR_RCTL)
end_define

begin_define
define|#
directive|define
name|G_FCOE_FCHDR_RCTL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FCOE_FCHDR_RCTL)& M_FCOE_FCHDR_RCTL)
end_define

begin_define
define|#
directive|define
name|S_FCOE_FCHDR_FCTL
value|0
end_define

begin_define
define|#
directive|define
name|M_FCOE_FCHDR_FCTL
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_FCOE_FCHDR_FCTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FCOE_FCHDR_FCTL)
end_define

begin_define
define|#
directive|define
name|G_FCOE_FCHDR_FCTL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FCOE_FCHDR_FCTL)& M_FCOE_FCHDR_FCTL)
end_define

begin_struct
struct|struct
name|cpl_fcoe_data
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|rsvd0
index|[
literal|2
index|]
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__u8
name|rsvd1
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
name|cpl_rx_urg_pkt
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

begin_struct
struct|struct
name|cpl_rx_data_ack_core
block|{
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
value|0x3FFFFFF
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
name|S_RX_MODULATE_TX
value|26
end_define

begin_define
define|#
directive|define
name|V_RX_MODULATE_TX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_MODULATE_TX)
end_define

begin_define
define|#
directive|define
name|F_RX_MODULATE_TX
value|V_RX_MODULATE_TX(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_MODULATE_RX
value|27
end_define

begin_define
define|#
directive|define
name|V_RX_MODULATE_RX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_MODULATE_RX)
end_define

begin_define
define|#
directive|define
name|F_RX_MODULATE_RX
value|V_RX_MODULATE_RX(1U)
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
name|__be32
name|rcv_nxt
decl_stmt|;
name|__be32
name|rsvd
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
name|u
union|;
name|__be32
name|ulp_crc
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cpl_rx_iscsi_ddp
value|cpl_rx_data_ddp
end_define

begin_struct
struct|struct
name|cpl_rx_fcoe_ddp
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
name|__be32
name|ddp_report
decl_stmt|;
name|__be32
name|ulp_crc
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_data_dif
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|ddp_len
decl_stmt|;
name|__be16
name|msg_len
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
name|u
union|;
name|__be32
name|err_vec
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_iscsi_dif
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|ddp_len
decl_stmt|;
name|__be16
name|msg_len
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
name|u
union|;
name|__be32
name|ulp_crc
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
name|__u8
name|rsvd0
index|[
literal|8
index|]
decl_stmt|;
name|__be32
name|err_vec
decl_stmt|;
name|__u8
name|rsvd1
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_iscsi_cmp
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
name|__be32
name|ulp_crc
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_rx_fcoe_dif
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|ddp_len
decl_stmt|;
name|__be16
name|msg_len
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__be32
name|ddp_report
decl_stmt|;
name|__be32
name|err_vec
decl_stmt|;
name|__be32
name|ddpvld
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_rx_{data,iscsi,fcoe}_{ddp,dif}.ddpvld fields */
end_comment

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
comment|/* cpl_rx_{data,iscsi,fcoe}_{ddp,dif}.ddp_report fields */
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
value|0xFFFFFF
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
name|S_DDP_DACK_MODE
value|24
end_define

begin_define
define|#
directive|define
name|M_DDP_DACK_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_DDP_DACK_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_DACK_MODE)
end_define

begin_define
define|#
directive|define
name|G_DDP_DACK_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_DDP_DACK_MODE)& M_DDP_DACK_MODE)
end_define

begin_define
define|#
directive|define
name|S_DDP_BUF_IDX
value|26
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

begin_define
define|#
directive|define
name|S_DDP_URG
value|27
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
value|28
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
value|29
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
value|30
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
name|S_DDP_INV
value|31
end_define

begin_define
define|#
directive|define
name|V_DDP_INV
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_DDP_INV)
end_define

begin_define
define|#
directive|define
name|F_DDP_INV
value|V_DDP_INV(1U)
end_define

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
name|csum_calc
range|:
literal|1
decl_stmt|;
name|__u8
name|ipmi_pkt
range|:
literal|1
decl_stmt|;
name|__u8
name|vlan_ex
range|:
literal|1
decl_stmt|;
name|__u8
name|ip_frag
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|ip_frag
range|:
literal|1
decl_stmt|;
name|__u8
name|vlan_ex
range|:
literal|1
decl_stmt|;
name|__u8
name|ipmi_pkt
range|:
literal|1
decl_stmt|;
name|__u8
name|csum_calc
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
name|__be32
name|l2info
decl_stmt|;
name|__be16
name|hdr_len
decl_stmt|;
name|__be16
name|err_vec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* rx_pkt.l2info fields */
end_comment

begin_define
define|#
directive|define
name|S_RX_ETHHDR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_RX_ETHHDR_LEN
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_RX_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_RX_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_ETHHDR_LEN)& M_RX_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_RX_T5_ETHHDR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_RX_T5_ETHHDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_RX_T5_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_T5_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_RX_T5_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_T5_ETHHDR_LEN)& M_RX_T5_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|M_RX_T6_ETHHDR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|G_RX_T6_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_ETHHDR_LEN)& M_RX_T6_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_RX_PKTYPE
value|5
end_define

begin_define
define|#
directive|define
name|M_RX_PKTYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_RX_PKTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_PKTYPE)
end_define

begin_define
define|#
directive|define
name|G_RX_PKTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_PKTYPE)& M_RX_PKTYPE)
end_define

begin_define
define|#
directive|define
name|S_RX_T5_DATYPE
value|6
end_define

begin_define
define|#
directive|define
name|M_RX_T5_DATYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RX_T5_DATYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_T5_DATYPE)
end_define

begin_define
define|#
directive|define
name|G_RX_T5_DATYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_T5_DATYPE)& M_RX_T5_DATYPE)
end_define

begin_define
define|#
directive|define
name|S_RX_MACIDX
value|8
end_define

begin_define
define|#
directive|define
name|M_RX_MACIDX
value|0x1FF
end_define

begin_define
define|#
directive|define
name|V_RX_MACIDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_MACIDX)
end_define

begin_define
define|#
directive|define
name|G_RX_MACIDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_MACIDX)& M_RX_MACIDX)
end_define

begin_define
define|#
directive|define
name|S_RX_T5_PKTYPE
value|17
end_define

begin_define
define|#
directive|define
name|M_RX_T5_PKTYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_RX_T5_PKTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_T5_PKTYPE)
end_define

begin_define
define|#
directive|define
name|G_RX_T5_PKTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_T5_PKTYPE)& M_RX_T5_PKTYPE)
end_define

begin_define
define|#
directive|define
name|S_RX_DATYPE
value|18
end_define

begin_define
define|#
directive|define
name|M_RX_DATYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_RX_DATYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_DATYPE)
end_define

begin_define
define|#
directive|define
name|G_RX_DATYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_DATYPE)& M_RX_DATYPE)
end_define

begin_define
define|#
directive|define
name|S_RXF_PSH
value|20
end_define

begin_define
define|#
directive|define
name|V_RXF_PSH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_PSH)
end_define

begin_define
define|#
directive|define
name|F_RXF_PSH
value|V_RXF_PSH(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_SYN
value|21
end_define

begin_define
define|#
directive|define
name|V_RXF_SYN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_SYN)
end_define

begin_define
define|#
directive|define
name|F_RXF_SYN
value|V_RXF_SYN(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_UDP
value|22
end_define

begin_define
define|#
directive|define
name|V_RXF_UDP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_UDP)
end_define

begin_define
define|#
directive|define
name|F_RXF_UDP
value|V_RXF_UDP(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_TCP
value|23
end_define

begin_define
define|#
directive|define
name|V_RXF_TCP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_TCP)
end_define

begin_define
define|#
directive|define
name|F_RXF_TCP
value|V_RXF_TCP(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_IP
value|24
end_define

begin_define
define|#
directive|define
name|V_RXF_IP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_IP)
end_define

begin_define
define|#
directive|define
name|F_RXF_IP
value|V_RXF_IP(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_IP6
value|25
end_define

begin_define
define|#
directive|define
name|V_RXF_IP6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_IP6)
end_define

begin_define
define|#
directive|define
name|F_RXF_IP6
value|V_RXF_IP6(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_SYN_COOKIE
value|26
end_define

begin_define
define|#
directive|define
name|V_RXF_SYN_COOKIE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_SYN_COOKIE)
end_define

begin_define
define|#
directive|define
name|F_RXF_SYN_COOKIE
value|V_RXF_SYN_COOKIE(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_FCOE
value|26
end_define

begin_define
define|#
directive|define
name|V_RXF_FCOE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_FCOE)
end_define

begin_define
define|#
directive|define
name|F_RXF_FCOE
value|V_RXF_FCOE(1U)
end_define

begin_define
define|#
directive|define
name|S_RXF_LRO
value|27
end_define

begin_define
define|#
directive|define
name|V_RXF_LRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXF_LRO)
end_define

begin_define
define|#
directive|define
name|F_RXF_LRO
value|V_RXF_LRO(1U)
end_define

begin_define
define|#
directive|define
name|S_RX_CHAN
value|28
end_define

begin_define
define|#
directive|define
name|M_RX_CHAN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_RX_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_CHAN)
end_define

begin_define
define|#
directive|define
name|G_RX_CHAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_CHAN)& M_RX_CHAN)
end_define

begin_comment
comment|/* rx_pkt.hdr_len fields */
end_comment

begin_define
define|#
directive|define
name|S_RX_TCPHDR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_RX_TCPHDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_RX_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_RX_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_TCPHDR_LEN)& M_RX_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_RX_IPHDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|M_RX_IPHDR_LEN
value|0x3FF
end_define

begin_define
define|#
directive|define
name|V_RX_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RX_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_RX_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RX_IPHDR_LEN)& M_RX_IPHDR_LEN)
end_define

begin_comment
comment|/* rx_pkt.err_vec fields */
end_comment

begin_define
define|#
directive|define
name|S_RXERR_OR
value|0
end_define

begin_define
define|#
directive|define
name|V_RXERR_OR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_OR)
end_define

begin_define
define|#
directive|define
name|F_RXERR_OR
value|V_RXERR_OR(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_MAC
value|1
end_define

begin_define
define|#
directive|define
name|V_RXERR_MAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_MAC)
end_define

begin_define
define|#
directive|define
name|F_RXERR_MAC
value|V_RXERR_MAC(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_IPVERS
value|2
end_define

begin_define
define|#
directive|define
name|V_RXERR_IPVERS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_IPVERS)
end_define

begin_define
define|#
directive|define
name|F_RXERR_IPVERS
value|V_RXERR_IPVERS(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_FRAG
value|3
end_define

begin_define
define|#
directive|define
name|V_RXERR_FRAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_FRAG)
end_define

begin_define
define|#
directive|define
name|F_RXERR_FRAG
value|V_RXERR_FRAG(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_ATTACK
value|4
end_define

begin_define
define|#
directive|define
name|V_RXERR_ATTACK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_ATTACK)
end_define

begin_define
define|#
directive|define
name|F_RXERR_ATTACK
value|V_RXERR_ATTACK(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_ETHHDR_LEN
value|5
end_define

begin_define
define|#
directive|define
name|V_RXERR_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|F_RXERR_ETHHDR_LEN
value|V_RXERR_ETHHDR_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_IPHDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|V_RXERR_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|F_RXERR_IPHDR_LEN
value|V_RXERR_IPHDR_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_TCPHDR_LEN
value|7
end_define

begin_define
define|#
directive|define
name|V_RXERR_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|F_RXERR_TCPHDR_LEN
value|V_RXERR_TCPHDR_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_PKT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|V_RXERR_PKT_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_PKT_LEN)
end_define

begin_define
define|#
directive|define
name|F_RXERR_PKT_LEN
value|V_RXERR_PKT_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_TCP_OPT
value|9
end_define

begin_define
define|#
directive|define
name|V_RXERR_TCP_OPT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_TCP_OPT)
end_define

begin_define
define|#
directive|define
name|F_RXERR_TCP_OPT
value|V_RXERR_TCP_OPT(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_IPCSUM
value|12
end_define

begin_define
define|#
directive|define
name|V_RXERR_IPCSUM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_IPCSUM)
end_define

begin_define
define|#
directive|define
name|F_RXERR_IPCSUM
value|V_RXERR_IPCSUM(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_CSUM
value|13
end_define

begin_define
define|#
directive|define
name|V_RXERR_CSUM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_CSUM)
end_define

begin_define
define|#
directive|define
name|F_RXERR_CSUM
value|V_RXERR_CSUM(1U)
end_define

begin_define
define|#
directive|define
name|S_RXERR_PING
value|14
end_define

begin_define
define|#
directive|define
name|V_RXERR_PING
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RXERR_PING)
end_define

begin_define
define|#
directive|define
name|F_RXERR_PING
value|V_RXERR_PING(1U)
end_define

begin_comment
comment|/* In T6, rx_pkt.err_vec indicates  * RxError Error vector (16b) or  * Encapsulating header length (8b),  * Outer encapsulation type (2b) and  * compressed error vector (6b) if CRxPktEnc is  * enabled in TP_OUT_CONFIG  */
end_comment

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_VEC
value|0
end_define

begin_define
define|#
directive|define
name|M_T6_COMPR_RXERR_VEC
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_VEC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_VEC)
end_define

begin_define
define|#
directive|define
name|G_T6_COMPR_RXERR_VEC
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_T6_COMPR_RXERR_VEC)& M_T6_COMPR_RXERR_VEC)
end_define

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_MAC
value|0
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_MAC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_MAC)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_MAC
value|V_T6_COMPR_RXERR_MAC(1U)
end_define

begin_comment
comment|/* Logical OR of RX_ERROR_PKT_LEN, RX_ERROR_TCP_HDR_LEN  * RX_ERROR_IP_HDR_LEN, RX_ERROR_ETH_HDR_LEN  */
end_comment

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_LEN
value|1
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_LEN)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_LEN
value|V_COMPR_T6_RXERR_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_TCP_OPT
value|2
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_TCP_OPT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_TCP_OPT)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_TCP_OPT
value|V_T6_COMPR_RXERR_TCP_OPT(1U)
end_define

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_IPV6_EXT
value|3
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_IPV6_EXT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_IPV6_EXT)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_IPV6_EXT
value|V_T6_COMPR_RXERR_IPV6_EXT(1U)
end_define

begin_comment
comment|/* Logical OR of RX_ERROR_CSUM, RX_ERROR_CSIP */
end_comment

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_SUM
value|4
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_SUM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_SUM)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_SUM
value|V_T6_COMPR_RXERR_SUM(1U)
end_define

begin_comment
comment|/* Logical OR of RX_ERROR_FPMA, RX_ERROR_PING_DROP,  * RX_ERROR_ATTACK, RX_ERROR_FRAG,RX_ERROR_IPVERSION  */
end_comment

begin_define
define|#
directive|define
name|S_T6_COMPR_RXERR_MISC
value|5
end_define

begin_define
define|#
directive|define
name|V_T6_COMPR_RXERR_MISC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_COMPR_RXERR_MISC)
end_define

begin_define
define|#
directive|define
name|F_T6_COMPR_RXERR_MISC
value|V_T6_COMPR_RXERR_MISC(1U)
end_define

begin_define
define|#
directive|define
name|S_T6_RX_TNL_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|M_T6_RX_TNL_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_T6_RX_TNL_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_RX_TNL_TYPE)
end_define

begin_define
define|#
directive|define
name|G_T6_RX_TNL_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T6_RX_TNL_TYPE)& M_T6_RX_TNL_TYPE)
end_define

begin_define
define|#
directive|define
name|RX_PKT_TNL_TYPE_NVGRE
value|1
end_define

begin_define
define|#
directive|define
name|RX_PKT_TNL_TYPE_VXLAN
value|2
end_define

begin_define
define|#
directive|define
name|RX_PKT_TNL_TYPE_GENEVE
value|3
end_define

begin_define
define|#
directive|define
name|S_T6_RX_TNLHDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|M_T6_RX_TNLHDR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_T6_RX_TNLHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T6_RX_TNLHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_T6_RX_TNLHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_T6_RX_TNLHDR_LEN)& M_T6_RX_TNLHDR_LEN)
end_define

begin_struct
struct|struct
name|cpl_trace_pkt
block|{
name|RSS_HDR
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|intf
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|runt
range|:
literal|4
decl_stmt|;
name|__u8
name|filter_hit
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|6
expr_stmt|;
name|__u8
name|err
range|:
literal|1
decl_stmt|;
name|__u8
name|trunc
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|filter_hit
range|:
literal|4
decl_stmt|;
name|__u8
name|runt
range|:
literal|4
decl_stmt|;
name|__u8
name|trunc
range|:
literal|1
decl_stmt|;
name|__u8
name|err
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|6
expr_stmt|;
endif|#
directive|endif
name|__be16
name|rsvd
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be64
name|tstamp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_t5_trace_pkt
block|{
name|RSS_HDR
name|__u8
name|opcode
decl_stmt|;
name|__u8
name|intf
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
name|__u8
name|runt
range|:
literal|4
decl_stmt|;
name|__u8
name|filter_hit
range|:
literal|4
decl_stmt|;
name|__u8
label|:
literal|6
expr_stmt|;
name|__u8
name|err
range|:
literal|1
decl_stmt|;
name|__u8
name|trunc
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|filter_hit
range|:
literal|4
decl_stmt|;
name|__u8
name|runt
range|:
literal|4
decl_stmt|;
name|__u8
name|trunc
range|:
literal|1
decl_stmt|;
name|__u8
name|err
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|6
expr_stmt|;
endif|#
directive|endif
name|__be16
name|rsvd
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be64
name|tstamp
decl_stmt|;
name|__be64
name|rsvd1
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
comment|/* {cpl_rte_delete_req, cpl_rte_read_req}.params fields */
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
name|__u32
name|write_sel
decl_stmt|;
name|__be32
name|lut_params
decl_stmt|;
name|__be32
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
comment|/* cpl_rte_write_req.write_sel fields */
end_comment

begin_define
define|#
directive|define
name|S_RTE_WR_L2TIDX
value|31
end_define

begin_define
define|#
directive|define
name|V_RTE_WR_L2TIDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WR_L2TIDX)
end_define

begin_define
define|#
directive|define
name|F_RTE_WR_L2TIDX
value|V_RTE_WR_L2TIDX(1U)
end_define

begin_define
define|#
directive|define
name|S_RTE_WR_FADDR
value|30
end_define

begin_define
define|#
directive|define
name|V_RTE_WR_FADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WR_FADDR)
end_define

begin_define
define|#
directive|define
name|F_RTE_WR_FADDR
value|V_RTE_WR_FADDR(1U)
end_define

begin_comment
comment|/* cpl_rte_write_req.lut_params fields */
end_comment

begin_define
define|#
directive|define
name|S_RTE_WR_LUT_IX
value|10
end_define

begin_define
define|#
directive|define
name|M_RTE_WR_LUT_IX
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_WR_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WR_LUT_IX)
end_define

begin_define
define|#
directive|define
name|G_RTE_WR_LUT_IX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_WR_LUT_IX)& M_RTE_WR_LUT_IX)
end_define

begin_define
define|#
directive|define
name|S_RTE_WR_LUT_BASE
value|21
end_define

begin_define
define|#
directive|define
name|M_RTE_WR_LUT_BASE
value|0x7FF
end_define

begin_define
define|#
directive|define
name|V_RTE_WR_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_RTE_WR_LUT_BASE)
end_define

begin_define
define|#
directive|define
name|G_RTE_WR_LUT_BASE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_RTE_WR_LUT_BASE)& M_RTE_WR_LUT_BASE)
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
name|rsvd
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
name|__u32
label|:
literal|30
expr_stmt|;
name|__u32
name|select
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u32
name|select
range|:
literal|1
decl_stmt|;
name|__u32
label|:
literal|30
expr_stmt|;
endif|#
directive|endif
name|__be32
name|addr
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
name|__be16
name|params
decl_stmt|;
name|__be16
name|l2t_idx
decl_stmt|;
name|__be16
name|vlan
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
name|S_L2T_W_INFO
value|2
end_define

begin_define
define|#
directive|define
name|M_L2T_W_INFO
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_L2T_W_INFO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_INFO)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_INFO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_INFO)& M_L2T_W_INFO)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_PORT
value|8
end_define

begin_define
define|#
directive|define
name|M_L2T_W_PORT
value|0x3
end_define

begin_define
define|#
directive|define
name|V_L2T_W_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_PORT)
end_define

begin_define
define|#
directive|define
name|G_L2T_W_PORT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_L2T_W_PORT)& M_L2T_W_PORT)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_LPBK
value|10
end_define

begin_define
define|#
directive|define
name|V_L2T_W_LPBK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_LPBK)
end_define

begin_define
define|#
directive|define
name|F_L2T_W_PKBK
value|V_L2T_W_LPBK(1U)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_ARPMISS
value|11
end_define

begin_define
define|#
directive|define
name|V_L2T_W_ARPMISS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_ARPMISS)
end_define

begin_define
define|#
directive|define
name|F_L2T_W_ARPMISS
value|V_L2T_W_ARPMISS(1U)
end_define

begin_define
define|#
directive|define
name|S_L2T_W_NOREPLY
value|15
end_define

begin_define
define|#
directive|define
name|V_L2T_W_NOREPLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_L2T_W_NOREPLY)
end_define

begin_define
define|#
directive|define
name|F_L2T_W_NOREPLY
value|V_L2T_W_NOREPLY(1U)
end_define

begin_define
define|#
directive|define
name|CPL_L2T_VLAN_NONE
value|0xfff
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
name|__be32
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
name|vlan
decl_stmt|;
name|__be16
name|info
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

begin_struct
struct|struct
name|cpl_srq_table_req
block|{
name|WR_HDR
expr_stmt|;
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
literal|2
index|]
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
name|__be64
name|rsvd_pdid
decl_stmt|;
name|__be32
name|qlen_qbase
decl_stmt|;
name|__be16
name|cur_msn
decl_stmt|;
name|__be16
name|max_msn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_srq_table_rpl
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
literal|2
index|]
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
name|__be64
name|rsvd_pdid
decl_stmt|;
name|__be32
name|qlen_qbase
decl_stmt|;
name|__be16
name|cur_msn
decl_stmt|;
name|__be16
name|max_msn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_srq_table_{req,rpl}.params fields */
end_comment

begin_define
define|#
directive|define
name|S_SRQT_QLEN
value|28
end_define

begin_define
define|#
directive|define
name|M_SRQT_QLEN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_SRQT_QLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SRQT_QLEN)
end_define

begin_define
define|#
directive|define
name|G_SRQT_QLEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SRQT_QLEN)& M_SRQT_QLEN)
end_define

begin_define
define|#
directive|define
name|S_SRQT_QBASE
value|0
end_define

begin_define
define|#
directive|define
name|M_SRQT_QBASE
value|0x3FFFFFF
end_define

begin_define
define|#
directive|define
name|V_SRQT_QBASE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SRQT_QBASE)
end_define

begin_define
define|#
directive|define
name|G_SRQT_QBASE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SRQT_QBASE)& M_SRQT_QBASE)
end_define

begin_define
define|#
directive|define
name|S_SRQT_PDID
value|0
end_define

begin_define
define|#
directive|define
name|M_SRQT_PDID
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_SRQT_PDID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SRQT_PDID)
end_define

begin_define
define|#
directive|define
name|G_SRQT_PDID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SRQT_PDID)& M_SRQT_PDID)
end_define

begin_define
define|#
directive|define
name|S_SRQT_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_SRQT_IDX
value|0xF
end_define

begin_define
define|#
directive|define
name|V_SRQT_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SRQT_IDX)
end_define

begin_define
define|#
directive|define
name|G_SRQT_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SRQT_IDX)& M_SRQT_IDX)
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
name|__be32
name|params
decl_stmt|;
name|__be16
name|pfvf1
decl_stmt|;
name|__u8
name|src_mac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|pfvf0
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
name|cpl_t6_smt_write_req
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
name|__be64
name|tag
decl_stmt|;
name|__be16
name|pfvf0
decl_stmt|;
name|__u8
name|src_mac0
index|[
literal|6
index|]
decl_stmt|;
name|__be32
name|local_ip
decl_stmt|;
name|__be32
name|rsvd
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
name|__be32
name|params
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
name|__u8
name|ovlan_idx
decl_stmt|;
name|__be16
name|rsvd
decl_stmt|;
name|__be16
name|pfvf1
decl_stmt|;
name|__u8
name|src_mac1
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|pfvf0
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

begin_comment
comment|/* cpl_smt_{read,write}_req.params fields */
end_comment

begin_define
define|#
directive|define
name|S_SMTW_OVLAN_IDX
value|16
end_define

begin_define
define|#
directive|define
name|M_SMTW_OVLAN_IDX
value|0xF
end_define

begin_define
define|#
directive|define
name|V_SMTW_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_OVLAN_IDX)
end_define

begin_define
define|#
directive|define
name|G_SMTW_OVLAN_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMTW_OVLAN_IDX)& M_SMTW_OVLAN_IDX)
end_define

begin_define
define|#
directive|define
name|S_SMTW_IDX
value|20
end_define

begin_define
define|#
directive|define
name|M_SMTW_IDX
value|0x7F
end_define

begin_define
define|#
directive|define
name|V_SMTW_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_IDX)
end_define

begin_define
define|#
directive|define
name|G_SMTW_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMTW_IDX)& M_SMTW_IDX)
end_define

begin_define
define|#
directive|define
name|M_T6_SMTW_IDX
value|0xFF
end_define

begin_define
define|#
directive|define
name|G_T6_SMTW_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMTW_IDX)& M_T6_SMTW_IDX)
end_define

begin_define
define|#
directive|define
name|S_SMTW_NORPL
value|31
end_define

begin_define
define|#
directive|define
name|V_SMTW_NORPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_NORPL)
end_define

begin_define
define|#
directive|define
name|F_SMTW_NORPL
value|V_SMTW_NORPL(1U)
end_define

begin_comment
comment|/* cpl_smt_{read,write}_req.pfvf? fields */
end_comment

begin_define
define|#
directive|define
name|S_SMTW_VF
value|0
end_define

begin_define
define|#
directive|define
name|M_SMTW_VF
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_SMTW_VF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_VF)
end_define

begin_define
define|#
directive|define
name|G_SMTW_VF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMTW_VF)& M_SMTW_VF)
end_define

begin_define
define|#
directive|define
name|S_SMTW_PF
value|8
end_define

begin_define
define|#
directive|define
name|M_SMTW_PF
value|0x7
end_define

begin_define
define|#
directive|define
name|V_SMTW_PF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_PF)
end_define

begin_define
define|#
directive|define
name|G_SMTW_PF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SMTW_PF)& M_SMTW_PF)
end_define

begin_define
define|#
directive|define
name|S_SMTW_VF_VLD
value|11
end_define

begin_define
define|#
directive|define
name|V_SMTW_VF_VLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SMTW_VF_VLD)
end_define

begin_define
define|#
directive|define
name|F_SMTW_VF_VLD
value|V_SMTW_VF_VLD(1U)
end_define

begin_struct
struct|struct
name|cpl_tag_write_req
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
name|__be64
name|tag_val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tag_write_rpl
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
literal|2
index|]
decl_stmt|;
name|__u8
name|idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_tag_read_req
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
name|cpl_tag_read_rpl
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
label|:
literal|4
expr_stmt|;
name|__u8
name|tag_len
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|2
expr_stmt|;
name|__u8
name|ins_enable
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|__u8
name|ins_enable
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|2
expr_stmt|;
name|__u8
name|tag_len
range|:
literal|1
decl_stmt|;
name|__u8
label|:
literal|4
expr_stmt|;
endif|#
directive|endif
name|__u8
name|rsvd
decl_stmt|;
name|__u8
name|tag_idx
decl_stmt|;
name|__be64
name|tag_val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tag{read,write}_req.params fields */
end_comment

begin_define
define|#
directive|define
name|S_TAGW_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_TAGW_IDX
value|0x7F
end_define

begin_define
define|#
directive|define
name|V_TAGW_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TAGW_IDX)
end_define

begin_define
define|#
directive|define
name|G_TAGW_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_TAGW_IDX)& M_TAGW_IDX)
end_define

begin_define
define|#
directive|define
name|S_TAGW_LEN
value|20
end_define

begin_define
define|#
directive|define
name|V_TAGW_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TAGW_LEN)
end_define

begin_define
define|#
directive|define
name|F_TAGW_LEN
value|V_TAGW_LEN(1U)
end_define

begin_define
define|#
directive|define
name|S_TAGW_INS_ENABLE
value|23
end_define

begin_define
define|#
directive|define
name|V_TAGW_INS_ENABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TAGW_INS_ENABLE)
end_define

begin_define
define|#
directive|define
name|F_TAGW_INS_ENABLE
value|V_TAGW_INS_ENABLE(1U)
end_define

begin_define
define|#
directive|define
name|S_TAGW_NORPL
value|31
end_define

begin_define
define|#
directive|define
name|V_TAGW_NORPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_TAGW_NORPL)
end_define

begin_define
define|#
directive|define
name|F_TAGW_NORPL
value|V_TAGW_NORPL(1U)
end_define

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
name|chan_map
decl_stmt|;
name|__be16
name|rsvd0
decl_stmt|;
name|__be32
name|rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_barrier.chan_map fields */
end_comment

begin_define
define|#
directive|define
name|S_CHAN_MAP
value|4
end_define

begin_define
define|#
directive|define
name|M_CHAN_MAP
value|0xF
end_define

begin_define
define|#
directive|define
name|V_CHAN_MAP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CHAN_MAP)
end_define

begin_define
define|#
directive|define
name|G_CHAN_MAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_CHAN_MAP)& M_CHAN_MAP)
end_define

begin_struct
struct|struct
name|cpl_error
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_hit_notify
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
name|__be32
name|info
decl_stmt|;
name|__be32
name|reason
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_pkt_notify
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
name|info
decl_stmt|;
name|__be32
name|reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_{hit,pkt}_notify.info fields */
end_comment

begin_define
define|#
directive|define
name|S_NTFY_MAC_IDX
value|0
end_define

begin_define
define|#
directive|define
name|M_NTFY_MAC_IDX
value|0x1FF
end_define

begin_define
define|#
directive|define
name|V_NTFY_MAC_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_MAC_IDX)
end_define

begin_define
define|#
directive|define
name|G_NTFY_MAC_IDX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_MAC_IDX)& M_NTFY_MAC_IDX)
end_define

begin_define
define|#
directive|define
name|S_NTFY_INTF
value|10
end_define

begin_define
define|#
directive|define
name|M_NTFY_INTF
value|0xF
end_define

begin_define
define|#
directive|define
name|V_NTFY_INTF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_INTF)
end_define

begin_define
define|#
directive|define
name|G_NTFY_INTF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_INTF)& M_NTFY_INTF)
end_define

begin_define
define|#
directive|define
name|S_NTFY_TCPHDR_LEN
value|14
end_define

begin_define
define|#
directive|define
name|M_NTFY_TCPHDR_LEN
value|0xF
end_define

begin_define
define|#
directive|define
name|V_NTFY_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_NTFY_TCPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_TCPHDR_LEN)& M_NTFY_TCPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_NTFY_IPHDR_LEN
value|18
end_define

begin_define
define|#
directive|define
name|M_NTFY_IPHDR_LEN
value|0x1FF
end_define

begin_define
define|#
directive|define
name|V_NTFY_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_NTFY_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_IPHDR_LEN)& M_NTFY_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_NTFY_ETHHDR_LEN
value|27
end_define

begin_define
define|#
directive|define
name|M_NTFY_ETHHDR_LEN
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_NTFY_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_NTFY_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_ETHHDR_LEN)& M_NTFY_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_NTFY_T5_IPHDR_LEN
value|18
end_define

begin_define
define|#
directive|define
name|M_NTFY_T5_IPHDR_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_NTFY_T5_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_T5_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_NTFY_T5_IPHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_T5_IPHDR_LEN)& M_NTFY_T5_IPHDR_LEN)
end_define

begin_define
define|#
directive|define
name|S_NTFY_T5_ETHHDR_LEN
value|26
end_define

begin_define
define|#
directive|define
name|M_NTFY_T5_ETHHDR_LEN
value|0x3F
end_define

begin_define
define|#
directive|define
name|V_NTFY_T5_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_NTFY_T5_ETHHDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_NTFY_T5_ETHHDR_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_NTFY_T5_ETHHDR_LEN)& M_NTFY_T5_ETHHDR_LEN)
end_define

begin_struct
struct|struct
name|cpl_rdma_terminate
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_set_le_req
block|{
name|WR_HDR
expr_stmt|;
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__be16
name|reply_ctrl
decl_stmt|;
name|__be16
name|params
decl_stmt|;
name|__be64
name|mask_hi
decl_stmt|;
name|__be64
name|mask_lo
decl_stmt|;
name|__be64
name|val_hi
decl_stmt|;
name|__be64
name|val_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_set_le_req.reply_ctrl additional fields */
end_comment

begin_define
define|#
directive|define
name|S_LE_REQ_IP6
value|13
end_define

begin_define
define|#
directive|define
name|V_LE_REQ_IP6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_REQ_IP6)
end_define

begin_define
define|#
directive|define
name|F_LE_REQ_IP6
value|V_LE_REQ_IP6(1U)
end_define

begin_comment
comment|/* cpl_set_le_req.params fields */
end_comment

begin_define
define|#
directive|define
name|S_LE_CHAN
value|0
end_define

begin_define
define|#
directive|define
name|M_LE_CHAN
value|0x3
end_define

begin_define
define|#
directive|define
name|V_LE_CHAN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_CHAN)
end_define

begin_define
define|#
directive|define
name|G_LE_CHAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_CHAN)& M_LE_CHAN)
end_define

begin_define
define|#
directive|define
name|S_LE_OFFSET
value|5
end_define

begin_define
define|#
directive|define
name|M_LE_OFFSET
value|0x7
end_define

begin_define
define|#
directive|define
name|V_LE_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_OFFSET)
end_define

begin_define
define|#
directive|define
name|G_LE_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_OFFSET)& M_LE_OFFSET)
end_define

begin_define
define|#
directive|define
name|S_LE_MORE
value|8
end_define

begin_define
define|#
directive|define
name|V_LE_MORE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_MORE)
end_define

begin_define
define|#
directive|define
name|F_LE_MORE
value|V_LE_MORE(1U)
end_define

begin_define
define|#
directive|define
name|S_LE_REQSIZE
value|9
end_define

begin_define
define|#
directive|define
name|M_LE_REQSIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_LE_REQSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_REQSIZE)
end_define

begin_define
define|#
directive|define
name|G_LE_REQSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_REQSIZE)& M_LE_REQSIZE)
end_define

begin_define
define|#
directive|define
name|S_LE_REQCMD
value|12
end_define

begin_define
define|#
directive|define
name|M_LE_REQCMD
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LE_REQCMD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_REQCMD)
end_define

begin_define
define|#
directive|define
name|G_LE_REQCMD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_REQCMD)& M_LE_REQCMD)
end_define

begin_struct
struct|struct
name|cpl_set_le_rpl
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|__u8
name|chan
decl_stmt|;
name|__u8
name|info
decl_stmt|;
name|__be16
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_set_le_rpl.info fields */
end_comment

begin_define
define|#
directive|define
name|S_LE_RSPCMD
value|0
end_define

begin_define
define|#
directive|define
name|M_LE_RSPCMD
value|0xF
end_define

begin_define
define|#
directive|define
name|V_LE_RSPCMD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_RSPCMD)
end_define

begin_define
define|#
directive|define
name|G_LE_RSPCMD
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_RSPCMD)& M_LE_RSPCMD)
end_define

begin_define
define|#
directive|define
name|S_LE_RSPSIZE
value|4
end_define

begin_define
define|#
directive|define
name|M_LE_RSPSIZE
value|0x7
end_define

begin_define
define|#
directive|define
name|V_LE_RSPSIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_RSPSIZE)
end_define

begin_define
define|#
directive|define
name|G_LE_RSPSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_LE_RSPSIZE)& M_LE_RSPSIZE)
end_define

begin_define
define|#
directive|define
name|S_LE_RSPTYPE
value|7
end_define

begin_define
define|#
directive|define
name|V_LE_RSPTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_LE_RSPTYPE)
end_define

begin_define
define|#
directive|define
name|F_LE_RSPTYPE
value|V_LE_RSPTYPE(1U)
end_define

begin_struct
struct|struct
name|cpl_sge_egr_update
block|{
name|RSS_HDR
name|__be32
name|opcode_qid
decl_stmt|;
name|__be16
name|cidx
decl_stmt|;
name|__be16
name|pidx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_sge_egr_update.ot fields */
end_comment

begin_define
define|#
directive|define
name|S_AUTOEQU
value|22
end_define

begin_define
define|#
directive|define
name|M_AUTOEQU
value|0x1
end_define

begin_define
define|#
directive|define
name|V_AUTOEQU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_AUTOEQU)
end_define

begin_define
define|#
directive|define
name|G_AUTOEQU
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_AUTOEQU)& M_AUTOEQU)
end_define

begin_define
define|#
directive|define
name|S_EGR_QID
value|0
end_define

begin_define
define|#
directive|define
name|M_EGR_QID
value|0x1FFFF
end_define

begin_define
define|#
directive|define
name|V_EGR_QID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_EGR_QID)
end_define

begin_define
define|#
directive|define
name|G_EGR_QID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_EGR_QID)& M_EGR_QID)
end_define

begin_comment
comment|/* cpl_fw*.type values */
end_comment

begin_enum
enum|enum
block|{
name|FW_TYPE_CMD_RPL
init|=
literal|0
block|,
name|FW_TYPE_WR_RPL
init|=
literal|1
block|,
name|FW_TYPE_CQE
init|=
literal|2
block|,
name|FW_TYPE_OFLD_CONNECTION_WR_RPL
init|=
literal|3
block|,
name|FW_TYPE_RSSCPL
init|=
literal|4
block|,
name|FW_TYPE_WRERR_RPL
init|=
literal|5
block|,
name|FW_TYPE_PI_ERR
init|=
literal|6
block|,
name|FW_TYPE_TLS_KEY
init|=
literal|7
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cpl_fw2_pld
block|{
name|RSS_HDR
name|u8
name|opcode
decl_stmt|;
name|u8
name|rsvd
index|[
literal|5
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
name|cpl_fw4_pld
block|{
name|RSS_HDR
name|u8
name|opcode
decl_stmt|;
name|u8
name|rsvd0
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|u8
name|rsvd1
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be64
name|data
decl_stmt|;
name|__be64
name|rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_fw6_pld
block|{
name|RSS_HDR
name|u8
name|opcode
decl_stmt|;
name|u8
name|rsvd
index|[
literal|5
index|]
decl_stmt|;
name|__be16
name|len
decl_stmt|;
name|__be64
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_fw2_msg
block|{
name|RSS_HDR
name|union
name|opcode_info
name|oi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_fw4_msg
block|{
name|RSS_HDR
name|u8
name|opcode
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|__be16
name|rsvd0
decl_stmt|;
name|__be32
name|rsvd1
decl_stmt|;
name|__be64
name|data
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpl_fw4_ack
block|{
name|RSS_HDR
name|union
name|opcode_tid
name|ot
decl_stmt|;
name|u8
name|credits
decl_stmt|;
name|u8
name|rsvd0
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|flags
decl_stmt|;
name|__be32
name|snd_nxt
decl_stmt|;
name|__be32
name|snd_una
decl_stmt|;
name|__be64
name|rsvd1
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|CPL_FW4_ACK_FLAGS_SEQVAL
init|=
literal|0x1
block|,
comment|/* seqn valid */
name|CPL_FW4_ACK_FLAGS_CH
init|=
literal|0x2
block|,
comment|/* channel change complete */
name|CPL_FW4_ACK_FLAGS_FLOWC
init|=
literal|0x4
block|,
comment|/* fw_flowc_wr complete */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|cpl_fw6_msg
block|{
name|RSS_HDR
name|u8
name|opcode
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|__be16
name|rsvd0
decl_stmt|;
name|__be32
name|rsvd1
decl_stmt|;
name|__be64
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_fw6_msg.type values */
end_comment

begin_enum
enum|enum
block|{
name|FW6_TYPE_CMD_RPL
init|=
name|FW_TYPE_CMD_RPL
block|,
name|FW6_TYPE_WR_RPL
init|=
name|FW_TYPE_WR_RPL
block|,
name|FW6_TYPE_CQE
init|=
name|FW_TYPE_CQE
block|,
name|FW6_TYPE_OFLD_CONNECTION_WR_RPL
init|=
name|FW_TYPE_OFLD_CONNECTION_WR_RPL
block|,
name|FW6_TYPE_RSSCPL
init|=
name|FW_TYPE_RSSCPL
block|,
name|FW6_TYPE_WRERR_RPL
init|=
name|FW_TYPE_WRERR_RPL
block|,
name|FW6_TYPE_PI_ERR
init|=
name|FW_TYPE_PI_ERR
block|,
name|NUM_FW6_TYPES
block|}
enum|;
end_enum

begin_struct
struct|struct
name|cpl_fw6_msg_ofld_connection_wr_rpl
block|{
name|__u64
name|cookie
decl_stmt|;
name|__be32
name|tid
decl_stmt|;
comment|/* or atid in case of active failure */
name|__u8
name|t_state
decl_stmt|;
name|__u8
name|retval
decl_stmt|;
name|__u8
name|rsvd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ULP_TX opcodes */
end_comment

begin_enum
enum|enum
block|{
name|ULP_TX_MEM_READ
init|=
literal|2
block|,
name|ULP_TX_MEM_WRITE
init|=
literal|3
block|,
name|ULP_TX_PKT
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ULP_TX_SC_NOOP
init|=
literal|0x80
block|,
name|ULP_TX_SC_IMM
init|=
literal|0x81
block|,
name|ULP_TX_SC_DSGL
init|=
literal|0x82
block|,
name|ULP_TX_SC_ISGL
init|=
literal|0x83
block|,
name|ULP_TX_SC_PICTRL
init|=
literal|0x84
block|,
name|ULP_TX_SC_MEMRD
init|=
literal|0x86
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|S_ULPTX_CMD
value|24
end_define

begin_define
define|#
directive|define
name|M_ULPTX_CMD
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_ULPTX_CMD
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULPTX_CMD)
end_define

begin_define
define|#
directive|define
name|S_ULPTX_LEN16
value|0
end_define

begin_define
define|#
directive|define
name|M_ULPTX_LEN16
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_ULPTX_LEN16
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULPTX_LEN16)
end_define

begin_define
define|#
directive|define
name|S_ULP_TX_SC_MORE
value|23
end_define

begin_define
define|#
directive|define
name|V_ULP_TX_SC_MORE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TX_SC_MORE)
end_define

begin_define
define|#
directive|define
name|F_ULP_TX_SC_MORE
value|V_ULP_TX_SC_MORE(1U)
end_define

begin_struct
struct|struct
name|ulptx_sge_pair
block|{
name|__be32
name|len
index|[
literal|2
index|]
decl_stmt|;
name|__be64
name|addr
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ulptx_sgl
block|{
name|__be32
name|cmd_nsge
decl_stmt|;
name|__be32
name|len0
decl_stmt|;
name|__be64
name|addr0
decl_stmt|;
if|#
directive|if
operator|!
operator|(
name|defined
name|C99_NOT_SUPPORTED
operator|)
name|struct
name|ulptx_sge_pair
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ulptx_isge
block|{
name|__be32
name|stag
decl_stmt|;
name|__be32
name|len
decl_stmt|;
name|__be64
name|target_ofst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ulptx_isgl
block|{
name|__be32
name|cmd_nisge
decl_stmt|;
name|__be32
name|rsvd
decl_stmt|;
if|#
directive|if
operator|!
operator|(
name|defined
name|C99_NOT_SUPPORTED
operator|)
name|struct
name|ulptx_isge
name|sge
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ulptx_idata
block|{
name|__be32
name|cmd_more
decl_stmt|;
name|__be32
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_ULPTX_NSGE
value|0
end_define

begin_define
define|#
directive|define
name|M_ULPTX_NSGE
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|V_ULPTX_NSGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULPTX_NSGE)
end_define

begin_define
define|#
directive|define
name|G_ULPTX_NSGE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_ULPTX_NSGE)& M_ULPTX_NSGE)
end_define

begin_struct
struct|struct
name|ulptx_sc_memrd
block|{
name|__be32
name|cmd_to_len
decl_stmt|;
name|__be32
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ulp_mem_io
block|{
name|WR_HDR
expr_stmt|;
name|__be32
name|cmd
decl_stmt|;
name|__be32
name|len16
decl_stmt|;
comment|/* command length */
name|__be32
name|dlen
decl_stmt|;
comment|/* data length in 32-byte units */
name|__be32
name|lock_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* additional ulp_mem_io.cmd fields */
end_comment

begin_define
define|#
directive|define
name|S_ULP_MEMIO_ORDER
value|23
end_define

begin_define
define|#
directive|define
name|V_ULP_MEMIO_ORDER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_MEMIO_ORDER)
end_define

begin_define
define|#
directive|define
name|F_ULP_MEMIO_ORDER
value|V_ULP_MEMIO_ORDER(1U)
end_define

begin_define
define|#
directive|define
name|S_T5_ULP_MEMIO_IMM
value|23
end_define

begin_define
define|#
directive|define
name|V_T5_ULP_MEMIO_IMM
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_ULP_MEMIO_IMM)
end_define

begin_define
define|#
directive|define
name|F_T5_ULP_MEMIO_IMM
value|V_T5_ULP_MEMIO_IMM(1U)
end_define

begin_define
define|#
directive|define
name|S_T5_ULP_MEMIO_ORDER
value|22
end_define

begin_define
define|#
directive|define
name|V_T5_ULP_MEMIO_ORDER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_ULP_MEMIO_ORDER)
end_define

begin_define
define|#
directive|define
name|F_T5_ULP_MEMIO_ORDER
value|V_T5_ULP_MEMIO_ORDER(1U)
end_define

begin_define
define|#
directive|define
name|S_T5_ULP_MEMIO_FID
value|4
end_define

begin_define
define|#
directive|define
name|M_T5_ULP_MEMIO_FID
value|0x7ff
end_define

begin_define
define|#
directive|define
name|V_T5_ULP_MEMIO_FID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_T5_ULP_MEMIO_FID)
end_define

begin_comment
comment|/* ulp_mem_io.lock_addr fields */
end_comment

begin_define
define|#
directive|define
name|S_ULP_MEMIO_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|M_ULP_MEMIO_ADDR
value|0x7FFFFFF
end_define

begin_define
define|#
directive|define
name|V_ULP_MEMIO_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_MEMIO_ADDR)
end_define

begin_define
define|#
directive|define
name|S_ULP_MEMIO_LOCK
value|31
end_define

begin_define
define|#
directive|define
name|V_ULP_MEMIO_LOCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_MEMIO_LOCK)
end_define

begin_define
define|#
directive|define
name|F_ULP_MEMIO_LOCK
value|V_ULP_MEMIO_LOCK(1U)
end_define

begin_comment
comment|/* ulp_mem_io.dlen fields */
end_comment

begin_define
define|#
directive|define
name|S_ULP_MEMIO_DATA_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_ULP_MEMIO_DATA_LEN
value|0x1F
end_define

begin_define
define|#
directive|define
name|V_ULP_MEMIO_DATA_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_MEMIO_DATA_LEN)
end_define

begin_comment
comment|/* ULP_TXPKT field values */
end_comment

begin_enum
enum|enum
block|{
name|ULP_TXPKT_DEST_TP
init|=
literal|0
block|,
name|ULP_TXPKT_DEST_SGE
block|,
name|ULP_TXPKT_DEST_UP
block|,
name|ULP_TXPKT_DEST_DEVNULL
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ulp_txpkt
block|{
name|__be32
name|cmd_dest
decl_stmt|;
name|__be32
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ulp_txpkt.cmd_dest fields */
end_comment

begin_define
define|#
directive|define
name|S_ULP_TXPKT_DATAMODIFY
value|23
end_define

begin_define
define|#
directive|define
name|M_ULP_TXPKT_DATAMODIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_ULP_TXPKT_DATAMODIFY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TXPKT_DATAMODIFY)
end_define

begin_define
define|#
directive|define
name|G_ULP_TXPKT_DATAMODIFY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_ULP_TXPKT_DATAMODIFY)& M_ULP_TXPKT_DATAMODIFY_)
end_define

begin_define
define|#
directive|define
name|F_ULP_TXPKT_DATAMODIFY
value|V_ULP_TXPKT_DATAMODIFY(1U)
end_define

begin_define
define|#
directive|define
name|S_ULP_TXPKT_CHANNELID
value|22
end_define

begin_define
define|#
directive|define
name|M_ULP_TXPKT_CHANNELID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_ULP_TXPKT_CHANNELID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TXPKT_CHANNELID)
end_define

begin_define
define|#
directive|define
name|G_ULP_TXPKT_CHANNELID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_ULP_TXPKT_CHANNELID)& M_ULP_TXPKT_CHANNELID)
end_define

begin_define
define|#
directive|define
name|F_ULP_TXPKT_CHANNELID
value|V_ULP_TXPKT_CHANNELID(1U)
end_define

begin_comment
comment|/* ulp_txpkt.cmd_dest fields */
end_comment

begin_define
define|#
directive|define
name|S_ULP_TXPKT_DEST
value|16
end_define

begin_define
define|#
directive|define
name|M_ULP_TXPKT_DEST
value|0x3
end_define

begin_define
define|#
directive|define
name|V_ULP_TXPKT_DEST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TXPKT_DEST)
end_define

begin_define
define|#
directive|define
name|S_ULP_TXPKT_FID
value|4
end_define

begin_define
define|#
directive|define
name|M_ULP_TXPKT_FID
value|0x7ff
end_define

begin_define
define|#
directive|define
name|V_ULP_TXPKT_FID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TXPKT_FID)
end_define

begin_define
define|#
directive|define
name|S_ULP_TXPKT_RO
value|3
end_define

begin_define
define|#
directive|define
name|V_ULP_TXPKT_RO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_ULP_TXPKT_RO)
end_define

begin_define
define|#
directive|define
name|F_ULP_TXPKT_RO
value|V_ULP_TXPKT_RO(1U)
end_define

begin_enum
enum|enum
name|cpl_tx_tnl_lso_type
block|{
name|TX_TNL_TYPE_OPAQUE
block|,
name|TX_TNL_TYPE_NVGRE
block|,
name|TX_TNL_TYPE_VXLAN
block|,
name|TX_TNL_TYPE_GENEVE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cpl_tx_tnl_lso
block|{
name|__be32
name|op_to_IpIdSplitOut
decl_stmt|;
name|__be16
name|IpIdOffsetOut
decl_stmt|;
name|__be16
name|UdpLenSetOut_to_TnlHdrLen
decl_stmt|;
name|__be64
name|r1
decl_stmt|;
name|__be32
name|Flow_to_TcpHdrLen
decl_stmt|;
name|__be16
name|IpIdOffset
decl_stmt|;
name|__be16
name|IpIdSplit_to_Mss
decl_stmt|;
name|__be32
name|TCPSeqOffset
decl_stmt|;
name|__be32
name|EthLenOffset_Size
decl_stmt|;
comment|/* encapsulated CPL (TX_PKT_XT) follows here */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_OPCODE)& M_CPL_TX_TNL_LSO_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_FIRST
value|23
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_FIRST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_FIRST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_FIRST)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_FIRST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_FIRST)& M_CPL_TX_TNL_LSO_FIRST)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_FIRST
value|V_CPL_TX_TNL_LSO_FIRST(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_LAST
value|22
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_LAST
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_LAST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_LAST)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_LAST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_LAST)& M_CPL_TX_TNL_LSO_LAST)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_LAST
value|V_CPL_TX_TNL_LSO_LAST(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_ETHHDRLENXOUT
value|21
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_ETHHDRLENXOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_ETHHDRLENXOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_ETHHDRLENXOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_ETHHDRLENXOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_ETHHDRLENXOUT)& M_CPL_TX_TNL_LSO_ETHHDRLENXOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_ETHHDRLENXOUT
value|V_CPL_TX_TNL_LSO_ETHHDRLENXOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPV6OUT
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPV6OUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPV6OUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPV6OUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPV6OUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPV6OUT)& M_CPL_TX_TNL_LSO_IPV6OUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPV6OUT
value|V_CPL_TX_TNL_LSO_IPV6OUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_ETHHDRLENOUT
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_ETHHDRLENOUT
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_ETHHDRLENOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_ETHHDRLENOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_ETHHDRLENOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_ETHHDRLENOUT)& M_CPL_TX_TNL_LSO_ETHHDRLENOUT)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPHDRLENOUT
value|4
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPHDRLENOUT
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPHDRLENOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPHDRLENOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPHDRLENOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPHDRLENOUT)& M_CPL_TX_TNL_LSO_IPHDRLENOUT)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPHDRCHKOUT
value|3
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPHDRCHKOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPHDRCHKOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPHDRCHKOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPHDRCHKOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPHDRCHKOUT)& M_CPL_TX_TNL_LSO_IPHDRCHKOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPHDRCHKOUT
value|V_CPL_TX_TNL_LSO_IPHDRCHKOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPLENSETOUT
value|2
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPLENSETOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPLENSETOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPLENSETOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPLENSETOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPLENSETOUT)& M_CPL_TX_TNL_LSO_IPLENSETOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPLENSETOUT
value|V_CPL_TX_TNL_LSO_IPLENSETOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPIDINCOUT
value|1
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPIDINCOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPIDINCOUT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPIDINCOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPIDINCOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPIDINCOUT)& M_CPL_TX_TNL_LSO_IPIDINCOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPIDINCOUT
value|V_CPL_TX_TNL_LSO_IPIDINCOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPIDSPLITOUT
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPIDSPLITOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPIDSPLITOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_IPIDSPLITOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPIDSPLITOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPIDSPLITOUT)& M_CPL_TX_TNL_LSO_IPIDSPLITOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPIDSPLITOUT
value|V_CPL_TX_TNL_LSO_IPIDSPLITOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_UDPLENSETOUT
value|15
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_UDPLENSETOUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_UDPLENSETOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_UDPLENSETOUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_UDPLENSETOUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_UDPLENSETOUT)& M_CPL_TX_TNL_LSO_UDPLENSETOUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_UDPLENSETOUT
value|V_CPL_TX_TNL_LSO_UDPLENSETOUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_UDPCHKCLROUT
value|14
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_UDPCHKCLROUT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_UDPCHKCLROUT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_UDPCHKCLROUT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_UDPCHKCLROUT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_UDPCHKCLROUT)& M_CPL_TX_TNL_LSO_UDPCHKCLROUT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_UDPCHKCLROUT
value|V_CPL_TX_TNL_LSO_UDPCHKCLROUT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_TNLTYPE
value|12
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_TNLTYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_TNLTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_TNLTYPE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_TNLTYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_TNLTYPE)& M_CPL_TX_TNL_LSO_TNLTYPE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_TNLHDRLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_TNLHDRLEN
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_TNLHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_TNLHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_TNLHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_TNLHDRLEN)& M_CPL_TX_TNL_LSO_TNLHDRLEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_FLOW
value|21
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_FLOW
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_FLOW
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_FLOW)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_FLOW
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_FLOW)& M_CPL_TX_TNL_LSO_FLOW)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_FLOW
value|V_CPL_TX_TNL_LSO_FLOW(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPV6
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPV6
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPV6
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPV6)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPV6
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPV6)& M_CPL_TX_TNL_LSO_IPV6)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPV6
value|V_CPL_TX_TNL_LSO_IPV6(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_ETHHDRLEN
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_ETHHDRLEN
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_ETHHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_ETHHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_ETHHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_ETHHDRLEN)& M_CPL_TX_TNL_LSO_ETHHDRLEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPHDRLEN
value|4
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPHDRLEN
value|0xfff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPHDRLEN)& M_CPL_TX_TNL_LSO_IPHDRLEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_TCPHDRLEN
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_TCPHDRLEN
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_TCPHDRLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_TCPHDRLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_TCPHDRLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_TCPHDRLEN)& M_CPL_TX_TNL_LSO_TCPHDRLEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_IPIDSPLIT
value|15
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_IPIDSPLIT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_IPIDSPLIT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_IPIDSPLIT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_IPIDSPLIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_IPIDSPLIT)& M_CPL_TX_TNL_LSO_IPIDSPLIT)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_IPIDSPLIT
value|V_CPL_TX_TNL_LSO_IPIDSPLIT(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_ETHHDRLENX
value|14
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_ETHHDRLENX
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_ETHHDRLENX
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_ETHHDRLENX)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_ETHHDRLENX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_ETHHDRLENX)& M_CPL_TX_TNL_LSO_ETHHDRLENX)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TNL_LSO_ETHHDRLENX
value|V_CPL_TX_TNL_LSO_ETHHDRLENX(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_MSS
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_MSS
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_MSS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_MSS)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_MSS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_MSS)& M_CPL_TX_TNL_LSO_MSS)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_ETHLENOFFSET
value|28
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_ETHLENOFFSET
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_ETHLENOFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_TNL_LSO_ETHLENOFFSET)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_ETHLENOFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_ETHLENOFFSET)& M_CPL_TX_TNL_LSO_ETHLENOFFSET)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TNL_LSO_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TNL_LSO_SIZE
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TNL_LSO_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TNL_LSO_SIZE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TNL_LSO_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TNL_LSO_SIZE)& M_CPL_TX_TNL_LSO_SIZE)
end_define

begin_struct
struct|struct
name|cpl_rx_mps_pkt
block|{
name|__be32
name|op_to_r1_hi
decl_stmt|;
name|__be32
name|r1_lo_length
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_RX_MPS_PKT_OP
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_MPS_PKT_OP
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_MPS_PKT_OP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_MPS_PKT_OP)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_MPS_PKT_OP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_MPS_PKT_OP)& M_CPL_RX_MPS_PKT_OP)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_MPS_PKT_TYPE
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_MPS_PKT_TYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_MPS_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_MPS_PKT_TYPE)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_MPS_PKT_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_MPS_PKT_TYPE)& M_CPL_RX_MPS_PKT_TYPE)
end_define

begin_comment
comment|/*  * Values for CPL_RX_MPS_PKT_TYPE, a bit-wise orthogonal field.  */
end_comment

begin_define
define|#
directive|define
name|X_CPL_RX_MPS_PKT_TYPE_PAUSE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|X_CPL_RX_MPS_PKT_TYPE_PPP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|X_CPL_RX_MPS_PKT_TYPE_QFC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|X_CPL_RX_MPS_PKT_TYPE_PTP
value|(1<< 3)
end_define

begin_struct
struct|struct
name|cpl_tx_tls_sfo
block|{
name|__be32
name|op_to_seg_len
decl_stmt|;
name|__be32
name|pld_len
decl_stmt|;
name|__be64
name|rsvd
decl_stmt|;
name|__be32
name|seqno_numivs
decl_stmt|;
name|__be32
name|ivgen_hdrlen
decl_stmt|;
name|__be64
name|scmd1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpl_tx_tls_sfo macros */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_SFO_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_SFO_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_SFO_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_SFO_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_SFO_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_SFO_OPCODE)& M_CPL_TX_TLS_SFO_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_SFO_DATA_TYPE
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_SFO_DATA_TYPE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_SFO_DATA_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_SFO_DATA_TYPE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_SFO_DATA_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_SFO_DATA_TYPE)& M_CPL_TX_TLS_SFO_DATA_TYPE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_SFO_CPL_LEN
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_SFO_CPL_LEN
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_SFO_CPL_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_SFO_CPL_LEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_SFO_CPL_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_SFO_CPL_LEN)& M_CPL_TX_TLS_SFO_CPL_LEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_SFO_SEG_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_SFO_SEG_LEN
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_SFO_SEG_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_SFO_SEG_LEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_SFO_SEG_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_SFO_SEG_LEN)& M_CPL_TX_TLS_SFO_SEG_LEN)
end_define

begin_struct
struct|struct
name|cpl_tls_data
block|{
name|RSS_HDR
name|__be32
name|op_tid
decl_stmt|;
name|__be32
name|length_pkd
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__be32
name|r1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_TLS_DATA_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TLS_DATA_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TLS_DATA_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TLS_DATA_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TLS_DATA_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TLS_DATA_OPCODE)& M_CPL_TLS_DATA_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TLS_DATA_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TLS_DATA_TID
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_CPL_TLS_DATA_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TLS_DATA_TID)
end_define

begin_define
define|#
directive|define
name|G_CPL_TLS_DATA_TID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TLS_DATA_TID)& M_CPL_TLS_DATA_TID)
end_define

begin_define
define|#
directive|define
name|S_CPL_TLS_DATA_LENGTH
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TLS_DATA_LENGTH
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_CPL_TLS_DATA_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TLS_DATA_LENGTH)
end_define

begin_define
define|#
directive|define
name|G_CPL_TLS_DATA_LENGTH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TLS_DATA_LENGTH)& M_CPL_TLS_DATA_LENGTH)
end_define

begin_struct
struct|struct
name|cpl_rx_tls_cmp
block|{
name|RSS_HDR
name|__be32
name|op_tid
decl_stmt|;
name|__be32
name|pdulength_length
decl_stmt|;
name|__be32
name|seq
decl_stmt|;
name|__be32
name|ddp_report
decl_stmt|;
name|__be32
name|r
decl_stmt|;
name|__be32
name|ddp_valid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_RX_TLS_CMP_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_TLS_CMP_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_TLS_CMP_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_TLS_CMP_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_TLS_CMP_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_TLS_CMP_OPCODE)& M_CPL_RX_TLS_CMP_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_TLS_CMP_TID
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_TLS_CMP_TID
value|0xffffff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_TLS_CMP_TID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_TLS_CMP_TID)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_TLS_CMP_TID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_TLS_CMP_TID)& M_CPL_RX_TLS_CMP_TID)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_TLS_CMP_PDULENGTH
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_TLS_CMP_PDULENGTH
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_TLS_CMP_PDULENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_TLS_CMP_PDULENGTH)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_TLS_CMP_PDULENGTH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_TLS_CMP_PDULENGTH)& M_CPL_RX_TLS_CMP_PDULENGTH)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_TLS_CMP_LENGTH
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_TLS_CMP_LENGTH
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_TLS_CMP_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_TLS_CMP_LENGTH)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_TLS_CMP_LENGTH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_TLS_CMP_LENGTH)& M_CPL_RX_TLS_CMP_LENGTH)
end_define

begin_define
define|#
directive|define
name|S_SCMD_SEQ_NO_CTRL
value|29
end_define

begin_define
define|#
directive|define
name|M_SCMD_SEQ_NO_CTRL
value|0x3
end_define

begin_define
define|#
directive|define
name|V_SCMD_SEQ_NO_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_SEQ_NO_CTRL)
end_define

begin_define
define|#
directive|define
name|G_SCMD_SEQ_NO_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_SEQ_NO_CTRL)& M_SCMD_SEQ_NO_CTRL)
end_define

begin_comment
comment|/* StsFieldPrsnt- Status field at the end of the TLS PDU */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_STATUS_PRESENT
value|28
end_define

begin_define
define|#
directive|define
name|M_SCMD_STATUS_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_STATUS_PRESENT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_STATUS_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_SCMD_STATUS_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_STATUS_PRESENT)& M_SCMD_STATUS_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_SCMD_STATUS_PRESENT
value|V_SCMD_STATUS_PRESENT(1U)
end_define

begin_comment
comment|/* ProtoVersion - Protocol Version 0: 1.2, 1:1.1, 2:DTLS, 3:Generic,  * 3-15: Reserved. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_PROTO_VERSION
value|24
end_define

begin_define
define|#
directive|define
name|M_SCMD_PROTO_VERSION
value|0xf
end_define

begin_define
define|#
directive|define
name|V_SCMD_PROTO_VERSION
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_PROTO_VERSION)
end_define

begin_define
define|#
directive|define
name|G_SCMD_PROTO_VERSION
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_PROTO_VERSION)& M_SCMD_PROTO_VERSION)
end_define

begin_comment
comment|/* EncDecCtrl - Encryption/Decryption Control. 0: Encrypt, 1: Decrypt */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_ENC_DEC_CTRL
value|23
end_define

begin_define
define|#
directive|define
name|M_SCMD_ENC_DEC_CTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_ENC_DEC_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_ENC_DEC_CTRL)
end_define

begin_define
define|#
directive|define
name|G_SCMD_ENC_DEC_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_ENC_DEC_CTRL)& M_SCMD_ENC_DEC_CTRL)
end_define

begin_define
define|#
directive|define
name|F_SCMD_ENC_DEC_CTRL
value|V_SCMD_ENC_DEC_CTRL(1U)
end_define

begin_comment
comment|/* CipherAuthSeqCtrl - Cipher Authentication Sequence Control. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_CIPH_AUTH_SEQ_CTRL
value|22
end_define

begin_define
define|#
directive|define
name|M_SCMD_CIPH_AUTH_SEQ_CTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_CIPH_AUTH_SEQ_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_SCMD_CIPH_AUTH_SEQ_CTRL)
end_define

begin_define
define|#
directive|define
name|G_SCMD_CIPH_AUTH_SEQ_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_CIPH_AUTH_SEQ_CTRL)& M_SCMD_CIPH_AUTH_SEQ_CTRL)
end_define

begin_define
define|#
directive|define
name|F_SCMD_CIPH_AUTH_SEQ_CTRL
value|V_SCMD_CIPH_AUTH_SEQ_CTRL(1U)
end_define

begin_comment
comment|/* CiphMode -  Cipher Mode. 0: NOP, 1:AES-CBC, 2:AES-GCM, 3:AES-CTR,  * 4:Generic-AES, 5-15: Reserved. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_CIPH_MODE
value|18
end_define

begin_define
define|#
directive|define
name|M_SCMD_CIPH_MODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_SCMD_CIPH_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_CIPH_MODE)
end_define

begin_define
define|#
directive|define
name|G_SCMD_CIPH_MODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_CIPH_MODE)& M_SCMD_CIPH_MODE)
end_define

begin_comment
comment|/* AuthMode - Auth Mode. 0: NOP, 1:SHA1, 2:SHA2-224, 3:SHA2-256  * 4-15: Reserved */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_AUTH_MODE
value|14
end_define

begin_define
define|#
directive|define
name|M_SCMD_AUTH_MODE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_SCMD_AUTH_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_AUTH_MODE)
end_define

begin_define
define|#
directive|define
name|G_SCMD_AUTH_MODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_AUTH_MODE)& M_SCMD_AUTH_MODE)
end_define

begin_comment
comment|/* HmacCtrl - HMAC Control. 0:NOP, 1:No truncation, 2:Support HMAC Truncation  * per RFC 4366, 3:IPSec 96 bits, 4-7:Reserved  */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_HMAC_CTRL
value|11
end_define

begin_define
define|#
directive|define
name|M_SCMD_HMAC_CTRL
value|0x7
end_define

begin_define
define|#
directive|define
name|V_SCMD_HMAC_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_HMAC_CTRL)
end_define

begin_define
define|#
directive|define
name|G_SCMD_HMAC_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_HMAC_CTRL)& M_SCMD_HMAC_CTRL)
end_define

begin_comment
comment|/* IvSize - IV size in units of 2 bytes */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_IV_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|M_SCMD_IV_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_SCMD_IV_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_IV_SIZE)
end_define

begin_define
define|#
directive|define
name|G_SCMD_IV_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_IV_SIZE)& M_SCMD_IV_SIZE)
end_define

begin_comment
comment|/* NumIVs - Number of IVs */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_NUM_IVS
value|0
end_define

begin_define
define|#
directive|define
name|M_SCMD_NUM_IVS
value|0x7f
end_define

begin_define
define|#
directive|define
name|V_SCMD_NUM_IVS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_NUM_IVS)
end_define

begin_define
define|#
directive|define
name|G_SCMD_NUM_IVS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_NUM_IVS)& M_SCMD_NUM_IVS)
end_define

begin_comment
comment|/* EnbDbgId - If this is enabled upper 20 (63:44) bits if SeqNumber  * (below) are used as Cid (connection id for debug status), these  * bits are padded to zero for forming the 64 bit  * sequence number for TLS  */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_ENB_DBGID
value|31
end_define

begin_define
define|#
directive|define
name|M_SCMD_ENB_DBGID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_ENB_DBGID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_ENB_DBGID)
end_define

begin_define
define|#
directive|define
name|G_SCMD_ENB_DBGID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_ENB_DBGID)& M_SCMD_ENB_DBGID)
end_define

begin_comment
comment|/* IV generation in SW. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_IV_GEN_CTRL
value|30
end_define

begin_define
define|#
directive|define
name|M_SCMD_IV_GEN_CTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_IV_GEN_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_IV_GEN_CTRL)
end_define

begin_define
define|#
directive|define
name|G_SCMD_IV_GEN_CTRL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_IV_GEN_CTRL)& M_SCMD_IV_GEN_CTRL)
end_define

begin_define
define|#
directive|define
name|F_SCMD_IV_GEN_CTRL
value|V_SCMD_IV_GEN_CTRL(1U)
end_define

begin_comment
comment|/* More frags */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_MORE_FRAGS
value|20
end_define

begin_define
define|#
directive|define
name|M_SCMD_MORE_FRAGS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_MORE_FRAGS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_MORE_FRAGS)
end_define

begin_define
define|#
directive|define
name|G_SCMD_MORE_FRAGS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SCMD_MORE_FRAGS)& M_SCMD_MORE_FRAGS)
end_define

begin_comment
comment|/*last frag */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_LAST_FRAG
value|19
end_define

begin_define
define|#
directive|define
name|M_SCMD_LAST_FRAG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_LAST_FRAG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_LAST_FRAG)
end_define

begin_define
define|#
directive|define
name|G_SCMD_LAST_FRAG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SCMD_LAST_FRAG)& M_SCMD_LAST_FRAG)
end_define

begin_comment
comment|/* TlsCompPdu */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_TLS_COMPPDU
value|18
end_define

begin_define
define|#
directive|define
name|M_SCMD_TLS_COMPPDU
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_TLS_COMPPDU
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_TLS_COMPPDU)
end_define

begin_define
define|#
directive|define
name|G_SCMD_TLS_COMPPDU
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_SCMD_TLS_COMPPDU)& M_SCMD_TLS_COMPPDU)
end_define

begin_comment
comment|/* KeyCntxtInline - Key context inline after the scmd  OR PayloadOnly*/
end_comment

begin_define
define|#
directive|define
name|S_SCMD_KEY_CTX_INLINE
value|17
end_define

begin_define
define|#
directive|define
name|M_SCMD_KEY_CTX_INLINE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_KEY_CTX_INLINE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_KEY_CTX_INLINE)
end_define

begin_define
define|#
directive|define
name|G_SCMD_KEY_CTX_INLINE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_KEY_CTX_INLINE)& M_SCMD_KEY_CTX_INLINE)
end_define

begin_define
define|#
directive|define
name|F_SCMD_KEY_CTX_INLINE
value|V_SCMD_KEY_CTX_INLINE(1U)
end_define

begin_comment
comment|/* TLSFragEnable - 0: Host created TLS PDUs, 1: TLS Framgmentation in ASIC */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_TLS_FRAG_ENABLE
value|16
end_define

begin_define
define|#
directive|define
name|M_SCMD_TLS_FRAG_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_TLS_FRAG_ENABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_TLS_FRAG_ENABLE)
end_define

begin_define
define|#
directive|define
name|G_SCMD_TLS_FRAG_ENABLE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_TLS_FRAG_ENABLE)& M_SCMD_TLS_FRAG_ENABLE)
end_define

begin_define
define|#
directive|define
name|F_SCMD_TLS_FRAG_ENABLE
value|V_SCMD_TLS_FRAG_ENABLE(1U)
end_define

begin_comment
comment|/* MacOnly - Only send the MAC and discard PDU. This is valid for hash only  * modes, in this case TLS_TX  will drop the PDU and only  * send back the MAC bytes. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_MAC_ONLY
value|15
end_define

begin_define
define|#
directive|define
name|M_SCMD_MAC_ONLY
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_MAC_ONLY
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_MAC_ONLY)
end_define

begin_define
define|#
directive|define
name|G_SCMD_MAC_ONLY
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_MAC_ONLY)& M_SCMD_MAC_ONLY)
end_define

begin_define
define|#
directive|define
name|F_SCMD_MAC_ONLY
value|V_SCMD_MAC_ONLY(1U)
end_define

begin_comment
comment|/* AadIVDrop - Drop the AAD and IV fields. Useful in protocols  * which have complex AAD and IV formations Eg:AES-CCM  */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_AADIVDROP
value|14
end_define

begin_define
define|#
directive|define
name|M_SCMD_AADIVDROP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_SCMD_AADIVDROP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_AADIVDROP)
end_define

begin_define
define|#
directive|define
name|G_SCMD_AADIVDROP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_AADIVDROP)& M_SCMD_AADIVDROP)
end_define

begin_define
define|#
directive|define
name|F_SCMD_AADIVDROP
value|V_SCMD_AADIVDROP(1U)
end_define

begin_comment
comment|/* HdrLength - Length of all headers excluding TLS header  * present before start of crypto PDU/payload. */
end_comment

begin_define
define|#
directive|define
name|S_SCMD_HDR_LEN
value|0
end_define

begin_define
define|#
directive|define
name|M_SCMD_HDR_LEN
value|0x3fff
end_define

begin_define
define|#
directive|define
name|V_SCMD_HDR_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_SCMD_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|G_SCMD_HDR_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_SCMD_HDR_LEN)& M_SCMD_HDR_LEN)
end_define

begin_struct
struct|struct
name|cpl_tx_sec_pdu
block|{
name|__be32
name|op_ivinsrtofst
decl_stmt|;
name|__be32
name|pldlen
decl_stmt|;
name|__be32
name|aadstart_cipherstop_hi
decl_stmt|;
name|__be32
name|cipherstop_lo_authinsert
decl_stmt|;
name|__be32
name|seqno_numivs
decl_stmt|;
name|__be32
name|ivgen_hdrlen
decl_stmt|;
name|__be64
name|scmd1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_OPCODE)& M_CPL_TX_SEC_PDU_OPCODE)
end_define

begin_comment
comment|/* RX Channel Id */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_RXCHID
value|22
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_RXCHID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_RXCHID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_RXCHID)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_RXCHID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_RXCHID)& M_CPL_TX_SEC_PDU_RXCHID)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_SEC_PDU_RXCHID
value|V_CPL_TX_SEC_PDU_RXCHID(1U)
end_define

begin_comment
comment|/* Ack Follows */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_ACKFOLLOWS
value|21
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_ACKFOLLOWS
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_ACKFOLLOWS
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_ACKFOLLOWS)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_ACKFOLLOWS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_ACKFOLLOWS)& M_CPL_TX_SEC_PDU_ACKFOLLOWS)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_SEC_PDU_ACKFOLLOWS
value|V_CPL_TX_SEC_PDU_ACKFOLLOWS(1U)
end_define

begin_comment
comment|/* Loopback bit in cpl_tx_sec_pdu */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_ULPTXLPBK
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_ULPTXLPBK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_ULPTXLPBK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_ULPTXLPBK)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_ULPTXLPBK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_ULPTXLPBK)& M_CPL_TX_SEC_PDU_ULPTXLPBK)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_SEC_PDU_ULPTXLPBK
value|V_CPL_TX_SEC_PDU_ULPTXLPBK(1U)
end_define

begin_comment
comment|/* Length of cpl header encapsulated */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_CPLLEN
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_CPLLEN
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_CPLLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_CPLLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_CPLLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_CPLLEN)& M_CPL_TX_SEC_PDU_CPLLEN)
end_define

begin_comment
comment|/* PlaceHolder */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_PLACEHOLDER
value|10
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_PLACEHOLDER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_PLACEHOLDER
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_PLACEHOLDER)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_PLACEHOLDER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_PLACEHOLDER)& \ 	 M_CPL_TX_SEC_PDU_PLACEHOLDER)
end_define

begin_comment
comment|/* IvInsrtOffset: Insertion location for IV */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_IVINSRTOFST
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_IVINSRTOFST
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_IVINSRTOFST
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_IVINSRTOFST)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_IVINSRTOFST
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_IVINSRTOFST)& \ 	 M_CPL_TX_SEC_PDU_IVINSRTOFST)
end_define

begin_comment
comment|/* AadStartOffset: Offset in bytes for AAD start from  * the first byte following  * the pkt headers (0-255  *  bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_AADSTART
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_AADSTART
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_AADSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_AADSTART)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_AADSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_AADSTART)& \ 	 M_CPL_TX_SEC_PDU_AADSTART)
end_define

begin_comment
comment|/* AadStopOffset: offset in bytes for AAD stop/end from the first byte following  * the pkt headers (0-511 bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_AADSTOP
value|15
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_AADSTOP
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_AADSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_AADSTOP)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_AADSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_AADSTOP)& M_CPL_TX_SEC_PDU_AADSTOP)
end_define

begin_comment
comment|/* CipherStartOffset: offset in bytes for encryption/decryption start from the  * first byte following the pkt headers (0-1023  *  bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_CIPHERSTART
value|5
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_CIPHERSTART
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_CIPHERSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_CIPHERSTART)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_CIPHERSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_CIPHERSTART)& \ 	 M_CPL_TX_SEC_PDU_CIPHERSTART)
end_define

begin_comment
comment|/* CipherStopOffset: offset in bytes for encryption/decryption end  * from end of the payload of this command (0-511 bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_CIPHERSTOP_HI
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_CIPHERSTOP_HI
value|0x1f
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_CIPHERSTOP_HI
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_SEC_PDU_CIPHERSTOP_HI)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_CIPHERSTOP_HI
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_CIPHERSTOP_HI)& \ 	 M_CPL_TX_SEC_PDU_CIPHERSTOP_HI)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_CIPHERSTOP_LO
value|28
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_CIPHERSTOP_LO
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_CIPHERSTOP_LO
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_TX_SEC_PDU_CIPHERSTOP_LO)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_CIPHERSTOP_LO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_CIPHERSTOP_LO)& \ 	 M_CPL_TX_SEC_PDU_CIPHERSTOP_LO)
end_define

begin_comment
comment|/* AuthStartOffset: offset in bytes for authentication start from  * the first byte following the pkt headers (0-1023)  *  */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_AUTHSTART
value|18
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_AUTHSTART
value|0x3ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_AUTHSTART
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_AUTHSTART)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_AUTHSTART
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_AUTHSTART)& \ 	 M_CPL_TX_SEC_PDU_AUTHSTART)
end_define

begin_comment
comment|/* AuthStopOffset: offset in bytes for authentication  * end from end of the payload of this command (0-511 Bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_AUTHSTOP
value|9
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_AUTHSTOP
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_AUTHSTOP
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_AUTHSTOP)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_AUTHSTOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_AUTHSTOP)& \ 	 M_CPL_TX_SEC_PDU_AUTHSTOP)
end_define

begin_comment
comment|/* AuthInsrtOffset: offset in bytes for authentication insertion  * from end of the payload of this command (0-511 bytes) */
end_comment

begin_define
define|#
directive|define
name|S_CPL_TX_SEC_PDU_AUTHINSERT
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_SEC_PDU_AUTHINSERT
value|0x1ff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_SEC_PDU_AUTHINSERT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_SEC_PDU_AUTHINSERT)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_SEC_PDU_AUTHINSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_SEC_PDU_AUTHINSERT)& \ 	 M_CPL_TX_SEC_PDU_AUTHINSERT)
end_define

begin_struct
struct|struct
name|cpl_rx_phys_dsgl
block|{
name|__be32
name|op_to_tid
decl_stmt|;
name|__be32
name|pcirlxorder_to_noofsgentr
decl_stmt|;
name|struct
name|rss_header
name|rss_hdr_int
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_PHYS_DSGL_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_OPCODE)& M_CPL_RX_PHYS_DSGL_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_ISRDMA
value|23
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_ISRDMA
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_ISRDMA
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_PHYS_DSGL_ISRDMA)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_ISRDMA
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_ISRDMA)& M_CPL_RX_PHYS_DSGL_ISRDMA)
end_define

begin_define
define|#
directive|define
name|F_CPL_RX_PHYS_DSGL_ISRDMA
value|V_CPL_RX_PHYS_DSGL_ISRDMA(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_RSVD1
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_RSVD1
value|0x7
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_RSVD1
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_PHYS_DSGL_RSVD1)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_RSVD1
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_RSVD1)& M_CPL_RX_PHYS_DSGL_RSVD1)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_PCIRLXORDER
value|31
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_PCIRLXORDER
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_PCIRLXORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_RX_PHYS_DSGL_PCIRLXORDER)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_PCIRLXORDER
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_PCIRLXORDER)& \ 	 M_CPL_RX_PHYS_DSGL_PCIRLXORDER)
end_define

begin_define
define|#
directive|define
name|F_CPL_RX_PHYS_DSGL_PCIRLXORDER
value|V_CPL_RX_PHYS_DSGL_PCIRLXORDER(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_PCINOSNOOP
value|30
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_PCINOSNOOP
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_PCINOSNOOP
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_RX_PHYS_DSGL_PCINOSNOOP)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_PCINOSNOOP
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_PCINOSNOOP)& \ 	 M_CPL_RX_PHYS_DSGL_PCINOSNOOP)
end_define

begin_define
define|#
directive|define
name|F_CPL_RX_PHYS_DSGL_PCINOSNOOP
value|V_CPL_RX_PHYS_DSGL_PCINOSNOOP(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_PCITPHNTENB
value|29
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_PCITPHNTENB
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_PCITPHNTENB
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_RX_PHYS_DSGL_PCITPHNTENB)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_PCITPHNTENB
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_PCITPHNTENB)& \ 	 M_CPL_RX_PHYS_DSGL_PCITPHNTENB)
end_define

begin_define
define|#
directive|define
name|F_CPL_RX_PHYS_DSGL_PCITPHNTENB
value|V_CPL_RX_PHYS_DSGL_PCITPHNTENB(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_PCITPHNT
value|27
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_PCITPHNT
value|0x3
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_PCITPHNT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_PHYS_DSGL_PCITPHNT)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_PCITPHNT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_PCITPHNT)& \ 	M_CPL_RX_PHYS_DSGL_PCITPHNT)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_DCAID
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_DCAID
value|0x7ff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_DCAID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_RX_PHYS_DSGL_DCAID)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_DCAID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_DCAID)& \ 	 M_CPL_RX_PHYS_DSGL_DCAID)
end_define

begin_define
define|#
directive|define
name|S_CPL_RX_PHYS_DSGL_NOOFSGENTR
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_RX_PHYS_DSGL_NOOFSGENTR
value|0xffff
end_define

begin_define
define|#
directive|define
name|V_CPL_RX_PHYS_DSGL_NOOFSGENTR
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< S_CPL_RX_PHYS_DSGL_NOOFSGENTR)
end_define

begin_define
define|#
directive|define
name|G_CPL_RX_PHYS_DSGL_NOOFSGENTR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_RX_PHYS_DSGL_NOOFSGENTR)& \ 	 M_CPL_RX_PHYS_DSGL_NOOFSGENTR)
end_define

begin_comment
comment|/* CPL_TX_TLS_ACK */
end_comment

begin_struct
struct|struct
name|cpl_tx_tls_ack
block|{
name|__be32
name|op_to_Rsvd2
decl_stmt|;
name|__be32
name|PldLen
decl_stmt|;
name|__be64
name|Rsvd3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_OPCODE
value|24
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_OPCODE
value|0xff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_OPCODE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_OPCODE)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_OPCODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_OPCODE)& M_CPL_TX_TLS_ACK_OPCODE)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_RSVD1
value|23
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_RSVD1
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_RSVD1
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_RSVD1)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_RSVD1
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_RSVD1)& M_CPL_TX_TLS_ACK_RSVD1)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_RSVD1
value|V_CPL_TX_TLS_ACK_RSVD1(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_RXCHID
value|22
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_RXCHID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_RXCHID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_RXCHID)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_RXCHID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_RXCHID)& M_CPL_TX_TLS_ACK_RXCHID)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_RXCHID
value|V_CPL_TX_TLS_ACK_RXCHID(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_FWMSG
value|21
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_FWMSG
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_FWMSG
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_FWMSG)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_FWMSG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_FWMSG)& M_CPL_TX_TLS_ACK_FWMSG)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_FWMSG
value|V_CPL_TX_TLS_ACK_FWMSG(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_ULPTXLPBK
value|20
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_ULPTXLPBK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_ULPTXLPBK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_ULPTXLPBK)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_ULPTXLPBK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_ULPTXLPBK)& M_CPL_TX_TLS_ACK_ULPTXLPBK)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_ULPTXLPBK
value|V_CPL_TX_TLS_ACK_ULPTXLPBK(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_CPLLEN
value|16
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_CPLLEN
value|0xf
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_CPLLEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_CPLLEN)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_CPLLEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_CPLLEN)& M_CPL_TX_TLS_ACK_CPLLEN)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_COMPLONERR
value|15
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_COMPLONERR
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_COMPLONERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_COMPLONERR)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_COMPLONERR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_COMPLONERR)& M_CPL_TX_TLS_ACK_COMPLONERR)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_COMPLONERR
value|V_CPL_TX_TLS_ACK_COMPLONERR(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_LCB
value|14
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_LCB
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_LCB
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_LCB)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_LCB
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_LCB)& M_CPL_TX_TLS_ACK_LCB)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_LCB
value|V_CPL_TX_TLS_ACK_LCB(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_PHASH
value|13
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_PHASH
value|0x1
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_PHASH
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_PHASH)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_PHASH
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_PHASH)& M_CPL_TX_TLS_ACK_PHASH)
end_define

begin_define
define|#
directive|define
name|F_CPL_TX_TLS_ACK_PHASH
value|V_CPL_TX_TLS_ACK_PHASH(1U)
end_define

begin_define
define|#
directive|define
name|S_CPL_TX_TLS_ACK_RSVD2
value|0
end_define

begin_define
define|#
directive|define
name|M_CPL_TX_TLS_ACK_RSVD2
value|0x1fff
end_define

begin_define
define|#
directive|define
name|V_CPL_TX_TLS_ACK_RSVD2
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_CPL_TX_TLS_ACK_RSVD2)
end_define

begin_define
define|#
directive|define
name|G_CPL_TX_TLS_ACK_RSVD2
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_CPL_TX_TLS_ACK_RSVD2)& M_CPL_TX_TLS_ACK_RSVD2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T4_MSG_H */
end_comment

end_unit

