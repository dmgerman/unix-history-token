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

begin_comment
comment|/* command packet opcodes */
end_comment

begin_define
define|#
directive|define
name|TWE_OP_NOP
value|0x0
end_define

begin_define
define|#
directive|define
name|TWE_OP_INIT_CONNECTION
value|0x1
end_define

begin_define
define|#
directive|define
name|TWE_OP_READ
value|0x2
end_define

begin_define
define|#
directive|define
name|TWE_OP_WRITE
value|0x3
end_define

begin_define
define|#
directive|define
name|TWE_OP_VERIFY
value|0x4
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
name|TWE_OP_SECTOR_INFO
value|0x1a
end_define

begin_define
define|#
directive|define
name|TWE_OP_AEN_LISTEN
value|0x1c
end_define

begin_comment
comment|/* asynchronous event notification (AEN) codes */
end_comment

begin_define
define|#
directive|define
name|TWE_AEN_QUEUE_EMPTY
value|0x0000
end_define

begin_define
define|#
directive|define
name|TWE_AEN_SOFT_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|TWE_AEN_DEGRADED_MIRROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|TWE_AEN_CONTROLLER_ERROR
value|0x0003
end_define

begin_define
define|#
directive|define
name|TWE_AEN_REBUILD_FAIL
value|0x0004
end_define

begin_define
define|#
directive|define
name|TWE_AEN_REBUILD_DONE
value|0x0005
end_define

begin_define
define|#
directive|define
name|TWE_AEN_QUEUE_FULL
value|0x00ff
end_define

begin_define
define|#
directive|define
name|TWE_AEN_TABLE_UNDEFINED
value|0x15
end_define

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
value|0x100
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
name|TWE_Q_LENGTH
value|256
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
name|TWE_UNIT_INFORMATION_TABLE_BASE
value|0x300
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

begin_comment
comment|/* wrappers for bus-space actions */
end_comment

begin_define
define|#
directive|define
name|TWE_CONTROL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->twe_btag, sc->twe_bhandle, 0x0, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_STATUS
parameter_list|(
name|sc
parameter_list|)
value|(u_int32_t)bus_space_read_4(sc->twe_btag, sc->twe_bhandle, 0x4)
end_define

begin_define
define|#
directive|define
name|TWE_COMMAND_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->twe_btag, sc->twe_bhandle, 0x8, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_RESPONSE_QUEUE
parameter_list|(
name|sc
parameter_list|)
value|(TWE_Response_Queue)bus_space_read_4(sc->twe_btag, sc->twe_bhandle, 0xc)
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

begin_comment
comment|/* command packet - must be TWE_ALIGNMENT aligned */
end_comment

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
name|u_int16_t
name|count
decl_stmt|;
comment|/* block count, parameter count, message credits */
union|union
block|{
struct|struct
block|{
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
name|io
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
struct|struct
block|{
name|TWE_SG_Entry
name|sgl
index|[
name|TWE_MAX_SGL_LENGTH
index|]
decl_stmt|;
block|}
name|param
struct|;
struct|struct
block|{
name|u_int32_t
name|response_queue_pointer
decl_stmt|;
block|}
name|init_connection
struct|;
block|}
name|args
union|;
block|}
name|TWE_Command
name|__attribute__
typedef|((
name|packed
typedef|));
end_typedef

begin_comment
comment|/* argument to TWE_OP_GET/SET_PARAM */
end_comment

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
literal|1
index|]
decl_stmt|;
block|}
name|TWE_Param
name|__attribute__
typedef|((
name|packed
typedef|));
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* no idea what these will be useful for yet */
end_comment

begin_endif
unit|typedef struct {     int32_t	buffer;     u_int8_t	opcode;     u_int16_t	table_id;     u_int8_t	parameter_id;     u_int8_t	parameter_size_bytes;     u_int8_t	data[1]; } TWE_Ioctl __attribute__ ((packed));  typedef struct {     u_int32_t	base_addr;     u_int32_t	control_reg_addr;     u_int32_t	status_reg_addr;     u_int32_t	command_que_addr;     u_int32_t	response_que_addr; } TWE_Registers __attribute__ ((packed));  typedef struct {     char	*buffer;     int32_t	length;     int32_t	offset;     int32_t	position; } TWE_Info __attribute__ ((packed));
endif|#
directive|endif
end_endif

end_unit

