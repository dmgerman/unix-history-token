begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Network configuration structures  * Copyright (c) 2003-2008, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_SSID_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_SSID_H
end_define

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"eap_peer/eap_config.h"
end_include

begin_define
define|#
directive|define
name|MAX_SSID_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DEFAULT_EAP_WORKAROUND
value|((unsigned int) -1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_EAPOL_FLAGS
value|(EAPOL_FLAG_REQUIRE_KEY_UNICAST | \ 			     EAPOL_FLAG_REQUIRE_KEY_BROADCAST)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROTO
value|(WPA_PROTO_WPA | WPA_PROTO_RSN)
end_define

begin_define
define|#
directive|define
name|DEFAULT_KEY_MGMT
value|(WPA_KEY_MGMT_PSK | WPA_KEY_MGMT_IEEE8021X)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PAIRWISE
value|(WPA_CIPHER_CCMP | WPA_CIPHER_TKIP)
end_define

begin_define
define|#
directive|define
name|DEFAULT_GROUP
value|(WPA_CIPHER_CCMP | WPA_CIPHER_TKIP | \ 		       WPA_CIPHER_WEP104 | WPA_CIPHER_WEP40)
end_define

begin_define
define|#
directive|define
name|DEFAULT_FRAGMENT_SIZE
value|1398
end_define

begin_define
define|#
directive|define
name|DEFAULT_BG_SCAN_PERIOD
value|-1
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISABLE_HT
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISABLE_HT40
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISABLE_SGI
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISABLE_MAX_AMSDU
value|-1
end_define

begin_comment
comment|/* no change */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_AMPDU_FACTOR
value|-1
end_define

begin_comment
comment|/* no change */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_AMPDU_DENSITY
value|-1
end_define

begin_comment
comment|/* no change */
end_comment

begin_comment
comment|/**  * struct wpa_ssid - Network configuration data  *  * This structure includes all the configuration variables for a network. This  * data is included in the per-interface configuration data as an element of  * the network list, struct wpa_config::ssid. Each network block in the  * configuration is mapped to a struct wpa_ssid instance.  */
end_comment

begin_struct
struct|struct
name|wpa_ssid
block|{
comment|/** 	 * next - Next network in global list 	 * 	 * This pointer can be used to iterate over all networks. The head of 	 * this list is stored in the ssid field of struct wpa_config. 	 */
name|struct
name|wpa_ssid
modifier|*
name|next
decl_stmt|;
comment|/** 	 * pnext - Next network in per-priority list 	 * 	 * This pointer can be used to iterate over all networks in the same 	 * priority class. The heads of these list are stored in the pssid 	 * fields of struct wpa_config. 	 */
name|struct
name|wpa_ssid
modifier|*
name|pnext
decl_stmt|;
comment|/** 	 * id - Unique id for the network 	 * 	 * This identifier is used as a unique identifier for each network 	 * block when using the control interface. Each network is allocated an 	 * id when it is being created, either when reading the configuration 	 * file or when a new network is added through the control interface. 	 */
name|int
name|id
decl_stmt|;
comment|/** 	 * priority - Priority group 	 * 	 * By default, all networks will get same priority group (0). If some 	 * of the networks are more desirable, this field can be used to change 	 * the order in which wpa_supplicant goes through the networks when 	 * selecting a BSS. The priority groups will be iterated in decreasing 	 * priority (i.e., the larger the priority value, the sooner the 	 * network is matched against the scan results). Within each priority 	 * group, networks will be selected based on security policy, signal 	 * strength, etc. 	 * 	 * Please note that AP scanning with scan_ssid=1 and ap_scan=2 mode are 	 * not using this priority to select the order for scanning. Instead, 	 * they try the networks in the order that used in the configuration 	 * file. 	 */
name|int
name|priority
decl_stmt|;
comment|/** 	 * ssid - Service set identifier (network name) 	 * 	 * This is the SSID for the network. For wireless interfaces, this is 	 * used to select which network will be used. If set to %NULL (or 	 * ssid_len=0), any SSID can be used. For wired interfaces, this must 	 * be set to %NULL. Note: SSID may contain any characters, even nul 	 * (ASCII 0) and as such, this should not be assumed to be a nul 	 * terminated string. ssid_len defines how many characters are valid 	 * and the ssid field is not guaranteed to be nul terminated. 	 */
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/** 	 * ssid_len - Length of the SSID 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * bssid - BSSID 	 * 	 * If set, this network block is used only when associating with the AP 	 * using the configured BSSID 	 * 	 * If this is a persistent P2P group (disabled == 2), this is the GO 	 * Device Address. 	 */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** 	 * bssid_set - Whether BSSID is configured for this network 	 */
name|int
name|bssid_set
decl_stmt|;
comment|/** 	 * psk - WPA pre-shared key (256 bits) 	 */
name|u8
name|psk
index|[
literal|32
index|]
decl_stmt|;
comment|/** 	 * psk_set - Whether PSK field is configured 	 */
name|int
name|psk_set
decl_stmt|;
comment|/** 	 * passphrase - WPA ASCII passphrase 	 * 	 * If this is set, psk will be generated using the SSID and passphrase 	 * configured for the network. ASCII passphrase must be between 8 and 	 * 63 characters (inclusive). 	 */
name|char
modifier|*
name|passphrase
decl_stmt|;
comment|/** 	 * ext_psk - PSK/passphrase name in external storage 	 * 	 * If this is set, PSK/passphrase will be fetched from external storage 	 * when requesting association with the network. 	 */
name|char
modifier|*
name|ext_psk
decl_stmt|;
comment|/** 	 * pairwise_cipher - Bitfield of allowed pairwise ciphers, WPA_CIPHER_* 	 */
name|int
name|pairwise_cipher
decl_stmt|;
comment|/** 	 * group_cipher - Bitfield of allowed group ciphers, WPA_CIPHER_* 	 */
name|int
name|group_cipher
decl_stmt|;
comment|/** 	 * key_mgmt - Bitfield of allowed key management protocols 	 * 	 * WPA_KEY_MGMT_* 	 */
name|int
name|key_mgmt
decl_stmt|;
comment|/** 	 * bg_scan_period - Background scan period in seconds, 0 to disable, or 	 * -1 to indicate no change to default driver configuration 	 */
name|int
name|bg_scan_period
decl_stmt|;
comment|/** 	 * proto - Bitfield of allowed protocols, WPA_PROTO_* 	 */
name|int
name|proto
decl_stmt|;
comment|/** 	 * auth_alg -  Bitfield of allowed authentication algorithms 	 * 	 * WPA_AUTH_ALG_* 	 */
name|int
name|auth_alg
decl_stmt|;
comment|/** 	 * scan_ssid - Scan this SSID with Probe Requests 	 * 	 * scan_ssid can be used to scan for APs using hidden SSIDs. 	 * Note: Many drivers do not support this. ap_mode=2 can be used with 	 * such drivers to use hidden SSIDs. 	 */
name|int
name|scan_ssid
decl_stmt|;
ifdef|#
directive|ifdef
name|IEEE8021X_EAPOL
define|#
directive|define
name|EAPOL_FLAG_REQUIRE_KEY_UNICAST
value|BIT(0)
define|#
directive|define
name|EAPOL_FLAG_REQUIRE_KEY_BROADCAST
value|BIT(1)
comment|/** 	 * eapol_flags - Bit field of IEEE 802.1X/EAPOL options (EAPOL_FLAG_*) 	 */
name|int
name|eapol_flags
decl_stmt|;
comment|/** 	 * eap - EAP peer configuration for this network 	 */
name|struct
name|eap_peer_config
name|eap
decl_stmt|;
endif|#
directive|endif
comment|/* IEEE8021X_EAPOL */
define|#
directive|define
name|NUM_WEP_KEYS
value|4
define|#
directive|define
name|MAX_WEP_KEY_LEN
value|16
comment|/** 	 * wep_key - WEP keys 	 */
name|u8
name|wep_key
index|[
name|NUM_WEP_KEYS
index|]
index|[
name|MAX_WEP_KEY_LEN
index|]
decl_stmt|;
comment|/** 	 * wep_key_len - WEP key lengths 	 */
name|size_t
name|wep_key_len
index|[
name|NUM_WEP_KEYS
index|]
decl_stmt|;
comment|/** 	 * wep_tx_keyidx - Default key index for TX frames using WEP 	 */
name|int
name|wep_tx_keyidx
decl_stmt|;
comment|/** 	 * proactive_key_caching - Enable proactive key caching 	 * 	 * This field can be used to enable proactive key caching which is also 	 * known as opportunistic PMKSA caching for WPA2. This is disabled (0) 	 * by default unless default value is changed with the global okc=1 	 * parameter. Enable by setting this to 1. 	 * 	 * Proactive key caching is used to make supplicant assume that the APs 	 * are using the same PMK and generate PMKSA cache entries without 	 * doing RSN pre-authentication. This requires support from the AP side 	 * and is normally used with wireless switches that co-locate the 	 * authenticator. 	 * 	 * Internally, special value -1 is used to indicate that the parameter 	 * was not specified in the configuration (i.e., default behavior is 	 * followed). 	 */
name|int
name|proactive_key_caching
decl_stmt|;
comment|/** 	 * mixed_cell - Whether mixed cells are allowed 	 * 	 * This option can be used to configure whether so called mixed cells, 	 * i.e., networks that use both plaintext and encryption in the same 	 * SSID, are allowed. This is disabled (0) by default. Enable by 	 * setting this to 1. 	 */
name|int
name|mixed_cell
decl_stmt|;
ifdef|#
directive|ifdef
name|IEEE8021X_EAPOL
comment|/** 	 * leap - Number of EAP methods using LEAP 	 * 	 * This field should be set to 1 if LEAP is enabled. This is used to 	 * select IEEE 802.11 authentication algorithm. 	 */
name|int
name|leap
decl_stmt|;
comment|/** 	 * non_leap - Number of EAP methods not using LEAP 	 * 	 * This field should be set to>0 if any EAP method other than LEAP is 	 * enabled. This is used to select IEEE 802.11 authentication 	 * algorithm. 	 */
name|int
name|non_leap
decl_stmt|;
comment|/** 	 * eap_workaround - EAP workarounds enabled 	 * 	 * wpa_supplicant supports number of "EAP workarounds" to work around 	 * interoperability issues with incorrectly behaving authentication 	 * servers. This is recommended to be enabled by default because some 	 * of the issues are present in large number of authentication servers. 	 * 	 * Strict EAP conformance mode can be configured by disabling 	 * workarounds with eap_workaround = 0. 	 */
name|unsigned
name|int
name|eap_workaround
decl_stmt|;
endif|#
directive|endif
comment|/* IEEE8021X_EAPOL */
comment|/** 	 * mode - IEEE 802.11 operation mode (Infrastucture/IBSS) 	 * 	 * 0 = infrastructure (Managed) mode, i.e., associate with an AP. 	 * 	 * 1 = IBSS (ad-hoc, peer-to-peer) 	 * 	 * 2 = AP (access point) 	 * 	 * 3 = P2P Group Owner (can be set in the configuration file) 	 * 	 * 4 = P2P Group Formation (used internally; not in configuration 	 * files) 	 * 	 * Note: IBSS can only be used with key_mgmt NONE (plaintext and 	 * static WEP) and key_mgmt=WPA-NONE (fixed group key TKIP/CCMP). In 	 * addition, ap_scan has to be set to 2 for IBSS. WPA-None requires 	 * following network block options: proto=WPA, key_mgmt=WPA-NONE, 	 * pairwise=NONE, group=TKIP (or CCMP, but not both), and psk must also 	 * be set (either directly or using ASCII passphrase). 	 */
enum|enum
name|wpas_mode
block|{
name|WPAS_MODE_INFRA
init|=
literal|0
block|,
name|WPAS_MODE_IBSS
init|=
literal|1
block|,
name|WPAS_MODE_AP
init|=
literal|2
block|,
name|WPAS_MODE_P2P_GO
init|=
literal|3
block|,
name|WPAS_MODE_P2P_GROUP_FORMATION
init|=
literal|4
block|, 	}
name|mode
enum|;
comment|/** 	 * disabled - Whether this network is currently disabled 	 * 	 * 0 = this network can be used (default). 	 * 1 = this network block is disabled (can be enabled through 	 * ctrl_iface, e.g., with wpa_cli or wpa_gui). 	 * 2 = this network block includes parameters for a persistent P2P 	 * group (can be used with P2P ctrl_iface commands) 	 */
name|int
name|disabled
decl_stmt|;
comment|/** 	 * disabled_for_connect - Whether this network was temporarily disabled 	 * 	 * This flag is used to reenable all the temporarily disabled networks 	 * after either the success or failure of a WPS connection. 	 */
name|int
name|disabled_for_connect
decl_stmt|;
comment|/** 	 * peerkey -  Whether PeerKey handshake for direct links is allowed 	 * 	 * This is only used when both RSN/WPA2 and IEEE 802.11e (QoS) are 	 * enabled. 	 * 	 * 0 = disabled (default) 	 * 1 = enabled 	 */
name|int
name|peerkey
decl_stmt|;
comment|/** 	 * id_str - Network identifier string for external scripts 	 * 	 * This value is passed to external ctrl_iface monitors in 	 * WPA_EVENT_CONNECTED event and wpa_cli sets this as WPA_ID_STR 	 * environment variable for action scripts. 	 */
name|char
modifier|*
name|id_str
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
comment|/** 	 * ieee80211w - Whether management frame protection is enabled 	 * 	 * This value is used to configure policy for management frame 	 * protection (IEEE 802.11w). 0 = disabled, 1 = optional, 2 = required. 	 * This is disabled by default unless the default value has been changed 	 * with the global pmf=1/2 parameter. 	 * 	 * Internally, special value 3 is used to indicate that the parameter 	 * was not specified in the configuration (i.e., default behavior is 	 * followed). 	 */
name|enum
name|mfp_options
name|ieee80211w
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_IEEE80211W */
comment|/** 	 * frequency - Channel frequency in megahertz (MHz) for IBSS 	 * 	 * This value is used to configure the initial channel for IBSS (adhoc) 	 * networks, e.g., 2412 = IEEE 802.11b/g channel 1. It is ignored in 	 * the infrastructure mode. In addition, this value is only used by the 	 * station that creates the IBSS. If an IBSS network with the 	 * configured SSID is already present, the frequency of the network 	 * will be used instead of this configured value. 	 */
name|int
name|frequency
decl_stmt|;
name|int
name|ht40
decl_stmt|;
comment|/** 	 * wpa_ptk_rekey - Maximum lifetime for PTK in seconds 	 * 	 * This value can be used to enforce rekeying of PTK to mitigate some 	 * attacks against TKIP deficiencies. 	 */
name|int
name|wpa_ptk_rekey
decl_stmt|;
comment|/** 	 * scan_freq - Array of frequencies to scan or %NULL for all 	 * 	 * This is an optional zero-terminated array of frequencies in 	 * megahertz (MHz) to include in scan requests when searching for this 	 * network. This can be used to speed up scanning when the network is 	 * known to not use all possible channels. 	 */
name|int
modifier|*
name|scan_freq
decl_stmt|;
comment|/** 	 * bgscan - Background scan and roaming parameters or %NULL if none 	 * 	 * This is an optional set of parameters for background scanning and 	 * roaming within a network (ESS) in following format: 	 *<bgscan module name>:<module parameters> 	 */
name|char
modifier|*
name|bgscan
decl_stmt|;
comment|/** 	 * ignore_broadcast_ssid - Hide SSID in AP mode 	 * 	 * Send empty SSID in beacons and ignore probe request frames that do 	 * not specify full SSID, i.e., require stations to know SSID. 	 * default: disabled (0) 	 * 1 = send empty (length=0) SSID in beacon and ignore probe request 	 * for broadcast SSID 	 * 2 = clear SSID (ASCII 0), but keep the original length (this may be 	 * required with some clients that do not support empty SSID) and 	 * ignore probe requests for broadcast SSID 	 */
name|int
name|ignore_broadcast_ssid
decl_stmt|;
comment|/** 	 * freq_list - Array of allowed frequencies or %NULL for all 	 * 	 * This is an optional zero-terminated array of frequencies in 	 * megahertz (MHz) to allow for selecting the BSS. If set, scan results 	 * that do not match any of the specified frequencies are not 	 * considered when selecting a BSS. 	 */
name|int
modifier|*
name|freq_list
decl_stmt|;
comment|/** 	 * p2p_client_list - List of P2P Clients in a persistent group (GO) 	 * 	 * This is a list of P2P Clients (P2P Device Address) that have joined 	 * the persistent group. This is maintained on the GO for persistent 	 * group entries (disabled == 2). 	 */
name|u8
modifier|*
name|p2p_client_list
decl_stmt|;
comment|/** 	 * num_p2p_clients - Number of entries in p2p_client_list 	 */
name|size_t
name|num_p2p_clients
decl_stmt|;
ifndef|#
directive|ifndef
name|P2P_MAX_STORED_CLIENTS
define|#
directive|define
name|P2P_MAX_STORED_CLIENTS
value|100
endif|#
directive|endif
comment|/* P2P_MAX_STORED_CLIENTS */
comment|/** 	 * p2p_group - Network generated as a P2P group (used internally) 	 */
name|int
name|p2p_group
decl_stmt|;
comment|/** 	 * p2p_persistent_group - Whether this is a persistent group 	 */
name|int
name|p2p_persistent_group
decl_stmt|;
comment|/** 	 * temporary - Whether this network is temporary and not to be saved 	 */
name|int
name|temporary
decl_stmt|;
comment|/** 	 * export_keys - Whether keys may be exported 	 * 	 * This attribute will be set when keys are determined through 	 * WPS or similar so that they may be exported. 	 */
name|int
name|export_keys
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_HT_OVERRIDES
comment|/** 	 * disable_ht - Disable HT (IEEE 802.11n) for this network 	 * 	 * By default, use it if it is available, but this can be configured 	 * to 1 to have it disabled. 	 */
name|int
name|disable_ht
decl_stmt|;
comment|/** 	 * disable_ht40 - Disable HT40 for this network 	 * 	 * By default, use it if it is available, but this can be configured 	 * to 1 to have it disabled. 	 */
name|int
name|disable_ht40
decl_stmt|;
comment|/** 	 * disable_sgi - Disable SGI (Short Guard Interval) for this network 	 * 	 * By default, use it if it is available, but this can be configured 	 * to 1 to have it disabled. 	 */
name|int
name|disable_sgi
decl_stmt|;
comment|/** 	 * disable_max_amsdu - Disable MAX A-MSDU 	 * 	 * A-MDSU will be 3839 bytes when disabled, or 7935 	 * when enabled (assuming it is otherwise supported) 	 * -1 (default) means do not apply any settings to the kernel. 	 */
name|int
name|disable_max_amsdu
decl_stmt|;
comment|/** 	 * ampdu_factor - Maximum A-MPDU Length Exponent 	 * 	 * Value: 0-3, see 7.3.2.56.3 in IEEE Std 802.11n-2009. 	 */
name|int
name|ampdu_factor
decl_stmt|;
comment|/** 	 * ampdu_density - Minimum A-MPDU Start Spacing 	 * 	 * Value: 0-7, see 7.3.2.56.3 in IEEE Std 802.11n-2009. 	 */
name|int
name|ampdu_density
decl_stmt|;
comment|/** 	 * ht_mcs - Allowed HT-MCS rates, in ASCII hex: ffff0000... 	 * 	 * By default (empty string): Use whatever the OS has configured. 	 */
name|char
modifier|*
name|ht_mcs
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_HT_OVERRIDES */
comment|/** 	 * ap_max_inactivity - Timeout in seconds to detect STA's inactivity 	 * 	 * This timeout value is used in AP mode to clean up inactive stations. 	 * By default: 300 seconds. 	 */
name|int
name|ap_max_inactivity
decl_stmt|;
comment|/** 	 * dtim_period - DTIM period in Beacon intervals 	 * By default: 2 	 */
name|int
name|dtim_period
decl_stmt|;
comment|/** 	 * auth_failures - Number of consecutive authentication failures 	 */
name|unsigned
name|int
name|auth_failures
decl_stmt|;
comment|/** 	 * disabled_until - Network block disabled until this time if non-zero 	 */
name|struct
name|os_time
name|disabled_until
decl_stmt|;
comment|/** 	 * parent_cred - Pointer to parent wpa_cred entry 	 * 	 * This pointer can be used to delete temporary networks when a wpa_cred 	 * that was used to create them is removed. This pointer should not be 	 * dereferences since it may not be updated in all cases. 	 */
name|void
modifier|*
name|parent_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_SSID_H */
end_comment

end_unit

