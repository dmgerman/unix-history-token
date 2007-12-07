begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: xform.h,v 1.8 2001/08/28 12:20:43 ben Exp $	*/
end_comment

begin_comment
comment|/*-  * The author of this code is Angelos D. Keromytis (angelos@cis.upenn.edu)  *  * This code was written by Angelos D. Keromytis in Athens, Greece, in  * February 2000. Network Security Technologies Inc. (NSTI) kindly  * supported the development of this code.  *  * Copyright (c) 2000 Angelos D. Keromytis  *  * Permission to use, copy, and modify this software without fee  * is hereby granted, provided that this entire notice is included in  * all source code copies of any software which is or includes a copy or  * modification of this software.   *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPTO_XFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRYPTO_XFORM_H_
end_define

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha2.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/rmd160.h>
end_include

begin_comment
comment|/* Declarations */
end_comment

begin_struct
struct|struct
name|auth_hash
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|u_int16_t
name|keysize
decl_stmt|;
name|u_int16_t
name|hashsize
decl_stmt|;
name|u_int16_t
name|blocksize
decl_stmt|;
name|u_int16_t
name|ctxsize
decl_stmt|;
name|void
function_decl|(
modifier|*
name|Init
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|Update
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|Final
function_decl|)
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AH_ALEN_MAX
value|20
end_define

begin_comment
comment|/* max authenticator hash length */
end_comment

begin_struct
struct|struct
name|enc_xform
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|u_int16_t
name|blocksize
decl_stmt|;
name|u_int16_t
name|minkey
decl_stmt|,
name|maxkey
decl_stmt|;
name|void
function_decl|(
modifier|*
name|encrypt
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|decrypt
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setkey
function_decl|)
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|zerokey
function_decl|)
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|comp_algo
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|minlen
decl_stmt|;
name|u_int32_t
function_decl|(
modifier|*
name|compress
function_decl|)
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|u_int32_t
function_decl|(
modifier|*
name|decompress
function_decl|)
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_union
union|union
name|authctx
block|{
name|MD5_CTX
name|md5ctx
decl_stmt|;
name|SHA1_CTX
name|sha1ctx
decl_stmt|;
name|RMD160_CTX
name|rmd160ctx
decl_stmt|;
name|SHA256_CTX
name|sha256ctx
decl_stmt|;
name|SHA384_CTX
name|sha384ctx
decl_stmt|;
name|SHA512_CTX
name|sha512ctx
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_des
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_3des
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_blf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_cast5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_skipjack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_rijndael128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_arc4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|enc_xform
name|enc_xform_camellia
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_key_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_key_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_ripemd_160
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_sha2_256
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_sha2_384
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|auth_hash
name|auth_hash_hmac_sha2_512
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|comp_algo
name|comp_algo_deflate
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_XDATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRYPTO_XFORM_H_ */
end_comment

end_unit

