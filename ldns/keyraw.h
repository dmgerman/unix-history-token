begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * keyraw.h -- raw key and signature access and conversion  *  * Copyright (c) 2005-2008, NLnet Labs. All rights reserved.  *  * See LICENSE for the license.  *  */
end_comment

begin_comment
comment|/**  * \file  *  * raw key and signature access and conversion  *  * Since those functions heavily rely op cryptographic operations,  * this module is dependent on openssl.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_KEYRAW_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_KEYRAW_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|LDNS_BUILD_CONFIG_HAVE_SSL
include|#
directive|include
file|<openssl/ssl.h>
include|#
directive|include
file|<openssl/evp.h>
endif|#
directive|endif
comment|/* LDNS_BUILD_CONFIG_HAVE_SSL */
comment|/**  * get the length of the keydata in bits  * \param[in] keydata the raw key data  * \param[in] len the length of the keydata  * \param[in] alg the cryptographic algorithm this is a key for  * \return the keysize in bits, or 0 on error  */
name|size_t
name|sldns_rr_dnskey_key_size_raw
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|keydata
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|,
name|int
name|alg
parameter_list|)
function_decl|;
comment|/**  * Calculates keytag of DNSSEC key, operates on wireformat rdata.  * \param[in] key the key as uncompressed wireformat rdata.  * \param[in] keysize length of key data.  * \return the keytag  */
name|uint16_t
name|sldns_calc_keytag_raw
parameter_list|(
name|uint8_t
modifier|*
name|key
parameter_list|,
name|size_t
name|keysize
parameter_list|)
function_decl|;
if|#
directive|if
name|LDNS_BUILD_CONFIG_HAVE_SSL
comment|/**   * Get the PKEY id for GOST, loads GOST into openssl as a side effect.  * Only available if GOST is compiled into the library and openssl.  * \return the gost id for EVP_CTX creation.  */
name|int
name|sldns_key_EVP_load_gost_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Release the engine reference held for the GOST engine. */
name|void
name|sldns_key_EVP_unload_gost
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Like sldns_key_buf2dsa, but uses raw buffer.  * \param[in] key the uncompressed wireformat of the key.  * \param[in] len length of key data  * \return a DSA * structure with the key material  */
name|DSA
modifier|*
name|sldns_key_buf2dsa_raw
parameter_list|(
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Converts a holding buffer with key material to EVP PKEY in openssl.  * Only available if ldns was compiled with GOST.  * \param[in] key data to convert  * \param[in] keylen length of the key data  * \return the key or NULL on error.  */
name|EVP_PKEY
modifier|*
name|sldns_gost2pkey_raw
parameter_list|(
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|)
function_decl|;
comment|/**  * Converts a holding buffer with key material to EVP PKEY in openssl.  * Only available if ldns was compiled with ECDSA.  * \param[in] key data to convert  * \param[in] keylen length of the key data  * \param[in] algo precise algorithm to initialize ECC group values.  * \return the key or NULL on error.  */
name|EVP_PKEY
modifier|*
name|sldns_ecdsa2pkey_raw
parameter_list|(
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|uint8_t
name|algo
parameter_list|)
function_decl|;
comment|/**  * Like sldns_key_buf2rsa, but uses raw buffer.  * \param[in] key the uncompressed wireformat of the key.  * \param[in] len length of key data  * \return a RSA * structure with the key material  */
name|RSA
modifier|*
name|sldns_key_buf2rsa_raw
parameter_list|(
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Utility function to calculate hash using generic EVP_MD pointer.  * \param[in] data the data to hash.  * \param[in] len  length of data.  * \param[out] dest the destination of the hash, must be large enough.  * \param[in] md the message digest to use.  * \return true if worked, false on failure.  */
name|int
name|sldns_digest_evp
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
name|md
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* LDNS_BUILD_CONFIG_HAVE_SSL */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_KEYRAW_H */
end_comment

end_unit

