begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wi-Fi Protected Setup - attribute parsing  * Copyright (c) 2008-2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPS_ATTR_PARSE_H
end_ifndef

begin_define
define|#
directive|define
name|WPS_ATTR_PARSE_H
end_define

begin_include
include|#
directive|include
file|"wps.h"
end_include

begin_struct
struct|struct
name|wps_parse_attr
block|{
comment|/* fixed length fields */
specifier|const
name|u8
modifier|*
name|version
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|version2
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|msg_type
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|enrollee_nonce
decl_stmt|;
comment|/* WPS_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|registrar_nonce
decl_stmt|;
comment|/* WPS_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|uuid_r
decl_stmt|;
comment|/* WPS_UUID_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|uuid_e
decl_stmt|;
comment|/* WPS_UUID_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|auth_type_flags
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|encr_type_flags
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|conn_type_flags
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|config_methods
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|sel_reg_config_methods
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|primary_dev_type
decl_stmt|;
comment|/* 8 octets */
specifier|const
name|u8
modifier|*
name|rf_bands
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|assoc_state
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|config_error
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|dev_password_id
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|os_version
decl_stmt|;
comment|/* 4 octets */
specifier|const
name|u8
modifier|*
name|wps_state
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|authenticator
decl_stmt|;
comment|/* WPS_AUTHENTICATOR_LEN (8) octets */
specifier|const
name|u8
modifier|*
name|r_hash1
decl_stmt|;
comment|/* WPS_HASH_LEN (32) octets */
specifier|const
name|u8
modifier|*
name|r_hash2
decl_stmt|;
comment|/* WPS_HASH_LEN (32) octets */
specifier|const
name|u8
modifier|*
name|e_hash1
decl_stmt|;
comment|/* WPS_HASH_LEN (32) octets */
specifier|const
name|u8
modifier|*
name|e_hash2
decl_stmt|;
comment|/* WPS_HASH_LEN (32) octets */
specifier|const
name|u8
modifier|*
name|r_snonce1
decl_stmt|;
comment|/* WPS_SECRET_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|r_snonce2
decl_stmt|;
comment|/* WPS_SECRET_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|e_snonce1
decl_stmt|;
comment|/* WPS_SECRET_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|e_snonce2
decl_stmt|;
comment|/* WPS_SECRET_NONCE_LEN (16) octets */
specifier|const
name|u8
modifier|*
name|key_wrap_auth
decl_stmt|;
comment|/* WPS_KWA_LEN (8) octets */
specifier|const
name|u8
modifier|*
name|auth_type
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|encr_type
decl_stmt|;
comment|/* 2 octets */
specifier|const
name|u8
modifier|*
name|network_idx
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|network_key_idx
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|mac_addr
decl_stmt|;
comment|/* ETH_ALEN (6) octets */
specifier|const
name|u8
modifier|*
name|key_prov_auto
decl_stmt|;
comment|/* 1 octet (Bool) */
specifier|const
name|u8
modifier|*
name|dot1x_enabled
decl_stmt|;
comment|/* 1 octet (Bool) */
specifier|const
name|u8
modifier|*
name|selected_registrar
decl_stmt|;
comment|/* 1 octet (Bool) */
specifier|const
name|u8
modifier|*
name|request_type
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|response_type
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|ap_setup_locked
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|settings_delay_time
decl_stmt|;
comment|/* 1 octet */
specifier|const
name|u8
modifier|*
name|network_key_shareable
decl_stmt|;
comment|/* 1 octet (Bool) */
specifier|const
name|u8
modifier|*
name|request_to_enroll
decl_stmt|;
comment|/* 1 octet (Bool) */
specifier|const
name|u8
modifier|*
name|ap_channel
decl_stmt|;
comment|/* 2 octets */
comment|/* variable length fields */
specifier|const
name|u8
modifier|*
name|manufacturer
decl_stmt|;
name|size_t
name|manufacturer_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|model_name
decl_stmt|;
name|size_t
name|model_name_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|model_number
decl_stmt|;
name|size_t
name|model_number_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|serial_number
decl_stmt|;
name|size_t
name|serial_number_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|dev_name
decl_stmt|;
name|size_t
name|dev_name_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|public_key
decl_stmt|;
name|size_t
name|public_key_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|encr_settings
decl_stmt|;
name|size_t
name|encr_settings_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/*<= 32 octets */
name|size_t
name|ssid_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|network_key
decl_stmt|;
comment|/*<= 64 octets */
name|size_t
name|network_key_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|eap_type
decl_stmt|;
comment|/*<= 8 octets */
name|size_t
name|eap_type_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|eap_identity
decl_stmt|;
comment|/*<= 64 octets */
name|size_t
name|eap_identity_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|authorized_macs
decl_stmt|;
comment|/*<= 30 octets */
name|size_t
name|authorized_macs_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|sec_dev_type_list
decl_stmt|;
comment|/*<= 128 octets */
name|size_t
name|sec_dev_type_list_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|oob_dev_password
decl_stmt|;
comment|/* 38..54 octets */
name|size_t
name|oob_dev_password_len
decl_stmt|;
comment|/* attributes that can occur multiple times */
define|#
directive|define
name|MAX_CRED_COUNT
value|10
specifier|const
name|u8
modifier|*
name|cred
index|[
name|MAX_CRED_COUNT
index|]
decl_stmt|;
name|size_t
name|cred_len
index|[
name|MAX_CRED_COUNT
index|]
decl_stmt|;
name|size_t
name|num_cred
decl_stmt|;
define|#
directive|define
name|MAX_REQ_DEV_TYPE_COUNT
value|10
specifier|const
name|u8
modifier|*
name|req_dev_type
index|[
name|MAX_REQ_DEV_TYPE_COUNT
index|]
decl_stmt|;
name|size_t
name|num_req_dev_type
decl_stmt|;
specifier|const
name|u8
modifier|*
name|vendor_ext
index|[
name|MAX_WPS_PARSE_VENDOR_EXT
index|]
decl_stmt|;
name|size_t
name|vendor_ext_len
index|[
name|MAX_WPS_PARSE_VENDOR_EXT
index|]
decl_stmt|;
name|size_t
name|num_vendor_ext
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|wps_parse_msg
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|,
name|struct
name|wps_parse_attr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPS_ATTR_PARSE_H */
end_comment

end_unit

