begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_COP2_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_COP2_H__
end_define

begin_comment
comment|/*  * COP2 registers of interest  */
end_comment

begin_define
define|#
directive|define
name|COP2_CRC_IV
value|0x201
end_define

begin_define
define|#
directive|define
name|COP2_CRC_IV_SET
value|COP2_CRC_IV
end_define

begin_define
define|#
directive|define
name|COP2_CRC_LENGTH
value|0x202
end_define

begin_define
define|#
directive|define
name|COP2_CRC_LENGTH_SET
value|0x1202
end_define

begin_define
define|#
directive|define
name|COP2_CRC_POLY
value|0x200
end_define

begin_define
define|#
directive|define
name|COP2_CRC_POLY_SET
value|0x4200
end_define

begin_define
define|#
directive|define
name|COP2_LLM_DAT0
value|0x402
end_define

begin_define
define|#
directive|define
name|COP2_LLM_DAT0_SET
value|COP2_LLM_DAT0
end_define

begin_define
define|#
directive|define
name|COP2_LLM_DAT1
value|0x40A
end_define

begin_define
define|#
directive|define
name|COP2_LLM_DAT1_SET
value|COP2_LLM_DAT1
end_define

begin_define
define|#
directive|define
name|COP2_3DES_IV
value|0x084
end_define

begin_define
define|#
directive|define
name|COP2_3DES_IV_SET
value|COP2_3DES_IV
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY0
value|0x080
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY0_SET
value|COP2_3DES_KEY0
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY1
value|0x081
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY1_SET
value|COP2_3DES_KEY1
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY2
value|0x082
end_define

begin_define
define|#
directive|define
name|COP2_3DES_KEY2_SET
value|COP2_3DES_KEY2
end_define

begin_define
define|#
directive|define
name|COP2_3DES_RESULT
value|0x088
end_define

begin_define
define|#
directive|define
name|COP2_3DES_RESULT_SET
value|0x098
end_define

begin_define
define|#
directive|define
name|COP2_AES_INP0
value|0x111
end_define

begin_define
define|#
directive|define
name|COP2_AES_INP0_SET
value|COP2_AES_INP0
end_define

begin_define
define|#
directive|define
name|COP2_AES_IV0
value|0x102
end_define

begin_define
define|#
directive|define
name|COP2_AES_IV0_SET
value|COP2_AES_IV0
end_define

begin_define
define|#
directive|define
name|COP2_AES_IV1
value|0x103
end_define

begin_define
define|#
directive|define
name|COP2_AES_IV1_SET
value|COP2_AES_IV1
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY0
value|0x104
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY0_SET
value|COP2_AES_KEY0
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY1
value|0x105
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY1_SET
value|COP2_AES_KEY1
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY2
value|0x106
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY2_SET
value|COP2_AES_KEY2
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY3
value|0x107
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEY3_SET
value|COP2_AES_KEY3
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEYLEN
value|0x110
end_define

begin_define
define|#
directive|define
name|COP2_AES_KEYLEN_SET
value|COP2_AES_KEYLEN
end_define

begin_define
define|#
directive|define
name|COP2_AES_RESULT0
value|0x100
end_define

begin_define
define|#
directive|define
name|COP2_AES_RESULT0_SET
value|COP2_AES_RESULT0
end_define

begin_define
define|#
directive|define
name|COP2_AES_RESULT1
value|0x101
end_define

begin_define
define|#
directive|define
name|COP2_AES_RESULT1_SET
value|COP2_AES_RESULT1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW0
value|0x240
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW0_SET
value|COP2_HSH_DATW0
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW1
value|0x241
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW1_SET
value|COP2_HSH_DATW1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW2
value|0x242
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW2_SET
value|COP2_HSH_DATW2
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW3
value|0x243
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW3_SET
value|COP2_HSH_DATW3
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW4
value|0x244
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW4_SET
value|COP2_HSH_DATW4
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW5
value|0x245
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW5_SET
value|COP2_HSH_DATW5
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW6
value|0x246
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW6_SET
value|COP2_HSH_DATW6
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW7
value|0x247
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW7_SET
value|COP2_HSH_DATW7
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW8
value|0x248
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW8_SET
value|COP2_HSH_DATW8
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW9
value|0x249
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW9_SET
value|COP2_HSH_DATW9
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW10
value|0x24A
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW10_SET
value|COP2_HSH_DATW10
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW11
value|0x24B
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW11_SET
value|COP2_HSH_DATW11
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW12
value|0x24C
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW12_SET
value|COP2_HSH_DATW12
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW13
value|0x24D
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW13_SET
value|COP2_HSH_DATW13
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW14
value|0x24E
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW14_SET
value|COP2_HSH_DATW14
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW0
value|0x250
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW0_SET
value|COP2_HSH_IVW0
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW1
value|0x251
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW1_SET
value|COP2_HSH_IVW1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW2
value|0x252
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW2_SET
value|COP2_HSH_IVW2
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW3
value|0x253
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW3_SET
value|COP2_HSH_IVW3
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW4
value|0x254
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW4_SET
value|COP2_HSH_IVW4
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW5
value|0x255
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW5_SET
value|COP2_HSH_IVW5
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW6
value|0x256
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW6_SET
value|COP2_HSH_IVW6
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW7
value|0x257
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW7_SET
value|COP2_HSH_IVW7
end_define

begin_define
define|#
directive|define
name|COP2_GFM_MULT0
value|0x258
end_define

begin_define
define|#
directive|define
name|COP2_GFM_MULT0_SET
value|COP2_GFM_MULT0
end_define

begin_define
define|#
directive|define
name|COP2_GFM_MULT1
value|0x259
end_define

begin_define
define|#
directive|define
name|COP2_GFM_MULT1_SET
value|COP2_GFM_MULT1
end_define

begin_define
define|#
directive|define
name|COP2_GFM_POLY
value|0x25E
end_define

begin_define
define|#
directive|define
name|COP2_GFM_POLY_SET
value|COP2_GFM_POLY
end_define

begin_define
define|#
directive|define
name|COP2_GFM_RESULT0
value|0x25A
end_define

begin_define
define|#
directive|define
name|COP2_GFM_RESULT0_SET
value|COP2_GFM_RESULT0
end_define

begin_define
define|#
directive|define
name|COP2_GFM_RESULT1
value|0x25B
end_define

begin_define
define|#
directive|define
name|COP2_GFM_RESULT1_SET
value|COP2_GFM_RESULT1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW0_PASS1
value|0x040
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW0_PASS1_SET
value|COP2_HSH_DATW0_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW1_PASS1
value|0x041
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW1_PASS1_SET
value|COP2_HSH_DATW1_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW2_PASS1
value|0x042
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW2_PASS1_SET
value|COP2_HSH_DATW2_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW3_PASS1
value|0x043
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW3_PASS1_SET
value|COP2_HSH_DATW3_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW4_PASS1
value|0x044
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW4_PASS1_SET
value|COP2_HSH_DATW4_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW5_PASS1
value|0x045
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW5_PASS1_SET
value|COP2_HSH_DATW5_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW6_PASS1
value|0x046
end_define

begin_define
define|#
directive|define
name|COP2_HSH_DATW6_PASS1_SET
value|COP2_HSH_DATW6_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW0_PASS1
value|0x048
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW0_PASS1_SET
value|COP2_HSH_IVW0_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW1_PASS1
value|0x049
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW1_PASS1_SET
value|COP2_HSH_IVW1_PASS1
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW2_PASS1
value|0x04A
end_define

begin_define
define|#
directive|define
name|COP2_HSH_IVW2_PASS1_SET
value|COP2_HSH_IVW2_PASS1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|octeon_cop2_state
block|{
comment|/* 3DES */
comment|/* 0x0084 */
name|unsigned
name|long
name|_3des_iv
decl_stmt|;
comment|/* 0x0080..0x0082 */
name|unsigned
name|long
name|_3des_key
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x0088, set: 0x0098 */
name|unsigned
name|long
name|_3des_result
decl_stmt|;
comment|/* AES */
comment|/* 0x0111 */
name|unsigned
name|long
name|aes_inp0
decl_stmt|;
comment|/* 0x0102..0x0103 */
name|unsigned
name|long
name|aes_iv
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x0104..0x0107 */
name|unsigned
name|long
name|aes_key
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x0110 */
name|unsigned
name|long
name|aes_keylen
decl_stmt|;
comment|/* 0x0100..0x0101 */
name|unsigned
name|long
name|aes_result
index|[
literal|2
index|]
decl_stmt|;
comment|/* CRC */
comment|/*  0x0201 */
name|unsigned
name|long
name|crc_iv
decl_stmt|;
comment|/* 0x0202, set: 0x1202 */
name|unsigned
name|long
name|crc_length
decl_stmt|;
comment|/* 0x0200, set: 0x4200 */
name|unsigned
name|long
name|crc_poly
decl_stmt|;
comment|/* Low-latency memory stuff */
comment|/* 0x0402, 0x040A */
name|unsigned
name|long
name|llm_dat
index|[
literal|2
index|]
decl_stmt|;
comment|/* SHA& MD5 */
comment|/* 0x0240..0x024E */
name|unsigned
name|long
name|hsh_datw
index|[
literal|15
index|]
decl_stmt|;
comment|/* 0x0250..0x0257 */
name|unsigned
name|long
name|hsh_ivw
index|[
literal|8
index|]
decl_stmt|;
comment|/* GFM */
comment|/*  0x0258..0x0259 */
name|unsigned
name|long
name|gfm_mult
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x025E */
name|unsigned
name|long
name|gfm_poly
decl_stmt|;
comment|/* 0x025A..0x025B */
name|unsigned
name|long
name|gfm_result
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Prototypes */
end_comment

begin_function_decl
name|struct
name|octeon_cop2_state
modifier|*
name|octeon_cop2_alloc_ctx
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|octeon_cop2_free_ctx
parameter_list|(
name|struct
name|octeon_cop2_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Save/restore part  */
end_comment

begin_function_decl
name|void
name|octeon_cop2_save
parameter_list|(
name|struct
name|octeon_cop2_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|octeon_cop2_restore
parameter_list|(
name|struct
name|octeon_cop2_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OCTEON_COP2_H__ */
end_comment

end_unit

