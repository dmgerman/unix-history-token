begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010, LSI Corp.  * All rights reserved.  * Author : Manjunath Ranganathaiah  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of the<ORGANIZATION> nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* bit's defination */
end_comment

begin_define
define|#
directive|define
name|TWS_BIT0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TWS_BIT1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TWS_BIT2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TWS_BIT3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TWS_BIT4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TWS_BIT5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TWS_BIT6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TWS_BIT7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TWS_BIT8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TWS_BIT9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TWS_BIT10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TWS_BIT11
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TWS_BIT12
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TWS_BIT13
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TWS_BIT14
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TWS_BIT15
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TWS_BIT16
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TWS_BIT17
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TWS_BIT18
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TWS_BIT19
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TWS_BIT20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TWS_BIT21
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TWS_BIT22
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TWS_BIT23
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TWS_BIT24
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT25
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT26
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT27
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT28
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT29
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT30
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TWS_BIT31
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TWS_SENSE_DATA_LENGTH
value|18
end_define

begin_define
define|#
directive|define
name|TWS_ERROR_SPECIFIC_DESC_LEN
value|98
end_define

begin_comment
comment|/* response codes */
end_comment

begin_define
define|#
directive|define
name|TWS_SENSE_SCSI_CURRENT_ERROR
value|0x70
end_define

begin_define
define|#
directive|define
name|TWS_SENSE_SCSI_DEFERRED_ERROR
value|0x71
end_define

begin_define
define|#
directive|define
name|TWS_SRC_CTRL_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|TWS_SRC_CTRL_EVENT
value|4
end_define

begin_define
define|#
directive|define
name|TWS_SRC_FREEBSD_DRIVER
value|5
end_define

begin_define
define|#
directive|define
name|TWS_SRC_FREEBSD_OS
value|8
end_define

begin_enum
enum|enum
name|tws_sense_severity
block|{
name|error
init|=
literal|1
block|,
name|warning
block|,
name|info
block|,
name|debug
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Some errors of interest (in cmd_hdr->status_block.error) when a command  * is completed by the firmware with an error.  */
end_comment

begin_define
define|#
directive|define
name|TWS_ERROR_LOGICAL_UNIT_NOT_SUPPORTED
value|0x010a
end_define

begin_define
define|#
directive|define
name|TWS_ERROR_NOT_SUPPORTED
value|0x010D
end_define

begin_define
define|#
directive|define
name|TWS_ERROR_UNIT_OFFLINE
value|0x0128
end_define

begin_define
define|#
directive|define
name|TWS_ERROR_MORE_DATA
value|0x0231
end_define

begin_comment
comment|/* AEN codes of interest. */
end_comment

begin_define
define|#
directive|define
name|TWS_AEN_QUEUE_EMPTY
value|0x00
end_define

begin_define
define|#
directive|define
name|TWS_AEN_SOFT_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|TWS_AEN_SYNC_TIME_WITH_HOST
value|0x31
end_define

begin_comment
comment|/* AEN severity */
end_comment

begin_define
define|#
directive|define
name|TWS_SEVERITY_ERROR
value|0x1
end_define

begin_define
define|#
directive|define
name|TWS_SEVERITY_WARNING
value|0x2
end_define

begin_define
define|#
directive|define
name|TWS_SEVERITY_INFO
value|0x3
end_define

begin_define
define|#
directive|define
name|TWS_SEVERITY_DEBUG
value|0x4
end_define

begin_define
define|#
directive|define
name|TWS_64BIT_SG_ADDRESSES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TWS_BIT_EXTEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TWS_BASE_FW_SRL
value|24
end_define

begin_define
define|#
directive|define
name|TWS_BASE_FW_BRANCH
value|0
end_define

begin_define
define|#
directive|define
name|TWS_BASE_FW_BUILD
value|1
end_define

begin_define
define|#
directive|define
name|TWS_CURRENT_FW_SRL
value|41
end_define

begin_define
define|#
directive|define
name|TWS_CURRENT_FW_BRANCH
value|8
end_define

begin_define
define|#
directive|define
name|TWS_CURRENT_FW_BUILD
value|4
end_define

begin_define
define|#
directive|define
name|TWS_CURRENT_ARCH_ID
value|0x000A
end_define

begin_define
define|#
directive|define
name|TWS_FIFO_EMPTY
value|0xFFFFFFFFFFFFFFFFull
end_define

begin_define
define|#
directive|define
name|TWS_FIFO_EMPTY32
value|0xFFFFFFFFull
end_define

begin_comment
comment|/* Register offsets from base address. */
end_comment

begin_define
define|#
directive|define
name|TWS_CONTROL_REGISTER_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|TWS_STATUS_REGISTER_OFFSET
value|0x4
end_define

begin_define
define|#
directive|define
name|TWS_COMMAND_QUEUE_OFFSET
value|0x8
end_define

begin_define
define|#
directive|define
name|TWS_RESPONSE_QUEUE_OFFSET
value|0xC
end_define

begin_define
define|#
directive|define
name|TWS_COMMAND_QUEUE_OFFSET_LOW
value|0x20
end_define

begin_define
define|#
directive|define
name|TWS_COMMAND_QUEUE_OFFSET_HIGH
value|0x24
end_define

begin_define
define|#
directive|define
name|TWS_LARGE_RESPONSE_QUEUE_OFFSET
value|0x30
end_define

begin_comment
comment|/* I2O offsets */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_STATUS
value|0x0
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HIBDB
value|0x20
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HISTAT
value|0x30
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HIMASK
value|0x34
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HIBQP
value|0x40
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HOBQP
value|0x44
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_CTL
value|0x74
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_IOBDB
value|0x9C
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HOBDBC
value|0xA0
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_SCRPD3
value|0xBC
end_define

begin_define
define|#
directive|define
name|TWS_I2O0_HIBQPL
value|0xC0
end_define

begin_comment
comment|/* 64bit inb port low */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_HIBQPH
value|0xC4
end_define

begin_comment
comment|/* 64bit inb port high */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_HOBQPL
value|0xC8
end_define

begin_comment
comment|/* 64bit out port low */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_HOBQPH
value|0xCC
end_define

begin_comment
comment|/* 64bit out port high */
end_comment

begin_comment
comment|/* IOP related */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_IOPOBQPL
value|0xD8
end_define

begin_comment
comment|/* OBFL */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_IOPOBQPH
value|0xDC
end_define

begin_comment
comment|/* OBFH */
end_comment

begin_define
define|#
directive|define
name|TWS_I2O0_SRC_ADDRH
value|0xF8
end_define

begin_comment
comment|/* Msg ASA */
end_comment

begin_define
define|#
directive|define
name|TWS_MSG_ACC_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TWS_32BIT_MASK
value|0xFFFFFFFF
end_define

begin_comment
comment|/* revisit */
end_comment

begin_define
define|#
directive|define
name|TWS_FW_CMD_NOP
value|0x0
end_define

begin_define
define|#
directive|define
name|TWS_FW_CMD_INIT_CONNECTION
value|0x01
end_define

begin_define
define|#
directive|define
name|TWS_FW_CMD_EXECUTE_SCSI
value|0x10
end_define

begin_define
define|#
directive|define
name|TWS_FW_CMD_ATA_PASSTHROUGH
value|0x11
end_define

begin_comment
comment|// This is really a PASSTHROUGH for both ATA and SCSI commands.
end_comment

begin_define
define|#
directive|define
name|TWS_FW_CMD_GET_PARAM
value|0x12
end_define

begin_define
define|#
directive|define
name|TWS_FW_CMD_SET_PARAM
value|0x13
end_define

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

begin_comment
comment|/* end revisit */
end_comment

begin_comment
comment|/* Table #'s and id's of parameters of interest in firmware's param table. */
end_comment

begin_define
define|#
directive|define
name|TWS_PARAM_VERSION_TABLE
value|0x0402
end_define

begin_define
define|#
directive|define
name|TWS_PARAM_VERSION_FW
value|3
end_define

begin_comment
comment|/* firmware version [16] */
end_comment

begin_define
define|#
directive|define
name|TWS_PARAM_VERSION_BIOS
value|4
end_define

begin_comment
comment|/* BIOSs version [16] */
end_comment

begin_define
define|#
directive|define
name|TWS_PARAM_CTLR_MODEL
value|8
end_define

begin_comment
comment|/* Controller model [16] */
end_comment

begin_define
define|#
directive|define
name|TWS_PARAM_CONTROLLER_TABLE
value|0x0403
end_define

begin_define
define|#
directive|define
name|TWS_PARAM_CONTROLLER_PORT_COUNT
value|3
end_define

begin_comment
comment|/* number of ports [1] */
end_comment

begin_define
define|#
directive|define
name|TWS_PARAM_TIME_TABLE
value|0x40A
end_define

begin_define
define|#
directive|define
name|TWS_PARAM_TIME_SCHED_TIME
value|0x3
end_define

begin_define
define|#
directive|define
name|TWS_PARAM_PHYS_TABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|TWS_PARAM_CONTROLLER_PHYS_COUNT
value|2
end_define

begin_comment
comment|/* number of phys */
end_comment

begin_define
define|#
directive|define
name|TWS_9K_PARAM_DESCRIPTOR
value|0x8000
end_define

begin_comment
comment|/* ----------- request  ------------- */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|tws_cmd_init_connect
block|{
name|u_int8_t
name|res1__opcode
decl_stmt|;
comment|/* 3:5 */
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
struct|;
end_struct

begin_comment
comment|/* Structure for downloading firmware onto the controller. */
end_comment

begin_struct
struct|struct
name|tws_cmd_download_firmware
block|{
name|u_int8_t
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
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
name|u_int8_t
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
name|tws_cmd_reset_firmware
block|{
name|u_int8_t
name|res1__opcode
decl_stmt|;
comment|/* 3:5 */
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
struct|;
end_struct

begin_comment
comment|/* Structure for sending get/set param commands. */
end_comment

begin_struct
struct|struct
name|tws_cmd_param
block|{
name|u_int8_t
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|host_id__unit
decl_stmt|;
comment|/* 4:4 */
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
name|param_count
decl_stmt|;
name|u_int8_t
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
name|tws_cmd_generic
block|{
name|u_int8_t
name|sgl_off__opcode
decl_stmt|;
comment|/* 3:5 */
name|u_int8_t
name|size
decl_stmt|;
name|u_int8_t
name|request_id
decl_stmt|;
name|u_int8_t
name|host_id__unit
decl_stmt|;
comment|/* 4:4 */
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int16_t
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
name|tws_command_header
block|{
name|u_int8_t
name|sense_data
index|[
name|TWS_SENSE_DATA_LENGTH
index|]
decl_stmt|;
struct|struct
block|{
comment|/* status block - additional sense data */
name|u_int16_t
name|srcnum
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int16_t
name|error
decl_stmt|;
name|u_int8_t
name|res__srcid
decl_stmt|;
comment|/* 4:4 */
name|u_int8_t
name|res__severity
decl_stmt|;
comment|/* 5:3 */
block|}
name|status_block
struct|;
name|u_int8_t
name|err_specific_desc
index|[
name|TWS_ERROR_SPECIFIC_DESC_LEN
index|]
decl_stmt|;
struct|struct
block|{
comment|/* sense buffer descriptor */
name|u_int8_t
name|size_header
decl_stmt|;
name|u_int16_t
name|request_id
decl_stmt|;
name|u_int8_t
name|size_sense
decl_stmt|;
block|}
name|header_desc
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* Command - 1024 byte size including header (128+24+896)*/
end_comment

begin_union
union|union
name|tws_command_giga
block|{
name|struct
name|tws_cmd_init_connect
name|init_connect
decl_stmt|;
name|struct
name|tws_cmd_download_firmware
name|download_fw
decl_stmt|;
name|struct
name|tws_cmd_reset_firmware
name|reset_fw
decl_stmt|;
name|struct
name|tws_cmd_param
name|param
decl_stmt|;
name|struct
name|tws_cmd_generic
name|generic
decl_stmt|;
name|u_int8_t
name|padding
index|[
literal|1024
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|tws_command_header
argument_list|)
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* driver command pkt - 1024 byte size including header(128+24+744+128) */
end_comment

begin_comment
comment|/* h/w& f/w supported command size excluding header 768 */
end_comment

begin_struct
struct|struct
name|tws_command_apache
block|{
name|u_int8_t
name|res__opcode
decl_stmt|;
comment|/* 3:5 */
name|u_int8_t
name|unit
decl_stmt|;
name|u_int16_t
name|lun_l4__req_id
decl_stmt|;
comment|/* 4:12 */
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|sgl_offset
decl_stmt|;
comment|/* offset (in bytes) to sg_list,                                       from the end of sgl_entries */
name|u_int16_t
name|lun_h4__sgl_entries
decl_stmt|;
name|u_int8_t
name|cdb
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|sg_list
index|[
literal|744
index|]
decl_stmt|;
comment|/* 768 - 24 */
name|u_int8_t
name|padding
index|[
literal|128
index|]
decl_stmt|;
comment|/* make it 1024 bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_command_packet
block|{
name|struct
name|tws_command_header
name|hdr
decl_stmt|;
union|union
block|{
name|union
name|tws_command_giga
name|pkt_g
decl_stmt|;
name|struct
name|tws_command_apache
name|pkt_a
decl_stmt|;
block|}
name|cmd
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing payload for get/set param commands. */
end_comment

begin_struct
struct|struct
name|tws_getset_param
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
struct|;
end_struct

begin_struct
struct|struct
name|tws_outbound_response
block|{
name|u_int32_t
name|not_mfa
range|:
literal|1
decl_stmt|;
comment|/* 1 if the structure is valid else MFA */
name|u_int32_t
name|reserved
range|:
literal|7
decl_stmt|;
comment|/* reserved bits */
name|u_int32_t
name|status
range|:
literal|8
decl_stmt|;
comment|/* should be 0 */
name|u_int32_t
name|request_id
range|:
literal|16
decl_stmt|;
comment|/* request id */
block|}
struct|;
end_struct

begin_comment
comment|/* Scatter/Gather list entry with 32 bit addresses. */
end_comment

begin_struct
struct|struct
name|tws_sg_desc32
block|{
name|u_int32_t
name|address
decl_stmt|;
name|u_int32_t
name|length
range|:
literal|24
decl_stmt|;
name|u_int32_t
name|flag
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Scatter/Gather list entry with 64 bit addresses. */
end_comment

begin_struct
struct|struct
name|tws_sg_desc64
block|{
name|u_int64_t
name|address
decl_stmt|;
name|u_int64_t
name|length
range|:
literal|32
decl_stmt|;
name|u_int64_t
name|reserved
range|:
literal|24
decl_stmt|;
name|u_int64_t
name|flag
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packet that describes an AEN/error generated by the controller,  * shared with user  */
end_comment

begin_struct
struct|struct
name|tws_event_packet
block|{
name|u_int32_t
name|sequence_id
decl_stmt|;
name|u_int32_t
name|time_stamp_sec
decl_stmt|;
name|u_int16_t
name|aen_code
decl_stmt|;
name|u_int8_t
name|severity
decl_stmt|;
name|u_int8_t
name|retrieved
decl_stmt|;
name|u_int8_t
name|repeat_count
decl_stmt|;
name|u_int8_t
name|parameter_len
decl_stmt|;
name|u_int8_t
name|parameter_data
index|[
name|TWS_ERROR_SPECIFIC_DESC_LEN
index|]
decl_stmt|;
name|u_int32_t
name|event_src
decl_stmt|;
name|u_int8_t
name|severity_str
index|[
literal|20
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

begin_struct
struct|struct
name|tws_sense
block|{
name|struct
name|tws_command_header
modifier|*
name|hdr
decl_stmt|;
name|u_int64_t
name|hdr_pkt_phy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_request
block|{
name|struct
name|tws_command_packet
modifier|*
name|cmd_pkt
decl_stmt|;
comment|/* command pkt */
name|u_int64_t
name|cmd_pkt_phy
decl_stmt|;
comment|/* cmd pkt physical address */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* ptr to data being passed to fw */
name|u_int32_t
name|length
decl_stmt|;
comment|/* length of data being passed to fw */
name|u_int32_t
name|state
decl_stmt|;
comment|/* request state */
name|u_int32_t
name|type
decl_stmt|;
comment|/* request type */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* request flags */
name|u_int32_t
name|error_code
decl_stmt|;
comment|/* error during request processing */
name|u_int32_t
name|request_id
decl_stmt|;
comment|/* request id for tracking with fw */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|tws_request
modifier|*
parameter_list|)
function_decl|;
comment|/* callback func */
name|bus_dmamap_t
name|dma_map
decl_stmt|;
comment|/* dma map */
name|union
name|ccb
modifier|*
name|ccb_ptr
decl_stmt|;
comment|/* pointer to ccb */
name|struct
name|callout
name|timeout
decl_stmt|;
comment|/* request timeout timer */
name|struct
name|tws_softc
modifier|*
name|sc
decl_stmt|;
comment|/* pointer back to ctlr softc */
name|struct
name|tws_request
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next request */
name|struct
name|tws_request
modifier|*
name|prev
decl_stmt|;
comment|/* pointer to prev request */
block|}
struct|;
end_struct

end_unit

