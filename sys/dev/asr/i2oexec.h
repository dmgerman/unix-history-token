begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *   * Copyright 1999 I2O Special Interest Group (I2O SIG).  All rights reserved.  * All rights reserved  *   * TERMS AND CONDITIONS OF USE  *   * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *   * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *   * This header file, and any modifications of this header file, are provided  * contingent upon your agreement and adherence to the here-listed terms and  * conditions.  By accepting and/or using this header file, you agree to abide  * by these terms and conditions and that these terms and conditions will be  * construed and governed in accordance with the laws of the State of California,  * without reference to conflict-of-law provisions.  If you do not agree  * to these terms and conditions, please delete this file, and any copies,  * permanently, without making any use thereof.  *   * THIS HEADER FILE IS PROVIDED FREE OF CHARGE ON AN AS-IS BASIS WITHOUT  * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  * TO IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE.  I2O SIG DOES NOT WARRANT THAT THIS HEADER FILE WILL MEET THE  * USER'S REQUIREMENTS OR THAT ITS OPERATION WILL BE UNINTERRUPTED OR  * ERROR-FREE.  *   * I2O SIG DISCLAIMS ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF  * ANY PROPRIETARY RIGHTS, RELATING TO THE IMPLEMENTATION OF THE I2O  * SPECIFICATIONS.  I2O SIG DOES NOT WARRANT OR REPRESENT THAT SUCH  * IMPLEMENTATIONS WILL NOT INFRINGE SUCH RIGHTS.  *   * THE USER OF THIS HEADER FILE SHALL HAVE NO RECOURSE TO I2O SIG FOR ANY  * ACTUAL OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT LIMITED TO, LOST DATA  * OR LOST PROFITS ARISING OUT OF THE USE OR INABILITY TO USE THIS PROGRAM.  *   * I2O SIG grants the user of this header file a license to copy, distribute,  * and modify it, for any purpose, under the following terms.  Any copying,  * distribution, or modification of this header file must not delete or alter  * the copyright notice of I2O SIG or any of these Terms and Conditions.  *   * Any distribution of this header file must not include a charge for the  * header file (unless such charges are strictly for the physical acts of  * copying or transferring copies).  However, distribution of a product in  * which this header file is embedded may include a charge so long as any  * such charge does not include any charge for the header file itself.  *   * Any modification of this header file constitutes a derivative work based  * on this header file.  Any distribution of such derivative work: (1) must  * include prominent notices that the header file has been changed from the  * original, together with the dates of any changes; (2) automatically includes   * this same license to the original header file from I2O SIG, without any  * restriction thereon from the distributing user; and (3) must include a  * grant of license of the modified file under the same terms and conditions  * as these Terms and Conditions.  *   * The I2O SIG Web site can be found at: http://www.i2osig.org  *   * The I2O SIG encourages you to deposit derivative works based on this  * header file at the I2O SIG Web site.  Furthermore, to become a Registered  * Developer of the I2O SIG, sign up at the Web site or call 415.750.8352  * (United States).  ****************************************************************/
end_comment

begin_comment
comment|/*********************************************************************  * I2OExec.h -- I2O Executive Class Message definition file  *  * This file contains information presented in Chapter 4 of the I2O(tm)  * Specification.  **********************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_EXECUTIVE_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_EXECUTIVE_HDR
end_define

begin_define
define|#
directive|define
name|I2OEXEC_REV
value|1_5_4
end_define

begin_comment
comment|/* I2OExec header file revision string */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|KERN_VERSION
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|KERN_VERSION
operator|<
literal|3
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/pci/i2omsg.h"
end_include

begin_comment
comment|/* Include the Base Message file */
end_comment

begin_include
include|#
directive|include
file|"i386/pci/i2outil.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dev/asr/i2omsg.h"
end_include

begin_comment
comment|/* Include the Base Message file */
end_comment

begin_include
include|#
directive|include
file|"dev/asr/i2outil.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"i2omsg.h"
end_include

begin_comment
comment|/* Include the Base Message file */
end_comment

begin_include
include|#
directive|include
file|"i2outil.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*     NOTES:      Gets, reads, receives, etc. are all even numbered functions.     Sets, writes, sends, etc. are all odd numbered functions.     Functions that both send and receive data can be either but an attempt is made         to use the function number that indicates the greater transfer amount.     Functions that do not send or receive data use odd function numbers.      Some functions are synonyms like read, receive and send, write.      All common functions will have a code of less than 0x80.     Unique functions to a class will start at 0x80.     Executive Functions start at 0xA0.      Utility Message function codes range from 0 - 0x1f     Base Message function codes range from 0x20 - 0xfe     Private Message function code is 0xff. */
end_comment

begin_expr_stmt
name|PRAGMA_ALIGN_PUSH
name|PRAGMA_PACK_PUSH
end_expr_stmt

begin_comment
comment|/*  I2O Executive Function Codes.  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_ASSIGN
value|0xB3
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_READ
value|0xB2
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_RELEASE
value|0xB5
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_BIOS_INFO_SET
value|0xA5
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_BOOT_DEVICE_SET
value|0xA7
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_CONFIG_VALIDATE
value|0xBB
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_CONN_SETUP
value|0xCA
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_DESTROY
value|0xB1
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_ENABLE
value|0xD5
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_QUIESCE
value|0xC7
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_RESET
value|0xD9
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_SUSPEND
value|0xAF
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN
value|0xB7
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE
value|0xB9
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_HRT_GET
value|0xA8
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_CLEAR
value|0xBE
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_CONNECT
value|0xC9
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET
value|0xBD
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_NOTIFY
value|0xA2
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT
value|0xA1
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_PATH_ENABLE
value|0xD3
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_PATH_QUIESCE
value|0xC5
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_PATH_RESET
value|0xD7
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATIC_MF_CREATE
value|0xDD
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATIC_MF_RELEASE
value|0xDF
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET
value|0xA0
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_DOWNLOAD
value|0xA9
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_UPLOAD
value|0xAB
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_REMOVE
value|0xAD
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_ENABLE
value|0xD1
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_MODIFY
value|0xC1
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_QUIESCE
value|0xC3
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET
value|0xA3
end_define

begin_comment
comment|/* I2O Get Status State values */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_STATE_INITIALIZING
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_HOLD
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_READY
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_OPERATIONAL
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_FAILED
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_FAULTED
value|0x11
end_define

begin_comment
comment|/* Event Indicator Assignments for the Executive Class. */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_IND_RESOURCE_LIMIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_CONNECTION_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_ADAPTER_FAULT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_POWER_FAIL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_RESET_PENDING
value|0x00000010
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_RESET_IMMINENT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_HARDWARE_FAIL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_XCT_CHANGE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_NEW_LCT_ENTRY
value|0x00000100
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_MODIFIED_LCT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_DDM_AVAILABILITY
value|0x00000400
end_define

begin_comment
comment|/* Resource Limit Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_RESOURCE_LIMIT_LOW_MEMORY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESOURCE_LIMIT_INBOUND_POOL_LOW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESOURCE_LIMIT_OUTBOUND_POOL_LOW
value|0x00000004
end_define

begin_comment
comment|/* Connection Fail Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_CONNECTION_FAIL_REPOND_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_CONNECTION_FAIL_NOT_REPONDING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_CONNECTION_FAIL_NO_AVAILABLE_FRAMES
value|0x00000002
end_define

begin_comment
comment|/* Reset Pending Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_PENDING_POWER_LOSS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_PENDING_CODE_VIOLATION
value|0x00000002
end_define

begin_comment
comment|/* Reset Imminent Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_UNKNOWN_CAUSE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_POWER_LOSS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_CODE_VIOLATION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_PARITY_ERROR
value|0x00000003
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_CODE_EXCEPTION
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_RESET_IMMINENT_WATCHDOG_TIMEOUT
value|0x00000005
end_define

begin_comment
comment|/* Hardware Fail Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_HARDWARE_FAIL_UNKNOWN_CAUSE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_HARDWARE_FAIL_CPU_FAILURE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_HARDWARE_FAIL_MEMORY_FAULT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_HARDWARE_FAIL_DMA_FAILURE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_HARDWARE_FAIL_IO_BUS_FAILURE
value|0x00000004
end_define

begin_comment
comment|/* DDM Availability Event Data */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_DDM_AVAILIBILITY_RESPOND_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_DDM_AVAILIBILITY_CONGESTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_DDM_AVAILIBILITY_NOT_RESPONDING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_DDM_AVAILIBILITY_PROTECTION_VIOLATION
value|0x00000003
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_DDM_AVAILIBILITY_CODE_VIOLATION
value|0x00000004
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_OPERATION_FLAG_ASSIGN_PERMANENT
value|0x01
end_define

begin_comment
comment|/* ExecAdapterAssign Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_ADAPTER_ASSIGN_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|DdmTID
decl_stmt|;
else|#
directive|else
name|BF
name|DdmTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_12BITS
decl_stmt|;
name|BF
name|OperationFlags
range|:
name|I2O_8BIT_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
name|I2O_HRT_ENTRY
name|HRTEntry
decl_stmt|;
block|}
name|I2O_EXEC_ADAPTER_ASSIGN_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_ADAPTER_ASSIGN_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_REQUEST_FLAG_CONFIG_REGISTER
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_REQUEST_FLAG_IO_REGISTER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_REQUEST_FLAG_ADAPTER_MEMORY
value|0x00000002
end_define

begin_comment
comment|/* ExecAdapterRead Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_ADAPTER_READ_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|AdapterID
decl_stmt|;
name|U32
name|RequestFlags
decl_stmt|;
name|U32
name|Offset
decl_stmt|;
name|U32
name|Length
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_ADAPTER_READ_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_ADAPTER_READ_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_OPERATION_FLAG_RELEASE_PERMANENT
value|0x01
end_define

begin_comment
comment|/* ExecAdapterRelease Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_ADAPTER_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|U8
name|OperationFlags
decl_stmt|;
name|I2O_HRT_ENTRY
name|HRTEntry
decl_stmt|;
block|}
name|I2O_EXEC_ADAPTER_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_ADAPTER_RELEASE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecBiosInfoSet Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_BIOS_INFO_SET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|DeviceTID
decl_stmt|;
else|#
directive|else
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_12BITS
decl_stmt|;
name|BF
name|BiosInfo
range|:
name|I2O_BIOS_INFO_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_EXEC_BIOS_INFO_SET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_BIOS_INFO_SET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecBootDeviceSet Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_BOOT_DEVICE_SET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|BootDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
block|}
name|I2O_EXEC_BOOT_DEVICE_SET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_BOOT_DEVICE_SET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecConfigValidate Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_CONFIG_VALIDATE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_EXEC_CONFIG_VALIDATE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_CONFIG_VALIDATE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecConnSetup Requestor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_ALIAS_CONNECT_SETUP
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|IOP1AliasForTargetDevice
decl_stmt|;
else|#
directive|else
name|BF
name|IOP1AliasForTargetDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|IOP2AliasForInitiatorDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_8BITS
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_ALIAS_CONNECT_SETUP
operator|,
typedef|*
name|PI2O_ALIAS_CONNECT_SETUP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_OPERATION_FLAG_PEER_TO_PEER_BIDIRECTIONAL
value|0x01
end_define

begin_comment
comment|/* ExecConnSetup Object  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_OBJECT_CONNECT_SETUP
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|TargetDevice
decl_stmt|;
else|#
directive|else
name|BF
name|TargetDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|InitiatorDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|OperationFlags
range|:
name|I2O_8BIT_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_OBJECT_CONNECT_SETUP
operator|,
typedef|*
name|PI2O_OBJECT_CONNECT_SETUP
typedef|;
end_typedef

begin_comment
comment|/* ExecConnSetup Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_CONN_SETUP_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_OBJECT_CONNECT_SETUP
name|ObjectInfo
decl_stmt|;
name|I2O_ALIAS_CONNECT_SETUP
name|AliasInfo
decl_stmt|;
name|U16
name|IOP2InboundMFrameSize
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
name|U32
name|MessageClass
decl_stmt|;
block|}
name|I2O_EXEC_CONN_SETUP_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_CONN_SETUP_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* ExecConnSetup Object Reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_OBJECT_CONNECT_REPLY
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|TargetDevice
decl_stmt|;
else|#
directive|else
name|BF
name|TargetDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|InitiatorDevice
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|ReplyStatusCode
range|:
name|I2O_8BIT_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_OBJECT_CONNECT_REPLY
operator|,
typedef|*
name|PI2O_OBJECT_CONNECT_REPLY
typedef|;
end_typedef

begin_comment
comment|/* ExecConnSetup reply structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_CONN_SETUP_REPLY
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_OBJECT_CONNECT_REPLY
name|ObjectInfo
decl_stmt|;
name|I2O_ALIAS_CONNECT_SETUP
name|AliasInfo
decl_stmt|;
name|U16
name|IOP2InboundMFrameSize
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
block|}
name|I2O_EXEC_CONN_SETUP_REPLY
operator|,
typedef|*
name|PI2O_EXEC_CONN_SETUP_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecDdmDestroy Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DDM_DESTROY_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|DdmTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
block|}
name|I2O_EXEC_DDM_DESTROY_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DDM_DESTROY_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecDdmEnable Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DDM_ENABLE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_DDM_ENABLE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DDM_ENABLE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecDdmQuiesce Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DDM_QUIESCE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_DDM_QUIESCE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DDM_QUIESCE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecDdmReset Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DDM_RESET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_DDM_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DDM_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecDdmSuspend Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DDM_SUSPEND_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|DdmTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
block|}
name|I2O_EXEC_DDM_SUSPEND_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DDM_SUSPEND_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_OPERATION_FLAG_ASSIGN_PERMANENT
value|0x01
end_define

begin_comment
comment|/* ExecDeviceAssign Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DEVICE_ASSIGN_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|DeviceTID
decl_stmt|;
else|#
directive|else
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|DdmTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|OperationFlags
range|:
name|I2O_8BIT_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DEVICE_ASSIGN_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_OPERATION_FLAG_RELEASE_PERMANENT
value|0x01
end_define

begin_comment
comment|/* ExecDeviceRelease Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DEVICE_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|DeviceTID
decl_stmt|;
else|#
directive|else
name|BF
name|DeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|DdmTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|OperationFlags
range|:
name|I2O_8BIT_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_DEVICE_RELEASE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* HRT Entry Structure defined in I2OMSG.H */
end_comment

begin_comment
comment|/* ExecHrtGet Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_HRT_GET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_HRT_GET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_HRT_GET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecIopClear Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_CLEAR_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_EXEC_IOP_CLEAR_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_IOP_CLEAR_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecIopConnect Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_CONNECT_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
name|BF
name|reserved3
range|:
name|I2O_RESERVED_8BITS
decl_stmt|;
name|BF
name|IOP1MsgerType
range|:
name|I2O_MESSENGER_TYPE_SZ
decl_stmt|;
name|U16
name|IOP1InboundMFrameSize
decl_stmt|;
name|BF
name|IOP1AliasForIOP2
range|:
name|I2O_TID_SZ
decl_stmt|;
name|U8
name|reserved1
decl_stmt|;
name|BF
name|IOP_ID1
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID1
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_IOP_CONNECT_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_IOP_CONNECT_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* ExecIopConnect reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_CONNECT_IOP_REPLY
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U16
name|DetailedStatusCode
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|ReqStatus
decl_stmt|;
name|U16
name|IOP2InboundMFrameSize
decl_stmt|;
name|BF
name|IOP2AliasForIOP1
range|:
name|I2O_TID_SZ
decl_stmt|;
name|U8
name|reserved1
decl_stmt|;
name|BF
name|IOP_ID2
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID2
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_IOP_CONNECT_REPLY
operator|,
typedef|*
name|PI2O_EXEC_IOP_CONNECT_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_RESERVED_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_IN_PROGRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_REJECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_STATUS_RESERVED_SZ
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_RESET_STATUS
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|ResetStatus
decl_stmt|;
else|#
directive|else
name|U8
name|ResetStatus
decl_stmt|;
name|U8
name|reserved
index|[
name|I2O_EXEC_IOP_RESET_STATUS_RESERVED_SZ
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_EXEC_IOP_RESET_STATUS
operator|,
typedef|*
name|PI2O_EXEC_IOP_RESET_STATUS
typedef|;
end_typedef

begin_comment
comment|/* ExecIopReset Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_RESET_MESSAGE
block|{
name|U8
name|VersionOffset
decl_stmt|;
name|U8
name|MsgFlags
decl_stmt|;
name|U16
name|MessageSize
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|TargetAddress
decl_stmt|;
else|#
directive|else
name|BF
name|TargetAddress
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|InitiatorAddress
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|Function
range|:
name|I2O_FUNCTION_SZ
decl_stmt|;
endif|#
directive|endif
name|U8
name|Reserved
index|[
name|I2O_EXEC_IOP_RESET_RESERVED_SZ
index|]
decl_stmt|;
name|U32
name|StatusWordLowAddress
decl_stmt|;
name|U32
name|StatusWordHighAddress
decl_stmt|;
block|}
name|I2O_EXEC_IOP_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_IOP_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* LCT Entry Structure defined in I2OMSG.H */
end_comment

begin_comment
comment|/* ExecLCTNotify Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_LCT_NOTIFY_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|ClassIdentifier
decl_stmt|;
name|U32
name|LastReportedChangeIndicator
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_LCT_NOTIFY_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_LCT_NOTIFY_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecOutboundInit Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_OUTBOUND_INIT_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|HostPageFrameSize
decl_stmt|;
name|U8
name|InitCode
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U16
name|OutboundMFrameSize
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_OUTBOUND_INIT_MESSAGE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_IN_PROGRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_REJECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_FAILED
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_COMPLETE
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_RESERVED_SZ
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_OUTBOUND_INIT_STATUS
block|{
name|U8
name|InitStatus
decl_stmt|;
name|U8
name|reserved
index|[
name|I2O_EXEC_OUTBOUND_INIT_RESERVED_SZ
index|]
decl_stmt|;
block|}
name|I2O_EXEC_OUTBOUND_INIT_STATUS
operator|,
typedef|*
name|PI2O_EXEC_OUTBOUND_INIT_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_OUTBOUND_INIT_RECLAIM_LIST
block|{
name|U32
name|MFACount
decl_stmt|;
name|U32
name|MFAReleaseCount
decl_stmt|;
name|U32
name|MFAAddress
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_EXEC_OUTBOUND_INIT_RECLAIM_LIST
operator|,
typedef|*
name|PI2O_EXEC_OUTBOUND_INIT_RECLAIM_LIST
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecPathEnable Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_PATH_ENABLE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_PATH_ENABLE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_PATH_ENABLE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecPathQuiesce Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_PATH_QUIESCE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_PATH_QUIESCE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_PATH_QUIESCE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecPathReset Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_PATH_RESET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
block|}
name|I2O_EXEC_PATH_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_PATH_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATIC_MF_CREATE_RESERVED_SZ
value|3
end_define

begin_comment
comment|/* ExecStaticMfCreate Message Frame  structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_STATIC_MF_CREATE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|MaxOutstanding
decl_stmt|;
name|U8
name|reserved
index|[
name|I2O_EXEC_STATIC_MF_CREATE_RESERVED_SZ
index|]
decl_stmt|;
name|I2O_MESSAGE_FRAME
name|StaticMessageFrame
decl_stmt|;
block|}
name|I2O_EXEC_STATIC_MF_CREATE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_STATIC_MF_CREATE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* ExecStaticMfCreate Message Frame reply */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_STATIC_MF_CREATE_REPLY
block|{
name|I2O_SINGLE_REPLY_MESSAGE_FRAME
name|StdReplyFrame
decl_stmt|;
name|PI2O_MESSAGE_FRAME
name|StaticMFA
decl_stmt|;
block|}
name|I2O_EXEC_STATIC_MF_CREATE_REPLY
operator|,
typedef|*
name|PI2O_EXEC_STATIC_MF_CREATE_REPLY
typedef|;
end_typedef

begin_comment
comment|/* ExecStaticMfRelease Message Frame structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_STATIC_MF_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|PI2O_MESSAGE_FRAME
name|StaticMFA
decl_stmt|;
block|}
name|I2O_EXEC_STATIC_MF_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_STATIC_MF_RELEASE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_RESERVED_SZ
value|16
end_define

begin_comment
comment|/* ExecStatusGet Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_STATUS_GET_MESSAGE
block|{
name|U8
name|VersionOffset
decl_stmt|;
name|U8
name|MsgFlags
decl_stmt|;
name|U16
name|MessageSize
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|TargetAddress
decl_stmt|;
else|#
directive|else
name|BF
name|TargetAddress
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|InitiatorAddress
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|Function
range|:
name|I2O_FUNCTION_SZ
decl_stmt|;
endif|#
directive|endif
name|U8
name|Reserved
index|[
name|I2O_EXEC_STATUS_GET_RESERVED_SZ
index|]
decl_stmt|;
name|U32
name|ReplyBufferAddressLow
decl_stmt|;
name|U32
name|ReplyBufferAddressHigh
decl_stmt|;
name|U32
name|ReplyBufferLength
decl_stmt|;
block|}
name|I2O_EXEC_STATUS_GET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_STATUS_GET_MESSAGE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_IOP_STATUS_PROD_ID_STR_SZ
value|24
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_RESERVED_SZ
value|6
end_define

begin_comment
comment|/* ExecStatusGet reply Structure */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CONTEXT_32_ONLY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CONTEXT_64_ONLY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CONTEXT_32_64_NOT_CURRENTLY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CONTEXT_32_64_CURRENTLY
value|0x00000003
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CURRENT_CONTEXT_NOT_CONFIG
value|0x00000000
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CURRENT_CONTEXT_32_ONLY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CURRENT_CONTEXT_64_ONLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_CURRENT_CONTEXT_32_64
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_INBOUND_PEER_SUPPORT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_OUTBOUND_PEER_SUPPORT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|I2O_IOP_CAP_PEER_TO_PEER_SUPPORT
value|0x00000040
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_STATUS_GET_REPLY
block|{
name|U16
name|OrganizationID
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|IOP_ID
decl_stmt|;
else|#
directive|else
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|SegmentNumber
decl_stmt|;
else|#
directive|else
name|BF
name|SegmentNumber
range|:
name|I2O_SEGMENT_NUMBER_SZ
decl_stmt|;
name|BF
name|I2oVersion
range|:
name|I2O_4BIT_VERSION_SZ
decl_stmt|;
name|BF
name|IopState
range|:
name|I2O_IOP_STATE_SZ
decl_stmt|;
name|BF
name|MessengerType
range|:
name|I2O_MESSENGER_TYPE_SZ
decl_stmt|;
endif|#
directive|endif
name|U16
name|InboundMFrameSize
decl_stmt|;
name|U8
name|InitCode
decl_stmt|;
name|U8
name|reserved2
decl_stmt|;
name|U32
name|MaxInboundMFrames
decl_stmt|;
name|U32
name|CurrentInboundMFrames
decl_stmt|;
name|U32
name|MaxOutboundMFrames
decl_stmt|;
name|U8
name|ProductIDString
index|[
name|I2O_IOP_STATUS_PROD_ID_STR_SZ
index|]
decl_stmt|;
name|U32
name|ExpectedLCTSize
decl_stmt|;
name|U32
name|IopCapabilities
decl_stmt|;
name|U32
name|DesiredPrivateMemSize
decl_stmt|;
name|U32
name|CurrentPrivateMemSize
decl_stmt|;
name|U32
name|CurrentPrivateMemBase
decl_stmt|;
name|U32
name|DesiredPrivateIOSize
decl_stmt|;
name|U32
name|CurrentPrivateIOSize
decl_stmt|;
name|U32
name|CurrentPrivateIOBase
decl_stmt|;
name|U8
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
name|U8
name|SyncByte
decl_stmt|;
block|}
name|I2O_EXEC_STATUS_GET_REPLY
operator|,
typedef|*
name|PI2O_EXEC_STATUS_GET_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_SW_DOWNLOAD_FLAG_LOAD_MEMORY
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_DOWNLOAD_FLAG_PERMANENT_STORE
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_DOWNLOAD_FLAG_EXPERIMENTAL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_DOWNLOAD_FLAG_OVERRIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_DDM
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_DDM_MPB
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_DDM_CONFIG_TABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_IRTOS
value|0x11
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_IRTOS_PRIVATE_MODULE
value|0x12
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_IRTOS_DIALOG_TABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_IOP_PRIVATE_MODULE
value|0x22
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SW_TYPE_IOP_DIALOG_TABLE
value|0x23
end_define

begin_comment
comment|/* I2O ExecSwDownload/Upload/Remove SwID Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SW_ID
block|{
name|U16
name|ModuleID
decl_stmt|;
name|U16
name|OrganizationID
decl_stmt|;
block|}
name|I2O_SW_ID
operator|,
typedef|*
name|PI2O_SW_ID
typedef|;
end_typedef

begin_comment
comment|/* ExecSwDownload Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SW_DOWNLOAD_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|CurrentFragment
decl_stmt|;
name|U8
name|TotalFragments
decl_stmt|;
name|U8
name|SwType
decl_stmt|;
name|U8
name|DownloadFlags
decl_stmt|;
name|U32
name|SWSize
decl_stmt|;
name|I2O_SW_ID
name|SwID
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_SW_DOWNLOAD_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SW_DOWNLOAD_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSwUpload Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SW_UPLOAD_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|CurrentFragment
decl_stmt|;
name|U8
name|TotalFragments
decl_stmt|;
name|U8
name|SwType
decl_stmt|;
name|U8
name|UploadFlags
decl_stmt|;
name|U32
name|SWSize
decl_stmt|;
name|I2O_SW_ID
name|SwID
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_SW_UPLOAD_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SW_UPLOAD_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSwRemove Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SW_REMOVE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
name|U8
name|SwType
decl_stmt|;
name|U8
name|RemoveFlags
decl_stmt|;
name|U32
name|SWSize
decl_stmt|;
name|I2O_SW_ID
name|SwID
decl_stmt|;
block|}
name|I2O_EXEC_SW_REMOVE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SW_REMOVE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSysEnable Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SYS_ENABLE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_EXEC_SYS_ENABLE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SYS_ENABLE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSysModify Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SYS_MODIFY_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_SYS_MODIFY_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SYS_MODIFY_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSysQuiesce Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SYS_QUIESCE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_EXEC_SYS_QUIESCE_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SYS_QUIESCE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ExecSysTabSet (System Table) Function Message Frame structure. */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_IOP_ID_LOCAL_IOP
value|0x000
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_IOP_ID_LOCAL_HOST
value|0x001
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_IOP_ID_UNKNOWN_IOP
value|0xFFF
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_HOST_UNIT_ID_LOCAL_UNIT
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_HOST_UNIT_ID_UNKNOWN_UNIT
value|0xffff
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SEG_NUMBER_LOCAL_SEGMENT
value|0x000
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SEG_NUMBER_UNKNOWN_SEGMENT
value|0xfff
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SYS_TAB_SET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|IOP_ID
decl_stmt|;
else|#
directive|else
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|HostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|SegmentNumber
decl_stmt|;
else|#
directive|else
name|BF
name|SegmentNumber
range|:
name|I2O_SEGMENT_NUMBER_SZ
decl_stmt|;
name|BF
name|reserved2
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved3
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
endif|#
directive|endif
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_EXEC_SYS_TAB_SET_MESSAGE
operator|,
typedef|*
name|PI2O_EXEC_SYS_TAB_SET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* ExecSysTabSet (System Table) Header Reply structure. */
end_comment

begin_define
define|#
directive|define
name|I2O_SET_SYSTAB_RESERVED_SZ
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SET_SYSTAB_HEADER
block|{
name|U8
name|NumberEntries
decl_stmt|;
name|U8
name|SysTabVersion
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
name|U32
name|CurrentChangeIndicator
decl_stmt|;
name|U8
name|reserved1
index|[
name|I2O_SET_SYSTAB_RESERVED_SZ
index|]
decl_stmt|;
comment|/*    I2O_SYSTAB_ENTRY    SysTabEntry[1]; */
block|}
name|I2O_SET_SYSTAB_HEADER
operator|,
typedef|*
name|PI2O_SET_SYSTAB_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_RESOURCE_MANAGER_VERSION
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MESSENGER_INFO
block|{
name|U32
name|InboundMessagePortAddressLow
decl_stmt|;
name|U32
name|InboundMessagePortAddressHigh
decl_stmt|;
block|}
name|I2O_MESSENGER_INFO
operator|,
typedef|*
name|PI2O_MESSENGER_INFO
typedef|;
end_typedef

begin_comment
comment|/* ExecSysTabSet IOP Descriptor Entry structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_IOP_ENTRY
block|{
name|U16
name|OrganizationID
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|IOP_ID
decl_stmt|;
else|#
directive|else
name|BF
name|IOP_ID
range|:
name|I2O_IOP_ID_SZ
decl_stmt|;
name|BF
name|reserved3
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|reserved1
range|:
name|I2O_RESERVED_16BITS
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|SegmentNumber
decl_stmt|;
else|#
directive|else
name|BF
name|SegmentNumber
range|:
name|I2O_SEGMENT_NUMBER_SZ
decl_stmt|;
name|BF
name|I2oVersion
range|:
name|I2O_4BIT_VERSION_SZ
decl_stmt|;
name|BF
name|IopState
range|:
name|I2O_IOP_STATE_SZ
decl_stmt|;
name|BF
name|MessengerType
range|:
name|I2O_MESSENGER_TYPE_SZ
decl_stmt|;
endif|#
directive|endif
name|U16
name|InboundMessageFrameSize
decl_stmt|;
name|U16
name|reserved2
decl_stmt|;
name|U32
name|LastChanged
decl_stmt|;
name|U32
name|IopCapabilities
decl_stmt|;
name|I2O_MESSENGER_INFO
name|MessengerInfo
decl_stmt|;
block|}
name|I2O_IOP_ENTRY
operator|,
typedef|*
name|PI2O_IOP_ENTRY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Executive Parameter Groups */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_HARDWARE_GROUP_NO
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_MESSAGE_IF_GROUP_NO
value|0x0001
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_EXECUTING_ENVIRONMENT_GROUP_NO
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_EXECUTING_DDM_LIST_GROUP_NO
value|0x0003
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DRIVER_STORE_GROUP_NO
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DRIVER_STORE_TABLE_GROUP_NO
value|0x0005
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_BUS_ATTRIBUTES_GROUP_NO
value|0x0006
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_SW_ATTRIBUTES_GROUP_NO
value|0x0007
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_HARDWARE_RESOURCE_TABLE_GROUP_NO
value|0x0100
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_SCALAR_GROUP_NO
value|0x0101
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_TABLE_GROUP_NO
value|0x0102
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYSTEM_TABLE_GROUP_NO
value|0x0103
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_EXTERNAL_CONN_TABLE_GROUP_NO
value|0x0104
end_define

begin_comment
comment|/* EXEC Group 0000h - IOP Hardware Parameter Group */
end_comment

begin_comment
comment|/* IOP HardWare Capabilities defines */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_HW_CAP_SELF_BOOT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_IOP_HW_CAP_IRTOS_UPGRADEABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_IOP_HW_CAP_DOWNLOADABLE_DDM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I2O_IOP_HW_CAP_INSTALLABLE_DDM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|I2O_IOP_HW_CAP_BATTERY_BACKUP_RAM
value|0x00000010
end_define

begin_comment
comment|/* IOP Processor Type defines */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_INTEL_80960
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_AMD_29000
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_MOTOROLA_68000
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_ARM
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_MIPS
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_SPARC
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_POWER_PC
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_ALPHA
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_INTEL_X86
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_IOP_PROC_TYPE_OTHER
value|0xFF
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_HARDWARE_SCALAR
block|{
name|U16
name|I2oVendorID
decl_stmt|;
name|U16
name|ProductID
decl_stmt|;
name|U32
name|ProcessorMemory
decl_stmt|;
name|U32
name|PermMemory
decl_stmt|;
name|U32
name|HWCapabilities
decl_stmt|;
name|U8
name|ProcessorType
decl_stmt|;
name|U8
name|ProcessorVersion
decl_stmt|;
block|}
name|I2O_EXEC_IOP_HARDWARE_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_IOP_HARDWARE_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0001h - IOP Message Interface Parameter Group */
end_comment

begin_comment
comment|/* InitCode defines */
end_comment

begin_define
define|#
directive|define
name|I2O_MESSAGE_IF_INIT_CODE_NO_OWNER
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_IF_INIT_CODE_BIOS
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_IF_INIT_CODE_OEM_BIOS_EXTENSION
value|0x20
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_IF_INIT_CODE_ROM_BIOS_EXTENSION
value|0x30
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_IF_INIT_CODE_OS
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_MESSAGE_IF_SCALAR
block|{
name|U32
name|InboundFrameSize
decl_stmt|;
name|U32
name|InboundSizeTarget
decl_stmt|;
name|U32
name|InboundMax
decl_stmt|;
name|U32
name|InboundTarget
decl_stmt|;
name|U32
name|InboundPoolCount
decl_stmt|;
name|U32
name|InboundCurrentFree
decl_stmt|;
name|U32
name|InboundCurrentPost
decl_stmt|;
name|U16
name|StaticCount
decl_stmt|;
name|U16
name|StaticInstanceCount
decl_stmt|;
name|U16
name|StaticLimit
decl_stmt|;
name|U16
name|StaticInstanceLimit
decl_stmt|;
name|U32
name|OutboundFrameSize
decl_stmt|;
name|U32
name|OutboundMax
decl_stmt|;
name|U32
name|OutboundMaxTarget
decl_stmt|;
name|U32
name|OutboundCurrentFree
decl_stmt|;
name|U32
name|OutboundCurrentPost
decl_stmt|;
name|U8
name|InitCode
decl_stmt|;
block|}
name|I2O_EXEC_IOP_MESSAGE_IF_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_IOP_MESSAGE_IF_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0002h - Executing Environment Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_EXECUTE_ENVIRONMENT_SCALAR
block|{
name|U32
name|MemTotal
decl_stmt|;
name|U32
name|MemFree
decl_stmt|;
name|U32
name|PageSize
decl_stmt|;
name|U32
name|EventQMax
decl_stmt|;
name|U32
name|EventQCurrent
decl_stmt|;
name|U32
name|DDMLoadMax
decl_stmt|;
block|}
name|I2O_EXEC_EXECUTE_ENVIRONMENT_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_EXECUTE_ENVIRONMENT_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0003h - Executing DDM's Parameter Group */
end_comment

begin_comment
comment|/* ModuleType Defines */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_MODULE_TYPE_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_MODULE_TYPE_DOWNLOAD
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DDM_MODULE_TYPE_EMBEDDED
value|0x22
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_EXECUTE_DDM_TABLE
block|{
name|U16
name|DdmTID
decl_stmt|;
name|U8
name|ModuleType
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U16
name|I2oVendorID
decl_stmt|;
name|U16
name|ModuleID
decl_stmt|;
name|U8
name|ModuleName
index|[
name|I2O_MODULE_NAME_SZ
index|]
decl_stmt|;
name|U32
name|ModuleVersion
decl_stmt|;
name|U32
name|DataSize
decl_stmt|;
name|U32
name|CodeSize
decl_stmt|;
block|}
name|I2O_EXEC_EXECUTE_DDM_TABLE
operator|,
typedef|*
name|PI2O_EXEC_EXECUTE_DDM_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0004h - Driver Store Environment Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DRIVER_STORE_SCALAR
block|{
name|U32
name|ModuleLimit
decl_stmt|;
name|U32
name|ModuleCount
decl_stmt|;
name|U32
name|CurrentSpace
decl_stmt|;
name|U32
name|FreeSpace
decl_stmt|;
block|}
name|I2O_EXEC_DRIVER_STORE_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_DRIVER_STORE_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0005h - Driver Store Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_DRIVER_STORE_TABLE
block|{
name|U16
name|StoredDdmIndex
decl_stmt|;
name|U8
name|ModuleType
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U16
name|I2oVendorID
decl_stmt|;
name|U16
name|ModuleID
decl_stmt|;
name|U8
name|ModuleName
index|[
name|I2O_MODULE_NAME_SZ
index|]
decl_stmt|;
name|U32
name|ModuleVersion
decl_stmt|;
name|U16
name|DateDay
decl_stmt|;
name|U16
name|DateMonth
decl_stmt|;
name|U32
name|DateYear
decl_stmt|;
name|U32
name|ModuleSize
decl_stmt|;
name|U32
name|MpbSize
decl_stmt|;
name|U32
name|ModuleFlags
decl_stmt|;
block|}
name|I2O_EXEC_DRIVER_STORE_TABLE
operator|,
typedef|*
name|PI2O_EXEC_DRIVER_STORE_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0006h - IOP's Bus Attributes Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_BUS_ATTRIB_SYSTEM_BUS
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_BUS_ATTRIB_BRIDGED_SYSTEM_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_BUS_ATTRIB_PRIVATE
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_BUS_ATTRIBUTE_TABLE
block|{
name|U32
name|BusID
decl_stmt|;
name|U8
name|BusType
decl_stmt|;
name|U8
name|MaxAdapters
decl_stmt|;
name|U8
name|AdapterCount
decl_stmt|;
name|U8
name|BusAttributes
decl_stmt|;
block|}
name|I2O_EXEC_IOP_BUS_ATTRIBUTE_TABLE
operator|,
typedef|*
name|PI2O_EXEC_IOP_BUS_ATTRIBUTE_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0007h - IOP's Bus Attributes Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_SW_CAP_IRTOS_I2O_COMPLIANT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_SW_CAP_IRTOS_UPGRADEABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_SW_CAP_DOWNLOADABLE_DDM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_SW_CAP_INSTALLABLE_DDM
value|0x00000008
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_IOP_SW_ATTRIBUTES_SCALAR
block|{
name|U16
name|I2oVendorID
decl_stmt|;
name|U16
name|ProductID
decl_stmt|;
name|U32
name|CodeSize
decl_stmt|;
name|U32
name|SWCapabilities
decl_stmt|;
block|}
name|I2O_EXEC_IOP_SW_ATTRIBUTES_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_IOP_SW_ATTRIBUTES_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0100h - Hardware Resource Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_HARDWARE_RESOURCE_TABLE
block|{
name|U32
name|AdapterID
decl_stmt|;
name|U16
name|StateInfo
decl_stmt|;
comment|/* AdapterState plus Local TID */
name|U8
name|BusNumber
decl_stmt|;
name|U8
name|BusType
decl_stmt|;
name|U64
name|PhysicalLocation
decl_stmt|;
name|U32
name|MemorySpace
decl_stmt|;
name|U32
name|IoSpace
decl_stmt|;
block|}
name|I2O_EXEC_HARDWARE_RESOURCE_TABLE
operator|,
typedef|*
name|PI2O_EXEC_HARDWARE_RESOURCE_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0101h - Logical Configuration Table Scalar Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_LCT_SCALAR
block|{
name|U16
name|BootDevice
decl_stmt|;
name|U32
name|IopFlags
decl_stmt|;
name|U32
name|CurrentChangeIndicator
decl_stmt|;
block|}
name|I2O_EXEC_LCT_SCALAR
operator|,
typedef|*
name|PI2O_EXEC_LCT_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0102h - Logical Configuration Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_LCT_TABLE
block|{
name|U16
name|LocalTID
decl_stmt|;
name|U16
name|UserTID
decl_stmt|;
name|U16
name|ParentTID
decl_stmt|;
name|U16
name|DdmTID
decl_stmt|;
name|U32
name|ChangeIndicator
decl_stmt|;
name|U32
name|DeviceFlags
decl_stmt|;
name|U32
name|ClassID
decl_stmt|;
name|U32
name|SubClass
decl_stmt|;
name|U8
name|IdentityTag
index|[
name|I2O_IDENTITY_TAG_SZ
index|]
decl_stmt|;
name|U32
name|EventCapabilities
decl_stmt|;
name|U8
name|BiosInfo
decl_stmt|;
block|}
name|I2O_EXEC_LCT_TABLE
operator|,
typedef|*
name|PI2O_EXEC_LCT_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0103h - System Table Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_MESSENGER_TYPE_MEMORY_MAPPED_MESSAGE_UNIT
value|0x0
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_SYSTEM_TABLE
block|{
name|U16
name|IOP_ID
decl_stmt|;
name|U16
name|OrganizationID
decl_stmt|;
name|U16
name|SegmentNumber
decl_stmt|;
name|U8
name|Version
decl_stmt|;
name|U8
name|IopState
decl_stmt|;
name|U8
name|MessengerType
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U32
name|InboundMessagePortAddress
decl_stmt|;
name|U16
name|InboundMessageFrameSize
decl_stmt|;
name|U32
name|IopCapabilities
decl_stmt|;
name|I2O_MESSENGER_INFO
name|MessengerInfo
decl_stmt|;
block|}
name|I2O_EXEC_SYSTEM_TABLE
operator|,
typedef|*
name|PI2O_EXEC_SYSTEM_TABLE
typedef|;
end_typedef

begin_comment
comment|/* EXEC Group 0104h - External Connection Table Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_XCT_FLAGS_REMOTE_IOP_CREATED_CONNECTION
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_XCT_FLAGS_THIS_IOP_CREATED_CONNECTION
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EXEC_EXTERNAL_CONNECTION_TABLE
block|{
name|U16
name|LocalAliasTID
decl_stmt|;
name|U16
name|RemoteTID
decl_stmt|;
name|U16
name|RemoteIOP
decl_stmt|;
name|U16
name|RemoteUnitID
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
block|}
name|I2O_EXEC_EXTERNAL_CONNECTION_TABLE
operator|,
typedef|*
name|PI2O_EXEC_EXTERNAL_CONNECTION_TABLE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_expr_stmt
name|PRAGMA_PACK_POP
name|PRAGMA_ALIGN_POP
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I2O_EXECUTIVE_HDR */
end_comment

end_unit

