begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|KEYSIZE
value|32
end_define

begin_comment
comment|/* in bytes - 32 bytes == 256 bits */
end_comment

begin_struct
struct|struct
name|yarrowhash
block|{
comment|/* Big! Make static! */
name|keyInstance
name|hashkey
decl_stmt|;
comment|/* Data cycles through here */
name|cipherInstance
name|cipher
decl_stmt|;
comment|/* Rijndael internal */
name|u_char
name|hash
index|[
name|KEYSIZE
index|]
decl_stmt|;
comment|/* Repeatedly encrypted */
name|char
name|accum
index|[
name|KEYSIZE
index|]
decl_stmt|;
comment|/* Accumulate partial chunks */
name|u_int
name|partial
decl_stmt|;
comment|/* Keep track of< KEYSIZE chunks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|yarrowkey
block|{
comment|/* Big! Make static! */
name|keyInstance
name|key
decl_stmt|;
comment|/* Key schedule */
name|cipherInstance
name|cipher
decl_stmt|;
comment|/* Rijndael internal */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|yarrow_hash_init
parameter_list|(
name|struct
name|yarrowhash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yarrow_hash_iterate
parameter_list|(
name|struct
name|yarrowhash
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yarrow_hash_finish
parameter_list|(
name|struct
name|yarrowhash
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yarrow_encrypt_init
parameter_list|(
name|struct
name|yarrowkey
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yarrow_encrypt
parameter_list|(
name|struct
name|yarrowkey
modifier|*
name|context
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

