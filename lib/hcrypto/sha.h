begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_SHA_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_SHA_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|SHA1_Init
value|hc_SHA1_Init
end_define

begin_define
define|#
directive|define
name|SHA1_Update
value|hc_SHA1_Update
end_define

begin_define
define|#
directive|define
name|SHA1_Final
value|hc_SHA1_Final
end_define

begin_define
define|#
directive|define
name|SHA256_Init
value|hc_SHA256_Init
end_define

begin_define
define|#
directive|define
name|SHA256_Update
value|hc_SHA256_Update
end_define

begin_define
define|#
directive|define
name|SHA256_Final
value|hc_SHA256_Final
end_define

begin_define
define|#
directive|define
name|SHA384_Init
value|hc_SHA384_Init
end_define

begin_define
define|#
directive|define
name|SHA384_Update
value|hc_SHA384_Update
end_define

begin_define
define|#
directive|define
name|SHA384_Final
value|hc_SHA384_Final
end_define

begin_define
define|#
directive|define
name|SHA512_Init
value|hc_SHA512_Init
end_define

begin_define
define|#
directive|define
name|SHA512_Update
value|hc_SHA512_Update
end_define

begin_define
define|#
directive|define
name|SHA512_Final
value|hc_SHA512_Final
end_define

begin_comment
comment|/*  * SHA-1  */
end_comment

begin_define
define|#
directive|define
name|SHA_DIGEST_LENGTH
value|20
end_define

begin_struct
struct|struct
name|sha
block|{
name|unsigned
name|int
name|sz
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|counter
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|char
name|save
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sha
name|SHA_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|SHA1_Init
parameter_list|(
name|struct
name|sha
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1_Update
parameter_list|(
name|struct
name|sha
modifier|*
name|m
parameter_list|,
specifier|const
name|void
modifier|*
name|v
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1_Final
parameter_list|(
name|void
modifier|*
name|res
parameter_list|,
name|struct
name|sha
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SHA-2 256  */
end_comment

begin_define
define|#
directive|define
name|SHA256_DIGEST_LENGTH
value|32
end_define

begin_struct
struct|struct
name|hc_sha256state
block|{
name|unsigned
name|int
name|sz
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|counter
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|save
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hc_sha256state
name|SHA256_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|SHA256_Init
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA256_Update
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA256_Final
parameter_list|(
name|void
modifier|*
parameter_list|,
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SHA-2 512  */
end_comment

begin_define
define|#
directive|define
name|SHA512_DIGEST_LENGTH
value|64
end_define

begin_struct
struct|struct
name|hc_sha512state
block|{
name|uint64_t
name|sz
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|counter
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|save
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hc_sha512state
name|SHA512_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|SHA512_Init
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA512_Update
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA512_Final
parameter_list|(
name|void
modifier|*
parameter_list|,
name|SHA512_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SHA384_DIGEST_LENGTH
value|48
end_define

begin_typedef
typedef|typedef
name|struct
name|hc_sha512state
name|SHA384_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|SHA384_Init
parameter_list|(
name|SHA384_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA384_Update
parameter_list|(
name|SHA384_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA384_Final
parameter_list|(
name|void
modifier|*
parameter_list|,
name|SHA384_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_SHA_H */
end_comment

end_unit

