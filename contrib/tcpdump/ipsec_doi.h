begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* YIPS @(#)$Id: ipsec_doi.h,v 1.4 2000/10/04 03:00:29 itojun Exp $ */
end_comment

begin_comment
comment|/* refer to RFC 2407 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_IPSEC_DOI_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_IPSEC_DOI_H_
end_define

begin_define
define|#
directive|define
name|IPSEC_DOI
value|1
end_define

begin_comment
comment|/* 4.2 IPSEC Situation Definition */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_SIT_IDENTITY_ONLY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPSECDOI_SIT_SECRECY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPSECDOI_SIT_INTEGRITY
value|0x00000004
end_define

begin_comment
comment|/* 4.4.1 IPSEC Security Protocol Identifiers */
end_comment

begin_comment
comment|/* 4.4.2 IPSEC ISAKMP Transform Values */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_PROTO_ISAKMP
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_KEY_IKE
value|1
end_define

begin_comment
comment|/* 4.4.1 IPSEC Security Protocol Identifiers */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_PROTO_IPSEC_AH
value|2
end_define

begin_comment
comment|/* 4.4.3 IPSEC AH Transform Values */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_AH_MD5
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_AH_SHA
value|3
end_define

begin_define
define|#
directive|define
name|IPSECDOI_AH_DES
value|4
end_define

begin_define
define|#
directive|define
name|IPSECDOI_AH_SHA2_256
value|5
end_define

begin_define
define|#
directive|define
name|IPSECDOI_AH_SHA2_384
value|6
end_define

begin_define
define|#
directive|define
name|IPSECDOI_AH_SHA2_512
value|7
end_define

begin_comment
comment|/* 4.4.1 IPSEC Security Protocol Identifiers */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_PROTO_IPSEC_ESP
value|3
end_define

begin_comment
comment|/* 4.4.4 IPSEC ESP Transform Identifiers */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ESP_DES_IV64
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_DES
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_3DES
value|3
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_RC5
value|4
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_IDEA
value|5
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_CAST
value|6
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_BLOWFISH
value|7
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_3IDEA
value|8
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_DES_IV32
value|9
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_RC4
value|10
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_NULL
value|11
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_RIJNDAEL
value|12
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ESP_AES
value|12
end_define

begin_comment
comment|/* 4.4.1 IPSEC Security Protocol Identifiers */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_PROTO_IPCOMP
value|4
end_define

begin_comment
comment|/* 4.4.5 IPSEC IPCOMP Transform Identifiers */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_IPCOMP_OUI
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_IPCOMP_DEFLATE
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_IPCOMP_LZS
value|3
end_define

begin_comment
comment|/* 4.5 IPSEC Security Association Attributes */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LTYPE
value|1
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LTYPE_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LTYPE_SEC
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LTYPE_KB
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LDUR
value|2
end_define

begin_comment
comment|/* V */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_SA_LDUR_DEFAULT
value|28800
end_define

begin_comment
comment|/* 8 hours */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_GRP_DESC
value|3
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_ENC_MODE
value|4
end_define

begin_comment
comment|/* B */
end_comment

begin_comment
comment|/* default value: host dependent */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_ENC_MODE_TUNNEL
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_ENC_MODE_TRNS
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_AUTH
value|5
end_define

begin_comment
comment|/* B */
end_comment

begin_comment
comment|/* 0 means not to use authentication. */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_AUTH_HMAC_MD5
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_AUTH_HMAC_SHA1
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_AUTH_DES_MAC
value|3
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_AUTH_KPDK
value|4
end_define

begin_comment
comment|/*RFC-1826(Key/Pad/Data/Key)*/
end_comment

begin_comment
comment|/* 	 * When negotiating ESP without authentication, the Auth 	 * Algorithm attribute MUST NOT be included in the proposal. 	 * When negotiating ESP without confidentiality, the Auth 	 * Algorithm attribute MUST be included in the proposal and 	 * the ESP transform ID must be ESP_NULL. 	*/
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_KEY_LENGTH
value|6
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_KEY_ROUNDS
value|7
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_COMP_DICT_SIZE
value|8
end_define

begin_comment
comment|/* B */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_ATTR_COMP_PRIVALG
value|9
end_define

begin_comment
comment|/* V */
end_comment

begin_comment
comment|/* 4.6.1 Security Association Payload */
end_comment

begin_struct
struct|struct
name|ipsecdoi_sa
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int32_t
name|doi
decl_stmt|;
comment|/* Domain of Interpretation */
name|u_int32_t
name|sit
decl_stmt|;
comment|/* Situation */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipsecdoi_secrecy_h
block|{
name|u_int16_t
name|len
decl_stmt|;
name|u_int16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 4.6.2.1 Identification Type Values */
end_comment

begin_struct
struct|struct
name|ipsecdoi_id
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
comment|/* ID Type */
name|u_int8_t
name|proto_id
decl_stmt|;
comment|/* Protocol ID */
name|u_int16_t
name|port
decl_stmt|;
comment|/* Port */
comment|/* Identification Data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV4_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_FQDN
value|2
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_USER_FQDN
value|3
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV4_ADDR_SUBNET
value|4
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV6_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV6_ADDR_SUBNET
value|6
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV4_ADDR_RANGE
value|7
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_IPV6_ADDR_RANGE
value|8
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_DER_ASN1_DN
value|9
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_DER_ASN1_GN
value|10
end_define

begin_define
define|#
directive|define
name|IPSECDOI_ID_KEY_ID
value|11
end_define

begin_comment
comment|/* 4.6.3 IPSEC DOI Notify Message Types */
end_comment

begin_comment
comment|/* Notify Messages - Status Types */
end_comment

begin_define
define|#
directive|define
name|IPSECDOI_NTYPE_RESPONDER_LIFETIME
value|24576
end_define

begin_define
define|#
directive|define
name|IPSECDOI_NTYPE_REPLAY_STATUS
value|24577
end_define

begin_define
define|#
directive|define
name|IPSECDOI_NTYPE_INITIAL_CONTACT
value|24578
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_IPSEC_DOI_H_) */
end_comment

end_unit

