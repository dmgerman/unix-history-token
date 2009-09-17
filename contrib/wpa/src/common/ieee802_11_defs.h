begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.11 Frame type definitions  * Copyright (c) 2002-2007, Jouni Malinen<j@w1.fi>  * Copyright (c) 2007-2008 Intel Corporation  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_11_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_11_DEFS_H
end_define

begin_comment
comment|/* IEEE 802.11 defines */
end_comment

begin_define
define|#
directive|define
name|WLAN_FC_PVER
value|0x0003
end_define

begin_define
define|#
directive|define
name|WLAN_FC_TODS
value|0x0100
end_define

begin_define
define|#
directive|define
name|WLAN_FC_FROMDS
value|0x0200
end_define

begin_define
define|#
directive|define
name|WLAN_FC_MOREFRAG
value|0x0400
end_define

begin_define
define|#
directive|define
name|WLAN_FC_RETRY
value|0x0800
end_define

begin_define
define|#
directive|define
name|WLAN_FC_PWRMGT
value|0x1000
end_define

begin_define
define|#
directive|define
name|WLAN_FC_MOREDATA
value|0x2000
end_define

begin_define
define|#
directive|define
name|WLAN_FC_ISWEP
value|0x4000
end_define

begin_define
define|#
directive|define
name|WLAN_FC_ORDER
value|0x8000
end_define

begin_define
define|#
directive|define
name|WLAN_FC_GET_TYPE
parameter_list|(
name|fc
parameter_list|)
value|(((fc)& 0x000c)>> 2)
end_define

begin_define
define|#
directive|define
name|WLAN_FC_GET_STYPE
parameter_list|(
name|fc
parameter_list|)
value|(((fc)& 0x00f0)>> 4)
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
name|WLAN_AUTH_FT
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_AUTH_LEAP
value|128
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
comment|/* Status codes (IEEE 802.11-2007, 7.3.1.9, Table 7-23) */
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
comment|/* IEEE 802.11g */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NO_SHORT_SLOT_TIME
value|25
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NO_ER_PBCC
value|26
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NO_DSSS_OFDM
value|27
end_define

begin_comment
comment|/* IEEE 802.11w */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_REJECTED_TEMPORARILY
value|30
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ROBUST_MGMT_FRAME_POLICY_VIOLATION
value|31
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

begin_define
define|#
directive|define
name|WLAN_STATUS_TS_NOT_CREATED
value|47
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_DIRECT_LINK_NOT_ALLOWED
value|48
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_DEST_STA_NOT_PRESENT
value|49
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_DEST_STA_NOT_QOS_STA
value|50
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_LISTEN_INT_TOO_LARGE
value|51
end_define

begin_comment
comment|/* IEEE 802.11r */
end_comment

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_FT_ACTION_FRAME_COUNT
value|52
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_EXPECTED_RESOURCE_REQ_FT
value|53
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_PMKID
value|54
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_MDIE
value|55
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_FTIE
value|56
end_define

begin_comment
comment|/* Reason codes (IEEE 802.11-2007, 7.3.1.7, Table 7-22) */
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
comment|/* IEEE 802.11h */
end_comment

begin_define
define|#
directive|define
name|WLAN_REASON_PWR_CAPABILITY_NOT_VALID
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_SUPPORTED_CHANNEL_NOT_VALID
value|11
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
name|WLAN_EID_HT_CAP
value|45
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
name|WLAN_EID_MOBILITY_DOMAIN
value|54
end_define

begin_define
define|#
directive|define
name|WLAN_EID_FAST_BSS_TRANSITION
value|55
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TIMEOUT_INTERVAL
value|56
end_define

begin_define
define|#
directive|define
name|WLAN_EID_RIC_DATA
value|57
end_define

begin_define
define|#
directive|define
name|WLAN_EID_HT_OPERATION
value|61
end_define

begin_define
define|#
directive|define
name|WLAN_EID_SECONDARY_CHANNEL_OFFSET
value|62
end_define

begin_define
define|#
directive|define
name|WLAN_EID_20_40_BSS_COEXISTENCE
value|72
end_define

begin_define
define|#
directive|define
name|WLAN_EID_20_40_BSS_INTOLERANT
value|73
end_define

begin_define
define|#
directive|define
name|WLAN_EID_OVERLAPPING_BSS_SCAN_PARAMS
value|74
end_define

begin_define
define|#
directive|define
name|WLAN_EID_MMIE
value|76
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VENDOR_SPECIFIC
value|221
end_define

begin_comment
comment|/* Action frame categories (IEEE 802.11-2007, 7.3.1.11, Table 7-24) */
end_comment

begin_define
define|#
directive|define
name|WLAN_ACTION_SPECTRUM_MGMT
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_QOS
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_DLS
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_BLOCK_ACK
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_RADIO_MEASUREMENT
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_FT
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_SA_QUERY
value|8
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_WMM
value|17
end_define

begin_comment
comment|/* SA Query Action frame (IEEE 802.11w/D7.0, 7.4.9) */
end_comment

begin_define
define|#
directive|define
name|WLAN_SA_QUERY_REQUEST
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_SA_QUERY_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_SA_QUERY_TR_ID_LEN
value|16
end_define

begin_comment
comment|/* Timeout Interval Type */
end_comment

begin_define
define|#
directive|define
name|WLAN_TIMEOUT_REASSOC_DEADLINE
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_TIMEOUT_KEY_LIFETIME
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_TIMEOUT_ASSOC_COMEBACK
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_struct
struct|struct
name|ieee80211_mgmt
block|{
name|le16
name|frame_control
decl_stmt|;
name|le16
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
name|le16
name|seq_ctrl
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|le16
name|auth_alg
decl_stmt|;
name|le16
name|auth_transaction
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|auth
struct|;
struct|struct
block|{
name|le16
name|reason_code
decl_stmt|;
block|}
name|STRUCT_PACKED
name|deauth
struct|;
struct|struct
block|{
name|le16
name|capab_info
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|assoc_req
struct|;
struct|struct
block|{
name|le16
name|capab_info
decl_stmt|;
name|le16
name|status_code
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|assoc_resp
struct|,
name|reassoc_resp
struct|;
struct|struct
block|{
name|le16
name|capab_info
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|reassoc_req
struct|;
struct|struct
block|{
name|le16
name|reason_code
decl_stmt|;
block|}
name|STRUCT_PACKED
name|disassoc
struct|;
struct|struct
block|{
name|u8
name|timestamp
index|[
literal|8
index|]
decl_stmt|;
name|le16
name|beacon_int
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|beacon
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
name|STRUCT_PACKED
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
name|le16
name|beacon_int
decl_stmt|;
name|le16
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
name|STRUCT_PACKED
name|probe_resp
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
name|STRUCT_PACKED
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
name|STRUCT_PACKED
name|chan_switch
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|sta_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|target_ap_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
comment|/* FT Request */
block|}
name|STRUCT_PACKED
name|ft_action_req
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|sta_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|target_ap_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|le16
name|status_code
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
comment|/* FT Request */
block|}
name|STRUCT_PACKED
name|ft_action_resp
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|trans_id
index|[
name|WLAN_SA_QUERY_TR_ID_LEN
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|sa_query_req
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
comment|/* */
name|u8
name|trans_id
index|[
name|WLAN_SA_QUERY_TR_ID_LEN
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|sa_query_resp
struct|;
block|}
name|u
union|;
block|}
name|STRUCT_PACKED
name|action
struct|;
block|}
name|u
union|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

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
comment|/* HT Capability element */
end_comment

begin_enum
enum|enum
block|{
name|MAX_RX_AMPDU_FACTOR_8KB
init|=
literal|0
block|,
name|MAX_RX_AMPDU_FACTOR_16KB
block|,
name|MAX_RX_AMPDU_FACTOR_32KB
block|,
name|MAX_RX_AMPDU_FACTOR_64KB
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|CALIBRATION_NOT_SUPPORTED
init|=
literal|0
block|,
name|CALIBRATION_CANNOT_INIT
block|,
name|CALIBRATION_CAN_INIT
block|,
name|CALIBRATION_FULL_SUPPORT
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|MCS_FEEDBACK_NOT_PROVIDED
init|=
literal|0
block|,
name|MCS_FEEDBACK_UNSOLICITED
block|,
name|MCS_FEEDBACK_MRQ_RESPONSE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ieee80211_ht_capability
block|{
name|le16
name|capabilities_info
decl_stmt|;
name|u8
name|mac_ht_params_info
decl_stmt|;
name|u8
name|supported_mcs_set
index|[
literal|16
index|]
decl_stmt|;
name|le16
name|extended_ht_capability_info
decl_stmt|;
name|le32
name|tx_BF_capability_info
decl_stmt|;
name|u8
name|antenna_selection_info
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_ht_operation
block|{
name|u8
name|control_chan
decl_stmt|;
name|u8
name|ht_param
decl_stmt|;
name|le16
name|operation_mode
decl_stmt|;
name|le16
name|stbc_param
decl_stmt|;
name|u8
name|basic_set
index|[
literal|16
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* auxiliary bit manipulation macros FIXME: move it to common later... */
end_comment

begin_define
define|#
directive|define
name|SET_2BIT_U8
parameter_list|(
name|_ptr_
parameter_list|,
name|_shift_
parameter_list|,
name|_val_
parameter_list|)
define|\
value|((*(_ptr_)&= ~(3<< (_shift_))),				\ 	 (*(_ptr_) |= (*(_ptr_)& (((u8)3)<< (_shift_))) |		\ 		      (((u8)(_val_)& 3)<< _shift_)))
end_define

begin_define
define|#
directive|define
name|GET_2BIT_U8
parameter_list|(
name|_var_
parameter_list|,
name|_shift_
parameter_list|)
define|\
value|(((_var_)& (((u8)3)<< (_shift_)))>> (_shift_))
end_define

begin_define
define|#
directive|define
name|SET_2BIT_LE16
parameter_list|(
name|_u16ptr_
parameter_list|,
name|_shift_
parameter_list|,
name|_val_
parameter_list|)
define|\
value|((*(_u16ptr_)&= ~(3<< (_shift_))),				\ 	 (*(_u16ptr_) |= 						\ 		(((*(_u16ptr_))& (((u16)3)<< ((u16)_shift_))) |	\ 		(((u16)(_val_)& (u16)3)<< (u16)(_shift_)))))
end_define

begin_define
define|#
directive|define
name|GET_2BIT_LE16
parameter_list|(
name|_var_
parameter_list|,
name|_shift_
parameter_list|)
define|\
value|(((_var_)& (((u16)3)<< (_shift_)))>> (_shift_))
end_define

begin_define
define|#
directive|define
name|SET_2BIT_LE32
parameter_list|(
name|_u32ptr_
parameter_list|,
name|_shift_
parameter_list|,
name|_val_
parameter_list|)
define|\
value|((*(_u32ptr_)&= ~(3<< (_shift_))),				\ 	 (*(_u32ptr_) |= (((*(_u32ptr_))& (((u32)3)<< (_shift_))) |	\ 			(((u32)(_val_)& 3)<< _shift_))))
end_define

begin_define
define|#
directive|define
name|GET_2BIT_LE32
parameter_list|(
name|_var_
parameter_list|,
name|_shift_
parameter_list|)
define|\
value|(((_var_)& (((u32)3)<< (_shift_)))>> (_shift_))
end_define

begin_define
define|#
directive|define
name|SET_3BIT_LE16
parameter_list|(
name|_u16ptr_
parameter_list|,
name|_shift_
parameter_list|,
name|_val_
parameter_list|)
define|\
value|((*(_u16ptr_)&= ~(7<< (_shift_))),				\ 	(*(_u16ptr_) |= (((*(_u16ptr_))& (((u16)7)<< (_shift_))) |	\ 			(((u16)(_val_)& 7)<< _shift_))))
end_define

begin_define
define|#
directive|define
name|GET_3BIT_LE16
parameter_list|(
name|_var_
parameter_list|,
name|_shift_
parameter_list|)
define|\
value|(((_var_)& (((u16)7)<< (_shift_)))>> (_shift_))
end_define

begin_define
define|#
directive|define
name|SET_3BIT_LE32
parameter_list|(
name|_u32ptr_
parameter_list|,
name|_shift_
parameter_list|,
name|_val_
parameter_list|)
define|\
value|((*(_u32ptr_)&= ~(7<< (_shift_))),				\ 	 (*(_u32ptr_) |= (((*(_u32ptr_))& (((u32)7)<< (_shift_))) |	\ 			(((u32)(_val_)& 7)<< _shift_))))
end_define

begin_define
define|#
directive|define
name|GET_3BIT_LE32
parameter_list|(
name|_var_
parameter_list|,
name|_shift_
parameter_list|)
define|\
value|(((_var_)& (((u32)7)<< (_shift_)))>> (_shift_))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_LDPC_CODING_CAP
value|((u16) BIT(0))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SUPP_CHANNEL_WIDTH_SET
value|((u16) BIT(1))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SMPS_MASK
value|((u16) (BIT(2) | BIT(3)))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SMPS_STATIC
value|((u16) 0)
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SMPS_DYNAMIC
value|((u16) BIT(2))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SMPS_DISABLED
value|((u16) (BIT(2) | BIT(3)))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_GREEN_FIELD
value|((u16) BIT(4))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SHORT_GI20MHZ
value|((u16) BIT(5))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_SHORT_GI40MHZ
value|((u16) BIT(6))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_TX_STBC
value|((u16) BIT(7))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_RX_STBC_MASK
value|((u16) (BIT(8) | BIT(9)))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_RX_STBC_1
value|((u16) BIT(8))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_RX_STBC_12
value|((u16) BIT(9))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_RX_STBC_123
value|((u16) (BIT(8) | BIT(9)))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_DELAYED_BA
value|((u16) BIT(10))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_MAX_AMSDU_SIZE
value|((u16) BIT(11))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_DSSS_CCK40MHZ
value|((u16) BIT(12))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_PSMP_SUPP
value|((u16) BIT(13))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_40MHZ_INTOLERANT
value|((u16) BIT(14))
end_define

begin_define
define|#
directive|define
name|HT_CAP_INFO_LSIG_TXOP_PROTECT_SUPPORT
value|((u16) BIT(15))
end_define

begin_define
define|#
directive|define
name|MAC_HT_PARAM_INFO_MAX_RX_AMPDU_FACTOR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MAC_HT_PARAM_INFO_MAX_MPDU_DENSITY_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|EXT_HT_CAP_INFO_PCO
value|((u16) BIT(0))
end_define

begin_define
define|#
directive|define
name|EXT_HT_CAP_INFO_TRANS_TIME_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|EXT_HT_CAP_INFO_MCS_FEEDBACK_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|EXT_HT_CAP_INFO_HTC_SUPPORTED
value|((u16) BIT(10))
end_define

begin_define
define|#
directive|define
name|EXT_HT_CAP_INFO_RD_RESPONDER
value|((u16) BIT(11))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_TXBF_CAP
value|((u32) BIT(0))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_RX_STAGGERED_SOUNDING_CAP
value|((u32) BIT(1))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_TX_STAGGERED_SOUNDING_CAP
value|((u32) BIT(2))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_RX_ZLF_CAP
value|((u32) BIT(3))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_TX_ZLF_CAP
value|((u32) BIT(4))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_IMPLICIT_ZLF_CAP
value|((u32) BIT(5))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_CALIB_OFFSET
value|6
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_CSI_TXBF_CAP
value|((u32) BIT(8))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_UNCOMPR_STEERING_MATRIX_CAP
value|((u32) BIT(9))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_BF_CSI_FEEDBACK_CAP
value|((u32) BIT(10))
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_BF_CSI_FEEDBACK_OFFSET
value|11
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_UNCOMPR_STEERING_MATRIX_FEEDBACK_OFFSET
value|13
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_EXPLICIT_COMPRESSED_STEERING_MATRIX_FEEDBACK_OFFSET
value|15
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_MINIMAL_GROUPING_OFFSET
value|17
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_CSI_NUM_BEAMFORMER_ANT_OFFSET
value|19
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_UNCOMPRESSED_STEERING_MATRIX_BEAMFORMER_ANT_OFFSET
value|21
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_COMPRESSED_STEERING_MATRIX_BEAMFORMER_ANT_OFFSET
value|23
end_define

begin_define
define|#
directive|define
name|TX_BEAMFORM_CAP_SCI_MAX_OF_ROWS_BEANFORMER_SUPPORTED_OFFSET
value|25
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_ASEL_CAPABLE
value|((u8) BIT(0))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_EXPLICIT_CSI_FEEDBACK_BASED_TX_AS_CAP
value|((u8) BIT(1))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_ANT_INDICES_FEEDBACK_BASED_TX_AS_CAP
value|((u8) BIT(2))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_EXPLICIT_CSI_FEEDBACK_CAP
value|((u8) BIT(3))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_ANT_INDICES_FEEDBACK_CAP
value|((u8) BIT(4))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_RX_AS_CAP
value|((u8) BIT(5))
end_define

begin_define
define|#
directive|define
name|ASEL_CAPABILITY_TX_SOUND_PPDUS_CAP
value|((u8) BIT(6))
end_define

begin_struct
struct|struct
name|ht_cap_ie
block|{
name|u8
name|id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|struct
name|ieee80211_ht_capability
name|data
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|REC_TRANS_CHNL_WIDTH_20
value|0
end_define

begin_define
define|#
directive|define
name|REC_TRANS_CHNL_WIDTH_ANY
value|1
end_define

begin_define
define|#
directive|define
name|OP_MODE_PURE
value|0
end_define

begin_define
define|#
directive|define
name|OP_MODE_MAY_BE_LEGACY_STAS
value|1
end_define

begin_define
define|#
directive|define
name|OP_MODE_20MHZ_HT_STA_ASSOCED
value|2
end_define

begin_define
define|#
directive|define
name|OP_MODE_MIXED
value|3
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_SECONDARY_CHNL_OFF_MASK
value|((u8) BIT(0) | BIT(1))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_SECONDARY_CHNL_ABOVE
value|((u8) BIT(0))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_SECONDARY_CHNL_BELOW
value|((u8) BIT(0) | BIT(1))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_REC_TRANS_CHNL_WIDTH
value|((u8) BIT(2))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_RIFS_MODE
value|((u8) BIT(3))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_CTRL_ACCESS_ONLY
value|((u8) BIT(4))
end_define

begin_define
define|#
directive|define
name|HT_INFO_HT_PARAM_SRV_INTERVAL_GRANULARITY
value|((u8) BIT(5))
end_define

begin_define
define|#
directive|define
name|HT_INFO_OPERATION_MODE_OP_MODE_MASK
define|\
value|((le16) (0x0001 | 0x0002))
end_define

begin_define
define|#
directive|define
name|HT_INFO_OPERATION_MODE_OP_MODE_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|HT_INFO_OPERATION_MODE_NON_GF_DEVS_PRESENT
value|((u8) BIT(2))
end_define

begin_define
define|#
directive|define
name|HT_INFO_OPERATION_MODE_TRANSMIT_BURST_LIMIT
value|((u8) BIT(3))
end_define

begin_define
define|#
directive|define
name|HT_INFO_OPERATION_MODE_NON_HT_STA_PRESENT
value|((u8) BIT(4))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_DUAL_BEACON
value|((u16) BIT(6))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_DUAL_STBC_PROTECT
value|((u16) BIT(7))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_SECONDARY_BCN
value|((u16) BIT(8))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_LSIG_TXOP_PROTECT_ALLOWED
value|((u16) BIT(9))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_PCO_ACTIVE
value|((u16) BIT(10))
end_define

begin_define
define|#
directive|define
name|HT_INFO_STBC_PARAM_PCO_PHASE
value|((u16) BIT(11))
end_define

begin_comment
comment|/* Secondary channel offset element */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_CHANNEL_OFFSET_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SECONDARY_CHANNEL_OFFSET_ABOVE
value|1
end_define

begin_define
define|#
directive|define
name|SECONDARY_CHANNEL_OFFSET_BELOW
value|3
end_define

begin_struct
struct|struct
name|secondary_channel_offset_ie
block|{
name|u8
name|id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|u8
name|secondary_offset_offset
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* body of Recommended Transmit Channel Width action frame */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_WIDTH_20
value|0
end_define

begin_define
define|#
directive|define
name|CHANNEL_WIDTH_ANY
value|1
end_define

begin_struct
struct|struct
name|recommended_tx_channel_width_action
block|{
name|u8
name|category
decl_stmt|;
name|u8
name|action
decl_stmt|;
name|u8
name|channel_width
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* body of MIMO Power Save action frame */
end_comment

begin_define
define|#
directive|define
name|PWR_SAVE_MODE_STATIC
value|0
end_define

begin_define
define|#
directive|define
name|PWR_SAVE_MODE_DYNAMIC
value|1
end_define

begin_struct
struct|struct
name|mimo_pwr_save_action
block|{
name|u8
name|category
decl_stmt|;
name|u8
name|action
decl_stmt|;
name|u8
name|enable
decl_stmt|;
name|u8
name|mode
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|OUI_MICROSOFT
value|0x0050f2
end_define

begin_comment
comment|/* Microsoft (also used in Wi-Fi specs) 				* 00:50:F2 */
end_comment

begin_define
define|#
directive|define
name|WME_OUI_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|WME_OUI_SUBTYPE_INFORMATION_ELEMENT
value|0
end_define

begin_define
define|#
directive|define
name|WME_OUI_SUBTYPE_PARAMETER_ELEMENT
value|1
end_define

begin_define
define|#
directive|define
name|WME_OUI_SUBTYPE_TSPEC_ELEMENT
value|2
end_define

begin_define
define|#
directive|define
name|WME_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|WME_ACTION_CODE_SETUP_REQUEST
value|0
end_define

begin_define
define|#
directive|define
name|WME_ACTION_CODE_SETUP_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|WME_ACTION_CODE_TEARDOWN
value|2
end_define

begin_define
define|#
directive|define
name|WME_SETUP_RESPONSE_STATUS_ADMISSION_ACCEPTED
value|0
end_define

begin_define
define|#
directive|define
name|WME_SETUP_RESPONSE_STATUS_INVALID_PARAMETERS
value|1
end_define

begin_define
define|#
directive|define
name|WME_SETUP_RESPONSE_STATUS_REFUSED
value|3
end_define

begin_define
define|#
directive|define
name|WME_TSPEC_DIRECTION_UPLINK
value|0
end_define

begin_define
define|#
directive|define
name|WME_TSPEC_DIRECTION_DOWNLINK
value|1
end_define

begin_define
define|#
directive|define
name|WME_TSPEC_DIRECTION_BI_DIRECTIONAL
value|3
end_define

begin_define
define|#
directive|define
name|OUI_BROADCOM
value|0x00904c
end_define

begin_comment
comment|/* Broadcom (Epigram) */
end_comment

begin_define
define|#
directive|define
name|VENDOR_HT_CAPAB_OUI_TYPE
value|0x33
end_define

begin_comment
comment|/* 00-90-4c:0x33 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11_DEFS_H */
end_comment

end_unit

