begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFIVAR_H_
end_define

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_include
include|#
directive|include
file|<sys/efi.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* Shoud these be elsewhere ? */
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_NON_VOLATILE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_BOOTSERVICE_ACCESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_RUNTIME_ACCESS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_HARDWARE_ERROR_RECORD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
define|\
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_APPEND_WRITE
value|0x00000040
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* todo */
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_HAS_AUTH_HEADER
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_HAS_SIGNATURE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_EFIVAR_EFI_GUID_T_DEF
end_ifndef

begin_define
define|#
directive|define
name|_EFIVAR_EFI_GUID_T_DEF
end_define

begin_typedef
typedef|typedef
name|uuid_t
name|efi_guid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|EFI_GUID
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e0
parameter_list|,
name|e1
parameter_list|,
name|e2
parameter_list|,
name|e3
parameter_list|,
name|e4
parameter_list|,
name|e5
parameter_list|)
define|\
value|((efi_guid_t) {(a), (b), (c), (d)>> 8, (d)& 0xff,		\ 	{ (e0), (e1), (e2), (e3), (e4), (e5) }})
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EFI_GUID
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e0
parameter_list|,
name|e1
parameter_list|,
name|e2
parameter_list|,
name|e3
parameter_list|,
name|e4
parameter_list|,
name|e5
parameter_list|)
define|\
value|((efi_guid_t) {(a), (b), (c), (d)& 0xff, (d)>> 8,		\ 	{ (e0), (e1), (e2), (e3), (e4), (e5) }})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EFI_GLOBAL_GUID
value|EFI_GUID(0x8be4df61, 0x93ca, 0x11d2, 0xaa0d, \     0x00, 0xe0, 0x98, 0x03, 0x2b, 0x8c)
end_define

begin_function_decl
name|int
name|efi_append_variable
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|data_size
parameter_list|,
name|uint32_t
name|attributes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_del_variable
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_get_variable
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_size
parameter_list|,
name|uint32_t
modifier|*
name|attributes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_get_variable_attributes
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint32_t
modifier|*
name|attributes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_get_variable_size
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_get_next_variable_name
parameter_list|(
name|efi_guid_t
modifier|*
modifier|*
name|guid
parameter_list|,
name|char
modifier|*
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_guid_cmp
parameter_list|(
specifier|const
name|efi_guid_t
modifier|*
name|guid1
parameter_list|,
specifier|const
name|efi_guid_t
modifier|*
name|guid2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_guid_is_zero
parameter_list|(
specifier|const
name|efi_guid_t
modifier|*
name|guid1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_guid_to_name
parameter_list|(
name|efi_guid_t
modifier|*
name|guid
parameter_list|,
name|char
modifier|*
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_guid_to_symbol
parameter_list|(
name|efi_guid_t
modifier|*
name|guid
parameter_list|,
name|char
modifier|*
modifier|*
name|symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_guid_to_str
parameter_list|(
specifier|const
name|efi_guid_t
modifier|*
name|guid
parameter_list|,
name|char
modifier|*
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_name_to_guid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|efi_guid_t
modifier|*
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_set_variable
parameter_list|(
name|efi_guid_t
name|guid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|data_size
parameter_list|,
name|uint32_t
name|attributes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_str_to_guid
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|efi_guid_t
modifier|*
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|efi_variables_supported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FreeBSD extensions */
end_comment

begin_struct
struct|struct
name|uuid_table
block|{
specifier|const
name|char
modifier|*
name|uuid_str
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|efi_guid_t
name|guid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|efi_known_guid
parameter_list|(
name|struct
name|uuid_table
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|efi_guid_t
name|efi_guid_empty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EFIVAR_H_ */
end_comment

end_unit

