begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Structure and I/O definitions for the Command Interface for SCSI-3 Support.  *  * Data in command CDBs are in big-endian format.  All other data is little-endian.  * This header only supports little-endian hosts at this time.  */
end_comment

begin_union
union|union
name|ciss_device_address
block|{
struct|struct
comment|/* MODE_PERIPHERAL and MODE_MASK_PERIPHERAL */
block|{
name|u_int32_t
name|target
range|:
literal|24
decl_stmt|;
comment|/* SCSI target */
name|u_int32_t
name|bus
range|:
literal|6
decl_stmt|;
comment|/* SCSI bus */
name|u_int32_t
name|mode
range|:
literal|2
decl_stmt|;
comment|/* CISS_HDR_ADDRESS_MODE_* */
name|u_int32_t
name|extra_address
decl_stmt|;
comment|/* SCSI-3 level-2 and level-3 address bytes */
block|}
name|physical
struct|;
struct|struct
comment|/* MODE_LOGICAL */
block|{
name|u_int32_t
name|lun
range|:
literal|30
decl_stmt|;
comment|/* logical device ID */
name|u_int32_t
name|mode
range|:
literal|2
decl_stmt|;
comment|/* CISS_HDR_ADDRESS_MODE_LOGICAL */
name|u_int32_t
label|:
literal|32
expr_stmt|;
comment|/* reserved */
block|}
name|logical
struct|;
struct|struct
block|{
name|u_int32_t
label|:
literal|30
expr_stmt|;
name|u_int32_t
name|mode
range|:
literal|2
decl_stmt|;
name|u_int32_t
label|:
literal|32
expr_stmt|;
block|}
name|mode
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|CISS_HDR_ADDRESS_MODE_PERIPHERAL
value|0x0
end_define

begin_define
define|#
directive|define
name|CISS_HDR_ADDRESS_MODE_LOGICAL
value|0x1
end_define

begin_define
define|#
directive|define
name|CISS_HDR_ADDRESS_MODE_MASK_PERIPHERAL
value|0x3
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_MODE2
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0xc0000000)>> 30)
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_BUS2
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0x3f000000)>> 24)
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_TARGET2
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0x00ff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_MODE3
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0x0000c000)>> 14)
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_BUS3
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0x00003f00)>> 8)
end_define

begin_define
define|#
directive|define
name|CISS_EXTRA_TARGET3
parameter_list|(
name|extra
parameter_list|)
value|((extra& 0x000000ff))
end_define

begin_struct
struct|struct
name|ciss_header
block|{
name|u_int8_t
label|:
literal|8
expr_stmt|;
comment|/* reserved */
name|u_int8_t
name|sg_in_list
decl_stmt|;
comment|/* SG's in the command structure */
name|u_int16_t
name|sg_total
decl_stmt|;
comment|/* total count of SGs for this command */
name|u_int32_t
name|host_tag
decl_stmt|;
comment|/* host identifier, bits 0&1 must be clear */
define|#
directive|define
name|CISS_HDR_HOST_TAG_ERROR
value|(1<<1)
name|u_int32_t
name|host_tag_zeroes
decl_stmt|;
comment|/* tag is 64 bits, but interface only supports 32 */
name|union
name|ciss_device_address
name|address
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_cdb
block|{
name|u_int8_t
name|cdb_length
decl_stmt|;
comment|/* valid CDB bytes */
name|u_int8_t
name|type
range|:
literal|3
decl_stmt|;
define|#
directive|define
name|CISS_CDB_TYPE_COMMAND
value|0
define|#
directive|define
name|CISS_CDB_TYPE_MESSAGE
value|1
name|u_int8_t
name|attribute
range|:
literal|3
decl_stmt|;
define|#
directive|define
name|CISS_CDB_ATTRIBUTE_UNTAGGED
value|0
define|#
directive|define
name|CISS_CDB_ATTRIBUTE_SIMPLE
value|4
define|#
directive|define
name|CISS_CDB_ATTRIBUTE_HEAD_OF_QUEUE
value|5
define|#
directive|define
name|CISS_CDB_ATTRIBUTE_ORDERED
value|6
define|#
directive|define
name|CISS_CDB_ATTRIBUTE_AUTO_CONTINGENT
value|7
name|u_int8_t
name|direction
range|:
literal|2
decl_stmt|;
define|#
directive|define
name|CISS_CDB_DIRECTION_NONE
value|0
define|#
directive|define
name|CISS_CDB_DIRECTION_WRITE
value|1
define|#
directive|define
name|CISS_CDB_DIRECTION_READ
value|2
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* seconds */
define|#
directive|define
name|CISS_CDB_BUFFER_SIZE
value|16
name|u_int8_t
name|cdb
index|[
name|CISS_CDB_BUFFER_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_error_info_pointer
block|{
name|u_int64_t
name|error_info_address
decl_stmt|;
comment|/* points to ciss_error_info structure */
name|u_int32_t
name|error_info_length
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_error_info
block|{
name|u_int8_t
name|scsi_status
decl_stmt|;
define|#
directive|define
name|CISS_SCSI_STATUS_GOOD
value|0x00
comment|/* these are scsi-standard values */
define|#
directive|define
name|CISS_SCSI_STATUS_CHECK_CONDITION
value|0x02
define|#
directive|define
name|CISS_SCSI_STATUS_CONDITION_MET
value|0x04
define|#
directive|define
name|CISS_SCSI_STATUS_BUSY
value|0x08
define|#
directive|define
name|CISS_SCSI_STATUS_INDETERMINATE
value|0x10
define|#
directive|define
name|CISS_SCSI_STATUS_INDETERMINATE_CM
value|0x14
define|#
directive|define
name|CISS_SCSI_STATUS_RESERVATION_CONFLICT
value|0x18
define|#
directive|define
name|CISS_SCSI_STATUS_COMMAND_TERMINATED
value|0x22
define|#
directive|define
name|CISS_SCSI_STATUS_QUEUE_FULL
value|0x28
define|#
directive|define
name|CISS_SCSI_STATUS_ACA_ACTIVE
value|0x30
name|u_int8_t
name|sense_length
decl_stmt|;
name|u_int16_t
name|command_status
decl_stmt|;
define|#
directive|define
name|CISS_CMD_STATUS_SUCCESS
value|0
define|#
directive|define
name|CISS_CMD_STATUS_TARGET_STATUS
value|1
define|#
directive|define
name|CISS_CMD_STATUS_DATA_UNDERRUN
value|2
define|#
directive|define
name|CISS_CMD_STATUS_DATA_OVERRUN
value|3
define|#
directive|define
name|CISS_CMD_STATUS_INVALID_COMMAND
value|4
define|#
directive|define
name|CISS_CMD_STATUS_PROTOCOL_ERROR
value|5
define|#
directive|define
name|CISS_CMD_STATUS_HARDWARE_ERROR
value|6
define|#
directive|define
name|CISS_CMD_STATUS_CONNECTION_LOST
value|7
define|#
directive|define
name|CISS_CMD_STATUS_ABORTED
value|8
define|#
directive|define
name|CISS_CMD_STATUS_ABORT_FAILED
value|9
define|#
directive|define
name|CISS_CMD_STATUS_UNSOLICITED_ABORT
value|10
define|#
directive|define
name|CISS_CMD_STATUS_TIMEOUT
value|11
define|#
directive|define
name|CISS_CMD_STATUS_UNABORTABLE
value|12
name|u_int32_t
name|residual_count
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|res1
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int32_t
name|error_info
decl_stmt|;
block|}
name|__packed
name|common_info
struct|;
struct|struct
block|{
name|u_int8_t
name|res1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|offense_size
decl_stmt|;
name|u_int8_t
name|offense_offset
decl_stmt|;
name|u_int32_t
name|offense_value
decl_stmt|;
block|}
name|__packed
name|invalid_command
struct|;
block|}
name|additional_error_info
union|;
name|u_int8_t
name|sense_info
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_sg_entry
block|{
name|u_int64_t
name|address
decl_stmt|;
define|#
directive|define
name|CISS_SG_ADDRESS_BITBUCKET
value|(~(u_int64_t)0)
name|u_int32_t
name|length
decl_stmt|;
name|u_int32_t
label|:
literal|31
expr_stmt|;
name|u_int32_t
name|extension
range|:
literal|1
decl_stmt|;
comment|/* address points to another s/g chain */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_command
block|{
name|struct
name|ciss_header
name|header
decl_stmt|;
name|struct
name|ciss_cdb
name|cdb
decl_stmt|;
name|struct
name|ciss_error_info_pointer
name|error_info
decl_stmt|;
name|struct
name|ciss_sg_entry
name|sg
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|CISS_OPCODE_REPORT_LOGICAL_LUNS
value|0xc2
end_define

begin_define
define|#
directive|define
name|CISS_OPCODE_REPORT_PHYSICAL_LUNS
value|0xc3
end_define

begin_struct
struct|struct
name|ciss_lun_report
block|{
name|u_int32_t
name|list_size
decl_stmt|;
comment|/* big-endian */
name|u_int32_t
label|:
literal|32
expr_stmt|;
name|union
name|ciss_device_address
name|lun
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|CISS_VPD_LOGICAL_DRIVE_GEOMETRY
value|0xc1
end_define

begin_struct
struct|struct
name|ciss_ldrive_geometry
block|{
name|u_int8_t
name|periph_qualifier
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|periph_devtype
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|page_code
decl_stmt|;
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|page_length
decl_stmt|;
name|u_int16_t
name|cylinders
decl_stmt|;
comment|/* big-endian */
name|u_int8_t
name|heads
decl_stmt|;
name|u_int8_t
name|sectors
decl_stmt|;
name|u_int8_t
name|fault_tolerance
decl_stmt|;
name|u_int8_t
name|res2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|ciss_report_cdb
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|5
index|]
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
comment|/* big-endian */
name|u_int8_t
label|:
literal|8
expr_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Note that it's not clear whether we have to set the detail field to  * the tag of the command to be aborted, or the tag field in the command itself;  * documentation conflicts on this.  */
end_comment

begin_define
define|#
directive|define
name|CISS_OPCODE_MESSAGE_ABORT
value|0x00
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_ABORT_TASK
value|0x00
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_ABORT_TASK_SET
value|0x01
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_ABORT_CLEAR_ACA
value|0x02
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_ABORT_CLEAR_TASK_SET
value|0x03
end_define

begin_define
define|#
directive|define
name|CISS_OPCODE_MESSAGE_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_RESET_CONTROLLER
value|0x00
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_RESET_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_RESET_TARGET
value|0x03
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_RESET_LOGICAL_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|CISS_OPCODE_MESSAGE_SCAN
value|0x02
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_SCAN_CONTROLLER
value|0x00
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_SCAN_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_SCAN_TARGET
value|0x03
end_define

begin_define
define|#
directive|define
name|CISS_MESSAGE_SCAN_LOGICAL_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|CISS_OPCODE_MESSAGE_NOP
value|0x03
end_define

begin_struct
struct|struct
name|ciss_message_cdb
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int16_t
label|:
literal|16
expr_stmt|;
name|u_int32_t
name|abort_tag
decl_stmt|;
comment|/* XXX endianness? */
name|u_int8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CISS vendor-specific commands/messages.  *  * Note that while messages and vendor-specific commands are  * differentiated, they are handled in basically the same way and can  * be considered to be basically the same thing, as long as the cdb  * type field is set correctly.  */
end_comment

begin_define
define|#
directive|define
name|CISS_OPCODE_READ
value|0xc0
end_define

begin_define
define|#
directive|define
name|CISS_OPCODE_WRITE
value|0xc1
end_define

begin_define
define|#
directive|define
name|CISS_COMMAND_NOTIFY_ON_EVENT
value|0xd0
end_define

begin_define
define|#
directive|define
name|CISS_COMMAND_ABORT_NOTIFY
value|0xd1
end_define

begin_struct
struct|struct
name|ciss_notify_cdb
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|timeout
decl_stmt|;
comment|/* seconds, little-endian */
name|u_int8_t
name|res2
decl_stmt|;
comment|/* reserved */
name|u_int8_t
name|synchronous
range|:
literal|1
decl_stmt|;
comment|/* return immediately */
name|u_int8_t
name|ordered
range|:
literal|1
decl_stmt|;
comment|/* return events in recorded order */
name|u_int8_t
name|seek_to_oldest
range|:
literal|1
decl_stmt|;
comment|/* reset read counter to oldest event */
name|u_int8_t
name|new_only
range|:
literal|1
decl_stmt|;
comment|/* ignore any queued events */
name|u_int8_t
label|:
literal|4
expr_stmt|;
name|u_int32_t
name|length
decl_stmt|;
comment|/* must be 512, little-endian */
define|#
directive|define
name|CISS_NOTIFY_DATA_SIZE
value|512
name|u_int8_t
name|control
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|CISS_NOTIFY_NOTIFIER
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_NOTIFIER_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_NOTIFIER_PROTOCOL
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_PHYSICAL
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_POWERSUPPLY
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_FAN
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_POWER
value|3
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_REDUNDANT
value|4
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HOTPLUG_NONDISK
value|5
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HARDWARE
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HARDWARE_CABLES
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HARDWARE_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HARDWARE_FAN
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_HARDWARE_VRM
value|3
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_ENVIRONMENT
value|3
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_ENVIRONMENT_TEMPERATURE
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_ENVIRONMENT_POWERSUPPLY
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_ENVIRONMENT_CHASSIS
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_ENVIRONMENT_POWER
value|3
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_PHYSICAL
value|4
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_PHYSICAL_STATE
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_LOGICAL
value|5
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_LOGICAL_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_LOGICAL_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_LOGICAL_SURFACE
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_REDUNDANT
value|6
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_REDUNDANT_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_CISS
value|8
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_CISS_REDUNDANT_CHANGE
value|0
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_CISS_PATH_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_CISS_HARDWARE_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|CISS_NOTIFY_CISS_LOGICAL
value|3
end_define

begin_struct
struct|struct
name|ciss_notify_drive
block|{
name|u_int16_t
name|physical_drive_number
decl_stmt|;
name|u_int8_t
name|configured_drive_flag
decl_stmt|;
name|u_int8_t
name|spare_drive_flag
decl_stmt|;
name|u_int8_t
name|big_physical_drive_number
decl_stmt|;
name|u_int8_t
name|enclosure_bay_number
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_locator
block|{
name|u_int16_t
name|port
decl_stmt|;
name|u_int16_t
name|id
decl_stmt|;
name|u_int16_t
name|box
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_redundant_controller
block|{
name|u_int16_t
name|slot
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_logical_status
block|{
name|u_int16_t
name|logical_drive
decl_stmt|;
name|u_int8_t
name|previous_state
decl_stmt|;
name|u_int8_t
name|new_state
decl_stmt|;
name|u_int8_t
name|spare_state
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_rebuild_aborted
block|{
name|u_int16_t
name|logical_drive
decl_stmt|;
name|u_int8_t
name|replacement_drive
decl_stmt|;
name|u_int8_t
name|error_drive
decl_stmt|;
name|u_int8_t
name|big_replacement_drive
decl_stmt|;
name|u_int8_t
name|big_error_drive
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_io_error
block|{
name|u_int16_t
name|logical_drive
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|u_int16_t
name|block_count
decl_stmt|;
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|failure_bus
decl_stmt|;
name|u_int8_t
name|failure_drive
decl_stmt|;
name|u_int64_t
name|big_lba
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify_consistency_completed
block|{
name|u_int16_t
name|logical_drive
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ciss_notify
block|{
name|u_int32_t
name|timestamp
decl_stmt|;
comment|/* seconds since controller power-on */
name|u_int16_t
name|class
decl_stmt|;
name|u_int16_t
name|subclass
decl_stmt|;
name|u_int16_t
name|detail
decl_stmt|;
union|union
block|{
name|struct
name|ciss_notify_drive
name|drive
decl_stmt|;
name|struct
name|ciss_notify_locator
name|location
decl_stmt|;
name|struct
name|ciss_notify_redundant_controller
name|redundant_controller
decl_stmt|;
name|struct
name|ciss_notify_logical_status
name|logical_status
decl_stmt|;
name|struct
name|ciss_notify_rebuild_aborted
name|rebuild_aborted
decl_stmt|;
name|struct
name|ciss_notify_io_error
name|io_error
decl_stmt|;
name|struct
name|ciss_notify_consistency_completed
name|consistency_completed
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|64
index|]
decl_stmt|;
block|}
name|data
union|;
name|char
name|message
index|[
literal|80
index|]
decl_stmt|;
name|u_int32_t
name|tag
decl_stmt|;
name|u_int16_t
name|date
decl_stmt|;
name|u_int16_t
name|year
decl_stmt|;
name|u_int32_t
name|time
decl_stmt|;
name|u_int16_t
name|pre_power_up_time
decl_stmt|;
name|union
name|ciss_device_address
name|device
decl_stmt|;
comment|/* XXX pads to 512 bytes */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CISS config table, which describes the controller's  * supported interface(s) and capabilities.  *  * This is mapped directly via PCI.  */
end_comment

begin_struct
struct|struct
name|ciss_config_table
block|{
name|char
name|signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* "CISS" */
name|u_int32_t
name|valence
decl_stmt|;
name|u_int32_t
name|supported_methods
decl_stmt|;
define|#
directive|define
name|CISS_TRANSPORT_METHOD_READY
value|(1<<0)
define|#
directive|define
name|CISS_TRANSPORT_METHOD_SIMPLE
value|(1<<1)
define|#
directive|define
name|CISS_TRANSPORT_METHOD_PERF
value|(1<<2)
name|u_int32_t
name|active_method
decl_stmt|;
name|u_int32_t
name|requested_method
decl_stmt|;
name|u_int32_t
name|command_physlimit
decl_stmt|;
name|u_int32_t
name|interrupt_coalesce_delay
decl_stmt|;
name|u_int32_t
name|interrupt_coalesce_count
decl_stmt|;
name|u_int32_t
name|max_outstanding_commands
decl_stmt|;
name|u_int32_t
name|bus_types
decl_stmt|;
define|#
directive|define
name|CISS_TRANSPORT_BUS_TYPE_ULTRA2
value|(1<<0)
define|#
directive|define
name|CISS_TRANSPORT_BUS_TYPE_ULTRA3
value|(1<<1)
define|#
directive|define
name|CISS_TRANSPORT_BUS_TYPE_FIBRE1
value|(1<<8)
define|#
directive|define
name|CISS_TRANSPORT_BUS_TYPE_FIBRE2
value|(1<<9)
name|u_int32_t
name|transport_offset
decl_stmt|;
name|char
name|server_name
index|[
literal|16
index|]
decl_stmt|;
name|u_int32_t
name|heartbeat
decl_stmt|;
name|u_int32_t
name|host_driver
decl_stmt|;
define|#
directive|define
name|CISS_DRIVER_SUPPORT_UNIT_ATTENTION
value|(1<<0)
define|#
directive|define
name|CISS_DRIVER_QUICK_INIT
value|(1<<1)
define|#
directive|define
name|CISS_DRIVER_INTERRUPT_ON_LOCKUP
value|(1<<2)
define|#
directive|define
name|CISS_DRIVER_SUPPORT_MIXED_Q_TAGS
value|(1<<3)
define|#
directive|define
name|CISS_DRIVER_HOST_IS_ALPHA
value|(1<<4)
define|#
directive|define
name|CISS_DRIVER_MULTI_LUN_SUPPORT
value|(1<<5)
define|#
directive|define
name|CISS_DRIVER_MESSAGE_REQUESTS_SUPPORTED
value|(1<<7)
define|#
directive|define
name|CISS_DRIVER_DAUGHTER_ATTACHED
value|(1<<8)
define|#
directive|define
name|CISS_DRIVER_SCSI_PREFETCH
value|(1<<9)
name|u_int32_t
name|max_sg_length
decl_stmt|;
comment|/* 31 in older firmware */
comment|/*  * these fields appear in OpenCISS Spec 1.06  * http://cciss.sourceforge.net/#docs  */
name|u_int32_t
name|max_logical_supported
decl_stmt|;
name|u_int32_t
name|max_physical_supported
decl_stmt|;
name|u_int32_t
name|max_physical_per_logical
decl_stmt|;
name|u_int32_t
name|max_perfomant_mode_cmds
decl_stmt|;
name|u_int32_t
name|max_block_fetch_count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Configuration table for the Performant transport.  Only 4 request queues  * are mentioned in this table, though apparently up to 256 can exist.  */
end_comment

begin_struct
struct|struct
name|ciss_perf_config
block|{
name|uint32_t
name|fetch_count
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|CISS_SG_FETCH_MAX
value|0
define|#
directive|define
name|CISS_SG_FETCH_1
value|1
define|#
directive|define
name|CISS_SG_FETCH_2
value|2
define|#
directive|define
name|CISS_SG_FETCH_4
value|3
define|#
directive|define
name|CISS_SG_FETCH_8
value|4
define|#
directive|define
name|CISS_SG_FETCH_16
value|5
define|#
directive|define
name|CISS_SG_FETCH_32
value|6
define|#
directive|define
name|CISS_SG_FETCH_NONE
value|7
name|uint32_t
name|rq_size
decl_stmt|;
name|uint32_t
name|rq_count
decl_stmt|;
name|uint32_t
name|rq_bank_lo
decl_stmt|;
name|uint32_t
name|rq_bank_hi
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|rq_addr_lo
decl_stmt|;
name|uint32_t
name|rq_addr_hi
decl_stmt|;
block|}
name|__packed
name|rq
index|[
literal|4
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * In a flagrant violation of what CISS seems to be meant to be about,  * Compaq recycle a goodly portion of their previous generation's  * command set (and all the legacy baggage related to a design  * originally aimed at narrow SCSI) through the Array Controller Read  * and Array Controller Write interface.  *  * Command ID values here can be looked up for in the  * publically-available documentation for the older controllers; note  * that the command layout is necessarily different to fit within the  * CDB.  */
end_comment

begin_define
define|#
directive|define
name|CISS_ARRAY_CONTROLLER_READ
value|0x26
end_define

begin_define
define|#
directive|define
name|CISS_ARRAY_CONTROLLER_WRITE
value|0x27
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_ID_LDRIVE
value|0x10
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_ID_CTLR
value|0x11
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_ID_LSTATUS
value|0x12
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_ID_PDRIVE
value|0x15
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_BLINK_PDRIVE
value|0x16
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_SENSE_BLINK_PDRIVE
value|0x17
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_SOFT_RESET
value|0x40
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_FLUSH_CACHE
value|0xc2
end_define

begin_define
define|#
directive|define
name|CISS_BMIC_ACCEPT_MEDIA
value|0xe0
end_define

begin_comment
comment|/*  * When numbering drives, the original design assumed that  * drives 0-7 are on the first SCSI bus, 8-15 on the second,  * and so forth.  In order to handle modern SCSI configurations,  * the MSB is set in the drive ID field, in which case the  * modulus changes from 8 to the number of supported drives  * per SCSI bus (as obtained from the ID_CTLR command).  * This feature is referred to as BIG_MAP support, and we assume  * that all CISS controllers support it.  */
end_comment

begin_define
define|#
directive|define
name|CISS_BIG_MAP_ID
parameter_list|(
name|sc
parameter_list|,
name|bus
parameter_list|,
name|target
parameter_list|)
define|\
value|(0x80 | 					\ 	 ((sc)->ciss_id->drives_per_scsi_bus * (bus)) |	\ 	 (target))
end_define

begin_define
define|#
directive|define
name|CISS_BIG_MAP_BUS
parameter_list|(
name|sc
parameter_list|,
name|id
parameter_list|)
define|\
value|(((id)& 0x80) ? (((id)& ~0x80) / (sc)->ciss_id->drives_per_scsi_bus) : -1)
end_define

begin_define
define|#
directive|define
name|CISS_BIG_MAP_TARGET
parameter_list|(
name|sc
parameter_list|,
name|id
parameter_list|)
define|\
value|(((id)& 0x80) ? (((id)& ~0x80) % (sc)->ciss_id->drives_per_scsi_bus) : -1)
end_define

begin_define
define|#
directive|define
name|CISS_BIG_MAP_ENTRIES
value|128
end_define

begin_comment
comment|/* number of entries in a BIG_MAP */
end_comment

begin_comment
comment|/*  * In the device address of a logical volume, the bus number  * is encoded into the logical lun volume number starting  * at the second byte, with the first byte defining the  * logical drive number.  */
end_comment

begin_define
define|#
directive|define
name|CISS_LUN_TO_BUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|CISS_LUN_TO_TARGET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_comment
comment|/*  * BMIC CDB  *  * Note that the phys_drive/res1 field is nominally the 32-bit  * "block number" field, but the only BMIC command(s) of interest  * implemented overload the MSB (note big-endian format here)  * to be the physical drive ID, so we define accordingly.  */
end_comment

begin_struct
struct|struct
name|ciss_bmic_cdb
block|{
name|u_int8_t
name|opcode
decl_stmt|;
name|u_int8_t
name|log_drive
decl_stmt|;
name|u_int8_t
name|phys_drive
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|bmic_opcode
decl_stmt|;
name|u_int16_t
name|size
decl_stmt|;
comment|/* big-endian */
name|u_int8_t
name|res2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * BMIC command command/return structures.  */
end_comment

begin_comment
comment|/* CISS_BMIC_ID_LDRIVE */
end_comment

begin_struct
struct|struct
name|ciss_bmic_id_ldrive
block|{
name|u_int16_t
name|block_size
decl_stmt|;
name|u_int32_t
name|blocks_available
decl_stmt|;
name|u_int8_t
name|drive_parameter_table
index|[
literal|16
index|]
decl_stmt|;
comment|/* XXX define */
name|u_int8_t
name|fault_tolerance
decl_stmt|;
define|#
directive|define
name|CISS_LDRIVE_RAID0
value|0
define|#
directive|define
name|CISS_LDRIVE_RAID4
value|1
define|#
directive|define
name|CISS_LDRIVE_RAID1
value|2
define|#
directive|define
name|CISS_LDRIVE_RAID5
value|3
define|#
directive|define
name|CISS_LDRIVE_RAID51
value|4
define|#
directive|define
name|CISS_LDRIVE_RAIDADG
value|5
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|bios_disable_flag
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
name|u_int32_t
name|logical_drive_identifier
decl_stmt|;
name|char
name|logical_drive_label
index|[
literal|64
index|]
decl_stmt|;
name|u_int64_t
name|big_blocks_available
decl_stmt|;
name|u_int8_t
name|res3
index|[
literal|410
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CISS_BMIC_ID_LSTATUS */
end_comment

begin_struct
struct|struct
name|ciss_bmic_id_lstatus
block|{
name|u_int8_t
name|status
decl_stmt|;
define|#
directive|define
name|CISS_LSTATUS_OK
value|0
define|#
directive|define
name|CISS_LSTATUS_FAILED
value|1
define|#
directive|define
name|CISS_LSTATUS_NOT_CONFIGURED
value|2
define|#
directive|define
name|CISS_LSTATUS_INTERIM_RECOVERY
value|3
define|#
directive|define
name|CISS_LSTATUS_READY_RECOVERY
value|4
define|#
directive|define
name|CISS_LSTATUS_RECOVERING
value|5
define|#
directive|define
name|CISS_LSTATUS_WRONG_PDRIVE
value|6
define|#
directive|define
name|CISS_LSTATUS_MISSING_PDRIVE
value|7
define|#
directive|define
name|CISS_LSTATUS_EXPANDING
value|10
define|#
directive|define
name|CISS_LSTATUS_BECOMING_READY
value|11
define|#
directive|define
name|CISS_LSTATUS_QUEUED_FOR_EXPANSION
value|12
name|u_int32_t
name|deprecated_drive_failure_map
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|416
index|]
decl_stmt|;
name|u_int32_t
name|blocks_to_recover
decl_stmt|;
name|u_int8_t
name|deprecated_drive_rebuilding
decl_stmt|;
name|u_int16_t
name|deprecated_remap_count
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|deprecated_replacement_map
decl_stmt|;
name|u_int32_t
name|deprecated_active_spare_map
decl_stmt|;
name|u_int8_t
name|spare_configured
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|spare_rebuilding
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|spare_rebuilt
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|spare_failed
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|spare_switched
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|spare_available
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res2
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|deprecated_spare_to_replace_map
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|deprecated_replaced_marked_ok_map
decl_stmt|;
name|u_int8_t
name|media_exchanged
decl_stmt|;
name|u_int8_t
name|cache_failure
decl_stmt|;
name|u_int8_t
name|expand_failure
decl_stmt|;
name|u_int8_t
name|rebuild_read_failure
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|rebuild_write_failure
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res3
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|drive_failure_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|remap_count
index|[
name|CISS_BIG_MAP_ENTRIES
index|]
decl_stmt|;
name|u_int8_t
name|replacement_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|active_spare_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|spare_to_replace_map
index|[
name|CISS_BIG_MAP_ENTRIES
index|]
decl_stmt|;
name|u_int8_t
name|replaced_marked_ok_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|drive_rebuilding
decl_stmt|;
name|u_int64_t
name|big_blocks_to_recover
decl_stmt|;
name|u_int8_t
name|res4
index|[
literal|28
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CISS_BMIC_ID_CTLR */
end_comment

begin_struct
struct|struct
name|ciss_bmic_id_table
block|{
name|u_int8_t
name|configured_logical_drives
decl_stmt|;
name|u_int32_t
name|config_signature
decl_stmt|;
name|char
name|running_firmware_revision
index|[
literal|4
index|]
decl_stmt|;
name|char
name|stored_firmware_revision
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|hardware_revision
decl_stmt|;
name|u_int8_t
name|boot_block_revision
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|deprecated_drive_present_map
decl_stmt|;
name|u_int32_t
name|deprecated_external_drive_present_map
decl_stmt|;
name|u_int32_t
name|board_id
decl_stmt|;
name|u_int8_t
name|swapped_error_cable
decl_stmt|;
name|u_int32_t
name|deprecated_non_disk_map
decl_stmt|;
name|u_int8_t
name|bad_host_ram_addr
decl_stmt|;
name|u_int8_t
name|cpu_revision
decl_stmt|;
name|u_int8_t
name|res3
index|[
literal|3
index|]
decl_stmt|;
name|char
name|marketting_revision
decl_stmt|;
name|u_int8_t
name|controller_flags
decl_stmt|;
define|#
directive|define
name|CONTROLLER_FLAGS_FLASH_ROM_INSTALLED
value|0x01
define|#
directive|define
name|CONTROLLER_FLAGS_DIAGS_MODE_BIT
value|0x02
define|#
directive|define
name|CONTROLLER_FLAGS_EXPAND_32MB_FX
value|0x04
define|#
directive|define
name|CONTROLLER_FLAGS_MORE_THAN_7_SUPPORT
value|0x08
define|#
directive|define
name|CONTROLLER_FLAGS_DAISY_SUPPORT_BIT
value|0x10
define|#
directive|define
name|CONTROLLER_FLAGS_RES6
value|0x20
define|#
directive|define
name|CONTROLLER_FLAGS_RES7
value|0x40
define|#
directive|define
name|CONTROLLER_FLAGS_BIG_MAP_SUPPORT
value|0x80
name|u_int8_t
name|host_flags
decl_stmt|;
define|#
directive|define
name|HOST_FLAGS_SDB_ASIC_WORK_AROUND
value|0x01
define|#
directive|define
name|HOST_FLAGS_PCI_DATA_BUS_PARITY_SUPPORT
value|0x02
define|#
directive|define
name|HOST_FLAGS_RES3
value|0x04
define|#
directive|define
name|HOST_FLAGS_RES4
value|0x08
define|#
directive|define
name|HOST_FLAGS_RES5
value|0x10
define|#
directive|define
name|HOST_FLAGS_RES6
value|0x20
define|#
directive|define
name|HOST_FLAGS_RES7
value|0x30
define|#
directive|define
name|HOST_FLAGS_RES8
value|0x40
name|u_int8_t
name|expand_disable_code
decl_stmt|;
define|#
directive|define
name|EXPAND_DISABLE_NOT_NEEDED
value|0x01
define|#
directive|define
name|EXPAND_DISABLE_MISSING_CACHE_BOARD
value|0x02
define|#
directive|define
name|EXPAND_DISABLE_WCXC_FATAL_CACHE_BITS
value|0x04
define|#
directive|define
name|EXPAND_DISABLE_CACHE_PERM_DISABLED
value|0x08
define|#
directive|define
name|EXPAND_DISABLE_RAM_ALLOCATION_FAILED
value|0x10
define|#
directive|define
name|EXPAND_DISABLE_BATTEREIS_DISCHARGED
value|0x20
define|#
directive|define
name|EXPAND_DISABLE_RES7
value|0x40
define|#
directive|define
name|EXPAND_DISABLE_REBUILD_RUNNING
value|0x80
name|u_int8_t
name|scsi_chip_count
decl_stmt|;
name|u_int32_t
name|maximum_blocks
decl_stmt|;
name|u_int32_t
name|controller_clock
decl_stmt|;
name|u_int8_t
name|drives_per_scsi_bus
decl_stmt|;
name|u_int8_t
name|big_drive_present_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_external_drive_present_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_non_disk_map
index|[
name|CISS_BIG_MAP_ENTRIES
operator|/
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|task_flags
decl_stmt|;
comment|/* used for FW debugging */
name|u_int8_t
name|ICL_bus_map
decl_stmt|;
comment|/* Bitmap used for ICL between controllers */
name|u_int8_t
name|redund_ctlr_modes_support
decl_stmt|;
comment|/* See REDUNDANT MODE VALUES */
name|u_int8_t
name|curr_redund_ctlr_mode
decl_stmt|;
name|u_int8_t
name|redund_ctlr_status
decl_stmt|;
name|u_int8_t
name|redund_op_failure_code
decl_stmt|;
name|u_int8_t
name|unsupported_nile_bus
decl_stmt|;
name|u_int8_t
name|host_i2c_autorev
decl_stmt|;
name|u_int8_t
name|cpld_revision
decl_stmt|;
name|u_int8_t
name|fibre_chip_count
decl_stmt|;
name|u_int8_t
name|daughterboard_type
decl_stmt|;
name|u_int8_t
name|more_swapped_config_cable_error
decl_stmt|;
name|u_int8_t
name|license_key_status
decl_stmt|;
name|u_int8_t
name|access_module_status
decl_stmt|;
name|u_int8_t
name|features_supported
index|[
literal|12
index|]
decl_stmt|;
name|u_int8_t
name|rec_rom_inact_rev
index|[
literal|4
index|]
decl_stmt|;
comment|/* Recovery ROM inactive f/w revision  */
name|u_int8_t
name|rec_rom_act_status
decl_stmt|;
comment|/* Recovery ROM flags                  */
name|u_int8_t
name|pci_to_pci_status
decl_stmt|;
comment|/* PCI to PCI bridge status            */
name|u_int32_t
name|redundant_server_info
decl_stmt|;
comment|/* Reserved for future use             */
name|u_int8_t
name|percent_write_cache
decl_stmt|;
comment|/* Percent of memory allocated to write cache */
name|u_int16_t
name|daughterboard_size_mb
decl_stmt|;
comment|/* Total size (MB) of cache board      */
name|u_int8_t
name|cache_batter_count
decl_stmt|;
comment|/* Number of cache batteries           */
name|u_int16_t
name|total_controller_mem_mb
decl_stmt|;
comment|/* Total size (MB) of atttached memory */
name|u_int8_t
name|more_controller_flags
decl_stmt|;
comment|/* Additional controller flags byte    */
name|u_int8_t
name|x_board_host_i2c_rev
decl_stmt|;
comment|/* 2nd byte of 3 byte autorev field    */
name|u_int8_t
name|battery_pic_rev
decl_stmt|;
comment|/* BBWC PIC revision                   */
comment|/*  * Below here I have no documentation on the rest of this data structure.  It is  * inferred from the opensource cciss_vol_status application.  I assume that this   * data strucutre is 512 bytes in total size, do not exceed it.  */
name|u_int8_t
name|bDdffVersion
index|[
literal|4
index|]
decl_stmt|;
comment|/* DDFF update engine version          */
name|u_int16_t
name|usMaxLogicalUnits
decl_stmt|;
comment|/* Maximum logical units supported */
name|u_int16_t
name|usExtLogicalUnitCount
decl_stmt|;
comment|/* Big num configured logical units */
name|u_int16_t
name|usMaxPhysicalDevices
decl_stmt|;
comment|/* Maximum physical devices supported */
name|u_int16_t
name|usMaxPhyDrvPerLogicalUnit
decl_stmt|;
comment|/* Max physical drive per logical unit */
name|u_int8_t
name|bEnclosureCount
decl_stmt|;
comment|/* Number of attached enclosures */
name|u_int8_t
name|bExpanderCount
decl_stmt|;
comment|/* Number of expanders detected */
name|u_int16_t
name|usOffsetToEDPbitmap
decl_stmt|;
comment|/* Offset to extended drive present map*/
name|u_int16_t
name|usOffsetToEEDPbitmap
decl_stmt|;
comment|/* Offset to extended external drive present map */
name|u_int16_t
name|usOffsetToENDbitmap
decl_stmt|;
comment|/* Offset to extended non-disk map */
name|u_int8_t
name|bInternalPortStatus
index|[
literal|8
index|]
decl_stmt|;
comment|/* Internal port status bytes */
name|u_int8_t
name|bExternalPortStatus
index|[
literal|8
index|]
decl_stmt|;
comment|/* External port status bytes */
name|u_int32_t
name|uiYetMoreControllerFlags
decl_stmt|;
comment|/* Yet More Controller flags  */
define|#
directive|define
name|YMORE_CONTROLLER_FLAGS_JBOD_SUPPORTED
define|\
value|( 1<< 25 )
comment|/* Controller has JBOD support */
name|u_int8_t
name|bLastLockup
decl_stmt|;
comment|/* Last lockup code */
name|u_int8_t
name|bSlot
decl_stmt|;
comment|/* PCI slot according to option ROM*/
name|u_int16_t
name|usBuildNum
decl_stmt|;
comment|/* Build number */
name|u_int32_t
name|uiMaxSafeFullStripeSize
decl_stmt|;
comment|/* Maximum safe full stripe size */
name|u_int32_t
name|uiTotalLength
decl_stmt|;
comment|/* Total structure length */
name|u_int8_t
name|bVendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor ID */
name|u_int8_t
name|bProductID
index|[
literal|16
index|]
decl_stmt|;
comment|/* Product ID */
comment|/*  * These are even more obscure as they seem to only be available in cciss_vol_status  */
name|u_int32_t
name|ExtendedLastLockupCode
decl_stmt|;
name|u_int16_t
name|MaxRaid
decl_stmt|;
name|u_int16_t
name|MaxParity
decl_stmt|;
name|u_int16_t
name|MaxADGStripSize
decl_stmt|;
name|u_int16_t
name|YetMoreSwappedCables
decl_stmt|;
name|u_int8_t
name|MaxDevicePaths
decl_stmt|;
name|u_int8_t
name|PowerUPNvramFlags
decl_stmt|;
define|#
directive|define
name|PWR_UP_FLAG_JBOD_ENABLED
value|0x08
comment|/*JBOD mode is enabled, all RAID features off */
name|u_int16_t
name|ZonedOffset
decl_stmt|;
name|u_int32_t
name|FixedFieldsLength
decl_stmt|;
name|u_int8_t
name|FWCompileTimeStamp
index|[
literal|24
index|]
decl_stmt|;
name|u_int32_t
name|EvenMoreControllerFlags
decl_stmt|;
name|u_int8_t
name|padding
index|[
literal|240
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CISS_BMIC_ID_PDRIVE */
end_comment

begin_struct
struct|struct
name|ciss_bmic_id_pdrive
block|{
name|u_int8_t
name|scsi_bus
decl_stmt|;
name|u_int8_t
name|scsi_id
decl_stmt|;
name|u_int16_t
name|block_size
decl_stmt|;
name|u_int32_t
name|total_blocks
decl_stmt|;
name|u_int32_t
name|reserved_blocks
decl_stmt|;
name|char
name|model
index|[
literal|40
index|]
decl_stmt|;
name|char
name|serial
index|[
literal|40
index|]
decl_stmt|;
name|char
name|revision
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|inquiry_bits
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|drive_present
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|non_disk
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|wide
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|synchronous
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|narrow
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|wide_downgraded_to_narrow
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ultra
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ultra2
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SMART
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SMART_errors_recorded
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SMART_errors_enabled
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|SMART_errors_detected
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|external
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|configured
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|configured_spare
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|cache_saved_enabled
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|res3
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|cache_currently_enabled
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|cache_safe
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res4
index|[
literal|5
index|]
decl_stmt|;
name|char
name|connector
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|res5
decl_stmt|;
name|u_int8_t
name|bay
decl_stmt|;
name|u_int16_t
name|rpm
decl_stmt|;
name|u_int8_t
name|drive_type
decl_stmt|;
name|u_int8_t
name|res6
index|[
literal|393
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CISS_BMIC_BLINK_PDRIVE */
end_comment

begin_comment
comment|/* CISS_BMIC_SENSE_BLINK_PDRIVE */
end_comment

begin_struct
struct|struct
name|ciss_bmic_blink_pdrive
block|{
name|u_int32_t
name|blink_duration
decl_stmt|;
comment|/* 10ths of a second */
name|u_int32_t
name|duration_elapsed
decl_stmt|;
comment|/* only for sense command  */
name|u_int8_t
name|blinktab
index|[
literal|256
index|]
decl_stmt|;
define|#
directive|define
name|CISS_BMIC_BLINK_ALL
value|1
define|#
directive|define
name|CISS_BMIC_BLINK_TIMED
value|2
name|u_int8_t
name|res2
index|[
literal|248
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CISS_BMIC_FLUSH_CACHE */
end_comment

begin_struct
struct|struct
name|ciss_bmic_flush_cache
block|{
name|u_int16_t
name|flag
decl_stmt|;
define|#
directive|define
name|CISS_BMIC_FLUSH_AND_ENABLE
value|0
define|#
directive|define
name|CISS_BMIC_FLUSH_AND_DISABLE
value|1
name|u_int8_t
name|res1
index|[
literal|510
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * CISS "simple" transport layer.  *  * Note that there are two slightly different versions of this interface  * with different interrupt mask bits.  There's nothing like consistency...  */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_BAR_REGS
value|0x10
end_define

begin_comment
comment|/* BAR pointing to register space */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_BAR_CFG
value|0x14
end_define

begin_comment
comment|/* BAR pointing to space containing config table */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_IDBR
value|0x20
end_define

begin_comment
comment|/* inbound doorbell register */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_IDBR_CFG_TABLE
value|(1<<0)
end_define

begin_comment
comment|/* notify controller of config table update */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_ISR
value|0x30
end_define

begin_comment
comment|/* interrupt status register */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_IMR
value|0x34
end_define

begin_comment
comment|/* interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_INTR_OPQ_SA5
value|(1<<3)
end_define

begin_comment
comment|/* OPQ not empty interrupt, SA5 boards */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_INTR_OPQ_SA5B
value|(1<<2)
end_define

begin_comment
comment|/* OPQ not empty interrupt, SA5B boards */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_IPQ
value|0x40
end_define

begin_comment
comment|/* inbound post queue */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_OPQ
value|0x44
end_define

begin_comment
comment|/* outbound post queue */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_OPQ_EMPTY
value|(~(u_int32_t)0)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_OSR
value|0x9c
end_define

begin_comment
comment|/* outbound status register */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_ODC
value|0xa0
end_define

begin_comment
comment|/* outbound doorbell clear register */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_ODC_CLEAR
value|(0x1)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_CFG_BAR
value|0xb4
end_define

begin_comment
comment|/* should be 0x14 */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_CFG_OFF
value|0xb8
end_define

begin_comment
comment|/* offset in BAR at which config table is located */
end_comment

begin_comment
comment|/*  * Register access primitives.  */
end_comment

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_READ
parameter_list|(
name|sc
parameter_list|,
name|ofs
parameter_list|)
define|\
value|bus_space_read_4(sc->ciss_regs_btag, sc->ciss_regs_bhandle, ofs)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_WRITE
parameter_list|(
name|sc
parameter_list|,
name|ofs
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->ciss_regs_btag, sc->ciss_regs_bhandle, ofs, val)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_POST_CMD
parameter_list|(
name|sc
parameter_list|,
name|phys
parameter_list|)
value|CISS_TL_SIMPLE_WRITE(sc, CISS_TL_SIMPLE_IPQ, phys)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_FETCH_CMD
parameter_list|(
name|sc
parameter_list|)
value|CISS_TL_SIMPLE_READ(sc, CISS_TL_SIMPLE_OPQ)
end_define

begin_define
define|#
directive|define
name|CISS_TL_PERF_INTR_OPQ
value|(CISS_TL_SIMPLE_INTR_OPQ_SA5 | CISS_TL_SIMPLE_INTR_OPQ_SA5B)
end_define

begin_define
define|#
directive|define
name|CISS_TL_PERF_INTR_MSI
value|0x01
end_define

begin_define
define|#
directive|define
name|CISS_TL_PERF_POST_CMD
parameter_list|(
name|sc
parameter_list|,
name|cr
parameter_list|)
value|CISS_TL_SIMPLE_WRITE(sc, CISS_TL_SIMPLE_IPQ, cr->cr_ccphys | (cr)->cr_sg_tag)
end_define

begin_define
define|#
directive|define
name|CISS_TL_PERF_FLUSH_INT
parameter_list|(
name|sc
parameter_list|)
value|CISS_TL_SIMPLE_READ(sc, CISS_TL_SIMPLE_OSR)
end_define

begin_define
define|#
directive|define
name|CISS_TL_PERF_CLEAR_INT
parameter_list|(
name|sc
parameter_list|)
value|CISS_TL_SIMPLE_WRITE(sc, CISS_TL_SIMPLE_ODC, CISS_TL_SIMPLE_ODC_CLEAR)
end_define

begin_define
define|#
directive|define
name|CISS_CYCLE_MASK
value|0x00000001
end_define

begin_comment
comment|/* Only need one MSI/MSI-X vector */
end_comment

begin_define
define|#
directive|define
name|CISS_MSI_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_DISABLE_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
define|\
value|CISS_TL_SIMPLE_WRITE(sc, CISS_TL_SIMPLE_IMR, \ 			     CISS_TL_SIMPLE_READ(sc, CISS_TL_SIMPLE_IMR) | (sc)->ciss_interrupt_mask)
end_define

begin_define
define|#
directive|define
name|CISS_TL_SIMPLE_ENABLE_INTERRUPTS
parameter_list|(
name|sc
parameter_list|)
define|\
value|CISS_TL_SIMPLE_WRITE(sc, CISS_TL_SIMPLE_IMR, \ 			     CISS_TL_SIMPLE_READ(sc, CISS_TL_SIMPLE_IMR)& ~(sc)->ciss_interrupt_mask)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

