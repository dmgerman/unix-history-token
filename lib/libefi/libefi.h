begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBEFI_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBEFI_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Attributes. */
end_comment

begin_define
define|#
directive|define
name|EFI_ATTR_NV
value|0x0001
end_define

begin_comment
comment|/* Variable stored in NVRAM. */
end_comment

begin_define
define|#
directive|define
name|EFI_ATTR_BS
value|0x0002
end_define

begin_comment
comment|/* Boot services accessable. */
end_comment

begin_define
define|#
directive|define
name|EFI_ATTR_RT
value|0x0004
end_define

begin_comment
comment|/* Runtime accessable. */
end_comment

begin_define
define|#
directive|define
name|EFI_ATTR_HR
value|0x0008
end_define

begin_comment
comment|/* Hardware error record. */
end_comment

begin_define
define|#
directive|define
name|EFI_ATTR_WR
value|0x0010
end_define

begin_comment
comment|/* Authenticated write access. */
end_comment

begin_comment
comment|/* Vendor for architecturally defined variables. */
end_comment

begin_define
define|#
directive|define
name|EFI_GLOBAL_VARIABLE
define|\
value|{0x8be4df61,0x93ca,0x11d2,0xaa,0x0d,{0x00,0xe0,0x98,0x03,0x2b,0x8c}}
end_define

begin_comment
comment|/* Vendor for FreeBSD-specific variables. */
end_comment

begin_define
define|#
directive|define
name|EFI_FREEBSD_VARIABLE
define|\
value|{0x13c32014,0x0c9c,0x11df,0xa2,0x38,{0x00,0x17,0xa4,0xab,0x91,0x2d}}
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|efi_getvar
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_nextvarname
parameter_list|(
name|size_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|uuid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_setvar
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBEFI_H_ */
end_comment

end_unit

