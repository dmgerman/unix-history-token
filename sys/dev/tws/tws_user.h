begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2010, LSI Corp.  * All rights reserved.  * Author : Manjunath Ranganathaiah  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of the<ORGANIZATION> nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TWS_AEN_NOT_RETRIEVED
value|0x1
end_define

begin_define
define|#
directive|define
name|TWS_AEN_RETRIEVED
value|0x2
end_define

begin_define
define|#
directive|define
name|TWS_AEN_NO_EVENTS
value|0x1003
end_define

begin_comment
comment|/* No more events */
end_comment

begin_define
define|#
directive|define
name|TWS_AEN_OVERFLOW
value|0x1004
end_define

begin_comment
comment|/* AEN overflow occurred */
end_comment

begin_define
define|#
directive|define
name|TWS_IOCTL_LOCK_NOT_HELD
value|0x1001
end_define

begin_comment
comment|/* Not locked */
end_comment

begin_define
define|#
directive|define
name|TWS_IOCTL_LOCK_ALREADY_HELD
value|0x1002
end_define

begin_comment
comment|/* Already locked */
end_comment

begin_define
define|#
directive|define
name|TWS_IOCTL_LOCK_HELD
value|0x1
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_LOCK_FREE
value|0x0
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
comment|/* Structure used to handle GET/RELEASE LOCK ioctls. */
end_comment

begin_struct
struct|struct
name|tws_lock_packet
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
struct|;
end_struct

begin_comment
comment|/* Structure used to handle GET COMPATIBILITY INFO ioctl. */
end_comment

begin_struct
struct|struct
name|tws_compatibility_packet
block|{
name|u_int8_t
name|driver_version
index|[
literal|32
index|]
decl_stmt|;
comment|/* driver version */
name|u_int16_t
name|working_srl
decl_stmt|;
comment|/* driver& firmware negotiated srl */
name|u_int16_t
name|working_branch
decl_stmt|;
comment|/* branch # of the firmware that the                                     driver is compatible with */
name|u_int16_t
name|working_build
decl_stmt|;
comment|/* build # of the firmware that the                                         driver is compatible with */
name|u_int16_t
name|driver_srl_high
decl_stmt|;
comment|/* highest driver supported srl */
name|u_int16_t
name|driver_branch_high
decl_stmt|;
comment|/* highest driver supported branch */
name|u_int16_t
name|driver_build_high
decl_stmt|;
comment|/* highest driver supported build */
name|u_int16_t
name|driver_srl_low
decl_stmt|;
comment|/* lowest driver supported srl */
name|u_int16_t
name|driver_branch_low
decl_stmt|;
comment|/* lowest driver supported branch */
name|u_int16_t
name|driver_build_low
decl_stmt|;
comment|/* lowest driver supported build */
name|u_int16_t
name|fw_on_ctlr_srl
decl_stmt|;
comment|/* srl of running firmware */
name|u_int16_t
name|fw_on_ctlr_branch
decl_stmt|;
comment|/* branch # of running firmware */
name|u_int16_t
name|fw_on_ctlr_build
decl_stmt|;
comment|/* build # of running firmware */
block|}
struct|;
end_struct

begin_comment
comment|/* Driver understandable part of the ioctl packet built by the API. */
end_comment

begin_struct
struct|struct
name|tws_driver_packet
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
struct|;
end_struct

begin_comment
comment|/* ioctl packet built by the API. */
end_comment

begin_struct
struct|struct
name|tws_ioctl_packet
block|{
name|struct
name|tws_driver_packet
name|driver_pkt
decl_stmt|;
name|char
name|padding
index|[
literal|488
index|]
decl_stmt|;
name|struct
name|tws_command_packet
name|cmd_pkt
decl_stmt|;
name|char
name|data_buf
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

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/*  * We need the structure below to ensure that the first byte of  * data_buf is not overwritten by the kernel, after we return  * from the ioctl call.  Note that cmd_pkt has been reduced  * to an array of 1024 bytes even though it's actually 2048 bytes  * in size.  This is because, we don't expect requests from user  * land requiring 2048 (273 sg elements) byte cmd pkts.  */
end_comment

begin_struct
struct|struct
name|tws_ioctl_no_data_buf
block|{
name|struct
name|tws_driver_packet
name|driver_pkt
decl_stmt|;
name|void
modifier|*
name|pdata
decl_stmt|;
comment|/* points to data_buf */
name|char
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
name|tws_command_packet
name|cmd_pkt
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

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

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
name|tws_ioctl_with_payload
block|{
name|struct
name|tws_driver_packet
name|driver_pkt
decl_stmt|;
name|char
name|padding
index|[
literal|488
index|]
decl_stmt|;
name|struct
name|tws_command_packet
name|cmd_pkt
decl_stmt|;
union|union
block|{
name|struct
name|tws_event_packet
name|event_pkt
decl_stmt|;
name|struct
name|tws_lock_packet
name|lock_pkt
decl_stmt|;
name|struct
name|tws_compatibility_packet
name|compat_pkt
decl_stmt|;
name|char
name|data_buf
index|[
literal|1
index|]
decl_stmt|;
block|}
name|payload
union|;
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
comment|/* ioctl cmds */
end_comment

begin_define
define|#
directive|define
name|TWS_IOCTL_SCAN_BUS
define|\
value|_IO('T', 200)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_FIRMWARE_PASS_THROUGH
define|\
value|_IOWR('T', 202, struct tws_ioctl_no_data_buf)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_FIRST_EVENT
define|\
value|_IOWR('T', 203, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_LAST_EVENT
define|\
value|_IOWR('T', 204, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_NEXT_EVENT
define|\
value|_IOWR('T', 205, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_PREVIOUS_EVENT
define|\
value|_IOWR('T', 206, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_LOCK
define|\
value|_IOWR('T', 207, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_RELEASE_LOCK
define|\
value|_IOWR('T', 208, struct tws_ioctl_with_payload)
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_GET_COMPATIBILITY_INFO
define|\
value|_IOWR('T', 209, struct tws_ioctl_with_payload)
end_define

end_unit

