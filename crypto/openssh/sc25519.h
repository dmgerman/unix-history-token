begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sc25519.h,v 1.3 2013/12/09 11:03:45 markus Exp $ */
end_comment

begin_comment
comment|/*  * Public Domain, Authors: Daniel J. Bernstein, Niels Duif, Tanja Lange,  * Peter Schwabe, Bo-Yin Yang.  * Copied from supercop-20130419/crypto_sign/ed25519/ref/sc25519.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SC25519_H
end_ifndef

begin_define
define|#
directive|define
name|SC25519_H
end_define

begin_include
include|#
directive|include
file|"crypto_api.h"
end_include

begin_define
define|#
directive|define
name|sc25519
value|crypto_sign_ed25519_ref_sc25519
end_define

begin_define
define|#
directive|define
name|shortsc25519
value|crypto_sign_ed25519_ref_shortsc25519
end_define

begin_define
define|#
directive|define
name|sc25519_from32bytes
value|crypto_sign_ed25519_ref_sc25519_from32bytes
end_define

begin_define
define|#
directive|define
name|shortsc25519_from16bytes
value|crypto_sign_ed25519_ref_shortsc25519_from16bytes
end_define

begin_define
define|#
directive|define
name|sc25519_from64bytes
value|crypto_sign_ed25519_ref_sc25519_from64bytes
end_define

begin_define
define|#
directive|define
name|sc25519_from_shortsc
value|crypto_sign_ed25519_ref_sc25519_from_shortsc
end_define

begin_define
define|#
directive|define
name|sc25519_to32bytes
value|crypto_sign_ed25519_ref_sc25519_to32bytes
end_define

begin_define
define|#
directive|define
name|sc25519_iszero_vartime
value|crypto_sign_ed25519_ref_sc25519_iszero_vartime
end_define

begin_define
define|#
directive|define
name|sc25519_isshort_vartime
value|crypto_sign_ed25519_ref_sc25519_isshort_vartime
end_define

begin_define
define|#
directive|define
name|sc25519_lt_vartime
value|crypto_sign_ed25519_ref_sc25519_lt_vartime
end_define

begin_define
define|#
directive|define
name|sc25519_add
value|crypto_sign_ed25519_ref_sc25519_add
end_define

begin_define
define|#
directive|define
name|sc25519_sub_nored
value|crypto_sign_ed25519_ref_sc25519_sub_nored
end_define

begin_define
define|#
directive|define
name|sc25519_mul
value|crypto_sign_ed25519_ref_sc25519_mul
end_define

begin_define
define|#
directive|define
name|sc25519_mul_shortsc
value|crypto_sign_ed25519_ref_sc25519_mul_shortsc
end_define

begin_define
define|#
directive|define
name|sc25519_window3
value|crypto_sign_ed25519_ref_sc25519_window3
end_define

begin_define
define|#
directive|define
name|sc25519_window5
value|crypto_sign_ed25519_ref_sc25519_window5
end_define

begin_define
define|#
directive|define
name|sc25519_2interleave2
value|crypto_sign_ed25519_ref_sc25519_2interleave2
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
name|sc25519
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|crypto_uint32
name|v
index|[
literal|16
index|]
decl_stmt|;
block|}
name|shortsc25519
typedef|;
end_typedef

begin_function_decl
name|void
name|sc25519_from32bytes
parameter_list|(
name|sc25519
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
name|shortsc25519_from16bytes
parameter_list|(
name|shortsc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|unsigned
name|char
name|x
index|[
literal|16
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_from64bytes
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|unsigned
name|char
name|x
index|[
literal|64
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_from_shortsc
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|shortsc25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_to32bytes
parameter_list|(
name|unsigned
name|char
name|r
index|[
literal|32
index|]
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc25519_iszero_vartime
parameter_list|(
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc25519_isshort_vartime
parameter_list|(
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc25519_lt_vartime
parameter_list|(
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_add
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_sub_nored
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_mul
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_mul_shortsc
parameter_list|(
name|sc25519
modifier|*
name|r
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|x
parameter_list|,
specifier|const
name|shortsc25519
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert s into a representation of the form \sum_{i=0}^{84}r[i]2^3  * with r[i] in {-4,...,3}  */
end_comment

begin_function_decl
name|void
name|sc25519_window3
parameter_list|(
name|signed
name|char
name|r
index|[
literal|85
index|]
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert s into a representation of the form \sum_{i=0}^{50}r[i]2^5  * with r[i] in {-16,...,15}  */
end_comment

begin_function_decl
name|void
name|sc25519_window5
parameter_list|(
name|signed
name|char
name|r
index|[
literal|51
index|]
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc25519_2interleave2
parameter_list|(
name|unsigned
name|char
name|r
index|[
literal|127
index|]
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s1
parameter_list|,
specifier|const
name|sc25519
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

