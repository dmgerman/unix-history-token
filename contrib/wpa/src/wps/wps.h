begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wi-Fi Protected Setup  * Copyright (c) 2007-2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPS_H
end_ifndef

begin_define
define|#
directive|define
name|WPS_H
end_define

begin_include
include|#
directive|include
file|"wps_defs.h"
end_include

begin_comment
comment|/**  * enum wsc_op_code - EAP-WSC OP-Code values  */
end_comment

begin_enum
enum|enum
name|wsc_op_code
block|{
name|WSC_UPnP
init|=
literal|0
comment|/* No OP Code in UPnP transport */
block|,
name|WSC_Start
init|=
literal|0x01
block|,
name|WSC_ACK
init|=
literal|0x02
block|,
name|WSC_NACK
init|=
literal|0x03
block|,
name|WSC_MSG
init|=
literal|0x04
block|,
name|WSC_Done
init|=
literal|0x05
block|,
name|WSC_FRAG_ACK
init|=
literal|0x06
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|wps_registrar
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|upnp_wps_device_sm
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct wps_credential - WPS Credential  * @ssid: SSID  * @ssid_len: Length of SSID  * @auth_type: Authentication Type (WPS_AUTH_OPEN, .. flags)  * @encr_type: Encryption Type (WPS_ENCR_NONE, .. flags)  * @key_idx: Key index  * @key: Key  * @key_len: Key length in octets  * @mac_addr: MAC address of the peer  * @cred_attr: Unparsed Credential attribute data (used only in cred_cb());  *	this may be %NULL, if not used  * @cred_attr_len: Length of cred_attr in octets  */
end_comment

begin_struct
struct|struct
name|wps_credential
block|{
name|u8
name|ssid
index|[
literal|32
index|]
decl_stmt|;
name|size_t
name|ssid_len
decl_stmt|;
name|u16
name|auth_type
decl_stmt|;
name|u16
name|encr_type
decl_stmt|;
name|u8
name|key_idx
decl_stmt|;
name|u8
name|key
index|[
literal|64
index|]
decl_stmt|;
name|size_t
name|key_len
decl_stmt|;
name|u8
name|mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
specifier|const
name|u8
modifier|*
name|cred_attr
decl_stmt|;
name|size_t
name|cred_attr_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wps_device_data - WPS Device Data  * @mac_addr: Device MAC address  * @device_name: Device Name (0..32 octets encoded in UTF-8)  * @manufacturer: Manufacturer (0..64 octets encoded in UTF-8)  * @model_name: Model Name (0..32 octets encoded in UTF-8)  * @model_number: Model Number (0..32 octets encoded in UTF-8)  * @serial_number: Serial Number (0..32 octets encoded in UTF-8)  * @categ: Primary Device Category  * @oui: Primary Device OUI  * @sub_categ: Primary Device Sub-Category  * @os_version: OS Version  * @rf_bands: RF bands (WPS_RF_24GHZ, WPS_RF_50GHZ flags)  */
end_comment

begin_struct
struct|struct
name|wps_device_data
block|{
name|u8
name|mac_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|char
modifier|*
name|device_name
decl_stmt|;
name|char
modifier|*
name|manufacturer
decl_stmt|;
name|char
modifier|*
name|model_name
decl_stmt|;
name|char
modifier|*
name|model_number
decl_stmt|;
name|char
modifier|*
name|serial_number
decl_stmt|;
name|u16
name|categ
decl_stmt|;
name|u32
name|oui
decl_stmt|;
name|u16
name|sub_categ
decl_stmt|;
name|u32
name|os_version
decl_stmt|;
name|u8
name|rf_bands
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wps_config - WPS configuration for a single registration protocol run  */
end_comment

begin_struct
struct|struct
name|wps_config
block|{
comment|/** 	 * wps - Pointer to long term WPS context 	 */
name|struct
name|wps_context
modifier|*
name|wps
decl_stmt|;
comment|/** 	 * registrar - Whether this end is a Registrar 	 */
name|int
name|registrar
decl_stmt|;
comment|/** 	 * pin - Enrollee Device Password (%NULL for Registrar or PBC) 	 */
specifier|const
name|u8
modifier|*
name|pin
decl_stmt|;
comment|/** 	 * pin_len - Length on pin in octets 	 */
name|size_t
name|pin_len
decl_stmt|;
comment|/** 	 * pbc - Whether this is protocol run uses PBC 	 */
name|int
name|pbc
decl_stmt|;
comment|/** 	 * assoc_wps_ie: (Re)AssocReq WPS IE (in AP; %NULL if not AP) 	 */
specifier|const
name|struct
name|wpabuf
modifier|*
name|assoc_wps_ie
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|wps_data
modifier|*
name|wps_init
parameter_list|(
specifier|const
name|struct
name|wps_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_deinit
parameter_list|(
name|struct
name|wps_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * enum wps_process_res - WPS message processing result  */
end_comment

begin_enum
enum|enum
name|wps_process_res
block|{
comment|/** 	 * WPS_DONE - Processing done 	 */
name|WPS_DONE
block|,
comment|/** 	 * WPS_CONTINUE - Processing continues 	 */
name|WPS_CONTINUE
block|,
comment|/** 	 * WPS_FAILURE - Processing failed 	 */
name|WPS_FAILURE
block|,
comment|/** 	 * WPS_PENDING - Processing continues, but waiting for an external 	 *	event (e.g., UPnP message from an external Registrar) 	 */
name|WPS_PENDING
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|wps_process_res
name|wps_process_msg
parameter_list|(
name|struct
name|wps_data
modifier|*
name|wps
parameter_list|,
name|enum
name|wsc_op_code
name|op_code
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wps_get_msg
parameter_list|(
name|struct
name|wps_data
modifier|*
name|wps
parameter_list|,
name|enum
name|wsc_op_code
modifier|*
name|op_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_is_selected_pbc_registrar
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_is_selected_pin_registrar
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|wps_get_uuid_e
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wps_build_assoc_req_ie
parameter_list|(
name|enum
name|wps_request_type
name|req_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|wps_build_probe_req_ie
parameter_list|(
name|int
name|pbc
parameter_list|,
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|,
name|enum
name|wps_request_type
name|req_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * struct wps_registrar_config - WPS Registrar configuration  */
end_comment

begin_struct
struct|struct
name|wps_registrar_config
block|{
comment|/** 	 * new_psk_cb - Callback for new PSK 	 * @ctx: Higher layer context data (cb_ctx) 	 * @mac_addr: MAC address of the Enrollee 	 * @psk: The new PSK 	 * @psk_len: The length of psk in octets 	 * Returns: 0 on success, -1 on failure 	 * 	 * This callback is called when a new per-device PSK is provisioned. 	 */
name|int
function_decl|(
modifier|*
name|new_psk_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|psk
parameter_list|,
name|size_t
name|psk_len
parameter_list|)
function_decl|;
comment|/** 	 * set_ie_cb - Callback for WPS IE changes 	 * @ctx: Higher layer context data (cb_ctx) 	 * @beacon_ie: WPS IE for Beacon 	 * @beacon_ie_len: WPS IE length for Beacon 	 * @probe_resp_ie: WPS IE for Probe Response 	 * @probe_resp_ie_len: WPS IE length for Probe Response 	 * Returns: 0 on success, -1 on failure 	 * 	 * This callback is called whenever the WPS IE in Beacon or Probe 	 * Response frames needs to be changed (AP only). 	 */
name|int
function_decl|(
modifier|*
name|set_ie_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|beacon_ie
parameter_list|,
name|size_t
name|beacon_ie_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|probe_resp_ie
parameter_list|,
name|size_t
name|probe_resp_ie_len
parameter_list|)
function_decl|;
comment|/** 	 * pin_needed_cb - Callback for requesting a PIN 	 * @ctx: Higher layer context data (cb_ctx) 	 * @uuid_e: UUID-E of the unknown Enrollee 	 * @dev: Device Data from the unknown Enrollee 	 * 	 * This callback is called whenever an unknown Enrollee requests to use 	 * PIN method and a matching PIN (Device Password) is not found in 	 * Registrar data. 	 */
name|void
function_decl|(
modifier|*
name|pin_needed_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid_e
parameter_list|,
specifier|const
name|struct
name|wps_device_data
modifier|*
name|dev
parameter_list|)
function_decl|;
comment|/** 	 * reg_success_cb - Callback for reporting successful registration 	 * @ctx: Higher layer context data (cb_ctx) 	 * @mac_addr: MAC address of the Enrollee 	 * @uuid_e: UUID-E of the Enrollee 	 * 	 * This callback is called whenever an Enrollee completes registration 	 * successfully. 	 */
name|void
function_decl|(
modifier|*
name|reg_success_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid_e
parameter_list|)
function_decl|;
comment|/** 	 * cb_ctx: Higher layer context data for Registrar callbacks 	 */
name|void
modifier|*
name|cb_ctx
decl_stmt|;
comment|/** 	 * skip_cred_build: Do not build credential 	 * 	 * This option can be used to disable internal code that builds 	 * Credential attribute into M8 based on the current network 	 * configuration and Enrollee capabilities. The extra_cred data will 	 * then be used as the Credential(s). 	 */
name|int
name|skip_cred_build
decl_stmt|;
comment|/** 	 * extra_cred: Additional Credential attribute(s) 	 * 	 * This optional data (set to %NULL to disable) can be used to add 	 * Credential attribute(s) for other networks into M8. If 	 * skip_cred_build is set, this will also override the automatically 	 * generated Credential attribute. 	 */
specifier|const
name|u8
modifier|*
name|extra_cred
decl_stmt|;
comment|/** 	 * extra_cred_len: Length of extra_cred in octets 	 */
name|size_t
name|extra_cred_len
decl_stmt|;
comment|/** 	 * disable_auto_conf - Disable auto-configuration on first registration 	 * 	 * By default, the AP that is started in not configured state will 	 * generate a random PSK and move to configured state when the first 	 * registration protocol run is completed successfully. This option can 	 * be used to disable this functionality and leave it up to an external 	 * program to take care of configuration. This requires the extra_cred 	 * to be set with a suitable Credential and skip_cred_build being used. 	 */
name|int
name|disable_auto_conf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * enum wps_event - WPS event types  */
end_comment

begin_enum
enum|enum
name|wps_event
block|{
comment|/** 	 * WPS_EV_M2D - M2D received (Registrar did not know us) 	 */
name|WPS_EV_M2D
block|,
comment|/** 	 * WPS_EV_FAIL - Registration failed 	 */
name|WPS_EV_FAIL
block|,
comment|/** 	 * WPS_EV_SUCCESS - Registration succeeded 	 */
name|WPS_EV_SUCCESS
block|,
comment|/** 	 * WPS_EV_PWD_AUTH_FAIL - Password authentication failed 	 */
name|WPS_EV_PWD_AUTH_FAIL
block|}
enum|;
end_enum

begin_comment
comment|/**  * union wps_event_data - WPS event data  */
end_comment

begin_union
union|union
name|wps_event_data
block|{
comment|/** 	 * struct wps_event_m2d - M2D event data 	 */
struct|struct
name|wps_event_m2d
block|{
name|u16
name|config_methods
decl_stmt|;
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
name|primary_dev_type
decl_stmt|;
comment|/* 8 octets */
name|u16
name|config_error
decl_stmt|;
name|u16
name|dev_password_id
decl_stmt|;
block|}
name|m2d
struct|;
comment|/** 	 * struct wps_event_fail - Registration failure information 	 * @msg: enum wps_msg_type 	 */
struct|struct
name|wps_event_fail
block|{
name|int
name|msg
decl_stmt|;
block|}
name|fail
struct|;
struct|struct
name|wps_event_pwd_auth_fail
block|{
name|int
name|enrollee
decl_stmt|;
name|int
name|part
decl_stmt|;
block|}
name|pwd_auth_fail
struct|;
block|}
union|;
end_union

begin_comment
comment|/**  * struct upnp_pending_message - Pending PutWLANResponse messages  * @next: Pointer to next pending message or %NULL  * @addr: NewWLANEventMAC  * @msg: NewMessage  * @type: Message Type  */
end_comment

begin_struct
struct|struct
name|upnp_pending_message
block|{
name|struct
name|upnp_pending_message
modifier|*
name|next
decl_stmt|;
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|msg
decl_stmt|;
name|enum
name|wps_msg_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wps_context - Long term WPS context data  *  * This data is stored at the higher layer Authenticator or Supplicant data  * structures and it is maintained over multiple registration protocol runs.  */
end_comment

begin_struct
struct|struct
name|wps_context
block|{
comment|/** 	 * ap - Whether the local end is an access point 	 */
name|int
name|ap
decl_stmt|;
comment|/** 	 * registrar - Pointer to WPS registrar data from wps_registrar_init() 	 */
name|struct
name|wps_registrar
modifier|*
name|registrar
decl_stmt|;
comment|/** 	 * wps_state - Current WPS state 	 */
name|enum
name|wps_state
name|wps_state
decl_stmt|;
comment|/** 	 * ap_setup_locked - Whether AP setup is locked (only used at AP) 	 */
name|int
name|ap_setup_locked
decl_stmt|;
comment|/** 	 * uuid - Own UUID 	 */
name|u8
name|uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/** 	 * ssid - SSID 	 * 	 * This SSID is used by the Registrar to fill in information for 	 * Credentials. In addition, AP uses it when acting as an Enrollee to 	 * notify Registrar of the current configuration. 	 */
name|u8
name|ssid
index|[
literal|32
index|]
decl_stmt|;
comment|/** 	 * ssid_len - Length of ssid in octets 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * dev - Own WPS device data 	 */
name|struct
name|wps_device_data
name|dev
decl_stmt|;
comment|/** 	 * config_methods - Enabled configuration methods 	 * 	 * Bit field of WPS_CONFIG_* 	 */
name|u16
name|config_methods
decl_stmt|;
comment|/** 	 * encr_types - Enabled encryption types (bit field of WPS_ENCR_*) 	 */
name|u16
name|encr_types
decl_stmt|;
comment|/** 	 * auth_types - Authentication types (bit field of WPS_AUTH_*) 	 */
name|u16
name|auth_types
decl_stmt|;
comment|/** 	 * network_key - The current Network Key (PSK) or %NULL to generate new 	 * 	 * If %NULL, Registrar will generate per-device PSK. In addition, AP 	 * uses this when acting as an Enrollee to notify Registrar of the 	 * current configuration. 	 */
name|u8
modifier|*
name|network_key
decl_stmt|;
comment|/** 	 * network_key_len - Length of network_key in octets 	 */
name|size_t
name|network_key_len
decl_stmt|;
comment|/** 	 * ap_settings - AP Settings override for M7 (only used at AP) 	 * 	 * If %NULL, AP Settings attributes will be generated based on the 	 * current network configuration. 	 */
name|u8
modifier|*
name|ap_settings
decl_stmt|;
comment|/** 	 * ap_settings_len - Length of ap_settings in octets 	 */
name|size_t
name|ap_settings_len
decl_stmt|;
comment|/** 	 * friendly_name - Friendly Name (required for UPnP) 	 */
name|char
modifier|*
name|friendly_name
decl_stmt|;
comment|/** 	 * manufacturer_url - Manufacturer URL (optional for UPnP) 	 */
name|char
modifier|*
name|manufacturer_url
decl_stmt|;
comment|/** 	 * model_description - Model Description (recommended for UPnP) 	 */
name|char
modifier|*
name|model_description
decl_stmt|;
comment|/** 	 * model_url - Model URL (optional for UPnP) 	 */
name|char
modifier|*
name|model_url
decl_stmt|;
comment|/** 	 * upc - Universal Product Code (optional for UPnP) 	 */
name|char
modifier|*
name|upc
decl_stmt|;
comment|/** 	 * cred_cb - Callback to notify that new Credentials were received 	 * @ctx: Higher layer context data (cb_ctx) 	 * @cred: The received Credential 	 * Return: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|cred_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|struct
name|wps_credential
modifier|*
name|cred
parameter_list|)
function_decl|;
comment|/** 	 * event_cb - Event callback (state information about progress) 	 * @ctx: Higher layer context data (cb_ctx) 	 * @event: Event type 	 * @data: Event data 	 */
name|void
function_decl|(
modifier|*
name|event_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|wps_event
name|event
parameter_list|,
name|union
name|wps_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/** 	 * cb_ctx: Higher layer context data for callbacks 	 */
name|void
modifier|*
name|cb_ctx
decl_stmt|;
name|struct
name|upnp_wps_device_sm
modifier|*
name|wps_upnp
decl_stmt|;
comment|/* Pending messages from UPnP PutWLANResponse */
name|struct
name|upnp_pending_message
modifier|*
name|upnp_msgs
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|wps_registrar
modifier|*
name|wps_registrar_init
parameter_list|(
name|struct
name|wps_context
modifier|*
name|wps
parameter_list|,
specifier|const
name|struct
name|wps_registrar_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_registrar_deinit
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_add_pin
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|,
specifier|const
name|u8
modifier|*
name|pin
parameter_list|,
name|size_t
name|pin_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_invalidate_pin
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_unlock_pin
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|,
specifier|const
name|u8
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_button_pushed
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_registrar_probe_req_rx
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|wps_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_update_ie
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wps_registrar_set_selected_registrar
parameter_list|(
name|struct
name|wps_registrar
modifier|*
name|reg
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|wps_pin_checksum
parameter_list|(
name|unsigned
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|wps_pin_valid
parameter_list|(
name|unsigned
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|wps_generate_pin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wps_free_pending_msgs
parameter_list|(
name|struct
name|upnp_pending_message
modifier|*
name|msgs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPS_H */
end_comment

end_unit

