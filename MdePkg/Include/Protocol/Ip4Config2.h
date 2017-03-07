begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides a definition of the EFI IPv4 Configuration II   Protocol.  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at<BR> http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  @par Revision Reference: This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IP4CONFIG2_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IP4CONFIG2_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip4.h>
end_include

begin_define
define|#
directive|define
name|EFI_IP4_CONFIG2_PROTOCOL_GUID
define|\
value|{ \     0x5b446ed1, 0xe30b, 0x4faa, {0x87, 0x1a, 0x36, 0x54, 0xec, 0xa3, 0x60, 0x80 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IP4_CONFIG2_PROTOCOL
name|EFI_IP4_CONFIG2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_CONFIG2_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The interface information of the communication device this EFI
comment|/// IPv4 Configuration II Protocol instance manages. This type of
comment|/// data is read only. The corresponding Data is of type
comment|/// EFI_IP4_CONFIG2_INTERFACE_INFO.
comment|///
name|Ip4Config2DataTypeInterfaceInfo
block|,
comment|///
comment|/// The general configuration policy for the EFI IPv4 network stack
comment|/// running on the communication device this EFI IPv4
comment|/// Configuration II Protocol instance manages. The policy will
comment|/// affect other configuration settings. The corresponding Data is of
comment|/// type EFI_IP4_CONFIG2_POLICY.
comment|///
name|Ip4Config2DataTypePolicy
block|,
comment|///
comment|/// The station addresses set manually for the EFI IPv4 network
comment|/// stack. It is only configurable when the policy is
comment|/// Ip4Config2PolicyStatic. The corresponding Data is of
comment|/// type EFI_IP4_CONFIG2_MANUAL_ADDRESS.
comment|///
name|Ip4Config2DataTypeManualAddress
block|,
comment|///
comment|/// The gateway addresses set manually for the EFI IPv4 network
comment|/// stack running on the communication device this EFI IPv4
comment|/// Configuration II Protocol manages. It is not configurable when
comment|/// the policy is Ip4Config2PolicyDhcp. The gateway
comment|/// addresses must be unicast IPv4 addresses. The corresponding
comment|/// Data is a pointer to an array of EFI_IPv4_ADDRESS instances.
comment|///
name|Ip4Config2DataTypeGateway
block|,
comment|///
comment|/// The DNS server list for the EFI IPv4 network stack running on
comment|/// the communication device this EFI IPv4 Configuration II
comment|/// Protocol manages. It is not configurable when the policy is
comment|/// Ip4Config2PolicyDhcp. The DNS server addresses must be
comment|/// unicast IPv4 addresses. The corresponding Data is a pointer to
comment|/// an array of EFI_IPv4_ADDRESS instances.
comment|///
name|Ip4Config2DataTypeDnsServer
block|,
name|Ip4Config2DataTypeMaximum
block|}
name|EFI_IP4_CONFIG2_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_CONFIG2_INTERFACE_INFO related definitions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IP4_CONFIG2_INTERFACE_INFO_NAME_SIZE
value|32
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_CONFIG2_INTERFACE_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The name of the interface. It is a NULL-terminated Unicode string.
comment|///
name|CHAR16
name|Name
index|[
name|EFI_IP4_CONFIG2_INTERFACE_INFO_NAME_SIZE
index|]
decl_stmt|;
comment|///
comment|/// The interface type of the network interface. See RFC 1700,
comment|/// section "Number Hardware Type".
comment|///
name|UINT8
name|IfType
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the network interface's hardware address.
comment|///
name|UINT32
name|HwAddressSize
decl_stmt|;
comment|///
comment|/// The hardware address for the network interface.
comment|///
name|EFI_MAC_ADDRESS
name|HwAddress
decl_stmt|;
comment|///
comment|/// The station IPv4 address of this EFI IPv4 network stack.
comment|///
name|EFI_IPv4_ADDRESS
name|StationAddress
decl_stmt|;
comment|///
comment|/// The subnet address mask that is associated with the station address.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// Size of the following RouteTable, in bytes. May be zero.
comment|///
name|UINT32
name|RouteTableSize
decl_stmt|;
comment|///
comment|/// The route table of the IPv4 network stack runs on this interface.
comment|/// Set to NULL if RouteTableSize is zero. Type EFI_IP4_ROUTE_TABLE is defined in
comment|/// EFI_IP4_PROTOCOL.GetModeData().
comment|///
name|EFI_IP4_ROUTE_TABLE
modifier|*
name|RouteTable
name|OPTIONAL
decl_stmt|;
block|}
name|EFI_IP4_CONFIG2_INTERFACE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_CONFIG2_POLICY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Under this policy, the Ip4Config2DataTypeManualAddress,
comment|/// Ip4Config2DataTypeGateway and Ip4Config2DataTypeDnsServer configuration
comment|/// data are required to be set manually. The EFI IPv4 Protocol will get all
comment|/// required configuration such as IPv4 address, subnet mask and
comment|/// gateway settings from the EFI IPv4 Configuration II protocol.
comment|///
name|Ip4Config2PolicyStatic
block|,
comment|///
comment|/// Under this policy, the Ip4Config2DataTypeManualAddress,
comment|/// Ip4Config2DataTypeGateway and Ip4Config2DataTypeDnsServer configuration data are
comment|/// not allowed to set via SetData(). All of these configurations are retrieved from DHCP
comment|/// server or other auto-configuration mechanism.
comment|///
name|Ip4Config2PolicyDhcp
block|,
name|Ip4Config2PolicyMax
block|}
name|EFI_IP4_CONFIG2_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_CONFIG2_MANUAL_ADDRESS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The IPv4 unicast address.
comment|///
name|EFI_IPv4_ADDRESS
name|Address
decl_stmt|;
comment|///
comment|/// The subnet mask.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
block|}
name|EFI_IP4_CONFIG2_MANUAL_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/**   Set the configuration for the EFI IPv4 network stack running on the communication device this EFI    IPv4 Configuration II Protocol instance manages.    This function is used to set the configuration data of type DataType for the EFI IPv4 network stack    running on the communication device this EFI IPv4 Configuration II Protocol instance manages.   The successfully configured data is valid after system reset or power-off.   The DataSize is used to calculate the count of structure instances in the Data for some    DataType that multiple structure instances are allowed.   This function is always non-blocking. When setting some typeof configuration data, an    asynchronous process is invoked to check the correctness of the data, such as doing address conflict    detection on the manually set local IPv4 address. EFI_NOT_READY is returned immediately to    indicate that such an asynchronous process is invoked and the process is not finished yet. The caller    willing to get the result of the asynchronous process is required to call RegisterDataNotify()   to register an event on the specified configuration data. Once the event is signaled, the caller can call    GetData()to get back the configuration data in order to know the result. For other types of    configuration data that do not require an asynchronous configuration process, the result of the    operation is immediately returned.     @param[in]   This               Pointer to the EFI_IP4_CONFIG2_PROTOCOL instance.          @param[in]   DataType           The type of data to set.   @param[in]   DataSize           Size of the buffer pointed to by Data in bytes.   @param[in]   Data               The data buffer to set. The type ofthe data buffer is associated                                    with the DataType.     @retval EFI_SUCCESS             The specified configuration data for the EFI IPv4 network stack is set                                    successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following are TRUE:                                   This is NULL.                                   Data is NULL.                                   One or more fields in Data do not match the requirement of the data type                                    indicated by DataType.   @retval EFI_WRITE_PROTECTED     The specified configuration data is read-only or the specified configuration                                    data can not be set under the current policy.   @retval EFI_ACCESS_DENIED       Another set operation on the specified configuration data is already in process.   @retval EFI_NOT_READY           An asynchronous process is invoked to set the specified configuration data and                                    the process is not finished yet.   @retval EFI_BAD_BUFFER_SIZE     The DataSize does not match the size of the type indicated by DataType.                                    @retval EFI_UNSUPPORTED         This DataType is not supported.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR        An unexpected system error or network error occurred. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG2_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP4_CONFIG2_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the configuration data for the EFI IPv4 network stack running on the communication device this    EFI IPv4 Configuration II Protocol instance manages.    This function returns the configuration data of type DataType for the EFI IPv4 network stack    running on the communication device this EFI IPv4 Configuration II Protocol instance manages.   The caller is responsible for allocating the buffer usedto return the specified configuration data and    the required size will be returned to the caller if the size of the buffer is too small.   EFI_NOT_READY is returned if the specified configuration data is not ready due to an already in    progress asynchronous configuration process. The caller can call RegisterDataNotify() to    register an event on the specified configuration data. Once the asynchronous configuration process is    finished, the event will be signaled and a subsequent GetData() call will return the specified    configuration data.    @param[in]   This               Pointer to the EFI_IP4_CONFIG2_PROTOCOL instance.          @param[in]   DataType           The type of data to get.   @param[out]  DataSize           On input, in bytes, the size of Data. On output, in bytes, the size                                    of buffer required to store the specified configuration data.    @param[in]   Data               The data buffer in which the configuration data is returned. The                                    type of the data buffer is associated with the DataType. Ignored                                    if DataSize is 0.      @retval EFI_SUCCESS             The specified configuration data is got successfully.   @retval EFI_INVALID_PARAMETER   One or more of the followings are TRUE:                                   This is NULL.                                   DataSize is NULL.                                   Data is NULL if *DataSizeis not zero.   @retval EFI_BUFFER_TOO_SMALL    The size of Data is too small for the specified configuration data                                    and the required size is returned in DataSize.   @retval EFI_NOT_READY           The specified configuration data is not ready due to an already in                                    progress asynchronous configuration process.   @retval EFI_NOT_FOUND           The specified configuration data is not found. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG2_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP4_CONFIG2_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register an event that is to be signaled whenever a configuration process on the specified    configuration data is done.    This function registers an event that is to be signaled whenever a configuration process on the    specified configuration data is done. An event can be registered for different DataType   simultaneously and the caller is responsible for determining which type of configuration data causes    the signaling of the event in such case.    @param[in]   This               Pointer to the EFI_IP4_CONFIG2_PROTOCOL instance.          @param[in]   DataType           The type of data to unregister the event for.   @param[in]   Event              The event to register.    @retval EFI_SUCCESS             The notification event for the specified configuration data is                                    registered.   @retval EFI_INVALID_PARAMETER   This is NULL or Event is NULL.   @retval EFI_UNSUPPORTED         The configuration data type specified by DataType is not supported.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.   @retval EFI_ACCESS_DENIED       The Event is already registered for the DataType. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG2_REGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP4_CONFIG2_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove a previously registered event for the specified configuration data.    This function removes a previously registeredevent for the specified configuration data.    @param[in]   This               Pointer to the EFI_IP4_CONFIG2_PROTOCOL instance.          @param[in]   DataType           The type of data to remove the previously registered event for.   @param[in]   Event              The event to unregister.    @retval EFI_SUCCESS             The event registered for the specified configuration data is removed.   @retval EFI_INVALID_PARAMETER   This is NULL or Event is NULL.   @retval EFI_NOT_FOUND           The Eventhas not been registered for the specified DataType. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG2_UNREGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP4_CONFIG2_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_IP4_CONFIG2_PROTOCOL is designed to be the central repository for the common
end_comment

begin_comment
comment|/// configurations and the administrator configurable settings for the EFI IPv4 network stack.
end_comment

begin_comment
comment|/// An EFI IPv4 Configuration II Protocol instance will be installed on each communication device that
end_comment

begin_comment
comment|/// the EFI IPv4 network stack runs on.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IP4_CONFIG2_PROTOCOL
block|{
name|EFI_IP4_CONFIG2_SET_DATA
name|SetData
decl_stmt|;
name|EFI_IP4_CONFIG2_GET_DATA
name|GetData
decl_stmt|;
name|EFI_IP4_CONFIG2_REGISTER_NOTIFY
name|RegisterDataNotify
decl_stmt|;
name|EFI_IP4_CONFIG2_UNREGISTER_NOTIFY
name|UnregisterDataNotify
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIp4Config2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

