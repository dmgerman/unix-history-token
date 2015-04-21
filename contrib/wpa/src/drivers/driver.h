begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Driver interface definition  * Copyright (c) 2003-2015, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  *  * This file defines a driver interface used by both %wpa_supplicant and  * hostapd. The first part of the file defines data structures used in various  * driver operations. This is followed by the struct wpa_driver_ops that each  * driver wrapper will beed to define with callback functions for requesting  * driver operations. After this, there are definitions for driver event  * reporting with wpa_supplicant_event() and some convenience helper functions  * that can be used to report events.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|DRIVER_H
end_define

begin_define
define|#
directive|define
name|WPA_SUPPLICANT_DRIVER_VERSION
value|4
end_define

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"utils/list.h"
end_include

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_NO_IR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_RADAR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_HT40PLUS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_HT40MINUS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_HT40
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_SURVEY_LIST_INITIALIZED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DFS_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DFS_USABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DFS_UNAVAILABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DFS_AVAILABLE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_DFS_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_VHT_10_70
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_VHT_30_50
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_VHT_50_30
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_VHT_70_10
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_INDOOR_ONLY
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HOSTAPD_CHAN_GO_CONCURRENT
value|0x00020000
end_define

begin_comment
comment|/**  * enum reg_change_initiator - Regulatory change initiator  */
end_comment

begin_enum
enum|enum
name|reg_change_initiator
block|{
name|REGDOM_SET_BY_CORE
block|,
name|REGDOM_SET_BY_USER
block|,
name|REGDOM_SET_BY_DRIVER
block|,
name|REGDOM_SET_BY_COUNTRY_IE
block|,
name|REGDOM_BEACON_HINT
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum reg_type - Regulatory change types  */
end_comment

begin_enum
enum|enum
name|reg_type
block|{
name|REGDOM_TYPE_UNKNOWN
block|,
name|REGDOM_TYPE_COUNTRY
block|,
name|REGDOM_TYPE_WORLD
block|,
name|REGDOM_TYPE_CUSTOM_WORLD
block|,
name|REGDOM_TYPE_INTERSECTION
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct hostapd_channel_data - Channel information  */
end_comment

begin_struct
struct|struct
name|hostapd_channel_data
block|{
comment|/** 	 * chan - Channel number (IEEE 802.11) 	 */
name|short
name|chan
decl_stmt|;
comment|/** 	 * freq - Frequency in MHz 	 */
name|int
name|freq
decl_stmt|;
comment|/** 	 * flag - Channel flags (HOSTAPD_CHAN_*) 	 */
name|int
name|flag
decl_stmt|;
comment|/** 	 * max_tx_power - Regulatory transmit power limit in dBm 	 */
name|u8
name|max_tx_power
decl_stmt|;
comment|/** 	 * survey_list - Linked list of surveys (struct freq_survey) 	 */
name|struct
name|dl_list
name|survey_list
decl_stmt|;
comment|/** 	 * min_nf - Minimum observed noise floor, in dBm, based on all 	 * surveyed channel data 	 */
name|s8
name|min_nf
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_ACS
comment|/** 	 * interference_factor - Computed interference factor on this 	 * channel (used internally in src/ap/acs.c; driver wrappers do not 	 * need to set this) 	 */
name|long
name|double
name|interference_factor
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_ACS */
comment|/** 	 * dfs_cac_ms - DFS CAC time in milliseconds 	 */
name|unsigned
name|int
name|dfs_cac_ms
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTAPD_MODE_FLAG_HT_INFO_KNOWN
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|HOSTAPD_MODE_FLAG_VHT_INFO_KNOWN
value|BIT(1)
end_define

begin_comment
comment|/**  * struct hostapd_hw_modes - Supported hardware mode information  */
end_comment

begin_struct
struct|struct
name|hostapd_hw_modes
block|{
comment|/** 	 * mode - Hardware mode 	 */
name|enum
name|hostapd_hw_mode
name|mode
decl_stmt|;
comment|/** 	 * num_channels - Number of entries in the channels array 	 */
name|int
name|num_channels
decl_stmt|;
comment|/** 	 * channels - Array of supported channels 	 */
name|struct
name|hostapd_channel_data
modifier|*
name|channels
decl_stmt|;
comment|/** 	 * num_rates - Number of entries in the rates array 	 */
name|int
name|num_rates
decl_stmt|;
comment|/** 	 * rates - Array of supported rates in 100 kbps units 	 */
name|int
modifier|*
name|rates
decl_stmt|;
comment|/** 	 * ht_capab - HT (IEEE 802.11n) capabilities 	 */
name|u16
name|ht_capab
decl_stmt|;
comment|/** 	 * mcs_set - MCS (IEEE 802.11n) rate parameters 	 */
name|u8
name|mcs_set
index|[
literal|16
index|]
decl_stmt|;
comment|/** 	 * a_mpdu_params - A-MPDU (IEEE 802.11n) parameters 	 */
name|u8
name|a_mpdu_params
decl_stmt|;
comment|/** 	 * vht_capab - VHT (IEEE 802.11ac) capabilities 	 */
name|u32
name|vht_capab
decl_stmt|;
comment|/** 	 * vht_mcs_set - VHT MCS (IEEE 802.11ac) rate parameters 	 */
name|u8
name|vht_mcs_set
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* HOSTAPD_MODE_FLAG_* */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_MODE_INFRA
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_MODE_IBSS
value|1
end_define

begin_define
define|#
directive|define
name|IEEE80211_MODE_AP
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_MODE_MESH
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAP_ESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAP_IBSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAP_PRIVACY
value|0x0010
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAP_RRM
value|0x1000
end_define

begin_comment
comment|/* DMG (60 GHz) IEEE 802.11ad */
end_comment

begin_comment
comment|/* type - bits 0..1 */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAP_DMG_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|IEEE80211_CAP_DMG_IBSS
value|0x0001
end_define

begin_comment
comment|/* Tx by: STA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAP_DMG_PBSS
value|0x0002
end_define

begin_comment
comment|/* Tx by: PCP */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_CAP_DMG_AP
value|0x0003
end_define

begin_comment
comment|/* Tx by: AP */
end_comment

begin_define
define|#
directive|define
name|WPA_SCAN_QUAL_INVALID
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_SCAN_NOISE_INVALID
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_SCAN_LEVEL_INVALID
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_SCAN_LEVEL_DBM
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_SCAN_ASSOCIATED
value|BIT(5)
end_define

begin_comment
comment|/**  * struct wpa_scan_res - Scan result for an BSS/IBSS  * @flags: information flags about the BSS/IBSS (WPA_SCAN_*)  * @bssid: BSSID  * @freq: frequency of the channel in MHz (e.g., 2412 = channel 1)  * @beacon_int: beacon interval in TUs (host byte order)  * @caps: capability information field in host byte order  * @qual: signal quality  * @noise: noise level  * @level: signal level  * @tsf: Timestamp  * @age: Age of the information in milliseconds (i.e., how many milliseconds  * ago the last Beacon or Probe Response frame was received)  * @est_throughput: Estimated throughput in kbps (this is calculated during  * scan result processing if left zero by the driver wrapper)  * @snr: Signal-to-noise ratio in dB (calculated during scan result processing)  * @ie_len: length of the following IE field in octets  * @beacon_ie_len: length of the following Beacon IE field in octets  *  * This structure is used as a generic format for scan results from the  * driver. Each driver interface implementation is responsible for converting  * the driver or OS specific scan results into this format.  *  * If the driver does not support reporting all IEs, the IE data structure is  * constructed of the IEs that are available. This field will also need to  * include SSID in IE format. All drivers are encouraged to be extended to  * report all IEs to make it easier to support future additions.  *  * This structure data is followed by ie_len octets of IEs from Probe Response  * frame (or if the driver does not indicate source of IEs, these may also be  * from Beacon frame). After the first set of IEs, another set of IEs may follow  * (with beacon_ie_len octets of data) if the driver provides both IE sets.  */
end_comment

begin_struct
struct|struct
name|wpa_scan_res
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|int
name|freq
decl_stmt|;
name|u16
name|beacon_int
decl_stmt|;
name|u16
name|caps
decl_stmt|;
name|int
name|qual
decl_stmt|;
name|int
name|noise
decl_stmt|;
name|int
name|level
decl_stmt|;
name|u64
name|tsf
decl_stmt|;
name|unsigned
name|int
name|age
decl_stmt|;
name|unsigned
name|int
name|est_throughput
decl_stmt|;
name|int
name|snr
decl_stmt|;
name|size_t
name|ie_len
decl_stmt|;
name|size_t
name|beacon_ie_len
decl_stmt|;
comment|/* Followed by ie_len + beacon_ie_len octets of IE data */
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_scan_results - Scan results  * @res: Array of pointers to allocated variable length scan result entries  * @num: Number of entries in the scan result array  * @fetch_time: Time when the results were fetched from the driver  */
end_comment

begin_struct
struct|struct
name|wpa_scan_results
block|{
name|struct
name|wpa_scan_res
modifier|*
modifier|*
name|res
decl_stmt|;
name|size_t
name|num
decl_stmt|;
name|struct
name|os_reltime
name|fetch_time
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_interface_info - Network interface information  * @next: Pointer to the next interface or NULL if this is the last one  * @ifname: Interface name that can be used with init() or init2()  * @desc: Human readable adapter description (e.g., vendor/model) or NULL if  *	not available  * @drv_name: struct wpa_driver_ops::name (note: unlike other strings, this one  *	is not an allocated copy, i.e., get_interfaces() caller will not free  *	this)  */
end_comment

begin_struct
struct|struct
name|wpa_interface_info
block|{
name|struct
name|wpa_interface_info
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|ifname
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
specifier|const
name|char
modifier|*
name|drv_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WPAS_MAX_SCAN_SSIDS
value|16
end_define

begin_comment
comment|/**  * struct wpa_driver_scan_params - Scan parameters  * Data for struct wpa_driver_ops::scan2().  */
end_comment

begin_struct
struct|struct
name|wpa_driver_scan_params
block|{
comment|/** 	 * ssids - SSIDs to scan for 	 */
struct|struct
name|wpa_driver_scan_ssid
block|{
comment|/** 		 * ssid - specific SSID to scan for (ProbeReq) 		 * %NULL or zero-length SSID is used to indicate active scan 		 * with wildcard SSID. 		 */
specifier|const
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/** 		 * ssid_len: Length of the SSID in octets 		 */
name|size_t
name|ssid_len
decl_stmt|;
block|}
name|ssids
index|[
name|WPAS_MAX_SCAN_SSIDS
index|]
struct|;
comment|/** 	 * num_ssids - Number of entries in ssids array 	 * Zero indicates a request for a passive scan. 	 */
name|size_t
name|num_ssids
decl_stmt|;
comment|/** 	 * extra_ies - Extra IE(s) to add into Probe Request or %NULL 	 */
specifier|const
name|u8
modifier|*
name|extra_ies
decl_stmt|;
comment|/** 	 * extra_ies_len - Length of extra_ies in octets 	 */
name|size_t
name|extra_ies_len
decl_stmt|;
comment|/** 	 * freqs - Array of frequencies to scan or %NULL for all frequencies 	 * 	 * The frequency is set in MHz. The array is zero-terminated. 	 */
name|int
modifier|*
name|freqs
decl_stmt|;
comment|/** 	 * filter_ssids - Filter for reporting SSIDs 	 * 	 * This optional parameter can be used to request the driver wrapper to 	 * filter scan results to include only the specified SSIDs. %NULL 	 * indicates that no filtering is to be done. This can be used to 	 * reduce memory needs for scan results in environments that have large 	 * number of APs with different SSIDs. 	 * 	 * The driver wrapper is allowed to take this allocated buffer into its 	 * own use by setting the pointer to %NULL. In that case, the driver 	 * wrapper is responsible for freeing the buffer with os_free() once it 	 * is not needed anymore. 	 */
struct|struct
name|wpa_driver_scan_filter
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
block|}
modifier|*
name|filter_ssids
struct|;
comment|/** 	 * num_filter_ssids - Number of entries in filter_ssids array 	 */
name|size_t
name|num_filter_ssids
decl_stmt|;
comment|/** 	 * filter_rssi - Filter by RSSI 	 * 	 * The driver may filter scan results in firmware to reduce host 	 * wakeups and thereby save power. Specify the RSSI threshold in s32 	 * dBm. 	 */
name|s32
name|filter_rssi
decl_stmt|;
comment|/** 	 * p2p_probe - Used to disable CCK (802.11b) rates for P2P probes 	 * 	 * When set, the driver is expected to remove rates 1, 2, 5.5, and 11 	 * Mbps from the support rates element(s) in the Probe Request frames 	 * and not to transmit the frames at any of those rates. 	 */
name|unsigned
name|int
name|p2p_probe
range|:
literal|1
decl_stmt|;
comment|/** 	 * only_new_results - Request driver to report only new results 	 * 	 * This is used to request the driver to report only BSSes that have 	 * been detected after this scan request has been started, i.e., to 	 * flush old cached BSS entries. 	 */
name|unsigned
name|int
name|only_new_results
range|:
literal|1
decl_stmt|;
comment|/** 	 * low_priority - Requests driver to use a lower scan priority 	 * 	 * This is used to request the driver to use a lower scan priority 	 * if it supports such a thing. 	 */
name|unsigned
name|int
name|low_priority
range|:
literal|1
decl_stmt|;
comment|/** 	 * mac_addr_rand - Requests driver to randomize MAC address 	 */
name|unsigned
name|int
name|mac_addr_rand
range|:
literal|1
decl_stmt|;
comment|/** 	 * mac_addr - MAC address used with randomization. The address cannot be 	 * a multicast one, i.e., bit 0 of byte 0 should not be set. 	 */
specifier|const
name|u8
modifier|*
name|mac_addr
decl_stmt|;
comment|/** 	 * mac_addr_mask - MAC address mask used with randomization. 	 * 	 * Bits that are 0 in the mask should be randomized. Bits that are 1 in 	 * the mask should be taken as is from mac_addr. The mask should not 	 * allow the generation of a multicast address, i.e., bit 0 of byte 0 	 * must be set. 	 */
specifier|const
name|u8
modifier|*
name|mac_addr_mask
decl_stmt|;
comment|/* 	 * NOTE: Whenever adding new parameters here, please make sure 	 * wpa_scan_clone_params() and wpa_scan_free_params() get updated with 	 * matching changes. 	 */
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_driver_auth_params - Authentication parameters  * Data for struct wpa_driver_ops::authenticate().  */
end_comment

begin_struct
struct|struct
name|wpa_driver_auth_params
block|{
name|int
name|freq
decl_stmt|;
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ssid
decl_stmt|;
name|size_t
name|ssid_len
decl_stmt|;
name|int
name|auth_alg
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ie
decl_stmt|;
name|size_t
name|ie_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|wep_key
index|[
literal|4
index|]
decl_stmt|;
name|size_t
name|wep_key_len
index|[
literal|4
index|]
decl_stmt|;
name|int
name|wep_tx_keyidx
decl_stmt|;
name|int
name|local_state_change
decl_stmt|;
comment|/** 	 * p2p - Whether this connection is a P2P group 	 */
name|int
name|p2p
decl_stmt|;
comment|/** 	 * sae_data - SAE elements for Authentication frame 	 * 	 * This buffer starts with the Authentication transaction sequence 	 * number field. If SAE is not used, this pointer is %NULL. 	 */
specifier|const
name|u8
modifier|*
name|sae_data
decl_stmt|;
comment|/** 	 * sae_data_len - Length of sae_data buffer in octets 	 */
name|size_t
name|sae_data_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * enum wps_mode - WPS mode  */
end_comment

begin_enum
enum|enum
name|wps_mode
block|{
comment|/** 	 * WPS_MODE_NONE - No WPS provisioning being used 	 */
name|WPS_MODE_NONE
block|,
comment|/** 	 * WPS_MODE_OPEN - WPS provisioning with AP that is in open mode 	 */
name|WPS_MODE_OPEN
block|,
comment|/** 	 * WPS_MODE_PRIVACY - WPS provisioning with AP that is using protection 	 */
name|WPS_MODE_PRIVACY
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct hostapd_freq_params - Channel parameters  */
end_comment

begin_struct
struct|struct
name|hostapd_freq_params
block|{
comment|/** 	 * mode - Mode/band (HOSTAPD_MODE_IEEE80211A, ..) 	 */
name|enum
name|hostapd_hw_mode
name|mode
decl_stmt|;
comment|/** 	 * freq - Primary channel center frequency in MHz 	 */
name|int
name|freq
decl_stmt|;
comment|/** 	 * channel - Channel number 	 */
name|int
name|channel
decl_stmt|;
comment|/** 	 * ht_enabled - Whether HT is enabled 	 */
name|int
name|ht_enabled
decl_stmt|;
comment|/** 	 * sec_channel_offset - Secondary channel offset for HT40 	 * 	 * 0 = HT40 disabled, 	 * -1 = HT40 enabled, secondary channel below primary, 	 * 1 = HT40 enabled, secondary channel above primary 	 */
name|int
name|sec_channel_offset
decl_stmt|;
comment|/** 	 * vht_enabled - Whether VHT is enabled 	 */
name|int
name|vht_enabled
decl_stmt|;
comment|/** 	 * center_freq1 - Segment 0 center frequency in MHz 	 * 	 * Valid for both HT and VHT. 	 */
name|int
name|center_freq1
decl_stmt|;
comment|/** 	 * center_freq2 - Segment 1 center frequency in MHz 	 * 	 * Non-zero only for bandwidth 80 and an 80+80 channel 	 */
name|int
name|center_freq2
decl_stmt|;
comment|/** 	 * bandwidth - Channel bandwidth in MHz (20, 40, 80, 160) 	 */
name|int
name|bandwidth
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_driver_associate_params - Association parameters  * Data for struct wpa_driver_ops::associate().  */
end_comment

begin_struct
struct|struct
name|wpa_driver_associate_params
block|{
comment|/** 	 * bssid - BSSID of the selected AP 	 * This can be %NULL, if ap_scan=2 mode is used and the driver is 	 * responsible for selecting with which BSS to associate. */
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
comment|/** 	 * bssid_hint - BSSID of a proposed AP 	 * 	 * This indicates which BSS has been found a suitable candidate for 	 * initial association for drivers that use driver/firmwate-based BSS 	 * selection. Unlike the @bssid parameter, @bssid_hint does not limit 	 * the driver from selecting other BSSes in the ESS. 	 */
specifier|const
name|u8
modifier|*
name|bssid_hint
decl_stmt|;
comment|/** 	 * ssid - The selected SSID 	 */
specifier|const
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/** 	 * ssid_len - Length of the SSID (1..32) 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * freq - channel parameters 	 */
name|struct
name|hostapd_freq_params
name|freq
decl_stmt|;
comment|/** 	 * freq_hint - Frequency of the channel the proposed AP is using 	 * 	 * This provides a channel on which a suitable BSS has been found as a 	 * hint for the driver. Unlike the @freq parameter, @freq_hint does not 	 * limit the driver from selecting other channels for 	 * driver/firmware-based BSS selection. 	 */
name|int
name|freq_hint
decl_stmt|;
comment|/** 	 * bg_scan_period - Background scan period in seconds, 0 to disable 	 * background scan, or -1 to indicate no change to default driver 	 * configuration 	 */
name|int
name|bg_scan_period
decl_stmt|;
comment|/** 	 * beacon_int - Beacon interval for IBSS or 0 to use driver default 	 */
name|int
name|beacon_int
decl_stmt|;
comment|/** 	 * wpa_ie - WPA information element for (Re)Association Request 	 * WPA information element to be included in (Re)Association 	 * Request (including information element id and length). Use 	 * of this WPA IE is optional. If the driver generates the WPA 	 * IE, it can use pairwise_suite, group_suite, and 	 * key_mgmt_suite to select proper algorithms. In this case, 	 * the driver has to notify wpa_supplicant about the used WPA 	 * IE by generating an event that the interface code will 	 * convert into EVENT_ASSOCINFO data (see below). 	 * 	 * When using WPA2/IEEE 802.11i, wpa_ie is used for RSN IE 	 * instead. The driver can determine which version is used by 	 * looking at the first byte of the IE (0xdd for WPA, 0x30 for 	 * WPA2/RSN). 	 * 	 * When using WPS, wpa_ie is used for WPS IE instead of WPA/RSN IE. 	 */
specifier|const
name|u8
modifier|*
name|wpa_ie
decl_stmt|;
comment|/** 	 * wpa_ie_len - length of the wpa_ie 	 */
name|size_t
name|wpa_ie_len
decl_stmt|;
comment|/** 	 * wpa_proto - Bitfield of WPA_PROTO_* values to indicate WPA/WPA2 	 */
name|unsigned
name|int
name|wpa_proto
decl_stmt|;
comment|/** 	 * pairwise_suite - Selected pairwise cipher suite (WPA_CIPHER_*) 	 * 	 * This is usually ignored if @wpa_ie is used. 	 */
name|unsigned
name|int
name|pairwise_suite
decl_stmt|;
comment|/** 	 * group_suite - Selected group cipher suite (WPA_CIPHER_*) 	 * 	 * This is usually ignored if @wpa_ie is used. 	 */
name|unsigned
name|int
name|group_suite
decl_stmt|;
comment|/** 	 * key_mgmt_suite - Selected key management suite (WPA_KEY_MGMT_*) 	 * 	 * This is usually ignored if @wpa_ie is used. 	 */
name|unsigned
name|int
name|key_mgmt_suite
decl_stmt|;
comment|/** 	 * auth_alg - Allowed authentication algorithms 	 * Bit field of WPA_AUTH_ALG_* 	 */
name|int
name|auth_alg
decl_stmt|;
comment|/** 	 * mode - Operation mode (infra/ibss) IEEE80211_MODE_* 	 */
name|int
name|mode
decl_stmt|;
comment|/** 	 * wep_key - WEP keys for static WEP configuration 	 */
specifier|const
name|u8
modifier|*
name|wep_key
index|[
literal|4
index|]
decl_stmt|;
comment|/** 	 * wep_key_len - WEP key length for static WEP configuration 	 */
name|size_t
name|wep_key_len
index|[
literal|4
index|]
decl_stmt|;
comment|/** 	 * wep_tx_keyidx - WEP TX key index for static WEP configuration 	 */
name|int
name|wep_tx_keyidx
decl_stmt|;
comment|/** 	 * mgmt_frame_protection - IEEE 802.11w management frame protection 	 */
name|enum
name|mfp_options
name|mgmt_frame_protection
decl_stmt|;
comment|/** 	 * ft_ies - IEEE 802.11r / FT information elements 	 * If the supplicant is using IEEE 802.11r (FT) and has the needed keys 	 * for fast transition, this parameter is set to include the IEs that 	 * are to be sent in the next FT Authentication Request message. 	 * update_ft_ies() handler is called to update the IEs for further 	 * FT messages in the sequence. 	 * 	 * The driver should use these IEs only if the target AP is advertising 	 * the same mobility domain as the one included in the MDIE here. 	 * 	 * In ap_scan=2 mode, the driver can use these IEs when moving to a new 	 * AP after the initial association. These IEs can only be used if the 	 * target AP is advertising support for FT and is using the same MDIE 	 * and SSID as the current AP. 	 * 	 * The driver is responsible for reporting the FT IEs received from the 	 * AP's response using wpa_supplicant_event() with EVENT_FT_RESPONSE 	 * type. update_ft_ies() handler will then be called with the FT IEs to 	 * include in the next frame in the authentication sequence. 	 */
specifier|const
name|u8
modifier|*
name|ft_ies
decl_stmt|;
comment|/** 	 * ft_ies_len - Length of ft_ies in bytes 	 */
name|size_t
name|ft_ies_len
decl_stmt|;
comment|/** 	 * ft_md - FT Mobility domain (6 octets) (also included inside ft_ies) 	 * 	 * This value is provided to allow the driver interface easier access 	 * to the current mobility domain. This value is set to %NULL if no 	 * mobility domain is currently active. 	 */
specifier|const
name|u8
modifier|*
name|ft_md
decl_stmt|;
comment|/** 	 * passphrase - RSN passphrase for PSK 	 * 	 * This value is made available only for WPA/WPA2-Personal (PSK) and 	 * only for drivers that set WPA_DRIVER_FLAGS_4WAY_HANDSHAKE. This is 	 * the 8..63 character ASCII passphrase, if available. Please note that 	 * this can be %NULL if passphrase was not used to generate the PSK. In 	 * that case, the psk field must be used to fetch the PSK. 	 */
specifier|const
name|char
modifier|*
name|passphrase
decl_stmt|;
comment|/** 	 * psk - RSN PSK (alternative for passphrase for PSK) 	 * 	 * This value is made available only for WPA/WPA2-Personal (PSK) and 	 * only for drivers that set WPA_DRIVER_FLAGS_4WAY_HANDSHAKE. This is 	 * the 32-octet (256-bit) PSK, if available. The driver wrapper should 	 * be prepared to handle %NULL value as an error. 	 */
specifier|const
name|u8
modifier|*
name|psk
decl_stmt|;
comment|/** 	 * drop_unencrypted - Enable/disable unencrypted frame filtering 	 * 	 * Configure the driver to drop all non-EAPOL frames (both receive and 	 * transmit paths). Unencrypted EAPOL frames (ethertype 0x888e) must 	 * still be allowed for key negotiation. 	 */
name|int
name|drop_unencrypted
decl_stmt|;
comment|/** 	 * prev_bssid - Previously used BSSID in this ESS 	 * 	 * When not %NULL, this is a request to use reassociation instead of 	 * association. 	 */
specifier|const
name|u8
modifier|*
name|prev_bssid
decl_stmt|;
comment|/** 	 * wps - WPS mode 	 * 	 * If the driver needs to do special configuration for WPS association, 	 * this variable provides more information on what type of association 	 * is being requested. Most drivers should not need ot use this. 	 */
name|enum
name|wps_mode
name|wps
decl_stmt|;
comment|/** 	 * p2p - Whether this connection is a P2P group 	 */
name|int
name|p2p
decl_stmt|;
comment|/** 	 * uapsd - UAPSD parameters for the network 	 * -1 = do not change defaults 	 * AP mode: 1 = enabled, 0 = disabled 	 * STA mode: bits 0..3 UAPSD enabled for VO,VI,BK,BE 	 */
name|int
name|uapsd
decl_stmt|;
comment|/** 	 * fixed_bssid - Whether to force this BSSID in IBSS mode 	 * 1 = Fix this BSSID and prevent merges. 	 * 0 = Do not fix BSSID. 	 */
name|int
name|fixed_bssid
decl_stmt|;
comment|/** 	 * fixed_freq - Fix control channel in IBSS mode 	 * 0 = don't fix control channel (default) 	 * 1 = fix control channel; this prevents IBSS merging with another 	 *	channel 	 */
name|int
name|fixed_freq
decl_stmt|;
comment|/** 	 * disable_ht - Disable HT (IEEE 802.11n) for this connection 	 */
name|int
name|disable_ht
decl_stmt|;
comment|/** 	 * htcaps - HT Capabilities over-rides 	 * 	 * Only bits set in the mask will be used, and not all values are used 	 * by the kernel anyway. Currently, MCS, MPDU and MSDU fields are used. 	 * 	 * Pointer to struct ieee80211_ht_capabilities. 	 */
specifier|const
name|u8
modifier|*
name|htcaps
decl_stmt|;
comment|/** 	 * htcaps_mask - HT Capabilities over-rides mask 	 * 	 * Pointer to struct ieee80211_ht_capabilities. 	 */
specifier|const
name|u8
modifier|*
name|htcaps_mask
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_VHT_OVERRIDES
comment|/** 	 * disable_vht - Disable VHT for this connection 	 */
name|int
name|disable_vht
decl_stmt|;
comment|/** 	 * VHT capability overrides. 	 */
specifier|const
name|struct
name|ieee80211_vht_capabilities
modifier|*
name|vhtcaps
decl_stmt|;
specifier|const
name|struct
name|ieee80211_vht_capabilities
modifier|*
name|vhtcaps_mask
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_VHT_OVERRIDES */
comment|/** 	 * req_key_mgmt_offload - Request key management offload for connection 	 * 	 * Request key management offload for this connection if the device 	 * supports it. 	 */
name|int
name|req_key_mgmt_offload
decl_stmt|;
comment|/** 	 * Flag for indicating whether this association includes support for 	 * RRM (Radio Resource Measurements) 	 */
name|int
name|rrm_used
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|hide_ssid
block|{
name|NO_SSID_HIDING
block|,
name|HIDDEN_SSID_ZERO_LEN
block|,
name|HIDDEN_SSID_ZERO_CONTENTS
block|}
enum|;
end_enum

begin_struct
struct|struct
name|wowlan_triggers
block|{
name|u8
name|any
decl_stmt|;
name|u8
name|disconnect
decl_stmt|;
name|u8
name|magic_pkt
decl_stmt|;
name|u8
name|gtk_rekey_failure
decl_stmt|;
name|u8
name|eap_identity_req
decl_stmt|;
name|u8
name|four_way_handshake
decl_stmt|;
name|u8
name|rfkill_release
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_driver_ap_params
block|{
comment|/** 	 * head - Beacon head from IEEE 802.11 header to IEs before TIM IE 	 */
name|u8
modifier|*
name|head
decl_stmt|;
comment|/** 	 * head_len - Length of the head buffer in octets 	 */
name|size_t
name|head_len
decl_stmt|;
comment|/** 	 * tail - Beacon tail following TIM IE 	 */
name|u8
modifier|*
name|tail
decl_stmt|;
comment|/** 	 * tail_len - Length of the tail buffer in octets 	 */
name|size_t
name|tail_len
decl_stmt|;
comment|/** 	 * dtim_period - DTIM period 	 */
name|int
name|dtim_period
decl_stmt|;
comment|/** 	 * beacon_int - Beacon interval 	 */
name|int
name|beacon_int
decl_stmt|;
comment|/** 	 * basic_rates: -1 terminated array of basic rates in 100 kbps 	 * 	 * This parameter can be used to set a specific basic rate set for the 	 * BSS. If %NULL, default basic rate set is used. 	 */
name|int
modifier|*
name|basic_rates
decl_stmt|;
comment|/** 	 * proberesp - Probe Response template 	 * 	 * This is used by drivers that reply to Probe Requests internally in 	 * AP mode and require the full Probe Response template. 	 */
name|u8
modifier|*
name|proberesp
decl_stmt|;
comment|/** 	 * proberesp_len - Length of the proberesp buffer in octets 	 */
name|size_t
name|proberesp_len
decl_stmt|;
comment|/** 	 * ssid - The SSID to use in Beacon/Probe Response frames 	 */
specifier|const
name|u8
modifier|*
name|ssid
decl_stmt|;
comment|/** 	 * ssid_len - Length of the SSID (1..32) 	 */
name|size_t
name|ssid_len
decl_stmt|;
comment|/** 	 * hide_ssid - Whether to hide the SSID 	 */
name|enum
name|hide_ssid
name|hide_ssid
decl_stmt|;
comment|/** 	 * pairwise_ciphers - WPA_CIPHER_* bitfield 	 */
name|unsigned
name|int
name|pairwise_ciphers
decl_stmt|;
comment|/** 	 * group_cipher - WPA_CIPHER_* 	 */
name|unsigned
name|int
name|group_cipher
decl_stmt|;
comment|/** 	 * key_mgmt_suites - WPA_KEY_MGMT_* bitfield 	 */
name|unsigned
name|int
name|key_mgmt_suites
decl_stmt|;
comment|/** 	 * auth_algs - WPA_AUTH_ALG_* bitfield 	 */
name|unsigned
name|int
name|auth_algs
decl_stmt|;
comment|/** 	 * wpa_version - WPA_PROTO_* bitfield 	 */
name|unsigned
name|int
name|wpa_version
decl_stmt|;
comment|/** 	 * privacy - Whether privacy is used in the BSS 	 */
name|int
name|privacy
decl_stmt|;
comment|/** 	 * beacon_ies - WPS/P2P IE(s) for Beacon frames 	 * 	 * This is used to add IEs like WPS IE and P2P IE by drivers that do 	 * not use the full Beacon template. 	 */
specifier|const
name|struct
name|wpabuf
modifier|*
name|beacon_ies
decl_stmt|;
comment|/** 	 * proberesp_ies - P2P/WPS IE(s) for Probe Response frames 	 * 	 * This is used to add IEs like WPS IE and P2P IE by drivers that 	 * reply to Probe Request frames internally. 	 */
specifier|const
name|struct
name|wpabuf
modifier|*
name|proberesp_ies
decl_stmt|;
comment|/** 	 * assocresp_ies - WPS IE(s) for (Re)Association Response frames 	 * 	 * This is used to add IEs like WPS IE by drivers that reply to 	 * (Re)Association Request frames internally. 	 */
specifier|const
name|struct
name|wpabuf
modifier|*
name|assocresp_ies
decl_stmt|;
comment|/** 	 * isolate - Whether to isolate frames between associated stations 	 * 	 * If this is non-zero, the AP is requested to disable forwarding of 	 * frames between associated stations. 	 */
name|int
name|isolate
decl_stmt|;
comment|/** 	 * cts_protect - Whether CTS protection is enabled 	 */
name|int
name|cts_protect
decl_stmt|;
comment|/** 	 * preamble - Whether short preamble is enabled 	 */
name|int
name|preamble
decl_stmt|;
comment|/** 	 * short_slot_time - Whether short slot time is enabled 	 * 	 * 0 = short slot time disable, 1 = short slot time enabled, -1 = do 	 * not set (e.g., when 802.11g mode is not in use) 	 */
name|int
name|short_slot_time
decl_stmt|;
comment|/** 	 * ht_opmode - HT operation mode or -1 if HT not in use 	 */
name|int
name|ht_opmode
decl_stmt|;
comment|/** 	 * interworking - Whether Interworking is enabled 	 */
name|int
name|interworking
decl_stmt|;
comment|/** 	 * hessid - Homogeneous ESS identifier or %NULL if not set 	 */
specifier|const
name|u8
modifier|*
name|hessid
decl_stmt|;
comment|/** 	 * access_network_type - Access Network Type (0..15) 	 * 	 * This is used for filtering Probe Request frames when Interworking is 	 * enabled. 	 */
name|u8
name|access_network_type
decl_stmt|;
comment|/** 	 * ap_max_inactivity - Timeout in seconds to detect STA's inactivity 	 * 	 * This is used by driver which advertises this capability. 	 */
name|int
name|ap_max_inactivity
decl_stmt|;
comment|/** 	 * ctwindow - Client Traffic Window (in TUs) 	 */
name|u8
name|p2p_go_ctwindow
decl_stmt|;
comment|/** 	 * smps_mode - SMPS mode 	 * 	 * SMPS mode to be used by the AP, specified as the relevant bits of 	 * ht_capab (i.e. HT_CAP_INFO_SMPS_*). 	 */
name|unsigned
name|int
name|smps_mode
decl_stmt|;
comment|/** 	 * disable_dgaf - Whether group-addressed frames are disabled 	 */
name|int
name|disable_dgaf
decl_stmt|;
comment|/** 	 * osen - Whether OSEN security is enabled 	 */
name|int
name|osen
decl_stmt|;
comment|/** 	 * freq - Channel parameters for dynamic bandwidth changes 	 */
name|struct
name|hostapd_freq_params
modifier|*
name|freq
decl_stmt|;
comment|/** 	 * reenable - Whether this is to re-enable beaconing 	 */
name|int
name|reenable
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_driver_mesh_bss_params
block|{
define|#
directive|define
name|WPA_DRIVER_MESH_CONF_FLAG_AUTO_PLINKS
value|0x00000001
comment|/* 	 * TODO: Other mesh configuration parameters would go here. 	 * See NL80211_MESHCONF_* for all the mesh config parameters. 	 */
name|unsigned
name|int
name|flags
decl_stmt|;
name|int
name|peer_link_timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_driver_mesh_join_params
block|{
specifier|const
name|u8
modifier|*
name|meshid
decl_stmt|;
name|int
name|meshid_len
decl_stmt|;
specifier|const
name|int
modifier|*
name|basic_rates
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ies
decl_stmt|;
name|int
name|ie_len
decl_stmt|;
name|struct
name|hostapd_freq_params
name|freq
decl_stmt|;
name|int
name|beacon_int
decl_stmt|;
name|int
name|max_peer_links
decl_stmt|;
name|struct
name|wpa_driver_mesh_bss_params
name|conf
decl_stmt|;
define|#
directive|define
name|WPA_DRIVER_MESH_FLAG_USER_MPM
value|0x00000001
define|#
directive|define
name|WPA_DRIVER_MESH_FLAG_DRIVER_MPM
value|0x00000002
define|#
directive|define
name|WPA_DRIVER_MESH_FLAG_SAE_AUTH
value|0x00000004
define|#
directive|define
name|WPA_DRIVER_MESH_FLAG_AMPE
value|0x00000008
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_driver_capa - Driver capability information  */
end_comment

begin_struct
struct|struct
name|wpa_driver_capa
block|{
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WPA
value|0x00000001
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WPA2
value|0x00000002
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WPA_PSK
value|0x00000004
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WPA2_PSK
value|0x00000008
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WPA_NONE
value|0x00000010
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_FT
value|0x00000020
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_FT_PSK
value|0x00000040
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_WAPI_PSK
value|0x00000080
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_SUITE_B
value|0x00000100
define|#
directive|define
name|WPA_DRIVER_CAPA_KEY_MGMT_SUITE_B_192
value|0x00000200
comment|/** Bitfield of supported key management suites */
name|unsigned
name|int
name|key_mgmt
decl_stmt|;
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_WEP40
value|0x00000001
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_WEP104
value|0x00000002
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_TKIP
value|0x00000004
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_CCMP
value|0x00000008
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_WEP128
value|0x00000010
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_GCMP
value|0x00000020
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_GCMP_256
value|0x00000040
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_CCMP_256
value|0x00000080
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_BIP
value|0x00000100
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_BIP_GMAC_128
value|0x00000200
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_BIP_GMAC_256
value|0x00000400
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_BIP_CMAC_256
value|0x00000800
define|#
directive|define
name|WPA_DRIVER_CAPA_ENC_GTK_NOT_USED
value|0x00001000
comment|/** Bitfield of supported cipher suites */
name|unsigned
name|int
name|enc
decl_stmt|;
define|#
directive|define
name|WPA_DRIVER_AUTH_OPEN
value|0x00000001
define|#
directive|define
name|WPA_DRIVER_AUTH_SHARED
value|0x00000002
define|#
directive|define
name|WPA_DRIVER_AUTH_LEAP
value|0x00000004
comment|/** Bitfield of supported IEEE 802.11 authentication algorithms */
name|unsigned
name|int
name|auth
decl_stmt|;
comment|/** Driver generated WPA/RSN IE */
define|#
directive|define
name|WPA_DRIVER_FLAGS_DRIVER_IE
value|0x00000001
comment|/** Driver needs static WEP key setup after association command */
define|#
directive|define
name|WPA_DRIVER_FLAGS_SET_KEYS_AFTER_ASSOC
value|0x00000002
comment|/** Driver takes care of all DFS operations */
define|#
directive|define
name|WPA_DRIVER_FLAGS_DFS_OFFLOAD
value|0x00000004
comment|/** Driver takes care of RSN 4-way handshake internally; PMK is configured with  * struct wpa_driver_ops::set_key using alg = WPA_ALG_PMK */
define|#
directive|define
name|WPA_DRIVER_FLAGS_4WAY_HANDSHAKE
value|0x00000008
comment|/** Driver is for a wired Ethernet interface */
define|#
directive|define
name|WPA_DRIVER_FLAGS_WIRED
value|0x00000010
comment|/** Driver provides separate commands for authentication and association (SME in  * wpa_supplicant). */
define|#
directive|define
name|WPA_DRIVER_FLAGS_SME
value|0x00000020
comment|/** Driver supports AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_AP
value|0x00000040
comment|/** Driver needs static WEP key setup after association has been completed */
define|#
directive|define
name|WPA_DRIVER_FLAGS_SET_KEYS_AFTER_ASSOC_DONE
value|0x00000080
comment|/** Driver supports dynamic HT 20/40 MHz channel changes during BSS lifetime */
define|#
directive|define
name|WPA_DRIVER_FLAGS_HT_2040_COEX
value|0x00000100
comment|/** Driver supports concurrent P2P operations */
define|#
directive|define
name|WPA_DRIVER_FLAGS_P2P_CONCURRENT
value|0x00000200
comment|/**  * Driver uses the initial interface as a dedicated management interface, i.e.,  * it cannot be used for P2P group operations or non-P2P purposes.  */
define|#
directive|define
name|WPA_DRIVER_FLAGS_P2P_DEDICATED_INTERFACE
value|0x00000400
comment|/** This interface is P2P capable (P2P GO or P2P Client) */
define|#
directive|define
name|WPA_DRIVER_FLAGS_P2P_CAPABLE
value|0x00000800
comment|/** Driver supports station and key removal when stopping an AP */
define|#
directive|define
name|WPA_DRIVER_FLAGS_AP_TEARDOWN_SUPPORT
value|0x00001000
comment|/**  * Driver uses the initial interface for P2P management interface and non-P2P  * purposes (e.g., connect to infra AP), but this interface cannot be used for  * P2P group operations.  */
define|#
directive|define
name|WPA_DRIVER_FLAGS_P2P_MGMT_AND_NON_P2P
value|0x00002000
comment|/**  * Driver is known to use sane error codes, i.e., when it indicates that  * something (e.g., association) fails, there was indeed a failure and the  * operation does not end up getting completed successfully later.  */
define|#
directive|define
name|WPA_DRIVER_FLAGS_SANE_ERROR_CODES
value|0x00004000
comment|/** Driver supports off-channel TX */
define|#
directive|define
name|WPA_DRIVER_FLAGS_OFFCHANNEL_TX
value|0x00008000
comment|/** Driver indicates TX status events for EAPOL Data frames */
define|#
directive|define
name|WPA_DRIVER_FLAGS_EAPOL_TX_STATUS
value|0x00010000
comment|/** Driver indicates TX status events for Deauth/Disassoc frames */
define|#
directive|define
name|WPA_DRIVER_FLAGS_DEAUTH_TX_STATUS
value|0x00020000
comment|/** Driver supports roaming (BSS selection) in firmware */
define|#
directive|define
name|WPA_DRIVER_FLAGS_BSS_SELECTION
value|0x00040000
comment|/** Driver supports operating as a TDLS peer */
define|#
directive|define
name|WPA_DRIVER_FLAGS_TDLS_SUPPORT
value|0x00080000
comment|/** Driver requires external TDLS setup/teardown/discovery */
define|#
directive|define
name|WPA_DRIVER_FLAGS_TDLS_EXTERNAL_SETUP
value|0x00100000
comment|/** Driver indicates support for Probe Response offloading in AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_PROBE_RESP_OFFLOAD
value|0x00200000
comment|/** Driver supports U-APSD in AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_AP_UAPSD
value|0x00400000
comment|/** Driver supports inactivity timer in AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_INACTIVITY_TIMER
value|0x00800000
comment|/** Driver expects user space implementation of MLME in AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_AP_MLME
value|0x01000000
comment|/** Driver supports SAE with user space SME */
define|#
directive|define
name|WPA_DRIVER_FLAGS_SAE
value|0x02000000
comment|/** Driver makes use of OBSS scan mechanism in wpa_supplicant */
define|#
directive|define
name|WPA_DRIVER_FLAGS_OBSS_SCAN
value|0x04000000
comment|/** Driver supports IBSS (Ad-hoc) mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_IBSS
value|0x08000000
comment|/** Driver supports radar detection */
define|#
directive|define
name|WPA_DRIVER_FLAGS_RADAR
value|0x10000000
comment|/** Driver supports a dedicated interface for P2P Device */
define|#
directive|define
name|WPA_DRIVER_FLAGS_DEDICATED_P2P_DEVICE
value|0x20000000
comment|/** Driver supports QoS Mapping */
define|#
directive|define
name|WPA_DRIVER_FLAGS_QOS_MAPPING
value|0x40000000
comment|/** Driver supports CSA in AP mode */
define|#
directive|define
name|WPA_DRIVER_FLAGS_AP_CSA
value|0x80000000
comment|/** Driver supports mesh */
define|#
directive|define
name|WPA_DRIVER_FLAGS_MESH
value|0x0000000100000000ULL
comment|/** Driver support ACS offload */
define|#
directive|define
name|WPA_DRIVER_FLAGS_ACS_OFFLOAD
value|0x0000000200000000ULL
comment|/** Driver supports key management offload */
define|#
directive|define
name|WPA_DRIVER_FLAGS_KEY_MGMT_OFFLOAD
value|0x0000000400000000ULL
comment|/** Driver supports TDLS channel switching */
define|#
directive|define
name|WPA_DRIVER_FLAGS_TDLS_CHANNEL_SWITCH
value|0x0000000800000000ULL
comment|/** Driver supports IBSS with HT datarates */
define|#
directive|define
name|WPA_DRIVER_FLAGS_HT_IBSS
value|0x0000001000000000ULL
comment|/** Driver supports IBSS with VHT datarates */
define|#
directive|define
name|WPA_DRIVER_FLAGS_VHT_IBSS
value|0x0000002000000000ULL
name|u64
name|flags
decl_stmt|;
define|#
directive|define
name|WPA_DRIVER_SMPS_MODE_STATIC
value|0x00000001
define|#
directive|define
name|WPA_DRIVER_SMPS_MODE_DYNAMIC
value|0x00000002
name|unsigned
name|int
name|smps_modes
decl_stmt|;
name|unsigned
name|int
name|wmm_ac_supported
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|mac_addr_rand_scan_supported
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|mac_addr_rand_sched_scan_supported
range|:
literal|1
decl_stmt|;
comment|/** Maximum number of supported active probe SSIDs */
name|int
name|max_scan_ssids
decl_stmt|;
comment|/** Maximum number of supported active probe SSIDs for sched_scan */
name|int
name|max_sched_scan_ssids
decl_stmt|;
comment|/** Whether sched_scan (offloaded scanning) is supported */
name|int
name|sched_scan_supported
decl_stmt|;
comment|/** Maximum number of supported match sets for sched_scan */
name|int
name|max_match_sets
decl_stmt|;
comment|/** 	 * max_remain_on_chan - Maximum remain-on-channel duration in msec 	 */
name|unsigned
name|int
name|max_remain_on_chan
decl_stmt|;
comment|/** 	 * max_stations - Maximum number of associated stations the driver 	 * supports in AP mode 	 */
name|unsigned
name|int
name|max_stations
decl_stmt|;
comment|/** 	 * probe_resp_offloads - Bitmap of supported protocols by the driver 	 * for Probe Response offloading. 	 */
comment|/** Driver Probe Response offloading support for WPS ver. 1 */
define|#
directive|define
name|WPA_DRIVER_PROBE_RESP_OFFLOAD_WPS
value|0x00000001
comment|/** Driver Probe Response offloading support for WPS ver. 2 */
define|#
directive|define
name|WPA_DRIVER_PROBE_RESP_OFFLOAD_WPS2
value|0x00000002
comment|/** Driver Probe Response offloading support for P2P */
define|#
directive|define
name|WPA_DRIVER_PROBE_RESP_OFFLOAD_P2P
value|0x00000004
comment|/** Driver Probe Response offloading support for IEEE 802.11u (Interworking) */
define|#
directive|define
name|WPA_DRIVER_PROBE_RESP_OFFLOAD_INTERWORKING
value|0x00000008
name|unsigned
name|int
name|probe_resp_offloads
decl_stmt|;
name|unsigned
name|int
name|max_acl_mac_addrs
decl_stmt|;
comment|/** 	 * Number of supported concurrent channels 	 */
name|unsigned
name|int
name|num_multichan_concurrent
decl_stmt|;
comment|/** 	 * extended_capa - extended capabilities in driver/device 	 * 	 * Must be allocated and freed by driver and the pointers must be 	 * valid for the lifetime of the driver, i.e., freed in deinit() 	 */
specifier|const
name|u8
modifier|*
name|extended_capa
decl_stmt|,
modifier|*
name|extended_capa_mask
decl_stmt|;
name|unsigned
name|int
name|extended_capa_len
decl_stmt|;
name|struct
name|wowlan_triggers
name|wowlan_triggers
decl_stmt|;
comment|/** Driver adds the DS Params Set IE in Probe Request frames */
define|#
directive|define
name|WPA_DRIVER_FLAGS_DS_PARAM_SET_IE_IN_PROBES
value|0x00000001
comment|/** Driver adds the WFA TPC IE in Probe Request frames */
define|#
directive|define
name|WPA_DRIVER_FLAGS_WFA_TPC_IE_IN_PROBES
value|0x00000002
comment|/** Driver handles quiet period requests */
define|#
directive|define
name|WPA_DRIVER_FLAGS_QUIET
value|0x00000004
comment|/**  * Driver is capable of inserting the current TX power value into the body of  * transmitted frames.  * Background: Some Action frames include a TPC Report IE. This IE contains a  * TX power field, which has to be updated by lower layers. One such Action  * frame is Link Measurement Report (part of RRM). Another is TPC Report (part  * of spectrum management). Note that this insertion takes place at a fixed  * offset, namely the 6th byte in the Action frame body.  */
define|#
directive|define
name|WPA_DRIVER_FLAGS_TX_POWER_INSERTION
value|0x00000008
name|u32
name|rrm_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|hostapd_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|hostap_sta_driver_data
block|{
name|unsigned
name|long
name|rx_packets
decl_stmt|,
name|tx_packets
decl_stmt|,
name|rx_bytes
decl_stmt|,
name|tx_bytes
decl_stmt|;
name|unsigned
name|long
name|current_tx_rate
decl_stmt|;
name|unsigned
name|long
name|inactive_msec
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|unsigned
name|long
name|num_ps_buf_frames
decl_stmt|;
name|unsigned
name|long
name|tx_retry_failed
decl_stmt|;
name|unsigned
name|long
name|tx_retry_count
decl_stmt|;
name|int
name|last_rssi
decl_stmt|;
name|int
name|last_ack_rssi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hostapd_sta_add_params
block|{
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
name|u16
name|aid
decl_stmt|;
name|u16
name|capability
decl_stmt|;
specifier|const
name|u8
modifier|*
name|supp_rates
decl_stmt|;
name|size_t
name|supp_rates_len
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
specifier|const
name|struct
name|ieee80211_ht_capabilities
modifier|*
name|ht_capabilities
decl_stmt|;
specifier|const
name|struct
name|ieee80211_vht_capabilities
modifier|*
name|vht_capabilities
decl_stmt|;
name|int
name|vht_opmode_enabled
decl_stmt|;
name|u8
name|vht_opmode
decl_stmt|;
name|u32
name|flags
decl_stmt|;
comment|/* bitmask of WPA_STA_* flags */
name|u32
name|flags_mask
decl_stmt|;
comment|/* unset bits in flags */
ifdef|#
directive|ifdef
name|CONFIG_MESH
name|enum
name|mesh_plink_state
name|plink_state
decl_stmt|;
endif|#
directive|endif
comment|/* CONFIG_MESH */
name|int
name|set
decl_stmt|;
comment|/* Set STA parameters instead of add */
name|u8
name|qosinfo
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ext_capab
decl_stmt|;
name|size_t
name|ext_capab_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|supp_channels
decl_stmt|;
name|size_t
name|supp_channels_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|supp_oper_classes
decl_stmt|;
name|size_t
name|supp_oper_classes_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_address
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hostapd_acl_params
block|{
name|u8
name|acl_policy
decl_stmt|;
name|unsigned
name|int
name|num_mac_acl
decl_stmt|;
name|struct
name|mac_address
name|mac_acl
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|wpa_driver_if_type
block|{
comment|/** 	 * WPA_IF_STATION - Station mode interface 	 */
name|WPA_IF_STATION
block|,
comment|/** 	 * WPA_IF_AP_VLAN - AP mode VLAN interface 	 * 	 * This interface shares its address and Beacon frame with the main 	 * BSS. 	 */
name|WPA_IF_AP_VLAN
block|,
comment|/** 	 * WPA_IF_AP_BSS - AP mode BSS interface 	 * 	 * This interface has its own address and Beacon frame. 	 */
name|WPA_IF_AP_BSS
block|,
comment|/** 	 * WPA_IF_P2P_GO - P2P Group Owner 	 */
name|WPA_IF_P2P_GO
block|,
comment|/** 	 * WPA_IF_P2P_CLIENT - P2P Client 	 */
name|WPA_IF_P2P_CLIENT
block|,
comment|/** 	 * WPA_IF_P2P_GROUP - P2P Group interface (will become either 	 * WPA_IF_P2P_GO or WPA_IF_P2P_CLIENT, but the role is not yet known) 	 */
name|WPA_IF_P2P_GROUP
block|,
comment|/** 	 * WPA_IF_P2P_DEVICE - P2P Device interface is used to indentify the 	 * abstracted P2P Device function in the driver 	 */
name|WPA_IF_P2P_DEVICE
block|,
comment|/* 	 * WPA_IF_MESH - Mesh interface 	 */
name|WPA_IF_MESH
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|wpa_init_params
block|{
name|void
modifier|*
name|global_priv
decl_stmt|;
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
specifier|const
name|char
modifier|*
name|ifname
decl_stmt|;
specifier|const
name|char
modifier|*
name|driver_params
decl_stmt|;
name|int
name|use_pae_group_addr
decl_stmt|;
name|char
modifier|*
modifier|*
name|bridge
decl_stmt|;
name|size_t
name|num_bridge
decl_stmt|;
name|u8
modifier|*
name|own_addr
decl_stmt|;
comment|/* buffer for writing own MAC address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wpa_bss_params
block|{
comment|/** Interface name (for multi-SSID/VLAN support) */
specifier|const
name|char
modifier|*
name|ifname
decl_stmt|;
comment|/** Whether IEEE 802.1X or WPA/WPA2 is enabled */
name|int
name|enabled
decl_stmt|;
name|int
name|wpa
decl_stmt|;
name|int
name|ieee802_1x
decl_stmt|;
name|int
name|wpa_group
decl_stmt|;
name|int
name|wpa_pairwise
decl_stmt|;
name|int
name|wpa_key_mgmt
decl_stmt|;
name|int
name|rsn_preauth
decl_stmt|;
name|enum
name|mfp_options
name|ieee80211w
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WPA_STA_AUTHORIZED
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WPA_STA_WMM
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WPA_STA_SHORT_PREAMBLE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WPA_STA_MFP
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WPA_STA_TDLS_PEER
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WPA_STA_AUTHENTICATED
value|BIT(5)
end_define

begin_enum
enum|enum
name|tdls_oper
block|{
name|TDLS_DISCOVERY_REQ
block|,
name|TDLS_SETUP
block|,
name|TDLS_TEARDOWN
block|,
name|TDLS_ENABLE_LINK
block|,
name|TDLS_DISABLE_LINK
block|,
name|TDLS_ENABLE
block|,
name|TDLS_DISABLE
block|}
enum|;
end_enum

begin_enum
enum|enum
name|wnm_oper
block|{
name|WNM_SLEEP_ENTER_CONFIRM
block|,
name|WNM_SLEEP_ENTER_FAIL
block|,
name|WNM_SLEEP_EXIT_CONFIRM
block|,
name|WNM_SLEEP_EXIT_FAIL
block|,
name|WNM_SLEEP_TFS_REQ_IE_ADD
block|,
comment|/* STA requests driver to add TFS req IE */
name|WNM_SLEEP_TFS_REQ_IE_NONE
block|,
comment|/* STA requests empty TFS req IE */
name|WNM_SLEEP_TFS_REQ_IE_SET
block|,
comment|/* AP requests driver to set TFS req IE for 				     * a STA */
name|WNM_SLEEP_TFS_RESP_IE_ADD
block|,
comment|/* AP requests driver to add TFS resp IE 				     * for a STA */
name|WNM_SLEEP_TFS_RESP_IE_NONE
block|,
comment|/* AP requests empty TFS resp IE */
name|WNM_SLEEP_TFS_RESP_IE_SET
block|,
comment|/* AP requests driver to set TFS resp IE 				     * for a STA */
name|WNM_SLEEP_TFS_IE_DEL
comment|/* AP delete the TFS IE */
block|}
enum|;
end_enum

begin_comment
comment|/* enum chan_width - Channel width definitions */
end_comment

begin_enum
enum|enum
name|chan_width
block|{
name|CHAN_WIDTH_20_NOHT
block|,
name|CHAN_WIDTH_20
block|,
name|CHAN_WIDTH_40
block|,
name|CHAN_WIDTH_80
block|,
name|CHAN_WIDTH_80P80
block|,
name|CHAN_WIDTH_160
block|,
name|CHAN_WIDTH_UNKNOWN
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct wpa_signal_info - Information about channel signal quality  */
end_comment

begin_struct
struct|struct
name|wpa_signal_info
block|{
name|u32
name|frequency
decl_stmt|;
name|int
name|above_threshold
decl_stmt|;
name|int
name|current_signal
decl_stmt|;
name|int
name|avg_signal
decl_stmt|;
name|int
name|current_noise
decl_stmt|;
name|int
name|current_txrate
decl_stmt|;
name|enum
name|chan_width
name|chanwidth
decl_stmt|;
name|int
name|center_frq1
decl_stmt|;
name|int
name|center_frq2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct beacon_data - Beacon data  * @head: Head portion of Beacon frame (before TIM IE)  * @tail: Tail portion of Beacon frame (after TIM IE)  * @beacon_ies: Extra information element(s) to add into Beacon frames or %NULL  * @proberesp_ies: Extra information element(s) to add into Probe Response  *	frames or %NULL  * @assocresp_ies: Extra information element(s) to add into (Re)Association  *	Response frames or %NULL  * @probe_resp: Probe Response frame template  * @head_len: Length of @head  * @tail_len: Length of @tail  * @beacon_ies_len: Length of beacon_ies in octets  * @proberesp_ies_len: Length of proberesp_ies in octets  * @proberesp_ies_len: Length of proberesp_ies in octets  * @probe_resp_len: Length of probe response template (@probe_resp)  */
end_comment

begin_struct
struct|struct
name|beacon_data
block|{
name|u8
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|u8
modifier|*
name|beacon_ies
decl_stmt|;
name|u8
modifier|*
name|proberesp_ies
decl_stmt|;
name|u8
modifier|*
name|assocresp_ies
decl_stmt|;
name|u8
modifier|*
name|probe_resp
decl_stmt|;
name|size_t
name|head_len
decl_stmt|,
name|tail_len
decl_stmt|;
name|size_t
name|beacon_ies_len
decl_stmt|;
name|size_t
name|proberesp_ies_len
decl_stmt|;
name|size_t
name|assocresp_ies_len
decl_stmt|;
name|size_t
name|probe_resp_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct csa_settings - Settings for channel switch command  * @cs_count: Count in Beacon frames (TBTT) to perform the switch  * @block_tx: 1 - block transmission for CSA period  * @freq_params: Next channel frequency parameter  * @beacon_csa: Beacon/probe resp/asooc resp info for CSA period  * @beacon_after: Next beacon/probe resp/asooc resp info  * @counter_offset_beacon: Offset to the count field in beacon's tail  * @counter_offset_presp: Offset to the count field in probe resp.  */
end_comment

begin_struct
struct|struct
name|csa_settings
block|{
name|u8
name|cs_count
decl_stmt|;
name|u8
name|block_tx
decl_stmt|;
name|struct
name|hostapd_freq_params
name|freq_params
decl_stmt|;
name|struct
name|beacon_data
name|beacon_csa
decl_stmt|;
name|struct
name|beacon_data
name|beacon_after
decl_stmt|;
name|u16
name|counter_offset_beacon
decl_stmt|;
name|u16
name|counter_offset_presp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* TDLS peer capabilities for send_tdls_mgmt() */
end_comment

begin_enum
enum|enum
name|tdls_peer_capability
block|{
name|TDLS_PEER_HT
init|=
name|BIT
argument_list|(
literal|0
argument_list|)
block|,
name|TDLS_PEER_VHT
init|=
name|BIT
argument_list|(
literal|1
argument_list|)
block|,
name|TDLS_PEER_WMM
init|=
name|BIT
argument_list|(
literal|2
argument_list|)
block|, }
enum|;
end_enum

begin_comment
comment|/* valid info in the wmm_params struct */
end_comment

begin_enum
enum|enum
name|wmm_params_valid_info
block|{
name|WMM_PARAMS_UAPSD_QUEUES_INFO
init|=
name|BIT
argument_list|(
literal|0
argument_list|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct wmm_params - WMM parameterss configured for this association  * @info_bitmap: Bitmap of valid wmm_params info; indicates what fields  *	of the struct contain valid information.  * @uapsd_queues: Bitmap of ACs configured for uapsd (valid only if  *	%WMM_PARAMS_UAPSD_QUEUES_INFO is set)  */
end_comment

begin_struct
struct|struct
name|wmm_params
block|{
name|u8
name|info_bitmap
decl_stmt|;
name|u8
name|uapsd_queues
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_MACSEC
end_ifdef

begin_struct
struct|struct
name|macsec_init_params
block|{
name|Boolean
name|always_include_sci
decl_stmt|;
name|Boolean
name|use_es
decl_stmt|;
name|Boolean
name|use_scb
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_MACSEC */
end_comment

begin_enum
enum|enum
name|drv_br_port_attr
block|{
name|DRV_BR_PORT_ATTR_PROXYARP
block|,
name|DRV_BR_PORT_ATTR_HAIRPIN_MODE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|drv_br_net_param
block|{
name|DRV_BR_NET_PARAM_GARP_ACCEPT
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|drv_acs_params
block|{
comment|/* Selected mode (HOSTAPD_MODE_*) */
name|enum
name|hostapd_hw_mode
name|hw_mode
decl_stmt|;
comment|/* Indicates whether HT is enabled */
name|int
name|ht_enabled
decl_stmt|;
comment|/* Indicates whether HT40 is enabled */
name|int
name|ht40_enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct wpa_driver_ops - Driver interface API definition  *  * This structure defines the API that each driver interface needs to implement  * for core wpa_supplicant code. All driver specific functionality is captured  * in this wrapper.  */
end_comment

begin_struct
struct|struct
name|wpa_driver_ops
block|{
comment|/** Name of the driver interface */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** One line description of the driver interface */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/** 	 * get_bssid - Get the current BSSID 	 * @priv: private driver interface data 	 * @bssid: buffer for BSSID (ETH_ALEN = 6 bytes) 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Query kernel driver for the current BSSID and copy it to bssid. 	 * Setting bssid to 00:00:00:00:00:00 is recommended if the STA is not 	 * associated. 	 */
name|int
function_decl|(
modifier|*
name|get_bssid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
modifier|*
name|bssid
parameter_list|)
function_decl|;
comment|/** 	 * get_ssid - Get the current SSID 	 * @priv: private driver interface data 	 * @ssid: buffer for SSID (at least 32 bytes) 	 * 	 * Returns: Length of the SSID on success, -1 on failure 	 * 	 * Query kernel driver for the current SSID and copy it to ssid. 	 * Returning zero is recommended if the STA is not associated. 	 * 	 * Note: SSID is an array of octets, i.e., it is not nul terminated and 	 * can, at least in theory, contain control characters (including nul) 	 * and as such, should be processed as binary data, not a printable 	 * string. 	 */
name|int
function_decl|(
modifier|*
name|get_ssid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
modifier|*
name|ssid
parameter_list|)
function_decl|;
comment|/** 	 * set_key - Configure encryption key 	 * @ifname: Interface name (for multi-SSID/VLAN support) 	 * @priv: private driver interface data 	 * @alg: encryption algorithm (%WPA_ALG_NONE, %WPA_ALG_WEP, 	 *	%WPA_ALG_TKIP, %WPA_ALG_CCMP, %WPA_ALG_IGTK, %WPA_ALG_PMK, 	 *	%WPA_ALG_GCMP, %WPA_ALG_GCMP_256, %WPA_ALG_CCMP_256, 	 *	%WPA_ALG_BIP_GMAC_128, %WPA_ALG_BIP_GMAC_256, 	 *	%WPA_ALG_BIP_CMAC_256); 	 *	%WPA_ALG_NONE clears the key. 	 * @addr: Address of the peer STA (BSSID of the current AP when setting 	 *	pairwise key in station mode), ff:ff:ff:ff:ff:ff for 	 *	broadcast keys, %NULL for default keys that are used both for 	 *	broadcast and unicast; when clearing keys, %NULL is used to 	 *	indicate that both the broadcast-only and default key of the 	 *	specified key index is to be cleared 	 * @key_idx: key index (0..3), usually 0 for unicast keys; 0..4095 for 	 *	IGTK 	 * @set_tx: configure this key as the default Tx key (only used when 	 *	driver does not support separate unicast/individual key 	 * @seq: sequence number/packet number, seq_len octets, the next 	 *	packet number to be used for in replay protection; configured 	 *	for Rx keys (in most cases, this is only used with broadcast 	 *	keys and set to zero for unicast keys); %NULL if not set 	 * @seq_len: length of the seq, depends on the algorithm: 	 *	TKIP: 6 octets, CCMP/GCMP: 6 octets, IGTK: 6 octets 	 * @key: key buffer; TKIP: 16-byte temporal key, 8-byte Tx Mic key, 	 *	8-byte Rx Mic Key 	 * @key_len: length of the key buffer in octets (WEP: 5 or 13, 	 *	TKIP: 32, CCMP/GCMP: 16, IGTK: 16) 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Configure the given key for the kernel driver. If the driver 	 * supports separate individual keys (4 default keys + 1 individual), 	 * addr can be used to determine whether the key is default or 	 * individual. If only 4 keys are supported, the default key with key 	 * index 0 is used as the individual key. STA must be configured to use 	 * it as the default Tx key (set_tx is set) and accept Rx for all the 	 * key indexes. In most cases, WPA uses only key indexes 1 and 2 for 	 * broadcast keys, so key index 0 is available for this kind of 	 * configuration. 	 * 	 * Please note that TKIP keys include separate TX and RX MIC keys and 	 * some drivers may expect them in different order than wpa_supplicant 	 * is using. If the TX/RX keys are swapped, all TKIP encrypted packets 	 * will trigger Michael MIC errors. This can be fixed by changing the 	 * order of MIC keys by swapping te bytes 16..23 and 24..31 of the key 	 * in driver_*.c set_key() implementation, see driver_ndis.c for an 	 * example on how this can be done. 	 */
name|int
function_decl|(
modifier|*
name|set_key
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|wpa_alg
name|alg
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|key_idx
parameter_list|,
name|int
name|set_tx
parameter_list|,
specifier|const
name|u8
modifier|*
name|seq
parameter_list|,
name|size_t
name|seq_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
comment|/** 	 * init - Initialize driver interface 	 * @ctx: context to be used when calling wpa_supplicant functions, 	 * e.g., wpa_supplicant_event() 	 * @ifname: interface name, e.g., wlan0 	 * 	 * Returns: Pointer to private data, %NULL on failure 	 * 	 * Initialize driver interface, including event processing for kernel 	 * driver events (e.g., associated, scan results, Michael MIC failure). 	 * This function can allocate a private configuration data area for 	 * @ctx, file descriptor, interface name, etc. information that may be 	 * needed in future driver operations. If this is not used, non-NULL 	 * value will need to be returned because %NULL is used to indicate 	 * failure. The returned value will be used as 'void *priv' data for 	 * all other driver_ops functions. 	 * 	 * The main event loop (eloop.c) of wpa_supplicant can be used to 	 * register callback for read sockets (eloop_register_read_sock()). 	 * 	 * See below for more information about events and 	 * wpa_supplicant_event() function. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
comment|/** 	 * deinit - Deinitialize driver interface 	 * @priv: private driver interface data from init() 	 * 	 * Shut down driver interface and processing of driver events. Free 	 * private data buffer if one was allocated in init() handler. 	 */
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * set_param - Set driver configuration parameters 	 * @priv: private driver interface data from init() 	 * @param: driver specific configuration parameters 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Optional handler for notifying driver interface about configuration 	 * parameters (driver_param). 	 */
name|int
function_decl|(
modifier|*
name|set_param
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|char
modifier|*
name|param
parameter_list|)
function_decl|;
comment|/** 	 * set_countermeasures - Enable/disable TKIP countermeasures 	 * @priv: private driver interface data 	 * @enabled: 1 = countermeasures enabled, 0 = disabled 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Configure TKIP countermeasures. When these are enabled, the driver 	 * should drop all received and queued frames that are using TKIP. 	 */
name|int
function_decl|(
modifier|*
name|set_countermeasures
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
comment|/** 	 * deauthenticate - Request driver to deauthenticate 	 * @priv: private driver interface data 	 * @addr: peer address (BSSID of the AP) 	 * @reason_code: 16-bit reason code to be sent in the deauthentication 	 *	frame 	 * 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|deauthenticate
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|reason_code
parameter_list|)
function_decl|;
comment|/** 	 * associate - Request driver to associate 	 * @priv: private driver interface data 	 * @params: association parameters 	 * 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|associate
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_associate_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * add_pmkid - Add PMKSA cache entry to the driver 	 * @priv: private driver interface data 	 * @bssid: BSSID for the PMKSA cache entry 	 * @pmkid: PMKID for the PMKSA cache entry 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is called when a new PMK is received, as a result of 	 * either normal authentication or RSN pre-authentication. 	 * 	 * If the driver generates RSN IE, i.e., it does not use wpa_ie in 	 * associate(), add_pmkid() can be used to add new PMKSA cache entries 	 * in the driver. If the driver uses wpa_ie from wpa_supplicant, this 	 * driver_ops function does not need to be implemented. Likewise, if 	 * the driver does not support WPA, this function is not needed. 	 */
name|int
function_decl|(
modifier|*
name|add_pmkid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|pmkid
parameter_list|)
function_decl|;
comment|/** 	 * remove_pmkid - Remove PMKSA cache entry to the driver 	 * @priv: private driver interface data 	 * @bssid: BSSID for the PMKSA cache entry 	 * @pmkid: PMKID for the PMKSA cache entry 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is called when the supplicant drops a PMKSA cache 	 * entry for any reason. 	 * 	 * If the driver generates RSN IE, i.e., it does not use wpa_ie in 	 * associate(), remove_pmkid() can be used to synchronize PMKSA caches 	 * between the driver and wpa_supplicant. If the driver uses wpa_ie 	 * from wpa_supplicant, this driver_ops function does not need to be 	 * implemented. Likewise, if the driver does not support WPA, this 	 * function is not needed. 	 */
name|int
function_decl|(
modifier|*
name|remove_pmkid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|pmkid
parameter_list|)
function_decl|;
comment|/** 	 * flush_pmkid - Flush PMKSA cache 	 * @priv: private driver interface data 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is called when the supplicant drops all PMKSA cache 	 * entries for any reason. 	 * 	 * If the driver generates RSN IE, i.e., it does not use wpa_ie in 	 * associate(), remove_pmkid() can be used to synchronize PMKSA caches 	 * between the driver and wpa_supplicant. If the driver uses wpa_ie 	 * from wpa_supplicant, this driver_ops function does not need to be 	 * implemented. Likewise, if the driver does not support WPA, this 	 * function is not needed. 	 */
name|int
function_decl|(
modifier|*
name|flush_pmkid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * get_capa - Get driver capabilities 	 * @priv: private driver interface data 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Get driver/firmware/hardware capabilities. 	 */
name|int
function_decl|(
modifier|*
name|get_capa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_capa
modifier|*
name|capa
parameter_list|)
function_decl|;
comment|/** 	 * poll - Poll driver for association information 	 * @priv: private driver interface data 	 * 	 * This is an option callback that can be used when the driver does not 	 * provide event mechanism for association events. This is called when 	 * receiving WPA EAPOL-Key messages that require association 	 * information. The driver interface is supposed to generate associnfo 	 * event before returning from this callback function. In addition, the 	 * driver interface should generate an association event after having 	 * sent out associnfo. 	 */
name|void
function_decl|(
modifier|*
name|poll
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * get_ifname - Get interface name 	 * @priv: private driver interface data 	 * 	 * Returns: Pointer to the interface name. This can differ from the 	 * interface name used in init() call. Init() is called first. 	 * 	 * This optional function can be used to allow the driver interface to 	 * replace the interface name with something else, e.g., based on an 	 * interface mapping from a more descriptive name. 	 */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|get_ifname
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * get_mac_addr - Get own MAC address 	 * @priv: private driver interface data 	 * 	 * Returns: Pointer to own MAC address or %NULL on failure 	 * 	 * This optional function can be used to get the own MAC address of the 	 * device from the driver interface code. This is only needed if the 	 * l2_packet implementation for the OS does not provide easy access to 	 * a MAC address. */
specifier|const
name|u8
modifier|*
function_decl|(
modifier|*
name|get_mac_addr
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * set_operstate - Sets device operating state to DORMANT or UP 	 * @priv: private driver interface data 	 * @state: 0 = dormant, 1 = up 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function that can be used on operating systems 	 * that support a concept of controlling network device state from user 	 * space applications. This function, if set, gets called with 	 * state = 1 when authentication has been completed and with state = 0 	 * when connection is lost. 	 */
name|int
function_decl|(
modifier|*
name|set_operstate
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
comment|/** 	 * mlme_setprotection - MLME-SETPROTECTION.request primitive 	 * @priv: Private driver interface data 	 * @addr: Address of the station for which to set protection (may be 	 * %NULL for group keys) 	 * @protect_type: MLME_SETPROTECTION_PROTECT_TYPE_* 	 * @key_type: MLME_SETPROTECTION_KEY_TYPE_* 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function that can be used to set the driver to 	 * require protection for Tx and/or Rx frames. This uses the layer 	 * interface defined in IEEE 802.11i-2004 clause 10.3.22.1 	 * (MLME-SETPROTECTION.request). Many drivers do not use explicit 	 * set protection operation; instead, they set protection implicitly 	 * based on configured keys. 	 */
name|int
function_decl|(
modifier|*
name|mlme_setprotection
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|protect_type
parameter_list|,
name|int
name|key_type
parameter_list|)
function_decl|;
comment|/** 	 * get_hw_feature_data - Get hardware support data (channels and rates) 	 * @priv: Private driver interface data 	 * @num_modes: Variable for returning the number of returned modes 	 * flags: Variable for returning hardware feature flags 	 * Returns: Pointer to allocated hardware data on success or %NULL on 	 * failure. Caller is responsible for freeing this. 	 */
name|struct
name|hostapd_hw_modes
modifier|*
function_decl|(
modifier|*
name|get_hw_feature_data
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u16
modifier|*
name|num_modes
parameter_list|,
name|u16
modifier|*
name|flags
parameter_list|)
function_decl|;
comment|/** 	 * send_mlme - Send management frame from MLME 	 * @priv: Private driver interface data 	 * @data: IEEE 802.11 management frame with IEEE 802.11 header 	 * @data_len: Size of the management frame 	 * @noack: Do not wait for this frame to be acked (disable retries) 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|send_mlme
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|int
name|noack
parameter_list|)
function_decl|;
comment|/** 	 * update_ft_ies - Update FT (IEEE 802.11r) IEs 	 * @priv: Private driver interface data 	 * @md: Mobility domain (2 octets) (also included inside ies) 	 * @ies: FT IEs (MDIE, FTIE, ...) or %NULL to remove IEs 	 * @ies_len: Length of FT IEs in bytes 	 * Returns: 0 on success, -1 on failure 	 * 	 * The supplicant uses this callback to let the driver know that keying 	 * material for FT is available and that the driver can use the 	 * provided IEs in the next message in FT authentication sequence. 	 * 	 * This function is only needed for driver that support IEEE 802.11r 	 * (Fast BSS Transition). 	 */
name|int
function_decl|(
modifier|*
name|update_ft_ies
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|md
parameter_list|,
specifier|const
name|u8
modifier|*
name|ies
parameter_list|,
name|size_t
name|ies_len
parameter_list|)
function_decl|;
comment|/** 	 * get_scan_results2 - Fetch the latest scan results 	 * @priv: private driver interface data 	 * 	 * Returns: Allocated buffer of scan results (caller is responsible for 	 * freeing the data structure) on success, NULL on failure 	 */
name|struct
name|wpa_scan_results
modifier|*
function_decl|(
modifier|*
name|get_scan_results2
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * set_country - Set country 	 * @priv: Private driver interface data 	 * @alpha2: country to which to switch to 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is for drivers which support some form 	 * of setting a regulatory domain. 	 */
name|int
function_decl|(
modifier|*
name|set_country
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|char
modifier|*
name|alpha2
parameter_list|)
function_decl|;
comment|/** 	 * get_country - Get country 	 * @priv: Private driver interface data 	 * @alpha2: Buffer for returning country code (at least 3 octets) 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|get_country
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|char
modifier|*
name|alpha2
parameter_list|)
function_decl|;
comment|/** 	 * global_init - Global driver initialization 	 * Returns: Pointer to private data (global), %NULL on failure 	 * 	 * This optional function is called to initialize the driver wrapper 	 * for global data, i.e., data that applies to all interfaces. If this 	 * function is implemented, global_deinit() will also need to be 	 * implemented to free the private data. The driver will also likely 	 * use init2() function instead of init() to get the pointer to global 	 * data available to per-interface initializer. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|global_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** 	 * global_deinit - Global driver deinitialization 	 * @priv: private driver global data from global_init() 	 * 	 * Terminate any global driver related functionality and free the 	 * global data structure. 	 */
name|void
function_decl|(
modifier|*
name|global_deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * init2 - Initialize driver interface (with global data) 	 * @ctx: context to be used when calling wpa_supplicant functions, 	 * e.g., wpa_supplicant_event() 	 * @ifname: interface name, e.g., wlan0 	 * @global_priv: private driver global data from global_init() 	 * Returns: Pointer to private data, %NULL on failure 	 * 	 * This function can be used instead of init() if the driver wrapper 	 * uses global data. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|init2
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|void
modifier|*
name|global_priv
parameter_list|)
function_decl|;
comment|/** 	 * get_interfaces - Get information about available interfaces 	 * @global_priv: private driver global data from global_init() 	 * Returns: Allocated buffer of interface information (caller is 	 * responsible for freeing the data structure) on success, NULL on 	 * failure 	 */
name|struct
name|wpa_interface_info
modifier|*
function_decl|(
modifier|*
name|get_interfaces
function_decl|)
parameter_list|(
name|void
modifier|*
name|global_priv
parameter_list|)
function_decl|;
comment|/** 	 * scan2 - Request the driver to initiate scan 	 * @priv: private driver interface data 	 * @params: Scan parameters 	 * 	 * Returns: 0 on success, -1 on failure 	 * 	 * Once the scan results are ready, the driver should report scan 	 * results event for wpa_supplicant which will eventually request the 	 * results with wpa_driver_get_scan_results2(). 	 */
name|int
function_decl|(
modifier|*
name|scan2
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_scan_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * authenticate - Request driver to authenticate 	 * @priv: private driver interface data 	 * @params: authentication parameters 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function that can be used with drivers that 	 * support separate authentication and association steps, i.e., when 	 * wpa_supplicant can act as the SME. If not implemented, associate() 	 * function is expected to take care of IEEE 802.11 authentication, 	 * too. 	 */
name|int
function_decl|(
modifier|*
name|authenticate
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_auth_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * set_ap - Set Beacon and Probe Response information for AP mode 	 * @priv: Private driver interface data 	 * @params: Parameters to use in AP mode 	 * 	 * This function is used to configure Beacon template and/or extra IEs 	 * to add for Beacon and Probe Response frames for the driver in 	 * AP mode. The driver is responsible for building the full Beacon 	 * frame by concatenating the head part with TIM IE generated by the 	 * driver/firmware and finishing with the tail part. Depending on the 	 * driver architectue, this can be done either by using the full 	 * template or the set of additional IEs (e.g., WPS and P2P IE). 	 * Similarly, Probe Response processing depends on the driver design. 	 * If the driver (or firmware) takes care of replying to Probe Request 	 * frames, the extra IEs provided here needs to be added to the Probe 	 * Response frames. 	 * 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_ap
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_ap_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * set_acl - Set ACL in AP mode 	 * @priv: Private driver interface data 	 * @params: Parameters to configure ACL 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is used only for the drivers which support MAC address ACL. 	 */
name|int
function_decl|(
modifier|*
name|set_acl
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|hostapd_acl_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * hapd_init - Initialize driver interface (hostapd only) 	 * @hapd: Pointer to hostapd context 	 * @params: Configuration for the driver wrapper 	 * Returns: Pointer to private data, %NULL on failure 	 * 	 * This function is used instead of init() or init2() when the driver 	 * wrapper is used with hostapd. 	 */
name|void
modifier|*
function_decl|(
modifier|*
name|hapd_init
function_decl|)
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|struct
name|wpa_init_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * hapd_deinit - Deinitialize driver interface (hostapd only) 	 * @priv: Private driver interface data from hapd_init() 	 */
name|void
function_decl|(
modifier|*
name|hapd_deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * set_ieee8021x - Enable/disable IEEE 802.1X support (AP only) 	 * @priv: Private driver interface data 	 * @params: BSS parameters 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function to configure the kernel driver to 	 * enable/disable IEEE 802.1X support and set WPA/WPA2 parameters. This 	 * can be left undefined (set to %NULL) if IEEE 802.1X support is 	 * always enabled and the driver uses set_ap() to set WPA/RSN IE 	 * for Beacon frames. 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|set_ieee8021x
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_bss_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * set_privacy - Enable/disable privacy (AP only) 	 * @priv: Private driver interface data 	 * @enabled: 1 = privacy enabled, 0 = disabled 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function to configure privacy field in the 	 * kernel driver for Beacon frames. This can be left undefined (set to 	 * %NULL) if the driver uses the Beacon template from set_ap(). 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|set_privacy
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
comment|/** 	 * get_seqnum - Fetch the current TSC/packet number (AP only) 	 * @ifname: The interface name (main or virtual) 	 * @priv: Private driver interface data 	 * @addr: MAC address of the station or %NULL for group keys 	 * @idx: Key index 	 * @seq: Buffer for returning the latest used TSC/packet number 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is used to fetch the last used TSC/packet number for 	 * a TKIP, CCMP, GCMP, or BIP/IGTK key. It is mainly used with group 	 * keys, so there is no strict requirement on implementing support for 	 * unicast keys (i.e., addr != %NULL). 	 */
name|int
function_decl|(
modifier|*
name|get_seqnum
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|idx
parameter_list|,
name|u8
modifier|*
name|seq
parameter_list|)
function_decl|;
comment|/** 	 * flush - Flush all association stations (AP only) 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function requests the driver to disassociate all associated 	 * stations. This function does not need to be implemented if the 	 * driver does not process association frames internally. 	 */
name|int
function_decl|(
modifier|*
name|flush
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * set_generic_elem - Add IEs into Beacon/Probe Response frames (AP) 	 * @priv: Private driver interface data 	 * @elem: Information elements 	 * @elem_len: Length of the elem buffer in octets 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function to add information elements in the 	 * kernel driver for Beacon and Probe Response frames. This can be left 	 * undefined (set to %NULL) if the driver uses the Beacon template from 	 * set_ap(). 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|set_generic_elem
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|elem
parameter_list|,
name|size_t
name|elem_len
parameter_list|)
function_decl|;
comment|/** 	 * read_sta_data - Fetch station data 	 * @priv: Private driver interface data 	 * @data: Buffer for returning station information 	 * @addr: MAC address of the station 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|read_sta_data
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|hostap_sta_driver_data
modifier|*
name|data
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * hapd_send_eapol - Send an EAPOL packet (AP only) 	 * @priv: private driver interface data 	 * @addr: Destination MAC address 	 * @data: EAPOL packet starting with IEEE 802.1X header 	 * @data_len: Length of the EAPOL packet in octets 	 * @encrypt: Whether the frame should be encrypted 	 * @own_addr: Source MAC address 	 * @flags: WPA_STA_* flags for the destination station 	 * 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|hapd_send_eapol
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|int
name|encrypt
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
name|u32
name|flags
parameter_list|)
function_decl|;
comment|/** 	 * sta_deauth - Deauthenticate a station (AP only) 	 * @priv: Private driver interface data 	 * @own_addr: Source address and BSSID for the Deauthentication frame 	 * @addr: MAC address of the station to deauthenticate 	 * @reason: Reason code for the Deauthentiation frame 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function requests a specific station to be deauthenticated and 	 * a Deauthentication frame to be sent to it. 	 */
name|int
function_decl|(
modifier|*
name|sta_deauth
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
comment|/** 	 * sta_disassoc - Disassociate a station (AP only) 	 * @priv: Private driver interface data 	 * @own_addr: Source address and BSSID for the Disassociation frame 	 * @addr: MAC address of the station to disassociate 	 * @reason: Reason code for the Disassociation frame 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function requests a specific station to be disassociated and 	 * a Disassociation frame to be sent to it. 	 */
name|int
function_decl|(
modifier|*
name|sta_disassoc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
comment|/** 	 * sta_remove - Remove a station entry (AP only) 	 * @priv: Private driver interface data 	 * @addr: MAC address of the station to be removed 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|sta_remove
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * hapd_get_ssid - Get the current SSID (AP only) 	 * @priv: Private driver interface data 	 * @buf: Buffer for returning the SSID 	 * @len: Maximum length of the buffer 	 * Returns: Length of the SSID on success, -1 on failure 	 * 	 * This function need not be implemented if the driver uses Beacon 	 * template from set_ap() and does not reply to Probe Request frames. 	 */
name|int
function_decl|(
modifier|*
name|hapd_get_ssid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/** 	 * hapd_set_ssid - Set SSID (AP only) 	 * @priv: Private driver interface data 	 * @buf: SSID 	 * @len: Length of the SSID in octets 	 * Returns: 0 on success, -1 on failure 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|hapd_set_ssid
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/** 	 * hapd_set_countermeasures - Enable/disable TKIP countermeasures (AP) 	 * @priv: Private driver interface data 	 * @enabled: 1 = countermeasures enabled, 0 = disabled 	 * Returns: 0 on success, -1 on failure 	 * 	 * This need not be implemented if the driver does not take care of 	 * association processing. 	 */
name|int
function_decl|(
modifier|*
name|hapd_set_countermeasures
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|enabled
parameter_list|)
function_decl|;
comment|/** 	 * sta_add - Add a station entry 	 * @priv: Private driver interface data 	 * @params: Station parameters 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is used to add a station entry to the driver once the 	 * station has completed association. This is only used if the driver 	 * does not take care of association processing. 	 * 	 * With TDLS, this function is also used to add or set (params->set 1) 	 * TDLS peer entries. 	 */
name|int
function_decl|(
modifier|*
name|sta_add
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|hostapd_sta_add_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * get_inact_sec - Get station inactivity duration (AP only) 	 * @priv: Private driver interface data 	 * @addr: Station address 	 * Returns: Number of seconds station has been inactive, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|get_inact_sec
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * sta_clear_stats - Clear station statistics (AP only) 	 * @priv: Private driver interface data 	 * @addr: Station address 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|sta_clear_stats
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * set_freq - Set channel/frequency (AP only) 	 * @priv: Private driver interface data 	 * @freq: Channel parameters 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_freq
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|hostapd_freq_params
modifier|*
name|freq
parameter_list|)
function_decl|;
comment|/** 	 * set_rts - Set RTS threshold 	 * @priv: Private driver interface data 	 * @rts: RTS threshold in octets 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_rts
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|rts
parameter_list|)
function_decl|;
comment|/** 	 * set_frag - Set fragmentation threshold 	 * @priv: Private driver interface data 	 * @frag: Fragmentation threshold in octets 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_frag
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|frag
parameter_list|)
function_decl|;
comment|/** 	 * sta_set_flags - Set station flags (AP only) 	 * @priv: Private driver interface data 	 * @addr: Station address 	 * @total_flags: Bitmap of all WPA_STA_* flags currently set 	 * @flags_or: Bitmap of WPA_STA_* flags to add 	 * @flags_and: Bitmap of WPA_STA_* flags to us as a mask 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|sta_set_flags
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|total_flags
parameter_list|,
name|int
name|flags_or
parameter_list|,
name|int
name|flags_and
parameter_list|)
function_decl|;
comment|/** 	 * set_tx_queue_params - Set TX queue parameters 	 * @priv: Private driver interface data 	 * @queue: Queue number (0 = VO, 1 = VI, 2 = BE, 3 = BK) 	 * @aifs: AIFS 	 * @cw_min: cwMin 	 * @cw_max: cwMax 	 * @burst_time: Maximum length for bursting in 0.1 msec units 	 */
name|int
function_decl|(
modifier|*
name|set_tx_queue_params
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|queue
parameter_list|,
name|int
name|aifs
parameter_list|,
name|int
name|cw_min
parameter_list|,
name|int
name|cw_max
parameter_list|,
name|int
name|burst_time
parameter_list|)
function_decl|;
comment|/** 	 * if_add - Add a virtual interface 	 * @priv: Private driver interface data 	 * @type: Interface type 	 * @ifname: Interface name for the new virtual interface 	 * @addr: Local address to use for the interface or %NULL to use the 	 *	parent interface address 	 * @bss_ctx: BSS context for %WPA_IF_AP_BSS interfaces 	 * @drv_priv: Pointer for overwriting the driver context or %NULL if 	 *	not allowed (applies only to %WPA_IF_AP_BSS type) 	 * @force_ifname: Buffer for returning an interface name that the 	 *	driver ended up using if it differs from the requested ifname 	 * @if_addr: Buffer for returning the allocated interface address 	 *	(this may differ from the requested addr if the driver cannot 	 *	change interface address) 	 * @bridge: Bridge interface to use or %NULL if no bridge configured 	 * @use_existing: Whether to allow existing interface to be used 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|if_add
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|wpa_driver_if_type
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|bss_ctx
parameter_list|,
name|void
modifier|*
modifier|*
name|drv_priv
parameter_list|,
name|char
modifier|*
name|force_ifname
parameter_list|,
name|u8
modifier|*
name|if_addr
parameter_list|,
specifier|const
name|char
modifier|*
name|bridge
parameter_list|,
name|int
name|use_existing
parameter_list|)
function_decl|;
comment|/** 	 * if_remove - Remove a virtual interface 	 * @priv: Private driver interface data 	 * @type: Interface type 	 * @ifname: Interface name of the virtual interface to be removed 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|if_remove
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|wpa_driver_if_type
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
comment|/** 	 * set_sta_vlan - Bind a station into a specific interface (AP only) 	 * @priv: Private driver interface data 	 * @ifname: Interface (main or virtual BSS or VLAN) 	 * @addr: MAC address of the associated station 	 * @vlan_id: VLAN ID 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is used to bind a station to a specific virtual 	 * interface. It is only used if when virtual interfaces are supported, 	 * e.g., to assign stations to different VLAN interfaces based on 	 * information from a RADIUS server. This allows separate broadcast 	 * domains to be used with a single BSS. 	 */
name|int
function_decl|(
modifier|*
name|set_sta_vlan
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
name|int
name|vlan_id
parameter_list|)
function_decl|;
comment|/** 	 * commit - Optional commit changes handler (AP only) 	 * @priv: driver private data 	 * Returns: 0 on success, -1 on failure 	 * 	 * This optional handler function can be registered if the driver 	 * interface implementation needs to commit changes (e.g., by setting 	 * network interface up) at the end of initial configuration. If set, 	 * this handler will be called after initial setup has been completed. 	 */
name|int
function_decl|(
modifier|*
name|commit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * send_ether - Send an ethernet packet (AP only) 	 * @priv: private driver interface data 	 * @dst: Destination MAC address 	 * @src: Source MAC address 	 * @proto: Ethertype 	 * @data: EAPOL packet starting with IEEE 802.1X header 	 * @data_len: Length of the EAPOL packet in octets 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|send_ether
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
name|u16
name|proto
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|)
function_decl|;
comment|/** 	 * set_radius_acl_auth - Notification of RADIUS ACL change 	 * @priv: Private driver interface data 	 * @mac: MAC address of the station 	 * @accepted: Whether the station was accepted 	 * @session_timeout: Session timeout for the station 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_radius_acl_auth
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac
parameter_list|,
name|int
name|accepted
parameter_list|,
name|u32
name|session_timeout
parameter_list|)
function_decl|;
comment|/** 	 * set_radius_acl_expire - Notification of RADIUS ACL expiration 	 * @priv: Private driver interface data 	 * @mac: MAC address of the station 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_radius_acl_expire
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
comment|/** 	 * set_ap_wps_ie - Add WPS IE(s) into Beacon/Probe Response frames (AP) 	 * @priv: Private driver interface data 	 * @beacon: WPS IE(s) for Beacon frames or %NULL to remove extra IE(s) 	 * @proberesp: WPS IE(s) for Probe Response frames or %NULL to remove 	 *	extra IE(s) 	 * @assocresp: WPS IE(s) for (Re)Association Response frames or %NULL 	 *	to remove extra IE(s) 	 * Returns: 0 on success, -1 on failure 	 * 	 * This is an optional function to add WPS IE in the kernel driver for 	 * Beacon and Probe Response frames. This can be left undefined (set 	 * to %NULL) if the driver uses the Beacon template from set_ap() 	 * and does not process Probe Request frames. If the driver takes care 	 * of (Re)Association frame processing, the assocresp buffer includes 	 * WPS IE(s) that need to be added to (Re)Association Response frames 	 * whenever a (Re)Association Request frame indicated use of WPS. 	 * 	 * This will also be used to add P2P IE(s) into Beacon/Probe Response 	 * frames when operating as a GO. The driver is responsible for adding 	 * timing related attributes (e.g., NoA) in addition to the IEs 	 * included here by appending them after these buffers. This call is 	 * also used to provide Probe Response IEs for P2P Listen state 	 * operations for drivers that generate the Probe Response frames 	 * internally. 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|set_ap_wps_ie
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|beacon
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|proberesp
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|assocresp
parameter_list|)
function_decl|;
comment|/** 	 * set_supp_port - Set IEEE 802.1X Supplicant Port status 	 * @priv: Private driver interface data 	 * @authorized: Whether the port is authorized 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_supp_port
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|authorized
parameter_list|)
function_decl|;
comment|/** 	 * set_wds_sta - Bind a station into a 4-address WDS (AP only) 	 * @priv: Private driver interface data 	 * @addr: MAC address of the associated station 	 * @aid: Association ID 	 * @val: 1 = bind to 4-address WDS; 0 = unbind 	 * @bridge_ifname: Bridge interface to use for the WDS station or %NULL 	 *	to indicate that bridge is not to be used 	 * @ifname_wds: Buffer to return the interface name for the new WDS 	 *	station or %NULL to indicate name is not returned. 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_wds_sta
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|aid
parameter_list|,
name|int
name|val
parameter_list|,
specifier|const
name|char
modifier|*
name|bridge_ifname
parameter_list|,
name|char
modifier|*
name|ifname_wds
parameter_list|)
function_decl|;
comment|/** 	 * send_action - Transmit an Action frame 	 * @priv: Private driver interface data 	 * @freq: Frequency (in MHz) of the channel 	 * @wait: Time to wait off-channel for a response (in ms), or zero 	 * @dst: Destination MAC address (Address 1) 	 * @src: Source MAC address (Address 2) 	 * @bssid: BSSID (Address 3) 	 * @data: Frame body 	 * @data_len: data length in octets 	 @ @no_cck: Whether CCK rates must not be used to transmit this frame 	 * Returns: 0 on success, -1 on failure 	 * 	 * This command can be used to request the driver to transmit an action 	 * frame to the specified destination. 	 * 	 * If the %WPA_DRIVER_FLAGS_OFFCHANNEL_TX flag is set, the frame will 	 * be transmitted on the given channel and the device will wait for a 	 * response on that channel for the given wait time. 	 * 	 * If the flag is not set, the wait time will be ignored. In this case, 	 * if a remain-on-channel duration is in progress, the frame must be 	 * transmitted on that channel; alternatively the frame may be sent on 	 * the current operational channel (if in associated state in station 	 * mode or while operating as an AP.) 	 */
name|int
function_decl|(
modifier|*
name|send_action
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
name|unsigned
name|int
name|wait
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|int
name|no_cck
parameter_list|)
function_decl|;
comment|/** 	 * send_action_cancel_wait - Cancel action frame TX wait 	 * @priv: Private driver interface data 	 * 	 * This command cancels the wait time associated with sending an action 	 * frame. It is only available when %WPA_DRIVER_FLAGS_OFFCHANNEL_TX is 	 * set in the driver flags. 	 */
name|void
function_decl|(
modifier|*
name|send_action_cancel_wait
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * remain_on_channel - Remain awake on a channel 	 * @priv: Private driver interface data 	 * @freq: Frequency (in MHz) of the channel 	 * @duration: Duration in milliseconds 	 * Returns: 0 on success, -1 on failure 	 * 	 * This command is used to request the driver to remain awake on the 	 * specified channel for the specified duration and report received 	 * Action frames with EVENT_RX_MGMT events. Optionally, received 	 * Probe Request frames may also be requested to be reported by calling 	 * probe_req_report(). These will be reported with EVENT_RX_PROBE_REQ. 	 * 	 * The driver may not be at the requested channel when this function 	 * returns, i.e., the return code is only indicating whether the 	 * request was accepted. The caller will need to wait until the 	 * EVENT_REMAIN_ON_CHANNEL event indicates that the driver has 	 * completed the channel change. This may take some time due to other 	 * need for the radio and the caller should be prepared to timing out 	 * its wait since there are no guarantees on when this request can be 	 * executed. 	 */
name|int
function_decl|(
modifier|*
name|remain_on_channel
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|,
name|unsigned
name|int
name|duration
parameter_list|)
function_decl|;
comment|/** 	 * cancel_remain_on_channel - Cancel remain-on-channel operation 	 * @priv: Private driver interface data 	 * 	 * This command can be used to cancel a remain-on-channel operation 	 * before its originally requested duration has passed. This could be 	 * used, e.g., when remain_on_channel() is used to request extra time 	 * to receive a response to an Action frame and the response is 	 * received when there is still unneeded time remaining on the 	 * remain-on-channel operation. 	 */
name|int
function_decl|(
modifier|*
name|cancel_remain_on_channel
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * probe_req_report - Request Probe Request frames to be indicated 	 * @priv: Private driver interface data 	 * @report: Whether to report received Probe Request frames 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 * 	 * This command can be used to request the driver to indicate when 	 * Probe Request frames are received with EVENT_RX_PROBE_REQ events. 	 * Since this operation may require extra resources, e.g., due to less 	 * optimal hardware/firmware RX filtering, many drivers may disable 	 * Probe Request reporting at least in station mode. This command is 	 * used to notify the driver when the Probe Request frames need to be 	 * reported, e.g., during remain-on-channel operations. 	 */
name|int
function_decl|(
modifier|*
name|probe_req_report
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|report
parameter_list|)
function_decl|;
comment|/** 	 * deinit_ap - Deinitialize AP mode 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 * 	 * This optional function can be used to disable AP mode related 	 * configuration. If the interface was not dynamically added, 	 * change the driver mode to station mode to allow normal station 	 * operations like scanning to be completed. 	 */
name|int
function_decl|(
modifier|*
name|deinit_ap
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * deinit_p2p_cli - Deinitialize P2P client mode 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 * 	 * This optional function can be used to disable P2P client mode. If the 	 * interface was not dynamically added, change the interface type back 	 * to station mode. 	 */
name|int
function_decl|(
modifier|*
name|deinit_p2p_cli
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * suspend - Notification on system suspend/hibernate event 	 * @priv: Private driver interface data 	 */
name|void
function_decl|(
modifier|*
name|suspend
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * resume - Notification on system resume/thaw event 	 * @priv: Private driver interface data 	 */
name|void
function_decl|(
modifier|*
name|resume
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * signal_monitor - Set signal monitoring parameters 	 * @priv: Private driver interface data 	 * @threshold: Threshold value for signal change events; 0 = disabled 	 * @hysteresis: Minimum change in signal strength before indicating a 	 *	new event 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 * 	 * This function can be used to configure monitoring of signal strength 	 * with the current AP. Whenever signal strength drops below the 	 * %threshold value or increases above it, EVENT_SIGNAL_CHANGE event 	 * should be generated assuming the signal strength has changed at 	 * least %hysteresis from the previously indicated signal change event. 	 */
name|int
function_decl|(
modifier|*
name|signal_monitor
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|threshold
parameter_list|,
name|int
name|hysteresis
parameter_list|)
function_decl|;
comment|/** 	 * send_frame - Send IEEE 802.11 frame (testing use only) 	 * @priv: Private driver interface data 	 * @data: IEEE 802.11 frame with IEEE 802.11 header 	 * @data_len: Size of the frame 	 * @encrypt: Whether to encrypt the frame (if keys are set) 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is only used for debugging purposes and is not 	 * required to be implemented for normal operations. 	 */
name|int
function_decl|(
modifier|*
name|send_frame
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|int
name|encrypt
parameter_list|)
function_decl|;
comment|/** 	 * shared_freq - Get operating frequency of shared interface(s) 	 * @priv: Private driver interface data 	 * Returns: Operating frequency in MHz, 0 if no shared operation in 	 * use, or -1 on failure 	 * 	 * This command can be used to request the current operating frequency 	 * of any virtual interface that shares the same radio to provide 	 * information for channel selection for other virtual interfaces. 	 */
name|int
function_decl|(
modifier|*
name|shared_freq
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * get_noa - Get current Notice of Absence attribute payload 	 * @priv: Private driver interface data 	 * @buf: Buffer for returning NoA 	 * @buf_len: Buffer length in octets 	 * Returns: Number of octets used in buf, 0 to indicate no NoA is being 	 * advertized, or -1 on failure 	 * 	 * This function is used to fetch the current Notice of Absence 	 * attribute value from GO. 	 */
name|int
function_decl|(
modifier|*
name|get_noa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
comment|/** 	 * set_noa - Set Notice of Absence parameters for GO (testing) 	 * @priv: Private driver interface data 	 * @count: Count 	 * @start: Start time in ms from next TBTT 	 * @duration: Duration in ms 	 * Returns: 0 on success or -1 on failure 	 * 	 * This function is used to set Notice of Absence parameters for GO. It 	 * is used only for testing. To disable NoA, all parameters are set to 	 * 0. 	 */
name|int
function_decl|(
modifier|*
name|set_noa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
name|count
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|duration
parameter_list|)
function_decl|;
comment|/** 	 * set_p2p_powersave - Set P2P power save options 	 * @priv: Private driver interface data 	 * @legacy_ps: 0 = disable, 1 = enable, 2 = maximum PS, -1 = no change 	 * @opp_ps: 0 = disable, 1 = enable, -1 = no change 	 * @ctwindow: 0.. = change (msec), -1 = no change 	 * Returns: 0 on success or -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_p2p_powersave
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|legacy_ps
parameter_list|,
name|int
name|opp_ps
parameter_list|,
name|int
name|ctwindow
parameter_list|)
function_decl|;
comment|/** 	 * ampdu - Enable/disable aggregation 	 * @priv: Private driver interface data 	 * @ampdu: 1/0 = enable/disable A-MPDU aggregation 	 * Returns: 0 on success or -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|ampdu
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|ampdu
parameter_list|)
function_decl|;
comment|/** 	 * get_radio_name - Get physical radio name for the device 	 * @priv: Private driver interface data 	 * Returns: Radio name or %NULL if not known 	 * 	 * The returned data must not be modified by the caller. It is assumed 	 * that any interface that has the same radio name as another is 	 * sharing the same physical radio. This information can be used to 	 * share scan results etc. information between the virtual interfaces 	 * to speed up various operations. 	 */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|get_radio_name
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * send_tdls_mgmt - for sending TDLS management packets 	 * @priv: private driver interface data 	 * @dst: Destination (peer) MAC address 	 * @action_code: TDLS action code for the mssage 	 * @dialog_token: Dialog Token to use in the message (if needed) 	 * @status_code: Status Code or Reason Code to use (if needed) 	 * @peer_capab: TDLS peer capability (TDLS_PEER_* bitfield) 	 * @initiator: Is the current end the TDLS link initiator 	 * @buf: TDLS IEs to add to the message 	 * @len: Length of buf in octets 	 * Returns: 0 on success, negative (<0) on failure 	 * 	 * This optional function can be used to send packet to driver which is 	 * responsible for receiving and sending all TDLS packets. 	 */
name|int
function_decl|(
modifier|*
name|send_tdls_mgmt
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|u8
name|action_code
parameter_list|,
name|u8
name|dialog_token
parameter_list|,
name|u16
name|status_code
parameter_list|,
name|u32
name|peer_capab
parameter_list|,
name|int
name|initiator
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/** 	 * tdls_oper - Ask the driver to perform high-level TDLS operations 	 * @priv: Private driver interface data 	 * @oper: TDLS high-level operation. See %enum tdls_oper 	 * @peer: Destination (peer) MAC address 	 * Returns: 0 on success, negative (<0) on failure 	 * 	 * This optional function can be used to send high-level TDLS commands 	 * to the driver. 	 */
name|int
function_decl|(
modifier|*
name|tdls_oper
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|tdls_oper
name|oper
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|)
function_decl|;
comment|/** 	 * wnm_oper - Notify driver of the WNM frame reception 	 * @priv: Private driver interface data 	 * @oper: WNM operation. See %enum wnm_oper 	 * @peer: Destination (peer) MAC address 	 * @buf: Buffer for the driver to fill in (for getting IE) 	 * @buf_len: Return the len of buf 	 * Returns: 0 on success, negative (<0) on failure 	 */
name|int
function_decl|(
modifier|*
name|wnm_oper
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|wnm_oper
name|oper
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|u16
modifier|*
name|buf_len
parameter_list|)
function_decl|;
comment|/** 	 * set_qos_map - Set QoS Map 	 * @priv: Private driver interface data 	 * @qos_map_set: QoS Map 	 * @qos_map_set_len: Length of QoS Map 	 */
name|int
function_decl|(
modifier|*
name|set_qos_map
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|qos_map_set
parameter_list|,
name|u8
name|qos_map_set_len
parameter_list|)
function_decl|;
comment|/** 	 * br_add_ip_neigh - Add a neigh to the bridge ip neigh table 	 * @priv: Private driver interface data 	 * @version: IP version of the IP address, 4 or 6 	 * @ipaddr: IP address for the neigh entry 	 * @prefixlen: IP address prefix length 	 * @addr: Corresponding MAC address 	 * Returns: 0 on success, negative (<0) on failure 	 */
name|int
function_decl|(
modifier|*
name|br_add_ip_neigh
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
name|version
parameter_list|,
specifier|const
name|u8
modifier|*
name|ipaddr
parameter_list|,
name|int
name|prefixlen
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * br_delete_ip_neigh - Remove a neigh from the bridge ip neigh table 	 * @priv: Private driver interface data 	 * @version: IP version of the IP address, 4 or 6 	 * @ipaddr: IP address for the neigh entry 	 * Returns: 0 on success, negative (<0) on failure 	 */
name|int
function_decl|(
modifier|*
name|br_delete_ip_neigh
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
name|version
parameter_list|,
specifier|const
name|u8
modifier|*
name|ipaddr
parameter_list|)
function_decl|;
comment|/** 	 * br_port_set_attr - Set a bridge port attribute 	 * @attr: Bridge port attribute to set 	 * @val: Value to be set 	 * Returns: 0 on success, negative (<0) on failure 	 */
name|int
function_decl|(
modifier|*
name|br_port_set_attr
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|drv_br_port_attr
name|attr
parameter_list|,
name|unsigned
name|int
name|val
parameter_list|)
function_decl|;
comment|/** 	 * br_port_set_attr - Set a bridge network parameter 	 * @param: Bridge parameter to set 	 * @val: Value to be set 	 * Returns: 0 on success, negative (<0) on failure 	 */
name|int
function_decl|(
modifier|*
name|br_set_net_param
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|enum
name|drv_br_net_param
name|param
parameter_list|,
name|unsigned
name|int
name|val
parameter_list|)
function_decl|;
comment|/** 	 * set_wowlan - Set wake-on-wireless triggers 	 * @priv: Private driver interface data 	 * @triggers: wowlan triggers 	 */
name|int
function_decl|(
modifier|*
name|set_wowlan
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|struct
name|wowlan_triggers
modifier|*
name|triggers
parameter_list|)
function_decl|;
comment|/** 	 * signal_poll - Get current connection information 	 * @priv: Private driver interface data 	 * @signal_info: Connection info structure 	 */
name|int
function_decl|(
modifier|*
name|signal_poll
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_signal_info
modifier|*
name|signal_info
parameter_list|)
function_decl|;
comment|/** 	 * set_authmode - Set authentication algorithm(s) for static WEP 	 * @priv: Private driver interface data 	 * @authmode: 1=Open System, 2=Shared Key, 3=both 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function can be used to set authentication algorithms for AP 	 * mode when static WEP is used. If the driver uses user space MLME/SME 	 * implementation, there is no need to implement this function. 	 * 	 * DEPRECATED - use set_ap() instead 	 */
name|int
function_decl|(
modifier|*
name|set_authmode
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|authmode
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|ANDROID
comment|/** 	 * driver_cmd - Execute driver-specific command 	 * @priv: Private driver interface data 	 * @cmd: Command to execute 	 * @buf: Return buffer 	 * @buf_len: Buffer length 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|driver_cmd
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ANDROID */
comment|/** 	 * vendor_cmd - Execute vendor specific command 	 * @priv: Private driver interface data 	 * @vendor_id: Vendor id 	 * @subcmd: Vendor command id 	 * @data: Vendor command parameters (%NULL if no parameters) 	 * @data_len: Data length 	 * @buf: Return buffer (%NULL to ignore reply) 	 * Returns: 0 on success, negative (<0) on failure 	 * 	 * This function handles vendor specific commands that are passed to 	 * the driver/device. The command is identified by vendor id and 	 * command id. Parameters can be passed as argument to the command 	 * in the data buffer. Reply (if any) will be filled in the supplied 	 * return buffer. 	 * 	 * The exact driver behavior is driver interface and vendor specific. As 	 * an example, this will be converted to a vendor specific cfg80211 	 * command in case of the nl80211 driver interface. 	 */
name|int
function_decl|(
modifier|*
name|vendor_cmd
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|unsigned
name|int
name|vendor_id
parameter_list|,
name|unsigned
name|int
name|subcmd
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/** 	 * set_rekey_info - Set rekey information 	 * @priv: Private driver interface data 	 * @kek: Current KEK 	 * @kek_len: KEK length in octets 	 * @kck: Current KCK 	 * @kck_len: KCK length in octets 	 * @replay_ctr: Current EAPOL-Key Replay Counter 	 * 	 * This optional function can be used to provide information for the 	 * driver/firmware to process EAPOL-Key frames in Group Key Handshake 	 * while the host (including wpa_supplicant) is sleeping. 	 */
name|void
function_decl|(
modifier|*
name|set_rekey_info
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|kek
parameter_list|,
name|size_t
name|kek_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|kck
parameter_list|,
name|size_t
name|kck_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|replay_ctr
parameter_list|)
function_decl|;
comment|/** 	 * sta_assoc - Station association indication 	 * @priv: Private driver interface data 	 * @own_addr: Source address and BSSID for association frame 	 * @addr: MAC address of the station to associate 	 * @reassoc: flag to indicate re-association 	 * @status: association response status code 	 * @ie: assoc response ie buffer 	 * @len: ie buffer length 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function indicates the driver to send (Re)Association 	 * Response frame to the station. 	 */
name|int
function_decl|(
modifier|*
name|sta_assoc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|reassoc
parameter_list|,
name|u16
name|status
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/** 	 * sta_auth - Station authentication indication 	 * @priv: Private driver interface data 	 * @own_addr: Source address and BSSID for authentication frame 	 * @addr: MAC address of the station to associate 	 * @seq: authentication sequence number 	 * @status: authentication response status code 	 * @ie: authentication frame ie buffer 	 * @len: ie buffer length 	 * 	 * This function indicates the driver to send Authentication frame 	 * to the station. 	 */
name|int
function_decl|(
modifier|*
name|sta_auth
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u16
name|seq
parameter_list|,
name|u16
name|status
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/** 	 * add_tspec - Add traffic stream 	 * @priv: Private driver interface data 	 * @addr: MAC address of the station to associate 	 * @tspec_ie: tspec ie buffer 	 * @tspec_ielen: tspec ie length 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function adds the traffic steam for the station 	 * and fills the medium_time in tspec_ie. 	 */
name|int
function_decl|(
modifier|*
name|add_tspec
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
modifier|*
name|tspec_ie
parameter_list|,
name|size_t
name|tspec_ielen
parameter_list|)
function_decl|;
comment|/** 	 * add_sta_node - Add a station node in the driver 	 * @priv: Private driver interface data 	 * @addr: MAC address of the station to add 	 * @auth_alg: authentication algorithm used by the station 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function adds the station node in the driver, when 	 * the station gets added by FT-over-DS. 	 */
name|int
function_decl|(
modifier|*
name|add_sta_node
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u16
name|auth_alg
parameter_list|)
function_decl|;
comment|/** 	 * sched_scan - Request the driver to initiate scheduled scan 	 * @priv: Private driver interface data 	 * @params: Scan parameters 	 * @interval: Interval between scan cycles in milliseconds 	 * Returns: 0 on success, -1 on failure 	 * 	 * This operation should be used for scheduled scan offload to 	 * the hardware. Every time scan results are available, the 	 * driver should report scan results event for wpa_supplicant 	 * which will eventually request the results with 	 * wpa_driver_get_scan_results2(). This operation is optional 	 * and if not provided or if it returns -1, we fall back to 	 * normal host-scheduled scans. 	 */
name|int
function_decl|(
modifier|*
name|sched_scan
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_scan_params
modifier|*
name|params
parameter_list|,
name|u32
name|interval
parameter_list|)
function_decl|;
comment|/** 	 * stop_sched_scan - Request the driver to stop a scheduled scan 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure 	 * 	 * This should cause the scheduled scan to be stopped and 	 * results should stop being sent. Must be supported if 	 * sched_scan is supported. 	 */
name|int
function_decl|(
modifier|*
name|stop_sched_scan
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * poll_client - Probe (null data or such) the given station 	 * @priv: Private driver interface data 	 * @own_addr: MAC address of sending interface 	 * @addr: MAC address of the station to probe 	 * @qos: Indicates whether station is QoS station 	 * 	 * This function is used to verify whether an associated station is 	 * still present. This function does not need to be implemented if the 	 * driver provides such inactivity polling mechanism. 	 */
name|void
function_decl|(
modifier|*
name|poll_client
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|int
name|qos
parameter_list|)
function_decl|;
comment|/** 	 * radio_disable - Disable/enable radio 	 * @priv: Private driver interface data 	 * @disabled: 1=disable 0=enable radio 	 * Returns: 0 on success, -1 on failure 	 * 	 * This optional command is for testing purposes. It can be used to 	 * disable the radio on a testbed device to simulate out-of-radio-range 	 * conditions. 	 */
name|int
function_decl|(
modifier|*
name|radio_disable
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|disabled
parameter_list|)
function_decl|;
comment|/** 	 * switch_channel - Announce channel switch and migrate the GO to the 	 * given frequency 	 * @priv: Private driver interface data 	 * @settings: Settings for CSA period and new channel 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function is used to move the GO to the legacy STA channel to 	 * avoid frequency conflict in single channel concurrency. 	 */
name|int
function_decl|(
modifier|*
name|switch_channel
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|csa_settings
modifier|*
name|settings
parameter_list|)
function_decl|;
comment|/** 	 * add_tx_ts - Add traffic stream 	 * @priv: Private driver interface data 	 * @tsid: Traffic stream ID 	 * @addr: Receiver address 	 * @user_prio: User priority of the traffic stream 	 * @admitted_time: Admitted time for this TS in units of 	 *	32 microsecond periods (per second). 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|add_tx_ts
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
name|tsid
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
name|user_prio
parameter_list|,
name|u16
name|admitted_time
parameter_list|)
function_decl|;
comment|/** 	 * del_tx_ts - Delete traffic stream 	 * @priv: Private driver interface data 	 * @tsid: Traffic stream ID 	 * @addr: Receiver address 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|del_tx_ts
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u8
name|tsid
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * Enable channel-switching with TDLS peer 	 * @priv: Private driver interface data 	 * @addr: MAC address of the TDLS peer 	 * @oper_class: Operating class of the switch channel 	 * @params: Channel specification 	 * Returns: 0 on success, -1 on failure 	 * 	 * The function indicates to driver that it can start switching to a 	 * different channel with a specified TDLS peer. The switching is 	 * assumed on until canceled with tdls_disable_channel_switch(). 	 */
name|int
function_decl|(
modifier|*
name|tdls_enable_channel_switch
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
name|oper_class
parameter_list|,
specifier|const
name|struct
name|hostapd_freq_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Disable channel switching with TDLS peer 	 * @priv: Private driver interface data 	 * @addr: MAC address of the TDLS peer 	 * Returns: 0 on success, -1 on failure 	 * 	 * This function indicates to the driver that it should stop switching 	 * with a given TDLS peer. 	 */
name|int
function_decl|(
modifier|*
name|tdls_disable_channel_switch
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * start_dfs_cac - Listen for radar interference on the channel 	 * @priv: Private driver interface data 	 * @freq: Channel parameters 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|start_dfs_cac
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|hostapd_freq_params
modifier|*
name|freq
parameter_list|)
function_decl|;
comment|/** 	 * stop_ap - Removes beacon from AP 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 * 	 * This optional function can be used to disable AP mode related 	 * configuration. Unlike deinit_ap, it does not change to station 	 * mode. 	 */
name|int
function_decl|(
modifier|*
name|stop_ap
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * get_survey - Retrieve survey data 	 * @priv: Private driver interface data 	 * @freq: If set, survey data for the specified frequency is only 	 *	being requested. If not set, all survey data is requested. 	 * Returns: 0 on success, -1 on failure 	 * 	 * Use this to retrieve: 	 * 	 * - the observed channel noise floor 	 * - the amount of time we have spent on the channel 	 * - the amount of time during which we have spent on the channel that 	 *   the radio has determined the medium is busy and we cannot 	 *   transmit 	 * - the amount of time we have spent receiving data 	 * - the amount of time we have spent transmitting data 	 * 	 * This data can be used for spectrum heuristics. One example is 	 * Automatic Channel Selection (ACS). The channel survey data is 	 * kept on a linked list on the channel data, one entry is added 	 * for each survey. The min_nf of the channel is updated for each 	 * survey. 	 */
name|int
function_decl|(
modifier|*
name|get_survey
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|unsigned
name|int
name|freq
parameter_list|)
function_decl|;
comment|/** 	 * status - Get driver interface status information 	 * @priv: Private driver interface data 	 * @buf: Buffer for printing tou the status information 	 * @buflen: Maximum length of the buffer 	 * Returns: Length of written status information or -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
comment|/** 	 * roaming - Set roaming policy for driver-based BSS selection 	 * @priv: Private driver interface data 	 * @allowed: Whether roaming within ESS is allowed 	 * @bssid: Forced BSSID if roaming is disabled or %NULL if not set 	 * Returns: Length of written status information or -1 on failure 	 * 	 * This optional callback can be used to update roaming policy from the 	 * associate() command (bssid being set there indicates that the driver 	 * should not roam before getting this roaming() call to allow roaming. 	 * If the driver does not indicate WPA_DRIVER_FLAGS_BSS_SELECTION 	 * capability, roaming policy is handled within wpa_supplicant and there 	 * is no need to implement or react to this callback. 	 */
name|int
function_decl|(
modifier|*
name|roaming
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|int
name|allowed
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|)
function_decl|;
comment|/** 	 * set_mac_addr - Set MAC address 	 * @priv: Private driver interface data 	 * @addr: MAC address to use or %NULL for setting back to permanent 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|set_mac_addr
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|CONFIG_MACSEC
name|int
function_decl|(
modifier|*
name|macsec_init
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|macsec_init_params
modifier|*
name|params
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|macsec_deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * enable_protect_frames - Set protect frames status 	 * @priv: Private driver interface data 	 * @enabled: TRUE = protect frames enabled 	 *           FALSE = protect frames disabled 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|enable_protect_frames
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|Boolean
name|enabled
parameter_list|)
function_decl|;
comment|/** 	 * set_replay_protect - Set replay protect status and window size 	 * @priv: Private driver interface data 	 * @enabled: TRUE = replay protect enabled 	 *           FALSE = replay protect disabled 	 * @window: replay window size, valid only when replay protect enabled 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|set_replay_protect
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|Boolean
name|enabled
parameter_list|,
name|u32
name|window
parameter_list|)
function_decl|;
comment|/** 	 * set_current_cipher_suite - Set current cipher suite 	 * @priv: Private driver interface data 	 * @cs: EUI64 identifier 	 * @cs_len: Length of the cs buffer in octets 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|set_current_cipher_suite
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
specifier|const
name|u8
modifier|*
name|cs
parameter_list|,
name|size_t
name|cs_len
parameter_list|)
function_decl|;
comment|/** 	 * enable_controlled_port - Set controlled port status 	 * @priv: Private driver interface data 	 * @enabled: TRUE = controlled port enabled 	 *           FALSE = controlled port disabled 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|enable_controlled_port
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|Boolean
name|enabled
parameter_list|)
function_decl|;
comment|/** 	 * get_receive_lowest_pn - Get receive lowest pn 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * @an: association number 	 * @lowest_pn: lowest accept pn 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|get_receive_lowest_pn
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|,
name|u32
modifier|*
name|lowest_pn
parameter_list|)
function_decl|;
comment|/** 	 * get_transmit_next_pn - Get transmit next pn 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * @an: association number 	 * @next_pn: next pn 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|get_transmit_next_pn
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|,
name|u32
modifier|*
name|next_pn
parameter_list|)
function_decl|;
comment|/** 	 * set_transmit_next_pn - Set transmit next pn 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * @an: association number 	 * @next_pn: next pn 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|set_transmit_next_pn
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|,
name|u32
name|next_pn
parameter_list|)
function_decl|;
comment|/** 	 * get_available_receive_sc - get available receive channel 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|get_available_receive_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
modifier|*
name|channel
parameter_list|)
function_decl|;
comment|/** 	 * create_receive_sc - create secure channel for receiving 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * @sci_addr: secure channel identifier - address 	 * @sci_port: secure channel identifier - port 	 * @conf_offset: confidentiality offset (0, 30, or 50) 	 * @validation: frame validation policy (0 = Disabled, 1 = Checked, 	 *	2 = Strict) 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|create_receive_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
specifier|const
name|u8
modifier|*
name|sci_addr
parameter_list|,
name|u16
name|sci_port
parameter_list|,
name|unsigned
name|int
name|conf_offset
parameter_list|,
name|int
name|validation
parameter_list|)
function_decl|;
comment|/** 	 * delete_receive_sc - delete secure connection for receiving 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|delete_receive_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|)
function_decl|;
comment|/** 	 * create_receive_sa - create secure association for receive 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * @an: association number 	 * @lowest_pn: the lowest packet number can be received 	 * @sak: the secure association key 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|create_receive_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|,
name|u32
name|lowest_pn
parameter_list|,
specifier|const
name|u8
modifier|*
name|sak
parameter_list|)
function_decl|;
comment|/** 	 * enable_receive_sa - enable the SA for receive 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * @an: association number 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|enable_receive_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|)
function_decl|;
comment|/** 	 * disable_receive_sa - disable SA for receive 	 * @priv: private driver interface data from init() 	 * @channel: secure channel index 	 * @an: association number 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|disable_receive_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|)
function_decl|;
comment|/** 	 * get_available_transmit_sc - get available transmit channel 	 * @priv: Private driver interface data 	 * @channel: secure channel 	 * Returns: 0 on success, -1 on failure (or if not supported) 	 */
name|int
function_decl|(
modifier|*
name|get_available_transmit_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
modifier|*
name|channel
parameter_list|)
function_decl|;
comment|/** 	 * create_transmit_sc - create secure connection for transmit 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * @sci_addr: secure channel identifier - address 	 * @sci_port: secure channel identifier - port 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|create_transmit_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
specifier|const
name|u8
modifier|*
name|sci_addr
parameter_list|,
name|u16
name|sci_port
parameter_list|,
name|unsigned
name|int
name|conf_offset
parameter_list|)
function_decl|;
comment|/** 	 * delete_transmit_sc - delete secure connection for transmit 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|delete_transmit_sc
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|)
function_decl|;
comment|/** 	 * create_transmit_sa - create secure association for transmit 	 * @priv: private driver interface data from init() 	 * @channel: secure channel index 	 * @an: association number 	 * @next_pn: the packet number used as next transmit packet 	 * @confidentiality: True if the SA is to provide confidentiality 	 *                   as well as integrity 	 * @sak: the secure association key 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|create_transmit_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|,
name|u32
name|next_pn
parameter_list|,
name|Boolean
name|confidentiality
parameter_list|,
specifier|const
name|u8
modifier|*
name|sak
parameter_list|)
function_decl|;
comment|/** 	 * enable_transmit_sa - enable SA for transmit 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * @an: association number 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|enable_transmit_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|)
function_decl|;
comment|/** 	 * disable_transmit_sa - disable SA for transmit 	 * @priv: private driver interface data from init() 	 * @channel: secure channel 	 * @an: association number 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|disable_transmit_sa
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|u32
name|channel
parameter_list|,
name|u8
name|an
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* CONFIG_MACSEC */
comment|/** 	 * init_mesh - Driver specific initialization for mesh 	 * @priv: Private driver interface data 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|init_mesh
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * join_mesh - Join a mesh network 	 * @priv: Private driver interface data 	 * @params: Mesh configuration parameters 	 * Returns: 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|join_mesh
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|wpa_driver_mesh_join_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * leave_mesh - Leave a mesh network 	 * @priv: Private driver interface data 	 * Returns 0 on success, -1 on failure 	 */
name|int
function_decl|(
modifier|*
name|leave_mesh
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
comment|/** 	 * do_acs - Automatically select channel 	 * @priv: Private driver interface data 	 * @params: Parameters for ACS 	 * Returns 0 on success, -1 on failure 	 * 	 * This command can be used to offload ACS to the driver if the driver 	 * indicates support for such offloading (WPA_DRIVER_FLAGS_ACS_OFFLOAD). 	 */
name|int
function_decl|(
modifier|*
name|do_acs
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|drv_acs_params
modifier|*
name|params
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * enum wpa_event_type - Event type for wpa_supplicant_event() calls  */
end_comment

begin_enum
enum|enum
name|wpa_event_type
block|{
comment|/** 	 * EVENT_ASSOC - Association completed 	 * 	 * This event needs to be delivered when the driver completes IEEE 	 * 802.11 association or reassociation successfully. 	 * wpa_driver_ops::get_bssid() is expected to provide the current BSSID 	 * after this event has been generated. In addition, optional 	 * EVENT_ASSOCINFO may be generated just before EVENT_ASSOC to provide 	 * more information about the association. If the driver interface gets 	 * both of these events at the same time, it can also include the 	 * assoc_info data in EVENT_ASSOC call. 	 */
name|EVENT_ASSOC
block|,
comment|/** 	 * EVENT_DISASSOC - Association lost 	 * 	 * This event should be called when association is lost either due to 	 * receiving deauthenticate or disassociate frame from the AP or when 	 * sending either of these frames to the current AP. If the driver 	 * supports separate deauthentication event, EVENT_DISASSOC should only 	 * be used for disassociation and EVENT_DEAUTH for deauthentication. 	 * In AP mode, union wpa_event_data::disassoc_info is required. 	 */
name|EVENT_DISASSOC
block|,
comment|/** 	 * EVENT_MICHAEL_MIC_FAILURE - Michael MIC (TKIP) detected 	 * 	 * This event must be delivered when a Michael MIC error is detected by 	 * the local driver. Additional data for event processing is 	 * provided with union wpa_event_data::michael_mic_failure. This 	 * information is used to request new encyption key and to initiate 	 * TKIP countermeasures if needed. 	 */
name|EVENT_MICHAEL_MIC_FAILURE
block|,
comment|/** 	 * EVENT_SCAN_RESULTS - Scan results available 	 * 	 * This event must be called whenever scan results are available to be 	 * fetched with struct wpa_driver_ops::get_scan_results(). This event 	 * is expected to be used some time after struct wpa_driver_ops::scan() 	 * is called. If the driver provides an unsolicited event when the scan 	 * has been completed, this event can be used to trigger 	 * EVENT_SCAN_RESULTS call. If such event is not available from the 	 * driver, the driver wrapper code is expected to use a registered 	 * timeout to generate EVENT_SCAN_RESULTS call after the time that the 	 * scan is expected to be completed. Optional information about 	 * completed scan can be provided with union wpa_event_data::scan_info. 	 */
name|EVENT_SCAN_RESULTS
block|,
comment|/** 	 * EVENT_ASSOCINFO - Report optional extra information for association 	 * 	 * This event can be used to report extra association information for 	 * EVENT_ASSOC processing. This extra information includes IEs from 	 * association frames and Beacon/Probe Response frames in union 	 * wpa_event_data::assoc_info. EVENT_ASSOCINFO must be send just before 	 * EVENT_ASSOC. Alternatively, the driver interface can include 	 * assoc_info data in the EVENT_ASSOC call if it has all the 	 * information available at the same point. 	 */
name|EVENT_ASSOCINFO
block|,
comment|/** 	 * EVENT_INTERFACE_STATUS - Report interface status changes 	 * 	 * This optional event can be used to report changes in interface 	 * status (interface added/removed) using union 	 * wpa_event_data::interface_status. This can be used to trigger 	 * wpa_supplicant to stop and re-start processing for the interface, 	 * e.g., when a cardbus card is ejected/inserted. 	 */
name|EVENT_INTERFACE_STATUS
block|,
comment|/** 	 * EVENT_PMKID_CANDIDATE - Report a candidate AP for pre-authentication 	 * 	 * This event can be used to inform wpa_supplicant about candidates for 	 * RSN (WPA2) pre-authentication. If wpa_supplicant is not responsible 	 * for scan request (ap_scan=2 mode), this event is required for 	 * pre-authentication. If wpa_supplicant is performing scan request 	 * (ap_scan=1), this event is optional since scan results can be used 	 * to add pre-authentication candidates. union 	 * wpa_event_data::pmkid_candidate is used to report the BSSID of the 	 * candidate and priority of the candidate, e.g., based on the signal 	 * strength, in order to try to pre-authenticate first with candidates 	 * that are most likely targets for re-association. 	 * 	 * EVENT_PMKID_CANDIDATE can be called whenever the driver has updates 	 * on the candidate list. In addition, it can be called for the current 	 * AP and APs that have existing PMKSA cache entries. wpa_supplicant 	 * will automatically skip pre-authentication in cases where a valid 	 * PMKSA exists. When more than one candidate exists, this event should 	 * be generated once for each candidate. 	 * 	 * Driver will be notified about successful pre-authentication with 	 * struct wpa_driver_ops::add_pmkid() calls. 	 */
name|EVENT_PMKID_CANDIDATE
block|,
comment|/** 	 * EVENT_STKSTART - Request STK handshake (MLME-STKSTART.request) 	 * 	 * This event can be used to inform wpa_supplicant about desire to set 	 * up secure direct link connection between two stations as defined in 	 * IEEE 802.11e with a new PeerKey mechanism that replaced the original 	 * STAKey negotiation. The caller will need to set peer address for the 	 * event. 	 */
name|EVENT_STKSTART
block|,
comment|/** 	 * EVENT_TDLS - Request TDLS operation 	 * 	 * This event can be used to request a TDLS operation to be performed. 	 */
name|EVENT_TDLS
block|,
comment|/** 	 * EVENT_FT_RESPONSE - Report FT (IEEE 802.11r) response IEs 	 * 	 * The driver is expected to report the received FT IEs from 	 * FT authentication sequence from the AP. The FT IEs are included in 	 * the extra information in union wpa_event_data::ft_ies. 	 */
name|EVENT_FT_RESPONSE
block|,
comment|/** 	 * EVENT_IBSS_RSN_START - Request RSN authentication in IBSS 	 * 	 * The driver can use this event to inform wpa_supplicant about a STA 	 * in an IBSS with which protected frames could be exchanged. This 	 * event starts RSN authentication with the other STA to authenticate 	 * the STA and set up encryption keys with it. 	 */
name|EVENT_IBSS_RSN_START
block|,
comment|/** 	 * EVENT_AUTH - Authentication result 	 * 	 * This event should be called when authentication attempt has been 	 * completed. This is only used if the driver supports separate 	 * authentication step (struct wpa_driver_ops::authenticate). 	 * Information about authentication result is included in 	 * union wpa_event_data::auth. 	 */
name|EVENT_AUTH
block|,
comment|/** 	 * EVENT_DEAUTH - Authentication lost 	 * 	 * This event should be called when authentication is lost either due 	 * to receiving deauthenticate frame from the AP or when sending that 	 * frame to the current AP. 	 * In AP mode, union wpa_event_data::deauth_info is required. 	 */
name|EVENT_DEAUTH
block|,
comment|/** 	 * EVENT_ASSOC_REJECT - Association rejected 	 * 	 * This event should be called when (re)association attempt has been 	 * rejected by the AP. Information about the association response is 	 * included in union wpa_event_data::assoc_reject. 	 */
name|EVENT_ASSOC_REJECT
block|,
comment|/** 	 * EVENT_AUTH_TIMED_OUT - Authentication timed out 	 */
name|EVENT_AUTH_TIMED_OUT
block|,
comment|/** 	 * EVENT_ASSOC_TIMED_OUT - Association timed out 	 */
name|EVENT_ASSOC_TIMED_OUT
block|,
comment|/** 	 * EVENT_WPS_BUTTON_PUSHED - Report hardware push button press for WPS 	 */
name|EVENT_WPS_BUTTON_PUSHED
block|,
comment|/** 	 * EVENT_TX_STATUS - Report TX status 	 */
name|EVENT_TX_STATUS
block|,
comment|/** 	 * EVENT_RX_FROM_UNKNOWN - Report RX from unknown STA 	 */
name|EVENT_RX_FROM_UNKNOWN
block|,
comment|/** 	 * EVENT_RX_MGMT - Report RX of a management frame 	 */
name|EVENT_RX_MGMT
block|,
comment|/** 	 * EVENT_REMAIN_ON_CHANNEL - Remain-on-channel duration started 	 * 	 * This event is used to indicate when the driver has started the 	 * requested remain-on-channel duration. Information about the 	 * operation is included in union wpa_event_data::remain_on_channel. 	 */
name|EVENT_REMAIN_ON_CHANNEL
block|,
comment|/** 	 * EVENT_CANCEL_REMAIN_ON_CHANNEL - Remain-on-channel timed out 	 * 	 * This event is used to indicate when the driver has completed 	 * remain-on-channel duration, i.e., may noot be available on the 	 * requested channel anymore. Information about the 	 * operation is included in union wpa_event_data::remain_on_channel. 	 */
name|EVENT_CANCEL_REMAIN_ON_CHANNEL
block|,
comment|/** 	 * EVENT_RX_PROBE_REQ - Indicate received Probe Request frame 	 * 	 * This event is used to indicate when a Probe Request frame has been 	 * received. Information about the received frame is included in 	 * union wpa_event_data::rx_probe_req. The driver is required to report 	 * these events only after successfully completed probe_req_report() 	 * commands to request the events (i.e., report parameter is non-zero) 	 * in station mode. In AP mode, Probe Request frames should always be 	 * reported. 	 */
name|EVENT_RX_PROBE_REQ
block|,
comment|/** 	 * EVENT_NEW_STA - New wired device noticed 	 * 	 * This event is used to indicate that a new device has been detected 	 * in a network that does not use association-like functionality (i.e., 	 * mainly wired Ethernet). This can be used to start EAPOL 	 * authenticator when receiving a frame from a device. The address of 	 * the device is included in union wpa_event_data::new_sta. 	 */
name|EVENT_NEW_STA
block|,
comment|/** 	 * EVENT_EAPOL_RX - Report received EAPOL frame 	 * 	 * When in AP mode with hostapd, this event is required to be used to 	 * deliver the receive EAPOL frames from the driver. 	 */
name|EVENT_EAPOL_RX
block|,
comment|/** 	 * EVENT_SIGNAL_CHANGE - Indicate change in signal strength 	 * 	 * This event is used to indicate changes in the signal strength 	 * observed in frames received from the current AP if signal strength 	 * monitoring has been enabled with signal_monitor(). 	 */
name|EVENT_SIGNAL_CHANGE
block|,
comment|/** 	 * EVENT_INTERFACE_ENABLED - Notify that interface was enabled 	 * 	 * This event is used to indicate that the interface was enabled after 	 * having been previously disabled, e.g., due to rfkill. 	 */
name|EVENT_INTERFACE_ENABLED
block|,
comment|/** 	 * EVENT_INTERFACE_DISABLED - Notify that interface was disabled 	 * 	 * This event is used to indicate that the interface was disabled, 	 * e.g., due to rfkill. 	 */
name|EVENT_INTERFACE_DISABLED
block|,
comment|/** 	 * EVENT_CHANNEL_LIST_CHANGED - Channel list changed 	 * 	 * This event is used to indicate that the channel list has changed, 	 * e.g., because of a regulatory domain change triggered by scan 	 * results including an AP advertising a country code. 	 */
name|EVENT_CHANNEL_LIST_CHANGED
block|,
comment|/** 	 * EVENT_INTERFACE_UNAVAILABLE - Notify that interface is unavailable 	 * 	 * This event is used to indicate that the driver cannot maintain this 	 * interface in its operation mode anymore. The most likely use for 	 * this is to indicate that AP mode operation is not available due to 	 * operating channel would need to be changed to a DFS channel when 	 * the driver does not support radar detection and another virtual 	 * interfaces caused the operating channel to change. Other similar 	 * resource conflicts could also trigger this for station mode 	 * interfaces. This event can be propagated when channel switching 	 * fails. 	 */
name|EVENT_INTERFACE_UNAVAILABLE
block|,
comment|/** 	 * EVENT_BEST_CHANNEL 	 * 	 * Driver generates this event whenever it detects a better channel 	 * (e.g., based on RSSI or channel use). This information can be used 	 * to improve channel selection for a new AP/P2P group. 	 */
name|EVENT_BEST_CHANNEL
block|,
comment|/** 	 * EVENT_UNPROT_DEAUTH - Unprotected Deauthentication frame received 	 * 	 * This event should be called when a Deauthentication frame is dropped 	 * due to it not being protected (MFP/IEEE 802.11w). 	 * union wpa_event_data::unprot_deauth is required to provide more 	 * details of the frame. 	 */
name|EVENT_UNPROT_DEAUTH
block|,
comment|/** 	 * EVENT_UNPROT_DISASSOC - Unprotected Disassociation frame received 	 * 	 * This event should be called when a Disassociation frame is dropped 	 * due to it not being protected (MFP/IEEE 802.11w). 	 * union wpa_event_data::unprot_disassoc is required to provide more 	 * details of the frame. 	 */
name|EVENT_UNPROT_DISASSOC
block|,
comment|/** 	 * EVENT_STATION_LOW_ACK 	 * 	 * Driver generates this event whenever it detected that a particular 	 * station was lost. Detection can be through massive transmission 	 * failures for example. 	 */
name|EVENT_STATION_LOW_ACK
block|,
comment|/** 	 * EVENT_IBSS_PEER_LOST - IBSS peer not reachable anymore 	 */
name|EVENT_IBSS_PEER_LOST
block|,
comment|/** 	 * EVENT_DRIVER_GTK_REKEY - Device/driver did GTK rekey 	 * 	 * This event carries the new replay counter to notify wpa_supplicant 	 * of the current EAPOL-Key Replay Counter in case the driver/firmware 	 * completed Group Key Handshake while the host (including 	 * wpa_supplicant was sleeping). 	 */
name|EVENT_DRIVER_GTK_REKEY
block|,
comment|/** 	 * EVENT_SCHED_SCAN_STOPPED - Scheduled scan was stopped 	 */
name|EVENT_SCHED_SCAN_STOPPED
block|,
comment|/** 	 * EVENT_DRIVER_CLIENT_POLL_OK - Station responded to poll 	 * 	 * This event indicates that the station responded to the poll 	 * initiated with @poll_client. 	 */
name|EVENT_DRIVER_CLIENT_POLL_OK
block|,
comment|/** 	 * EVENT_EAPOL_TX_STATUS - notify of EAPOL TX status 	 */
name|EVENT_EAPOL_TX_STATUS
block|,
comment|/** 	 * EVENT_CH_SWITCH - AP or GO decided to switch channels 	 * 	 * Described in wpa_event_data.ch_switch 	 * */
name|EVENT_CH_SWITCH
block|,
comment|/** 	 * EVENT_WNM - Request WNM operation 	 * 	 * This event can be used to request a WNM operation to be performed. 	 */
name|EVENT_WNM
block|,
comment|/** 	 * EVENT_CONNECT_FAILED_REASON - Connection failure reason in AP mode 	 * 	 * This event indicates that the driver reported a connection failure 	 * with the specified client (for example, max client reached, etc.) in 	 * AP mode. 	 */
name|EVENT_CONNECT_FAILED_REASON
block|,
comment|/** 	 * EVENT_DFS_RADAR_DETECTED - Notify of radar detection 	 * 	 * A radar has been detected on the supplied frequency, hostapd should 	 * react accordingly (e.g., change channel). 	 */
name|EVENT_DFS_RADAR_DETECTED
block|,
comment|/** 	 * EVENT_DFS_CAC_FINISHED - Notify that channel availability check has been completed 	 * 	 * After a successful CAC, the channel can be marked clear and used. 	 */
name|EVENT_DFS_CAC_FINISHED
block|,
comment|/** 	 * EVENT_DFS_CAC_ABORTED - Notify that channel availability check has been aborted 	 * 	 * The CAC was not successful, and the channel remains in the previous 	 * state. This may happen due to a radar beeing detected or other 	 * external influences. 	 */
name|EVENT_DFS_CAC_ABORTED
block|,
comment|/** 	 * EVENT_DFS_NOP_FINISHED - Notify that non-occupancy period is over 	 * 	 * The channel which was previously unavailable is now available again. 	 */
name|EVENT_DFS_NOP_FINISHED
block|,
comment|/** 	 * EVENT_SURVEY - Received survey data 	 * 	 * This event gets triggered when a driver query is issued for survey 	 * data and the requested data becomes available. The returned data is 	 * stored in struct survey_results. The results provide at most one 	 * survey entry for each frequency and at minimum will provide one 	 * survey entry for one frequency. The survey data can be os_malloc()'d 	 * and then os_free()'d, so the event callback must only copy data. 	 */
name|EVENT_SURVEY
block|,
comment|/** 	 * EVENT_SCAN_STARTED - Scan started 	 * 	 * This indicates that driver has started a scan operation either based 	 * on a request from wpa_supplicant/hostapd or from another application. 	 * EVENT_SCAN_RESULTS is used to indicate when the scan has been 	 * completed (either successfully or by getting cancelled). 	 */
name|EVENT_SCAN_STARTED
block|,
comment|/** 	 * EVENT_AVOID_FREQUENCIES - Received avoid frequency range 	 * 	 * This event indicates a set of frequency ranges that should be avoided 	 * to reduce issues due to interference or internal co-existence 	 * information in the driver. 	 */
name|EVENT_AVOID_FREQUENCIES
block|,
comment|/** 	 * EVENT_NEW_PEER_CANDIDATE - new (unknown) mesh peer notification 	 */
name|EVENT_NEW_PEER_CANDIDATE
block|,
comment|/** 	 * EVENT_ACS_CHANNEL_SELECTED - Received selected channels by ACS 	 * 	 * Indicates a pair of primary and secondary channels chosen by ACS 	 * in device. 	 */
name|EVENT_ACS_CHANNEL_SELECTED
block|,
comment|/** 	 * EVENT_DFS_CAC_STARTED - Notify that channel availability check has 	 * been started. 	 * 	 * This event indicates that channel availability check has been started 	 * on a DFS frequency by a driver that supports DFS Offload. 	 */
name|EVENT_DFS_CAC_STARTED
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct freq_survey - Channel survey info  *  * @ifidx: Interface index in which this survey was observed  * @freq: Center of frequency of the surveyed channel  * @nf: Channel noise floor in dBm  * @channel_time: Amount of time in ms the radio spent on the channel  * @channel_time_busy: Amount of time in ms the radio detected some signal  *     that indicated to the radio the channel was not clear  * @channel_time_rx: Amount of time the radio spent receiving data  * @channel_time_tx: Amount of time the radio spent transmitting data  * @filled: bitmask indicating which fields have been reported, see  *     SURVEY_HAS_* defines.  * @list: Internal list pointers  */
end_comment

begin_struct
struct|struct
name|freq_survey
block|{
name|u32
name|ifidx
decl_stmt|;
name|unsigned
name|int
name|freq
decl_stmt|;
name|s8
name|nf
decl_stmt|;
name|u64
name|channel_time
decl_stmt|;
name|u64
name|channel_time_busy
decl_stmt|;
name|u64
name|channel_time_rx
decl_stmt|;
name|u64
name|channel_time_tx
decl_stmt|;
name|unsigned
name|int
name|filled
decl_stmt|;
name|struct
name|dl_list
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SURVEY_HAS_NF
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|SURVEY_HAS_CHAN_TIME
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|SURVEY_HAS_CHAN_TIME_BUSY
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|SURVEY_HAS_CHAN_TIME_RX
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|SURVEY_HAS_CHAN_TIME_TX
value|BIT(4)
end_define

begin_comment
comment|/**  * union wpa_event_data - Additional data for wpa_supplicant_event() calls  */
end_comment

begin_union
union|union
name|wpa_event_data
block|{
comment|/** 	 * struct assoc_info - Data for EVENT_ASSOC and EVENT_ASSOCINFO events 	 * 	 * This structure is optional for EVENT_ASSOC calls and required for 	 * EVENT_ASSOCINFO calls. By using EVENT_ASSOC with this data, the 	 * driver interface does not need to generate separate EVENT_ASSOCINFO 	 * calls. 	 */
struct|struct
name|assoc_info
block|{
comment|/** 		 * reassoc - Flag to indicate association or reassociation 		 */
name|int
name|reassoc
decl_stmt|;
comment|/** 		 * req_ies - (Re)Association Request IEs 		 * 		 * If the driver generates WPA/RSN IE, this event data must be 		 * returned for WPA handshake to have needed information. If 		 * wpa_supplicant-generated WPA/RSN IE is used, this 		 * information event is optional. 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
specifier|const
name|u8
modifier|*
name|req_ies
decl_stmt|;
comment|/** 		 * req_ies_len - Length of req_ies in bytes 		 */
name|size_t
name|req_ies_len
decl_stmt|;
comment|/** 		 * resp_ies - (Re)Association Response IEs 		 * 		 * Optional association data from the driver. This data is not 		 * required WPA, but may be useful for some protocols and as 		 * such, should be reported if this is available to the driver 		 * interface. 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
specifier|const
name|u8
modifier|*
name|resp_ies
decl_stmt|;
comment|/** 		 * resp_ies_len - Length of resp_ies in bytes 		 */
name|size_t
name|resp_ies_len
decl_stmt|;
comment|/** 		 * beacon_ies - Beacon or Probe Response IEs 		 * 		 * Optional Beacon/ProbeResp data: IEs included in Beacon or 		 * Probe Response frames from the current AP (i.e., the one 		 * that the client just associated with). This information is 		 * used to update WPA/RSN IE for the AP. If this field is not 		 * set, the results from previous scan will be used. If no 		 * data for the new AP is found, scan results will be requested 		 * again (without scan request). At this point, the driver is 		 * expected to provide WPA/RSN IE for the AP (if WPA/WPA2 is 		 * used). 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
specifier|const
name|u8
modifier|*
name|beacon_ies
decl_stmt|;
comment|/** 		 * beacon_ies_len - Length of beacon_ies */
name|size_t
name|beacon_ies_len
decl_stmt|;
comment|/** 		 * freq - Frequency of the operational channel in MHz 		 */
name|unsigned
name|int
name|freq
decl_stmt|;
comment|/** 		 * wmm_params - WMM parameters used in this association. 		 */
name|struct
name|wmm_params
name|wmm_params
decl_stmt|;
comment|/** 		 * addr - Station address (for AP mode) 		 */
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
comment|/** 		 * The following is the key management offload information 		 * @authorized 		 * @key_replay_ctr 		 * @key_replay_ctr_len 		 * @ptk_kck 		 * @ptk_kek_len 		 * @ptk_kek 		 * @ptk_kek_len 		 */
comment|/** 		 * authorized - Status of key management offload, 		 * 1 = successful 		 */
name|int
name|authorized
decl_stmt|;
comment|/** 		 * key_replay_ctr - Key replay counter value last used 		 * in a valid EAPOL-Key frame 		 */
specifier|const
name|u8
modifier|*
name|key_replay_ctr
decl_stmt|;
comment|/** 		 * key_replay_ctr_len - The length of key_replay_ctr 		 */
name|size_t
name|key_replay_ctr_len
decl_stmt|;
comment|/** 		 * ptk_kck - The derived PTK KCK 		 */
specifier|const
name|u8
modifier|*
name|ptk_kck
decl_stmt|;
comment|/** 		 * ptk_kek_len - The length of ptk_kck 		 */
name|size_t
name|ptk_kck_len
decl_stmt|;
comment|/** 		 * ptk_kek - The derived PTK KEK 		 */
specifier|const
name|u8
modifier|*
name|ptk_kek
decl_stmt|;
comment|/** 		 * ptk_kek_len - The length of ptk_kek 		 */
name|size_t
name|ptk_kek_len
decl_stmt|;
block|}
name|assoc_info
struct|;
comment|/** 	 * struct disassoc_info - Data for EVENT_DISASSOC events 	 */
struct|struct
name|disassoc_info
block|{
comment|/** 		 * addr - Station address (for AP mode) 		 */
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
comment|/** 		 * reason_code - Reason Code (host byte order) used in 		 *	Deauthentication frame 		 */
name|u16
name|reason_code
decl_stmt|;
comment|/** 		 * ie - Optional IE(s) in Disassociation frame 		 */
specifier|const
name|u8
modifier|*
name|ie
decl_stmt|;
comment|/** 		 * ie_len - Length of ie buffer in octets 		 */
name|size_t
name|ie_len
decl_stmt|;
comment|/** 		 * locally_generated - Whether the frame was locally generated 		 */
name|int
name|locally_generated
decl_stmt|;
block|}
name|disassoc_info
struct|;
comment|/** 	 * struct deauth_info - Data for EVENT_DEAUTH events 	 */
struct|struct
name|deauth_info
block|{
comment|/** 		 * addr - Station address (for AP mode) 		 */
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
comment|/** 		 * reason_code - Reason Code (host byte order) used in 		 *	Deauthentication frame 		 */
name|u16
name|reason_code
decl_stmt|;
comment|/** 		 * ie - Optional IE(s) in Deauthentication frame 		 */
specifier|const
name|u8
modifier|*
name|ie
decl_stmt|;
comment|/** 		 * ie_len - Length of ie buffer in octets 		 */
name|size_t
name|ie_len
decl_stmt|;
comment|/** 		 * locally_generated - Whether the frame was locally generated 		 */
name|int
name|locally_generated
decl_stmt|;
block|}
name|deauth_info
struct|;
comment|/** 	 * struct michael_mic_failure - Data for EVENT_MICHAEL_MIC_FAILURE 	 */
struct|struct
name|michael_mic_failure
block|{
name|int
name|unicast
decl_stmt|;
specifier|const
name|u8
modifier|*
name|src
decl_stmt|;
block|}
name|michael_mic_failure
struct|;
comment|/** 	 * struct interface_status - Data for EVENT_INTERFACE_STATUS 	 */
struct|struct
name|interface_status
block|{
name|char
name|ifname
index|[
literal|100
index|]
decl_stmt|;
enum|enum
block|{
name|EVENT_INTERFACE_ADDED
block|,
name|EVENT_INTERFACE_REMOVED
block|}
name|ievent
enum|;
block|}
name|interface_status
struct|;
comment|/** 	 * struct pmkid_candidate - Data for EVENT_PMKID_CANDIDATE 	 */
struct|struct
name|pmkid_candidate
block|{
comment|/** BSSID of the PMKID candidate */
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** Smaller the index, higher the priority */
name|int
name|index
decl_stmt|;
comment|/** Whether RSN IE includes pre-authenticate flag */
name|int
name|preauth
decl_stmt|;
block|}
name|pmkid_candidate
struct|;
comment|/** 	 * struct stkstart - Data for EVENT_STKSTART 	 */
struct|struct
name|stkstart
block|{
name|u8
name|peer
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|stkstart
struct|;
comment|/** 	 * struct tdls - Data for EVENT_TDLS 	 */
struct|struct
name|tdls
block|{
name|u8
name|peer
index|[
name|ETH_ALEN
index|]
decl_stmt|;
enum|enum
block|{
name|TDLS_REQUEST_SETUP
block|,
name|TDLS_REQUEST_TEARDOWN
block|,
name|TDLS_REQUEST_DISCOVER
block|, 		}
name|oper
enum|;
name|u16
name|reason_code
decl_stmt|;
comment|/* for teardown */
block|}
name|tdls
struct|;
comment|/** 	 * struct wnm - Data for EVENT_WNM 	 */
struct|struct
name|wnm
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
enum|enum
block|{
name|WNM_OPER_SLEEP
block|, 		}
name|oper
enum|;
enum|enum
block|{
name|WNM_SLEEP_ENTER
block|,
name|WNM_SLEEP_EXIT
block|}
name|sleep_action
enum|;
name|int
name|sleep_intval
decl_stmt|;
name|u16
name|reason_code
decl_stmt|;
name|u8
modifier|*
name|buf
decl_stmt|;
name|u16
name|buf_len
decl_stmt|;
block|}
name|wnm
struct|;
comment|/** 	 * struct ft_ies - FT information elements (EVENT_FT_RESPONSE) 	 * 	 * During FT (IEEE 802.11r) authentication sequence, the driver is 	 * expected to use this event to report received FT IEs (MDIE, FTIE, 	 * RSN IE, TIE, possible resource request) to the supplicant. The FT 	 * IEs for the next message will be delivered through the 	 * struct wpa_driver_ops::update_ft_ies() callback. 	 */
struct|struct
name|ft_ies
block|{
specifier|const
name|u8
modifier|*
name|ies
decl_stmt|;
name|size_t
name|ies_len
decl_stmt|;
name|int
name|ft_action
decl_stmt|;
name|u8
name|target_ap
index|[
name|ETH_ALEN
index|]
decl_stmt|;
comment|/** Optional IE(s), e.g., WMM TSPEC(s), for RIC-Request */
specifier|const
name|u8
modifier|*
name|ric_ies
decl_stmt|;
comment|/** Length of ric_ies buffer in octets */
name|size_t
name|ric_ies_len
decl_stmt|;
block|}
name|ft_ies
struct|;
comment|/** 	 * struct ibss_rsn_start - Data for EVENT_IBSS_RSN_START 	 */
struct|struct
name|ibss_rsn_start
block|{
name|u8
name|peer
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|ibss_rsn_start
struct|;
comment|/** 	 * struct auth_info - Data for EVENT_AUTH events 	 */
struct|struct
name|auth_info
block|{
name|u8
name|peer
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u16
name|auth_type
decl_stmt|;
name|u16
name|auth_transaction
decl_stmt|;
name|u16
name|status_code
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ies
decl_stmt|;
name|size_t
name|ies_len
decl_stmt|;
block|}
name|auth
struct|;
comment|/** 	 * struct assoc_reject - Data for EVENT_ASSOC_REJECT events 	 */
struct|struct
name|assoc_reject
block|{
comment|/** 		 * bssid - BSSID of the AP that rejected association 		 */
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
comment|/** 		 * resp_ies - (Re)Association Response IEs 		 * 		 * Optional association data from the driver. This data is not 		 * required WPA, but may be useful for some protocols and as 		 * such, should be reported if this is available to the driver 		 * interface. 		 * 		 * This should start with the first IE (fixed fields before IEs 		 * are not included). 		 */
specifier|const
name|u8
modifier|*
name|resp_ies
decl_stmt|;
comment|/** 		 * resp_ies_len - Length of resp_ies in bytes 		 */
name|size_t
name|resp_ies_len
decl_stmt|;
comment|/** 		 * status_code - Status Code from (Re)association Response 		 */
name|u16
name|status_code
decl_stmt|;
block|}
name|assoc_reject
struct|;
struct|struct
name|timeout_event
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|timeout_event
struct|;
comment|/** 	 * struct tx_status - Data for EVENT_TX_STATUS events 	 */
struct|struct
name|tx_status
block|{
name|u16
name|type
decl_stmt|;
name|u16
name|stype
decl_stmt|;
specifier|const
name|u8
modifier|*
name|dst
decl_stmt|;
specifier|const
name|u8
modifier|*
name|data
decl_stmt|;
name|size_t
name|data_len
decl_stmt|;
name|int
name|ack
decl_stmt|;
block|}
name|tx_status
struct|;
comment|/** 	 * struct rx_from_unknown - Data for EVENT_RX_FROM_UNKNOWN events 	 */
struct|struct
name|rx_from_unknown
block|{
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
name|int
name|wds
decl_stmt|;
block|}
name|rx_from_unknown
struct|;
comment|/** 	 * struct rx_mgmt - Data for EVENT_RX_MGMT events 	 */
struct|struct
name|rx_mgmt
block|{
specifier|const
name|u8
modifier|*
name|frame
decl_stmt|;
name|size_t
name|frame_len
decl_stmt|;
name|u32
name|datarate
decl_stmt|;
comment|/** 		 * drv_priv - Pointer to store driver private BSS information 		 * 		 * If not set to NULL, this is used for comparison with 		 * hostapd_data->drv_priv to determine which BSS should process 		 * the frame. 		 */
name|void
modifier|*
name|drv_priv
decl_stmt|;
comment|/** 		 * freq - Frequency (in MHz) on which the frame was received 		 */
name|int
name|freq
decl_stmt|;
comment|/** 		 * ssi_signal - Signal strength in dBm (or 0 if not available) 		 */
name|int
name|ssi_signal
decl_stmt|;
block|}
name|rx_mgmt
struct|;
comment|/** 	 * struct remain_on_channel - Data for EVENT_REMAIN_ON_CHANNEL events 	 * 	 * This is also used with EVENT_CANCEL_REMAIN_ON_CHANNEL events. 	 */
struct|struct
name|remain_on_channel
block|{
comment|/** 		 * freq - Channel frequency in MHz 		 */
name|unsigned
name|int
name|freq
decl_stmt|;
comment|/** 		 * duration - Duration to remain on the channel in milliseconds 		 */
name|unsigned
name|int
name|duration
decl_stmt|;
block|}
name|remain_on_channel
struct|;
comment|/** 	 * struct scan_info - Optional data for EVENT_SCAN_RESULTS events 	 * @aborted: Whether the scan was aborted 	 * @freqs: Scanned frequencies in MHz (%NULL = all channels scanned) 	 * @num_freqs: Number of entries in freqs array 	 * @ssids: Scanned SSIDs (%NULL or zero-length SSID indicates wildcard 	 *	SSID) 	 * @num_ssids: Number of entries in ssids array 	 */
struct|struct
name|scan_info
block|{
name|int
name|aborted
decl_stmt|;
specifier|const
name|int
modifier|*
name|freqs
decl_stmt|;
name|size_t
name|num_freqs
decl_stmt|;
name|struct
name|wpa_driver_scan_ssid
name|ssids
index|[
name|WPAS_MAX_SCAN_SSIDS
index|]
decl_stmt|;
name|size_t
name|num_ssids
decl_stmt|;
block|}
name|scan_info
struct|;
comment|/** 	 * struct rx_probe_req - Data for EVENT_RX_PROBE_REQ events 	 */
struct|struct
name|rx_probe_req
block|{
comment|/** 		 * sa - Source address of the received Probe Request frame 		 */
specifier|const
name|u8
modifier|*
name|sa
decl_stmt|;
comment|/** 		 * da - Destination address of the received Probe Request frame 		 *	or %NULL if not available 		 */
specifier|const
name|u8
modifier|*
name|da
decl_stmt|;
comment|/** 		 * bssid - BSSID of the received Probe Request frame or %NULL 		 *	if not available 		 */
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
comment|/** 		 * ie - IEs from the Probe Request body 		 */
specifier|const
name|u8
modifier|*
name|ie
decl_stmt|;
comment|/** 		 * ie_len - Length of ie buffer in octets 		 */
name|size_t
name|ie_len
decl_stmt|;
comment|/** 		 * signal - signal strength in dBm (or 0 if not available) 		 */
name|int
name|ssi_signal
decl_stmt|;
block|}
name|rx_probe_req
struct|;
comment|/** 	 * struct new_sta - Data for EVENT_NEW_STA events 	 */
struct|struct
name|new_sta
block|{
specifier|const
name|u8
modifier|*
name|addr
decl_stmt|;
block|}
name|new_sta
struct|;
comment|/** 	 * struct eapol_rx - Data for EVENT_EAPOL_RX events 	 */
struct|struct
name|eapol_rx
block|{
specifier|const
name|u8
modifier|*
name|src
decl_stmt|;
specifier|const
name|u8
modifier|*
name|data
decl_stmt|;
name|size_t
name|data_len
decl_stmt|;
block|}
name|eapol_rx
struct|;
comment|/** 	 * signal_change - Data for EVENT_SIGNAL_CHANGE events 	 */
name|struct
name|wpa_signal_info
name|signal_change
decl_stmt|;
comment|/** 	 * struct best_channel - Data for EVENT_BEST_CHANNEL events 	 * @freq_24: Best 2.4 GHz band channel frequency in MHz 	 * @freq_5: Best 5 GHz band channel frequency in MHz 	 * @freq_overall: Best channel frequency in MHz 	 * 	 * 0 can be used to indicate no preference in either band. 	 */
struct|struct
name|best_channel
block|{
name|int
name|freq_24
decl_stmt|;
name|int
name|freq_5
decl_stmt|;
name|int
name|freq_overall
decl_stmt|;
block|}
name|best_chan
struct|;
struct|struct
name|unprot_deauth
block|{
specifier|const
name|u8
modifier|*
name|sa
decl_stmt|;
specifier|const
name|u8
modifier|*
name|da
decl_stmt|;
name|u16
name|reason_code
decl_stmt|;
block|}
name|unprot_deauth
struct|;
struct|struct
name|unprot_disassoc
block|{
specifier|const
name|u8
modifier|*
name|sa
decl_stmt|;
specifier|const
name|u8
modifier|*
name|da
decl_stmt|;
name|u16
name|reason_code
decl_stmt|;
block|}
name|unprot_disassoc
struct|;
comment|/** 	 * struct low_ack - Data for EVENT_STATION_LOW_ACK events 	 * @addr: station address 	 */
struct|struct
name|low_ack
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|low_ack
struct|;
comment|/** 	 * struct ibss_peer_lost - Data for EVENT_IBSS_PEER_LOST 	 */
struct|struct
name|ibss_peer_lost
block|{
name|u8
name|peer
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|ibss_peer_lost
struct|;
comment|/** 	 * struct driver_gtk_rekey - Data for EVENT_DRIVER_GTK_REKEY 	 */
struct|struct
name|driver_gtk_rekey
block|{
specifier|const
name|u8
modifier|*
name|bssid
decl_stmt|;
specifier|const
name|u8
modifier|*
name|replay_ctr
decl_stmt|;
block|}
name|driver_gtk_rekey
struct|;
comment|/** 	 * struct client_poll - Data for EVENT_DRIVER_CLIENT_POLL_OK events 	 * @addr: station address 	 */
struct|struct
name|client_poll
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|client_poll
struct|;
comment|/** 	 * struct eapol_tx_status 	 * @dst: Original destination 	 * @data: Data starting with IEEE 802.1X header (!) 	 * @data_len: Length of data 	 * @ack: Indicates ack or lost frame 	 * 	 * This corresponds to hapd_send_eapol if the frame sent 	 * there isn't just reported as EVENT_TX_STATUS. 	 */
struct|struct
name|eapol_tx_status
block|{
specifier|const
name|u8
modifier|*
name|dst
decl_stmt|;
specifier|const
name|u8
modifier|*
name|data
decl_stmt|;
name|int
name|data_len
decl_stmt|;
name|int
name|ack
decl_stmt|;
block|}
name|eapol_tx_status
struct|;
comment|/** 	 * struct ch_switch 	 * @freq: Frequency of new channel in MHz 	 * @ht_enabled: Whether this is an HT channel 	 * @ch_offset: Secondary channel offset 	 * @ch_width: Channel width 	 * @cf1: Center frequency 1 	 * @cf2: Center frequency 2 	 */
struct|struct
name|ch_switch
block|{
name|int
name|freq
decl_stmt|;
name|int
name|ht_enabled
decl_stmt|;
name|int
name|ch_offset
decl_stmt|;
name|enum
name|chan_width
name|ch_width
decl_stmt|;
name|int
name|cf1
decl_stmt|;
name|int
name|cf2
decl_stmt|;
block|}
name|ch_switch
struct|;
comment|/** 	 * struct connect_failed - Data for EVENT_CONNECT_FAILED_REASON 	 * @addr: Remote client address 	 * @code: Reason code for connection failure 	 */
struct|struct
name|connect_failed_reason
block|{
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
enum|enum
block|{
name|MAX_CLIENT_REACHED
block|,
name|BLOCKED_CLIENT
block|}
name|code
enum|;
block|}
name|connect_failed_reason
struct|;
comment|/** 	 * struct dfs_event - Data for radar detected events 	 * @freq: Frequency of the channel in MHz 	 */
struct|struct
name|dfs_event
block|{
name|int
name|freq
decl_stmt|;
name|int
name|ht_enabled
decl_stmt|;
name|int
name|chan_offset
decl_stmt|;
name|enum
name|chan_width
name|chan_width
decl_stmt|;
name|int
name|cf1
decl_stmt|;
name|int
name|cf2
decl_stmt|;
block|}
name|dfs_event
struct|;
comment|/** 	 * survey_results - Survey result data for EVENT_SURVEY 	 * @freq_filter: Requested frequency survey filter, 0 if request 	 *	was for all survey data 	 * @survey_list: Linked list of survey data (struct freq_survey) 	 */
struct|struct
name|survey_results
block|{
name|unsigned
name|int
name|freq_filter
decl_stmt|;
name|struct
name|dl_list
name|survey_list
decl_stmt|;
comment|/* struct freq_survey */
block|}
name|survey_results
struct|;
comment|/** 	 * channel_list_changed - Data for EVENT_CHANNEL_LIST_CHANGED 	 * @initiator: Initiator of the regulatory change 	 * @type: Regulatory change type 	 * @alpha2: Country code (or "" if not available) 	 */
struct|struct
name|channel_list_changed
block|{
name|enum
name|reg_change_initiator
name|initiator
decl_stmt|;
name|enum
name|reg_type
name|type
decl_stmt|;
name|char
name|alpha2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|channel_list_changed
struct|;
comment|/** 	 * freq_range - List of frequency ranges 	 * 	 * This is used as the data with EVENT_AVOID_FREQUENCIES. 	 */
name|struct
name|wpa_freq_range_list
name|freq_range
decl_stmt|;
comment|/** 	 * struct mesh_peer 	 * 	 * @peer: Peer address 	 * @ies: Beacon IEs 	 * @ie_len: Length of @ies 	 * 	 * Notification of new candidate mesh peer. 	 */
struct|struct
name|mesh_peer
block|{
specifier|const
name|u8
modifier|*
name|peer
decl_stmt|;
specifier|const
name|u8
modifier|*
name|ies
decl_stmt|;
name|size_t
name|ie_len
decl_stmt|;
block|}
name|mesh_peer
struct|;
comment|/** 	 * struct acs_selected_channels - Data for EVENT_ACS_CHANNEL_SELECTED 	 * @pri_channel: Selected primary channel 	 * @sec_channel: Selected secondary channel 	 */
struct|struct
name|acs_selected_channels
block|{
name|u8
name|pri_channel
decl_stmt|;
name|u8
name|sec_channel
decl_stmt|;
block|}
name|acs_selected_channels
struct|;
block|}
union|;
end_union

begin_comment
comment|/**  * wpa_supplicant_event - Report a driver event for wpa_supplicant  * @ctx: Context pointer (wpa_s); this is the ctx variable registered  *	with struct wpa_driver_ops::init()  * @event: event type (defined above)  * @data: possible extra data for the event  *  * Driver wrapper code should call this function whenever an event is received  * from the driver.  */
end_comment

begin_function_decl
name|void
name|wpa_supplicant_event
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|wpa_event_type
name|event
parameter_list|,
name|union
name|wpa_event_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The following inline functions are provided for convenience to simplify  * event indication for some of the common events.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|drv_event_assoc
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|ie
parameter_list|,
name|size_t
name|ielen
parameter_list|,
name|int
name|reassoc
parameter_list|)
block|{
name|union
name|wpa_event_data
name|event
decl_stmt|;
name|os_memset
argument_list|(
operator|&
name|event
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
name|event
operator|.
name|assoc_info
operator|.
name|reassoc
operator|=
name|reassoc
expr_stmt|;
name|event
operator|.
name|assoc_info
operator|.
name|req_ies
operator|=
name|ie
expr_stmt|;
name|event
operator|.
name|assoc_info
operator|.
name|req_ies_len
operator|=
name|ielen
expr_stmt|;
name|event
operator|.
name|assoc_info
operator|.
name|addr
operator|=
name|addr
expr_stmt|;
name|wpa_supplicant_event
argument_list|(
name|ctx
argument_list|,
name|EVENT_ASSOC
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|drv_event_disassoc
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
block|{
name|union
name|wpa_event_data
name|event
decl_stmt|;
name|os_memset
argument_list|(
operator|&
name|event
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
name|event
operator|.
name|disassoc_info
operator|.
name|addr
operator|=
name|addr
expr_stmt|;
name|wpa_supplicant_event
argument_list|(
name|ctx
argument_list|,
name|EVENT_DISASSOC
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|drv_event_eapol_rx
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|)
block|{
name|union
name|wpa_event_data
name|event
decl_stmt|;
name|os_memset
argument_list|(
operator|&
name|event
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|event
argument_list|)
argument_list|)
expr_stmt|;
name|event
operator|.
name|eapol_rx
operator|.
name|src
operator|=
name|src
expr_stmt|;
name|event
operator|.
name|eapol_rx
operator|.
name|data
operator|=
name|data
expr_stmt|;
name|event
operator|.
name|eapol_rx
operator|.
name|data_len
operator|=
name|data_len
expr_stmt|;
name|wpa_supplicant_event
argument_list|(
name|ctx
argument_list|,
name|EVENT_EAPOL_RX
argument_list|,
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* driver_common.c */
end_comment

begin_function_decl
name|void
name|wpa_scan_results_free
parameter_list|(
name|struct
name|wpa_scan_results
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert wpa_event_type to a string for logging */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|event_to_string
parameter_list|(
name|enum
name|wpa_event_type
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert chan_width to a string for logging and control interfaces */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|channel_width_to_string
parameter_list|(
name|enum
name|chan_width
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ht_supported
parameter_list|(
specifier|const
name|struct
name|hostapd_hw_modes
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vht_supported
parameter_list|(
specifier|const
name|struct
name|hostapd_hw_modes
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wowlan_triggers
modifier|*
name|wpa_get_wowlan_triggers
parameter_list|(
specifier|const
name|char
modifier|*
name|wowlan_triggers
parameter_list|,
specifier|const
name|struct
name|wpa_driver_capa
modifier|*
name|capa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NULL terminated array of linked in driver wrappers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
modifier|*
name|wpa_drivers
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DRIVER_H */
end_comment

end_unit

