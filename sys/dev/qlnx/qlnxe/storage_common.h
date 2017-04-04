begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STORAGE_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__STORAGE_COMMON__
end_define

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* SCSI CONSTANTS */
end_comment

begin_comment
comment|/*********************/
end_comment

begin_define
define|#
directive|define
name|NUM_OF_CMDQS_CQS
value|(NUM_OF_GLOBAL_QUEUES / 2)
end_define

begin_comment
comment|// Each Resource ID is one-one-valued mapped by the driver to a BDQ Resource ID (for instance per port)
end_comment

begin_define
define|#
directive|define
name|BDQ_NUM_RESOURCES
value|(4)
end_define

begin_comment
comment|// ID 0 : RQ, ID 1 : IMMEDIATE_DATA:
end_comment

begin_define
define|#
directive|define
name|BDQ_ID_RQ
value|(0)
end_define

begin_define
define|#
directive|define
name|BDQ_ID_IMM_DATA
value|(1)
end_define

begin_define
define|#
directive|define
name|BDQ_NUM_IDS
value|(2)
end_define

begin_define
define|#
directive|define
name|SCSI_NUM_SGES_SLOW_SGL_THR
value|8
end_define

begin_define
define|#
directive|define
name|BDQ_MAX_EXTERNAL_RING_SIZE
value|(1<<15)
end_define

begin_comment
comment|/*  * SCSI buffer descriptor  */
end_comment

begin_struct
struct|struct
name|scsi_bd
block|{
name|struct
name|regpair
name|address
comment|/* Physical Address of buffer */
decl_stmt|;
name|struct
name|regpair
name|opaque
comment|/* Driver Metadata (preferably Virtual Address of buffer) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scsi Drv BDQ struct  */
end_comment

begin_struct
struct|struct
name|scsi_bdq_ram_drv_data
block|{
name|__le16
name|external_producer
comment|/* BDQ External Producer; updated by driver when it loads BDs to External Ring */
decl_stmt|;
name|__le16
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI SGE entry  */
end_comment

begin_struct
struct|struct
name|scsi_sge
block|{
name|struct
name|regpair
name|sge_addr
comment|/* SGE address */
decl_stmt|;
name|__le32
name|sge_len
comment|/* SGE length */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cached SGEs section  */
end_comment

begin_struct
struct|struct
name|scsi_cached_sges
block|{
name|struct
name|scsi_sge
name|sge
index|[
literal|4
index|]
comment|/* Cached SGEs section */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scsi Drv CMDQ struct  */
end_comment

begin_struct
struct|struct
name|scsi_drv_cmdq
block|{
name|__le16
name|cmdq_cons
comment|/* CMDQ consumer - updated by driver when CMDQ is consumed */
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
comment|/*  * Common SCSI init params passed by driver to FW in function init ramrod   */
end_comment

begin_struct
struct|struct
name|scsi_init_func_params
block|{
name|__le16
name|num_tasks
comment|/* Number of tasks in global task list */
decl_stmt|;
name|u8
name|log_page_size
comment|/* log of page size value */
decl_stmt|;
name|u8
name|debug_mode
comment|/* Use iscsi_debug_mode enum */
decl_stmt|;
name|u8
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI RQ/CQ/CMDQ firmware function init parameters  */
end_comment

begin_struct
struct|struct
name|scsi_init_func_queues
block|{
name|struct
name|regpair
name|glbl_q_params_addr
comment|/* Global Qs (CQ/RQ/CMDQ) params host address */
decl_stmt|;
name|__le16
name|rq_buffer_size
comment|/* The buffer size of RQ BDQ */
decl_stmt|;
name|__le16
name|cq_num_entries
comment|/* CQ num entries */
decl_stmt|;
name|__le16
name|cmdq_num_entries
comment|/* CMDQ num entries */
decl_stmt|;
name|u8
name|bdq_resource_id
comment|/* Each function-init Ramrod maps its funciton ID to a BDQ function ID, each BDQ function ID contains per-BDQ-ID BDQs */
decl_stmt|;
name|u8
name|q_validity
decl_stmt|;
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_RQ_VALID_MASK
value|0x1
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_RQ_VALID_SHIFT
value|0
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_IMM_DATA_VALID_MASK
value|0x1
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_IMM_DATA_VALID_SHIFT
value|1
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_CMD_VALID_MASK
value|0x1
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_CMD_VALID_SHIFT
value|2
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_RESERVED_VALID_MASK
value|0x1F
define|#
directive|define
name|SCSI_INIT_FUNC_QUEUES_RESERVED_VALID_SHIFT
value|3
name|u8
name|num_queues
comment|/* Number of continuous global queues used */
decl_stmt|;
name|u8
name|queue_relative_offset
comment|/* offset of continuous global queues used */
decl_stmt|;
name|u8
name|cq_sb_pi
comment|/* Protocol Index of CQ in status block (CQ consumer) */
decl_stmt|;
name|u8
name|cmdq_sb_pi
comment|/* Protocol Index of CMDQ in status block (CMDQ consumer) */
decl_stmt|;
name|__le16
name|cq_cmdq_sb_num_arr
index|[
name|NUM_OF_CMDQS_CQS
index|]
comment|/* CQ/CMDQ status block number array */
decl_stmt|;
name|__le16
name|reserved0
comment|/* reserved */
decl_stmt|;
name|u8
name|bdq_pbl_num_entries
index|[
name|BDQ_NUM_IDS
index|]
comment|/* Per BDQ ID, the PBL page size (number of entries in PBL) */
decl_stmt|;
name|struct
name|regpair
name|bdq_pbl_base_address
index|[
name|BDQ_NUM_IDS
index|]
comment|/* Per BDQ ID, the PBL page Base Address */
decl_stmt|;
name|__le16
name|bdq_xoff_threshold
index|[
name|BDQ_NUM_IDS
index|]
comment|/* BDQ XOFF threshold - when number of entries will be below that TH, it will send XOFF */
decl_stmt|;
name|__le16
name|bdq_xon_threshold
index|[
name|BDQ_NUM_IDS
index|]
comment|/* BDQ XON threshold - when number of entries will be above that TH, it will send XON */
decl_stmt|;
name|__le16
name|cmdq_xoff_threshold
comment|/* CMDQ XOFF threshold - when number of entries will be below that TH, it will send XOFF */
decl_stmt|;
name|__le16
name|cmdq_xon_threshold
comment|/* CMDQ XON threshold - when number of entries will be above that TH, it will send XON */
decl_stmt|;
name|__le32
name|reserved1
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scsi Drv BDQ Data struct (2 BDQ IDs: 0 - RQ, 1 - Immediate Data)  */
end_comment

begin_struct
struct|struct
name|scsi_ram_per_bdq_resource_drv_data
block|{
name|struct
name|scsi_bdq_ram_drv_data
name|drv_data_per_bdq_id
index|[
name|BDQ_NUM_IDS
index|]
comment|/* External ring data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI SGL types  */
end_comment

begin_enum
enum|enum
name|scsi_sgl_mode
block|{
name|SCSI_TX_SLOW_SGL
comment|/* Slow-SGL: More than SCSI_NUM_SGES_SLOW_SGL_THR SGEs and there is at least 1 middle SGE than is smaller than a page size. May be only at TX  */
block|,
name|SCSI_FAST_SGL
comment|/* Fast SGL: Less than SCSI_NUM_SGES_SLOW_SGL_THR SGEs or all middle SGEs are at least a page size */
block|,
name|MAX_SCSI_SGL_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * SCSI SGL parameters  */
end_comment

begin_struct
struct|struct
name|scsi_sgl_params
block|{
name|struct
name|regpair
name|sgl_addr
comment|/* SGL base address */
decl_stmt|;
name|__le32
name|sgl_total_length
comment|/* SGL total legnth (bytes)  */
decl_stmt|;
name|__le32
name|sge_offset
comment|/* Offset in SGE (bytes) */
decl_stmt|;
name|__le16
name|sgl_num_sges
comment|/* Number of SGLs sges */
decl_stmt|;
name|u8
name|sgl_index
comment|/* SGL index */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI terminate connection params  */
end_comment

begin_struct
struct|struct
name|scsi_terminate_extra_params
block|{
name|__le16
name|unsolicited_cq_count
comment|/* Counts number of CQ placements done due to arrival of unsolicited packets on this connection */
decl_stmt|;
name|__le16
name|cmdq_count
comment|/* Counts number of CMDQ placements on this connection */
decl_stmt|;
name|u8
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STORAGE_COMMON__ */
end_comment

end_unit

