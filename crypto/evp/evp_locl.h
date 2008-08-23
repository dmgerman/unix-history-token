begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* evp_locl.h */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (shenson@bigfoot.com) for the OpenSSL  * project 2000.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* Macros to code block cipher wrappers */
end_comment

begin_comment
comment|/* Wrapper functions for each cipher mode */
end_comment

begin_define
define|#
directive|define
name|BLOCK_CIPHER_ecb_loop
parameter_list|()
define|\
value|unsigned int i, bl; \ 	bl = ctx->cipher->block_size;\ 	if(inl< bl) return 1;\ 	inl -= bl; \ 	for(i=0; i<= inl; i+=bl)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_func_ecb
parameter_list|(
name|cname
parameter_list|,
name|cprefix
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|)
define|\
value|static int cname##_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl) \ {\ 	BLOCK_CIPHER_ecb_loop() \ 		cprefix##_ecb_encrypt(in + i, out + i,&((kstruct *)ctx->cipher_data)->ksched, ctx->encrypt);\ 	return 1;\ }
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_func_ofb
parameter_list|(
name|cname
parameter_list|,
name|cprefix
parameter_list|,
name|cbits
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|)
define|\
value|static int cname##_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl) \ {\ 	cprefix##_ofb##cbits##_encrypt(in, out, (long)inl,&((kstruct *)ctx->cipher_data)->ksched, ctx->iv,&ctx->num);\ 	return 1;\ }
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_func_cbc
parameter_list|(
name|cname
parameter_list|,
name|cprefix
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|)
define|\
value|static int cname##_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl) \ {\ 	cprefix##_cbc_encrypt(in, out, (long)inl,&((kstruct *)ctx->cipher_data)->ksched, ctx->iv, ctx->encrypt);\ 	return 1;\ }
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_func_cfb
parameter_list|(
name|cname
parameter_list|,
name|cprefix
parameter_list|,
name|cbits
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|)
define|\
value|static int cname##_cfb##cbits##_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl) \ {\ 	cprefix##_cfb##cbits##_encrypt(in, out, (long)inl,&((kstruct *)ctx->cipher_data)->ksched, ctx->iv,&ctx->num, ctx->encrypt);\ 	return 1;\ }
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_all_funcs
parameter_list|(
name|cname
parameter_list|,
name|cprefix
parameter_list|,
name|cbits
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|)
define|\
value|BLOCK_CIPHER_func_cbc(cname, cprefix, kstruct, ksched) \ 	BLOCK_CIPHER_func_cfb(cname, cprefix, cbits, kstruct, ksched) \ 	BLOCK_CIPHER_func_ecb(cname, cprefix, kstruct, ksched) \ 	BLOCK_CIPHER_func_ofb(cname, cprefix, cbits, kstruct, ksched)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_def1
parameter_list|(
name|cname
parameter_list|,
name|nmode
parameter_list|,
name|mode
parameter_list|,
name|MODE
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|,
name|block_size
parameter_list|, \
name|key_len
parameter_list|,
name|iv_len
parameter_list|,
name|flags
parameter_list|,
name|init_key
parameter_list|,
name|cleanup
parameter_list|, \
name|set_asn1
parameter_list|,
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|static const EVP_CIPHER cname##_##mode = { \ 	nid##_##nmode, block_size, key_len, iv_len, \ 	flags | EVP_CIPH_##MODE##_MODE, \ 	init_key, \ 	cname##_##mode##_cipher, \ 	cleanup, \ 	sizeof(kstruct), \ 	set_asn1, get_asn1,\ 	ctrl, \ 	NULL \ }; \ const EVP_CIPHER *EVP_##cname##_##mode(void) { return&cname##_##mode; }
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_def_cbc
parameter_list|(
name|cname
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|,
name|block_size
parameter_list|,
name|key_len
parameter_list|, \
name|iv_len
parameter_list|,
name|flags
parameter_list|,
name|init_key
parameter_list|,
name|cleanup
parameter_list|,
name|set_asn1
parameter_list|, \
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_def1(cname, cbc, cbc, CBC, kstruct, nid, block_size, key_len, \ 		  iv_len, flags, init_key, cleanup, set_asn1, get_asn1, ctrl)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_def_cfb
parameter_list|(
name|cname
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|,
name|key_len
parameter_list|, \
name|iv_len
parameter_list|,
name|cbits
parameter_list|,
name|flags
parameter_list|,
name|init_key
parameter_list|,
name|cleanup
parameter_list|, \
name|set_asn1
parameter_list|,
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_def1(cname, cfb##cbits, cfb##cbits, CFB, kstruct, nid, 1, \ 		  key_len, iv_len, flags, init_key, cleanup, set_asn1, \ 		  get_asn1, ctrl)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_def_ofb
parameter_list|(
name|cname
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|,
name|key_len
parameter_list|, \
name|iv_len
parameter_list|,
name|cbits
parameter_list|,
name|flags
parameter_list|,
name|init_key
parameter_list|,
name|cleanup
parameter_list|, \
name|set_asn1
parameter_list|,
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_def1(cname, ofb##cbits, ofb, OFB, kstruct, nid, 1, \ 		  key_len, iv_len, flags, init_key, cleanup, set_asn1, \ 		  get_asn1, ctrl)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_def_ecb
parameter_list|(
name|cname
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|,
name|block_size
parameter_list|,
name|key_len
parameter_list|, \
name|iv_len
parameter_list|,
name|flags
parameter_list|,
name|init_key
parameter_list|,
name|cleanup
parameter_list|,
name|set_asn1
parameter_list|, \
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_def1(cname, ecb, ecb, ECB, kstruct, nid, block_size, key_len, \ 		  iv_len, flags, init_key, cleanup, set_asn1, get_asn1, ctrl)
end_define

begin_define
define|#
directive|define
name|BLOCK_CIPHER_defs
parameter_list|(
name|cname
parameter_list|,
name|kstruct
parameter_list|, \
name|nid
parameter_list|,
name|block_size
parameter_list|,
name|key_len
parameter_list|,
name|iv_len
parameter_list|,
name|cbits
parameter_list|,
name|flags
parameter_list|, \
name|init_key
parameter_list|,
name|cleanup
parameter_list|,
name|set_asn1
parameter_list|,
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_def_cbc(cname, kstruct, nid, block_size, key_len, iv_len, flags, \ 		     init_key, cleanup, set_asn1, get_asn1, ctrl) \ BLOCK_CIPHER_def_cfb(cname, kstruct, nid, key_len, iv_len, cbits, \ 		     flags, init_key, cleanup, set_asn1, get_asn1, ctrl) \ BLOCK_CIPHER_def_ofb(cname, kstruct, nid, key_len, iv_len, cbits, \ 		     flags, init_key, cleanup, set_asn1, get_asn1, ctrl) \ BLOCK_CIPHER_def_ecb(cname, kstruct, nid, block_size, key_len, iv_len, flags, \ 		     init_key, cleanup, set_asn1, get_asn1, ctrl)
end_define

begin_comment
comment|/* #define BLOCK_CIPHER_defs(cname, kstruct, \ 				nid, block_size, key_len, iv_len, flags,\ 				 init_key, cleanup, set_asn1, get_asn1, ctrl)\ static const EVP_CIPHER cname##_cbc = {\ 	nid##_cbc, block_size, key_len, iv_len, \ 	flags | EVP_CIPH_CBC_MODE,\ 	init_key,\ 	cname##_cbc_cipher,\ 	cleanup,\ 	sizeof(EVP_CIPHER_CTX)-sizeof((((EVP_CIPHER_CTX *)NULL)->c))+\ 		sizeof((((EVP_CIPHER_CTX *)NULL)->c.kstruct)),\ 	set_asn1, get_asn1,\ 	ctrl, \ 	NULL \ };\ const EVP_CIPHER *EVP_##cname##_cbc(void) { return&cname##_cbc; }\ static const EVP_CIPHER cname##_cfb = {\ 	nid##_cfb64, 1, key_len, iv_len, \ 	flags | EVP_CIPH_CFB_MODE,\ 	init_key,\ 	cname##_cfb_cipher,\ 	cleanup,\ 	sizeof(EVP_CIPHER_CTX)-sizeof((((EVP_CIPHER_CTX *)NULL)->c))+\ 		sizeof((((EVP_CIPHER_CTX *)NULL)->c.kstruct)),\ 	set_asn1, get_asn1,\ 	ctrl,\ 	NULL \ };\ const EVP_CIPHER *EVP_##cname##_cfb(void) { return&cname##_cfb; }\ static const EVP_CIPHER cname##_ofb = {\ 	nid##_ofb64, 1, key_len, iv_len, \ 	flags | EVP_CIPH_OFB_MODE,\ 	init_key,\ 	cname##_ofb_cipher,\ 	cleanup,\ 	sizeof(EVP_CIPHER_CTX)-sizeof((((EVP_CIPHER_CTX *)NULL)->c))+\ 		sizeof((((EVP_CIPHER_CTX *)NULL)->c.kstruct)),\ 	set_asn1, get_asn1,\ 	ctrl,\ 	NULL \ };\ const EVP_CIPHER *EVP_##cname##_ofb(void) { return&cname##_ofb; }\ static const EVP_CIPHER cname##_ecb = {\ 	nid##_ecb, block_size, key_len, iv_len, \ 	flags | EVP_CIPH_ECB_MODE,\ 	init_key,\ 	cname##_ecb_cipher,\ 	cleanup,\ 	sizeof(EVP_CIPHER_CTX)-sizeof((((EVP_CIPHER_CTX *)NULL)->c))+\ 		sizeof((((EVP_CIPHER_CTX *)NULL)->c.kstruct)),\ 	set_asn1, get_asn1,\ 	ctrl,\ 	NULL \ };\ const EVP_CIPHER *EVP_##cname##_ecb(void) { return&cname##_ecb; } */
end_comment

begin_define
define|#
directive|define
name|IMPLEMENT_BLOCK_CIPHER
parameter_list|(
name|cname
parameter_list|,
name|ksched
parameter_list|,
name|cprefix
parameter_list|,
name|kstruct
parameter_list|,
name|nid
parameter_list|, \
name|block_size
parameter_list|,
name|key_len
parameter_list|,
name|iv_len
parameter_list|,
name|cbits
parameter_list|, \
name|flags
parameter_list|,
name|init_key
parameter_list|, \
name|cleanup
parameter_list|,
name|set_asn1
parameter_list|,
name|get_asn1
parameter_list|,
name|ctrl
parameter_list|)
define|\
value|BLOCK_CIPHER_all_funcs(cname, cprefix, cbits, kstruct, ksched) \ 	BLOCK_CIPHER_defs(cname, kstruct, nid, block_size, key_len, iv_len, \ 			  cbits, flags, init_key, cleanup, set_asn1, \ 			  get_asn1, ctrl)
end_define

begin_define
define|#
directive|define
name|EVP_C_DATA
parameter_list|(
name|kstruct
parameter_list|,
name|ctx
parameter_list|)
value|((kstruct *)(ctx)->cipher_data)
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_CFBR
parameter_list|(
name|cipher
parameter_list|,
name|cprefix
parameter_list|,
name|kstruct
parameter_list|,
name|ksched
parameter_list|,
name|keysize
parameter_list|,
name|cbits
parameter_list|,
name|iv_len
parameter_list|)
define|\
value|BLOCK_CIPHER_func_cfb(cipher##_##keysize,cprefix,cbits,kstruct,ksched) \ 	BLOCK_CIPHER_def_cfb(cipher##_##keysize,kstruct, \ 			     NID_##cipher##_##keysize, keysize/8, iv_len, cbits, \ 			     0, cipher##_init_key, NULL, \ 			     EVP_CIPHER_set_asn1_iv, \ 			     EVP_CIPHER_get_asn1_iv, \ 			     NULL)
end_define

end_unit

