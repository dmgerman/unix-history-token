begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Register names, bit definitions, structure names and members are  * identical with those in the Linux driver where possible and sane   * for simplicity's sake.  (The TW_ prefix has become TWE_)  * Some defines that are clearly irrelevant to FreeBSD have been  * removed.  */
end_comment

begin_comment
comment|/* control register bit definitions */
end_comment

begin_define
define|#
directive|define
name|TWE_CONTROL_CLEAR_HOST_INTERRUPT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_CLEAR_ATTENTION_INTERRUPT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_MASK_COMMAND_INTERRUPT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_MASK_RESPONSE_INTERRUPT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_UNMASK_COMMAND_INTERRUPT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_UNMASK_RESPONSE_INTERRUPT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_CLEAR_ERROR_STATUS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_ISSUE_SOFT_RESET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_ENABLE_INTERRUPTS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_DISABLE_INTERRUPTS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_ISSUE_HOST_INTERRUPT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_CLEAR_PARITY_ERROR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TWE_CONTROL_CLEAR_PCI_ABORT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TWE_SOFT_RESET
parameter_list|(
name|sc
parameter_list|)
value|TWE_CONTROL(sc, TWE_CONTROL_ISSUE_SOFT_RESET |		\ 					   TWE_CONTROL_CLEAR_HOST_INTERRUPT |		\ 					   TWE_CONTROL_CLEAR_ATTENTION_INTERRUPT |	\ 					   TWE_CONTROL_MASK_COMMAND_INTERRUPT |		\ 					   TWE_CONTROL_MASK_RESPONSE_INTERRUPT |	\ 					   TWE_CONTROL_CLEAR_ERROR_STATUS |		\ 					   TWE_CONTROL_DISABLE_INTERRUPTS)
end_define

begin_comment
comment|/* status register bit definitions */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_MAJOR_VERSION_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_MINOR_VERSION_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_PCI_PARITY_ERROR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_QUEUE_ERROR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_MICROCONTROLLER_ERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_PCI_ABORT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_HOST_INTERRUPT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_ATTENTION_INTERRUPT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_COMMAND_INTERRUPT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_RESPONSE_INTERRUPT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_COMMAND_QUEUE_FULL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_RESPONSE_QUEUE_EMPTY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_MICROCONTROLLER_READY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_COMMAND_QUEUE_EMPTY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_ALL_INTERRUPTS
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_CLEARABLE_BITS
value|0x00D00000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_EXPECTED_BITS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TWE_STATUS_UNEXPECTED_BITS
value|0x00F80000
end_define

begin_comment
comment|/* XXX this is a little harsh, but necessary to chase down firmware problems */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_PANIC_BITS
value|(TWE_STATUS_MICROCONTROLLER_ERROR)
end_define

begin_comment
comment|/* for use with the %b printf format */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_BITS_DESCRIPTION
define|\
value|"\20\15CQEMPTY\16UCREADY\17RQEMPTY\20CQFULL\21RINTR\22CINTR\23AINTR\24HINTR\25PCIABRT\26MCERR\27QERR\30PCIPERR\n"
end_define

begin_comment
comment|/* detect inconsistencies in the status register */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_ERRORS
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x& TWE_STATUS_PCI_ABORT) 		||	\ 	  (x& TWE_STATUS_PCI_PARITY_ERROR) 	||	\ 	  (x& TWE_STATUS_QUEUE_ERROR)		||	\ 	  (x& TWE_STATUS_MICROCONTROLLER_ERROR))&&	\ 	 (x& TWE_STATUS_MICROCONTROLLER_READY))
end_define

begin_comment
comment|/* Response queue bit definitions */
end_comment

begin_define
define|#
directive|define
name|TWE_RESPONSE_ID_MASK
value|0x00000FF0
end_define

begin_comment
comment|/* PCI related defines */
end_comment

begin_define
define|#
directive|define
name|TWE_IO_CONFIG_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|TWE_DEVICE_NAME
value|"3ware Storage Controller"
end_define

begin_define
define|#
directive|define
name|TWE_VENDOR_ID
value|0x13C1
end_define

begin_define
define|#
directive|define
name|TWE_DEVICE_ID
value|0x1000
end_define

begin_define
define|#
directive|define
name|TWE_DEVICE_ID_ASIC
value|0x1001
end_define

begin_define
define|#
directive|define
name|TWE_PCI_CLEAR_PARITY_ERROR
value|0xc100
end_define

begin_define
define|#
directive|define
name|TWE_PCI_CLEAR_PCI_ABORT
value|0x2000
end_define

begin_comment
comment|/* command packet opcodes */
end_comment

begin_define
define|#
directive|define
name|TWE_OP_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|TWE_OP_INIT_CONNECTION
value|0x01
end_define

begin_define
define|#
directive|define
name|TWE_OP_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|TWE_OP_WRITE
value|0x03
end_define

begin_define
define|#
directive|define
name|TWE_OP_READVERIFY
value|0x04
end_define

begin_define
define|#
directive|define
name|TWE_OP_VERIFY
value|0x05
end_define

begin_define
define|#
directive|define
name|TWE_OP_ZEROUNIT
value|0x08
end_define

begin_define
define|#
directive|define
name|TWE_OP_REPLACEUNIT
value|0x09
end_define

begin_define
define|#
directive|define
name|TWE_OP_HOTSWAP
value|0x0a
end_define

begin_define
define|#
directive|define
name|TWE_OP_SETATAFEATURE
value|0x0c
end_define

begin_define
define|#
directive|define
name|TWE_OP_FLUSH
value|0x0e
end_define

begin_define
define|#
directive|define
name|TWE_OP_ABORT
value|0x0f
end_define

begin_define
define|#
directive|define
name|TWE_OP_CHECKSTATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|TWE_OP_GET_PARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|TWE_OP_SET_PARAM
value|0x13
end_define

begin_define
define|#
directive|define
name|TWE_OP_CREATEUNIT
value|0x14
end_define

begin_define
define|#
directive|define
name|TWE_OP_DELETEUNIT
value|0x15
end_define

begin_define
define|#
directive|define
name|TWE_OP_REBUILDUNIT
value|0x17
end_define

begin_define
define|#
directive|define
name|TWE_OP_SECTOR_INFO
value|0x1a
end_define

begin_define
define|#
directive|define
name|TWE_OP_AEN_LISTEN
value|0x1c
end_define

begin_define
define|#
directive|define
name|TWE_OP_CMD_PACKET
value|0x1d
end_define

begin_define
define|#
directive|define
name|TWE_OP_ATA_PASSTHROUGH
value|0x1e
end_define

begin_define
define|#
directive|define
name|TWE_OP_CMD_WITH_DATA
value|0x1f
end_define

begin_comment
comment|/* command status values */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_RESET
value|0xff
end_define

begin_comment
comment|/* controller requests reset */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_FATAL
value|0xc0
end_define

begin_comment
comment|/* fatal errors not requiring reset */
end_comment

begin_define
define|#
directive|define
name|TWE_STATUS_WARNING
value|0x80
end_define

begin_comment
comment|/* warnings */
end_comment

begin_define
define|#
directive|define
name|TWE_STAUS_INFO
value|0x40
end_define

begin_comment
comment|/* informative status */
end_comment

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|TWE_ALIGNMENT
value|0x200
end_define

begin_define
define|#
directive|define
name|TWE_MAX_UNITS
value|16
end_define

begin_define
define|#
directive|define
name|TWE_COMMAND_ALIGNMENT_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|TWE_INIT_MESSAGE_CREDITS
value|0xff
end_define

begin_comment
comment|/* older firmware has issues with 256 commands */
end_comment

begin_define
define|#
directive|define
name|TWE_SHUTDOWN_MESSAGE_CREDITS
value|0x001
end_define

begin_define
define|#
directive|define
name|TWE_INIT_COMMAND_PACKET_SIZE
value|0x3
end_define

begin_define
define|#
directive|define
name|TWE_MAX_SGL_LENGTH
value|62
end_define

begin_define
define|#
directive|define
name|TWE_MAX_ATA_SGL_LENGTH
value|60
end_define

begin_define
define|#
directive|define
name|TWE_MAX_PASSTHROUGH
value|4096
end_define

begin_define
define|#
directive|define
name|TWE_Q_LENGTH
value|TWE_INIT_MESSAGE_CREDITS
end_define

begin_define
define|#
directive|define
name|TWE_Q_START
value|0
end_define

begin_define
define|#
directive|define
name|TWE_MAX_RESET_TRIES
value|3
end_define

begin_define
define|#
directive|define
name|TWE_BLOCK_SIZE
value|0x200
end_define

begin_comment
comment|/* 512-byte blocks */
end_comment

begin_define
define|#
directive|define
name|TWE_SECTOR_SIZE
value|0x200
end_define

begin_comment
comment|/* generic I/O bufffer */
end_comment

begin_define
define|#
directive|define
name|TWE_IOCTL
value|0x80
end_define

begin_define
define|#
directive|define
name|TWE_MAX_AEN_TRIES
value|100
end_define

begin_define
define|#
directive|define
name|TWE_UNIT_ONLINE
value|1
end_define

begin_comment
comment|/* scatter/gather list entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|address
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
block|}
name|TWE_SG_Entry
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_INITCONNECTION */
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
name|message_credits
decl_stmt|;
name|u_int32_t
name|response_queue_pointer
decl_stmt|;
block|}
name|TWE_Command_INITCONNECTION
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_READ/TWE_OP_WRITE */
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
name|u_int16_t
name|block_count
decl_stmt|;
name|u_int32_t
name|lba
decl_stmt|;
name|TWE_SG_Entry
name|sgl
index|[
name|TWE_MAX_SGL_LENGTH
index|]
decl_stmt|;
block|}
name|TWE_Command_IO
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_HOTSWAP */
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
name|TWE_OP_HOTSWAP_REMOVE
value|0x00
comment|/* remove assumed-degraded unit */
define|#
directive|define
name|TWE_OP_HOTSWAP_ADD_CBOD
value|0x01
comment|/* add CBOD to empty port */
define|#
directive|define
name|TWE_OP_HOTSWAP_ADD_SPARE
value|0x02
comment|/* add spare to empty port */
name|u_int8_t
name|aport
decl_stmt|;
block|}
name|TWE_Command_HOTSWAP
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_SETATAFEATURE */
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
name|feature
decl_stmt|;
define|#
directive|define
name|TWE_OP_SETATAFEATURE_WCE
value|0x02
define|#
directive|define
name|TWE_OP_SETATAFEATURE_DIS_WCE
value|0x82
name|u_int8_t
name|feature_mode
decl_stmt|;
name|u_int16_t
name|all_units
decl_stmt|;
name|u_int16_t
name|persistence
decl_stmt|;
block|}
name|TWE_Command_SETATAFEATURE
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_CHECKSTATUS */
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
name|res2
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
name|target_status
decl_stmt|;
comment|/* set low byte to target request's ID */
block|}
name|TWE_Command_CHECKSTATUS
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_GETPARAM, TWE_OP_SETPARAM */
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
name|u_int16_t
name|param_count
decl_stmt|;
name|TWE_SG_Entry
name|sgl
index|[
name|TWE_MAX_SGL_LENGTH
index|]
decl_stmt|;
block|}
name|TWE_Command_PARAM
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|opcode
range|:
literal|5
decl_stmt|;
comment|/* TWE_OP_REBUILDUNIT */
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
name|TWE_OP_REBUILDUNIT_NOP
value|0
define|#
directive|define
name|TWE_OP_REBUILDUNIT_STOP
value|2
comment|/* stop all rebuilds */
define|#
directive|define
name|TWE_OP_REBUILDUNIT_START
value|4
comment|/* start rebuild with lowest unit */
define|#
directive|define
name|TWE_OP_REBUILDUNIT_STARTUNIT
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
name|TWE_Command_REBUILDUNIT
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
name|TWE_SG_Entry
name|sgl
index|[
name|TWE_MAX_ATA_SGL_LENGTH
index|]
decl_stmt|;
block|}
name|TWE_Command_ATA
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
name|TWE_FLAGS_SUCCESS
value|0x00
define|#
directive|define
name|TWE_FLAGS_INFORMATIONAL
value|0x01
define|#
directive|define
name|TWE_FLAGS_WARNING
value|0x02
define|#
directive|define
name|TWE_FLAGS_FATAL
value|0x03
define|#
directive|define
name|TWE_FLAGS_PERCENTAGE
value|(1<<8)
comment|/* bits 0-6 indicate completion percentage */
name|u_int16_t
name|count
decl_stmt|;
comment|/* block count, parameter count, message credits */
block|}
name|TWE_Command_Generic
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_comment
comment|/* command packet - must be TWE_ALIGNMENT aligned */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TWE_Command_INITCONNECTION
name|initconnection
decl_stmt|;
name|TWE_Command_IO
name|io
decl_stmt|;
name|TWE_Command_PARAM
name|param
decl_stmt|;
name|TWE_Command_CHECKSTATUS
name|checkstatus
decl_stmt|;
name|TWE_Command_REBUILDUNIT
name|rebuildunit
decl_stmt|;
name|TWE_Command_SETATAFEATURE
name|setatafeature
decl_stmt|;
name|TWE_Command_ATA
name|ata
decl_stmt|;
name|TWE_Command_Generic
name|generic
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|512
index|]
decl_stmt|;
block|}
name|TWE_Command
typedef|;
end_typedef

begin_comment
comment|/* response queue entry */
end_comment

begin_typedef
typedef|typedef
union|union
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
name|TWE_Response_Queue
typedef|;
end_typedef

begin_comment
comment|/*  * From 3ware's documentation:  *   All parameters maintained by the controller are grouped into related tables.  *   Tables are are accessed indirectly via get and set parameter commands.  *   To access a specific parameter in a table, the table ID and parameter index  *   are used to uniquely identify a parameter.  Table 0xffff is the directory  *   table and provides a list of the table IDs and sizes of all other tables.  *   Index zero in each table specifies the entire table, and index one specifies  *   the size of the table.  An entire table can be read or set by using index zero.  */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_PARAM_ALL
value|0
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_PARAM_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_DIRECTORY
value|0xffff
end_define

begin_comment
comment|/* size is 4 * number of tables */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DIRECTORY_TABLES
value|2
end_define

begin_comment
comment|/* 16 bits * number of tables */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DIRECTORY_SIZES
value|3
end_define

begin_comment
comment|/* 16 bits * number of tables */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESUMMARY
value|0x0002
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESUMMARY_Num
value|2
end_define

begin_comment
comment|/* number of physical drives [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESUMMARY_Status
value|3
end_define

begin_comment
comment|/* array giving drive status per aport */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESTATUS_Missing
value|0x00
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESTATUS_NotSupp
value|0xfe
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVESTATUS_Present
value|0xff
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSUMMARY
value|0x0003
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSUMMARY_Num
value|2
end_define

begin_comment
comment|/* number of logical units [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSUMMARY_Status
value|3
end_define

begin_comment
comment|/* array giving unit status [16] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Online
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Complete
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_MASK
value|0xfc
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Normal
value|0xfc
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Initialising
value|0xf4
end_define

begin_comment
comment|/* cannot be incomplete */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Degraded
value|0xec
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Rebuilding
value|0xdc
end_define

begin_comment
comment|/* cannot be incomplete */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Verifying
value|0xcc
end_define

begin_comment
comment|/* cannot be incomplete */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Corrupt
value|0xbc
end_define

begin_comment
comment|/* cannot be complete */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITSTATUS_Missing
value|0x00
end_define

begin_comment
comment|/* cannot be complete or online */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO
value|0x0200
end_define

begin_comment
comment|/* add drive number 0x00-0x0f XXX docco confused 0x0100 vs 0x0200 */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_Size
value|2
end_define

begin_comment
comment|/* size in blocks [4] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_Model
value|3
end_define

begin_comment
comment|/* drive model string [40] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_Serial
value|4
end_define

begin_comment
comment|/* drive serial number [20] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_PhysCylNum
value|5
end_define

begin_comment
comment|/* physical geometry [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_PhysHeadNum
value|6
end_define

begin_comment
comment|/* [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_PhysSectorNym
value|7
end_define

begin_comment
comment|/* [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_LogCylNum
value|8
end_define

begin_comment
comment|/* logical geometry [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_LogHeadNum
value|9
end_define

begin_comment
comment|/* [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_LogSectorNum
value|10
end_define

begin_comment
comment|/* [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_UnitNum
value|11
end_define

begin_comment
comment|/* unit number this drive is associated with or 0xff [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_DRIVEINFO_DriveFlags
value|12
end_define

begin_comment
comment|/* N/A [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_APORTTIMEOUT
value|0x02c0
end_define

begin_comment
comment|/* add (aport_number * 3) to parameter index */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_APORTTIMEOUT_READ
value|2
end_define

begin_comment
comment|/* read timeouts last 24hrs [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_APORTTIMEOUT_WRITE
value|3
end_define

begin_comment
comment|/* write timeouts last 24hrs [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_APORTTIMEOUT_DEGRADE
value|4
end_define

begin_comment
comment|/* degrade threshold [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO
value|0x0300
end_define

begin_comment
comment|/* add unit number 0x00-0x0f */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_Number
value|2
end_define

begin_comment
comment|/* unit number [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_Status
value|3
end_define

begin_comment
comment|/* unit status [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_Capacity
value|4
end_define

begin_comment
comment|/* unit capacity in blocks [4] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_DescriptorSize
value|5
end_define

begin_comment
comment|/* unit descriptor size + 3 bytes [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_Descriptor
value|6
end_define

begin_comment
comment|/* unit descriptor, TWE_UnitDescriptor or TWE_Array_Descriptor */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITINFO_Flags
value|7
end_define

begin_comment
comment|/* unit flags [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_UNITFLAGS_WCE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_AEN
value|0x0401
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_AEN_UnitCode
value|2
end_define

begin_comment
comment|/* (unit number<< 8) | AEN code [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_QUEUE_EMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|TWE_AEN_SOFT_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|TWE_AEN_DEGRADED_MIRROR
value|0x02
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_CONTROLLER_ERROR
value|0x03
end_define

begin_define
define|#
directive|define
name|TWE_AEN_REBUILD_FAIL
value|0x04
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_REBUILD_DONE
value|0x05
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_INCOMP_UNIT
value|0x06
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_INIT_DONE
value|0x07
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_UNCLEAN_SHUTDOWN
value|0x08
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_APORT_TIMEOUT
value|0x09
end_define

begin_comment
comment|/* reports unit, rate limited to 1 per 2^16 errors */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_DRIVE_ERROR
value|0x0a
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_REBUILD_STARTED
value|0x0b
end_define

begin_comment
comment|/* reports unit */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_QUEUE_FULL
value|0xff
end_define

begin_define
define|#
directive|define
name|TWE_AEN_TABLE_UNDEFINED
value|0x15
end_define

begin_define
define|#
directive|define
name|TWE_AEN_CODE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|TWE_AEN_UNIT
parameter_list|(
name|x
parameter_list|)
value|((x)>> 8)
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION
value|0x0402
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_Mon
value|2
end_define

begin_comment
comment|/* monitor version [16] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_FW
value|3
end_define

begin_comment
comment|/* firmware version [16] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_BIOS
value|4
end_define

begin_comment
comment|/* BIOSs version [16] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_PCB
value|5
end_define

begin_comment
comment|/* PCB version [8] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_ATA
value|6
end_define

begin_comment
comment|/* A-chip version [8] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_PCI
value|7
end_define

begin_comment
comment|/* P-chip version [8] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_CtrlModel
value|8
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_CtrlSerial
value|9
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_SBufSize
value|10
end_define

begin_comment
comment|/* N/A */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_VERSION_CompCode
value|11
end_define

begin_comment
comment|/* compatibility code [4] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_CONTROLLER
value|0x0403
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_CONTROLLER_DCBSectors
value|2
end_define

begin_comment
comment|/* # sectors reserved for DCB per drive [2] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_CONTROLLER_PortCount
value|3
end_define

begin_comment
comment|/* number of drive ports [1] */
end_comment

begin_define
define|#
directive|define
name|TWE_PARAM_FEATURES
value|0x404
end_define

begin_define
define|#
directive|define
name|TWE_PARAM_FEATURES_DriverShutdown
value|2
end_define

begin_comment
comment|/* set to 1 if driver supports shutdown notification [1] */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_subunits
decl_stmt|;
comment|/* must be zero */
name|u_int8_t
name|configuration
decl_stmt|;
define|#
directive|define
name|TWE_UD_CONFIG_CBOD
value|0x0c
comment|/* JBOD with DCB, used for mirrors */
define|#
directive|define
name|TWE_UD_CONFIG_SPARE
value|0x0d
comment|/* same as CBOD, but firmware will use as spare */
define|#
directive|define
name|TWE_UD_CONFIG_SUBUNIT
value|0x0e
comment|/* drive is a subunit in an array */
define|#
directive|define
name|TWE_UD_CONFIG_JBOD
value|0x0f
comment|/* plain drive */
name|u_int8_t
name|phys_drv_num
decl_stmt|;
comment|/* may be 0xff if port can't be determined at runtime */
name|u_int8_t
name|log_drv_num
decl_stmt|;
comment|/* must be zero for configuration == 0x0f */
name|u_int32_t
name|start_lba
decl_stmt|;
name|u_int32_t
name|block_count
decl_stmt|;
comment|/* actual drive size if configuration == 0x0f, otherwise less DCB size */
block|}
name|TWE_Unit_Descriptor
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|flag
decl_stmt|;
comment|/* must be 0xff */
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|mirunit_status
index|[
literal|4
index|]
decl_stmt|;
comment|/* bitmap of functional subunits in each mirror */
name|u_int8_t
name|res2
index|[
literal|6
index|]
decl_stmt|;
block|}
name|TWE_Mirror_Descriptor
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|num_subunits
decl_stmt|;
comment|/* number of subunits, or number of mirror units in RAID10 */
name|u_int8_t
name|configuration
decl_stmt|;
define|#
directive|define
name|TWE_UD_CONFIG_RAID0
value|0x00
define|#
directive|define
name|TWE_UD_CONFIG_RAID1
value|0x01
define|#
directive|define
name|TWE_UD_CONFIG_TwinStor
value|0x02
define|#
directive|define
name|TWE_UD_CONFIG_RAID5
value|0x05
define|#
directive|define
name|TWE_UD_CONFIG_RAID10
value|0x06
name|u_int8_t
name|stripe_size
decl_stmt|;
define|#
directive|define
name|TWE_UD_STRIPE_4k
value|0x03
define|#
directive|define
name|TWE_UD_STRIPE_8k
value|0x04
define|#
directive|define
name|TWE_UD_STRIPE_16k
value|0x05
define|#
directive|define
name|TWE_UD_STRIPE_32k
value|0x06
define|#
directive|define
name|TWE_UD_STRIPE_64k
value|0x07
name|u_int8_t
name|log_drv_status
decl_stmt|;
comment|/* bitmap of functional subunits, or mirror units in RAID10 */
name|u_int32_t
name|start_lba
decl_stmt|;
name|u_int32_t
name|block_count
decl_stmt|;
comment|/* actual drive size if configuration == 0x0f, otherwise less DCB size */
name|TWE_Unit_Descriptor
name|subunit
index|[
literal|0
index|]
decl_stmt|;
comment|/* subunit descriptors, in RAID10 mode is [mirunit][subunit] */
block|}
name|TWE_Array_Descriptor
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|table_id
decl_stmt|;
name|u_int8_t
name|parameter_id
decl_stmt|;
name|u_int8_t
name|parameter_size_bytes
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|TWE_Param
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

end_unit

