begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corproation.  * All rights reserved.  *   * Copyright 1999 I2O Special Interest Group (I2O SIG).  All rights reserved.  * All rights reserved  *   * TERMS AND CONDITIONS OF USE  *   * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *   * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *   * This header file, and any modifications of this header file, are provided  * contingent upon your agreement and adherence to the here-listed terms and  * conditions.  By accepting and/or using this header file, you agree to abide  * by these terms and conditions and that these terms and conditions will be  * construed and governed in accordance with the laws of the State of California,  * without reference to conflict-of-law provisions.  If you do not agree  * to these terms and conditions, please delete this file, and any copies,  * permanently, without making any use thereof.  *   * THIS HEADER FILE IS PROVIDED FREE OF CHARGE ON AN AS-IS BASIS WITHOUT  * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  * TO IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE.  I2O SIG DOES NOT WARRANT THAT THIS HEADER FILE WILL MEET THE  * USER'S REQUIREMENTS OR THAT ITS OPERATION WILL BE UNINTERRUPTED OR  * ERROR-FREE.  *   * I2O SIG DISCLAIMS ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF  * ANY PROPRIETARY RIGHTS, RELATING TO THE IMPLEMENTATION OF THE I2O  * SPECIFICATIONS.  I2O SIG DOES NOT WARRANT OR REPRESENT THAT SUCH  * IMPLEMENTATIONS WILL NOT INFRINGE SUCH RIGHTS.  *   * THE USER OF THIS HEADER FILE SHALL HAVE NO RECOURSE TO I2O SIG FOR ANY  * ACTUAL OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT LIMITED TO, LOST DATA  * OR LOST PROFITS ARISING OUT OF THE USE OR INABILITY TO USE THIS PROGRAM.  *   * I2O SIG grants the user of this header file a license to copy, distribute,  * and modify it, for any purpose, under the following terms.  Any copying,  * distribution, or modification of this header file must not delete or alter  * the copyright notice of I2O SIG or any of these Terms and Conditions.  *   * Any distribution of this header file must not include a charge for the  * header file (unless such charges are strictly for the physical acts of  * copying or transferring copies).  However, distribution of a product in  * which this header file is embedded may include a charge so long as any  * such charge does not include any charge for the header file itself.  *   * Any modification of this header file constitutes a derivative work based  * on this header file.  Any distribution of such derivative work: (1) must  * include prominent notices that the header file has been changed from the  * original, together with the dates of any changes; (2) automatically includes   * this same license to the original header file from I2O SIG, without any  * restriction thereon from the distributing user; and (3) must include a  * grant of license of the modified file under the same terms and conditions  * as these Terms and Conditions.  *   * The I2O SIG Web site can be found at: http://www.i2osig.org  *   * The I2O SIG encourages you to deposit derivative works based on this  * header file at the I2O SIG Web site.  Furthermore, to become a Registered  * Developer of the I2O SIG, sign up at the Web site or call 415.750.8352  * (United States).  ****************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_ADPTR_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_ADPTR_HDR
end_define

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

begin_define
define|#
directive|define
name|I2OADPTR_REV
value|1_5_1
end_define

begin_comment
comment|/* Header file revision string */
end_comment

begin_comment
comment|/*****************************************************************************  *  *    i2oadptr.h -- I2O Adapter Class Message defintion file  *  *  *  Revision History:  *  *  1.5.d   03/06/97 - First definition for spec. draft version 1.5d.  *  1.5.1   05/02/97 - Corrections from review cycle:  *          1) Remove "SCSI" from function definition comment.  *          2) Add revision string.  *          3) Convert tabs to spaces.  *          4) New disclaimer.  *  *                *  *****************************************************************************/
end_comment

begin_comment
comment|/*     NOTES:          Gets, reads, receives, etc. are all even numbered functions.     Sets, writes, sends, etc. are all odd numbered functions.     Functions that both send and receive data can be either but an attempt is made     to use the function number that indicates the greater transfer amount.     Functions that do not send or receive data use odd function numbers.      Some functions are synonyms like read, receive and send, write.          All common functions will have a code of less than 0x80.     Unique functions to a class will start at 0x80.     Executive Functions start at 0xA0.          Utility Message function codes range from 0 - 0x1f     Base Message function codes range from 0x20 - 0xfe     Private Message function code is 0xff. */
end_comment

begin_expr_stmt
name|PRAGMA_ALIGN_PUSH
name|PRAGMA_PACK_PUSH
end_expr_stmt

begin_comment
comment|/*     Bus Adapter Class specific functions */
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_ADAPTER_RESET
value|0x85
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE
value|0x8b
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_RESET
value|0x87
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_SCAN
value|0x89
end_define

begin_comment
comment|/*     Detailed Status Codes for HBA operations      Note:     The 16-bit Detailed Status Code field for HBA operations is divided      into two separate 8-bit fields.  The lower 8 bits are reserved.  The      upper 8 bits are used to report Adapter Status information.  The      definitions for these two fields, however, will be consistent with      the standard reply message frame structure declaration, which treats      this as a single 16-bit field.  In addition, the values used will be     consistent with the Adapter Status codes defined for the SCSI      Peripheral class.  Theses codes are based on CAM-1.  In other words,     these definitions are a subset of the SCSI peripheral class codes.     Where applicable, "SCSI" has been removed from the definition. */
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_DSC_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_ADAPTER_BUSY
value|0x0500
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_COMMAND_TIMEOUT
value|0x0B00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_COMPLETE_WITH_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_FUNCTION_UNAVAILABLE
value|0x3A00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_NO_ADAPTER
value|0x1100
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_PARITY_ERROR_FAILURE
value|0x0F00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_PATH_INVALID
value|0x0700
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_PROVIDE_FAILURE
value|0x1600
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_QUEUE_FROZEN
value|0x4000
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_REQUEST_ABORTED
value|0x0200
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_REQUEST_INVALID
value|0x0600
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_REQUEST_LENGTH_ERROR
value|0x1500
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_REQUEST_TERMINATED
value|0x1800
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_RESOURCE_UNAVAILABLE
value|0x3400
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_BUS_BUSY
value|0x3F00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_BUS_RESET
value|0x0E00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_ID_INVALID
value|0x3900
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_SEQUENCE_FAILURE
value|0x1400
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_UNABLE_TO_ABORT
value|0x0300
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_UNABLE_TO_TERMINATE
value|0x0900
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_UNACKNOWLEDGED_EVENT
value|0x3500
end_define

begin_define
define|#
directive|define
name|I2O_HBA_DSC_UNEXPECTED_BUS_FREE
value|0x1300
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Bus Adapter Parameter Groups */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_CONTROLLER_INFO_GROUP_NO
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_HBA_HISTORICAL_STATS_GROUP_NO
value|0x0100
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_GROUP_NO
value|0x0200
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_BUS_PORT_INFO_GROUP_NO
value|0x0201
end_define

begin_define
define|#
directive|define
name|I2O_HBA_FCA_CONTROLLER_INFO_GROUP_NO
value|0x0300
end_define

begin_define
define|#
directive|define
name|I2O_HBA_FCA_PORT_INFO_GROUP_NO
value|0x0301
end_define

begin_comment
comment|/* - 0000h - HBA Controller Information Parameter Group */
end_comment

begin_comment
comment|/* Bus Type */
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_BUS_TYPE_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_TYPE_SCSI
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_TYPE_FCA
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_CONTROLLER_INFO_SCALAR
block|{
name|U8
name|BusType
decl_stmt|;
name|U8
name|BusState
decl_stmt|;
name|U16
name|Reserved2
decl_stmt|;
name|U8
name|BusName
index|[
literal|12
index|]
decl_stmt|;
block|}
name|I2O_HBA_CONTROLLER_INFO_SCALAR
operator|,
typedef|*
name|PI2O_HBA_CONTROLLER_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* - 0100h - HBA Historical Stats Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_HIST_STATS_SCALAR
block|{
name|U32
name|TimeLastPoweredUp
decl_stmt|;
name|U32
name|TimeLastReset
decl_stmt|;
block|}
name|I2O_HBA_HIST_STATS_SCALAR
operator|,
typedef|*
name|PI2O_HBA_HIST_STATS_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* - 0200h - HBA SCSI Controller Information Parameter Group */
end_comment

begin_comment
comment|/* SCSI Type */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_TYPE_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_TYPE_SCSI_1
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_TYPE_SCSI_2
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_TYPE_SCSI_3
value|0x03
end_define

begin_comment
comment|/* Protection Management */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PROT_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PROT_UNKNOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PROT_UNPROTECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PROT_PROTECTED
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PROT_SCC
value|0x04
end_define

begin_comment
comment|/* Settings */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PARITY_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PARITY_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PARITY_ENABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAN_ORDER_FLAG
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAN_LOW_TO_HIGH
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAN_HIGH_TO_LOW
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_IID_FLAG
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_IID_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_IID_SPECIFIED
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAM_FLAG
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAM_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_SCAM_ENABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_TYPE_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_TYPE_PARALLEL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_TYPE_SERIAL
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR
block|{
name|U8
name|SCSIType
decl_stmt|;
name|U8
name|ProtectionManagement
decl_stmt|;
name|U8
name|Settings
decl_stmt|;
name|U8
name|Reserved1
decl_stmt|;
name|U32
name|InitiatorID
decl_stmt|;
name|U64
name|ScanLun0Only
decl_stmt|;
name|U16
name|DisableDevice
decl_stmt|;
name|U8
name|MaxOffset
decl_stmt|;
name|U8
name|MaxDataWidth
decl_stmt|;
name|U64
name|MaxSyncRate
decl_stmt|;
block|}
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR
operator|,
typedef|*
name|PI2O_HBA_SCSI_CONTROLLER_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* - 0201h - HBA SCSI Bus Port Information Parameter Group */
end_comment

begin_comment
comment|/*  NOTE:   Refer to the SCSI Peripheral Class Bus Port Information Parameter             Group field definitions for HBA SCSI Bus Port field definitions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_SCSI_BUS_PORT_INFO_SCALAR
block|{
name|U8
name|PhysicalInterface
decl_stmt|;
name|U8
name|ElectricalInterface
decl_stmt|;
name|U8
name|Isochronous
decl_stmt|;
name|U8
name|ConnectorType
decl_stmt|;
name|U8
name|ConnectorGender
decl_stmt|;
name|U8
name|Reserved1
decl_stmt|;
name|U16
name|Reserved2
decl_stmt|;
name|U32
name|MaxNumberDevices
decl_stmt|;
name|U32
name|DeviceIdBegin
decl_stmt|;
name|U32
name|DeviceIdEnd
decl_stmt|;
name|U8
name|LunBegin
index|[
literal|8
index|]
decl_stmt|;
name|U8
name|LunEnd
index|[
literal|8
index|]
decl_stmt|;
block|}
name|I2O_HBA_SCSI_BUS_PORT_INFO_SCALAR
operator|,
typedef|*
name|PI2O_HBA_SCSI_BUS_PORT_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* - 0300h - HBA FCA Controller Information Parameters Group defines */
end_comment

begin_comment
comment|/* SCSI Type */
end_comment

begin_define
define|#
directive|define
name|I2O_FCA_TYPE_UNKNOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_FCA_TYPE_FCAL
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_FCA_CONTROLLER_INFO_SCALAR
block|{
name|U8
name|FcaType
decl_stmt|;
name|U8
name|Reserved1
decl_stmt|;
name|U16
name|Reserved2
decl_stmt|;
block|}
name|I2O_HBA_FCA_CONTROLLER_INFO_SCALAR
operator|,
typedef|*
name|PI2O_HBA_FCA_CONTROLLER_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* - 0301h - HBA FCA Port Information Parameters Group defines */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_FCA_PORT_INFO_SCALAR
block|{
name|U32
name|Reserved4
decl_stmt|;
block|}
name|I2O_HBA_FCA_PORT_INFO_SCALAR
operator|,
typedef|*
name|PI2O_HBA_FCA_PORT_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Bus Adapter Class Specific Message Definitions */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O Bus Adapter Class Reply Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_REPLY_MESSAGE_FRAME
block|{
name|I2O_SINGLE_REPLY_MESSAGE_FRAME
name|StdReplyFrame
decl_stmt|;
block|}
name|I2O_HBA_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_HBA_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O HBA Adapter Reset Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_ADAPTER_RESET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_HBA_ADAPTER_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_HBA_ADAPTER_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O HBA Bus Quiesce Message Frame */
end_comment

begin_typedef
typedef|typedef
name|U32
name|I2O_HBQ_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_HBQ_FLAG_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_HBQ_FLAG_QUIESCE
value|0x0001
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_BUS_QUIESCE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_HBQ_FLAGS
name|Flags
decl_stmt|;
block|}
name|I2O_HBA_BUS_QUIESCE_MESSAGE
operator|,
typedef|*
name|PI2O_HBA_BUS_QUIESCE_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O HBA Bus Reset Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_BUS_RESET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_HBA_BUS_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_HBA_BUS_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O HBA Bus Scan Message Frame */
end_comment

begin_comment
comment|/* NOTE: SCSI-2 8-bit scalar LUN goes into offset 1 of Lun arrays */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_HBA_BUS_SCAN_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_HBA_BUS_SCAN_MESSAGE
operator|,
typedef|*
name|PI2O_HBA_BUS_SCAN_MESSAGE
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
comment|/* I2O_ADPTR_HDR */
end_comment

end_unit

