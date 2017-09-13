begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFIVAR_DP_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFIVAR_DP_H_
end_define

begin_comment
comment|/*  * "Linux compatible" efivar-dp.h header. At the moment, it's really a  * very thin, minimal interface.  */
end_comment

begin_comment
comment|/*  * Generic EFI_DEVICE_PATH, spelled the Linux way. We use this  * interface to the outside world and type-pun to the EFI EDK2 code  * we use to implement it.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|subtype
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
block|}
name|__packed
name|efidp_header
typedef|;
end_typedef

begin_comment
comment|/* NB: Linux has shadow types for all dp type */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|efidp_header
name|header
decl_stmt|;
block|}
name|efidp_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|efidp_data
modifier|*
name|efidp
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|efidp_data
modifier|*
name|const_efidp
typedef|;
end_typedef

begin_comment
comment|/** format a device path into UEFI standard conforming output.  *  * NB: FreeBSD's implementation is taken from EDK2, while Linux's  * was hand-rolled. There may be differences as a result.  */
end_comment

begin_function_decl
name|ssize_t
name|efidp_format_device_path
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|const_efidp
name|dp
parameter_list|,
name|ssize_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|efidp_parse_device_path
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|efidp
name|out
parameter_list|,
name|size_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|efidp_size
parameter_list|(
name|const_efidp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EFIVAR_DP_H_ */
end_comment

end_unit

