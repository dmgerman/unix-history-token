begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by John-Mark Gurney under  * the sponsorship of the FreeBSD Foundation and  * Rubicon Communications, LLC (Netgate).  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GMAC_H_
end_ifndef

begin_include
include|#
directive|include
file|"gfmult.h"
end_include

begin_include
include|#
directive|include
file|<crypto/rijndael/rijndael.h>
end_include

begin_define
define|#
directive|define
name|GMAC_BLOCK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|GMAC_DIGEST_LEN
value|16
end_define

begin_struct
struct|struct
name|aes_gmac_ctx
block|{
name|struct
name|gf128table4
name|ghashtbl
decl_stmt|;
name|struct
name|gf128
name|hash
decl_stmt|;
name|uint32_t
name|keysched
index|[
literal|4
operator|*
operator|(
name|RIJNDAEL_MAXNR
operator|+
literal|1
operator|)
index|]
decl_stmt|;
name|uint8_t
name|counter
index|[
name|GMAC_BLOCK_LEN
index|]
decl_stmt|;
name|int
name|rounds
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|AES_GMAC_Init
parameter_list|(
name|struct
name|aes_gmac_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AES_GMAC_Setkey
parameter_list|(
name|struct
name|aes_gmac_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AES_GMAC_Reinit
parameter_list|(
name|struct
name|aes_gmac_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AES_GMAC_Update
parameter_list|(
name|struct
name|aes_gmac_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AES_GMAC_Final
parameter_list|(
name|uint8_t
index|[
name|GMAC_DIGEST_LEN
index|]
parameter_list|,
name|struct
name|aes_gmac_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GMAC_H_ */
end_comment

end_unit

