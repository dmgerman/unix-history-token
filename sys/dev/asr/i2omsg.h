begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *  * Copyright 1999 I2O Special Interest Group (I2O SIG).  All rights reserved.  * All rights reserved  *  * TERMS AND CONDITIONS OF USE  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  * This header file, and any modifications of this header file, are provided  * contingent upon your agreement and adherence to the here-listed terms and  * conditions.  By accepting and/or using this header file, you agree to abide  * by these terms and conditions and that these terms and conditions will be  * construed and governed in accordance with the laws of the State of California,  * without reference to conflict-of-law provisions.  If you do not agree  * to these terms and conditions, please delete this file, and any copies,  * permanently, without making any use thereof.  *  * THIS HEADER FILE IS PROVIDED FREE OF CHARGE ON AN AS-IS BASIS WITHOUT  * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  * TO IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE.  I2O SIG DOES NOT WARRANT THAT THIS HEADER FILE WILL MEET THE  * USER'S REQUIREMENTS OR THAT ITS OPERATION WILL BE UNINTERRUPTED OR  * ERROR-FREE.  *  * I2O SIG DISCLAIMS ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF  * ANY PROPRIETARY RIGHTS, RELATING TO THE IMPLEMENTATION OF THE I2O  * SPECIFICATIONS.  I2O SIG DOES NOT WARRANT OR REPRESENT THAT SUCH  * IMPLEMENTATIONS WILL NOT INFRINGE SUCH RIGHTS.  *  * THE USER OF THIS HEADER FILE SHALL HAVE NO RECOURSE TO I2O SIG FOR ANY  * ACTUAL OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT LIMITED TO, LOST DATA  * OR LOST PROFITS ARISING OUT OF THE USE OR INABILITY TO USE THIS PROGRAM.  *  * I2O SIG grants the user of this header file a license to copy, distribute,  * and modify it, for any purpose, under the following terms.  Any copying,  * distribution, or modification of this header file must not delete or alter  * the copyright notice of I2O SIG or any of these Terms and Conditions.  *  * Any distribution of this header file must not include a charge for the  * header file (unless such charges are strictly for the physical acts of  * copying or transferring copies).  However, distribution of a product in  * which this header file is embedded may include a charge so long as any  * such charge does not include any charge for the header file itself.  *  * Any modification of this header file constitutes a derivative work based  * on this header file.  Any distribution of such derivative work: (1) must  * include prominent notices that the header file has been changed from the  * original, together with the dates of any changes; (2) automatically includes  * this same license to the original header file from I2O SIG, without any  * restriction thereon from the distributing user; and (3) must include a  * grant of license of the modified file under the same terms and conditions  * as these Terms and Conditions.  *  * The I2O SIG Web site can be found at: http://www.i2osig.org  *  * The I2O SIG encourages you to deposit derivative works based on this  * header file at the I2O SIG Web site.  Furthermore, to become a Registered  * Developer of the I2O SIG, sign up at the Web site or call 415.750.8352  * (United States).  ****************************************************************/
end_comment

begin_comment
comment|/*********************************************************************  * I2OMsg.h -- I2O Message defintion file  *  * This file contains information presented in Chapter 3, 4 and 6 of  * the I2O(tm) Specification and most of the I2O Global defines and  * Typedefs.  **********************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_MESSAGE_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_MESSAGE_HDR
end_define

begin_define
define|#
directive|define
name|I2OMSG_REV
value|1_5_4
end_define

begin_comment
comment|/* I2OMsg header file revision string */
end_comment

begin_comment
comment|/*     NOTES:     Gets, reads, receives, etc. are all even numbered functions.    Sets, writes, sends, etc. are all odd numbered functions.    Functions that both send and receive data can be either but an attempt is    made to use the function number that indicates the greater transfer amount.    Functions that do not send or receive data use odd function numbers.     Some functions are synonyms like read, receive and send, write.     All common functions will have a code of less than 0x80.    Unique functions to a class will start at 0x80.    Executive Functions start at 0xA0.     Utility Message function codes range from 0 - 0x1f    Base Message function codes range from 0x20 - 0xfe    Private Message function code is 0xff. */
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
name|KERN_VERSION
operator|<
literal|3
operator|)
end_if

begin_include
include|#
directive|include
file|"i386/pci/i2otypes.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dev/asr/i2otypes.h"
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
file|"i2otypes.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|PRAGMA_ALIGN_PUSH
name|PRAGMA_PACK_PUSH
end_expr_stmt

begin_comment
comment|/* Set to 1 for 64 bit Context Fields */
end_comment

begin_define
define|#
directive|define
name|I2O_64BIT_CONTEXT
value|0
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Common functions accross all classes. */
end_comment

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE
value|0xFF
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Class ID and Code Assignments */
end_comment

begin_define
define|#
directive|define
name|I2O_CLASS_VERSION_10
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_VERSION_11
value|0x01
end_define

begin_comment
comment|/*    Class Code Names:  Table 6-1 Class Code Assignments. */
end_comment

begin_define
define|#
directive|define
name|I2O_CLASS_EXECUTIVE
value|0x000
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_DDM
value|0x001
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_RANDOM_BLOCK_STORAGE
value|0x010
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_SEQUENTIAL_STORAGE
value|0x011
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_LAN
value|0x020
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_WAN
value|0x030
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_FIBRE_CHANNEL_PORT
value|0x040
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_FIBRE_CHANNEL_PERIPHERAL
value|0x041
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_SCSI_PERIPHERAL
value|0x051
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ATE_PORT
value|0x060
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ATE_PERIPHERAL
value|0x061
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_FLOPPY_CONTROLLER
value|0x070
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_FLOPPY_DEVICE
value|0x071
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_BUS_ADAPTER_PORT
value|0x080
end_define

begin_comment
comment|/* Class Codes 0x090 - 0x09f are reserved for Peer-to-Peer classes */
end_comment

begin_define
define|#
directive|define
name|I2O_CLASS_MATCH_ANYCLASS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|I2O_SUBCLASS_i960
value|0x001
end_define

begin_define
define|#
directive|define
name|I2O_SUBCLASS_HDM
value|0x020
end_define

begin_define
define|#
directive|define
name|I2O_SUBCLASS_ISM
value|0x021
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Message Frame defines and structures  */
end_comment

begin_comment
comment|/*   Defines for the Version_Status field. */
end_comment

begin_define
define|#
directive|define
name|I2O_VERSION_10
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_VERSION_11
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_VERSION_OFFSET_NUMBER_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_VERSION_OFFSET_SGL_TRL_OFFSET_MASK
value|0xF0
end_define

begin_comment
comment|/*   Defines for the Message Flags Field. */
end_comment

begin_comment
comment|/*   Please Note the the FAIL bit is only set in the Transport Fail Message. */
end_comment

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_STATIC
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_64BIT_CONTEXT
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_MULTIPLE
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_FAIL
value|0x20
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_LAST
value|0x40
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FLAGS_REPLY
value|0x80
end_define

begin_comment
comment|/* Defines for Request Status Codes:  Table 3-1 Reply Status Codes.  */
end_comment

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ABORT_DIRTY
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ABORT_NO_DATA_TRANSFER
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ABORT_PARTIAL_TRANSFER
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ERROR_DIRTY
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ERROR_NO_DATA_TRANSFER
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_ERROR_PARTIAL_TRANSFER
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_PROCESS_ABORT_DIRTY
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_PROCESS_ABORT_NO_DATA_TRANSFER
value|0x09
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_PROCESS_ABORT_PARTIAL_TRANSFER
value|0x0A
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_TRANSACTION_ERROR
value|0x0B
end_define

begin_define
define|#
directive|define
name|I2O_REPLY_STATUS_PROGRESS_REPORT
value|0x80
end_define

begin_comment
comment|/* DetailedStatusCode defines for ALL messages: Table 3-2 Detailed Status Codes.  */
end_comment

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_BAD_KEY
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_TCL_ERROR
value|0x0003
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_REPLY_BUFFER_FULL
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_NO_SUCH_PAGE
value|0x0005
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INSUFFICIENT_RESOURCE_SOFT
value|0x0006
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INSUFFICIENT_RESOURCE_HARD
value|0x0007
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_CHAIN_BUFFER_TOO_LARGE
value|0x0009
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_UNSUPPORTED_FUNCTION
value|0x000A
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_DEVICE_LOCKED
value|0x000B
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_DEVICE_RESET
value|0x000C
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INAPPROPRIATE_FUNCTION
value|0x000D
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_INITIATOR_ADDRESS
value|0x000E
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_MESSAGE_FLAGS
value|0x000F
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_OFFSET
value|0x0010
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_PARAMETER
value|0x0011
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_REQUEST
value|0x0012
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_INVALID_TARGET_ADDRESS
value|0x0013
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_MESSAGE_TOO_LARGE
value|0x0014
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_MESSAGE_TOO_SMALL
value|0x0015
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_MISSING_PARAMETER
value|0x0016
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_TIMEOUT
value|0x0017
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_UNKNOWN_ERROR
value|0x0018
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_UNKNOWN_FUNCTION
value|0x0019
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_UNSUPPORTED_VERSION
value|0x001A
end_define

begin_define
define|#
directive|define
name|I2O_DEATIL_STATUS_DEVICE_BUSY
value|0x001B
end_define

begin_define
define|#
directive|define
name|I2O_DETAIL_STATUS_DEVICE_NOT_AVAILABLE
value|0x001C
end_define

begin_comment
comment|/* Common I2O Field sizes  */
end_comment

begin_define
define|#
directive|define
name|I2O_TID_SZ
value|12
end_define

begin_define
define|#
directive|define
name|I2O_FUNCTION_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_UNIT_ID_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_SEGMENT_NUMBER_SZ
value|12
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ID_SZ
value|12
end_define

begin_define
define|#
directive|define
name|I2O_GROUP_ID_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_IOP_STATE_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_MESSENGER_TYPE_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_SZ
value|12
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ORGANIZATION_ID_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_4BIT_VERSION_SZ
value|4
end_define

begin_define
define|#
directive|define
name|I2O_8BIT_FLAGS_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_COMMON_LENGTH_FIELD_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_DEVID_DESCRIPTION_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_DEVID_VENDOR_INFO_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_DEVID_PRODUCT_INFO_SZ
value|16
end_define

begin_define
define|#
directive|define
name|I2O_DEVID_REV_LEVEL_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_MODULE_NAME_SZ
value|24
end_define

begin_define
define|#
directive|define
name|I2O_BIOS_INFO_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_4BITS
value|4
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_8BITS
value|8
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_12BITS
value|12
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_16BITS
value|16
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_20BITS
value|20
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_24BITS
value|24
end_define

begin_define
define|#
directive|define
name|I2O_RESERVED_28BITS
value|28
end_define

begin_typedef
typedef|typedef
name|U32
name|I2O_PARAMETER_TID
typedef|;
end_typedef

begin_if
if|#
directive|if
name|I2O_64BIT_CONTEXT
end_if

begin_typedef
typedef|typedef
name|U64
name|I2O_INITIATOR_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U64
name|I2O_TRANSACTION_CONTEXT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|U32
name|I2O_INITIATOR_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U32
name|I2O_TRANSACTION_CONTEXT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Serial Number format defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_BINARY
value|1
end_define

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_ASCII
value|2
end_define

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_UNICODE
value|3
end_define

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_LAN_MAC
value|4
end_define

begin_define
define|#
directive|define
name|I2O_SERIAL_FORMAT_WAN
value|5
end_define

begin_comment
comment|/* Special TID Assignments */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_TID
value|0
end_define

begin_define
define|#
directive|define
name|I2O_HOST_TID
value|1
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Message Frame common for all messages  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_MESSAGE_FRAME
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
operator|)
operator|||
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
operator|(
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
name|I2O_INITIATOR_CONTEXT
name|InitiatorContext
decl_stmt|;
block|}
name|I2O_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Transaction Reply Lists (TRL) Control Word structure */
end_comment

begin_define
define|#
directive|define
name|I2O_TRL_FLAGS_SINGLE_FIXED_LENGTH
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_TRL_FLAGS_SINGLE_VARIABLE_LENGTH
value|0x40
end_define

begin_define
define|#
directive|define
name|I2O_TRL_FLAGS_MULTIPLE_FIXED_LENGTH
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_TRL_CONTROL_WORD
block|{
name|U8
name|TrlCount
decl_stmt|;
name|U8
name|TrlElementSize
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|TrlFlags
decl_stmt|;
if|#
directive|if
name|I2O_64BIT_CONTEXT
name|U32
name|Padding
decl_stmt|;
comment|/* Padding for 64 bit */
endif|#
directive|endif
block|}
name|I2O_TRL_CONTROL_WORD
operator|,
typedef|*
name|PI2O_TRL_CONTROL_WORD
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Successful Single Transaction Reply Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SINGLE_REPLY_MESSAGE_FRAME
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
comment|/*                             ReplyPayload        */
block|}
name|I2O_SINGLE_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_SINGLE_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Successful Multiple Transaction Reply Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_MULTIPLE_REPLY_MESSAGE_FRAME
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRL_CONTROL_WORD
name|TrlControlWord
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
comment|/*                             TransactionDetails[]        */
block|}
name|I2O_MULTIPLE_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_MULTIPLE_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Private Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PRIVATE_MESSAGE_FRAME
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U16
name|XFunctionCode
decl_stmt|;
name|U16
name|OrganizationID
decl_stmt|;
comment|/*                             PrivatePayload[]        */
block|}
name|I2O_PRIVATE_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_PRIVATE_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Message Failure Severity Codes */
end_comment

begin_define
define|#
directive|define
name|I2O_SEVERITY_FORMAT_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|I2O_SEVERITY_PATH_ERROR
value|0x2
end_define

begin_define
define|#
directive|define
name|I2O_SEVERITY_PATH_STATE
value|0x4
end_define

begin_define
define|#
directive|define
name|I2O_SEVERITY_CONGESTION
value|0x8
end_define

begin_comment
comment|/* Transport Failure Codes: Table 3-3 Mesasge Failure Codes */
end_comment

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_SERVICE_SUSPENDED
value|0x81
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_SERVICE_TERMINATED
value|0x82
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_CONGESTION
value|0x83
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_FAIL
value|0x84
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_STATE_ERROR
value|0x85
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_TIME_OUT
value|0x86
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_ROUTING_FAILURE
value|0x87
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_VERSION
value|0x88
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_OFFSET
value|0x89
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_MSG_FLAGS
value|0x8A
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_FRAME_TOO_SMALL
value|0x8B
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_FRAME_TOO_LARGE
value|0x8C
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_TARGET_ID
value|0x8D
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_INITIATOR_ID
value|0x8E
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_INVALID_INITIATOR_CONTEXT
value|0x8F
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_CODE_TRANSPORT_UNKNOWN_FAILURE
value|0xFF
end_define

begin_comment
comment|/* IOP_ID and Severity sizes */
end_comment

begin_define
define|#
directive|define
name|I2O_FAILCODE_SEVERITY_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_FAILCODE_CODE_SZ
value|8
end_define

begin_comment
comment|/* I2O Transport Message Reply for Message Failure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_FAILURE_REPLY_MESSAGE_FRAME
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
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
name|U32
name|LowestVersion
decl_stmt|;
name|U32
name|reserved
decl_stmt|;
else|#
directive|else
name|U8
name|LowestVersion
decl_stmt|;
name|U8
name|HighestVersion
decl_stmt|;
comment|/*      BF                      Severity:I2O_FAILCODE_SEVERITY_SZ; //      BF                      FailureCode:I2O_FAILCODE_CODE_SZ; // // Due to our compiler padding this structure and making it larger than // it really is (4 bytes larger), we are re-defining these two fields */
name|U8
name|Severity
decl_stmt|;
name|U8
name|FailureCode
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_RESERVED_4BITS
decl_stmt|;
name|BF
name|FailingHostUnitID
range|:
name|I2O_UNIT_ID_SZ
decl_stmt|;
name|BF
name|reserved1
range|:
literal|12
decl_stmt|;
endif|#
directive|endif
name|U32
name|AgeLimit
decl_stmt|;
name|U32
name|PreservedMFA
decl_stmt|;
block|}
name|I2O_FAILURE_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_FAILURE_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/* I2O Transport Message Reply for Transaction Error. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_TRANSACTION_ERROR_REPLY_MESSAGE_FRAME
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
comment|/* Should always be Transaction Error */
name|U32
name|ErrorOffset
decl_stmt|;
name|U8
name|BitOffset
decl_stmt|;
name|U8
name|reserved1
decl_stmt|;
name|U16
name|reserved2
decl_stmt|;
block|}
name|I2O_TRANSACTION_ERROR_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_TRANSACTION_ERROR_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Misc. commonly used structures */
end_comment

begin_comment
comment|/* Class ID Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_CLASS_ID
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
name|Class
decl_stmt|;
else|#
directive|else
name|BF
name|Class
range|:
name|I2O_CLASS_ID_SZ
decl_stmt|;
name|BF
name|Version
range|:
name|I2O_4BIT_VERSION_SZ
decl_stmt|;
name|BF
name|OrganizationID
range|:
name|I2O_CLASS_ORGANIZATION_ID_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_CLASS_ID
operator|,
typedef|*
name|PI2O_CLASS_ID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_MAX_SERIAL_NUMBER_SZ
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SERIAL_INFO
block|{
name|U8
name|SerialNumberLength
decl_stmt|;
name|U8
name|SerialNumberFormat
decl_stmt|;
name|U8
name|SerialNumber
index|[
name|I2O_MAX_SERIAL_NUMBER_SZ
index|]
decl_stmt|;
block|}
name|I2O_SERIAL_INFO
operator|,
typedef|*
name|PI2O_SERIAL_INFO
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Hardware Resource Table (HRT) and Logical Configuration Table (LCT) */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Bus Type Code defines */
end_comment

begin_define
define|#
directive|define
name|I2O_LOCAL_BUS
value|0
end_define

begin_define
define|#
directive|define
name|I2O_ISA_BUS
value|1
end_define

begin_define
define|#
directive|define
name|I2O_EISA_BUS
value|2
end_define

begin_define
define|#
directive|define
name|I2O_MCA_BUS
value|3
end_define

begin_define
define|#
directive|define
name|I2O_PCI_BUS
value|4
end_define

begin_define
define|#
directive|define
name|I2O_PCMCIA_BUS
value|5
end_define

begin_define
define|#
directive|define
name|I2O_NUBUS_BUS
value|6
end_define

begin_define
define|#
directive|define
name|I2O_CARDBUS_BUS
value|7
end_define

begin_define
define|#
directive|define
name|I2O_OTHER_BUS
value|0x80
end_define

begin_define
define|#
directive|define
name|I2O_HRT_STATE_SZ
value|4
end_define

begin_define
define|#
directive|define
name|I2O_HRT_BUS_NUMBER_SZ
value|8
end_define

begin_define
define|#
directive|define
name|I2O_HRT_BUS_TYPE_SZ
value|8
end_define

begin_comment
comment|/* Bus Structures */
end_comment

begin_comment
comment|/* PCI Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PCI_BUS_INFO
block|{
name|U8
name|PciFunctionNumber
decl_stmt|;
name|U8
name|PciDeviceNumber
decl_stmt|;
name|U8
name|PciBusNumber
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U16
name|PciVendorID
decl_stmt|;
name|U16
name|PciDeviceID
decl_stmt|;
block|}
name|I2O_PCI_BUS_INFO
operator|,
typedef|*
name|PI2O_PCI_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* Local Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_LOCAL_BUS_INFO
block|{
name|U16
name|LbBaseIOPort
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
name|U32
name|LbBaseMemoryAddress
decl_stmt|;
block|}
name|I2O_LOCAL_BUS_INFO
operator|,
typedef|*
name|PI2O_LOCAL_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* ISA Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_ISA_BUS_INFO
block|{
name|U16
name|IsaBaseIOPort
decl_stmt|;
name|U8
name|CSN
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U32
name|IsaBaseMemoryAddress
decl_stmt|;
block|}
name|I2O_ISA_BUS_INFO
operator|,
typedef|*
name|PI2O_ISA_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* EISA Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_EISA_BUS_INFO
block|{
name|U16
name|EisaBaseIOPort
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|EisaSlotNumber
decl_stmt|;
name|U32
name|EisaBaseMemoryAddress
decl_stmt|;
block|}
name|I2O_EISA_BUS_INFO
operator|,
typedef|*
name|PI2O_EISA_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* MCA Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_MCA_BUS_INFO
block|{
name|U16
name|McaBaseIOPort
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|McaSlotNumber
decl_stmt|;
name|U32
name|McaBaseMemoryAddress
decl_stmt|;
block|}
name|I2O_MCA_BUS_INFO
operator|,
typedef|*
name|PI2O_MCA_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* Other Bus */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_OTHER_BUS_INFO
block|{
name|U16
name|BaseIOPort
decl_stmt|;
name|U16
name|reserved
decl_stmt|;
name|U32
name|BaseMemoryAddress
decl_stmt|;
block|}
name|I2O_OTHER_BUS_INFO
operator|,
typedef|*
name|PI2O_OTHER_BUS_INFO
typedef|;
end_typedef

begin_comment
comment|/* HRT Entry Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HRT_ENTRY
block|{
name|U32
name|AdapterID
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
name|ControllingTID
decl_stmt|;
else|#
directive|else
name|BF
name|ControllingTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|AdapterState
range|:
name|I2O_HRT_STATE_SZ
decl_stmt|;
name|BF
name|BusNumber
range|:
name|I2O_HRT_BUS_NUMBER_SZ
decl_stmt|;
name|BF
name|BusType
range|:
name|I2O_HRT_BUS_TYPE_SZ
decl_stmt|;
endif|#
directive|endif
union|union
block|{
comment|/* PCI Bus */
name|I2O_PCI_BUS_INFO
name|PCIBus
decl_stmt|;
comment|/* Local Bus */
name|I2O_LOCAL_BUS_INFO
name|LocalBus
decl_stmt|;
comment|/* ISA Bus */
name|I2O_ISA_BUS_INFO
name|ISABus
decl_stmt|;
comment|/* EISA Bus */
name|I2O_EISA_BUS_INFO
name|EISABus
decl_stmt|;
comment|/* MCA Bus */
name|I2O_MCA_BUS_INFO
name|MCABus
decl_stmt|;
comment|/* Other. */
name|I2O_OTHER_BUS_INFO
name|OtherBus
decl_stmt|;
block|}
name|uBus
union|;
block|}
name|I2O_HRT_ENTRY
operator|,
typedef|*
name|PI2O_HRT_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* I2O Hardware Resource Table structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HRT
block|{
name|U16
name|NumberEntries
decl_stmt|;
name|U8
name|EntryLength
decl_stmt|;
name|U8
name|HRTVersion
decl_stmt|;
name|U32
name|CurrentChangeIndicator
decl_stmt|;
name|I2O_HRT_ENTRY
name|HRTEntry
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_HRT
operator|,
typedef|*
name|PI2O_HRT
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Logical Configuration Table  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Logical Configuration Table structures. */
end_comment

begin_define
define|#
directive|define
name|I2O_IDENTITY_TAG_SZ
value|8
end_define

begin_comment
comment|/* I2O Logical Configuration Table Device Flags */
end_comment

begin_define
define|#
directive|define
name|I2O_LCT_DEVICE_FLAGS_CONF_DIALOG_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_LCT_DEVICE_FLAGS_MORE_THAN_1_USER
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_LCT_DEVICE_FLAGS_PEER_SERVICE_DISABLED
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_LCT_DEVICE_FLAGS_MANAGEMENT_SERVICE_DISABLED
value|0x20
end_define

begin_comment
comment|/* LCT Entry Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_LCT_ENTRY
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
name|TableEntrySize
decl_stmt|;
else|#
directive|else
name|BF
name|TableEntrySize
range|:
name|I2O_COMMON_LENGTH_FIELD_SZ
decl_stmt|;
name|BF
name|LocalTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|reserved
range|:
name|I2O_4BIT_VERSION_SZ
decl_stmt|;
endif|#
directive|endif
name|U32
name|ChangeIndicator
decl_stmt|;
name|U32
name|DeviceFlags
decl_stmt|;
name|I2O_CLASS_ID
name|ClassID
decl_stmt|;
name|U32
name|SubClassInfo
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|UserTID
decl_stmt|;
else|#
directive|else
name|BF
name|UserTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|ParentTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|BiosInfo
range|:
name|I2O_BIOS_INFO_SZ
decl_stmt|;
endif|#
directive|endif
name|U8
name|IdentityTag
index|[
name|I2O_IDENTITY_TAG_SZ
index|]
decl_stmt|;
name|U32
name|EventCapabilities
decl_stmt|;
block|}
name|I2O_LCT_ENTRY
operator|,
typedef|*
name|PI2O_LCT_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* I2O Logical Configuration Table structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_LCT
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
name|TableSize
decl_stmt|;
else|#
directive|else
name|BF
name|TableSize
range|:
name|I2O_COMMON_LENGTH_FIELD_SZ
decl_stmt|;
name|BF
name|BootDeviceTID
range|:
name|I2O_TID_SZ
decl_stmt|;
name|BF
name|LctVer
range|:
name|I2O_4BIT_VERSION_SZ
decl_stmt|;
endif|#
directive|endif
name|U32
name|IopFlags
decl_stmt|;
name|U32
name|CurrentChangeIndicator
decl_stmt|;
name|I2O_LCT_ENTRY
name|LCTEntry
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_LCT
operator|,
typedef|*
name|PI2O_LCT
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Memory Addressing structures and defines. */
end_comment

begin_comment
comment|/* SglFlags defines. */
end_comment

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_LAST_ELEMENT
value|0x80
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_END_OF_BUFFER
value|0x40
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_IGNORE_ELEMENT
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_TRANSPORT_ELEMENT
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_BIT_BUCKET_ELEMENT
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_IMMEDIATE_DATA_ELEMENT
value|0x0C
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_SIMPLE_ADDRESS_ELEMENT
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_PAGE_LIST_ADDRESS_ELEMENT
value|0x20
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CHAIN_POINTER_ELEMENT
value|0x30
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_LONG_TRANSACTION_ELEMENT
value|0x40
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_SHORT_TRANSACTION_ELEMENT
value|0x70
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_SGL_ATTRIBUTES_ELEMENT
value|0x7C
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_BC0
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_BC1
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_DIR
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_LOCAL_ADDRESS
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT_COUNT_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_ADDRESS_MODE_MASK
value|0x3C
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_NO_CONTEXT
value|0x00
end_define

begin_comment
comment|/*  Scatter/Gather Truth Table */
end_comment

begin_comment
comment|/*  typedef enum _SG_TYPE {    INVALID,    Ignore,    TransportDetails,    BitBucket,    ImmediateData,    Simple,    PageList,    ChainPointer,    ShortTransaction,    LongTransaction,    SGLAttributes,    INVALID/ReservedLongFormat,    INVALID/ReservedShortFormat } SG_TYPE, *PSG_TYPE;      0x00    Ignore;    0x04    TransportDetails;    0x08    BitBucket;    0x0C    ImmediateData;    0x10    Simple;    0x14    Simple;    0x18    Simple;    0x1C    Simple;    0x20    PageList;    0x24    PageList;    0x28    PageList;    0x2C    PageList;    0x30    ChainPointer;    0x34    INVALID;    0x38    ChainPointer;    0x3C    INVALID;    0x40    LongTransaction;    0x44    INVALID/ReservedLongFormat;    0x48    BitBucket;    0x4C    ImmediateData;    0x50    Simple;    0x54    Simple;    0x58    Simple;    0x5C    Simple;    0x60    PageList;    0x64    PageList;    0x68    PageList;    0x6C    PageList;    0x70    ShortTransaction;    0x74    INVALID/ReservedShortFormat;    0x78    INVALID/ReservedShortFormat;    0x7C    SGLAttributes; */
end_comment

begin_comment
comment|/* 32 Bit Context Field defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U32
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U64
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U96
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_NULL_SZ
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U32_SZ
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U64_SZ
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT32_U96_SZ
value|0x0C
end_define

begin_comment
comment|/* 64 Bit Context Field defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U64
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U128
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U192
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_NULL_SZ
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U64_SZ
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U128_SZ
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_SGL_FLAGS_CONTEXT64_U192_SZ
value|0x18
end_define

begin_comment
comment|/* SGL Attribute Element defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_BIT_BUCKET_HINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_IMMEDIATE_DATA_HINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_LOCAL_ADDRESS_HINT
value|0x0100
end_define

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_32BIT_TRANSACTION
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_64BIT_TRANSACTION
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_SGL_ATTRIBUTE_FLAGS_32BIT_LOCAL_ADDRESS
value|0x0000
end_define

begin_comment
comment|/* SG Size defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SG_COUNT_SZ
value|24
end_define

begin_define
define|#
directive|define
name|I2O_SG_FLAGS_SZ
value|8
end_define

begin_comment
comment|/* Standard Flags and Count fields for SG Elements */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_FLAGS_COUNT
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|sparc
argument_list|)
operator|)
name|U32
name|Count
decl_stmt|;
else|#
directive|else
name|BF
name|Count
range|:
name|I2O_SG_COUNT_SZ
decl_stmt|;
name|BF
name|Flags
range|:
name|I2O_SG_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_FLAGS_COUNT
operator|,
typedef|*
name|PI2O_FLAGS_COUNT
typedef|;
end_typedef

begin_comment
comment|/* Bit Bucket Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_BIT_BUCKET_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|BufferContext
decl_stmt|;
block|}
name|I2O_SGE_BIT_BUCKET_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_BIT_BUCKET_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Chain Addressing Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_CHAIN_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|PhysicalAddress
decl_stmt|;
block|}
name|I2O_SGE_CHAIN_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_CHAIN_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Chain Addressing with Context Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_CHAIN_CONTEXT_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|Context
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|PhysicalAddress
decl_stmt|;
block|}
name|I2O_SGE_CHAIN_CONTEXT_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_CHAIN_CONTEXT_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Ignore Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_IGNORE_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
block|}
name|I2O_SGE_IGNORE_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_IGNORE_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Immediate Data Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_IMMEDIATE_DATA_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
block|}
name|I2O_SGE_IMMEDIATE_DATA_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_IMMEDIATE_DATA_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Immediate Data with Context Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_IMMEDIATE_DATA_CONTEXT_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|BufferContext
decl_stmt|;
block|}
name|I2O_SGE_IMMEDIATE_DATA_CONTEXT_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_IMMEDIATE_DATA_CONTEXT_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Long Transaction Parameters Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_LONG_TRANSACTION_ELEMENT
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
name|LongElementLength
decl_stmt|;
else|#
directive|else
name|BF
name|LongElementLength
range|:
name|I2O_SG_COUNT_SZ
decl_stmt|;
name|BF
name|Flags
range|:
name|I2O_SG_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
name|U32
name|BufferContext
decl_stmt|;
block|}
name|I2O_SGE_LONG_TRANSACTION_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_LONG_TRANSACTION_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Page List Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_PAGE_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|PhysicalAddress
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_SGE_PAGE_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_PAGE_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Page List with Context Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_PAGE_CONTEXT_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|BufferContext
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|PhysicalAddress
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_SGE_PAGE_CONTEXT_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_PAGE_CONTEXT_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* SGL Attribute Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_SGL_ATTRIBUTES_ELEMENT
block|{
name|U16
name|SglAttributeFlags
decl_stmt|;
name|U8
name|ElementLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|PageFrameSize
decl_stmt|;
block|}
name|I2O_SGE_SGL_ATTRIBUTES_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_SGL_ATTRIBUTES_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Short Transaction Parameters Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_SHORT_TRANSACTION_ELEMENT
block|{
name|U16
name|ClassFields
decl_stmt|;
name|U8
name|ElementLength
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U32
name|BufferContext
decl_stmt|;
block|}
name|I2O_SGE_SHORT_TRANSACTION_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_SHORT_TRANSACTION_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Simple Addressing Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_SIMPLE_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|PhysicalAddress
decl_stmt|;
block|}
name|I2O_SGE_SIMPLE_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_SIMPLE_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Simple Addressing with Context Scatter-Gather Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_SIMPLE_CONTEXT_ELEMENT
block|{
name|I2O_FLAGS_COUNT
name|FlagsCount
decl_stmt|;
name|U32
name|BufferContext
index|[
literal|1
index|]
decl_stmt|;
name|U32
name|PhysicalAddress
decl_stmt|;
block|}
name|I2O_SGE_SIMPLE_CONTEXT_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_SIMPLE_CONTEXT_ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Transport Detail Element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SGE_TRANSPORT_ELEMENT
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
name|LongElementLength
decl_stmt|;
else|#
directive|else
name|BF
name|LongElementLength
range|:
name|I2O_SG_COUNT_SZ
decl_stmt|;
name|BF
name|Flags
range|:
name|I2O_SG_FLAGS_SZ
decl_stmt|;
endif|#
directive|endif
block|}
name|I2O_SGE_TRANSPORT_ELEMENT
operator|,
typedef|*
name|PI2O_SGE_TRANSPORT_ELEMENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SG_ELEMENT
block|{
union|union
block|{
comment|/* Bit Bucket Element */
name|I2O_SGE_BIT_BUCKET_ELEMENT
name|BitBucket
decl_stmt|;
comment|/* Chain Addressing Element */
name|I2O_SGE_CHAIN_ELEMENT
name|Chain
decl_stmt|;
comment|/* Chain Addressing with Context Element */
name|I2O_SGE_CHAIN_CONTEXT_ELEMENT
name|ChainContext
decl_stmt|;
comment|/* Ignore Scatter-Gather Element */
name|I2O_SGE_IGNORE_ELEMENT
name|Ignore
decl_stmt|;
comment|/* Immediate Data Element */
name|I2O_SGE_IMMEDIATE_DATA_ELEMENT
name|ImmediateData
decl_stmt|;
comment|/* Immediate Data with Context Element */
name|I2O_SGE_IMMEDIATE_DATA_CONTEXT_ELEMENT
name|ImmediateDataContext
decl_stmt|;
comment|/* Long Transaction Parameters Element */
name|I2O_SGE_LONG_TRANSACTION_ELEMENT
name|LongTransaction
decl_stmt|;
comment|/* Page List Element */
name|I2O_SGE_PAGE_ELEMENT
name|Page
decl_stmt|;
comment|/* Page List with Context Element */
name|I2O_SGE_PAGE_CONTEXT_ELEMENT
name|PageContext
decl_stmt|;
comment|/* SGL Attribute Element */
name|I2O_SGE_SGL_ATTRIBUTES_ELEMENT
name|SGLAttribute
decl_stmt|;
comment|/* Short Transaction Parameters Element */
name|I2O_SGE_SHORT_TRANSACTION_ELEMENT
name|ShortTransaction
decl_stmt|;
comment|/* Simple Addressing Element */
name|I2O_SGE_SIMPLE_ELEMENT
name|Simple
index|[
literal|1
index|]
decl_stmt|;
comment|/* Simple Addressing with Context Element */
name|I2O_SGE_SIMPLE_CONTEXT_ELEMENT
name|SimpleContext
index|[
literal|1
index|]
decl_stmt|;
comment|/* Transport Detail Element */
name|I2O_SGE_TRANSPORT_ELEMENT
name|Transport
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|u
argument_list|)
operator|)
comment|// there is a macro defined in Solaris sys/user.h for u, rename this to uSG
block|}
name|uSG
union|;
else|#
directive|else
block|}
name|u
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_operator
unit|} I2O_SG_ELEMENT
operator|,
end_operator

begin_expr_stmt
operator|*
name|PI2O_SG_ELEMENT
expr_stmt|;
end_expr_stmt

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Basic Parameter Group Access */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Operation Function Numbers */
end_comment

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_FIELD_GET
value|0x0001
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_LIST_GET
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_MORE_GET
value|0x0003
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_SIZE_GET
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_TABLE_GET
value|0x0005
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_FIELD_SET
value|0x0006
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_LIST_SET
value|0x0007
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_ROW_ADD
value|0x0008
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_ROW_DELETE
value|0x0009
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_OPERATION_TABLE_CLEAR
value|0x000A
end_define

begin_comment
comment|/* Operations List Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATIONS_LIST_HEADER
block|{
name|U16
name|OperationCount
decl_stmt|;
name|U16
name|Reserved
decl_stmt|;
block|}
name|I2O_PARAM_OPERATIONS_LIST_HEADER
operator|,
typedef|*
name|PI2O_PARAM_OPERATIONS_LIST_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Results List Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_RESULTS_LIST_HEADER
block|{
name|U16
name|ResultCount
decl_stmt|;
name|U16
name|Reserved
decl_stmt|;
block|}
name|I2O_PARAM_RESULTS_LIST_HEADER
operator|,
typedef|*
name|PI2O_PARAM_RESULTS_LIST_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Read Operation Result Block Template Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_READ_OPERATION_RESULT
block|{
name|U16
name|BlockSize
decl_stmt|;
name|U8
name|BlockStatus
decl_stmt|;
name|U8
name|ErrorInfoSize
decl_stmt|;
comment|/*                          Operations Results          */
comment|/*                          Pad (if any)                */
comment|/*                          ErrorInformation (if any)   */
block|}
name|I2O_PARAM_READ_OPERATION_RESULT
operator|,
typedef|*
name|PI2O_PARAM_READ_OPERATION_RESULT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_I2O_TABLE_READ_OPERATION_RESULT
block|{
name|U16
name|BlockSize
decl_stmt|;
name|U8
name|BlockStatus
decl_stmt|;
name|U8
name|ErrorInfoSize
decl_stmt|;
name|U16
name|RowCount
decl_stmt|;
name|U16
name|MoreFlag
decl_stmt|;
comment|/*                          Operations Results          */
comment|/*                          Pad (if any)                */
comment|/*                          ErrorInformation (if any)   */
block|}
name|I2O_TABLE_READ_OPERATION_RESULT
operator|,
typedef|*
name|PI2O_TABLE_READ_OPERATION_RESULT
typedef|;
end_typedef

begin_comment
comment|/* Error Information Template Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_ERROR_INFO_TEMPLATE
block|{
name|U16
name|OperationCode
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|FieldIdx
decl_stmt|;
name|U8
name|AdditionalStatus
decl_stmt|;
name|U8
name|NumberKeys
decl_stmt|;
comment|/*                          List of Key Values (variable)   */
comment|/*                          Pad (if any)                    */
block|}
name|I2O_PARAM_ERROR_INFO_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_ERROR_INFO_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Operation Template for Specific Fields */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATION_SPECIFIC_TEMPLATE
block|{
name|U16
name|Operation
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|FieldCount
decl_stmt|;
name|U16
name|FieldIdx
index|[
literal|1
index|]
decl_stmt|;
comment|/*                          Pad (if any)                    */
block|}
name|I2O_PARAM_OPERATION_SPECIFIC_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_OPERATION_SPECIFIC_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Operation Template for All Fields */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATION_ALL_TEMPLATE
block|{
name|U16
name|Operation
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|FieldCount
decl_stmt|;
comment|/*                          Pad (if any)                    */
block|}
name|I2O_PARAM_OPERATION_ALL_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_OPERATION_ALL_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Operation Template for All List Fields */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATION_ALL_LIST_TEMPLATE
block|{
name|U16
name|Operation
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|FieldCount
decl_stmt|;
name|U16
name|KeyCount
decl_stmt|;
name|U8
name|KeyValue
decl_stmt|;
comment|/*                          Pad (if any)                    */
block|}
name|I2O_PARAM_OPERATION_ALL_LIST_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_OPERATION_ALL_LIST_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Modify Operation Result Block Template Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_MODIFY_OPERATION_RESULT
block|{
name|U16
name|BlockSize
decl_stmt|;
name|U8
name|BlockStatus
decl_stmt|;
name|U8
name|ErrorInfoSize
decl_stmt|;
comment|/*                          ErrorInformation (if any)   */
block|}
name|I2O_PARAM_MODIFY_OPERATION_RESULT
operator|,
typedef|*
name|PI2O_PARAM_MODIFY_OPERATION_RESULT
typedef|;
end_typedef

begin_comment
comment|/* Operation Template for Row Delete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATION_ROW_DELETE_TEMPLATE
block|{
name|U16
name|Operation
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|RowCount
decl_stmt|;
name|U8
name|KeyValue
decl_stmt|;
block|}
name|I2O_PARAM_OPERATION_ROW_DELETE_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_OPERATION_ROW_DELETE_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Operation Template for Table Clear  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_PARAM_OPERATION_TABLE_CLEAR_TEMPLATE
block|{
name|U16
name|Operation
decl_stmt|;
name|U16
name|GroupNumber
decl_stmt|;
block|}
name|I2O_PARAM_OPERATION_TABLE_CLEAR_TEMPLATE
operator|,
typedef|*
name|PI2O_PARAM_OPERATION_TABLE_CLEAR_TEMPLATE
typedef|;
end_typedef

begin_comment
comment|/* Status codes and Error Information for Parameter functions */
end_comment

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_BAD_KEY_ABORT
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_BAD_KEY_CONTINUE
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_BUFFER_FULL
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_BUFFER_TOO_SMALL
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_FIELD_UNREADABLE
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_FIELD_UNWRITEABLE
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_INSUFFICIENT_FIELDS
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_INVALID_GROUP_ID
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_INVALID_OPERATION
value|0x09
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_NO_KEY_FIELD
value|0x0A
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_NO_SUCH_FIELD
value|0x0B
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_NON_DYNAMIC_GROUP
value|0x0C
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_OPERATION_ERROR
value|0x0D
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_SCALAR_ERROR
value|0x0E
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_TABLE_ERROR
value|0x0F
end_define

begin_define
define|#
directive|define
name|I2O_PARAMS_STATUS_WRONG_GROUP_TYPE
value|0x10
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* GROUP Parameter Groups */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* GROUP Configuration and Operating Structures and Defines */
end_comment

begin_comment
comment|/* Groups Numbers */
end_comment

begin_define
define|#
directive|define
name|I2O_UTIL_PARAMS_DESCRIPTOR_GROUP_NO
value|0xF000
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_PHYSICAL_DEVICE_TABLE_GROUP_NO
value|0xF001
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_CLAIMED_TABLE_GROUP_NO
value|0xF002
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_USER_TABLE_GROUP_NO
value|0xF003
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_PRIVATE_MESSAGE_EXTENSIONS_GROUP_NO
value|0xF005
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_AUTHORIZED_USER_TABLE_GROUP_NO
value|0xF006
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_DEVICE_IDENTITY_GROUP_NO
value|0xF100
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_DDM_IDENTITY_GROUP_NO
value|0xF101
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_USER_INFORMATION_GROUP_NO
value|0xF102
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_SGL_OPERATING_LIMITS_GROUP_NO
value|0xF103
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_SENSORS_GROUP_NO
value|0xF200
end_define

begin_comment
comment|/* UTIL Group F000h - GROUP DESCRIPTORS Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_UTIL_GROUP_PROPERTIES_GROUP_TABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_GROUP_PROPERTIES_ROW_ADDITION
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_GROUP_PROPERTIES_ROW_DELETION
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_GROUP_PROPERTIES_CLEAR_OPERATION
value|0x08
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_GROUP_DESCRIPTOR_TABLE
block|{
name|U16
name|GroupNumber
decl_stmt|;
name|U16
name|FieldCount
decl_stmt|;
name|U16
name|RowCount
decl_stmt|;
name|U8
name|Properties
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
block|}
name|I2O_UTIL_GROUP_DESCRIPTOR_TABLE
operator|,
typedef|*
name|PI2O_UTIL_GROUP_DESCRIPTOR_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F001h - Physical Device Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_PHYSICAL_DEVICE_TABLE
block|{
name|U32
name|AdapterID
decl_stmt|;
block|}
name|I2O_UTIL_PHYSICAL_DEVICE_TABLE
operator|,
typedef|*
name|PI2O_UTIL_PHYSICAL_DEVICE_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F002h - Claimed Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_CLAIMED_TABLE
block|{
name|U16
name|ClaimedTID
decl_stmt|;
block|}
name|I2O_UTIL_CLAIMED_TABLE
operator|,
typedef|*
name|PI2O_UTIL_CLAIMED_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F003h - User Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_USER_TABLE
block|{
name|U16
name|Instance
decl_stmt|;
name|U16
name|UserTID
decl_stmt|;
name|U8
name|ClaimType
decl_stmt|;
name|U8
name|reserved1
decl_stmt|;
name|U16
name|reserved2
decl_stmt|;
block|}
name|I2O_UTIL_USER_TABLE
operator|,
typedef|*
name|PI2O_UTIL_USER_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F005h - Private Message Extensions Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_PRIVATE_MESSAGE_EXTENSIONS_TABLE
block|{
name|U16
name|ExtInstance
decl_stmt|;
name|U16
name|OrganizationID
decl_stmt|;
name|U16
name|XFunctionCode
decl_stmt|;
block|}
name|I2O_UTIL_PRIVATE_MESSAGE_EXTENSIONS_TABLE
operator|,
typedef|*
name|PI2O_UTIL_PRIVATE_MESSAGE_EXTENSIONS_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F006h - Authorized User Table Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_AUTHORIZED_USER_TABLE
block|{
name|U16
name|AlternateTID
decl_stmt|;
block|}
name|I2O_UTIL_AUTHORIZED_USER_TABLE
operator|,
typedef|*
name|PI2O_UTIL_AUTHORIZED_USER_TABLE
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F100h - Device Identity Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_DEVICE_IDENTITY_SCALAR
block|{
name|U32
name|ClassID
decl_stmt|;
name|U16
name|OwnerTID
decl_stmt|;
name|U16
name|ParentTID
decl_stmt|;
name|U8
name|VendorInfo
index|[
name|I2O_DEVID_VENDOR_INFO_SZ
index|]
decl_stmt|;
name|U8
name|ProductInfo
index|[
name|I2O_DEVID_PRODUCT_INFO_SZ
index|]
decl_stmt|;
name|U8
name|Description
index|[
name|I2O_DEVID_DESCRIPTION_SZ
index|]
decl_stmt|;
name|U8
name|ProductRevLevel
index|[
name|I2O_DEVID_REV_LEVEL_SZ
index|]
decl_stmt|;
name|U8
name|SNFormat
decl_stmt|;
name|U8
name|SerialNumber
index|[
name|I2O_MAX_SERIAL_NUMBER_SZ
index|]
decl_stmt|;
block|}
name|I2O_UTIL_DEVICE_IDENTITY_SCALAR
operator|,
typedef|*
name|PI2O_UTIL_DEVICE_IDENTITY_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F101h - DDM Identity Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_DDM_IDENTITY_SCALAR
block|{
name|U16
name|DdmTID
decl_stmt|;
name|U8
name|ModuleName
index|[
name|I2O_MODULE_NAME_SZ
index|]
decl_stmt|;
name|U8
name|ModuleRevLevel
index|[
name|I2O_DEVID_REV_LEVEL_SZ
index|]
decl_stmt|;
name|U8
name|SNFormat
decl_stmt|;
name|U8
name|SerialNumber
index|[
name|I2O_MAX_SERIAL_NUMBER_SZ
index|]
decl_stmt|;
block|}
name|I2O_UTIL_DDM_IDENTITY_SCALAR
operator|,
typedef|*
name|PI2O_UTIL_DDM_IDENTITY_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F102h - User Information Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_USER_DEVICE_NAME_SZ
value|64
end_define

begin_define
define|#
directive|define
name|I2O_USER_SERVICE_NAME_SZ
value|64
end_define

begin_define
define|#
directive|define
name|I2O_USER_PHYSICAL_LOCATION_SZ
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_USER_INFORMATION_SCALAR
block|{
name|U8
name|DeviceName
index|[
name|I2O_USER_DEVICE_NAME_SZ
index|]
decl_stmt|;
name|U8
name|ServiceName
index|[
name|I2O_USER_SERVICE_NAME_SZ
index|]
decl_stmt|;
name|U8
name|PhysicalLocation
index|[
name|I2O_USER_PHYSICAL_LOCATION_SZ
index|]
decl_stmt|;
name|U32
name|InstanceNumber
decl_stmt|;
block|}
name|I2O_UTIL_USER_INFORMATION_SCALAR
operator|,
typedef|*
name|PI2O_UTIL_USER_INFORMATION_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F103h - SGL Operating Limits Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_SGL_OPERATING_LIMITS_SCALAR
block|{
name|U32
name|SglChainSize
decl_stmt|;
name|U32
name|SglChainSizeMax
decl_stmt|;
name|U32
name|SglChainSizeTarget
decl_stmt|;
name|U16
name|SglFragCount
decl_stmt|;
name|U16
name|SglFragCountMax
decl_stmt|;
name|U16
name|SglFragCountTarget
decl_stmt|;
block|}
name|I2O_UTIL_SGL_OPERATING_LIMITS_SCALAR
operator|,
typedef|*
name|PI2O_UTIL_SGL_OPERATING_LIMITS_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* UTIL Group F200h - Sensors Parameter Group */
end_comment

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_PLANAR_LOGIC_BOARD
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_CPU
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_CHASSIS
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_POWER_SUPPLY
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_STORAGE
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_COMPONENT_EXTERNAL
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_CLASS_ANALOG
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_CLASS_DIGITAL
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_THERMAL
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_DC_VOLTAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_AC_VOLTAGE
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_DC_CURRENT
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_AC_CURRENT
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_DOOR_OPEN
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_TYPE_FAN_OPERATIONAL
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_ABNORMAL
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_LOW_CAT
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_LOW
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_LOW_WARNING
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_HIGH_WARNING
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_HIGH
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_SENSOR_STATE_HIGH_CAT
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_STATE_CHANGE
value|0x0001
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_LOW_CATASTROPHIC
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_LOW_READING
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_LOW_WARNING
value|0x0008
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_CHANGE_TO_NORMAL
value|0x0010
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_HIGH_WARNING
value|0x0020
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_HIGH_READING
value|0x0040
end_define

begin_define
define|#
directive|define
name|I2O_SENSOR_EVENT_ENABLE_HIGH_CATASTROPHIC
value|0x0080
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_SENSORS_TABLE
block|{
name|U16
name|SensorInstance
decl_stmt|;
name|U8
name|Component
decl_stmt|;
name|U16
name|ComponentInstance
decl_stmt|;
name|U8
name|SensorClass
decl_stmt|;
name|U8
name|SensorType
decl_stmt|;
name|S8
name|ScalingExponent
decl_stmt|;
name|S32
name|ActualReading
decl_stmt|;
name|S32
name|MinimumReading
decl_stmt|;
name|S32
name|Low2LowCatThreshold
decl_stmt|;
name|S32
name|LowCat2LowThreshold
decl_stmt|;
name|S32
name|LowWarn2LowThreshold
decl_stmt|;
name|S32
name|Low2LowWarnThreshold
decl_stmt|;
name|S32
name|Norm2LowWarnThreshold
decl_stmt|;
name|S32
name|LowWarn2NormThreshold
decl_stmt|;
name|S32
name|NominalReading
decl_stmt|;
name|S32
name|HiWarn2NormThreshold
decl_stmt|;
name|S32
name|Norm2HiWarnThreshold
decl_stmt|;
name|S32
name|High2HiWarnThreshold
decl_stmt|;
name|S32
name|HiWarn2HighThreshold
decl_stmt|;
name|S32
name|HiCat2HighThreshold
decl_stmt|;
name|S32
name|Hi2HiCatThreshold
decl_stmt|;
name|S32
name|MaximumReading
decl_stmt|;
name|U8
name|SensorState
decl_stmt|;
name|U16
name|EventEnable
decl_stmt|;
block|}
name|I2O_UTIL_SENSORS_TABLE
operator|,
typedef|*
name|PI2O_UTIL_SENSORS_TABLE
typedef|;
end_typedef

begin_expr_stmt
name|PRAGMA_PACK_POP
name|PRAGMA_ALIGN_POP
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I2O_MESSAGE_HDR */
end_comment

end_unit

