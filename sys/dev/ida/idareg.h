begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * #defines and software structures for the Compaq RAID card  */
end_comment

begin_comment
comment|/*  * defines for older EISA controllers (IDA, IDA-2, IAES, SMART)  */
end_comment

begin_define
define|#
directive|define
name|R_EISA_INT_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|R_EISA_LOCAL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|R_EISA_LOCAL_DOORBELL
value|0x05
end_define

begin_define
define|#
directive|define
name|R_EISA_SYSTEM_MASK
value|0x06
end_define

begin_define
define|#
directive|define
name|R_EISA_SYSTEM_DOORBELL
value|0x07
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_ADDR
value|0x08
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_LEN
value|0x0c
end_define

begin_define
define|#
directive|define
name|R_EISA_TAG
value|0x0f
end_define

begin_define
define|#
directive|define
name|R_EISA_COMPLETE_ADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_STATUS
value|0x16
end_define

begin_define
define|#
directive|define
name|EISA_CHANNEL_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|EISA_CHANNEL_CLEAR
value|0x02
end_define

begin_comment
comment|/*  * board register offsets for SMART-2 controllers  */
end_comment

begin_define
define|#
directive|define
name|R_CMD_FIFO
value|0x04
end_define

begin_define
define|#
directive|define
name|R_DONE_FIFO
value|0x08
end_define

begin_define
define|#
directive|define
name|R_INT_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|R_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|R_INT_PENDING
value|0x14
end_define

begin_comment
comment|/*  * interrupt mask values for SMART series  */
end_comment

begin_define
define|#
directive|define
name|INT_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|INT_ENABLE
value|0x01
end_define

begin_comment
comment|/*  * board offsets for the 42xx series  */
end_comment

begin_define
define|#
directive|define
name|R_42XX_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|R_42XX_INT_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|R_42XX_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|R_42XX_REPLY
value|0x44
end_define

begin_comment
comment|/*  * interrupt values for 42xx series  */
end_comment

begin_define
define|#
directive|define
name|INT_ENABLE_42XX
value|0x00
end_define

begin_define
define|#
directive|define
name|INT_DISABLE_42XX
value|0x08
end_define

begin_define
define|#
directive|define
name|STATUS_42XX_INT_PENDING
value|0x08
end_define

begin_comment
comment|/*  * return status codes  */
end_comment

begin_define
define|#
directive|define
name|SOFT_ERROR
value|0x02
end_define

begin_comment
comment|/* Non-fatal error. */
end_comment

begin_define
define|#
directive|define
name|HARD_ERROR
value|0x04
end_define

begin_comment
comment|/* Fatal error. */
end_comment

begin_define
define|#
directive|define
name|INVALID_ERROR
value|0x10
end_define

begin_comment
comment|/* Invalid Request Block. */
end_comment

begin_define
define|#
directive|define
name|CMD_REJECTED
value|0x14
end_define

begin_comment
comment|/*  * command types  */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_LOG_DRV_INFO
value|0x10
end_define

begin_comment
comment|/* Identify controller */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_CTRL_INFO
value|0x11
end_define

begin_comment
comment|/* Identify logical driver */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_DRV_STATUS
value|0x12
end_define

begin_comment
comment|/* Sense logical drive status */
end_comment

begin_define
define|#
directive|define
name|CMD_START_RECOVERY
value|0x13
end_define

begin_comment
comment|/* Start recover */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_PHYS_DRV_INFO
value|0x15
end_define

begin_comment
comment|/* Identify physical drive */
end_comment

begin_define
define|#
directive|define
name|CMD_BLINK_DRV_LEDS
value|0x16
end_define

begin_comment
comment|/* Blink drive tray LEDs */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_DRV_LEDS
value|0x17
end_define

begin_comment
comment|/* Sense Blinking drive tray LEDs */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_LOG_DRV_EXT
value|0x18
end_define

begin_comment
comment|/* Identify logical drive, Extended */
end_comment

begin_define
define|#
directive|define
name|CMD_READ
value|0x20
end_define

begin_comment
comment|/* Read */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x30
end_define

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE_MEDIA
value|0x31
end_define

begin_comment
comment|/* Write media */
end_comment

begin_define
define|#
directive|define
name|CMD_RESET_CTRL
value|0x40
end_define

begin_comment
comment|/* Reset controller */
end_comment

begin_define
define|#
directive|define
name|CMD_DIAG_PASS_THRU
value|0x41
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_CONFIG
value|0x50
end_define

begin_comment
comment|/* Sense configuration */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_CONFIG
value|0x51
end_define

begin_comment
comment|/* Set configuration */
end_comment

begin_define
define|#
directive|define
name|CMD_BYPASS_VOL_STATE
value|0x52
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_SS_CREATE_VOL
value|0x53
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_CHANGE_CONFIG
value|0x54
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_ORIG_CONF
value|0x55
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_REORDER_LOG_DRV
value|0x56
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_LABEL_LOG_DRV
value|0x57
end_define

begin_comment
comment|/* Label logical drive */
end_comment

begin_define
define|#
directive|define
name|CMD_SS_TO_VOL
value|0x58
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_SURFACE_DELAY
value|0x60
end_define

begin_comment
comment|/* Set surface delay */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_OVERHEAT_DELAY
value|0x61
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_BUS_PARAMS
value|0x65
end_define

begin_comment
comment|/* Sense bus parameters */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_SUBSYS_INFO
value|0x66
end_define

begin_comment
comment|/* Sense Subsystem Information */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_SURFACE_ATS
value|0x70
end_define

begin_comment
comment|/* Sense surface analysis task status */
end_comment

begin_define
define|#
directive|define
name|CMD_PASSTHROUGH
value|0x90
end_define

begin_comment
comment|/* Pass-through operation */
end_comment

begin_define
define|#
directive|define
name|CMD_PASSTHROUGH_A
value|0x91
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_RESET_SCSI_DEV
value|0x94
end_define

begin_comment
comment|/* Reset SCSI device */
end_comment

begin_define
define|#
directive|define
name|CMD_PAUSE_BG_ACT
value|0x98
end_define

begin_comment
comment|/* Pause Background Activity */
end_comment

begin_define
define|#
directive|define
name|CMD_RESUME_BG_ACT
value|0x99
end_define

begin_comment
comment|/* Resume Background Activity */
end_comment

begin_define
define|#
directive|define
name|CMD_START_FIRMWARE
value|0x99
end_define

begin_comment
comment|/* for integrated RAID */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_DRV_ERR_LOG
value|0xa6
end_define

begin_comment
comment|/* Sense drive error log */
end_comment

begin_define
define|#
directive|define
name|CMD_START_CPM
value|0xa7
end_define

begin_comment
comment|/* Start controller performance monitoring */
end_comment

begin_define
define|#
directive|define
name|CMD_SENSE_CP
value|0xa8
end_define

begin_comment
comment|/* Sense controller performance */
end_comment

begin_define
define|#
directive|define
name|CMD_STOP_CPM
value|0xa9
end_define

begin_comment
comment|/* Stop controller performance monitoring */
end_comment

begin_define
define|#
directive|define
name|CMD_FLUSH_CACHE
value|0xc2
end_define

begin_comment
comment|/* Flush/disable write cache */
end_comment

begin_define
define|#
directive|define
name|CMD_COLLECT_BUFFER
value|0xd2
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|CMD_ACCEPT_MEDIA_EXCH
value|0xe0
end_define

begin_comment
comment|/* Accept Media Exchange */
end_comment

begin_define
define|#
directive|define
name|CMD_FLASH_READ
value|0xf6
end_define

begin_comment
comment|/* Read FLASH */
end_comment

begin_define
define|#
directive|define
name|CMD_FLASH_WRITE
value|0xf7
end_define

begin_comment
comment|/* Write FLASH */
end_comment

begin_comment
comment|/* logical drive parameter table */
end_comment

begin_struct
struct|struct
name|ida_drive_param
block|{
name|u_int16_t
name|ncylinders
decl_stmt|;
name|u_int8_t
name|nheads
decl_stmt|;
name|u_int8_t
name|signature
decl_stmt|;
name|u_int8_t
name|psectors
decl_stmt|;
name|u_int16_t
name|wprecomp
decl_stmt|;
name|u_int8_t
name|max_acc
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
name|u_int16_t
name|pcylinders
decl_stmt|;
name|u_int8_t
name|ptracks
decl_stmt|;
name|u_int16_t
name|landing_zone
decl_stmt|;
name|u_int8_t
name|nsectors
decl_stmt|;
name|u_int8_t
name|checksum
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IDA_RAID0
value|0
end_define

begin_comment
comment|/* No fault tolerance. */
end_comment

begin_define
define|#
directive|define
name|IDA_RAID4
value|1
end_define

begin_comment
comment|/* Data Guard */
end_comment

begin_define
define|#
directive|define
name|IDA_RAID1
value|2
end_define

begin_comment
comment|/* Mirroring */
end_comment

begin_define
define|#
directive|define
name|IDA_RAID5
value|3
end_define

begin_comment
comment|/* Distributed Data Guard */
end_comment

begin_comment
comment|/*  * CMD_GET_LOG_DRV_INFO (0x10)  * Identify Logical Drive  */
end_comment

begin_struct
struct|struct
name|ida_drive_info
block|{
name|u_int16_t
name|secsize
decl_stmt|;
comment|/* block size in bytes */
name|u_int32_t
name|secperunit
decl_stmt|;
comment|/* blocks available */
name|struct
name|ida_drive_param
name|dp
decl_stmt|;
comment|/* logical drive parameter table */
name|u_int8_t
name|mirror
decl_stmt|;
comment|/* fault tolerance */
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|bios_disable
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_GET_LOG_DRV_EXT (0x18)  * Identify Logical Drive, Extended  */
end_comment

begin_struct
struct|struct
name|ida_drive_info_ext
block|{
name|u_int16_t
name|secsize
decl_stmt|;
comment|/* block size in bytes */
name|u_int32_t
name|secperunit
decl_stmt|;
comment|/* blocks available */
name|struct
name|ida_drive_param
name|dp
decl_stmt|;
comment|/* logical drive parameter table */
name|u_int8_t
name|mirror
decl_stmt|;
comment|/* fault tolerance */
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|bios_disable
decl_stmt|;
name|u_int32_t
name|ld_id
decl_stmt|;
comment|/* Logical drive identifier */
name|u_int8_t
name|ld_label
index|[
literal|64
index|]
decl_stmt|;
comment|/* Logical drive label */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_GET_CTRL_INFO (0x11)  * Identify Controller  */
end_comment

begin_struct
struct|struct
name|ida_controller_info
block|{
name|u_int8_t
name|num_drvs
decl_stmt|;
comment|/* Number of configured logical drives */
name|u_int32_t
name|signature
decl_stmt|;
comment|/* Configuration signature */
name|u_int8_t
name|firm_rev
index|[
literal|4
index|]
decl_stmt|;
comment|/* ASCII firmware revision */
name|u_int8_t
name|rom_rev
index|[
literal|4
index|]
decl_stmt|;
comment|/* ROM firmware revision */
name|u_int8_t
name|hw_rev
decl_stmt|;
comment|/* Revision level of the hardware */
name|u_int32_t
name|bb_rev
decl_stmt|;
name|u_int32_t
name|dp_map
decl_stmt|;
comment|/* Drive present bit map */
name|u_int32_t
name|ed_map
decl_stmt|;
comment|/* External drive bit map */
name|u_int32_t
name|board_id
decl_stmt|;
name|u_int8_t
name|cfg_error
decl_stmt|;
name|u_int32_t
name|nd_map
decl_stmt|;
comment|/* Non-disk map */
name|u_int8_t
name|bad_ram_addr
decl_stmt|;
name|u_int8_t
name|cpu_rev
decl_stmt|;
name|u_int8_t
name|pdpi_rev
decl_stmt|;
name|u_int8_t
name|epic_rev
decl_stmt|;
name|u_int8_t
name|wcxc_rev
decl_stmt|;
name|u_int8_t
name|mkt_rev
decl_stmt|;
comment|/* Marketing revision */
name|u_int8_t
name|cflag
decl_stmt|;
comment|/* Controller flags */
define|#
directive|define
name|IDA_CI_CFLAG_7DPB
value|(1<<3)
define|#
directive|define
name|IDA_CI_CFLAG_BIGMAP
value|(1<<7)
name|u_int8_t
name|hflag
decl_stmt|;
name|u_int8_t
name|expand_dis
decl_stmt|;
name|u_int8_t
name|scsi_cc
decl_stmt|;
comment|/* SCSI chip count */
name|u_int32_t
name|max_req_blocks
decl_stmt|;
name|u_int32_t
name|cclock
decl_stmt|;
comment|/* Controller Clock */
name|u_int8_t
name|dp_scsi
decl_stmt|;
comment|/* Drives per SCSI bus */
name|u_int16_t
name|big_dp_map
index|[
literal|8
index|]
decl_stmt|;
comment|/* Big drive present bit map */
name|u_int16_t
name|big_ed_map
index|[
literal|8
index|]
decl_stmt|;
comment|/* Big external drive bit map */
name|u_int16_t
name|big_nd_map
index|[
literal|8
index|]
decl_stmt|;
comment|/* Big non-disk map */
name|u_int16_t
name|task_flags
decl_stmt|;
name|u_int8_t
name|icl_bus
decl_stmt|;
name|u_int8_t
name|red_modes
decl_stmt|;
name|u_int8_t
name|cur_red_mode
decl_stmt|;
name|u_int8_t
name|red_ctlr_stat
decl_stmt|;
name|u_int8_t
name|red_fail_reason
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|403
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_SENSE_DRV_STATUS (0x12)  * Sense logical drive status  */
end_comment

begin_struct
struct|struct
name|ida_drive_status
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int32_t
name|failure_map
decl_stmt|;
name|u_int16_t
name|read_err
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|write_error
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|reserved0
index|[
literal|288
index|]
decl_stmt|;
name|u_int32_t
name|secrecover
decl_stmt|;
name|u_int8_t
name|rebuilding
decl_stmt|;
name|u_int16_t
name|remap_cnt
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|repl_map
decl_stmt|;
name|u_int32_t
name|spare_map
decl_stmt|;
name|u_int8_t
name|spare_status
decl_stmt|;
name|u_int8_t
name|spare_repl_map
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|repl_ok_map
decl_stmt|;
name|u_int8_t
name|media_exchange
decl_stmt|;
name|u_int8_t
name|cache_failure
decl_stmt|;
name|u_int8_t
name|expand_failure
decl_stmt|;
name|u_int8_t
name|unit_flags
decl_stmt|;
name|u_int16_t
name|big_failure_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|big_remap_cnt
index|[
literal|128
index|]
decl_stmt|;
name|u_int16_t
name|big_repl_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|big_act_spare_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_spare_repl_map
index|[
literal|128
index|]
decl_stmt|;
name|u_int16_t
name|big_repl_ok_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_rebuilding
decl_stmt|;
name|u_int8_t
name|reserved1
index|[
literal|36
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_GET_PHYS_DRV_INFO (0x15)  * Identify Physical Drive  */
end_comment

begin_struct
struct|struct
name|ida_phys_drv_info
block|{
name|u_int8_t
name|scsi_bus
decl_stmt|;
comment|/* SCSI Bus */
name|u_int8_t
name|scsi_id
decl_stmt|;
comment|/* SCSI ID */
name|u_int16_t
name|blksize
decl_stmt|;
comment|/* block size in bytes */
name|u_int32_t
name|blkcount
decl_stmt|;
comment|/* total blocks */
name|u_int32_t
name|blkreserved
decl_stmt|;
comment|/* reserved blocks */
name|u_int8_t
name|drv_model
index|[
literal|40
index|]
decl_stmt|;
comment|/* drive model */
name|u_int8_t
name|drv_serial
index|[
literal|40
index|]
decl_stmt|;
comment|/* drive serial number */
name|u_int8_t
name|drv_fwrev
index|[
literal|8
index|]
decl_stmt|;
comment|/* drive firmware revision */
name|u_int8_t
name|scsi_inq
decl_stmt|;
comment|/* SCSI inquiry bits */
name|u_int8_t
name|cpq_drv_stmp
decl_stmt|;
name|u_int8_t
name|last_fail
decl_stmt|;
name|u_int8_t
name|pd_flags
decl_stmt|;
comment|/* physical drive flags */
define|#
directive|define
name|PDF_DISK_PRESENT
value|0x01
define|#
directive|define
name|PDF_NONDISK_PRESENT
value|0x02
define|#
directive|define
name|PDF_WIDE_ENABLED
value|0x04
define|#
directive|define
name|PDF_SYNC
value|0x08
define|#
directive|define
name|PDF_NARROW_TRAY
value|0x10
define|#
directive|define
name|PDF_WIDEFAIL
value|0x20
define|#
directive|define
name|PDF_ULTRA
value|0x40
define|#
directive|define
name|PDF_ULTRA2
value|0x80
name|u_int8_t
name|mpd_flags
decl_stmt|;
comment|/* more physical drive flags */
define|#
directive|define
name|MPDF_SMART_SUPPORT
value|0x01
comment|/* S.M.A.R.T supported */
define|#
directive|define
name|MPDF_SMART_ERRORS
value|0x02
comment|/* S.M.A.R.T errors recorded */
define|#
directive|define
name|MPDF_SMART_ENABLED
value|0x04
comment|/* S.M.A.R.T predictive failure is enabled */
define|#
directive|define
name|MPDF_SMART_ERR_RESET
value|0x08
comment|/* S.M.A.R.T errors recorded since last reset */
define|#
directive|define
name|MPDF_DRIVE_EXTERNAL
value|0x10
comment|/* Connected to external connector. */
define|#
directive|define
name|MPDF_DRIVE_CONF_LVOL
value|0x20
comment|/* Configured as part of a logical volume */
define|#
directive|define
name|MPDF_DRIVE_CONF_SPARE
value|0x40
comment|/* Configured as a spare */
define|#
directive|define
name|MPDF_DRIVE_WCE
value|0x80
comment|/* Drive WCE set on spinup */
name|u_int8_t
name|scsi_lun
decl_stmt|;
name|u_int8_t
name|ympd_flags
decl_stmt|;
comment|/* yet more physical drive flags */
define|#
directive|define
name|YMPDF_DRIVE_WCE_SET
value|0x40
comment|/* WCE currently set */
define|#
directive|define
name|YMPDF_DRIVE_WCE_CHNG
value|0x80
comment|/* WCE changable */
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int32_t
name|spi_speed_rules
decl_stmt|;
name|u_int8_t
name|phys_con
index|[
literal|2
index|]
decl_stmt|;
comment|/* Physical Connector */
name|u_int8_t
name|phys_box
decl_stmt|;
comment|/* Physical Box on Bus */
name|u_int8_t
name|phys_bay
decl_stmt|;
comment|/* Physical Bay in Box */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_BLINK_DRV_LEDS (0x16)  * Blink Drive Tray LEDs  *  * CMD_SENSE_DRV_LEDS (0x17)  * Sense Blinking Drive Tray LEDs  */
end_comment

begin_struct
struct|struct
name|ida_blink_drv_leds
block|{
name|u_int32_t
name|bd
decl_stmt|;
comment|/* Blink duration (in 10ths sec) */
name|u_int32_t
name|bte
decl_stmt|;
comment|/* Blink time elapsed (sense only) */
name|u_int8_t
name|bse
index|[
literal|256
index|]
decl_stmt|;
comment|/* Blink/seek enable */
name|u_int8_t
name|reserved1
index|[
literal|248
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CMD_LABEL_LOG_DRV (0x57)  * Label Logical Drive  */
end_comment

begin_struct
struct|struct
name|ida_label_logical
block|{
name|u_int32_t
name|ld_id
decl_stmt|;
comment|/* Logical drive identifier */
name|u_int8_t
name|ld_label
index|[
literal|64
index|]
decl_stmt|;
comment|/* Logical drive label */
block|}
name|__packed
struct|;
end_struct

end_unit

