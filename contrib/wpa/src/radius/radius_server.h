begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RADIUS authentication server  * Copyright (c) 2005-2009, 2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_SERVER_H
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_SERVER_H
end_define

begin_struct_decl
struct_decl|struct
name|radius_server_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eap_user
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct radius_server_conf - RADIUS server configuration  */
end_comment

begin_struct
struct|struct
name|radius_server_conf
block|{
comment|/** 	 * auth_port - UDP port to listen to as an authentication server 	 */
name|int
name|auth_port
decl_stmt|;
comment|/** 	 * client_file - RADIUS client configuration file 	 * 	 * This file contains the RADIUS clients and the shared secret to be 	 * used with them in a format where each client is on its own line. The 	 * first item on the line is the IPv4 or IPv6 address of the client 	 * with an optional address mask to allow full network to be specified 	 * (e.g., 192.168.1.2 or 192.168.1.0/24). This is followed by white 	 * space (space or tabulator) and the shared secret. Lines starting 	 * with '#' are skipped and can be used as comments. 	 */
name|char
modifier|*
name|client_file
decl_stmt|;
comment|/** 	 * conf_ctx - Context pointer for callbacks 	 * 	 * This is used as the ctx argument in get_eap_user() calls. 	 */
name|void
modifier|*
name|conf_ctx
decl_stmt|;
comment|/** 	 * eap_sim_db_priv - EAP-SIM/AKA database context 	 * 	 * This is passed to the EAP-SIM/AKA server implementation as a 	 * callback context. 	 */
name|void
modifier|*
name|eap_sim_db_priv
decl_stmt|;
comment|/** 	 * ssl_ctx - TLS context 	 * 	 * This is passed to the EAP server implementation as a callback 	 * context for TLS operations. 	 */
name|void
modifier|*
name|ssl_ctx
decl_stmt|;
comment|/** 	 * pac_opaque_encr_key - PAC-Opaque encryption key for EAP-FAST 	 * 	 * This parameter is used to set a key for EAP-FAST to encrypt the 	 * PAC-Opaque data. It can be set to %NULL if EAP-FAST is not used. If 	 * set, must point to a 16-octet key. 	 */
name|u8
modifier|*
name|pac_opaque_encr_key
decl_stmt|;
comment|/** 	 * eap_fast_a_id - EAP-FAST authority identity (A-ID) 	 * 	 * If EAP-FAST is not used, this can be set to %NULL. In theory, this 	 * is a variable length field, but due to some existing implementations 	 * requiring A-ID to be 16 octets in length, it is recommended to use 	 * that length for the field to provide interoperability with deployed 	 * peer implementations. 	 */
name|u8
modifier|*
name|eap_fast_a_id
decl_stmt|;
comment|/** 	 * eap_fast_a_id_len - Length of eap_fast_a_id buffer in octets 	 */
name|size_t
name|eap_fast_a_id_len
decl_stmt|;
comment|/** 	 * eap_fast_a_id_info - EAP-FAST authority identifier information 	 * 	 * This A-ID-Info contains a user-friendly name for the A-ID. For 	 * example, this could be the enterprise and server names in 	 * human-readable format. This field is encoded as UTF-8. If EAP-FAST 	 * is not used, this can be set to %NULL. 	 */
name|char
modifier|*
name|eap_fast_a_id_info
decl_stmt|;
comment|/** 	 * eap_fast_prov - EAP-FAST provisioning modes 	 * 	 * 0 = provisioning disabled, 1 = only anonymous provisioning allowed, 	 * 2 = only authenticated provisioning allowed, 3 = both provisioning 	 * modes allowed. 	 */
name|int
name|eap_fast_prov
decl_stmt|;
comment|/** 	 * pac_key_lifetime - EAP-FAST PAC-Key lifetime in seconds 	 * 	 * This is the hard limit on how long a provisioned PAC-Key can be 	 * used. 	 */
name|int
name|pac_key_lifetime
decl_stmt|;
comment|/** 	 * pac_key_refresh_time - EAP-FAST PAC-Key refresh time in seconds 	 * 	 * This is a soft limit on the PAC-Key. The server will automatically 	 * generate a new PAC-Key when this number of seconds (or fewer) of the 	 * lifetime remains. 	 */
name|int
name|pac_key_refresh_time
decl_stmt|;
comment|/** 	 * eap_sim_aka_result_ind - EAP-SIM/AKA protected success indication 	 * 	 * This controls whether the protected success/failure indication 	 * (AT_RESULT_IND) is used with EAP-SIM and EAP-AKA. 	 */
name|int
name|eap_sim_aka_result_ind
decl_stmt|;
comment|/** 	 * tnc - Trusted Network Connect (TNC) 	 * 	 * This controls whether TNC is enabled and will be required before the 	 * peer is allowed to connect. Note: This is only used with EAP-TTLS 	 * and EAP-FAST. If any other EAP method is enabled, the peer will be 	 * allowed to connect without TNC. 	 */
name|int
name|tnc
decl_stmt|;
comment|/** 	 * pwd_group - EAP-pwd D-H group 	 * 	 * This is used to select which D-H group to use with EAP-pwd. 	 */
name|u16
name|pwd_group
decl_stmt|;
comment|/** 	 * wps - Wi-Fi Protected Setup context 	 * 	 * If WPS is used with an external RADIUS server (which is quite 	 * unlikely configuration), this is used to provide a pointer to WPS 	 * context data. Normally, this can be set to %NULL. 	 */
name|struct
name|wps_context
modifier|*
name|wps
decl_stmt|;
comment|/** 	 * ipv6 - Whether to enable IPv6 support in the RADIUS server 	 */
name|int
name|ipv6
decl_stmt|;
comment|/** 	 * get_eap_user - Callback for fetching EAP user information 	 * @ctx: Context data from conf_ctx 	 * @identity: User identity 	 * @identity_len: identity buffer length in octets 	 * @phase2: Whether this is for Phase 2 identity 	 * @user: Data structure for filling in the user information 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is used to fetch information from user database. The callback 	 * will fill in information about allowed EAP methods and the user 	 * password. The password field will be an allocated copy of the 	 * password data and RADIUS server will free it after use. 	 */
name|int
function_decl|(
modifier|*
name|get_eap_user
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|identity
parameter_list|,
name|size_t
name|identity_len
parameter_list|,
name|int
name|phase2
parameter_list|,
name|struct
name|eap_user
modifier|*
name|user
parameter_list|)
function_decl|;
comment|/** 	 * eap_req_id_text - Optional data for EAP-Request/Identity 	 * 	 * This can be used to configure an optional, displayable message that 	 * will be sent in EAP-Request/Identity. This string can contain an 	 * ASCII-0 character (nul) to separate network infromation per RFC 	 * 4284. The actual string length is explicit provided in 	 * eap_req_id_text_len since nul character will not be used as a string 	 * terminator. 	 */
specifier|const
name|char
modifier|*
name|eap_req_id_text
decl_stmt|;
comment|/** 	 * eap_req_id_text_len - Length of eap_req_id_text buffer in octets 	 */
name|size_t
name|eap_req_id_text_len
decl_stmt|;
comment|/* 	 * msg_ctx - Context data for wpa_msg() calls 	 */
name|void
modifier|*
name|msg_ctx
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_RADIUS_TEST
specifier|const
name|char
modifier|*
name|dump_msk_file
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_RADIUS_TEST */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|radius_server_data
modifier|*
name|radius_server_init
parameter_list|(
name|struct
name|radius_server_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_server_deinit
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radius_server_get_mib
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|radius_server_eap_pending_cb
parameter_list|(
name|struct
name|radius_server_data
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RADIUS_SERVER_H */
end_comment

end_unit

