begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server/peer: EAP-EKE shared routines  * Copyright (c) 2011-2013, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_EKE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_EKE_COMMON_H
end_define

begin_comment
comment|/* EKE Exchange */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_ID
value|1
end_define

begin_define
define|#
directive|define
name|EAP_EKE_COMMIT
value|2
end_define

begin_define
define|#
directive|define
name|EAP_EKE_CONFIRM
value|3
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAILURE
value|4
end_define

begin_comment
comment|/* Diffie-Hellman Group Registry */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_DHGROUP_EKE_2
value|1
end_define

begin_define
define|#
directive|define
name|EAP_EKE_DHGROUP_EKE_5
value|2
end_define

begin_define
define|#
directive|define
name|EAP_EKE_DHGROUP_EKE_14
value|3
end_define

begin_comment
comment|/* mandatory to implement */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_DHGROUP_EKE_15
value|4
end_define

begin_define
define|#
directive|define
name|EAP_EKE_DHGROUP_EKE_16
value|5
end_define

begin_comment
comment|/* Encryption Algorithm Registry */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_ENCR_AES128_CBC
value|1
end_define

begin_comment
comment|/* mandatory to implement */
end_comment

begin_comment
comment|/* Pseudo Random Function Registry */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_PRF_HMAC_SHA1
value|1
end_define

begin_comment
comment|/* mandatory to implement */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_PRF_HMAC_SHA2_256
value|2
end_define

begin_comment
comment|/* Keyed Message Digest (MAC) Registry */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_MAC_HMAC_SHA1
value|1
end_define

begin_comment
comment|/* mandatory to implement */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_MAC_HMAC_SHA2_256
value|2
end_define

begin_comment
comment|/* Identity Type Registry */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_ID_OPAQUE
value|1
end_define

begin_define
define|#
directive|define
name|EAP_EKE_ID_NAI
value|2
end_define

begin_define
define|#
directive|define
name|EAP_EKE_ID_IPv4
value|3
end_define

begin_define
define|#
directive|define
name|EAP_EKE_ID_IPv6
value|4
end_define

begin_define
define|#
directive|define
name|EAP_EKE_ID_FQDN
value|5
end_define

begin_define
define|#
directive|define
name|EAP_EKE_ID_DN
value|6
end_define

begin_comment
comment|/* Failure-Code */
end_comment

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_NO_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_PROTO_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_PASSWD_NOT_FOUND
value|3
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_AUTHENTICATION_FAIL
value|4
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_AUTHORIZATION_FAIL
value|5
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_NO_PROPOSAL_CHOSEN
value|6
end_define

begin_define
define|#
directive|define
name|EAP_EKE_FAIL_PRIVATE_INTERNAL_ERROR
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_DH_LEN
value|512
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_HASH_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_KEY_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_KE_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_KI_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_KA_LEN
value|32
end_define

begin_define
define|#
directive|define
name|EAP_EKE_MAX_NONCE_LEN
value|16
end_define

begin_struct
struct|struct
name|eap_eke_session
block|{
comment|/* Selected proposal */
name|u8
name|dhgroup
decl_stmt|;
name|u8
name|encr
decl_stmt|;
name|u8
name|prf
decl_stmt|;
name|u8
name|mac
decl_stmt|;
name|u8
name|shared_secret
index|[
name|EAP_EKE_MAX_HASH_LEN
index|]
decl_stmt|;
name|u8
name|ke
index|[
name|EAP_EKE_MAX_KE_LEN
index|]
decl_stmt|;
name|u8
name|ki
index|[
name|EAP_EKE_MAX_KI_LEN
index|]
decl_stmt|;
name|u8
name|ka
index|[
name|EAP_EKE_MAX_KA_LEN
index|]
decl_stmt|;
name|int
name|prf_len
decl_stmt|;
name|int
name|nonce_len
decl_stmt|;
name|int
name|auth_len
decl_stmt|;
name|int
name|dhcomp_len
decl_stmt|;
name|int
name|pnonce_len
decl_stmt|;
name|int
name|pnonce_ps_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|eap_eke_session_init
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
name|u8
name|dhgroup
parameter_list|,
name|u8
name|encr
parameter_list|,
name|u8
name|prf
parameter_list|,
name|u8
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_eke_session_clean
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_dh_init
parameter_list|(
name|u8
name|group
parameter_list|,
name|u8
modifier|*
name|ret_priv
parameter_list|,
name|u8
modifier|*
name|ret_pub
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_derive_key
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|password
parameter_list|,
name|size_t
name|password_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_s
parameter_list|,
name|size_t
name|id_s_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_p
parameter_list|,
name|size_t
name|id_p_len
parameter_list|,
name|u8
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_dhcomp
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|dhpub
parameter_list|,
name|u8
modifier|*
name|ret_dhcomp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_shared_secret
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|dhpriv
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_dhcomp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_derive_ke_ki
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_s
parameter_list|,
name|size_t
name|id_s_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_p
parameter_list|,
name|size_t
name|id_p_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_derive_ka
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_s
parameter_list|,
name|size_t
name|id_s_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_p
parameter_list|,
name|size_t
name|id_p_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce_p
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_derive_msk
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_s
parameter_list|,
name|size_t
name|id_s_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|id_p
parameter_list|,
name|size_t
name|id_p_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce_p
parameter_list|,
specifier|const
name|u8
modifier|*
name|nonce_s
parameter_list|,
name|u8
modifier|*
name|msk
parameter_list|,
name|u8
modifier|*
name|emsk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_prot
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|u8
modifier|*
name|prot
parameter_list|,
name|size_t
modifier|*
name|prot_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_decrypt_prot
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|u8
modifier|*
name|prot
parameter_list|,
name|size_t
name|prot_len
parameter_list|,
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_eke_auth
parameter_list|(
name|struct
name|eap_eke_session
modifier|*
name|sess
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|msgs
parameter_list|,
name|u8
modifier|*
name|auth
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_EKE_COMMON_H */
end_comment

end_unit

