begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic register and struct definitions for the Adaptech 154x/164x  * SCSI host adapters. Product specific probe and attach routines can  * be found in:  *<fill in list here>  *  * Derived from bt.c written by:  *  * Copyright (c) 1998 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AHAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_AHAREG_H_
end_define

begin_include
include|#
directive|include
file|"aha.h"
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_define
define|#
directive|define
name|AHA_MAXTRANSFER_SIZE
value|0xffffff
end_define

begin_comment
comment|/* limited by 24bit counter */
end_comment

begin_define
define|#
directive|define
name|AHA_NSEG
value|17
end_define

begin_comment
comment|/* The number of dma segments  					 * supported. */
end_comment

begin_define
define|#
directive|define
name|ALL_TARGETS
value|(~0)
end_define

begin_comment
comment|/*  * Control Register pp. 1-8, 1-9 (Write Only)  */
end_comment

begin_define
define|#
directive|define
name|CONTROL_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|HARD_RESET
value|0x80
end_define

begin_comment
comment|/* Hard Reset - return to POST state */
end_comment

begin_define
define|#
directive|define
name|SOFT_RESET
value|0x40
end_define

begin_comment
comment|/* Soft Reset - Clears Adapter state */
end_comment

begin_define
define|#
directive|define
name|RESET_INTR
value|0x20
end_define

begin_comment
comment|/* Reset/Ack Interrupt */
end_comment

begin_define
define|#
directive|define
name|RESET_SBUS
value|0x10
end_define

begin_comment
comment|/* Drive SCSI bus reset signal */
end_comment

begin_comment
comment|/*  * Status Register pp. 1-9, 1-10 (Read Only)  */
end_comment

begin_define
define|#
directive|define
name|STATUS_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|DIAG_ACTIVE
value|0x80
end_define

begin_comment
comment|/* Performing Internal Diags */
end_comment

begin_define
define|#
directive|define
name|DIAG_FAIL
value|0x40
end_define

begin_comment
comment|/* Internal Diags failed */
end_comment

begin_define
define|#
directive|define
name|INIT_REQUIRED
value|0x20
end_define

begin_comment
comment|/* MBOXes need initialization */
end_comment

begin_define
define|#
directive|define
name|HA_READY
value|0x10
end_define

begin_comment
comment|/* HA ready for new commands */
end_comment

begin_define
define|#
directive|define
name|CMD_REG_BUSY
value|0x08
end_define

begin_comment
comment|/* HA busy with last cmd byte */
end_comment

begin_define
define|#
directive|define
name|DATAIN_REG_READY
value|0x04
end_define

begin_comment
comment|/* Data-in Byte available */
end_comment

begin_define
define|#
directive|define
name|STATUS_REG_RSVD
value|0x02
end_define

begin_define
define|#
directive|define
name|CMD_INVALID
value|0x01
end_define

begin_comment
comment|/* Invalid Command detected */
end_comment

begin_comment
comment|/*  * Command/Parameter Register pp. 1-10, 1-11 (Write Only)  */
end_comment

begin_define
define|#
directive|define
name|COMMAND_REG
value|0x01
end_define

begin_comment
comment|/*  * Data in Register p. 1-11 (Read Only)  */
end_comment

begin_define
define|#
directive|define
name|DATAIN_REG
value|0x01
end_define

begin_comment
comment|/*  * Interrupt Status Register pp. 1-12 -> 1-14 (Read Only)  */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|INTR_PENDING
value|0x80
end_define

begin_comment
comment|/* There is a pending INTR */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_REG_RSVD
value|0x70
end_define

begin_define
define|#
directive|define
name|SCSI_BUS_RESET
value|0x08
end_define

begin_comment
comment|/* Bus Reset detected */
end_comment

begin_define
define|#
directive|define
name|CMD_COMPLETE
value|0x04
end_define

begin_define
define|#
directive|define
name|OMB_READY
value|0x02
end_define

begin_comment
comment|/* Outgoin Mailbox Ready */
end_comment

begin_define
define|#
directive|define
name|IMB_LOADED
value|0x01
end_define

begin_comment
comment|/* Incoming Mailbox loaded */
end_comment

begin_comment
comment|/*  * Definitions for the "undocumented" geometry register, we just need  * its location.  */
end_comment

begin_define
define|#
directive|define
name|GEOMETRY_REG
value|0x03
end_define

begin_define
define|#
directive|define
name|AHA_NREGS
value|(4)
end_define

begin_comment
comment|/*  * Opcodes for Adapter commands.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AOP_NOP
init|=
literal|0x00
block|,
name|AOP_INITIALIZE_MBOX
init|=
literal|0x01
block|,
name|AOP_START_MBOX
init|=
literal|0x02
block|,
name|AOP_EXECUTE_BIOS_CMD
init|=
literal|0x03
block|,
name|AOP_INQUIRE_BOARD_ID
init|=
literal|0x04
block|,
name|AOP_ENABLE_OMBR_INT
init|=
literal|0x05
block|,
name|AOP_SET_SEL_TIMOUT
init|=
literal|0x06
block|,
name|AOP_SET_TIME_ON_BUS
init|=
literal|0x07
block|,
name|AOP_SET_TIME_OFF_BUS
init|=
literal|0x08
block|,
name|AOP_SET_BUS_TRANS_RATE
init|=
literal|0x09
block|,
name|AOP_INQUIRE_INST_LDEVS
init|=
literal|0x0A
block|,
name|AOP_INQUIRE_CONFIG
init|=
literal|0x0B
block|,
name|AOP_ENABLE_TARGET_MODE
init|=
literal|0x0C
block|,
name|AOP_INQUIRE_SETUP_INFO
init|=
literal|0x0D
block|,
name|AOP_WRITE_LRAM
init|=
literal|0x1A
block|,
name|AOP_READ_LRAM
init|=
literal|0x1B
block|,
name|AOP_WRITE_CHIP_FIFO
init|=
literal|0x1C
block|,
name|AOP_READ_CHIP_FIFO
init|=
literal|0x1D
block|,
name|AOP_ECHO_DATA_BYTE
init|=
literal|0x1F
block|,
name|AOP_ADAPTER_DIAGNOSTICS
init|=
literal|0x20
block|,
name|AOP_SET_ADAPTER_OPTIONS
init|=
literal|0x21
block|,
name|AOP_SET_EEPROM
init|=
literal|0x22
block|,
name|AOP_RETURN_EEPROM
init|=
literal|0x23
block|,
name|AOP_ENABLE_SHADOW_RAM
init|=
literal|0x24
block|,
name|AOP_INIT_BIOS_MBOX
init|=
literal|0x25
block|,
name|AOP_SET_BIOS_BANK_1
init|=
literal|0x26
block|,
name|AOP_SET_BIOS_BANK_2
init|=
literal|0x27
block|,
name|AOP_RETURN_EXT_BIOS_INFO
init|=
literal|0x28
block|,
name|AOP_MBOX_IF_ENABLE
init|=
literal|0x29
block|,
name|AOP_SCSI_TERM_STATUS
init|=
literal|0x2C
block|,
name|AOP_INQUIRE_SCAM_DEV
init|=
literal|0x2D
block|,
name|AOP_SCSI_DEV_TABLE
init|=
literal|0x2E
block|,
name|AOP_SCAM_OP
init|=
literal|0x2F
block|,
name|AOP_START_BIOS_CMD
init|=
literal|0x82
block|,
name|AOP_INQUIRE_ESETUP_INFO
init|=
literal|0x8D
block|}
name|aha_op_t
typedef|;
end_typedef

begin_comment
comment|/************** Definitions of Multi-byte commands and responses ************/
end_comment

begin_struct
struct|struct
name|aha_extbios
block|{
name|u_int8_t
name|flags
decl_stmt|;
comment|/* Bit 3 == 1 extended bios enabled */
name|u_int8_t
name|mailboxlock
decl_stmt|;
comment|/* mail box lock code to unlock it */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_mboxes
decl_stmt|;
name|u_int8_t
name|base_addr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|init_24b_mbox_params_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|board_type
decl_stmt|;
comment|/* These values are mostly from the aha-1540CP technical reference, but */
comment|/* with other values from the old aha1542.c driver. The values from the */
comment|/* aha-1540CP technical manual are used where conflicts arise */
define|#
directive|define
name|BOARD_1540_16HEAD_BIOS
value|0x00
define|#
directive|define
name|BOARD_1540_64HEAD_BIOS
value|0x30
define|#
directive|define
name|BOARD_1542
value|0x41
comment|/* aha-1540/1542 w/64-h bios */
define|#
directive|define
name|BOARD_1640
value|0x42
comment|/* aha-1640 */
define|#
directive|define
name|BOARD_1740
value|0x43
comment|/* aha-1740A/1742A/1744 */
define|#
directive|define
name|BOARD_1542C
value|0x44
comment|/* aha-1542C */
define|#
directive|define
name|BOARD_1542CF
value|0x45
comment|/* aha-1542CF */
define|#
directive|define
name|BOARD_1542CP
value|0x46
comment|/* aha-1542CP, plug and play */
name|u_int8_t
name|cust_features
decl_stmt|;
define|#
directive|define
name|FEATURES_STANDARD
value|0x30
name|u_int8_t
name|firmware_rev_major
decl_stmt|;
name|u_int8_t
name|firmware_rev_minor
decl_stmt|;
block|}
name|board_id_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|dma_chan
decl_stmt|;
define|#
directive|define
name|DMA_CHAN_5
value|0x20
define|#
directive|define
name|DMA_CHAN_6
value|0x40
define|#
directive|define
name|DMA_CHAN_7
value|0x80
name|u_int8_t
name|irq
decl_stmt|;
define|#
directive|define
name|IRQ_9
value|0x01
define|#
directive|define
name|IRQ_10
value|0x02
define|#
directive|define
name|IRQ_11
value|0x04
define|#
directive|define
name|IRQ_12
value|0x08
define|#
directive|define
name|IRQ_14
value|0x20
define|#
directive|define
name|IRQ_15
value|0x40
name|u_int8_t
name|scsi_id
decl_stmt|;
block|}
name|config_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|enable
decl_stmt|;
block|}
name|target_mode_params_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|offset
range|:
literal|4
decl_stmt|,
name|period
range|:
literal|3
decl_stmt|,
name|sync
range|:
literal|1
decl_stmt|;
block|}
name|targ_syncinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|initiate_sync
range|:
literal|1
decl_stmt|,
name|parity_enable
range|:
literal|1
decl_stmt|,
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|bus_transfer_rate
decl_stmt|;
name|u_int8_t
name|time_on_bus
decl_stmt|;
name|u_int8_t
name|time_off_bus
decl_stmt|;
name|u_int8_t
name|num_mboxes
decl_stmt|;
name|u_int8_t
name|mbox_base_addr
index|[
literal|3
index|]
decl_stmt|;
name|targ_syncinfo_t
name|syncinfo
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|discinfo
decl_stmt|;
name|u_int8_t
name|customer_sig
index|[
literal|20
index|]
decl_stmt|;
name|u_int8_t
name|auto_retry
decl_stmt|;
name|u_int8_t
name|board_switches
decl_stmt|;
name|u_int8_t
name|firmware_cksum
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|bios_mbox_addr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|setup_data_t
typedef|;
end_typedef

begin_struct
struct|struct
name|aha_isa_port
block|{
name|u_int16_t
name|addr
decl_stmt|;
name|u_int8_t
name|bio
decl_stmt|;
comment|/* board IO offset */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AHA_NUM_ISAPORTS
value|6
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|BIO_330
init|=
literal|0
block|,
name|BIO_334
init|=
literal|1
block|,
name|BIO_230
init|=
literal|2
block|,
name|BIO_234
init|=
literal|3
block|,
name|BIO_130
init|=
literal|4
block|,
name|BIO_134
init|=
literal|5
block|,
name|BIO_DISABLED
init|=
literal|6
block|,
name|BIO_DISABLED2
init|=
literal|7
block|}
name|isa_compat_io_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|sync_rate
index|[
literal|16
index|]
decl_stmt|;
comment|/* Sync in 10ns units */
block|}
name|target_sync_info_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|len
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|addr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|aha_sg_t
typedef|;
end_typedef

begin_comment
comment|/********************** Mail Box definitions *******************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AMBO_FREE
init|=
literal|0x0
block|,
comment|/* MBO intry is free */
name|AMBO_START
init|=
literal|0x1
block|,
comment|/* MBO activate entry */
name|AMBO_ABORT
init|=
literal|0x2
comment|/* MBO abort entry */
block|}
name|aha_mbo_action_code_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aha_mbox_out
block|{
name|u_int8_t
name|action_code
decl_stmt|;
name|u_int8_t
name|ccb_addr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|aha_mbox_out_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AMBI_FREE
init|=
literal|0x0
block|,
comment|/* MBI entry is free */
name|AMBI_OK
init|=
literal|0x1
block|,
comment|/* completed without error */
name|AMBI_ABORT
init|=
literal|0x2
block|,
comment|/* aborted ccb */
name|AMBI_NOT_FOUND
init|=
literal|0x3
block|,
comment|/* Tried to abort invalid CCB */
name|AMBI_ERROR
init|=
literal|0x4
comment|/* Completed with error */
block|}
name|aha_mbi_comp_code_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aha_mbox_in
block|{
name|u_int8_t
name|comp_code
decl_stmt|;
name|u_int8_t
name|ccb_addr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|aha_mbox_in_t
typedef|;
end_typedef

begin_comment
comment|/****************** Hardware CCB definition *********************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|INITIATOR_CCB
init|=
literal|0x00
block|,
name|INITIATOR_SG_CCB
init|=
literal|0x02
block|,
name|INITIATOR_CCB_WRESID
init|=
literal|0x03
block|,
name|INITIATOR_SG_CCB_WRESID
init|=
literal|0x04
block|,
name|INITIATOR_BUS_DEV_RESET
init|=
literal|0x81
block|}
name|aha_ccb_opcode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHASTAT_NOERROR
init|=
literal|0x00
block|,
name|AHASTAT_SELTIMEOUT
init|=
literal|0x11
block|,
name|AHASTAT_DATARUN_ERROR
init|=
literal|0x12
block|,
name|AHASTAT_UNEXPECTED_BUSFREE
init|=
literal|0x13
block|,
name|AHASTAT_INVALID_PHASE
init|=
literal|0x14
block|,
name|AHASTAT_INVALID_ACTION_CODE
init|=
literal|0x15
block|,
name|AHASTAT_INVALID_OPCODE
init|=
literal|0x16
block|,
name|AHASTAT_LINKED_CCB_LUN_MISMATCH
init|=
literal|0x17
block|,
name|AHASTAT_INVALID_CCB_OR_SG_PARAM
init|=
literal|0x1A
block|,
name|AHASTAT_HA_SCSI_BUS_RESET
init|=
literal|0x22
block|,
comment|/* stolen from bt */
name|AHASTAT_HA_BDR
init|=
literal|0x25
comment|/* Stolen from bt */
block|}
name|ahastat_t
typedef|;
end_typedef

begin_struct
struct|struct
name|aha_hccb
block|{
name|u_int8_t
name|opcode
decl_stmt|;
comment|/* 0 */
name|u_int8_t
name|lun
range|:
literal|3
decl_stmt|,
comment|/* 1 */
name|datain
range|:
literal|1
decl_stmt|,
name|dataout
range|:
literal|1
decl_stmt|,
name|target
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|cmd_len
decl_stmt|;
comment|/* 2 */
name|u_int8_t
name|sense_len
decl_stmt|;
comment|/* 3 */
name|u_int8_t
name|data_len
index|[
literal|3
index|]
decl_stmt|;
comment|/* 4 */
name|u_int8_t
name|data_addr
index|[
literal|3
index|]
decl_stmt|;
comment|/* 7 */
name|u_int8_t
name|link_ptr
index|[
literal|3
index|]
decl_stmt|;
comment|/* 10 */
name|u_int8_t
name|link_id
decl_stmt|;
comment|/* 13 */
name|u_int8_t
name|ahastat
decl_stmt|;
comment|/* 14 */
name|u_int8_t
name|sdstat
decl_stmt|;
comment|/* 15 */
name|u_int8_t
name|reserved1
decl_stmt|;
comment|/* 16 */
name|u_int8_t
name|reserved2
decl_stmt|;
comment|/* 17 */
name|u_int8_t
name|scsi_cdb
index|[
literal|16
index|]
decl_stmt|;
comment|/* 18 */
name|u_int8_t
name|sense_data
index|[
name|SSD_FULL_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACCB_FREE
init|=
literal|0x0
block|,
name|ACCB_ACTIVE
init|=
literal|0x1
block|,
name|ACCB_DEVICE_RESET
init|=
literal|0x2
block|,
name|ACCB_RELEASE_SIMQ
init|=
literal|0x4
block|}
name|accb_flags_t
typedef|;
end_typedef

begin_struct
struct|struct
name|aha_ccb
block|{
name|struct
name|aha_hccb
name|hccb
decl_stmt|;
comment|/* hccb assumed to be at 0 */
name|SLIST_ENTRY
argument_list|(
argument|aha_ccb
argument_list|)
name|links
expr_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|aha_sg_t
modifier|*
name|sg_list
decl_stmt|;
name|u_int32_t
name|sg_list_phys
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sg_map_node
block|{
name|bus_dmamap_t
name|sg_dmamap
decl_stmt|;
name|bus_addr_t
name|sg_physaddr
decl_stmt|;
name|aha_sg_t
modifier|*
name|sg_vaddr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sg_map_node
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aha_softc
block|{
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|aha_mbox_out_t
modifier|*
name|cur_outbox
decl_stmt|;
name|aha_mbox_in_t
modifier|*
name|cur_inbox
decl_stmt|;
name|aha_mbox_out_t
modifier|*
name|last_outbox
decl_stmt|;
name|aha_mbox_in_t
modifier|*
name|last_inbox
decl_stmt|;
name|struct
name|aha_ccb
modifier|*
name|aha_ccb_array
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|aha_ccb
argument_list|)
name|free_aha_ccbs
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
name|u_int
name|active_ccbs
decl_stmt|;
name|u_int32_t
name|aha_ccb_physbase
decl_stmt|;
name|aha_ccb_opcode_t
name|ccb_sg_opcode
decl_stmt|;
name|aha_ccb_opcode_t
name|ccb_ccb_opcode
decl_stmt|;
name|aha_mbox_in_t
modifier|*
name|in_boxes
decl_stmt|;
name|aha_mbox_out_t
modifier|*
name|out_boxes
decl_stmt|;
name|struct
name|scsi_sense_data
modifier|*
name|sense_buffers
decl_stmt|;
name|u_int32_t
name|sense_buffers_physbase
decl_stmt|;
name|struct
name|aha_ccb
modifier|*
name|recovery_accb
decl_stmt|;
name|u_int
name|num_boxes
decl_stmt|;
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
comment|/* 						 * All dmat's derive from 						 * the dmat defined by our 						 * bus. 						 */
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
name|bus_dma_tag_t
name|mailbox_dmat
decl_stmt|;
comment|/* dmat for our mailboxes */
name|bus_dmamap_t
name|mailbox_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|ccb_dmat
decl_stmt|;
comment|/* dmat for our ccb array */
name|bus_dmamap_t
name|ccb_dmamap
decl_stmt|;
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
comment|/* dmat for our sg maps */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|sg_map_node
argument_list|)
name|sg_maps
expr_stmt|;
name|bus_addr_t
name|mailbox_physbase
decl_stmt|;
name|u_int
name|num_ccbs
decl_stmt|;
comment|/* Number of CCBs malloc'd */
name|u_int
name|max_ccbs
decl_stmt|;
comment|/* Maximum allocatable CCBs */
name|u_int
name|max_sg
decl_stmt|;
name|u_int
name|unit
decl_stmt|;
name|u_int
name|scsi_id
decl_stmt|;
name|u_int32_t
name|extended_trans
range|:
literal|1
decl_stmt|,
name|diff_bus
range|:
literal|1
decl_stmt|,
name|extended_lun
range|:
literal|1
decl_stmt|,
name|strict_rr
range|:
literal|1
decl_stmt|,
name|tag_capable
range|:
literal|1
decl_stmt|,
name|resource_shortage
range|:
literal|1
decl_stmt|,
range|:
literal|26
decl_stmt|;
name|u_int16_t
name|disc_permitted
decl_stmt|;
name|u_int16_t
name|sync_permitted
decl_stmt|;
name|u_int8_t
name|init_level
decl_stmt|;
specifier|volatile
name|u_int8_t
name|command_cmp
decl_stmt|;
specifier|volatile
name|u_int8_t
name|latched_status
decl_stmt|;
name|u_int32_t
name|bios_addr
decl_stmt|;
name|u_int8_t
name|fw_major
decl_stmt|;
name|u_int8_t
name|fw_minor
decl_stmt|;
name|char
name|model
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|boardid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irqrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|port
decl_stmt|;
name|int
name|portrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|drq
decl_stmt|;
name|int
name|drqrid
decl_stmt|;
name|void
modifier|*
modifier|*
name|ih
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|aha_softc
modifier|*
name|aha_softcs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX Config should handle this */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|aha_unit
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AHA_TEMP_UNIT
value|0xFF
end_define

begin_comment
comment|/* Unit for probes */
end_comment

begin_function_decl
name|struct
name|aha_softc
modifier|*
name|aha_alloc
parameter_list|(
name|int
parameter_list|,
name|bus_space_tag_t
parameter_list|,
name|bus_space_handle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_attach
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_cmd
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|,
name|aha_op_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_detach
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_fetch_adapter_info
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aha_find_probe_range
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aha_free
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_init
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aha_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_iop_from_bio
parameter_list|(
name|isa_compat_io_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|aha_name
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aha_probe
parameter_list|(
name|struct
name|aha_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DEFAULT_CMD_TIMEOUT
value|10000
end_define

begin_comment
comment|/* 1 sec */
end_comment

begin_define
define|#
directive|define
name|aha_inb
parameter_list|(
name|aha
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((aha)->tag, (aha)->bsh, port)
end_define

begin_define
define|#
directive|define
name|aha_outb
parameter_list|(
name|aha
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((aha)->tag, (aha)->bsh, port, value)
end_define

begin_comment
comment|/* XXX BAD */
end_comment

begin_define
define|#
directive|define
name|EXTRA_AHA
value|4
end_define

begin_define
define|#
directive|define
name|NAHATOT
value|(NAHA + EXTRA_AHA)
end_define

begin_define
define|#
directive|define
name|ADP0100_PNP
value|0x00019004
end_define

begin_comment
comment|/* ADP0100 */
end_comment

begin_define
define|#
directive|define
name|AHA1540_PNP
value|0x40159004
end_define

begin_comment
comment|/* ADP1540 */
end_comment

begin_define
define|#
directive|define
name|AHA1542_PNP
value|0x42159004
end_define

begin_comment
comment|/* ADP1542 */
end_comment

begin_define
define|#
directive|define
name|AHA1542_PNPCOMPAT
value|0xA000D040
end_define

begin_comment
comment|/* PNP00A0 */
end_comment

begin_define
define|#
directive|define
name|ICU0091_PNP
value|0X91005AA4
end_define

begin_comment
comment|/* ICU0091 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AHA_H_ */
end_comment

end_unit

