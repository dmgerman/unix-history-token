begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ge25519.h,v 1.3 2013/12/09 11:03:45 markus Exp $ */
end_comment

begin_comment
comment|/*  * Public Domain, Authors: Daniel J. Bernstein, Niels Duif, Tanja Lange,  * Peter Schwabe, Bo-Yin Yang.  * Copied from supercop-20130419/crypto_sign/ed25519/ref/ge25519.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GE25519_H
end_ifndef

begin_define
define|#
directive|define
name|GE25519_H
end_define

begin_include
include|#
directive|include
file|"fe25519.h"
end_include

begin_include
include|#
directive|include
file|"sc25519.h"
end_include

begin_define
define|#
directive|define
name|ge25519
value|crypto_sign_ed25519_ref_ge25519
end_define

begin_define
define|#
directive|define
name|ge25519_base
value|crypto_sign_ed25519_ref_ge25519_base
end_define

begin_define
define|#
directive|define
name|ge25519_unpackneg_vartime
value|crypto_sign_ed25519_ref_unpackneg_vartime
end_define

begin_define
define|#
directive|define
name|ge25519_pack
value|crypto_sign_ed25519_ref_pack
end_define

begin_define
define|#
directive|define
name|ge25519_isneutral_vartime
value|crypto_sign_ed25519_ref_isneutral_vartime
end_define

begin_define
define|#
directive|define
name|ge25519_double_scalarmult_vartime
value|crypto_sign_ed25519_ref_double_scalarmult_vartime
end_define

begin_define
define|#
directive|define
name|ge25519_scalarmult_base
value|crypto_sign_ed25519_ref_scalarmult_base
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|fe25519
name|x
decl_stmt|;
name|fe25519
name|y
decl_stmt|;
name|fe25519
name|z
decl_stmt|;
name|fe25519
name|t
decl_stmt|;
block|}
name|ge25519
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|ge25519
name|ge25519_base
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ge25519_unpackneg_vartime
parameter_list|(
name|ge25519
modifier|*
name|r
parameter_list|,
specifier|const
name|unsigned
name|char
name|p
index|[
literal|32
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ge25519_pack
parameter_list|(
name|unsigned
name|char
name|r
index|[
literal|32
index|]
parameter_list|,
specifier|const
name|ge25519
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ge25519_isneutral_vartime
parameter_list|(
specifier|const
name|ge25519
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ge25519_double_scalarmult_vartime
parameter_list|(
name|ge25519
modifier|*
name|r
parameter_list|,
specifier|const
name|ge25519
modifier|*
name|p1
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s1
parameter_list|,
specifier|const
name|ge25519
modifier|*
name|p2
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ge25519_scalarmult_base
parameter_list|(
name|ge25519
modifier|*
name|r
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

