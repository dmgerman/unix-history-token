begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI Wireless MAC Connection II Protocol.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.6  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_WIFI2_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_WIFI2_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL_GUID
define|\
value|{ \     0x1b0fb9bf, 0x699d, 0x4fdd, { 0xa7, 0xc3, 0x25, 0x46, 0x68, 0x1b, 0xf6, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
name|EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_BSS_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IeeeInfrastructureBSS
block|,
name|IeeeIndependentBSS
block|,
name|IeeeMeshBSS
block|,
name|IeeeAnyBss
block|}
name|EFI_80211_BSS_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_CONNECT_NETWORK_RESULT_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// The connection establishment operation finished successfully.
comment|//
name|ConnectSuccess
block|,
comment|//
comment|// The connection was refused by the Network.
comment|//
name|ConnectRefused
block|,
comment|//
comment|// The connection establishment operation failed (i.e, Network is not
comment|// detected).
comment|//
name|ConnectFailed
block|,
comment|//
comment|// The connection establishment operation was terminated on timeout.
comment|//
name|ConnectFailureTimeout
block|,
comment|//
comment|// The connection establishment operation failed on other reason.
comment|//
name|ConnectFailedReasonUnspecified
block|}
name|EFI_80211_CONNECT_NETWORK_RESULT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_MAC_ADDRESS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_80211_MAC_ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_MAX_SSID_LEN
value|32
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SSID
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Length in bytes of the SSId. If zero, ignore SSId field.
comment|//
name|UINT8
name|SSIdLen
decl_stmt|;
comment|//
comment|// Specifies the service set identifier.
comment|//
name|UINT8
name|SSId
index|[
name|EFI_MAX_SSID_LEN
index|]
decl_stmt|;
block|}
name|EFI_80211_SSID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_GET_NETWORKS_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// The number of EFI_80211_SSID in SSIDList. If zero, SSIDList should be
comment|// ignored.
comment|//
name|UINT32
name|NumOfSSID
decl_stmt|;
comment|//
comment|// The SSIDList is a pointer to an array of EFI_80211_SSID instances. The
comment|// number of entries is specified by NumOfSSID. The array should only include
comment|// SSIDs of hidden networks. It is suggested that the caller inputs less than
comment|// 10 elements in the SSIDList. It is the caller's responsibility to free
comment|// this buffer.
comment|//
name|EFI_80211_SSID
name|SSIDList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_GET_NETWORKS_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_SUITE_SELECTOR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Organization Unique Identifier, as defined in IEEE 802.11 standard,
comment|// usually set to 00-0F-AC.
comment|//
name|UINT8
name|Oui
index|[
literal|3
index|]
decl_stmt|;
comment|//
comment|// Suites types, as defined in IEEE 802.11 standard.
comment|//
name|UINT8
name|SuiteType
decl_stmt|;
block|}
name|EFI_80211_SUITE_SELECTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_AKM_SUITE_SELECTOR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Indicates the number of AKM suite selectors that are contained in
comment|// AKMSuiteList. If zero, the AKMSuiteList is ignored.
comment|//
name|UINT16
name|AKMSuiteCount
decl_stmt|;
comment|//
comment|// A variable-length array of AKM suites, as defined in IEEE 802.11 standard,
comment|// Table 8-101. The number of entries is specified by AKMSuiteCount.
comment|//
name|EFI_80211_SUITE_SELECTOR
name|AKMSuiteList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_AKM_SUITE_SELECTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_CIPHER_SUITE_SELECTOR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Indicates the number of cipher suites that are contained in
comment|// CipherSuiteList. If zero, the CipherSuiteList is ignored.
comment|//
name|UINT16
name|CipherSuiteCount
decl_stmt|;
comment|//
comment|// A variable-length array of cipher suites, as defined in IEEE 802.11
comment|// standard, Table 8-99. The number of entries is specified by
comment|// CipherSuiteCount.
comment|//
name|EFI_80211_SUITE_SELECTOR
name|CipherSuiteList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_80211_CIPHER_SUITE_SELECTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_NETWORK
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Specifies the type of the BSS.
comment|//
name|EFI_80211_BSS_TYPE
name|BSSType
decl_stmt|;
comment|//
comment|// Specifies the SSID of the BSS.
comment|//
name|EFI_80211_SSID
name|SSId
decl_stmt|;
comment|//
comment|// Pointer to the AKM suites supported in the wireless network.
comment|//
name|EFI_80211_AKM_SUITE_SELECTOR
modifier|*
name|AKMSuite
decl_stmt|;
comment|//
comment|// Pointer to the cipher suites supported in the wireless network.
comment|//
name|EFI_80211_CIPHER_SUITE_SELECTOR
modifier|*
name|CipherSuite
decl_stmt|;
block|}
name|EFI_80211_NETWORK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_NETWORK_DESCRIPTION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Specifies the found wireless network.
comment|//
name|EFI_80211_NETWORK
name|Network
decl_stmt|;
comment|//
comment|// Indicates the network quality as a value between 0 to 100, where 100
comment|// indicates the highest network quality.
comment|//
name|UINT8
name|NetworkQuality
decl_stmt|;
block|}
name|EFI_80211_NETWORK_DESCRIPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_GET_NETWORKS_RESULT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// The number of EFI_80211_NETWORK_DESCRIPTION in NetworkDesc. If zero,
comment|// NetworkDesc should be ignored.
comment|//
name|UINT8
name|NumOfNetworkDesc
decl_stmt|;
comment|//
comment|// The NetworkDesc is a pointer to an array of EFI_80211_NETWORK_DESCRIPTION
comment|// instances. It is caller's responsibility to free this buffer.
comment|//
name|EFI_80211_NETWORK_DESCRIPTION
modifier|*
modifier|*
name|NetworkDesc
decl_stmt|;
block|}
name|EFI_80211_GET_NETWORKS_RESULT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_GET_NETWORKS_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If the status code returned by GetNetworks() is EFI_SUCCESS, then this
comment|// Event will be signaled after the Status field is updated by the EFI
comment|// Wireless MAC Connection Protocol II driver. The type of Event must be
comment|// EFI_NOTIFY_SIGNAL.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Will be set to one of the following values:
comment|// EFI_SUCCESS: The operation completed successfully.
comment|// EFI_NOT_FOUND: Failed to find available wireless networks.
comment|// EFI_DEVICE_ERROR: An unexpected network or system error occurred.
comment|// EFI_ACCESS_DENIED: The operation is not completed due to some underlying
comment|// hardware or software state.
comment|// EFI_NOT_READY: The operation is started but not yet completed.
comment|//
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// Pointer to the input data for getting networks.
comment|//
name|EFI_80211_GET_NETWORKS_DATA
modifier|*
name|Data
decl_stmt|;
comment|//
comment|// Indicates the scan result. It is caller's responsibility to free this
comment|// buffer.
comment|//
name|EFI_80211_GET_NETWORKS_RESULT
modifier|*
name|Result
decl_stmt|;
block|}
name|EFI_80211_GET_NETWORKS_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_CONNECT_NETWORK_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Specifies the wireless network to connect to.
comment|//
name|EFI_80211_NETWORK
modifier|*
name|Network
decl_stmt|;
comment|//
comment|// Specifies a time limit in seconds that is optionally present, after which
comment|// the connection establishment procedure is terminated by the UNDI driver.
comment|// This is an optional parameter and may be 0. Values of 5 seconds or higher
comment|// are recommended.
comment|//
name|UINT32
name|FailureTimeout
decl_stmt|;
block|}
name|EFI_80211_CONNECT_NETWORK_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_CONNECT_NETWORK_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If the status code returned by ConnectNetwork() is EFI_SUCCESS, then this
comment|// Event will be signaled after the Status field is updated by the EFI
comment|// Wireless MAC Connection Protocol II driver. The type of Event must be
comment|// EFI_NOTIFY_SIGNAL.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Will be set to one of the following values:
comment|// EFI_SUCCESS: The operation completed successfully.
comment|// EFI_DEVICE_ERROR: An unexpected network or system error occurred.
comment|// EFI_ACCESS_DENIED: The operation is not completed due to some underlying
comment|// hardware or software state.
comment|// EFI_NOT_READY: The operation is started but not yet completed.
comment|//
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// Pointer to the connection data.
comment|//
name|EFI_80211_CONNECT_NETWORK_DATA
modifier|*
name|Data
decl_stmt|;
comment|//
comment|// Indicates the connection state.
comment|//
name|EFI_80211_CONNECT_NETWORK_RESULT_CODE
name|ResultCode
decl_stmt|;
block|}
name|EFI_80211_CONNECT_NETWORK_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_DISCONNECT_NETWORK_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If the status code returned by DisconnectNetwork() is EFI_SUCCESS, then
comment|// this Event will be signaled after the Status field is updated by the EFI
comment|// Wireless MAC Connection Protocol II driver. The type of Event must be
comment|// EFI_NOTIFY_SIGNAL.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Will be set to one of the following values:
comment|// EFI_SUCCESS: The operation completed successfully
comment|// EFI_DEVICE_ERROR: An unexpected network or system error occurred.
comment|// EFI_ACCESS_DENIED: The operation is not completed due to some underlying
comment|// hardware or software state.
comment|//
name|EFI_STATUS
name|Status
decl_stmt|;
block|}
name|EFI_80211_DISCONNECT_NETWORK_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Request a survey of potential wireless networks that administrator can later   elect to try to join.    @param[in]  This                Pointer to the                                   EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL                                   instance.   @param[in]  Token               Pointer to the token for getting wireless                                   network.    @retval EFI_SUCCESS             The operation started, and an event will                                   eventually be raised for the caller.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   This is NULL.                                   Token is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters is not                                   supported by this implementation.   @retval EFI_ALREADY_STARTED     The operation of getting wireless network is                                   already started.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be                                   allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_II_GET_NETWORKS
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_GET_NETWORKS_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Connect a wireless network specified by a particular SSID, BSS type and   Security type.    @param[in]  This                Pointer to the                                   EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL                                   instance.   @param[in]  Token               Pointer to the token for connecting wireless                                   network.    @retval EFI_SUCCESS             The operation started successfully. Results                                   will be notified eventually.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   This is NULL.                                   Token is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters are not                                   supported by this implementation.   @retval EFI_ALREADY_STARTED     The connection process is already started.   @retval EFI_NOT_FOUND           The specified wireless network is not found.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be                                   allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_II_CONNECT_NETWORK
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_CONNECT_NETWORK_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Request a disconnection with current connected wireless network.    @param[in]  This                Pointer to the                                   EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL                                   instance.   @param[in]  Token               Pointer to the token for disconnecting                                   wireless network.    @retval EFI_SUCCESS             The operation started successfully. Results                                   will be notified eventually.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   This is NULL.                                   Token is NULL.   @retval EFI_UNSUPPORTED         One or more of the input parameters are not                                   supported by this implementation.   @retval EFI_NOT_FOUND           Not connected to a wireless network.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be                                   allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WIRELESS_MAC_CONNECTION_II_DISCONNECT_NETWORK
function_decl|)
parameter_list|(
name|IN
name|EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_80211_DISCONNECT_NETWORK_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL provides network management
end_comment

begin_comment
comment|/// service interfaces for 802.11 network stack. It is used by network
end_comment

begin_comment
comment|/// applications (and drivers) to establish wireless connection with a wireless
end_comment

begin_comment
comment|/// network.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_WIRELESS_MAC_CONNECTION_II_PROTOCOL
block|{
name|EFI_WIRELESS_MAC_CONNECTION_II_GET_NETWORKS
name|GetNetworks
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_II_CONNECT_NETWORK
name|ConnectNetwork
decl_stmt|;
name|EFI_WIRELESS_MAC_CONNECTION_II_DISCONNECT_NETWORK
name|DisconnectNetwork
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiWiFi2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

