begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * #defines and software structures for the Compaq RAID card  */
end_comment

begin_comment
comment|/*  * defines for older EISA controllers (IDA, IDA-2, IAES, SMART)  */
end_comment

begin_define
define|#
directive|define
name|R_EISA_INT_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|R_EISA_LOCAL_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|R_EISA_LOCAL_DOORBELL
value|0x05
end_define

begin_define
define|#
directive|define
name|R_EISA_SYSTEM_MASK
value|0x06
end_define

begin_define
define|#
directive|define
name|R_EISA_SYSTEM_DOORBELL
value|0x07
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_ADDR
value|0x08
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_LEN
value|0x0c
end_define

begin_define
define|#
directive|define
name|R_EISA_TAG
value|0x0f
end_define

begin_define
define|#
directive|define
name|R_EISA_COMPLETE_ADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|R_EISA_LIST_STATUS
value|0x16
end_define

begin_define
define|#
directive|define
name|EISA_CHANNEL_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|EISA_CHANNEL_CLEAR
value|0x02
end_define

begin_comment
comment|/*  * board register offsets for SMART-2 controllers  */
end_comment

begin_define
define|#
directive|define
name|R_CMD_FIFO
value|0x04
end_define

begin_define
define|#
directive|define
name|R_DONE_FIFO
value|0x08
end_define

begin_define
define|#
directive|define
name|R_INT_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|R_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|R_INT_PENDING
value|0x14
end_define

begin_comment
comment|/*  * interrupt mask values for SMART series  */
end_comment

begin_define
define|#
directive|define
name|INT_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|INT_ENABLE
value|0x01
end_define

begin_comment
comment|/*  * board offsets for the 42xx series  */
end_comment

begin_define
define|#
directive|define
name|R_42XX_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|R_42XX_INT_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|R_42XX_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|R_42XX_REPLY
value|0x44
end_define

begin_comment
comment|/*  * interrupt values for 42xx series  */
end_comment

begin_define
define|#
directive|define
name|INT_ENABLE_42XX
value|0x00
end_define

begin_define
define|#
directive|define
name|INT_DISABLE_42XX
value|0x08
end_define

begin_define
define|#
directive|define
name|STATUS_42XX_INT_PENDING
value|0x08
end_define

begin_comment
comment|/*  * return status codes  */
end_comment

begin_define
define|#
directive|define
name|SOFT_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|HARD_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|CMD_REJECTED
value|0x14
end_define

begin_comment
comment|/*  * command types   */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_LOG_DRV_INFO
value|0x10
end_define

begin_define
define|#
directive|define
name|CMD_GET_CTRL_INFO
value|0x11
end_define

begin_define
define|#
directive|define
name|CMD_SENSE_DRV_STATUS
value|0x12
end_define

begin_define
define|#
directive|define
name|CMD_START_RECOVERY
value|0x13
end_define

begin_define
define|#
directive|define
name|CMD_GET_PHYS_DRV_INFO
value|0x15
end_define

begin_define
define|#
directive|define
name|CMD_BLINK_DRV_LEDS
value|0x16
end_define

begin_define
define|#
directive|define
name|CMD_SENSE_DRV_LEDS
value|0x17
end_define

begin_define
define|#
directive|define
name|CMD_GET_LOG_DRV_EXT
value|0x18
end_define

begin_define
define|#
directive|define
name|CMD_GET_CTRL_INFO
value|0x11
end_define

begin_define
define|#
directive|define
name|CMD_READ
value|0x20
end_define

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x30
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_MEDIA
value|0x31
end_define

begin_define
define|#
directive|define
name|CMD_GET_CONFIG
value|0x50
end_define

begin_define
define|#
directive|define
name|CMD_SET_CONFIG
value|0x51
end_define

begin_define
define|#
directive|define
name|CMD_START_FIRMWARE
value|0x99
end_define

begin_comment
comment|/* for integrated RAID */
end_comment

begin_define
define|#
directive|define
name|CMD_FLUSH_CACHE
value|0xc2
end_define

begin_comment
comment|/*  * command structures  */
end_comment

begin_struct
struct|struct
name|ida_drive_info
block|{
name|u_int16_t
name|secsize
decl_stmt|;
name|u_int32_t
name|secperunit
decl_stmt|;
name|u_int16_t
name|ncylinders
decl_stmt|;
name|u_int8_t
name|nheads
decl_stmt|;
name|u_int8_t
name|signature
decl_stmt|;
name|u_int8_t
name|psectors
decl_stmt|;
name|u_int16_t
name|wprecomp
decl_stmt|;
name|u_int8_t
name|max_acc
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
name|u_int16_t
name|pcylinders
decl_stmt|;
name|u_int8_t
name|ptracks
decl_stmt|;
name|u_int16_t
name|landing_zone
decl_stmt|;
name|u_int8_t
name|nsectors
decl_stmt|;
name|u_int8_t
name|checksum
decl_stmt|;
name|u_int8_t
name|mirror
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
name|ida_controller_info
block|{
name|u_int8_t
name|num_drvs
decl_stmt|;
name|u_int32_t
name|signature
decl_stmt|;
name|u_int8_t
name|firm_rev
index|[
literal|4
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
name|ida_drive_status
block|{
name|u_int8_t
name|status
decl_stmt|;
name|u_int32_t
name|failure_map
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|416
index|]
decl_stmt|;
name|u_int32_t
name|secrecover
decl_stmt|;
name|u_int8_t
name|rebuilding
decl_stmt|;
name|u_int16_t
name|remap_cnt
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|repl_map
decl_stmt|;
name|u_int32_t
name|spare_map
decl_stmt|;
name|u_int8_t
name|spare_status
decl_stmt|;
name|u_int8_t
name|spare_repl_map
index|[
literal|32
index|]
decl_stmt|;
name|u_int32_t
name|repl_ok_map
decl_stmt|;
name|u_int8_t
name|media_exchange
decl_stmt|;
name|u_int8_t
name|cache_failure
decl_stmt|;
name|u_int8_t
name|expand_failure
decl_stmt|;
name|u_int8_t
name|unit_flags
decl_stmt|;
name|u_int16_t
name|big_failure_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|big_remap_cnt
index|[
literal|128
index|]
decl_stmt|;
name|u_int16_t
name|big_repl_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|big_act_spare_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_spare_repl_map
index|[
literal|128
index|]
decl_stmt|;
name|u_int16_t
name|big_repl_ok_map
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|big_rebuilding
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

end_unit

