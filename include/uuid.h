begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002,2005 Marcel Moolenaar  * Copyright (c) 2002 Hiten Mahesh Pandya  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_UUID_H_
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

begin_comment
comment|/*  * This implementation mostly conforms to the DCE 1.1 specification.  * See Also:  *	uuidgen(1), uuidgen(2), uuid(3)  */
end_comment

begin_comment
comment|/* Status codes returned by the functions. */
end_comment

begin_define
define|#
directive|define
name|uuid_s_ok
value|0
end_define

begin_define
define|#
directive|define
name|uuid_s_bad_version
value|1
end_define

begin_define
define|#
directive|define
name|uuid_s_invalid_string_uuid
value|2
end_define

begin_define
define|#
directive|define
name|uuid_s_no_memory
value|3
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int32_t
name|uuid_compare
parameter_list|(
specifier|const
name|uuid_t
modifier|*
parameter_list|,
specifier|const
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_create
parameter_list|(
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_create_nil
parameter_list|(
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|uuid_equal
parameter_list|(
specifier|const
name|uuid_t
modifier|*
parameter_list|,
specifier|const
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_from_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|uuid_hash
parameter_list|(
specifier|const
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|uuid_is_nil
parameter_list|(
specifier|const
name|uuid_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uuid_to_string
parameter_list|(
specifier|const
name|uuid_t
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|uint32_t
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
comment|/* _UUID_H_ */
end_comment

end_unit

