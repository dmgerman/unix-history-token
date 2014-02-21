begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**********************************************************************  *                         gost_keywrap.h                             *  *             Copyright (c) 2005-2006 Cryptocom LTD                  *  *       This file is distributed under the same license as OpenSSL   *  *                                                                    *  * Implementation of CryptoPro key wrap algorithm, as defined in      *  * RFC 4357 p 6.3 and 6.4                                             *  * Doesn't need OpenSSL                                               *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOST_KEYWRAP_H
end_ifndef

begin_define
define|#
directive|define
name|GOST_KEYWRAP_H
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"gost89.h"
end_include

begin_comment
comment|/* Diversifies key using random UserKey Material  * Implements RFC 4357 p 6.5 key diversification algorithm   *   * inputKey - 32byte key to be diversified  * ukm - 8byte user key material  * outputKey - 32byte buffer to store diversified key   *  */
end_comment

begin_function_decl
name|void
name|keyDiversifyCryptoPro
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|inputKey
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|ukm
parameter_list|,
name|unsigned
name|char
modifier|*
name|outputKey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Wraps key using RFC 4357 6.3  * ctx - gost encryption context, initialized with some S-boxes   * keyExchangeKey (KEK) 32-byte (256-bit) shared key  * ukm - 8 byte (64 bit) user key material,   * sessionKey - 32-byte (256-bit) key to be wrapped  * wrappedKey - 44-byte buffer to store wrapped key  */
end_comment

begin_function_decl
name|int
name|keyWrapCryptoPro
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|keyExchangeKey
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|ukm
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|sessionKey
parameter_list|,
name|unsigned
name|char
modifier|*
name|wrappedKey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unwraps key using RFC 4357 6.4  * ctx - gost encryption context, initialized with some S-boxes   * keyExchangeKey 32-byte shared key  * wrappedKey  44 byte key to be unwrapped (concatenation of 8-byte UKM,  * 32 byte  encrypted key and 4 byte MAC    *   * sessionKEy - 32byte buffer to store sessionKey in  * Returns 1 if key is decrypted successfully, and 0 if MAC doesn't match  */
end_comment

begin_function_decl
name|int
name|keyUnwrapCryptoPro
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|keyExchangeKey
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|wrappedKey
parameter_list|,
name|unsigned
name|char
modifier|*
name|sessionKey
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

