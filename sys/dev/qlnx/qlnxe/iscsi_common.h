begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISCSI_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__ISCSI_COMMON__
end_define

begin_comment
comment|/**********************/
end_comment

begin_comment
comment|/* ISCSI FW CONSTANTS */
end_comment

begin_comment
comment|/**********************/
end_comment

begin_comment
comment|/* iSCSI HSI constants */
end_comment

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_MTU
value|(1500)
end_define

begin_comment
comment|/* KWQ (kernel work queue) layer codes */
end_comment

begin_define
define|#
directive|define
name|ISCSI_SLOW_PATH_LAYER_CODE
value|(6)
end_define

begin_comment
comment|/* iSCSI parameter defaults */
end_comment

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_HEADER_DIGEST
value|(0)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_DATA_DIGEST
value|(0)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_INITIAL_R2T
value|(1)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_IMMEDIATE_DATA
value|(1)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_MAX_PDU_LENGTH
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_FIRST_BURST_LENGTH
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_MAX_BURST_LENGTH
value|(0x40000)
end_define

begin_define
define|#
directive|define
name|ISCSI_DEFAULT_MAX_OUTSTANDING_R2T
value|(1)
end_define

begin_comment
comment|/* iSCSI parameter limits */
end_comment

begin_define
define|#
directive|define
name|ISCSI_MIN_VAL_MAX_PDU_LENGTH
value|(0x200)
end_define

begin_define
define|#
directive|define
name|ISCSI_MAX_VAL_MAX_PDU_LENGTH
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|ISCSI_MIN_VAL_BURST_LENGTH
value|(0x200)
end_define

begin_define
define|#
directive|define
name|ISCSI_MAX_VAL_BURST_LENGTH
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|ISCSI_MIN_VAL_MAX_OUTSTANDING_R2T
value|(1)
end_define

begin_define
define|#
directive|define
name|ISCSI_MAX_VAL_MAX_OUTSTANDING_R2T
value|(0xff)
end_define

begin_comment
comment|// 0x10000 according to RFC
end_comment

begin_define
define|#
directive|define
name|ISCSI_AHS_CNTL_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ISCSI_WQE_NUM_SGES_SLOWIO
value|(0xf)
end_define

begin_comment
comment|/* iSCSI reserved params */
end_comment

begin_define
define|#
directive|define
name|ISCSI_ITT_ALL_ONES
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|ISCSI_TTT_ALL_ONES
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPTION_1_OFF_CHIP_TCP
value|1
end_define

begin_define
define|#
directive|define
name|ISCSI_OPTION_2_ON_CHIP_TCP
value|2
end_define

begin_define
define|#
directive|define
name|ISCSI_INITIATOR_MODE
value|0
end_define

begin_define
define|#
directive|define
name|ISCSI_TARGET_MODE
value|1
end_define

begin_comment
comment|/* iSCSI request op codes */
end_comment

begin_define
define|#
directive|define
name|ISCSI_OPCODE_NOP_OUT
value|(0)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_SCSI_CMD
value|(1)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_TMF_REQUEST
value|(2)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_LOGIN_REQUEST
value|(3)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_TEXT_REQUEST
value|(4)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_DATA_OUT
value|(5)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_LOGOUT_REQUEST
value|(6)
end_define

begin_comment
comment|/* iSCSI response/messages op codes */
end_comment

begin_define
define|#
directive|define
name|ISCSI_OPCODE_NOP_IN
value|(0x20)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_SCSI_RESPONSE
value|(0x21)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_TMF_RESPONSE
value|(0x22)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_LOGIN_RESPONSE
value|(0x23)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_TEXT_RESPONSE
value|(0x24)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_DATA_IN
value|(0x25)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_LOGOUT_RESPONSE
value|(0x26)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_R2T
value|(0x31)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_ASYNC_MSG
value|(0x32)
end_define

begin_define
define|#
directive|define
name|ISCSI_OPCODE_REJECT
value|(0x3f)
end_define

begin_comment
comment|/* iSCSI stages */
end_comment

begin_define
define|#
directive|define
name|ISCSI_STAGE_SECURITY_NEGOTIATION
value|(0)
end_define

begin_define
define|#
directive|define
name|ISCSI_STAGE_LOGIN_OPERATIONAL_NEGOTIATION
value|(1)
end_define

begin_define
define|#
directive|define
name|ISCSI_STAGE_FULL_FEATURE_PHASE
value|(3)
end_define

begin_comment
comment|/* iSCSI CQE errors */
end_comment

begin_define
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_DIGEST
value|(0x08)
end_define

begin_define
define|#
directive|define
name|CQE_ERROR_BITMAP_RCV_ON_INVALID_CONN
value|(0x10)
end_define

begin_define
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_TRUNCATED
value|(0x20)
end_define

begin_comment
comment|/*  * ISCSI SGL entry  */
end_comment

begin_struct
struct|struct
name|cqe_error_bitmap
block|{
name|u8
name|cqe_error_status_bits
decl_stmt|;
define|#
directive|define
name|CQE_ERROR_BITMAP_DIF_ERR_BITS_MASK
value|0x7
comment|/* Mark task with DIF error (3 bit): [0]-CRC/checksum, [1]-app tag, [2]-reference tag */
define|#
directive|define
name|CQE_ERROR_BITMAP_DIF_ERR_BITS_SHIFT
value|0
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_DIGEST_ERR_MASK
value|0x1
comment|/* Mark task with data digest error (1 bit) */
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_DIGEST_ERR_SHIFT
value|3
define|#
directive|define
name|CQE_ERROR_BITMAP_RCV_ON_INVALID_CONN_MASK
value|0x1
comment|/* Mark receive on invalid connection */
define|#
directive|define
name|CQE_ERROR_BITMAP_RCV_ON_INVALID_CONN_SHIFT
value|4
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_TRUNCATED_ERR_MASK
value|0x1
comment|/* Target Mode - Mark middle task error, data truncated */
define|#
directive|define
name|CQE_ERROR_BITMAP_DATA_TRUNCATED_ERR_SHIFT
value|5
define|#
directive|define
name|CQE_ERROR_BITMAP_UNDER_RUN_ERR_MASK
value|0x1
define|#
directive|define
name|CQE_ERROR_BITMAP_UNDER_RUN_ERR_SHIFT
value|6
define|#
directive|define
name|CQE_ERROR_BITMAP_RESERVED2_MASK
value|0x1
define|#
directive|define
name|CQE_ERROR_BITMAP_RESERVED2_SHIFT
value|7
block|}
struct|;
end_struct

begin_union
union|union
name|cqe_error_status
block|{
name|u8
name|error_status
comment|/* all error bits as uint8 */
decl_stmt|;
name|struct
name|cqe_error_bitmap
name|error_bits
comment|/* cqe errors bitmap */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI Login Response PDU header  */
end_comment

begin_struct
struct|struct
name|data_hdr
block|{
name|__le32
name|data
index|[
literal|12
index|]
comment|/* iscsi header data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Asynchronous Message PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_async_msg_hdr
block|{
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_RSRV_MASK
value|0x7F
comment|/* reserved */
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_CONST1_MASK
value|0x1
comment|/* const1 */
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_CONST1_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_ASYNC_MSG_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|all_ones
comment|/* should be 0xffffffff */
decl_stmt|;
name|__le32
name|reserved1
comment|/* reserved */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* stat_sn */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* exp_cmd_sn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* max_cmd_sn */
decl_stmt|;
name|__le16
name|param1_rsrv
comment|/* Parameter1 or Reserved */
decl_stmt|;
name|u8
name|async_vcode
comment|/* AsuncVCode */
decl_stmt|;
name|u8
name|async_event
comment|/* AsyncEvent */
decl_stmt|;
name|__le16
name|param3_rsrv
comment|/* Parameter3 or Reserved */
decl_stmt|;
name|__le16
name|param2_rsrv
comment|/* Parameter2 or Reserved */
decl_stmt|;
name|__le32
name|reserved7
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Command PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_cmd_hdr
block|{
name|__le16
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_HDR_ATTR_MASK
value|0x7
comment|/* attributes */
define|#
directive|define
name|ISCSI_CMD_HDR_ATTR_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_HDR_RSRV_MASK
value|0x3
comment|/* reserved */
define|#
directive|define
name|ISCSI_CMD_HDR_RSRV_SHIFT
value|3
define|#
directive|define
name|ISCSI_CMD_HDR_WRITE_MASK
value|0x1
comment|/* write */
define|#
directive|define
name|ISCSI_CMD_HDR_WRITE_SHIFT
value|5
define|#
directive|define
name|ISCSI_CMD_HDR_READ_MASK
value|0x1
comment|/* read */
define|#
directive|define
name|ISCSI_CMD_HDR_READ_SHIFT
value|6
define|#
directive|define
name|ISCSI_CMD_HDR_FINAL_MASK
value|0x1
comment|/* final */
define|#
directive|define
name|ISCSI_CMD_HDR_FINAL_SHIFT
value|7
name|u8
name|hdr_first_byte
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_HDR_OPCODE_MASK
value|0x3F
comment|/* Opcode */
define|#
directive|define
name|ISCSI_CMD_HDR_OPCODE_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_HDR_IMM_MASK
value|0x1
comment|/* Immediate delivery */
define|#
directive|define
name|ISCSI_CMD_HDR_IMM_SHIFT
value|6
define|#
directive|define
name|ISCSI_CMD_HDR_RSRV1_MASK
value|0x1
comment|/* first bit of iSCSI PDU header */
define|#
directive|define
name|ISCSI_CMD_HDR_RSRV1_SHIFT
value|7
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_CMD_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_CMD_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number. [constant, initialized] */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|expected_transfer_length
comment|/* Expected Data Transfer Length (only 3 bytes are significant) */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* CmdSn. [constant, initialized] */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* various fields for middle-path PDU. [constant, initialized] */
decl_stmt|;
name|__le32
name|cdb
index|[
literal|4
index|]
comment|/* CDB. [constant, initialized] */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Common PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_common_hdr
block|{
name|u8
name|hdr_status
comment|/* Status field of ISCSI header */
decl_stmt|;
name|u8
name|hdr_response
comment|/* Response field of ISCSI header for Responses / Reserved for Data-In */
decl_stmt|;
name|u8
name|hdr_flags
comment|/* Flags field of ISCSI header */
decl_stmt|;
name|u8
name|hdr_first_byte
decl_stmt|;
define|#
directive|define
name|ISCSI_COMMON_HDR_OPCODE_MASK
value|0x3F
comment|/* Opcode */
define|#
directive|define
name|ISCSI_COMMON_HDR_OPCODE_SHIFT
value|0
define|#
directive|define
name|ISCSI_COMMON_HDR_IMM_MASK
value|0x1
comment|/* Immediate */
define|#
directive|define
name|ISCSI_COMMON_HDR_IMM_SHIFT
value|6
define|#
directive|define
name|ISCSI_COMMON_HDR_RSRV_MASK
value|0x1
comment|/* first bit of iSCSI PDU header */
define|#
directive|define
name|ISCSI_COMMON_HDR_RSRV_SHIFT
value|7
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_COMMON_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_COMMON_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_COMMON_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_COMMON_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun_reserved
comment|/* Bytes 8..15 : LUN (if PDU contains a LUN field) or reserved */
decl_stmt|;
name|__le32
name|itt
comment|/* ITT - common to all headers */
decl_stmt|;
name|__le32
name|ttt
comment|/* bytes 20 to 23 - common ttt to various PDU headers */
decl_stmt|;
name|__le32
name|cmdstat_sn
comment|/* bytes 24 to 27 - common cmd_sn (initiator) or stat_sn (target) to various PDU headers */
decl_stmt|;
name|__le32
name|exp_statcmd_sn
comment|/* bytes 28 to 31 - common expected stat_sn (initiator) or cmd_sn (target) to various PDU headers */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* bytes 32 to 35 - common max cmd_sn to various PDU headers */
decl_stmt|;
name|__le32
name|data
index|[
literal|3
index|]
comment|/* bytes 36 to 47 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISCSI connection offload params passed by driver to FW in ISCSI offload ramrod   */
end_comment

begin_struct
struct|struct
name|iscsi_conn_offload_params
block|{
name|struct
name|regpair
name|sq_pbl_addr
comment|/* PBL SQ pointer */
decl_stmt|;
name|struct
name|regpair
name|r2tq_pbl_addr
comment|/* PBL R2TQ pointer */
decl_stmt|;
name|struct
name|regpair
name|xhq_pbl_addr
comment|/* PBL XHQ pointer */
decl_stmt|;
name|struct
name|regpair
name|uhq_pbl_addr
comment|/* PBL UHQ pointer */
decl_stmt|;
name|__le32
name|initial_ack
comment|/* Initial ack, received from TCP */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* Physical QM queue to be tied to logical Q0 */
decl_stmt|;
name|__le16
name|physical_q1
comment|/* Physical QM queue to be tied to logical Q1 */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_TCP_ON_CHIP_1B_MASK
value|0x1
comment|/* TCP connect/terminate option. 0 - TCP on host (option-1); 1 - TCP on chip (option-2). */
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_TCP_ON_CHIP_1B_SHIFT
value|0
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_TARGET_MODE_MASK
value|0x1
comment|/* iSCSI connect mode: 0-iSCSI Initiator, 1-iSCSI Target */
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_TARGET_MODE_SHIFT
value|1
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_RESTRICTED_MODE_MASK
value|0x1
comment|/* Restricted mode: 0 - un-restricted (deviating from the RFC), 1 - restricted (according to the RFC) */
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_RESTRICTED_MODE_SHIFT
value|2
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_RESERVED1_MASK
value|0x1F
comment|/* reserved */
define|#
directive|define
name|ISCSI_CONN_OFFLOAD_PARAMS_RESERVED1_SHIFT
value|3
name|u8
name|pbl_page_size_log
comment|/* Page size with PBEs log; Page Size = 2^(page_size_log+12) */
decl_stmt|;
name|u8
name|pbe_page_size_log
comment|/* PBE page size with log; Page Size = 2^(page_size_log+12) */
decl_stmt|;
name|u8
name|default_cq
comment|/* Default CQ used to write unsolicited data */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* StatSn for Target Mode only: the first Login Response StatSn value for Target mode */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * spe message header   */
end_comment

begin_struct
struct|struct
name|iscsi_slow_path_hdr
block|{
name|u8
name|op_code
comment|/* iscsi bus-drv message opcode */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_RESERVED0_MASK
value|0xF
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_RESERVED0_SHIFT
value|0
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_LAYER_CODE_MASK
value|0x7
comment|/* protocol layer (L2,L3,L4,L5) */
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_RESERVED1_MASK
value|0x1
define|#
directive|define
name|ISCSI_SLOW_PATH_HDR_RESERVED1_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISCSI connection update params passed by driver to FW in ISCSI update ramrod   */
end_comment

begin_struct
struct|struct
name|iscsi_conn_update_ramrod_params
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|conn_id
comment|/* ISCSI Connection ID. (MOTI_COHEN : draft for DrvSim sake) */
decl_stmt|;
name|__le32
name|fw_cid
comment|/* Context ID (cid) of the connection. (MOTI_COHEN : draft for DrvSim sake) */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_HD_EN_MASK
value|0x1
comment|/* Is header digest enabled */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_HD_EN_SHIFT
value|0
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DD_EN_MASK
value|0x1
comment|/* Is data digest enabled */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DD_EN_SHIFT
value|1
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_INITIAL_R2T_MASK
value|0x1
comment|/* Initial R2T */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_INITIAL_R2T_SHIFT
value|2
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_IMMEDIATE_DATA_MASK
value|0x1
comment|/* Immediate data */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_IMMEDIATE_DATA_SHIFT
value|3
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DIF_BLOCK_SIZE_MASK
value|0x1
comment|/* 0 - 512B, 1 - 4K */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DIF_BLOCK_SIZE_SHIFT
value|4
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DIF_ON_HOST_EN_MASK
value|0x1
comment|/* 0 - no DIF, 1 - could be enabled per task */
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_DIF_ON_HOST_EN_SHIFT
value|5
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_RESERVED1_MASK
value|0x3
define|#
directive|define
name|ISCSI_CONN_UPDATE_RAMROD_PARAMS_RESERVED1_SHIFT
value|6
name|u8
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
name|__le32
name|max_seq_size
comment|/* Maximum sequence size. Valid for TX and RX */
decl_stmt|;
name|__le32
name|max_send_pdu_length
comment|/* Maximum PDU size. Valid for the TX */
decl_stmt|;
name|__le32
name|max_recv_pdu_length
comment|/* Maximum PDU size. Valid for the RX */
decl_stmt|;
name|__le32
name|first_seq_length
comment|/* Initial sequence length */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* ExpStatSn - Option1 Only */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Command PDU header with Extended CDB (Initiator Mode)  */
end_comment

begin_struct
struct|struct
name|iscsi_ext_cdb_cmd_hdr
block|{
name|__le16
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_ATTR_MASK
value|0x7
comment|/* attributes */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_ATTR_SHIFT
value|0
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_RSRV_MASK
value|0x3
comment|/* reserved */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_RSRV_SHIFT
value|3
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_WRITE_MASK
value|0x1
comment|/* write */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_WRITE_SHIFT
value|5
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_READ_MASK
value|0x1
comment|/* read */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_READ_SHIFT
value|6
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_FINAL_MASK
value|0x1
comment|/* final */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_FINAL_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_CDB_SIZE_MASK
value|0xFF
comment|/* The Extended CDB size in bytes. Maximum Extended CDB size supported is CDB 64B. */
define|#
directive|define
name|ISCSI_EXT_CDB_CMD_HDR_CDB_SIZE_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number. [constant, initialized] */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|expected_transfer_length
comment|/* Expected Data Transfer Length (only 3 bytes are significant) */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* CmdSn. [constant, initialized] */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* various fields for middle-path PDU. [constant, initialized] */
decl_stmt|;
name|struct
name|scsi_sge
name|cdb_sge
comment|/* Extended CDBs dedicated SGE */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI login request PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_login_req_hdr
block|{
name|u8
name|version_min
comment|/* Version-min */
decl_stmt|;
name|u8
name|version_max
comment|/* Version-max */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_NSG_MASK
value|0x3
comment|/* Next Stage (NSG) */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_NSG_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_CSG_MASK
value|0x3
comment|/* Current stage (CSG) */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_CSG_SHIFT
value|2
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_RSRV_MASK
value|0x3
comment|/* reserved */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_RSRV_SHIFT
value|4
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_C_MASK
value|0x1
comment|/* C (Continue) bit */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_C_SHIFT
value|6
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_T_MASK
value|0x1
comment|/* T (Transit) bit */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_T_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|__le32
name|isid_tabc
comment|/* Session identifier high double word [constant, initialized] */
decl_stmt|;
name|__le16
name|tsih
comment|/* TSIH */
decl_stmt|;
name|__le16
name|isid_d
comment|/* Session identifier low word [constant, initialized] */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|__le16
name|cid
comment|/* Unique Connection ID within the session [constant, initialized] */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* CmdSn. [constant, initialized] */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* various fields for middle-path PDU. [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI logout request PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_logout_req_hdr
block|{
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|reason_code
comment|/* Reason Code */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved1
decl_stmt|;
name|__le32
name|reserved2
index|[
literal|2
index|]
comment|/* Reserved */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le16
name|reserved3
comment|/* Reserved */
decl_stmt|;
name|__le16
name|cid
comment|/* Unique Connection ID within the session [constant, initialized] */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* CmdSn. [constant, initialized] */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* various fields for middle-path PDU. [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|4
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Data-out PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_data_out_hdr
block|{
name|__le16
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_DATA_OUT_HDR_RSRV_MASK
value|0x7F
comment|/* reserved */
define|#
directive|define
name|ISCSI_DATA_OUT_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_DATA_OUT_HDR_FINAL_MASK
value|0x1
comment|/* final */
define|#
directive|define
name|ISCSI_DATA_OUT_HDR_FINAL_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|reserved2
comment|/* reserved */
decl_stmt|;
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant) */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Transfer Tag (from R2T) */
decl_stmt|;
name|__le32
name|reserved3
comment|/* resrved */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* Expected StatSn */
decl_stmt|;
name|__le32
name|reserved4
comment|/* resrved */
decl_stmt|;
name|__le32
name|data_sn
comment|/* DataSN - PDU index in sequnece */
decl_stmt|;
name|__le32
name|buffer_offset
comment|/* Buffer Offset - offset in task */
decl_stmt|;
name|__le32
name|reserved5
comment|/* resrved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Data-in PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_data_in_hdr
block|{
name|u8
name|status_rsvd
comment|/* Status or reserved */
decl_stmt|;
name|u8
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_DATA_IN_HDR_STATUS_MASK
value|0x1
comment|/* Status */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_STATUS_SHIFT
value|0
define|#
directive|define
name|ISCSI_DATA_IN_HDR_UNDERFLOW_MASK
value|0x1
comment|/* Residual Underflow */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_UNDERFLOW_SHIFT
value|1
define|#
directive|define
name|ISCSI_DATA_IN_HDR_OVERFLOW_MASK
value|0x1
comment|/* Residual Overflow */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_OVERFLOW_SHIFT
value|2
define|#
directive|define
name|ISCSI_DATA_IN_HDR_RSRV_MASK
value|0x7
comment|/* reserved - 0 */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_RSRV_SHIFT
value|3
define|#
directive|define
name|ISCSI_DATA_IN_HDR_ACK_MASK
value|0x1
comment|/* Acknowledge */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_ACK_SHIFT
value|6
define|#
directive|define
name|ISCSI_DATA_IN_HDR_FINAL_MASK
value|0x1
comment|/* final */
define|#
directive|define
name|ISCSI_DATA_IN_HDR_FINAL_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|reserved2
comment|/* reserved */
decl_stmt|;
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant) */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Transfer Tag (from R2T) */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* StatSN or reserved */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* Expected CmdSn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* MaxCmdSn */
decl_stmt|;
name|__le32
name|data_sn
comment|/* DataSN - PDU index in sequnece */
decl_stmt|;
name|__le32
name|buffer_offset
comment|/* Buffer Offset - offset in task */
decl_stmt|;
name|__le32
name|residual_count
comment|/* Residual Count */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI R2T PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_r2t_hdr
block|{
name|u8
name|reserved0
index|[
literal|3
index|]
comment|/* reserved */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|reserved2
comment|/* reserved */
decl_stmt|;
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Transfer Tag */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* stat sn */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* Expected CmdSn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* Max CmdSn */
decl_stmt|;
name|__le32
name|r2t_sn
comment|/* DataSN - PDU index in sequnece */
decl_stmt|;
name|__le32
name|buffer_offset
comment|/* Buffer Offset - offset in task */
decl_stmt|;
name|__le32
name|desired_data_trns_len
comment|/* Desired data trnsfer len */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI NOP-out PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_nop_out_hdr
block|{
name|__le16
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_RSRV_MASK
value|0x7F
comment|/* reserved */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_CONST1_MASK
value|0x1
comment|/* const1 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_CONST1_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|reserved2
comment|/* reserved */
decl_stmt|;
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant) */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Transfer Tag (from R2T) */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* Expected StatSn */
decl_stmt|;
name|__le32
name|reserved3
comment|/* reserved */
decl_stmt|;
name|__le32
name|reserved4
comment|/* reserved */
decl_stmt|;
name|__le32
name|reserved5
comment|/* reserved */
decl_stmt|;
name|__le32
name|reserved6
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI NOP-in PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_nop_in_hdr
block|{
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_IN_HDR_RSRV_MASK
value|0x7F
comment|/* reserved */
define|#
directive|define
name|ISCSI_NOP_IN_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_IN_HDR_CONST1_MASK
value|0x1
comment|/* const1 */
define|#
directive|define
name|ISCSI_NOP_IN_HDR_CONST1_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_IN_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_NOP_IN_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_IN_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_NOP_IN_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant) */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Transfer Tag */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* stat_sn */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* exp_cmd_sn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* max_cmd_sn */
decl_stmt|;
name|__le32
name|reserved5
comment|/* reserved */
decl_stmt|;
name|__le32
name|reserved6
comment|/* reserved */
decl_stmt|;
name|__le32
name|reserved7
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Login Response PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_login_response_hdr
block|{
name|u8
name|version_active
comment|/* Version-active */
decl_stmt|;
name|u8
name|version_max
comment|/* Version-max */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_NSG_MASK
value|0x3
comment|/* Next Stage (NSG) */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_NSG_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_CSG_MASK
value|0x3
comment|/* Current stage (CSG) */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_CSG_SHIFT
value|2
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_RSRV_MASK
value|0x3
comment|/* reserved */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_RSRV_SHIFT
value|4
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_C_MASK
value|0x1
comment|/* C (Continue) bit */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_C_SHIFT
value|6
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_T_MASK
value|0x1
comment|/* T (Transit) bit */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_T_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_LOGIN_RESPONSE_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|__le32
name|isid_tabc
comment|/* Session identifier high double word [constant, initialized] */
decl_stmt|;
name|__le16
name|tsih
comment|/* TSIH */
decl_stmt|;
name|__le16
name|isid_d
comment|/* Session identifier low word [constant, initialized] */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved1
decl_stmt|;
name|__le32
name|stat_sn
comment|/* CmdSn. [constant, initialized] */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* various fields for middle-path PDU. [constant, initialized] */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* max_cmd_sn */
decl_stmt|;
name|__le16
name|reserved2
decl_stmt|;
name|u8
name|status_detail
comment|/* status_detail */
decl_stmt|;
name|u8
name|status_class
comment|/* status_class */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Logout Response PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_logout_response_hdr
block|{
name|u8
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|response
comment|/* response */
decl_stmt|;
name|u8
name|flags
comment|/* flags and attributes */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGOUT_RESPONSE_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_LOGOUT_RESPONSE_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGOUT_RESPONSE_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_LOGOUT_RESPONSE_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|__le32
name|reserved2
index|[
literal|2
index|]
comment|/* Reserved */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved3
comment|/* Reserved */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* Expected StatSn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|reserved4
comment|/* Reserved */
decl_stmt|;
name|__le16
name|time_2_retain
comment|/* Time to Retain  */
decl_stmt|;
name|__le16
name|time_2_wait
comment|/* Time to wait */
decl_stmt|;
name|__le32
name|reserved5
index|[
literal|1
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Text Request PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_text_request_hdr
block|{
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|flags_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_RSRV_MASK
value|0x3F
comment|/* reserved */
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_C_MASK
value|0x1
comment|/* C (Continue) bit */
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_C_SHIFT
value|6
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_F_MASK
value|0x1
comment|/* F (Final) bit */
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_F_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_TEXT_REQUEST_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|ttt
comment|/* Referenced Task Tag or 0xffffffff */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* cmd_sn */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* exp_stat_sn */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|4
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Text Response PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_text_response_hdr
block|{
name|__le16
name|reserved1
comment|/* reserved */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_RSRV_MASK
value|0x3F
comment|/* reserved */
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_RSRV_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_C_MASK
value|0x1
comment|/* C (Continue) bit */
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_C_SHIFT
value|6
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_F_MASK
value|0x1
comment|/* F (Final) bit */
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_F_SHIFT
value|7
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_TEXT_RESPONSE_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|ttt
comment|/* Target Task Tag */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* Expected StatSn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|3
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI TMF Request PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_tmf_request_hdr
block|{
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|function
comment|/* function */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_TMF_REQUEST_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_TMF_REQUEST_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_TMF_REQUEST_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_TMF_REQUEST_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|rtt
comment|/* Referenced Task Tag or 0xffffffff */
decl_stmt|;
name|__le32
name|cmd_sn
comment|/* cmd_sn */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* exp_stat_sn */
decl_stmt|;
name|__le32
name|ref_cmd_sn
comment|/* ref_cmd_sn */
decl_stmt|;
name|__le32
name|exp_data_sn
comment|/* exp_data_sn */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|2
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_tmf_response_hdr
block|{
name|u8
name|reserved2
comment|/* reserved2 */
decl_stmt|;
name|u8
name|hdr_response
comment|/* Response field of ISCSI header for Responses / Reserved for Data-In */
decl_stmt|;
name|u8
name|hdr_flags
comment|/* Flags field of ISCSI header */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_TMF_RESPONSE_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_TMF_RESPONSE_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_TMF_RESPONSE_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_TMF_RESPONSE_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|reserved0
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|reserved1
comment|/* Reserved */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* stat_sn */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* exp_cmd_sn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* max_cmd_sn */
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|3
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Response PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_response_hdr
block|{
name|u8
name|hdr_status
comment|/* Status field of ISCSI header */
decl_stmt|;
name|u8
name|hdr_response
comment|/* Response field of ISCSI header for Responses / Reserved for Data-In */
decl_stmt|;
name|u8
name|hdr_flags
comment|/* Flags field of ISCSI header */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_RESPONSE_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_RESPONSE_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_RESPONSE_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_RESPONSE_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|lun
comment|/* Logical Unit Number */
decl_stmt|;
name|__le32
name|itt
comment|/* Initiator Task Tag (only 2 bytes are significant). [constant, initialized] */
decl_stmt|;
name|__le32
name|snack_tag
comment|/* Currently ERL>0 is not supported */
decl_stmt|;
name|__le32
name|stat_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* Expected StatSn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* CmdSN */
decl_stmt|;
name|__le32
name|exp_data_sn
comment|/* exp_data_sn */
decl_stmt|;
name|__le32
name|bi_residual_count
comment|/* bi residual count */
decl_stmt|;
name|__le32
name|residual_count
comment|/* residual count */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Reject PDU header  */
end_comment

begin_struct
struct|struct
name|iscsi_reject_hdr
block|{
name|u8
name|reserved4
comment|/* Reserved */
decl_stmt|;
name|u8
name|hdr_reason
comment|/* The reject reason */
decl_stmt|;
name|u8
name|hdr_flags
comment|/* Flags field of ISCSI header */
decl_stmt|;
name|u8
name|opcode
comment|/* opcode. [constant, initialized] */
decl_stmt|;
name|__le32
name|hdr_second_dword
decl_stmt|;
define|#
directive|define
name|ISCSI_REJECT_HDR_DATA_SEG_LEN_MASK
value|0xFFFFFF
comment|/* DataSegmentLength */
define|#
directive|define
name|ISCSI_REJECT_HDR_DATA_SEG_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_REJECT_HDR_TOTAL_AHS_LEN_MASK
value|0xFF
comment|/* TotalAHSLength */
define|#
directive|define
name|ISCSI_REJECT_HDR_TOTAL_AHS_LEN_SHIFT
value|24
name|struct
name|regpair
name|reserved0
decl_stmt|;
name|__le32
name|all_ones
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
name|__le32
name|stat_sn
comment|/* stat_sn */
decl_stmt|;
name|__le32
name|exp_cmd_sn
comment|/* exp_cmd_sn */
decl_stmt|;
name|__le32
name|max_cmd_sn
comment|/* max_cmd_sn */
decl_stmt|;
name|__le32
name|data_sn
comment|/* data_sn */
decl_stmt|;
name|__le32
name|reserved3
index|[
literal|2
index|]
comment|/* reserved3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header part of Ystorm task context  */
end_comment

begin_union
union|union
name|iscsi_task_hdr
block|{
name|struct
name|iscsi_common_hdr
name|common
comment|/* Command PDU header */
decl_stmt|;
name|struct
name|data_hdr
name|data
comment|/* Command PDU header */
decl_stmt|;
name|struct
name|iscsi_cmd_hdr
name|cmd
comment|/* Command PDU header */
decl_stmt|;
name|struct
name|iscsi_ext_cdb_cmd_hdr
name|ext_cdb_cmd
comment|/* Command PDU header with extended CDB - Initiator Mode */
decl_stmt|;
name|struct
name|iscsi_login_req_hdr
name|login_req
comment|/* Login request PDU header */
decl_stmt|;
name|struct
name|iscsi_logout_req_hdr
name|logout_req
comment|/* Logout request PDU header */
decl_stmt|;
name|struct
name|iscsi_data_out_hdr
name|data_out
comment|/* Data-out PDU header */
decl_stmt|;
name|struct
name|iscsi_data_in_hdr
name|data_in
comment|/* Data-in PDU header */
decl_stmt|;
name|struct
name|iscsi_r2t_hdr
name|r2t
comment|/* R2T PDU header */
decl_stmt|;
name|struct
name|iscsi_nop_out_hdr
name|nop_out
comment|/* NOP-out PDU header */
decl_stmt|;
name|struct
name|iscsi_nop_in_hdr
name|nop_in
comment|/* NOP-in PDU header */
decl_stmt|;
name|struct
name|iscsi_login_response_hdr
name|login_response
comment|/* Login response PDU header */
decl_stmt|;
name|struct
name|iscsi_logout_response_hdr
name|logout_response
comment|/* Logout response PDU header */
decl_stmt|;
name|struct
name|iscsi_text_request_hdr
name|text_request
comment|/* Text request PDU header */
decl_stmt|;
name|struct
name|iscsi_text_response_hdr
name|text_response
comment|/* Text response PDU header */
decl_stmt|;
name|struct
name|iscsi_tmf_request_hdr
name|tmf_request
comment|/* TMF request PDU header */
decl_stmt|;
name|struct
name|iscsi_tmf_response_hdr
name|tmf_response
comment|/* TMF response PDU header */
decl_stmt|;
name|struct
name|iscsi_response_hdr
name|response
comment|/* Text response PDU header */
decl_stmt|;
name|struct
name|iscsi_reject_hdr
name|reject
comment|/* Reject PDU header */
decl_stmt|;
name|struct
name|iscsi_async_msg_hdr
name|async_msg
comment|/* Asynchronous Message PDU header */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI CQ element  */
end_comment

begin_struct
struct|struct
name|iscsi_cqe_common
block|{
name|__le16
name|conn_id
comment|/* Drivers connection Id */
decl_stmt|;
name|u8
name|cqe_type
comment|/* Indicates CQE type */
decl_stmt|;
name|union
name|cqe_error_status
name|error_bitmap
comment|/* CQE error status */
decl_stmt|;
name|__le32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|union
name|iscsi_task_hdr
name|iscsi_hdr
comment|/* iscsi header union */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI CQ element  */
end_comment

begin_struct
struct|struct
name|iscsi_cqe_solicited
block|{
name|__le16
name|conn_id
comment|/* Drivers connection Id */
decl_stmt|;
name|u8
name|cqe_type
comment|/* Indicates CQE type */
decl_stmt|;
name|union
name|cqe_error_status
name|error_bitmap
comment|/* CQE error status */
decl_stmt|;
name|__le16
name|itid
comment|/* initiator itt (Initiator mode) or target ttt (Target mode) */
decl_stmt|;
name|u8
name|task_type
comment|/* Task type */
decl_stmt|;
name|u8
name|fw_dbg_field
comment|/* FW debug params */
decl_stmt|;
name|u8
name|caused_conn_err
comment|/* Equals 1 if this TID caused the connection error, otherwise equals 0. */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
name|__le32
name|reserved1
index|[
literal|1
index|]
decl_stmt|;
name|union
name|iscsi_task_hdr
name|iscsi_hdr
comment|/* iscsi header union */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI CQ element  */
end_comment

begin_struct
struct|struct
name|iscsi_cqe_unsolicited
block|{
name|__le16
name|conn_id
comment|/* Drivers connection Id */
decl_stmt|;
name|u8
name|cqe_type
comment|/* Indicates CQE type */
decl_stmt|;
name|union
name|cqe_error_status
name|error_bitmap
comment|/* CQE error status */
decl_stmt|;
name|__le16
name|reserved0
comment|/* Reserved */
decl_stmt|;
name|u8
name|reserved1
comment|/* Reserved */
decl_stmt|;
name|u8
name|unsol_cqe_type
comment|/* Represent this unsolicited CQE position in a sequence of packets belonging to the same unsolicited PDU */
decl_stmt|;
name|struct
name|regpair
name|rqe_opaque
comment|/* Relevant for Unsolicited CQE only: The opaque data of RQ BDQ */
decl_stmt|;
name|union
name|iscsi_task_hdr
name|iscsi_hdr
comment|/* iscsi header union */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI CQ element  */
end_comment

begin_union
union|union
name|iscsi_cqe
block|{
name|struct
name|iscsi_cqe_common
name|cqe_common
comment|/* Common CQE */
decl_stmt|;
name|struct
name|iscsi_cqe_solicited
name|cqe_solicited
comment|/* Solicited CQE */
decl_stmt|;
name|struct
name|iscsi_cqe_unsolicited
name|cqe_unsolicited
comment|/* Unsolicited CQE. relevant only when cqe_opcode == ISCSI_CQE_TYPE_UNSOLICITED */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI CQE type   */
end_comment

begin_enum
enum|enum
name|iscsi_cqes_type
block|{
name|ISCSI_CQE_TYPE_SOLICITED
init|=
literal|1
comment|/* iSCSI CQE with solicited data */
block|,
name|ISCSI_CQE_TYPE_UNSOLICITED
comment|/* iSCSI CQE with unsolicited data */
block|,
name|ISCSI_CQE_TYPE_SOLICITED_WITH_SENSE
comment|/* iSCSI CQE with solicited with sense data */
block|,
name|ISCSI_CQE_TYPE_TASK_CLEANUP
comment|/* iSCSI CQE task cleanup */
block|,
name|ISCSI_CQE_TYPE_DUMMY
comment|/* iSCSI Dummy CQE */
block|,
name|MAX_ISCSI_CQES_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iSCSI CQE type   */
end_comment

begin_enum
enum|enum
name|iscsi_cqe_unsolicited_type
block|{
name|ISCSI_CQE_UNSOLICITED_NONE
comment|/* iSCSI CQE with unsolicited data */
block|,
name|ISCSI_CQE_UNSOLICITED_SINGLE
comment|/* iSCSI CQE with unsolicited data */
block|,
name|ISCSI_CQE_UNSOLICITED_FIRST
comment|/* iSCSI CQE with unsolicited data */
block|,
name|ISCSI_CQE_UNSOLICITED_MIDDLE
comment|/* iSCSI CQE with unsolicited data */
block|,
name|ISCSI_CQE_UNSOLICITED_LAST
comment|/* iSCSI CQE with unsolicited data */
block|,
name|MAX_ISCSI_CQE_UNSOLICITED_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iscsi debug modes  */
end_comment

begin_struct
struct|struct
name|iscsi_debug_modes
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RX_CONN_ERROR_MASK
value|0x1
comment|/* Assert on Rx connection error */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RX_CONN_ERROR_SHIFT
value|0
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_RESET_MASK
value|0x1
comment|/* Assert if TCP RESET arrived */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_RESET_SHIFT
value|1
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_FIN_MASK
value|0x1
comment|/* Assert if TCP FIN arrived */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_FIN_SHIFT
value|2
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_CLEANUP_MASK
value|0x1
comment|/* Assert if cleanup flow */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_CLEANUP_SHIFT
value|3
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_REJECT_OR_ASYNC_MASK
value|0x1
comment|/* Assert if REJECT PDU or ASYNC PDU arrived */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_REJECT_OR_ASYNC_SHIFT
value|4
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_NOP_MASK
value|0x1
comment|/* Assert if NOP IN PDU or NOP OUT PDU arrived */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_RECV_NOP_SHIFT
value|5
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_DATA_DIGEST_ERROR_MASK
value|0x1
comment|/* Assert if data digest error */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_DATA_DIGEST_ERROR_SHIFT
value|6
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_DIF_ERROR_MASK
value|0x1
comment|/* Assert if DIF error */
define|#
directive|define
name|ISCSI_DEBUG_MODES_ASSERT_IF_DIF_ERROR_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI DIF flags   */
end_comment

begin_struct
struct|struct
name|iscsi_dif_flags
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_DIF_FLAGS_PROT_INTERVAL_SIZE_LOG_MASK
value|0xF
comment|/* Protection log interval (9=512 10=1024  11=2048 12=4096 13=8192) */
define|#
directive|define
name|ISCSI_DIF_FLAGS_PROT_INTERVAL_SIZE_LOG_SHIFT
value|0
define|#
directive|define
name|ISCSI_DIF_FLAGS_DIF_TO_PEER_MASK
value|0x1
comment|/* If DIF protection is configured against target (0=no, 1=yes) */
define|#
directive|define
name|ISCSI_DIF_FLAGS_DIF_TO_PEER_SHIFT
value|4
define|#
directive|define
name|ISCSI_DIF_FLAGS_HOST_INTERFACE_MASK
value|0x7
comment|/* If DIF/DIX protection is configured against the host (0=none, 1=DIF, 2=DIX 2 bytes, 3=DIX 4 bytes, 4=DIX 8 bytes) */
define|#
directive|define
name|ISCSI_DIF_FLAGS_HOST_INTERFACE_SHIFT
value|5
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI kernel completion queue IDs   */
end_comment

begin_enum
enum|enum
name|iscsi_eqe_opcode
block|{
name|ISCSI_EVENT_TYPE_INIT_FUNC
init|=
literal|0
comment|/* iSCSI response after init Ramrod */
block|,
name|ISCSI_EVENT_TYPE_DESTROY_FUNC
comment|/* iSCSI response after destroy Ramrod */
block|,
name|ISCSI_EVENT_TYPE_OFFLOAD_CONN
comment|/* iSCSI response after option 2 offload Ramrod */
block|,
name|ISCSI_EVENT_TYPE_UPDATE_CONN
comment|/* iSCSI response after update Ramrod */
block|,
name|ISCSI_EVENT_TYPE_CLEAR_SQ
comment|/* iSCSI response after clear sq Ramrod */
block|,
name|ISCSI_EVENT_TYPE_TERMINATE_CONN
comment|/* iSCSI response after termination Ramrod */
block|,
name|ISCSI_EVENT_TYPE_MAC_UPDATE_CONN
comment|/* iSCSI response after MAC address update Ramrod */
block|,
name|ISCSI_EVENT_TYPE_ASYN_CONNECT_COMPLETE
comment|/* iSCSI response after option 2 connect completed (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_TERMINATE_DONE
comment|/* iSCSI response after option 2 termination completed (A-syn EQE) */
block|,
name|RESERVED9
comment|/* reserved9 */
block|,
name|ISCSI_EVENT_TYPE_START_OF_ERROR_TYPES
init|=
literal|10
comment|/* Never returned in EQE, used to separate Regular event types from Error event types */
block|,
name|ISCSI_EVENT_TYPE_ASYN_ABORT_RCVD
comment|/* iSCSI abort response after TCP RST packet receive (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_CLOSE_RCVD
comment|/* iSCSI response after close receive (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_SYN_RCVD
comment|/* iSCSI response after TCP SYN+ACK packet receive (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_MAX_RT_TIME
comment|/* iSCSI error - tcp max retransmit time (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_MAX_RT_CNT
comment|/* iSCSI error - tcp max retransmit count (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_MAX_KA_PROBES_CNT
comment|/* iSCSI error - tcp ka probes count (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ASYN_FIN_WAIT2
comment|/* iSCSI error - tcp fin wait 2 (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_ISCSI_CONN_ERROR
comment|/* iSCSI error response (A-syn EQE) */
block|,
name|ISCSI_EVENT_TYPE_TCP_CONN_ERROR
comment|/* iSCSI error - tcp error (A-syn EQE) */
block|,
name|MAX_ISCSI_EQE_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iSCSI EQE and CQE completion status   */
end_comment

begin_enum
enum|enum
name|iscsi_error_types
block|{
name|ISCSI_STATUS_NONE
init|=
literal|0
block|,
name|ISCSI_CQE_ERROR_UNSOLICITED_RCV_ON_INVALID_CONN
init|=
literal|1
block|,
name|ISCSI_CONN_ERROR_TASK_CID_MISMATCH
comment|/* iSCSI connection error - Corrupted Task context  */
block|,
name|ISCSI_CONN_ERROR_TASK_NOT_VALID
comment|/* iSCSI connection error - The task is not valid  */
block|,
name|ISCSI_CONN_ERROR_RQ_RING_IS_FULL
comment|/* iSCSI connection error - RQ full  */
block|,
name|ISCSI_CONN_ERROR_CMDQ_RING_IS_FULL
comment|/* iSCSI connection error - CMDQ full (Target only)  */
block|,
name|ISCSI_CONN_ERROR_HQE_CACHING_FAILED
comment|/* iSCSI connection error - HQ error  */
block|,
name|ISCSI_CONN_ERROR_HEADER_DIGEST_ERROR
comment|/* iSCSI connection error - Header digest error */
block|,
name|ISCSI_CONN_ERROR_LOCAL_COMPLETION_ERROR
comment|/* iSCSI connection error - Local completion bit is not correct   (A-syn EQE) */
block|,
name|ISCSI_CONN_ERROR_DATA_OVERRUN
comment|/* iSCSI connection error - data overrun */
block|,
name|ISCSI_CONN_ERROR_OUT_OF_SGES_ERROR
comment|/* iSCSI connection error - out of sges in task context */
block|,
name|ISCSI_CONN_ERROR_IP_OPTIONS_ERROR
comment|/* TCP connection error - IP option error  */
block|,
name|ISCSI_CONN_ERROR_PRS_ERRORS
comment|/* TCP connection error - error indication form parser */
block|,
name|ISCSI_CONN_ERROR_CONNECT_INVALID_TCP_OPTION
comment|/* TCP connection error - tcp options error(option 2 only)  */
block|,
name|ISCSI_CONN_ERROR_TCP_IP_FRAGMENT_ERROR
comment|/* TCP connection error - IP fragmentation error  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_AHS_LEN
comment|/* iSCSI connection error - invalid AHS length (Target only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_AHS_TYPE
comment|/* iSCSI connection error - invalid AHS type (Target only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_ITT_OUT_OF_RANGE
comment|/* iSCSI connection error - invalid ITT  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_TTT_OUT_OF_RANGE
comment|/* iSCSI connection error - invalid TTT (Target only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DATA_SEG_LEN_EXCEEDS_PDU_SIZE
comment|/* iSCSI connection error - PDU data_seg_len> max receive pdu size */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_INVALID_OPCODE
comment|/* iSCSI connection error - invalid PDU opcode */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_INVALID_OPCODE_BEFORE_UPDATE
comment|/* iSCSI connection error - invalid PDU opcode before update ramrod (Option 2 only)  */
block|,
name|ISCSI_CONN_ERROR_UNVALID_NOPIN_DSL
comment|/* iSCSI connection error - NOPIN dsl> 0 and ITT = 0xffffffff (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_R2T_CARRIES_NO_DATA
comment|/* iSCSI connection error - R2T dsl> 0 (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DATA_SN
comment|/* iSCSI connection error - DATA-SN error  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DATA_IN_TTT
comment|/* iSCSI connection error - DATA-IN TTT error (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DATA_OUT_ITT
comment|/* iSCSI connection error - DATA-OUT ITT error (Target only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_R2T_TTT
comment|/* iSCSI connection error - R2T TTT error (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_R2T_BUFFER_OFFSET
comment|/* iSCSI connection error - R2T buffer offset error (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_BUFFER_OFFSET_OOO
comment|/* iSCSI connection error - DATA PDU buffer offset error  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_R2T_SN
comment|/* iSCSI connection error - R2T SN error (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DESIRED_DATA_TRNS_LEN_0
comment|/* iSCSI connection error - R2T desired data transfer length = 0 (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DESIRED_DATA_TRNS_LEN_1
comment|/* iSCSI connection error - R2T desired data transfer length less then max burst size (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DESIRED_DATA_TRNS_LEN_2
comment|/* iSCSI connection error - R2T desired data transfer length + buffer offset> task size (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_LUN
comment|/* iSCSI connection error - R2T unvalid LUN (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_F_BIT_ZERO
comment|/* iSCSI connection error - All data has been already received, however it is not the end of sequence (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_F_BIT_ZERO_S_BIT_ONE
comment|/* iSCSI connection error - S-bit and final bit = 1 (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_EXP_STAT_SN
comment|/* iSCSI connection error - STAT SN error (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DSL_NOT_ZERO
comment|/* iSCSI connection error - TMF or LOGOUT PDUs dsl> 0 (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_INVALID_DSL
comment|/* iSCSI connection error - CMD PDU dsl>0 while immediate data is disabled (Target only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DATA_SEG_LEN_TOO_BIG
comment|/* iSCSI connection error - Data In overrun (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_OUTSTANDING_R2T_COUNT
comment|/* iSCSI connection error ->1 outstanding R2T (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_PROTOCOL_ERR_DIF_TX
comment|/* iSCSI connection error - DIF Tx error + DIF error drop is enabled (Target only)  */
block|,
name|ISCSI_CONN_ERROR_SENSE_DATA_LENGTH
comment|/* iSCSI connection error - Sense data length> 256 (Initiator only)  */
block|,
name|ISCSI_CONN_ERROR_DATA_PLACEMENT_ERROR
comment|/* iSCSI connection error - Data placement error  */
block|,
name|ISCSI_CONN_ERROR_INVALID_ITT
comment|/* iSCSI connection error - Invalid ITT (Target Only) */
block|,
name|ISCSI_ERROR_UNKNOWN
comment|/* iSCSI connection error  */
block|,
name|MAX_ISCSI_ERROR_TYPES
block|}
enum|;
end_enum

begin_comment
comment|/*  * iSCSI Ramrod Command IDs   */
end_comment

begin_enum
enum|enum
name|iscsi_ramrod_cmd_id
block|{
name|ISCSI_RAMROD_CMD_ID_UNUSED
init|=
literal|0
block|,
name|ISCSI_RAMROD_CMD_ID_INIT_FUNC
init|=
literal|1
comment|/* iSCSI function init Ramrod */
block|,
name|ISCSI_RAMROD_CMD_ID_DESTROY_FUNC
init|=
literal|2
comment|/* iSCSI function destroy Ramrod */
block|,
name|ISCSI_RAMROD_CMD_ID_OFFLOAD_CONN
init|=
literal|3
comment|/* iSCSI connection offload Ramrod */
block|,
name|ISCSI_RAMROD_CMD_ID_UPDATE_CONN
init|=
literal|4
comment|/* iSCSI connection update Ramrod  */
block|,
name|ISCSI_RAMROD_CMD_ID_TERMINATION_CONN
init|=
literal|5
comment|/* iSCSI connection offload Ramrod. Command ID known only to FW and VBD */
block|,
name|ISCSI_RAMROD_CMD_ID_CLEAR_SQ
init|=
literal|6
comment|/* iSCSI connection clear-sq ramrod.  */
block|,
name|ISCSI_RAMROD_CMD_ID_MAC_UPDATE
init|=
literal|7
comment|/* iSCSI connection update MAC address ramrod.  */
block|,
name|MAX_ISCSI_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_struct
struct|struct
name|iscsi_reg1
block|{
name|__le32
name|reg1_map
decl_stmt|;
define|#
directive|define
name|ISCSI_REG1_NUM_SGES_MASK
value|0xF
comment|/* Written to R2tQE */
define|#
directive|define
name|ISCSI_REG1_NUM_SGES_SHIFT
value|0
define|#
directive|define
name|ISCSI_REG1_RESERVED1_MASK
value|0xFFFFFFF
comment|/* reserved */
define|#
directive|define
name|ISCSI_REG1_RESERVED1_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * Union of data/r2t sequence number  */
end_comment

begin_union
union|union
name|iscsi_seq_num
block|{
name|__le16
name|data_sn
comment|/* data-in sequence number */
decl_stmt|;
name|__le16
name|r2t_sn
comment|/* r2t pdu sequence number */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * ISCSI connection termination request  */
end_comment

begin_struct
struct|struct
name|iscsi_spe_conn_mac_update
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|conn_id
comment|/* ISCSI Connection ID. */
decl_stmt|;
name|__le32
name|fw_cid
comment|/* Context ID (cid) of the connection. */
decl_stmt|;
name|__le16
name|remote_mac_addr_lo
comment|/* new remote mac address lo */
decl_stmt|;
name|__le16
name|remote_mac_addr_mid
comment|/* new remote mac address mid */
decl_stmt|;
name|__le16
name|remote_mac_addr_hi
comment|/* new remote mac address hi */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISCSI and TCP connection(Option 1) offload params passed by driver to FW in ISCSI offload ramrod   */
end_comment

begin_struct
struct|struct
name|iscsi_spe_conn_offload
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|conn_id
comment|/* ISCSI Connection ID. */
decl_stmt|;
name|__le32
name|fw_cid
decl_stmt|;
name|struct
name|iscsi_conn_offload_params
name|iscsi
comment|/* iSCSI session offload params */
decl_stmt|;
name|struct
name|tcp_offload_params
name|tcp
comment|/* iSCSI session offload params */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISCSI and TCP connection(Option 2) offload params passed by driver to FW in ISCSI offload ramrod   */
end_comment

begin_struct
struct|struct
name|iscsi_spe_conn_offload_option2
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|conn_id
comment|/* ISCSI Connection ID. */
decl_stmt|;
name|__le32
name|fw_cid
decl_stmt|;
name|struct
name|iscsi_conn_offload_params
name|iscsi
comment|/* iSCSI session offload params */
decl_stmt|;
name|struct
name|tcp_offload_params_opt2
name|tcp
comment|/* iSCSI session offload params */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ISCSI connection termination request  */
end_comment

begin_struct
struct|struct
name|iscsi_spe_conn_termination
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|conn_id
comment|/* ISCSI Connection ID. */
decl_stmt|;
name|__le32
name|fw_cid
comment|/* Context ID (cid) of the connection. */
decl_stmt|;
name|u8
name|abortive
comment|/* Mark termination as abort(reset) flow */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|7
index|]
decl_stmt|;
name|struct
name|regpair
name|queue_cnts_addr
comment|/* cmdq and unsolicited counters termination params */
decl_stmt|;
name|struct
name|regpair
name|query_params_addr
comment|/* query_params_ptr */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI firmware function destroy parameters   */
end_comment

begin_struct
struct|struct
name|iscsi_spe_func_dstry
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|reserved0
decl_stmt|;
name|__le32
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI firmware function init parameters   */
end_comment

begin_struct
struct|struct
name|iscsi_spe_func_init
block|{
name|struct
name|iscsi_slow_path_hdr
name|hdr
comment|/* spe message header. */
decl_stmt|;
name|__le16
name|half_way_close_timeout
comment|/* Half Way Close Timeout in Option 2 Close */
decl_stmt|;
name|u8
name|num_sq_pages_in_ring
comment|/* Number of entries in the SQ PBL. Provided by driver at function init spe */
decl_stmt|;
name|u8
name|num_r2tq_pages_in_ring
comment|/* Number of entries in the R2TQ PBL. Provided by driver at function init spe */
decl_stmt|;
name|u8
name|num_uhq_pages_in_ring
comment|/* Number of entries in the uHQ PBL (xHQ entries is X2). Provided by driver at function init spe */
decl_stmt|;
name|u8
name|ll2_rx_queue_id
comment|/* Queue ID of the Light-L2 Rx Queue */
decl_stmt|;
name|u8
name|ooo_enable
comment|/* Enable Out Of Order mode (enable = 1) */
decl_stmt|;
name|struct
name|iscsi_debug_modes
name|debug_mode
comment|/* Use iscsi_debug_mode flags */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
name|__le32
name|reserved3
decl_stmt|;
name|__le32
name|reserved4
decl_stmt|;
name|struct
name|scsi_init_func_params
name|func_params
comment|/* Common SCSI init params passed by driver to FW in function init ramrod */
decl_stmt|;
name|struct
name|scsi_init_func_queues
name|q_params
comment|/* SCSI RQ/CQ firmware function init parameters */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm task context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_iscsi_task_state
block|{
name|struct
name|scsi_cached_sges
name|data_desc
decl_stmt|;
name|struct
name|scsi_sgl_params
name|sgl_params
decl_stmt|;
name|__le32
name|exp_r2t_sn
comment|/* Initiator mode - Expected R2T PDU index in sequence. [variable, initialized 0] */
decl_stmt|;
name|__le32
name|buffer_offset
comment|/* Payload data offset */
decl_stmt|;
name|union
name|iscsi_seq_num
name|seq_num
comment|/* PDU index in sequence */
decl_stmt|;
name|struct
name|iscsi_dif_flags
name|dif_flags
comment|/* Dif flags */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_LOCAL_COMP_MASK
value|0x1
comment|/* local_completion  */
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_LOCAL_COMP_SHIFT
value|0
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_SLOW_IO_MASK
value|0x1
comment|/* Equals 1 if SGL is predicted and 0 otherwise. */
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_SLOW_IO_SHIFT
value|1
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_RESERVED0_MASK
value|0x3F
define|#
directive|define
name|YSTORM_ISCSI_TASK_STATE_RESERVED0_SHIFT
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm task context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_iscsi_task_rxmit_opt
block|{
name|__le32
name|fast_rxmit_sge_offset
comment|/* SGE offset from which to continue dummy-read or start fast retransmit */
decl_stmt|;
name|__le32
name|scan_start_buffer_offset
comment|/* Starting buffer offset of next retransmit SGL scan */
decl_stmt|;
name|__le32
name|fast_rxmit_buffer_offset
comment|/* Buffer offset from which to continue dummy-read or start fast retransmit */
decl_stmt|;
name|u8
name|scan_start_sgl_index
comment|/* Starting SGL index of next retransmit SGL scan */
decl_stmt|;
name|u8
name|fast_rxmit_sgl_index
comment|/* SGL index from which to continue dummy-read or start fast retransmit */
decl_stmt|;
name|__le16
name|reserved
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm task context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_iscsi_task_st_ctx
block|{
name|struct
name|ystorm_iscsi_task_state
name|state
comment|/* iSCSI task parameters and state */
decl_stmt|;
name|struct
name|ystorm_iscsi_task_rxmit_opt
name|rxmit_opt
comment|/* iSCSI retransmit optimizations parameters */
decl_stmt|;
name|union
name|iscsi_task_hdr
name|pdu_hdr
comment|/* PDU header - [constant initialized] */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_iscsi_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_YSTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le32
name|TTT
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_iscsi_task_ag_ctx
block|{
name|u8
name|cdu_validation
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|task_cid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_FLAG_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_FLAG_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_MSTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_iscsi_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RESERVED1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DISABLE_DATA_ACKED_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DISABLE_DATA_ACKED_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CMP_DATA_TOTAL_EXP_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CMP_DATA_TOTAL_EXP_EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CMP_CONT_RCV_EXP_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_CMP_CONT_RCV_EXP_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* nibble1 */
define|#
directive|define
name|E4_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
value|4
name|__le32
name|dif_err_intervals
comment|/* reg0 */
decl_stmt|;
name|__le32
name|dif_error_1st_interval
comment|/* reg1 */
decl_stmt|;
name|__le32
name|rcv_cont_len
comment|/* reg2 */
decl_stmt|;
name|__le32
name|exp_cont_len
comment|/* reg3 */
decl_stmt|;
name|__le32
name|total_data_acked
comment|/* reg4 */
decl_stmt|;
name|__le32
name|exp_data_acked
comment|/* reg5 */
decl_stmt|;
name|u8
name|next_tid_valid
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|next_tid
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le32
name|hdr_residual_count
comment|/* reg6 */
decl_stmt|;
name|__le32
name|exp_r2t_sn
comment|/* reg7 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm task context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_iscsi_task_st_ctx
block|{
name|struct
name|scsi_cached_sges
name|data_desc
comment|/* Union of Data SGL / cached sge */
decl_stmt|;
name|struct
name|scsi_sgl_params
name|sgl_params
decl_stmt|;
name|__le32
name|rem_task_size
comment|/* Remaining task size, used for placement verification */
decl_stmt|;
name|__le32
name|data_buffer_offset
comment|/* Buffer offset */
decl_stmt|;
name|u8
name|task_type
comment|/* Task type, (use: iscsi_task_type enum) */
decl_stmt|;
name|struct
name|iscsi_dif_flags
name|dif_flags
comment|/* sizes of host/peer protection intervals + protection log interval */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|2
index|]
comment|/* reserved0 */
decl_stmt|;
name|struct
name|regpair
name|sense_db
comment|/* Pointer to sense data buffer */
decl_stmt|;
name|__le32
name|expected_itt
comment|/* ITT - for target mode validations */
decl_stmt|;
name|__le32
name|reserved1
comment|/* reserved1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm task context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_task_st_ctx
block|{
name|__le32
name|rem_rcv_len
comment|/* Remaining data to be received in bytes. Used in validations */
decl_stmt|;
name|__le32
name|exp_data_transfer_len
comment|/* iSCSI Initiator - The size of the transmitted task, iSCSI Target - the size of the Rx continuation */
decl_stmt|;
name|__le32
name|exp_data_sn
comment|/* Expected data SN */
decl_stmt|;
name|struct
name|regpair
name|lun
comment|/* LUN */
decl_stmt|;
name|struct
name|iscsi_reg1
name|reg1
decl_stmt|;
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_AHS_EXIST_MASK
value|0x1
comment|/* Initiator Mode - Mark AHS exist */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_AHS_EXIST_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED1_MASK
value|0x7F
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED1_SHIFT
value|1
name|struct
name|iscsi_dif_flags
name|dif_flags
comment|/* Dif flags (written to R2T WQE) */
decl_stmt|;
name|__le16
name|reserved3
decl_stmt|;
name|__le32
name|reserved4
decl_stmt|;
name|__le32
name|reserved5
decl_stmt|;
name|__le32
name|reserved6
decl_stmt|;
name|__le32
name|reserved7
decl_stmt|;
name|u8
name|task_type
comment|/* Task Type */
decl_stmt|;
name|u8
name|error_flags
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_DATA_DIGEST_ERROR_MASK
value|0x1
comment|/* Mark task with data digest error (1 bit) */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_DATA_DIGEST_ERROR_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_DATA_TRUNCATED_ERROR_MASK
value|0x1
comment|/* Target Mode - Mark middle task error, data truncated */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_DATA_TRUNCATED_ERROR_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_UNDER_RUN_ERROR_MASK
value|0x1
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_UNDER_RUN_ERROR_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED8_MASK
value|0x1F
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED8_SHIFT
value|3
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_CQE_WRITE_MASK
value|0x3
comment|/* mark task cqe write (for cleanup flow) */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_CQE_WRITE_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_LOCAL_COMP_MASK
value|0x1
comment|/* local completion bit */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_LOCAL_COMP_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_Q0_R2TQE_WRITE_MASK
value|0x1
comment|/* write R2TQE from Q0 flow */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_Q0_R2TQE_WRITE_SHIFT
value|3
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_TOTAL_DATA_ACKED_DONE_MASK
value|0x1
comment|/* Mark total data acked or disabled */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_TOTAL_DATA_ACKED_DONE_SHIFT
value|4
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_HQ_SCANNED_DONE_MASK
value|0x1
comment|/* Mark HQ scanned or disabled */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_HQ_SCANNED_DONE_SHIFT
value|5
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_R2T2RECV_DONE_MASK
value|0x1
comment|/* Mark HQ scanned or disabled */
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_R2T2RECV_DONE_SHIFT
value|6
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED0_MASK
value|0x1
define|#
directive|define
name|USTORM_ISCSI_TASK_ST_CTX_RESERVED0_SHIFT
value|7
name|u8
name|cq_rss_number
comment|/* Task CQ_RSS number 0.63 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iscsi task context  */
end_comment

begin_struct
struct|struct
name|iscsi_task_context
block|{
name|struct
name|ystorm_iscsi_task_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|e4_ystorm_iscsi_task_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|ystorm_ag_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|tdif_task_context
name|tdif_context
comment|/* tdif context */
decl_stmt|;
name|struct
name|e4_mstorm_iscsi_task_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|mstorm_ag_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e4_ustorm_iscsi_task_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_iscsi_task_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_iscsi_task_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|rdif_task_context
name|rdif_context
comment|/* rdif context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI task type  */
end_comment

begin_enum
enum|enum
name|iscsi_task_type
block|{
name|ISCSI_TASK_TYPE_INITIATOR_WRITE
block|,
name|ISCSI_TASK_TYPE_INITIATOR_READ
block|,
name|ISCSI_TASK_TYPE_MIDPATH
block|,
name|ISCSI_TASK_TYPE_UNSOLIC
block|,
name|ISCSI_TASK_TYPE_EXCHCLEANUP
block|,
name|ISCSI_TASK_TYPE_IRRELEVANT
block|,
name|ISCSI_TASK_TYPE_TARGET_WRITE
block|,
name|ISCSI_TASK_TYPE_TARGET_READ
block|,
name|ISCSI_TASK_TYPE_TARGET_RESPONSE
block|,
name|ISCSI_TASK_TYPE_LOGIN_RESPONSE
block|,
name|MAX_ISCSI_TASK_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iSCSI DesiredDataTransferLength/ttt union  */
end_comment

begin_union
union|union
name|iscsi_ttt_txlen_union
block|{
name|__le32
name|desired_tx_len
comment|/* desired data transfer length */
decl_stmt|;
name|__le32
name|ttt
comment|/* target transfer tag */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI uHQ element  */
end_comment

begin_struct
struct|struct
name|iscsi_uhqe
block|{
name|__le32
name|reg1
decl_stmt|;
define|#
directive|define
name|ISCSI_UHQE_PDU_PAYLOAD_LEN_MASK
value|0xFFFFF
comment|/* iSCSI payload (doesnt include padding or digest) or AHS length */
define|#
directive|define
name|ISCSI_UHQE_PDU_PAYLOAD_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_UHQE_LOCAL_COMP_MASK
value|0x1
comment|/* local compleiton flag */
define|#
directive|define
name|ISCSI_UHQE_LOCAL_COMP_SHIFT
value|20
define|#
directive|define
name|ISCSI_UHQE_TOGGLE_BIT_MASK
value|0x1
comment|/* toggle bit to protect from uHQ full */
define|#
directive|define
name|ISCSI_UHQE_TOGGLE_BIT_SHIFT
value|21
define|#
directive|define
name|ISCSI_UHQE_PURE_PAYLOAD_MASK
value|0x1
comment|/* indicates whether pdu_payload_len contains pure payload length. if not, pdu_payload_len is AHS length */
define|#
directive|define
name|ISCSI_UHQE_PURE_PAYLOAD_SHIFT
value|22
define|#
directive|define
name|ISCSI_UHQE_LOGIN_RESPONSE_PDU_MASK
value|0x1
comment|/* indicates login pdu */
define|#
directive|define
name|ISCSI_UHQE_LOGIN_RESPONSE_PDU_SHIFT
value|23
define|#
directive|define
name|ISCSI_UHQE_TASK_ID_HI_MASK
value|0xFF
comment|/* most significant byte of task_id */
define|#
directive|define
name|ISCSI_UHQE_TASK_ID_HI_SHIFT
value|24
name|__le32
name|reg2
decl_stmt|;
define|#
directive|define
name|ISCSI_UHQE_BUFFER_OFFSET_MASK
value|0xFFFFFF
comment|/* absolute offset in task */
define|#
directive|define
name|ISCSI_UHQE_BUFFER_OFFSET_SHIFT
value|0
define|#
directive|define
name|ISCSI_UHQE_TASK_ID_LO_MASK
value|0xFF
comment|/* least significant byte of task_id */
define|#
directive|define
name|ISCSI_UHQE_TASK_ID_LO_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI WQ element   */
end_comment

begin_struct
struct|struct
name|iscsi_wqe
block|{
name|__le16
name|task_id
comment|/* The task identifier (itt) includes all the relevant information required for the task processing */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_WQE_WQE_TYPE_MASK
value|0x7
comment|/* Wqe type [use iscsi_wqe_type] */
define|#
directive|define
name|ISCSI_WQE_WQE_TYPE_SHIFT
value|0
define|#
directive|define
name|ISCSI_WQE_NUM_SGES_MASK
value|0xF
comment|/* The driver will give a hint about sizes of SGEs for better credits evaluation at Xstorm */
define|#
directive|define
name|ISCSI_WQE_NUM_SGES_SHIFT
value|3
define|#
directive|define
name|ISCSI_WQE_RESPONSE_MASK
value|0x1
comment|/* 1 if this Wqe triggers a response and advances stat_sn, 0 otherwise */
define|#
directive|define
name|ISCSI_WQE_RESPONSE_SHIFT
value|7
name|struct
name|iscsi_dif_flags
name|prot_flags
comment|/* Task data-integrity flags (protection) */
decl_stmt|;
name|__le32
name|contlen_cdbsize
decl_stmt|;
define|#
directive|define
name|ISCSI_WQE_CONT_LEN_MASK
value|0xFFFFFF
comment|/* expected/desired data transfer length */
define|#
directive|define
name|ISCSI_WQE_CONT_LEN_SHIFT
value|0
define|#
directive|define
name|ISCSI_WQE_CDB_SIZE_MASK
value|0xFF
comment|/* Initiator mode only: equals SCSI command CDB size if extended CDB is used, otherwise equals zero.  */
define|#
directive|define
name|ISCSI_WQE_CDB_SIZE_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI wqe type   */
end_comment

begin_enum
enum|enum
name|iscsi_wqe_type
block|{
name|ISCSI_WQE_TYPE_NORMAL
comment|/* iSCSI WQE type normal. excluding status bit in target mode. */
block|,
name|ISCSI_WQE_TYPE_TASK_CLEANUP
comment|/* iSCSI WQE type task cleanup */
block|,
name|ISCSI_WQE_TYPE_MIDDLE_PATH
comment|/* iSCSI WQE type middle path */
block|,
name|ISCSI_WQE_TYPE_LOGIN
comment|/* iSCSI WQE type login */
block|,
name|ISCSI_WQE_TYPE_FIRST_R2T_CONT
comment|/* iSCSI WQE type First Write Continuation (Target) */
block|,
name|ISCSI_WQE_TYPE_NONFIRST_R2T_CONT
comment|/* iSCSI WQE type Non-First Write Continuation (Target) */
block|,
name|ISCSI_WQE_TYPE_RESPONSE
comment|/* iSCSI WQE type SCSI response */
block|,
name|MAX_ISCSI_WQE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iSCSI xHQ element  */
end_comment

begin_struct
struct|struct
name|iscsi_xhqe
block|{
name|union
name|iscsi_ttt_txlen_union
name|ttt_or_txlen
comment|/* iSCSI DesiredDataTransferLength/ttt union */
decl_stmt|;
name|__le32
name|exp_stat_sn
comment|/* expected StatSn */
decl_stmt|;
name|struct
name|iscsi_dif_flags
name|prot_flags
comment|/* Task data-integrity flags (protection) */
decl_stmt|;
name|u8
name|total_ahs_length
comment|/* Initiator mode only: Total AHS Length. greater than zero if and only if PDU is SCSI command and CDB> 16 */
decl_stmt|;
name|u8
name|opcode
comment|/* Type opcode for command PDU */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_XHQE_FINAL_MASK
value|0x1
comment|/* The Final(F) for this PDU */
define|#
directive|define
name|ISCSI_XHQE_FINAL_SHIFT
value|0
define|#
directive|define
name|ISCSI_XHQE_STATUS_BIT_MASK
value|0x1
comment|/* Whether this PDU is Data-In PDU with status_bit = 1 */
define|#
directive|define
name|ISCSI_XHQE_STATUS_BIT_SHIFT
value|1
define|#
directive|define
name|ISCSI_XHQE_NUM_SGES_MASK
value|0xF
comment|/* If Predicted IO equals Min(8, number of SGEs in SGL), otherwise equals 0 */
define|#
directive|define
name|ISCSI_XHQE_NUM_SGES_SHIFT
value|2
define|#
directive|define
name|ISCSI_XHQE_RESERVED0_MASK
value|0x3
comment|/* reserved */
define|#
directive|define
name|ISCSI_XHQE_RESERVED0_SHIFT
value|6
name|union
name|iscsi_seq_num
name|seq_num
comment|/* R2T/DataSN sequence number */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI receive path statistics - mStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|mstorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_rx_dropped_PDUs_task_not_valid
comment|/* Number of Rx silently dropped PDUs due to task not valid */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI transmit path statistics - pStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|pstorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_tx_bytes_cnt
comment|/* Counts the number of tx bytes that were transmitted */
decl_stmt|;
name|struct
name|regpair
name|iscsi_tx_packet_cnt
comment|/* Counts the number of tx packets that were transmitted */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI receive path statistics - tStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_rx_bytes_cnt
comment|/* Counts the number of rx bytes that were received */
decl_stmt|;
name|struct
name|regpair
name|iscsi_rx_packet_cnt
comment|/* Counts the number of rx packets that were received */
decl_stmt|;
name|struct
name|regpair
name|iscsi_rx_new_ooo_isle_events_cnt
comment|/* Counts the number of new out-of-order isle event */
decl_stmt|;
name|__le32
name|iscsi_cmdq_threshold_cnt
comment|/* Counts the number of times elements in cmdQ reached threshold */
decl_stmt|;
name|__le32
name|iscsi_rq_threshold_cnt
comment|/* Counts the number of times elements in RQQ reached threshold */
decl_stmt|;
name|__le32
name|iscsi_immq_threshold_cnt
comment|/* Counts the number of times elements in immQ reached threshold */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI receive path statistics - uStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_rx_data_pdu_cnt
comment|/* Number of data PDUs that were received */
decl_stmt|;
name|struct
name|regpair
name|iscsi_rx_r2t_pdu_cnt
comment|/* Number of R2T PDUs that were received */
decl_stmt|;
name|struct
name|regpair
name|iscsi_rx_total_pdu_cnt
comment|/* Number of total PDUs that were received */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI transmit path statistics - xStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_tx_go_to_slow_start_event_cnt
comment|/* Number of times slow start event occurred */
decl_stmt|;
name|struct
name|regpair
name|iscsi_tx_fast_retransmit_event_cnt
comment|/* Number of times fast retransmit event occurred */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF iSCSI transmit path statistics - yStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|ystorm_iscsi_stats_drv
block|{
name|struct
name|regpair
name|iscsi_tx_data_pdu_cnt
comment|/* Number of data PDUs that were transmitted */
decl_stmt|;
name|struct
name|regpair
name|iscsi_tx_r2t_pdu_cnt
comment|/* Number of R2T PDUs that were transmitted */
decl_stmt|;
name|struct
name|regpair
name|iscsi_tx_total_pdu_cnt
comment|/* Number of total PDUs that were transmitted */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_iscsi_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF7_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF0EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF3EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF4EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF5EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF6EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_CF7EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_iscsi_task_ag_ctx
block|{
name|u8
name|cdu_validation
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|task_cid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_FLAG_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_FLAG_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_TASK_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_MSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_tstorm_iscsi_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF7_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF0EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF3EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF4EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF5EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF6EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_CF7EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* regpair0 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg1
comment|/* regpair1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_iscsi_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RESERVED1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* dif_error_cf */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_HQ_SCANNED_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DISABLE_DATA_ACKED_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DISABLE_DATA_ACKED_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_R2T2RECV_EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CMP_DATA_TOTAL_EXP_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CMP_DATA_TOTAL_EXP_EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CMP_CONT_RCV_EXP_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_CMP_CONT_RCV_EXP_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_E4_RESERVED7_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* dif_error_type */
define|#
directive|define
name|E5_USTORM_ISCSI_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
value|4
name|u8
name|next_tid_valid
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|e4_reserved8
comment|/* byte4 */
decl_stmt|;
name|__le32
name|dif_err_intervals
comment|/* dif_err_intervals */
decl_stmt|;
name|__le32
name|dif_error_1st_interval
comment|/* dif_error_1st_interval */
decl_stmt|;
name|__le32
name|rcv_cont_len
comment|/* reg2 */
decl_stmt|;
name|__le32
name|exp_cont_len
comment|/* reg3 */
decl_stmt|;
name|__le32
name|total_data_acked
comment|/* reg4 */
decl_stmt|;
name|__le32
name|exp_data_acked
comment|/* reg5 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|next_tid
comment|/* word2 */
decl_stmt|;
name|__le32
name|hdr_residual_count
comment|/* reg6 */
decl_stmt|;
name|__le32
name|exp_r2t_sn
comment|/* reg7 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_iscsi_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_YSTORM_ISCSI_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|TTT
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI doorbell data  */
end_comment

begin_struct
struct|struct
name|iscsi_db_data
block|{
name|u8
name|params
decl_stmt|;
define|#
directive|define
name|ISCSI_DB_DATA_DEST_MASK
value|0x3
comment|/* destination of doorbell (use enum db_dest) */
define|#
directive|define
name|ISCSI_DB_DATA_DEST_SHIFT
value|0
define|#
directive|define
name|ISCSI_DB_DATA_AGG_CMD_MASK
value|0x3
comment|/* aggregative command to CM (use enum db_agg_cmd_sel) */
define|#
directive|define
name|ISCSI_DB_DATA_AGG_CMD_SHIFT
value|2
define|#
directive|define
name|ISCSI_DB_DATA_BYPASS_EN_MASK
value|0x1
comment|/* enable QM bypass */
define|#
directive|define
name|ISCSI_DB_DATA_BYPASS_EN_SHIFT
value|4
define|#
directive|define
name|ISCSI_DB_DATA_RESERVED_MASK
value|0x1
define|#
directive|define
name|ISCSI_DB_DATA_RESERVED_SHIFT
value|5
define|#
directive|define
name|ISCSI_DB_DATA_AGG_VAL_SEL_MASK
value|0x3
comment|/* aggregative value selection */
define|#
directive|define
name|ISCSI_DB_DATA_AGG_VAL_SEL_SHIFT
value|6
name|u8
name|agg_flags
comment|/* bit for every DQ counter flags in CM context that DQ can increment */
decl_stmt|;
name|__le16
name|sq_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISCSI_COMMON__ */
end_comment

end_unit

