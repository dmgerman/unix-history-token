begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Mailbox and Queue Entry Definitions for for Qlogic ISP SCSI adapters.  *  *---------------------------------------  * Copyright (c) 1997, 1998, 1999 by Matthew Jacob  * NASA/Ames Research Center  * All rights reserved.  *---------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_comment
comment|/* These are for the ISP2100 FC cards */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_LOOP_ID
value|0x20
end_define

begin_define
define|#
directive|define
name|MBOX_EXEC_COMMAND_IOCB_A64
value|0x54
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_FIRMWARE
value|0x60
end_define

begin_define
define|#
directive|define
name|MBOX_GET_INIT_CONTROL_BLOCK
value|0x61
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP
value|0x62
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FC_AL_POSITION_MAP
value|0x63
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PORT_DB
value|0x64
end_define

begin_define
define|#
directive|define
name|MBOX_CLEAR_ACA
value|0x65
end_define

begin_define
define|#
directive|define
name|MBOX_TARGET_RESET
value|0x66
end_define

begin_define
define|#
directive|define
name|MBOX_CLEAR_TASK_SET
value|0x67
end_define

begin_define
define|#
directive|define
name|MBOX_ABORT_TASK_SET
value|0x68
end_define

begin_define
define|#
directive|define
name|MBOX_GET_FW_STATE
value|0x69
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PORT_NAME
value|0x6a
end_define

begin_define
define|#
directive|define
name|MBOX_GET_LINK_STATUS
value|0x6b
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP_RESET
value|0x6c
end_define

begin_define
define|#
directive|define
name|MBOX_SEND_SNS
value|0x6e
end_define

begin_define
define|#
directive|define
name|MBOX_FABRIC_LOGIN
value|0x6f
end_define

begin_define
define|#
directive|define
name|MBOX_SEND_CHANGE_REQUEST
value|0x70
end_define

begin_define
define|#
directive|define
name|MBOX_FABRIC_LOGOUT
value|0x71
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_LIP_LOGIN
value|0x72
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
name|ASYNC_CMD_CMPLT
value|0x8020
end_define

begin_define
define|#
directive|define
name|ASYNC_CTIO_DONE
value|0x8021
end_define

begin_comment
comment|/* for ISP2100 only */
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

begin_define
define|#
directive|define
name|_ISP_SWAP8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{	\ 	u_int8_t tmp;			\ 	tmp = a;			\ 	a = b;				\ 	b = tmp;			\ }
end_define

begin_comment
comment|/*  * These elements get swizzled around for SBus instances.  */
end_comment

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
comment|/*  * There are no (for all intents and purposes) non-sparc SBus machines  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SBUSIFY_ISPHDR
parameter_list|(
name|isp
parameter_list|,
name|hdrp
parameter_list|)
define|\
value|if ((isp)->isp_bustype == ISP_BT_SBUS) {				\ 	_ISP_SWAP8((hdrp)->rqs_entry_count, (hdrp)->rqs_entry_type);	\ 	_ISP_SWAP8((hdrp)->rqs_flags, (hdrp)->rqs_seqno);		\     }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_SBUSIFY_ISPHDR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|RQSTYPE_CTIO0
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
name|RQSTYPE_T4RQS
value|0x15
end_define

begin_define
define|#
directive|define
name|RQSTYPE_ATIO2
value|0x16
end_define

begin_define
define|#
directive|define
name|RQSTYPE_CTIO2
value|0x17
end_define

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
name|RQSTYPE_CTIO3
value|0x1f
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

begin_comment
comment|/*  * There are no (for all intents and purposes) non-sparc SBus machines  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc__
end_ifdef

begin_define
define|#
directive|define
name|ISP_SBUSIFY_ISPREQ
parameter_list|(
name|isp
parameter_list|,
name|rqp
parameter_list|)
define|\
value|if ((isp)->isp_bustype == ISP_BT_SBUS) {				\ 	_ISP_SWAP8((rqp)->req_target, (rqp)->req_lun_trn);		\     }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISP_SBUSIFY_ISPREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|u_int32_t
name|req_cdb
index|[
literal|4
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
name|u_int16_t
name|req_sense_len
decl_stmt|;
name|u_int32_t
name|req_resid
decl_stmt|;
name|u_int8_t
name|_res1
index|[
literal|8
index|]
decl_stmt|;
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

begin_comment
comment|/*   * For Qlogic 2100, the high order byte of SCSI status has  * additional meaning.  */
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
comment|/* Residual Valid */
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
name|RQCS_INCOMPLETE
value|0x0001
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
name|RQCS_TRANSPORT_ERROR
value|0x0003
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
name|RQCS_DATA_UNDERRUN
value|0x0015
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
name|RQCS_QUEUE_FULL
value|0x001C
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
comment|/* 2100 Only Completion Codes */
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
comment|/*  * State Flags (not applicable to 2100)  */
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
comment|/*  * Status Flags (not applicable to 2100)  */
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
name|ICBOPT_USE_PORTNAME
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
value|(x)[0]<< 16 | (x)[3]<< 8 | (x)[2]
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

begin_comment
comment|/*  * Target Mode Structures  */
end_comment

begin_define
define|#
directive|define
name|TGTSVALID
value|0x80
end_define

begin_comment
comment|/* scsi status& sense data valid */
end_comment

begin_define
define|#
directive|define
name|SUGGSENSELEN
value|18
end_define

begin_comment
comment|/*  * Structure for Enable Lun and Modify Lun queue entries  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|le_header
decl_stmt|;
name|u_int32_t
name|le_reserved2
decl_stmt|;
name|u_int8_t
name|le_lun
decl_stmt|;
name|u_int8_t
name|le_rsvd
decl_stmt|;
name|u_int8_t
name|le_ops
decl_stmt|;
comment|/* Modify LUN only */
name|u_int8_t
name|le_tgt
decl_stmt|;
comment|/* Not for FC */
name|u_int32_t
name|le_flags
decl_stmt|;
comment|/* Not for FC */
name|u_int8_t
name|le_status
decl_stmt|;
name|u_int8_t
name|le_rsvd2
decl_stmt|;
name|u_int8_t
name|le_cmd_count
decl_stmt|;
name|u_int8_t
name|le_in_count
decl_stmt|;
name|u_int8_t
name|le_cdb6len
decl_stmt|;
comment|/* Not for FC */
name|u_int8_t
name|le_cdb7len
decl_stmt|;
comment|/* Not for FC */
name|u_int16_t
name|le_timeout
decl_stmt|;
name|u_int16_t
name|le_reserved
index|[
literal|20
index|]
decl_stmt|;
block|}
name|lun_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * le_flags values  */
end_comment

begin_define
define|#
directive|define
name|LUN_TQAE
value|0x00000001
end_define

begin_comment
comment|/* Tagged Queue Action Enable */
end_comment

begin_define
define|#
directive|define
name|LUN_DSSM
value|0x01000000
end_define

begin_comment
comment|/* Disable Sending SDP Message */
end_comment

begin_define
define|#
directive|define
name|LUN_DM
value|0x40000000
end_define

begin_comment
comment|/* Disconnects Mandatory */
end_comment

begin_comment
comment|/*  * le_ops values  */
end_comment

begin_define
define|#
directive|define
name|LUN_CCINCR
value|0x01
end_define

begin_comment
comment|/* increment command count */
end_comment

begin_define
define|#
directive|define
name|LUN_CCDECR
value|0x02
end_define

begin_comment
comment|/* decrement command count */
end_comment

begin_define
define|#
directive|define
name|LUN_ININCR
value|0x40
end_define

begin_comment
comment|/* increment immed. notify count */
end_comment

begin_define
define|#
directive|define
name|LUN_INDECR
value|0x80
end_define

begin_comment
comment|/* decrement immed. notify count */
end_comment

begin_comment
comment|/*  * le_status values  */
end_comment

begin_define
define|#
directive|define
name|LUN_ERR
value|0x04
end_define

begin_comment
comment|/* request completed with error */
end_comment

begin_define
define|#
directive|define
name|LUN_INVAL
value|0x06
end_define

begin_comment
comment|/* invalid request */
end_comment

begin_define
define|#
directive|define
name|LUN_NOCAP
value|0x16
end_define

begin_comment
comment|/* can't provide requested capability */
end_comment

begin_define
define|#
directive|define
name|LUN_ENABLED
value|0x3E
end_define

begin_comment
comment|/* LUN already enabled */
end_comment

begin_comment
comment|/*  * Immediate Notify Entry structure  */
end_comment

begin_define
define|#
directive|define
name|IN_MSGLEN
value|8
end_define

begin_comment
comment|/* 8 bytes */
end_comment

begin_define
define|#
directive|define
name|IN_RSVDLEN
value|8
end_define

begin_comment
comment|/* 8 words */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|u_int32_t
name|in_reserved2
decl_stmt|;
name|u_int8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|in_rsvd
decl_stmt|;
name|u_int8_t
name|in_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|in_flags
decl_stmt|;
name|u_int8_t
name|in_status
decl_stmt|;
name|u_int8_t
name|in_rsvd2
decl_stmt|;
name|u_int8_t
name|in_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|in_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int8_t
name|in_msg
index|[
name|IN_MSGLEN
index|]
decl_stmt|;
comment|/* SCSI message bytes */
name|u_int16_t
name|in_reserved
index|[
name|IN_RSVDLEN
index|]
decl_stmt|;
name|u_int8_t
name|in_sense
index|[
name|SUGGSENSELEN
index|]
decl_stmt|;
comment|/* suggested sense data */
block|}
name|in_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|u_int32_t
name|in_reserved2
decl_stmt|;
name|u_int8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|in_rsvd
decl_stmt|;
name|u_int32_t
name|in_rsvd2
decl_stmt|;
name|u_int16_t
name|in_status
decl_stmt|;
name|u_int16_t
name|in_task_flags
decl_stmt|;
name|u_int16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for the in_status field  */
end_comment

begin_define
define|#
directive|define
name|IN_NO_RCAP
value|0x16
end_define

begin_comment
comment|/* requested capability not available */
end_comment

begin_define
define|#
directive|define
name|IN_IDE_RECEIVED
value|0x33
end_define

begin_comment
comment|/* Initiator Detected Error msg received */
end_comment

begin_define
define|#
directive|define
name|IN_RSRC_UNAVAIL
value|0x34
end_define

begin_comment
comment|/* resource unavailable */
end_comment

begin_define
define|#
directive|define
name|IN_MSG_RECEIVED
value|0x36
end_define

begin_comment
comment|/* SCSI message received */
end_comment

begin_define
define|#
directive|define
name|IN_PORT_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port has logged out (FC) */
end_comment

begin_define
define|#
directive|define
name|IN_ABORT_TASK
value|0x20
end_define

begin_comment
comment|/* task named in RX_ID is being aborted (FC) */
end_comment

begin_comment
comment|/*  * Notify Acknowledge Entry structure  */
end_comment

begin_define
define|#
directive|define
name|NA_RSVDLEN
value|22
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|u_int32_t
name|na_reserved2
decl_stmt|;
name|u_int8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|na_rsvd
decl_stmt|;
name|u_int8_t
name|na_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|na_flags
decl_stmt|;
name|u_int8_t
name|na_status
decl_stmt|;
name|u_int8_t
name|na_event
decl_stmt|;
name|u_int16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int16_t
name|na_reserved
index|[
name|NA_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Value for the na_event field  */
end_comment

begin_define
define|#
directive|define
name|NA_RST_CLRD
value|0x80
end_define

begin_comment
comment|/* Clear an async event notification */
end_comment

begin_define
define|#
directive|define
name|NA2_RSVDLEN
value|21
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|u_int32_t
name|na_reserved2
decl_stmt|;
name|u_int8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|na_rsvd
decl_stmt|;
name|u_int16_t
name|na_flags
decl_stmt|;
name|u_int16_t
name|na_rsvd2
decl_stmt|;
name|u_int16_t
name|na_status
decl_stmt|;
name|u_int16_t
name|na_task_flags
decl_stmt|;
name|u_int16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|u_int16_t
name|na_reserved
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NAFC_RST_CLRD
value|0x40
end_define

begin_comment
comment|/*  * Value for the na_event field  */
end_comment

begin_define
define|#
directive|define
name|NA_RST_CLRD
value|0x80
end_define

begin_comment
comment|/* Clear an async event notification */
end_comment

begin_comment
comment|/*  * Accept Target I/O Entry structure  */
end_comment

begin_define
define|#
directive|define
name|ATIO_CDBLEN
value|26
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|u_int32_t
name|at_reserved2
decl_stmt|;
name|u_int8_t
name|at_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|u_int8_t
name|at_cdblen
decl_stmt|;
comment|/* cdb length */
name|u_int8_t
name|at_tgt
decl_stmt|;
comment|/* target */
name|u_int32_t
name|at_flags
decl_stmt|;
name|u_int8_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|u_int8_t
name|at_scsi_status
decl_stmt|;
comment|/* scsi status */
name|u_int8_t
name|at_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|at_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int8_t
name|at_cdb
index|[
name|ATIO_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|u_int8_t
name|at_sense
index|[
name|SUGGSENSELEN
index|]
decl_stmt|;
comment|/* suggested sense data */
block|}
name|at_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * at_flags values  */
end_comment

begin_define
define|#
directive|define
name|AT_NODISC
value|0x00008000
end_define

begin_comment
comment|/* disconnect disabled */
end_comment

begin_define
define|#
directive|define
name|AT_TQAE
value|0x00000001
end_define

begin_comment
comment|/* Tagged Queue Action enabled */
end_comment

begin_comment
comment|/*  * at_status values  */
end_comment

begin_define
define|#
directive|define
name|AT_PATH_INVALID
value|0x07
end_define

begin_comment
comment|/* ATIO sent to firmware for disabled lun */
end_comment

begin_define
define|#
directive|define
name|AT_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|/* Bus phase sequence error */
end_comment

begin_define
define|#
directive|define
name|AT_NOCAP
value|0x16
end_define

begin_comment
comment|/* Requested capability not available */
end_comment

begin_define
define|#
directive|define
name|AT_BDR_MSG
value|0x17
end_define

begin_comment
comment|/* Bus Device Reset msg received */
end_comment

begin_define
define|#
directive|define
name|AT_CDB
value|0x3D
end_define

begin_comment
comment|/* CDB received */
end_comment

begin_comment
comment|/*  * Accept Target I/O Entry structure, Type 2  */
end_comment

begin_define
define|#
directive|define
name|ATIO2_CDBLEN
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|u_int32_t
name|at_reserved2
decl_stmt|;
name|u_int8_t
name|at_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|u_int16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|u_int16_t
name|at_flags
decl_stmt|;
name|u_int16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|u_int8_t
name|at_reserved1
decl_stmt|;
name|u_int8_t
name|at_taskcodes
decl_stmt|;
name|u_int8_t
name|at_taskflags
decl_stmt|;
name|u_int8_t
name|at_execodes
decl_stmt|;
name|u_int8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|u_int32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|u_int16_t
name|at_scclun
decl_stmt|;
name|u_int16_t
name|at_reserved3
decl_stmt|;
name|u_int16_t
name|at_scsi_status
decl_stmt|;
name|u_int8_t
name|at_sense
index|[
name|SUGGSENSELEN
index|]
decl_stmt|;
comment|/* suggested sense data */
block|}
name|at2_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_SIMPLEQ
value|0
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_HEADOFQ
value|1
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_ORDERED
value|2
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_ACAQ
value|4
end_define

begin_define
define|#
directive|define
name|ATIO2_TC_ATTR_UNTAGGED
value|5
end_define

begin_define
define|#
directive|define
name|TC2TT
parameter_list|(
name|code
parameter_list|)
define|\
value|(((code) == ATIO2_TC_ATTR_SIMPLEQ)? 0x20 : \ 	(((code) == ATIO2_TC_ATTR_HEADOFQ)? 0x21 : \ 	(((code) == ATIO2_TC_ATTR_ORDERED)? 0x22 : \ 	(((code) == ATIO2_TC_ATTR_ACAQ)? 0x24 : 0))))
end_define

begin_comment
comment|/*  * Continue Target I/O Entry structure  * Request from driver. The response from the  * ISP firmware is the same except that the last 18  * bytes are overwritten by suggested sense data if  * the 'autosense valid' bit is set in the status byte.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|u_int32_t
name|ct_reserved
decl_stmt|;
name|u_int8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|u_int8_t
name|ct_rsvd
decl_stmt|;
name|u_int8_t
name|ct_tgt
decl_stmt|;
comment|/* our target id */
name|u_int32_t
name|ct_flags
decl_stmt|;
name|u_int8_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|u_int8_t
name|ct_scsi_status
decl_stmt|;
comment|/* scsi status */
name|u_int8_t
name|ct_tag_val
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|ct_tag_type
decl_stmt|;
comment|/* tag type */
name|u_int32_t
name|ct_xfrlen
decl_stmt|;
comment|/* transfer length */
name|u_int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|u_int16_t
name|ct_timeout
decl_stmt|;
name|u_int16_t
name|ct_seg_count
decl_stmt|;
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG
index|]
decl_stmt|;
block|}
name|ct_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values  */
end_comment

begin_define
define|#
directive|define
name|CT_TQAE
value|0x00000001
end_define

begin_comment
comment|/* Tagged Queue Action enable */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_IN
value|0x00000040
end_define

begin_comment
comment|/* Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_OUT
value|0x00000080
end_define

begin_comment
comment|/* Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_NO_DATA
value|0x000000C0
end_define

begin_comment
comment|/* Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_DATAMASK
value|0x000000C0
end_define

begin_comment
comment|/* Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_NODISC
value|0x00008000
end_define

begin_comment
comment|/* Disconnects disabled */
end_comment

begin_define
define|#
directive|define
name|CT_DSDP
value|0x01000000
end_define

begin_comment
comment|/* Disable Save Data Pointers */
end_comment

begin_define
define|#
directive|define
name|CT_SENDRDP
value|0x04000000
end_define

begin_comment
comment|/* Send Restore Pointers msg */
end_comment

begin_define
define|#
directive|define
name|CT_SENDSTATUS
value|0x80000000
end_define

begin_comment
comment|/* Send SCSI status byte */
end_comment

begin_comment
comment|/*  * ct_status values  * - set by the firmware when it returns the CTIO  */
end_comment

begin_define
define|#
directive|define
name|CT_OK
value|0x01
end_define

begin_comment
comment|/* completed without error */
end_comment

begin_define
define|#
directive|define
name|CT_ABORTED
value|0x02
end_define

begin_comment
comment|/* aborted by host */
end_comment

begin_define
define|#
directive|define
name|CT_ERR
value|0x04
end_define

begin_comment
comment|/* see sense data for error */
end_comment

begin_define
define|#
directive|define
name|CT_INVAL
value|0x06
end_define

begin_comment
comment|/* request for disabled lun */
end_comment

begin_define
define|#
directive|define
name|CT_NOPATH
value|0x07
end_define

begin_comment
comment|/* invalid ITL nexus */
end_comment

begin_define
define|#
directive|define
name|CT_INVRXID
value|0x08
end_define

begin_comment
comment|/* (FC only) Invalid RX_ID */
end_comment

begin_define
define|#
directive|define
name|CT_RSELTMO
value|0x0A
end_define

begin_comment
comment|/* reselection timeout after 2 tries */
end_comment

begin_define
define|#
directive|define
name|CT_TIMEOUT
value|0x0B
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|CT_RESET
value|0x0E
end_define

begin_comment
comment|/* SCSI Bus Reset occurred */
end_comment

begin_define
define|#
directive|define
name|CT_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|/* Bus phase sequence error */
end_comment

begin_define
define|#
directive|define
name|CT_BDR_MSG
value|0x17
end_define

begin_comment
comment|/* Bus Device Reset msg received */
end_comment

begin_define
define|#
directive|define
name|CT_TERMINATED
value|0x19
end_define

begin_comment
comment|/* due to Terminate Transfer mbox cmd */
end_comment

begin_define
define|#
directive|define
name|CT_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port logout not acknowledged yet */
end_comment

begin_define
define|#
directive|define
name|CT_NOACK
value|0x35
end_define

begin_comment
comment|/* Outstanding Immed. Notify. entry */
end_comment

begin_comment
comment|/*  * When the firmware returns a CTIO entry, it may overwrite the last  * part of the structure with sense data. This starts at offset 0x2E  * into the entry, which is in the middle of ct_dataseg[1]. Rather  * than define a new struct for this, I'm just using the sense data  * offset.  */
end_comment

begin_define
define|#
directive|define
name|CTIO_SENSE_OFFSET
value|0x2E
end_define

begin_comment
comment|/*  * Entry length in u_longs. All entries are the same size so  * any one will do as the numerator.  */
end_comment

begin_define
define|#
directive|define
name|UINT32_ENTRY_SIZE
value|(sizeof(at_entry_t)/sizeof(u_int32_t))
end_define

begin_comment
comment|/*  * QLA2100 CTIO (type 2) entry  */
end_comment

begin_define
define|#
directive|define
name|MAXRESPLEN
value|26
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|u_int32_t
name|ct_reserved
decl_stmt|;
name|u_int8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|u_int8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|u_int16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|u_int16_t
name|ct_flags
decl_stmt|;
name|u_int16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|u_int16_t
name|ct_timeout
decl_stmt|;
name|u_int16_t
name|ct_seg_count
decl_stmt|;
name|u_int32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|u_int32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
comment|/* 		 * The three different modes that the target driver 		 * can set the CTIO2 up as. 		 * 		 * The first is for sending FCP_DATA_IUs as well as 		 * (optionally) sending a terminal SCSI status FCP_RSP_IU. 		 * 		 * The second is for sending SCSI sense data in an FCP_RSP_IU. 		 * Note that no FCP_DATA_IUs will be sent. 		 * 		 * The third is for sending FCP_RSP_IUs as built specifically 		 * in system memory as located by the isp_dataseg. 		 */
struct|struct
block|{
name|u_int32_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int32_t
name|ct_xfrlen
decl_stmt|;
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
block|}
name|m0
struct|;
struct|struct
block|{
name|u_int16_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|ct_senselen
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int16_t
name|ct_resplen
decl_stmt|;
name|u_int8_t
name|ct_resp
index|[
name|MAXRESPLEN
index|]
decl_stmt|;
block|}
name|m1
struct|;
struct|struct
block|{
name|u_int32_t
name|_reserved
decl_stmt|;
name|u_int16_t
name|_reserved2
decl_stmt|;
name|u_int16_t
name|_reserved3
decl_stmt|;
name|u_int32_t
name|ct_datalen
decl_stmt|;
name|ispds_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
comment|/* 		 * CTIO2 returned from F/W... 		 */
struct|struct
block|{
name|u_int32_t
name|_reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|ct_scsi_status
decl_stmt|;
name|u_int8_t
name|ct_sense
index|[
name|SUGGSENSELEN
index|]
decl_stmt|;
block|}
name|fw
struct|;
block|}
name|rsp
union|;
block|}
name|ct2_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO2  */
end_comment

begin_define
define|#
directive|define
name|CT2_FLAG_MMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE0
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE1
value|0x0001
end_define

begin_define
define|#
directive|define
name|CT2_FLAG_MODE2
value|0x0002
end_define

begin_define
define|#
directive|define
name|CT2_DATA_IN
value|CT_DATA_IN
end_define

begin_define
define|#
directive|define
name|CT2_DATA_OUT
value|CT_DATA_OUT
end_define

begin_define
define|#
directive|define
name|CT2_NO_DATA
value|CT_NO_DATA
end_define

begin_define
define|#
directive|define
name|CT2_DATAMASK
value|CT_DATA_MASK
end_define

begin_define
define|#
directive|define
name|CT2_CCINCR
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT2_FASTPOST
value|0x0200
end_define

begin_define
define|#
directive|define
name|CT2_SENDSTATUS
value|0x8000
end_define

begin_comment
comment|/*  * ct_status values are (mostly) the same as that for ct_entry.  */
end_comment

begin_comment
comment|/*  * ct_scsi_status values- the low 8 bits are the normal SCSI status  * we know and love. The upper 8 bits are validity markers for FCP_RSP_IU  * fields.  */
end_comment

begin_define
define|#
directive|define
name|CT2_RSPLEN_VALID
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT2_SNSLEN_VALID
value|0x0200
end_define

begin_define
define|#
directive|define
name|CT2_DATA_OVER
value|0x0400
end_define

begin_define
define|#
directive|define
name|CT2_DATA_UNDER
value|0x0800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPMBOX_H */
end_comment

end_unit

