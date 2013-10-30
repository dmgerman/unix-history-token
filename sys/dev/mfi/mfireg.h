begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 LSI Corp.  * Copyright (c) 2007 Rajesh Prabhakaran.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MFIREG_H
end_ifndef

begin_define
define|#
directive|define
name|_MFIREG_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * MegaRAID SAS MFI firmware definitions  *  * Calling this driver 'MegaRAID SAS' is a bit misleading.  It's a completely  * new firmware interface from the old AMI MegaRAID one, and there is no  * reason why this interface should be limited to just SAS.  In any case, LSI  * seems to also call this interface 'MFI', so that will be used here.  */
end_comment

begin_define
define|#
directive|define
name|MEGAMFI_FRAME_SIZE
value|64
end_define

begin_comment
comment|/*  * Start with the register set.  All registers are 32 bits wide.  * The usual Intel IOP style setup.  */
end_comment

begin_define
define|#
directive|define
name|MFI_IMSG0
value|0x10
end_define

begin_comment
comment|/* Inbound message 0 */
end_comment

begin_define
define|#
directive|define
name|MFI_IMSG1
value|0x14
end_define

begin_comment
comment|/* Inbound message 1 */
end_comment

begin_define
define|#
directive|define
name|MFI_OMSG0
value|0x18
end_define

begin_comment
comment|/* Outbound message 0 */
end_comment

begin_define
define|#
directive|define
name|MFI_OMSG1
value|0x1c
end_define

begin_comment
comment|/* Outbound message 1 */
end_comment

begin_define
define|#
directive|define
name|MFI_IDB
value|0x20
end_define

begin_comment
comment|/* Inbound doorbell */
end_comment

begin_define
define|#
directive|define
name|MFI_ISTS
value|0x24
end_define

begin_comment
comment|/* Inbound interrupt status */
end_comment

begin_define
define|#
directive|define
name|MFI_IMSK
value|0x28
end_define

begin_comment
comment|/* Inbound interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MFI_ODB
value|0x2c
end_define

begin_comment
comment|/* Outbound doorbell */
end_comment

begin_define
define|#
directive|define
name|MFI_OSTS
value|0x30
end_define

begin_comment
comment|/* Outbound interrupt status */
end_comment

begin_define
define|#
directive|define
name|MFI_OMSK
value|0x34
end_define

begin_comment
comment|/* Outbound interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MFI_IQP
value|0x40
end_define

begin_comment
comment|/* Inbound queue port */
end_comment

begin_define
define|#
directive|define
name|MFI_OQP
value|0x44
end_define

begin_comment
comment|/* Outbound queue port */
end_comment

begin_comment
comment|/* *  ThunderBolt specific Register */
end_comment

begin_define
define|#
directive|define
name|MFI_RFPI
value|0x48
end_define

begin_comment
comment|/* reply_free_post_host_index */
end_comment

begin_define
define|#
directive|define
name|MFI_RPI
value|0x6c
end_define

begin_comment
comment|/* reply_post_host_index */
end_comment

begin_define
define|#
directive|define
name|MFI_ILQP
value|0xc0
end_define

begin_comment
comment|/* inbound_low_queue_port */
end_comment

begin_define
define|#
directive|define
name|MFI_IHQP
value|0xc4
end_define

begin_comment
comment|/* inbound_high_queue_port */
end_comment

begin_comment
comment|/*  * 1078 specific related register  */
end_comment

begin_define
define|#
directive|define
name|MFI_ODR0
value|0x9c
end_define

begin_comment
comment|/* outbound doorbell register0 */
end_comment

begin_define
define|#
directive|define
name|MFI_ODCR0
value|0xa0
end_define

begin_comment
comment|/* outbound doorbell clear register0  */
end_comment

begin_define
define|#
directive|define
name|MFI_OSP0
value|0xb0
end_define

begin_comment
comment|/* outbound scratch pad0  */
end_comment

begin_define
define|#
directive|define
name|MFI_1078_EIM
value|0x80000004
end_define

begin_comment
comment|/* 1078 enable intrrupt mask  */
end_comment

begin_define
define|#
directive|define
name|MFI_RMI
value|0x2
end_define

begin_comment
comment|/* reply message interrupt  */
end_comment

begin_define
define|#
directive|define
name|MFI_1078_RM
value|0x80000000
end_define

begin_comment
comment|/* reply 1078 message interrupt  */
end_comment

begin_define
define|#
directive|define
name|MFI_ODC
value|0x4
end_define

begin_comment
comment|/* outbound doorbell change interrupt */
end_comment

begin_comment
comment|/* OCR registers */
end_comment

begin_define
define|#
directive|define
name|MFI_WSR
value|0x004
end_define

begin_comment
comment|/* write sequence register */
end_comment

begin_define
define|#
directive|define
name|MFI_HDR
value|0x008
end_define

begin_comment
comment|/* host diagnostic register */
end_comment

begin_define
define|#
directive|define
name|MFI_RSR
value|0x3c3
end_define

begin_comment
comment|/* Reset Status Register */
end_comment

begin_comment
comment|/*  * GEN2 specific changes  */
end_comment

begin_define
define|#
directive|define
name|MFI_GEN2_EIM
value|0x00000005
end_define

begin_comment
comment|/* GEN2 enable interrupt mask */
end_comment

begin_define
define|#
directive|define
name|MFI_GEN2_RM
value|0x00000001
end_define

begin_comment
comment|/* reply GEN2 message interrupt */
end_comment

begin_comment
comment|/*  * skinny specific changes  */
end_comment

begin_define
define|#
directive|define
name|MFI_SKINNY_IDB
value|0x00
end_define

begin_comment
comment|/* Inbound doorbell is at 0x00 for skinny */
end_comment

begin_define
define|#
directive|define
name|MFI_IQPL
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|MFI_IQPH
value|0x000000c4
end_define

begin_define
define|#
directive|define
name|MFI_SKINNY_RM
value|0x00000001
end_define

begin_comment
comment|/* reply skinny message interrupt */
end_comment

begin_comment
comment|/* Bits for MFI_OSTS */
end_comment

begin_define
define|#
directive|define
name|MFI_OSTS_INTR_VALID
value|0x00000002
end_define

begin_comment
comment|/* OCR specific flags */
end_comment

begin_define
define|#
directive|define
name|MFI_FIRMWARE_STATE_CHANGE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MFI_STATE_CHANGE_INTERRUPT
value|0x00000004
end_define

begin_comment
comment|/* MFI state change interrrupt */
end_comment

begin_comment
comment|/*  * Firmware state values.  Found in OMSG0 during initialization.  */
end_comment

begin_define
define|#
directive|define
name|MFI_FWSTATE_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_UNDEFINED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_BB_INIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_FW_INIT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_WAIT_HANDSHAKE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_FW_INIT_2
value|0x70000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_DEVICE_SCAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_BOOT_MESSAGE_PENDING
value|0x90000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_FLUSH_CACHE
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_READY
value|0xb0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_OPERATIONAL
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_FAULT
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_MAXSGL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_MAXCMD_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_HOSTMEMREQD_MASK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_BOOT_MESSAGE_PENDING
value|0x90000000
end_define

begin_define
define|#
directive|define
name|MFI_RESET_REQUIRED
value|0x00000001
end_define

begin_comment
comment|/* ThunderBolt Support */
end_comment

begin_define
define|#
directive|define
name|MFI_FWSTATE_TB_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_TB_RESET
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_TB_READY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_TB_OPERATIONAL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MFI_FWSTATE_TB_FAULT
value|0x40000000
end_define

begin_comment
comment|/*  * Control bits to drive the card to ready state.  These go into the IDB  * register.  */
end_comment

begin_define
define|#
directive|define
name|MFI_FWINIT_ABORT
value|0x00000000
end_define

begin_comment
comment|/* Abort all pending commands */
end_comment

begin_define
define|#
directive|define
name|MFI_FWINIT_READY
value|0x00000002
end_define

begin_comment
comment|/* Move from operational to ready */
end_comment

begin_define
define|#
directive|define
name|MFI_FWINIT_MFIMODE
value|0x00000004
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|MFI_FWINIT_CLEAR_HANDSHAKE
value|0x00000008
end_define

begin_comment
comment|/* Respond to WAIT_HANDSHAKE */
end_comment

begin_define
define|#
directive|define
name|MFI_FWINIT_HOTPLUG
value|0x00000010
end_define

begin_comment
comment|/* ADP reset flags */
end_comment

begin_define
define|#
directive|define
name|MFI_STOP_ADP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MFI_ADP_RESET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DIAG_WRITE_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DIAG_RESET_ADAPTER
value|0x00000004
end_define

begin_comment
comment|/* MFI Commands */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MFI_CMD_INIT
init|=
literal|0x00
block|,
name|MFI_CMD_LD_READ
block|,
name|MFI_CMD_LD_WRITE
block|,
name|MFI_CMD_LD_SCSI_IO
block|,
name|MFI_CMD_PD_SCSI_IO
block|,
name|MFI_CMD_DCMD
block|,
name|MFI_CMD_ABORT
block|,
name|MFI_CMD_SMP
block|,
name|MFI_CMD_STP
block|}
name|mfi_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* Direct commands */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MFI_DCMD_CTRL_GETINFO
init|=
literal|0x01010000
block|,
name|MFI_DCMD_CTRL_MFI_HOST_MEM_ALLOC
init|=
literal|0x0100e100
block|,
name|MFI_DCMD_CTRL_MFC_DEFAULTS_GET
init|=
literal|0x010e0201
block|,
name|MFI_DCMD_CTRL_MFC_DEFAULTS_SET
init|=
literal|0x010e0202
block|,
name|MFI_DCMD_CTRL_FLUSHCACHE
init|=
literal|0x01101000
block|,
name|MFI_DCMD_CTRL_GET_PROPS
init|=
literal|0x01020100
block|,
name|MFI_DCMD_CTRL_SET_PROPS
init|=
literal|0x01020200
block|,
name|MFI_DCMD_CTRL_SHUTDOWN
init|=
literal|0x01050000
block|,
name|MFI_DCMD_CTRL_EVENT_GETINFO
init|=
literal|0x01040100
block|,
name|MFI_DCMD_CTRL_EVENT_GET
init|=
literal|0x01040300
block|,
name|MFI_DCMD_CTRL_EVENT_WAIT
init|=
literal|0x01040500
block|,
name|MFI_DCMD_PR_GET_STATUS
init|=
literal|0x01070100
block|,
name|MFI_DCMD_PR_GET_PROPERTIES
init|=
literal|0x01070200
block|,
name|MFI_DCMD_PR_SET_PROPERTIES
init|=
literal|0x01070300
block|,
name|MFI_DCMD_PR_START
init|=
literal|0x01070400
block|,
name|MFI_DCMD_PR_STOP
init|=
literal|0x01070500
block|,
name|MFI_DCMD_TIME_SECS_GET
init|=
literal|0x01080201
block|,
name|MFI_DCMD_FLASH_FW_OPEN
init|=
literal|0x010f0100
block|,
name|MFI_DCMD_FLASH_FW_DOWNLOAD
init|=
literal|0x010f0200
block|,
name|MFI_DCMD_FLASH_FW_FLASH
init|=
literal|0x010f0300
block|,
name|MFI_DCMD_FLASH_FW_CLOSE
init|=
literal|0x010f0400
block|,
name|MFI_DCMD_PD_GET_LIST
init|=
literal|0x02010000
block|,
name|MFI_DCMD_PD_LIST_QUERY
init|=
literal|0x02010100
block|,
name|MFI_DCMD_PD_GET_INFO
init|=
literal|0x02020000
block|,
name|MFI_DCMD_PD_STATE_SET
init|=
literal|0x02030100
block|,
name|MFI_DCMD_PD_REBUILD_START
init|=
literal|0x02040100
block|,
name|MFI_DCMD_PD_REBUILD_ABORT
init|=
literal|0x02040200
block|,
name|MFI_DCMD_PD_CLEAR_START
init|=
literal|0x02050100
block|,
name|MFI_DCMD_PD_CLEAR_ABORT
init|=
literal|0x02050200
block|,
name|MFI_DCMD_PD_GET_PROGRESS
init|=
literal|0x02060000
block|,
name|MFI_DCMD_PD_LOCATE_START
init|=
literal|0x02070100
block|,
name|MFI_DCMD_PD_LOCATE_STOP
init|=
literal|0x02070200
block|,
name|MFI_DCMD_LD_MAP_GET_INFO
init|=
literal|0x0300e101
block|,
name|MFI_DCMD_LD_SYNC
init|=
literal|0x0300e102
block|,
name|MFI_DCMD_LD_GET_LIST
init|=
literal|0x03010000
block|,
name|MFI_DCMD_LD_GET_INFO
init|=
literal|0x03020000
block|,
name|MFI_DCMD_LD_GET_PROP
init|=
literal|0x03030000
block|,
name|MFI_DCMD_LD_SET_PROP
init|=
literal|0x03040000
block|,
name|MFI_DCMD_LD_INIT_START
init|=
literal|0x03060100
block|,
name|MFI_DCMD_LD_DELETE
init|=
literal|0x03090000
block|,
name|MFI_DCMD_CFG_READ
init|=
literal|0x04010000
block|,
name|MFI_DCMD_CFG_ADD
init|=
literal|0x04020000
block|,
name|MFI_DCMD_CFG_CLEAR
init|=
literal|0x04030000
block|,
name|MFI_DCMD_CFG_MAKE_SPARE
init|=
literal|0x04040000
block|,
name|MFI_DCMD_CFG_REMOVE_SPARE
init|=
literal|0x04050000
block|,
name|MFI_DCMD_CFG_FOREIGN_SCAN
init|=
literal|0x04060100
block|,
name|MFI_DCMD_CFG_FOREIGN_DISPLAY
init|=
literal|0x04060200
block|,
name|MFI_DCMD_CFG_FOREIGN_PREVIEW
init|=
literal|0x04060300
block|,
name|MFI_DCMD_CFG_FOREIGN_IMPORT
init|=
literal|0x04060400
block|,
name|MFI_DCMD_CFG_FOREIGN_CLEAR
init|=
literal|0x04060500
block|,
name|MFI_DCMD_BBU_GET_STATUS
init|=
literal|0x05010000
block|,
name|MFI_DCMD_BBU_GET_CAPACITY_INFO
init|=
literal|0x05020000
block|,
name|MFI_DCMD_BBU_GET_DESIGN_INFO
init|=
literal|0x05030000
block|,
name|MFI_DCMD_BBU_START_LEARN
init|=
literal|0x05040000
block|,
name|MFI_DCMD_BBU_GET_PROP
init|=
literal|0x05050100
block|,
name|MFI_DCMD_BBU_SET_PROP
init|=
literal|0x05050200
block|,
name|MFI_DCMD_CLUSTER
init|=
literal|0x08000000
block|,
name|MFI_DCMD_CLUSTER_RESET_ALL
init|=
literal|0x08010100
block|,
name|MFI_DCMD_CLUSTER_RESET_LD
init|=
literal|0x08010200
block|}
name|mfi_dcmd_t
typedef|;
end_typedef

begin_comment
comment|/* Modifiers for MFI_DCMD_CTRL_FLUSHCACHE */
end_comment

begin_define
define|#
directive|define
name|MFI_FLUSHCACHE_CTRL
value|0x01
end_define

begin_define
define|#
directive|define
name|MFI_FLUSHCACHE_DISK
value|0x02
end_define

begin_comment
comment|/* Modifiers for MFI_DCMD_CTRL_SHUTDOWN */
end_comment

begin_define
define|#
directive|define
name|MFI_SHUTDOWN_SPINDOWN
value|0x01
end_define

begin_comment
comment|/*  * MFI Frame flags  */
end_comment

begin_define
define|#
directive|define
name|MFI_FRAME_POST_IN_REPLY_QUEUE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DONT_POST_IN_REPLY_QUEUE
value|0x0001
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SGL32
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SGL64
value|0x0002
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SENSE32
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SENSE64
value|0x0004
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_WRITE
value|0x0008
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_READ
value|0x0010
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_DIR_BOTH
value|0x0018
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_IEEE_SGL
value|0x0020
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_FMT
value|"\20" \     "\1NOPOST" \     "\2SGL64" \     "\3SENSE64" \     "\4WRITE" \     "\5READ" \     "\6IEEESGL"
end_define

begin_comment
comment|/* ThunderBolt Specific */
end_comment

begin_comment
comment|/*  * Pre-TB command size and TB command size.  * We will be checking it at the load time for the time being  */
end_comment

begin_define
define|#
directive|define
name|MR_COMMAND_SIZE
value|(MFI_FRAME_SIZE*20)
end_define

begin_comment
comment|/* 1280 bytes */
end_comment

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_MSG_ALLIGNMENT
value|256
end_define

begin_comment
comment|/*  * We are defining only 128 byte message to reduce memory move over head  * and also it will reduce the SRB extension size by 128byte compared with  * 256 message size  */
end_comment

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_NEW_MSG_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_MAX_COMMANDS
value|1024
end_define

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_MAX_REPLY_COUNT
value|1024
end_define

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_REPLY_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MEGASAS_THUNDERBOLT_MAX_CHAIN_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|MEGASAS_MAX_SZ_CHAIN_FRAME
value|1024
end_define

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PASSTHRU_IO_REQUEST
value|0xF0
end_define

begin_define
define|#
directive|define
name|MPI2_FUNCTION_LD_IO_REQUEST
value|0xF1
end_define

begin_define
define|#
directive|define
name|MR_INTERNAL_MFI_FRAMES_SMID
value|1
end_define

begin_define
define|#
directive|define
name|MR_CTRL_EVENT_WAIT_SMID
value|2
end_define

begin_define
define|#
directive|define
name|MR_INTERNAL_DRIVER_RESET_SMID
value|3
end_define

begin_comment
comment|/* MFI Status codes */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MFI_STAT_OK
init|=
literal|0x00
block|,
name|MFI_STAT_INVALID_CMD
block|,
name|MFI_STAT_INVALID_DCMD
block|,
name|MFI_STAT_INVALID_PARAMETER
block|,
name|MFI_STAT_INVALID_SEQUENCE_NUMBER
block|,
name|MFI_STAT_ABORT_NOT_POSSIBLE
block|,
name|MFI_STAT_APP_HOST_CODE_NOT_FOUND
block|,
name|MFI_STAT_APP_IN_USE
block|,
name|MFI_STAT_APP_NOT_INITIALIZED
block|,
name|MFI_STAT_ARRAY_INDEX_INVALID
block|,
name|MFI_STAT_ARRAY_ROW_NOT_EMPTY
block|,
name|MFI_STAT_CONFIG_RESOURCE_CONFLICT
block|,
name|MFI_STAT_DEVICE_NOT_FOUND
block|,
name|MFI_STAT_DRIVE_TOO_SMALL
block|,
name|MFI_STAT_FLASH_ALLOC_FAIL
block|,
name|MFI_STAT_FLASH_BUSY
block|,
name|MFI_STAT_FLASH_ERROR
init|=
literal|0x10
block|,
name|MFI_STAT_FLASH_IMAGE_BAD
block|,
name|MFI_STAT_FLASH_IMAGE_INCOMPLETE
block|,
name|MFI_STAT_FLASH_NOT_OPEN
block|,
name|MFI_STAT_FLASH_NOT_STARTED
block|,
name|MFI_STAT_FLUSH_FAILED
block|,
name|MFI_STAT_HOST_CODE_NOT_FOUNT
block|,
name|MFI_STAT_LD_CC_IN_PROGRESS
block|,
name|MFI_STAT_LD_INIT_IN_PROGRESS
block|,
name|MFI_STAT_LD_LBA_OUT_OF_RANGE
block|,
name|MFI_STAT_LD_MAX_CONFIGURED
block|,
name|MFI_STAT_LD_NOT_OPTIMAL
block|,
name|MFI_STAT_LD_RBLD_IN_PROGRESS
block|,
name|MFI_STAT_LD_RECON_IN_PROGRESS
block|,
name|MFI_STAT_LD_WRONG_RAID_LEVEL
block|,
name|MFI_STAT_MAX_SPARES_EXCEEDED
block|,
name|MFI_STAT_MEMORY_NOT_AVAILABLE
init|=
literal|0x20
block|,
name|MFI_STAT_MFC_HW_ERROR
block|,
name|MFI_STAT_NO_HW_PRESENT
block|,
name|MFI_STAT_NOT_FOUND
block|,
name|MFI_STAT_NOT_IN_ENCL
block|,
name|MFI_STAT_PD_CLEAR_IN_PROGRESS
block|,
name|MFI_STAT_PD_TYPE_WRONG
block|,
name|MFI_STAT_PR_DISABLED
block|,
name|MFI_STAT_ROW_INDEX_INVALID
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_ACTION
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_DATA
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_PAGE
block|,
name|MFI_STAT_SAS_CONFIG_INVALID_TYPE
block|,
name|MFI_STAT_SCSI_DONE_WITH_ERROR
block|,
name|MFI_STAT_SCSI_IO_FAILED
block|,
name|MFI_STAT_SCSI_RESERVATION_CONFLICT
block|,
name|MFI_STAT_SHUTDOWN_FAILED
init|=
literal|0x30
block|,
name|MFI_STAT_TIME_NOT_SET
block|,
name|MFI_STAT_WRONG_STATE
block|,
name|MFI_STAT_LD_OFFLINE
block|,
name|MFI_STAT_PEER_NOTIFICATION_REJECTED
block|,
name|MFI_STAT_PEER_NOTIFICATION_FAILED
block|,
name|MFI_STAT_RESERVATION_IN_PROGRESS
block|,
name|MFI_STAT_I2C_ERRORS_DETECTED
block|,
name|MFI_STAT_PCI_ERRORS_DETECTED
block|,
name|MFI_STAT_DIAG_FAILED
block|,
name|MFI_STAT_BOOT_MSG_PENDING
block|,
name|MFI_STAT_FOREIGN_CONFIG_INCOMPLETE
block|,
name|MFI_STAT_INVALID_STATUS
init|=
literal|0xFF
block|}
name|mfi_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MFI_EVT_CLASS_DEBUG
init|=
operator|-
literal|2
block|,
name|MFI_EVT_CLASS_PROGRESS
init|=
operator|-
literal|1
block|,
name|MFI_EVT_CLASS_INFO
init|=
literal|0
block|,
name|MFI_EVT_CLASS_WARNING
init|=
literal|1
block|,
name|MFI_EVT_CLASS_CRITICAL
init|=
literal|2
block|,
name|MFI_EVT_CLASS_FATAL
init|=
literal|3
block|,
name|MFI_EVT_CLASS_DEAD
init|=
literal|4
block|}
name|mfi_evt_class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MFI_EVT_LOCALE_LD
init|=
literal|0x0001
block|,
name|MFI_EVT_LOCALE_PD
init|=
literal|0x0002
block|,
name|MFI_EVT_LOCALE_ENCL
init|=
literal|0x0004
block|,
name|MFI_EVT_LOCALE_BBU
init|=
literal|0x0008
block|,
name|MFI_EVT_LOCALE_SAS
init|=
literal|0x0010
block|,
name|MFI_EVT_LOCALE_CTRL
init|=
literal|0x0020
block|,
name|MFI_EVT_LOCALE_CONFIG
init|=
literal|0x0040
block|,
name|MFI_EVT_LOCALE_CLUSTER
init|=
literal|0x0080
block|,
name|MFI_EVT_LOCALE_ALL
init|=
literal|0xffff
block|}
name|mfi_evt_locale_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MR_EVT_ARGS_NONE
init|=
literal|0x00
block|,
name|MR_EVT_ARGS_CDB_SENSE
block|,
name|MR_EVT_ARGS_LD
block|,
name|MR_EVT_ARGS_LD_COUNT
block|,
name|MR_EVT_ARGS_LD_LBA
block|,
name|MR_EVT_ARGS_LD_OWNER
block|,
name|MR_EVT_ARGS_LD_LBA_PD_LBA
block|,
name|MR_EVT_ARGS_LD_PROG
block|,
name|MR_EVT_ARGS_LD_STATE
block|,
name|MR_EVT_ARGS_LD_STRIP
block|,
name|MR_EVT_ARGS_PD
block|,
name|MR_EVT_ARGS_PD_ERR
block|,
name|MR_EVT_ARGS_PD_LBA
block|,
name|MR_EVT_ARGS_PD_LBA_LD
block|,
name|MR_EVT_ARGS_PD_PROG
block|,
name|MR_EVT_ARGS_PD_STATE
block|,
name|MR_EVT_ARGS_PCI
block|,
name|MR_EVT_ARGS_RATE
block|,
name|MR_EVT_ARGS_STR
block|,
name|MR_EVT_ARGS_TIME
block|,
name|MR_EVT_ARGS_ECC
block|}
name|mfi_evt_args
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MR_EVT_CTRL_HOST_BUS_SCAN_REQUESTED
value|0x0152
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_REMOVED
value|0x0070
end_define

begin_define
define|#
directive|define
name|MR_EVT_PD_INSERTED
value|0x005b
end_define

begin_define
define|#
directive|define
name|MR_EVT_LD_CHANGE
value|0x0051
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|MR_LD_CACHE_WRITE_BACK
init|=
literal|0x01
block|,
name|MR_LD_CACHE_WRITE_ADAPTIVE
init|=
literal|0x02
block|,
name|MR_LD_CACHE_READ_AHEAD
init|=
literal|0x04
block|,
name|MR_LD_CACHE_READ_ADAPTIVE
init|=
literal|0x08
block|,
name|MR_LD_CACHE_WRITE_CACHE_BAD_BBU
init|=
literal|0x10
block|,
name|MR_LD_CACHE_ALLOW_WRITE_CACHE
init|=
literal|0x20
block|,
name|MR_LD_CACHE_ALLOW_READ_CACHE
init|=
literal|0x40
block|}
name|mfi_ld_cache
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MR_LD_CACHE_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_READ_AHEAD_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_READ_AHEAD_ALWAYS
value|MR_LD_CACHE_READ_AHEAD
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_READ_AHEAD_ADAPTIVE
define|\
value|(MR_LD_CACHE_READ_AHEAD | MR_LD_CACHE_READ_ADAPTIVE)
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_WRITE_THROUGH
value|0
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_WRITE_BACK
value|MR_LD_CACHE_WRITE_BACK
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_IO_CACHED
define|\
value|(MR_LD_CACHE_ALLOW_WRITE_CACHE | MR_LD_CACHE_ALLOW_READ_CACHE)
end_define

begin_define
define|#
directive|define
name|MR_LD_CACHE_POLICY_IO_DIRECT
value|0
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|MR_PD_CACHE_UNCHANGED
init|=
literal|0
block|,
name|MR_PD_CACHE_ENABLE
init|=
literal|1
block|,
name|MR_PD_CACHE_DISABLE
init|=
literal|2
block|}
name|mfi_pd_cache
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MR_PD_QUERY_TYPE_ALL
init|=
literal|0
block|,
name|MR_PD_QUERY_TYPE_STATE
init|=
literal|1
block|,
name|MR_PD_QUERY_TYPE_POWER_STATE
init|=
literal|2
block|,
name|MR_PD_QUERY_TYPE_MEDIA_TYPE
init|=
literal|3
block|,
name|MR_PD_QUERY_TYPE_SPEED
init|=
literal|4
block|,
name|MR_PD_QUERY_TYPE_EXPOSED_TO_HOST
init|=
literal|5
comment|/*query for system drives */
block|}
name|mfi_pd_query_type
typedef|;
end_typedef

begin_comment
comment|/*  * Other propertities and definitions  */
end_comment

begin_define
define|#
directive|define
name|MFI_MAX_PD_CHANNELS
value|2
end_define

begin_define
define|#
directive|define
name|MFI_MAX_LD_CHANNELS
value|2
end_define

begin_define
define|#
directive|define
name|MFI_MAX_CHANNELS
value|(MFI_MAX_PD_CHANNELS + MFI_MAX_LD_CHANNELS)
end_define

begin_define
define|#
directive|define
name|MFI_MAX_CHANNEL_DEVS
value|128
end_define

begin_define
define|#
directive|define
name|MFI_DEFAULT_ID
value|-1
end_define

begin_define
define|#
directive|define
name|MFI_MAX_LUN
value|8
end_define

begin_define
define|#
directive|define
name|MFI_MAX_LD
value|64
end_define

begin_define
define|#
directive|define
name|MFI_MAX_PD
value|256
end_define

begin_define
define|#
directive|define
name|MFI_FRAME_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|MFI_MBOX_SIZE
value|12
end_define

begin_comment
comment|/* Firmware flashing can take 50+ seconds */
end_comment

begin_define
define|#
directive|define
name|MFI_POLL_TIMEOUT_SECS
value|60
end_define

begin_comment
comment|/* Allow for speedier math calculations */
end_comment

begin_define
define|#
directive|define
name|MFI_SECTOR_LEN
value|512
end_define

begin_comment
comment|/* Scatter Gather elements */
end_comment

begin_struct
struct|struct
name|mfi_sg32
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_sg64
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_sg_skinny
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|flag
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|mfi_sgl
block|{
name|struct
name|mfi_sg32
name|sg32
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|mfi_sg64
name|sg64
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|mfi_sg_skinny
name|sg_skinny
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_comment
comment|/* Message frames.  All messages have a common header */
end_comment

begin_struct
struct|struct
name|mfi_frame_header
block|{
name|uint8_t
name|cmd
decl_stmt|;
name|uint8_t
name|sense_len
decl_stmt|;
name|uint8_t
name|cmd_status
decl_stmt|;
name|uint8_t
name|scsi_status
decl_stmt|;
name|uint8_t
name|target_id
decl_stmt|;
name|uint8_t
name|lun_id
decl_stmt|;
name|uint8_t
name|cdb_len
decl_stmt|;
name|uint8_t
name|sg_count
decl_stmt|;
name|uint32_t
name|context
decl_stmt|;
comment|/* 	 * pad0 is MSI Specific. Not used by Driver. Zero the value before 	 * sending the command to f/w. 	 */
name|uint32_t
name|pad0
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|MFI_FRAME_DATAOUT
value|0x08
define|#
directive|define
name|MFI_FRAME_DATAIN
value|0x10
name|uint16_t
name|timeout
decl_stmt|;
name|uint32_t
name|data_len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_init_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint32_t
name|qinfo_new_addr_lo
decl_stmt|;
name|uint32_t
name|qinfo_new_addr_hi
decl_stmt|;
name|uint32_t
name|qinfo_old_addr_lo
decl_stmt|;
name|uint32_t
name|qinfo_old_addr_hi
decl_stmt|;
comment|// Start LSIP200113393
name|uint32_t
name|driver_ver_lo
decl_stmt|;
comment|/*28h */
name|uint32_t
name|driver_ver_hi
decl_stmt|;
comment|/*2Ch */
name|uint32_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
comment|// End LSIP200113393
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Define MFI Address Context union.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MFI_ADDRESS_IS_uint64_t
end_ifdef

begin_typedef
typedef|typedef
name|uint64_t
name|MFI_ADDRESS
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
union|union
name|_MFI_ADDRESS
block|{
struct|struct
block|{
name|uint32_t
name|addressLow
decl_stmt|;
name|uint32_t
name|addressHigh
decl_stmt|;
block|}
name|u
struct|;
name|uint64_t
name|address
decl_stmt|;
block|}
name|MFI_ADDRESS
operator|,
typedef|*
name|PMFI_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MFI_IO_FRAME_SIZE
value|40
end_define

begin_struct
struct|struct
name|mfi_io_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint32_t
name|sense_addr_lo
decl_stmt|;
name|uint32_t
name|sense_addr_hi
decl_stmt|;
name|uint32_t
name|lba_lo
decl_stmt|;
name|uint32_t
name|lba_hi
decl_stmt|;
name|union
name|mfi_sgl
name|sgl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_PASS_FRAME_SIZE
value|48
end_define

begin_struct
struct|struct
name|mfi_pass_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint32_t
name|sense_addr_lo
decl_stmt|;
name|uint32_t
name|sense_addr_hi
decl_stmt|;
name|uint8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|union
name|mfi_sgl
name|sgl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_DCMD_FRAME_SIZE
value|40
end_define

begin_struct
struct|struct
name|mfi_dcmd_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint32_t
name|opcode
decl_stmt|;
name|uint8_t
name|mbox
index|[
name|MFI_MBOX_SIZE
index|]
decl_stmt|;
name|union
name|mfi_sgl
name|sgl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_abort_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint32_t
name|abort_context
decl_stmt|;
comment|/* pad is changed to reserved.*/
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|abort_mfi_addr_lo
decl_stmt|;
name|uint32_t
name|abort_mfi_addr_hi
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_smp_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint64_t
name|sas_addr
decl_stmt|;
union|union
block|{
name|struct
name|mfi_sg32
name|sg32
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|mfi_sg64
name|sg64
index|[
literal|2
index|]
decl_stmt|;
block|}
name|sgl
union|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_stp_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|uint16_t
name|fis
index|[
literal|10
index|]
decl_stmt|;
name|uint32_t
name|stp_flags
decl_stmt|;
union|union
block|{
name|struct
name|mfi_sg32
name|sg32
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|mfi_sg64
name|sg64
index|[
literal|2
index|]
decl_stmt|;
block|}
name|sgl
union|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|mfi_frame
block|{
name|struct
name|mfi_frame_header
name|header
decl_stmt|;
name|struct
name|mfi_init_frame
name|init
decl_stmt|;
comment|/* ThunderBolt Initialization */
name|struct
name|mfi_io_frame
name|io
decl_stmt|;
name|struct
name|mfi_pass_frame
name|pass
decl_stmt|;
name|struct
name|mfi_dcmd_frame
name|dcmd
decl_stmt|;
name|struct
name|mfi_abort_frame
name|abort
decl_stmt|;
name|struct
name|mfi_smp_frame
name|smp
decl_stmt|;
name|struct
name|mfi_stp_frame
name|stp
decl_stmt|;
name|uint8_t
name|bytes
index|[
name|MFI_FRAME_SIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|MFI_SENSE_LEN
value|128
end_define

begin_struct
struct|struct
name|mfi_sense
block|{
name|uint8_t
name|data
index|[
name|MFI_SENSE_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The queue init structure that is passed with the init message */
end_comment

begin_struct
struct|struct
name|mfi_init_qinfo
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|rq_entries
decl_stmt|;
name|uint32_t
name|rq_addr_lo
decl_stmt|;
name|uint32_t
name|rq_addr_hi
decl_stmt|;
name|uint32_t
name|pi_addr_lo
decl_stmt|;
name|uint32_t
name|pi_addr_hi
decl_stmt|;
name|uint32_t
name|ci_addr_lo
decl_stmt|;
name|uint32_t
name|ci_addr_hi
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SAS (?) controller properties, part of mfi_ctrl_info */
end_comment

begin_struct
struct|struct
name|mfi_ctrl_props
block|{
name|uint16_t
name|seq_num
decl_stmt|;
name|uint16_t
name|pred_fail_poll_interval
decl_stmt|;
name|uint16_t
name|intr_throttle_cnt
decl_stmt|;
name|uint16_t
name|intr_throttle_timeout
decl_stmt|;
name|uint8_t
name|rebuild_rate
decl_stmt|;
name|uint8_t
name|patrol_read_rate
decl_stmt|;
name|uint8_t
name|bgi_rate
decl_stmt|;
name|uint8_t
name|cc_rate
decl_stmt|;
name|uint8_t
name|recon_rate
decl_stmt|;
name|uint8_t
name|cache_flush_interval
decl_stmt|;
name|uint8_t
name|spinup_drv_cnt
decl_stmt|;
name|uint8_t
name|spinup_delay
decl_stmt|;
name|uint8_t
name|cluster_enable
decl_stmt|;
name|uint8_t
name|coercion_mode
decl_stmt|;
name|uint8_t
name|alarm_enable
decl_stmt|;
name|uint8_t
name|disable_auto_rebuild
decl_stmt|;
name|uint8_t
name|disable_battery_warn
decl_stmt|;
name|uint8_t
name|ecc_bucket_size
decl_stmt|;
name|uint16_t
name|ecc_bucket_leak_rate
decl_stmt|;
name|uint8_t
name|restore_hotspare_on_insertion
decl_stmt|;
name|uint8_t
name|expose_encl_devices
decl_stmt|;
name|uint8_t
name|maintainPdFailHistory
decl_stmt|;
name|uint8_t
name|disallowHostRequestReordering
decl_stmt|;
comment|/* set TRUE to abort CC on detecting an inconsistency */
name|uint8_t
name|abortCCOnError
decl_stmt|;
comment|/* load balance mode (MR_LOAD_BALANCE_MODE) */
name|uint8_t
name|loadBalanceMode
decl_stmt|;
comment|/* 	 * 0 - use auto detect logic of backplanes like SGPIO, i2c SEP using 	 *     h/w mechansim like GPIO pins 	 * 1 - disable auto detect SGPIO, 	 * 2 - disable i2c SEP auto detect 	 * 3 - disable both auto detect 	 */
name|uint8_t
name|disableAutoDetectBackplane
decl_stmt|;
comment|/* 	 * % of source LD to be reserved for a VDs snapshot in snapshot 	 * repository, for metadata and user data: 1=5%, 2=10%, 3=15% and so on 	 */
name|uint8_t
name|snapVDSpace
decl_stmt|;
comment|/* 	 * Add properties that can be controlled by a bit in the following 	 * structure. 	 */
struct|struct
block|{
comment|/* set TRUE to disable copyBack (0=copback enabled) */
name|uint32_t
name|copyBackDisabled
range|:
literal|1
decl_stmt|;
name|uint32_t
name|SMARTerEnabled
range|:
literal|1
decl_stmt|;
name|uint32_t
name|prCorrectUnconfiguredAreas
range|:
literal|1
decl_stmt|;
name|uint32_t
name|useFdeOnly
range|:
literal|1
decl_stmt|;
name|uint32_t
name|disableNCQ
range|:
literal|1
decl_stmt|;
name|uint32_t
name|SSDSMARTerEnabled
range|:
literal|1
decl_stmt|;
name|uint32_t
name|SSDPatrolReadEnabled
range|:
literal|1
decl_stmt|;
name|uint32_t
name|enableSpinDownUnconfigured
range|:
literal|1
decl_stmt|;
name|uint32_t
name|autoEnhancedImport
range|:
literal|1
decl_stmt|;
name|uint32_t
name|enableSecretKeyControl
range|:
literal|1
decl_stmt|;
name|uint32_t
name|disableOnlineCtrlReset
range|:
literal|1
decl_stmt|;
name|uint32_t
name|allowBootWithPinnedCache
range|:
literal|1
decl_stmt|;
name|uint32_t
name|disableSpinDownHS
range|:
literal|1
decl_stmt|;
name|uint32_t
name|enableJBOD
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|18
decl_stmt|;
block|}
name|OnOffProperties
struct|;
comment|/* 	 * % of source LD to be reserved for auto snapshot in snapshot 	 * repository, for metadata and user data: 1=5%, 2=10%, 3=15% and so on. 	 */
name|uint8_t
name|autoSnapVDSpace
decl_stmt|;
comment|/* 	 * Snapshot writeable VIEWs capacity as a % of source LD capacity: 	 * 0=READ only, 1=5%, 2=10%, 3=15% and so on. 	 */
name|uint8_t
name|viewSpace
decl_stmt|;
comment|/* # of idle minutes before device is spun down (0=use FW defaults) */
name|uint16_t
name|spinDownTime
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* PCI information about the card. */
end_comment

begin_struct
struct|struct
name|mfi_info_pci
block|{
name|uint16_t
name|vendor
decl_stmt|;
name|uint16_t
name|device
decl_stmt|;
name|uint16_t
name|subvendor
decl_stmt|;
name|uint16_t
name|subdevice
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Host (front end) interface information */
end_comment

begin_struct
struct|struct
name|mfi_info_host
block|{
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|MFI_INFO_HOST_PCIX
value|0x01
define|#
directive|define
name|MFI_INFO_HOST_PCIE
value|0x02
define|#
directive|define
name|MFI_INFO_HOST_ISCSI
value|0x04
define|#
directive|define
name|MFI_INFO_HOST_SAS3G
value|0x08
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|port_count
decl_stmt|;
name|uint64_t
name|port_addr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Device (back end) interface information */
end_comment

begin_struct
struct|struct
name|mfi_info_device
block|{
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|MFI_INFO_DEV_SPI
value|0x01
define|#
directive|define
name|MFI_INFO_DEV_SAS3G
value|0x02
define|#
directive|define
name|MFI_INFO_DEV_SATA1
value|0x04
define|#
directive|define
name|MFI_INFO_DEV_SATA3G
value|0x08
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|port_count
decl_stmt|;
name|uint64_t
name|port_addr
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Firmware component information */
end_comment

begin_struct
struct|struct
name|mfi_info_component
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|char
name|version
index|[
literal|32
index|]
decl_stmt|;
name|char
name|build_date
index|[
literal|16
index|]
decl_stmt|;
name|char
name|build_time
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Controller default settings */
end_comment

begin_struct
struct|struct
name|mfi_defaults
block|{
name|uint64_t
name|sas_addr
decl_stmt|;
name|uint8_t
name|phy_polarity
decl_stmt|;
name|uint8_t
name|background_rate
decl_stmt|;
name|uint8_t
name|stripe_size
decl_stmt|;
name|uint8_t
name|flush_time
decl_stmt|;
name|uint8_t
name|write_back
decl_stmt|;
name|uint8_t
name|read_ahead
decl_stmt|;
name|uint8_t
name|cache_when_bbu_bad
decl_stmt|;
name|uint8_t
name|cached_io
decl_stmt|;
name|uint8_t
name|smart_mode
decl_stmt|;
name|uint8_t
name|alarm_disable
decl_stmt|;
name|uint8_t
name|coercion
decl_stmt|;
name|uint8_t
name|zrc_config
decl_stmt|;
name|uint8_t
name|dirty_led_shows_drive_activity
decl_stmt|;
name|uint8_t
name|bios_continue_on_error
decl_stmt|;
name|uint8_t
name|spindown_mode
decl_stmt|;
name|uint8_t
name|allowed_device_types
decl_stmt|;
name|uint8_t
name|allow_mix_in_enclosure
decl_stmt|;
name|uint8_t
name|allow_mix_in_ld
decl_stmt|;
name|uint8_t
name|allow_sata_in_cluster
decl_stmt|;
name|uint8_t
name|max_chained_enclosures
decl_stmt|;
name|uint8_t
name|disable_ctrl_r
decl_stmt|;
name|uint8_t
name|enabel_web_bios
decl_stmt|;
name|uint8_t
name|phy_polarity_split
decl_stmt|;
name|uint8_t
name|direct_pd_mapping
decl_stmt|;
name|uint8_t
name|bios_enumerate_lds
decl_stmt|;
name|uint8_t
name|restored_hot_spare_on_insertion
decl_stmt|;
name|uint8_t
name|expose_enclosure_devices
decl_stmt|;
name|uint8_t
name|maintain_pd_fail_history
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|28
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Controller default settings */
end_comment

begin_struct
struct|struct
name|mfi_bios_data
block|{
name|uint16_t
name|boot_target_id
decl_stmt|;
name|uint8_t
name|do_not_int_13
decl_stmt|;
name|uint8_t
name|continue_on_error
decl_stmt|;
name|uint8_t
name|verbose
decl_stmt|;
name|uint8_t
name|geometry
decl_stmt|;
name|uint8_t
name|expose_all_drives
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|56
index|]
decl_stmt|;
name|uint8_t
name|check_sum
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SAS (?) controller info, returned from MFI_DCMD_CTRL_GETINFO. */
end_comment

begin_struct
struct|struct
name|mfi_ctrl_info
block|{
name|struct
name|mfi_info_pci
name|pci
decl_stmt|;
name|struct
name|mfi_info_host
name|host
decl_stmt|;
name|struct
name|mfi_info_device
name|device
decl_stmt|;
comment|/* Firmware components that are present and active. */
name|uint32_t
name|image_check_word
decl_stmt|;
name|uint32_t
name|image_component_count
decl_stmt|;
name|struct
name|mfi_info_component
name|image_component
index|[
literal|8
index|]
decl_stmt|;
comment|/* Firmware components that have been flashed but are inactive */
name|uint32_t
name|pending_image_component_count
decl_stmt|;
name|struct
name|mfi_info_component
name|pending_image_component
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|max_arms
decl_stmt|;
name|uint8_t
name|max_spans
decl_stmt|;
name|uint8_t
name|max_arrays
decl_stmt|;
name|uint8_t
name|max_lds
decl_stmt|;
name|char
name|product_name
index|[
literal|80
index|]
decl_stmt|;
name|char
name|serial_number
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|hw_present
decl_stmt|;
define|#
directive|define
name|MFI_INFO_HW_BBU
value|0x01
define|#
directive|define
name|MFI_INFO_HW_ALARM
value|0x02
define|#
directive|define
name|MFI_INFO_HW_NVRAM
value|0x04
define|#
directive|define
name|MFI_INFO_HW_UART
value|0x08
name|uint32_t
name|current_fw_time
decl_stmt|;
name|uint16_t
name|max_cmds
decl_stmt|;
name|uint16_t
name|max_sg_elements
decl_stmt|;
name|uint32_t
name|max_request_size
decl_stmt|;
name|uint16_t
name|lds_present
decl_stmt|;
name|uint16_t
name|lds_degraded
decl_stmt|;
name|uint16_t
name|lds_offline
decl_stmt|;
name|uint16_t
name|pd_present
decl_stmt|;
name|uint16_t
name|pd_disks_present
decl_stmt|;
name|uint16_t
name|pd_disks_pred_failure
decl_stmt|;
name|uint16_t
name|pd_disks_failed
decl_stmt|;
name|uint16_t
name|nvram_size
decl_stmt|;
name|uint16_t
name|memory_size
decl_stmt|;
name|uint16_t
name|flash_size
decl_stmt|;
name|uint16_t
name|ram_correctable_errors
decl_stmt|;
name|uint16_t
name|ram_uncorrectable_errors
decl_stmt|;
name|uint8_t
name|cluster_allowed
decl_stmt|;
name|uint8_t
name|cluster_active
decl_stmt|;
name|uint16_t
name|max_strips_per_io
decl_stmt|;
name|uint32_t
name|raid_levels
decl_stmt|;
define|#
directive|define
name|MFI_INFO_RAID_0
value|0x01
define|#
directive|define
name|MFI_INFO_RAID_1
value|0x02
define|#
directive|define
name|MFI_INFO_RAID_5
value|0x04
define|#
directive|define
name|MFI_INFO_RAID_1E
value|0x08
define|#
directive|define
name|MFI_INFO_RAID_6
value|0x10
name|uint32_t
name|adapter_ops
decl_stmt|;
define|#
directive|define
name|MFI_INFO_AOPS_RBLD_RATE
value|0x0001
define|#
directive|define
name|MFI_INFO_AOPS_CC_RATE
value|0x0002
define|#
directive|define
name|MFI_INFO_AOPS_BGI_RATE
value|0x0004
define|#
directive|define
name|MFI_INFO_AOPS_RECON_RATE
value|0x0008
define|#
directive|define
name|MFI_INFO_AOPS_PATROL_RATE
value|0x0010
define|#
directive|define
name|MFI_INFO_AOPS_ALARM_CONTROL
value|0x0020
define|#
directive|define
name|MFI_INFO_AOPS_CLUSTER_SUPPORTED
value|0x0040
define|#
directive|define
name|MFI_INFO_AOPS_BBU
value|0x0080
define|#
directive|define
name|MFI_INFO_AOPS_SPANNING_ALLOWED
value|0x0100
define|#
directive|define
name|MFI_INFO_AOPS_DEDICATED_SPARES
value|0x0200
define|#
directive|define
name|MFI_INFO_AOPS_REVERTIBLE_SPARES
value|0x0400
define|#
directive|define
name|MFI_INFO_AOPS_FOREIGN_IMPORT
value|0x0800
define|#
directive|define
name|MFI_INFO_AOPS_SELF_DIAGNOSTIC
value|0x1000
define|#
directive|define
name|MFI_INFO_AOPS_MIXED_ARRAY
value|0x2000
define|#
directive|define
name|MFI_INFO_AOPS_GLOBAL_SPARES
value|0x4000
name|uint32_t
name|ld_ops
decl_stmt|;
define|#
directive|define
name|MFI_INFO_LDOPS_READ_POLICY
value|0x01
define|#
directive|define
name|MFI_INFO_LDOPS_WRITE_POLICY
value|0x02
define|#
directive|define
name|MFI_INFO_LDOPS_IO_POLICY
value|0x04
define|#
directive|define
name|MFI_INFO_LDOPS_ACCESS_POLICY
value|0x08
define|#
directive|define
name|MFI_INFO_LDOPS_DISK_CACHE_POLICY
value|0x10
struct|struct
block|{
name|uint8_t
name|min
decl_stmt|;
name|uint8_t
name|max
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|stripe_sz_ops
struct|;
name|uint32_t
name|pd_ops
decl_stmt|;
define|#
directive|define
name|MFI_INFO_PDOPS_FORCE_ONLINE
value|0x01
define|#
directive|define
name|MFI_INFO_PDOPS_FORCE_OFFLINE
value|0x02
define|#
directive|define
name|MFI_INFO_PDOPS_FORCE_REBUILD
value|0x04
name|uint32_t
name|pd_mix_support
decl_stmt|;
define|#
directive|define
name|MFI_INFO_PDMIX_SAS
value|0x01
define|#
directive|define
name|MFI_INFO_PDMIX_SATA
value|0x02
define|#
directive|define
name|MFI_INFO_PDMIX_ENCL
value|0x04
define|#
directive|define
name|MFI_INFO_PDMIX_LD
value|0x08
define|#
directive|define
name|MFI_INFO_PDMIX_SATA_CLUSTER
value|0x10
name|uint8_t
name|ecc_bucket_count
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|11
index|]
decl_stmt|;
name|struct
name|mfi_ctrl_props
name|properties
decl_stmt|;
name|char
name|package_version
index|[
literal|0x60
index|]
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|0x800
operator|-
literal|0x6a0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* keep track of an event. */
end_comment

begin_union
union|union
name|mfi_evt
block|{
struct|struct
block|{
name|uint16_t
name|locale
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|int8_t
name|evt_class
decl_stmt|;
block|}
name|members
struct|;
name|uint32_t
name|word
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_comment
comment|/* event log state. */
end_comment

begin_struct
struct|struct
name|mfi_evt_log_state
block|{
name|uint32_t
name|newest_seq_num
decl_stmt|;
name|uint32_t
name|oldest_seq_num
decl_stmt|;
name|uint32_t
name|clear_seq_num
decl_stmt|;
name|uint32_t
name|shutdown_seq_num
decl_stmt|;
name|uint32_t
name|boot_seq_num
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_progress
block|{
name|uint16_t
name|progress
decl_stmt|;
name|uint16_t
name|elapsed_seconds
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_evt_ld
block|{
name|uint16_t
name|target_id
decl_stmt|;
name|uint8_t
name|ld_index
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_evt_pd
block|{
name|uint16_t
name|device_id
decl_stmt|;
name|uint8_t
name|enclosure_index
decl_stmt|;
name|uint8_t
name|slot_number
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SAS (?) event detail, returned from MFI_DCMD_CTRL_EVENT_WAIT. */
end_comment

begin_struct
struct|struct
name|mfi_evt_detail
block|{
name|uint32_t
name|seq
decl_stmt|;
name|uint32_t
name|time
decl_stmt|;
name|uint32_t
name|code
decl_stmt|;
name|union
name|mfi_evt
name|evt_class
decl_stmt|;
name|uint8_t
name|arg_type
decl_stmt|;
name|uint8_t
name|reserved1
index|[
literal|15
index|]
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
name|uint8_t
name|cdb_len
decl_stmt|;
name|uint8_t
name|sense_len
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|sense
index|[
literal|64
index|]
decl_stmt|;
block|}
name|cdb_sense
struct|;
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
struct|struct
block|{
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
name|uint64_t
name|count
decl_stmt|;
block|}
name|ld_count
struct|;
struct|struct
block|{
name|uint64_t
name|lba
decl_stmt|;
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
block|}
name|ld_lba
struct|;
struct|struct
block|{
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
name|uint32_t
name|pre_owner
decl_stmt|;
name|uint32_t
name|new_owner
decl_stmt|;
block|}
name|ld_owner
struct|;
struct|struct
block|{
name|uint64_t
name|ld_lba
decl_stmt|;
name|uint64_t
name|pd_lba
decl_stmt|;
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
block|}
name|ld_lba_pd_lba
struct|;
struct|struct
block|{
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
name|struct
name|mfi_progress
name|prog
decl_stmt|;
block|}
name|ld_prog
struct|;
struct|struct
block|{
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
name|uint32_t
name|prev_state
decl_stmt|;
name|uint32_t
name|new_state
decl_stmt|;
block|}
name|ld_state
struct|;
struct|struct
block|{
name|uint64_t
name|strip
decl_stmt|;
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
block|}
name|ld_strip
struct|;
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
struct|struct
block|{
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
name|uint32_t
name|err
decl_stmt|;
block|}
name|pd_err
struct|;
struct|struct
block|{
name|uint64_t
name|lba
decl_stmt|;
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
block|}
name|pd_lba
struct|;
struct|struct
block|{
name|uint64_t
name|lba
decl_stmt|;
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
name|struct
name|mfi_evt_ld
name|ld
decl_stmt|;
block|}
name|pd_lba_ld
struct|;
struct|struct
block|{
name|struct
name|mfi_evt_pd
name|pd
decl_stmt|;
name|struct
name|mfi_progress
name|prog
decl_stmt|;
block|}
name|pd_prog
struct|;
struct|struct
block|{
name|struct
name|mfi_evt_pd
name|ld
decl_stmt|;
name|uint32_t
name|prev_state
decl_stmt|;
name|uint32_t
name|new_state
decl_stmt|;
block|}
name|pd_state
struct|;
struct|struct
block|{
name|uint16_t
name|venderId
decl_stmt|;
name|uint16_t
name|deviceId
decl_stmt|;
name|uint16_t
name|subVenderId
decl_stmt|;
name|uint16_t
name|subDeviceId
decl_stmt|;
block|}
name|pci
struct|;
name|uint32_t
name|rate
decl_stmt|;
name|char
name|str
index|[
literal|96
index|]
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|rtc
decl_stmt|;
name|uint16_t
name|elapsedSeconds
decl_stmt|;
block|}
name|time
struct|;
struct|struct
block|{
name|uint32_t
name|ecar
decl_stmt|;
name|uint32_t
name|elog
decl_stmt|;
name|char
name|str
index|[
literal|64
index|]
decl_stmt|;
block|}
name|ecc
struct|;
name|uint8_t
name|b
index|[
literal|96
index|]
decl_stmt|;
name|uint16_t
name|s
index|[
literal|48
index|]
decl_stmt|;
name|uint32_t
name|w
index|[
literal|24
index|]
decl_stmt|;
name|uint64_t
name|d
index|[
literal|12
index|]
decl_stmt|;
block|}
name|args
union|;
name|char
name|description
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_evt_list
block|{
name|uint32_t
name|count
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|struct
name|mfi_evt_detail
name|event
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|mfi_pd_ref
block|{
struct|struct
block|{
name|uint16_t
name|device_id
decl_stmt|;
name|uint16_t
name|seq_num
decl_stmt|;
block|}
name|v
struct|;
name|uint32_t
name|ref
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_union
union|union
name|mfi_pd_ddf_type
block|{
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|uint16_t
name|forced_pd_guid
range|:
literal|1
decl_stmt|;
name|uint16_t
name|in_vd
range|:
literal|1
decl_stmt|;
name|uint16_t
name|is_global_spare
range|:
literal|1
decl_stmt|;
name|uint16_t
name|is_spare
range|:
literal|1
decl_stmt|;
name|uint16_t
name|is_foreign
range|:
literal|1
decl_stmt|;
name|uint16_t
name|reserved
range|:
literal|7
decl_stmt|;
name|uint16_t
name|intf
range|:
literal|4
decl_stmt|;
block|}
name|pd_type
struct|;
name|uint16_t
name|type
decl_stmt|;
block|}
name|v
union|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|ddf
struct|;
struct|struct
block|{
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|non_disk
struct|;
name|uint32_t
name|type
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_struct
struct|struct
name|mfi_pd_progress
block|{
name|uint32_t
name|active
decl_stmt|;
define|#
directive|define
name|MFI_PD_PROGRESS_REBUILD
value|(1<<0)
define|#
directive|define
name|MFI_PD_PROGRESS_PATROL
value|(1<<1)
define|#
directive|define
name|MFI_PD_PROGRESS_CLEAR
value|(1<<2)
name|struct
name|mfi_progress
name|rbld
decl_stmt|;
name|struct
name|mfi_progress
name|patrol
decl_stmt|;
name|struct
name|mfi_progress
name|clear
decl_stmt|;
name|struct
name|mfi_progress
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_pd_info
block|{
name|union
name|mfi_pd_ref
name|ref
decl_stmt|;
name|uint8_t
name|inquiry_data
index|[
literal|96
index|]
decl_stmt|;
name|uint8_t
name|vpd_page83
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|not_supported
decl_stmt|;
name|uint8_t
name|scsi_dev_type
decl_stmt|;
name|uint8_t
name|connected_port_bitmap
decl_stmt|;
name|uint8_t
name|device_speed
decl_stmt|;
name|uint32_t
name|media_err_count
decl_stmt|;
name|uint32_t
name|other_err_count
decl_stmt|;
name|uint32_t
name|pred_fail_count
decl_stmt|;
name|uint32_t
name|last_pred_fail_event_seq_num
decl_stmt|;
name|uint16_t
name|fw_state
decl_stmt|;
comment|/* MFI_PD_STATE_* */
name|uint8_t
name|disabled_for_removal
decl_stmt|;
name|uint8_t
name|link_speed
decl_stmt|;
name|union
name|mfi_pd_ddf_type
name|state
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|count
decl_stmt|;
name|uint8_t
name|is_path_broken
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|uint64_t
name|sas_addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|path_info
struct|;
name|uint64_t
name|raw_size
decl_stmt|;
name|uint64_t
name|non_coerced_size
decl_stmt|;
name|uint64_t
name|coerced_size
decl_stmt|;
name|uint16_t
name|encl_device_id
decl_stmt|;
name|uint8_t
name|encl_index
decl_stmt|;
name|uint8_t
name|slot_number
decl_stmt|;
name|struct
name|mfi_pd_progress
name|prog_info
decl_stmt|;
name|uint8_t
name|bad_block_table_full
decl_stmt|;
name|uint8_t
name|unusable_in_current_config
decl_stmt|;
name|uint8_t
name|vpd_page83_ext
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|512
operator|-
literal|358
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_pd_address
block|{
name|uint16_t
name|device_id
decl_stmt|;
name|uint16_t
name|encl_device_id
decl_stmt|;
name|uint8_t
name|encl_index
decl_stmt|;
name|uint8_t
name|slot_number
decl_stmt|;
name|uint8_t
name|scsi_dev_type
decl_stmt|;
comment|/* 0 = disk */
name|uint8_t
name|connect_port_bitmap
decl_stmt|;
name|uint64_t
name|sas_addr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_SYS_PDS
value|240
end_define

begin_struct
struct|struct
name|mfi_pd_list
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
name|struct
name|mfi_pd_address
name|addr
index|[
name|MAX_SYS_PDS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|mfi_pd_state
block|{
name|MFI_PD_STATE_UNCONFIGURED_GOOD
init|=
literal|0x00
block|,
name|MFI_PD_STATE_UNCONFIGURED_BAD
init|=
literal|0x01
block|,
name|MFI_PD_STATE_HOT_SPARE
init|=
literal|0x02
block|,
name|MFI_PD_STATE_OFFLINE
init|=
literal|0x10
block|,
name|MFI_PD_STATE_FAILED
init|=
literal|0x11
block|,
name|MFI_PD_STATE_REBUILD
init|=
literal|0x14
block|,
name|MFI_PD_STATE_ONLINE
init|=
literal|0x18
block|,
name|MFI_PD_STATE_COPYBACK
init|=
literal|0x20
block|,
name|MFI_PD_STATE_SYSTEM
init|=
literal|0x40
block|}
enum|;
end_enum

begin_comment
comment|/*  * "SYSTEM" disk appears to be "JBOD" support from the RAID controller.  * Adding a #define to denote this.  */
end_comment

begin_define
define|#
directive|define
name|MFI_PD_STATE_JBOD
value|MFI_PD_STATE_SYSTEM
end_define

begin_union
union|union
name|mfi_ld_ref
block|{
struct|struct
block|{
name|uint8_t
name|target_id
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|seq
decl_stmt|;
block|}
name|v
struct|;
name|uint32_t
name|ref
decl_stmt|;
block|}
name|__packed
union|;
end_union

begin_struct
struct|struct
name|mfi_ld_list
block|{
name|uint32_t
name|ld_count
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
struct|struct
block|{
name|union
name|mfi_ld_ref
name|ld
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
name|ld_list
index|[
name|MFI_MAX_LD
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|mfi_ld_access
block|{
name|MFI_LD_ACCESS_RW
init|=
literal|0
block|,
name|MFI_LD_ACCSSS_RO
init|=
literal|2
block|,
name|MFI_LD_ACCESS_BLOCKED
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MFI_LD_ACCESS_MASK
value|3
end_define

begin_enum
enum|enum
name|mfi_ld_state
block|{
name|MFI_LD_STATE_OFFLINE
init|=
literal|0
block|,
name|MFI_LD_STATE_PARTIALLY_DEGRADED
init|=
literal|1
block|,
name|MFI_LD_STATE_DEGRADED
init|=
literal|2
block|,
name|MFI_LD_STATE_OPTIMAL
init|=
literal|3
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mfi_ld_props
block|{
name|union
name|mfi_ld_ref
name|ld
decl_stmt|;
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|default_cache_policy
decl_stmt|;
name|uint8_t
name|access_policy
decl_stmt|;
name|uint8_t
name|disk_cache_policy
decl_stmt|;
name|uint8_t
name|current_cache_policy
decl_stmt|;
name|uint8_t
name|no_bgi
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_ld_params
block|{
name|uint8_t
name|primary_raid_level
decl_stmt|;
name|uint8_t
name|raid_level_qualifier
decl_stmt|;
name|uint8_t
name|secondary_raid_level
decl_stmt|;
name|uint8_t
name|stripe_size
decl_stmt|;
name|uint8_t
name|num_drives
decl_stmt|;
name|uint8_t
name|span_depth
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|init_state
decl_stmt|;
define|#
directive|define
name|MFI_LD_PARAMS_INIT_NO
value|0
define|#
directive|define
name|MFI_LD_PARAMS_INIT_QUICK
value|1
define|#
directive|define
name|MFI_LD_PARAMS_INIT_FULL
value|2
name|uint8_t
name|is_consistent
decl_stmt|;
name|uint8_t
name|reserved1
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|isSSCD
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_ld_progress
block|{
name|uint32_t
name|active
decl_stmt|;
define|#
directive|define
name|MFI_LD_PROGRESS_CC
value|(1<<0)
define|#
directive|define
name|MFI_LD_PROGRESS_BGI
value|(1<<1)
define|#
directive|define
name|MFI_LD_PROGRESS_FGI
value|(1<<2)
define|#
directive|define
name|MFI_LD_PROGRESS_RECON
value|(1<<3)
name|struct
name|mfi_progress
name|cc
decl_stmt|;
name|struct
name|mfi_progress
name|bgi
decl_stmt|;
name|struct
name|mfi_progress
name|fgi
decl_stmt|;
name|struct
name|mfi_progress
name|recon
decl_stmt|;
name|struct
name|mfi_progress
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_span
block|{
name|uint64_t
name|start_block
decl_stmt|;
name|uint64_t
name|num_blocks
decl_stmt|;
name|uint16_t
name|array_ref
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_MAX_SPAN_DEPTH
value|8
end_define

begin_struct
struct|struct
name|mfi_ld_config
block|{
name|struct
name|mfi_ld_props
name|properties
decl_stmt|;
name|struct
name|mfi_ld_params
name|params
decl_stmt|;
name|struct
name|mfi_span
name|span
index|[
name|MFI_MAX_SPAN_DEPTH
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_ld_info
block|{
name|struct
name|mfi_ld_config
name|ld_config
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|struct
name|mfi_ld_progress
name|progress
decl_stmt|;
name|uint16_t
name|cluster_owner
decl_stmt|;
name|uint8_t
name|reconstruct_active
decl_stmt|;
name|uint8_t
name|reserved1
index|[
literal|1
index|]
decl_stmt|;
name|uint8_t
name|vpd_page83
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_MAX_ARRAYS
value|16
end_define

begin_struct
struct|struct
name|mfi_spare
block|{
name|union
name|mfi_pd_ref
name|ref
decl_stmt|;
name|uint8_t
name|spare_type
decl_stmt|;
define|#
directive|define
name|MFI_SPARE_DEDICATED
value|(1<< 0)
define|#
directive|define
name|MFI_SPARE_REVERTIBLE
value|(1<< 1)
define|#
directive|define
name|MFI_SPARE_ENCL_AFFINITY
value|(1<< 2)
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|array_count
decl_stmt|;
name|uint16_t
name|array_ref
index|[
name|MFI_MAX_ARRAYS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_MAX_ROW_SIZE
value|32
end_define

begin_struct
struct|struct
name|mfi_array
block|{
name|uint64_t
name|size
decl_stmt|;
name|uint8_t
name|num_drives
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|array_ref
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|20
index|]
decl_stmt|;
struct|struct
block|{
name|union
name|mfi_pd_ref
name|ref
decl_stmt|;
comment|/* 0xffff == missing drive */
name|uint16_t
name|fw_state
decl_stmt|;
comment|/* MFI_PD_STATE_* */
struct|struct
block|{
name|uint8_t
name|pd
decl_stmt|;
name|uint8_t
name|slot
decl_stmt|;
block|}
name|encl
struct|;
block|}
name|pd
index|[
name|MFI_MAX_ROW_SIZE
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_config_data
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint16_t
name|array_count
decl_stmt|;
name|uint16_t
name|array_size
decl_stmt|;
name|uint16_t
name|log_drv_count
decl_stmt|;
name|uint16_t
name|log_drv_size
decl_stmt|;
name|uint16_t
name|spares_count
decl_stmt|;
name|uint16_t
name|spares_size
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|mfi_array
name|array
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|mfi_ld_config
name|ld
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|mfi_spare
name|spare
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_bbu_capacity_info
block|{
name|uint16_t
name|relative_charge
decl_stmt|;
name|uint16_t
name|absolute_charge
decl_stmt|;
name|uint16_t
name|remaining_capacity
decl_stmt|;
name|uint16_t
name|full_charge_capacity
decl_stmt|;
name|uint16_t
name|run_time_to_empty
decl_stmt|;
name|uint16_t
name|average_time_to_empty
decl_stmt|;
name|uint16_t
name|average_time_to_full
decl_stmt|;
name|uint16_t
name|cycle_count
decl_stmt|;
name|uint16_t
name|max_error
decl_stmt|;
name|uint16_t
name|remaining_capacity_alarm
decl_stmt|;
name|uint16_t
name|remaining_time_alarm
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|26
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_bbu_design_info
block|{
name|uint32_t
name|mfg_date
decl_stmt|;
name|uint16_t
name|design_capacity
decl_stmt|;
name|uint16_t
name|design_voltage
decl_stmt|;
name|uint16_t
name|spec_info
decl_stmt|;
name|uint16_t
name|serial_number
decl_stmt|;
name|uint16_t
name|pack_stat_config
decl_stmt|;
name|uint8_t
name|mfg_name
index|[
literal|12
index|]
decl_stmt|;
name|uint8_t
name|device_name
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|device_chemistry
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|mfg_data
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|17
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_ibbu_state
block|{
name|uint16_t
name|gas_guage_status
decl_stmt|;
name|uint16_t
name|relative_charge
decl_stmt|;
name|uint16_t
name|charger_system_state
decl_stmt|;
name|uint16_t
name|charger_system_ctrl
decl_stmt|;
name|uint16_t
name|charging_current
decl_stmt|;
name|uint16_t
name|absolute_charge
decl_stmt|;
name|uint16_t
name|max_error
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|18
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_bbu_state
block|{
name|uint16_t
name|gas_guage_status
decl_stmt|;
name|uint16_t
name|relative_charge
decl_stmt|;
name|uint16_t
name|charger_status
decl_stmt|;
name|uint16_t
name|remaining_capacity
decl_stmt|;
name|uint16_t
name|full_charge_capacity
decl_stmt|;
name|uint8_t
name|is_SOH_good
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|21
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|mfi_bbu_properties
block|{
name|uint32_t
name|auto_learn_period
decl_stmt|;
name|uint32_t
name|next_learn_time
decl_stmt|;
name|uint8_t
name|learn_delay_interval
decl_stmt|;
name|uint8_t
name|auto_learn_mode
decl_stmt|;
name|uint8_t
name|bbu_mode
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|21
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|mfi_bbu_status_detail
block|{
name|struct
name|mfi_ibbu_state
name|ibbu
decl_stmt|;
name|struct
name|mfi_bbu_state
name|bbu
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|mfi_bbu_status
block|{
name|uint8_t
name|battery_type
decl_stmt|;
define|#
directive|define
name|MFI_BBU_TYPE_NONE
value|0
define|#
directive|define
name|MFI_BBU_TYPE_IBBU
value|1
define|#
directive|define
name|MFI_BBU_TYPE_BBU
value|2
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|voltage
decl_stmt|;
name|int16_t
name|current
decl_stmt|;
name|uint16_t
name|temperature
decl_stmt|;
name|uint32_t
name|fw_status
decl_stmt|;
define|#
directive|define
name|MFI_BBU_STATE_PACK_MISSING
value|(1<< 0)
define|#
directive|define
name|MFI_BBU_STATE_VOLTAGE_LOW
value|(1<< 1)
define|#
directive|define
name|MFI_BBU_STATE_TEMPERATURE_HIGH
value|(1<< 2)
define|#
directive|define
name|MFI_BBU_STATE_CHARGE_ACTIVE
value|(1<< 3)
define|#
directive|define
name|MFI_BBU_STATE_DISCHARGE_ACTIVE
value|(1<< 4)
define|#
directive|define
name|MFI_BBU_STATE_LEARN_CYC_REQ
value|(1<< 5)
define|#
directive|define
name|MFI_BBU_STATE_LEARN_CYC_ACTIVE
value|(1<< 6)
define|#
directive|define
name|MFI_BBU_STATE_LEARN_CYC_FAIL
value|(1<< 7)
define|#
directive|define
name|MFI_BBU_STATE_LEARN_CYC_TIMEOUT
value|(1<< 8)
define|#
directive|define
name|MFI_BBU_STATE_I2C_ERR_DETECT
value|(1<< 9)
name|uint8_t
name|pad
index|[
literal|20
index|]
decl_stmt|;
name|union
name|mfi_bbu_status_detail
name|detail
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|mfi_pr_state
block|{
name|MFI_PR_STATE_STOPPED
init|=
literal|0
block|,
name|MFI_PR_STATE_READY
init|=
literal|1
block|,
name|MFI_PR_STATE_ACTIVE
init|=
literal|2
block|,
name|MFI_PR_STATE_ABORTED
init|=
literal|0xff
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mfi_pr_status
block|{
name|uint32_t
name|num_iteration
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|num_pd_done
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mfi_pr_opmode
block|{
name|MFI_PR_OPMODE_AUTO
init|=
literal|0
block|,
name|MFI_PR_OPMODE_MANUAL
init|=
literal|1
block|,
name|MFI_PR_OPMODE_DISABLED
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mfi_pr_properties
block|{
name|uint8_t
name|op_mode
decl_stmt|;
name|uint8_t
name|max_pd
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|exclude_ld_count
decl_stmt|;
name|uint16_t
name|excluded_ld
index|[
name|MFI_MAX_LD
index|]
decl_stmt|;
name|uint8_t
name|cur_pd_map
index|[
name|MFI_MAX_PD
operator|/
literal|8
index|]
decl_stmt|;
name|uint8_t
name|last_pd_map
index|[
name|MFI_MAX_PD
operator|/
literal|8
index|]
decl_stmt|;
name|uint32_t
name|next_exec
decl_stmt|;
name|uint32_t
name|exec_freq
decl_stmt|;
name|uint32_t
name|clear_freq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ThunderBolt support */
end_comment

begin_comment
comment|/*  * Raid Context structure which describes MegaRAID specific IO Paramenters  * This resides at offset 0x60 where the SGL normally starts in MPT IO Frames  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SCSI_IO_VENDOR_UNIQUE
block|{
name|uint16_t
name|resvd0
decl_stmt|;
comment|/* 0x00 - 0x01 */
name|uint16_t
name|timeoutValue
decl_stmt|;
comment|/* 0x02 - 0x03 */
name|uint8_t
name|regLockFlags
decl_stmt|;
name|uint8_t
name|armId
decl_stmt|;
name|uint16_t
name|TargetID
decl_stmt|;
comment|/* 0x06 - 0x07 */
name|uint64_t
name|RegLockLBA
decl_stmt|;
comment|/* 0x08 - 0x0F */
name|uint32_t
name|RegLockLength
decl_stmt|;
comment|/* 0x10 - 0x13 */
name|uint16_t
name|SMID
decl_stmt|;
comment|/* 0x14 - 0x15 nextLMId */
name|uint8_t
name|exStatus
decl_stmt|;
comment|/* 0x16 */
name|uint8_t
name|Status
decl_stmt|;
comment|/* 0x17 status */
name|uint8_t
name|RAIDFlags
decl_stmt|;
comment|/* 0x18 */
name|uint8_t
name|numSGE
decl_stmt|;
comment|/* 0x19 numSge */
name|uint16_t
name|configSeqNum
decl_stmt|;
comment|/* 0x1A - 0x1B */
name|uint8_t
name|spanArm
decl_stmt|;
comment|/* 0x1C */
name|uint8_t
name|resvd2
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x1D - 0x1F */
block|}
name|MPI2_SCSI_IO_VENDOR_UNIQUE
operator|,
name|MPI25_SCSI_IO_VENDOR_UNIQUE
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** * *        Message Functions * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NA_MPI2_FUNCTION_SCSI_IO_REQUEST
value|(0x00)
end_define

begin_comment
comment|/* SCSI IO */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_TASK_MGMT
value|(0x01)
end_define

begin_comment
comment|/* SCSI Task Management */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_INIT
value|(0x02)
end_define

begin_comment
comment|/* IOC Init */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_FACTS
value|(0x03)
end_define

begin_comment
comment|/* IOC Facts */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_CONFIG
value|(0x04)
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PORT_FACTS
value|(0x05)
end_define

begin_comment
comment|/* Port Facts */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PORT_ENABLE
value|(0x06)
end_define

begin_comment
comment|/* Port Enable */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_EVENT_NOTIFICATION
value|(0x07)
end_define

begin_comment
comment|/* Event Notification */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_EVENT_ACK
value|(0x08)
end_define

begin_comment
comment|/* Event Acknowledge */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_FW_DOWNLOAD
value|(0x09)
end_define

begin_comment
comment|/* FW Download */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_ASSIST
value|(0x0B)
end_define

begin_comment
comment|/* Target Assist */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_STATUS_SEND
value|(0x0C)
end_define

begin_comment
comment|/* Target Status Send */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_MODE_ABORT
value|(0x0D)
end_define

begin_comment
comment|/* Target Mode Abort */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_FW_UPLOAD
value|(0x12)
end_define

begin_comment
comment|/* FW Upload */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_ACTION
value|(0x15)
end_define

begin_comment
comment|/* RAID Action */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_SCSI_IO_PASSTHROUGH
value|(0x16)
end_define

begin_comment
comment|/* SCSI IO RAID Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TOOLBOX
value|(0x17)
end_define

begin_comment
comment|/* Toolbox */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SCSI_ENCLOSURE_PROCESSOR
value|(0x18)
end_define

begin_comment
comment|/* SCSI Enclosure Processor */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SMP_PASSTHROUGH
value|(0x1A)
end_define

begin_comment
comment|/* SMP Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SAS_IO_UNIT_CONTROL
value|(0x1B)
end_define

begin_comment
comment|/* SAS IO Unit Control */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_SATA_PASSTHROUGH
value|(0x1C)
end_define

begin_comment
comment|/* SATA Passthrough */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_DIAG_BUFFER_POST
value|(0x1D)
end_define

begin_comment
comment|/* Diagnostic Buffer Post */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_DIAG_RELEASE
value|(0x1E)
end_define

begin_comment
comment|/* Diagnostic Release */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_CMD_BUF_BASE_POST
value|(0x24)
end_define

begin_comment
comment|/* Target Command Buffer Post Base */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_TARGET_CMD_BUF_LIST_POST
value|(0x25)
end_define

begin_comment
comment|/* Target Command Buffer Post List */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_RAID_ACCELERATOR
value|(0x2C)
end_define

begin_comment
comment|/* RAID Accelerator */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_HOST_BASED_DISCOVERY_ACTION
value|(0x2F)
end_define

begin_comment
comment|/* Host Based Discovery Action */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_PWR_MGMT_CONTROL
value|(0x30)
end_define

begin_comment
comment|/* Power Management Control */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_MIN_PRODUCT_SPECIFIC
value|(0xF0)
end_define

begin_comment
comment|/* beginning of product-specific range */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_MAX_PRODUCT_SPECIFIC
value|(0xFF)
end_define

begin_comment
comment|/* end of product-specific range */
end_comment

begin_comment
comment|/* Doorbell functions */
end_comment

begin_define
define|#
directive|define
name|MPI2_FUNCTION_IOC_MESSAGE_UNIT_RESET
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_FUNCTION_HANDSHAKE
value|(0x42)
end_define

begin_comment
comment|/***************************************************************************** * *        MPI Version Definitions * *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_MINOR_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION
value|((MPI2_VERSION_MAJOR<< MPI2_VERSION_MAJOR_SHIFT) |   \                                       MPI2_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|MPI2_VERSION_02_00
value|(0x0200)
end_define

begin_comment
comment|/* versioning for this MPI header set */
end_comment

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_UNIT_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION_DEV_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_HEADER_VERSION
value|((MPI2_HEADER_VERSION_UNIT<< 8) |		\ 					MPI2_HEADER_VERSION_DEV)
end_define

begin_comment
comment|/* IOCInit Request message */
end_comment

begin_struct
struct|struct
name|MPI2_IOC_INIT_REQUEST
block|{
name|uint8_t
name|WhoInit
decl_stmt|;
comment|/* 0x00 */
name|uint8_t
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|uint8_t
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|uint8_t
name|Function
decl_stmt|;
comment|/* 0x03 */
name|uint16_t
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|uint8_t
name|Reserved3
decl_stmt|;
comment|/* 0x06 */
name|uint8_t
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|uint8_t
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|uint8_t
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|uint16_t
name|Reserved4
decl_stmt|;
comment|/* 0x0A */
name|uint16_t
name|MsgVersion
decl_stmt|;
comment|/* 0x0C */
name|uint16_t
name|HeaderVersion
decl_stmt|;
comment|/* 0x0E */
name|uint32_t
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|uint16_t
name|Reserved6
decl_stmt|;
comment|/* 0x14 */
name|uint8_t
name|Reserved7
decl_stmt|;
comment|/* 0x16 */
name|uint8_t
name|HostMSIxVectors
decl_stmt|;
comment|/* 0x17 */
name|uint16_t
name|Reserved8
decl_stmt|;
comment|/* 0x18 */
name|uint16_t
name|SystemRequestFrameSize
decl_stmt|;
comment|/* 0x1A */
name|uint16_t
name|ReplyDescriptorPostQueueDepth
decl_stmt|;
comment|/* 0x1C */
name|uint16_t
name|ReplyFreeQueueDepth
decl_stmt|;
comment|/* 0x1E */
name|uint32_t
name|SenseBufferAddressHigh
decl_stmt|;
comment|/* 0x20 */
name|uint32_t
name|SystemReplyAddressHigh
decl_stmt|;
comment|/* 0x24 */
name|uint64_t
name|SystemRequestFrameBaseAddress
decl_stmt|;
comment|/* 0x28 */
name|uint64_t
name|ReplyDescriptorPostQueueAddress
decl_stmt|;
comment|/* 0x30 */
name|uint64_t
name|ReplyFreeQueueAddress
decl_stmt|;
comment|/* 0x38 */
name|uint64_t
name|TimeStamp
decl_stmt|;
comment|/* 0x40 */
block|}
struct|;
end_struct

begin_comment
comment|/* WhoInit values */
end_comment

begin_define
define|#
directive|define
name|MPI2_WHOINIT_NOT_INITIALIZED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_SYSTEM_BIOS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_ROM_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_PCI_PEER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_HOST_DRIVER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_WHOINIT_MANUFACTURER
value|(0x05)
end_define

begin_struct
struct|struct
name|MPI2_SGE_CHAIN_UNION
block|{
name|uint16_t
name|Length
decl_stmt|;
name|uint8_t
name|NextChainOffset
decl_stmt|;
name|uint8_t
name|Flags
decl_stmt|;
union|union
block|{
name|uint32_t
name|Address32
decl_stmt|;
name|uint64_t
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|MPI2_IEEE_SGE_SIMPLE32
block|{
name|uint32_t
name|Address
decl_stmt|;
name|uint32_t
name|FlagsLength
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|MPI2_IEEE_SGE_SIMPLE64
block|{
name|uint64_t
name|Address
decl_stmt|;
name|uint32_t
name|Length
decl_stmt|;
name|uint16_t
name|Reserved1
decl_stmt|;
name|uint8_t
name|Reserved2
decl_stmt|;
name|uint8_t
name|Flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_SIMPLE_UNION
block|{
name|struct
name|MPI2_IEEE_SGE_SIMPLE32
name|Simple32
decl_stmt|;
name|struct
name|MPI2_IEEE_SGE_SIMPLE64
name|Simple64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_SIMPLE_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SGE_SIMPLE_UNION
block|{
name|uint32_t
name|FlagsLength
decl_stmt|;
union|union
block|{
name|uint32_t
name|Address32
decl_stmt|;
name|uint64_t
name|Address64
decl_stmt|;
block|}
name|u
union|;
block|}
name|MPI2_SGE_SIMPLE_UNION
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *  IEEE SGE field definitions and masks ****************************************************************************/
end_comment

begin_comment
comment|/* Flags field bit definitions */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_ELEMENT_TYPE_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_FLAGS_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE32_SGE_LENGTH_MASK
value|(0x00FFFFFF)
end_define

begin_comment
comment|/* Element Type */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SIMPLE_ELEMENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_CHAIN_ELEMENT
value|(0x80)
end_define

begin_comment
comment|/* Data Location Address Space */
end_comment

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_ADDR_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_SYSTEM_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCDDR_ADDR
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCPLB_ADDR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_IEEE_SGE_FLAGS_IOCPLBNTA_ADDR
value|(0x03)
end_define

begin_comment
comment|/* Address Size */
end_comment

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_32_BIT_ADDRESSING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SGE_FLAGS_64_BIT_ADDRESSING
value|(0x02)
end_define

begin_comment
comment|/*******************/
end_comment

begin_comment
comment|/* SCSI IO Control bits */
end_comment

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ADDCDBLEN_MASK
value|(0xFC000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ADDCDBLEN_SHIFT
value|(26)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_DATADIRECTION_MASK
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_NODATATRANSFER
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_WRITE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_READ
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_BIDIRECTIONAL
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKPRI_MASK
value|(0x00007800)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKPRI_SHIFT
value|(11)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TASKATTRIBUTE_MASK
value|(0x00000700)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_SIMPLEQ
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_HEADOFQ
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ORDEREDQ
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_ACAQ
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_MASK
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_NO_TLR
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_ON
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SCSIIO_CONTROL_TLR_OFF
value|(0x00000080)
end_define

begin_comment
comment|/*******************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|CDB
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x00 */
name|uint32_t
name|PrimaryReferenceTag
decl_stmt|;
comment|/* 0x14 */
name|uint16_t
name|PrimaryApplicationTag
decl_stmt|;
comment|/* 0x18 */
name|uint16_t
name|PrimaryApplicationTagMask
decl_stmt|;
comment|/* 0x1A */
name|uint32_t
name|TransferLength
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_SCSI_IO_CDB_EEDP32
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_IEEE_SGE_CHAIN_UNION
block|{
name|struct
name|MPI2_IEEE_SGE_SIMPLE32
name|Chain32
decl_stmt|;
name|struct
name|MPI2_IEEE_SGE_SIMPLE64
name|Chain64
decl_stmt|;
block|}
name|MPI2_IEEE_SGE_CHAIN_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_SIMPLE_SGE_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
block|}
name|MPI2_SIMPLE_SGE_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_SGE_IO_UNION
block|{
name|MPI2_SGE_SIMPLE_UNION
name|MpiSimple
decl_stmt|;
name|struct
name|MPI2_SGE_CHAIN_UNION
name|MpiChain
decl_stmt|;
name|MPI2_IEEE_SGE_SIMPLE_UNION
name|IeeeSimple
decl_stmt|;
name|MPI2_IEEE_SGE_CHAIN_UNION
name|IeeeChain
decl_stmt|;
block|}
name|MPI2_SGE_IO_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|CDB32
index|[
literal|32
index|]
decl_stmt|;
name|MPI2_SCSI_IO_CDB_EEDP32
name|EEDP32
decl_stmt|;
name|MPI2_SGE_SIMPLE_UNION
name|SGE
decl_stmt|;
block|}
name|MPI2_SCSI_IO_CDB_UNION
typedef|;
end_typedef

begin_comment
comment|/* MPI 2.5 SGLs */
end_comment

begin_define
define|#
directive|define
name|MPI25_IEEE_SGE_FLAGS_END_OF_LIST
value|(0x40)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI25_IEEE_SGE_CHAIN64
block|{
name|uint64_t
name|Address
decl_stmt|;
name|uint32_t
name|Length
decl_stmt|;
name|uint16_t
name|Reserved1
decl_stmt|;
name|uint8_t
name|NextChainOffset
decl_stmt|;
name|uint8_t
name|Flags
decl_stmt|;
block|}
name|MPI25_IEEE_SGE_CHAIN64
operator|,
typedef|*
name|pMpi25IeeeSgeChain64_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_IEEE_SGE_FLAGS_ defines for the Flags field */
end_comment

begin_comment
comment|/********/
end_comment

begin_comment
comment|/*  * RAID SCSI IO Request Message  * Total SGE count will be one less than  _MPI2_SCSI_IO_REQUEST  */
end_comment

begin_struct
struct|struct
name|mfi_mpi2_request_raid_scsi_io
block|{
name|uint16_t
name|DevHandle
decl_stmt|;
comment|/* 0x00 */
name|uint8_t
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|uint8_t
name|Function
decl_stmt|;
comment|/* 0x03 */
name|uint16_t
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|uint8_t
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|uint8_t
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|uint8_t
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|uint8_t
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|uint16_t
name|Reserved3
decl_stmt|;
comment|/* 0x0A */
name|uint32_t
name|SenseBufferLowAddress
decl_stmt|;
comment|/* 0x0C */
name|uint16_t
name|SGLFlags
decl_stmt|;
comment|/* 0x10 */
name|uint8_t
name|SenseBufferLength
decl_stmt|;
comment|/* 0x12 */
name|uint8_t
name|Reserved4
decl_stmt|;
comment|/* 0x13 */
name|uint8_t
name|SGLOffset0
decl_stmt|;
comment|/* 0x14 */
name|uint8_t
name|SGLOffset1
decl_stmt|;
comment|/* 0x15 */
name|uint8_t
name|SGLOffset2
decl_stmt|;
comment|/* 0x16 */
name|uint8_t
name|SGLOffset3
decl_stmt|;
comment|/* 0x17 */
name|uint32_t
name|SkipCount
decl_stmt|;
comment|/* 0x18 */
name|uint32_t
name|DataLength
decl_stmt|;
comment|/* 0x1C */
name|uint32_t
name|BidirectionalDataLength
decl_stmt|;
comment|/* 0x20 */
name|uint16_t
name|IoFlags
decl_stmt|;
comment|/* 0x24 */
name|uint16_t
name|EEDPFlags
decl_stmt|;
comment|/* 0x26 */
name|uint32_t
name|EEDPBlockSize
decl_stmt|;
comment|/* 0x28 */
name|uint32_t
name|SecondaryReferenceTag
decl_stmt|;
comment|/* 0x2C */
name|uint16_t
name|SecondaryApplicationTag
decl_stmt|;
comment|/* 0x30 */
name|uint16_t
name|ApplicationTagTranslationMask
decl_stmt|;
comment|/* 0x32 */
name|uint8_t
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x34 */
name|uint32_t
name|Control
decl_stmt|;
comment|/* 0x3C */
name|MPI2_SCSI_IO_CDB_UNION
name|CDB
decl_stmt|;
comment|/* 0x40 */
name|MPI2_SCSI_IO_VENDOR_UNIQUE
name|RaidContext
decl_stmt|;
comment|/* 0x60 */
name|MPI2_SGE_IO_UNION
name|SGL
decl_stmt|;
comment|/* 0x80 */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * MPT RAID MFA IO Descriptor.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MFI_RAID_MFA_IO_DESCRIPTOR
block|{
name|uint32_t
name|RequestFlags
range|:
literal|8
decl_stmt|;
name|uint32_t
name|MessageAddress1
range|:
literal|24
decl_stmt|;
comment|/* bits 31:8*/
name|uint32_t
name|MessageAddress2
decl_stmt|;
comment|/* bits 61:32 */
block|}
name|MFI_RAID_MFA_IO_REQUEST_DESCRIPTOR
operator|,
typedef|*
name|PMFI_RAID_MFA_IO_REQUEST_DESCRIPTOR
typedef|;
end_typedef

begin_struct
struct|struct
name|mfi_mpi2_request_header
block|{
name|uint8_t
name|RequestFlags
decl_stmt|;
comment|/* 0x00 */
name|uint8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|uint16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
name|uint16_t
name|LMID
decl_stmt|;
comment|/* 0x04 */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for the RequestFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_TYPE_MASK
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_SCSI_IO
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_SCSI_TARGET
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_HIGH_PRIORITY
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_DEFAULT_TYPE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_RAID_ACCELERATOR
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_REQ_DESCRIPT_FLAGS_IOC_FIFO_MARKER
value|(0x01)
end_define

begin_struct
struct|struct
name|mfi_mpi2_request_high_priority
block|{
name|struct
name|mfi_mpi2_request_header
name|header
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_request_scsi_io
block|{
name|struct
name|mfi_mpi2_request_header
name|header
decl_stmt|;
name|uint16_t
name|scsi_io_dev_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_request_scsi_target
block|{
name|struct
name|mfi_mpi2_request_header
name|header
decl_stmt|;
name|uint16_t
name|scsi_target_io_index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Request Descriptors */
end_comment

begin_union
union|union
name|mfi_mpi2_request_descriptor
block|{
name|struct
name|mfi_mpi2_request_header
name|header
decl_stmt|;
name|struct
name|mfi_mpi2_request_high_priority
name|high_priority
decl_stmt|;
name|struct
name|mfi_mpi2_request_scsi_io
name|scsi_io
decl_stmt|;
name|struct
name|mfi_mpi2_request_scsi_target
name|scsi_target
decl_stmt|;
name|uint64_t
name|words
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|mfi_mpi2_reply_header
block|{
name|uint8_t
name|ReplyFlags
decl_stmt|;
comment|/* 0x00 */
name|uint8_t
name|MSIxIndex
decl_stmt|;
comment|/* 0x01 */
name|uint16_t
name|SMID
decl_stmt|;
comment|/* 0x02 */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for the ReplyFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TYPE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_SCSI_IO_SUCCESS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_ADDRESS_REPLY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TARGETASSIST_SUCCESS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_TARGET_COMMAND_BUFFER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_RAID_ACCELERATOR_SUCCESS
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_FLAGS_UNUSED
value|(0x0F)
end_define

begin_comment
comment|/* values for marking a reply descriptor as unused */
end_comment

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_UNUSED_WORD0_MARK
value|(0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_RPY_DESCRIPT_UNUSED_WORD1_MARK
value|(0xFFFFFFFF)
end_define

begin_struct
struct|struct
name|mfi_mpi2_reply_default
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint32_t
name|DescriptorTypeDependent2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_reply_address
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint32_t
name|ReplyFrameAddress
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_reply_scsi_io
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint16_t
name|TaskTag
decl_stmt|;
comment|/* 0x04 */
name|uint16_t
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_reply_target_assist
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint8_t
name|SequenceNumber
decl_stmt|;
comment|/* 0x04 */
name|uint8_t
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|uint16_t
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_reply_target_cmd_buffer
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint8_t
name|SequenceNumber
decl_stmt|;
comment|/* 0x04 */
name|uint8_t
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|uint16_t
name|InitiatorDevHandle
decl_stmt|;
comment|/* 0x06 */
name|uint16_t
name|IoIndex
decl_stmt|;
comment|/* 0x06 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mfi_mpi2_reply_raid_accel
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|uint8_t
name|SequenceNumber
decl_stmt|;
comment|/* 0x04 */
name|uint32_t
name|Reserved
decl_stmt|;
comment|/* 0x04 */
block|}
struct|;
end_struct

begin_comment
comment|/* union of Reply Descriptors */
end_comment

begin_union
union|union
name|mfi_mpi2_reply_descriptor
block|{
name|struct
name|mfi_mpi2_reply_header
name|header
decl_stmt|;
name|struct
name|mfi_mpi2_reply_scsi_io
name|scsi_io
decl_stmt|;
name|struct
name|mfi_mpi2_reply_target_assist
name|target_assist
decl_stmt|;
name|struct
name|mfi_mpi2_reply_target_cmd_buffer
name|target_cmd
decl_stmt|;
name|struct
name|mfi_mpi2_reply_raid_accel
name|raid_accel
decl_stmt|;
name|struct
name|mfi_mpi2_reply_default
name|reply_default
decl_stmt|;
name|uint64_t
name|words
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|IO_REQUEST_INFO
block|{
name|uint64_t
name|ldStartBlock
decl_stmt|;
name|uint32_t
name|numBlocks
decl_stmt|;
name|uint16_t
name|ldTgtId
decl_stmt|;
name|uint8_t
name|isRead
decl_stmt|;
name|uint16_t
name|devHandle
decl_stmt|;
name|uint64_t
name|pdBlock
decl_stmt|;
name|uint8_t
name|fpOkForIo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MFI_SCSI_MAX_TARGETS
value|128
end_define

begin_define
define|#
directive|define
name|MFI_SCSI_MAX_LUNS
value|8
end_define

begin_define
define|#
directive|define
name|MFI_SCSI_INITIATOR_ID
value|255
end_define

begin_define
define|#
directive|define
name|MFI_SCSI_MAX_CMDS
value|8
end_define

begin_define
define|#
directive|define
name|MFI_SCSI_MAX_CDB_LEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MFIREG_H */
end_comment

end_unit

