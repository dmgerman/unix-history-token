begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Adaptec Inc.  * All rights reserved.  *  * Written by: David Jeffery  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|IPS_USER_CMD
value|_IOWR(0x81,0x21,ips_user_request)
end_define

begin_define
define|#
directive|define
name|IPS_IOCTL_READ
value|1
end_define

begin_define
define|#
directive|define
name|IPS_IOCTL_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|IPS_REBUILD_STAT_SIZE
value|116
end_define

begin_define
define|#
directive|define
name|IPS_SUBSYS_PARAM_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IPS_RW_NVRAM_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IPS_IOCTL_BUFFER_SIZE
value|4096
end_define

begin_typedef
typedef|typedef
struct|struct
name|ips_ioctl
block|{
name|ips_generic_cmd
modifier|*
name|command_buffer
decl_stmt|;
name|void
modifier|*
name|data_buffer
decl_stmt|;
name|ips_cmd_status_t
name|status
decl_stmt|;
name|int
name|datasize
decl_stmt|;
name|int
name|readwrite
decl_stmt|;
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
block|}
name|ips_ioctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ips_user_request
block|{
name|void
modifier|*
name|command_buffer
decl_stmt|;
name|void
modifier|*
name|data_buffer
decl_stmt|;
name|u_int32_t
name|status
decl_stmt|;
block|}
name|ips_user_request
typedef|;
end_typedef

end_unit

