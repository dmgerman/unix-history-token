begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_CL_FWIF_H
end_ifndef

begin_define
define|#
directive|define
name|TW_CL_FWIF_H
end_define

begin_comment
comment|/*  * Macros and data structures for interfacing with the firmware.  */
end_comment

begin_comment
comment|/* Register offsets from base address. */
end_comment

begin_define
define|#
directive|define
name|TWA_CONTROL_REGISTER_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_REGISTER_OFFSET
value|0x4
end_define

begin_define
define|#
directive|define
name|TWA_COMMAND_QUEUE_OFFSET
value|0x8
end_define

begin_define
define|#
directive|define
name|TWA_RESPONSE_QUEUE_OFFSET
value|0xC
end_define

begin_define
define|#
directive|define
name|TWA_COMMAND_QUEUE_OFFSET_LOW
value|0x20
end_define

begin_define
define|#
directive|define
name|TWA_COMMAND_QUEUE_OFFSET_HIGH
value|0x24
end_define

begin_define
define|#
directive|define
name|TWA_LARGE_RESPONSE_QUEUE_OFFSET
value|0x30
end_define

begin_comment
comment|/* Control register bit definitions. */
end_comment

begin_define
define|#
directive|define
name|TWA_CONTROL_ISSUE_HOST_INTERRUPT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_DISABLE_INTERRUPTS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_ENABLE_INTERRUPTS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_ISSUE_SOFT_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_UNMASK_RESPONSE_INTERRUPT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_UNMASK_COMMAND_INTERRUPT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_MASK_RESPONSE_INTERRUPT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_MASK_COMMAND_INTERRUPT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_ATTENTION_INTERRUPT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_HOST_INTERRUPT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_PCI_ABORT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_QUEUE_ERROR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_PARITY_ERROR
value|0x00800000
end_define

begin_comment
comment|/* Status register bit definitions. */
end_comment

begin_define
define|#
directive|define
name|TWA_STATUS_ROM_BIOS_IN_SBUF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_COMMAND_QUEUE_EMPTY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_MICROCONTROLLER_READY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_RESPONSE_QUEUE_EMPTY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_COMMAND_QUEUE_FULL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_RESPONSE_INTERRUPT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_COMMAND_INTERRUPT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_ATTENTION_INTERRUPT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_HOST_INTERRUPT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_PCI_ABORT_INTERRUPT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_MICROCONTROLLER_ERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_QUEUE_ERROR_INTERRUPT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_PCI_PARITY_ERROR_INTERRUPT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_MINOR_VERSION_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_MAJOR_VERSION_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_EXPECTED_BITS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TWA_STATUS_UNEXPECTED_BITS
value|0x00F00000
end_define

begin_comment
comment|/* PCI related defines. */
end_comment

begin_define
define|#
directive|define
name|TWA_IO_CONFIG_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|TWA_PCI_CONFIG_CLEAR_PARITY_ERROR
value|0xc100
end_define

begin_define
define|#
directive|define
name|TWA_PCI_CONFIG_CLEAR_PCI_ABORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|TWA_RESET_PHASE1_NOTIFICATION_RESPONSE
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|TWA_RESET_PHASE1_WAIT_TIME_MS
value|500
end_define

begin_comment
comment|/* Command packet opcodes. */
end_comment

begin_define
define|#
directive|define
name|TWA_FW_CMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_INIT_CONNECTION
value|0x01
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_WRITE
value|0x03
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_READVERIFY
value|0x04
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_VERIFY
value|0x05
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_ZEROUNIT
value|0x08
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_REPLACEUNIT
value|0x09
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_HOTSWAP
value|0x0A
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_SELFTESTS
value|0x0B
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_SYNC_PARAM
value|0x0C
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_REORDER_UNITS
value|0x0D
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_EXECUTE_SCSI
value|0x10
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_ATA_PASSTHROUGH
value|0x11
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_GET_PARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_SET_PARAM
value|0x13
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_CREATEUNIT
value|0x14
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_DELETEUNIT
value|0x15
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_DOWNLOAD_FIRMWARE
value|0x16
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_REBUILDUNIT
value|0x17
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_POWER_MANAGEMENT
value|0x18
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_REMOTE_PRINT
value|0x1B
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_HARD_RESET_FIRMWARE
value|0x1C
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_DEBUG
value|0x1D
end_define

begin_define
define|#
directive|define
name|TWA_FW_CMD_DIAGNOSTICS
value|0x1F
end_define

begin_comment
comment|/* Misc defines. */
end_comment

begin_define
define|#
directive|define
name|TWA_SHUTDOWN_MESSAGE_CREDITS
value|0x001
end_define

begin_define
define|#
directive|define
name|TWA_64BIT_SG_ADDRESSES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TWA_EXTENDED_INIT_CONNECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TWA_BASE_MODE
value|1
end_define

begin_define
define|#
directive|define
name|TWA_BASE_FW_SRL
value|24
end_define

begin_define
define|#
directive|define
name|TWA_BASE_FW_BRANCH
value|0
end_define

begin_define
define|#
directive|define
name|TWA_BASE_FW_BUILD
value|1
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_SRL
value|30
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BRANCH_9K
value|4
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BUILD_9K
value|8
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BRANCH_9K_X
value|8
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BUILD_9K_X
value|4
end_define

begin_define
define|#
directive|define
name|TWA_MULTI_LUN_FW_SRL
value|28
end_define

begin_define
define|#
directive|define
name|TWA_ARCH_ID_9K
value|0x5
end_define

begin_comment
comment|/* 9000 PCI controllers */
end_comment

begin_define
define|#
directive|define
name|TWA_ARCH_ID_9K_X
value|0x6
end_define

begin_comment
comment|/* 9000 PCI-X controllers */
end_comment

begin_define
define|#
directive|define
name|TWA_CTLR_FW_SAME_OR_NEWER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TWA_CTLR_FW_COMPATIBLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TWA_SENSE_DATA_LENGTH
value|18
end_define

begin_define
define|#
directive|define
name|TWA_ARCH_ID
parameter_list|(
name|device_id
parameter_list|)
define|\
value|(((device_id) == TW_CL_DEVICE_ID_9K) ? TWA_ARCH_ID_9K :		\ 	TWA_ARCH_ID_9K_X)
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BRANCH
parameter_list|(
name|arch_id
parameter_list|)
define|\
value|(((arch_id) == TWA_ARCH_ID_9K) ? TWA_CURRENT_FW_BRANCH_9K :	\ 	TWA_CURRENT_FW_BRANCH_9K_X)
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BUILD
parameter_list|(
name|arch_id
parameter_list|)
define|\
value|(((arch_id) == TWA_ARCH_ID_9K) ? TWA_CURRENT_FW_BUILD_9K :	\ 	TWA_CURRENT_FW_BUILD_9K_X)
end_define

begin_comment
comment|/*  * All SG addresses and DMA'able memory allocated by the OSL should be  * TWA_ALIGNMENT bytes aligned, and have a size that is a multiple of  * TWA_SG_ELEMENT_SIZE_FACTOR.  */
end_comment

begin_define
define|#
directive|define
name|TWA_ALIGNMENT
parameter_list|(
name|device_id
parameter_list|)
value|0x4
end_define

begin_define
define|#
directive|define
name|TWA_SG_ELEMENT_SIZE_FACTOR
parameter_list|(
name|device_id
parameter_list|)
define|\
value|(((device_id) == TW_CL_DEVICE_ID_9K) ? 512 : 4)
end_define

begin_comment
comment|/*  * Some errors of interest (in cmd_hdr->status_block.error) when a command  * is completed by the firmware with a bad status.  */
end_comment

begin_define
define|#
directive|define
name|TWA_ERROR_LOGICAL_UNIT_NOT_SUPPORTED
value|0x010a
end_define

begin_define
define|#
directive|define
name|TWA_ERROR_UNIT_OFFLINE
value|0x0128
end_define

begin_define
define|#
directive|define
name|TWA_ERROR_MORE_DATA
value|0x0231
end_define

begin_comment
comment|/* AEN codes of interest. */
end_comment

begin_define
define|#
directive|define
name|TWA_AEN_QUEUE_EMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|TWA_AEN_SOFT_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|TWA_AEN_SYNC_TIME_WITH_HOST
value|0x31
end_define

begin_comment
comment|/* Table #'s and id's of parameters of interest in firmware's param table. */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_TABLE
value|0x0402
end_define

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_FW
value|3
end_define

begin_comment
comment|/* firmware version [16] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_BIOS
value|4
end_define

begin_comment
comment|/* BIOSs version [16] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_CTLR_MODEL
value|8
end_define

begin_comment
comment|/* Controller model [16] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_CONTROLLER_TABLE
value|0x0403
end_define

begin_define
define|#
directive|define
name|TWA_PARAM_CONTROLLER_PORT_COUNT
value|3
end_define

begin_comment
comment|/* number of ports [1] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_TIME_TABLE
value|0x40A
end_define

begin_define
define|#
directive|define
name|TWA_PARAM_TIME_SCHED_TIME
value|0x3
end_define

begin_define
define|#
directive|define
name|TWA_9K_PARAM_DESCRIPTOR
value|0x8000
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/* 7000 structures. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_init_connect
block|{
name|TW_UINT8
name|res1__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|size
decl_stmt|;
name|TW_UINT8
name|request_id
decl_stmt|;
name|TW_UINT8
name|res2
decl_stmt|;
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|flags
decl_stmt|;
name|TW_UINT16
name|message_credits
decl_stmt|;
name|TW_UINT32
name|features
decl_stmt|;
name|TW_UINT16
name|fw_srl
decl_stmt|;
name|TW_UINT16
name|fw_arch_id
decl_stmt|;
name|TW_UINT16
name|fw_branch
decl_stmt|;
name|TW_UINT16
name|fw_build
decl_stmt|;
name|TW_UINT32
name|result
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for downloading firmware onto the controller. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_download_firmware
block|{
name|TW_UINT8
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|size
decl_stmt|;
name|TW_UINT8
name|request_id
decl_stmt|;
name|TW_UINT8
name|unit
decl_stmt|;
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|flags
decl_stmt|;
name|TW_UINT16
name|param
decl_stmt|;
name|TW_UINT8
name|sgl
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for hard resetting the controller. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_reset_firmware
block|{
name|TW_UINT8
name|res1__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|size
decl_stmt|;
name|TW_UINT8
name|request_id
decl_stmt|;
name|TW_UINT8
name|unit
decl_stmt|;
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|flags
decl_stmt|;
name|TW_UINT8
name|res2
decl_stmt|;
name|TW_UINT8
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for sending get/set param commands. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_param
block|{
name|TW_UINT8
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|size
decl_stmt|;
name|TW_UINT8
name|request_id
decl_stmt|;
name|TW_UINT8
name|host_id__unit
decl_stmt|;
comment|/* 4:4 */
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|flags
decl_stmt|;
name|TW_UINT16
name|param_count
decl_stmt|;
name|TW_UINT8
name|sgl
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Generic command packet. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_generic
block|{
name|TW_UINT8
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|size
decl_stmt|;
name|TW_UINT8
name|request_id
decl_stmt|;
name|TW_UINT8
name|host_id__unit
decl_stmt|;
comment|/* 4:4 */
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|flags
decl_stmt|;
name|TW_UINT16
name|count
decl_stmt|;
comment|/* block cnt, parameter cnt, message credits */
block|}
struct|;
end_struct

begin_comment
comment|/* Command packet header. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_header
block|{
name|TW_UINT8
name|sense_data
index|[
name|TWA_SENSE_DATA_LENGTH
index|]
decl_stmt|;
struct|struct
block|{
name|TW_INT8
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|TW_UINT16
name|error
decl_stmt|;
name|TW_UINT8
name|padding
decl_stmt|;
name|TW_UINT8
name|res__severity
decl_stmt|;
comment|/* 5:3 */
block|}
name|status_block
struct|;
name|TW_UINT8
name|err_specific_desc
index|[
literal|98
index|]
decl_stmt|;
struct|struct
block|{
name|TW_UINT8
name|size_header
decl_stmt|;
name|TW_UINT16
name|reserved
decl_stmt|;
name|TW_UINT8
name|size_sense
decl_stmt|;
block|}
name|header_desc
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* 7000 Command packet. */
end_comment

begin_union
union|union
name|tw_cl_command_7k
block|{
name|struct
name|tw_cl_command_init_connect
name|init_connect
decl_stmt|;
name|struct
name|tw_cl_command_download_firmware
name|download_fw
decl_stmt|;
name|struct
name|tw_cl_command_reset_firmware
name|reset_fw
decl_stmt|;
name|struct
name|tw_cl_command_param
name|param
decl_stmt|;
name|struct
name|tw_cl_command_generic
name|generic
decl_stmt|;
name|TW_UINT8
name|padding
index|[
literal|1024
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|tw_cl_command_header
argument_list|)
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* 9000 Command Packet. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_9k
block|{
name|TW_UINT8
name|res__opcode
decl_stmt|;
comment|/* 3:5 */
name|TW_UINT8
name|unit
decl_stmt|;
name|TW_UINT16
name|lun_l4__req_id
decl_stmt|;
comment|/* 4:12 */
name|TW_UINT8
name|status
decl_stmt|;
name|TW_UINT8
name|sgl_offset
decl_stmt|;
comment|/* offset (in bytes) to sg_list, from the 					end of sgl_entries */
name|TW_UINT16
name|lun_h4__sgl_entries
decl_stmt|;
name|TW_UINT8
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|TW_UINT8
name|sg_list
index|[
literal|872
index|]
decl_stmt|;
comment|/* total struct size = 					1024-sizeof(cmd_hdr) */
block|}
struct|;
end_struct

begin_comment
comment|/* Full command packet. */
end_comment

begin_struct
struct|struct
name|tw_cl_command_packet
block|{
name|struct
name|tw_cl_command_header
name|cmd_hdr
decl_stmt|;
union|union
block|{
name|union
name|tw_cl_command_7k
name|cmd_pkt_7k
decl_stmt|;
name|struct
name|tw_cl_command_9k
name|cmd_pkt_9k
decl_stmt|;
block|}
name|command
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing payload for get/set param commands. */
end_comment

begin_struct
struct|struct
name|tw_cl_param_9k
block|{
name|TW_UINT16
name|table_id
decl_stmt|;
name|TW_UINT8
name|parameter_id
decl_stmt|;
name|TW_UINT8
name|reserved
decl_stmt|;
name|TW_UINT16
name|parameter_size_bytes
decl_stmt|;
name|TW_UINT16
name|parameter_actual_size_bytes
decl_stmt|;
name|TW_UINT8
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* Functions to read from, and write to registers */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_WRITE_CONTROL_REGISTER
parameter_list|(
name|ctlr_handle
parameter_list|,
name|value
parameter_list|)
define|\
value|tw_osl_write_reg(ctlr_handle, TWA_CONTROL_REGISTER_OFFSET, value, 4)
end_define

begin_define
define|#
directive|define
name|TW_CLI_READ_STATUS_REGISTER
parameter_list|(
name|ctlr_handle
parameter_list|)
define|\
value|tw_osl_read_reg(ctlr_handle, TWA_STATUS_REGISTER_OFFSET, 4)
end_define

begin_define
define|#
directive|define
name|TW_CLI_WRITE_COMMAND_QUEUE
parameter_list|(
name|ctlr_handle
parameter_list|,
name|value
parameter_list|)
value|do {		\ 	if (ctlr->flags& TW_CL_64BIT_ADDRESSES) {			\
comment|/* First write the low 4 bytes, then the high 4. */
value|\ 		tw_osl_write_reg(ctlr_handle, TWA_COMMAND_QUEUE_OFFSET_LOW, \ 			(TW_UINT32)(value), 4);				\ 		tw_osl_write_reg(ctlr_handle, TWA_COMMAND_QUEUE_OFFSET_HIGH,\ 			(TW_UINT32)(((TW_UINT64)value)>>32), 4);	\ 	} else								\ 		tw_osl_write_reg(ctlr_handle, TWA_COMMAND_QUEUE_OFFSET,	\ 					(TW_UINT32)(value), 4);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|TW_CLI_READ_RESPONSE_QUEUE
parameter_list|(
name|ctlr_handle
parameter_list|)
define|\
value|tw_osl_read_reg(ctlr_handle, TWA_RESPONSE_QUEUE_OFFSET, 4)
end_define

begin_define
define|#
directive|define
name|TW_CLI_READ_LARGE_RESPONSE_QUEUE
parameter_list|(
name|ctlr_handle
parameter_list|)
define|\
value|tw_osl_read_reg(ctlr_handle, TWA_LARGE_RESPONSE_QUEUE_OFFSET, 4)
end_define

begin_define
define|#
directive|define
name|TW_CLI_SOFT_RESET
parameter_list|(
name|ctlr
parameter_list|)
define|\
value|TW_CLI_WRITE_CONTROL_REGISTER(ctlr,			\ 		TWA_CONTROL_ISSUE_SOFT_RESET |			\ 		TWA_CONTROL_CLEAR_HOST_INTERRUPT |		\ 		TWA_CONTROL_CLEAR_ATTENTION_INTERRUPT |		\ 		TWA_CONTROL_MASK_COMMAND_INTERRUPT |		\ 		TWA_CONTROL_MASK_RESPONSE_INTERRUPT |		\ 		TWA_CONTROL_DISABLE_INTERRUPTS)
end_define

begin_comment
comment|/* Detect inconsistencies in the status register. */
end_comment

begin_define
define|#
directive|define
name|TW_CLI_STATUS_ERRORS
parameter_list|(
name|x
parameter_list|)
define|\
value|((x& TWA_STATUS_UNEXPECTED_BITS)&&			\ 	 (x& TWA_STATUS_MICROCONTROLLER_READY))
end_define

begin_comment
comment|/*  * Functions for making transparent, the bit fields in firmware  * interface structures.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_SGL_OFF__OPCODE
parameter_list|(
name|sgl_off
parameter_list|,
name|opcode
parameter_list|)
define|\
value|((sgl_off<< 5)& 0xE0) | (opcode& 0x1F)
end_define

begin_comment
comment|/* 3:5 */
end_comment

begin_define
define|#
directive|define
name|BUILD_RES__OPCODE
parameter_list|(
name|res
parameter_list|,
name|opcode
parameter_list|)
define|\
value|((res<< 5)& 0xE0) | (opcode& 0x1F)
end_define

begin_comment
comment|/* 3:5 */
end_comment

begin_define
define|#
directive|define
name|BUILD_HOST_ID__UNIT
parameter_list|(
name|host_id
parameter_list|,
name|unit
parameter_list|)
define|\
value|((host_id<< 4)& 0xF0) | (unit& 0xF)
end_define

begin_comment
comment|/* 4:4 */
end_comment

begin_define
define|#
directive|define
name|BUILD_RES__SEVERITY
parameter_list|(
name|res
parameter_list|,
name|severity
parameter_list|)
define|\
value|((res<< 3)& 0xF8) | (severity& 0x7)
end_define

begin_comment
comment|/* 5:3 */
end_comment

begin_define
define|#
directive|define
name|BUILD_LUN_L4__REQ_ID
parameter_list|(
name|lun
parameter_list|,
name|req_id
parameter_list|)
define|\
value|(((lun<< 12)& 0xF000) | (req_id& 0xFFF))
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_define
define|#
directive|define
name|BUILD_LUN_H4__SGL_ENTRIES
parameter_list|(
name|lun
parameter_list|,
name|sgl_entries
parameter_list|)
define|\
value|(((lun<< 8)& 0xF000) | (sgl_entries& 0xFFF))
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_define
define|#
directive|define
name|GET_OPCODE
parameter_list|(
name|sgl_off__opcode
parameter_list|)
define|\
value|(sgl_off__opcode& 0x1F)
end_define

begin_comment
comment|/* 3:5 */
end_comment

begin_define
define|#
directive|define
name|GET_SGL_OFF
parameter_list|(
name|sgl_off__opcode
parameter_list|)
define|\
value|((sgl_off__opcode>> 5)& 0x7)
end_define

begin_comment
comment|/* 3:5 */
end_comment

begin_define
define|#
directive|define
name|GET_UNIT
parameter_list|(
name|host_id__unit
parameter_list|)
define|\
value|(host_id__unit& 0xF)
end_define

begin_comment
comment|/* 4:4 */
end_comment

begin_define
define|#
directive|define
name|GET_HOST_ID
parameter_list|(
name|host_id__unit
parameter_list|)
define|\
value|((host_id__unit>> 4)& 0xF)
end_define

begin_comment
comment|/* 4:4 */
end_comment

begin_define
define|#
directive|define
name|GET_SEVERITY
parameter_list|(
name|res__severity
parameter_list|)
define|\
value|(res__severity& 0x7)
end_define

begin_comment
comment|/* 5:3 */
end_comment

begin_define
define|#
directive|define
name|GET_RESP_ID
parameter_list|(
name|undef2__resp_id__undef1
parameter_list|)
define|\
value|((undef2__resp_id__undef1>> 4)& 0xFF)
end_define

begin_comment
comment|/* 20:8:4 */
end_comment

begin_define
define|#
directive|define
name|GET_RESP_ID_9K_X
parameter_list|(
name|undef2__resp_id
parameter_list|)
define|\
value|((undef2__resp_id)& 0xFFF)
end_define

begin_comment
comment|/* 20:12 */
end_comment

begin_define
define|#
directive|define
name|GET_LARGE_RESP_ID
parameter_list|(
name|misc__large_resp_id
parameter_list|)
define|\
value|((misc__large_resp_id)& 0xFFFF)
end_define

begin_comment
comment|/* 16:16 */
end_comment

begin_define
define|#
directive|define
name|GET_REQ_ID
parameter_list|(
name|lun_l4__req_id
parameter_list|)
define|\
value|(lun_l4__req_id& 0xFFF)
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_define
define|#
directive|define
name|GET_LUN_L4
parameter_list|(
name|lun_l4__req_id
parameter_list|)
define|\
value|((lun_l4__req_id>> 12)& 0xF)
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_define
define|#
directive|define
name|GET_SGL_ENTRIES
parameter_list|(
name|lun_h4__sgl_entries
parameter_list|)
define|\
value|(lun_h4__sgl_entries& 0xFFF)
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_define
define|#
directive|define
name|GET_LUN_H4
parameter_list|(
name|lun_h4__sgl_entries
parameter_list|)
define|\
value|((lun_h4__sgl_entries>> 12)& 0xF)
end_define

begin_comment
comment|/* 4:12 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_CL_FWIF_H */
end_comment

end_unit

