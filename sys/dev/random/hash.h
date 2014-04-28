begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_HASH_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_HASH_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|KEYSIZE
value|32
end_define

begin_comment
comment|/* (in bytes) == 256 bits */
end_comment

begin_define
define|#
directive|define
name|BLOCKSIZE
value|16
end_define

begin_comment
comment|/* (in bytes) == 128 bits */
end_comment

begin_struct
struct|struct
name|randomdev_hash
block|{
comment|/* Big! Make static! */
name|SHA256_CTX
name|sha
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|randomdev_key
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
name|randomdev_hash_init
parameter_list|(
name|struct
name|randomdev_hash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_hash_iterate
parameter_list|(
name|struct
name|randomdev_hash
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
name|randomdev_hash_finish
parameter_list|(
name|struct
name|randomdev_hash
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_encrypt_init
parameter_list|(
name|struct
name|randomdev_key
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_encrypt
parameter_list|(
name|struct
name|randomdev_key
modifier|*
name|context
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

