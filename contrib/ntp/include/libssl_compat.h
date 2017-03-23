begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libssl_compat.h -- OpenSSL v1.1 compatibility shims  *  * ---------------------------------------------------------------------  *  * Written by Juergen Perlinger<perlinger@ntp.org> for the NTP project  *  * Based on an idea by Kurt Roeckx<kurt@roeckx.be>  *  * ---------------------------------------------------------------------  * This is a clean room implementation of shim functions that have  * counterparts in the OpenSSL v1.1 API but not in earlier versions.  *  * If the OpenSSL version used for compilation needs the shims (that is,  * does not provide the new functions) the names of these functions are  * redirected to our shims.  * ---------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_LIBSSL_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_LIBSSL_COMPAT_H
end_define

begin_include
include|#
directive|include
file|"openssl/evp.h"
end_include

begin_include
include|#
directive|include
file|"openssl/dsa.h"
end_include

begin_include
include|#
directive|include
file|"openssl/rsa.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_VERSION_NUMBER
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_VERSION_NUMBER
value|SSLEAY_VERSION_NUMBER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_VERSION_TEXT
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_VERSION_TEXT
value|SSLEAY_VERSION_TEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_VERSION
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_VERSION
value|SSLEAY_VERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ----------------------------------------------------------------- */
end_comment

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x10100000L
end_if

begin_comment
comment|/* ----------------------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_comment
comment|/* shim the new-style API on an old-style OpenSSL */
end_comment

begin_function_decl
specifier|extern
name|BN_GENCB
modifier|*
name|sslshimBN_GENCB_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshimBN_GENCB_free
parameter_list|(
name|BN_GENCB
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EVP_MD_CTX
modifier|*
name|sslshim_EVP_MD_CTX_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_EVP_MD_CTX_free
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_EVP_PKEY_id
parameter_list|(
specifier|const
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_EVP_PKEY_base_id
parameter_list|(
specifier|const
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RSA
modifier|*
name|sslshim_EVP_PKEY_get0_RSA
parameter_list|(
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DSA
modifier|*
name|sslshim_EVP_PKEY_get0_DSA
parameter_list|(
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_RSA_get0_key
parameter_list|(
specifier|const
name|RSA
modifier|*
name|prsa
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pn
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pe
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_RSA_set0_key
parameter_list|(
name|RSA
modifier|*
name|prsa
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_RSA_get0_factors
parameter_list|(
specifier|const
name|RSA
modifier|*
name|prsa
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pp
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_RSA_set0_factors
parameter_list|(
name|RSA
modifier|*
name|prsar
parameter_list|,
name|BIGNUM
modifier|*
name|p
parameter_list|,
name|BIGNUM
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_RSA_set0_crt_params
parameter_list|(
name|RSA
modifier|*
name|prsa
parameter_list|,
name|BIGNUM
modifier|*
name|dmp1
parameter_list|,
name|BIGNUM
modifier|*
name|dmq1
parameter_list|,
name|BIGNUM
modifier|*
name|iqmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_DSA_SIG_get0
parameter_list|(
specifier|const
name|DSA_SIG
modifier|*
name|psig
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pr
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_DSA_SIG_set0
parameter_list|(
name|DSA_SIG
modifier|*
name|psig
parameter_list|,
name|BIGNUM
modifier|*
name|r
parameter_list|,
name|BIGNUM
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_DSA_get0_pqg
parameter_list|(
specifier|const
name|DSA
modifier|*
name|pdsa
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pp
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pq
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|pg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_DSA_set0_pqg
parameter_list|(
name|DSA
modifier|*
name|pdsa
parameter_list|,
name|BIGNUM
modifier|*
name|p
parameter_list|,
name|BIGNUM
modifier|*
name|q
parameter_list|,
name|BIGNUM
modifier|*
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sslshim_DSA_get0_key
parameter_list|(
specifier|const
name|DSA
modifier|*
name|pdsa
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|ppub_key
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
modifier|*
name|ppriv_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_DSA_set0_key
parameter_list|(
name|DSA
modifier|*
name|pdsa
parameter_list|,
name|BIGNUM
modifier|*
name|pub_key
parameter_list|,
name|BIGNUM
modifier|*
name|priv_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sslshim_X509_get_signature_nid
parameter_list|(
specifier|const
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BN_GENCB_new
value|sslshimBN_GENCB_new
end_define

begin_define
define|#
directive|define
name|BN_GENCB_free
value|sslshimBN_GENCB_free
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_new
value|sslshim_EVP_MD_CTX_new
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_free
value|sslshim_EVP_MD_CTX_free
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_id
value|sslshim_EVP_PKEY_id
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_base_id
value|sslshim_EVP_PKEY_base_id
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_get0_RSA
value|sslshim_EVP_PKEY_get0_RSA
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_get0_DSA
value|sslshim_EVP_PKEY_get0_DSA
end_define

begin_define
define|#
directive|define
name|RSA_get0_key
value|sslshim_RSA_get0_key
end_define

begin_define
define|#
directive|define
name|RSA_set0_key
value|sslshim_RSA_set0_key
end_define

begin_define
define|#
directive|define
name|RSA_get0_factors
value|sslshim_RSA_get0_factors
end_define

begin_define
define|#
directive|define
name|RSA_set0_factors
value|sslshim_RSA_set0_factors
end_define

begin_define
define|#
directive|define
name|RSA_set0_crt_params
value|sslshim_RSA_set0_crt_params
end_define

begin_define
define|#
directive|define
name|DSA_SIG_get0
value|sslshim_DSA_SIG_get0
end_define

begin_define
define|#
directive|define
name|DSA_SIG_set0
value|sslshim_DSA_SIG_set0
end_define

begin_define
define|#
directive|define
name|DSA_get0_pqg
value|sslshim_DSA_get0_pqg
end_define

begin_define
define|#
directive|define
name|DSA_set0_pqg
value|sslshim_DSA_set0_pqg
end_define

begin_define
define|#
directive|define
name|DSA_get0_key
value|sslshim_DSA_get0_key
end_define

begin_define
define|#
directive|define
name|DSA_set0_key
value|sslshim_DSA_set0_key
end_define

begin_define
define|#
directive|define
name|X509_get_signature_nid
value|sslshim_X509_get_signature_nid
end_define

begin_define
define|#
directive|define
name|OpenSSL_version_num
value|SSLeay
end_define

begin_define
define|#
directive|define
name|OpenSSL_version
value|SSLeay_version
end_define

begin_define
define|#
directive|define
name|X509_get0_notBefore
value|X509_get_notBefore
end_define

begin_define
define|#
directive|define
name|X509_getm_notBefore
value|X509_get_notBefore
end_define

begin_define
define|#
directive|define
name|X509_get0_notAfter
value|X509_get_notAfter
end_define

begin_define
define|#
directive|define
name|X509_getm_notAfter
value|X509_get_notAfter
end_define

begin_comment
comment|/* ----------------------------------------------------------------- */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_VERSION_NUMBER< v1.1.0 */
end_comment

begin_comment
comment|/* ----------------------------------------------------------------- */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_LIBSSL_COMPAT_H */
end_comment

end_unit

