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
name|TW_CL_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|TW_CL_IOCTL_H
end_define

begin_comment
comment|/*  * Macros and structures for Common Layer handled ioctls.  */
end_comment

begin_define
define|#
directive|define
name|TW_CL_AEN_NOT_RETRIEVED
value|0x1
end_define

begin_define
define|#
directive|define
name|TW_CL_AEN_RETRIEVED
value|0x2
end_define

begin_define
define|#
directive|define
name|TW_CL_ERROR_AEN_NO_EVENTS
value|0x1003
end_define

begin_comment
comment|/* No more events */
end_comment

begin_define
define|#
directive|define
name|TW_CL_ERROR_AEN_OVERFLOW
value|0x1004
end_define

begin_comment
comment|/* AEN overflow occurred */
end_comment

begin_define
define|#
directive|define
name|TW_CL_ERROR_IOCTL_LOCK_NOT_HELD
value|0x1001
end_define

begin_comment
comment|/* Not locked */
end_comment

begin_define
define|#
directive|define
name|TW_CL_ERROR_IOCTL_LOCK_ALREADY_HELD
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

begin_comment
comment|/* Structure used to handle GET/RELEASE LOCK ioctls. */
end_comment

begin_struct
struct|struct
name|tw_cl_lock_packet
block|{
name|TW_UINT32
name|timeout_msec
decl_stmt|;
name|TW_UINT32
name|time_remaining_msec
decl_stmt|;
name|TW_UINT32
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
name|tw_cl_compatibility_packet
block|{
name|TW_UINT8
name|driver_version
index|[
literal|32
index|]
decl_stmt|;
comment|/* driver version */
name|TW_UINT16
name|working_srl
decl_stmt|;
comment|/* driver& firmware negotiated srl */
name|TW_UINT16
name|working_branch
decl_stmt|;
comment|/* branch # of the firmware that the 					driver is compatible with */
name|TW_UINT16
name|working_build
decl_stmt|;
comment|/* build # of the firmware that the 					driver is compatible with */
name|TW_UINT16
name|driver_srl_high
decl_stmt|;
comment|/* highest driver supported srl */
name|TW_UINT16
name|driver_branch_high
decl_stmt|;
comment|/* highest driver supported branch */
name|TW_UINT16
name|driver_build_high
decl_stmt|;
comment|/* highest driver supported build */
name|TW_UINT16
name|driver_srl_low
decl_stmt|;
comment|/* lowest driver supported srl */
name|TW_UINT16
name|driver_branch_low
decl_stmt|;
comment|/* lowest driver supported branch */
name|TW_UINT16
name|driver_build_low
decl_stmt|;
comment|/* lowest driver supported build */
name|TW_UINT16
name|fw_on_ctlr_srl
decl_stmt|;
comment|/* srl of running firmware */
name|TW_UINT16
name|fw_on_ctlr_branch
decl_stmt|;
comment|/* branch # of running firmware */
name|TW_UINT16
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
name|tw_cl_driver_packet
block|{
name|TW_UINT32
name|control_code
decl_stmt|;
name|TW_UINT32
name|status
decl_stmt|;
name|TW_UINT32
name|unique_id
decl_stmt|;
name|TW_UINT32
name|sequence_id
decl_stmt|;
name|TW_UINT32
name|os_status
decl_stmt|;
name|TW_UINT32
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
name|tw_cl_ioctl_packet
block|{
name|struct
name|tw_cl_driver_packet
name|driver_pkt
decl_stmt|;
name|TW_INT8
name|padding
index|[
literal|488
index|]
decl_stmt|;
name|struct
name|tw_cl_command_packet
name|cmd_pkt
decl_stmt|;
name|TW_INT8
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_CL_IOCTL_H */
end_comment

end_unit

