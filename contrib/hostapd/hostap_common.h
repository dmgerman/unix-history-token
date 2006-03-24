begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HOSTAP_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTAP_COMMON_H
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|MAC2STR
parameter_list|(
name|a
parameter_list|)
value|(a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
end_define

begin_define
define|#
directive|define
name|MACSTR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_PAE
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_PAE
value|0x888E
end_define

begin_comment
comment|/* Port Access Entity (IEEE 802.1X) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ETH_P_PAE */
end_comment

begin_define
define|#
directive|define
name|ETH_P_PREAUTH
value|0x88C7
end_define

begin_comment
comment|/* IEEE 802.11i pre-authentication */
end_comment

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
comment|/* 802.11b */
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
name|WLAN_EID_CHALLENGE
value|16
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
name|WLAN_EID_GENERIC
value|221
end_define

begin_comment
comment|/* HFA384X Configuration RIDs */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPORTTYPE
value|0xFC00
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNMACADDR
value|0xFC01
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDESIREDSSID
value|0xFC02
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNCHANNEL
value|0xFC03
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNSSID
value|0xFC04
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNATIMWINDOW
value|0xFC05
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFSYSTEMSCALE
value|0xFC06
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMAXDATALEN
value|0xFC07
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS
value|0xFC08
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPMENABLED
value|0xFC09
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPMEPS
value|0xFC0A
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMULTICASTRECEIVE
value|0xFC0B
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMAXSLEEPDURATION
value|0xFC0C
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPMHOLDOVERDURATION
value|0xFC0D
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNNAME
value|0xFC0E
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFOWNDTIMPERIOD
value|0xFC10
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS1
value|0xFC11
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS2
value|0xFC12
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS3
value|0xFC13
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS4
value|0xFC14
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS5
value|0xFC15
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWDSADDRESS6
value|0xFC16
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMULTICASTPMBUFFERING
value|0xFC17
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_UNKNOWN1
value|0xFC20
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_UNKNOWN2
value|0xFC21
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWEPDEFAULTKEYID
value|0xFC23
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDEFAULTKEY0
value|0xFC24
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDEFAULTKEY1
value|0xFC25
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDEFAULTKEY2
value|0xFC26
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDEFAULTKEY3
value|0xFC27
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWEPFLAGS
value|0xFC28
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFWEPKEYMAPPINGTABLE
value|0xFC29
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFAUTHENTICATION
value|0xFC2A
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMAXASSOCSTA
value|0xFC2B
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFTXCONTROL
value|0xFC2C
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFROAMINGMODE
value|0xFC2D
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFHOSTAUTHENTICATION
value|0xFC2E
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFRCVCRCERROR
value|0xFC30
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFMMLIFE
value|0xFC31
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFALTRETRYCOUNT
value|0xFC32
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFBEACONINT
value|0xFC33
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFAPPCFINFO
value|0xFC34
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFSTAPCFINFO
value|0xFC35
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPRIORITYQUSAGE
value|0xFC37
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFTIMCTRL
value|0xFC40
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_UNKNOWN3
value|0xFC41
end_define

begin_comment
comment|/* added in STA f/w 0.7.x */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFTHIRTY2TALLY
value|0xFC42
end_define

begin_comment
comment|/* added in STA f/w 0.8.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFENHSECURITY
value|0xFC43
end_define

begin_comment
comment|/* AP f/w or STA f/w>= 1.6.3 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFDBMADJUST
value|0xFC46
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_GENERICELEMENT
value|0xFC48
end_define

begin_comment
comment|/* added in STA f/w 1.7.0; 					   * write only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_PROPAGATIONDELAY
value|0xFC49
end_define

begin_comment
comment|/* added in STA f/w 1.7.6 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_GROUPADDRESSES
value|0xFC80
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CREATEIBSS
value|0xFC81
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD
value|0xFC82
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD
value|0xFC83
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL
value|0xFC84
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PROMISCUOUSMODE
value|0xFC85
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD0
value|0xFC90
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD1
value|0xFC91
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD2
value|0xFC92
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD3
value|0xFC93
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD4
value|0xFC94
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD5
value|0xFC95
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_FRAGMENTATIONTHRESHOLD6
value|0xFC96
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD0
value|0xFC97
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD1
value|0xFC98
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD2
value|0xFC99
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD3
value|0xFC9A
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD4
value|0xFC9B
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD5
value|0xFC9C
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_RTSTHRESHOLD6
value|0xFC9D
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL0
value|0xFC9E
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL1
value|0xFC9F
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL2
value|0xFCA0
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL3
value|0xFCA1
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL4
value|0xFCA2
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL5
value|0xFCA3
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXRATECONTROL6
value|0xFCA4
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFSHORTPREAMBLE
value|0xFCB0
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFEXCLUDELONGPREAMBLE
value|0xFCB1
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFAUTHENTICATIONRSPTO
value|0xFCB2
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFBASICRATES
value|0xFCB3
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFSUPPORTEDRATES
value|0xFCB4
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CNFFALLBACKCTRL
value|0xFCB5
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_WEPKEYDISABLE
value|0xFCB6
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_WEPKEYMAPINDEX
value|0xFCB7
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_BROADCASTKEYID
value|0xFCB8
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_ENTSECFLAGEYID
value|0xFCB9
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFPASSIVESCANCTRL
value|0xFCBA
end_define

begin_comment
comment|/* added in STA f/w 1.5.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_SSNHANDLINGMODE
value|0xFCBB
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_MDCCONTROL
value|0xFCBC
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_MDCCOUNTRY
value|0xFCBD
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TXPOWERMAX
value|0xFCBE
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFLFOENABLED
value|0xFCBF
end_define

begin_comment
comment|/* added in STA f/w 1.6.3 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CAPINFO
value|0xFCC0
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_LISTENINTERVAL
value|0xFCC1
end_define

begin_comment
comment|/* added in STA f/w 1.7.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_SW_ANT_DIV
value|0xFCC2
end_define

begin_comment
comment|/* added in STA f/w 1.7.0; Prism3 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_LED_CTRL
value|0xFCC4
end_define

begin_comment
comment|/* added in STA f/w 1.7.6 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_HFODELAY
value|0xFCC5
end_define

begin_comment
comment|/* added in STA f/w 1.7.6 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_DISALLOWEDBSSID
value|0xFCC6
end_define

begin_comment
comment|/* added in STA f/w 1.8.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_TICKTIME
value|0xFCE0
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_SCANREQUEST
value|0xFCE1
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_JOINREQUEST
value|0xFCE2
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_AUTHENTICATESTATION
value|0xFCE3
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CHANNELINFOREQUEST
value|0xFCE4
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_HOSTSCAN
value|0xFCE5
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_comment
comment|/* HFA384X Information RIDs */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_MAXLOADTIME
value|0xFD00
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_DOWNLOADBUFFER
value|0xFD01
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PRIID
value|0xFD02
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PRISUPRANGE
value|0xFD03
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CFIACTRANGES
value|0xFD04
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_NICSERNUM
value|0xFD0A
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_NICID
value|0xFD0B
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_MFISUPRANGE
value|0xFD0C
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CFISUPRANGE
value|0xFD0D
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CHANNELLIST
value|0xFD10
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_REGULATORYDOMAINS
value|0xFD11
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_TEMPTYPE
value|0xFD12
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CIS
value|0xFD13
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_STAID
value|0xFD20
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_STASUPRANGE
value|0xFD21
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_MFIACTRANGES
value|0xFD22
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CFIACTRANGES2
value|0xFD23
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PRODUCTNAME
value|0xFD24
end_define

begin_comment
comment|/* added in STA f/w 1.3.1; 					* only Prism2.5(?) */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_PORTSTATUS
value|0xFD40
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTSSID
value|0xFD41
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTBSSID
value|0xFD42
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_COMMSQUALITY
value|0xFD43
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE
value|0xFD44
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTBEACONINTERVAL
value|0xFD45
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTSCALETHRESHOLDS
value|0xFD46
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PROTOCOLRSPTIME
value|0xFD47
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_SHORTRETRYLIMIT
value|0xFD48
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_LONGRETRYLIMIT
value|0xFD49
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_MAXTRANSMITLIFETIME
value|0xFD4A
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_MAXRECEIVELIFETIME
value|0xFD4B
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CFPOLLABLE
value|0xFD4C
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_AUTHENTICATIONALGORITHMS
value|0xFD4D
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_PRIVACYOPTIONIMPLEMENTED
value|0xFD4F
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_DBMCOMMSQUALITY
value|0xFD51
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE1
value|0xFD80
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE2
value|0xFD81
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE3
value|0xFD82
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE4
value|0xFD83
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE5
value|0xFD84
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTTXRATE6
value|0xFD85
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_OWNMACADDR
value|0xFD86
end_define

begin_comment
comment|/* AP f/w only */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_SCANRESULTSTABLE
value|0xFD88
end_define

begin_comment
comment|/* added in STA f/w 0.8.3 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_HOSTSCANRESULTS
value|0xFD89
end_define

begin_comment
comment|/* added in STA f/w 1.3.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_AUTHENTICATIONUSED
value|0xFD8A
end_define

begin_comment
comment|/* added in STA f/w 1.3.4 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_CNFFAASWITCHCTRL
value|0xFD8B
end_define

begin_comment
comment|/* added in STA f/w 1.6.3 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_ASSOCIATIONFAILURE
value|0xFD8D
end_define

begin_comment
comment|/* added in STA f/w 1.8.0 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_PHYTYPE
value|0xFDC0
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTCHANNEL
value|0xFDC1
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CURRENTPOWERSTATE
value|0xFDC2
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_CCAMODE
value|0xFDC3
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_SUPPORTEDDATARATES
value|0xFDC6
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_LFO_VOLT_REG_TEST_RES
value|0xFDC7
end_define

begin_comment
comment|/* added in STA f/w 1.7.1 */
end_comment

begin_define
define|#
directive|define
name|HFA384X_RID_BUILDSEQ
value|0xFFFE
end_define

begin_define
define|#
directive|define
name|HFA384X_RID_FWID
value|0xFFFF
end_define

begin_struct
struct|struct
name|hfa384x_comp_ident
block|{
name|u16
name|id
decl_stmt|;
name|u16
name|variant
decl_stmt|;
name|u16
name|major
decl_stmt|;
name|u16
name|minor
decl_stmt|;
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
name|HFA384X_COMP_ID_PRI
value|0x15
end_define

begin_define
define|#
directive|define
name|HFA384X_COMP_ID_STA
value|0x1f
end_define

begin_define
define|#
directive|define
name|HFA384X_COMP_ID_FW_AP
value|0x14b
end_define

begin_struct
struct|struct
name|hfa384x_sup_range
block|{
name|u16
name|role
decl_stmt|;
name|u16
name|id
decl_stmt|;
name|u16
name|variant
decl_stmt|;
name|u16
name|bottom
decl_stmt|;
name|u16
name|top
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|hfa384x_build_id
block|{
name|u16
name|pri_seq
decl_stmt|;
name|u16
name|sec_seq
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* FD01 - Download Buffer */
end_comment

begin_struct
struct|struct
name|hfa384x_rid_download_buffer
block|{
name|u16
name|page
decl_stmt|;
name|u16
name|offset
decl_stmt|;
name|u16
name|length
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* BSS connection quality (RID FD43 range, RID FD51 dBm-normalized) */
end_comment

begin_struct
struct|struct
name|hfa384x_comms_quality
block|{
name|u16
name|comm_qual
decl_stmt|;
comment|/* 0 .. 92 */
name|u16
name|signal_level
decl_stmt|;
comment|/* 27 .. 154 */
name|u16
name|noise_level
decl_stmt|;
comment|/* 27 .. 154 */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* netdevice private ioctls (used, e.g., with iwpriv from user space) */
end_comment

begin_comment
comment|/* New wireless extensions API - SET/GET convention (even ioctl numbers are  * root only)  */
end_comment

begin_define
define|#
directive|define
name|PRISM2_IOCTL_PRISM2_PARAM
value|(SIOCIWFIRSTPRIV + 0)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_GET_PRISM2_PARAM
value|(SIOCIWFIRSTPRIV + 1)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WRITEMIF
value|(SIOCIWFIRSTPRIV + 2)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_READMIF
value|(SIOCIWFIRSTPRIV + 3)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_MONITOR
value|(SIOCIWFIRSTPRIV + 4)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_RESET
value|(SIOCIWFIRSTPRIV + 6)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_INQUIRE
value|(SIOCIWFIRSTPRIV + 8)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WDS_ADD
value|(SIOCIWFIRSTPRIV + 10)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_WDS_DEL
value|(SIOCIWFIRSTPRIV + 12)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_SET_RID_WORD
value|(SIOCIWFIRSTPRIV + 14)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_MACCMD
value|(SIOCIWFIRSTPRIV + 16)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_ADDMAC
value|(SIOCIWFIRSTPRIV + 18)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_DELMAC
value|(SIOCIWFIRSTPRIV + 20)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_KICKMAC
value|(SIOCIWFIRSTPRIV + 22)
end_define

begin_comment
comment|/* following are not in SIOCGIWPRIV list; check permission in the driver code  */
end_comment

begin_define
define|#
directive|define
name|PRISM2_IOCTL_DOWNLOAD
value|(SIOCDEVPRIVATE + 13)
end_define

begin_define
define|#
directive|define
name|PRISM2_IOCTL_HOSTAPD
value|(SIOCDEVPRIVATE + 14)
end_define

begin_comment
comment|/* PRISM2_IOCTL_PRISM2_PARAM ioctl() subtypes: */
end_comment

begin_enum
enum|enum
block|{
comment|/* PRISM2_PARAM_PTYPE = 1, */
comment|/* REMOVED 2003-10-22 */
name|PRISM2_PARAM_TXRATECTRL
init|=
literal|2
block|,
name|PRISM2_PARAM_BEACON_INT
init|=
literal|3
block|,
name|PRISM2_PARAM_PSEUDO_IBSS
init|=
literal|4
block|,
name|PRISM2_PARAM_ALC
init|=
literal|5
block|,
comment|/* PRISM2_PARAM_TXPOWER = 6, */
comment|/* REMOVED 2003-10-22 */
name|PRISM2_PARAM_DUMP
init|=
literal|7
block|,
name|PRISM2_PARAM_OTHER_AP_POLICY
init|=
literal|8
block|,
name|PRISM2_PARAM_AP_MAX_INACTIVITY
init|=
literal|9
block|,
name|PRISM2_PARAM_AP_BRIDGE_PACKETS
init|=
literal|10
block|,
name|PRISM2_PARAM_DTIM_PERIOD
init|=
literal|11
block|,
name|PRISM2_PARAM_AP_NULLFUNC_ACK
init|=
literal|12
block|,
name|PRISM2_PARAM_MAX_WDS
init|=
literal|13
block|,
name|PRISM2_PARAM_AP_AUTOM_AP_WDS
init|=
literal|14
block|,
name|PRISM2_PARAM_AP_AUTH_ALGS
init|=
literal|15
block|,
name|PRISM2_PARAM_MONITOR_ALLOW_FCSERR
init|=
literal|16
block|,
name|PRISM2_PARAM_HOST_ENCRYPT
init|=
literal|17
block|,
name|PRISM2_PARAM_HOST_DECRYPT
init|=
literal|18
block|,
name|PRISM2_PARAM_BUS_MASTER_THRESHOLD_RX
init|=
literal|19
block|,
name|PRISM2_PARAM_BUS_MASTER_THRESHOLD_TX
init|=
literal|20
block|,
name|PRISM2_PARAM_HOST_ROAMING
init|=
literal|21
block|,
name|PRISM2_PARAM_BCRX_STA_KEY
init|=
literal|22
block|,
name|PRISM2_PARAM_IEEE_802_1X
init|=
literal|23
block|,
name|PRISM2_PARAM_ANTSEL_TX
init|=
literal|24
block|,
name|PRISM2_PARAM_ANTSEL_RX
init|=
literal|25
block|,
name|PRISM2_PARAM_MONITOR_TYPE
init|=
literal|26
block|,
name|PRISM2_PARAM_WDS_TYPE
init|=
literal|27
block|,
name|PRISM2_PARAM_HOSTSCAN
init|=
literal|28
block|,
name|PRISM2_PARAM_AP_SCAN
init|=
literal|29
block|,
name|PRISM2_PARAM_ENH_SEC
init|=
literal|30
block|,
name|PRISM2_PARAM_IO_DEBUG
init|=
literal|31
block|,
name|PRISM2_PARAM_BASIC_RATES
init|=
literal|32
block|,
name|PRISM2_PARAM_OPER_RATES
init|=
literal|33
block|,
name|PRISM2_PARAM_HOSTAPD
init|=
literal|34
block|,
name|PRISM2_PARAM_HOSTAPD_STA
init|=
literal|35
block|,
name|PRISM2_PARAM_WPA
init|=
literal|36
block|,
name|PRISM2_PARAM_PRIVACY_INVOKED
init|=
literal|37
block|,
name|PRISM2_PARAM_TKIP_COUNTERMEASURES
init|=
literal|38
block|,
name|PRISM2_PARAM_DROP_UNENCRYPTED
init|=
literal|39
block|,
name|PRISM2_PARAM_SCAN_CHANNEL_MASK
init|=
literal|40
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|HOSTAP_ANTSEL_DO_NOT_TOUCH
init|=
literal|0
block|,
name|HOSTAP_ANTSEL_DIVERSITY
init|=
literal|1
block|,
name|HOSTAP_ANTSEL_LOW
init|=
literal|2
block|,
name|HOSTAP_ANTSEL_HIGH
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* PRISM2_IOCTL_MACCMD ioctl() subcommands: */
end_comment

begin_enum
enum|enum
block|{
name|AP_MAC_CMD_POLICY_OPEN
init|=
literal|0
block|,
name|AP_MAC_CMD_POLICY_ALLOW
init|=
literal|1
block|,
name|AP_MAC_CMD_POLICY_DENY
init|=
literal|2
block|,
name|AP_MAC_CMD_FLUSH
init|=
literal|3
block|,
name|AP_MAC_CMD_KICKALL
init|=
literal|4
block|}
enum|;
end_enum

begin_comment
comment|/* PRISM2_IOCTL_DOWNLOAD ioctl() dl_cmd: */
end_comment

begin_enum
enum|enum
block|{
name|PRISM2_DOWNLOAD_VOLATILE
init|=
literal|1
comment|/* RAM */
block|,
comment|/* Note! Old versions of prism2_srec have a fatal error in CRC-16 	 * calculation, which will corrupt all non-volatile downloads. 	 * PRISM2_DOWNLOAD_NON_VOLATILE used to be 2, but it is now 3 to 	 * prevent use of old versions of prism2_srec for non-volatile 	 * download. */
name|PRISM2_DOWNLOAD_NON_VOLATILE
init|=
literal|3
comment|/* FLASH */
block|,
name|PRISM2_DOWNLOAD_VOLATILE_GENESIS
init|=
literal|4
comment|/* RAM in Genesis mode */
block|,
comment|/* Persistent versions of volatile download commands (keep firmware 	 * data in memory and automatically re-download after hw_reset */
name|PRISM2_DOWNLOAD_VOLATILE_PERSISTENT
init|=
literal|5
block|,
name|PRISM2_DOWNLOAD_VOLATILE_GENESIS_PERSISTENT
init|=
literal|6
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|prism2_download_param
block|{
name|u32
name|dl_cmd
decl_stmt|;
name|u32
name|start_addr
decl_stmt|;
name|u32
name|num_areas
decl_stmt|;
struct|struct
name|prism2_download_area
block|{
name|u32
name|addr
decl_stmt|;
comment|/* wlan card address */
name|u32
name|len
decl_stmt|;
name|caddr_t
name|ptr
decl_stmt|;
comment|/* pointer to data in user space */
block|}
name|data
index|[
literal|0
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRISM2_MAX_DOWNLOAD_AREA_LEN
value|131072
end_define

begin_define
define|#
directive|define
name|PRISM2_MAX_DOWNLOAD_LEN
value|262144
end_define

begin_comment
comment|/* PRISM2_IOCTL_HOSTAPD ioctl() cmd: */
end_comment

begin_enum
enum|enum
block|{
name|PRISM2_HOSTAPD_FLUSH
init|=
literal|1
block|,
name|PRISM2_HOSTAPD_ADD_STA
init|=
literal|2
block|,
name|PRISM2_HOSTAPD_REMOVE_STA
init|=
literal|3
block|,
name|PRISM2_HOSTAPD_GET_INFO_STA
init|=
literal|4
block|,
comment|/* REMOVED: PRISM2_HOSTAPD_RESET_TXEXC_STA = 5, */
name|PRISM2_SET_ENCRYPTION
init|=
literal|6
block|,
name|PRISM2_GET_ENCRYPTION
init|=
literal|7
block|,
name|PRISM2_HOSTAPD_SET_FLAGS_STA
init|=
literal|8
block|,
name|PRISM2_HOSTAPD_GET_RID
init|=
literal|9
block|,
name|PRISM2_HOSTAPD_SET_RID
init|=
literal|10
block|,
name|PRISM2_HOSTAPD_SET_ASSOC_AP_ADDR
init|=
literal|11
block|,
name|PRISM2_HOSTAPD_SET_GENERIC_ELEMENT
init|=
literal|12
block|,
name|PRISM2_HOSTAPD_MLME
init|=
literal|13
block|,
name|PRISM2_HOSTAPD_SCAN_REQ
init|=
literal|14
block|,
name|PRISM2_HOSTAPD_STA_CLEAR_STATS
init|=
literal|15
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_MAX_BUF_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_RID_HDR_LEN
define|\
value|((int) (&((struct prism2_hostapd_param *) 0)->u.rid.data))
end_define

begin_define
define|#
directive|define
name|PRISM2_HOSTAPD_GENERIC_ELEMENT_HDR_LEN
define|\
value|((int) (&((struct prism2_hostapd_param *) 0)->u.generic_elem.data))
end_define

begin_comment
comment|/* Maximum length for algorithm names (-1 for nul termination) used in ioctl()  */
end_comment

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ALG_NAME_LEN
value|16
end_define

begin_struct
struct|struct
name|prism2_hostapd_param
block|{
name|u32
name|cmd
decl_stmt|;
name|u8
name|sta_addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u16
name|aid
decl_stmt|;
name|u16
name|capability
decl_stmt|;
name|u8
name|tx_supp_rates
decl_stmt|;
block|}
name|add_sta
struct|;
struct|struct
block|{
name|u32
name|inactive_sec
decl_stmt|;
block|}
name|get_info_sta
struct|;
struct|struct
block|{
name|u8
name|alg
index|[
name|HOSTAP_CRYPT_ALG_NAME_LEN
index|]
decl_stmt|;
name|u32
name|flags
decl_stmt|;
name|u32
name|err
decl_stmt|;
name|u8
name|idx
decl_stmt|;
name|u8
name|seq
index|[
literal|8
index|]
decl_stmt|;
comment|/* sequence counter (set: RX, get: TX) */
name|u16
name|key_len
decl_stmt|;
name|u8
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
name|crypt
struct|;
struct|struct
block|{
name|u32
name|flags_and
decl_stmt|;
name|u32
name|flags_or
decl_stmt|;
block|}
name|set_flags_sta
struct|;
struct|struct
block|{
name|u16
name|rid
decl_stmt|;
name|u16
name|len
decl_stmt|;
name|u8
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|rid
struct|;
struct|struct
block|{
name|u8
name|len
decl_stmt|;
name|u8
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|generic_elem
struct|;
struct|struct
block|{
define|#
directive|define
name|MLME_STA_DEAUTH
value|0
define|#
directive|define
name|MLME_STA_DISASSOC
value|1
name|u16
name|cmd
decl_stmt|;
name|u16
name|reason_code
decl_stmt|;
block|}
name|mlme
struct|;
struct|struct
block|{
name|u8
name|ssid_len
decl_stmt|;
name|u8
name|ssid
index|[
literal|32
index|]
decl_stmt|;
block|}
name|scan_req
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_FLAG_SET_TX_KEY
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_FLAG_PERMANENT
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_UNKNOWN_ALG
value|2
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_UNKNOWN_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_CRYPT_INIT_FAILED
value|4
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_KEY_SET_FAILED
value|5
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_TX_KEY_SET_FAILED
value|6
end_define

begin_define
define|#
directive|define
name|HOSTAP_CRYPT_ERR_CARD_CONF_FAILED
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOSTAP_COMMON_H */
end_comment

end_unit

