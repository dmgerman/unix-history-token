begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|RC2_set_key
value|hc_RC2_set_key
end_define

begin_define
define|#
directive|define
name|RC2_encryptc
value|hc_RC2_encryptc
end_define

begin_define
define|#
directive|define
name|RC2_decryptc
value|hc_RC2_decryptc
end_define

begin_define
define|#
directive|define
name|RC2_cbc_encrypt
value|hc_RC2_cbc_encrypt
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|RC2_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|RC2_DECRYPT
value|0
end_define

begin_define
define|#
directive|define
name|RC2_BLOCK_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|RC2_BLOCK
value|RC2_BLOCK_SIZE
end_define

begin_define
define|#
directive|define
name|RC2_KEY_LENGTH
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|rc2_key
block|{
name|unsigned
name|int
name|data
index|[
literal|64
index|]
decl_stmt|;
block|}
name|RC2_KEY
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|void
name|RC2_set_key
parameter_list|(
name|RC2_KEY
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|RC2_encryptc
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|RC2_KEY
modifier|*
parameter_list|)
function_decl|;
name|void
name|RC2_decryptc
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|RC2_KEY
modifier|*
parameter_list|)
function_decl|;
name|void
name|RC2_cbc_encrypt
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
name|long
parameter_list|,
name|RC2_KEY
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

