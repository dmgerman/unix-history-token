begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Blowfish - a fast block cipher designed by Bruce Schneier  *  * Copyright 1997 Niels Provos<provos@physnet.uni-hamburg.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Niels Provos.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * FreeBSD implementation by Paul Herman<pherman@frenchfries.net>  */
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

begin_comment
comment|/* Schneier states the maximum key length to be 56 bytes.  * The way how the subkeys are initalized by the key up  * to (N+2)*4 i.e. 72 bytes are utilized.  * Warning: For normal blowfish encryption only 56 bytes  * of the key affect all cipherbits.  */
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

begin_decl_stmt
name|void
name|Blowfish_encipher
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Blowfish_decipher
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Blowfish_initstate
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Blowfish_expand0state
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Blowfish_expandstate
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard Blowfish */
end_comment

begin_decl_stmt
name|void
name|blf_key
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
specifier|const
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_enc
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_dec
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_ecb_encrypt
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_ecb_decrypt
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_cbc_encrypt
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blf_cbc_decrypt
name|__P
argument_list|(
operator|(
name|blf_ctx
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int8_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Converts u_int8_t to u_int32_t */
end_comment

begin_decl_stmt
name|u_int32_t
name|Blowfish_stream2word
name|__P
argument_list|(
operator|(
specifier|const
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|,
name|u_int16_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

