begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_HMAC_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_HMAC_H
value|1
end_define

begin_include
include|#
directive|include
file|<hcrypto/evp.h>
end_include

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|HMAC_CTX_init
value|hc_HMAC_CTX_init
end_define

begin_define
define|#
directive|define
name|HMAC_CTX_cleanup
value|hc_HMAC_CTX_cleanup
end_define

begin_define
define|#
directive|define
name|HMAC_size
value|hc_HMAC_size
end_define

begin_define
define|#
directive|define
name|HMAC_Init_ex
value|hc_HMAC_Init_ex
end_define

begin_define
define|#
directive|define
name|HMAC_Update
value|hc_HMAC_Update
end_define

begin_define
define|#
directive|define
name|HMAC_Final
value|hc_HMAC_Final
end_define

begin_define
define|#
directive|define
name|HMAC
value|hc_HMAC
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|HMAC_MAX_MD_CBLOCK
value|64
end_define

begin_typedef
typedef|typedef
name|struct
name|hc_HMAC_CTX
name|HMAC_CTX
typedef|;
end_typedef

begin_struct
struct|struct
name|hc_HMAC_CTX
block|{
specifier|const
name|EVP_MD
modifier|*
name|md
decl_stmt|;
name|ENGINE
modifier|*
name|engine
decl_stmt|;
name|EVP_MD_CTX
modifier|*
name|ctx
decl_stmt|;
name|size_t
name|key_length
decl_stmt|;
name|void
modifier|*
name|opad
decl_stmt|;
name|void
modifier|*
name|ipad
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|HMAC_CTX_init
parameter_list|(
name|HMAC_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HMAC_CTX_cleanup
parameter_list|(
name|HMAC_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|HMAC_size
parameter_list|(
specifier|const
name|HMAC_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HMAC_Init_ex
parameter_list|(
name|HMAC_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
parameter_list|,
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HMAC_Update
parameter_list|(
name|HMAC_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HMAC_Final
parameter_list|(
name|HMAC_CTX
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|md
parameter_list|,
name|unsigned
name|int
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|HMAC
parameter_list|(
specifier|const
name|EVP_MD
modifier|*
name|evp_md
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|n
parameter_list|,
name|void
modifier|*
name|md
parameter_list|,
name|unsigned
name|int
modifier|*
name|md_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_HMAC_H */
end_comment

end_unit

