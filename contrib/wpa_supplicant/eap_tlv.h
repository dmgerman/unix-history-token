begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / EAP-TLV (draft-josefsson-pppext-eap-tls-eap-07.txt)  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_TLV_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_TLV_H
end_define

begin_comment
comment|/* EAP-TLV TLVs (draft-josefsson-ppext-eap-tls-eap-07.txt) */
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
name|EAP_TLV_CRYPTO_BINDING_TLV
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
comment|/* draft-cam-winget-eap-fast-01.txt */
end_comment

begin_define
define|#
directive|define
name|EAP_TLV_CRYPTO_BINDING_TLV_
value|12
end_define

begin_comment
comment|/* draft-cam-winget-eap-fast-01.txt */
end_comment

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

begin_struct
struct|struct
name|eap_tlv_hdr
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_nak_tlv
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u32
name|vendor_id
decl_stmt|;
name|u16
name|nak_type
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_result_tlv
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u16
name|status
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_intermediate_result_tlv
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u16
name|status
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_crypto_binding__tlv
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
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
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|eap_tlv_pac_ack_tlv
block|{
name|u16
name|tlv_type
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u16
name|pac_type
decl_stmt|;
name|u16
name|pac_len
decl_stmt|;
name|u16
name|result
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

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

begin_function_decl
name|u8
modifier|*
name|eap_tlv_build_nak
parameter_list|(
name|int
name|id
parameter_list|,
name|u16
name|nak_type
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_tlv_build_result
parameter_list|(
name|int
name|id
parameter_list|,
name|u16
name|status
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_tlv_process
parameter_list|(
name|struct
name|eap_sm
modifier|*
name|sm
parameter_list|,
name|struct
name|eap_method_ret
modifier|*
name|ret
parameter_list|,
specifier|const
name|struct
name|eap_hdr
modifier|*
name|hdr
parameter_list|,
name|u8
modifier|*
modifier|*
name|resp
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_TLV_H */
end_comment

end_unit

