begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *      Dave Safford.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_comment
comment|/* header for the des routines that we will use */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|,
name|DesData
index|[
literal|8
index|]
typedef|,
name|IdeaData
index|[
literal|16
index|]
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|typedef unsigned long word, DesKeys[32];
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DesKeys
value|des_key_schedule
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DES_DECRYPT
value|0
end_define

begin_define
define|#
directive|define
name|DES_ENCRYPT
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|extern void des_fixup_key_parity();
comment|/* (DesData *key) */
end_comment

begin_comment
unit|extern int des_key_sched();
comment|/* (DesData *key, DesKeys *m) */
end_comment

begin_comment
unit|extern int des_ecb_encrypt();
comment|/* (DesData *src, *dst, DesKeys *m, int mode) */
end_comment

begin_comment
unit|extern int des_cbc_encrypt();
comment|/* (char *src, *dst, int length, 				    DesKeys *m, DesData *init, int mode) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* public key routines */
end_comment

begin_comment
comment|/* functions: 	genkeys(char *public, char *secret) 	common_key(char *secret, char *public, desData *deskey)       where 	char public[HEXKEYBYTES + 1]; 	char secret[HEXKEYBYTES + 1];  */
end_comment

begin_define
define|#
directive|define
name|HEXMODULUS
value|"d4a0ba0250b6fd2ec626e7efd637df76c716e22d0944b88b"
end_define

begin_define
define|#
directive|define
name|HEXKEYBYTES
value|48
end_define

begin_define
define|#
directive|define
name|KEYSIZE
value|192
end_define

begin_define
define|#
directive|define
name|KEYBYTES
value|24
end_define

begin_define
define|#
directive|define
name|PROOT
value|3
end_define

begin_function_decl
specifier|extern
name|void
name|genkeys
parameter_list|(
name|char
modifier|*
name|public
parameter_list|,
name|char
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|common_key
parameter_list|(
name|char
modifier|*
name|secret
parameter_list|,
name|char
modifier|*
name|public
parameter_list|,
name|IdeaData
modifier|*
name|common
parameter_list|,
name|DesData
modifier|*
name|deskey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_encode
parameter_list|(
name|char
modifier|*
name|in
parameter_list|,
name|char
modifier|*
name|out
parameter_list|,
name|DesData
modifier|*
name|deskey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_decode
parameter_list|(
name|char
modifier|*
name|in
parameter_list|,
name|char
modifier|*
name|out
parameter_list|,
name|DesData
modifier|*
name|deskey
parameter_list|)
function_decl|;
end_function_decl

end_unit

