begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Matthew N. Dodd<winter@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMAPI_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|smapi_bios_header
block|{
name|u_int8_t
name|signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* '$SMB' */
name|u_int8_t
name|version_major
decl_stmt|;
name|u_int8_t
name|version_minor
decl_stmt|;
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|checksum
decl_stmt|;
name|u_int16_t
name|information
decl_stmt|;
define|#
directive|define
name|SMAPI_REAL_VM86
value|0x0001
define|#
directive|define
name|SMAPI_PROT_16BIT
value|0x0002
define|#
directive|define
name|SMAPI_PROT_32BIT
value|0x0004
name|u_int16_t
name|reserved1
decl_stmt|;
name|u_int16_t
name|real16_offset
decl_stmt|;
name|u_int16_t
name|real16_segment
decl_stmt|;
name|u_int16_t
name|reserved2
decl_stmt|;
name|u_int16_t
name|prot16_offset
decl_stmt|;
name|u_int32_t
name|prot16_segment
decl_stmt|;
name|u_int32_t
name|prot32_offset
decl_stmt|;
name|u_int32_t
name|prot32_segment
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|smapi_bios_parameter
block|{
union|union
block|{
struct|struct
block|{
name|u_int8_t
name|func
decl_stmt|;
name|u_int8_t
name|sub_func
decl_stmt|;
block|}
name|in
struct|;
struct|struct
block|{
name|u_int8_t
name|rc
decl_stmt|;
name|u_int8_t
name|sub_rc
decl_stmt|;
block|}
name|out
struct|;
block|}
name|type
union|;
name|u_int16_t
name|param1
decl_stmt|;
name|u_int16_t
name|param2
decl_stmt|;
name|u_int16_t
name|param3
decl_stmt|;
name|u_int32_t
name|param4
decl_stmt|;
name|u_int32_t
name|param5
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|cmd_func
value|type.in.func
end_define

begin_define
define|#
directive|define
name|cmd_sub_func
value|type.in.sub_func
end_define

begin_define
define|#
directive|define
name|rsp_rc
value|type.out.rc
end_define

begin_define
define|#
directive|define
name|rsp_sub_rc
value|type.out.sub_rc
end_define

begin_define
define|#
directive|define
name|SMAPIOGHEADER
value|_IOR('$', 0, struct smapi_bios_header)
end_define

begin_define
define|#
directive|define
name|SMAPIOCGFUNCTION
value|_IOWR('$', 1, struct smapi_bios_parameter)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMAPI_H_ */
end_comment

end_unit

