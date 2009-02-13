begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2006 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLXSB_H_
end_ifndef

begin_define
define|#
directive|define
name|_GLXSB_H_
end_define

begin_include
include|#
directive|include
file|<opencrypto/cryptodev.h>
end_include

begin_define
define|#
directive|define
name|SB_AES_BLOCK_SIZE
value|0x0010
end_define

begin_struct
struct|struct
name|glxsb_session
block|{
name|uint32_t
name|ses_key
index|[
literal|4
index|]
decl_stmt|;
comment|/* key */
name|uint8_t
name|ses_iv
index|[
name|SB_AES_BLOCK_SIZE
index|]
decl_stmt|;
comment|/* initialization vector */
name|int
name|ses_klen
decl_stmt|;
comment|/* key len */
name|int
name|ses_used
decl_stmt|;
comment|/* session is used */
name|uint32_t
name|ses_id
decl_stmt|;
comment|/* session id*/
name|struct
name|auth_hash
modifier|*
name|ses_axf
decl_stmt|;
name|uint8_t
modifier|*
name|ses_ictx
decl_stmt|;
name|uint8_t
modifier|*
name|ses_octx
decl_stmt|;
name|int
name|ses_mlen
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|glxsb_session
argument_list|)
name|ses_next
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|glxsb_hash_setup
parameter_list|(
name|struct
name|glxsb_session
modifier|*
name|ses
parameter_list|,
name|struct
name|cryptoini
modifier|*
name|macini
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|glxsb_hash_process
parameter_list|(
name|struct
name|glxsb_session
modifier|*
name|ses
parameter_list|,
name|struct
name|cryptodesc
modifier|*
name|maccrd
parameter_list|,
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|glxsb_hash_free
parameter_list|(
name|struct
name|glxsb_session
modifier|*
name|ses
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GLXSB_H_ */
end_comment

end_unit

