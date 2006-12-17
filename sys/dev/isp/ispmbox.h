begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Mailbox and Queue Entry Definitions for for Qlogic ISP SCSI adapters.  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISPMBOX_H
end_ifndef

begin_define
define|#
directive|define
name|_ISPMBOX_H
end_define

begin_comment
comment|/*  * Mailbox Command Opcodes  */
end_comment

begin_define
define|#
directive|define
name|MBOX_NO_OP
value|0x0000
end_define

begin_define
define|#
directive|define
name|MBOX_LOAD_RAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|MBOX_EXEC_FIRMWARE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MBOX_DUMP_RAM
value|0x0003
end_define

begin_define
define|#
directive|define
name|MBOX_WRITE_RAM_WORD
value|0x0004
end_define

begin_define
define|#
directive|define
name|MBOX_READ_RAM_WORD
value|0x0005
end_define

begin_define
define|#
directive|define
name|MBOX_MAILBOX_REG_TEST
value|0x0006
end_define

begin_define
define|#
directive|define
name|MBOX_VERIFY_CHECKSUM
value|0x0007
end_define

begin_define
define|#
directive|define
name|MBOX_ABOUT_FIRMWARE
value|0x0008
end_define

begin_define
define|#
directive|define
name|MBOX_LOAD_RISC_RAM_2100
value|0x0009
end_define

begin_comment
comment|/*   a */
end_comment

begin_define
define|#
directive|define
name|MBOX_LOAD_RISC_RAM
value|0x000b
end_define

begin_comment
comment|/*   c */
end_comment

begin_define
define|#
directive|define
name|MBOX_WRITE_RAM_WORD_EXTENDED
value|0x000d
end_define

begin_define
define|#
directive|define
name|MBOX_CHECK_FIRMWARE
value|0x000e
end_define

begin_define
define|#
directive|define
name|MBOX_READ_RAM_WORD_EXTENDED
value|0x000f
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_REQ_QUEUE
value|0x0010
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_RES_QUEUE
value|0x0011
end_define

begin_define
define|#
directive|define
name|MBOX_EXECUTE_IOCB
value|0x0012
end_define

begin_define
define|#
directive|define
name|MBOX_WAKE_UP
value|0x0013
end_define

begin_define
define|#
directive|define
name|MBOX_STOP_FIRMWARE
value|0x0014
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT
value|0x0015
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT_DEVICE
value|0x0016
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT_TARGET
value|0x0017
end_define

begin_define
define|#
directive|define
name|MBOX_BUS_RESET
value|0x0018
end_define

begin_define
define|#
directive|define
name|MBOX_STOP_QUEUE
value|0x0019
end_define

begin_define
define|#
directive|define
name|MBOX_START_QUEUE
value|0x001a
end_define

begin_define
define|#
directive|define
name|MBOX_SINGLE_STEP_QUEUE
value|0x001b
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT_QUEUE
value|0x001c
end_define

begin_define
define|#
directive|define
name|MBOX_GET_DEV_QUEUE_STATUS
value|0x001d
end_define

begin_comment
comment|/*  1e */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_FIRMWARE_STATUS
value|0x001f
end_define

begin_define
define|#
directive|define
name|MBOX_GET_INIT_SCSI_ID
value|0x0020
end_define

begin_define
define|#
directive|define
name|MBOX_GET_SELECT_TIMEOUT
value|0x0021
end_define

begin_define
define|#
directive|define
name|MBOX_GET_RETRY_COUNT
value|0x0022
end_define

begin_define
define|#
directive|define
name|MBOX_GET_TAG_AGE_LIMIT
value|0x0023
end_define

begin_define
define|#
directive|define
name|MBOX_GET_CLOCK_RATE
value|0x0024
end_define

begin_define
define|#
directive|define
name|MBOX_GET_ACT_NEG_STATE
value|0x0025
end_define

begin_define
define|#
directive|define
name|MBOX_GET_ASYNC_DATA_SETUP_TIME
value|0x0026
end_define

begin_define
define|#
directive|define
name|MBOX_GET_SBUS_PARAMS
value|0x0027
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PCI_PARAMS
value|MBOX_GET_SBUS_PARAMS
end_define

begin_define
define|#
directive|define
name|MBOX_GET_TARGET_PARAMS
value|0x0028
end_define

begin_define
define|#
directive|define
name|MBOX_GET_DEV_QUEUE_PARAMS
value|0x0029
end_define

begin_define
define|#
directive|define
name|MBOX_GET_RESET_DELAY_PARAMS
value|0x002a
end_define

begin_comment
comment|/*  2b */
end_comment

begin_comment
comment|/*  2c */
end_comment

begin_comment
comment|/*  2d */
end_comment

begin_comment
comment|/*  2e */
end_comment

begin_comment
comment|/*  2f */
end_comment

begin_define
define|#
directive|define
name|MBOX_SET_INIT_SCSI_ID
value|0x0030
end_define

begin_define
define|#
directive|define
name|MBOX_SET_SELECT_TIMEOUT
value|0x0031
end_define

begin_define
define|#
directive|define
name|MBOX_SET_RETRY_COUNT
value|0x0032
end_define

begin_define
define|#
directive|define
name|MBOX_SET_TAG_AGE_LIMIT
value|0x0033
end_define

begin_define
define|#
directive|define
name|MBOX_SET_CLOCK_RATE
value|0x0034
end_define

begin_define
define|#
directive|define
name|MBOX_SET_ACT_NEG_STATE
value|0x0035
end_define

begin_define
define|#
directive|define
name|MBOX_SET_ASYNC_DATA_SETUP_TIME
value|0x0036
end_define

begin_define
define|#
directive|define
name|MBOX_SET_SBUS_CONTROL_PARAMS
value|0x0037
end_define

begin_define
define|#
directive|define
name|MBOX_SET_PCI_PARAMETERS
value|0x0037
end_define

begin_define
define|#
directive|define
name|MBOX_SET_TARGET_PARAMS
value|0x0038
end_define

begin_define
define|#
directive|define
name|MBOX_SET_DEV_QUEUE_PARAMS
value|0x0039
end_define

begin_define
define|#
directive|define
name|MBOX_SET_RESET_DELAY_PARAMS
value|0x003a
end_define

begin_comment
comment|/*  3b */
end_comment

begin_comment
comment|/*  3c */
end_comment

begin_comment
comment|/*  3d */
end_comment

begin_comment
comment|/*  3e */
end_comment

begin_comment
comment|/*  3f */
end_comment

begin_define
define|#
directive|define
name|MBOX_RETURN_BIOS_BLOCK_ADDR
value|0x0040
end_define

begin_define
define|#
directive|define
name|MBOX_WRITE_FOUR_RAM_WORDS
value|0x0041
end_define

begin_define
define|#
directive|define
name|MBOX_EXEC_BIOS_IOCB
value|0x0042
end_define

begin_define
define|#
directive|define
name|MBOX_SET_FW_FEATURES
value|0x004a
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FW_FEATURES
value|0x004b
end_define

begin_define
define|#
directive|define
name|FW_FEATURE_FAST_POST
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_FEATURE_LVD_NOTIFY
value|0x2
end_define

begin_define
define|#
directive|define
name|FW_FEATURE_RIO_32BIT
value|0x4
end_define

begin_define
define|#
directive|define
name|FW_FEATURE_RIO_16BIT
value|0x8
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_REQ_QUEUE_A64
value|0x0052
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_RES_QUEUE_A64
value|0x0053
end_define

begin_define
define|#
directive|define
name|MBOX_ENABLE_TARGET_MODE
value|0x0055
end_define

begin_define
define|#
directive|define
name|ENABLE_TARGET_FLAG
value|0x8000
end_define

begin_define
define|#
directive|define
name|ENABLE_TQING_FLAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|ENABLE_MANDATORY_DISC
value|0x0002
end_define

begin_define
define|#
directive|define
name|MBOX_GET_TARGET_STATUS
value|0x0056
end_define

begin_comment
comment|/* These are for the ISP2X00 FC cards */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_LOOP_ID
value|0x0020
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FIRMWARE_OPTIONS
value|0x0028
end_define

begin_define
define|#
directive|define
name|MBOX_SET_FIRMWARE_OPTIONS
value|0x0038
end_define

begin_define
define|#
directive|define
name|MBOX_GET_RESOURCE_COUNT
value|0x0042
end_define

begin_define
define|#
directive|define
name|MBOX_REQUEST_OFFLINE_MODE
value|0x0043
end_define

begin_define
define|#
directive|define
name|MBOX_ENHANCED_GET_PDB
value|0x0047
end_define

begin_define
define|#
directive|define
name|MBOX_EXEC_COMMAND_IOCB_A64
value|0x0054
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_FIRMWARE
value|0x0060
end_define

begin_define
define|#
directive|define
name|MBOX_GET_INIT_CONTROL_BLOCK
value|0x0061
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP
value|0x0062
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FC_AL_POSITION_MAP
value|0x0063
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PORT_DB
value|0x0064
end_define

begin_define
define|#
directive|define
name|MBOX_CLEAR_ACA
value|0x0065
end_define

begin_define
define|#
directive|define
name|MBOX_TARGET_RESET
value|0x0066
end_define

begin_define
define|#
directive|define
name|MBOX_CLEAR_TASK_SET
value|0x0067
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT_TASK_SET
value|0x0068
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FW_STATE
value|0x0069
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PORT_NAME
value|0x006A
end_define

begin_define
define|#
directive|define
name|MBOX_GET_LINK_STATUS
value|0x006B
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP_RESET
value|0x006C
end_define

begin_define
define|#
directive|define
name|MBOX_SEND_SNS
value|0x006E
end_define

begin_define
define|#
directive|define
name|MBOX_FABRIC_LOGIN
value|0x006F
end_define

begin_define
define|#
directive|define
name|MBOX_SEND_CHANGE_REQUEST
value|0x0070
end_define

begin_define
define|#
directive|define
name|MBOX_FABRIC_LOGOUT
value|0x0071
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP_LOGIN
value|0x0072
end_define

begin_define
define|#
directive|define
name|MBOX_LUN_RESET
value|0x007E
end_define

begin_define
define|#
directive|define
name|MBOX_DRIVER_HEARTBEAT
value|0x005B
end_define

begin_define
define|#
directive|define
name|MBOX_FW_HEARTBEAT
value|0x005C
end_define

begin_define
define|#
directive|define
name|MBOX_GET_SET_DATA_RATE
value|0x005D
end_define

begin_comment
comment|/* 24XX/23XX only */
end_comment

begin_define
define|#
directive|define
name|MBGSD_GET_RATE
value|0
end_define

begin_define
define|#
directive|define
name|MBGSD_SET_RATE
value|1
end_define

begin_define
define|#
directive|define
name|MBGSD_SET_RATE_NOW
value|2
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|MBGSD_ONEGB
value|0
end_define

begin_define
define|#
directive|define
name|MBGSD_TWOGB
value|1
end_define

begin_define
define|#
directive|define
name|MBGSD_AUTO
value|2
end_define

begin_define
define|#
directive|define
name|MBGSD_FOURGB
value|3
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|ISP2100_SET_PCI_PARAM
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MBOX_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Mailbox Command Complete Status Codes  */
end_comment

begin_define
define|#
directive|define
name|MBOX_COMMAND_COMPLETE
value|0x4000
end_define

begin_define
define|#
directive|define
name|MBOX_INVALID_COMMAND
value|0x4001
end_define

begin_define
define|#
directive|define
name|MBOX_HOST_INTERFACE_ERROR
value|0x4002
end_define

begin_define
define|#
directive|define
name|MBOX_TEST_FAILED
value|0x4003
end_define

begin_define
define|#
directive|define
name|MBOX_COMMAND_ERROR
value|0x4005
end_define

begin_define
define|#
directive|define
name|MBOX_COMMAND_PARAM_ERROR
value|0x4006
end_define

begin_define
define|#
directive|define
name|MBOX_PORT_ID_USED
value|0x4007
end_define

begin_define
define|#
directive|define
name|MBOX_LOOP_ID_USED
value|0x4008
end_define

begin_define
define|#
directive|define
name|MBOX_ALL_IDS_USED
value|0x4009
end_define

begin_define
define|#
directive|define
name|MBOX_NOT_LOGGED_IN
value|0x400A
end_define

begin_comment
comment|/* pseudo mailbox completion codes */
end_comment

begin_define
define|#
directive|define
name|MBOX_REGS_BUSY
value|0x6000
end_define

begin_comment
comment|/* registers in use */
end_comment

begin_define
define|#
directive|define
name|MBOX_TIMEOUT
value|0x6001
end_define

begin_comment
comment|/* command timed out */
end_comment

begin_define
define|#
directive|define
name|MBLOGALL
value|0x000f
end_define

begin_define
define|#
directive|define
name|MBLOGNONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|MBLOGMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_comment
comment|/*  * Asynchronous event status codes  */
end_comment

begin_define
define|#
directive|define
name|ASYNC_BUS_RESET
value|0x8001
end_define

begin_define
define|#
directive|define
name|ASYNC_SYSTEM_ERROR
value|0x8002
end_define

begin_define
define|#
directive|define
name|ASYNC_RQS_XFER_ERR
value|0x8003
end_define

begin_define
define|#
directive|define
name|ASYNC_RSP_XFER_ERR
value|0x8004
end_define

begin_define
define|#
directive|define
name|ASYNC_QWAKEUP
value|0x8005
end_define

begin_define
define|#
directive|define
name|ASYNC_TIMEOUT_RESET
value|0x8006
end_define

begin_define
define|#
directive|define
name|ASYNC_DEVICE_RESET
value|0x8007
end_define

begin_define
define|#
directive|define
name|ASYNC_EXTMSG_UNDERRUN
value|0x800A
end_define

begin_define
define|#
directive|define
name|ASYNC_SCAM_INT
value|0x800B
end_define

begin_define
define|#
directive|define
name|ASYNC_HUNG_SCSI
value|0x800C
end_define

begin_define
define|#
directive|define
name|ASYNC_KILLED_BUS
value|0x800D
end_define

begin_define
define|#
directive|define
name|ASYNC_BUS_TRANSIT
value|0x800E
end_define

begin_comment
comment|/* LVD -> HVD, eg. */
end_comment

begin_define
define|#
directive|define
name|ASYNC_LIP_OCCURRED
value|0x8010
end_define

begin_define
define|#
directive|define
name|ASYNC_LOOP_UP
value|0x8011
end_define

begin_define
define|#
directive|define
name|ASYNC_LOOP_DOWN
value|0x8012
end_define

begin_define
define|#
directive|define
name|ASYNC_LOOP_RESET
value|0x8013
end_define

begin_define
define|#
directive|define
name|ASYNC_PDB_CHANGED
value|0x8014
end_define

begin_define
define|#
directive|define
name|ASYNC_CHANGE_NOTIFY
value|0x8015
end_define

begin_define
define|#
directive|define
name|ASYNC_LIP_F8
value|0x8016
end_define

begin_define
define|#
directive|define
name|ASYNC_LIP_ERROR
value|0x8017
end_define

begin_define
define|#
directive|define
name|ASYNC_SECURITY_UPDATE
value|0x801B
end_define

begin_define
define|#
directive|define
name|ASYNC_CMD_CMPLT
value|0x8020
end_define

begin_define
define|#
directive|define
name|ASYNC_CTIO_DONE
value|0x8021
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_XMIT_DONE
value|0x8022
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_RECV_DONE
value|0x8023
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_BROADCAST
value|0x8024
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_RCVQ_LOW
value|0x8025
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_RCVQ_EMPTY
value|0x8026
end_define

begin_define
define|#
directive|define
name|ASYNC_IP_RECV_DONE_ALIGNED
value|0x8027
end_define

begin_define
define|#
directive|define
name|ASYNC_PTPMODE
value|0x8030
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO1
value|0x8031
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO2
value|0x8032
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO3
value|0x8033
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO4
value|0x8034
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO5
value|0x8035
end_define

begin_define
define|#
directive|define
name|ASYNC_CONNMODE
value|0x8036
end_define

begin_define
define|#
directive|define
name|ISP_CONN_LOOP
value|1
end_define

begin_define
define|#
directive|define
name|ISP_CONN_PTP
value|2
end_define

begin_define
define|#
directive|define
name|ISP_CONN_BADLIP
value|3
end_define

begin_define
define|#
directive|define
name|ISP_CONN_FATAL
value|4
end_define

begin_define
define|#
directive|define
name|ISP_CONN_LOOPBACK
value|5
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO_RESP
value|0x8040
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO_COMP
value|0x8042
end_define

begin_define
define|#
directive|define
name|ASYNC_RCV_ERR
value|0x8048
end_define

begin_comment
comment|/*  * 2.01.31 2200 Only. Need Bit 13 in Mailbox 1 for Set Firmware Options  * mailbox command to enable this.  */
end_comment

begin_define
define|#
directive|define
name|ASYNC_QFULL_SENT
value|0x8049
end_define

begin_comment
comment|/*  * 24XX only  */
end_comment

begin_define
define|#
directive|define
name|ASYNC_RJT_SENT
value|0x8049
end_define

begin_comment
comment|/*  * All IOCB Queue entries are this size  */
end_comment

begin_define
define|#
directive|define
name|QENTRY_LEN
value|64
end_define

begin_comment
comment|/*  * Command Structure Definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ds_base
decl_stmt|;
name|uint32_t
name|ds_count
decl_stmt|;
block|}
name|ispds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|ds_base
decl_stmt|;
name|uint32_t
name|ds_basehi
decl_stmt|;
name|uint32_t
name|ds_count
decl_stmt|;
block|}
name|ispds64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSTYPE_32BIT
value|0
end_define

begin_define
define|#
directive|define
name|DSTYPE_64BIT
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|ds_type
decl_stmt|;
comment|/* 0-> ispds_t, 1-> ispds64_t */
name|uint32_t
name|ds_segment
decl_stmt|;
comment|/* unused */
name|uint32_t
name|ds_base
decl_stmt|;
comment|/* 32 bit address of DSD list */
block|}
name|ispdslist_t
typedef|;
end_typedef

begin_comment
comment|/*  * These elements get swizzled around for SBus instances.  */
end_comment

begin_define
define|#
directive|define
name|ISP_SWAP8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{		\ 	uint8_t tmp;			\ 	tmp = a;			\ 	a = b;				\ 	b = tmp;			\ }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|rqs_entry_type
decl_stmt|;
name|uint8_t
name|rqs_entry_count
decl_stmt|;
name|uint8_t
name|rqs_seqno
decl_stmt|;
name|uint8_t
name|rqs_flags
decl_stmt|;
block|}
name|isphdr_t
typedef|;
end_typedef

begin_comment
comment|/* RQS Flag definitions */
end_comment

begin_define
define|#
directive|define
name|RQSFLAG_CONTINUATION
value|0x01
end_define

begin_define
define|#
directive|define
name|RQSFLAG_FULL
value|0x02
end_define

begin_define
define|#
directive|define
name|RQSFLAG_BADHEADER
value|0x04
end_define

begin_define
define|#
directive|define
name|RQSFLAG_BADPACKET
value|0x08
end_define

begin_define
define|#
directive|define
name|RQSFLAG_MASK
value|0x0f
end_define

begin_comment
comment|/* RQS entry_type definitions */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|RQSTYPE_DATASEG
value|0x02
end_define

begin_define
define|#
directive|define
name|RQSTYPE_RESPONSE
value|0x03
end_define

begin_define
define|#
directive|define
name|RQSTYPE_MARKER
value|0x04
end_define

begin_define
define|#
directive|define
name|RQSTYPE_CMDONLY
value|0x05
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ATIO
value|0x06
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_CTIO
value|0x07
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_SCAM
value|0x08
end_define

begin_define
define|#
directive|define
name|RQSTYPE_A64
value|0x09
end_define

begin_define
define|#
directive|define
name|RQSTYPE_A64_CONT
value|0x0a
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ENABLE_LUN
value|0x0b
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_MODIFY_LUN
value|0x0c
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_NOTIFY
value|0x0d
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_NOTIFY_ACK
value|0x0e
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_CTIO1
value|0x0f
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_STATUS_CONT
value|0x10
end_define

begin_define
define|#
directive|define
name|RQSTYPE_T2RQS
value|0x11
end_define

begin_define
define|#
directive|define
name|RQSTYPE_CTIO7
value|0x12
end_define

begin_define
define|#
directive|define
name|RQSTYPE_IP_XMIT
value|0x13
end_define

begin_define
define|#
directive|define
name|RQSTYPE_TSK_MGMT
value|0x14
end_define

begin_define
define|#
directive|define
name|RQSTYPE_T4RQS
value|0x15
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ATIO2
value|0x16
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_CTIO2
value|0x17
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_T7RQS
value|0x18
end_define

begin_define
define|#
directive|define
name|RQSTYPE_T3RQS
value|0x19
end_define

begin_define
define|#
directive|define
name|RQSTYPE_IP_XMIT_64
value|0x1b
end_define

begin_define
define|#
directive|define
name|RQSTYPE_CTIO4
value|0x1e
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_CTIO3
value|0x1f
end_define

begin_comment
comment|/* Target Mode */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_RIO1
value|0x21
end_define

begin_define
define|#
directive|define
name|RQSTYPE_RIO2
value|0x22
end_define

begin_define
define|#
directive|define
name|RQSTYPE_IP_RECV
value|0x23
end_define

begin_define
define|#
directive|define
name|RQSTYPE_IP_RECV_CONT
value|0x24
end_define

begin_define
define|#
directive|define
name|RQSTYPE_CT_PASSTHRU
value|0x29
end_define

begin_define
define|#
directive|define
name|RQSTYPE_MS_PASSTHRU
value|0x29
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ABORT_IO
value|0x33
end_define

begin_define
define|#
directive|define
name|RQSTYPE_T6RQS
value|0x48
end_define

begin_define
define|#
directive|define
name|RQSTYPE_LOGIN
value|0x52
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ABTS_RCVD
value|0x54
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_ABTS_RSP
value|0x55
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|ISP_RQDSEG
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint8_t
name|req_lun_trn
decl_stmt|;
name|uint8_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_cdblen
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|12
index|]
decl_stmt|;
name|ispds_t
name|req_dataseg
index|[
name|ISP_RQDSEG
index|]
decl_stmt|;
block|}
name|ispreq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP_RQDSEG_A64
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|mrk_header
decl_stmt|;
name|uint32_t
name|mrk_handle
decl_stmt|;
name|uint8_t
name|mrk_reserved0
decl_stmt|;
name|uint8_t
name|mrk_target
decl_stmt|;
name|uint16_t
name|mrk_modifier
decl_stmt|;
name|uint16_t
name|mrk_flags
decl_stmt|;
name|uint16_t
name|mrk_lun
decl_stmt|;
name|uint8_t
name|mrk_reserved1
index|[
literal|48
index|]
decl_stmt|;
block|}
name|isp_marker_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|mrk_header
decl_stmt|;
name|uint32_t
name|mrk_handle
decl_stmt|;
name|uint16_t
name|mrk_nphdl
decl_stmt|;
name|uint8_t
name|mrk_modifier
decl_stmt|;
name|uint8_t
name|mrk_reserved0
decl_stmt|;
name|uint8_t
name|mrk_reserved1
decl_stmt|;
name|uint8_t
name|mrk_vphdl
decl_stmt|;
name|uint16_t
name|mrk_reserved2
decl_stmt|;
name|uint8_t
name|mrk_lun
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|mrk_reserved3
index|[
literal|40
index|]
decl_stmt|;
block|}
name|isp_marker_24xx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SYNC_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|SYNC_TARGET
value|1
end_define

begin_define
define|#
directive|define
name|SYNC_ALL
value|2
end_define

begin_define
define|#
directive|define
name|SYNC_LIP
value|3
end_define

begin_define
define|#
directive|define
name|ISP_RQDSEG_T2
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint8_t
name|req_lun_trn
decl_stmt|;
name|uint8_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_scclun
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|req_totalcnt
decl_stmt|;
name|ispds_t
name|req_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
block|}
name|ispreqt2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_scclun
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|req_totalcnt
decl_stmt|;
name|ispds_t
name|req_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
block|}
name|ispreqt2e_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP_RQDSEG_T3
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint8_t
name|req_lun_trn
decl_stmt|;
name|uint8_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_scclun
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|req_totalcnt
decl_stmt|;
name|ispds64_t
name|req_dataseg
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
block|}
name|ispreqt3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ispreq64_t
value|ispreqt3_t
end_define

begin_comment
comment|/* same as.... */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_scclun
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|req_totalcnt
decl_stmt|;
name|ispds64_t
name|req_dataseg
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
block|}
name|ispreqt3e_t
typedef|;
end_typedef

begin_comment
comment|/* req_flag values */
end_comment

begin_define
define|#
directive|define
name|REQFLAG_NODISCON
value|0x0001
end_define

begin_define
define|#
directive|define
name|REQFLAG_HTAG
value|0x0002
end_define

begin_define
define|#
directive|define
name|REQFLAG_OTAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|REQFLAG_STAG
value|0x0008
end_define

begin_define
define|#
directive|define
name|REQFLAG_TARGET_RTN
value|0x0010
end_define

begin_define
define|#
directive|define
name|REQFLAG_NODATA
value|0x0000
end_define

begin_define
define|#
directive|define
name|REQFLAG_DATA_IN
value|0x0020
end_define

begin_define
define|#
directive|define
name|REQFLAG_DATA_OUT
value|0x0040
end_define

begin_define
define|#
directive|define
name|REQFLAG_DATA_UNKNOWN
value|0x0060
end_define

begin_define
define|#
directive|define
name|REQFLAG_DISARQ
value|0x0100
end_define

begin_define
define|#
directive|define
name|REQFLAG_FRC_ASYNC
value|0x0200
end_define

begin_define
define|#
directive|define
name|REQFLAG_FRC_SYNC
value|0x0400
end_define

begin_define
define|#
directive|define
name|REQFLAG_FRC_WIDE
value|0x0800
end_define

begin_define
define|#
directive|define
name|REQFLAG_NOPARITY
value|0x1000
end_define

begin_define
define|#
directive|define
name|REQFLAG_STOPQ
value|0x2000
end_define

begin_define
define|#
directive|define
name|REQFLAG_XTRASNS
value|0x4000
end_define

begin_define
define|#
directive|define
name|REQFLAG_PRIORITY
value|0x8000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint8_t
name|req_lun_trn
decl_stmt|;
name|uint8_t
name|req_target
decl_stmt|;
name|uint16_t
name|req_cdblen
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|44
index|]
decl_stmt|;
block|}
name|ispextreq_t
typedef|;
end_typedef

begin_comment
comment|/* 24XX only */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|fcd_length
decl_stmt|;
name|uint16_t
name|fcd_a1500
decl_stmt|;
name|uint16_t
name|fcd_a3116
decl_stmt|;
name|uint16_t
name|fcd_a4732
decl_stmt|;
name|uint16_t
name|fcd_a6348
decl_stmt|;
block|}
name|fcp_cmnd_ds_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_nphdl
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint16_t
name|req_fc_rsp_dsd_length
decl_stmt|;
name|uint8_t
name|req_lun
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|req_flags
decl_stmt|;
name|uint16_t
name|req_fc_cmnd_dsd_length
decl_stmt|;
name|uint16_t
name|req_fc_cmnd_dsd_a1500
decl_stmt|;
name|uint16_t
name|req_fc_cmnd_dsd_a3116
decl_stmt|;
name|uint16_t
name|req_fc_cmnd_dsd_a4732
decl_stmt|;
name|uint16_t
name|req_fc_cmnd_dsd_a6348
decl_stmt|;
name|uint16_t
name|req_fc_rsp_dsd_a1500
decl_stmt|;
name|uint16_t
name|req_fc_rsp_dsd_a3116
decl_stmt|;
name|uint16_t
name|req_fc_rsp_dsd_a4732
decl_stmt|;
name|uint16_t
name|req_fc_rsp_dsd_a6348
decl_stmt|;
name|uint32_t
name|req_totalcnt
decl_stmt|;
name|uint16_t
name|req_tidlo
decl_stmt|;
name|uint8_t
name|req_tidhi
decl_stmt|;
name|uint8_t
name|req_vpidx
decl_stmt|;
name|ispds64_t
name|req_dataseg
decl_stmt|;
block|}
name|ispreqt6_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_nphdl
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
name|uint16_t
name|req_seg_count
decl_stmt|;
name|uint16_t
name|req_reserved
decl_stmt|;
name|uint8_t
name|req_lun
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|req_alen_datadir
decl_stmt|;
name|uint8_t
name|req_task_management
decl_stmt|;
name|uint8_t
name|req_task_attribute
decl_stmt|;
name|uint8_t
name|req_crn
decl_stmt|;
name|uint8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|req_dl
decl_stmt|;
name|uint16_t
name|req_tidlo
decl_stmt|;
name|uint8_t
name|req_tidhi
decl_stmt|;
name|uint8_t
name|req_vpidx
decl_stmt|;
name|ispds64_t
name|req_dataseg
decl_stmt|;
block|}
name|ispreqt7_t
typedef|;
end_typedef

begin_comment
comment|/* I/O Abort Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|abrt_header
decl_stmt|;
name|uint32_t
name|abrt_handle
decl_stmt|;
name|uint16_t
name|abrt_nphdl
decl_stmt|;
name|uint16_t
name|abrt_options
decl_stmt|;
name|uint32_t
name|abrt_cmd_handle
decl_stmt|;
name|uint8_t
name|abrt_reserved
index|[
literal|32
index|]
decl_stmt|;
name|uint16_t
name|abrt_tidlo
decl_stmt|;
name|uint8_t
name|abrt_tidhi
decl_stmt|;
name|uint8_t
name|abrt_vpidx
decl_stmt|;
name|uint8_t
name|abrt_reserved1
index|[
literal|12
index|]
decl_stmt|;
block|}
name|isp24xx_abrt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP24XX_ABRT_NO_ABTS
value|0x01
end_define

begin_comment
comment|/* don't actually send an ABTS */
end_comment

begin_define
define|#
directive|define
name|ISP24XX_ABRT_ENXIO
value|0x31
end_define

begin_comment
comment|/* in nphdl on return */
end_comment

begin_define
define|#
directive|define
name|ISP_CDSEG
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_reserved
decl_stmt|;
name|ispds_t
name|req_dataseg
index|[
name|ISP_CDSEG
index|]
decl_stmt|;
block|}
name|ispcontreq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP_CDSEG64
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|ispds64_t
name|req_dataseg
index|[
name|ISP_CDSEG64
index|]
decl_stmt|;
block|}
name|ispcontreq64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_scsi_status
decl_stmt|;
name|uint16_t
name|req_completion_status
decl_stmt|;
name|uint16_t
name|req_state_flags
decl_stmt|;
name|uint16_t
name|req_status_flags
decl_stmt|;
name|uint16_t
name|req_time
decl_stmt|;
define|#
directive|define
name|req_response_len
value|req_time
comment|/* FC only */
name|uint16_t
name|req_sense_len
decl_stmt|;
name|uint32_t
name|req_resid
decl_stmt|;
name|uint8_t
name|req_response
index|[
literal|8
index|]
decl_stmt|;
comment|/* FC only */
name|uint8_t
name|req_sense_data
index|[
literal|32
index|]
decl_stmt|;
block|}
name|ispstatusreq_t
typedef|;
end_typedef

begin_comment
comment|/*  * Status Continuation  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint8_t
name|req_sense_data
index|[
literal|60
index|]
decl_stmt|;
block|}
name|ispstatus_cont_t
typedef|;
end_typedef

begin_comment
comment|/*  * 24XX Type 0 status  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handle
decl_stmt|;
name|uint16_t
name|req_completion_status
decl_stmt|;
name|uint16_t
name|req_oxid
decl_stmt|;
name|uint32_t
name|req_resid
decl_stmt|;
name|uint16_t
name|req_reserved0
decl_stmt|;
name|uint16_t
name|req_state_flags
decl_stmt|;
name|uint16_t
name|req_reserved1
decl_stmt|;
name|uint16_t
name|req_scsi_status
decl_stmt|;
name|uint32_t
name|req_fcp_residual
decl_stmt|;
name|uint32_t
name|req_sense_len
decl_stmt|;
name|uint32_t
name|req_response_len
decl_stmt|;
name|uint8_t
name|req_rsp_sense
index|[
literal|28
index|]
decl_stmt|;
block|}
name|isp24xx_statusreq_t
typedef|;
end_typedef

begin_comment
comment|/*   * For Qlogic 2X00, the high order byte of SCSI status has  * additional meaning.  */
end_comment

begin_define
define|#
directive|define
name|RQCS_RU
value|0x800
end_define

begin_comment
comment|/* Residual Under */
end_comment

begin_define
define|#
directive|define
name|RQCS_RO
value|0x400
end_define

begin_comment
comment|/* Residual Over */
end_comment

begin_define
define|#
directive|define
name|RQCS_RESID
value|(RQCS_RU|RQCS_RO)
end_define

begin_define
define|#
directive|define
name|RQCS_SV
value|0x200
end_define

begin_comment
comment|/* Sense Length Valid */
end_comment

begin_define
define|#
directive|define
name|RQCS_RV
value|0x100
end_define

begin_comment
comment|/* FCP Response Length Valid */
end_comment

begin_comment
comment|/*  * CT Passthru IOCB  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ctp_header
decl_stmt|;
name|uint32_t
name|ctp_handle
decl_stmt|;
name|uint16_t
name|ctp_status
decl_stmt|;
name|uint16_t
name|ctp_nphdl
decl_stmt|;
comment|/* n-port handle */
name|uint16_t
name|ctp_cmd_cnt
decl_stmt|;
comment|/* Command DSD count */
name|uint16_t
name|ctp_vpidx
decl_stmt|;
comment|/* low 8 bits */
name|uint16_t
name|ctp_time
decl_stmt|;
name|uint16_t
name|ctp_reserved0
decl_stmt|;
name|uint16_t
name|ctp_rsp_cnt
decl_stmt|;
comment|/* Response DSD count */
name|uint16_t
name|ctp_reserved1
index|[
literal|5
index|]
decl_stmt|;
name|uint32_t
name|ctp_rsp_bcnt
decl_stmt|;
comment|/* Response byte count */
name|uint32_t
name|ctp_cmd_bcnt
decl_stmt|;
comment|/* Command byte count */
name|ispds64_t
name|ctp_dataseg
index|[
literal|2
index|]
decl_stmt|;
block|}
name|isp_ct_pt_t
typedef|;
end_typedef

begin_comment
comment|/*  * MS Passthru IOCB  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ms_header
decl_stmt|;
name|uint32_t
name|ms_handle
decl_stmt|;
name|uint16_t
name|ms_nphdl
decl_stmt|;
comment|/* handle in high byte for !2k f/w */
name|uint16_t
name|ms_status
decl_stmt|;
name|uint16_t
name|ms_flags
decl_stmt|;
name|uint16_t
name|ms_reserved1
decl_stmt|;
comment|/* low 8 bits */
name|uint16_t
name|ms_time
decl_stmt|;
name|uint16_t
name|ms_cmd_cnt
decl_stmt|;
comment|/* Command DSD count */
empty_stmt|;
name|uint16_t
name|ms_tot_cnt
decl_stmt|;
comment|/* Total DSD Count */
name|uint8_t
name|ms_type
decl_stmt|;
comment|/* MS type */
name|uint8_t
name|ms_r_ctl
decl_stmt|;
comment|/* R_CTL */
name|uint16_t
name|ms_rxid
decl_stmt|;
comment|/* RX_ID */
name|uint16_t
name|ms_reserved2
decl_stmt|;
name|uint32_t
name|ms_handle2
decl_stmt|;
name|uint32_t
name|ms_rsp_bcnt
decl_stmt|;
comment|/* Response byte count */
name|uint32_t
name|ms_cmd_bcnt
decl_stmt|;
comment|/* Command byte count */
name|ispds64_t
name|ms_dataseg
index|[
literal|2
index|]
decl_stmt|;
block|}
name|isp_ms_t
typedef|;
end_typedef

begin_comment
comment|/*   * Completion Status Codes.  */
end_comment

begin_define
define|#
directive|define
name|RQCS_COMPLETE
value|0x0000
end_define

begin_define
define|#
directive|define
name|RQCS_DMA_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|RQCS_RESET_OCCURRED
value|0x0004
end_define

begin_define
define|#
directive|define
name|RQCS_ABORTED
value|0x0005
end_define

begin_define
define|#
directive|define
name|RQCS_TIMEOUT
value|0x0006
end_define

begin_define
define|#
directive|define
name|RQCS_DATA_OVERRUN
value|0x0007
end_define

begin_define
define|#
directive|define
name|RQCS_DATA_UNDERRUN
value|0x0015
end_define

begin_define
define|#
directive|define
name|RQCS_QUEUE_FULL
value|0x001C
end_define

begin_comment
comment|/* 1X00 Only Completion Codes */
end_comment

begin_define
define|#
directive|define
name|RQCS_INCOMPLETE
value|0x0001
end_define

begin_define
define|#
directive|define
name|RQCS_TRANSPORT_ERROR
value|0x0003
end_define

begin_define
define|#
directive|define
name|RQCS_COMMAND_OVERRUN
value|0x0008
end_define

begin_define
define|#
directive|define
name|RQCS_STATUS_OVERRUN
value|0x0009
end_define

begin_define
define|#
directive|define
name|RQCS_BAD_MESSAGE
value|0x000a
end_define

begin_define
define|#
directive|define
name|RQCS_NO_MESSAGE_OUT
value|0x000b
end_define

begin_define
define|#
directive|define
name|RQCS_EXT_ID_FAILED
value|0x000c
end_define

begin_define
define|#
directive|define
name|RQCS_IDE_MSG_FAILED
value|0x000d
end_define

begin_define
define|#
directive|define
name|RQCS_ABORT_MSG_FAILED
value|0x000e
end_define

begin_define
define|#
directive|define
name|RQCS_REJECT_MSG_FAILED
value|0x000f
end_define

begin_define
define|#
directive|define
name|RQCS_NOP_MSG_FAILED
value|0x0010
end_define

begin_define
define|#
directive|define
name|RQCS_PARITY_ERROR_MSG_FAILED
value|0x0011
end_define

begin_define
define|#
directive|define
name|RQCS_DEVICE_RESET_MSG_FAILED
value|0x0012
end_define

begin_define
define|#
directive|define
name|RQCS_ID_MSG_FAILED
value|0x0013
end_define

begin_define
define|#
directive|define
name|RQCS_UNEXP_BUS_FREE
value|0x0014
end_define

begin_define
define|#
directive|define
name|RQCS_XACT_ERR1
value|0x0018
end_define

begin_define
define|#
directive|define
name|RQCS_XACT_ERR2
value|0x0019
end_define

begin_define
define|#
directive|define
name|RQCS_XACT_ERR3
value|0x001A
end_define

begin_define
define|#
directive|define
name|RQCS_BAD_ENTRY
value|0x001B
end_define

begin_define
define|#
directive|define
name|RQCS_PHASE_SKIPPED
value|0x001D
end_define

begin_define
define|#
directive|define
name|RQCS_ARQS_FAILED
value|0x001E
end_define

begin_define
define|#
directive|define
name|RQCS_WIDE_FAILED
value|0x001F
end_define

begin_define
define|#
directive|define
name|RQCS_SYNCXFER_FAILED
value|0x0020
end_define

begin_define
define|#
directive|define
name|RQCS_LVD_BUSERR
value|0x0021
end_define

begin_comment
comment|/* 2X00 Only Completion Codes */
end_comment

begin_define
define|#
directive|define
name|RQCS_PORT_UNAVAILABLE
value|0x0028
end_define

begin_define
define|#
directive|define
name|RQCS_PORT_LOGGED_OUT
value|0x0029
end_define

begin_define
define|#
directive|define
name|RQCS_PORT_CHANGED
value|0x002A
end_define

begin_define
define|#
directive|define
name|RQCS_PORT_BUSY
value|0x002B
end_define

begin_comment
comment|/* 24XX Only Completion Codes */
end_comment

begin_define
define|#
directive|define
name|RQCS_24XX_DRE
value|0x0011
end_define

begin_comment
comment|/* data reassembly error */
end_comment

begin_define
define|#
directive|define
name|RQCS_24XX_TABORT
value|0x0013
end_define

begin_comment
comment|/* aborted by target */
end_comment

begin_define
define|#
directive|define
name|RQCS_24XX_ENOMEM
value|0x002C
end_define

begin_comment
comment|/* f/w resource unavailable */
end_comment

begin_define
define|#
directive|define
name|RQCS_24XX_TMO
value|0x0030
end_define

begin_comment
comment|/* task management overrun */
end_comment

begin_comment
comment|/*  * 1X00 specific State Flags   */
end_comment

begin_define
define|#
directive|define
name|RQSF_GOT_BUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|RQSF_GOT_TARGET
value|0x0200
end_define

begin_define
define|#
directive|define
name|RQSF_SENT_CDB
value|0x0400
end_define

begin_define
define|#
directive|define
name|RQSF_XFRD_DATA
value|0x0800
end_define

begin_define
define|#
directive|define
name|RQSF_GOT_STATUS
value|0x1000
end_define

begin_define
define|#
directive|define
name|RQSF_GOT_SENSE
value|0x2000
end_define

begin_define
define|#
directive|define
name|RQSF_XFER_COMPLETE
value|0x4000
end_define

begin_comment
comment|/*  * 2X00 specific State Flags  * (same as 1X00 except RQSF_GOT_BUS/RQSF_GOT_TARGET are not available)  */
end_comment

begin_define
define|#
directive|define
name|RQSF_DATA_IN
value|0x0020
end_define

begin_define
define|#
directive|define
name|RQSF_DATA_OUT
value|0x0040
end_define

begin_define
define|#
directive|define
name|RQSF_STAG
value|0x0008
end_define

begin_define
define|#
directive|define
name|RQSF_OTAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|RQSF_HTAG
value|0x0002
end_define

begin_comment
comment|/*  * 1X00 Status Flags  */
end_comment

begin_define
define|#
directive|define
name|RQSTF_DISCONNECT
value|0x0001
end_define

begin_define
define|#
directive|define
name|RQSTF_SYNCHRONOUS
value|0x0002
end_define

begin_define
define|#
directive|define
name|RQSTF_PARITY_ERROR
value|0x0004
end_define

begin_define
define|#
directive|define
name|RQSTF_BUS_RESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|RQSTF_DEVICE_RESET
value|0x0010
end_define

begin_define
define|#
directive|define
name|RQSTF_ABORTED
value|0x0020
end_define

begin_define
define|#
directive|define
name|RQSTF_TIMEOUT
value|0x0040
end_define

begin_define
define|#
directive|define
name|RQSTF_NEGOTIATION
value|0x0080
end_define

begin_comment
comment|/*  * 2X00 specific state flags  */
end_comment

begin_comment
comment|/* RQSF_SENT_CDB	*/
end_comment

begin_comment
comment|/* RQSF_XFRD_DATA	*/
end_comment

begin_comment
comment|/* RQSF_GOT_STATUS	*/
end_comment

begin_comment
comment|/* RQSF_XFER_COMPLETE	*/
end_comment

begin_comment
comment|/*  * 2X00 specific status flags  */
end_comment

begin_comment
comment|/* RQSTF_ABORTED */
end_comment

begin_comment
comment|/* RQSTF_TIMEOUT */
end_comment

begin_define
define|#
directive|define
name|RQSTF_DMA_ERROR
value|0x0080
end_define

begin_define
define|#
directive|define
name|RQSTF_LOGOUT
value|0x2000
end_define

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISP_EXEC_THROTTLE
end_ifndef

begin_define
define|#
directive|define
name|ISP_EXEC_THROTTLE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * About Firmware returns an 'attribute' word in mailbox 6.  * These attributes are for 2200 and 2300.  */
end_comment

begin_define
define|#
directive|define
name|ISP_FW_ATTR_TMODE
value|0x01
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_SCCLUN
value|0x02
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_FABRIC
value|0x04
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_CLASS2
value|0x08
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_FCTAPE
value|0x10
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_IP
value|0x20
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_VI
value|0x40
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_VI_SOLARIS
value|0x80
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_2KLOGINS
value|0x100
end_define

begin_comment
comment|/* XXX: just a guess */
end_comment

begin_comment
comment|/* and these are for the 2400 */
end_comment

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_CLASS2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_IP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_MULTIID
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_SB2
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_T10CRC
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_VI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_EXPFW
value|(1<< 13)
end_define

begin_comment
comment|/*  * Reduced Interrupt Operation Response Queue Entreis  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint32_t
name|req_handles
index|[
literal|15
index|]
decl_stmt|;
block|}
name|isp_rio1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|uint16_t
name|req_handles
index|[
literal|30
index|]
decl_stmt|;
block|}
name|isp_rio2_t
typedef|;
end_typedef

begin_comment
comment|/*  * FC (ISP2100/ISP2200/ISP2300/ISP2400) specific data structures  */
end_comment

begin_comment
comment|/*  * Initialization Control Block  *  * Version One (prime) format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|icb_version
decl_stmt|;
name|uint8_t
name|icb_reserved0
decl_stmt|;
name|uint16_t
name|icb_fwoptions
decl_stmt|;
name|uint16_t
name|icb_maxfrmlen
decl_stmt|;
name|uint16_t
name|icb_maxalloc
decl_stmt|;
name|uint16_t
name|icb_execthrottle
decl_stmt|;
name|uint8_t
name|icb_retry_count
decl_stmt|;
name|uint8_t
name|icb_retry_delay
decl_stmt|;
name|uint8_t
name|icb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|icb_hardaddr
decl_stmt|;
name|uint8_t
name|icb_iqdevtype
decl_stmt|;
name|uint8_t
name|icb_logintime
decl_stmt|;
name|uint8_t
name|icb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|icb_rqstout
decl_stmt|;
name|uint16_t
name|icb_rspnsin
decl_stmt|;
name|uint16_t
name|icb_rqstqlen
decl_stmt|;
name|uint16_t
name|icb_rsltqlen
decl_stmt|;
name|uint16_t
name|icb_rqstaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_respaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_lunenables
decl_stmt|;
name|uint8_t
name|icb_ccnt
decl_stmt|;
name|uint8_t
name|icb_icnt
decl_stmt|;
name|uint16_t
name|icb_lunetimeout
decl_stmt|;
name|uint16_t
name|icb_reserved1
decl_stmt|;
name|uint16_t
name|icb_xfwoptions
decl_stmt|;
name|uint8_t
name|icb_racctimer
decl_stmt|;
name|uint8_t
name|icb_idelaytimer
decl_stmt|;
name|uint16_t
name|icb_zfwoptions
decl_stmt|;
name|uint16_t
name|icb_reserved2
index|[
literal|13
index|]
decl_stmt|;
block|}
name|isp_icb_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ICB_VERSION1
value|1
end_define

begin_define
define|#
directive|define
name|ICBOPT_EXTENDED
value|0x8000
end_define

begin_define
define|#
directive|define
name|ICBOPT_BOTH_WWNS
value|0x4000
end_define

begin_define
define|#
directive|define
name|ICBOPT_FULL_LOGIN
value|0x2000
end_define

begin_define
define|#
directive|define
name|ICBOPT_STOP_ON_QFULL
value|0x1000
end_define

begin_comment
comment|/* 2200/2100 only */
end_comment

begin_define
define|#
directive|define
name|ICBOPT_PREVLOOP
value|0x0800
end_define

begin_define
define|#
directive|define
name|ICBOPT_SRCHDOWN
value|0x0400
end_define

begin_define
define|#
directive|define
name|ICBOPT_NOLIP
value|0x0200
end_define

begin_define
define|#
directive|define
name|ICBOPT_PDBCHANGE_AE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ICBOPT_INI_TGTTYPE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ICBOPT_INI_ADISC
value|0x0040
end_define

begin_define
define|#
directive|define
name|ICBOPT_INI_DISABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ICBOPT_TGT_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|ICBOPT_FAST_POST
value|0x0008
end_define

begin_define
define|#
directive|define
name|ICBOPT_FULL_DUPLEX
value|0x0004
end_define

begin_define
define|#
directive|define
name|ICBOPT_FAIRNESS
value|0x0002
end_define

begin_define
define|#
directive|define
name|ICBOPT_HARD_ADDRESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|ICBXOPT_NO_LOGOUT
value|0x8000
end_define

begin_comment
comment|/* no logout on link failure */
end_comment

begin_define
define|#
directive|define
name|ICBXOPT_FCTAPE_CCQ
value|0x4000
end_define

begin_comment
comment|/* FC-Tape Command Queueing */
end_comment

begin_define
define|#
directive|define
name|ICBXOPT_FCTAPE_CONFIRM
value|0x2000
end_define

begin_define
define|#
directive|define
name|ICBXOPT_FCTAPE
value|0x1000
end_define

begin_define
define|#
directive|define
name|ICBXOPT_CLASS2_ACK0
value|0x0200
end_define

begin_define
define|#
directive|define
name|ICBXOPT_CLASS2
value|0x0100
end_define

begin_define
define|#
directive|define
name|ICBXOPT_NO_PLAY
value|0x0080
end_define

begin_comment
comment|/* don't play if can't get hard addr */
end_comment

begin_define
define|#
directive|define
name|ICBXOPT_TOPO_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|ICBXOPT_LOOP_ONLY
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICBXOPT_PTP_ONLY
value|0x0010
end_define

begin_define
define|#
directive|define
name|ICBXOPT_LOOP_2_PTP
value|0x0020
end_define

begin_define
define|#
directive|define
name|ICBXOPT_PTP_2_LOOP
value|0x0030
end_define

begin_comment
comment|/*  * The lower 4 bits of the xfwoptions field are the OPERATION MODE bits.  * RIO is not defined for the 23XX cards (just 2200)  */
end_comment

begin_define
define|#
directive|define
name|ICBXOPT_RIO_OFF
value|0
end_define

begin_define
define|#
directive|define
name|ICBXOPT_RIO_16BIT
value|1
end_define

begin_define
define|#
directive|define
name|ICBXOPT_RIO_32BIT
value|2
end_define

begin_define
define|#
directive|define
name|ICBXOPT_RIO_16BIT_IOCB
value|3
end_define

begin_define
define|#
directive|define
name|ICBXOPT_RIO_32BIT_IOCB
value|4
end_define

begin_define
define|#
directive|define
name|ICBXOPT_ZIO
value|5
end_define

begin_define
define|#
directive|define
name|ICBXOPT_TIMER_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_ONEGB
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_AUTO
value|0x8000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_TWOGB
value|0x4000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_50_OHM
value|0x2000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_ENA_OOF
value|0x0040
end_define

begin_comment
comment|/* out of order frame handling */
end_comment

begin_define
define|#
directive|define
name|ICBZOPT_RSPSZ_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RSPSZ_24
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RSPSZ_12
value|0x0010
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RSPSZ_24A
value|0x0020
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RSPSZ_32
value|0x0030
end_define

begin_define
define|#
directive|define
name|ICBZOPT_SOFTID
value|0x0002
end_define

begin_define
define|#
directive|define
name|ICBZOPT_ENA_RDXFR_RDY
value|0x0001
end_define

begin_comment
comment|/* 2400 F/W options */
end_comment

begin_define
define|#
directive|define
name|ICB2400_OPT1_BOTH_WWNS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_FULL_LOGIN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_PREVLOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_SRCHDOWN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_NOLIP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_INI_DISABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_TGT_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_FULL_DUPLEX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_FAIRNESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT1_HARD_ADDRESS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_FCTAPE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_CLASS2_ACK0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_CLASS2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_NO_PLAY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_TOPO_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_LOOP_ONLY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_PTP_ONLY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_LOOP_2_PTP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_PTP_2_LOOP
value|0x00000030
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_TIMER_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ZIO
value|0x00000005
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ZIO1
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_75_OHM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_MASK
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_ONEGB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_TWOGB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_AUTO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_FOURGB
value|0x00006000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_ENA_OOF_XFRDY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_NO_LOCAL_PLOGI
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_ENA_OOF
value|0x00000040
end_define

begin_comment
comment|/* note that a response size flag of zero is reserved! */
end_comment

begin_define
define|#
directive|define
name|ICB2400_OPT3_RSPSZ_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RSPSZ_12
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RSPSZ_24
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RSPSZ_32
value|0x00000030
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_SOFTID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ICB_MIN_FRMLEN
value|256
end_define

begin_define
define|#
directive|define
name|ICB_MAX_FRMLEN
value|2112
end_define

begin_define
define|#
directive|define
name|ICB_DFLT_FRMLEN
value|1024
end_define

begin_define
define|#
directive|define
name|ICB_DFLT_ALLOC
value|256
end_define

begin_define
define|#
directive|define
name|ICB_DFLT_THROTTLE
value|16
end_define

begin_define
define|#
directive|define
name|ICB_DFLT_RDELAY
value|5
end_define

begin_define
define|#
directive|define
name|ICB_DFLT_RCOUNT
value|3
end_define

begin_define
define|#
directive|define
name|ICB_LOGIN_TOV
value|30
end_define

begin_define
define|#
directive|define
name|ICB_LUN_ENABLE_TOV
value|180
end_define

begin_comment
comment|/*  * And somebody at QLogic had a great idea that you could just change  * the structure *and* keep the version number the same as the other cards.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|icb_version
decl_stmt|;
name|uint16_t
name|icb_reserved0
decl_stmt|;
name|uint16_t
name|icb_maxfrmlen
decl_stmt|;
name|uint16_t
name|icb_execthrottle
decl_stmt|;
name|uint16_t
name|icb_xchgcnt
decl_stmt|;
name|uint16_t
name|icb_hardaddr
decl_stmt|;
name|uint8_t
name|icb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|icb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|icb_rspnsin
decl_stmt|;
name|uint16_t
name|icb_rqstout
decl_stmt|;
name|uint16_t
name|icb_retry_count
decl_stmt|;
name|uint16_t
name|icb_priout
decl_stmt|;
name|uint16_t
name|icb_rsltqlen
decl_stmt|;
name|uint16_t
name|icb_rqstqlen
decl_stmt|;
name|uint16_t
name|icb_ldn_nols
decl_stmt|;
name|uint16_t
name|icb_prqstqlen
decl_stmt|;
name|uint16_t
name|icb_rqstaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_respaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_priaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_reserved1
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_atio_in
decl_stmt|;
name|uint16_t
name|icb_atioqlen
decl_stmt|;
name|uint16_t
name|icb_atioqaddr
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|icb_idelaytimer
decl_stmt|;
name|uint16_t
name|icb_logintime
decl_stmt|;
name|uint32_t
name|icb_fwoptions1
decl_stmt|;
name|uint32_t
name|icb_fwoptions2
decl_stmt|;
name|uint32_t
name|icb_fwoptions3
decl_stmt|;
name|uint16_t
name|icb_reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|isp_icb_2400_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RQRSP_ADDR0015
value|0
end_define

begin_define
define|#
directive|define
name|RQRSP_ADDR1631
value|1
end_define

begin_define
define|#
directive|define
name|RQRSP_ADDR3247
value|2
end_define

begin_define
define|#
directive|define
name|RQRSP_ADDR4863
value|3
end_define

begin_define
define|#
directive|define
name|ICB_NNM0
value|7
end_define

begin_define
define|#
directive|define
name|ICB_NNM1
value|6
end_define

begin_define
define|#
directive|define
name|ICB_NNM2
value|5
end_define

begin_define
define|#
directive|define
name|ICB_NNM3
value|4
end_define

begin_define
define|#
directive|define
name|ICB_NNM4
value|3
end_define

begin_define
define|#
directive|define
name|ICB_NNM5
value|2
end_define

begin_define
define|#
directive|define
name|ICB_NNM6
value|1
end_define

begin_define
define|#
directive|define
name|ICB_NNM7
value|0
end_define

begin_define
define|#
directive|define
name|MAKE_NODE_NAME_FROM_WWN
parameter_list|(
name|array
parameter_list|,
name|wwn
parameter_list|)
define|\
value|array[ICB_NNM0] = (uint8_t) ((wwn>>  0)& 0xff), \ 	array[ICB_NNM1] = (uint8_t) ((wwn>>  8)& 0xff), \ 	array[ICB_NNM2] = (uint8_t) ((wwn>> 16)& 0xff), \ 	array[ICB_NNM3] = (uint8_t) ((wwn>> 24)& 0xff), \ 	array[ICB_NNM4] = (uint8_t) ((wwn>> 32)& 0xff), \ 	array[ICB_NNM5] = (uint8_t) ((wwn>> 40)& 0xff), \ 	array[ICB_NNM6] = (uint8_t) ((wwn>> 48)& 0xff), \ 	array[ICB_NNM7] = (uint8_t) ((wwn>> 56)& 0xff)
end_define

begin_define
define|#
directive|define
name|MAKE_WWN_FROM_NODE_NAME
parameter_list|(
name|wwn
parameter_list|,
name|array
parameter_list|)
define|\
value|wwn =	((uint64_t) array[ICB_NNM0]) | \ 		((uint64_t) array[ICB_NNM1]<<  8) | \ 		((uint64_t) array[ICB_NNM2]<< 16) | \ 		((uint64_t) array[ICB_NNM3]<< 24) | \ 		((uint64_t) array[ICB_NNM4]<< 32) | \ 		((uint64_t) array[ICB_NNM5]<< 40) | \ 		((uint64_t) array[ICB_NNM6]<< 48) | \ 		((uint64_t) array[ICB_NNM7]<< 56)
end_define

begin_comment
comment|/*  * Port Data Base Element  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pdb_options
decl_stmt|;
name|uint8_t
name|pdb_mstate
decl_stmt|;
name|uint8_t
name|pdb_sstate
decl_stmt|;
name|uint8_t
name|pdb_hardaddr_bits
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|pdb_portid_bits
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|pdb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|pdb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|pdb_execthrottle
decl_stmt|;
name|uint16_t
name|pdb_exec_count
decl_stmt|;
name|uint8_t
name|pdb_retry_count
decl_stmt|;
name|uint8_t
name|pdb_retry_delay
decl_stmt|;
name|uint16_t
name|pdb_resalloc
decl_stmt|;
name|uint16_t
name|pdb_curalloc
decl_stmt|;
name|uint16_t
name|pdb_qhead
decl_stmt|;
name|uint16_t
name|pdb_qtail
decl_stmt|;
name|uint16_t
name|pdb_tl_next
decl_stmt|;
name|uint16_t
name|pdb_tl_last
decl_stmt|;
name|uint16_t
name|pdb_features
decl_stmt|;
comment|/* PLOGI, Common Service */
name|uint16_t
name|pdb_pconcurrnt
decl_stmt|;
comment|/* PLOGI, Common Service */
name|uint16_t
name|pdb_roi
decl_stmt|;
comment|/* PLOGI, Common Service */
name|uint8_t
name|pdb_target
decl_stmt|;
name|uint8_t
name|pdb_initiator
decl_stmt|;
comment|/* PLOGI, Class 3 Control Flags */
name|uint16_t
name|pdb_rdsiz
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|uint16_t
name|pdb_ncseq
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|uint16_t
name|pdb_noseq
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|uint16_t
name|pdb_labrtflg
decl_stmt|;
name|uint16_t
name|pdb_lstopflg
decl_stmt|;
name|uint16_t
name|pdb_sqhead
decl_stmt|;
name|uint16_t
name|pdb_sqtail
decl_stmt|;
name|uint16_t
name|pdb_ptimer
decl_stmt|;
name|uint16_t
name|pdb_nxt_seqid
decl_stmt|;
name|uint16_t
name|pdb_fcount
decl_stmt|;
name|uint16_t
name|pdb_prli_len
decl_stmt|;
name|uint16_t
name|pdb_prli_svc0
decl_stmt|;
name|uint16_t
name|pdb_prli_svc3
decl_stmt|;
name|uint16_t
name|pdb_loopid
decl_stmt|;
name|uint16_t
name|pdb_il_ptr
decl_stmt|;
name|uint16_t
name|pdb_sl_ptr
decl_stmt|;
block|}
name|isp_pdb_21xx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDB_OPTIONS_XMITTING
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|PDB_OPTIONS_LNKXMIT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|PDB_OPTIONS_ABORTED
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PDB_OPTIONS_ADISC
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PDB_STATE_DISCOVERY
value|0
end_define

begin_define
define|#
directive|define
name|PDB_STATE_WDISC_ACK
value|1
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PLOGI
value|2
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PLOGI_ACK
value|3
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PRLI
value|4
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PRLI_ACK
value|5
end_define

begin_define
define|#
directive|define
name|PDB_STATE_LOGGED_IN
value|6
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PORT_UNAVAIL
value|7
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PRLO
value|8
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PRLO_ACK
value|9
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PLOGO
value|10
end_define

begin_define
define|#
directive|define
name|PDB_STATE_PLOG_ACK
value|11
end_define

begin_define
define|#
directive|define
name|SVC3_TGT_ROLE
value|0x10
end_define

begin_define
define|#
directive|define
name|SVC3_INI_ROLE
value|0x20
end_define

begin_define
define|#
directive|define
name|SVC3_ROLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|SVC3_ROLE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BITS2WORD
parameter_list|(
name|x
parameter_list|)
value|((x)[0]<< 16 | (x)[3]<< 8 | (x)[2])
end_define

begin_define
define|#
directive|define
name|BITS2WORD_24XX
parameter_list|(
name|x
parameter_list|)
value|((x)[0]<< 16 | (x)[1]<< 8 | (x)[2])
end_define

begin_comment
comment|/*  * Port Data Base Element- 24XX cards  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pdb_flags
decl_stmt|;
name|uint8_t
name|pdb_curstate
decl_stmt|;
name|uint8_t
name|pdb_laststate
decl_stmt|;
name|uint8_t
name|pdb_hardaddr_bits
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|pdb_portid_bits
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|pdb_nxt_seqid_2400
value|pdb_portid_bits[3]
name|uint16_t
name|pdb_retry_timer
decl_stmt|;
name|uint16_t
name|pdb_handle
decl_stmt|;
name|uint16_t
name|pdb_rcv_dsize
decl_stmt|;
name|uint16_t
name|pdb_reserved0
decl_stmt|;
name|uint16_t
name|pdb_prli_svc0
decl_stmt|;
name|uint16_t
name|pdb_prli_svc3
decl_stmt|;
name|uint8_t
name|pdb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|pdb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|pdb_reserved1
index|[
literal|24
index|]
decl_stmt|;
block|}
name|isp_pdb_24xx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDB2400_TID_SUPPORTED
value|0x4000
end_define

begin_define
define|#
directive|define
name|PDB2400_FC_TAPE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PDB2400_CLASS2_ACK0
value|0x0040
end_define

begin_define
define|#
directive|define
name|PDB2400_FCP_CONF
value|0x0020
end_define

begin_define
define|#
directive|define
name|PDB2400_CLASS2
value|0x0010
end_define

begin_define
define|#
directive|define
name|PDB2400_ADDR_VALID
value|0x0002
end_define

begin_comment
comment|/*  * Common elements from the above two structures that are actually useful to us.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|handle
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|s3_role
range|:
literal|8
decl_stmt|,
name|portid
range|:
literal|24
decl_stmt|;
name|uint8_t
name|portname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|nodename
index|[
literal|8
index|]
decl_stmt|;
block|}
name|isp_pdb_t
typedef|;
end_typedef

begin_comment
comment|/*  * Genericized Port Login/Logout software structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|handle
decl_stmt|;
name|uint32_t
name|flags
range|:
literal|8
decl_stmt|,
name|portid
range|:
literal|24
decl_stmt|;
block|}
name|isp_plcmd_t
typedef|;
end_typedef

begin_comment
comment|/* the flags to use are those for PLOGX_FLG_* below */
end_comment

begin_comment
comment|/*  * ISP24XX- Login/Logout Port IOCB  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|plogx_header
decl_stmt|;
name|uint32_t
name|plogx_handle
decl_stmt|;
name|uint16_t
name|plogx_status
decl_stmt|;
name|uint16_t
name|plogx_nphdl
decl_stmt|;
name|uint16_t
name|plogx_flags
decl_stmt|;
name|uint16_t
name|plogx_vphdl
decl_stmt|;
comment|/* low 8 bits */
name|uint16_t
name|plogx_portlo
decl_stmt|;
comment|/* low 16 bits */
name|uint16_t
name|plogx_rspsz_porthi
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|lo16
decl_stmt|;
name|uint16_t
name|hi16
decl_stmt|;
block|}
name|plogx_ioparm
index|[
literal|11
index|]
struct|;
block|}
name|isp_plogx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PLOGX_STATUS_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|PLOGX_STATUS_UNAVAIL
value|0x28
end_define

begin_define
define|#
directive|define
name|PLOGX_STATUS_LOGOUT
value|0x29
end_define

begin_define
define|#
directive|define
name|PLOGX_STATUS_IOCBERR
value|0x31
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOLINK
value|0x01
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOIOCB
value|0x02
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOXGHG
value|0x03
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_FAILED
value|0x04
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOFABRIC
value|0x05
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOTREADY
value|0x07
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOLOGIN
value|0x08
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOPCB
value|0x0a
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_REJECT
value|0x18
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_EINVAL
value|0x19
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_PORTUSED
value|0x1a
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_HNDLUSED
value|0x1b
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOHANDLE
value|0x1c
end_define

begin_define
define|#
directive|define
name|PLOGX_IOCBERR_NOFLOGI
value|0x1f
end_define

begin_comment
comment|/* further info in IOPARM 1 */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_PLOGI
value|0
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_PRLI
value|1
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_PDISC
value|2
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_LOGO
value|8
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_PRLO
value|9
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_CMD_TPRLO
value|10
end_define

begin_define
define|#
directive|define
name|PLOGX_FLG_COND_PLOGI
value|0x10
end_define

begin_comment
comment|/* if with PLOGI */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_IMPLICIT
value|0x10
end_define

begin_comment
comment|/* if with LOGO, PRLO, TPRLO */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_SKIP_PRLI
value|0x20
end_define

begin_comment
comment|/* if with PLOGI */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_IMPLICIT_LOGO_ALL
value|0x20
end_define

begin_comment
comment|/* if with LOGO */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_EXPLICIT_LOGO
value|0x40
end_define

begin_comment
comment|/* if with LOGO */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_COMMON_FEATURES
value|0x80
end_define

begin_comment
comment|/* if with PLOGI */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_FREE_NPHDL
value|0x80
end_define

begin_comment
comment|/* if with with LOGO */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_CLASS2
value|0x100
end_define

begin_comment
comment|/* if with PLOGI */
end_comment

begin_define
define|#
directive|define
name|PLOGX_FLG_FCP2_OVERRIDE
value|0x200
end_define

begin_comment
comment|/* if with PRLOG, PRLI */
end_comment

begin_comment
comment|/*  * Simple Name Server Data Structures  */
end_comment

begin_define
define|#
directive|define
name|SNS_GA_NXT
value|0x100
end_define

begin_define
define|#
directive|define
name|SNS_GPN_ID
value|0x112
end_define

begin_define
define|#
directive|define
name|SNS_GNN_ID
value|0x113
end_define

begin_define
define|#
directive|define
name|SNS_GFF_ID
value|0x11F
end_define

begin_define
define|#
directive|define
name|SNS_GID_FT
value|0x171
end_define

begin_define
define|#
directive|define
name|SNS_RFT_ID
value|0x217
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|uint16_t
name|snscb_reserved0
decl_stmt|;
name|uint16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|uint16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|uint16_t
name|snscb_reserved1
decl_stmt|;
name|uint16_t
name|snscb_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable data */
block|}
name|sns_screq_t
typedef|;
end_typedef

begin_comment
comment|/* Subcommand Request Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|uint16_t
name|snscb_reserved0
decl_stmt|;
name|uint16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|uint16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|uint16_t
name|snscb_reserved1
decl_stmt|;
name|uint16_t
name|snscb_cmd
decl_stmt|;
name|uint16_t
name|snscb_reserved2
decl_stmt|;
name|uint32_t
name|snscb_reserved3
decl_stmt|;
name|uint32_t
name|snscb_port
decl_stmt|;
block|}
name|sns_ga_nxt_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GA_NXT_REQ_SIZE
value|(sizeof (sns_ga_nxt_req_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|uint16_t
name|snscb_reserved0
decl_stmt|;
name|uint16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|uint16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|uint16_t
name|snscb_reserved1
decl_stmt|;
name|uint16_t
name|snscb_cmd
decl_stmt|;
name|uint16_t
name|snscb_reserved2
decl_stmt|;
name|uint32_t
name|snscb_reserved3
decl_stmt|;
name|uint32_t
name|snscb_portid
decl_stmt|;
block|}
name|sns_gxn_id_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GXN_ID_REQ_SIZE
value|(sizeof (sns_gxn_id_req_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|uint16_t
name|snscb_reserved0
decl_stmt|;
name|uint16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|uint16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|uint16_t
name|snscb_reserved1
decl_stmt|;
name|uint16_t
name|snscb_cmd
decl_stmt|;
name|uint16_t
name|snscb_mword_div_2
decl_stmt|;
name|uint32_t
name|snscb_reserved3
decl_stmt|;
name|uint32_t
name|snscb_fc4_type
decl_stmt|;
block|}
name|sns_gid_ft_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GID_FT_REQ_SIZE
value|(sizeof (sns_gid_ft_req_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|uint16_t
name|snscb_reserved0
decl_stmt|;
name|uint16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|uint16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|uint16_t
name|snscb_reserved1
decl_stmt|;
name|uint16_t
name|snscb_cmd
decl_stmt|;
name|uint16_t
name|snscb_reserved2
decl_stmt|;
name|uint32_t
name|snscb_reserved3
decl_stmt|;
name|uint32_t
name|snscb_port
decl_stmt|;
name|uint32_t
name|snscb_fc4_types
index|[
literal|8
index|]
decl_stmt|;
block|}
name|sns_rft_id_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_RFT_ID_REQ_SIZE
value|(sizeof (sns_rft_id_req_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|snscb_cthdr
decl_stmt|;
name|uint8_t
name|snscb_port_type
decl_stmt|;
name|uint8_t
name|snscb_port_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|snscb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|snscb_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable data */
block|}
name|sns_scrsp_t
typedef|;
end_typedef

begin_comment
comment|/* Subcommand Response Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|snscb_cthdr
decl_stmt|;
name|uint8_t
name|snscb_port_type
decl_stmt|;
name|uint8_t
name|snscb_port_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|snscb_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|snscb_pnlen
decl_stmt|;
comment|/* symbolic port name length */
name|uint8_t
name|snscb_pname
index|[
literal|255
index|]
decl_stmt|;
comment|/* symbolic port name */
name|uint8_t
name|snscb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|snscb_nnlen
decl_stmt|;
comment|/* symbolic node name length */
name|uint8_t
name|snscb_nname
index|[
literal|255
index|]
decl_stmt|;
comment|/* symbolic node name */
name|uint8_t
name|snscb_ipassoc
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|snscb_ipaddr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|snscb_svc_class
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|snscb_fc4_types
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|snscb_fpname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|snscb_reserved
decl_stmt|;
name|uint8_t
name|snscb_hardaddr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|sns_ga_nxt_rsp_t
typedef|;
end_typedef

begin_comment
comment|/* Subcommand Response Structure */
end_comment

begin_define
define|#
directive|define
name|SNS_GA_NXT_RESP_SIZE
value|(sizeof (sns_ga_nxt_rsp_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|snscb_cthdr
decl_stmt|;
name|uint8_t
name|snscb_wwn
index|[
literal|8
index|]
decl_stmt|;
block|}
name|sns_gxn_id_rsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GXN_ID_RESP_SIZE
value|(sizeof (sns_gxn_id_rsp_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|snscb_cthdr
decl_stmt|;
name|uint32_t
name|snscb_fc4_features
index|[
literal|32
index|]
decl_stmt|;
block|}
name|sns_gff_id_rsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GFF_ID_RESP_SIZE
value|(sizeof (sns_gff_id_rsp_t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_hdr_t
name|snscb_cthdr
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|control
decl_stmt|;
name|uint8_t
name|portid
index|[
literal|3
index|]
decl_stmt|;
block|}
name|snscb_ports
index|[
literal|1
index|]
struct|;
block|}
name|sns_gid_ft_rsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNS_GID_FT_RESP_SIZE
parameter_list|(
name|x
parameter_list|)
value|((sizeof (sns_gid_ft_rsp_t)) + ((x - 1)<< 2))
end_define

begin_define
define|#
directive|define
name|SNS_RFT_ID_RESP_SIZE
value|(sizeof (ct_hdr_t))
end_define

begin_comment
comment|/*  * Other Misc Structures  */
end_comment

begin_comment
comment|/* ELS Pass Through */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|els_hdr
decl_stmt|;
name|uint32_t
name|els_handle
decl_stmt|;
name|uint16_t
name|els_status
decl_stmt|;
name|uint16_t
name|els_nphdl
decl_stmt|;
name|uint16_t
name|els_xmit_dsd_count
decl_stmt|;
comment|/* outgoing only */
name|uint8_t
name|els_vphdl
decl_stmt|;
name|uint8_t
name|els_sof
decl_stmt|;
name|uint32_t
name|els_rxid
decl_stmt|;
name|uint16_t
name|els_recv_dsd_count
decl_stmt|;
comment|/* outgoing only */
name|uint8_t
name|els_opcode
decl_stmt|;
name|uint8_t
name|els_reserved1
decl_stmt|;
name|uint8_t
name|els_did_lo
decl_stmt|;
name|uint8_t
name|els_did_mid
decl_stmt|;
name|uint8_t
name|els_did_hi
decl_stmt|;
name|uint8_t
name|els_reserved2
decl_stmt|;
name|uint16_t
name|els_reserved3
decl_stmt|;
name|uint16_t
name|els_ctl_flags
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|_els_bytecnt
decl_stmt|;
name|uint32_t
name|_els_subcode1
decl_stmt|;
name|uint32_t
name|_els_subcode2
decl_stmt|;
name|uint8_t
name|_els_reserved4
index|[
literal|20
index|]
decl_stmt|;
block|}
name|in
struct|;
struct|struct
block|{
name|uint32_t
name|_els_recv_bytecnt
decl_stmt|;
name|uint32_t
name|_els_xmit_bytecnt
decl_stmt|;
name|uint32_t
name|_els_xmit_dsd_length
decl_stmt|;
name|uint16_t
name|_els_xmit_dsd_a1500
decl_stmt|;
name|uint16_t
name|_els_xmit_dsd_a3116
decl_stmt|;
name|uint16_t
name|_els_xmit_dsd_a4732
decl_stmt|;
name|uint16_t
name|_els_xmit_dsd_a6348
decl_stmt|;
name|uint32_t
name|_els_recv_dsd_length
decl_stmt|;
name|uint16_t
name|_els_recv_dsd_a1500
decl_stmt|;
name|uint16_t
name|_els_recv_dsd_a3116
decl_stmt|;
name|uint16_t
name|_els_recv_dsd_a4732
decl_stmt|;
name|uint16_t
name|_els_recv_dsd_a6348
decl_stmt|;
block|}
name|out
struct|;
block|}
name|inout
union|;
define|#
directive|define
name|els_bytecnt
value|inout.in._els_bytecnt
define|#
directive|define
name|els_subcode1
value|inout.in._els_subcode1
define|#
directive|define
name|els_subcode2
value|inout.in._els_subcode2
define|#
directive|define
name|els_reserved4
value|inout.in._els_reserved4
define|#
directive|define
name|els_recv_bytecnt
value|inout.out._els_recv_bytecnt
define|#
directive|define
name|els_xmit_bytecnt
value|inout.out._els_xmit_bytecnt
define|#
directive|define
name|els_xmit_dsd_length
value|inout.out._els_xmit_dsd_length
define|#
directive|define
name|els_xmit_dsd_a1500
value|inout.out._els_xmit_dsd_a1500
define|#
directive|define
name|els_xmit_dsd_a3116
value|inout.out._els_xmit_dsd_a3116
define|#
directive|define
name|els_xmit_dsd_a4732
value|inout.out._els_xmit_dsd_a4732
define|#
directive|define
name|els_xmit_dsd_a6348
value|inout.out._els_xmit_dsd_a6348
define|#
directive|define
name|els_recv_dsd_length
value|inout.out._els_recv_dsd_length
define|#
directive|define
name|els_recv_dsd_a1500
value|inout.out._els_recv_dsd_a1500
define|#
directive|define
name|els_recv_dsd_a3116
value|inout.out._els_recv_dsd_a3116
define|#
directive|define
name|els_recv_dsd_a4732
value|inout.out._els_recv_dsd_a4732
define|#
directive|define
name|els_recv_dsd_a6348
value|inout.out._els_recv_dsd_a6348
block|}
name|els_t
typedef|;
end_typedef

begin_comment
comment|/*  * A handy package structure for running FC-SCSI commands via RUN IOCB A64.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|handle
decl_stmt|;
name|uint16_t
name|lun
decl_stmt|;
name|uint32_t
name|portid
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint32_t
name|data_length
decl_stmt|;
name|uint8_t
name|do_read
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|void
modifier|*
name|data_ptr
decl_stmt|;
block|}
name|beg
struct|;
struct|struct
block|{
name|uint32_t
name|data_residual
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
name|uint16_t
name|sense_length
decl_stmt|;
name|uint8_t
name|sense_data
index|[
literal|32
index|]
decl_stmt|;
block|}
name|end
struct|;
block|}
name|fcd
union|;
block|}
name|isp_xcmd_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPMBOX_H */
end_comment

end_unit

