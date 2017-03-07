begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Adapter Information Protocol definition.   The EFI Adapter Information Protocol is used to dynamically and quickly discover   or set device information for an adapter.    Copyright (c) 2014 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.4  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_ADAPTER_INFORMATION_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_ADAPTER_INFORMATION_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_ADAPTER_INFORMATION_PROTOCOL_GUID
define|\
value|{ \     0xE5DD1403, 0xD622, 0xC24E, {0x84, 0x88, 0xC7, 0x1B, 0x17, 0xF5, 0xE8, 0x02 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ADAPTER_INFO_MEDIA_STATE_GUID
define|\
value|{ \     0xD7C74207, 0xA831, 0x4A26, {0xB1, 0xF5, 0xD1, 0x93, 0x06, 0x5C, 0xE8, 0xB6 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ADAPTER_INFO_NETWORK_BOOT_GUID
define|\
value|{ \     0x1FBD2960, 0x4130, 0x41E5, {0x94, 0xAC, 0xD2, 0xCF, 0x03, 0x7F, 0xB3, 0x7C } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ADAPTER_INFO_SAN_MAC_ADDRESS_GUID
define|\
value|{ \     0x114da5ef, 0x2cf1, 0x4e12, {0x9b, 0xbb, 0xc4, 0x70, 0xb5, 0x52, 0x5, 0xd9 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ADAPTER_INFO_UNDI_IPV6_SUPPORT_GUID
define|\
value|{ \     0x4bd56be3, 0x4975, 0x4d8a, {0xa0, 0xad, 0xc4, 0x91, 0x20, 0x4b, 0x5d, 0x4d} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ADAPTER_INFORMATION_PROTOCOL
name|EFI_ADAPTER_INFORMATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ADAPTER_INFO_MEDIA_STATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Returns the current media state status. MediaState can have any of the following values:
comment|/// EFI_SUCCESS: There is media attached to the network adapter. EFI_NOT_READY: This detects a bounced state.
comment|/// There was media attached to the network adapter, but it was removed and reattached. EFI_NO_MEDIA: There is
comment|/// not any media attached to the network.
comment|///
name|EFI_STATUS
name|MediaState
decl_stmt|;
block|}
name|EFI_ADAPTER_INFO_MEDIA_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ADAPTER_INFO_NETWORK_BOOT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// TRUE if the adapter supports booting from iSCSI IPv4 targets.
comment|///
name|BOOLEAN
name|iScsiIpv4BootCapablity
decl_stmt|;
comment|///
comment|/// TRUE if the adapter supports booting from iSCSI IPv6 targets.
comment|///
name|BOOLEAN
name|iScsiIpv6BootCapablity
decl_stmt|;
comment|///
comment|/// TRUE if the adapter supports booting from FCoE targets.
comment|///
name|BOOLEAN
name|FCoeBootCapablity
decl_stmt|;
comment|///
comment|/// TRUE if the adapter supports an offload engine (such as TCP
comment|/// Offload Engine (TOE)) for its iSCSI or FCoE boot operations.
comment|///
name|BOOLEAN
name|OffloadCapability
decl_stmt|;
comment|///
comment|/// TRUE if the adapter supports multipath I/O (MPIO) for its iSCSI
comment|/// boot operations.
comment|///
name|BOOLEAN
name|iScsiMpioCapability
decl_stmt|;
comment|///
comment|/// TRUE if the adapter is currently configured to boot from iSCSI
comment|/// IPv4 targets.
comment|///
name|BOOLEAN
name|iScsiIpv4Boot
decl_stmt|;
comment|///
comment|/// TRUE if the adapter is currently configured to boot from iSCSI
comment|/// IPv6 targets.
comment|///
name|BOOLEAN
name|iScsiIpv6Boot
decl_stmt|;
comment|///
comment|/// TRUE if the adapter is currently configured to boot from FCoE targets.
comment|///
name|BOOLEAN
name|FCoeBoot
decl_stmt|;
block|}
name|EFI_ADAPTER_INFO_NETWORK_BOOT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ADAPTER_INFO_SAN_MAC_ADDRESS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Returns the SAN MAC address for the adapter.For adapters that support today's 802.3 ethernet
comment|/// networking and Fibre-Channel Over Ethernet (FCOE), this conveys the FCOE SAN MAC address from the adapter.
comment|///
name|EFI_MAC_ADDRESS
name|SanMacAddress
decl_stmt|;
block|}
name|EFI_ADAPTER_INFO_SAN_MAC_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ADAPTER_INFO_UNDI_IPV6_SUPPORT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Returns capability of UNDI to support IPv6 traffic.
comment|///
name|BOOLEAN
name|Ipv6Support
decl_stmt|;
block|}
name|EFI_ADAPTER_INFO_UNDI_IPV6_SUPPORT
typedef|;
end_typedef

begin_comment
comment|/**   Returns the current state information for the adapter.    This function returns information of type InformationType from the adapter.   If an adapter does not support the requested informational type, then   EFI_UNSUPPORTED is returned.     @param[in]  This                   A pointer to the EFI_ADAPTER_INFORMATION_PROTOCOL instance.   @param[in]  InformationType        A pointer to an EFI_GUID that defines the contents of InformationBlock.   @param[out] InforamtionBlock       The service returns a pointer to the buffer with the InformationBlock                                      structure which contains details about the data specific to InformationType.   @param[out] InforamtionBlockSize   The driver returns the size of the InformationBlock in bytes.    @retval EFI_SUCCESS                The InformationType information was retrieved.   @retval EFI_UNSUPPORTED            The InformationType is not known.   @retval EFI_DEVICE_ERROR           The device reported an error.   @retval EFI_OUT_OF_RESOURCES       The request could not be completed due to a lack of resources.   @retval EFI_INVALID_PARAMETER      This is NULL.    @retval EFI_INVALID_PARAMETER      InformationBlock is NULL.    @retval EFI_INVALID_PARAMETER      InformationBlockSize is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ADAPTER_INFO_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_ADAPTER_INFORMATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|InformationType
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|InformationBlock
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|InformationBlockSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets state information for an adapter.    This function sends information of type InformationType for an adapter.   If an adapter does not support the requested information type, then EFI_UNSUPPORTED   is returned.    @param[in]  This                   A pointer to the EFI_ADAPTER_INFORMATION_PROTOCOL instance.   @param[in]  InformationType        A pointer to an EFI_GUID that defines the contents of InformationBlock.   @param[in]  InforamtionBlock       A pointer to the InformationBlock structure which contains details                                      about the data specific to InformationType.   @param[in]  InforamtionBlockSize   The size of the InformationBlock in bytes.    @retval EFI_SUCCESS                The information was received and interpreted successfully.   @retval EFI_UNSUPPORTED            The InformationType is not known.   @retval EFI_DEVICE_ERROR           The device reported an error.   @retval EFI_INVALID_PARAMETER      This is NULL.   @retval EFI_INVALID_PARAMETER      InformationBlock is NULL.   @retval EFI_WRITE_PROTECTED        The InformationType cannot be modified using EFI_ADAPTER_INFO_SET_INFO().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ADAPTER_INFO_SET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_ADAPTER_INFORMATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|InformationType
parameter_list|,
name|IN
name|VOID
modifier|*
name|InformationBlock
parameter_list|,
name|IN
name|UINTN
name|InformationBlockSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get a list of supported information types for this instance of the protocol.    This function returns a list of InformationType GUIDs that are supported on an   adapter with this instance of EFI_ADAPTER_INFORMATION_PROTOCOL. The list is returned   in InfoTypesBuffer, and the number of GUID pointers in InfoTypesBuffer is returned in   InfoTypesBufferCount.    @param[in]  This                  A pointer to the EFI_ADAPTER_INFORMATION_PROTOCOL instance.   @param[out] InfoTypesBuffer       A pointer to the array of InformationType GUIDs that are supported                                     by This.   @param[out] InfoTypesBufferCount  A pointer to the number of GUIDs present in InfoTypesBuffer.    @retval EFI_SUCCESS               The list of information type GUIDs that are supported on this adapter was                                     returned in InfoTypesBuffer. The number of information type GUIDs was                                     returned in InfoTypesBufferCount.   @retval EFI_INVALID_PARAMETER     This is NULL.   @retval EFI_INVALID_PARAMETER     InfoTypesBuffer is NULL.   @retval EFI_INVALID_PARAMETER     InfoTypesBufferCount is NULL.   @retval EFI_OUT_OF_RESOURCES      There is not enough pool memory to store the results.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ADAPTER_INFO_GET_SUPPORTED_TYPES
function_decl|)
parameter_list|(
name|IN
name|EFI_ADAPTER_INFORMATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
modifier|*
name|InfoTypesBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|InfoTypesBufferCount
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ADAPTER_INFORMATION_PROTOCOL
end_comment

begin_comment
comment|/// The protocol for adapter provides the following services.
end_comment

begin_comment
comment|/// - Gets device state information from adapter.
end_comment

begin_comment
comment|/// - Sets device information for adapter.
end_comment

begin_comment
comment|/// - Gets a list of supported information types for this instance of the protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ADAPTER_INFORMATION_PROTOCOL
block|{
name|EFI_ADAPTER_INFO_GET_INFO
name|GetInformation
decl_stmt|;
name|EFI_ADAPTER_INFO_SET_INFO
name|SetInformation
decl_stmt|;
name|EFI_ADAPTER_INFO_GET_SUPPORTED_TYPES
name|GetSupportedTypes
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAdapterInformationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAdapterInfoMediaStateGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAdapterInfoNetworkBootGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAdapterInfoSanMacAddressGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAdapterInfoUndiIpv6SupportGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

