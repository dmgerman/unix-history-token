begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Chelsio Communications, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_CRYPTO_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_CRYPTO_H__
end_define

begin_comment
comment|/* From chr_core.h */
end_comment

begin_define
define|#
directive|define
name|PAD_ERROR_BIT
value|1
end_define

begin_define
define|#
directive|define
name|CHK_PAD_ERR_BIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PAD_ERROR_BIT)& 1)
end_define

begin_define
define|#
directive|define
name|MAC_ERROR_BIT
value|0
end_define

begin_define
define|#
directive|define
name|CHK_MAC_ERR_BIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> MAC_ERROR_BIT)& 1)
end_define

begin_define
define|#
directive|define
name|MAX_SALT
value|4
end_define

begin_struct
struct|struct
name|_key_ctx
block|{
name|__be32
name|ctx_hdr
decl_stmt|;
name|u8
name|salt
index|[
name|MAX_SALT
index|]
decl_stmt|;
name|__be64
name|reserverd
decl_stmt|;
name|unsigned
name|char
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chcr_wr
block|{
name|struct
name|fw_crypto_lookaside_wr
name|wreq
decl_stmt|;
name|struct
name|ulp_txpkt
name|ulptx
decl_stmt|;
name|struct
name|ulptx_idata
name|sc_imm
decl_stmt|;
name|struct
name|cpl_tx_sec_pdu
name|sec_cpl
decl_stmt|;
name|struct
name|_key_ctx
name|key_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* From chr_algo.h */
end_comment

begin_comment
comment|/* Crypto key context */
end_comment

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_CTX_LEN
value|24
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_CTX_LEN
value|0xff
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_CTX_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_CTX_LEN)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_CTX_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_CTX_LEN)& M_KEY_CONTEXT_CTX_LEN)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_DUAL_CK
value|12
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_DUAL_CK
value|0x1
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_DUAL_CK
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_DUAL_CK)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_DUAL_CK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_DUAL_CK)& M_KEY_CONTEXT_DUAL_CK)
end_define

begin_define
define|#
directive|define
name|F_KEY_CONTEXT_DUAL_CK
value|V_KEY_CONTEXT_DUAL_CK(1U)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_OPAD_PRESENT
value|11
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_OPAD_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_OPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_OPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_OPAD_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_OPAD_PRESENT)& \ 	 M_KEY_CONTEXT_OPAD_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_KEY_CONTEXT_OPAD_PRESENT
value|V_KEY_CONTEXT_OPAD_PRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_SALT_PRESENT
value|10
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_SALT_PRESENT
value|0x1
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_SALT_PRESENT
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_SALT_PRESENT)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_SALT_PRESENT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_SALT_PRESENT)& \ 	 M_KEY_CONTEXT_SALT_PRESENT)
end_define

begin_define
define|#
directive|define
name|F_KEY_CONTEXT_SALT_PRESENT
value|V_KEY_CONTEXT_SALT_PRESENT(1U)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_CK_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_CK_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_CK_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_CK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_CK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_CK_SIZE)& M_KEY_CONTEXT_CK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_MK_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_MK_SIZE
value|0xf
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_MK_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_MK_SIZE)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_MK_SIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_MK_SIZE)& M_KEY_CONTEXT_MK_SIZE)
end_define

begin_define
define|#
directive|define
name|S_KEY_CONTEXT_VALID
value|0
end_define

begin_define
define|#
directive|define
name|M_KEY_CONTEXT_VALID
value|0x1
end_define

begin_define
define|#
directive|define
name|V_KEY_CONTEXT_VALID
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_KEY_CONTEXT_VALID)
end_define

begin_define
define|#
directive|define
name|G_KEY_CONTEXT_VALID
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_KEY_CONTEXT_VALID)& \ 	 M_KEY_CONTEXT_VALID)
end_define

begin_define
define|#
directive|define
name|F_KEY_CONTEXT_VALID
value|V_KEY_CONTEXT_VALID(1U)
end_define

begin_define
define|#
directive|define
name|CHCR_HASH_MAX_DIGEST_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|DUMMY_BYTES
value|16
end_define

begin_define
define|#
directive|define
name|TRANSHDR_SIZE
parameter_list|(
name|kctx_len
parameter_list|)
define|\
value|(sizeof(struct chcr_wr) +\ 	 kctx_len)
end_define

begin_define
define|#
directive|define
name|CIPHER_TRANSHDR_SIZE
parameter_list|(
name|kctx_len
parameter_list|,
name|sge_pairs
parameter_list|)
define|\
value|(TRANSHDR_SIZE((kctx_len)) + (sge_pairs) +\ 	 sizeof(struct cpl_rx_phys_dsgl))
end_define

begin_define
define|#
directive|define
name|HASH_TRANSHDR_SIZE
parameter_list|(
name|kctx_len
parameter_list|)
define|\
value|(TRANSHDR_SIZE(kctx_len) + DUMMY_BYTES)
end_define

begin_define
define|#
directive|define
name|CRYPTO_MAX_IMM_TX_PKT_LEN
value|256
end_define

begin_struct
struct|struct
name|phys_sge_pairs
block|{
name|__be16
name|len
index|[
literal|8
index|]
decl_stmt|;
name|__be64
name|addr
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* From chr_crypto.h */
end_comment

begin_define
define|#
directive|define
name|CHCR_AES_MAX_KEY_LEN
value|(AES_XTS_MAX_KEY)
end_define

begin_define
define|#
directive|define
name|CHCR_MAX_CRYPTO_IV_LEN
value|16
end_define

begin_comment
comment|/* AES IV len */
end_comment

begin_define
define|#
directive|define
name|CHCR_ENCRYPT_OP
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_DECRYPT_OP
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_PROTO_VERSION_GENERIC
value|4
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_NOP
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_AES_CBC
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_AES_GCM
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_AES_CTR
value|3
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_GENERIC_AES
value|4
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_AES_XTS
value|6
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_CIPHER_MODE_AES_CCM
value|7
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_NOP
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA1
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA224
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA256
value|3
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_GHASH
value|4
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA512_224
value|5
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA512_256
value|6
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA512_384
value|7
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_SHA512_512
value|8
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_CBCMAC
value|9
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_AUTH_MODE_CMAC
value|10
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_NOP
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_NO_TRUNC
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_TRUNC_RFC4366
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_IPSEC_96BIT
value|3
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_PL1
value|4
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_PL2
value|5
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_PL3
value|6
end_define

begin_define
define|#
directive|define
name|CHCR_SCMD_HMAC_CTRL_DIV2
value|7
end_define

begin_comment
comment|/* This are not really mac key size. They are intermediate values  * of sha engine and its size  */
end_comment

begin_define
define|#
directive|define
name|CHCR_KEYCTX_MAC_KEY_SIZE_128
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_MAC_KEY_SIZE_160
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_MAC_KEY_SIZE_192
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_MAC_KEY_SIZE_256
value|3
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_MAC_KEY_SIZE_512
value|4
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_CIPHER_KEY_SIZE_128
value|0
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_CIPHER_KEY_SIZE_192
value|1
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_CIPHER_KEY_SIZE_256
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_KEYCTX_NO_KEY
value|15
end_define

begin_define
define|#
directive|define
name|IV_NOP
value|0
end_define

begin_define
define|#
directive|define
name|IV_IMMEDIATE
value|1
end_define

begin_define
define|#
directive|define
name|IV_DSGL
value|2
end_define

begin_define
define|#
directive|define
name|CHCR_HASH_MAX_BLOCK_SIZE_64
value|64
end_define

begin_define
define|#
directive|define
name|CHCR_HASH_MAX_BLOCK_SIZE_128
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__T4_CRYPTO_H__ */
end_comment

end_unit

