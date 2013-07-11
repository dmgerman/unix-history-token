begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Andre Oppermann<andre@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SipHash is a family of pseudorandom functions (a.k.a. keyed hash functions)  * optimized for speed on short messages returning a 64bit hash/digest value.  *  * The number of rounds is defined during the initialization:  *  SipHash24_Init() for the fast and resonable strong version  *  SipHash48_Init() for the strong version (half as fast)  *  * struct SIPHASH_CTX ctx;  * SipHash24_Init(&ctx);  * SipHash_SetKey(&ctx, "16bytes long key");  * SipHash_Update(&ctx, pointer_to_string, length_of_string);  * SipHash_Final(output,&ctx);  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIPHASH_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIPHASH_H_
end_define

begin_define
define|#
directive|define
name|SIPHASH_BLOCK_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SIPHASH_KEY_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|SIPHASH_DIGEST_LENGTH
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SIPHASH_CTX
block|{
name|uint64_t
name|v
index|[
literal|4
index|]
decl_stmt|;
union|union
block|{
name|uint64_t
name|b64
decl_stmt|;
name|uint8_t
name|b8
index|[
literal|8
index|]
decl_stmt|;
block|}
name|buf
union|;
name|uint64_t
name|bytes
decl_stmt|;
name|uint8_t
name|buflen
decl_stmt|;
name|uint8_t
name|rounds_compr
decl_stmt|;
name|uint8_t
name|rounds_final
decl_stmt|;
name|uint8_t
name|initialized
decl_stmt|;
block|}
name|SIPHASH_CTX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SipHash24_Init
parameter_list|(
name|x
parameter_list|)
value|SipHash_InitX((x), 2, 4)
end_define

begin_define
define|#
directive|define
name|SipHash48_Init
parameter_list|(
name|x
parameter_list|)
value|SipHash_InitX((x), 4, 8)
end_define

begin_function_decl
name|void
name|SipHash_InitX
parameter_list|(
name|SIPHASH_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SipHash_SetKey
parameter_list|(
name|SIPHASH_CTX
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SipHash_Update
parameter_list|(
name|SIPHASH_CTX
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
name|SipHash_Final
parameter_list|(
name|void
modifier|*
parameter_list|,
name|SIPHASH_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|SipHash_End
parameter_list|(
name|SIPHASH_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SipHash24
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|i
parameter_list|)
value|SipHashX((x), 2, 4, (y), (z), (i));
end_define

begin_define
define|#
directive|define
name|SipHash48
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|i
parameter_list|)
value|SipHashX((x), 4, 8, (y), (z), (i));
end_define

begin_function_decl
name|uint64_t
name|SipHashX
parameter_list|(
name|SIPHASH_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|uint8_t
index|[
literal|16
index|]
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
name|int
name|SipHash24_TestVectors
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIPHASH_H_ */
end_comment

end_unit

