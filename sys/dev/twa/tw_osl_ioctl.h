begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_IOCTL_H
end_define

begin_comment
comment|/*  * Macros and structures for OS Layer/Common Layer handled ioctls.  */
end_comment

begin_include
include|#
directive|include
file|<dev/twa/tw_cl_fwif.h>
end_include

begin_include
include|#
directive|include
file|<dev/twa/tw_cl_ioctl.h>
end_include

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

begin_typedef
typedef|typedef
struct|struct
name|tw_osli_ioctl_no_data_buf
block|{
name|struct
name|tw_cl_driver_packet
name|driver_pkt
decl_stmt|;
name|TW_VOID
modifier|*
name|pdata
decl_stmt|;
comment|/* points to data_buf */
name|TW_INT8
name|padding
index|[
literal|488
operator|-
sizeof|sizeof
argument_list|(
name|TW_VOID
operator|*
argument_list|)
index|]
decl_stmt|;
name|struct
name|tw_cl_command_packet
name|cmd_pkt
decl_stmt|;
block|}
name|TW_OSLI_IOCTL_NO_DATA_BUF
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* ioctl cmds handled by the OS Layer */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_IOCTL_SCAN_BUS
define|\
value|_IO('T', 200)
end_define

begin_define
define|#
directive|define
name|TW_OSL_IOCTL_FIRMWARE_PASS_THROUGH
define|\
value|_IOWR('T', 202, TW_OSLI_IOCTL_NO_DATA_BUF)
end_define

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

begin_typedef
typedef|typedef
struct|struct
name|tw_osli_ioctl_with_payload
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
union|union
block|{
name|struct
name|tw_cl_event_packet
name|event_pkt
decl_stmt|;
name|struct
name|tw_cl_lock_packet
name|lock_pkt
decl_stmt|;
name|struct
name|tw_cl_compatibility_packet
name|compat_pkt
decl_stmt|;
name|TW_INT8
name|data_buf
index|[
literal|1
index|]
decl_stmt|;
block|}
name|payload
union|;
block|}
name|TW_OSLI_IOCTL_WITH_PAYLOAD
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* ioctl cmds handled by the Common Layer */
end_comment

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_FIRST_EVENT
define|\
value|_IOWR('T', 203, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_LAST_EVENT
define|\
value|_IOWR('T', 204, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_NEXT_EVENT
define|\
value|_IOWR('T', 205, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_PREVIOUS_EVENT
define|\
value|_IOWR('T', 206, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_LOCK
define|\
value|_IOWR('T', 207, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_RELEASE_LOCK
define|\
value|_IOWR('T', 208, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_define
define|#
directive|define
name|TW_CL_IOCTL_GET_COMPATIBILITY_INFO
define|\
value|_IOWR('T', 209, TW_OSLI_IOCTL_WITH_PAYLOAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_IOCTL_H */
end_comment

end_unit

