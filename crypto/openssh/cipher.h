begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  *  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: cipher.h,v 1.25 2000/12/19 23:17:56 markus Exp $"); */
end_comment

begin_comment
comment|/* RCSID("$FreeBSD$"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CIPHER_H
end_ifndef

begin_define
define|#
directive|define
name|CIPHER_H
end_define

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|<openssl/blowfish.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rc4.h>
end_include

begin_include
include|#
directive|include
file|<openssl/cast.h>
end_include

begin_include
include|#
directive|include
file|"rijndael.h"
end_include

begin_comment
comment|/*  * Cipher types for SSH-1.  New types can be added, but old types should not  * be removed for compatibility.  The maximum allowed value is 31.  */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_SSH2
value|-3
end_define

begin_define
define|#
directive|define
name|SSH_CIPHER_ILLEGAL
value|-2
end_define

begin_comment
comment|/* No valid cipher selected. */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_NOT_SET
value|-1
end_define

begin_comment
comment|/* None selected (invalid number). */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_NONE
value|0
end_define

begin_comment
comment|/* no encryption */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_IDEA
value|1
end_define

begin_comment
comment|/* IDEA CFB */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_DES
value|2
end_define

begin_comment
comment|/* DES CBC */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_3DES
value|3
end_define

begin_comment
comment|/* 3DES CBC */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_BROKEN_TSS
value|4
end_define

begin_comment
comment|/* TRI's Simple Stream encryption CBC */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_BROKEN_RC4
value|5
end_define

begin_comment
comment|/* Alleged RC4 */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_BLOWFISH
value|6
end_define

begin_define
define|#
directive|define
name|SSH_CIPHER_RESERVED
value|7
end_define

begin_define
define|#
directive|define
name|SSH_CIPHER_MAX
value|31
end_define

begin_typedef
typedef|typedef
name|struct
name|Cipher
name|Cipher
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|CipherContext
name|CipherContext
typedef|;
end_typedef

begin_struct
struct|struct
name|CipherContext
block|{
union|union
block|{
struct|struct
block|{
name|des_key_schedule
name|key
decl_stmt|;
name|des_cblock
name|iv
decl_stmt|;
block|}
name|des
struct|;
struct|struct
block|{
name|des_key_schedule
name|key1
decl_stmt|;
name|des_key_schedule
name|key2
decl_stmt|;
name|des_cblock
name|iv2
decl_stmt|;
name|des_key_schedule
name|key3
decl_stmt|;
name|des_cblock
name|iv3
decl_stmt|;
block|}
name|des3
struct|;
struct|struct
block|{
name|struct
name|bf_key_st
name|key
decl_stmt|;
name|u_char
name|iv
index|[
literal|8
index|]
decl_stmt|;
block|}
name|bf
struct|;
struct|struct
block|{
name|CAST_KEY
name|key
decl_stmt|;
name|u_char
name|iv
index|[
literal|8
index|]
decl_stmt|;
block|}
name|cast
struct|;
struct|struct
block|{
name|u4byte
name|iv
index|[
literal|4
index|]
decl_stmt|;
name|rijndael_ctx
name|enc
decl_stmt|;
name|rijndael_ctx
name|dec
decl_stmt|;
block|}
name|rijndael
struct|;
name|RC4_KEY
name|rc4
decl_stmt|;
block|}
name|u
union|;
name|Cipher
modifier|*
name|cipher
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Cipher
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|number
decl_stmt|;
comment|/* for ssh1 only */
name|u_int
name|block_size
decl_stmt|;
name|u_int
name|key_len
decl_stmt|;
name|void
function_decl|(
modifier|*
name|setkey
function_decl|)
parameter_list|(
name|CipherContext
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setiv
function_decl|)
parameter_list|(
name|CipherContext
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|encrypt
function_decl|)
parameter_list|(
name|CipherContext
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|decrypt
function_decl|)
parameter_list|(
name|CipherContext
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|u_int
name|cipher_mask_ssh1
parameter_list|(
name|int
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Cipher
modifier|*
name|cipher_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Cipher
modifier|*
name|cipher_by_number
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cipher_number
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cipher_name
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ciphers_valid
parameter_list|(
specifier|const
name|char
modifier|*
name|names
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cipher_init
parameter_list|(
name|CipherContext
modifier|*
parameter_list|,
name|Cipher
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cipher_encrypt
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|u_char
modifier|*
name|dest
parameter_list|,
specifier|const
name|u_char
modifier|*
name|src
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cipher_decrypt
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|u_char
modifier|*
name|dest
parameter_list|,
specifier|const
name|u_char
modifier|*
name|src
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cipher_set_key_string
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|Cipher
modifier|*
name|cipher
parameter_list|,
specifier|const
name|char
modifier|*
name|passphrase
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CIPHER_H */
end_comment

end_unit

