begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Exported interface to downloadable microcode for AdvanSys SCSI Adapters  *  * $FreeBSD$  *  * Obtained from:  *  * Copyright (c) 1995-1998 Advanced System Products, Inc.  * All Rights Reserved.  *     * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that redistributions of source  * code retain the above copyright notice and this comment without  * modification.  */
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

begin_decl_stmt
specifier|extern
name|u_int16_t
name|adw_mcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int16_t
name|adw_mcode_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|adw_mcode_chksum
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
name|ADW_MC_STACK_BEGIN
value|0x002E
end_define

begin_comment
comment|/* microcode stack begin */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_STACK_END
value|0x0030
end_define

begin_comment
comment|/* microcode stack end */
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
name|ADW_MC_HALTCODE
value|0x0094
end_define

begin_comment
comment|/* microcode halt code */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_CALLERPC
value|0x0096
end_define

begin_comment
comment|/* microcode halt caller PC */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_ADAPTER_SCSI_ID
value|0x0098
end_define

begin_comment
comment|/* one ID byte + reserved */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_ULTRA_ABLE
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
name|ADW_MC_IDLE_CMD
value|0x00A6
end_define

begin_define
define|#
directive|define
name|ADW_MC_IDLE_PARA_STAT
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
value|0x0F00
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
name|ADW_HSHK_CFG_PERIOD_FACTOR
parameter_list|(
name|cfg_val
parameter_list|)
define|\
value|((((((cfg_val)& ADW_HSHK_CFG_RATE_MASK)>> ADW_HSHK_CFG_RATE_SHIFT) \ 								* 25) + 50)/4)
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
name|ADW_MC_WDTR_ABLE
value|0x0120
end_define

begin_comment
comment|/* Wide Transfer TID bitmask. */
end_comment

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
name|ADW_MC_HOST_NEXT_READY
value|0x0128
end_define

begin_comment
comment|/* Host Next Ready RQL Entry. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_HOST_NEXT_DONE
value|0x0129
end_define

begin_comment
comment|/* Host Next Done RQL Entry. */
end_comment

begin_comment
comment|/*  * LRAM RISC Queue Lists (LRAM addresses 0x1200 - 0x19FF)  *  * Each of the 255 Adv Library/Microcode RISC queue lists or mailboxes   * starting at LRAM address 0x1200 is 8 bytes and has the following  * structure. Only 253 of these are actually used for command queues.  */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_RISC_Q_LIST_BASE
value|0x1200
end_define

begin_define
define|#
directive|define
name|ADW_MC_RISC_Q_LIST_SIZE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADW_MC_RISC_Q_TOTAL_CNT
value|0x00FF
end_define

begin_comment
comment|/* Num. queue slots in LRAM. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_RISC_Q_FIRST
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADW_MC_RISC_Q_LAST
value|0x00FF
end_define

begin_comment
comment|/* RISC Queue List structure - 8 bytes */
end_comment

begin_define
define|#
directive|define
name|RQL_FWD
value|0
end_define

begin_comment
comment|/* forward pointer (1 byte) */
end_comment

begin_define
define|#
directive|define
name|RQL_BWD
value|1
end_define

begin_comment
comment|/* backward pointer (1 byte) */
end_comment

begin_define
define|#
directive|define
name|RQL_STATE
value|2
end_define

begin_comment
comment|/* state byte - free, ready, done, aborted (1 byte) */
end_comment

begin_define
define|#
directive|define
name|RQL_TID
value|3
end_define

begin_comment
comment|/* request target id (1 byte) */
end_comment

begin_define
define|#
directive|define
name|RQL_PHYADDR
value|4
end_define

begin_comment
comment|/* request physical pointer (4 bytes) */
end_comment

begin_comment
comment|/* RISC Queue List state values */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QS_FREE
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_MC_QS_READY
value|0x01
end_define

begin_define
define|#
directive|define
name|ADW_MC_QS_DONE
value|0x40
end_define

begin_define
define|#
directive|define
name|ADW_MC_QS_ABORTED
value|0x80
end_define

begin_comment
comment|/* RISC Queue List pointer values */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_NULL_Q
value|0x00
end_define

begin_define
define|#
directive|define
name|ADW_MC_BIOS_Q
value|0xFF
end_define

begin_comment
comment|/* ADW_SCSI_REQ_Q 'cntl' field values */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_START_MOTOR
value|0x02
end_define

begin_comment
comment|/* Issue start motor. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_NO_OVERRUN
value|0x04
end_define

begin_comment
comment|/* Don't report overrun. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_FIRST_DMA
value|0x08
end_define

begin_comment
comment|/* Internal microcode flag. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_ABORTED
value|0x10
end_define

begin_comment
comment|/* Request aborted by host. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_REQ_SENSE
value|0x20
end_define

begin_comment
comment|/* Auto-Request Sense. */
end_comment

begin_define
define|#
directive|define
name|ADW_MC_QC_DOS_REQ
value|0x80
end_define

begin_comment
comment|/* Request issued by DOS. */
end_comment

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
name|ADW_IDLE_CMD_SCSI_RESET
init|=
literal|0x0020
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

