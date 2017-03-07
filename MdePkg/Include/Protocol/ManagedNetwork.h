begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_MANAGED_NETWORK_SERVICE_BINDING_PROTOCOL as defined in UEFI 2.0.   EFI_MANAGED_NETWORK_PROTOCOL as defined in UEFI 2.0.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.0  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_MANAGED_NETWORK_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_MANAGED_NETWORK_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/SimpleNetwork.h>
end_include

begin_define
define|#
directive|define
name|EFI_MANAGED_NETWORK_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xf36ff770, 0xa7e1, 0x42cf, {0x9e, 0xd2, 0x56, 0xf0, 0xf2, 0x71, 0xf4, 0x4c } \   }
end_define

begin_define
define|#
directive|define
name|EFI_MANAGED_NETWORK_PROTOCOL_GUID
define|\
value|{ \     0x7ab33a91, 0xace5, 0x4326, { 0xb5, 0x72, 0xe7, 0xee, 0x33, 0xd3, 0x9f, 0x16 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_MANAGED_NETWORK_PROTOCOL
name|EFI_MANAGED_NETWORK_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Timeout value for a UEFI one-shot timer event. A packet that has not been removed
comment|/// from the MNP receive queue will be dropped if its receive timeout expires.
comment|///
name|UINT32
name|ReceivedQueueTimeoutValue
decl_stmt|;
comment|///
comment|/// Timeout value for a UEFI one-shot timer event. A packet that has not been removed
comment|/// from the MNP transmit queue will be dropped if its receive timeout expires.
comment|///
name|UINT32
name|TransmitQueueTimeoutValue
decl_stmt|;
comment|///
comment|/// Ethernet type II 16-bit protocol type in host byte order. Valid
comment|/// values are zero and 1,500 to 65,535.
comment|///
name|UINT16
name|ProtocolTypeFilter
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive packets that are sent to the network
comment|/// device MAC address. The startup default value is FALSE.
comment|///
name|BOOLEAN
name|EnableUnicastReceive
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive packets that are sent to any of the
comment|/// active multicast groups. The startup default value is FALSE.
comment|///
name|BOOLEAN
name|EnableMulticastReceive
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive packets that are sent to the network
comment|/// device broadcast address. The startup default value is FALSE.
comment|///
name|BOOLEAN
name|EnableBroadcastReceive
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive packets that are sent to any MAC address.
comment|/// The startup default value is FALSE.
comment|///
name|BOOLEAN
name|EnablePromiscuousReceive
decl_stmt|;
comment|///
comment|/// Set to TRUE to drop queued packets when the configuration
comment|/// is changed. The startup default value is FALSE.
comment|///
name|BOOLEAN
name|FlushQueuesOnReset
decl_stmt|;
comment|///
comment|/// Set to TRUE to timestamp all packets when they are received
comment|/// by the MNP. Note that timestamps may be unsupported in some
comment|/// MNP implementations. The startup default value is FALSE.
comment|///
name|BOOLEAN
name|EnableReceiveTimestamps
decl_stmt|;
comment|///
comment|/// Set to TRUE to disable background polling in this MNP
comment|/// instance. Note that background polling may not be supported in
comment|/// all MNP implementations. The startup default value is FALSE,
comment|/// unless background polling is not supported.
comment|///
name|BOOLEAN
name|DisableBackgroundPolling
decl_stmt|;
block|}
name|EFI_MANAGED_NETWORK_CONFIG_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TIME
name|Timestamp
decl_stmt|;
name|EFI_EVENT
name|RecycleEvent
decl_stmt|;
name|UINT32
name|PacketLength
decl_stmt|;
name|UINT32
name|HeaderLength
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|BOOLEAN
name|BroadcastFlag
decl_stmt|;
name|BOOLEAN
name|MulticastFlag
decl_stmt|;
name|BOOLEAN
name|PromiscuousFlag
decl_stmt|;
name|UINT16
name|ProtocolType
decl_stmt|;
name|VOID
modifier|*
name|DestinationAddress
decl_stmt|;
name|VOID
modifier|*
name|SourceAddress
decl_stmt|;
name|VOID
modifier|*
name|MediaHeader
decl_stmt|;
name|VOID
modifier|*
name|PacketData
decl_stmt|;
block|}
name|EFI_MANAGED_NETWORK_RECEIVE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|FragmentLength
decl_stmt|;
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
block|}
name|EFI_MANAGED_NETWORK_FRAGMENT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_MAC_ADDRESS
modifier|*
name|DestinationAddress
decl_stmt|;
comment|//OPTIONAL
name|EFI_MAC_ADDRESS
modifier|*
name|SourceAddress
decl_stmt|;
comment|//OPTIONAL
name|UINT16
name|ProtocolType
decl_stmt|;
comment|//OPTIONAL
name|UINT32
name|DataLength
decl_stmt|;
name|UINT16
name|HeaderLength
decl_stmt|;
comment|//OPTIONAL
name|UINT16
name|FragmentCount
decl_stmt|;
name|EFI_MANAGED_NETWORK_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MANAGED_NETWORK_TRANSMIT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated
comment|/// by the MNP. The type of Event must be
comment|/// EFI_NOTIFY_SIGNAL. The Task Priority Level (TPL) of
comment|/// Event must be lower than or equal to TPL_CALLBACK.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// The status that is returned to the caller at the end of the operation
comment|/// to indicate whether this operation completed successfully.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
union|union
block|{
comment|///
comment|/// When this token is used for receiving, RxData is a pointer to the EFI_MANAGED_NETWORK_RECEIVE_DATA.
comment|///
name|EFI_MANAGED_NETWORK_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
comment|///
comment|/// When this token is used for transmitting, TxData is a pointer to the EFI_MANAGED_NETWORK_TRANSMIT_DATA.
comment|///
name|EFI_MANAGED_NETWORK_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_MANAGED_NETWORK_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Returns the operational parameters for the current MNP child driver.    @param  This          The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  MnpConfigData The pointer to storage for MNP operational parameters.   @param  SnpModeData   The pointer to storage for SNP operational parameters.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_UNSUPPORTED       The requested feature is unsupported in this MNP implementation.   @retval EFI_NOT_STARTED       This MNP child driver instance has not been configured. The default                                 values are returned in MnpConfigData if it is not NULL.   @retval Other                 The mode data could not be read.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_MANAGED_NETWORK_CONFIG_DATA
modifier|*
name|MnpConfigData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_SIMPLE_NETWORK_MODE
modifier|*
name|SnpModeData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets or clears the operational parameters for the MNP child driver.    @param  This          The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  MnpConfigData The pointer to configuration data that will be assigned to the MNP                         child driver instance. If NULL, the MNP child driver instance is                         reset to startup defaults and all pending transmit and receive                         requests are flushed.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  Required system resources (usually memory) could not be                                 allocated.   @retval EFI_UNSUPPORTED       The requested feature is unsupported in this [MNP]                                 implementation.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval Other                 The MNP child driver instance has been reset to startup defaults.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MANAGED_NETWORK_CONFIG_DATA
modifier|*
name|MnpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Translates an IP multicast address to a hardware (MAC) multicast address.    @param  This       The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  Ipv6Flag   Set to TRUE to if IpAddress is an IPv6 multicast address.                      Set to FALSE if IpAddress is an IPv4 multicast address.   @param  IpAddress  The pointer to the multicast IP address (in network byte order) to convert.   @param  MacAddress The pointer to the resulting multicast MAC address.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_INVALID_PARAMETER One of the following conditions is TRUE:                                 - This is NULL.                                 - IpAddress is NULL.                                 - *IpAddress is not a valid multicast IP address.                                 - MacAddress is NULL.   @retval EFI_NOT_STARTED       This MNP child driver instance has not been configured.   @retval EFI_UNSUPPORTED       The requested feature is unsupported in this MNP implementation.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval Other                 The address could not be converted.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_MCAST_IP_TO_MAC
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Ipv6Flag
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|IpAddress
parameter_list|,
name|OUT
name|EFI_MAC_ADDRESS
modifier|*
name|MacAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enables and disables receive filters for multicast address.    @param  This       The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  JoinFlag   Set to TRUE to join this multicast group.                      Set to FALSE to leave this multicast group.   @param  MacAddress The pointer to the multicast MAC group (address) to join or leave.    @retval EFI_SUCCESS           The requested operation completed successfully.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - JoinFlag is TRUE and MacAddress is NULL.                                 - *MacAddress is not a valid multicast MAC address.   @retval EFI_NOT_STARTED       This MNP child driver instance has not been configured.   @retval EFI_ALREADY_STARTED   The supplied multicast group is already joined.   @retval EFI_NOT_FOUND         The supplied multicast group is not joined.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_UNSUPPORTED       The requested feature is unsupported in this MNP implementation.   @retval Other                 The requested operation could not be completed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_GROUPS
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|JoinFlag
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|MacAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places asynchronous outgoing data packets into the transmit queue.    @param  This  The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  Token The pointer to a token associated with the transmit data descriptor.    @retval EFI_SUCCESS           The transmit completion token was cached.   @retval EFI_NOT_STARTED       This MNP child driver instance has not been configured.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_ACCESS_DENIED     The transmit completion token is already in the transmit queue.   @retval EFI_OUT_OF_RESOURCES  The transmit data could not be queued due to a lack of system resources                                 (usually memory).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval EFI_NOT_READY         The transmit request could not be queued because the transmit queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MANAGED_NETWORK_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places an asynchronous receiving request into the receiving queue.    @param  This  The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  Token The pointer to a token associated with the receive data descriptor.    @retval EFI_SUCCESS           The receive completion token was cached.   @retval EFI_NOT_STARTED       This MNP child driver instance has not been configured.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - Token is NULL.                                 - Token.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  The transmit data could not be queued due to a lack of system resources                                 (usually memory).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval EFI_ACCESS_DENIED     The receive completion token was already in the receive queue.   @retval EFI_NOT_READY         The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MANAGED_NETWORK_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Aborts an asynchronous transmit or receive request.    @param  This  The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.   @param  Token The pointer to a token that has been issued by                 EFI_MANAGED_NETWORK_PROTOCOL.Transmit() or                 EFI_MANAGED_NETWORK_PROTOCOL.Receive(). If                 NULL, all pending tokens are aborted.    @retval  EFI_SUCCESS           The asynchronous I/O request was aborted and Token.Event                                  was signaled. When Token is NULL, all pending requests were                                  aborted and their events were signaled.   @retval  EFI_NOT_STARTED       This MNP child driver instance has not been configured.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_NOT_FOUND         When Token is not NULL, the asynchronous I/O request was                                  not found in the transmit or receive queue. It has either completed                                  or was not issued by Transmit() and Receive().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MANAGED_NETWORK_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    @param  This The pointer to the EFI_MANAGED_NETWORK_PROTOCOL instance.    @retval EFI_SUCCESS      Incoming or outgoing data was processed.   @retval EFI_NOT_STARTED  This MNP child driver instance has not been configured.   @retval EFI_DEVICE_ERROR An unexpected system or network error occurred.   @retval EFI_NOT_READY    No incoming or outgoing data was processed. Consider increasing                            the polling rate.   @retval EFI_TIMEOUT      Data was dropped out of the transmit and/or receive queue.                             Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MANAGED_NETWORK_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_MANAGED_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The MNP is used by network applications (and drivers) to
end_comment

begin_comment
comment|/// perform raw (unformatted) asynchronous network packet I/O.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_MANAGED_NETWORK_PROTOCOL
block|{
name|EFI_MANAGED_NETWORK_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_MANAGED_NETWORK_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_MANAGED_NETWORK_MCAST_IP_TO_MAC
name|McastIpToMac
decl_stmt|;
name|EFI_MANAGED_NETWORK_GROUPS
name|Groups
decl_stmt|;
name|EFI_MANAGED_NETWORK_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_MANAGED_NETWORK_RECEIVE
name|Receive
decl_stmt|;
name|EFI_MANAGED_NETWORK_CANCEL
name|Cancel
decl_stmt|;
name|EFI_MANAGED_NETWORK_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiManagedNetworkServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiManagedNetworkProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

