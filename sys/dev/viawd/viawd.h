begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Fabien Thomas<fabient@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIAWD_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIAWD_H_
end_define

begin_struct
struct|struct
name|viawd_device
block|{
name|uint16_t
name|device
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|viawd_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|device_t
name|sb_dev
decl_stmt|;
name|int
name|wd_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|wd_res
decl_stmt|;
name|eventhandler_tag
name|ev_tag
decl_stmt|;
name|unsigned
name|int
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VENDORID_VIA
value|0x1106
end_define

begin_define
define|#
directive|define
name|DEVICEID_VT8251
value|0x3287
end_define

begin_define
define|#
directive|define
name|DEVICEID_CX700
value|0x8324
end_define

begin_define
define|#
directive|define
name|DEVICEID_VX800
value|0x8353
end_define

begin_define
define|#
directive|define
name|DEVICEID_VX855
value|0x8409
end_define

begin_define
define|#
directive|define
name|DEVICEID_VX900
value|0x8410
end_define

begin_define
define|#
directive|define
name|VIAWD_CONFIG_BASE
value|0xE8
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_LEN
value|8
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL_TRIGGER
value|0x000000080
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL_DISABLE
value|0x000000008
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL_POWEROFF
value|0x000000004
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL_FIRED
value|0x000000002
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_CTRL_ENABLE
value|0x000000001
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_COUNT_MIN
value|1
end_define

begin_define
define|#
directive|define
name|VIAWD_MEM_COUNT_MAX
value|1023
end_define

begin_define
define|#
directive|define
name|VIAWD_TIMEOUT_SHUTDOWN
value|(5 * 60)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

