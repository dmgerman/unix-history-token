begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * cipher.h  *  * Author: Tatu Ylonen<ylo@cs.hut.fi>  *  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * Created: Wed Apr 19 16:50:42 1995 ylo  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* RCSID("$Id: cipher.h,v 1.17 2000/05/08 17:12:15 markus Exp $"); */
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

begin_comment
comment|/* Cipher types.  New types can be added, but old types should not be removed    for compatibility.  The maximum allowed value is 31. */
end_comment

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

begin_comment
comment|/* these ciphers are used in SSH2: */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_BLOWFISH_CBC
value|8
end_define

begin_define
define|#
directive|define
name|SSH_CIPHER_3DES_CBC
value|9
end_define

begin_define
define|#
directive|define
name|SSH_CIPHER_ARCFOUR
value|10
end_define

begin_comment
comment|/* Alleged RC4 */
end_comment

begin_define
define|#
directive|define
name|SSH_CIPHER_CAST128_CBC
value|11
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|type
decl_stmt|;
union|union
block|{
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
name|unsigned
name|char
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
name|unsigned
name|char
name|iv
index|[
literal|8
index|]
decl_stmt|;
block|}
name|cast
struct|;
name|RC4_KEY
name|rc4
decl_stmt|;
block|}
name|u
union|;
block|}
name|CipherContext
typedef|;
end_typedef

begin_comment
comment|/*  * Returns a bit mask indicating which ciphers are supported by this  * implementation.  The bit mask has the corresponding bit set of each  * supported cipher.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|cipher_mask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|cipher_mask1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|cipher_mask2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the name of the cipher. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|cipher_name
parameter_list|(
name|int
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parses the name of the cipher.  Returns the number of the corresponding  * cipher, or -1 on error.  */
end_comment

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

begin_comment
comment|/* returns 1 if all ciphers are supported (ssh2 only) */
end_comment

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

begin_comment
comment|/*  * Selects the cipher to use and sets the key.  If for_encryption is true,  * the key is setup for encryption; otherwise it is setup for decryption.  */
end_comment

begin_function_decl
name|void
name|cipher_set_key
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|int
name|cipher
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|int
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cipher_set_key_iv
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|int
name|cipher
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|int
name|keylen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|iv
parameter_list|,
name|int
name|ivlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets key for the cipher by computing the MD5 checksum of the passphrase,  * and using the resulting 16 bytes as the key.  */
end_comment

begin_function_decl
name|void
name|cipher_set_key_string
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|int
name|cipher
parameter_list|,
specifier|const
name|char
modifier|*
name|passphrase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Encrypts data using the cipher. */
end_comment

begin_function_decl
name|void
name|cipher_encrypt
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decrypts data using the cipher. */
end_comment

begin_function_decl
name|void
name|cipher_decrypt
parameter_list|(
name|CipherContext
modifier|*
name|context
parameter_list|,
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|unsigned
name|int
name|len
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

