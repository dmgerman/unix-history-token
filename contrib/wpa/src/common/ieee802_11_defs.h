begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE 802.11 Frame type definitions  * Copyright (c) 2002-2009, Jouni Malinen<j@w1.fi>  * Copyright (c) 2007-2008 Intel Corporation  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
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

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_DATA_CFACK
value|9
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_DATA_CFPOLL
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_DATA_CFACKPOLL
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_NULL
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_CFPOLL
value|14
end_define

begin_define
define|#
directive|define
name|WLAN_FC_STYPE_QOS_CFACKPOLL
value|15
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
name|WLAN_AUTH_SAE
value|3
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
name|WLAN_STATUS_TDLS_WAKEUP_ALTERNATE
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_TDLS_WAKEUP_REJECT
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_SECURITY_DISABLED
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_UNACCEPTABLE_LIFETIME
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_NOT_IN_SAME_BSS
value|7
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
name|WLAN_STATUS_ASSOC_DENIED_NO_DSSS_OFDM
value|26
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NO_HT
value|27
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_R0KH_UNREACHABLE
value|28
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ASSOC_DENIED_NO_PCO
value|29
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

begin_define
define|#
directive|define
name|WLAN_STATUS_UNSPECIFIED_QOS_FAILURE
value|32
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_REQUEST_DECLINED
value|37
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_PARAMETERS
value|38
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
name|WLAN_STATUS_INVALID_PMKID
value|53
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_MDIE
value|54
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_FTIE
value|55
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_GAS_ADV_PROTO_NOT_SUPPORTED
value|59
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_NO_OUTSTANDING_GAS_REQ
value|60
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_GAS_RESP_NOT_RECEIVED
value|61
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_STA_TIMED_OUT_WAITING_FOR_GAS_RESP
value|62
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_GAS_RESP_LARGER_THAN_LIMIT
value|63
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_REQ_REFUSED_HOME
value|64
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ADV_SRV_UNREACHABLE
value|65
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_REQ_REFUSED_SSPN
value|67
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_REQ_REFUSED_UNAUTH_ACCESS
value|68
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_INVALID_RSNIE
value|72
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_ANTI_CLOGGING_TOKEN_REQ
value|76
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_FINITE_CYCLIC_GROUP_NOT_SUPPORTED
value|77
end_define

begin_define
define|#
directive|define
name|WLAN_STATUS_TRANSMISSION_FAILURE
value|79
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

begin_define
define|#
directive|define
name|WLAN_REASON_TDLS_TEARDOWN_UNREACHABLE
value|25
end_define

begin_define
define|#
directive|define
name|WLAN_REASON_TDLS_TEARDOWN_UNSPECIFIED
value|26
end_define

begin_comment
comment|/* IEEE 802.11e */
end_comment

begin_define
define|#
directive|define
name|WLAN_REASON_DISASSOC_LOW_ACK
value|34
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
name|WLAN_EID_WAPI
value|68
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TIME_ADVERTISEMENT
value|69
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
name|WLAN_EID_SSID_LIST
value|84
end_define

begin_define
define|#
directive|define
name|WLAN_EID_BSS_MAX_IDLE_PERIOD
value|90
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TFS_REQ
value|91
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TFS_RESP
value|92
end_define

begin_define
define|#
directive|define
name|WLAN_EID_WNMSLEEP
value|93
end_define

begin_define
define|#
directive|define
name|WLAN_EID_TIME_ZONE
value|98
end_define

begin_define
define|#
directive|define
name|WLAN_EID_LINK_ID
value|101
end_define

begin_define
define|#
directive|define
name|WLAN_EID_INTERWORKING
value|107
end_define

begin_define
define|#
directive|define
name|WLAN_EID_ADV_PROTO
value|108
end_define

begin_define
define|#
directive|define
name|WLAN_EID_ROAMING_CONSORTIUM
value|111
end_define

begin_define
define|#
directive|define
name|WLAN_EID_EXT_CAPAB
value|127
end_define

begin_define
define|#
directive|define
name|WLAN_EID_CCKM
value|156
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_CAP
value|191
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_OPERATION
value|192
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_EXTENDED_BSS_LOAD
value|193
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_WIDE_BW_CHSWITCH
value|194
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_TRANSMIT_POWER_ENVELOPE
value|195
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_CHANNEL_SWITCH_WRAPPER
value|196
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_AID
value|197
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_QUIET_CHANNEL
value|198
end_define

begin_define
define|#
directive|define
name|WLAN_EID_VHT_OPERATING_MODE_NOTIFICATION
value|199
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
name|WLAN_ACTION_PUBLIC
value|4
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
name|WLAN_ACTION_HT
value|7
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
name|WLAN_ACTION_WNM
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_UNPROTECTED_WNM
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_TDLS
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_ACTION_WMM
value|17
end_define

begin_comment
comment|/* WMM Specification 1.1 */
end_comment

begin_define
define|#
directive|define
name|WLAN_ACTION_VENDOR_SPECIFIC
value|127
end_define

begin_comment
comment|/* Public action codes */
end_comment

begin_define
define|#
directive|define
name|WLAN_PA_20_40_BSS_COEX
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_PA_VENDOR_SPECIFIC
value|9
end_define

begin_define
define|#
directive|define
name|WLAN_PA_GAS_INITIAL_REQ
value|10
end_define

begin_define
define|#
directive|define
name|WLAN_PA_GAS_INITIAL_RESP
value|11
end_define

begin_define
define|#
directive|define
name|WLAN_PA_GAS_COMEBACK_REQ
value|12
end_define

begin_define
define|#
directive|define
name|WLAN_PA_GAS_COMEBACK_RESP
value|13
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_DISCOVERY_RESPONSE
value|14
end_define

begin_comment
comment|/* SA Query Action frame (IEEE 802.11w/D8.0, 7.4.9) */
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
value|2
end_define

begin_comment
comment|/* TDLS action codes */
end_comment

begin_define
define|#
directive|define
name|WLAN_TDLS_SETUP_REQUEST
value|0
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_SETUP_RESPONSE
value|1
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_SETUP_CONFIRM
value|2
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_TEARDOWN
value|3
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_PEER_TRAFFIC_INDICATION
value|4
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_CHANNEL_SWITCH_REQUEST
value|5
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_CHANNEL_SWITCH_RESPONSE
value|6
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_PEER_PSM_REQUEST
value|7
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_PEER_PSM_RESPONSE
value|8
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_PEER_TRAFFIC_RESPONSE
value|9
end_define

begin_define
define|#
directive|define
name|WLAN_TDLS_DISCOVERY_REQUEST
value|10
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

begin_comment
comment|/* Interworking element (IEEE 802.11u) - Access Network Options */
end_comment

begin_define
define|#
directive|define
name|INTERWORKING_ANO_ACCESS_NETWORK_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANO_INTERNET
value|0x10
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANO_ASRA
value|0x20
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANO_ESR
value|0x40
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANO_UESA
value|0x80
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_PRIVATE
value|0
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_PRIVATE_WITH_GUEST
value|1
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_CHARGEABLE_PUBLIC
value|2
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_FREE_PUBLIC
value|3
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_PERSONAL_DEVICE
value|4
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_EMERGENCY_SERVICES
value|5
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_TEST
value|6
end_define

begin_define
define|#
directive|define
name|INTERWORKING_ANT_WILDCARD
value|15
end_define

begin_comment
comment|/* Advertisement Protocol ID definitions (IEEE Std 802.11u-2011) */
end_comment

begin_enum
enum|enum
name|adv_proto_id
block|{
name|ACCESS_NETWORK_QUERY_PROTOCOL
init|=
literal|0
block|,
name|MIH_INFO_SERVICE
init|=
literal|1
block|,
name|MIH_CMD_AND_EVENT_DISCOVERY
init|=
literal|2
block|,
name|EMERGENCY_ALERT_SYSTEM
init|=
literal|3
block|,
name|ADV_PROTO_VENDOR_SPECIFIC
init|=
literal|221
block|}
enum|;
end_enum

begin_comment
comment|/* Access Network Query Protocol info ID definitions (IEEE Std 802.11u-2011) */
end_comment

begin_enum
enum|enum
name|anqp_info_id
block|{
name|ANQP_QUERY_LIST
init|=
literal|256
block|,
name|ANQP_CAPABILITY_LIST
init|=
literal|257
block|,
name|ANQP_VENUE_NAME
init|=
literal|258
block|,
name|ANQP_EMERGENCY_CALL_NUMBER
init|=
literal|259
block|,
name|ANQP_NETWORK_AUTH_TYPE
init|=
literal|260
block|,
name|ANQP_ROAMING_CONSORTIUM
init|=
literal|261
block|,
name|ANQP_IP_ADDR_TYPE_AVAILABILITY
init|=
literal|262
block|,
name|ANQP_NAI_REALM
init|=
literal|263
block|,
name|ANQP_3GPP_CELLULAR_NETWORK
init|=
literal|264
block|,
name|ANQP_AP_GEOSPATIAL_LOCATION
init|=
literal|265
block|,
name|ANQP_AP_CIVIC_LOCATION
init|=
literal|266
block|,
name|ANQP_AP_LOCATION_PUBLIC_URI
init|=
literal|267
block|,
name|ANQP_DOMAIN_NAME
init|=
literal|268
block|,
name|ANQP_EMERGENCY_ALERT_URI
init|=
literal|269
block|,
name|ANQP_EMERGENCY_NAI
init|=
literal|271
block|,
name|ANQP_VENDOR_SPECIFIC
init|=
literal|56797
block|}
enum|;
end_enum

begin_comment
comment|/* NAI Realm list - EAP Method subfield - Authentication Parameter ID */
end_comment

begin_enum
enum|enum
name|nai_realm_eap_auth_param
block|{
name|NAI_REALM_EAP_AUTH_EXPANDED_EAP_METHOD
init|=
literal|1
block|,
name|NAI_REALM_EAP_AUTH_NON_EAP_INNER_AUTH
init|=
literal|2
block|,
name|NAI_REALM_EAP_AUTH_INNER_AUTH_EAP_METHOD
init|=
literal|3
block|,
name|NAI_REALM_EAP_AUTH_EXPANDED_INNER_EAP_METHOD
init|=
literal|4
block|,
name|NAI_REALM_EAP_AUTH_CRED_TYPE
init|=
literal|5
block|,
name|NAI_REALM_EAP_AUTH_TUNNELED_CRED_TYPE
init|=
literal|6
block|,
name|NAI_REALM_EAP_AUTH_VENDOR_SPECIFIC
init|=
literal|221
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nai_realm_eap_auth_inner_non_eap
block|{
name|NAI_REALM_INNER_NON_EAP_PAP
init|=
literal|1
block|,
name|NAI_REALM_INNER_NON_EAP_CHAP
init|=
literal|2
block|,
name|NAI_REALM_INNER_NON_EAP_MSCHAP
init|=
literal|3
block|,
name|NAI_REALM_INNER_NON_EAP_MSCHAPV2
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nai_realm_eap_cred_type
block|{
name|NAI_REALM_CRED_TYPE_SIM
init|=
literal|1
block|,
name|NAI_REALM_CRED_TYPE_USIM
init|=
literal|2
block|,
name|NAI_REALM_CRED_TYPE_NFC_SECURE_ELEMENT
init|=
literal|3
block|,
name|NAI_REALM_CRED_TYPE_HARDWARE_TOKEN
init|=
literal|4
block|,
name|NAI_REALM_CRED_TYPE_SOFTOKEN
init|=
literal|5
block|,
name|NAI_REALM_CRED_TYPE_CERTIFICATE
init|=
literal|6
block|,
name|NAI_REALM_CRED_TYPE_USERNAME_PASSWORD
init|=
literal|7
block|,
name|NAI_REALM_CRED_TYPE_NONE
init|=
literal|8
block|,
name|NAI_REALM_CRED_TYPE_ANONYMOUS
init|=
literal|9
block|,
name|NAI_REALM_CRED_TYPE_VENDOR_SPECIFIC
init|=
literal|10
block|}
enum|;
end_enum

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
name|ieee80211_hdr
block|{
name|le16
name|frame_control
decl_stmt|;
name|le16
name|duration_id
decl_stmt|;
name|u8
name|addr1
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|addr2
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|addr3
index|[
literal|6
index|]
decl_stmt|;
name|le16
name|seq_ctrl
decl_stmt|;
comment|/* followed by 'u8 addr4[6];' if ToDS and FromDS is set in data frame 	 */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_DA_FROMDS
value|addr1
end_define

begin_define
define|#
directive|define
name|IEEE80211_BSSID_FROMDS
value|addr2
end_define

begin_define
define|#
directive|define
name|IEEE80211_SA_FROMDS
value|addr3
end_define

begin_define
define|#
directive|define
name|IEEE80211_HDRLEN
value|(sizeof(struct ieee80211_hdr))
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC
parameter_list|(
name|type
parameter_list|,
name|stype
parameter_list|)
value|host_to_le16((type<< 2) | (stype<< 4))
end_define

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
name|u8
name|variable
index|[
literal|0
index|]
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
name|u8
name|variable
index|[
literal|0
index|]
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
name|wmm_action
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
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialogtoken
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|wnm_sleep_req
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialogtoken
decl_stmt|;
name|le16
name|keydata_len
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|wnm_sleep_resp
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|public_action
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
comment|/* 9 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* Vendor-specific content */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|vs_public_action
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
comment|/* 7 */
name|u8
name|dialog_token
decl_stmt|;
name|u8
name|req_mode
decl_stmt|;
name|le16
name|disassoc_timer
decl_stmt|;
name|u8
name|validity_interval
decl_stmt|;
comment|/* BSS Termination Duration (optional), 					 * Session Information URL (optional), 					 * BSS Transition Candidate List 					 * Entries */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|bss_tm_req
struct|;
struct|struct
block|{
name|u8
name|action
decl_stmt|;
comment|/* 8 */
name|u8
name|dialog_token
decl_stmt|;
name|u8
name|status_code
decl_stmt|;
name|u8
name|bss_termination_delay
decl_stmt|;
comment|/* Target BSSID (optional), 					 * BSS Transition Candidate List 					 * Entries (optional) */
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
name|bss_tm_resp
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

begin_comment
comment|/* Rx MCS bitmask is in the first 77 bits of supported_mcs_set */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_HT_MCS_MASK_LEN
value|10
end_define

begin_struct
struct|struct
name|ieee80211_ht_capabilities
block|{
name|le16
name|ht_capabilities_info
decl_stmt|;
name|u8
name|a_mpdu_params
decl_stmt|;
name|u8
name|supported_mcs_set
index|[
literal|16
index|]
decl_stmt|;
name|le16
name|ht_extended_capabilities
decl_stmt|;
name|le32
name|tx_bf_capability_info
decl_stmt|;
name|u8
name|asel_capabilities
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

begin_struct
struct|struct
name|ieee80211_vht_capabilities
block|{
name|le32
name|vht_capabilities_info
decl_stmt|;
name|u8
name|vht_supported_mcs_set
index|[
literal|8
index|]
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_vht_operation
block|{
name|u8
name|vht_op_info_chwidth
decl_stmt|;
name|u8
name|vht_op_info_chan_center_freq_seg0_idx
decl_stmt|;
name|u8
name|vht_op_info_chan_center_freq_seg1_idx
decl_stmt|;
name|le16
name|vht_basic_mcs_set
decl_stmt|;
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
name|HT_INFO_OPERATION_MODE_OP_MODE_MASK
define|\
value|(0x0001 | 0x0002)
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

begin_define
define|#
directive|define
name|BSS_MEMBERSHIP_SELECTOR_VHT_PHY
value|126
end_define

begin_define
define|#
directive|define
name|BSS_MEMBERSHIP_SELECTOR_HT_PHY
value|127
end_define

begin_comment
comment|/* VHT Defines */
end_comment

begin_define
define|#
directive|define
name|VHT_CAP_MAX_MPDU_LENGTH_7991
value|((u32) BIT(0))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_MAX_MPDU_LENGTH_11454
value|((u32) BIT(1))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SUPP_CHAN_WIDTH_160MHZ
value|((u32) BIT(2))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SUPP_CHAN_WIDTH_160_80PLUS80MHZ
value|((u32) BIT(3))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RXLDPC
value|((u32) BIT(4))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SHORT_GI_80
value|((u32) BIT(5))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SHORT_GI_160
value|((u32) BIT(6))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_TXSTBC
value|((u32) BIT(7))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RXSTBC_1
value|((u32) BIT(8))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RXSTBC_2
value|((u32) BIT(9))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RXSTBC_3
value|((u32) BIT(8) | BIT(9))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RXSTBC_4
value|((u32) BIT(10))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SU_BEAMFORMER_CAPABLE
value|((u32) BIT(11))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SU_BEAMFORMEE_CAPABLE
value|((u32) BIT(12))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_BEAMFORMER_ANTENNAS_MAX
value|((u32) BIT(13) | BIT(14))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_SOUNDING_DIMENTION_MAX
value|((u32) BIT(16) | BIT(17))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_MU_BEAMFORMER_CAPABLE
value|((u32) BIT(19))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_MU_BEAMFORMEE_CAPABLE
value|((u32) BIT(20))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_VHT_TXOP_PS
value|((u32) BIT(21))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_HTC_VHT
value|((u32) BIT(22))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT
value|((u32) BIT(23))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_VHT_LINK_ADAPTATION_VHT_UNSOL_MFB
value|((u32) BIT(27))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_VHT_LINK_ADAPTATION_VHT_MRQ_MFB
value|((u32) BIT(26) | BIT(27))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_RX_ANTENNA_PATTERN
value|((u32) BIT(28))
end_define

begin_define
define|#
directive|define
name|VHT_CAP_TX_ANTENNA_PATTERN
value|((u32) BIT(29))
end_define

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
name|WPA_IE_VENDOR_TYPE
value|0x0050f201
end_define

begin_define
define|#
directive|define
name|WPS_IE_VENDOR_TYPE
value|0x0050f204
end_define

begin_define
define|#
directive|define
name|OUI_WFA
value|0x506f9a
end_define

begin_define
define|#
directive|define
name|P2P_IE_VENDOR_TYPE
value|0x506f9a09
end_define

begin_define
define|#
directive|define
name|WFD_IE_VENDOR_TYPE
value|0x506f9a0a
end_define

begin_define
define|#
directive|define
name|WFD_OUI_TYPE
value|10
end_define

begin_define
define|#
directive|define
name|HS20_IE_VENDOR_TYPE
value|0x506f9a10
end_define

begin_define
define|#
directive|define
name|WMM_OUI_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|WMM_OUI_SUBTYPE_INFORMATION_ELEMENT
value|0
end_define

begin_define
define|#
directive|define
name|WMM_OUI_SUBTYPE_PARAMETER_ELEMENT
value|1
end_define

begin_define
define|#
directive|define
name|WMM_OUI_SUBTYPE_TSPEC_ELEMENT
value|2
end_define

begin_define
define|#
directive|define
name|WMM_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|WMM_ACTION_CODE_ADDTS_REQ
value|0
end_define

begin_define
define|#
directive|define
name|WMM_ACTION_CODE_ADDTS_RESP
value|1
end_define

begin_define
define|#
directive|define
name|WMM_ACTION_CODE_DELTS
value|2
end_define

begin_define
define|#
directive|define
name|WMM_ADDTS_STATUS_ADMISSION_ACCEPTED
value|0
end_define

begin_define
define|#
directive|define
name|WMM_ADDTS_STATUS_INVALID_PARAMETERS
value|1
end_define

begin_comment
comment|/* 2 - Reserved */
end_comment

begin_define
define|#
directive|define
name|WMM_ADDTS_STATUS_REFUSED
value|3
end_define

begin_comment
comment|/* 4-255 - Reserved */
end_comment

begin_comment
comment|/* WMM TSPEC Direction Field Values */
end_comment

begin_define
define|#
directive|define
name|WMM_TSPEC_DIRECTION_UPLINK
value|0
end_define

begin_define
define|#
directive|define
name|WMM_TSPEC_DIRECTION_DOWNLINK
value|1
end_define

begin_comment
comment|/* 2 - Reserved */
end_comment

begin_define
define|#
directive|define
name|WMM_TSPEC_DIRECTION_BI_DIRECTIONAL
value|3
end_define

begin_comment
comment|/*  * WMM Information Element (used in (Re)Association Request frames; may also be  * used in Beacon frames)  */
end_comment

begin_struct
struct|struct
name|wmm_information_element
block|{
comment|/* Element ID: 221 (0xdd); Length: 7 */
comment|/* required fields for WMM version 1 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 0 */
name|u8
name|version
decl_stmt|;
comment|/* 1 for WMM version 1.0 */
name|u8
name|qos_info
decl_stmt|;
comment|/* AP/STA specific QoS info */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|WMM_QOSINFO_STA_AC_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|WMM_QOSINFO_STA_SP_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|WMM_QOSINFO_STA_SP_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|WMM_AC_AIFSN_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|WMM_AC_AIFNS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACM
value|0x10
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACI_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|WMM_AC_ACI_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMIN_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMAX_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|WMM_AC_ECWMAX_SHIFT
value|4
end_define

begin_struct
struct|struct
name|wmm_ac_parameter
block|{
name|u8
name|aci_aifsn
decl_stmt|;
comment|/* AIFSN, ACM, ACI */
name|u8
name|cw
decl_stmt|;
comment|/* ECWmin, ECWmax (CW = 2^ECW - 1) */
name|le16
name|txop_limit
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/*  * WMM Parameter Element (used in Beacon, Probe Response, and (Re)Association  * Response frmaes)  */
end_comment

begin_struct
struct|struct
name|wmm_parameter_element
block|{
comment|/* Element ID: 221 (0xdd); Length: 24 */
comment|/* required fields for WMM version 1 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 1 */
name|u8
name|version
decl_stmt|;
comment|/* 1 for WMM version 1.0 */
name|u8
name|qos_info
decl_stmt|;
comment|/* AP/STA specific QoS info */
name|u8
name|reserved
decl_stmt|;
comment|/* 0 */
name|struct
name|wmm_ac_parameter
name|ac
index|[
literal|4
index|]
decl_stmt|;
comment|/* AC_BE, AC_BK, AC_VI, AC_VO */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* WMM TSPEC Element */
end_comment

begin_struct
struct|struct
name|wmm_tspec_element
block|{
name|u8
name|eid
decl_stmt|;
comment|/* 221 = 0xdd */
name|u8
name|length
decl_stmt|;
comment|/* 6 + 55 = 61 */
name|u8
name|oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 00:50:f2 */
name|u8
name|oui_type
decl_stmt|;
comment|/* 2 */
name|u8
name|oui_subtype
decl_stmt|;
comment|/* 2 */
name|u8
name|version
decl_stmt|;
comment|/* 1 */
comment|/* WMM TSPEC body (55 octets): */
name|u8
name|ts_info
index|[
literal|3
index|]
decl_stmt|;
name|le16
name|nominal_msdu_size
decl_stmt|;
name|le16
name|maximum_msdu_size
decl_stmt|;
name|le32
name|minimum_service_interval
decl_stmt|;
name|le32
name|maximum_service_interval
decl_stmt|;
name|le32
name|inactivity_interval
decl_stmt|;
name|le32
name|suspension_interval
decl_stmt|;
name|le32
name|service_start_time
decl_stmt|;
name|le32
name|minimum_data_rate
decl_stmt|;
name|le32
name|mean_data_rate
decl_stmt|;
name|le32
name|peak_data_rate
decl_stmt|;
name|le32
name|maximum_burst_size
decl_stmt|;
name|le32
name|delay_bound
decl_stmt|;
name|le32
name|minimum_phy_rate
decl_stmt|;
name|le16
name|surplus_bandwidth_allowance
decl_stmt|;
name|le16
name|medium_time
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* Access Categories / ACI to AC coding */
end_comment

begin_enum
enum|enum
block|{
name|WMM_AC_BE
init|=
literal|0
comment|/* Best Effort */
block|,
name|WMM_AC_BK
init|=
literal|1
comment|/* Background */
block|,
name|WMM_AC_VI
init|=
literal|2
comment|/* Video */
block|,
name|WMM_AC_VO
init|=
literal|3
comment|/* Voice */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HS20_INDICATION_OUI_TYPE
value|16
end_define

begin_define
define|#
directive|define
name|HS20_ANQP_OUI_TYPE
value|17
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_QUERY_LIST
value|1
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_CAPABILITY_LIST
value|2
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_OPERATOR_FRIENDLY_NAME
value|3
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_WAN_METRICS
value|4
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_CONNECTION_CAPABILITY
value|5
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_NAI_HOME_REALM_QUERY
value|6
end_define

begin_define
define|#
directive|define
name|HS20_STYPE_OPERATING_CLASS
value|7
end_define

begin_comment
comment|/* Wi-Fi Direct (P2P) */
end_comment

begin_define
define|#
directive|define
name|P2P_OUI_TYPE
value|9
end_define

begin_enum
enum|enum
name|p2p_attr_id
block|{
name|P2P_ATTR_STATUS
init|=
literal|0
block|,
name|P2P_ATTR_MINOR_REASON_CODE
init|=
literal|1
block|,
name|P2P_ATTR_CAPABILITY
init|=
literal|2
block|,
name|P2P_ATTR_DEVICE_ID
init|=
literal|3
block|,
name|P2P_ATTR_GROUP_OWNER_INTENT
init|=
literal|4
block|,
name|P2P_ATTR_CONFIGURATION_TIMEOUT
init|=
literal|5
block|,
name|P2P_ATTR_LISTEN_CHANNEL
init|=
literal|6
block|,
name|P2P_ATTR_GROUP_BSSID
init|=
literal|7
block|,
name|P2P_ATTR_EXT_LISTEN_TIMING
init|=
literal|8
block|,
name|P2P_ATTR_INTENDED_INTERFACE_ADDR
init|=
literal|9
block|,
name|P2P_ATTR_MANAGEABILITY
init|=
literal|10
block|,
name|P2P_ATTR_CHANNEL_LIST
init|=
literal|11
block|,
name|P2P_ATTR_NOTICE_OF_ABSENCE
init|=
literal|12
block|,
name|P2P_ATTR_DEVICE_INFO
init|=
literal|13
block|,
name|P2P_ATTR_GROUP_INFO
init|=
literal|14
block|,
name|P2P_ATTR_GROUP_ID
init|=
literal|15
block|,
name|P2P_ATTR_INTERFACE
init|=
literal|16
block|,
name|P2P_ATTR_OPERATING_CHANNEL
init|=
literal|17
block|,
name|P2P_ATTR_INVITATION_FLAGS
init|=
literal|18
block|,
name|P2P_ATTR_VENDOR_SPECIFIC
init|=
literal|221
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|P2P_MAX_GO_INTENT
value|15
end_define

begin_comment
comment|/* P2P Capability - Device Capability bitmap */
end_comment

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_SERVICE_DISCOVERY
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_CLIENT_DISCOVERABILITY
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_CONCURRENT_OPER
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_INFRA_MANAGED
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_DEVICE_LIMIT
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|P2P_DEV_CAPAB_INVITATION_PROCEDURE
value|BIT(5)
end_define

begin_comment
comment|/* P2P Capability - Group Capability bitmap */
end_comment

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_GROUP_OWNER
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_PERSISTENT_GROUP
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_GROUP_LIMIT
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_INTRA_BSS_DIST
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_CROSS_CONN
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_PERSISTENT_RECONN
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|P2P_GROUP_CAPAB_GROUP_FORMATION
value|BIT(6)
end_define

begin_comment
comment|/* Invitation Flags */
end_comment

begin_define
define|#
directive|define
name|P2P_INVITATION_FLAGS_TYPE
value|BIT(0)
end_define

begin_comment
comment|/* P2P Manageability */
end_comment

begin_define
define|#
directive|define
name|P2P_MAN_DEVICE_MANAGEMENT
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|P2P_MAN_CROSS_CONNECTION_PERMITTED
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|P2P_MAN_COEXISTENCE_OPTIONAL
value|BIT(2)
end_define

begin_enum
enum|enum
name|p2p_status_code
block|{
name|P2P_SC_SUCCESS
init|=
literal|0
block|,
name|P2P_SC_FAIL_INFO_CURRENTLY_UNAVAILABLE
init|=
literal|1
block|,
name|P2P_SC_FAIL_INCOMPATIBLE_PARAMS
init|=
literal|2
block|,
name|P2P_SC_FAIL_LIMIT_REACHED
init|=
literal|3
block|,
name|P2P_SC_FAIL_INVALID_PARAMS
init|=
literal|4
block|,
name|P2P_SC_FAIL_UNABLE_TO_ACCOMMODATE
init|=
literal|5
block|,
name|P2P_SC_FAIL_PREV_PROTOCOL_ERROR
init|=
literal|6
block|,
name|P2P_SC_FAIL_NO_COMMON_CHANNELS
init|=
literal|7
block|,
name|P2P_SC_FAIL_UNKNOWN_GROUP
init|=
literal|8
block|,
name|P2P_SC_FAIL_BOTH_GO_INTENT_15
init|=
literal|9
block|,
name|P2P_SC_FAIL_INCOMPATIBLE_PROV_METHOD
init|=
literal|10
block|,
name|P2P_SC_FAIL_REJECTED_BY_USER
init|=
literal|11
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|P2P_WILDCARD_SSID
value|"DIRECT-"
end_define

begin_define
define|#
directive|define
name|P2P_WILDCARD_SSID_LEN
value|7
end_define

begin_comment
comment|/* P2P action frames */
end_comment

begin_enum
enum|enum
name|p2p_act_frame_type
block|{
name|P2P_NOA
init|=
literal|0
block|,
name|P2P_PRESENCE_REQ
init|=
literal|1
block|,
name|P2P_PRESENCE_RESP
init|=
literal|2
block|,
name|P2P_GO_DISC_REQ
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* P2P public action frames */
end_comment

begin_enum
enum|enum
name|p2p_action_frame_type
block|{
name|P2P_GO_NEG_REQ
init|=
literal|0
block|,
name|P2P_GO_NEG_RESP
init|=
literal|1
block|,
name|P2P_GO_NEG_CONF
init|=
literal|2
block|,
name|P2P_INVITATION_REQ
init|=
literal|3
block|,
name|P2P_INVITATION_RESP
init|=
literal|4
block|,
name|P2P_DEV_DISC_REQ
init|=
literal|5
block|,
name|P2P_DEV_DISC_RESP
init|=
literal|6
block|,
name|P2P_PROV_DISC_REQ
init|=
literal|7
block|,
name|P2P_PROV_DISC_RESP
init|=
literal|8
block|}
enum|;
end_enum

begin_enum
enum|enum
name|p2p_service_protocol_type
block|{
name|P2P_SERV_ALL_SERVICES
init|=
literal|0
block|,
name|P2P_SERV_BONJOUR
init|=
literal|1
block|,
name|P2P_SERV_UPNP
init|=
literal|2
block|,
name|P2P_SERV_WS_DISCOVERY
init|=
literal|3
block|,
name|P2P_SERV_WIFI_DISPLAY
init|=
literal|4
block|,
name|P2P_SERV_VENDOR_SPECIFIC
init|=
literal|255
block|}
enum|;
end_enum

begin_enum
enum|enum
name|p2p_sd_status
block|{
name|P2P_SD_SUCCESS
init|=
literal|0
block|,
name|P2P_SD_PROTO_NOT_AVAILABLE
init|=
literal|1
block|,
name|P2P_SD_REQUESTED_INFO_NOT_AVAILABLE
init|=
literal|2
block|,
name|P2P_SD_BAD_REQUEST
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|wifi_display_subelem
block|{
name|WFD_SUBELEM_DEVICE_INFO
init|=
literal|0
block|,
name|WFD_SUBELEM_ASSOCIATED_BSSID
init|=
literal|1
block|,
name|WFD_SUBELEM_AUDIO_FORMATS
init|=
literal|2
block|,
name|WFD_SUBELEM_VIDEO_FORMATS
init|=
literal|3
block|,
name|WFD_SUBELEM_3D_VIDEO_FORMATS
init|=
literal|4
block|,
name|WFD_SUBELEM_CONTENT_PROTECTION
init|=
literal|5
block|,
name|WFD_SUBELEM_COUPLED_SINK
init|=
literal|6
block|,
name|WFD_SUBELEM_EXT_CAPAB
init|=
literal|7
block|,
name|WFD_SUBELEM_LOCAL_IP_ADDRESS
init|=
literal|8
block|,
name|WFD_SUBELEM_SESSION_INFO
init|=
literal|9
block|}
enum|;
end_enum

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

begin_comment
comment|/* cipher suite selectors */
end_comment

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_USE_GROUP
value|0x000FAC00
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_WEP40
value|0x000FAC01
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_TKIP
value|0x000FAC02
end_define

begin_comment
comment|/* reserved: 				0x000FAC03 */
end_comment

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_CCMP
value|0x000FAC04
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_WEP104
value|0x000FAC05
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_AES_CMAC
value|0x000FAC06
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_NO_GROUP_ADDR
value|0x000FAC07
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_GCMP
value|0x000FAC08
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_SMS4
value|0x00147201
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_CKIP
value|0x00409600
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_CKIP_CMIC
value|0x00409601
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_CMIC
value|0x00409602
end_define

begin_define
define|#
directive|define
name|WLAN_CIPHER_SUITE_KRK
value|0x004096FF
end_define

begin_comment
comment|/* for nl80211 use only */
end_comment

begin_comment
comment|/* AKM suite selectors */
end_comment

begin_define
define|#
directive|define
name|WLAN_AKM_SUITE_8021X
value|0x000FAC01
end_define

begin_define
define|#
directive|define
name|WLAN_AKM_SUITE_PSK
value|0x000FAC02
end_define

begin_define
define|#
directive|define
name|WLAN_AKM_SUITE_CCKM
value|0x00409600
end_define

begin_comment
comment|/* IEEE 802.11v - WNM Action field values */
end_comment

begin_enum
enum|enum
name|wnm_action
block|{
name|WNM_EVENT_REQ
init|=
literal|0
block|,
name|WNM_EVENT_REPORT
init|=
literal|1
block|,
name|WNM_DIAGNOSTIC_REQ
init|=
literal|2
block|,
name|WNM_DIAGNOSTIC_REPORT
init|=
literal|3
block|,
name|WNM_LOCATION_CFG_REQ
init|=
literal|4
block|,
name|WNM_LOCATION_CFG_RESP
init|=
literal|5
block|,
name|WNM_BSS_TRANS_MGMT_QUERY
init|=
literal|6
block|,
name|WNM_BSS_TRANS_MGMT_REQ
init|=
literal|7
block|,
name|WNM_BSS_TRANS_MGMT_RESP
init|=
literal|8
block|,
name|WNM_FMS_REQ
init|=
literal|9
block|,
name|WNM_FMS_RESP
init|=
literal|10
block|,
name|WNM_COLLOCATED_INTERFERENCE_REQ
init|=
literal|11
block|,
name|WNM_COLLOCATED_INTERFERENCE_REPORT
init|=
literal|12
block|,
name|WNM_TFS_REQ
init|=
literal|13
block|,
name|WNM_TFS_RESP
init|=
literal|14
block|,
name|WNM_TFS_NOTIFY
init|=
literal|15
block|,
name|WNM_SLEEP_MODE_REQ
init|=
literal|16
block|,
name|WNM_SLEEP_MODE_RESP
init|=
literal|17
block|,
name|WNM_TIM_BROADCAST_REQ
init|=
literal|18
block|,
name|WNM_TIM_BROADCAST_RESP
init|=
literal|19
block|,
name|WNM_QOS_TRAFFIC_CAPAB_UPDATE
init|=
literal|20
block|,
name|WNM_CHANNEL_USAGE_REQ
init|=
literal|21
block|,
name|WNM_CHANNEL_USAGE_RESP
init|=
literal|22
block|,
name|WNM_DMS_REQ
init|=
literal|23
block|,
name|WNM_DMS_RESP
init|=
literal|24
block|,
name|WNM_TIMING_MEASUREMENT_REQ
init|=
literal|25
block|,
name|WNM_NOTIFICATION_REQ
init|=
literal|26
block|,
name|WNM_NOTIFICATION_RESP
init|=
literal|27
block|}
enum|;
end_enum

begin_comment
comment|/* IEEE 802.11v - BSS Transition Management Request - Request Mode */
end_comment

begin_define
define|#
directive|define
name|WNM_BSS_TM_REQ_PREF_CAND_LIST_INCLUDED
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WNM_BSS_TM_REQ_ABRIDGED
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WNM_BSS_TM_REQ_DISASSOC_IMMINENT
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WNM_BSS_TM_REQ_BSS_TERMINATION_INCLUDED
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WNM_BSS_TM_REQ_ESS_DISASSOC_IMMINENT
value|BIT(4)
end_define

begin_comment
comment|/* IEEE Std 802.11-2012, 8.4.2.62 20/40 BSS Coexistence element */
end_comment

begin_define
define|#
directive|define
name|WLAN_20_40_BSS_COEX_INFO_REQ
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|WLAN_20_40_BSS_COEX_40MHZ_INTOL
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|WLAN_20_40_BSS_COEX_20MHZ_WIDTH_REQ
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|WLAN_20_40_BSS_COEX_OBSS_EXEMPT_REQ
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|WLAN_20_40_BSS_COEX_OBSS_EXEMPT_GRNT
value|BIT(4)
end_define

begin_struct
struct|struct
name|ieee80211_2040_bss_coex_ie
block|{
name|u8
name|element_id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|u8
name|coex_param
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|ieee80211_2040_intol_chan_report
block|{
name|u8
name|element_id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|u8
name|op_class
decl_stmt|;
name|u8
name|variable
index|[
literal|0
index|]
decl_stmt|;
comment|/* Channel List */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_comment
comment|/* IEEE 802.11v - WNM-Sleep Mode element */
end_comment

begin_struct
struct|struct
name|wnm_sleep_element
block|{
name|u8
name|eid
decl_stmt|;
comment|/* WLAN_EID_WNMSLEEP */
name|u8
name|len
decl_stmt|;
name|u8
name|action_type
decl_stmt|;
comment|/* WNM_SLEEP_ENTER/WNM_SLEEP_MODE_EXIT */
name|u8
name|status
decl_stmt|;
name|le16
name|intval
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|WNM_SLEEP_MODE_ENTER
value|0
end_define

begin_define
define|#
directive|define
name|WNM_SLEEP_MODE_EXIT
value|1
end_define

begin_enum
enum|enum
name|wnm_sleep_mode_response_status
block|{
name|WNM_STATUS_SLEEP_ACCEPT
init|=
literal|0
block|,
name|WNM_STATUS_SLEEP_EXIT_ACCEPT_GTK_UPDATE
init|=
literal|1
block|,
name|WNM_STATUS_DENIED_ACTION
init|=
literal|2
block|,
name|WNM_STATUS_DENIED_TMP
init|=
literal|3
block|,
name|WNM_STATUS_DENIED_KEY
init|=
literal|4
block|,
name|WNM_STATUS_DENIED_OTHER_WNM_SERVICE
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|/* WNM-Sleep Mode subelement IDs */
end_comment

begin_enum
enum|enum
name|wnm_sleep_mode_subelement_id
block|{
name|WNM_SLEEP_SUBELEM_GTK
init|=
literal|0
block|,
name|WNM_SLEEP_SUBELEM_IGTK
init|=
literal|1
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_11_DEFS_H */
end_comment

end_unit

