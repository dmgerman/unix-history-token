begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Mailbox and Queue Entry Definitions for for Qlogic ISP SCSI adapters.  *  * Copyright (c) 1997, 1998, 1999, 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_comment
comment|/*   9 */
end_comment

begin_comment
comment|/*   a */
end_comment

begin_comment
comment|/*   b */
end_comment

begin_comment
comment|/*   c */
end_comment

begin_comment
comment|/*   d */
end_comment

begin_define
define|#
directive|define
name|MBOX_CHECK_FIRMWARE
value|0x000e
end_define

begin_comment
comment|/*   f */
end_comment

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
name|FW_FEATURE_LVD_NOTIFY
value|0x2
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
name|MBOX_GET_SET_DATA_RATE
value|0x005D
end_define

begin_comment
comment|/* 23XX only */
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
name|ISP2100_SET_PCI_PARAM
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MBOX_BUSY
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|param
index|[
literal|8
index|]
decl_stmt|;
block|}
name|mbreg_t
typedef|;
end_typedef

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
comment|/*  * Mailbox Usages  */
end_comment

begin_define
define|#
directive|define
name|WRITE_REQUEST_QUEUE_IN_POINTER
parameter_list|(
name|isp
parameter_list|,
name|value
parameter_list|)
define|\
value|ISP_WRITE(isp, isp->isp_rqstinrp, value)
end_define

begin_define
define|#
directive|define
name|READ_REQUEST_QUEUE_OUT_POINTER
parameter_list|(
name|isp
parameter_list|)
define|\
value|ISP_READ(isp, isp->isp_rqstoutrp)
end_define

begin_define
define|#
directive|define
name|READ_RESPONSE_QUEUE_IN_POINTER
parameter_list|(
name|isp
parameter_list|)
define|\
value|ISP_READ(isp, isp->isp_respinrp)
end_define

begin_define
define|#
directive|define
name|WRITE_RESPONSE_QUEUE_OUT_POINTER
parameter_list|(
name|isp
parameter_list|,
name|value
parameter_list|)
define|\
value|ISP_WRITE(isp, isp->isp_respoutrp, value)
end_define

begin_comment
comment|/*  * Command Structure Definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|ds_base
decl_stmt|;
name|u_int32_t
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
name|u_int32_t
name|ds_base
decl_stmt|;
name|u_int32_t
name|ds_basehi
decl_stmt|;
name|u_int32_t
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
name|u_int16_t
name|ds_type
decl_stmt|;
comment|/* 0-> ispds_t, 1-> ispds64_t */
name|u_int32_t
name|ds_segment
decl_stmt|;
comment|/* unused */
name|u_int32_t
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
value|{		\ 	u_int8_t tmp;			\ 	tmp = a;			\ 	a = b;				\ 	b = tmp;			\ }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|rqs_entry_type
decl_stmt|;
name|u_int8_t
name|rqs_entry_count
decl_stmt|;
name|u_int8_t
name|rqs_seqno
decl_stmt|;
name|u_int8_t
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
name|RQSTYPE_IP_XMIT
value|0x13
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
name|RQSTYPE_CSET0
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
name|u_int32_t
name|req_handle
decl_stmt|;
name|u_int8_t
name|req_lun_trn
decl_stmt|;
name|u_int8_t
name|req_target
decl_stmt|;
name|u_int16_t
name|req_cdblen
decl_stmt|;
define|#
directive|define
name|req_modifier
value|req_cdblen
comment|/* marker packet */
name|u_int16_t
name|req_flags
decl_stmt|;
name|u_int16_t
name|req_reserved
decl_stmt|;
name|u_int16_t
name|req_time
decl_stmt|;
name|u_int16_t
name|req_seg_count
decl_stmt|;
name|u_int8_t
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

begin_comment
comment|/*  * A request packet can also be a marker packet.  */
end_comment

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
name|u_int32_t
name|req_handle
decl_stmt|;
name|u_int8_t
name|req_lun_trn
decl_stmt|;
name|u_int8_t
name|req_target
decl_stmt|;
name|u_int16_t
name|req_scclun
decl_stmt|;
name|u_int16_t
name|req_flags
decl_stmt|;
name|u_int16_t
name|_res2
decl_stmt|;
name|u_int16_t
name|req_time
decl_stmt|;
name|u_int16_t
name|req_seg_count
decl_stmt|;
name|u_int8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|u_int32_t
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
name|u_int32_t
name|req_handle
decl_stmt|;
name|u_int8_t
name|req_lun_trn
decl_stmt|;
name|u_int8_t
name|req_target
decl_stmt|;
name|u_int16_t
name|req_scclun
decl_stmt|;
name|u_int16_t
name|req_flags
decl_stmt|;
name|u_int16_t
name|_res2
decl_stmt|;
name|u_int16_t
name|req_time
decl_stmt|;
name|u_int16_t
name|req_seg_count
decl_stmt|;
name|u_int8_t
name|req_cdb
index|[
literal|16
index|]
decl_stmt|;
name|u_int32_t
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
name|u_int32_t
name|req_handle
decl_stmt|;
name|u_int8_t
name|req_lun_trn
decl_stmt|;
name|u_int8_t
name|req_target
decl_stmt|;
name|u_int16_t
name|req_cdblen
decl_stmt|;
name|u_int16_t
name|req_flags
decl_stmt|;
name|u_int16_t
name|_res1
decl_stmt|;
name|u_int16_t
name|req_time
decl_stmt|;
name|u_int16_t
name|req_seg_count
decl_stmt|;
name|u_int8_t
name|req_cdb
index|[
literal|44
index|]
decl_stmt|;
block|}
name|ispextreq_t
typedef|;
end_typedef

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
name|u_int32_t
name|_res1
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
name|u_int32_t
name|req_handle
decl_stmt|;
name|u_int16_t
name|req_scsi_status
decl_stmt|;
name|u_int16_t
name|req_completion_status
decl_stmt|;
name|u_int16_t
name|req_state_flags
decl_stmt|;
name|u_int16_t
name|req_status_flags
decl_stmt|;
name|u_int16_t
name|req_time
decl_stmt|;
define|#
directive|define
name|req_response_len
value|req_time
comment|/* FC only */
name|u_int16_t
name|req_sense_len
decl_stmt|;
name|u_int32_t
name|req_resid
decl_stmt|;
name|u_int8_t
name|req_response
index|[
literal|8
index|]
decl_stmt|;
comment|/* FC only */
name|u_int8_t
name|req_sense_data
index|[
literal|32
index|]
decl_stmt|;
block|}
name|ispstatusreq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|req_header
decl_stmt|;
name|u_int8_t
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
comment|/*  * About Firmware returns an 'attribute' word in mailbox 6.  */
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
name|u_int32_t
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
name|u_int16_t
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
comment|/*  * FC (ISP2100) specific data structures  */
end_comment

begin_comment
comment|/*  * Initialization Control Block  *  * Version One (prime) format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isp_icb
block|{
name|u_int8_t
name|icb_version
decl_stmt|;
name|u_int8_t
name|_reserved0
decl_stmt|;
name|u_int16_t
name|icb_fwoptions
decl_stmt|;
name|u_int16_t
name|icb_maxfrmlen
decl_stmt|;
name|u_int16_t
name|icb_maxalloc
decl_stmt|;
name|u_int16_t
name|icb_execthrottle
decl_stmt|;
name|u_int8_t
name|icb_retry_count
decl_stmt|;
name|u_int8_t
name|icb_retry_delay
decl_stmt|;
name|u_int8_t
name|icb_portname
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|icb_hardaddr
decl_stmt|;
name|u_int8_t
name|icb_iqdevtype
decl_stmt|;
name|u_int8_t
name|icb_logintime
decl_stmt|;
name|u_int8_t
name|icb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|icb_rqstout
decl_stmt|;
name|u_int16_t
name|icb_rspnsin
decl_stmt|;
name|u_int16_t
name|icb_rqstqlen
decl_stmt|;
name|u_int16_t
name|icb_rsltqlen
decl_stmt|;
name|u_int16_t
name|icb_rqstaddr
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|icb_respaddr
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|icb_lunenables
decl_stmt|;
name|u_int8_t
name|icb_ccnt
decl_stmt|;
name|u_int8_t
name|icb_icnt
decl_stmt|;
name|u_int16_t
name|icb_lunetimeout
decl_stmt|;
name|u_int16_t
name|_reserved1
decl_stmt|;
name|u_int16_t
name|icb_xfwoptions
decl_stmt|;
name|u_int8_t
name|icb_racctimer
decl_stmt|;
name|u_int8_t
name|icb_idelaytimer
decl_stmt|;
name|u_int16_t
name|icb_zfwoptions
decl_stmt|;
name|u_int16_t
name|_reserved2
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
name|ICBOPT_HARD_ADDRESS
value|0x0001
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
name|ICBOPT_FULL_DUPLEX
value|0x0004
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
name|ICBOPT_TGT_ENABLE
value|0x0010
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
name|ICBOPT_INI_ADISC
value|0x0040
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
name|ICBOPT_PDBCHANGE_AE
value|0x0100
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
name|ICBOPT_SRCHDOWN
value|0x0400
end_define

begin_define
define|#
directive|define
name|ICBOPT_PREVLOOP
value|0x0800
end_define

begin_define
define|#
directive|define
name|ICBOPT_STOP_ON_QFULL
value|0x1000
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
name|ICBOPT_BOTH_WWNS
value|0x4000
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
name|ICBXOPT_LOOP_ONLY
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|ICBXOPT_PTP_ONLY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ICBXOPT_LOOP_2_PTP
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|ICBXOPT_PTP_2_LOOP
value|(3<< 4)
end_define

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
name|ICBXOPT_RIO_16BIT_DELAY
value|3
end_define

begin_define
define|#
directive|define
name|ICBXOPT_RIO_32BIT_DELAY
value|4
end_define

begin_comment
comment|/* These 3 only apply to the 2300 */
end_comment

begin_define
define|#
directive|define
name|ICBZOPT_RATE_ONEGB
value|(MBGSD_ONEGB<< 14)
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_TWOGB
value|(MBGSD_TWOGB<< 14)
end_define

begin_define
define|#
directive|define
name|ICBZOPT_RATE_AUTO
value|(MBGSD_AUTO<< 14)
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
value|array[ICB_NNM0] = (u_int8_t) ((wwn>>  0)& 0xff), \ 	array[ICB_NNM1] = (u_int8_t) ((wwn>>  8)& 0xff), \ 	array[ICB_NNM2] = (u_int8_t) ((wwn>> 16)& 0xff), \ 	array[ICB_NNM3] = (u_int8_t) ((wwn>> 24)& 0xff), \ 	array[ICB_NNM4] = (u_int8_t) ((wwn>> 32)& 0xff), \ 	array[ICB_NNM5] = (u_int8_t) ((wwn>> 40)& 0xff), \ 	array[ICB_NNM6] = (u_int8_t) ((wwn>> 48)& 0xff), \ 	array[ICB_NNM7] = (u_int8_t) ((wwn>> 56)& 0xff)
end_define

begin_comment
comment|/*  * FC-AL Position Map  *  * This is an at most 128 byte map that returns either  * the LILP or Firmware generated list of ports.  *  * We deviate a bit from the returned qlogic format to  * use an extra bit to say whether this was a LILP or  * f/w generated map.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|fwmap
range|:
literal|1
decl_stmt|,
name|count
range|:
literal|7
decl_stmt|;
name|u_int8_t
name|map
index|[
literal|127
index|]
decl_stmt|;
block|}
name|fcpos_map_t
typedef|;
end_typedef

begin_comment
comment|/*  * Port Data Base Element  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|pdb_options
decl_stmt|;
name|u_int8_t
name|pdb_mstate
decl_stmt|;
name|u_int8_t
name|pdb_sstate
decl_stmt|;
define|#
directive|define
name|BITS2WORD
parameter_list|(
name|x
parameter_list|)
value|((x)[0]<< 16 | (x)[3]<< 8 | (x)[2])
name|u_int8_t
name|pdb_hardaddr_bits
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|pdb_portid_bits
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|pdb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|pdb_portname
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|pdb_execthrottle
decl_stmt|;
name|u_int16_t
name|pdb_exec_count
decl_stmt|;
name|u_int8_t
name|pdb_retry_count
decl_stmt|;
name|u_int8_t
name|pdb_retry_delay
decl_stmt|;
name|u_int16_t
name|pdb_resalloc
decl_stmt|;
name|u_int16_t
name|pdb_curalloc
decl_stmt|;
name|u_int16_t
name|pdb_qhead
decl_stmt|;
name|u_int16_t
name|pdb_qtail
decl_stmt|;
name|u_int16_t
name|pdb_tl_next
decl_stmt|;
name|u_int16_t
name|pdb_tl_last
decl_stmt|;
name|u_int16_t
name|pdb_features
decl_stmt|;
comment|/* PLOGI, Common Service */
name|u_int16_t
name|pdb_pconcurrnt
decl_stmt|;
comment|/* PLOGI, Common Service */
name|u_int16_t
name|pdb_roi
decl_stmt|;
comment|/* PLOGI, Common Service */
name|u_int8_t
name|pdb_target
decl_stmt|;
name|u_int8_t
name|pdb_initiator
decl_stmt|;
comment|/* PLOGI, Class 3 Control Flags */
name|u_int16_t
name|pdb_rdsiz
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|u_int16_t
name|pdb_ncseq
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|u_int16_t
name|pdb_noseq
decl_stmt|;
comment|/* PLOGI, Class 3 */
name|u_int16_t
name|pdb_labrtflg
decl_stmt|;
name|u_int16_t
name|pdb_lstopflg
decl_stmt|;
name|u_int16_t
name|pdb_sqhead
decl_stmt|;
name|u_int16_t
name|pdb_sqtail
decl_stmt|;
name|u_int16_t
name|pdb_ptimer
decl_stmt|;
name|u_int16_t
name|pdb_nxt_seqid
decl_stmt|;
name|u_int16_t
name|pdb_fcount
decl_stmt|;
name|u_int16_t
name|pdb_prli_len
decl_stmt|;
name|u_int16_t
name|pdb_prli_svc0
decl_stmt|;
name|u_int16_t
name|pdb_prli_svc3
decl_stmt|;
name|u_int16_t
name|pdb_loopid
decl_stmt|;
name|u_int16_t
name|pdb_il_ptr
decl_stmt|;
name|u_int16_t
name|pdb_sl_ptr
decl_stmt|;
block|}
name|isp_pdb_t
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
name|SNS_GAN
value|0x100
end_define

begin_define
define|#
directive|define
name|SNS_GP3
value|0x171
end_define

begin_define
define|#
directive|define
name|SNS_RFT
value|0x217
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|snscb_rblen
decl_stmt|;
comment|/* response buffer length (words) */
name|u_int16_t
name|snscb_res0
decl_stmt|;
name|u_int16_t
name|snscb_addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* response buffer address */
name|u_int16_t
name|snscb_sblen
decl_stmt|;
comment|/* subcommand buffer length (words) */
name|u_int16_t
name|snscb_res1
decl_stmt|;
name|u_int16_t
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

begin_define
define|#
directive|define
name|SNS_GAN_REQ_SIZE
value|(sizeof (sns_screq_t)+(5*(sizeof (u_int16_t))))
end_define

begin_define
define|#
directive|define
name|SNS_GP3_REQ_SIZE
value|(sizeof (sns_screq_t)+(5*(sizeof (u_int16_t))))
end_define

begin_define
define|#
directive|define
name|SNS_RFT_REQ_SIZE
value|(sizeof (sns_screq_t)+(21*(sizeof (u_int16_t))))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|snscb_cthdr
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|snscb_port_type
decl_stmt|;
name|u_int8_t
name|snscb_port_id
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|snscb_portname
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
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

begin_define
define|#
directive|define
name|SNS_GAN_RESP_SIZE
value|608
end_define

begin_comment
comment|/* Maximum response size (bytes) */
end_comment

begin_define
define|#
directive|define
name|SNS_GP3_RESP_SIZE
value|532
end_define

begin_comment
comment|/* XXX: For 128 ports */
end_comment

begin_define
define|#
directive|define
name|SNS_RFT_RESP_SIZE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|snscb_cthdr
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|snscb_port_type
decl_stmt|;
name|u_int8_t
name|snscb_port_id
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|snscb_portname
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|snscb_pnlen
decl_stmt|;
comment|/* symbolic port name length */
name|u_int8_t
name|snscb_pname
index|[
literal|255
index|]
decl_stmt|;
comment|/* symbolic port name */
name|u_int8_t
name|snscb_nodename
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|snscb_nnlen
decl_stmt|;
comment|/* symbolic node name length */
name|u_int8_t
name|snscb_nname
index|[
literal|255
index|]
decl_stmt|;
comment|/* symbolic node name */
name|u_int8_t
name|snscb_ipassoc
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|snscb_ipaddr
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|snscb_svc_class
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|snscb_fc4_types
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|snscb_fpname
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|snscb_reserved
decl_stmt|;
name|u_int8_t
name|snscb_hardaddr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|sns_ganrsp_t
typedef|;
end_typedef

begin_comment
comment|/* Subcommand Response Structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPMBOX_H */
end_comment

end_unit

