begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_CAMELLIA_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_CAMELLIA_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|CAMELLIA_set_key
value|hc_CAMELLIA_set_encrypt_key
end_define

begin_define
define|#
directive|define
name|CAMELLIA_encrypt
value|hc_CAMELLIA_encrypt
end_define

begin_define
define|#
directive|define
name|CAMELLIA_decrypt
value|hc_CAMELLIA_decrypt
end_define

begin_define
define|#
directive|define
name|CAMELLIA_cbc_encrypt
value|hc_CAMELLIA_cbc_encrypt
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|CAMELLIA_BLOCK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|CAMELLIA_TABLE_BYTE_LEN
value|272
end_define

begin_define
define|#
directive|define
name|CAMELLIA_TABLE_WORD_LEN
value|(CAMELLIA_TABLE_BYTE_LEN / 4)
end_define

begin_define
define|#
directive|define
name|CAMELLIA_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|CAMELLIA_DECRYPT
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|camellia_key
block|{
name|unsigned
name|int
name|bits
decl_stmt|;
name|uint32_t
name|key
index|[
name|CAMELLIA_TABLE_WORD_LEN
index|]
decl_stmt|;
block|}
name|CAMELLIA_KEY
typedef|;
end_typedef

begin_function_decl
name|int
name|CAMELLIA_set_key
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|,
name|CAMELLIA_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CAMELLIA_encrypt
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|CAMELLIA_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CAMELLIA_decrypt
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|CAMELLIA_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CAMELLIA_cbc_encrypt
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|CAMELLIA_KEY
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_CAMELLIA_H */
end_comment

end_unit

