begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI Supplicant Protocol.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.6  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SUPPLICANT_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SUPPLICANT_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/WiFi2.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI Supplicant Service Binding Protocol is used to locate EFI
end_comment

begin_comment
comment|/// Supplicant Protocol drivers to create and destroy child of the driver to
end_comment

begin_comment
comment|/// communicate with other host using Supplicant protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SUPPLICANT_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x45bcd98e, 0x59ad, 0x4174, { 0x95, 0x46, 0x34, 0x4a, 0x7, 0x48, 0x58, 0x98 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI Supplicant protocol provides services to process authentication and
end_comment

begin_comment
comment|/// data encryption/decryption for security management.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SUPPLICANT_PROTOCOL_GUID
define|\
value|{ \     0x54fcc43e, 0xaa89, 0x4333, { 0x9a, 0x85, 0xcd, 0xea, 0x24, 0x5, 0x1e, 0x9e } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SUPPLICANT_PROTOCOL
name|EFI_SUPPLICANT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_CRYPT_MODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// Encrypt data provided in the fragment buffers.
comment|//
name|EfiSupplicantEncrypt
block|,
comment|//
comment|// Decrypt data provided in the fragment buffers.
comment|//
name|EfiSupplicantDecrypt
block|, }
name|EFI_SUPPLICANT_CRYPT_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// Session Configuration
comment|//
comment|//
comment|// Current authentication type in use. The corresponding Data is of type
comment|// EFI_80211_AKM_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211AKMSuite
block|,
comment|//
comment|// Group data encryption type in use. The corresponding Data is of type
comment|// EFI_SUPPLICANT_CIPHER_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211GroupDataCipherSuite
block|,
comment|//
comment|// Pairwise encryption type in use. The corresponding Data is of type
comment|// EFI_80211_CIPHER_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211PairwiseCipherSuite
block|,
comment|//
comment|// PSK password. The corresponding Data is a NULL-terminated ASCII string.
comment|//
name|EfiSupplicant80211PskPassword
block|,
comment|//
comment|// Target SSID name. The corresponding Data is of type EFI_80211_SSID.
comment|//
name|EfiSupplicant80211TargetSSIDName
block|,
comment|//
comment|// Station MAC address. The corresponding Data is of type
comment|// EFI_80211_MAC_ADDRESS.
comment|//
name|EfiSupplicant80211StationMac
block|,
comment|//
comment|// Target SSID MAC address. The corresponding Data is 6 bytes MAC address.
comment|//
name|EfiSupplicant80211TargetSSIDMac
block|,
comment|//
comment|// Session Information
comment|//
comment|//
comment|// 802.11 PTK. The corresponding Data is of type EFI_SUPPLICANT_KEY.
comment|//
name|EfiSupplicant80211PTK
block|,
comment|//
comment|// 802.11 GTK. The corresponding Data is of type EFI_SUPPLICANT_GTK_LIST.
comment|//
name|EfiSupplicant80211GTK
block|,
comment|//
comment|// Supplicant state. The corresponding Data is
comment|// EFI_EAPOL_SUPPLICANT_PAE_STATE.
comment|//
name|EfiSupplicantState
block|,
comment|//
comment|// 802.11 link state. The corresponding Data is EFI_80211_LINK_STATE.
comment|//
name|EfiSupplicant80211LinkState
block|,
comment|//
comment|// Flag indicates key is refreshed. The corresponding Data is
comment|// EFI_SUPPLICANT_KEY_REFRESH.
comment|//
name|EfiSupplicantKeyRefresh
block|,
comment|//
comment|// Session Configuration
comment|//
comment|//
comment|// Supported authentication types. The corresponding Data is of type
comment|// EFI_80211_AKM_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211SupportedAKMSuites
block|,
comment|//
comment|// Supported software encryption types provided by supplicant driver. The
comment|// corresponding Data is of type EFI_80211_CIPHER_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211SupportedSoftwareCipherSuites
block|,
comment|//
comment|// Supported hardware encryption types provided by wireless UNDI driver. The
comment|// corresponding Data is of type EFI_80211_CIPHER_SUITE_SELECTOR.
comment|//
name|EfiSupplicant80211SupportedHardwareCipherSuites
block|,
comment|//
comment|// Session Information
comment|//
comment|//
comment|// 802.11 Integrity GTK. The corresponding Data is of type
comment|// EFI_SUPPLICANT_GTK_LIST.
comment|//
name|EfiSupplicant80211IGTK
block|,
name|EfiSupplicantDataTypeMaximum
block|}
name|EFI_SUPPLICANT_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_80211_LINK_STATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// Indicates initial start state, unauthenticated, unassociated.
comment|//
name|Ieee80211UnauthenticatedUnassociated
block|,
comment|//
comment|// Indicates authenticated, unassociated.
comment|//
name|Ieee80211AuthenticatedUnassociated
block|,
comment|//
comment|// Indicates authenticated and associated, but pending RSN authentication.
comment|//
name|Ieee80211PendingRSNAuthentication
block|,
comment|//
comment|// Indicates authenticated and associated.
comment|//
name|Ieee80211AuthenticatedAssociated
block|}
name|EFI_80211_LINK_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_KEY_TYPE (IEEE Std 802.11 Section 6.3.19.1.2)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Group
block|,
name|Pairwise
block|,
name|PeerKey
block|,
name|IGTK
block|}
name|EFI_SUPPLICANT_KEY_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_KEY_DIRECTION (IEEE Std 802.11 Section 6.3.19.1.2)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// Indicates that the keys are being installed for the receive direction.
comment|//
name|Receive
block|,
comment|//
comment|// Indicates that the keys are being installed for the transmit direction.
comment|//
name|Transmit
block|,
comment|//
comment|// Indicates that the keys are being installed for both the receive and
comment|// transmit directions.
comment|//
name|Both
block|}
name|EFI_SUPPLICANT_KEY_DIRECTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_KEY_REFRESH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If TRUE, indicates GTK is just refreshed after a successful call to
comment|// EFI_SUPPLICANT_PROTOCOL.BuildResponsePacket().
comment|//
name|BOOLEAN
name|GTKRefresh
decl_stmt|;
block|}
name|EFI_SUPPLICANT_KEY_REFRESH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_MAX_KEY_LEN
value|64
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_KEY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// The key value.
comment|//
name|UINT8
name|Key
index|[
name|EFI_MAX_KEY_LEN
index|]
decl_stmt|;
comment|//
comment|// Length in bytes of the Key. Should be up to EFI_MAX_KEY_LEN.
comment|//
name|UINT8
name|KeyLen
decl_stmt|;
comment|//
comment|// The key identifier.
comment|//
name|UINT8
name|KeyId
decl_stmt|;
comment|//
comment|// Defines whether this key is a group key, pairwise key, PeerKey, or
comment|// Integrity Group.
comment|//
name|EFI_SUPPLICANT_KEY_TYPE
name|KeyType
decl_stmt|;
comment|//
comment|// The value is set according to the KeyType.
comment|//
name|EFI_80211_MAC_ADDRESS
name|Addr
decl_stmt|;
comment|//
comment|// The Receive Sequence Count value.
comment|//
name|UINT8
name|Rsc
index|[
literal|8
index|]
decl_stmt|;
comment|//
comment|// Length in bytes of the Rsc. Should be up to 8.
comment|//
name|UINT8
name|RscLen
decl_stmt|;
comment|//
comment|// Indicates whether the key is configured by the Authenticator or
comment|// Supplicant. The value true indicates Authenticator.
comment|//
name|BOOLEAN
name|IsAuthenticator
decl_stmt|;
comment|//
comment|// The cipher suite required for this association.
comment|//
name|EFI_80211_SUITE_SELECTOR
name|CipherSuite
decl_stmt|;
comment|//
comment|// Indicates the direction for which the keys are to be installed.
comment|//
name|EFI_SUPPLICANT_KEY_DIRECTION
name|Direction
decl_stmt|;
block|}
name|EFI_SUPPLICANT_KEY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_GTK_LIST
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Indicates the number of GTKs that are contained in GTKList.
comment|//
name|UINT8
name|GTKCount
decl_stmt|;
comment|//
comment|// A variable-length array of GTKs of type EFI_SUPPLICANT_KEY. The number of
comment|// entries is specified by GTKCount.
comment|//
name|EFI_SUPPLICANT_KEY
name|GTKList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_SUPPLICANT_GTK_LIST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SUPPLICANT_FRAGMENT_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Length of data buffer in the fragment.
comment|//
name|UINT32
name|FragmentLength
decl_stmt|;
comment|//
comment|// Pointer to the data buffer in the fragment.
comment|//
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
block|}
name|EFI_SUPPLICANT_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|/**   BuildResponsePacket() is called during STA and AP authentication is in   progress. Supplicant derives the PTK or session keys depend on type of   authentication is being employed.    @param[in]       This           Pointer to the EFI_SUPPLICANT_PROTOCOL                                   instance.   @param[in]       RequestBuffer  Pointer to the most recently received EAPOL                                   packet. NULL means the supplicant need                                   initiate the EAP authentication session and                                   send EAPOL-Start message.   @param[in]       RequestBufferSize                                   Packet size in bytes for the most recently                                   received EAPOL packet. 0 is only valid when                                   RequestBuffer is NULL.   @param[out]      Buffer         Pointer to the buffer to hold the built                                   packet.   @param[in, out]  BufferSize     Pointer to the buffer size in bytes. On                                   input, it is the buffer size provided by the                                   caller. On output, it is the buffer size in                                   fact needed to contain the packet.    @retval EFI_SUCCESS             The required EAPOL packet is built                                   successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   RequestBuffer is NULL, but RequestSize is                                   NOT 0.                                   RequestBufferSize is 0.                                   Buffer is NULL, but RequestBuffer is NOT 0.                                   BufferSize is NULL.   @retval EFI_BUFFER_TOO_SMALL    BufferSize is too small to hold the response                                   packet.   @retval EFI_NOT_READY           Current EAPOL session state is NOT ready to                                   build ResponsePacket.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SUPPLICANT_BUILD_RESPONSE_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_SUPPLICANT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
modifier|*
name|RequestBuffer
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|RequestBufferSize
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   ProcessPacket() is called to Supplicant driver to encrypt or decrypt the data   depending type of authentication type.    @param[in]       This           Pointer to the EFI_SUPPLICANT_PROTOCOL                                   instance.   @param[in, out]  FragmentTable  Pointer to a list of fragment. The caller                                   will take responsible to handle the original                                   FragmentTable while it may be reallocated in                                   Supplicant driver.   @param[in]       FragmentCount  Number of fragment.   @param[in]       CryptMode      Crypt mode.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   FragmentTable is NULL.                                   FragmentCount is NULL.                                   CryptMode is invalid.   @retval EFI_NOT_READY           Current supplicant state is NOT Authenticated.   @retval EFI_ABORTED             Something wrong decryption the message.   @retval EFI_UNSUPPORTED         This API is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SUPPLICANT_PROCESS_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_SUPPLICANT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_SUPPLICANT_FRAGMENT_DATA
modifier|*
modifier|*
name|FragmentTable
parameter_list|,
name|IN
name|UINT32
modifier|*
name|FragmentCount
parameter_list|,
name|IN
name|EFI_SUPPLICANT_CRYPT_MODE
name|CryptMode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set Supplicant configuration data.    @param[in]  This                Pointer to the EFI_SUPPLICANT_PROTOCOL                                   instance.   @param[in]  DataType            The type of data.   @param[in]  Data                Pointer to the buffer to hold the data.   @param[in]  DataSize            Pointer to the buffer size in bytes.    @retval EFI_SUCCESS             The Supplicant configuration data is set                                   successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   Data is NULL.                                   DataSize is 0.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SUPPLICANT_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SUPPLICANT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SUPPLICANT_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get Supplicant configuration data.    @param[in]       This           Pointer to the EFI_SUPPLICANT_PROTOCOL                                   instance.   @param[in]       DataType       The type of data.   @param[out]      Data           Pointer to the buffer to hold the data.                                   Ignored if DataSize is 0.   @param[in, out]  DataSize       Pointer to the buffer size in bytes. On                                   input, it is the buffer size provided by the                                   caller. On output, it is the buffer size in                                   fact needed to contain the packet.    @retval EFI_SUCCESS             The Supplicant configuration data is got                                   successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is                                   TRUE:                                   This is NULL.                                   DataSize is NULL.                                   Data is NULL if *DataSize is not zero.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_NOT_FOUND           The Supplicant configuration data is not                                   found.   @retval EFI_BUFFER_TOO_SMALL    The size of Data is too small for the                                   specified configuration data and the required                                   size is returned in DataSize.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SUPPLICANT_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SUPPLICANT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SUPPLICANT_DATA_TYPE
name|DataType
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Data
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SUPPLICANT_PROTOCOL is designed to provide unified place for WIFI
end_comment

begin_comment
comment|/// and EAP security management. Both PSK authentication and 802.1X EAP
end_comment

begin_comment
comment|/// authentication can be managed via this protocol and driver or application
end_comment

begin_comment
comment|/// as a consumer can only focus on about packet transmitting or receiving.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SUPPLICANT_PROTOCOL
block|{
name|EFI_SUPPLICANT_BUILD_RESPONSE_PACKET
name|BuildResponsePacket
decl_stmt|;
name|EFI_SUPPLICANT_PROCESS_PACKET
name|ProcessPacket
decl_stmt|;
name|EFI_SUPPLICANT_SET_DATA
name|SetData
decl_stmt|;
name|EFI_SUPPLICANT_GET_DATA
name|GetData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSupplicantServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSupplicantProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

