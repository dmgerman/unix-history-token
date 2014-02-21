begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Common definitions  * Copyright (c) 2004-2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|DEFS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|Boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WPA_CIPHER_NONE
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_WEP40
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_WEP104
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_TKIP
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_CCMP
value|BIT(4)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_define
define|#
directive|define
name|WPA_CIPHER_AES_128_CMAC
value|BIT(5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_define
define|#
directive|define
name|WPA_CIPHER_GCMP
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|WPA_CIPHER_SMS4
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_IEEE8021X
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_PSK
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_NONE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_IEEE8021X_NO_WPA
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_WPA_NONE
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_FT_IEEE8021X
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_FT_PSK
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_IEEE8021X_SHA256
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_PSK_SHA256
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_WPS
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_SAE
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_FT_SAE
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_WAPI_PSK
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_WAPI_CERT
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|WPA_KEY_MGMT_CCKM
value|BIT(14)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_wpa_ieee8021x
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
name|akm
operator|&
operator|(
name|WPA_KEY_MGMT_IEEE8021X
operator||
name|WPA_KEY_MGMT_FT_IEEE8021X
operator||
name|WPA_KEY_MGMT_CCKM
operator||
name|WPA_KEY_MGMT_IEEE8021X_SHA256
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_wpa_psk
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
name|akm
operator|&
operator|(
name|WPA_KEY_MGMT_PSK
operator||
name|WPA_KEY_MGMT_FT_PSK
operator||
name|WPA_KEY_MGMT_PSK_SHA256
operator||
name|WPA_KEY_MGMT_SAE
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_ft
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
name|akm
operator|&
operator|(
name|WPA_KEY_MGMT_FT_PSK
operator||
name|WPA_KEY_MGMT_FT_IEEE8021X
operator||
name|WPA_KEY_MGMT_FT_SAE
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_sae
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
name|akm
operator|&
operator|(
name|WPA_KEY_MGMT_SAE
operator||
name|WPA_KEY_MGMT_FT_SAE
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_sha256
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
name|akm
operator|&
operator|(
name|WPA_KEY_MGMT_PSK_SHA256
operator||
name|WPA_KEY_MGMT_IEEE8021X_SHA256
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_wpa
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
name|wpa_key_mgmt_wpa_ieee8021x
argument_list|(
name|akm
argument_list|)
operator|||
name|wpa_key_mgmt_wpa_psk
argument_list|(
name|akm
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_wpa_any
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
name|wpa_key_mgmt_wpa
argument_list|(
name|akm
argument_list|)
operator|||
operator|(
name|akm
operator|&
name|WPA_KEY_MGMT_WPA_NONE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|wpa_key_mgmt_cckm
parameter_list|(
name|int
name|akm
parameter_list|)
block|{
return|return
name|akm
operator|==
name|WPA_KEY_MGMT_CCKM
return|;
block|}
end_function

begin_define
define|#
directive|define
name|WPA_PROTO_WPA
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_PROTO_RSN
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_PROTO_WAPI
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_OPEN
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_SHARED
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_LEAP
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_FT
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_AUTH_ALG_SAE
value|BIT(4)
end_define

begin_enum
enum|enum
name|wpa_alg
block|{
name|WPA_ALG_NONE
block|,
name|WPA_ALG_WEP
block|,
name|WPA_ALG_TKIP
block|,
name|WPA_ALG_CCMP
block|,
name|WPA_ALG_IGTK
block|,
name|WPA_ALG_PMK
block|,
name|WPA_ALG_GCMP
block|,
name|WPA_ALG_SMS4
block|,
name|WPA_ALG_KRK
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum wpa_cipher - Cipher suites  */
end_comment

begin_enum
enum|enum
name|wpa_cipher
block|{
name|CIPHER_NONE
block|,
name|CIPHER_WEP40
block|,
name|CIPHER_TKIP
block|,
name|CIPHER_CCMP
block|,
name|CIPHER_WEP104
block|,
name|CIPHER_GCMP
block|,
name|CIPHER_SMS4
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum wpa_key_mgmt - Key management suites  */
end_comment

begin_enum
enum|enum
name|wpa_key_mgmt
block|{
name|KEY_MGMT_802_1X
block|,
name|KEY_MGMT_PSK
block|,
name|KEY_MGMT_NONE
block|,
name|KEY_MGMT_802_1X_NO_WPA
block|,
name|KEY_MGMT_WPA_NONE
block|,
name|KEY_MGMT_FT_802_1X
block|,
name|KEY_MGMT_FT_PSK
block|,
name|KEY_MGMT_802_1X_SHA256
block|,
name|KEY_MGMT_PSK_SHA256
block|,
name|KEY_MGMT_WPS
block|,
name|KEY_MGMT_SAE
block|,
name|KEY_MGMT_FT_SAE
block|,
name|KEY_MGMT_WAPI_PSK
block|,
name|KEY_MGMT_WAPI_CERT
block|,
name|KEY_MGMT_CCKM
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum wpa_states - wpa_supplicant state  *  * These enumeration values are used to indicate the current wpa_supplicant  * state (wpa_s->wpa_state). The current state can be retrieved with  * wpa_supplicant_get_state() function and the state can be changed by calling  * wpa_supplicant_set_state(). In WPA state machine (wpa.c and preauth.c), the  * wrapper functions wpa_sm_get_state() and wpa_sm_set_state() should be used  * to access the state variable.  */
end_comment

begin_enum
enum|enum
name|wpa_states
block|{
comment|/** 	 * WPA_DISCONNECTED - Disconnected state 	 * 	 * This state indicates that client is not associated, but is likely to 	 * start looking for an access point. This state is entered when a 	 * connection is lost. 	 */
name|WPA_DISCONNECTED
block|,
comment|/** 	 * WPA_INTERFACE_DISABLED - Interface disabled 	 * 	 * This stat eis entered if the network interface is disabled, e.g., 	 * due to rfkill. wpa_supplicant refuses any new operations that would 	 * use the radio until the interface has been enabled. 	 */
name|WPA_INTERFACE_DISABLED
block|,
comment|/** 	 * WPA_INACTIVE - Inactive state (wpa_supplicant disabled) 	 * 	 * This state is entered if there are no enabled networks in the 	 * configuration. wpa_supplicant is not trying to associate with a new 	 * network and external interaction (e.g., ctrl_iface call to add or 	 * enable a network) is needed to start association. 	 */
name|WPA_INACTIVE
block|,
comment|/** 	 * WPA_SCANNING - Scanning for a network 	 * 	 * This state is entered when wpa_supplicant starts scanning for a 	 * network. 	 */
name|WPA_SCANNING
block|,
comment|/** 	 * WPA_AUTHENTICATING - Trying to authenticate with a BSS/SSID 	 * 	 * This state is entered when wpa_supplicant has found a suitable BSS 	 * to authenticate with and the driver is configured to try to 	 * authenticate with this BSS. This state is used only with drivers 	 * that use wpa_supplicant as the SME. 	 */
name|WPA_AUTHENTICATING
block|,
comment|/** 	 * WPA_ASSOCIATING - Trying to associate with a BSS/SSID 	 * 	 * This state is entered when wpa_supplicant has found a suitable BSS 	 * to associate with and the driver is configured to try to associate 	 * with this BSS in ap_scan=1 mode. When using ap_scan=2 mode, this 	 * state is entered when the driver is configured to try to associate 	 * with a network using the configured SSID and security policy. 	 */
name|WPA_ASSOCIATING
block|,
comment|/** 	 * WPA_ASSOCIATED - Association completed 	 * 	 * This state is entered when the driver reports that association has 	 * been successfully completed with an AP. If IEEE 802.1X is used 	 * (with or without WPA/WPA2), wpa_supplicant remains in this state 	 * until the IEEE 802.1X/EAPOL authentication has been completed. 	 */
name|WPA_ASSOCIATED
block|,
comment|/** 	 * WPA_4WAY_HANDSHAKE - WPA 4-Way Key Handshake in progress 	 * 	 * This state is entered when WPA/WPA2 4-Way Handshake is started. In 	 * case of WPA-PSK, this happens when receiving the first EAPOL-Key 	 * frame after association. In case of WPA-EAP, this state is entered 	 * when the IEEE 802.1X/EAPOL authentication has been completed. 	 */
name|WPA_4WAY_HANDSHAKE
block|,
comment|/** 	 * WPA_GROUP_HANDSHAKE - WPA Group Key Handshake in progress 	 * 	 * This state is entered when 4-Way Key Handshake has been completed 	 * (i.e., when the supplicant sends out message 4/4) and when Group 	 * Key rekeying is started by the AP (i.e., when supplicant receives 	 * message 1/2). 	 */
name|WPA_GROUP_HANDSHAKE
block|,
comment|/** 	 * WPA_COMPLETED - All authentication completed 	 * 	 * This state is entered when the full authentication process is 	 * completed. In case of WPA2, this happens when the 4-Way Handshake is 	 * successfully completed. With WPA, this state is entered after the 	 * Group Key Handshake; with IEEE 802.1X (non-WPA) connection is 	 * completed after dynamic keys are received (or if not used, after 	 * the EAP authentication has been completed). With static WEP keys and 	 * plaintext connections, this state is entered when an association 	 * has been completed. 	 * 	 * This state indicates that the supplicant has completed its 	 * processing for the association phase and that data connection is 	 * fully configured. 	 */
name|WPA_COMPLETED
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_PROTECT_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_PROTECT_TYPE_RX
value|1
end_define

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_PROTECT_TYPE_TX
value|2
end_define

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_PROTECT_TYPE_RX_TX
value|3
end_define

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_KEY_TYPE_GROUP
value|0
end_define

begin_define
define|#
directive|define
name|MLME_SETPROTECTION_KEY_TYPE_PAIRWISE
value|1
end_define

begin_comment
comment|/**  * enum mfp_options - Management frame protection (IEEE 802.11w) options  */
end_comment

begin_enum
enum|enum
name|mfp_options
block|{
name|NO_MGMT_FRAME_PROTECTION
init|=
literal|0
block|,
name|MGMT_FRAME_PROTECTION_OPTIONAL
init|=
literal|1
block|,
name|MGMT_FRAME_PROTECTION_REQUIRED
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|MGMT_FRAME_PROTECTION_DEFAULT
value|3
end_define

begin_comment
comment|/**  * enum hostapd_hw_mode - Hardware mode  */
end_comment

begin_enum
enum|enum
name|hostapd_hw_mode
block|{
name|HOSTAPD_MODE_IEEE80211B
block|,
name|HOSTAPD_MODE_IEEE80211G
block|,
name|HOSTAPD_MODE_IEEE80211A
block|,
name|HOSTAPD_MODE_IEEE80211AD
block|,
name|NUM_HOSTAPD_MODES
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum wpa_ctrl_req_type - Control interface request types  */
end_comment

begin_enum
enum|enum
name|wpa_ctrl_req_type
block|{
name|WPA_CTRL_REQ_UNKNOWN
block|,
name|WPA_CTRL_REQ_EAP_IDENTITY
block|,
name|WPA_CTRL_REQ_EAP_PASSWORD
block|,
name|WPA_CTRL_REQ_EAP_NEW_PASSWORD
block|,
name|WPA_CTRL_REQ_EAP_PIN
block|,
name|WPA_CTRL_REQ_EAP_OTP
block|,
name|WPA_CTRL_REQ_EAP_PASSPHRASE
block|,
name|NUM_WPA_CTRL_REQS
block|}
enum|;
end_enum

begin_comment
comment|/* Maximum number of EAP methods to store for EAP server user information */
end_comment

begin_define
define|#
directive|define
name|EAP_MAX_METHODS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFS_H */
end_comment

end_unit

