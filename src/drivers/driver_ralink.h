begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - driver_ralink exported functions  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  * Copyright (c) 2007, Snowpin Lee<snowpin_lee@ralinktech.com.tw>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_comment
comment|// Ralink defined OIDs
end_comment

begin_if
if|#
directive|if
name|WIRELESS_EXT
operator|<=
literal|11
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCDEVPRIVATE
end_ifndef

begin_define
define|#
directive|define
name|SIOCDEVPRIVATE
value|0x8BE0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCIWFIRSTPRIV
value|SIOCDEVPRIVATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RT_PRIV_IOCTL
value|(SIOCIWFIRSTPRIV + 0x0E)
end_define

begin_define
define|#
directive|define
name|RTPRIV_IOCTL_SET
value|(SIOCIWFIRSTPRIV + 0x02)
end_define

begin_comment
comment|// IEEE 802.11 OIDs&  Ralink defined OIDs  ******
end_comment

begin_comment
comment|// (RaConfig Set/QueryInform) ==>
end_comment

begin_define
define|#
directive|define
name|OID_GET_SET_TOGGLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|OID_802_11_ADD_WEP
value|0x0112
end_define

begin_define
define|#
directive|define
name|OID_802_11_REMOVE_WEP
value|0x0113
end_define

begin_define
define|#
directive|define
name|OID_802_11_DISASSOCIATE
value|0x0114
end_define

begin_define
define|#
directive|define
name|OID_802_11_PRIVACY_FILTER
value|0x0118
end_define

begin_define
define|#
directive|define
name|OID_802_11_ASSOCIATION_INFORMATION
value|0x011E
end_define

begin_define
define|#
directive|define
name|OID_802_11_BSSID_LIST_SCAN
value|0x0508
end_define

begin_define
define|#
directive|define
name|OID_802_11_SSID
value|0x0509
end_define

begin_define
define|#
directive|define
name|OID_802_11_BSSID
value|0x050A
end_define

begin_define
define|#
directive|define
name|OID_802_11_WEP_STATUS
value|0x0510
end_define

begin_define
define|#
directive|define
name|OID_802_11_AUTHENTICATION_MODE
value|0x0511
end_define

begin_define
define|#
directive|define
name|OID_802_11_INFRASTRUCTURE_MODE
value|0x0512
end_define

begin_define
define|#
directive|define
name|OID_802_11_TX_POWER_LEVEL
value|0x0517
end_define

begin_define
define|#
directive|define
name|OID_802_11_REMOVE_KEY
value|0x0519
end_define

begin_define
define|#
directive|define
name|OID_802_11_ADD_KEY
value|0x0520
end_define

begin_define
define|#
directive|define
name|OID_802_11_DEAUTHENTICATION
value|0x0526
end_define

begin_define
define|#
directive|define
name|OID_802_11_DROP_UNENCRYPTED
value|0x0527
end_define

begin_define
define|#
directive|define
name|OID_802_11_BSSID_LIST
value|0x0609
end_define

begin_define
define|#
directive|define
name|OID_802_3_CURRENT_ADDRESS
value|0x060A
end_define

begin_define
define|#
directive|define
name|OID_SET_COUNTERMEASURES
value|0x0616
end_define

begin_define
define|#
directive|define
name|OID_802_11_SET_IEEE8021X
value|0x0617
end_define

begin_comment
comment|// For IEEE8021x mode
end_comment

begin_define
define|#
directive|define
name|OID_802_11_SET_IEEE8021X_REQUIRE_KEY
value|0x0618
end_define

begin_comment
comment|// For DynamicWEP in IEEE802.1x mode
end_comment

begin_define
define|#
directive|define
name|OID_802_11_PMKID
value|0x0620
end_define

begin_define
define|#
directive|define
name|RT_OID_WPA_SUPPLICANT_SUPPORT
value|0x0621
end_define

begin_comment
comment|// for trigger driver enable/disable wpa_supplicant support
end_comment

begin_define
define|#
directive|define
name|RT_OID_WE_VERSION_COMPILED
value|0x0622
end_define

begin_define
define|#
directive|define
name|RT_OID_NEW_DRIVER
value|0x0623
end_define

begin_define
define|#
directive|define
name|PACKED
value|__attribute__ ((packed))
end_define

begin_comment
comment|//wpa_supplicant event flags
end_comment

begin_define
define|#
directive|define
name|RT_ASSOC_EVENT_FLAG
value|0x0101
end_define

begin_define
define|#
directive|define
name|RT_DISASSOC_EVENT_FLAG
value|0x0102
end_define

begin_define
define|#
directive|define
name|RT_REQIE_EVENT_FLAG
value|0x0103
end_define

begin_define
define|#
directive|define
name|RT_RESPIE_EVENT_FLAG
value|0x0104
end_define

begin_define
define|#
directive|define
name|RT_ASSOCINFO_EVENT_FLAG
value|0x0105
end_define

begin_define
define|#
directive|define
name|RT_PMKIDCAND_FLAG
value|0x0106
end_define

begin_define
define|#
directive|define
name|RT_INTERFACE_DOWN
value|0x0107
end_define

begin_define
define|#
directive|define
name|RT_REPORT_AP_INFO
value|0x0108
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IEEE 802.11 Structures and definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// new types for Media Specific Indications
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG
end_ifndef

begin_define
define|#
directive|define
name|CHAR
value|char
end_define

begin_define
define|#
directive|define
name|INT
value|int
end_define

begin_define
define|#
directive|define
name|SHORT
value|int
end_define

begin_define
define|#
directive|define
name|UINT
value|u32
end_define

begin_undef
undef|#
directive|undef
name|ULONG
end_undef

begin_comment
comment|//#define ULONG           u32
end_comment

begin_define
define|#
directive|define
name|ULONG
value|unsigned long
end_define

begin_comment
comment|/* 32-bit in 32-bit CPU or 64-bit in 64-bit CPU */
end_comment

begin_define
define|#
directive|define
name|USHORT
value|unsigned short
end_define

begin_define
define|#
directive|define
name|UCHAR
value|unsigned char
end_define

begin_define
define|#
directive|define
name|uint32
value|u32
end_define

begin_define
define|#
directive|define
name|uint8
value|u8
end_define

begin_define
define|#
directive|define
name|BOOLEAN
value|u8
end_define

begin_comment
comment|//#define LARGE_INTEGER s64
end_comment

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_define
define|#
directive|define
name|LONG
value|long
end_define

begin_define
define|#
directive|define
name|LONGLONG
value|s64
end_define

begin_define
define|#
directive|define
name|ULONGLONG
value|u64
end_define

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|PVOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHAR
modifier|*
name|PCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UCHAR
modifier|*
name|PUCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|USHORT
modifier|*
name|PUSHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|LONG
modifier|*
name|PLONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONG
modifier|*
name|PULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_LARGE_INTEGER
block|{
struct|struct
block|{
name|ULONG
name|LowPart
decl_stmt|;
name|LONG
name|HighPart
decl_stmt|;
block|}
name|vv
struct|;
struct|struct
block|{
name|ULONG
name|LowPart
decl_stmt|;
name|LONG
name|HighPart
decl_stmt|;
block|}
name|u
struct|;
name|s64
name|QuadPart
decl_stmt|;
block|}
name|LARGE_INTEGER
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NDIS_802_11_LENGTH_SSID
value|32
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_LENGTH_RATES
value|8
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_LENGTH_RATES_EX
value|16
end_define

begin_define
define|#
directive|define
name|MAX_LEN_OF_SSID
value|32
end_define

begin_define
define|#
directive|define
name|MAC_ADDR_LEN
value|6
end_define

begin_typedef
typedef|typedef
name|UCHAR
name|NDIS_802_11_MAC_ADDRESS
index|[
literal|6
index|]
typedef|;
end_typedef

begin_comment
comment|// mask for authentication/integrity fields
end_comment

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS
value|0x0f
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_REAUTH
value|0x01
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_KEYUPDATE
value|0x02
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR
value|0x06
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_GROUP_ERROR
value|0x0E
end_define

begin_comment
comment|// Added new types for OFDM 5G and 2.4G
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NDIS_802_11_NETWORK_TYPE
block|{
name|Ndis802_11FH
block|,
name|Ndis802_11DS
block|,
name|Ndis802_11OFDM5
block|,
name|Ndis802_11OFDM24
block|,
name|Ndis802_11Automode
block|,
name|Ndis802_11NetworkTypeMax
comment|// not a real type, defined as an upper bound
block|}
name|NDIS_802_11_NETWORK_TYPE
operator|,
typedef|*
name|PNDIS_802_11_NETWORK_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Received Signal Strength Indication
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|LONG
name|NDIS_802_11_RSSI
typedef|;
end_typedef

begin_comment
comment|// in dBm
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_CONFIGURATION_FH
block|{
name|ULONG
name|Length
decl_stmt|;
comment|// Length of structure
name|ULONG
name|HopPattern
decl_stmt|;
comment|// As defined by 802.11, MSB set
name|ULONG
name|HopSet
decl_stmt|;
comment|// to one if non-802.11
name|ULONG
name|DwellTime
decl_stmt|;
comment|// units are Kusec
block|}
name|NDIS_802_11_CONFIGURATION_FH
operator|,
typedef|*
name|PNDIS_802_11_CONFIGURATION_FH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_CONFIGURATION
block|{
name|ULONG
name|Length
decl_stmt|;
comment|// Length of structure
name|ULONG
name|BeaconPeriod
decl_stmt|;
comment|// units are Kusec
name|ULONG
name|ATIMWindow
decl_stmt|;
comment|// units are Kusec
name|ULONG
name|DSConfig
decl_stmt|;
comment|// Frequency, units are kHz
name|NDIS_802_11_CONFIGURATION_FH
name|FHConfig
decl_stmt|;
block|}
name|NDIS_802_11_CONFIGURATION
operator|,
typedef|*
name|PNDIS_802_11_CONFIGURATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONG
name|NDIS_802_11_KEY_INDEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONGLONG
name|NDIS_802_11_KEY_RSC
typedef|;
end_typedef

begin_comment
comment|// Key mapping keys require a BSSID
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_KEY
block|{
name|UINT
name|Length
decl_stmt|;
comment|// Length of this structure
name|UINT
name|KeyIndex
decl_stmt|;
name|UINT
name|KeyLength
decl_stmt|;
comment|// length of key in bytes
name|NDIS_802_11_MAC_ADDRESS
name|BSSID
decl_stmt|;
name|NDIS_802_11_KEY_RSC
name|KeyRSC
decl_stmt|;
name|UCHAR
name|KeyMaterial
index|[
literal|1
index|]
decl_stmt|;
comment|// variable length depending on above field
block|}
name|NDIS_802_11_KEY
operator|,
typedef|*
name|PNDIS_802_11_KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_REMOVE_KEY
block|{
name|UINT
name|Length
decl_stmt|;
comment|// Length of this structure
name|UINT
name|KeyIndex
decl_stmt|;
name|NDIS_802_11_MAC_ADDRESS
name|BSSID
decl_stmt|;
block|}
name|NDIS_802_11_REMOVE_KEY
operator|,
typedef|*
name|PNDIS_802_11_REMOVE_KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_802_11_WEP
block|{
name|UINT
name|Length
decl_stmt|;
comment|// Length of this structure
name|UINT
name|KeyIndex
decl_stmt|;
comment|// 0 is the per-client key, 1-N are the
comment|// global keys
name|UINT
name|KeyLength
decl_stmt|;
comment|// length of key in bytes
name|UCHAR
name|KeyMaterial
index|[
literal|1
index|]
decl_stmt|;
comment|// variable length depending on above field
block|}
name|NDIS_802_11_WEP
operator|,
typedef|*
name|PNDIS_802_11_WEP
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NDIS_802_11_NETWORK_INFRASTRUCTURE
block|{
name|Ndis802_11IBSS
block|,
name|Ndis802_11Infrastructure
block|,
name|Ndis802_11AutoUnknown
block|,
name|Ndis802_11InfrastructureMax
comment|// Not a real value, defined as upper bound
block|}
name|NDIS_802_11_NETWORK_INFRASTRUCTURE
operator|,
typedef|*
name|PNDIS_802_11_NETWORK_INFRASTRUCTURE
typedef|;
end_typedef

begin_comment
comment|// PMKID Structures
end_comment

begin_typedef
typedef|typedef
name|UCHAR
name|NDIS_802_11_PMKID_VALUE
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_BSSID_INFO
block|{
name|NDIS_802_11_MAC_ADDRESS
name|BSSID
decl_stmt|;
name|NDIS_802_11_PMKID_VALUE
name|PMKID
decl_stmt|;
block|}
name|BSSID_INFO
operator|,
typedef|*
name|PBSSID_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_PMKID
block|{
name|ULONG
name|Length
decl_stmt|;
name|ULONG
name|BSSIDInfoCount
decl_stmt|;
name|BSSID_INFO
name|BSSIDInfo
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NDIS_802_11_PMKID
operator|,
typedef|*
name|PNDIS_802_11_PMKID
typedef|;
end_typedef

begin_comment
comment|//Added new types for PMKID Candidate lists.
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PMKID_CANDIDATE
block|{
name|NDIS_802_11_MAC_ADDRESS
name|BSSID
decl_stmt|;
name|ULONG
name|Flags
decl_stmt|;
block|}
name|PMKID_CANDIDATE
operator|,
typedef|*
name|PPMKID_CANDIDATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_PMKID_CANDIDATE_LIST
block|{
name|ULONG
name|Version
decl_stmt|;
comment|// Version of the structure
name|ULONG
name|NumCandidates
decl_stmt|;
comment|// No. of pmkid candidates
name|PMKID_CANDIDATE
name|CandidateList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NDIS_802_11_PMKID_CANDIDATE_LIST
operator|,
typedef|*
name|PNDIS_802_11_PMKID_CANDIDATE_LIST
typedef|;
end_typedef

begin_comment
comment|//Flags for PMKID Candidate list structure
end_comment

begin_define
define|#
directive|define
name|NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED
value|0x01
end_define

begin_comment
comment|// Add new authentication modes
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NDIS_802_11_AUTHENTICATION_MODE
block|{
name|Ndis802_11AuthModeOpen
block|,
name|Ndis802_11AuthModeShared
block|,
name|Ndis802_11AuthModeAutoSwitch
block|,
name|Ndis802_11AuthModeWPA
block|,
name|Ndis802_11AuthModeWPAPSK
block|,
name|Ndis802_11AuthModeWPANone
block|,
name|Ndis802_11AuthModeWPA2
block|,
name|Ndis802_11AuthModeWPA2PSK
block|,
name|Ndis802_11AuthModeMax
comment|// Not a real mode, defined as upper bound
block|}
name|NDIS_802_11_AUTHENTICATION_MODE
operator|,
typedef|*
name|PNDIS_802_11_AUTHENTICATION_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UCHAR
name|NDIS_802_11_RATES
index|[
name|NDIS_802_11_LENGTH_RATES
index|]
typedef|;
end_typedef

begin_comment
comment|// Set of 8 data rates
end_comment

begin_typedef
typedef|typedef
name|UCHAR
name|NDIS_802_11_RATES_EX
index|[
name|NDIS_802_11_LENGTH_RATES_EX
index|]
typedef|;
end_typedef

begin_comment
comment|// Set of 16 data rates
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_802_11_SSID
block|{
name|INT
name|SsidLength
decl_stmt|;
comment|// length of SSID field below, in bytes;
comment|// this can be zero.
name|UCHAR
name|Ssid
index|[
name|NDIS_802_11_LENGTH_SSID
index|]
decl_stmt|;
comment|// SSID information field
block|}
name|NDIS_802_11_SSID
operator|,
typedef|*
name|PNDIS_802_11_SSID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_WLAN_BSSID
block|{
name|ULONG
name|Length
decl_stmt|;
comment|// Length of this structure
name|NDIS_802_11_MAC_ADDRESS
name|MacAddress
decl_stmt|;
comment|// BSSID
name|UCHAR
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|NDIS_802_11_SSID
name|Ssid
decl_stmt|;
comment|// SSID
name|ULONG
name|Privacy
decl_stmt|;
comment|// WEP encryption requirement
name|NDIS_802_11_RSSI
name|Rssi
decl_stmt|;
comment|// receive signal
comment|// strength in dBm
name|NDIS_802_11_NETWORK_TYPE
name|NetworkTypeInUse
decl_stmt|;
name|NDIS_802_11_CONFIGURATION
name|Configuration
decl_stmt|;
name|NDIS_802_11_NETWORK_INFRASTRUCTURE
name|InfrastructureMode
decl_stmt|;
name|NDIS_802_11_RATES
name|SupportedRates
decl_stmt|;
block|}
name|NDIS_WLAN_BSSID
operator|,
typedef|*
name|PNDIS_WLAN_BSSID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_802_11_BSSID_LIST
block|{
name|UINT
name|NumberOfItems
decl_stmt|;
comment|// in list below, at least 1
name|NDIS_WLAN_BSSID
name|Bssid
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NDIS_802_11_BSSID_LIST
operator|,
typedef|*
name|PNDIS_802_11_BSSID_LIST
typedef|;
end_typedef

begin_comment
comment|// Added Capabilities, IELength and IEs for each BSSID
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_WLAN_BSSID_EX
block|{
name|ULONG
name|Length
decl_stmt|;
comment|// Length of this structure
name|NDIS_802_11_MAC_ADDRESS
name|MacAddress
decl_stmt|;
comment|// BSSID
name|UCHAR
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|NDIS_802_11_SSID
name|Ssid
decl_stmt|;
comment|// SSID
name|UINT
name|Privacy
decl_stmt|;
comment|// WEP encryption requirement
name|NDIS_802_11_RSSI
name|Rssi
decl_stmt|;
comment|// receive signal
comment|// strength in dBm
name|NDIS_802_11_NETWORK_TYPE
name|NetworkTypeInUse
decl_stmt|;
name|NDIS_802_11_CONFIGURATION
name|Configuration
decl_stmt|;
name|NDIS_802_11_NETWORK_INFRASTRUCTURE
name|InfrastructureMode
decl_stmt|;
name|NDIS_802_11_RATES_EX
name|SupportedRates
decl_stmt|;
name|ULONG
name|IELength
decl_stmt|;
name|UCHAR
name|IEs
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NDIS_WLAN_BSSID_EX
operator|,
typedef|*
name|PNDIS_WLAN_BSSID_EX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_802_11_BSSID_LIST_EX
block|{
name|UINT
name|NumberOfItems
decl_stmt|;
comment|// in list below, at least 1
name|NDIS_WLAN_BSSID_EX
name|Bssid
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NDIS_802_11_BSSID_LIST_EX
operator|,
typedef|*
name|PNDIS_802_11_BSSID_LIST_EX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|PACKED
name|_NDIS_802_11_FIXED_IEs
block|{
name|UCHAR
name|Timestamp
index|[
literal|8
index|]
decl_stmt|;
name|USHORT
name|BeaconInterval
decl_stmt|;
name|USHORT
name|Capabilities
decl_stmt|;
block|}
name|NDIS_802_11_FIXED_IEs
operator|,
typedef|*
name|PNDIS_802_11_FIXED_IEs
typedef|;
end_typedef

begin_comment
comment|// Added new encryption types
end_comment

begin_comment
comment|// Also aliased typedef to new name
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NDIS_802_11_WEP_STATUS
block|{
name|Ndis802_11WEPEnabled
block|,
name|Ndis802_11Encryption1Enabled
init|=
name|Ndis802_11WEPEnabled
block|,
name|Ndis802_11WEPDisabled
block|,
name|Ndis802_11EncryptionDisabled
init|=
name|Ndis802_11WEPDisabled
block|,
name|Ndis802_11WEPKeyAbsent
block|,
name|Ndis802_11Encryption1KeyAbsent
init|=
name|Ndis802_11WEPKeyAbsent
block|,
name|Ndis802_11WEPNotSupported
block|,
name|Ndis802_11EncryptionNotSupported
init|=
name|Ndis802_11WEPNotSupported
block|,
name|Ndis802_11Encryption2Enabled
block|,
name|Ndis802_11Encryption2KeyAbsent
block|,
name|Ndis802_11Encryption3Enabled
block|,
name|Ndis802_11Encryption3KeyAbsent
block|}
name|NDIS_802_11_WEP_STATUS
operator|,
typedef|*
name|PNDIS_802_11_WEP_STATUS
operator|,
name|NDIS_802_11_ENCRYPTION_STATUS
operator|,
typedef|*
name|PNDIS_802_11_ENCRYPTION_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NDIS_802_11_RELOAD_DEFAULTS
block|{
name|Ndis802_11ReloadWEPKeys
block|}
name|NDIS_802_11_RELOAD_DEFAULTS
operator|,
typedef|*
name|PNDIS_802_11_RELOAD_DEFAULTS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_802_11_AI_REQFI_CAPABILITIES
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AI_REQFI_LISTENINTERVAL
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AI_REQFI_CURRENTAPADDRESS
value|4
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AI_RESFI_CAPABILITIES
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AI_RESFI_STATUSCODE
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AI_RESFI_ASSOCIATIONID
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_AI_REQFI
block|{
name|USHORT
name|Capabilities
decl_stmt|;
name|USHORT
name|ListenInterval
decl_stmt|;
name|NDIS_802_11_MAC_ADDRESS
name|CurrentAPAddress
decl_stmt|;
block|}
name|NDIS_802_11_AI_REQFI
operator|,
typedef|*
name|PNDIS_802_11_AI_REQFI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_AI_RESFI
block|{
name|USHORT
name|Capabilities
decl_stmt|;
name|USHORT
name|StatusCode
decl_stmt|;
name|USHORT
name|AssociationId
decl_stmt|;
block|}
name|NDIS_802_11_AI_RESFI
operator|,
typedef|*
name|PNDIS_802_11_AI_RESFI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NDIS_802_11_ASSOCIATION_INFORMATION
block|{
name|ULONG
name|Length
decl_stmt|;
name|USHORT
name|AvailableRequestFixedIEs
decl_stmt|;
name|NDIS_802_11_AI_REQFI
name|RequestFixedIEs
decl_stmt|;
name|ULONG
name|RequestIELength
decl_stmt|;
name|ULONG
name|OffsetRequestIEs
decl_stmt|;
name|USHORT
name|AvailableResponseFixedIEs
decl_stmt|;
name|NDIS_802_11_AI_RESFI
name|ResponseFixedIEs
decl_stmt|;
name|ULONG
name|ResponseIELength
decl_stmt|;
name|ULONG
name|OffsetResponseIEs
decl_stmt|;
block|}
name|NDIS_802_11_ASSOCIATION_INFORMATION
operator|,
typedef|*
name|PNDIS_802_11_ASSOCIATION_INFORMATION
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_pmkid_entry
block|{
name|struct
name|ndis_pmkid_entry
modifier|*
name|next
decl_stmt|;
name|u8
name|bssid
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|pmkid
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_MLME_DEAUTH_REQ_STRUCT
block|{
name|UCHAR
name|Addr
index|[
name|MAC_ADDR_LEN
index|]
decl_stmt|;
name|USHORT
name|Reason
decl_stmt|;
block|}
name|MLME_DEAUTH_REQ_STRUCT
operator|,
typedef|*
name|PMLME_DEAUTH_REQ_STRUCT
typedef|;
end_typedef

end_unit

