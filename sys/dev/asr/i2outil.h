begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *   * Copyright 1999 I2O Special Interest Group (I2O SIG).  All rights reserved.  * All rights reserved  *   * TERMS AND CONDITIONS OF USE  *   * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *   * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *   * This header file, and any modifications of this header file, are provided  * contingent upon your agreement and adherence to the here-listed terms and  * conditions.  By accepting and/or using this header file, you agree to abide  * by these terms and conditions and that these terms and conditions will be  * construed and governed in accordance with the laws of the State of California,  * without reference to conflict-of-law provisions.  If you do not agree  * to these terms and conditions, please delete this file, and any copies,  * permanently, without making any use thereof.  *   * THIS HEADER FILE IS PROVIDED FREE OF CHARGE ON AN AS-IS BASIS WITHOUT  * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  * TO IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE.  I2O SIG DOES NOT WARRANT THAT THIS HEADER FILE WILL MEET THE  * USER'S REQUIREMENTS OR THAT ITS OPERATION WILL BE UNINTERRUPTED OR  * ERROR-FREE.  *   * I2O SIG DISCLAIMS ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF  * ANY PROPRIETARY RIGHTS, RELATING TO THE IMPLEMENTATION OF THE I2O  * SPECIFICATIONS.  I2O SIG DOES NOT WARRANT OR REPRESENT THAT SUCH  * IMPLEMENTATIONS WILL NOT INFRINGE SUCH RIGHTS.  *   * THE USER OF THIS HEADER FILE SHALL HAVE NO RECOURSE TO I2O SIG FOR ANY  * ACTUAL OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT LIMITED TO, LOST DATA  * OR LOST PROFITS ARISING OUT OF THE USE OR INABILITY TO USE THIS PROGRAM.  *   * I2O SIG grants the user of this header file a license to copy, distribute,  * and modify it, for any purpose, under the following terms.  Any copying,  * distribution, or modification of this header file must not delete or alter  * the copyright notice of I2O SIG or any of these Terms and Conditions.  *   * Any distribution of this header file must not include a charge for the  * header file (unless such charges are strictly for the physical acts of  * copying or transferring copies).  However, distribution of a product in  * which this header file is embedded may include a charge so long as any  * such charge does not include any charge for the header file itself.  *   * Any modification of this header file constitutes a derivative work based  * on this header file.  Any distribution of such derivative work: (1) must  * include prominent notices that the header file has been changed from the  * original, together with the dates of any changes; (2) automatically includes   * this same license to the original header file from I2O SIG, without any  * restriction thereon from the distributing user; and (3) must include a  * grant of license of the modified file under the same terms and conditions  * as these Terms and Conditions.  *   * The I2O SIG Web site can be found at: http://www.i2osig.org  *   * The I2O SIG encourages you to deposit derivative works based on this  * header file at the I2O SIG Web site.  Furthermore, to become a Registered  * Developer of the I2O SIG, sign up at the Web site or call 415.750.8352  * (United States).  ****************************************************************/
end_comment

begin_comment
comment|/*********************************************************************  * I2OUtil.h -- I2O Utility Class Message defintion file  *  * This file contains information presented in Chapter 6 of the I2O  * Specification.  **********************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_UTILITY_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_UTILITY_HDR
end_define

begin_define
define|#
directive|define
name|I2OUTIL_REV
value|1_5_4
end_define

begin_comment
comment|/* I2OUtil header file revision string */
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
file|"i386/pci/i2omsg.h"
end_include

begin_comment
comment|/* Include the Base Message file */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dev/asr/i2omsg.h"
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTES:     Gets, reads, receives, etc. are all even numbered functions.    Sets, writes, sends, etc. are all odd numbered functions.    Functions that both send and receive data can be either but an attempt is made        to use the function number that indicates the greater transfer amount.    Functions that do not send or receive data use odd function numbers.     Some functions are synonyms like read, receive and send, write.     All common functions will have a code of less than 0x80.    Unique functions to a class will start at 0x80.    Executive Functions start at 0xA0.     Utility Message function codes range from 0 - 0x1f    Base Message function codes range from 0x20 - 0xfe    Private Message function code is 0xff. */
end_comment

begin_expr_stmt
name|PRAGMA_ALIGN_PUSH
name|PRAGMA_PACK_PUSH
end_expr_stmt

begin_comment
comment|/* Utility Message class functions. */
end_comment

begin_define
define|#
directive|define
name|I2O_UTIL_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_ABORT
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_CLAIM
value|0x09
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_CLAIM_RELEASE
value|0x0B
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_CONFIG_DIALOG
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_DEVICE_RESERVE
value|0x0D
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_DEVICE_RELEASE
value|0x0F
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_EVENT_ACKNOWLEDGE
value|0x14
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_EVENT_REGISTER
value|0x13
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_LOCK
value|0x17
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_LOCK_RELEASE
value|0x19
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_PARAMS_GET
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_PARAMS_SET
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_REPLY_FAULT_NOTIFY
value|0x15
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* ABORT Abort type defines. */
end_comment

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_EXACT_ABORT
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_FUNCTION_ABORT
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_TRANSACTION_ABORT
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_WILD_ABORT
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_CLEAN_EXACT_ABORT
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_CLEAN_FUNCTION_ABORT
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_CLEAN_TRANSACTION_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_ABORT_TYPE_CLEAN_WILD_ABORT
value|0x07
end_define

begin_comment
comment|/* UtilAbort Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_ABORT_MESSAGE
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
name|reserved
decl_stmt|;
else|#
directive|else
name|U16
name|reserved
decl_stmt|;
name|U8
name|AbortType
decl_stmt|;
name|U8
name|FunctionToAbort
decl_stmt|;
endif|#
directive|endif
name|I2O_TRANSACTION_CONTEXT
name|TransactionContextToAbort
decl_stmt|;
block|}
name|I2O_UTIL_ABORT_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_ABORT_MESSAGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_ABORT_REPLY
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|CountOfAbortedMessages
decl_stmt|;
block|}
name|I2O_UTIL_ABORT_REPLY
operator|,
typedef|*
name|PI2O_UTIL_ABORT_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Claim Flag defines */
end_comment

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_EXCLUSIVE
value|0x0001
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_RESET_SENSITIVE
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_STATE_SENSITIVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_CAPACITY_SENSITIVE
value|0x0008
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_PEER_SERVICE_DISABLED
value|0x0010
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_FLAGS_MGMT_SERVICE_DISABLED
value|0x0020
end_define

begin_comment
comment|/* Claim Type defines */
end_comment

begin_define
define|#
directive|define
name|I2O_CLAIM_TYPE_PRIMARY_USER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_TYPE_AUTHORIZED_USER
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_TYPE_SECONDARY_USER
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_CLAIM_TYPE_MANAGEMENT_USER
value|0x04
end_define

begin_comment
comment|/* UtilClaim Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_CLAIM_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U16
name|ClaimFlags
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|ClaimType
decl_stmt|;
block|}
name|I2O_UTIL_CLAIM_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_CLAIM_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Claim Release Flag defines */
end_comment

begin_define
define|#
directive|define
name|I2O_RELEASE_FLAGS_CONDITIONAL
value|0x0001
end_define

begin_comment
comment|/* UtilClaimRelease Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_CLAIM_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U16
name|ReleaseFlags
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|ClaimType
decl_stmt|;
block|}
name|I2O_UTIL_CLAIM_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_CLAIM_RELEASE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  UtilConfigDialog Function Message Frame structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_CONFIG_DIALOG_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|PageNumber
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_UTIL_CONFIG_DIALOG_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_CONFIG_DIALOG_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Event Acknowledge Function Message Frame structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_EVENT_ACK_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|EventIndicator
decl_stmt|;
name|U32
name|EventData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_UTIL_EVENT_ACK_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_EVENT_ACK_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* Event Ack Reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_EVENT_ACK_REPLY
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|EventIndicator
decl_stmt|;
name|U32
name|EventData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_UTIL_EVENT_ACK_REPLY
operator|,
typedef|*
name|PI2O_UTIL_EVENT_ACK_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Event Indicator Mask Flags */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_IND_STATE_CHANGE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_GENERAL_WARNING
value|0x40000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_CONFIGURATION_FLAG
value|0x20000000
end_define

begin_comment
comment|/* #define    I2O_EVENT_IND_RESERVE_RELEASE               0x10000000 */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_IND_LOCK_RELEASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_CAPABILITY_CHANGE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_DEVICE_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_EVENT_MASK_MODIFIED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_FIELD_MODIFIED
value|0x01000000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_VENDOR_EVENT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_IND_DEVICE_STATE
value|0x00400000
end_define

begin_comment
comment|/* Event Data for generic Events */
end_comment

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_SUSPENDED
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_RESTART
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_NA_RECOVER
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_NA_NO_RECOVER
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_QUIESCE_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_FAILED
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_STATE_CHANGE_FAULTED
value|0x11
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_GEN_WARNING_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_GEN_WARNING_ERROR_THRESHOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_GEN_WARNING_MEDIA_FAULT
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_CAPABILITY_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_CAPABILITY_CHANGED
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_EVENT_SENSOR_STATE_CHANGED
value|0x01
end_define

begin_comment
comment|/*  UtilEventRegister Function Message Frame structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_EVENT_REGISTER_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|EventMask
decl_stmt|;
block|}
name|I2O_UTIL_EVENT_REGISTER_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_EVENT_REGISTER_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* UtilEventRegister Reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_EVENT_REGISTER_REPLY
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|EventIndicator
decl_stmt|;
name|U32
name|EventData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|I2O_UTIL_EVENT_REGISTER_REPLY
operator|,
typedef|*
name|PI2O_UTIL_EVENT_REGISTER_REPLY
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilLock Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_LOCK_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_UTIL_LOCK_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_LOCK_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilLockRelease Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_LOCK_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_UTIL_LOCK_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_LOCK_RELEASE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilNOP Function Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_NOP_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
block|}
name|I2O_UTIL_NOP_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_NOP_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilParamsGet Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_PARAMS_GET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|OperationFlags
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_UTIL_PARAMS_GET_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_PARAMS_GET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilParamsSet Message Frame structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_PARAMS_SET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U32
name|OperationFlags
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_UTIL_PARAMS_SET_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_PARAMS_SET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* UtilReplyFaultNotify Message for Message Failure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_REPLY_FAULT_NOTIFY_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|LowestVersion
decl_stmt|;
name|U8
name|HighestVersion
decl_stmt|;
name|BF
name|Severity
range|:
name|I2O_FAILCODE_SEVERITY_SZ
decl_stmt|;
name|BF
name|FailureCode
range|:
name|I2O_FAILCODE_CODE_SZ
decl_stmt|;
name|BF
name|FailingIOP_ID
range|:
name|I2O_IOP_ID_SZ
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
name|U32
name|AgeLimit
decl_stmt|;
if|#
directive|if
name|I2O_64BIT_CONTEXT
name|PI2O_MESSAGE_FRAME
name|OriginalMFA
decl_stmt|;
else|#
directive|else
name|PI2O_MESSAGE_FRAME
name|OriginalMFALowPart
decl_stmt|;
name|U32
name|OriginalMFAHighPart
decl_stmt|;
comment|/* Always 0000 */
endif|#
directive|endif
block|}
name|I2O_UTIL_REPLY_FAULT_NOTIFY_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_REPLY_FAULT_NOTIFY_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Device Reserve Function Message Frame structure. */
end_comment

begin_comment
comment|/* NOTE:  This was previously called the Reserve Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_DEVICE_RESERVE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_UTIL_DEVICE_RESERVE_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_DEVICE_RESERVE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Device Release Function Message Frame structure. */
end_comment

begin_comment
comment|/* NOTE:  This was previously called the ReserveRelease Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_UTIL_DEVICE_RELEASE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_UTIL_DEVICE_RELEASE_MESSAGE
operator|,
typedef|*
name|PI2O_UTIL_DEVICE_RELEASE_MESSAGE
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
comment|/* I2O_UTILITY_HDR  */
end_comment

end_unit

