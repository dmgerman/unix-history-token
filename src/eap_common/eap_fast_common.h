begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-FAST definitions (RFC 4851)  * Copyright (c) 2004-2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_FAST_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_FAST_H
end_define

begin_define
define|#
directive|define
name|EAP_FAST_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|EAP_FAST_KEY_LEN
value|64
end_define

begin_define
define|#
directive|define
name|EAP_FAST_SIMCK_LEN
value|40
end_define

begin_define
define|#
directive|define
name|EAP_FAST_SKS_LEN
value|40
end_define

begin_define
define|#
directive|define
name|EAP_FAST_CMK_LEN
value|20
end_define

begin_define
define|#
directive|define
name|TLS_EXT_PAC_OPAQUE
value|35
end_define

begin_comment
comment|/*  * RFC 5422: Section 4.2.1 - Formats for PAC TLV Attributes / Type Field  * Note: bit 0x8000 (Mandatory) and bit 0x4000 (Reserved) are also defined  * in the general PAC TLV format (Section 4.2).  */
end_comment

begin_define
define|#
directive|define
name|PAC_TYPE_PAC_KEY
value|1
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_PAC_OPAQUE
value|2
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_CRED_LIFETIME
value|3
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_A_ID
value|4
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_I_ID
value|5
end_define

begin_comment
comment|/*  * 6 was previous assigned for SERVER_PROTECTED_DATA, but  * draft-cam-winget-eap-fast-provisioning-02.txt changed this to Reserved.  */
end_comment

begin_define
define|#
directive|define
name|PAC_TYPE_A_ID_INFO
value|7
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_PAC_ACKNOWLEDGEMENT
value|8
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_PAC_INFO
value|9
end_define

begin_define
define|#
directive|define
name|PAC_TYPE_PAC_TYPE
value|10
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
name|pac_tlv_hdr
block|{
name|be16
name|type
decl_stmt|;
name|be16
name|len
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
name|EAP_FAST_PAC_KEY_LEN
value|32
end_define

begin_comment
comment|/* RFC 5422: 4.2.6 PAC-Type TLV */
end_comment

begin_define
define|#
directive|define
name|PAC_TYPE_TUNNEL_PAC
value|1
end_define

begin_comment
comment|/* Application Specific Short Lived PACs (only in volatile storage) */
end_comment

begin_comment
comment|/* User Authorization PAC */
end_comment

begin_define
define|#
directive|define
name|PAC_TYPE_USER_AUTHORIZATION
value|3
end_define

begin_comment
comment|/* Application Specific Long Lived PACs */
end_comment

begin_comment
comment|/* Machine Authentication PAC */
end_comment

begin_define
define|#
directive|define
name|PAC_TYPE_MACHINE_AUTHENTICATION
value|2
end_define

begin_comment
comment|/*  * RFC 5422:  * Section 3.3 - Key Derivations Used in the EAP-FAST Provisioning Exchange  */
end_comment

begin_struct
struct|struct
name|eap_fast_key_block_provisioning
block|{
comment|/* Extra key material after TLS key_block */
name|u8
name|session_key_seed
index|[
name|EAP_FAST_SKS_LEN
index|]
decl_stmt|;
name|u8
name|server_challenge
index|[
literal|16
index|]
decl_stmt|;
comment|/* MSCHAPv2 ServerChallenge */
name|u8
name|client_challenge
index|[
literal|16
index|]
decl_stmt|;
comment|/* MSCHAPv2 ClientChallenge */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|wpabuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tls_connection
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|eap_fast_tlv_parse
block|{
name|u8
modifier|*
name|eap_payload_tlv
decl_stmt|;
name|size_t
name|eap_payload_tlv_len
decl_stmt|;
name|struct
name|eap_tlv_crypto_binding_tlv
modifier|*
name|crypto_binding
decl_stmt|;
name|size_t
name|crypto_binding_len
decl_stmt|;
name|int
name|iresult
decl_stmt|;
name|int
name|result
decl_stmt|;
name|int
name|request_action
decl_stmt|;
name|u8
modifier|*
name|pac
decl_stmt|;
name|size_t
name|pac_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|eap_fast_put_tlv_hdr
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
name|u16
name|type
parameter_list|,
name|u16
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_fast_put_tlv
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
name|u16
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|u16
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_fast_put_tlv_buf
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|,
name|u16
name|type
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_fast_tlv_eap_payload
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_fast_derive_master_secret
parameter_list|(
specifier|const
name|u8
modifier|*
name|pac_key
parameter_list|,
specifier|const
name|u8
modifier|*
name|server_random
parameter_list|,
specifier|const
name|u8
modifier|*
name|client_random
parameter_list|,
name|u8
modifier|*
name|master_secret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|eap_fast_derive_key
parameter_list|(
name|void
modifier|*
name|ssl_ctx
parameter_list|,
name|struct
name|tls_connection
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_fast_derive_eap_msk
parameter_list|(
specifier|const
name|u8
modifier|*
name|simck
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_fast_derive_eap_emsk
parameter_list|(
specifier|const
name|u8
modifier|*
name|simck
parameter_list|,
name|u8
modifier|*
name|emsk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_fast_parse_tlv
parameter_list|(
name|struct
name|eap_fast_tlv_parse
modifier|*
name|tlv
parameter_list|,
name|int
name|tlv_type
parameter_list|,
name|u8
modifier|*
name|pos
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_FAST_H */
end_comment

end_unit

