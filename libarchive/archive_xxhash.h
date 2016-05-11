begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Michihiro NAKAJIMA  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_XXHASH_H
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_XXHASH_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XXH_OK
init|=
literal|0
block|,
name|XXH_ERROR
block|}
name|XXH_errorcode
typedef|;
end_typedef

begin_struct
struct|struct
name|archive_xxhash
block|{
name|unsigned
name|int
function_decl|(
modifier|*
name|XXH32
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|unsigned
name|int
name|seed
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|XXH32_init
function_decl|)
parameter_list|(
name|unsigned
name|int
name|seed
parameter_list|)
function_decl|;
name|XXH_errorcode
function_decl|(
modifier|*
name|XXH32_update
function_decl|)
parameter_list|(
name|void
modifier|*
name|state
parameter_list|,
specifier|const
name|void
modifier|*
name|input
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|XXH32_digest
function_decl|)
parameter_list|(
name|void
modifier|*
name|state
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|archive_xxhash
name|__archive_xxhash
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

