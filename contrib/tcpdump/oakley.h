begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* YIPS @(#)$Id: oakley.h,v 1.1 1999/10/30 05:11:10 itojun Exp $ */
end_comment

begin_comment
comment|/* refer to RFC 2409 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ISAKMP_OAKLEY_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISAKMP_OAKLEY_H_
end_define

begin_comment
comment|/* Attribute Classes */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG
value|1
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_DES
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_IDEA
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_BL
value|3
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_RC5
value|4
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_3DES
value|5
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_ENC_ALG_CAST
value|6
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_HASH_ALG
value|2
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_HASH_ALG_MD5
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_HASH_ALG_SHA
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_HASH_ALG_TIGER
value|3
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD
value|3
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD_PSKEY
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD_DSS
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD_RSA
value|3
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD_RSAENC
value|4
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_AUTH_METHOD_RSAREV
value|5
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_DESC
value|4
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_DESC_MODP768
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_DESC_MODP1024
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_DESC_EC2N155
value|3
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_DESC_EC2N185
value|4
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_TYPE
value|5
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_TYPE_MODP
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_TYPE_ECP
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_TYPE_EC2N
value|3
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_PI
value|6
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_GEN_ONE
value|7
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_GEN_TWO
value|8
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_CURVE_A
value|9
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_CURVE_B
value|10
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LTYPE
value|11
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LTYPE_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LTYPE_SEC
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LTYPE_KB
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LDUR
value|12
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_SA_LDUR_DEFAULT
value|28800
end_define

begin_comment
comment|/* 8 hours */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_PRF
value|13
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_KEY_LEN
value|14
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_FIELD_SIZE
value|15
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ATTR_GRP_ORDER
value|16
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_ID_IPV4_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|OAKLEY_ID_IPV4_ADDR_SUBNET
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_ID_IPV6_ADDR
value|2
end_define

begin_define
define|#
directive|define
name|OAKLEY_ID_IPV6_ADDR_SUBNET
value|3
end_define

begin_comment
comment|/* Additional Exchange Type */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_QUICK
value|32
end_define

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_NEWGRP
value|33
end_define

begin_comment
comment|/* The use for checking proposal payload. This is not exchange type. */
end_comment

begin_define
define|#
directive|define
name|OAKLEY_MAIN_MODE
value|0
end_define

begin_define
define|#
directive|define
name|OAKLEY_QUICK_MODE
value|1
end_define

begin_define
define|#
directive|define
name|OAKLEY_PRIME_MODP768
value|"\ 	FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 \ 	29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD \ 	EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245 \ 	E485B576 625E7EC6 F44C42E9 A63A3620 FFFFFFFF FFFFFFFF"
end_define

begin_define
define|#
directive|define
name|OAKLEY_PRIME_MODP1024
value|"\ 	FFFFFFFF FFFFFFFF C90FDAA2 2168C234 C4C6628B 80DC1CD1 \ 	29024E08 8A67CC74 020BBEA6 3B139B22 514A0879 8E3404DD \ 	EF9519B3 CD3A431B 302B0A6D F25F1437 4FE1356D 6D51C245 \ 	E485B576 625E7EC6 F44C42E9 A637ED6B 0BFF5CB6 F406B7ED \ 	EE386BFB 5A899FA5 AE9F2411 7C4B1FE6 49286651 ECE65381 \ 	FFFFFFFF FFFFFFFF"
end_define

begin_define
define|#
directive|define
name|DEFAULTSECRETSIZE
value|( 128 / 8 )
end_define

begin_comment
comment|/* 128 bits */
end_comment

begin_define
define|#
directive|define
name|DEFAULTNONCESIZE
value|( 128 / 8 )
end_define

begin_comment
comment|/* 128 bits */
end_comment

begin_define
define|#
directive|define
name|MAXPADLWORD
value|20
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* isakmp sa structure */
end_comment

begin_comment
unit|struct oakley_sa { 	u_int8_t  proto_id;
comment|/* OAKLEY */
end_comment

begin_comment
unit|vchar_t   *spi;
comment|/* spi */
end_comment

begin_comment
unit|u_int8_t  dhgrp;
comment|/* DH; group */
end_comment

begin_comment
unit|u_int8_t  auth_t;
comment|/* method of authentication */
end_comment

begin_comment
unit|u_int8_t  prf_t;
comment|/* type of prf */
end_comment

begin_comment
unit|u_int8_t  hash_t;
comment|/* type of hash */
end_comment

begin_comment
unit|u_int8_t  enc_t;
comment|/* type of cipher */
end_comment

begin_comment
unit|u_int8_t  life_t;
comment|/* type of duration of lifetime */
end_comment

begin_comment
unit|u_int32_t ldur;
comment|/* life duration */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_ISAKMP_OAKLEY_H_) */
end_comment

end_unit

