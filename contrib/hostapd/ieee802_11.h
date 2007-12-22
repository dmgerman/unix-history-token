begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / IEEE 802.11 Management  * Copyright (c) 2002-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_11_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_11_H
end_define

begin_comment
comment|/* IEEE 802.11 defines */
end_comment

begin_define
define|#
directive|define
name|WLAN_FC_PVER
value|(BIT(1) | BIT(0))
end_define

begin_define
define|#
directive|define
name|WLAN_FC_TODS
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_FROMDS
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_MOREFRAG
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_RETRY
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_PWRMGT
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_MOREDATA
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_ISWEP
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_ORDER
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_GET_TYPE
parameter_list|(
name|fc
parameter_list|)
value|(((fc)& (BIT(3) | BIT(2)))>> 2)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_GET_STYPE
parameter_list|(
name|fc
parameter_list|)
define|\
value|(((fc)& (BIT(7) | BIT(6) | BIT(5) | BIT(4)))>> 4)
end_define

begin_define
define|#
directive|define
name|WLAN_GET_SEQ_FRAG
parameter_list|(
name|seq
parameter_list|)
value|((seq)& (BIT(3) | BIT(2) | BIT(1) | BIT(0)))
end_define

begin_define
define|#
directive|define
name|WLAN_GET_SEQ_SEQ
parameter_list|(
name|seq
parameter_list|)
define|\
value|(((seq)& (~(BIT(3) | BIT(2) | BIT(1) | BIT(0))))>> 4)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_TYPE_MGMT
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_FC_TYPE_CTRL
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_FC_TYPE_DATA
value|2
end_define

begin_comment
comment|/* management */
end_comment

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_ASSOC_REQ
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_ASSOC_RESP
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_REASSOC_REQ
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_REASSOC_RESP
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_PROBE_REQ
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_PROBE_RESP
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_BEACON
value|8
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_ATIM
value|9
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DISASSOC
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_AUTH
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DEAUTH
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_ACTION
value|13
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_PSPOLL
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_RTS
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CTS
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_ACK
value|13
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CFEND
value|14
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CFENDACK
value|15
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DATA
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DATA_CFACK
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DATA_CFPOLL
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_DATA_CFACKPOLL
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_NULLFUNC
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CFACK
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CFPOLL
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_CFACKPOLL
value|7
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_DATA
value|8
end_define

begin_comment
comment|/* Authentication algorithms */
end_comment

begin_define
define|#
directive|define
name|WLAN_AUTH_OPEN
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_AUTH_SHARED_KEY
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_AUTH_CHALLENGE_LEN
value|128
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_ESS
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_IBSS
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_CF_POLLABLE
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_CF_POLL_REQUEST
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_PRIVACY
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_SHORT_PREAMBLE
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_PBCC
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_CHANNEL_AGILITY
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_SPECTRUM_MGMT
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_SHORT_SLOT_TIME
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|WLAN_CAPABILITY_DSSS_OFDM
value|BIT(13)
end_define

begin_comment
comment|/* Status codes */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_UNSPECIFIED_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_CAPS_UNSUPPORTED
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_REASSOC_NO_ASSOC
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_UNSPEC
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_NOT_SUPPORTED_AUTH_ALG
value|13
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_UNKNOWN_AUTH_TRANSACTION
value|14
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_CHALLENGE_FAIL
value|15
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_AUTH_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_AP_UNABLE_TO_HANDLE_NEW_STA
value|17
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_RATES
value|18
end_define

begin_comment
comment|/* IEEE 802.11b */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NOSHORT
value|19
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NOPBCC
value|20
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NOAGILITY
value|21
end_define

begin_comment
comment|/* IEEE 802.11h */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_SPEC_MGMT_REQUIRED
value|22
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_PWR_CAPABILITY_NOT_VALID
value|23
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_SUPPORTED_CHANNEL_NOT_VALID
value|24
end_define

begin_comment
comment|/* IEEE 802.11i */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_IE
value|40
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_GROUP_CIPHER_NOT_VALID
value|41
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_PAIRWISE_CIPHER_NOT_VALID
value|42
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_AKMP_NOT_VALID
value|43
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_UNSUPPORTED_RSN_IE_VERSION
value|44
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_RSN_IE_CAPAB
value|45
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_CIPHER_REJECTED_PER_POLICY
value|46
end_define

begin_comment
comment|/* Reason codes */
end_comment

begin_define
define|#
directive|define
name|WLAN_REASON_UNSPECIFIED
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_PREV_AUTH_NOT_VALID
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_DEAUTH_LEAVING
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_DISASSOC_AP_BUSY
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_CLASS2_FRAME_FROM_NONAUTH_STA
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA
value|7
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_DISASSOC_STA_HAS_LEFT
value|8
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_STA_REQ_ASSOC_WITHOUT_AUTH
value|9
end_define

begin_comment
comment|/* IEEE 802.11i */
end_comment

begin_define
define|#
directive|define
name|WLAN_REASON_INVALID_IE
value|13
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_MICHAEL_MIC_FAILURE
value|14
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_4WAY_HANDSHAKE_TIMEOUT
value|15
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_GROUP_KEY_UPDATE_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_IE_IN_4WAY_DIFFERS
value|17
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_GROUP_CIPHER_NOT_VALID
value|18
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_PAIRWISE_CIPHER_NOT_VALID
value|19
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_AKMP_NOT_VALID
value|20
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_UNSUPPORTED_RSN_IE_VERSION
value|21
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_INVALID_RSN_IE_CAPAB
value|22
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_IEEE_802_1X_AUTH_FAILED
value|23
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_CIPHER_SUITE_REJECTED
value|24
end_define

begin_comment
comment|/* Information Element IDs */
end_comment

begin_define
define|#
directive|define
name|WLAN_EID_SSID
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_EID_SUPP_RATES
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_EID_FH_PARAMS
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_EID_DS_PARAMS
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_EID_CF_PARAMS
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TIM
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_EID_IBSS_PARAMS
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_EID_COUNTRY
value|7
end_define

begin_define
define|#
directive|define
name|WLAN_EID_CHALLENGE
value|16
end_define

begin_comment
comment|/* EIDs defined by IEEE 802.11h - START */
end_comment

begin_define
define|#
directive|define
name|WLAN_EID_PWR_CONSTRAINT
value|32
end_define

begin_define
define|#
directive|define
name|WLAN_EID_PWR_CAPABILITY
value|33
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TPC_REQUEST
value|34
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TPC_REPORT
value|35
end_define

begin_define
define|#
directive|define
name|WLAN_EID_SUPPORTED_CHANNELS
value|36
end_define

begin_define
define|#
directive|define
name|WLAN_EID_CHANNEL_SWITCH
value|37
end_define

begin_define
define|#
directive|define
name|WLAN_EID_MEASURE_REQUEST
value|38
end_define

begin_define
define|#
directive|define
name|WLAN_EID_MEASURE_REPORT
value|39
end_define

begin_define
define|#
directive|define
name|WLAN_EID_QUITE
value|40
end_define

begin_define
define|#
directive|define
name|WLAN_EID_IBSS_DFS
value|41
end_define

begin_comment
comment|/* EIDs defined by IEEE 802.11h - END */
end_comment

begin_define
define|#
directive|define
name|WLAN_EID_ERP_INFO
value|42
end_define

begin_define
define|#
directive|define
name|WLAN_EID_RSN
value|48
end_define

begin_define
define|#
directive|define
name|WLAN_EID_EXT_SUPP_RATES
value|50
end_define

begin_define
define|#
directive|define
name|WLAN_EID_GENERIC
value|221
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VENDOR_SPECIFIC
value|221
end_define

begin_struct
struct|struct
name|ieee80211_mgmt
block|{
name|u16
name|frame_control
decl_stmt|;
name|u16
name|duration
decl_stmt|;
name|u8
name|da
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|sa
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|u16
name|seq_ctrl
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u16
name|auth_alg
decl_stmt|;
name|u16
name|auth_transaction
decl_stmt|;
name|u16
name|status_code
decl_stmt|;
comment|/* possibly followed by Challenge text */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|auth
struct|;
struct|struct
block|{
name|u16
name|reason_code
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|deauth
struct|;
struct|struct
block|{
name|u16
name|capab_info
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
comment|/* followed by SSID and Supported rates */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|assoc_req
struct|;
struct|struct
block|{
name|u16
name|capab_info
decl_stmt|;
name|u16
name|status_code
decl_stmt|;
name|u16
name|aid
decl_stmt|;
comment|/* followed by Supported rates */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|assoc_resp
struct|,
name|reassoc_resp
struct|;
struct|struct
block|{
name|u16
name|capab_info
decl_stmt|;
name|u16
name|listen_interval
decl_stmt|;
name|u8
name|current_ap
index|[
literal|6
index|]
decl_stmt|;
comment|/* followed by SSID and Supported rates */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|reassoc_req
struct|;
struct|struct
block|{
name|u16
name|reason_code
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|disassoc
struct|;
struct|struct
block|{
comment|/* only variable items: SSID, Supported rates */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|probe_req
struct|;
struct|struct
block|{
name|u8
name|timestamp
index|[
literal|8
index|]
decl_stmt|;
name|u16
name|beacon_int
decl_stmt|;
name|u16
name|capab_info
decl_stmt|;
comment|/* followed by some of SSID, Supported rates, 			 * FH Params, DS Params, CF Params, IBSS Params */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|probe_resp
struct|;
struct|struct
block|{
name|u8
name|timestamp
index|[
literal|8
index|]
decl_stmt|;
name|u16
name|beacon_int
decl_stmt|;
name|u16
name|capab_info
decl_stmt|;
comment|/* followed by some of SSID, Supported rates, 			 * FH Params, DS Params, CF Params, IBSS Params, TIM */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|beacon
struct|;
struct|struct
block|{
name|u8
name|category
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u8
name|action_code
decl_stmt|;
name|u8
name|dialog_token
decl_stmt|;
name|u8
name|status_code
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|wme_action
struct|;
struct|struct
block|{
name|u8
name|action_code
decl_stmt|;
name|u8
name|element_id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|u8
name|switch_mode
decl_stmt|;
name|u8
name|new_chan
decl_stmt|;
name|u8
name|switch_count
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|chan_switch
struct|;
block|}
name|u
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|action
struct|;
block|}
name|u
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|ERP_INFO_NON_ERP_PRESENT
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|ERP_INFO_USE_PROTECTION
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|ERP_INFO_BARKER_PREAMBLE_MODE
value|BIT(2)
end_define

begin_comment
comment|/* Parsed Information Elements */
end_comment

begin_struct
struct|struct
name|ieee802_11_elems
block|{
name|u8
modifier|*
name|ssid
decl_stmt|;
name|u8
name|ssid_len
decl_stmt|;
name|u8
modifier|*
name|supp_rates
decl_stmt|;
name|u8
name|supp_rates_len
decl_stmt|;
name|u8
modifier|*
name|fh_params
decl_stmt|;
name|u8
name|fh_params_len
decl_stmt|;
name|u8
modifier|*
name|ds_params
decl_stmt|;
name|u8
name|ds_params_len
decl_stmt|;
name|u8
modifier|*
name|cf_params
decl_stmt|;
name|u8
name|cf_params_len
decl_stmt|;
name|u8
modifier|*
name|tim
decl_stmt|;
name|u8
name|tim_len
decl_stmt|;
name|u8
modifier|*
name|ibss_params
decl_stmt|;
name|u8
name|ibss_params_len
decl_stmt|;
name|u8
modifier|*
name|challenge
decl_stmt|;
name|u8
name|challenge_len
decl_stmt|;
name|u8
modifier|*
name|erp_info
decl_stmt|;
name|u8
name|erp_info_len
decl_stmt|;
name|u8
modifier|*
name|ext_supp_rates
decl_stmt|;
name|u8
name|ext_supp_rates_len
decl_stmt|;
name|u8
modifier|*
name|wpa_ie
decl_stmt|;
name|u8
name|wpa_ie_len
decl_stmt|;
name|u8
modifier|*
name|rsn_ie
decl_stmt|;
name|u8
name|rsn_ie_len
decl_stmt|;
name|u8
modifier|*
name|wme
decl_stmt|;
name|u8
name|wme_len
decl_stmt|;
name|u8
modifier|*
name|wme_tspec
decl_stmt|;
name|u8
name|wme_tspec_len
decl_stmt|;
name|u8
modifier|*
name|power_cap
decl_stmt|;
name|u8
name|power_cap_len
decl_stmt|;
name|u8
modifier|*
name|supp_channels
decl_stmt|;
name|u8
name|supp_channels_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|ParseOK
init|=
literal|0
block|,
name|ParseUnknown
init|=
literal|1
block|,
name|ParseFailed
init|=
operator|-
literal|1
block|}
name|ParseRes
typedef|;
end_typedef

begin_struct
struct|struct
name|hostapd_frame_info
block|{
name|u32
name|phytype
decl_stmt|;
name|u32
name|channel
decl_stmt|;
name|u32
name|datarate
decl_stmt|;
name|u32
name|ssi_signal
decl_stmt|;
name|unsigned
name|int
name|passive_scan
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee802_11_send_deauth
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
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
name|ieee802_11_mgmt
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u16
name|stype
parameter_list|,
name|struct
name|hostapd_frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_11_mgmt_cb
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u16
name|stype
parameter_list|,
name|int
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ParseRes
name|ieee802_11_parse_elems
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|start
parameter_list|,
name|size_t
name|len
parameter_list|,
name|struct
name|ieee802_11_elems
modifier|*
name|elems
parameter_list|,
name|int
name|show_errors
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_11_print_ssid
parameter_list|(
specifier|const
name|u8
modifier|*
name|ssid
parameter_list|,
name|u8
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_michael_mic_failure
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
parameter_list|,
name|int
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee802_11_get_mib
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
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
name|int
name|ieee802_11_get_mib_sta
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
name|u16
name|hostapd_own_capab_info
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
name|probe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_supp_rates
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|hostapd_eid_ext_supp_rates
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
name|u8
modifier|*
name|eid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11_H */
end_comment

end_unit

