begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / Station table  * Copyright (c) 2002-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STA_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|STA_INFO_H
end_define

begin_comment
comment|/* STA flags */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_AUTH
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_ASSOC
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_TIM
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PERM
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_AUTHORIZED
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PENDING_POLL
value|BIT(6)
end_define

begin_comment
comment|/* pending activity poll not ACKed */
end_comment

begin_define
define|#
directive|define
name|WLAN_STA_SHORT_PREAMBLE
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PREAUTH
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_WMM
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_MFP
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_HT
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_WPS
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_MAYBE_WPS
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_WDS
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_ASSOC_REQ_OK
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_WPS2
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_GAS
value|BIT(17)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_VHT
value|BIT(18)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PENDING_DISASSOC_CB
value|BIT(29)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_PENDING_DEAUTH_CB
value|BIT(30)
end_define

begin_define
define|#
directive|define
name|WLAN_STA_NONERP
value|BIT(31)
end_define

begin_comment
comment|/* Maximum number of supported rates (from both Supported Rates and Extended  * Supported Rates IEs). */
end_comment

begin_define
define|#
directive|define
name|WLAN_SUPP_RATES_MAX
value|32
end_define

begin_struct
struct|struct
name|sta_info
block|{
name|struct
name|sta_info
modifier|*
name|next
decl_stmt|;
comment|/* next entry in sta list */
name|struct
name|sta_info
modifier|*
name|hnext
decl_stmt|;
comment|/* next entry in hash table list */
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|aid
decl_stmt|;
comment|/* STA's unique AID (1 .. 2007) or 0 if not yet assigned */
name|u32
name|flags
decl_stmt|;
comment|/* Bitfield of WLAN_STA_* */
name|u16
name|capability
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
comment|/* or beacon_int for APs */
name|u8
name|supported_rates
index|[
name|WLAN_SUPP_RATES_MAX
index|]
decl_stmt|;
name|int
name|supported_rates_len
decl_stmt|;
name|u8
name|qosinfo
decl_stmt|;
comment|/* Valid when WLAN_STA_WMM is set */
name|unsigned
name|int
name|nonerp_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_short_slot_time_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_short_preamble_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_ht_gf_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_ht_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ht_20mhz_set
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|no_p2p_set
range|:
literal|1
decl_stmt|;
name|u16
name|auth_alg
decl_stmt|;
name|u8
name|previous_ap
index|[
literal|6
index|]
decl_stmt|;
enum|enum
block|{
name|STA_NULLFUNC
init|=
literal|0
block|,
name|STA_DISASSOC
block|,
name|STA_DEAUTH
block|,
name|STA_REMOVE
block|}
name|timeout_next
enum|;
name|u16
name|deauth_reason
decl_stmt|;
name|u16
name|disassoc_reason
decl_stmt|;
comment|/* IEEE 802.1X related data */
name|struct
name|eapol_state_machine
modifier|*
name|eapol_sm
decl_stmt|;
comment|/* IEEE 802.11f (IAPP) related data */
name|struct
name|ieee80211_mgmt
modifier|*
name|last_assoc_req
decl_stmt|;
name|u32
name|acct_session_id_hi
decl_stmt|;
name|u32
name|acct_session_id_lo
decl_stmt|;
name|time_t
name|acct_session_start
decl_stmt|;
name|int
name|acct_session_started
decl_stmt|;
name|int
name|acct_terminate_cause
decl_stmt|;
comment|/* Acct-Terminate-Cause */
name|int
name|acct_interim_interval
decl_stmt|;
comment|/* Acct-Interim-Interval */
name|unsigned
name|long
name|last_rx_bytes
decl_stmt|;
name|unsigned
name|long
name|last_tx_bytes
decl_stmt|;
name|u32
name|acct_input_gigawords
decl_stmt|;
comment|/* Acct-Input-Gigawords */
name|u32
name|acct_output_gigawords
decl_stmt|;
comment|/* Acct-Output-Gigawords */
name|u8
modifier|*
name|challenge
decl_stmt|;
comment|/* IEEE 802.11 Shared Key Authentication Challenge */
name|struct
name|wpa_state_machine
modifier|*
name|wpa_sm
decl_stmt|;
name|struct
name|rsn_preauth_interface
modifier|*
name|preauth_iface
decl_stmt|;
name|struct
name|hostapd_ssid
modifier|*
name|ssid
decl_stmt|;
comment|/* SSID selection based on (Re)AssocReq */
name|struct
name|hostapd_ssid
modifier|*
name|ssid_probe
decl_stmt|;
comment|/* SSID selection based on ProbeReq */
name|int
name|vlan_id
decl_stmt|;
comment|/* PSKs from RADIUS authentication server */
name|struct
name|hostapd_sta_wpa_psk_short
modifier|*
name|psk
decl_stmt|;
name|char
modifier|*
name|identity
decl_stmt|;
comment|/* User-Name from RADIUS */
name|char
modifier|*
name|radius_cui
decl_stmt|;
comment|/* Chargeable-User-Identity from RADIUS */
name|struct
name|ieee80211_ht_capabilities
modifier|*
name|ht_capabilities
decl_stmt|;
name|struct
name|ieee80211_vht_capabilities
modifier|*
name|vht_capabilities
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
name|int
name|sa_query_count
decl_stmt|;
comment|/* number of pending SA Query requests; 			     * 0 = no SA Query in progress */
name|int
name|sa_query_timed_out
decl_stmt|;
name|u8
modifier|*
name|sa_query_trans_id
decl_stmt|;
comment|/* buffer of WLAN_SA_QUERY_TR_ID_LEN * 				* sa_query_count octets of pending SA Query 				* transaction identifiers */
name|struct
name|os_time
name|sa_query_start
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_IEEE80211W */
ifdef|#
directive|ifdef
name|CONFIG_INTERWORKING
define|#
directive|define
name|GAS_DIALOG_MAX
value|8
comment|/* Max concurrent dialog number */
name|struct
name|gas_dialog_info
modifier|*
name|gas_dialog
decl_stmt|;
name|u8
name|gas_dialog_next
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_INTERWORKING */
name|struct
name|wpabuf
modifier|*
name|wps_ie
decl_stmt|;
comment|/* WPS IE from (Re)Association Request */
name|struct
name|wpabuf
modifier|*
name|p2p_ie
decl_stmt|;
comment|/* P2P IE from (Re)Association Request */
name|struct
name|wpabuf
modifier|*
name|hs20_ie
decl_stmt|;
comment|/* HS 2.0 IE from (Re)Association Request */
name|struct
name|os_time
name|connected_time
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_SAE
enum|enum
block|{
name|SAE_INIT
block|,
name|SAE_COMMIT
block|,
name|SAE_CONFIRM
block|}
name|sae_state
enum|;
name|u16
name|sae_send_confirm
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_SAE */
block|}
struct|;
end_struct

begin_comment
comment|/* Default value for maximum station inactivity. After AP_MAX_INACTIVITY has  * passed since last received frame from the station, a nullfunc data frame is  * sent to the station. If this frame is not acknowledged and no other frames  * have been received, the station will be disassociated after  * AP_DISASSOC_DELAY seconds. Similarly, the station will be deauthenticated  * after AP_DEAUTH_DELAY seconds has passed after disassociation. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY
value|(5 * 60)
end_define

begin_define
define|#
directive|define
name|AP_DISASSOC_DELAY
value|(1)
end_define

begin_define
define|#
directive|define
name|AP_DEAUTH_DELAY
value|(1)
end_define

begin_comment
comment|/* Number of seconds to keep STA entry with Authenticated flag after it has  * been disassociated. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY_AFTER_DISASSOC
value|(1 * 30)
end_define

begin_comment
comment|/* Number of seconds to keep STA entry after it has been deauthenticated. */
end_comment

begin_define
define|#
directive|define
name|AP_MAX_INACTIVITY_AFTER_DEAUTH
value|(1 * 5)
end_define

begin_struct_decl
struct_decl|struct
name|hostapd_data
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ap_for_each_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sta_info
modifier|*
name|ap_get_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_hash_add
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_free_sta
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostapd_free_stas
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_handle_timer
parameter_list|(
name|void
modifier|*
name|eloop_ctx
parameter_list|,
name|void
modifier|*
name|timeout_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_session_timeout
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|u32
name|session_timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_no_session_timeout
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sta_info
modifier|*
name|ap_sta_add
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_disassociate
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|u16
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_deauthenticate
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|u16
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_WPS
end_ifdef

begin_function_decl
name|int
name|ap_sta_wps_cancel
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
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
comment|/* CONFIG_WPS */
end_comment

begin_function_decl
name|int
name|ap_sta_bind_vlan
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|int
name|old_vlanid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_start_sa_query
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_stop_sa_query
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ap_check_sa_query_timeout
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_disconnect
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u16
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_set_authorized
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|,
name|int
name|authorized
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|ap_sta_is_authorized
parameter_list|(
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
block|{
return|return
name|sta
operator|->
name|flags
operator|&
name|WLAN_STA_AUTHORIZED
return|;
block|}
end_function

begin_function_decl
name|void
name|ap_sta_deauth_cb
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ap_sta_disassoc_cb
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|sta_info
modifier|*
name|sta
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STA_INFO_H */
end_comment

end_unit

