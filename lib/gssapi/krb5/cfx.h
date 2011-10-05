begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003, PADL Software Pty Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of PADL Software nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PADL SOFTWARE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PADL SOFTWARE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_CFX_H_
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_CFX_H_
value|1
end_define

begin_comment
comment|/*  * Implementation of draft-ietf-krb-wg-gssapi-cfx-01.txt  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gss_cfx_mic_token_desc_struct
block|{
name|u_char
name|TOK_ID
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04 04 */
name|u_char
name|Flags
decl_stmt|;
name|u_char
name|Filler
index|[
literal|5
index|]
decl_stmt|;
name|u_char
name|SND_SEQ
index|[
literal|8
index|]
decl_stmt|;
block|}
name|gss_cfx_mic_token_desc
operator|,
typedef|*
name|gss_cfx_mic_token
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_cfx_wrap_token_desc_struct
block|{
name|u_char
name|TOK_ID
index|[
literal|2
index|]
decl_stmt|;
comment|/* 04 05 */
name|u_char
name|Flags
decl_stmt|;
name|u_char
name|Filler
decl_stmt|;
name|u_char
name|EC
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|RRC
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|SND_SEQ
index|[
literal|8
index|]
decl_stmt|;
block|}
name|gss_cfx_wrap_token_desc
operator|,
typedef|*
name|gss_cfx_wrap_token
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gss_cfx_delete_token_desc_struct
block|{
name|u_char
name|TOK_ID
index|[
literal|2
index|]
decl_stmt|;
comment|/* 05 04 */
name|u_char
name|Flags
decl_stmt|;
name|u_char
name|Filler
index|[
literal|5
index|]
decl_stmt|;
name|u_char
name|SND_SEQ
index|[
literal|8
index|]
decl_stmt|;
block|}
name|gss_cfx_delete_token_desc
operator|,
typedef|*
name|gss_cfx_delete_token
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_CFX_H_ */
end_comment

end_unit

