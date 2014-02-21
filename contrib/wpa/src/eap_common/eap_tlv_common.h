begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-TLV definitions (draft-josefsson-pppext-eap-tls-eap-10.txt)  * Copyright (c) 2004-2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_TLV_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_TLV_COMMON_H
end_define

begin_comment
comment|/* EAP-TLV TLVs (draft-josefsson-ppext-eap-tls-eap-10.txt) */
end_comment

begin_define
define|#
directive|define
name|EAP_TLV_RESULT_TLV
value|3
end_define

begin_comment
comment|/* Acknowledged Result */
end_comment

begin_define
define|#
directive|define
name|EAP_TLV_NAK_TLV
value|4
end_define

begin_define
define|#
directive|define
name|EAP_TLV_ERROR_CODE_TLV
value|5
end_define

begin_define
define|#
directive|define
name|EAP_TLV_CONNECTION_BINDING_TLV
value|6
end_define

begin_define
define|#
directive|define
name|EAP_TLV_VENDOR_SPECIFIC_TLV
value|7
end_define

begin_define
define|#
directive|define
name|EAP_TLV_URI_TLV
value|8
end_define

begin_define
define|#
directive|define
name|EAP_TLV_EAP_PAYLOAD_TLV
value|9
end_define

begin_define
define|#
directive|define
name|EAP_TLV_INTERMEDIATE_RESULT_TLV
value|10
end_define

begin_define
define|#
directive|define
name|EAP_TLV_PAC_TLV
value|11
end_define

begin_comment
comment|/* RFC 5422, Section 4.2 */
end_comment

begin_define
define|#
directive|define
name|EAP_TLV_CRYPTO_BINDING_TLV
value|12
end_define

begin_define
define|#
directive|define
name|EAP_TLV_CALLING_STATION_ID_TLV
value|13
end_define

begin_define
define|#
directive|define
name|EAP_TLV_CALLED_STATION_ID_TLV
value|14
end_define

begin_define
define|#
directive|define
name|EAP_TLV_NAS_PORT_TYPE_TLV
value|15
end_define

begin_define
define|#
directive|define
name|EAP_TLV_SERVER_IDENTIFIER_TLV
value|16
end_define

begin_define
define|#
directive|define
name|EAP_TLV_IDENTITY_TYPE_TLV
value|17
end_define

begin_define
define|#
directive|define
name|EAP_TLV_SERVER_TRUSTED_ROOT_TLV
value|18
end_define

begin_define
define|#
directive|define
name|EAP_TLV_REQUEST_ACTION_TLV
value|19
end_define

begin_define
define|#
directive|define
name|EAP_TLV_PKCS7_TLV
value|20
end_define

begin_define
define|#
directive|define
name|EAP_TLV_RESULT_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|EAP_TLV_RESULT_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|EAP_TLV_TYPE_MANDATORY
value|0x8000
end_define

begin_define
define|#
directive|define
name|EAP_TLV_TYPE_MASK
value|0x3fff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_struct
struct|struct
name|eap_tlv_hdr
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_nak_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|be32
name|vendor_id
decl_stmt|;
name|be16
name|nak_type
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_result_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|be16
name|status
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* RFC 4851, Section 4.2.7 - Intermediate-Result TLV */
end_comment

begin_struct
struct|struct
name|eap_tlv_intermediate_result_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|be16
name|status
decl_stmt|;
comment|/* Followed by optional TLVs */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* RFC 4851, Section 4.2.8 - Crypto-Binding TLV */
end_comment

begin_struct
struct|struct
name|eap_tlv_crypto_binding_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|u8
name|version
decl_stmt|;
name|u8
name|received_version
decl_stmt|;
name|u8
name|subtype
decl_stmt|;
name|u8
name|nonce
index|[
literal|32
index|]
decl_stmt|;
name|u8
name|compound_mac
index|[
literal|20
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_pac_ack_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|be16
name|pac_type
decl_stmt|;
name|be16
name|pac_len
decl_stmt|;
name|be16
name|result
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* RFC 4851, Section 4.2.9 - Request-Action TLV */
end_comment

begin_struct
struct|struct
name|eap_tlv_request_action_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
name|be16
name|length
decl_stmt|;
name|be16
name|action
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* RFC 5422, Section 4.2.6 - PAC-Type TLV */
end_comment

begin_struct
struct|struct
name|eap_tlv_pac_type_tlv
block|{
name|be16
name|tlv_type
decl_stmt|;
comment|/* PAC_TYPE_PAC_TYPE */
name|be16
name|length
decl_stmt|;
name|be16
name|pac_type
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_define
define|#
directive|define
name|EAP_TLV_CRYPTO_BINDING_SUBTYPE_REQUEST
value|0
end_define

begin_define
define|#
directive|define
name|EAP_TLV_CRYPTO_BINDING_SUBTYPE_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|EAP_TLV_ACTION_PROCESS_TLV
value|1
end_define

begin_define
define|#
directive|define
name|EAP_TLV_ACTION_NEGOTIATE_EAP
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_TLV_COMMON_H */
end_comment

end_unit

