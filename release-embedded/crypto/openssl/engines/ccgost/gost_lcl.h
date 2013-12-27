begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|GOST_TOOLS_H
end_ifndef

begin_define
define|#
directive|define
name|GOST_TOOLS_H
end_define

begin_comment
comment|/**********************************************************************  *                        gost_lcl.h                                  *  *             Copyright (c) 2006 Cryptocom LTD                       *  *       This file is distributed under the same license as OpenSSL   *  *                                                                    *  *         Internal declarations  used in GOST engine                *  *         OpenSSL 0.9.9 libraries required to compile and use        *  *                              this code                             *  **********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_include
include|#
directive|include
file|<openssl/asn1t.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ec.h>
end_include

begin_include
include|#
directive|include
file|"gost89.h"
end_include

begin_include
include|#
directive|include
file|"gosthash.h"
end_include

begin_comment
comment|/* Control commands */
end_comment

begin_define
define|#
directive|define
name|GOST_PARAM_CRYPT_PARAMS
value|0
end_define

begin_define
define|#
directive|define
name|GOST_PARAM_MAX
value|0
end_define

begin_define
define|#
directive|define
name|GOST_CTRL_CRYPT_PARAMS
value|(ENGINE_CMD_BASE+GOST_PARAM_CRYPT_PARAMS)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|ENGINE_CMD_DEFN
name|gost_cmds
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|gost_control_func
parameter_list|(
name|ENGINE
modifier|*
name|e
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|i
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_gost_engine_param
parameter_list|(
name|int
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost_set_default_param
parameter_list|(
name|int
name|param
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gost_param_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* method registration */
end_comment

begin_function_decl
name|int
name|register_ameth_gost
parameter_list|(
name|int
name|nid
parameter_list|,
name|EVP_PKEY_ASN1_METHOD
modifier|*
modifier|*
name|ameth
parameter_list|,
specifier|const
name|char
modifier|*
name|pemstr
parameter_list|,
specifier|const
name|char
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_pmeth_gost
parameter_list|(
name|int
name|id
parameter_list|,
name|EVP_PKEY_METHOD
modifier|*
modifier|*
name|pmeth
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Gost-specific pmeth control-function parameters */
end_comment

begin_comment
comment|/* For GOST R34.10 parameters */
end_comment

begin_define
define|#
directive|define
name|param_ctrl_string
value|"paramset"
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_CTRL_GOST_PARAMSET
value|(EVP_PKEY_ALG_CTRL+1)
end_define

begin_comment
comment|/* For GOST 28147 MAC */
end_comment

begin_define
define|#
directive|define
name|key_ctrl_string
value|"key"
end_define

begin_define
define|#
directive|define
name|hexkey_ctrl_string
value|"hexkey"
end_define

begin_define
define|#
directive|define
name|EVP_PKEY_CTRL_GOST_MAC_HEXKEY
value|(EVP_PKEY_ALG_CTRL+3)
end_define

begin_comment
comment|/* Pmeth internal representation */
end_comment

begin_struct
struct|struct
name|gost_pmeth_data
block|{
name|int
name|sign_param_nid
decl_stmt|;
comment|/* Should be set whenever parameters are filled */
name|EVP_MD
modifier|*
name|md
decl_stmt|;
name|unsigned
name|char
modifier|*
name|shared_ukm
decl_stmt|;
name|int
name|peer_key_used
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gost_mac_pmeth_data
block|{
name|int
name|key_set
decl_stmt|;
name|EVP_MD
modifier|*
name|md
decl_stmt|;
name|unsigned
name|char
name|key
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* GOST-specific ASN1 structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ASN1_OCTET_STRING
modifier|*
name|encrypted_key
decl_stmt|;
name|ASN1_OCTET_STRING
modifier|*
name|imit
decl_stmt|;
block|}
name|GOST_KEY_INFO
typedef|;
end_typedef

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_KEY_INFO
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
name|ASN1_OBJECT
modifier|*
name|cipher
decl_stmt|;
name|X509_PUBKEY
modifier|*
name|ephem_key
decl_stmt|;
name|ASN1_OCTET_STRING
modifier|*
name|eph_iv
decl_stmt|;
block|}
name|GOST_KEY_AGREEMENT_INFO
typedef|;
end_typedef

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_KEY_AGREEMENT_INFO
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
name|GOST_KEY_INFO
modifier|*
name|key_info
decl_stmt|;
name|GOST_KEY_AGREEMENT_INFO
modifier|*
name|key_agreement_info
decl_stmt|;
block|}
name|GOST_KEY_TRANSPORT
typedef|;
end_typedef

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_KEY_TRANSPORT
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* FIXME incomplete */
name|GOST_KEY_TRANSPORT
modifier|*
name|gkt
decl_stmt|;
block|}
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS
typedef|;
end_typedef

begin_comment
comment|/* Hacks to shorten symbols to 31 characters or less, or OpenVMS.    This mimics what's done in symhacks.h, but since this is a very    local header file, I prefered to put this hack directly here.    -- Richard Levitte */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_SYS_VMS
end_ifdef

begin_undef
undef|#
directive|undef
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_it
end_undef

begin_define
define|#
directive|define
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_it
value|GOST_CLIENT_KEY_EXC_PARAMS_it
end_define

begin_undef
undef|#
directive|undef
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_new
end_undef

begin_define
define|#
directive|define
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_new
value|GOST_CLIENT_KEY_EXC_PARAMS_new
end_define

begin_undef
undef|#
directive|undef
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_free
end_undef

begin_define
define|#
directive|define
name|GOST_CLIENT_KEY_EXCHANGE_PARAMS_free
value|GOST_CLIENT_KEY_EXC_PARAMS_free
end_define

begin_undef
undef|#
directive|undef
name|d2i_GOST_CLIENT_KEY_EXCHANGE_PARAMS
end_undef

begin_define
define|#
directive|define
name|d2i_GOST_CLIENT_KEY_EXCHANGE_PARAMS
value|d2i_GOST_CLIENT_KEY_EXC_PARAMS
end_define

begin_undef
undef|#
directive|undef
name|i2d_GOST_CLIENT_KEY_EXCHANGE_PARAMS
end_undef

begin_define
define|#
directive|define
name|i2d_GOST_CLIENT_KEY_EXCHANGE_PARAMS
value|i2d_GOST_CLIENT_KEY_EXC_PARAMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of hack */
end_comment

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_CLIENT_KEY_EXCHANGE_PARAMS
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
name|ASN1_OBJECT
modifier|*
name|key_params
decl_stmt|;
name|ASN1_OBJECT
modifier|*
name|hash_params
decl_stmt|;
name|ASN1_OBJECT
modifier|*
name|cipher_params
decl_stmt|;
block|}
name|GOST_KEY_PARAMS
typedef|;
end_typedef

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_KEY_PARAMS
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
block|{
name|ASN1_OCTET_STRING
modifier|*
name|iv
decl_stmt|;
name|ASN1_OBJECT
modifier|*
name|enc_param_set
decl_stmt|;
block|}
name|GOST_CIPHER_PARAMS
typedef|;
end_typedef

begin_macro
name|DECLARE_ASN1_FUNCTIONS
argument_list|(
argument|GOST_CIPHER_PARAMS
argument_list|)
end_macro

begin_comment
comment|/*============== Message digest  and cipher related structures  ==========*/
end_comment

begin_comment
comment|/* Structure used as EVP_MD_CTX-md_data.  	  * It allows to avoid storing in the md-data pointers to 	  * dynamically allocated memory. 	  * 	  * I cannot invent better way to avoid memory leaks, because 	  * openssl insist on invoking Init on Final-ed digests, and there 	  * is no reliable way to find out whether pointer in the passed 	  * md_data is valid or not. 	  * */
end_comment

begin_struct
struct|struct
name|ossl_gost_digest_ctx
block|{
name|gost_hash_ctx
name|dctx
decl_stmt|;
name|gost_ctx
name|cctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EVP_MD structure for GOST R 34.11 */
end_comment

begin_decl_stmt
specifier|extern
name|EVP_MD
name|digest_gost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EVP_MD structure for GOST 28147 in MAC mode */
end_comment

begin_decl_stmt
specifier|extern
name|EVP_MD
name|imit_gost_cpa
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cipher context used for EVP_CIPHER operation */
end_comment

begin_struct
struct|struct
name|ossl_gost_cipher_ctx
block|{
name|int
name|paramNID
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|int
name|key_meshing
decl_stmt|;
name|gost_ctx
name|cctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to map parameter NID to S-block */
end_comment

begin_struct
struct|struct
name|gost_cipher_info
block|{
name|int
name|nid
decl_stmt|;
name|gost_subst_block
modifier|*
name|sblock
decl_stmt|;
name|int
name|key_meshing
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Context for MAC */
end_comment

begin_struct
struct|struct
name|ossl_gost_imit_ctx
block|{
name|gost_ctx
name|cctx
decl_stmt|;
name|unsigned
name|char
name|buffer
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|partial_block
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|int
name|key_meshing
decl_stmt|;
name|int
name|bytes_left
decl_stmt|;
name|int
name|key_set
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Table which maps parameter NID to S-blocks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gost_cipher_info
name|gost_cipher_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find encryption params from ASN1_OBJECT */
end_comment

begin_function_decl
specifier|const
name|struct
name|gost_cipher_info
modifier|*
name|get_encryption_params
parameter_list|(
name|ASN1_OBJECT
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implementation of GOST 28147-89 cipher in CFB and CNT modes */
end_comment

begin_decl_stmt
specifier|extern
name|EVP_CIPHER
name|cipher_gost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EVP_CIPHER
name|cipher_gost_cpacnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EVP_MD_CTRL_KEY_LEN
value|(EVP_MD_CTRL_ALG_CTRL+3)
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTRL_SET_KEY
value|(EVP_MD_CTRL_ALG_CTRL+4)
end_define

begin_comment
comment|/* EVP_PKEY_METHOD key encryption callbacks */
end_comment

begin_comment
comment|/* From gost94_keyx.c */
end_comment

begin_function_decl
name|int
name|pkey_GOST94cp_encrypt
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkey_GOST94cp_decrypt
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|size_t
name|in_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From gost2001_keyx.c */
end_comment

begin_function_decl
name|int
name|pkey_GOST01cp_encrypt
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkey_GOST01cp_decrypt
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|size_t
name|in_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* derive functions */
end_comment

begin_comment
comment|/* From gost2001_keyx.c */
end_comment

begin_function_decl
name|int
name|pkey_gost2001_derive
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
modifier|*
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From gost94_keyx.c */
end_comment

begin_function_decl
name|int
name|pkey_gost94_derive
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
modifier|*
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Internal functions for signature algorithms */
end_comment

begin_function_decl
name|int
name|fill_GOST94_params
parameter_list|(
name|DSA
modifier|*
name|dsa
parameter_list|,
name|int
name|nid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_GOST2001_params
parameter_list|(
name|EC_KEY
modifier|*
name|eckey
parameter_list|,
name|int
name|nid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost_sign_keygen
parameter_list|(
name|DSA
modifier|*
name|dsa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost2001_keygen
parameter_list|(
name|EC_KEY
modifier|*
name|ec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DSA_SIG
modifier|*
name|gost_do_sign
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dlen
parameter_list|,
name|DSA
modifier|*
name|dsa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DSA_SIG
modifier|*
name|gost2001_do_sign
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dlen
parameter_list|,
name|EC_KEY
modifier|*
name|eckey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost_do_verify
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
name|DSA_SIG
modifier|*
name|sig
parameter_list|,
name|DSA
modifier|*
name|dsa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost2001_do_verify
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
name|DSA_SIG
modifier|*
name|sig
parameter_list|,
name|EC_KEY
modifier|*
name|ec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost2001_compute_public
parameter_list|(
name|EC_KEY
modifier|*
name|ec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gost94_compute_public
parameter_list|(
name|DSA
modifier|*
name|dsa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*============== miscellaneous functions============================= */
end_comment

begin_comment
comment|/* from gost_sign.c */
end_comment

begin_comment
comment|/* Convert GOST R 34.11 hash sum to bignum according to standard */
end_comment

begin_function_decl
name|BIGNUM
modifier|*
name|hashsum2bn
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store bignum in byte array of given length, prepending by zeros  * if nesseccary */
end_comment

begin_function_decl
name|int
name|store_bignum
parameter_list|(
name|BIGNUM
modifier|*
name|bn
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read bignum, which can have few MSB all-zeros    from buffer*/
end_comment

begin_function_decl
name|BIGNUM
modifier|*
name|getbnfrombuf
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pack GOST R 34.10 signature according to CryptoPro rules */
end_comment

begin_function_decl
name|int
name|pack_sign_cp
parameter_list|(
name|DSA_SIG
modifier|*
name|s
parameter_list|,
name|int
name|order
parameter_list|,
name|unsigned
name|char
modifier|*
name|sig
parameter_list|,
name|size_t
modifier|*
name|siglen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unpack GOST R 34.10 signature according to CryptoPro rules */
end_comment

begin_function_decl
name|DSA_SIG
modifier|*
name|unpack_cp_signature
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|sig
parameter_list|,
name|size_t
name|siglen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from ameth.c */
end_comment

begin_comment
comment|/* Get private key as BIGNUM from both R 34.10-94 and R 34.10-2001  keys*/
end_comment

begin_comment
comment|/* Returns pointer into EVP_PKEY structure */
end_comment

begin_function_decl
name|BIGNUM
modifier|*
name|gost_get0_priv_key
parameter_list|(
specifier|const
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find NID by GOST 94 parameters */
end_comment

begin_function_decl
name|int
name|gost94_nid_by_params
parameter_list|(
name|DSA
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

