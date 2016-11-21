begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARMV8_CRYPTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARMV8_CRYPTO_H_
end_define

begin_define
define|#
directive|define
name|AES128_ROUNDS
value|10
end_define

begin_define
define|#
directive|define
name|AES192_ROUNDS
value|12
end_define

begin_define
define|#
directive|define
name|AES256_ROUNDS
value|14
end_define

begin_define
define|#
directive|define
name|AES_SCHED_LEN
value|((AES256_ROUNDS + 1) * AES_BLOCK_LEN)
end_define

begin_struct
struct|struct
name|armv8_crypto_session
block|{
name|uint32_t
name|enc_schedule
index|[
name|AES_SCHED_LEN
operator|/
literal|4
index|]
decl_stmt|;
name|uint32_t
name|dec_schedule
index|[
name|AES_SCHED_LEN
operator|/
literal|4
index|]
decl_stmt|;
name|int
name|algo
decl_stmt|;
name|int
name|rounds
decl_stmt|;
name|int
name|used
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|armv8_crypto_session
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|armv8_aes_encrypt_cbc
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
specifier|static
name|AES_BLOCK_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv8_aes_decrypt_cbc
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[
specifier|static
name|AES_BLOCK_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARMV8_CRYPTO_H_ */
end_comment

end_unit

