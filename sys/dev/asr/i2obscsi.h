begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *  * Copyright 1999 I2O Special Interest Group (I2O SIG).  All rights reserved.  * All rights reserved  *  * TERMS AND CONDITIONS OF USE  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  * This header file, and any modifications of this header file, are provided  * contingent upon your agreement and adherence to the here-listed terms and  * conditions.  By accepting and/or using this header file, you agree to abide  * by these terms and conditions and that these terms and conditions will be  * construed and governed in accordance with the laws of the State of California,  * without reference to conflict-of-law provisions.  If you do not agree  * to these terms and conditions, please delete this file, and any copies,  * permanently, without making any use thereof.  *  * THIS HEADER FILE IS PROVIDED FREE OF CHARGE ON AN AS-IS BASIS WITHOUT  * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  * TO IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE.  I2O SIG DOES NOT WARRANT THAT THIS HEADER FILE WILL MEET THE  * USER'S REQUIREMENTS OR THAT ITS OPERATION WILL BE UNINTERRUPTED OR  * ERROR-FREE.  *  * I2O SIG DISCLAIMS ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF  * ANY PROPRIETARY RIGHTS, RELATING TO THE IMPLEMENTATION OF THE I2O  * SPECIFICATIONS.  I2O SIG DOES NOT WARRANT OR REPRESENT THAT SUCH  * IMPLEMENTATIONS WILL NOT INFRINGE SUCH RIGHTS.  *  * THE USER OF THIS HEADER FILE SHALL HAVE NO RECOURSE TO I2O SIG FOR ANY  * ACTUAL OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT LIMITED TO, LOST DATA  * OR LOST PROFITS ARISING OUT OF THE USE OR INABILITY TO USE THIS PROGRAM.  *  * I2O SIG grants the user of this header file a license to copy, distribute,  * and modify it, for any purpose, under the following terms.  Any copying,  * distribution, or modification of this header file must not delete or alter  * the copyright notice of I2O SIG or any of these Terms and Conditions.  *  * Any distribution of this header file must not include a charge for the  * header file (unless such charges are strictly for the physical acts of  * copying or transferring copies).  However, distribution of a product in  * which this header file is embedded may include a charge so long as any  * such charge does not include any charge for the header file itself.  *  * Any modification of this header file constitutes a derivative work based  * on this header file.  Any distribution of such derivative work: (1) must  * include prominent notices that the header file has been changed from the  * original, together with the dates of any changes; (2) automatically includes  * this same license to the original header file from I2O SIG, without any  * restriction thereon from the distributing user; and (3) must include a  * grant of license of the modified file under the same terms and conditions  * as these Terms and Conditions.  *  * The I2O SIG Web site can be found at: http://www.i2osig.org  *  * The I2O SIG encourages you to deposit derivative works based on this  * header file at the I2O SIG Web site.  Furthermore, to become a Registered  * Developer of the I2O SIG, sign up at the Web site or call 415.750.8352  * (United States).  ****************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|I2O_BASE_SCSI_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|I2O_BASE_SCSI_HDR
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

begin_define
define|#
directive|define
name|I2OBSCSI_REV
value|1_5_1
end_define

begin_comment
comment|/* Header file revision string */
end_comment

begin_comment
comment|/*****************************************************************************  *  *    I2OBSCSI.h -- I2O Base SCSI Device Class Message defintion file  *  *      This file contains information presented in Chapter 6, Section 6& 7 of  *      the I2O Specification.  *  *  Revision History: (Revision History tracks the revision number of the I2O  *          specification)  *  *      .92 - First marked revsion used for Proof of Concept.  *      .93 - Change to match the rev .93 of the spec.  *      .95 - Updated to Rev .95 of 2/5/96.  *     1.00 - Checked and Updated against spec version 1.00 4/9/96.  *     1.xx - Updated to the 1.x version of the I2O Specification on 11/11/96.  *     1.xx - 11/14/96  *            1) Removed duplicate device type definitions.  *            2) Added "DSC" to Detailed Status Code definitions.  *            3) Changed SCSI-3 LUN fields from U64 to U8 array.  *     1.xx   11/15/96 - Added #pragma statments for i960.  *     1.xx   11/20/96 - Changed duplicate Bus Scan structure to Bus Reset.  *     1.xx   12/05/96 - Added Auto Request Sense flag definition.  *     1.5d   03/06/97 - Update for spec. draft version 1.5d.  *            1) Converted SCSI bus adapter class to generic in i2oadptr.h.  *            2) Fixed DSC reference:  changed from _BUS_SCAN to _BUS_RESET.  *     1.5d   03/031/97 - Made AutoSense flag definition consistent with spec.  *     1.5d   04/11/97 - Corrections from review cycle:  *            1) Corrected typo in I2O_SCSI_PERIPHERAL_TYPE_PARALLEL.  *            2) Corrected typo in I2O_SCSI_PORT_CONN_UNSHIELDED_P_HD.  *     1.5.1  05/02/97 - Corrections from review cycle:  *            1) Remove #include for i2omstor.h.  *            2) Add revision string.  *            3) Convert tabs to spaces.  *            4) New disclaimer.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*     NOTES:      Gets, reads, receives, etc. are all even numbered functions.     Sets, writes, sends, etc. are all odd numbered functions.     Functions that both send and receive data can be either but an attempt is made     to use the function number that indicates the greater transfer amount.     Functions that do not send or receive data use odd function numbers.      Some functions are synonyms like read, receive and send, write.      All common functions will have a code of less than 0x80.     Unique functions to a class will start at 0x80.     Executive Functions start at 0xA0.      Utility Message function codes range from 0 - 0x1f     Base Message function codes range from 0x20 - 0xfe     Private Message function code is 0xff. */
end_comment

begin_expr_stmt
name|PRAGMA_ALIGN_PUSH
name|PRAGMA_PACK_PUSH
end_expr_stmt

begin_comment
comment|/*     SCSI Peripheral Class specific functions      Although the names are SCSI Peripheral class specific, the values     assigned are common with other classes when applicable. */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_RESET
value|0x27
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT
value|0x83
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXEC
value|0x81
end_define

begin_comment
comment|/*     Detailed Status Codes for SCSI operations      The 16-bit Detailed Status Code field for SCSI operations is divided     into two separate 8-bit fields.  The lower 8 bits are used to report     Device Status information.  The upper 8 bits are used to report     Adapter Status information.  The definitions for these two fields,     however, will be consistent with the standard reply message frame     structure declaration, which treats this as a single 16-bit field. */
end_comment

begin_comment
comment|/*  SCSI Device Completion Status Codes (defined by SCSI-2/3)*/
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_DSC_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_CHECK_CONDITION
value|0x0002
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_BUSY
value|0x0008
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_RESERVATION_CONFLICT
value|0x0018
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_COMMAND_TERMINATED
value|0x0022
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_TASK_SET_FULL
value|0x0028
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DSC_ACA_ACTIVE
value|0x0030
end_define

begin_comment
comment|/*  SCSI Adapter Status Codes (based on CAM-1) */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_REQUEST_ABORTED
value|0x0200
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_UNABLE_TO_ABORT
value|0x0300
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_COMPLETE_WITH_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_ADAPTER_BUSY
value|0x0500
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_REQUEST_INVALID
value|0x0600
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_PATH_INVALID
value|0x0700
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_DEVICE_NOT_PRESENT
value|0x0800
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_UNABLE_TO_TERMINATE
value|0x0900
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SELECTION_TIMEOUT
value|0x0A00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_COMMAND_TIMEOUT
value|0x0B00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_MR_MESSAGE_RECEIVED
value|0x0D00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SCSI_BUS_RESET
value|0x0E00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_PARITY_ERROR_FAILURE
value|0x0F00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_AUTOSENSE_FAILED
value|0x1000
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_NO_ADAPTER
value|0x1100
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_DATA_OVERRUN
value|0x1200
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_UNEXPECTED_BUS_FREE
value|0x1300
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SEQUENCE_FAILURE
value|0x1400
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_REQUEST_LENGTH_ERROR
value|0x1500
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_PROVIDE_FAILURE
value|0x1600
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_BDR_MESSAGE_SENT
value|0x1700
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_REQUEST_TERMINATED
value|0x1800
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_IDE_MESSAGE_SENT
value|0x3300
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_RESOURCE_UNAVAILABLE
value|0x3400
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_UNACKNOWLEDGED_EVENT
value|0x3500
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_MESSAGE_RECEIVED
value|0x3600
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_INVALID_CDB
value|0x3700
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_LUN_INVALID
value|0x3800
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SCSI_TID_INVALID
value|0x3900
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_FUNCTION_UNAVAILABLE
value|0x3A00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_NO_NEXUS
value|0x3B00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_SCSI_IID_INVALID
value|0x3C00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_CDB_RECEIVED
value|0x3D00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_LUN_ALREADY_ENABLED
value|0x3E00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_BUS_BUSY
value|0x3F00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_HBA_DSC_QUEUE_FROZEN
value|0x4000
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SCSI Peripheral Device Parameter Groups */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SCSI Configuration and Operating Structures and Defines */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_INFO_GROUP_NO
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_BUS_PORT_INFO_GROUP_NO
value|0x0001
end_define

begin_comment
comment|/* - 0000h - SCSI Device Information Parameters Group defines */
end_comment

begin_comment
comment|/* Device Type */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_DIRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_SEQUENTIAL
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_PRINTER
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_PROCESSOR
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_WORM
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_CDROM
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_SCANNER
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_OPTICAL
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_MEDIA_CHANGER
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_COMM
value|0x09
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_GRAPHICS_1
value|0x0A
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_GRAPHICS_2
value|0x0B
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_ARRAY_CONT
value|0x0C
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_SES
value|0x0D
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DEVICE_TYPE_UNKNOWN
value|0x1F
end_define

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PERIPHERAL_TYPE_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PERIPHERAL_TYPE_PARALLEL
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PERIPHERAL_TYPE_SERIAL
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_RESERVED_FLAG
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DISCONNECT_FLAG
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DISABLE_DISCONNECT
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ENABLE_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_MODE_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_MODE_SET_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_MODE_SET_DEFAULT
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_MODE_SET_SAFEST
value|0x10
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DATA_WIDTH_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DATA_WIDTH_8
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DATA_WIDTH_16
value|0x20
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DATA_WIDTH_32
value|0x40
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SYNC_NEGOTIATION_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_DISABLE_SYNC_NEGOTIATION
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ENABLE_SYNC_NEGOTIATION
value|0x80
end_define

begin_comment
comment|/* - 0001h - SCSI Device Bus Port Info Parameters Group defines */
end_comment

begin_comment
comment|/* Physical */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_PARALLEL
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_FIBRE_CHANNEL
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_SERIAL_P1394
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_PHYS_SERIAL_SSA
value|0x06
end_define

begin_comment
comment|/* Electrical */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_SINGLE_ENDED
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_DIFFERENTIAL
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_LOW_VOLT_DIFF
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ELEC_OPTICAL
value|0x06
end_define

begin_comment
comment|/* Isochronous */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ISOC_NO
value|0x00
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ISOC_YES
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_ISOC_UNKNOWN
value|0x02
end_define

begin_comment
comment|/* Connector Type */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_NONE
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_SHIELDED_A_HD
value|0x04
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_UNSHIELDED_A_HD
value|0x05
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_SHIELDED_A_LD
value|0x06
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_UNSHIELDED_A_LD
value|0x07
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_SHIELDED_P_HD
value|0x08
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_UNSHIELDED_P_HD
value|0x09
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_SCA_I
value|0x0A
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_SCA_II
value|0x0B
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_FC_DB9
value|0x0C
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_FC_FIBRE
value|0x0D
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_FC_SCA_II_40
value|0x0E
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_FC_SCA_II_20
value|0x0F
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_FC_BNC
value|0x10
end_define

begin_comment
comment|/* Connector Gender */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_GENDER_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_GENDER_UNKOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_GENDER_FEMALE
value|0x03
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_PORT_CONN_GENDER_MALE
value|0x04
end_define

begin_comment
comment|/* SCSI Device Group 0000h - Device Information Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_DEVICE_INFO_SCALAR
block|{
name|U8
name|DeviceType
decl_stmt|;
name|U8
name|Flags
decl_stmt|;
name|U16
name|Reserved2
decl_stmt|;
name|U32
name|Identifier
decl_stmt|;
name|U8
name|LunInfo
index|[
literal|8
index|]
decl_stmt|;
comment|/* SCSI-2 8-bit scalar LUN goes into offset 1 */
name|U32
name|QueueDepth
decl_stmt|;
name|U8
name|Reserved1a
decl_stmt|;
name|U8
name|NegOffset
decl_stmt|;
name|U8
name|NegDataWidth
decl_stmt|;
name|U8
name|Reserved1b
decl_stmt|;
name|U64
name|NegSyncRate
decl_stmt|;
block|}
name|I2O_SCSI_DEVICE_INFO_SCALAR
operator|,
typedef|*
name|PI2O_SCSI_DEVICE_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/* SCSI Device Group 0001h - Bus Port Information Parameter Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_BUS_PORT_INFO_SCALAR
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
block|}
name|I2O_SCSI_BUS_PORT_INFO_SCALAR
operator|,
typedef|*
name|PI2O_SCSI_BUS_PORT_INFO_SCALAR
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Peripheral Event Indicator Assignment */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_EVENT_SCSI_SMART
value|0x00000010
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* SCSI Peripheral Class Specific Message Definitions */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Peripheral Successful Completion Reply Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_SUCCESS_REPLY_MESSAGE_FRAME
block|{
name|I2O_SINGLE_REPLY_MESSAGE_FRAME
name|StdReplyFrame
decl_stmt|;
name|U32
name|TransferCount
decl_stmt|;
block|}
name|I2O_SCSI_SUCCESS_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_SCSI_SUCCESS_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Peripheral Error Report Reply Message Frame */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_define
define|#
directive|define
name|I2O_SCSI_SENSE_DATA_SZ
value|44
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|I2O_SCSI_SENSE_DATA_SZ
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME
block|{
name|I2O_SINGLE_REPLY_MESSAGE_FRAME
name|StdReplyFrame
decl_stmt|;
name|U32
name|TransferCount
decl_stmt|;
name|U32
name|AutoSenseTransferCount
decl_stmt|;
name|U8
name|SenseData
index|[
name|I2O_SCSI_SENSE_DATA_SZ
index|]
decl_stmt|;
block|}
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME
operator|,
typedef|*
name|PI2O_SCSI_ERROR_REPLY_MESSAGE_FRAME
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Device Reset Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_DEVICE_RESET_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
block|}
name|I2O_SCSI_DEVICE_RESET_MESSAGE
operator|,
typedef|*
name|PI2O_SCSI_DEVICE_RESET_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Control Block Abort Message Frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_SCB_ABORT_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContextToAbort
decl_stmt|;
block|}
name|I2O_SCSI_SCB_ABORT_MESSAGE
operator|,
typedef|*
name|PI2O_SCSI_SCB_ABORT_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* I2O SCSI Control Block Execute Message Frame */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_CDB_LENGTH
value|16
end_define

begin_typedef
typedef|typedef
name|U16
name|I2O_SCB_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_XFER_DIR_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_NO_DATA_XFER
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_XFER_FROM_DEVICE
value|0x4000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_XFER_TO_DEVICE
value|0x8000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_ENABLE_DISCONNECT
value|0x2000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_TAG_TYPE_MASK
value|0x0380
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_NO_TAG_QUEUEING
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_SIMPLE_QUEUE_TAG
value|0x0080
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_HEAD_QUEUE_TAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_ORDERED_QUEUE_TAG
value|0x0180
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_ACA_QUEUE_TAG
value|0x0200
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_AUTOSENSE_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_DISABLE_AUTOSENSE
value|0x0000
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_SENSE_DATA_IN_MESSAGE
value|0x0020
end_define

begin_define
define|#
directive|define
name|I2O_SCB_FLAG_SENSE_DATA_IN_BUFFER
value|0x0060
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_SCSI_SCB_EXECUTE_MESSAGE
block|{
name|I2O_MESSAGE_FRAME
name|StdMessageFrame
decl_stmt|;
name|I2O_TRANSACTION_CONTEXT
name|TransactionContext
decl_stmt|;
name|U8
name|CDBLength
decl_stmt|;
name|U8
name|Reserved
decl_stmt|;
name|I2O_SCB_FLAGS
name|SCBFlags
decl_stmt|;
name|U8
name|CDB
index|[
name|I2O_SCSI_CDB_LENGTH
index|]
decl_stmt|;
name|U32
name|ByteCount
decl_stmt|;
name|I2O_SG_ELEMENT
name|SGL
decl_stmt|;
block|}
name|I2O_SCSI_SCB_EXECUTE_MESSAGE
operator|,
typedef|*
name|PI2O_SCSI_SCB_EXECUTE_MESSAGE
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
comment|/* I2O_BASE_SCSI_HDR */
end_comment

end_unit

