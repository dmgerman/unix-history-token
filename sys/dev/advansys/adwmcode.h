begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Exported interface to downloadable microcode for AdvanSys SCSI Adapters  *  * $FreeBSD$  *  * Obtained from:  *  * Copyright (c) 1995-1999 Advanced System Products, Inc.  * All Rights Reserved.  *     * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that redistributions of source  * code retain the above copyright notice and this comment without  * modification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADMCODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADMCODE_H_
end_define

begin_struct
struct|struct
name|adw_mcode
block|{
specifier|const
name|u_int8_t
modifier|*
name|mcode_buf
decl_stmt|;
specifier|const
name|u_int32_t
name|mcode_chksum
decl_stmt|;
specifier|const
name|u_int16_t
name|mcode_size
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|adw_mcode
name|adw_asc3550_mcode_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|adw_mcode
name|adw_asc38C0800_mcode_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Fixed LRAM locations of microcode operating variables.  */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CODE_BEGIN_ADDR
value|0x0028
end_define

begin_comment
comment|/* microcode start address */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CODE_END_ADDR
value|0x002A
end_define

begin_comment
comment|/* microcode end address */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CODE_CHK_SUM
value|0x002C
end_define

begin_comment
comment|/* microcode code checksum */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_VERSION_DATE
value|0x0038
end_define

begin_comment
comment|/* microcode version */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_VERSION_NUM
value|0x003A
end_define

begin_comment
comment|/* microcode number */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOSMEM
value|0x0040
end_define

begin_comment
comment|/* BIOS RISC Memory Start */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOSLEN
value|0x0050
end_define

begin_comment
comment|/* BIOS RISC Memory Length */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOS_SIGNATURE
value|0x0058
end_define

begin_comment
comment|/* BIOS Signature 0x55AA */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_BIOS_VERSION
value|0x005A
end_define

begin_comment
comment|/* BIOS Version (2 Bytes) */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_SDTR_SPEED1
value|0x0090
end_define

begin_comment
comment|/* SDTR Speed for TID 0-3 */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_SDTR_SPEED2
value|0x0092
end_define

begin_comment
comment|/* SDTR Speed for TID 4-7 */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_SDTR_SPEED3
value|0x0094
end_define

begin_comment
comment|/* SDTR Speed for TID 8-11 */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_SDTR_SPEED4
value|0x0096
end_define

begin_comment
comment|/* SDTR Speed for TID 12-15 */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CHIP_TYPE
value|0x009A
end_define

begin_define
define|#
directive|define
name|ADW_MC_INTRB_CODE
value|0x009B
end_define

begin_define
define|#
directive|define
name|ADW_ASYNC_RDMA_FAILURE
value|0x01
end_define

begin_comment
comment|/* Fatal RDMA failure. */
end_comment

begin_define
define|#
directive|define
name|ADW_ASYNC_SCSI_BUS_RESET_DET
value|0x02
end_define

begin_comment
comment|/* Detected Bus Reset. */
end_comment

begin_define
define|#
directive|define
name|ADW_ASYNC_CARRIER_READY_FAILURE
value|0x03
end_define

begin_comment
comment|/* Carrier Ready failure.*/
end_comment

begin_define
define|#
directive|define
name|ADW_ASYNC_HOST_SCSI_BUS_RESET
value|0x80
end_define

begin_comment
comment|/* 						      * Host Initiated 						      * SCSI Bus Reset. 						      */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_WDTR_ABLE_BIOS_31
value|0x0120
end_define

begin_define
define|#
directive|define
name|ADW_MC_WDTR_ABLE
value|0x009C
end_define

begin_define
define|#
directive|define
name|ADW_MC_SDTR_ABLE
value|0x009E
end_define

begin_define
define|#
directive|define
name|ADW_MC_TAGQNG_ABLE
value|0x00A0
end_define

begin_define
define|#
directive|define
name|ADW_MC_DISC_ENABLE
value|0x00A2
end_define

begin_define
define|#
directive|define
name|ADW_MC_IDLE_CMD_STATUS
value|0x00A4
end_define

begin_define
define|#
directive|define
name|ADW_MC_IDLE_CMD
value|0x00A6
end_define

begin_define
define|#
directive|define
name|ADW_MC_IDLE_CMD_PARAMETER
value|0x00A8
end_define

begin_define
define|#
directive|define
name|ADW_MC_DEFAULT_SCSI_CFG0
value|0x00AC
end_define

begin_define
define|#
directive|define
name|ADW_MC_DEFAULT_SCSI_CFG1
value|0x00AE
end_define

begin_define
define|#
directive|define
name|ADW_MC_DEFAULT_MEM_CFG
value|0x00B0
end_define

begin_define
define|#
directive|define
name|ADW_MC_DEFAULT_SEL_MASK
value|0x00B2
end_define

begin_define
define|#
directive|define
name|ADW_MC_RISC_NEXT_READY
value|0x00B4
end_define

begin_define
define|#
directive|define
name|ADW_MC_RISC_NEXT_DONE
value|0x00B5
end_define

begin_define
define|#
directive|define
name|ADW_MC_SDTR_DONE
value|0x00B6
end_define

begin_define
define|#
directive|define
name|ADW_MC_NUMBER_OF_QUEUED_CMD
value|0x00C0
end_define

begin_define
define|#
directive|define
name|ADW_MC_NUMBER_OF_MAX_CMD
value|0x00D0
end_define

begin_define
define|#
directive|define
name|ADW_MC_DEVICE_HSHK_CFG_TABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ADW_HSHK_CFG_WIDE_XFR
value|0x8000
end_define

begin_define
define|#
directive|define
name|ADW_HSHK_CFG_RATE_MASK
value|0x7F00
end_define

begin_define
define|#
directive|define
name|ADW_HSHK_CFG_RATE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ADW_HSHK_CFG_OFFSET
value|0x001F
end_define

begin_define
define|#
directive|define
name|ADW_MC_CONTROL_FLAG
value|0x0122
end_define

begin_comment
comment|/* Microcode control flag. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CONTROL_IGN_PERR
value|0x0001
end_define

begin_comment
comment|/* Ignore DMA Parity Errors */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_WDTR_DONE
value|0x0124
end_define

begin_define
define|#
directive|define
name|ADW_MC_CAM_MODE_MASK
value|0x015E
end_define

begin_comment
comment|/* CAM mode TID bitmask. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_ICQ
value|0x0160
end_define

begin_define
define|#
directive|define
name|ADW_MC_IRQ
value|0x0164
end_define

begin_comment
comment|/* ADW_SCSI_REQ_Q 'cntl' field values */
end_comment

begin_define
define|#
directive|define
name|ADW_QC_DATA_CHECK
value|0x01
end_define

begin_comment
comment|/* Require ADW_QC_DATA_OUT set or clear. */
end_comment

begin_define
define|#
directive|define
name|ADW_QC_DATA_OUT
value|0x02
end_define

begin_comment
comment|/* Data out DMA transfer. */
end_comment

begin_define
define|#
directive|define
name|ADW_QC_START_MOTOR
value|0x04
end_define

begin_comment
comment|/* Send auto-start motor before request. */
end_comment

begin_define
define|#
directive|define
name|ADW_QC_NO_OVERRUN
value|0x08
end_define

begin_comment
comment|/* Don't report overrun. */
end_comment

begin_define
define|#
directive|define
name|ADW_QC_FREEZE_TIDQ
value|0x10
end_define

begin_comment
comment|/* Freeze TID queue after request.XXXTBD */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_NO_DISC
value|0x01
end_define

begin_comment
comment|/* Don't allow disconnect for request.  */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_NO_TAGMSG
value|0x02
end_define

begin_comment
comment|/* Don't allow tag queuing for request. */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_NO_SYNC
value|0x04
end_define

begin_comment
comment|/* Don't use Synch. transfer on request.*/
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_NO_WIDE
value|0x08
end_define

begin_comment
comment|/* Don't use Wide transfer on request.  */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_REDO_DTR
value|0x10
end_define

begin_comment
comment|/* Renegotiate WDTR/SDTR before request.*/
end_comment

begin_comment
comment|/*  * Note: If a Tag Message is to be sent and neither ADW_QSC_HEAD_TAG or  * ADW_QSC_ORDERED_TAG is set, then a Simple Tag Message (0x20) is used.  */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_HEAD_TAG
value|0x40
end_define

begin_comment
comment|/* Use Head Tag Message (0x21). */
end_comment

begin_define
define|#
directive|define
name|ADW_QSC_ORDERED_TAG
value|0x80
end_define

begin_comment
comment|/* Use Ordered Tag Message (0x22). */
end_comment

begin_struct
struct|struct
name|adw_carrier
block|{
name|u_int32_t
name|carr_offset
decl_stmt|;
comment|/* Carrier byte offset into our array */
name|u_int32_t
name|carr_ba
decl_stmt|;
comment|/* Carrier Bus Address */
name|u_int32_t
name|areq_ba
decl_stmt|;
comment|/* SCSI Req Queue Bus Address */
name|u_int32_t
name|next_ba
decl_stmt|;
define|#
directive|define
name|ADW_RQ_DONE
value|0x00000001
define|#
directive|define
name|ADW_CQ_STOPPER
value|0x00000000
define|#
directive|define
name|ADW_NEXT_BA_MASK
value|0xFFFFFFF0
block|}
struct|;
end_struct

begin_comment
comment|/*  * Microcode idle loop commands  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_IDLE_CMD_COMPLETED
init|=
literal|0x0000
block|,
name|ADW_IDLE_CMD_STOP_CHIP
init|=
literal|0x0001
block|,
name|ADW_IDLE_CMD_STOP_CHIP_SEND_INT
init|=
literal|0x0002
block|,
name|ADW_IDLE_CMD_SEND_INT
init|=
literal|0x0004
block|,
name|ADW_IDLE_CMD_ABORT
init|=
literal|0x0008
block|,
name|ADW_IDLE_CMD_DEVICE_RESET
init|=
literal|0x0010
block|,
name|ADW_IDLE_CMD_SCSI_RESET_START
init|=
literal|0x0020
block|,
name|ADW_IDLE_CMD_SCSI_RESET_END
init|=
literal|0x0040
block|,
name|ADW_IDLE_CMD_SCSIREQ
init|=
literal|0x0080
block|}
name|adw_idle_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ADW_IDLE_CMD_FAILURE
init|=
literal|0x0000
block|,
name|ADW_IDLE_CMD_SUCCESS
init|=
literal|0x0001
block|}
name|adw_idle_cmd_status_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADMCODE_H_ */
end_comment

end_unit

