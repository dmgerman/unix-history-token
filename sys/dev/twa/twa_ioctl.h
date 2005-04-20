begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-04 3ware, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  */
end_comment

begin_define
define|#
directive|define
name|TWA_AEN_NOT_RETRIEVED
value|0x1
end_define

begin_define
define|#
directive|define
name|TWA_AEN_RETRIEVED
value|0x2
end_define

begin_define
define|#
directive|define
name|TWA_ERROR_AEN_NO_EVENTS
value|0x1003
end_define

begin_comment
comment|/* No more events */
end_comment

begin_define
define|#
directive|define
name|TWA_ERROR_AEN_OVERFLOW
value|0x1004
end_define

begin_comment
comment|/* AEN clobber occurred */
end_comment

begin_define
define|#
directive|define
name|TWA_ERROR_IOCTL_LOCK_NOT_HELD
value|0x1001
end_define

begin_comment
comment|/* Not locked */
end_comment

begin_define
define|#
directive|define
name|TWA_ERROR_IOCTL_LOCK_ALREADY_HELD
value|0x1002
end_define

begin_comment
comment|/* Already locked */
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
name|twa_scan_bus_packet
block|{
name|u_int32_t
name|unit
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
name|twa_event_packet
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
literal|98
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
name|twa_lock_packet
block|{
name|u_int32_t
name|timeout_msec
decl_stmt|;
name|u_int32_t
name|time_remaining_msec
decl_stmt|;
name|u_int32_t
name|force_flag
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
name|twa_compatibility_packet
block|{
name|uint8_t
name|driver_version
index|[
literal|32
index|]
decl_stmt|;
comment|/* driver version */
name|uint16_t
name|working_srl
decl_stmt|;
comment|/* driver& firmware negotiated srl */
name|uint16_t
name|working_branch
decl_stmt|;
comment|/* branch # of the firmware that the driver is compatible with */
name|uint16_t
name|working_build
decl_stmt|;
comment|/* build # of the firmware that the driver is compatible with */
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
name|twa_driver_packet
block|{
name|u_int32_t
name|control_code
decl_stmt|;
name|u_int32_t
name|status
decl_stmt|;
name|u_int32_t
name|unique_id
decl_stmt|;
name|u_int32_t
name|sequence_id
decl_stmt|;
name|u_int32_t
name|os_status
decl_stmt|;
name|u_int32_t
name|buffer_length
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
name|twa_ioctl_9k
block|{
name|struct
name|twa_driver_packet
name|twa_drvr_pkt
decl_stmt|;
name|void
modifier|*
name|pdata
decl_stmt|;
comment|/* points to data_buf */
name|int8_t
name|padding
index|[
literal|488
operator|-
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|struct
name|twa_command_packet
name|twa_cmd_pkt
decl_stmt|;
name|int8_t
name|data_buf
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

begin_comment
comment|/*  * We need the structure below to ensure that the first byte of  * data_buf is not overwritten by the kernel, after we return  * from the ioctl call.  Note that twa_cmd_pkt has been reduced  * to an array of 1024 bytes even though it's actually 2048 bytes  * in size.  This is because, we don't expect requests from user  * land requiring 2048 (273 sg elements) byte cmd pkts.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|twa_ioctl_no_data_buf
block|{
name|struct
name|twa_driver_packet
name|twa_drvr_pkt
decl_stmt|;
name|void
modifier|*
name|pdata
decl_stmt|;
comment|/* points to data_buf */
name|int8_t
name|padding
index|[
literal|488
operator|-
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|struct
name|twa_command_packet
name|twa_cmd_pkt
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|TWA_IOCTL_NO_DATA_BUF
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|TWA_IOCTL_SCAN_BUS
value|_IOW ('T', 200, u_int32_t)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_FIRMWARE_PASS_THROUGH
value|_IOWR('T', 202, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_FIRST_EVENT
value|_IOWR('T', 203, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_LAST_EVENT
value|_IOWR('T', 204, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_NEXT_EVENT
value|_IOWR('T', 205, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_PREVIOUS_EVENT
value|_IOWR('T', 206, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_LOCK
value|_IOWR('T', 207, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_RELEASE_LOCK
value|_IOWR('T', 208, TWA_IOCTL_NO_DATA_BUF)
end_define

begin_define
define|#
directive|define
name|TWA_IOCTL_GET_COMPATIBILITY_INFO
value|_IOWR('T', 209, TWA_IOCTL_NO_DATA_BUF)
end_define

end_unit

