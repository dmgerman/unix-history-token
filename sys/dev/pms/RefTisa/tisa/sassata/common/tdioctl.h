begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************** * *   tdioctl.h * *   Abstract:   This module contains data structure definition used *               by the Transport Dependent (TD) Layer IOCTL. * * *   Notes: * * ** MODIFICATION HISTORY ****************************************************** * * NAME        DATE        DESCRIPTION * ----        ----        ----------- * IWN         12/11/02     Initial creation. * * *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TD_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|TD_IOCTL_H
end_define

begin_comment
comment|//#include "global.h"
end_comment

begin_comment
comment|/*  * PMC-Sierra IOCTL signature  */
end_comment

begin_define
define|#
directive|define
name|PMC_SIERRA_SIGNATURE
value|0x1234
end_define

begin_define
define|#
directive|define
name|PMC_SIERRA_IOCTL_SIGNATURE
value|"PMC-STRG"
end_define

begin_comment
comment|/*  * Major function code of IOCTL functions, common to target and initiator.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MJ_CARD_PARAMETER
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FW_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_NVMD_GET
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_NVMD_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_EVENT_LOG1
value|0x05
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_EVENT_LOG2
value|0x06
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_CORE_DUMP
value|0x07
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_LL_TRACING
value|0x08
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FW_PROFILE
value|0x09
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_MNID
value|0x0A
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_ENCRYPTION_CTL
value|0x0B
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FW_INFO
value|0x0C
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_LL_API_TEST
value|0x11
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_CHECK_DPMC_EVENT
value|0x16
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_FW_REV
value|0x1A
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_DEVICE_INFO
value|0x1B
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_IO_ERROR_STATISTIC
value|0x1C
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_IO_EVENT_STATISTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_FORENSIC_DATA
value|0x1E
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_DEVICE_LIST
value|0x1F
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SMP_REQUEST
value|0x6D
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_DEVICE_LUN
value|0x7A1
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_PHY_GENERAL_STATUS
value|0x7A6
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_PHY_DETAILS
value|0x7A7
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SEND_BIST
value|0x20
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_CHECK_FATAL_ERROR
value|0x70
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERROR_DUMP_COMPLETE
value|0x71
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GPIO
value|0x41
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SGPIO
value|0x42
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SEND_TMF
value|0x6E
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERROR_SOFT_RESET_TRIG
value|0x72
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERR_CHK_RET_FALSE
value|0x76
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERR_CHK_SEND_FALSE
value|0x76
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_FATAL_ERR_CHK_SEND_TRUE
value|0x77
end_define

begin_comment
comment|/*  * Major function code of IOCTL functions, specific to initiator.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_ISCSI_DISCOVERY
value|0x21
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_SESSION_CONTROL
value|0x22
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_SNIA_IMA
value|0x23
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_SCSI
value|0x24
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_WMI
value|0x25
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_DRIVER_EVENT_LOG
value|0x26
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_PERSISTENT_BINDING
value|0x27
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_INI_DRIVER_IDENTIFY
value|0x28
end_define

begin_comment
comment|/* temp */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MJ_PORT_STOP
value|0x29
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_PORT_START
value|0x30
end_define

begin_comment
comment|/* SPCv controller configuration page commands */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MJ_MODE_CTL_PAGE
value|0x40
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SET_OR_GET_REGISTER
value|0x41
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_PHY_PROFILE
value|0x44
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_SET_PHY_PROFILE
value|0x43
end_define

begin_define
define|#
directive|define
name|IOCTL_MJ_GET_DRIVER_VERSION
value|0x101
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_PHY_PROFILE_COUNTERS
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_PHY_PROFILE_COUNTERS_CLR
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_PHY_PROFILE_BW_COUNTERS
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_PHY_PROFILE_ANALOG_SETTINGS
value|0x04
end_define

begin_comment
comment|/*   * Minor functions for Card parameter IOCTL functions.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_VPD_INFO
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_PORTSTART_INFO
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_INTERRUPT_CONFIG
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_PHY_ANALOGSETTING
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_TIMER_CONFIG
value|0x05
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_CARD_GET_TYPE_FATAL_DUMP
value|0x06
end_define

begin_comment
comment|/*  * Minor functions for FW control IOCTL functions.  */
end_comment

begin_comment
comment|/* Send FW data requests.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_DOWNLOAD_DATA
value|0x01
end_define

begin_comment
comment|/* Send the request for burning the new firmware.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_DOWNLOAD_BURN
value|0x02
end_define

begin_comment
comment|/* Poll for the flash burn phases. Sequences of poll function calls are  * needed following the IOCTL_MN_FW_DOWNLOAD_BURN, IOCTL_MN_FW_BURN_OSPD  * and IOCTL_MN_FW_ROLL_BACK_FW functions.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_BURN_POLL
value|0x03
end_define

begin_comment
comment|/* Instruct the FW to roll back FW to prior revision.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_ROLL_BACK_FW
value|0x04
end_define

begin_comment
comment|/* Instruct the FW to return the current firmware revision number.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_VERSION
value|0x05
end_define

begin_comment
comment|/* Retrieve the maximum size of the OS Persistent Data stored on the card.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_OSPD_SIZE
value|0x06
end_define

begin_comment
comment|/*  Retrieve the OS Persistent Data from the card.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_OSPD
value|0x07
end_define

begin_comment
comment|/* Send a new OS Persistent Data to the card and burn in flash.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_BURN_OSPD
value|0x08
end_define

begin_comment
comment|/* Retrieve the trace buffer from the card FW. Only available on the debug  * version of the FW.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_TRACE_BUFFER
value|0x0f
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_NVMD_GET_CONFIG
value|0x0A
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_NVMD_SET_CONFIG
value|0x0B
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_CORE_DUMP_AAP1
value|0x0C
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_CORE_DUMP_IOP
value|0x0D
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_CORE_DUMP_FLASH_AAP1
value|0x12
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_CORE_DUMP_FLASH_IOP
value|0x13
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_LL_RESET_TRACE_INDEX
value|0x0e
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_LL_GET_TRACE_BUFFER_INFO
value|0x0f
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_LL_GET_TRACE_BUFFER
value|0x10
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_GET_INFO
value|0x13
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_SET_MODE
value|0x14
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_KEK_ADD
value|0x15
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_DEK_ADD
value|0x16
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_DEK_INVALID
value|0x17
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_KEK_NVRAM
value|0x18
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_DEK_ASSIGN
value|0x19
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_LUN_QUERY
value|0x1A
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_KEK_LOAD_NVRAM
value|0x1B
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_ERROR_QUERY
value|0x1C
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPTION_DEK_TABLE_INIT
value|0x1D
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_LUN_VERIFY
value|0x1E
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_OPERATOR_MGMT
value|0x1F
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_SET_DEK_CONFIG_PAGE
value|0x21
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_SET_CONTROL_PAGE
value|0x22
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_SET_OPERATOR_CMD
value|0x23
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_TEST_EXECUTE
value|0x24
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_SET_HMAC_CONFIG_PAGE
value|0x25
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_GET_OPERATOR_CMD
value|0x26
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_ENCRYPT_RESCAN
value|0x27
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOFT_RESET_TEST
end_ifdef

begin_define
define|#
directive|define
name|IOCTL_MN_SOFT_RESET
value|0x28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPCv configuration pages */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MN_MODE_SENSE
value|0x30
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_MODE_SELECT
value|0x31
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_TISA_TEST_ENCRYPT_DEK_DUMP
value|0x51
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_EVENT_FLASH_LOG1
value|0x5A
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_FW_GET_EVENT_FLASH_LOG2
value|0x6A
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GET_EVENT_LOG1
value|0x5B
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GET_EVENT_LOG2
value|0x6B
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GPIO_PINSETUP
value|0x01
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GPIO_EVENTSETUP
value|0x02
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GPIO_READ
value|0x03
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_GPIO_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_TMF_DEVICE_RESET
value|0x6F
end_define

begin_define
define|#
directive|define
name|IOCTL_MN_TMF_LUN_RESET
value|0x70
end_define

begin_typedef
typedef|typedef
struct|struct
name|tdFWControl
block|{
name|bit32
name|retcode
decl_stmt|;
comment|/* ret code (status) = (bit32)oscmCtrlEvnt_e      */
name|bit32
name|phase
decl_stmt|;
comment|/* ret code phase    = (bit32)agcmCtrlFwPhase_e   */
name|bit32
name|phaseCmplt
decl_stmt|;
comment|/* percent complete for the current update phase  */
name|bit32
name|version
decl_stmt|;
comment|/* Hex encoded firmware version number            */
name|bit32
name|offset
decl_stmt|;
comment|/* Used for downloading firmware                  */
name|bit32
name|len
decl_stmt|;
comment|/* len of buffer                                  */
name|bit32
name|size
decl_stmt|;
comment|/* Used in OS VPD and Trace get size operations.  */
name|bit32
name|reserved
decl_stmt|;
comment|/* padding required for 64 bit alignment          */
name|bit8
name|buffer
index|[
literal|1
index|]
decl_stmt|;
comment|/* Start of buffer                                */
block|}
name|tdFWControl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdFWControlEx
block|{
name|tdFWControl_t
modifier|*
name|tdFWControl
decl_stmt|;
name|bit8
modifier|*
name|buffer
decl_stmt|;
comment|// keep buffer pointer to be freed when the responce comes
name|bit8
modifier|*
name|virtAddr
decl_stmt|;
comment|/* keep virtual address of the data */
name|bit8
modifier|*
name|usrAddr
decl_stmt|;
comment|/* keep virtual address of the user data */
name|bit32
name|len
decl_stmt|;
comment|/* len of buffer                                  */
name|void
modifier|*
name|payload
decl_stmt|;
comment|/* pointer to IOCTL Payload */
name|bit8
name|inProgress
decl_stmt|;
comment|/* if 1 - the IOCTL request is in progress */
name|void
modifier|*
name|param1
decl_stmt|;
name|void
modifier|*
name|param2
decl_stmt|;
name|void
modifier|*
name|param3
decl_stmt|;
block|}
name|tdFWControlEx_t
typedef|;
end_typedef

begin_comment
comment|/************************************************************/
end_comment

begin_comment
comment|//This flag and datastructure are specific for fw profiling, Now defined as
end_comment

begin_comment
comment|// compiler flag
end_comment

begin_comment
comment|//#define SPC_ENABLE_PROFILE
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPC_ENABLE_PROFILE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|tdFWProfile
block|{
name|bit32
name|status
decl_stmt|;
name|bit32
name|tcid
decl_stmt|;
name|bit32
name|processor
decl_stmt|;
comment|/* processor name "iop/aap1"      */
name|bit32
name|cmd
decl_stmt|;
comment|/* cmd to fw   */
name|bit32
name|len
decl_stmt|;
comment|/* len of buffer                                  */
name|bit32
name|codeStartAdd
decl_stmt|;
name|bit32
name|codeEndAdd
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
comment|/* padding required for 64 bit alignment          */
name|bit8
name|buffer
index|[
literal|1
index|]
decl_stmt|;
comment|/* Start of buffer                                */
block|}
name|tdFWProfile_t
typedef|;
end_typedef

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/**Definations for FW profile*/
end_comment

begin_define
define|#
directive|define
name|FW_PROFILE_PROCESSOR_ID_IOP
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_PROFILE_PROCESSOR_ID_AAP1
value|0x02
end_define

begin_comment
comment|/* definitions for sub operation */
end_comment

begin_define
define|#
directive|define
name|START_TIMER_PROFILE
value|0x01
end_define

begin_define
define|#
directive|define
name|START_CODE_PROFILE
value|0x02
end_define

begin_define
define|#
directive|define
name|STOP_TIMER_PROFILE
value|0x81
end_define

begin_define
define|#
directive|define
name|STOP_CODE_PROFILE
value|0x82
end_define

begin_comment
comment|/************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdFWProfileEx
block|{
name|tdFWProfile_t
modifier|*
name|tdFWProfile
decl_stmt|;
name|bit8
modifier|*
name|buffer
decl_stmt|;
comment|// keep buffer pointer to be freed when the responce comes
name|bit8
modifier|*
name|virtAddr
decl_stmt|;
comment|/* keep virtual address of the data */
name|bit8
modifier|*
name|usrAddr
decl_stmt|;
comment|/* keep virtual address of the user data */
name|bit32
name|len
decl_stmt|;
comment|/* len of buffer                                  */
name|void
modifier|*
name|payload
decl_stmt|;
comment|/* pointer to IOCTL Payload */
name|bit8
name|inProgress
decl_stmt|;
comment|/* if 1 - the IOCTL request is in progress */
name|void
modifier|*
name|param1
decl_stmt|;
name|void
modifier|*
name|param2
decl_stmt|;
name|void
modifier|*
name|param3
decl_stmt|;
block|}
name|tdFWProfileEx_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdVPDControl
block|{
name|bit32
name|retcode
decl_stmt|;
comment|/* ret code (status)                              */
name|bit32
name|phase
decl_stmt|;
comment|/* ret code phase                                 */
name|bit32
name|phaseCmplt
decl_stmt|;
comment|/* percent complete for the current update phase  */
name|bit32
name|version
decl_stmt|;
comment|/* Hex encoded firmware version number            */
name|bit32
name|offset
decl_stmt|;
comment|/* Used for downloading firmware                  */
name|bit32
name|len
decl_stmt|;
comment|/* len of buffer                                  */
name|bit32
name|size
decl_stmt|;
comment|/* Used in OS VPD and Trace get size operations.  */
name|bit8
name|deviceID
decl_stmt|;
comment|/* padding required for 64 bit alignment          */
name|bit8
name|reserved1
decl_stmt|;
name|bit16
name|reserved2
decl_stmt|;
name|bit32
name|signature
decl_stmt|;
name|bit8
name|buffer
index|[
literal|1
index|]
decl_stmt|;
comment|/* Start of buffer                                */
block|}
name|tdVPDControl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdDeviceInfoIOCTL_s
block|{
name|bit8
name|deviceType
decl_stmt|;
comment|// TD_SATA_DEVICE or TD_SAS_DEVICE
name|bit8
name|linkRate
decl_stmt|;
comment|// 0x08: 1.5 Gbit/s; 0x09: 3.0; 0x0A: 6.0 Gbit/s.
name|bit8
name|phyId
decl_stmt|;
name|bit8
name|reserved
decl_stmt|;
name|bit32
name|sasAddressHi
decl_stmt|;
comment|// SAS address high
name|bit32
name|sasAddressLo
decl_stmt|;
comment|// SAS address low
name|bit32
name|up_sasAddressHi
decl_stmt|;
comment|// upstream SAS address high
name|bit32
name|up_sasAddressLo
decl_stmt|;
comment|// upstream SAS address low
name|bit32
name|ishost
decl_stmt|;
name|bit32
name|isEncryption
decl_stmt|;
comment|// is encryption enabled
name|bit32
name|isDIF
decl_stmt|;
comment|// is DIF enabled
name|unsigned
name|long
name|DeviceHandle
decl_stmt|;
name|bit32
name|host_num
decl_stmt|;
name|bit32
name|channel
decl_stmt|;
name|bit32
name|id
decl_stmt|;
name|bit32
name|lun
decl_stmt|;
block|}
name|tdDeviceInfoIOCTL_t
typedef|;
end_typedef

begin_comment
comment|/* Payload of IOCTL dump device list at OS layer */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdDeviceInfoPayload_s
block|{
name|bit32
name|PathId
decl_stmt|;
name|bit32
name|TargetId
decl_stmt|;
name|bit32
name|Lun
decl_stmt|;
name|bit32
name|Reserved
decl_stmt|;
comment|/* Had better aligned to 64-bit. */
comment|/* output */
name|tdDeviceInfoIOCTL_t
name|devInfo
decl_stmt|;
block|}
name|tdDeviceInfoPayload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdDeviceListPayload_s
block|{
name|bit32
name|realDeviceCount
decl_stmt|;
comment|// the real device out in the array, returned by driver
name|bit32
name|deviceLength
decl_stmt|;
comment|// the length of tdDeviceInfoIOCTL_t array
name|bit8
name|pDeviceInfo
index|[
literal|1
index|]
decl_stmt|;
comment|// point to tdDeviceInfoIOCTL_t array
block|}
name|tdDeviceListPayload_t
typedef|;
end_typedef

begin_comment
comment|// Payload of IO error and event statistic IOCTL.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdIoErrorEventStatisticIOCTL_s
block|{
name|bit32
name|agOSSA_IO_COMPLETED_ERROR_SCSI_STATUS
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OVERFLOW
decl_stmt|;
name|bit32
name|agOSSA_IO_UNDERFLOW
decl_stmt|;
name|bit32
name|agOSSA_IO_FAILED
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_RESET
decl_stmt|;
name|bit32
name|agOSSA_IO_NOT_VALID
decl_stmt|;
name|bit32
name|agOSSA_IO_NO_DEVICE
decl_stmt|;
name|bit32
name|agOSSA_IO_ILLEGAL_PARAMETER
decl_stmt|;
name|bit32
name|agOSSA_IO_LINK_FAILURE
decl_stmt|;
name|bit32
name|agOSSA_IO_PROG_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DIF_IN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DIF_OUT_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_ERROR_HW_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_BREAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_PHY_NOT_READY
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_PROTOCOL_NOT_SUPPORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_ZONE_VIOLATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_BREAK
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_BAD_DESTINATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_CONNECTION_RATE_NOT_SUPPORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_STP_RESOURCES_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_WRONG_DESTINATION
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_UNKNOWN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_NAK_RECEIVED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ACK_NAK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_PEER_ABORTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_RX_FRAME
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_DMA
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CREDIT_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_SATA_LINK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_SATA
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ABORTED_DUE_TO_SRST
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_REJECTED_NCQ_MODE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_ABORTED_NCQ_MODE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_OPEN_RETRY_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_SMP_RESP_CONNECTION_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_UNEXPECTED_PHASE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_RDY_OVERRUN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_RDY_NOT_EXPECTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_ACK_NAK_TIMEOUT
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_BREAK_BEFORE_ACK_NAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_CMD_ISSUE_PHY_DOWN_BEFORE_ACK_NAK
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_OFFSET_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_XFER_ZERO_DATA_LEN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_CMD_FRAME_ISSUED
decl_stmt|;
name|bit32
name|agOSSA_IO_ERROR_INTERNAL_SMP_RESOURCE
decl_stmt|;
name|bit32
name|agOSSA_IO_PORT_IN_RESET
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_NON_OPERATIONAL
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_IN_RECOVERY
decl_stmt|;
name|bit32
name|agOSSA_IO_TM_TAG_NOT_FOUND
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_PIO_SETUP_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_SSP_EXT_IU_ZERO_LEN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_IN_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_IN_PROGRESS
decl_stmt|;
name|bit32
name|agOSSA_IO_ABORT_DELAYED
decl_stmt|;
name|bit32
name|agOSSA_IO_INVALID_LENGTH
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_HW_RESOURCE_BUSY_ALT
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_RETRY_BACKOFF_THRESHOLD_REACHED
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_TMO
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_NO_DEST
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_OPEN_COLLIDE
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_IT_NEXUS_LOSS_PATHWAY_BLOCKED
decl_stmt|;
name|bit32
name|agOSSA_IO_DS_INVALID
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_READ_COMPL_ERR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERR_LAST_PIO_DATAIN_CRC_ERR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INTERNAL_CRC_ERROR
decl_stmt|;
name|bit32
name|agOSSA_MPI_IO_RQE_BUSY_FULL
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_IO_RESOURCE_UNAVAILABLE
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_ATAPI_DEVICE_BUSY
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_KEY_CACHE_MISS
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_KEY_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_CIPHER_MODE_INVALID
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_IV_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_RAM_INTERFACE_ERROR
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INTERNAL_RAM
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_APPLICATION_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_REFERENCE_TAG_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DIF_CRC_MISMATCH
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_INVALID_SSP_RSP_FRAME
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERR_EOB_DATA_OVERRUN
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_INDEX_OUT_OF_BOUNDS
decl_stmt|;
name|bit32
name|agOSSA_IO_OPEN_CNX_ERROR_OPEN_PREEMPTED
decl_stmt|;
name|bit32
name|agOSSA_IO_XFR_ERROR_DEK_ILLEGAL_TABLE
decl_stmt|;
name|bit32
name|agOSSA_IO_XFER_ERROR_DIF_INTERNAL_ERROR
decl_stmt|;
name|bit32
name|agOSSA_MPI_ERR_OFFLOAD_DIF_OR_ENC_NOT_ENABLED
decl_stmt|;
name|bit32
name|agOSSA_IO_UNKNOWN_ERROR
decl_stmt|;
block|}
name|tdIoErrorEventStatisticIOCTL_t
typedef|;
end_typedef

begin_comment
comment|/* 01: soft error 02: not ready 03: medium error 04: hardware error 05: illegal request 06: unit attention 0b: abort command */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdSenseKeyCount_s
block|{
name|bit32
name|SoftError
decl_stmt|;
name|bit32
name|MediumNotReady
decl_stmt|;
name|bit32
name|MediumError
decl_stmt|;
name|bit32
name|HardwareError
decl_stmt|;
name|bit32
name|IllegalRequest
decl_stmt|;
name|bit32
name|UnitAttention
decl_stmt|;
name|bit32
name|AbortCommand
decl_stmt|;
name|bit32
name|OtherKeyType
decl_stmt|;
block|}
name|tdSenseKeyCount_t
typedef|;
end_typedef

begin_comment
comment|/* Code Status Command  completed Service response 00h GOOD Yes COMMAND COMPLETE 02h CHECK CONDITION Yes COMMAND COMPLETE 04h CONDITION MET Yes COMMAND COMPLETE 08h BUSY Yes COMMAND COMPLETE 10h Obsolete 14h Obsolete 18h RESERVATION CONFLICT Yes COMMAND COMPLETE 22h Obsolete 28h TASK SET FULL Yes COMMAND COMPLETE 30h ACA ACTIVE Yes COMMAND COMPLETE 40h TASK ABORTED Yes COMMAND COMPLETE */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdSCSIStatusCount_s
block|{
name|bit32
name|GoodStatus
decl_stmt|;
name|bit32
name|CheckCondition
decl_stmt|;
name|bit32
name|ConditionMet
decl_stmt|;
name|bit32
name|BusyStatus
decl_stmt|;
name|bit32
name|ResvConflict
decl_stmt|;
name|bit32
name|TaskSetFull
decl_stmt|;
name|bit32
name|AcaActive
decl_stmt|;
name|bit32
name|TaskAborted
decl_stmt|;
name|bit32
name|ObsoleteStatus
decl_stmt|;
block|}
name|tdSCSIStatusCount_t
typedef|;
end_typedef

begin_comment
comment|/* Payload of Io Error Statistic IOCTL. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdIoErrorStatisticPayload_s
block|{
name|bit32
name|flag
decl_stmt|;
name|bit32
name|Reserved
decl_stmt|;
comment|/* Had better aligned to 64-bit. */
comment|/* output */
name|tdIoErrorEventStatisticIOCTL_t
name|IoError
decl_stmt|;
name|tdSCSIStatusCount_t
name|ScsiStatusCounter
decl_stmt|;
name|tdSenseKeyCount_t
name|SenseKeyCounter
decl_stmt|;
block|}
name|tdIoErrorStatisticPayload_t
typedef|;
end_typedef

begin_comment
comment|/* Payload of Io Error Statistic IOCTL. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdIoEventStatisticPayload_s
block|{
name|bit32
name|flag
decl_stmt|;
name|bit32
name|Reserved
decl_stmt|;
comment|/* Had better aligned to 64-bit. */
comment|/* output */
name|tdIoErrorEventStatisticIOCTL_t
name|IoEvent
decl_stmt|;
block|}
name|tdIoEventStatisticPayload_t
typedef|;
end_typedef

begin_comment
comment|/* Payload of Register IOCTL. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdRegisterPayload_s
block|{
name|bit32
name|flag
decl_stmt|;
name|bit32
name|busNum
decl_stmt|;
name|bit32
name|RegAddr
decl_stmt|;
comment|/* Register address */
name|bit32
name|RegValue
decl_stmt|;
comment|/* Register value */
block|}
name|tdRegisterPayload_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_GSM_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_QUEUE
value|2
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_FATAL
value|3
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_NON_FATAL
value|4
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_IB_QUEUE
value|5
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_OB_QUEUE
value|6
end_define

begin_define
define|#
directive|define
name|FORENSIC_DATA_TYPE_CHECK_FATAL
value|0x70
end_define

begin_define
define|#
directive|define
name|FORENSIC_Q_TYPE_INBOUND
value|1
end_define

begin_define
define|#
directive|define
name|FORENSIC_Q_TYPE_OUTBOUND
value|2
end_define

begin_comment
comment|/* get forensic data IOCTL payload */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdForensicDataPayload_s
block|{
name|bit32
name|DataType
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|bit32
name|directLen
decl_stmt|;
name|bit32
name|directOffset
decl_stmt|;
name|bit32
name|readLen
decl_stmt|;
name|bit8
name|directData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|gsmBuffer
struct|;
struct|struct
block|{
name|bit16
name|queueType
decl_stmt|;
name|bit16
name|queueIndex
decl_stmt|;
name|bit32
name|directLen
decl_stmt|;
name|bit8
name|directData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|queueBuffer
struct|;
struct|struct
block|{
name|bit32
name|directLen
decl_stmt|;
name|bit32
name|directOffset
decl_stmt|;
name|bit32
name|readLen
decl_stmt|;
name|bit8
name|directData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|dataBuffer
struct|;
block|}
union|;
block|}
name|tdForensicDataPayload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdBistPayload_s
block|{
name|bit32
name|testType
decl_stmt|;
name|bit32
name|testLength
decl_stmt|;
name|bit32
name|testData
index|[
literal|29
index|]
decl_stmt|;
block|}
name|tdBistPayload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TSTMTID_CARD_LOCATION_INFO
block|{
name|bit32
name|CardNo
decl_stmt|;
name|bit32
name|Bus
decl_stmt|;
name|bit32
name|Slot
decl_stmt|;
name|bit32
name|Device
decl_stmt|;
name|bit32
name|Function
decl_stmt|;
name|bit32
name|IOLower
decl_stmt|;
name|bit32
name|IO_Upper
decl_stmt|;
name|bit32
name|VidDid
decl_stmt|;
name|bit32
name|PhyMem
decl_stmt|;
name|bit32
name|Flag
decl_stmt|;
block|}
name|TSTMTID_CARD_LOCATION_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TSTMTID_TRACE_BUFFER_INFO
block|{
name|bit32
name|CardNo
decl_stmt|;
name|bit32
name|TraceCompiled
decl_stmt|;
name|bit32
name|BufferSize
decl_stmt|;
name|bit32
name|CurrentIndex
decl_stmt|;
name|bit32
name|TraceWrap
decl_stmt|;
name|bit32
name|CurrentTraceIndexWrapCount
decl_stmt|;
name|bit32
name|TraceMask
decl_stmt|;
name|bit32
name|Flag
decl_stmt|;
block|}
name|TSTMTID_TRACE_BUFFER_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FetchBufferSIZE
value|32
end_define

begin_define
define|#
directive|define
name|LowFence32Bits
value|0xFCFD1234
end_define

begin_define
define|#
directive|define
name|HighFence32Bits
value|0x5678ABDC
end_define

begin_typedef
typedef|typedef
struct|struct
name|_TSTMTID_TRACE_BUFFER_FETCH
block|{
name|bit32
name|CardNo
decl_stmt|;
name|bit32
name|BufferOffsetBegin
decl_stmt|;
name|bit32
name|LowFence
decl_stmt|;
name|bit8
name|Data
index|[
name|FetchBufferSIZE
index|]
decl_stmt|;
name|bit32
name|HighFence
decl_stmt|;
name|bit32
name|Flag
decl_stmt|;
block|}
name|TSTMTID_TRACE_BUFFER_FETCH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TSTMTID_TRACE_BUFFER_RESET
block|{
name|bit32
name|CardNo
decl_stmt|;
name|bit32
name|Reset
decl_stmt|;
name|bit32
name|TraceMask
decl_stmt|;
name|bit32
name|Flag
decl_stmt|;
block|}
name|TSTMTID_TRACE_BUFFER_RESET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdPhyCount_s
block|{
name|bit32
name|Phy
decl_stmt|;
name|bit32
name|BW_tx
decl_stmt|;
name|bit32
name|BW_rx
decl_stmt|;
name|bit32
name|InvalidDword
decl_stmt|;
name|bit32
name|runningDisparityError
decl_stmt|;
name|bit32
name|codeViolation
decl_stmt|;
name|bit32
name|LossOfSyncDW
decl_stmt|;
name|bit32
name|phyResetProblem
decl_stmt|;
name|bit32
name|inboundCRCError
decl_stmt|;
block|}
name|tdPhyCount_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PHY_GENERAL_STATE
block|{
name|bit32
name|Dword0
decl_stmt|;
name|bit32
name|Dword1
decl_stmt|;
block|}
name|GetPhyGenState_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyGeneralState_s
block|{
name|GetPhyGenState_t
name|PhyGenData
index|[
literal|16
index|]
decl_stmt|;
name|bit32
name|Reserved1
decl_stmt|;
name|bit32
name|Reserved2
decl_stmt|;
block|}
name|agsaPhyGeneralState_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PHY_DETAILS_
block|{
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attached_sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attached_sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attached_phy
decl_stmt|;
name|bit8
name|attached_dev_type
decl_stmt|;
block|}
name|PhyDetails_t
typedef|;
end_typedef

begin_enum
enum|enum
name|SAS_SATA_DEVICE_TYPE
block|{
name|SAS_PHY_NO_DEVICE
block|,
name|SAS_PHY_END_DEVICE
block|,
name|SAS_PHY_EXPANDER_DEVICE
block|,
name|SAS_PHY_SATA_DEVICE
init|=
literal|0x11
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PHY_SETTINGS_LEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TD_IOCTL_H */
end_comment

end_unit

