begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  *  Copyright (c) 1997-2009 by Matthew Jacob  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *   *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  *   */
end_comment

begin_comment
comment|/*  * Mailbox and Queue Entry Definitions for for Qlogic ISP SCSI adapters.  */
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

begin_define
define|#
directive|define
name|MBOX_DUMP_RISC_RAM
value|0x000c
end_define

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
name|MBOX_LOAD_FLASH_FIRMWARE
value|0x0003
end_define

begin_define
define|#
directive|define
name|MBOX_WRITE_FC_SERDES_REG
value|0x0003
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|MBOX_READ_FC_SERDES_REG
value|0x0004
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_IO_STATUS
value|0x0012
end_define

begin_define
define|#
directive|define
name|MBOX_SET_TRANSMIT_PARAMS
value|0x0019
end_define

begin_define
define|#
directive|define
name|MBOX_SET_PORT_PARAMS
value|0x001a
end_define

begin_define
define|#
directive|define
name|MBOX_LOAD_OP_FW_PARAMS
value|0x001b
end_define

begin_define
define|#
directive|define
name|MBOX_INIT_MULTIPLE_QUEUE
value|0x001f
end_define

begin_define
define|#
directive|define
name|MBOX_GET_LOOP_ID
value|0x0020
end_define

begin_comment
comment|/* for 24XX cards, outgoing mailbox 7 has these values for F or FL topologies */
end_comment

begin_define
define|#
directive|define
name|ISP24XX_INORDER
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISP24XX_NPIV_SAN
value|0x0400
end_define

begin_define
define|#
directive|define
name|ISP24XX_VSAN_SAN
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISP24XX_FC_SP_SAN
value|0x2000
end_define

begin_define
define|#
directive|define
name|MBOX_GET_TIMEOUT_PARAMS
value|0x0022
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
name|MBOX_GENERATE_SYSTEM_ERROR
value|0x002a
end_define

begin_define
define|#
directive|define
name|MBOX_WRITE_SFP
value|0x0030
end_define

begin_define
define|#
directive|define
name|MBOX_READ_SFP
value|0x0031
end_define

begin_define
define|#
directive|define
name|MBOX_SET_TIMEOUT_PARAMS
value|0x0032
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
name|MBOX_GET_SET_FC_LED_CONF
value|0x003b
end_define

begin_define
define|#
directive|define
name|MBOX_RESTART_NIC_FIRMWARE
value|0x003d
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|MBOX_ACCESS_CONTROL
value|0x003e
end_define

begin_define
define|#
directive|define
name|MBOX_LOOP_PORT_BYPASS
value|0x0040
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|MBOX_LOOP_PORT_ENABLE
value|0x0041
end_define

begin_comment
comment|/* FC only */
end_comment

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
name|MBOX_DIAGNOSTIC_ECHO_TEST
value|0x0044
end_define

begin_define
define|#
directive|define
name|MBOX_DIAGNOSTIC_LOOPBACK
value|0x0045
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
name|MBOX_INIT_FIRMWARE_MULTI_ID
value|0x0048
end_define

begin_comment
comment|/* 2400 only */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_VP_DATABASE
value|0x0049
end_define

begin_comment
comment|/* 2400 only */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_VP_DATABASE_ENTRY
value|0x004a
end_define

begin_comment
comment|/* 2400 only */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_FCF_LIST
value|0x0050
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|MBOX_GET_DCBX_PARAMETERS
value|0x0051
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|MBOX_HOST_MEMORY_COPY
value|0x0053
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
name|MBOX_SEND_RNID
value|0x0057
end_define

begin_define
define|#
directive|define
name|MBOX_SET_PARAMETERS
value|0x0059
end_define

begin_define
define|#
directive|define
name|MBOX_GET_PARAMETERS
value|0x005a
end_define

begin_define
define|#
directive|define
name|MBOX_DRIVER_HEARTBEAT
value|0x005B
end_define

begin_comment
comment|/* FC only */
end_comment

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
comment|/*>=23XX only */
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
name|MBGSD_1GB
value|0x00
end_define

begin_define
define|#
directive|define
name|MBGSD_2GB
value|0x01
end_define

begin_define
define|#
directive|define
name|MBGSD_AUTO
value|0x02
end_define

begin_define
define|#
directive|define
name|MBGSD_4GB
value|0x03
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|MBGSD_8GB
value|0x04
end_define

begin_comment
comment|/* 25XX only */
end_comment

begin_define
define|#
directive|define
name|MBGSD_16GB
value|0x05
end_define

begin_comment
comment|/* 26XX only */
end_comment

begin_define
define|#
directive|define
name|MBGSD_10GB
value|0x13
end_define

begin_comment
comment|/* 26XX only */
end_comment

begin_define
define|#
directive|define
name|MBOX_SEND_RNFT
value|0x005e
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
name|MBOX_GET_LINK_STAT_PR_DATA_CNT
value|0x006D
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
name|MBOX_GET_PORT_NODE_NAME_LIST
value|0x0075
end_define

begin_define
define|#
directive|define
name|MBOX_SET_VENDOR_ID
value|0x0076
end_define

begin_define
define|#
directive|define
name|MBOX_GET_XGMAC_STATS
value|0x007a
end_define

begin_define
define|#
directive|define
name|MBOX_GET_ID_LIST
value|0x007C
end_define

begin_define
define|#
directive|define
name|MBOX_SEND_LFA
value|0x007d
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

begin_define
define|#
directive|define
name|MBOX_LINK_DOWN_ERROR
value|0x400B
end_define

begin_define
define|#
directive|define
name|MBOX_LOOPBACK_ERROR
value|0x400C
end_define

begin_define
define|#
directive|define
name|MBOX_CHECKSUM_ERROR
value|0x4010
end_define

begin_define
define|#
directive|define
name|MBOX_INVALID_PRODUCT_KEY
value|0x4020
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
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MBLOGNONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MBLOGMASK
parameter_list|(
name|x
parameter_list|)
value|(1<< (((x) - 1)& 0x1f))
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

begin_comment
comment|/* FC only */
end_comment

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

begin_comment
comment|/* FC only */
end_comment

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
name|ASYNC_LIP_NOS_OLS_RECV
value|0x8016
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_LIP_ERROR
value|0x8017
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_AUTO_PLOGI_RJT
value|0x8018
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
name|ASYNC_RIO32_1
value|0x8021
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO32_2
value|0x8022
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
name|ASYNC_ERR_LOGGING_DISABLED
value|0x8029
end_define

begin_define
define|#
directive|define
name|ASYNC_PTPMODE
value|0x8030
end_define

begin_comment
comment|/* FC only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_RIO16_1
value|0x8031
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO16_2
value|0x8032
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO16_3
value|0x8033
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO16_4
value|0x8034
end_define

begin_define
define|#
directive|define
name|ASYNC_RIO16_5
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
name|ASYNC_P2P_INIT_ERR
value|0x8037
end_define

begin_define
define|#
directive|define
name|ASYNC_RIOZIO_STALL
value|0x8040
end_define

begin_comment
comment|/* there's a RIO/ZIO entry that hasn't been serviced */
end_comment

begin_define
define|#
directive|define
name|ASYNC_RIO32_2_2200
value|0x8042
end_define

begin_comment
comment|/* same as ASYNC_RIO32_2, but for 2100/2200 */
end_comment

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

begin_define
define|#
directive|define
name|ASYNC_RJT_SENT
value|0x8049
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_SEL_CLASS2_P_RJT_SENT
value|0x804f
end_define

begin_define
define|#
directive|define
name|ASYNC_FW_RESTART_COMPLETE
value|0x8060
end_define

begin_define
define|#
directive|define
name|ASYNC_TEMPERATURE_ALERT
value|0x8070
end_define

begin_define
define|#
directive|define
name|ASYNC_INTER_DRIVER_COMP
value|0x8100
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_INTER_DRIVER_NOTIFY
value|0x8101
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_INTER_DRIVER_TIME_EXT
value|0x8102
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_NIC_FW_STATE_CHANGE
value|0x8200
end_define

begin_comment
comment|/* FCoE only */
end_comment

begin_define
define|#
directive|define
name|ASYNC_AUTOLOAD_FW_COMPLETE
value|0x8400
end_define

begin_define
define|#
directive|define
name|ASYNC_AUTOLOAD_FW_FAILURE
value|0x8401
end_define

begin_comment
comment|/*  * Firmware Options. There are a lot of them.  *  * IFCOPTN - ISP Fibre Channel Option Word N  */
end_comment

begin_define
define|#
directive|define
name|IFCOPT1_EQFQASYNC
value|(1<< 13)
end_define

begin_comment
comment|/* enable QFULL notification */
end_comment

begin_define
define|#
directive|define
name|IFCOPT1_EAABSRCVD
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_RJTASYNC
value|(1<< 11)
end_define

begin_comment
comment|/* enable 8018 notification */
end_comment

begin_define
define|#
directive|define
name|IFCOPT1_ENAPURE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_ENA8017
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_DISGPIO67
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_LIPLOSSIMM
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_DISF7SWTCH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_CTIO_RETRY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_LIPASYNC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IFCOPT1_LIPF8
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IFCOPT2_LOOPBACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IFCOPT2_ATIO3_ONLY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IFCOPT3_NOPRLI
value|(1<< 4)
end_define

begin_comment
comment|/* disable automatic sending of PRLI on local loops */
end_comment

begin_define
define|#
directive|define
name|IFCOPT3_RNDASYNC
value|(1<< 1)
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
name|RQSFLAG_BADCOUNT
value|0x10
end_define

begin_define
define|#
directive|define
name|RQSFLAG_BADORDER
value|0x20
end_define

begin_define
define|#
directive|define
name|RQSFLAG_MASK
value|0x3f
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
name|RQSTYPE_VP_CTRL
value|0x30
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_VP_MODIFY
value|0x31
end_define

begin_comment
comment|/* 24XX only */
end_comment

begin_define
define|#
directive|define
name|RQSTYPE_RPT_ID_ACQ
value|0x32
end_define

begin_comment
comment|/* 24XX only */
end_comment

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
name|uint8_t
name|req_crn
decl_stmt|;
name|uint8_t
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
name|uint8_t
name|req_crn
decl_stmt|;
name|uint8_t
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
name|uint8_t
name|req_crn
decl_stmt|;
name|uint8_t
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
name|uint8_t
name|req_crn
decl_stmt|;
name|uint8_t
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
comment|/*  * ISP24XX structures  */
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
comment|/* Task Management Request Function */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|tmf_header
decl_stmt|;
name|uint32_t
name|tmf_handle
decl_stmt|;
name|uint16_t
name|tmf_nphdl
decl_stmt|;
name|uint8_t
name|tmf_reserved0
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|tmf_delay
decl_stmt|;
name|uint16_t
name|tmf_timeout
decl_stmt|;
name|uint8_t
name|tmf_lun
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|tmf_flags
decl_stmt|;
name|uint8_t
name|tmf_reserved1
index|[
literal|20
index|]
decl_stmt|;
name|uint16_t
name|tmf_tidlo
decl_stmt|;
name|uint8_t
name|tmf_tidhi
decl_stmt|;
name|uint8_t
name|tmf_vpidx
decl_stmt|;
name|uint8_t
name|tmf_reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|isp24xx_tmf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISP24XX_TMF_NOSEND
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ISP24XX_TMF_LUN_RESET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ISP24XX_TMF_ABORT_TASK_SET
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ISP24XX_TMF_CLEAR_TASK_SET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ISP24XX_TMF_TARGET_RESET
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ISP24XX_TMF_CLEAR_ACA
value|0x00000001
end_define

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
name|uint16_t
name|abrt_queue_number
decl_stmt|;
name|uint8_t
name|abrt_reserved
index|[
literal|30
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
name|ISP24XX_ABRT_NOSEND
value|0x01
end_define

begin_comment
comment|/* don't actually send ABTS */
end_comment

begin_define
define|#
directive|define
name|ISP24XX_ABRT_OKAY
value|0x00
end_define

begin_comment
comment|/* in nphdl on return */
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
name|req_retry_delay
decl_stmt|;
comment|/* aka Status Qualifier */
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
name|RQCS_CR
value|0x1000
end_define

begin_comment
comment|/* Confirmation Request */
end_comment

begin_define
define|#
directive|define
name|RQCS_RU
value|0x0800
end_define

begin_comment
comment|/* Residual Under */
end_comment

begin_define
define|#
directive|define
name|RQCS_RO
value|0x0400
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
value|0x0200
end_define

begin_comment
comment|/* Sense Length Valid */
end_comment

begin_define
define|#
directive|define
name|RQCS_RV
value|0x0100
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
name|uint8_t
name|ctp_vpidx
decl_stmt|;
name|uint8_t
name|ctp_reserved0
decl_stmt|;
name|uint16_t
name|ctp_time
decl_stmt|;
name|uint16_t
name|ctp_reserved1
decl_stmt|;
name|uint16_t
name|ctp_rsp_cnt
decl_stmt|;
comment|/* Response DSD count */
name|uint16_t
name|ctp_reserved2
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
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_SCCLUN
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_FABRIC
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_CLASS2
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_FCTAPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_IP
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_VI
value|0x0040
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_VI_SOLARIS
value|0x0080
end_define

begin_define
define|#
directive|define
name|ISP_FW_ATTR_2KLOGINS
value|0x0100
end_define

begin_comment
comment|/* just a guess... */
end_comment

begin_comment
comment|/* and these are for the 2400 */
end_comment

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_CLASS2
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_IP
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_MULTIID
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_SB2
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_T10CRC
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_VI
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_MQ
value|0x0040
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_MSIX
value|0x0080
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_FCOE
value|0x0800
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_VP0
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_EXPFW
value|0x2000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_HOTFW
value|0x4000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_EXTNDED
value|0x8000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_EXTVP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_VN2VN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_EXMOFF
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_NPMOFF
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_DIFCHOP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_SRIOV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_ASICTMP
value|0x0200000000
end_define

begin_define
define|#
directive|define
name|ISP2400_FW_ATTR_ATIOMQ
value|0x0400000000
end_define

begin_comment
comment|/*  * These are either manifestly true or are dependent on f/w attributes  */
end_comment

begin_define
define|#
directive|define
name|ISP_CAP_TMODE
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? 1 : (isp->isp_fwattr& ISP_FW_ATTR_TMODE))
end_define

begin_define
define|#
directive|define
name|ISP_CAP_SCCFW
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? 1 : (isp->isp_fwattr& ISP_FW_ATTR_SCCLUN))
end_define

begin_define
define|#
directive|define
name|ISP_CAP_2KLOGIN
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? 1 : (isp->isp_fwattr& ISP_FW_ATTR_2KLOGINS))
end_define

begin_comment
comment|/*  * This is only true for 24XX cards with this f/w attribute  */
end_comment

begin_define
define|#
directive|define
name|ISP_CAP_MULTI_ID
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? (isp->isp_fwattr& ISP2400_FW_ATTR_MULTIID) : 0)
end_define

begin_define
define|#
directive|define
name|ISP_GET_VPIDX
parameter_list|(
name|isp
parameter_list|,
name|tag
parameter_list|)
define|\
value|(ISP_CAP_MULTI_ID(isp) ? tag : 0)
end_define

begin_define
define|#
directive|define
name|ISP_CAP_MSIX
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? (isp->isp_fwattr& ISP2400_FW_ATTR_MSIX) : 0)
end_define

begin_define
define|#
directive|define
name|ISP_CAP_VP0
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? (isp->isp_fwattr& ISP2400_FW_ATTR_VP0) : 0)
end_define

begin_comment
comment|/*  * This is true manifestly or is dependent on a f/w attribute  * but may or may not actually be *enabled*. In any case, it  * is enabled on a per-channel basis.  */
end_comment

begin_define
define|#
directive|define
name|ISP_CAP_FCTAPE
parameter_list|(
name|isp
parameter_list|)
define|\
value|(IS_24XX(isp)? 1 : (isp->isp_fwattr& ISP_FW_ATTR_FCTAPE))
end_define

begin_define
define|#
directive|define
name|ISP_FCTAPE_ENABLED
parameter_list|(
name|isp
parameter_list|,
name|chan
parameter_list|)
define|\
value|(IS_24XX(isp)? (FCPARAM(isp, chan)->isp_xfwoptions& ICB2400_OPT2_FCTAPE) != 0 : (FCPARAM(isp, chan)->isp_xfwoptions& ICBXOPT_FCTAPE) != 0)
end_define

begin_comment
comment|/*  * Reduced Interrupt Operation Response Queue Entries  */
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
name|ICBOPT_PREV_ADDRESS
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
name|ICBOPT_TGT_TYPE
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
name|ICBZOPT_RATE_1GB
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
name|ICBZOPT_RATE_2GB
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
name|ICBZOPT_NO_LOCAL_PLOGI
value|0x0080
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
name|ICB2400_OPT1_PREV_ADDRESS
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
name|ICB2400_OPT2_ENA_ATIOMQ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ENA_IHA
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_QOS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_IOCBS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ENA_IHR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ENA_VMS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_ENA_TA
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT2_TPRLIC
value|0x00004000
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
name|ICB2400_OPT2_FCSP
value|0x00000800
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
name|ICB2400_OPT2_TIMER_MASK
value|0x0000000f
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
name|ICB2400_OPT3_NO_CTXDIS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_ENA_ETH_RESP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_ENA_ETH_ATIO
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_ENA_MFCF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_SKIP_4GB
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
name|ICB2400_OPT3_RATE_1GB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_2GB
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
name|ICB2400_OPT3_RATE_4GB
value|0x00006000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_8GB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ICB2400_OPT3_RATE_16GB
value|0x0000A000
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
name|ICB2400_OPT3_NO_N2N_LOGI
value|0x00000100
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
value|10
end_define

begin_define
define|#
directive|define
name|ICB_LUN_ENABLE_TOV
value|15
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
name|icb_msixresp
decl_stmt|;
name|uint16_t
name|icb_msixatio
decl_stmt|;
name|uint16_t
name|icb_reserved1
index|[
literal|2
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
name|icb_qos
decl_stmt|;
name|uint16_t
name|icb_reserved2
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|icb_enodemac
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|icb_disctime
decl_stmt|;
name|uint16_t
name|icb_reserved3
index|[
literal|4
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
comment|/*  * For MULTI_ID firmware, this describes a  * virtual port entity for getting status.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|vp_port_status
decl_stmt|;
name|uint8_t
name|vp_port_options
decl_stmt|;
name|uint8_t
name|vp_port_loopid
decl_stmt|;
name|uint8_t
name|vp_port_portname
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|vp_port_nodename
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|vp_port_portid_lo
decl_stmt|;
comment|/* not present when trailing icb */
name|uint16_t
name|vp_port_portid_hi
decl_stmt|;
comment|/* not present when trailing icb */
block|}
name|vp_port_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ICB2400_VPOPT_ENA_SNSLOGIN
value|0x00000040
end_define

begin_comment
comment|/* Enable SNS Login and SCR for Virtual Ports */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_TGT_DISABLE
value|0x00000020
end_define

begin_comment
comment|/* Target Mode Disabled */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_INI_ENABLE
value|0x00000010
end_define

begin_comment
comment|/* Initiator Mode Enabled */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_ENABLED
value|0x00000008
end_define

begin_comment
comment|/* VP Enabled */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_NOPLAY
value|0x00000004
end_define

begin_comment
comment|/* ID Not Acquired */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_PREV_ADDRESS
value|0x00000002
end_define

begin_comment
comment|/* Previously Assigned ID */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_HARD_ADDRESS
value|0x00000001
end_define

begin_comment
comment|/* Hard Assigned ID */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPOPT_WRITE_SIZE
value|20
end_define

begin_comment
comment|/*  * For MULTI_ID firmware, we append this structure  * to the isp_icb_2400_t above, followed by a list  * structures that are *most* of the vp_port_info_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|vp_count
decl_stmt|;
name|uint16_t
name|vp_global_options
decl_stmt|;
block|}
name|isp_icb_2400_vpinfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ICB2400_VPINFO_OFF
value|0x80
end_define

begin_comment
comment|/* offset from start of ICB */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPINFO_PORT_OFF
parameter_list|(
name|chan
parameter_list|)
define|\
value|(ICB2400_VPINFO_OFF + 			\      sizeof (isp_icb_2400_vpinfo_t) + ((chan) * ICB2400_VPOPT_WRITE_SIZE))
end_define

begin_define
define|#
directive|define
name|ICB2400_VPGOPT_FCA
value|0x01
end_define

begin_comment
comment|/* Assume Clean Address bit in FLOGI ACC set (works only in static configurations) */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPGOPT_MID_DISABLE
value|0x02
end_define

begin_comment
comment|/* when set, connection mode2 will work with NPIV-capable switched */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPGOPT_VP0_DECOUPLE
value|0x04
end_define

begin_comment
comment|/* Allow VP0 decoupling if firmware supports it */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPGOPT_SUSP_FDISK
value|0x10
end_define

begin_comment
comment|/* Suspend FDISC for Enabled VPs */
end_comment

begin_define
define|#
directive|define
name|ICB2400_VPGOPT_GEN_RIDA
value|0x20
end_define

begin_comment
comment|/* Generate RIDA if FLOGI Fails */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|vp_ctrl_hdr
decl_stmt|;
name|uint32_t
name|vp_ctrl_handle
decl_stmt|;
name|uint16_t
name|vp_ctrl_index_fail
decl_stmt|;
name|uint16_t
name|vp_ctrl_status
decl_stmt|;
name|uint16_t
name|vp_ctrl_command
decl_stmt|;
name|uint16_t
name|vp_ctrl_vp_count
decl_stmt|;
name|uint16_t
name|vp_ctrl_idmap
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|vp_ctrl_reserved
index|[
literal|7
index|]
decl_stmt|;
name|uint16_t
name|vp_ctrl_fcf_index
decl_stmt|;
block|}
name|vp_ctrl_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VP_CTRL_CMD_ENABLE_VP
value|0x00
end_define

begin_define
define|#
directive|define
name|VP_CTRL_CMD_DISABLE_VP
value|0x08
end_define

begin_define
define|#
directive|define
name|VP_CTRL_CMD_DISABLE_VP_REINIT_LINK
value|0x09
end_define

begin_define
define|#
directive|define
name|VP_CTRL_CMD_DISABLE_VP_LOGO
value|0x0A
end_define

begin_define
define|#
directive|define
name|VP_CTRL_CMD_DISABLE_VP_LOGO_ALL
value|0x0B
end_define

begin_comment
comment|/*  * We can use this structure for modifying either one or two VP ports after initialization  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|vp_mod_hdr
decl_stmt|;
name|uint32_t
name|vp_mod_hdl
decl_stmt|;
name|uint16_t
name|vp_mod_reserved0
decl_stmt|;
name|uint16_t
name|vp_mod_status
decl_stmt|;
name|uint8_t
name|vp_mod_cmd
decl_stmt|;
name|uint8_t
name|vp_mod_cnt
decl_stmt|;
name|uint8_t
name|vp_mod_idx0
decl_stmt|;
name|uint8_t
name|vp_mod_idx1
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|options
decl_stmt|;
name|uint8_t
name|loopid
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|wwpn
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|wwnn
index|[
literal|8
index|]
decl_stmt|;
block|}
name|vp_mod_ports
index|[
literal|2
index|]
struct|;
name|uint8_t
name|vp_mod_reserved2
index|[
literal|8
index|]
decl_stmt|;
block|}
name|vp_modify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VP_STS_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|VP_STS_ERR
value|0x01
end_define

begin_define
define|#
directive|define
name|VP_CNT_ERR
value|0x02
end_define

begin_define
define|#
directive|define
name|VP_GEN_ERR
value|0x03
end_define

begin_define
define|#
directive|define
name|VP_IDX_ERR
value|0x04
end_define

begin_define
define|#
directive|define
name|VP_STS_BSY
value|0x05
end_define

begin_define
define|#
directive|define
name|VP_MODIFY
value|0x00
end_define

begin_define
define|#
directive|define
name|VP_MODIFY_ENA
value|0x01
end_define

begin_define
define|#
directive|define
name|VP_MODIFY_OPT
value|0x02
end_define

begin_define
define|#
directive|define
name|VP_RESUME
value|0x03
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

begin_define
define|#
directive|define
name|PDB2400_STATE_PLOGI_PEND
value|0x03
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_PLOGI_DONE
value|0x04
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_PRLI_PEND
value|0x05
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_LOGGED_IN
value|0x06
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_PORT_UNAVAIL
value|0x07
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_PRLO_PEND
value|0x09
end_define

begin_define
define|#
directive|define
name|PDB2400_STATE_LOGO_PEND
value|0x0B
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
name|prli_word3
decl_stmt|;
name|uint32_t
label|:
literal|8
operator|,
name|portid
operator|:
literal|24
expr_stmt|;
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
comment|/*  * Port/Node Name List Element  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|pnnle_name
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|pnnle_handle
decl_stmt|;
name|uint16_t
name|pnnle_reserved
decl_stmt|;
block|}
name|isp_pnnle_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PNNL_OPTIONS_NODE_NAMES
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PNNL_OPTIONS_PORT_DATA
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PNNL_OPTIONS_INITIATORS
value|(1<<3)
end_define

begin_comment
comment|/*  * Port and N-Port Handle List Element  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pnhle_port_id_lo
decl_stmt|;
name|uint16_t
name|pnhle_port_id_hi_handle
decl_stmt|;
block|}
name|isp_pnhle_21xx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pnhle_port_id_lo
decl_stmt|;
name|uint16_t
name|pnhle_port_id_hi
decl_stmt|;
name|uint16_t
name|pnhle_handle
decl_stmt|;
block|}
name|isp_pnhle_23xx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|pnhle_port_id_lo
decl_stmt|;
name|uint16_t
name|pnhle_port_id_hi
decl_stmt|;
name|uint16_t
name|pnhle_handle
decl_stmt|;
name|uint16_t
name|pnhle_reserved
decl_stmt|;
block|}
name|isp_pnhle_24xx_t
typedef|;
end_typedef

begin_comment
comment|/*  * Port Database Changed Async Event information for 24XX cards  */
end_comment

begin_comment
comment|/* N-Port Handle */
end_comment

begin_define
define|#
directive|define
name|PDB24XX_AE_GLOBAL
value|0xFFFF
end_define

begin_comment
comment|/* Reason Codes */
end_comment

begin_define
define|#
directive|define
name|PDB24XX_AE_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_IMPL_LOGO_1
value|0x01
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_IMPL_LOGO_2
value|0x02
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_IMPL_LOGO_3
value|0x03
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PLOGI_RCVD
value|0x04
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PLOGI_RJT
value|0x05
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PRLI_RCVD
value|0x06
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PRLI_RJT
value|0x07
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_TPRLO
value|0x08
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_TPRLO_RJT
value|0x09
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PRLO_RCVD
value|0x0a
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_LOGO_RCVD
value|0x0b
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_TOPO_CHG
value|0x0c
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_NPORT_CHG
value|0x0d
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_FLOGI_RJT
value|0x0e
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_BAD_FANN
value|0x0f
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_FLOGI_TIMO
value|0x10
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_ABX_LOGO
value|0x11
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PLOGI_DONE
value|0x12
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_PRLI_DONE
value|0x13
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_OPN_1
value|0x14
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_OPN_2
value|0x15
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_TXERR
value|0x16
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_FORCED_LOGO
value|0x17
end_define

begin_define
define|#
directive|define
name|PDB24XX_AE_DISC_TIMO
value|0x18
end_define

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
name|uint16_t
name|channel
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
value|0x09
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
comment|/*  * Report ID Acquisistion (24XX multi-id firmware)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ridacq_hdr
decl_stmt|;
name|uint32_t
name|ridacq_handle
decl_stmt|;
name|uint8_t
name|ridacq_vp_acquired
decl_stmt|;
name|uint8_t
name|ridacq_vp_setup
decl_stmt|;
name|uint8_t
name|ridacq_vp_index
decl_stmt|;
name|uint8_t
name|ridacq_vp_status
decl_stmt|;
name|uint16_t
name|ridacq_vp_port_lo
decl_stmt|;
name|uint8_t
name|ridacq_vp_port_hi
decl_stmt|;
name|uint8_t
name|ridacq_format
decl_stmt|;
comment|/* 0 or 1 */
name|uint16_t
name|ridacq_map
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|ridacq_reserved1
index|[
literal|32
index|]
decl_stmt|;
block|}
name|isp_ridacq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RIDACQ_STS_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_UNACQUIRED
value|1
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_CHANGED
value|2
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_SNS_TIMEOUT
value|3
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_SNS_REJECTED
value|4
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_SCR_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|RIDACQ_STS_SCR_REJECTED
value|6
end_define

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

begin_define
define|#
directive|define
name|SNS_RSPN_ID
value|0x218
end_define

begin_define
define|#
directive|define
name|SNS_RFF_ID
value|0x21F
end_define

begin_define
define|#
directive|define
name|SNS_RSNN_NN
value|0x239
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
index|[]
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
index|[]
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
comment|/*  * A handy package structure for running FC-SCSI commands internally  */
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
name|channel
range|:
literal|8
decl_stmt|,
name|portid
range|:
literal|24
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
name|uint32_t
name|no_wait
range|:
literal|1
decl_stmt|,
name|do_read
range|:
literal|1
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

begin_comment
comment|/*  * Target Mode related definitions  */
end_comment

begin_define
define|#
directive|define
name|QLTM_SENSELEN
value|18
end_define

begin_comment
comment|/* non-FC cards only */
end_comment

begin_define
define|#
directive|define
name|QLTM_SVALID
value|0x80
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
name|uint32_t
name|le_reserved
decl_stmt|;
name|uint8_t
name|le_lun
decl_stmt|;
name|uint8_t
name|le_rsvd
decl_stmt|;
name|uint8_t
name|le_ops
decl_stmt|;
comment|/* Modify LUN only */
name|uint8_t
name|le_tgt
decl_stmt|;
comment|/* Not for FC */
name|uint32_t
name|le_flags
decl_stmt|;
comment|/* Not for FC */
name|uint8_t
name|le_status
decl_stmt|;
name|uint8_t
name|le_reserved2
decl_stmt|;
name|uint8_t
name|le_cmd_count
decl_stmt|;
name|uint8_t
name|le_in_count
decl_stmt|;
name|uint8_t
name|le_cdb6len
decl_stmt|;
comment|/* Not for FC */
name|uint8_t
name|le_cdb7len
decl_stmt|;
comment|/* Not for FC */
name|uint16_t
name|le_timeout
decl_stmt|;
name|uint16_t
name|le_reserved3
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
value|0x00000002
end_define

begin_comment
comment|/* bit1  Tagged Queue Action Enable */
end_comment

begin_define
define|#
directive|define
name|LUN_DSSM
value|0x01000000
end_define

begin_comment
comment|/* bit24 Disable Sending SDP Message */
end_comment

begin_define
define|#
directive|define
name|LUN_DISAD
value|0x02000000
end_define

begin_comment
comment|/* bit25 Disable autodisconnect */
end_comment

begin_define
define|#
directive|define
name|LUN_DM
value|0x40000000
end_define

begin_comment
comment|/* bit30 Disconnects Mandatory */
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
name|LUN_OK
value|0x01
end_define

begin_comment
comment|/* we be rockin' */
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
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|in_reserved2
decl_stmt|;
name|uint8_t
name|in_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|in_flags
decl_stmt|;
name|uint8_t
name|in_status
decl_stmt|;
name|uint8_t
name|in_rsvd2
decl_stmt|;
name|uint8_t
name|in_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|in_tag_type
decl_stmt|;
comment|/* tag type */
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
name|uint8_t
name|in_msg
index|[
name|IN_MSGLEN
index|]
decl_stmt|;
comment|/* SCSI message bytes */
name|uint16_t
name|in_reserved3
index|[
name|IN_RSVDLEN
index|]
decl_stmt|;
name|uint8_t
name|in_sense
index|[
name|QLTM_SENSELEN
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
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint8_t
name|in_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|in_scclun
decl_stmt|;
name|uint32_t
name|in_reserved2
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint16_t
name|in_task_flags
decl_stmt|;
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint16_t
name|in_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|in_scclun
decl_stmt|;
name|uint32_t
name|in_reserved2
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint16_t
name|in_task_flags
decl_stmt|;
name|uint16_t
name|in_seqid
decl_stmt|;
comment|/* sequence id */
block|}
name|in_fcentry_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for the in_status field  */
end_comment

begin_define
define|#
directive|define
name|IN_REJECT
value|0x0D
end_define

begin_comment
comment|/* Message Reject message received */
end_comment

begin_define
define|#
directive|define
name|IN_RESET
value|0x0E
end_define

begin_comment
comment|/* Bus Reset occurred */
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
name|IN_ABORT_TASK
value|0x20
end_define

begin_comment
comment|/* task named in RX_ID is being aborted (FC) */
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
name|IN_PORT_CHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|IN_GLOBAL_LOGO
value|0x2E
end_define

begin_comment
comment|/* all ports logged out */
end_comment

begin_define
define|#
directive|define
name|IN_NO_NEXUS
value|0x3B
end_define

begin_comment
comment|/* Nexus not established */
end_comment

begin_define
define|#
directive|define
name|IN_SRR_RCVD
value|0x45
end_define

begin_comment
comment|/* SRR received */
end_comment

begin_comment
comment|/*  * Values for the in_task_flags field- should only get one at a time!  */
end_comment

begin_define
define|#
directive|define
name|TASK_FLAGS_RESERVED_MASK
value|(0xe700)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_CLEAR_ACA
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_TARGET_RESET
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_LUN_RESET
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_CLEAR_TASK_SET
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|TASK_FLAGS_ABORT_TASK_SET
value|(1<<9)
end_define

begin_comment
comment|/*  * ISP24XX Immediate Notify  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|in_header
decl_stmt|;
name|uint32_t
name|in_reserved
decl_stmt|;
name|uint16_t
name|in_nphdl
decl_stmt|;
name|uint16_t
name|in_reserved1
decl_stmt|;
name|uint16_t
name|in_flags
decl_stmt|;
name|uint16_t
name|in_srr_rxid
decl_stmt|;
name|uint16_t
name|in_status
decl_stmt|;
name|uint8_t
name|in_status_subcode
decl_stmt|;
name|uint8_t
name|in_fwhandle
decl_stmt|;
name|uint32_t
name|in_rxid
decl_stmt|;
name|uint16_t
name|in_srr_reloff_lo
decl_stmt|;
name|uint16_t
name|in_srr_reloff_hi
decl_stmt|;
name|uint16_t
name|in_srr_iu
decl_stmt|;
name|uint16_t
name|in_srr_oxid
decl_stmt|;
comment|/* 	 * If bit 2 is set in in_flags, the N-Port and 	 * handle tags are valid. If the received ELS is 	 * a LOGO, then these tags contain the N Port ID 	 * from the LOGO payload. If the received ELS 	 * request is TPRLO, these tags contain the 	 * Third Party Originator N Port ID. 	 */
name|uint16_t
name|in_nport_id_hi
decl_stmt|;
define|#
directive|define
name|in_prli_options
value|in_nport_id_hi
name|uint8_t
name|in_nport_id_lo
decl_stmt|;
name|uint8_t
name|in_reserved3
decl_stmt|;
name|uint16_t
name|in_np_handle
decl_stmt|;
name|uint8_t
name|in_reserved4
index|[
literal|12
index|]
decl_stmt|;
name|uint8_t
name|in_reserved5
decl_stmt|;
name|uint8_t
name|in_vpidx
decl_stmt|;
name|uint32_t
name|in_reserved6
decl_stmt|;
name|uint16_t
name|in_portid_lo
decl_stmt|;
name|uint8_t
name|in_portid_hi
decl_stmt|;
name|uint8_t
name|in_reserved7
decl_stmt|;
name|uint16_t
name|in_reserved8
decl_stmt|;
name|uint16_t
name|in_oxid
decl_stmt|;
block|}
name|in_fcentry_24xx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IN24XX_FLAG_PUREX_IOCB
value|0x1
end_define

begin_define
define|#
directive|define
name|IN24XX_FLAG_GLOBAL_LOGOUT
value|0x2
end_define

begin_define
define|#
directive|define
name|IN24XX_FLAG_NPHDL_VALID
value|0x4
end_define

begin_define
define|#
directive|define
name|IN24XX_FLAG_N2N_PRLI
value|0x8
end_define

begin_define
define|#
directive|define
name|IN24XX_FLAG_PN_NN_VALID
value|0x10
end_define

begin_define
define|#
directive|define
name|IN24XX_LIP_RESET
value|0x0E
end_define

begin_define
define|#
directive|define
name|IN24XX_LINK_RESET
value|0x0F
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT
value|0x29
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED
value|0x2A
end_define

begin_define
define|#
directive|define
name|IN24XX_LINK_FAILED
value|0x2E
end_define

begin_define
define|#
directive|define
name|IN24XX_SRR_RCVD
value|0x45
end_define

begin_define
define|#
directive|define
name|IN24XX_ELS_RCVD
value|0x46
end_define

begin_comment
comment|/* 					 * login-affectin ELS received- check 					 * subcode for specific opcode 					 */
end_comment

begin_comment
comment|/*  * For f/w> 4.0.25, these offsets in the Immediate Notify contain  * the WWNN/WWPN if the ELS is PLOGI, PDISC or ADISC. The WWN is in  * Big Endian format.  */
end_comment

begin_define
define|#
directive|define
name|IN24XX_PRLI_WWNN_OFF
value|0x18
end_define

begin_define
define|#
directive|define
name|IN24XX_PRLI_WWPN_OFF
value|0x28
end_define

begin_define
define|#
directive|define
name|IN24XX_PLOGI_WWNN_OFF
value|0x20
end_define

begin_define
define|#
directive|define
name|IN24XX_PLOGI_WWPN_OFF
value|0x28
end_define

begin_comment
comment|/*  * For f/w> 4.0.25, this offset in the Immediate Notify contain  * the WWPN if the ELS is LOGO. The WWN is in Big Endian format.  */
end_comment

begin_define
define|#
directive|define
name|IN24XX_LOGO_WWPN_OFF
value|0x28
end_define

begin_comment
comment|/*  * Immediate Notify Status Subcodes for IN24XX_PORT_LOGOUT  */
end_comment

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_PDISC_TMO
value|0x00
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_UXPR_DISC
value|0x01
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_OWN_OPN
value|0x02
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_OWN_OPN_SFT
value|0x03
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_ABTS_TMO
value|0x04
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_DISC_RJT
value|0x05
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_LOGIN_NEEDED
value|0x06
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_BAD_DISC
value|0x07
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_LOST_ALPA
value|0x08
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_LOGOUT_XMIT_FAILURE
value|0x09
end_define

begin_comment
comment|/*  * Immediate Notify Status Subcodes for IN24XX_PORT_CHANGED  */
end_comment

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_BADFAN
value|0x00
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_TOPO_CHANGE
value|0x01
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_FLOGI_ACC
value|0x02
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_FLOGI_RJT
value|0x03
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_TIMEOUT
value|0x04
end_define

begin_define
define|#
directive|define
name|IN24XX_PORT_CHANGED_PORT_CHANGE
value|0x05
end_define

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
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint8_t
name|na_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|na_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|na_reserved2
decl_stmt|;
name|uint8_t
name|na_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|na_flags
decl_stmt|;
name|uint8_t
name|na_status
decl_stmt|;
name|uint8_t
name|na_event
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
name|na_reserved3
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
name|NA_OK
value|0x01
end_define

begin_comment
comment|/* Notify Acknowledge Succeeded */
end_comment

begin_define
define|#
directive|define
name|NA_INVALID
value|0x06
end_define

begin_comment
comment|/* Invalid Notify Acknowledge */
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
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint8_t
name|na_reserved1
decl_stmt|;
name|uint8_t
name|na_iid
decl_stmt|;
comment|/* initiator loop id */
name|uint16_t
name|na_response
decl_stmt|;
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_reserved2
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint16_t
name|na_task_flags
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
name|na_reserved3
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|uint32_t
name|na_reserved
decl_stmt|;
name|uint16_t
name|na_iid
decl_stmt|;
comment|/* initiator loop id */
name|uint16_t
name|na_response
decl_stmt|;
comment|/* response code */
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_reserved2
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint16_t
name|na_task_flags
decl_stmt|;
name|uint16_t
name|na_seqid
decl_stmt|;
comment|/* sequence id */
name|uint16_t
name|na_reserved3
index|[
name|NA2_RSVDLEN
index|]
decl_stmt|;
block|}
name|na_fcentry_e_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NAFC_RCOUNT
value|0x80
end_define

begin_comment
comment|/* increment resource count */
end_comment

begin_define
define|#
directive|define
name|NAFC_RST_CLRD
value|0x20
end_define

begin_comment
comment|/* Clear LIP Reset */
end_comment

begin_define
define|#
directive|define
name|NAFC_TVALID
value|0x10
end_define

begin_comment
comment|/* task mangement response code is valid */
end_comment

begin_comment
comment|/*  * ISP24XX Notify Acknowledge  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|na_header
decl_stmt|;
name|uint32_t
name|na_handle
decl_stmt|;
name|uint16_t
name|na_nphdl
decl_stmt|;
name|uint16_t
name|na_reserved1
decl_stmt|;
name|uint16_t
name|na_flags
decl_stmt|;
name|uint16_t
name|na_srr_rxid
decl_stmt|;
name|uint16_t
name|na_status
decl_stmt|;
name|uint8_t
name|na_status_subcode
decl_stmt|;
name|uint8_t
name|na_fwhandle
decl_stmt|;
name|uint32_t
name|na_rxid
decl_stmt|;
name|uint16_t
name|na_srr_reloff_lo
decl_stmt|;
name|uint16_t
name|na_srr_reloff_hi
decl_stmt|;
name|uint16_t
name|na_srr_iu
decl_stmt|;
name|uint16_t
name|na_srr_flags
decl_stmt|;
name|uint8_t
name|na_reserved3
index|[
literal|18
index|]
decl_stmt|;
name|uint8_t
name|na_reserved4
decl_stmt|;
name|uint8_t
name|na_vpidx
decl_stmt|;
name|uint8_t
name|na_srr_reject_vunique
decl_stmt|;
name|uint8_t
name|na_srr_reject_explanation
decl_stmt|;
name|uint8_t
name|na_srr_reject_code
decl_stmt|;
name|uint8_t
name|na_reserved5
decl_stmt|;
name|uint8_t
name|na_reserved6
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|na_oxid
decl_stmt|;
block|}
name|na_fcentry_24xx_t
typedef|;
end_typedef

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
name|uint16_t
name|at_reserved
decl_stmt|;
name|uint16_t
name|at_handle
decl_stmt|;
name|uint8_t
name|at_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint8_t
name|at_cdblen
decl_stmt|;
comment|/* cdb length */
name|uint8_t
name|at_tgt
decl_stmt|;
comment|/* target */
name|uint32_t
name|at_flags
decl_stmt|;
name|uint8_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_scsi_status
decl_stmt|;
comment|/* scsi status */
name|uint8_t
name|at_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|at_tag_type
decl_stmt|;
comment|/* tag type */
name|uint8_t
name|at_cdb
index|[
name|ATIO_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint8_t
name|at_sense
index|[
name|QLTM_SENSELEN
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
value|0x00000002
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
name|AT_RESET
value|0x0E
end_define

begin_comment
comment|/* SCSI Bus Reset Occurred */
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
comment|/*  * Macros to create and fetch and test concatenated handle and tag value macros  * (SPI only)  */
end_comment

begin_define
define|#
directive|define
name|AT_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|aep
parameter_list|)
define|\
value|tid = aep->at_handle;						\ 	if (aep->at_flags& AT_TQAE) {					\ 		tid |= (aep->at_tag_val<< 16);				\ 		tid |= (1<< 24);					\ 	}
end_define

begin_define
define|#
directive|define
name|CT_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|ct
parameter_list|)
define|\
value|tid = ct->ct_fwhandle;						\ 	if (ct->ct_flags& CT_TQAE) {					\ 		tid |= (ct->ct_tag_val<< 16);				\ 		tid |= (1<< 24);					\ 	}
end_define

begin_define
define|#
directive|define
name|AT_HAS_TAG
parameter_list|(
name|val
parameter_list|)
value|((val)& (1<< 24))
end_define

begin_define
define|#
directive|define
name|AT_GET_TAG
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|AT_GET_HANDLE
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffff)
end_define

begin_define
define|#
directive|define
name|IN_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|inp
parameter_list|)
define|\
value|tid = inp->in_seqid;						\ 	tid |= (inp->in_tag_val<< 16);					\ 	tid |= (1<< 24)
end_define

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
name|uint32_t
name|at_reserved
decl_stmt|;
name|uint8_t
name|at_lun
decl_stmt|;
comment|/* lun or reserved */
name|uint8_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|at_flags
decl_stmt|;
name|uint16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_crn
decl_stmt|;
comment|/* command reference number */
name|uint8_t
name|at_taskcodes
decl_stmt|;
name|uint8_t
name|at_taskflags
decl_stmt|;
name|uint8_t
name|at_execodes
decl_stmt|;
name|uint8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|uint16_t
name|at_scclun
decl_stmt|;
comment|/* SCC Lun or reserved */
name|uint16_t
name|at_wwpn
index|[
literal|4
index|]
decl_stmt|;
comment|/* WWPN of initiator */
name|uint16_t
name|at_reserved2
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|at_oxid
decl_stmt|;
block|}
name|at2_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|at_header
decl_stmt|;
name|uint32_t
name|at_reserved
decl_stmt|;
name|uint16_t
name|at_iid
decl_stmt|;
comment|/* initiator */
name|uint16_t
name|at_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|at_flags
decl_stmt|;
name|uint16_t
name|at_status
decl_stmt|;
comment|/* firmware status */
name|uint8_t
name|at_crn
decl_stmt|;
comment|/* command reference number */
name|uint8_t
name|at_taskcodes
decl_stmt|;
name|uint8_t
name|at_taskflags
decl_stmt|;
name|uint8_t
name|at_execodes
decl_stmt|;
name|uint8_t
name|at_cdb
index|[
name|ATIO2_CDBLEN
index|]
decl_stmt|;
comment|/* received CDB */
name|uint32_t
name|at_datalen
decl_stmt|;
comment|/* allocated data len */
name|uint16_t
name|at_scclun
decl_stmt|;
comment|/* SCC Lun or reserved */
name|uint16_t
name|at_wwpn
index|[
literal|4
index|]
decl_stmt|;
comment|/* WWPN of initiator */
name|uint16_t
name|at_reserved2
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|at_oxid
decl_stmt|;
block|}
name|at2e_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATIO2_WWPN_OFFSET
value|0x2A
end_define

begin_define
define|#
directive|define
name|ATIO2_OXID_OFFSET
value|0x3E
end_define

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
name|ATIO2_EX_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|ATIO2_EX_READ
value|0x2
end_define

begin_comment
comment|/*  * Macros to create and fetch and test concatenated handle and tag value macros  */
end_comment

begin_define
define|#
directive|define
name|AT2_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|aep
parameter_list|)
define|\
value|tid = aep->at_rxid;						\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)bus)<< 48)
end_define

begin_define
define|#
directive|define
name|CT2_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|ct
parameter_list|)
define|\
value|tid = ct->ct_rxid;						\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)(bus& 0xff))<< 48)
end_define

begin_define
define|#
directive|define
name|AT2_HAS_TAG
parameter_list|(
name|val
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|AT2_GET_TAG
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|AT2_GET_INST
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 32)& 0xffff)
end_define

begin_define
define|#
directive|define
name|AT2_GET_HANDLE
value|AT2_GET_TAG
end_define

begin_define
define|#
directive|define
name|AT2_GET_BUS
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 48)& 0xff)
end_define

begin_define
define|#
directive|define
name|FC_HAS_TAG
value|AT2_HAS_TAG
end_define

begin_define
define|#
directive|define
name|FC_GET_TAG
value|AT2_GET_TAG
end_define

begin_define
define|#
directive|define
name|FC_GET_INST
value|AT2_GET_INST
end_define

begin_define
define|#
directive|define
name|FC_GET_HANDLE
value|AT2_GET_HANDLE
end_define

begin_define
define|#
directive|define
name|IN_FC_MAKE_TAGID
parameter_list|(
name|tid
parameter_list|,
name|bus
parameter_list|,
name|inst
parameter_list|,
name|seqid
parameter_list|)
define|\
value|tid = seqid;							\ 	tid |= (((uint64_t)inst)<< 32);				\ 	tid |= (((uint64_t)(bus& 0xff))<< 48)
end_define

begin_define
define|#
directive|define
name|FC_TAG_INSERT_INST
parameter_list|(
name|tid
parameter_list|,
name|inst
parameter_list|)
define|\
value|tid&= ~0x0000ffff00000000ull;					\ 	tid |= (((uint64_t)inst)<< 32)
end_define

begin_comment
comment|/*  * 24XX ATIO Definition  *  * This is *quite* different from other entry types.  * First of all, it has its own queue it comes in on.  *  * Secondly, it doesn't have a normal header.  *  * Thirdly, it's just a passthru of the FCP CMND IU  * which is recorded in big endian mode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|at_type
decl_stmt|;
name|uint8_t
name|at_count
decl_stmt|;
comment|/* 	 * Task attribute in high four bits, 	 * the rest is the FCP CMND IU Length. 	 * NB: the command can extend past the 	 * length for a single queue entry. 	 */
name|uint16_t
name|at_ta_len
decl_stmt|;
name|uint32_t
name|at_rxid
decl_stmt|;
name|fc_hdr_t
name|at_hdr
decl_stmt|;
name|fcp_cmnd_iu_t
name|at_cmnd
decl_stmt|;
block|}
name|at7_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AT7_NORESRC_RXID
value|0xffffffff
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
name|uint16_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_fwhandle
decl_stmt|;
comment|/* required by f/w */
name|uint8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint8_t
name|ct_reserved2
decl_stmt|;
name|uint8_t
name|ct_tgt
decl_stmt|;
comment|/* our target id */
name|uint32_t
name|ct_flags
decl_stmt|;
name|uint8_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint8_t
name|ct_scsi_status
decl_stmt|;
comment|/* scsi status */
name|uint8_t
name|ct_tag_val
decl_stmt|;
comment|/* tag value */
name|uint8_t
name|ct_tag_type
decl_stmt|;
comment|/* tag type */
name|uint32_t
name|ct_xfrlen
decl_stmt|;
comment|/* transfer length */
name|uint32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
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
comment|/*  * For some of the dual port SCSI adapters, port (bus #) is reported  * in the MSbit of ct_iid. Bit fields are a bit too awkward here.  *  * Note that this does not apply to FC adapters at all which can and  * do report IIDs between 0x81&& 0xfe (or 0x7ff) which represent devices  * that have logged in across a SCSI fabric.  */
end_comment

begin_define
define|#
directive|define
name|GET_IID_VAL
parameter_list|(
name|x
parameter_list|)
value|(x& 0x3f)
end_define

begin_define
define|#
directive|define
name|GET_BUS_VAL
parameter_list|(
name|x
parameter_list|)
value|((x>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|SET_IID_VAL
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|y = ((y& ~0x3f) | (x& 0x3f))
end_define

begin_define
define|#
directive|define
name|SET_BUS_VAL
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|y = ((y& 0x3f) | ((x& 0x1)<< 7))
end_define

begin_comment
comment|/*  * ct_flags values  */
end_comment

begin_define
define|#
directive|define
name|CT_TQAE
value|0x00000002
end_define

begin_comment
comment|/* bit  1, Tagged Queue Action enable */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_IN
value|0x00000040
end_define

begin_comment
comment|/* bits 6&7, Data direction - *to* initiator */
end_comment

begin_define
define|#
directive|define
name|CT_DATA_OUT
value|0x00000080
end_define

begin_comment
comment|/* bits 6&7, Data direction - *from* initiator */
end_comment

begin_define
define|#
directive|define
name|CT_NO_DATA
value|0x000000C0
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_CCINCR
value|0x00000100
end_define

begin_comment
comment|/* bit 8, autoincrement atio count */
end_comment

begin_define
define|#
directive|define
name|CT_DATAMASK
value|0x000000C0
end_define

begin_comment
comment|/* bits 6&7, Data direction */
end_comment

begin_define
define|#
directive|define
name|CT_INISYNCWIDE
value|0x00004000
end_define

begin_comment
comment|/* bit 14, Do Sync/Wide Negotiation */
end_comment

begin_define
define|#
directive|define
name|CT_NODISC
value|0x00008000
end_define

begin_comment
comment|/* bit 15, Disconnects disabled */
end_comment

begin_define
define|#
directive|define
name|CT_DSDP
value|0x01000000
end_define

begin_comment
comment|/* bit 24, Disable Save Data Pointers */
end_comment

begin_define
define|#
directive|define
name|CT_SENDRDP
value|0x04000000
end_define

begin_comment
comment|/* bit 26, Send Restore Pointers msg */
end_comment

begin_define
define|#
directive|define
name|CT_SENDSTATUS
value|0x80000000
end_define

begin_comment
comment|/* bit 31, Send SCSI status byte */
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
name|CT_DATA_OVER
value|0x09
end_define

begin_comment
comment|/* (FC only) Data Overrun */
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
name|CT_PARITY
value|0x0F
end_define

begin_comment
comment|/* Uncorrectable Parity Error */
end_comment

begin_define
define|#
directive|define
name|CT_BUS_ERROR
value|0x10
end_define

begin_comment
comment|/* (FC Only) DMA PCI Error */
end_comment

begin_define
define|#
directive|define
name|CT_PANIC
value|0x13
end_define

begin_comment
comment|/* Unrecoverable Error */
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
name|CT_DATA_UNDER
value|0x15
end_define

begin_comment
comment|/* (FC only) Data Underrun */
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
name|CT_PORTUNAVAIL
value|0x28
end_define

begin_comment
comment|/* port not available */
end_comment

begin_define
define|#
directive|define
name|CT_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port logout */
end_comment

begin_define
define|#
directive|define
name|CT_PORTCHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|CT_IDE
value|0x33
end_define

begin_comment
comment|/* Initiator Detected Error */
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

begin_define
define|#
directive|define
name|CT_SRR
value|0x45
end_define

begin_comment
comment|/* SRR Received */
end_comment

begin_define
define|#
directive|define
name|CT_LUN_RESET
value|0x48
end_define

begin_comment
comment|/* Lun Reset Received */
end_comment

begin_define
define|#
directive|define
name|CT_HBA_RESET
value|0xffff
end_define

begin_comment
comment|/* pseudo error - command destroyed by HBA reset*/
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
value|(sizeof(at_entry_t)/sizeof(uint32_t))
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
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint8_t
name|ct_lun
decl_stmt|;
comment|/* lun */
name|uint8_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|ct_flags
decl_stmt|;
name|uint16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|uint32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
comment|/* 		 * The three different modes that the target driver 		 * can set the CTIO{2,3,4} up as. 		 * 		 * The first is for sending FCP_DATA_IUs as well as 		 * (optionally) sending a terminal SCSI status FCP_RSP_IU. 		 * 		 * The second is for sending SCSI sense data in an FCP_RSP_IU. 		 * Note that no FCP_DATA_IUs will be sent. 		 * 		 * The third is for sending FCP_RSP_IUs as built specifically 		 * in system memory as located by the isp_dataseg. 		 */
struct|struct
block|{
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
name|ispds64_t
name|ct_dataseg64
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
name|ispdslist_t
name|ct_dslist
decl_stmt|;
block|}
name|u
union|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint8_t
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
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|_reserved3
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_fcp_rsp_iudata_32
decl_stmt|;
name|ispds64_t
name|ct_fcp_rsp_iudata_64
decl_stmt|;
block|}
name|u
union|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct2_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_iid
decl_stmt|;
comment|/* initiator id */
name|uint16_t
name|ct_rxid
decl_stmt|;
comment|/* response ID */
name|uint16_t
name|ct_flags
decl_stmt|;
name|uint16_t
name|ct_status
decl_stmt|;
comment|/* isp status */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint32_t
name|ct_reloff
decl_stmt|;
comment|/* relative offset */
name|uint32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_dataseg
index|[
name|ISP_RQDSEG_T2
index|]
decl_stmt|;
name|ispds64_t
name|ct_dataseg64
index|[
name|ISP_RQDSEG_T3
index|]
decl_stmt|;
name|ispdslist_t
name|ct_dslist
decl_stmt|;
block|}
name|u
union|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint8_t
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
name|uint32_t
name|_reserved
decl_stmt|;
name|uint16_t
name|_reserved2
decl_stmt|;
name|uint16_t
name|_reserved3
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
union|union
block|{
name|ispds_t
name|ct_fcp_rsp_iudata_32
decl_stmt|;
name|ispds64_t
name|ct_fcp_rsp_iudata_64
decl_stmt|;
block|}
name|u
union|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct2e_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO2  */
end_comment

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
name|CT2_FLAG_MMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|CT2_DATA_IN
value|0x0040
end_define

begin_comment
comment|/* *to* initiator */
end_comment

begin_define
define|#
directive|define
name|CT2_DATA_OUT
value|0x0080
end_define

begin_comment
comment|/* *from* initiator */
end_comment

begin_define
define|#
directive|define
name|CT2_NO_DATA
value|0x00C0
end_define

begin_define
define|#
directive|define
name|CT2_DATAMASK
value|0x00C0
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
name|CT2_CONFIRM
value|0x2000
end_define

begin_define
define|#
directive|define
name|CT2_TERMINATE
value|0x4000
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

begin_comment
comment|/*  * ISP24XX CTIO  */
end_comment

begin_define
define|#
directive|define
name|MAXRESPLEN_24XX
value|24
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|ct_header
decl_stmt|;
name|uint32_t
name|ct_syshandle
decl_stmt|;
name|uint16_t
name|ct_nphdl
decl_stmt|;
comment|/* status on returned CTIOs */
name|uint16_t
name|ct_timeout
decl_stmt|;
name|uint16_t
name|ct_seg_count
decl_stmt|;
name|uint8_t
name|ct_vpidx
decl_stmt|;
name|uint8_t
name|ct_xflags
decl_stmt|;
name|uint16_t
name|ct_iid_lo
decl_stmt|;
comment|/* low 16 bits of portid */
name|uint8_t
name|ct_iid_hi
decl_stmt|;
comment|/* hi 8 bits of portid */
name|uint8_t
name|ct_reserved
decl_stmt|;
name|uint32_t
name|ct_rxid
decl_stmt|;
name|uint16_t
name|ct_senselen
decl_stmt|;
comment|/* mode 1 only */
name|uint16_t
name|ct_flags
decl_stmt|;
name|uint32_t
name|ct_resid
decl_stmt|;
comment|/* residual length */
name|uint16_t
name|ct_oxid
decl_stmt|;
name|uint16_t
name|ct_scsi_status
decl_stmt|;
comment|/* modes 0&& 1 only */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|reloff
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|ct_xfrlen
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|ispds64_t
name|ds
decl_stmt|;
block|}
name|m0
struct|;
struct|struct
block|{
name|uint16_t
name|ct_resplen
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|ct_resp
index|[
name|MAXRESPLEN_24XX
index|]
decl_stmt|;
block|}
name|m1
struct|;
struct|struct
block|{
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|ct_datalen
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|ispds64_t
name|ct_fcp_rsp_iudata
decl_stmt|;
block|}
name|m2
struct|;
block|}
name|rsp
union|;
block|}
name|ct7_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * ct_flags values for CTIO7  */
end_comment

begin_define
define|#
directive|define
name|CT7_NO_DATA
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT7_DATA_OUT
value|0x0001
end_define

begin_comment
comment|/* *from* initiator */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_IN
value|0x0002
end_define

begin_comment
comment|/* *to* initiator */
end_comment

begin_define
define|#
directive|define
name|CT7_DATAMASK
value|0x3
end_define

begin_define
define|#
directive|define
name|CT7_DSD_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|CT7_CONF_STSFD
value|0x0010
end_define

begin_define
define|#
directive|define
name|CT7_EXPLCT_CONF
value|0x0020
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE0
value|0x0000
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE1
value|0x0040
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MODE2
value|0x0080
end_define

begin_define
define|#
directive|define
name|CT7_FLAG_MMASK
value|0x00C0
end_define

begin_define
define|#
directive|define
name|CT7_NOACK
value|0x0100
end_define

begin_define
define|#
directive|define
name|CT7_TASK_ATTR_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|CT7_CONFIRM
value|0x2000
end_define

begin_define
define|#
directive|define
name|CT7_TERMINATE
value|0x4000
end_define

begin_define
define|#
directive|define
name|CT7_SENDSTATUS
value|0x8000
end_define

begin_comment
comment|/*  * Type 7 CTIO status codes  */
end_comment

begin_define
define|#
directive|define
name|CT7_OK
value|0x01
end_define

begin_comment
comment|/* completed without error */
end_comment

begin_define
define|#
directive|define
name|CT7_ABORTED
value|0x02
end_define

begin_comment
comment|/* aborted by host */
end_comment

begin_define
define|#
directive|define
name|CT7_ERR
value|0x04
end_define

begin_comment
comment|/* see sense data for error */
end_comment

begin_define
define|#
directive|define
name|CT7_INVAL
value|0x06
end_define

begin_comment
comment|/* request for disabled lun */
end_comment

begin_define
define|#
directive|define
name|CT7_INVRXID
value|0x08
end_define

begin_comment
comment|/* Invalid RX_ID */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_OVER
value|0x09
end_define

begin_comment
comment|/* Data Overrun */
end_comment

begin_define
define|#
directive|define
name|CT7_TIMEOUT
value|0x0B
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|CT7_RESET
value|0x0E
end_define

begin_comment
comment|/* LIP Rset Received */
end_comment

begin_define
define|#
directive|define
name|CT7_BUS_ERROR
value|0x10
end_define

begin_comment
comment|/* DMA PCI Error */
end_comment

begin_define
define|#
directive|define
name|CT7_REASSY_ERR
value|0x11
end_define

begin_comment
comment|/* DMA reassembly error */
end_comment

begin_define
define|#
directive|define
name|CT7_DATA_UNDER
value|0x15
end_define

begin_comment
comment|/* Data Underrun */
end_comment

begin_define
define|#
directive|define
name|CT7_PORTUNAVAIL
value|0x28
end_define

begin_comment
comment|/* port not available */
end_comment

begin_define
define|#
directive|define
name|CT7_LOGOUT
value|0x29
end_define

begin_comment
comment|/* port logout */
end_comment

begin_define
define|#
directive|define
name|CT7_PORTCHANGED
value|0x2A
end_define

begin_comment
comment|/* port changed */
end_comment

begin_define
define|#
directive|define
name|CT7_SRR
value|0x45
end_define

begin_comment
comment|/* SRR Received */
end_comment

begin_comment
comment|/*  * Other 24XX related target IOCBs  */
end_comment

begin_comment
comment|/*  * ABTS Received  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|abts_header
decl_stmt|;
name|uint8_t
name|abts_reserved0
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|abts_nphdl
decl_stmt|;
name|uint16_t
name|abts_reserved1
decl_stmt|;
name|uint16_t
name|abts_sof
decl_stmt|;
name|uint32_t
name|abts_rxid_abts
decl_stmt|;
name|uint16_t
name|abts_did_lo
decl_stmt|;
name|uint8_t
name|abts_did_hi
decl_stmt|;
name|uint8_t
name|abts_r_ctl
decl_stmt|;
name|uint16_t
name|abts_sid_lo
decl_stmt|;
name|uint8_t
name|abts_sid_hi
decl_stmt|;
name|uint8_t
name|abts_cs_ctl
decl_stmt|;
name|uint16_t
name|abts_fs_ctl
decl_stmt|;
name|uint8_t
name|abts_f_ctl
decl_stmt|;
name|uint8_t
name|abts_type
decl_stmt|;
name|uint16_t
name|abts_seq_cnt
decl_stmt|;
name|uint8_t
name|abts_df_ctl
decl_stmt|;
name|uint8_t
name|abts_seq_id
decl_stmt|;
name|uint16_t
name|abts_rx_id
decl_stmt|;
name|uint16_t
name|abts_ox_id
decl_stmt|;
name|uint32_t
name|abts_param
decl_stmt|;
name|uint8_t
name|abts_reserved2
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|abts_rxid_task
decl_stmt|;
block|}
name|abts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|isphdr_t
name|abts_rsp_header
decl_stmt|;
name|uint32_t
name|abts_rsp_handle
decl_stmt|;
name|uint16_t
name|abts_rsp_status
decl_stmt|;
name|uint16_t
name|abts_rsp_nphdl
decl_stmt|;
name|uint16_t
name|abts_rsp_ctl_flags
decl_stmt|;
name|uint16_t
name|abts_rsp_sof
decl_stmt|;
name|uint32_t
name|abts_rsp_rxid_abts
decl_stmt|;
name|uint16_t
name|abts_rsp_did_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_did_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_r_ctl
decl_stmt|;
name|uint16_t
name|abts_rsp_sid_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_sid_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_cs_ctl
decl_stmt|;
name|uint16_t
name|abts_rsp_f_ctl_lo
decl_stmt|;
name|uint8_t
name|abts_rsp_f_ctl_hi
decl_stmt|;
name|uint8_t
name|abts_rsp_type
decl_stmt|;
name|uint16_t
name|abts_rsp_seq_cnt
decl_stmt|;
name|uint8_t
name|abts_rsp_df_ctl
decl_stmt|;
name|uint8_t
name|abts_rsp_seq_id
decl_stmt|;
name|uint16_t
name|abts_rsp_rx_id
decl_stmt|;
name|uint16_t
name|abts_rsp_ox_id
decl_stmt|;
name|uint32_t
name|abts_rsp_param
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|last_seq_id
decl_stmt|;
name|uint8_t
name|seq_id_valid
decl_stmt|;
name|uint16_t
name|aborted_rx_id
decl_stmt|;
name|uint16_t
name|aborted_ox_id
decl_stmt|;
name|uint16_t
name|high_seq_cnt
decl_stmt|;
name|uint16_t
name|low_seq_cnt
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ba_acc
struct|;
struct|struct
block|{
name|uint8_t
name|vendor_unique
decl_stmt|;
name|uint8_t
name|explanation
decl_stmt|;
name|uint8_t
name|reason
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|ba_rjt
struct|;
struct|struct
block|{
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|subcode1
decl_stmt|;
name|uint32_t
name|subcode2
decl_stmt|;
block|}
name|rsp
struct|;
name|uint8_t
name|reserved
index|[
literal|16
index|]
decl_stmt|;
block|}
name|abts_rsp_payload
union|;
name|uint32_t
name|abts_rsp_rxid_task
decl_stmt|;
block|}
name|abts_rsp_t
typedef|;
end_typedef

begin_comment
comment|/* terminate this ABTS exchange */
end_comment

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_TERMINATE
value|0x01
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_RESET
value|0x04
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_ABORTED
value|0x05
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_TIMEOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_INVXID
value|0x08
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_LOGOUT
value|0x29
end_define

begin_define
define|#
directive|define
name|ISP24XX_ABTS_RSP_SUBCODE
value|0x31
end_define

begin_define
define|#
directive|define
name|ISP24XX_NO_TASK
value|0xffffffff
end_define

begin_comment
comment|/*  * Miscellaneous  *  * These are the limits of the number of dma segments we  * can deal with based not on the size of the segment counter  * (which is 16 bits), but on the size of the number of   * queue entries field (which is 8 bits). We assume no  * segments in the first queue entry, so we can either  * have 7 dma segments per continuation entry or 5  * (for 64 bit dma).. multiplying out by 254....  */
end_comment

begin_define
define|#
directive|define
name|ISP_NSEG_MAX
value|1778
end_define

begin_define
define|#
directive|define
name|ISP_NSEG64_MAX
value|1270
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISPMBOX_H */
end_comment

end_unit

