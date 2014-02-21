begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: crypto_api.h,v 1.3 2013/12/17 10:36:38 markus Exp $ */
end_comment

begin_comment
comment|/*  * Assembled from generated headers and source files by Markus Friedl.  * Placed in the public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|crypto_api_h
end_ifndef

begin_define
define|#
directive|define
name|crypto_api_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_typedef
typedef|typedef
name|int32_t
name|crypto_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|crypto_uint32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|randombytes
parameter_list|(
name|buf
parameter_list|,
name|buf_len
parameter_list|)
value|arc4random_buf((buf), (buf_len))
end_define

begin_define
define|#
directive|define
name|crypto_hashblocks_sha512_STATEBYTES
value|64U
end_define

begin_define
define|#
directive|define
name|crypto_hashblocks_sha512_BLOCKBYTES
value|128U
end_define

begin_function_decl
name|int
name|crypto_hashblocks_sha512
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|crypto_hash_sha512_BYTES
value|64U
end_define

begin_function_decl
name|int
name|crypto_hash_sha512
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypto_verify_32
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|crypto_sign_ed25519_SECRETKEYBYTES
value|64U
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_PUBLICKEYBYTES
value|32U
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_BYTES
value|64U
end_define

begin_function_decl
name|int
name|crypto_sign_ed25519
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypto_sign_ed25519_open
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
name|long
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypto_sign_ed25519_keypair
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* crypto_api_h */
end_comment

end_unit

