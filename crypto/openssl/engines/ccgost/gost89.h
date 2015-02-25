begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**********************************************************************  *                        gost89.h                                    *  *             Copyright (c) 2005-2006 Cryptocom LTD                  *  *     This file is distributed under the same license as OpenSSL     *  *                                                                    *  *          Declarations for GOST 28147-89 encryption algorithm       *  *            No OpenSSL libraries required to compile and use        *  *                       this code                                    *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOST89_H
end_ifndef

begin_define
define|#
directive|define
name|GOST89_H
end_define

begin_comment
comment|/* Typedef for unsigned 32-bit integer */
end_comment

begin_if
if|#
directive|if
name|__LONG_MAX__
operator|>
literal|2147483647L
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u4
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u4
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Typedef for unsigned 8-bit integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_comment
comment|/* Internal representation of GOST substitution blocks */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|byte
name|k8
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k7
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k6
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k5
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k4
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k3
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k2
index|[
literal|16
index|]
decl_stmt|;
name|byte
name|k1
index|[
literal|16
index|]
decl_stmt|;
block|}
name|gost_subst_block
typedef|;
end_typedef

begin_comment
comment|/* Cipher context includes key and preprocessed  substitution block */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u4
name|k
index|[
literal|8
index|]
decl_stmt|;
comment|/* Constant s-boxes -- set up in gost_init(). */
name|u4
name|k87
index|[
literal|256
index|]
decl_stmt|,
name|k65
index|[
literal|256
index|]
decl_stmt|,
name|k43
index|[
literal|256
index|]
decl_stmt|,
name|k21
index|[
literal|256
index|]
decl_stmt|;
block|}
name|gost_ctx
typedef|;
end_typedef

begin_comment
comment|/* Note: encrypt and decrypt expect full blocks--padding blocks is           caller's responsibility. All bulk encryption is done in  		 ECB mode by these calls. Other modes may be added easily  		 enough.                                            */
end_comment

begin_comment
comment|/* Encrypt several full blocks in ECB mode */
end_comment

begin_function_decl
name|void
name|gost_enc
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|clear
parameter_list|,
name|byte
modifier|*
name|cipher
parameter_list|,
name|int
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decrypt several full blocks in ECB mode */
end_comment

begin_function_decl
name|void
name|gost_dec
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|cipher
parameter_list|,
name|byte
modifier|*
name|clear
parameter_list|,
name|int
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Encrypts several full blocks in CFB mode using 8byte IV */
end_comment

begin_function_decl
name|void
name|gost_enc_cfb
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|iv
parameter_list|,
specifier|const
name|byte
modifier|*
name|clear
parameter_list|,
name|byte
modifier|*
name|cipher
parameter_list|,
name|int
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decrypts several full blocks in CFB mode using 8byte IV */
end_comment

begin_function_decl
name|void
name|gost_dec_cfb
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|iv
parameter_list|,
specifier|const
name|byte
modifier|*
name|cipher
parameter_list|,
name|byte
modifier|*
name|clear
parameter_list|,
name|int
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Encrypt one  block */
end_comment

begin_function_decl
name|void
name|gostcrypt
parameter_list|(
name|gost_ctx
modifier|*
name|c
parameter_list|,
specifier|const
name|byte
modifier|*
name|in
parameter_list|,
name|byte
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decrypt one  block */
end_comment

begin_function_decl
name|void
name|gostdecrypt
parameter_list|(
name|gost_ctx
modifier|*
name|c
parameter_list|,
specifier|const
name|byte
modifier|*
name|in
parameter_list|,
name|byte
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set key into context */
end_comment

begin_function_decl
name|void
name|gost_key
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|byte
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get key from context */
end_comment

begin_function_decl
name|void
name|gost_get_key
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
name|byte
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set S-blocks into context */
end_comment

begin_function_decl
name|void
name|gost_init
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|gost_subst_block
modifier|*
name|subst_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clean up context */
end_comment

begin_function_decl
name|void
name|gost_destroy
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Intermediate function used for calculate hash */
end_comment

begin_function_decl
name|void
name|gost_enc_with_key
parameter_list|(
name|gost_ctx
modifier|*
parameter_list|,
name|byte
modifier|*
name|key
parameter_list|,
name|byte
modifier|*
name|inblock
parameter_list|,
name|byte
modifier|*
name|outblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute MAC of given length in bits from data */
end_comment

begin_function_decl
name|int
name|gost_mac
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|hmac_len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|data_len
parameter_list|,
name|unsigned
name|char
modifier|*
name|hmac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute MAC of given length in bits from data, using non-zero 8-byte  * IV (non-standard, for use in CryptoPro key transport only */
end_comment

begin_function_decl
name|int
name|gost_mac_iv
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|hmac_len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|iv
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|data_len
parameter_list|,
name|unsigned
name|char
modifier|*
name|hmac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Perform one step of MAC calculation like gostcrypt */
end_comment

begin_function_decl
name|void
name|mac_block
parameter_list|(
name|gost_ctx
modifier|*
name|c
parameter_list|,
name|byte
modifier|*
name|buffer
parameter_list|,
specifier|const
name|byte
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extracts MAC value from mac state buffer */
end_comment

begin_function_decl
name|void
name|get_mac
parameter_list|(
name|byte
modifier|*
name|buffer
parameter_list|,
name|int
name|nbits
parameter_list|,
name|byte
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implements cryptopro key meshing algorithm. Expect IV to be 8-byte size*/
end_comment

begin_function_decl
name|void
name|cryptopro_key_meshing
parameter_list|(
name|gost_ctx
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parameter sets specified in RFC 4357 */
end_comment

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|GostR3411_94_TestParamSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|GostR3411_94_CryptoProParamSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|Gost28147_TestParamSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|Gost28147_CryptoProParamSetA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|Gost28147_CryptoProParamSetB
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|Gost28147_CryptoProParamSetC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gost_subst_block
name|Gost28147_CryptoProParamSetD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|byte
name|CryptoProKeyMeshingKey
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|unsigned
name|int
name|word32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

