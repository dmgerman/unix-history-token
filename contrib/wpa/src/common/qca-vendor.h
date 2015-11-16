begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Qualcomm Atheros OUI and vendor specific assignments  * Copyright (c) 2014-2015, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QCA_VENDOR_H
end_ifndef

begin_define
define|#
directive|define
name|QCA_VENDOR_H
end_define

begin_comment
comment|/*  * This file is a registry of identifier assignments from the Qualcomm Atheros  * OUI 00:13:74 for purposes other than MAC address assignment. New identifiers  * can be assigned through normal review process for changes to the upstream  * hostap.git repository.  */
end_comment

begin_define
define|#
directive|define
name|OUI_QCA
value|0x001374
end_define

begin_comment
comment|/**  * enum qca_radiotap_vendor_ids - QCA radiotap vendor namespace IDs  */
end_comment

begin_enum
enum|enum
name|qca_radiotap_vendor_ids
block|{
name|QCA_RADIOTAP_VID_WLANTEST
init|=
literal|0
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum qca_nl80211_vendor_subcmds - QCA nl80211 vendor command identifiers  *  * @QCA_NL80211_VENDOR_SUBCMD_UNSPEC: Reserved value 0  *  * @QCA_NL80211_VENDOR_SUBCMD_TEST: Test command/event  *  * @QCA_NL80211_VENDOR_SUBCMD_ROAMING: Set roaming policy for drivers that use  *	internal BSS-selection. This command uses  *	@QCA_WLAN_VENDOR_ATTR_ROAMING_POLICY to specify the new roaming policy  *	for the current connection (i.e., changes policy set by the nl80211  *	Connect command). @QCA_WLAN_VENDOR_ATTR_MAC_ADDR may optionally be  *	included to indicate which BSS to use in case roaming is disabled.  *  * @QCA_NL80211_VENDOR_SUBCMD_AVOID_FREQUENCY: Recommendation of frequency  *	ranges to avoid to reduce issues due to interference or internal  *	co-existence information in the driver. The event data structure is  *	defined in struct qca_avoid_freq_list.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY: Command to check driver support  *	for DFS offloading.  *  * @QCA_NL80211_VENDOR_SUBCMD_NAN: NAN command/event which is used to pass  *	NAN Request/Response and NAN Indication messages. These messages are  *	interpreted between the framework and the firmware component.  *  * @QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_SET_KEY: Set key operation that can be  *	used to configure PMK to the driver even when not connected. This can  *	be used to request offloading of key management operations. Only used  *	if device supports QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD.  *  * @QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_ROAM_AUTH: An extended version of  *	NL80211_CMD_ROAM event with optional attributes including information  *	from offloaded key management operation. Uses  *	enum qca_wlan_vendor_attr_roam_auth attributes. Only used  *	if device supports QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD.  *  * @QCA_NL80211_VENDOR_SUBCMD_DO_ACS: ACS command/event which is used to  *	invoke the ACS function in device and pass selected channels to  *	hostapd.  *  * @QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES: Command to get the features  *	supported by the driver. enum qca_wlan_vendor_features defines  *	the possible features.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_STARTED: Event used by driver,  *	which supports DFS offloading, to indicate a channel availability check  *	start.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_FINISHED: Event used by driver,  *	which supports DFS offloading, to indicate a channel availability check  *	completion.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_ABORTED: Event used by driver,  *	which supports DFS offloading, to indicate that the channel availability  *	check aborted, no change to the channel status.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_NOP_FINISHED: Event used by  *	driver, which supports DFS offloading, to indicate that the  *	Non-Occupancy Period for this channel is over, channel becomes usable.  *  * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_RADAR_DETECTED: Event used by driver,  *	which supports DFS offloading, to indicate a radar pattern has been  *	detected. The channel is now unusable.  */
end_comment

begin_enum
enum|enum
name|qca_nl80211_vendor_subcmds
block|{
name|QCA_NL80211_VENDOR_SUBCMD_UNSPEC
init|=
literal|0
block|,
name|QCA_NL80211_VENDOR_SUBCMD_TEST
init|=
literal|1
block|,
comment|/* subcmds 2..8 not yet allocated */
name|QCA_NL80211_VENDOR_SUBCMD_ROAMING
init|=
literal|9
block|,
name|QCA_NL80211_VENDOR_SUBCMD_AVOID_FREQUENCY
init|=
literal|10
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY
init|=
literal|11
block|,
name|QCA_NL80211_VENDOR_SUBCMD_NAN
init|=
literal|12
block|,
name|QCA_NL80211_VENDOR_SUBMCD_STATS_EXT
init|=
literal|13
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_SET
init|=
literal|14
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_GET
init|=
literal|15
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_CLR
init|=
literal|16
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_RADIO_RESULTS
init|=
literal|17
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_IFACE_RESULTS
init|=
literal|18
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LL_STATS_PEERS_RESULTS
init|=
literal|19
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_START
init|=
literal|20
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_STOP
init|=
literal|21
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_VALID_CHANNELS
init|=
literal|22
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_CAPABILITIES
init|=
literal|23
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_CACHED_RESULTS
init|=
literal|24
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_SCAN_RESULTS_AVAILABLE
init|=
literal|25
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_FULL_SCAN_RESULT
init|=
literal|26
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_SCAN_EVENT
init|=
literal|27
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_HOTLIST_AP_FOUND
init|=
literal|28
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_SET_BSSID_HOTLIST
init|=
literal|29
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_RESET_BSSID_HOTLIST
init|=
literal|30
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_SIGNIFICANT_CHANGE
init|=
literal|31
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_SET_SIGNIFICANT_CHANGE
init|=
literal|32
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_RESET_SIGNIFICANT_CHANGE
init|=
literal|33
block|,
name|QCA_NL80211_VENDOR_SUBCMD_TDLS_ENABLE
init|=
literal|34
block|,
name|QCA_NL80211_VENDOR_SUBCMD_TDLS_DISABLE
init|=
literal|35
block|,
name|QCA_NL80211_VENDOR_SUBCMD_TDLS_GET_STATUS
init|=
literal|36
block|,
name|QCA_NL80211_VENDOR_SUBCMD_TDLS_STATE
init|=
literal|37
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GET_SUPPORTED_FEATURES
init|=
literal|38
block|,
name|QCA_NL80211_VENDOR_SUBCMD_SCANNING_MAC_OUI
init|=
literal|39
block|,
name|QCA_NL80211_VENDOR_SUBCMD_NO_DFS_FLAG
init|=
literal|40
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GSCAN_HOTLIST_AP_LOST
init|=
literal|41
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GET_CONCURRENCY_MATRIX
init|=
literal|42
block|,
comment|/* 43..49 - reserved for QCA */
name|QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_SET_KEY
init|=
literal|50
block|,
name|QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_ROAM_AUTH
init|=
literal|51
block|,
name|QCA_NL80211_VENDOR_SUBCMD_APFIND
init|=
literal|52
block|,
comment|/* 53 - reserved - was used by QCA, but not in use anymore */
name|QCA_NL80211_VENDOR_SUBCMD_DO_ACS
init|=
literal|54
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES
init|=
literal|55
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_STARTED
init|=
literal|56
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_FINISHED
init|=
literal|57
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_ABORTED
init|=
literal|58
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_NOP_FINISHED
init|=
literal|59
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_RADAR_DETECTED
init|=
literal|60
block|,
comment|/* 61-90 - reserved for QCA */
name|QCA_NL80211_VENDOR_SUBCMD_DATA_OFFLOAD
init|=
literal|91
block|,
name|QCA_NL80211_VENDOR_SUBCMD_OCB_SET_CONFIG
init|=
literal|92
block|,
name|QCA_NL80211_VENDOR_SUBCMD_OCB_SET_UTC_TIME
init|=
literal|93
block|,
name|QCA_NL80211_VENDOR_SUBCMD_OCB_START_TIMING_ADVERT
init|=
literal|94
block|,
name|QCA_NL80211_VENDOR_SUBCMD_OCB_STOP_TIMING_ADVERT
init|=
literal|95
block|,
name|QCA_NL80211_VENDOR_SUBCMD_OCB_GET_TSF_TIMER
init|=
literal|96
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DCC_GET_STATS
init|=
literal|97
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DCC_CLEAR_STATS
init|=
literal|98
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DCC_UPDATE_NDL
init|=
literal|99
block|,
name|QCA_NL80211_VENDOR_SUBCMD_DCC_STATS_EVENT
init|=
literal|100
block|,
name|QCA_NL80211_VENDOR_SUBCMD_LINK_PROPERTIES
init|=
literal|101
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GW_PARAM_CONFIG
init|=
literal|102
block|,
name|QCA_NL80211_VENDOR_SUBCMD_GET_PREFERRED_FREQ_LIST
init|=
literal|103
block|,
name|QCA_NL80211_VENDOR_SUBCMD_SET_PROBABLE_OPER_CHANNEL
init|=
literal|104
block|,
name|QCA_NL80211_VENDOR_SUBCMD_SETBAND
init|=
literal|105
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|qca_wlan_vendor_attr
block|{
name|QCA_WLAN_VENDOR_ATTR_INVALID
init|=
literal|0
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY */
name|QCA_WLAN_VENDOR_ATTR_DFS
init|=
literal|1
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_NAN */
name|QCA_WLAN_VENDOR_ATTR_NAN
init|=
literal|2
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_STATS_EXT */
name|QCA_WLAN_VENDOR_ATTR_STATS_EXT
init|=
literal|3
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_STATS_EXT */
name|QCA_WLAN_VENDOR_ATTR_IFINDEX
init|=
literal|4
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_ROAMING, u32 with values defined 	 * by enum qca_roaming_policy. */
name|QCA_WLAN_VENDOR_ATTR_ROAMING_POLICY
init|=
literal|5
block|,
name|QCA_WLAN_VENDOR_ATTR_MAC_ADDR
init|=
literal|6
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES */
name|QCA_WLAN_VENDOR_ATTR_FEATURE_FLAGS
init|=
literal|7
block|,
name|QCA_WLAN_VENDOR_ATTR_TEST
init|=
literal|8
block|,
comment|/* used by QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES */
comment|/* Unsigned 32-bit value. */
name|QCA_WLAN_VENDOR_ATTR_CONCURRENCY_CAPA
init|=
literal|9
block|,
comment|/* Unsigned 32-bit value */
name|QCA_WLAN_VENDOR_ATTR_MAX_CONCURRENT_CHANNELS_2_4_BAND
init|=
literal|10
block|,
comment|/* Unsigned 32-bit value */
name|QCA_WLAN_VENDOR_ATTR_MAX_CONCURRENT_CHANNELS_5_0_BAND
init|=
literal|11
block|,
comment|/* Unsigned 32-bit value from enum qca_set_band. */
name|QCA_WLAN_VENDOR_ATTR_SETBAND_VALUE
init|=
literal|12
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_AFTER_LAST
operator|-
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|qca_roaming_policy
block|{
name|QCA_ROAMING_NOT_ALLOWED
block|,
name|QCA_ROAMING_ALLOWED_WITHIN_ESS
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|qca_wlan_vendor_attr_roam_auth
block|{
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_INVALID
init|=
literal|0
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_BSSID
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_REQ_IE
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_RESP_IE
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AUTHORIZED
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_KEY_REPLAY_CTR
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_PTK_KCK
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_PTK_KEK
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qca_wlan_vendor_attr_acs_offload
block|{
name|QCA_WLAN_VENDOR_ATTR_ACS_CHANNEL_INVALID
init|=
literal|0
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_PRIMARY_CHANNEL
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_SECONDARY_CHANNEL
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_HW_MODE
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_HT_ENABLED
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_HT40_ENABLED
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_VHT_ENABLED
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_CHWIDTH
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_CH_LIST
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG0_CENTER_CHANNEL
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG1_CENTER_CHANNEL
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_FREQ_LIST
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_ACS_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_ACS_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_ACS_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qca_wlan_vendor_acs_hw_mode
block|{
name|QCA_ACS_MODE_IEEE80211B
block|,
name|QCA_ACS_MODE_IEEE80211G
block|,
name|QCA_ACS_MODE_IEEE80211A
block|,
name|QCA_ACS_MODE_IEEE80211AD
block|,
name|QCA_ACS_MODE_IEEE80211ANY
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum qca_wlan_vendor_features - Vendor device/driver feature flags  *  * @QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD: Device supports key  *	management offload, a mechanism where the station's firmware  *	does the exchange with the AP to establish the temporal keys  *	after roaming, rather than having the user space wpa_supplicant do it.  * @QCA_WLAN_VENDOR_FEATURE_SUPPORT_HW_MODE_ANY: Device supports automatic  *	band selection based on channel selection results.  * @NUM_QCA_WLAN_VENDOR_FEATURES: Number of assigned feature bits  */
end_comment

begin_enum
enum|enum
name|qca_wlan_vendor_features
block|{
name|QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD
init|=
literal|0
block|,
name|QCA_WLAN_VENDOR_FEATURE_SUPPORT_HW_MODE_ANY
init|=
literal|1
block|,
name|NUM_QCA_WLAN_VENDOR_FEATURES
comment|/* keep last */
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum qca_wlan_vendor_attr_data_offload_ind - Vendor Data Offload Indication  *  * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_SESSION: Session corresponding to  *	the offloaded data.  * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_PROTOCOL: Protocol of the offloaded  *	data.  * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_EVENT: Event type for the data offload  *	indication.  */
end_comment

begin_enum
enum|enum
name|qca_wlan_vendor_attr_data_offload_ind
block|{
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_INVALID
init|=
literal|0
block|,
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_SESSION
block|,
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_PROTOCOL
block|,
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_EVENT
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qca_vendor_attr_get_preferred_freq_list
block|{
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_INVALID
block|,
comment|/* A 32-unsigned value; the interface type/mode for which the preferred 	 * frequency list is requested (see enum qca_iface_type for possible 	 * values); used in GET_PREFERRED_FREQ_LIST command from user-space to 	 * kernel and in the kernel response back to user-space. 	 */
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_IFACE_TYPE
block|,
comment|/* An array of 32-unsigned values; values are frequency (MHz); sent 	 * from kernel space to user space. 	 */
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qca_vendor_attr_probable_oper_channel
block|{
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_INVALID
block|,
comment|/* 32-bit unsigned value; indicates the connection/iface type likely to 	 * come on this channel (see enum qca_iface_type). 	 */
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_IFACE_TYPE
block|,
comment|/* 32-bit unsigned value; the frequency (MHz) of the probable channel */
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_FREQ
block|,
comment|/* keep last */
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_AFTER_LAST
block|,
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_MAX
init|=
name|QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|qca_iface_type
block|{
name|QCA_IFACE_TYPE_STA
block|,
name|QCA_IFACE_TYPE_AP
block|,
name|QCA_IFACE_TYPE_P2P_CLIENT
block|,
name|QCA_IFACE_TYPE_P2P_GO
block|,
name|QCA_IFACE_TYPE_IBSS
block|,
name|QCA_IFACE_TYPE_TDLS
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|qca_set_band
block|{
name|QCA_SETBAND_AUTO
block|,
name|QCA_SETBAND_5G
block|,
name|QCA_SETBAND_2G
block|, }
enum|;
end_enum

begin_comment
comment|/* IEEE 802.11 Vendor Specific elements */
end_comment

begin_comment
comment|/**  * enum qca_vendor_element_id - QCA Vendor Specific element types  *  * These values are used to identify QCA Vendor Specific elements. The  * payload of the element starts with the three octet OUI (OUI_QCA) and  * is followed by a single octet type which is defined by this enum.  *  * @QCA_VENDOR_ELEM_P2P_PREF_CHAN_LIST: P2P preferred channel list.  *	This element can be used to specify preference order for supported  *	channels. The channels in this list are in preference order (the first  *	one has the highest preference) and are described as a pair of  *	(global) Operating Class and Channel Number (each one octet) fields.  *  *	This extends the standard P2P functionality by providing option to have  *	more than one preferred operating channel. When this element is present,  *	it replaces the preference indicated in the Operating Channel attribute.  *	For supporting other implementations, the Operating Channel attribute is  *	expected to be used with the highest preference channel. Similarly, all  *	the channels included in this Preferred channel list element are  *	expected to be included in the Channel List attribute.  *  *	This vendor element may be included in GO Negotiation Request, P2P  *	Invitation Request, and Provision Discovery Request frames.  */
end_comment

begin_enum
enum|enum
name|qca_vendor_element_id
block|{
name|QCA_VENDOR_ELEM_P2P_PREF_CHAN_LIST
init|=
literal|0
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QCA_VENDOR_H */
end_comment

end_unit

