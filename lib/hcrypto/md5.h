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
name|HEIM_MD5_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_MD5_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|MD5_Init
value|hc_MD5_Init
end_define

begin_define
define|#
directive|define
name|MD5_Update
value|hc_MD5_Update
end_define

begin_define
define|#
directive|define
name|MD5_Final
value|hc_MD5_Final
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|MD5_DIGEST_LENGTH
value|16
end_define

begin_struct
struct|struct
name|md5
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
literal|4
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
name|md5
name|MD5_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|MD5_Init
parameter_list|(
name|struct
name|md5
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5_Update
parameter_list|(
name|struct
name|md5
modifier|*
name|m
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5_Final
parameter_list|(
name|void
modifier|*
name|res
parameter_list|,
name|struct
name|md5
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* uint32_t res[4] */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_MD5_H */
end_comment

end_unit

