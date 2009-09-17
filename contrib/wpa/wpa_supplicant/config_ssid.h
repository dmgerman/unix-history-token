begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / Network configuration structures  * Copyright (c) 2003-2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
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
file|"defs.h"
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
comment|/** 	 * bssid - BSSID 	 * 	 * If set, this network block is used only when associating with the AP 	 * using the configured BSSID 	 */
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
comment|/** 	 * proactive_key_caching - Enable proactive key caching 	 * 	 * This field can be used to enable proactive key caching which is also 	 * known as opportunistic PMKSA caching for WPA2. This is disabled (0) 	 * by default. Enable by setting this to 1. 	 * 	 * Proactive key caching is used to make supplicant assume that the APs 	 * are using the same PMK and generate PMKSA cache entries without 	 * doing RSN pre-authentication. This requires support from the AP side 	 * and is normally used with wireless switches that co-locate the 	 * authenticator. 	 */
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
comment|/** 	 * mode - IEEE 802.11 operation mode (Infrastucture/IBSS) 	 * 	 * 0 = infrastructure (Managed) mode, i.e., associate with an AP. 	 * 	 * 1 = IBSS (ad-hoc, peer-to-peer) 	 * 	 * Note: IBSS can only be used with key_mgmt NONE (plaintext and 	 * static WEP) and key_mgmt=WPA-NONE (fixed group key TKIP/CCMP). In 	 * addition, ap_scan has to be set to 2 for IBSS. WPA-None requires 	 * following network block options: proto=WPA, key_mgmt=WPA-NONE, 	 * pairwise=NONE, group=TKIP (or CCMP, but not both), and psk must also 	 * be set (either directly or using ASCII passphrase). 	 */
name|int
name|mode
decl_stmt|;
comment|/** 	 * disabled - Whether this network is currently disabled 	 * 	 * 0 = this network can be used (default). 	 * 1 = this network block is disabled (can be enabled through 	 * ctrl_iface, e.g., with wpa_cli or wpa_gui). 	 */
name|int
name|disabled
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
comment|/** 	 * ieee80211w - Whether management frame protection is enabled 	 * 	 * This value is used to configure policy for management frame 	 * protection (IEEE 802.11w). 0 = disabled, 1 = optional, 2 = required. 	 */
enum|enum
block|{
name|NO_IEEE80211W
init|=
literal|0
block|,
name|IEEE80211W_OPTIONAL
init|=
literal|1
block|,
name|IEEE80211W_REQUIRED
init|=
literal|2
block|}
name|ieee80211w
enum|;
endif|#
directive|endif
comment|/* CONFIG_IEEE80211W */
comment|/** 	 * frequency - Channel frequency in megahertz (MHz) for IBSS 	 * 	 * This value is used to configure the initial channel for IBSS (adhoc) 	 * networks, e.g., 2412 = IEEE 802.11b/g channel 1. It is ignored in 	 * the infrastructure mode. In addition, this value is only used by the 	 * station that creates the IBSS. If an IBSS network with the 	 * configured SSID is already present, the frequency of the network 	 * will be used instead of this configured value. 	 */
name|int
name|frequency
decl_stmt|;
comment|/** 	 * wpa_ptk_rekey - Maximum lifetime for PTK in seconds 	 * 	 * This value can be used to enforce rekeying of PTK to mitigate some 	 * attacks against TKIP deficiencies. 	 */
name|int
name|wpa_ptk_rekey
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

