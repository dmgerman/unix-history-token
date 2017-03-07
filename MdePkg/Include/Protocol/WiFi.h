begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides management service interfaces of 802.11 MAC layer. It is used by   network applications (and drivers) to establish wireless connection with an access   point (AP).    Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_WIFI_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_WIFI_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/WiFi2.h>
end_include

begin_define
define|#
directive|define
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL_GUID
define|\
value|{ \     0xda55bc9, 0x45f8, 0x4bb4, {0x87, 0x19, 0x52, 0x24, 0xf1, 0x8a, 0x4d, 0x45 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ACC_NET_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IeeePrivate
init|=
literal|0
block|,
name|IeeePrivatewithGuest
init|=
literal|1
block|,
name|IeeeChargeablePublic
init|=
literal|2
block|,
name|IeeeFreePublic
init|=
literal|3
block|,
name|IeeePersonal
init|=
literal|4
block|,
name|IeeeEmergencyServOnly
init|=
literal|5
block|,
name|IeeeTestOrExp
init|=
literal|14
block|,
name|IeeeWildcard
init|=
literal|15
block|}
name|EFI_80211_ACC_NET_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ASSOCIATE_RESULT_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AssociateSuccess
block|,
name|AssociateRefusedReasonUnspecified
block|,
name|AssociateRefusedCapsMismatch
block|,
name|AssociateRefusedExtReason
block|,
name|AssociateRefusedAPOutOfMemory
block|,
name|AssociateRefusedBasicRatesMismatch
block|,
name|AssociateRejectedEmergencyServicesNotSupported
block|,
name|AssociateRefusedTemporarily
block|}
name|EFI_80211_ASSOCIATE_RESULT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SCAN_RESULT_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The scan operation finished successfully.
comment|///
name|ScanSuccess
block|,
comment|///
comment|/// The scan operation is not supported in current implementation.
comment|///
name|ScanNotSupported
block|}
name|EFI_80211_SCAN_RESULT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_REASON_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Ieee80211UnspecifiedReason
init|=
literal|1
block|,
name|Ieee80211PreviousAuthenticateInvalid
init|=
literal|2
block|,
name|Ieee80211DeauthenticatedSinceLeaving
init|=
literal|3
block|,
name|Ieee80211DisassociatedDueToInactive
init|=
literal|4
block|,
name|Ieee80211DisassociatedSinceApUnable
init|=
literal|5
block|,
name|Ieee80211Class2FrameNonauthenticated
init|=
literal|6
block|,
name|Ieee80211Class3FrameNonassociated
init|=
literal|7
block|,
name|Ieee80211DisassociatedSinceLeaving
init|=
literal|8
block|,
comment|// ...
block|}
name|EFI_80211_REASON_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DISASSOCIATE_RESULT_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Disassociation process completed successfully.
comment|///
name|DisassociateSuccess
block|,
comment|///
comment|/// Disassociation failed due to any input parameter is invalid.
comment|///
name|DisassociateInvalidParameters
block|}
name|EFI_80211_DISASSOCIATE_RESULT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AUTHENTICATION_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Open system authentication, admits any STA to the DS.
comment|///
name|OpenSystem
block|,
comment|///
comment|/// Shared Key authentication relies on WEP to demonstrate knowledge of a WEP
comment|/// encryption key.
comment|///
name|SharedKey
block|,
comment|///
comment|/// FT authentication relies on keys derived during the initial mobility domain
comment|/// association to authenticate the stations.
comment|///
name|FastBSSTransition
block|,
comment|///
comment|/// SAE authentication uses finite field cryptography to prove knowledge of a shared
comment|/// password.
comment|///
name|SAE
block|}
name|EFI_80211_AUTHENTICATION_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AUTHENTICATION_RESULT_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AuthenticateSuccess
block|,
name|AuthenticateRefused
block|,
name|AuthenticateAnticLoggingTokenRequired
block|,
name|AuthenticateFiniteCyclicGroupNotSupported
block|,
name|AuthenticationRejected
block|,
name|AuthenticateInvalidParameter
block|}
name|EFI_80211_AUTHENTICATE_RESULT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A unique element ID defined in IEEE 802.11 specification.
comment|///
name|UINT8
name|ElementID
decl_stmt|;
comment|///
comment|/// Specifies the number of octets in the element body.
comment|///
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_REQ
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Start of elements that are requested to be included in the Probe Response frame.
comment|/// The elements are listed in order of increasing element ID.
comment|///
name|UINT8
name|RequestIDs
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_REQ
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_SSID
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Service set identifier. If Hdr.Length is zero, this field is ignored.
comment|///
name|UINT8
name|SSId
index|[
literal|32
index|]
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_SSID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SCAN_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Determines whether infrastructure BSS, IBSS, MBSS, or all, are included in the
comment|/// scan.
comment|///
name|EFI_80211_BSS_TYPE
name|BSSType
decl_stmt|;
comment|///
comment|/// Indicates a specific or wildcard BSSID. Use all binary 1s to represent all SSIDs.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Length in bytes of the SSId. If zero, ignore SSId field.
comment|///
name|UINT8
name|SSIdLen
decl_stmt|;
comment|///
comment|/// Specifies the desired SSID or the wildcard SSID. Use NULL to represent all SSIDs.
comment|///
name|UINT8
modifier|*
name|SSId
decl_stmt|;
comment|///
comment|/// Indicates passive scanning if TRUE.
comment|///
name|BOOLEAN
name|PassiveMode
decl_stmt|;
comment|///
comment|/// The delay in microseconds to be used prior to transmitting a Probe frame during
comment|/// active scanning. If zero, the value can be overridden by an
comment|/// implementation-dependent default value.
comment|///
name|UINT32
name|ProbeDelay
decl_stmt|;
comment|///
comment|/// Specifies a list of channels that are examined when scanning for a BSS. If set to
comment|/// NULL, all valid channels will be scanned.
comment|///
name|UINT32
modifier|*
name|ChannelList
decl_stmt|;
comment|///
comment|/// Indicates the minimum time in TU to spend on each channel when scanning. If zero,
comment|/// the value can be overridden by an implementation-dependent default value.
comment|///
name|UINT32
name|MinChannelTime
decl_stmt|;
comment|///
comment|/// Indicates the maximum time in TU to spend on each channel when scanning. If zero,
comment|/// the value can be overridden by an implementation-dependent default value.
comment|///
name|UINT32
name|MaxChannelTime
decl_stmt|;
comment|///
comment|/// Points to an optionally present element. This is an optional parameter and may be
comment|/// NULL.
comment|///
name|EFI_80211_ELEMENT_REQ
modifier|*
name|RequestInformation
decl_stmt|;
comment|///
comment|/// Indicates one or more SSID elements that are optionally present. This is an
comment|/// optional parameter and may be NULL.
comment|///
name|EFI_80211_ELEMENT_SSID
modifier|*
name|SSIDList
decl_stmt|;
comment|///
comment|/// Specifies a desired specific access network type or the wildcard access network
comment|/// type. Use 15 as wildcard access network type.
comment|///
name|EFI_80211_ACC_NET_TYPE
name|AccessNetworkType
decl_stmt|;
comment|///
comment|///  Specifies zero or more elements. This is an optional parameter and may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_SCAN_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_COUNTRY_TRIPLET_SUBBAND
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates the lowest channel number in the subband. It has a positive integer
comment|/// value less than 201.
comment|///
name|UINT8
name|FirstChannelNum
decl_stmt|;
comment|///
comment|/// Indicates the number of channels in the subband.
comment|///
name|UINT8
name|NumOfChannels
decl_stmt|;
comment|///
comment|/// Indicates the maximum power in dBm allowed to be transmitted.
comment|///
name|UINT8
name|MaxTxPowerLevel
decl_stmt|;
block|}
name|EFI_80211_COUNTRY_TRIPLET_SUBBAND
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_COUNTRY_TRIPLET_OPERATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates the operating extension identifier. It has a positive integer value of
comment|/// 201 or greater.
comment|///
name|UINT8
name|OperatingExtId
decl_stmt|;
comment|///
comment|/// Index into a set of values for radio equipment set of rules.
comment|///
name|UINT8
name|OperatingClass
decl_stmt|;
comment|///
comment|/// Specifies aAirPropagationTime characteristics used in BSS operation. Refer the
comment|/// definition of aAirPropagationTime in IEEE 802.11 specification.
comment|///
name|UINT8
name|CoverageClass
decl_stmt|;
block|}
name|EFI_80211_COUNTRY_TRIPLET_OPERATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_COUNTRY_TRIPLET
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// The subband triplet.
comment|///
name|EFI_80211_COUNTRY_TRIPLET_SUBBAND
name|Subband
decl_stmt|;
comment|///
comment|/// The operating triplet.
comment|///
name|EFI_80211_COUNTRY_TRIPLET_OPERATE
name|Operating
decl_stmt|;
block|}
name|EFI_80211_COUNTRY_TRIPLET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_COUNTRY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Specifies country strings in 3 octets.
comment|///
name|UINT8
name|CountryStr
index|[
literal|3
index|]
decl_stmt|;
comment|///
comment|/// Indicates a triplet that repeated in country element. The number of triplets is
comment|/// determined by the Hdr.Length field.
comment|///
name|EFI_80211_COUNTRY_TRIPLET
name|CountryTriplet
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_COUNTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_DATA_RSN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates the version number of the RSNA protocol. Value 1 is defined in current
comment|/// IEEE 802.11 specification.
comment|///
name|UINT16
name|Version
decl_stmt|;
comment|///
comment|/// Specifies the cipher suite selector used by the BSS to protect group address frames.
comment|///
name|UINT32
name|GroupDataCipherSuite
decl_stmt|;
comment|///
comment|/// Indicates the number of pairwise cipher suite selectors that are contained in
comment|/// PairwiseCipherSuiteList.
comment|///
comment|//UINT16                             PairwiseCipherSuiteCount;
comment|///
comment|/// Contains a series of cipher suite selectors that indicate the pairwise cipher
comment|/// suites contained in this element.
comment|///
comment|//UINT32                             PairwiseCipherSuiteList[PairwiseCipherSuiteCount];
comment|///
comment|/// Indicates the number of AKM suite selectors that are contained in AKMSuiteList.
comment|///
comment|//UINT16                             AKMSuiteCount;
comment|///
comment|/// Contains a series of AKM suite selectors that indicate the AKM suites contained in
comment|/// this element.
comment|///
comment|//UINT32                             AKMSuiteList[AKMSuiteCount];
comment|///
comment|/// Indicates requested or advertised capabilities.
comment|///
comment|//UINT16                             RSNCapabilities;
comment|///
comment|/// Indicates the number of PKMIDs in the PMKIDList.
comment|///
comment|//UINT16                             PMKIDCount;
comment|///
comment|/// Contains zero or more PKMIDs that the STA believes to be valid for the destination
comment|/// AP.
comment|//UINT8                              PMKIDList[PMKIDCount][16];
comment|///
comment|/// Specifies the cipher suite selector used by the BSS to protect group addressed
comment|/// robust management frames.
comment|///
comment|//UINT32                             GroupManagementCipherSuite;
block|}
name|EFI_80211_ELEMENT_DATA_RSN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_RSN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Points to RSN element. The size of a RSN element is limited to 255 octets.
comment|///
name|EFI_80211_ELEMENT_DATA_RSN
modifier|*
name|Data
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_RSN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_EXT_CAP
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Indicates the capabilities being advertised by the STA transmitting the element.
comment|/// This is a bit field with variable length. Refer to IEEE 802.11 specification for
comment|/// bit value.
comment|///
name|UINT8
name|Capabilities
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_EXT_CAP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_BSS_DESCRIPTION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates a specific BSSID of the found BSS.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the SSID of the found BSS. If NULL, ignore SSIdLen field.
comment|///
name|UINT8
modifier|*
name|SSId
decl_stmt|;
comment|///
comment|/// Specifies the SSID of the found BSS. If NULL, ignore SSIdLen field.
comment|///
name|UINT8
name|SSIdLen
decl_stmt|;
comment|///
comment|/// Specifies the type of the found BSS.
comment|///
name|EFI_80211_BSS_TYPE
name|BSSType
decl_stmt|;
comment|///
comment|/// The beacon period in TU of the found BSS.
comment|///
name|UINT16
name|BeaconPeriod
decl_stmt|;
comment|///
comment|/// The timestamp of the received frame from the found BSS.
comment|///
name|UINT64
name|Timestamp
decl_stmt|;
comment|///
comment|/// The advertised capabilities of the BSS.
comment|///
name|UINT16
name|CapabilityInfo
decl_stmt|;
comment|///
comment|/// The set of data rates that shall be supported by all STAs that desire to join this
comment|/// BSS.
comment|///
name|UINT8
modifier|*
name|BSSBasicRateSet
decl_stmt|;
comment|///
comment|/// The set of data rates that the peer STA desires to use for communication within
comment|/// the BSS.
comment|///
name|UINT8
modifier|*
name|OperationalRateSet
decl_stmt|;
comment|///
comment|/// The information required to identify the regulatory domain in which the peer STA
comment|/// is located.
comment|///
name|EFI_80211_ELEMENT_COUNTRY
modifier|*
name|Country
decl_stmt|;
comment|///
comment|/// The cipher suites and AKM suites supported in the BSS.
comment|///
name|EFI_80211_ELEMENT_RSN
name|RSN
decl_stmt|;
comment|///
comment|/// Specifies the RSSI of the received frame.
comment|///
name|UINT8
name|RSSI
decl_stmt|;
comment|///
comment|/// Specifies the RCPI of the received frame.
comment|///
name|UINT8
name|RCPIMeasurement
decl_stmt|;
comment|///
comment|/// Specifies the RSNI of the received frame.
comment|///
name|UINT8
name|RSNIMeasurement
decl_stmt|;
comment|///
comment|/// Specifies the elements requested by the request element of the Probe Request frame.
comment|/// This is an optional parameter and may be NULL.
comment|///
name|UINT8
modifier|*
name|RequestedElements
decl_stmt|;
comment|///
comment|/// Specifies the BSS membership selectors that represent the set of features that
comment|/// shall be supported by all STAs to join this BSS.
comment|///
name|UINT8
modifier|*
name|BSSMembershipSelectorSet
decl_stmt|;
comment|///
comment|/// Specifies the parameters within the Extended Capabilities element that are
comment|/// supported by the MAC entity. This is an optional parameter and may be NULL.
comment|///
name|EFI_80211_ELEMENT_EXT_CAP
modifier|*
name|ExtCapElement
decl_stmt|;
block|}
name|EFI_80211_BSS_DESCRIPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SUBELEMENT_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates the unique identifier within the containing element or sub-element.
comment|///
name|UINT8
name|SubElementID
decl_stmt|;
comment|///
comment|/// Specifies the number of octets in the Data field.
comment|///
name|UINT8
name|Length
decl_stmt|;
comment|///
comment|/// A variable length data buffer.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_SUBELEMENT_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_MULTIPLE_BSSID
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Indicates the maximum number of BSSIDs in the multiple BSSID set. When Indicator
comment|/// is set to n, 2n is the maximum number.
comment|///
name|UINT8
name|Indicator
decl_stmt|;
comment|///
comment|/// Contains zero or more sub-elements.
comment|///
name|EFI_80211_SUBELEMENT_INFO
name|SubElement
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_MULTIPLE_BSSID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_BSS_DESP_PILOT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates a specific BSSID of the found BSS.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the type of the found BSS.
comment|///
name|EFI_80211_BSS_TYPE
name|BSSType
decl_stmt|;
comment|///
comment|/// One octet field to report condensed capability information.
comment|///
name|UINT8
name|ConCapInfo
decl_stmt|;
comment|///
comment|/// Two octet's field to report condensed country string.
comment|///
name|UINT8
name|ConCountryStr
index|[
literal|2
index|]
decl_stmt|;
comment|///
comment|/// Indicates the operating class value for the operating channel.
comment|///
name|UINT8
name|OperatingClass
decl_stmt|;
comment|///
comment|/// Indicates the operating channel.
comment|///
name|UINT8
name|Channel
decl_stmt|;
comment|///
comment|/// Indicates the measurement pilot interval in TU.
comment|///
name|UINT8
name|Interval
decl_stmt|;
comment|///
comment|/// Indicates that the BSS is within a multiple BSSID set.
comment|///
name|EFI_80211_MULTIPLE_BSSID
modifier|*
name|MultipleBSSID
decl_stmt|;
comment|///
comment|/// Specifies the RCPI of the received frame.
comment|///
name|UINT8
name|RCPIMeasurement
decl_stmt|;
comment|///
comment|/// Specifies the RSNI of the received frame.
comment|///
name|UINT8
name|RSNIMeasurement
decl_stmt|;
block|}
name|EFI_80211_BSS_DESP_PILOT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SCAN_RESULT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The number of EFI_80211_BSS_DESCRIPTION in BSSDespSet. If zero, BSSDespSet should
comment|/// be ignored.
comment|///
name|UINTN
name|NumOfBSSDesp
decl_stmt|;
comment|///
comment|/// Points to zero or more instances of EFI_80211_BSS_DESCRIPTION.
comment|///
name|EFI_80211_BSS_DESCRIPTION
modifier|*
modifier|*
name|BSSDespSet
decl_stmt|;
comment|///
comment|/// The number of EFI_80211_BSS_DESP_PILOT in BSSDespFromPilotSet. If zero,
comment|/// BSSDespFromPilotSet should be ignored.
comment|///
name|UINTN
name|NumofBSSDespFromPilot
decl_stmt|;
comment|///
comment|/// Points to zero or more instances of EFI_80211_BSS_DESP_PILOT.
comment|///
name|EFI_80211_BSS_DESP_PILOT
modifier|*
modifier|*
name|BSSDespFromPilotSet
decl_stmt|;
comment|///
comment|/// Specifies zero or more elements. This is an optional parameter and may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_SCAN_RESULT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SCAN_DATA_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI Wireless
comment|/// MAC Connection Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS:       Scan operation completed successfully.
comment|///   EFI_NOT_FOUND:     Failed to find available BSS.
comment|///   EFI_DEVICE_ERROR:  An unexpected network or system error occurred.
comment|///   EFI_ACCESS_DENIED: The scan operation is not completed due to some underlying
comment|///                      hardware or software state.
comment|///   EFI_NOT_READY:     The scan operation is started but not yet completed.
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to the scan data.
comment|///
name|EFI_80211_SCAN_DATA
modifier|*
name|Data
decl_stmt|;
comment|///
comment|/// Indicates the scan state.
comment|///
name|EFI_80211_SCAN_RESULT_CODE
name|ResultCode
decl_stmt|;
comment|///
comment|/// Indicates the scan result. It is caller's responsibility to free this buffer.
comment|///
name|EFI_80211_SCAN_RESULT
modifier|*
name|Result
decl_stmt|;
block|}
name|EFI_80211_SCAN_DATA_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_SUPP_CHANNEL_TUPLE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The first channel number in a subband of supported channels.
comment|///
name|UINT8
name|FirstChannelNumber
decl_stmt|;
comment|///
comment|/// The number of channels in a subband of supported channels.
comment|///
name|UINT8
name|NumberOfChannels
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_SUPP_CHANNEL_TUPLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_SUPP_CHANNEL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Indicates one or more tuples of (first channel, number of channels).
comment|///
name|EFI_80211_ELEMENT_SUPP_CHANNEL_TUPLE
name|Subband
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_SUPP_CHANNEL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ASSOCIATE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity to associate with.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the requested operational capabilities to the AP in 2 octets.
comment|///
name|UINT16
name|CapabilityInfo
decl_stmt|;
comment|///
comment|/// Specifies a time limit in TU, after which the associate procedure is terminated.
comment|///
name|UINT32
name|FailureTimeout
decl_stmt|;
comment|///
comment|/// Specifies if in power save mode, how often the STA awakes and listens for the next
comment|/// beacon frame in TU.
comment|///
name|UINT32
name|ListenInterval
decl_stmt|;
comment|///
comment|/// Indicates a list of channels in which the STA is capable of operating.
comment|///
name|EFI_80211_ELEMENT_SUPP_CHANNEL
modifier|*
name|Channels
decl_stmt|;
comment|///
comment|/// The cipher suites and AKM suites selected by the STA.
comment|///
name|EFI_80211_ELEMENT_RSN
name|RSN
decl_stmt|;
comment|///
comment|/// Specifies the parameters within the Extended Capabilities element that are
comment|/// supported by the MAC entity.  This is an optional parameter and may be NULL.
comment|///
name|EFI_80211_ELEMENT_EXT_CAP
modifier|*
name|ExtCapElement
decl_stmt|;
comment|///
comment|/// Specifies zero or more elements. This is an optional parameter and may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_ASSOCIATE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ELEMENT_TIMEOUT_VAL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Common header of an element.
comment|///
name|EFI_80211_ELEMENT_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// Specifies the timeout interval type.
comment|///
name|UINT8
name|Type
decl_stmt|;
comment|///
comment|/// Specifies the timeout interval value.
comment|///
name|UINT32
name|Value
decl_stmt|;
block|}
name|EFI_80211_ELEMENT_TIMEOUT_VAL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ASSOCIATE_RESULT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity from which the association request
comment|/// was received.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the operational capabilities advertised by the AP.
comment|///
name|UINT16
name|CapabilityInfo
decl_stmt|;
comment|///
comment|/// Specifies the association ID value assigned by the AP.
comment|///
name|UINT16
name|AssociationID
decl_stmt|;
comment|///
comment|/// Indicates the measured RCPI of the corresponding association request frame. It is
comment|/// an optional parameter and is set to zero if unavailable.
comment|///
name|UINT8
name|RCPIValue
decl_stmt|;
comment|///
comment|/// Indicates the measured RSNI at the time the corresponding association request
comment|/// frame was received. It is an optional parameter and is set to zero if unavailable.
comment|///
name|UINT8
name|RSNIValue
decl_stmt|;
comment|///
comment|/// Specifies the parameters within the Extended Capabilities element that are
comment|/// supported by the MAC entity.  This is an optional parameter and may be NULL.
comment|///
name|EFI_80211_ELEMENT_EXT_CAP
modifier|*
name|ExtCapElement
decl_stmt|;
comment|///
comment|/// Specifies the timeout interval when the result code is AssociateRefusedTemporarily.
comment|///
name|EFI_80211_ELEMENT_TIMEOUT_VAL
name|TimeoutInterval
decl_stmt|;
comment|///
comment|/// Specifies zero or more elements. This is an optional parameter and may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_ASSOCIATE_RESULT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_ASSOCIATE_DATA_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI Wireless
comment|/// MAC Connection Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS:      Association operation completed successfully.
comment|///   EFI_DEVICE_ERROR: An unexpected network or system error occurred.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to the association data.
comment|///
name|EFI_80211_ASSOCIATE_DATA
modifier|*
name|Data
decl_stmt|;
comment|///
comment|/// Indicates the association state.
comment|///
name|EFI_80211_ASSOCIATE_RESULT_CODE
name|ResultCode
decl_stmt|;
comment|///
comment|/// Indicates the association result. It is caller's responsibility to free this
comment|/// buffer.
comment|///
name|EFI_80211_ASSOCIATE_RESULT
modifier|*
name|Result
decl_stmt|;
block|}
name|EFI_80211_ASSOCIATE_DATA_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DISASSOCIATE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity with which to perform the
comment|/// disassociation process.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the reason for initiating the disassociation process.
comment|///
name|EFI_80211_REASON_CODE
name|ReasonCode
decl_stmt|;
comment|///
comment|/// Zero or more elements, may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_DISASSOCIATE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DISASSOCIATE_DATA_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI Wireless
comment|/// MAC Connection Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS:       Disassociation operation completed successfully.
comment|///   EFI_DEVICE_ERROR:  An unexpected network or system error occurred.
comment|///   EFI_ACCESS_DENIED: The disassociation operation is not completed due to some
comment|///                      underlying hardware or software state.
comment|///   EFI_NOT_READY:     The disassociation operation is started but not yet completed.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to the disassociation data.
comment|///
name|EFI_80211_DISASSOCIATE_DATA
modifier|*
name|Data
decl_stmt|;
comment|///
comment|/// Indicates the disassociation state.
comment|///
name|EFI_80211_DISASSOCIATE_RESULT_CODE
name|ResultCode
decl_stmt|;
block|}
name|EFI_80211_DISASSOCIATE_DATA_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AUTHENTICATION_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity with which to perform the
comment|/// authentication process.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the type of authentication algorithm to use during the authentication
comment|/// process.
comment|///
name|EFI_80211_AUTHENTICATION_TYPE
name|AuthType
decl_stmt|;
comment|///
comment|/// Specifies a time limit in TU after which the authentication procedure is
comment|/// terminated.
comment|///
name|UINT32
name|FailureTimeout
decl_stmt|;
comment|///
comment|/// Specifies the set of elements to be included in the first message of the FT
comment|/// authentication sequence, may be NULL.
comment|///
name|UINT8
modifier|*
name|FTContent
decl_stmt|;
comment|///
comment|/// Specifies the set of elements to be included in the SAE Commit Message or SAE
comment|/// Confirm Message, may be NULL.
comment|///
name|UINT8
modifier|*
name|SAEContent
decl_stmt|;
comment|///
comment|/// Zero or more elements, may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_AUTHENTICATE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AUTHENTICATION_RESULT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity from which the authentication request
comment|/// was received.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the set of elements to be included in the second message of the FT
comment|/// authentication sequence, may be NULL.
comment|///
name|UINT8
modifier|*
name|FTContent
decl_stmt|;
comment|///
comment|/// Specifies the set of elements to be included in the SAE Commit Message or SAE
comment|/// Confirm Message, may be NULL.
comment|///
name|UINT8
modifier|*
name|SAEContent
decl_stmt|;
comment|///
comment|/// Zero or more elements, may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_AUTHENTICATE_RESULT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AUTHENTICATE_DATA_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI Wireless
comment|/// MAC Connection Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS: Authentication operation completed successfully.
comment|///   EFI_PROTOCOL_ERROR: Peer MAC entity rejects the authentication.
comment|///   EFI_NO_RESPONSE:    Peer MAC entity does not response the authentication request.
comment|///   EFI_DEVICE_ERROR:   An unexpected network or system error occurred.
comment|///   EFI_ACCESS_DENIED:  The authentication operation is not completed due to some
comment|///                       underlying hardware or software state.
comment|///   EFI_NOT_READY:      The authentication operation is started but not yet completed.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to the authentication data.
comment|///
name|EFI_80211_AUTHENTICATE_DATA
modifier|*
name|Data
decl_stmt|;
comment|///
comment|/// Indicates the association state.
comment|///
name|EFI_80211_AUTHENTICATE_RESULT_CODE
name|ResultCode
decl_stmt|;
comment|///
comment|/// Indicates the association result. It is caller's responsibility to free this
comment|/// buffer.
comment|///
name|EFI_80211_AUTHENTICATE_RESULT
modifier|*
name|Result
decl_stmt|;
block|}
name|EFI_80211_AUTHENTICATE_DATA_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DEAUTHENTICATE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies the address of the peer MAC entity with which to perform the
comment|/// deauthentication process.
comment|///
name|EFI_80211_MAC_ADDRESS
name|BSSId
decl_stmt|;
comment|///
comment|/// Specifies the reason for initiating the deauthentication process.
comment|///
name|EFI_80211_REASON_CODE
name|ReasonCode
decl_stmt|;
comment|///
comment|/// Zero or more elements, may be NULL.
comment|///
name|UINT8
modifier|*
name|VendorSpecificInfo
decl_stmt|;
block|}
name|EFI_80211_DEAUTHENTICATE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DEAUTHENTICATE_DATA_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI Wireless
comment|/// MAC Connection Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS:       Deauthentication operation completed successfully.
comment|///   EFI_DEVICE_ERROR:  An unexpected network or system error occurred.
comment|///   EFI_ACCESS_DENIED: The deauthentication operation is not completed due to some
comment|///                      underlying hardware or software state.
comment|///   EFI_NOT_READY:     The deauthentication operation is started but not yet
comment|///                      completed.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to the deauthentication data.
comment|///
name|EFI_80211_DEAUTHENTICATE_DATA
modifier|*
name|Data
decl_stmt|;
block|}
name|EFI_80211_DEAUTHENTICATE_DATA_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Request a survey of potential BSSs that administrator can later elect to try to join.    The Scan() function returns the description of the set of BSSs detected by the scan   process. Passive scan operation is performed by default.    @param[in]  This                Pointer to the EFI_WIRELESS_MAC_CONNECTION_PROTOCOL                                   instance.   @param[in]  Data                Pointer to the scan token.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   Data->Data is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters are not supported                                   by this implementation.   @retval EFI_ALREADY_STARTED     The scan operation is already started. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_SCAN
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_SCAN_DATA_TOKEN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Request an association with a specified peer MAC entity that is within an AP.    The Associate() function provides the capability for MAC layer to become associated   with an AP.    @param[in]  This                Pointer to the EFI_WIRELESS_MAC_CONNECTION_PROTOCOL                                   instance.   @param[in]  Data                Pointer to the association token.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   Data->Data is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters are not supported                                   by this implementation.   @retval EFI_ALREADY_STARTED     The association process is already started.   @retval EFI_NOT_READY           Authentication is not performed before this association                                   process.   @retval EFI_NOT_FOUND           The specified peer MAC entity is not found.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_ASSOCIATE
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_ASSOCIATE_DATA_TOKEN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Request a disassociation with a specified peer MAC entity.    The Disassociate() function is invoked to terminate an existing association.   Disassociation is a notification and cannot be refused by the receiving peer except   when management frame protection is negotiated and the message integrity check fails.    @param[in]  This                Pointer to the EFI_WIRELESS_MAC_CONNECTION_PROTOCOL                                   instance.   @param[in]  Data                Pointer to the disassociation token.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.   @retval EFI_ALREADY_STARTED     The disassociation process is already started.   @retval EFI_NOT_READY           The disassociation service is invoked to a                                   nonexistent association relationship.   @retval EFI_NOT_FOUND           The specified peer MAC entity is not found.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_DISASSOCIATE
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_DISASSOCIATE_DATA_TOKEN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Request the process of establishing an authentication relationship with a peer MAC   entity.    The Authenticate() function requests authentication with a specified peer MAC entity.   This service might be time-consuming thus is designed to be invoked independently of   the association service.    @param[in]  This                Pointer to the EFI_WIRELESS_MAC_CONNECTION_PROTOCOL                                   instance.   @param[in]  Data                Pointer to the authentication token.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   Data.Data is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters are not supported                                   by this implementation.   @retval EFI_ALREADY_STARTED     The authentication process is already started.   @retval EFI_NOT_FOUND           The specified peer MAC entity is not found.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_AUTHENTICATE
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_AUTHENTICATE_DATA_TOKEN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Invalidate the authentication relationship with a peer MAC entity.    The Deauthenticate() function requests that the authentication relationship with a   specified peer MAC entity be invalidated. Deauthentication is a notification and when   it is sent out the association at the transmitting station is terminated.    @param[in]  This                Pointer to the EFI_WIRELESS_MAC_CONNECTION_PROTOCOL                                   instance.   @param[in]  Data                Pointer to the deauthentication token.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   Data.Data is NULL.   @retval EFI_ALREADY_STARTED     The deauthentication process is already started.   @retval EFI_NOT_READY           The deauthentication service is invoked to a                                   nonexistent association or authentication relationship.   @retval EFI_NOT_FOUND           The specified peer MAC entity is not found.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_DEAUTHENTICATE
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_DEAUTHENTICATE_DATA_TOKEN
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_WIRELESS_MAC_CONNECTION_PROTOCOL is designed to provide management service
end_comment

begin_comment
comment|/// interfaces for the EFI wireless network stack to establish wireless connection with
end_comment

begin_comment
comment|/// AP. An EFI Wireless MAC Connection Protocol instance will be installed on each
end_comment

begin_comment
comment|/// communication device that the EFI wireless network stack runs on.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_WIRELESS_MAC_CONNECTION_PROTOCOL
block|{
name|EFI_WIRELESS_MAC_CONNECTION_SCAN
name|Scan
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_ASSOCIATE
name|Associate
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_DISASSOCIATE
name|Disassociate
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_AUTHENTICATE
name|Authenticate
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_DEAUTHENTICATE
name|Deauthenticate
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiWiFiProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

