begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2010 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  * @brief This file defines all of the SCSI related constants, enumerations,  *        and types.  Please note that this file does not necessarily contain  *        an exhaustive list of all constants, commands, sub-commands, etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_H__
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_H__
end_define

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* C O N S T A N T S   A N D   M A C R O S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|/**  * @enum _SCSI_TASK_MGMT_REQUEST_CODES  *  * @brief This enumberation contains the constants to be used for SCSI task  *        management request codes.  SAM does not specify any particular  *        values for these codes so constants used here are the same as  *        those specified in SAS.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SCSI_TASK_MGMT_REQUEST_CODES
block|{
name|SCSI_TASK_REQUEST_ABORT_TASK
init|=
literal|0x01
block|,
name|SCSI_TASK_REQUEST_ABORT_TASK_SET
init|=
literal|0x02
block|,
name|SCSI_TASK_REQUEST_CLEAR_TASK_SET
init|=
literal|0x04
block|,
name|SCSI_TASK_REQUEST_LOGICAL_UNIT_RESET
init|=
literal|0x08
block|,
name|SCSI_TASK_REQUEST_I_T_NEXUS_RESET
init|=
literal|0x10
block|,
name|SCSI_TASK_REQUEST_CLEAR_ACA
init|=
literal|0x40
block|,
name|SCSI_TASK_REQUEST_QUERY_TASK
init|=
literal|0x80
block|,
name|SCSI_TASK_REQUEST_QUERY_TASK_SET
init|=
literal|0x81
block|,
name|SCSI_TASK_REQUEST_QUERY_UNIT_ATTENTION
init|=
literal|0x82
block|,  }
name|SCSI_TASK_MGMT_REQUEST_CODES
typedef|;
end_typedef

begin_comment
comment|/**  * @enum _SCSI_TASK_MGMT_RESPONSE_CODES  *  * @brief This enumeration contains all of the SCSI task management response  *        codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SCSI_TASK_MGMT_RESPONSE_CODES
block|{
name|SCSI_TASK_MGMT_FUNC_COMPLETE
init|=
literal|0
block|,
name|SCSI_INVALID_FRAME
init|=
literal|2
block|,
name|SCSI_TASK_MGMT_FUNC_NOT_SUPPORTED
init|=
literal|4
block|,
name|SCSI_TASK_MGMT_FUNC_FAILED
init|=
literal|5
block|,
name|SCSI_TASK_MGMT_FUNC_SUCCEEDED
init|=
literal|8
block|,
name|SCSI_INVALID_LUN
init|=
literal|9
block|}
name|SCSI_TASK_MGMT_RESPONSE_CODES
typedef|;
end_typedef

begin_comment
comment|/**  * @enum _SCSI_SENSE_RESPONSE_CODE  *  * @brief this enumeration depicts the types of sense data responses as  *      per SPC-3.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SCSI_SENSE_RESPONSE_CODE
block|{
name|SCSI_FIXED_CURRENT_RESPONSE_CODE
init|=
literal|0x70
block|,
name|SCSI_FIXED_DEFERRED_RESPONSE_CODE
init|=
literal|0x71
block|,
name|SCSI_DESCRIPTOR_CURRENT_RESPONSE_CODE
init|=
literal|0x72
block|,
name|SCSI_DESCRIPTOR_DEFERRED_RESPONSE_CODE
init|=
literal|0x73
block|}
name|SCSI_SENSE_RESPONSE_CODE
typedef|;
end_typedef

begin_comment
comment|/**  * @enum _SCSI_SENSE_DATA_DESCRIPTOR_TYPE  *  * @brief this enumeration depicts the types of sense data descriptor as  *      per SPC-4.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SCSI_SENSE_DATA_DESCRIPTOR_TYPE
block|{
name|SCSI_INFORMATION_DESCRIPTOR_TYPE
init|=
literal|0x00
block|,
name|SCSI_CMD_SPECIFIC_DESCRIPTOR_TYPE
init|=
literal|0x01
block|,
name|SCSI_KEY_SPECIFIC_DESCRIPTOR_TYPE
init|=
literal|0x02
block|,
name|SCSI_FIELD_REPLACEABLE_UNIT_DESCRIPTOR_TYPE
init|=
literal|0x03
block|,
name|SCSI_STREAM_CMD_DESCRIPTOR_TYPE
init|=
literal|0x04
block|,
name|SCSI_BLOCK_DESCRIPTOR_TYPE
init|=
literal|0x05
block|,
name|SCSI_OSD_OBJ_IDENTIFICATION_DESCRIPTOR_TYPE
init|=
literal|0x06
block|,
name|SCSI_OSC_RESPONSE_INTEGRITY_DESCRIPTOR_TYPE
init|=
literal|0x07
block|,
name|SCSI_OSD_ATTR_IDENTIFICATION_DESCRIPTOR_TYPE
init|=
literal|0x08
block|,
name|SCSI_ATA_STATUS_RETURN_DESCRIPTOR_TYPE
init|=
literal|0x09
block|,
name|SCSI_PROGRESS_INDICATION_DESCRIPTOR_TYPE
init|=
literal|0x0a
block|,
name|SCSI_USER_DATA_SEGEMNT_REF_DESCRIPTOR_TYPE
init|=
literal|0x0b
block|}
name|SCSI_SENSE_DATA_DESCRIPTOR_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCSI_CMD_SPECIFIC_DESCRIPTOR_ADDITIONAL_LENGTH
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCSI_CMD_SPECIFIC_DESCRIPTOR_LENGTH
value|0x0c
end_define

begin_define
define|#
directive|define
name|SCSI_INFORMATION_DESCRIPTOR_ADDITIONAL_LENGTH
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCSI_INFORMATION_DESCRIPTOR_LENGTH
value|0x0c
end_define

begin_define
define|#
directive|define
name|SCSI_BLOCK_DESCRIPTOR_ADDITIONAL_LENGTH
value|0x2
end_define

begin_define
define|#
directive|define
name|SCSI_BLOCK_DESCRIPTOR_LENGTH
value|0x4
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_DATA_DESC_BIT
value|0x01
end_define

begin_comment
comment|// This constant represents the valid bit located in byte 0 of a FIXED
end_comment

begin_comment
comment|// format sense data.
end_comment

begin_define
define|#
directive|define
name|SCSI_FIXED_SENSE_DATA_VALID_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_FIXED_SENSE_DATA_BASE_LENGTH
value|18
end_define

begin_comment
comment|// This value is used in the DATAPRES field of the SCSI Response IU.
end_comment

begin_define
define|#
directive|define
name|SCSI_RESPONSE_DATA_PRES_SENSE_DATA
value|0x02
end_define

begin_comment
comment|/**  * @name SCSI_SENSE_KEYS  *  * These constants delineate all of the SCSI protocol sense key constants  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_SENSE_NO_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_RECOVERED_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_NOT_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_MEDIUM_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_HARDWARE_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_ILLEGAL_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_UNIT_ATTENTION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_DATA_PROTECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_BLANK_CHECK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_VENDOR_SPECIFIC
value|0x09
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_COPY_ABORTED
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_ABORTED_COMMAND
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_VOLUME_OVERFLOW
value|0x0D
end_define

begin_define
define|#
directive|define
name|SCSI_SENSE_MISCOMPARE
value|0x0E
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_ADDITIONAL_SENSE_CODES  *  * These constants delineate all of the SCSI protocol additional sense  * code constants.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_ASC_NO_ADDITIONAL_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_INITIALIZING_COMMAND_REQUIRED
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LUN_SELF_TEST_IN_PROGRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LUN_FORMAT_IN_PROGRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LUN_NOT_RESPOND_TO_SELECTION
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_UNRECOVERED_READ_ERROR
value|0x11
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_INVALID_COMMAND_OPERATION_CODE
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LBA_OUT_OF_RANGE
value|0x21
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_INVALID_FIELD_IN_CDB
value|0x24
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LOGICAL_UNIT_NOT_SUPPORTED
value|0x25
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_INVALID_FIELD_IN_PARM_LIST
value|0x26
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_WRITE_PROTECTED
value|0x27
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_NOT_READY_TO_READY_CHANGE
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_MEDIUM_FORMAT_CORRUPTED
value|0x31
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_ENCLOSURE_SERVICES_UNAVAILABLE
value|0x35
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_SAVING_PARMS_NOT_SUPPORTED
value|0x39
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_MEDIUM_NOT_PRESENT
value|0x3A
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_INTERNAL_TARGET_FAILURE
value|0x44
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_IU_CRC_ERROR_DETECTED
value|0x47
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_MEDIUM_REMOVAL_REQUEST
value|0x5A
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_COMMAND_SEQUENCE_ERROR
value|0x2C
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_MEDIA_LOAD_OR_EJECT_FAILED
value|0x53
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_HARDWARE_IMPENDING_FAILURE
value|0x5D
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_POWER_STATE_CHANGE
value|0x5E
end_define

begin_define
define|#
directive|define
name|SCSI_DIAGNOSTIC_FAILURE_ON_COMPONENT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_LOGICAL_UNIT_FAILED
value|0x4C
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_ATA_DEVICE_FEATURE_NOT_ENABLED
value|0x67
end_define

begin_define
define|#
directive|define
name|SCSI_ASC_MICROCODE_HAS_CHANGED
value|0x3F
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_ADDITIONAL_SENSE_CODE_QUALIFIERS  *  * This enumeration contains all of the used SCSI protocol additional  * sense code qualifier constants.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_ASCQ_NO_ADDITIONAL_SENSE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_INVALID_FIELD_IN_CDB
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_INVALID_FIELD_IN_PARM_LIST
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_LUN_NOT_RESPOND_TO_SELECTION
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_INTERNAL_TARGET_FAILURE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_LBA_OUT_OF_RANGE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_MEDIUM_NOT_PRESENT
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_NOT_READY_TO_READY_CHANGE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_WRITE_PROTECTED
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_UNRECOVERED_READ_ERROR
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_SAVING_PARMS_NOT_SUPPORTED
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_INVALID_COMMAND_OPERATION_CODE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_MEDIUM_REMOVAL_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_INITIALIZING_COMMAND_REQUIRED
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_IU_CRC_ERROR_DETECTED
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_LUN_FORMAT_IN_PROGRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_LUN_SELF_TEST_IN_PROGRESS
value|0x09
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_GENERAL_HARD_DRIVE_FAILURE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_IDLE_CONDITION_ACTIVATE_BY_COMMAND
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_STANDBY_CONDITION_ACTIVATE_BY_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_POWER_STATE_CHANGE_TO_IDLE
value|0x42
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_POWER_STATE_CHANGE_TO_STANDBY
value|0x43
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_ATA_DEVICE_FEATURE_NOT_ENABLED
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_UNRECOVERED_READ_ERROR_AUTO_REALLOCATE_FAIL
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_ATA_PASS_THROUGH_INFORMATION_AVAILABLE
value|0x1D
end_define

begin_define
define|#
directive|define
name|SCSI_ASCQ_MICROCODE_HAS_CHANGED
value|0x01
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_STATUS_CODES  *  * These constants define all of the used SCSI status values.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_CHECK_CONDITION
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_CONDITION_MET
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_TASKFULL
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_ACA
value|0x30
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_ABORT
value|0x40
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_OPERATION_CODES  *  * These constants delineate all of the SCSI command/operation codes.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY_10
value|0x25
end_define

begin_define
define|#
directive|define
name|SCSI_SERVICE_ACTION_IN_16
value|0x9E
end_define

begin_define
define|#
directive|define
name|SCSI_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT
value|0x1B
end_define

begin_define
define|#
directive|define
name|SCSI_SYNCHRONIZE_CACHE_10
value|0x35
end_define

begin_define
define|#
directive|define
name|SCSI_SYNCHRONIZE_CACHE_16
value|0x91
end_define

begin_define
define|#
directive|define
name|SCSI_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_REPORT_LUNS
value|0xA0
end_define

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_READ_6
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_READ_10
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_READ_12
value|0xA8
end_define

begin_define
define|#
directive|define
name|SCSI_READ_16
value|0x88
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_6
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_10
value|0x2A
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_12
value|0xAA
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_16
value|0x8A
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY_10
value|0x2F
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY_12
value|0xAF
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY_16
value|0x8F
end_define

begin_define
define|#
directive|define
name|SCSI_SEEK_6
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SEEK_10
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_VERIFY
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_READ_BUFFER
value|0x3C
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_BUFFER
value|0x3B
end_define

begin_define
define|#
directive|define
name|SCSI_SEND_DIAGNOSTIC
value|0x1D
end_define

begin_define
define|#
directive|define
name|SCSI_RECEIVE_DIAGNOSTIC
value|0x1C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_6
value|0x1A
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_10
value|0x5A
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_6
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_10
value|0x55
end_define

begin_define
define|#
directive|define
name|SCSI_MAINTENANCE_IN
value|0xA3
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE
value|0x4D
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SELECT
value|0x4C
end_define

begin_define
define|#
directive|define
name|SCSI_RESERVE_6
value|0x16
end_define

begin_define
define|#
directive|define
name|SCSI_RESERVE_10
value|0x56
end_define

begin_define
define|#
directive|define
name|SCSI_RELEASE_6
value|0x17
end_define

begin_define
define|#
directive|define
name|SCSI_RELEASE_10
value|0x57
end_define

begin_define
define|#
directive|define
name|SCSI_ATA_PASSTHRU_12
value|0xA1
end_define

begin_define
define|#
directive|define
name|SCSI_ATA_PASSTHRU_16
value|0x85
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_LONG_10
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_LONG_16
value|0x9F
end_define

begin_define
define|#
directive|define
name|SCSI_PERSISTENT_RESERVE_IN
value|0x5E
end_define

begin_define
define|#
directive|define
name|SCSI_PERSISTENT_RESERVE_OUT
value|0x5F
end_define

begin_define
define|#
directive|define
name|SCSI_SECURITY_PROTOCOL_IN
value|0xA2
end_define

begin_define
define|#
directive|define
name|SCSI_SECURITY_PROTOCOL_OUT
value|0xB5
end_define

begin_define
define|#
directive|define
name|SCSI_UNMAP
value|0x42
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_AND_VERIFY_10
value|0x2E
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_AND_VERIFY_12
value|0xAE
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_AND_VERIFY_16
value|0x8E
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_SERVICE_ACTION_IN_CODES  *  * Service action in operations.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_SERVICE_ACTION_IN_CODES_READ_CAPACITY_16
value|0x10
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/** * * Service action mask.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_SERVICE_ACTION_MASK
value|0x1f
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_MAINTENANCE_IN_SERVICE_ACTION_CODES  *  * MAINTENANCE IN service action codes.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_REPORT_TASK_MGMT
value|0x0D
end_define

begin_define
define|#
directive|define
name|SCSI_REPORT_OP_CODES
value|0x0C
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SCSI_MODE_PAGE_CONTROLS  *  * These constants delineate all of the used SCSI Mode Page control  * values.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PC_CURRENT
value|0x0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PC_CHANGEABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PC_DEFAULT
value|0x2
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PC_SAVED
value|0x3
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PC_SHIFT
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PAGE_CODE_ENABLE
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_DBD_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_LLBAA_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CONTROL_D_SENSE_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CONTROL_D_SENSE_ENABLE
value|0x1
end_define

begin_comment
comment|/**  * @name SCSI_MODE_PAGE_CODES  *  * These constants delineate all of the used SCSI Mode Page codes.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_READ_WRITE_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_DISCONNECT_RECONNECT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CACHING
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CONTROL
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_PROTOCOL_SPECIFIC_PORT
value|0x19
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_POWER_CONDITION
value|0x1A
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_INFORMATIONAL_EXCP_CONTROL
value|0x1C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_ALL_PAGES
value|0x3F
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_ALL_SUB_PAGES_CODE
value|0xFF
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_NO_SUB_PAGES_CODE
value|0x0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_PROTOCOL_PORT_NUM_SUBPAGES
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CACHE_PAGE_WCE_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_CACHE_PAGE_DRA_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_DEXCPT_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_HEADER_FUA_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_POWER_CONDITION_STANDBY
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_POWER_CONDITION_IDLE
value|0x2
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_6_HEADER_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_10_HEADER_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_STD_BLOCK_DESCRIPTOR_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE_LLBA_BLOCK_DESCRIPTOR_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_INFORMATIONAL_EXCP_DXCPT_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_19_SAS_ID
value|0x6
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_19_SUB1_PAGE_NUM
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_19_SUB1_PC
value|0x59
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_HEADER_MEDIUM_TYPE_SBC
value|0x00
end_define

begin_comment
comment|//Mode Select constrains related masks value
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_PF_BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_PF_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_MRIE_BYTE
value|0x6
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_MRIE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_SPF_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_01_AWRE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_01_ARRE_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_01_RC_ERBITS_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_08_FSW_LBCSS_NVDIS
value|0xC1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_1C_PERF_TEST
value|0x84
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_0A_TST_TMF_RLEC
value|0xF1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_0A_MODIFIER
value|0xE0
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_0A_UA_SWP
value|0x38
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_0A_TAS_AUTO
value|0x47
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT_MODE_PAGE_D_SENSE
value|0x4
end_define

begin_define
define|#
directive|define
name|SCSI_CONTROL_BYTE_NACA_BIT_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_MOVE_FUA_BIT_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY_PMI_BIT_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY_10_DATA_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY_16_DATA_LENGTH
value|32
end_define

begin_comment
comment|// Inquiry constants
end_comment

begin_define
define|#
directive|define
name|SCSI_INQUIRY_EVPD_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_PAGE_CODE_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_SUPPORTED_PAGES_PAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_UNIT_SERIAL_NUM_PAGE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_DEVICE_ID_PAGE
value|0x83
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_ATA_INFORMATION_PAGE
value|0x89
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_BLOCK_DEVICE_PAGE
value|0xB1
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_BLOCK_DEVICE_LENGTH
value|0x3C
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY_STANDARD_ALLOCATION_LENGTH
value|0x24
end_define

begin_comment
comment|//36
end_comment

begin_define
define|#
directive|define
name|SCSI_REQUEST_SENSE_ALLOCATION_LENGTH
value|0xFC
end_define

begin_comment
comment|//252
end_comment

begin_comment
comment|/** Defines the log page codes that are use in gathing Smart data */
end_comment

begin_define
define|#
directive|define
name|SCSI_LOG_PAGE_SUPPORTED_PAGES
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_PAGE_INFORMATION_EXCEPTION
value|0x2F
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_PAGE_SELF_TEST
value|0x10
end_define

begin_comment
comment|/**  * @name SCSI_INQUIRY_VPD  *  * The following are constants used with vital product data inquiry pages.  * Values are already shifted into the proper nibble location.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_PIV_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_LUN_ASSOCIATION
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_TARGET_PORT_ASSOCIATION
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_VEN_UNIQUE_IDENTIFIER_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_NAA_IDENTIFIER_TYPE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_T10_IDENTIFIER_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_BINARY_CODE_SET
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_ASCII_CODE_SET
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_FC_PROTOCOL_IDENTIFIER
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SAS_PROTOCOL_IDENTIFIER
value|0x60
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SCSI_VERIFY_BYTCHK_ENABLED
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SYNCHRONIZE_CACHE_IMMED_ENABLED
value|0x02
end_define

begin_comment
comment|/**  * @name SCSI_START_STOP_UNIT_POWER_CONDITION_CODES  *  * The following are SCSI Start Stop Unit command Power Condition codes.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_START_VALID
value|0x0
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_ACTIVE
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_IDLE
value|0x2
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_STANDBY
value|0x3
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_LU_CONTROL
value|0x7
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_FORCE_S_CONTROL
value|0xB
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_IMMED_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_IMMED_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_START_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_START_BIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_LOEJ_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_LOEJ_BIT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_NO_FLUSH_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_NO_FLUSH_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_MODIFIER_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_MODIFIER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP_UNIT_POWER_CONDITION_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE_PC_FIELD_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE_PC_FIELD_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE_PAGE_CODE_FIELD_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|SCSI_LOG_SENSE_PAGE_CODE_FIELD_SHIFT
value|0
end_define

begin_comment
comment|/**  * @name MRIE - Method of reporting informational exceptions codes  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|NO_REPORTING_INFO_EXCEPTION_CONDITION
value|0x0
end_define

begin_define
define|#
directive|define
name|ASYNCHRONOUS_EVENT_REPORTING
value|0x1
end_define

begin_define
define|#
directive|define
name|ESTABLISH_UNIT_ATTENTION_CONDITION
value|0x2
end_define

begin_define
define|#
directive|define
name|CONDITIONALLY_GENERATE_RECOVERED_ERROR
value|0x3
end_define

begin_define
define|#
directive|define
name|UNCONDITIONALLY_GENERATE_RECOVERED_ERROR
value|0x4
end_define

begin_define
define|#
directive|define
name|GENERATE_NO_SENSE
value|0x5
end_define

begin_define
define|#
directive|define
name|REPORT_INFO_EXCEPTION_CONDITION_ON_REQUEST
value|0x6
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SCSI_INFORMATION_EXCEPTION_DEXCPT_BIT
value|0x08
end_define

begin_comment
comment|//Reassign Blocks masks
end_comment

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS_LONGLBA_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS_LONGLIST_BIT
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCSI_H_
end_comment

end_unit

