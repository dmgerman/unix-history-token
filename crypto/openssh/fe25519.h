begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: fe25519.h,v 1.3 2013/12/09 11:03:45 markus Exp $ */
end_comment

begin_comment
comment|/*  * Public Domain, Authors: Daniel J. Bernstein, Niels Duif, Tanja Lange,  * Peter Schwabe, Bo-Yin Yang.  * Copied from supercop-20130419/crypto_sign/ed25519/ref/fe25519.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FE25519_H
end_ifndef

begin_define
define|#
directive|define
name|FE25519_H
end_define

begin_include
include|#
directive|include
file|"crypto_api.h"
end_include

begin_define
define|#
directive|define
name|fe25519
value|crypto_sign_ed25519_ref_fe25519
end_define

begin_define
define|#
directive|define
name|fe25519_freeze
value|crypto_sign_ed25519_ref_fe25519_freeze
end_define

begin_define
define|#
directive|define
name|fe25519_unpack
value|crypto_sign_ed25519_ref_fe25519_unpack
end_define

begin_define
define|#
directive|define
name|fe25519_pack
value|crypto_sign_ed25519_ref_fe25519_pack
end_define

begin_define
define|#
directive|define
name|fe25519_iszero
value|crypto_sign_ed25519_ref_fe25519_iszero
end_define

begin_define
define|#
directive|define
name|fe25519_iseq_vartime
value|crypto_sign_ed25519_ref_fe25519_iseq_vartime
end_define

begin_define
define|#
directive|define
name|fe25519_cmov
value|crypto_sign_ed25519_ref_fe25519_cmov
end_define

begin_define
define|#
directive|define
name|fe25519_setone
value|crypto_sign_ed25519_ref_fe25519_setone
end_define

begin_define
define|#
directive|define
name|fe25519_setzero
value|crypto_sign_ed25519_ref_fe25519_setzero
end_define

begin_define
define|#
directive|define
name|fe25519_neg
value|crypto_sign_ed25519_ref_fe25519_neg
end_define

begin_define
define|#
directive|define
name|fe25519_getparity
value|crypto_sign_ed25519_ref_fe25519_getparity
end_define

begin_define
define|#
directive|define
name|fe25519_add
value|crypto_sign_ed25519_ref_fe25519_add
end_define

begin_define
define|#
directive|define
name|fe25519_sub
value|crypto_sign_ed25519_ref_fe25519_sub
end_define

begin_define
define|#
directive|define
name|fe25519_mul
value|crypto_sign_ed25519_ref_fe25519_mul
end_define

begin_define
define|#
directive|define
name|fe25519_square
value|crypto_sign_ed25519_ref_fe25519_square
end_define

begin_define
define|#
directive|define
name|fe25519_invert
value|crypto_sign_ed25519_ref_fe25519_invert
end_define

begin_define
define|#
directive|define
name|fe25519_pow2523
value|crypto_sign_ed25519_ref_fe25519_pow2523
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|crypto_uint32
name|v
index|[
literal|32
index|]
decl_stmt|;
block|}
name|fe25519
typedef|;
end_typedef

begin_function_decl
name|void
name|fe25519_freeze
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_unpack
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|unsigned
name|char
name|x
index|[
literal|32
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_pack
parameter_list|(
name|unsigned
name|char
name|r
index|[
literal|32
index|]
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fe25519_iszero
parameter_list|(
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fe25519_iseq_vartime
parameter_list|(
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_cmov
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|,
name|unsigned
name|char
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_setone
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_setzero
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_neg
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|fe25519_getparity
parameter_list|(
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_add
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_sub
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_mul
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_square
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_invert
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe25519_pow2523
parameter_list|(
name|fe25519
modifier|*
name|r
parameter_list|,
specifier|const
name|fe25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

