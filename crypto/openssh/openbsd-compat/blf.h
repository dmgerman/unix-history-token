begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: blf.h,v 1.7 2007/03/14 17:59:41 grunk Exp $ */
end_comment

begin_comment
comment|/*  * Blowfish - a fast block cipher designed by Bruce Schneier  *  * Copyright 1997 Niels Provos<provos@physnet.uni-hamburg.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Niels Provos.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLF_H_
end_ifndef

begin_define
define|#
directive|define
name|_BLF_H_
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BCRYPT_PBKDF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BLH_H
argument_list|)
end_if

begin_comment
comment|/* Schneier specifies a maximum key length of 56 bytes.  * This ensures that every key bit affects every cipher  * bit.  However, the subkeys can hold up to 72 bytes.  * Warning: For normal blowfish encryption only 56 bytes  * of the key affect all cipherbits.  */
end_comment

begin_define
define|#
directive|define
name|BLF_N
value|16
end_define

begin_comment
comment|/* Number of Subkeys */
end_comment

begin_define
define|#
directive|define
name|BLF_MAXKEYLEN
value|((BLF_N-2)*4)
end_define

begin_comment
comment|/* 448 bits */
end_comment

begin_define
define|#
directive|define
name|BLF_MAXUTILIZED
value|((BLF_N+2)*4)
end_define

begin_comment
comment|/* 576 bits */
end_comment

begin_comment
comment|/* Blowfish context */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BlowfishContext
block|{
name|u_int32_t
name|S
index|[
literal|4
index|]
index|[
literal|256
index|]
decl_stmt|;
comment|/* S-Boxes */
name|u_int32_t
name|P
index|[
name|BLF_N
operator|+
literal|2
index|]
decl_stmt|;
comment|/* Subkeys */
block|}
name|blf_ctx
typedef|;
end_typedef

begin_comment
comment|/* Raw access to customized Blowfish  *	blf_key is just:  *	Blowfish_initstate( state )  *	Blowfish_expand0state( state, key, keylen )  */
end_comment

begin_function_decl
name|void
name|Blowfish_encipher
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Blowfish_decipher
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Blowfish_initstate
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Blowfish_expand0state
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Blowfish_expandstate
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Standard Blowfish */
end_comment

begin_function_decl
name|void
name|blf_key
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_enc
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_dec
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_ecb_encrypt
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_ecb_decrypt
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_cbc_encrypt
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blf_cbc_decrypt
parameter_list|(
name|blf_ctx
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Converts u_int8_t to u_int32_t */
end_comment

begin_function_decl
name|u_int32_t
name|Blowfish_stream2word
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_BCRYPT_PBKDF)&& !defined(HAVE_BLH_H) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BLF_H */
end_comment

end_unit

