begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* YIPS @(#)$Id: isakmp.h,v 1.7 2000/10/03 05:16:38 itojun Exp $ */
end_comment

begin_comment
comment|/* refer to RFC 2408 */
end_comment

begin_comment
comment|/* must include<netinet/in.h> */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ISAKMP_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ISAKMP_H_
end_define

begin_typedef
typedef|typedef
name|u_char
name|cookie_t
index|[
literal|8
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|msgid_t
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* i_cookie + r_cookie */
name|cookie_t
name|i_ck
decl_stmt|;
name|cookie_t
name|r_ck
decl_stmt|;
block|}
name|isakmp_index
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INITIATOR
value|1
end_define

begin_define
define|#
directive|define
name|RESPONDER
value|2
end_define

begin_define
define|#
directive|define
name|PORT_ISAKMP
value|500
end_define

begin_define
define|#
directive|define
name|GENERATE
value|1
end_define

begin_define
define|#
directive|define
name|VALIDATE
value|0
end_define

begin_comment
comment|/* Phase of oakley definition */
end_comment

begin_comment
comment|/*   0000 0000 0000 0000        |    |||| ||||        |    |||| ++++--> negosiation number in phase        |    ++++-------> phase number        +---------------> expire ?  */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_PH1
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH2
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISAKMP_EXPIRED
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISAKMP_NGP_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISAKMP_NGP_1
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISAKMP_NGP_2
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISAKMP_NGP_3
value|0x0003
end_define

begin_define
define|#
directive|define
name|ISAKMP_NGP_4
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH1_N
value|(ISAKMP_PH1 | ISAKMP_NGP_0)
end_define

begin_comment
comment|/* i.e. spawn */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_PH1_1
value|(ISAKMP_PH1 | ISAKMP_NGP_1)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH1_2
value|(ISAKMP_PH1 | ISAKMP_NGP_2)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH1_3
value|(ISAKMP_PH1 | ISAKMP_NGP_3)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH2_N
value|(ISAKMP_PH2 | ISAKMP_NGP_0)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH2_1
value|(ISAKMP_PH2 | ISAKMP_NGP_1)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH2_2
value|(ISAKMP_PH2 | ISAKMP_NGP_2)
end_define

begin_define
define|#
directive|define
name|ISAKMP_PH2_3
value|(ISAKMP_PH2 | ISAKMP_NGP_3)
end_define

begin_define
define|#
directive|define
name|ISAKMP_TIMER_DEFAULT
value|10
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_TRY_DEFAULT
value|3
end_define

begin_comment
comment|/* times */
end_comment

begin_comment
comment|/* 3.1 ISAKMP Header Format          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !                          Initiator                            !         !                            Cookie                             !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !                          Responder                            !         !                            Cookie                             !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !  Next Payload ! MjVer ! MnVer ! Exchange Type !     Flags     !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !                          Message ID                           !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !                            Length                             !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|isakmp
block|{
name|cookie_t
name|i_ck
decl_stmt|;
comment|/* Initiator Cookie */
name|cookie_t
name|r_ck
decl_stmt|;
comment|/* Responder Cookie */
name|u_int8_t
name|np
decl_stmt|;
comment|/* Next Payload Type */
name|u_int8_t
name|vers
decl_stmt|;
define|#
directive|define
name|ISAKMP_VERS_MAJOR
value|0xf0
define|#
directive|define
name|ISAKMP_VERS_MAJOR_SHIFT
value|4
define|#
directive|define
name|ISAKMP_VERS_MINOR
value|0x0f
define|#
directive|define
name|ISAKMP_VERS_MINOR_SHIFT
value|0
name|u_int8_t
name|etype
decl_stmt|;
comment|/* Exchange Type */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* Flags */
name|msgid_t
name|msgid
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
comment|/* Length */
block|}
struct|;
end_struct

begin_comment
comment|/* Next Payload Type */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_NONE
value|0
end_define

begin_comment
comment|/* NONE*/
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_SA
value|1
end_define

begin_comment
comment|/* Security Association */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_P
value|2
end_define

begin_comment
comment|/* Proposal */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_T
value|3
end_define

begin_comment
comment|/* Transform */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_KE
value|4
end_define

begin_comment
comment|/* Key Exchange */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_ID
value|5
end_define

begin_comment
comment|/* Identification */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_CERT
value|6
end_define

begin_comment
comment|/* Certificate */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_CR
value|7
end_define

begin_comment
comment|/* Certificate Request */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_HASH
value|8
end_define

begin_comment
comment|/* Hash */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_SIG
value|9
end_define

begin_comment
comment|/* Signature */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_NONCE
value|10
end_define

begin_comment
comment|/* Nonce */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_N
value|11
end_define

begin_comment
comment|/* Notification */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_D
value|12
end_define

begin_comment
comment|/* Delete */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NPTYPE_VID
value|13
end_define

begin_comment
comment|/* Vendor ID */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|ISAKMP_MINOR_VERSION
value|0
end_define

begin_comment
comment|/* Exchange Type */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_NONE
value|0
end_define

begin_comment
comment|/* NONE */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_BASE
value|1
end_define

begin_comment
comment|/* Base */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_IDENT
value|2
end_define

begin_comment
comment|/* Identity Proteciton */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_AUTH
value|3
end_define

begin_comment
comment|/* Authentication Only */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_AGG
value|4
end_define

begin_comment
comment|/* Aggressive */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_ETYPE_INF
value|5
end_define

begin_comment
comment|/* Informational */
end_comment

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_FLAG_E
value|0x01
end_define

begin_comment
comment|/* Encryption Bit */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_FLAG_C
value|0x02
end_define

begin_comment
comment|/* Commit Bit */
end_comment

begin_comment
comment|/* 3.2 Payload Generic Header          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         ! Next Payload  !   RESERVED    !         Payload Length        !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|isakmp_gen
block|{
name|u_int8_t
name|np
decl_stmt|;
comment|/* Next Payload */
name|u_int8_t
name|reserved
decl_stmt|;
comment|/* RESERVED, unused, must set to 0 */
name|u_int16_t
name|len
decl_stmt|;
comment|/* Payload Length */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.3 Data Attributes          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         !A!       Attribute Type        !    AF=0  Attribute Length     !         !F!                             !    AF=1  Attribute Value      !         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+         .                   AF=0  Attribute Value                       .         .                   AF=1  Not Transmitted                       .         +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|isakmp_data
block|{
name|u_int16_t
name|type
decl_stmt|;
comment|/* defined by DOI-spec, and Attribute Format */
name|u_int16_t
name|lorv
decl_stmt|;
comment|/* if f equal 1, Attribute Length */
comment|/* if f equal 0, Attribute Value */
comment|/* if f equal 1, Attribute Value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISAKMP_GEN_TLV
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISAKMP_GEN_TV
value|0x8000
end_define

begin_comment
comment|/* mask for type of attribute format */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_GEN_MASK
value|0x8000
end_define

begin_comment
comment|/* 3.4 Security Association Payload */
end_comment

begin_comment
comment|/* MAY NOT be used, because of being defined in ipsec-doi. */
end_comment

begin_comment
comment|/* 	If the current payload is the last in the message, 	then the value of the next payload field will be 0. 	This field MUST NOT contain the 	values for the Proposal or Transform payloads as they are considered 	part of the security association negotiation.  For example, this 	field would contain the value "10" (Nonce payload) in the first 	message of a Base Exchange (see Section 4.4) and the value "0" in the 	first message of an Identity Protect Exchange (see Section 4.5). 	*/
end_comment

begin_struct
struct|struct
name|isakmp_pl_sa
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

begin_comment
comment|/* 3.5 Proposal Payload */
end_comment

begin_comment
comment|/* 	The value of the next payload field MUST only contain the value "2" 	or "0".  If there are additional Proposal payloads in the message, 	then this field will be 2.  If the current Proposal payload is the 	last within the security association proposal, then this field will 	be 0. 	*/
end_comment

begin_struct
struct|struct
name|isakmp_pl_p
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int8_t
name|p_no
decl_stmt|;
comment|/* Proposal # */
name|u_int8_t
name|prot_id
decl_stmt|;
comment|/* Protocol */
name|u_int8_t
name|spi_size
decl_stmt|;
comment|/* SPI Size */
name|u_int8_t
name|num_t
decl_stmt|;
comment|/* Number of Transforms */
comment|/* SPI */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.6 Transform Payload */
end_comment

begin_comment
comment|/* 	The value of the next payload field MUST only contain the value "3" 	or "0".  If there are additional Transform payloads in the proposal, 	then this field will be 3.  If the current Transform payload is the 	last within the proposal, then this field will be 0. 	*/
end_comment

begin_struct
struct|struct
name|isakmp_pl_t
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int8_t
name|t_no
decl_stmt|;
comment|/* Transform # */
name|u_int8_t
name|t_id
decl_stmt|;
comment|/* Transform-Id */
name|u_int16_t
name|reserved
decl_stmt|;
comment|/* RESERVED2 */
comment|/* SA Attributes */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.7 Key Exchange Payload */
end_comment

begin_struct
struct|struct
name|isakmp_pl_ke
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
comment|/* Key Exchange Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.8 Identification Payload */
end_comment

begin_comment
comment|/* MUST NOT to be used, because of being defined in ipsec-doi. */
end_comment

begin_struct
struct|struct
name|isakmp_pl_id
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
union|union
block|{
name|u_int8_t
name|id_type
decl_stmt|;
comment|/* ID Type */
name|u_int32_t
name|doi_data
decl_stmt|;
comment|/* DOI Specific ID Data */
block|}
name|d
union|;
comment|/* Identification Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.9 Certificate Payload */
end_comment

begin_struct
struct|struct
name|isakmp_pl_cert
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int8_t
name|encode
decl_stmt|;
comment|/* Cert Encoding */
name|char
name|cert
decl_stmt|;
comment|/* Certificate Data */
comment|/* 		This field indicates the type of 		certificate or certificate-related information contained in the 		Certificate Data field. 		*/
block|}
struct|;
end_struct

begin_comment
comment|/* Certificate Type */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_CERT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_PKCS
value|1
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_PGP
value|2
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_DNS
value|3
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_SIGN
value|4
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_KE
value|5
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_KT
value|6
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_CRL
value|7
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_ARL
value|8
end_define

begin_define
define|#
directive|define
name|ISAKMP_CERT_SPKI
value|9
end_define

begin_comment
comment|/* 3.10 Certificate Request Payload */
end_comment

begin_struct
struct|struct
name|isakmp_pl_cr
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int8_t
name|num_cert
decl_stmt|;
comment|/* # Cert. Types */
comment|/* 	Certificate Types (variable length) 	  -- Contains a list of the types of certificates requested, 	  sorted in order of preference.  Each individual certificate 	  type is 1 octet.  This field is NOT requiredo 	*/
comment|/* # Certificate Authorities (1 octet) */
comment|/* Certificate Authorities (variable length) */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.11 Hash Payload */
end_comment

begin_comment
comment|/* may not be used, because of having only data. */
end_comment

begin_struct
struct|struct
name|isakmp_pl_hash
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
comment|/* Hash Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.12 Signature Payload */
end_comment

begin_comment
comment|/* may not be used, because of having only data. */
end_comment

begin_struct
struct|struct
name|isakmp_pl_sig
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
comment|/* Signature Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.13 Nonce Payload */
end_comment

begin_comment
comment|/* may not be used, because of having only data. */
end_comment

begin_struct
struct|struct
name|isakmp_pl_nonce
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
comment|/* Nonce Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.14 Notification Payload */
end_comment

begin_struct
struct|struct
name|isakmp_pl_n
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int32_t
name|doi
decl_stmt|;
comment|/* Domain of Interpretation */
name|u_int8_t
name|prot_id
decl_stmt|;
comment|/* Protocol-ID */
name|u_int8_t
name|spi_size
decl_stmt|;
comment|/* SPI Size */
name|u_int16_t
name|type
decl_stmt|;
comment|/* Notify Message Type */
comment|/* SPI */
comment|/* Notification Data */
block|}
struct|;
end_struct

begin_comment
comment|/* 3.14.1 Notify Message Types */
end_comment

begin_comment
comment|/* NOTIFY MESSAGES - ERROR TYPES */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_PAYLOAD_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_DOI_NOT_SUPPORTED
value|2
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_SITUATION_NOT_SUPPORTED
value|3
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_COOKIE
value|4
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_MAJOR_VERSION
value|5
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_MINOR_VERSION
value|6
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_EXCHANGE_TYPE
value|7
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_FLAGS
value|8
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_MESSAGE_ID
value|9
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_PROTOCOL_ID
value|10
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_SPI
value|11
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_TRANSFORM_ID
value|12
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_ATTRIBUTES_NOT_SUPPORTED
value|13
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_NO_PROPOSAL_CHOSEN
value|14
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_BAD_PROPOSAL_SYNTAX
value|15
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_PAYLOAD_MALFORMED
value|16
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_KEY_INFORMATION
value|17
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_ID_INFORMATION
value|18
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_CERT_ENCODING
value|19
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_CERTIFICATE
value|20
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_BAD_CERT_REQUEST_SYNTAX
value|21
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_CERT_AUTHORITY
value|22
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_HASH_INFORMATION
value|23
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_AUTHENTICATION_FAILED
value|24
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_INVALID_SIGNATURE
value|25
end_define

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_ADDRESS_NOTIFICATION
value|26
end_define

begin_comment
comment|/* NOTIFY MESSAGES - STATUS TYPES */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_NTYPE_CONNECTED
value|16384
end_define

begin_comment
comment|/* using only to log */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_LOG_RETRY_LIMIT_REACHED
value|65530
end_define

begin_comment
comment|/* 3.15 Delete Payload */
end_comment

begin_struct
struct|struct
name|isakmp_pl_d
block|{
name|struct
name|isakmp_gen
name|h
decl_stmt|;
name|u_int32_t
name|doi
decl_stmt|;
comment|/* Domain of Interpretation */
name|u_int8_t
name|prot_id
decl_stmt|;
comment|/* Protocol-Id */
name|u_int8_t
name|spi_size
decl_stmt|;
comment|/* SPI Size */
name|u_int16_t
name|num_spi
decl_stmt|;
comment|/* # of SPIs */
comment|/* SPI(es) */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_struct
struct|struct
name|isakmp_ph1tab
block|{
name|struct
name|isakmp_ph1
modifier|*
name|head
decl_stmt|;
name|struct
name|isakmp_ph1
modifier|*
name|tail
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isakmp_ph2tab
block|{
name|struct
name|isakmp_ph2
modifier|*
name|head
decl_stmt|;
name|struct
name|isakmp_ph2
modifier|*
name|tail
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXCHANGE_PROXY
value|1
end_define

begin_define
define|#
directive|define
name|EXCHANGE_MYSELF
value|0
end_define

begin_define
define|#
directive|define
name|PFS_NEED
value|1
end_define

begin_define
define|#
directive|define
name|PFS_NONEED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_ISAKMP_H_) */
end_comment

end_unit

