begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-04 3ware, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  */
end_comment

begin_comment
comment|/*  * The following macro has no business being in twa_reg.h.  It should probably  * be defined in twa_includes.h, before the #include twa_reg.h....  But that  * causes the API to run into build errors.  Will leave it here for now...  */
end_comment

begin_define
define|#
directive|define
name|TWA_64BIT_ADDRESSES
value|((sizeof(bus_addr_t) == 8) ? 1 : 0)
end_define

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

begin_comment
comment|/* Functions to read from, and write to registers */
end_comment

begin_define
define|#
directive|define
name|TWA_WRITE_CONTROL_REGISTER
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|TWA_WRITE_REGISTER(sc, TWA_CONTROL_REGISTER_OFFSET, val)
end_define

begin_define
define|#
directive|define
name|TWA_READ_STATUS_REGISTER
parameter_list|(
name|sc
parameter_list|)
define|\
value|TWA_READ_REGISTER(sc, TWA_STATUS_REGISTER_OFFSET)
end_define

begin_define
define|#
directive|define
name|TWA_WRITE_COMMAND_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		if (TWA_64BIT_ADDRESSES) {				\
comment|/* First write the low 4 bytes, then the high 4. */
value|\ 			TWA_WRITE_REGISTER(sc, TWA_COMMAND_QUEUE_OFFSET_LOW, \ 						(u_int32_t)(val));	\ 			TWA_WRITE_REGISTER(sc, TWA_COMMAND_QUEUE_OFFSET_HIGH,\ 					(u_int32_t)(((u_int64_t)val)>>32));  \ 		} else							\ 			TWA_WRITE_REGISTER(sc, TWA_COMMAND_QUEUE_OFFSET,\ 						(u_int32_t)(val)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TWA_READ_RESPONSE_QUEUE
parameter_list|(
name|sc
parameter_list|)
define|\
value|(union twa_response_queue)TWA_READ_REGISTER(sc, TWA_RESPONSE_QUEUE_OFFSET)
end_define

begin_comment
comment|/* Control register bit definitions. */
end_comment

begin_define
define|#
directive|define
name|TWA_CONTROL_CLEAR_SBUF_WRITE_ERROR
value|0x00000008
end_define

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

begin_define
define|#
directive|define
name|TWA_SOFT_RESET
parameter_list|(
name|sc
parameter_list|)
define|\
value|TWA_WRITE_CONTROL_REGISTER(sc,				\ 			TWA_CONTROL_ISSUE_SOFT_RESET |			\ 			TWA_CONTROL_CLEAR_HOST_INTERRUPT |		\ 			TWA_CONTROL_CLEAR_ATTENTION_INTERRUPT |		\ 			TWA_CONTROL_MASK_COMMAND_INTERRUPT |		\ 			TWA_CONTROL_MASK_RESPONSE_INTERRUPT |		\ 			TWA_CONTROL_DISABLE_INTERRUPTS)
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
name|TWA_STATUS_SBUF_WRITE_ERROR
value|0x00000008
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
comment|/* For use with the %b printf format. */
end_comment

begin_define
define|#
directive|define
name|TWA_STATUS_BITS_DESCRIPTION
define|\
value|"\20\15CMD_Q_EMPTY\16MC_RDY\17RESP_Q_EMPTY\20CMD_Q_FULL\21RESP_INTR\22CMD_INTR\23ATTN_INTR\24HOST_INTR\25PCI_ABRT\26MC_ERR\27Q_ERR\30PCI_PERR\n"
end_define

begin_comment
comment|/* Detect inconsistencies in the status register. */
end_comment

begin_define
define|#
directive|define
name|TWA_STATUS_ERRORS
parameter_list|(
name|x
parameter_list|)
define|\
value|((x& TWA_STATUS_UNEXPECTED_BITS)&&	\ 	 (x& TWA_STATUS_MICROCONTROLLER_READY))
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
name|TWA_DEVICE_NAME
value|"3ware 9000 series Storage Controller"
end_define

begin_define
define|#
directive|define
name|TWA_VENDOR_ID
value|0x13C1
end_define

begin_define
define|#
directive|define
name|TWA_DEVICE_ID_9K
value|0x1002
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

begin_comment
comment|/* Command packet opcodes. */
end_comment

begin_define
define|#
directive|define
name|TWA_OP_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|TWA_OP_INIT_CONNECTION
value|0x01
end_define

begin_define
define|#
directive|define
name|TWA_OP_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|TWA_OP_WRITE
value|0x03
end_define

begin_define
define|#
directive|define
name|TWA_OP_READVERIFY
value|0x04
end_define

begin_define
define|#
directive|define
name|TWA_OP_VERIFY
value|0x05
end_define

begin_define
define|#
directive|define
name|TWA_OP_ZEROUNIT
value|0x08
end_define

begin_define
define|#
directive|define
name|TWA_OP_REPLACEUNIT
value|0x09
end_define

begin_define
define|#
directive|define
name|TWA_OP_HOTSWAP
value|0x0A
end_define

begin_define
define|#
directive|define
name|TWA_OP_SELFTESTS
value|0x0B
end_define

begin_define
define|#
directive|define
name|TWA_OP_SYNC_PARAM
value|0x0C
end_define

begin_define
define|#
directive|define
name|TWA_OP_REORDER_UNITS
value|0x0D
end_define

begin_define
define|#
directive|define
name|TWA_OP_EXECUTE_SCSI_COMMAND
value|0x10
end_define

begin_define
define|#
directive|define
name|TWA_OP_ATA_PASSTHROUGH
value|0x11
end_define

begin_define
define|#
directive|define
name|TWA_OP_GET_PARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|TWA_OP_SET_PARAM
value|0x13
end_define

begin_define
define|#
directive|define
name|TWA_OP_CREATEUNIT
value|0x14
end_define

begin_define
define|#
directive|define
name|TWA_OP_DELETEUNIT
value|0x15
end_define

begin_define
define|#
directive|define
name|TWA_OP_DOWNLOAD_FIRMWARE
value|0x16
end_define

begin_define
define|#
directive|define
name|TWA_OP_REBUILDUNIT
value|0x17
end_define

begin_define
define|#
directive|define
name|TWA_OP_POWER_MANAGEMENT
value|0x18
end_define

begin_define
define|#
directive|define
name|TWA_OP_REMOTE_PRINT
value|0x1B
end_define

begin_define
define|#
directive|define
name|TWA_OP_RESET_FIRMWARE
value|0x1C
end_define

begin_define
define|#
directive|define
name|TWA_OP_DEBUG
value|0x1D
end_define

begin_define
define|#
directive|define
name|TWA_OP_DIAGNOSTICS
value|0x1F
end_define

begin_comment
comment|/* Misc defines. */
end_comment

begin_define
define|#
directive|define
name|TWA_BUNDLED_FW_VERSION_STRING
value|"2.04.00.005"
end_define

begin_define
define|#
directive|define
name|TWA_ALIGNMENT
value|0x4
end_define

begin_define
define|#
directive|define
name|TWA_MAX_UNITS
value|16
end_define

begin_define
define|#
directive|define
name|TWA_INIT_MESSAGE_CREDITS
value|0x100
end_define

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
value|23
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
value|27
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BRANCH
value|2
end_define

begin_define
define|#
directive|define
name|TWA_CURRENT_FW_BUILD
value|6
end_define

begin_define
define|#
directive|define
name|TWA_9000_ARCH_ID
value|0x5
end_define

begin_comment
comment|/* 9000 series controllers */
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
name|TWA_BUNDLED_FW_SAFE_TO_FLASH
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TWA_CTLR_FW_RECOMMENDS_FLASH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NUM_FW_IMAGE_CHUNKS
value|5
end_define

begin_define
define|#
directive|define
name|TWA_MAX_IO_SIZE
value|0x20000
end_define

begin_comment
comment|/* 128K */
end_comment

begin_define
define|#
directive|define
name|TWA_MAX_SG_ELEMENTS
value|(TWA_64BIT_ADDRESSES ? 70 : 105)
end_define

begin_define
define|#
directive|define
name|TWA_MAX_ATA_SG_ELEMENTS
value|60
end_define

begin_define
define|#
directive|define
name|TWA_Q_LENGTH
value|TWA_INIT_MESSAGE_CREDITS
end_define

begin_define
define|#
directive|define
name|TWA_MAX_RESET_TRIES
value|3
end_define

begin_define
define|#
directive|define
name|TWA_SECTOR_SIZE
value|0x200
end_define

begin_comment
comment|/* generic I/O bufffer */
end_comment

begin_define
define|#
directive|define
name|TWA_SENSE_DATA_LENGTH
value|18
end_define

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

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/* Scatter/Gather list entry. */
end_comment

begin_struct
struct|struct
name|twa_sg
block|{
name|bus_addr_t
name|address
decl_stmt|;
name|u_int32_t
name|length
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

begin_comment
comment|/* 7000 structures. */
end_comment

begin_struct
struct|struct
name|twa_command_init_connect
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_INITCONNECTION */
name|u_int8_t
name|res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|message_credits
decl_stmt|;
name|u_int32_t
name|features
decl_stmt|;
name|u_int16_t
name|fw_srl
decl_stmt|;
name|u_int16_t
name|fw_arch_id
decl_stmt|;
name|u_int16_t
name|fw_branch
decl_stmt|;
name|u_int16_t
name|fw_build
decl_stmt|;
name|u_int32_t
name|result
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
name|twa_command_download_firmware
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_DOWNLOAD_FIRMWARE */
name|u_int8_t
name|sgl_offset
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|param
decl_stmt|;
name|struct
name|twa_sg
name|sgl
index|[
name|TWA_MAX_SG_ELEMENTS
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
name|twa_command_reset_firmware
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_RESET_FIRMWARE */
name|u_int8_t
name|res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|param
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
name|twa_command_io
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_READ/TWA_OP_WRITE */
name|u_int8_t
name|sgl_offset
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|block_count
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|struct
name|twa_sg
name|sgl
index|[
name|TWA_MAX_SG_ELEMENTS
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
name|twa_command_hotswap
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_HOTSWAP */
name|u_int8_t
name|res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
define|#
directive|define
name|TWA_OP_HOTSWAP_REMOVE
value|0x00
comment|/* remove assumed-degraded unit */
define|#
directive|define
name|TWA_OP_HOTSWAP_ADD_CBOD
value|0x01
comment|/* add CBOD to empty port */
define|#
directive|define
name|TWA_OP_HOTSWAP_ADD_SPARE
value|0x02
comment|/* add spare to empty port */
name|u_int8_t
name|aport
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
name|twa_command_param
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_GETPARAM, TWA_OP_SETPARAM */
name|u_int8_t
name|sgl_offset
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|param_count
decl_stmt|;
name|struct
name|twa_sg
name|sgl
index|[
name|TWA_MAX_SG_ELEMENTS
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
name|twa_command_rebuildunit
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_REBUILDUNIT */
name|u_int8_t
name|res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|src_unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|action
range|:
literal|7
decl_stmt|;
define|#
directive|define
name|TWA_OP_REBUILDUNIT_NOP
value|0
define|#
directive|define
name|TWA_OP_REBUILDUNIT_STOP
value|2
comment|/* stop all rebuilds */
define|#
directive|define
name|TWA_OP_REBUILDUNIT_START
value|4
comment|/* start rebuild with lowest unit */
define|#
directive|define
name|TWA_OP_REBUILDUNIT_STARTUNIT
value|5
comment|/* rebuild src_unit (not supported) */
name|u_int8_t
name|cs
range|:
literal|1
decl_stmt|;
comment|/* request state change on src_unit */
name|u_int8_t
name|logical_subunit
decl_stmt|;
comment|/* for RAID10 rebuild of logical subunit */
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
name|twa_command_ata
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWA_OP_ATA_PASSTHROUGH */
name|u_int8_t
name|sgl_offset
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|param
decl_stmt|;
name|u_int16_t
name|features
decl_stmt|;
name|u_int16_t
name|sector_count
decl_stmt|;
name|u_int16_t
name|sector_num
decl_stmt|;
name|u_int16_t
name|cylinder_lo
decl_stmt|;
name|u_int16_t
name|cylinder_hi
decl_stmt|;
name|u_int8_t
name|drive_head
decl_stmt|;
name|u_int8_t
name|command
decl_stmt|;
name|struct
name|twa_sg
name|sgl
index|[
name|TWA_MAX_ATA_SG_ELEMENTS
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
name|twa_command_generic
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|sgl_offset
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|unit
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_id
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|TWA_FLAGS_SUCCESS
value|0x00
define|#
directive|define
name|TWA_FLAGS_INFORMATIONAL
value|0x01
define|#
directive|define
name|TWA_FLAGS_WARNING
value|0x02
define|#
directive|define
name|TWA_FLAGS_FATAL
value|0x03
define|#
directive|define
name|TWA_FLAGS_PERCENTAGE
value|(1<<8)
comment|/* bits 0-6 indicate completion percentage */
name|u_int16_t
name|count
decl_stmt|;
comment|/* block count, parameter count, message credits */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Command packet - must be TWA_ALIGNMENT aligned. */
end_comment

begin_union
union|union
name|twa_command_7k
block|{
name|struct
name|twa_command_init_connect
name|init_connect
decl_stmt|;
name|struct
name|twa_command_download_firmware
name|download_fw
decl_stmt|;
name|struct
name|twa_command_reset_firmware
name|reset_fw
decl_stmt|;
name|struct
name|twa_command_io
name|io
decl_stmt|;
name|struct
name|twa_command_hotswap
name|hotswap
decl_stmt|;
name|struct
name|twa_command_param
name|param
decl_stmt|;
name|struct
name|twa_command_rebuildunit
name|rebuildunit
decl_stmt|;
name|struct
name|twa_command_ata
name|ata
decl_stmt|;
name|struct
name|twa_command_generic
name|generic
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
union|;
end_union

begin_comment
comment|/* 9000 structures. */
end_comment

begin_comment
comment|/* Command Packet. */
end_comment

begin_struct
struct|struct
name|twa_command_9k
block|{
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|reserved
range|:
literal|3
decl_stmt|;
block|}
name|command
struct|;
name|u_int8_t
name|unit
decl_stmt|;
name|u_int16_t
name|request_id
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|sgl_offset
decl_stmt|;
comment|/* offset (in bytes) to sg_list, from the end of sgl_entries */
name|u_int16_t
name|sgl_entries
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|twa_sg
name|sg_list
index|[
name|TWA_MAX_SG_ELEMENTS
index|]
decl_stmt|;
name|u_int8_t
name|padding
index|[
literal|32
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

begin_comment
comment|/* Command packet header. */
end_comment

begin_struct
struct|struct
name|twa_command_header
block|{
name|u_int8_t
name|sense_data
index|[
name|TWA_SENSE_DATA_LENGTH
index|]
decl_stmt|;
struct|struct
block|{
name|int8_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|error
decl_stmt|;
name|u_int8_t
name|padding
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|severity
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|reserved
range|:
literal|5
decl_stmt|;
block|}
name|substatus_block
struct|;
block|}
name|status_block
struct|;
name|u_int8_t
name|err_desc
index|[
literal|98
index|]
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|size_header
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int8_t
name|size_sense
decl_stmt|;
block|}
name|header_desc
struct|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Full command packet. */
end_comment

begin_struct
struct|struct
name|twa_command_packet
block|{
name|struct
name|twa_command_header
name|cmd_hdr
decl_stmt|;
union|union
block|{
name|union
name|twa_command_7k
name|cmd_pkt_7k
decl_stmt|;
name|struct
name|twa_command_9k
name|cmd_pkt_9k
decl_stmt|;
block|}
name|command
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Response queue entry. */
end_comment

begin_union
union|union
name|twa_response_queue
block|{
struct|struct
block|{
name|u_int32_t
name|undefined_1
range|:
literal|4
decl_stmt|;
name|u_int32_t
name|response_id
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|undefined_2
range|:
literal|20
decl_stmt|;
block|}
name|u
struct|;
name|u_int32_t
name|value
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
union|;
end_union

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

begin_define
define|#
directive|define
name|TWA_AEN_SEVERITY_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|TWA_AEN_SEVERITY_WARNING
value|0x1
end_define

begin_define
define|#
directive|define
name|TWA_AEN_SEVERITY_INFO
value|0x1
end_define

begin_define
define|#
directive|define
name|TWA_AEN_SEVERITY_DEBUG
value|0x4
end_define

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_TABLE
value|0x0402
end_define

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_MONITOR
value|2
end_define

begin_comment
comment|/* monitor version [16] */
end_comment

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
name|TWA_PARAM_VERSION_PCBA
value|5
end_define

begin_comment
comment|/* PCB version [8] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_ATA
value|6
end_define

begin_comment
comment|/* A-chip version [8] */
end_comment

begin_define
define|#
directive|define
name|TWA_PARAM_VERSION_PCI
value|7
end_define

begin_comment
comment|/* P-chip version [8] */
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
name|TWA_PARAM_TIME_SchedulerTime
value|0x3
end_define

begin_define
define|#
directive|define
name|TWA_9K_PARAM_DESCRIPTOR
value|0x8000
end_define

begin_struct
struct|struct
name|twa_param_9k
block|{
name|u_int16_t
name|table_id
decl_stmt|;
name|u_int8_t
name|parameter_id
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int16_t
name|parameter_size_bytes
decl_stmt|;
name|u_int16_t
name|parameter_actual_size_bytes
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|1
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

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

end_unit

