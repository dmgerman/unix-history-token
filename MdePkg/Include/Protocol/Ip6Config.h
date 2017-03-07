begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides a definition of the EFI IPv6 Configuration   Protocol.  Copyright (c) 2008 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at<BR> http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IP6CONFIG_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IP6CONFIG_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip6.h>
end_include

begin_define
define|#
directive|define
name|EFI_IP6_CONFIG_PROTOCOL_GUID
define|\
value|{ \     0x937fe521, 0x95ae, 0x4d1a, {0x89, 0x29, 0x48, 0xbc, 0xd9, 0x0a, 0xd3, 0x1a } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IP6_CONFIG_PROTOCOL
name|EFI_IP6_CONFIG_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The interface information of the communication
comment|/// device this EFI IPv6 Configuration Protocol instance manages.
comment|/// This type of data is read only.The corresponding Data is of type
comment|/// EFI_IP6_CONFIG_INTERFACE_INFO.
comment|///
name|Ip6ConfigDataTypeInterfaceInfo
block|,
comment|///
comment|/// The alternative interface ID for the
comment|/// communication device this EFI IPv6 Configuration Protocol
comment|/// instance manages if the link local IPv6 address generated from
comment|/// the interfaced ID based on the default source the EFI IPv6
comment|/// Protocol uses is a duplicate address. The length of the interface
comment|/// ID is 64 bit. The corresponding Data is of type
comment|/// EFI_IP6_CONFIG_INTERFACE_ID.
comment|///
name|Ip6ConfigDataTypeAltInterfaceId
block|,
comment|///
comment|/// The general configuration policy for the EFI IPv6 network
comment|/// stack running on the communication device this EFI IPv6
comment|/// Configuration Protocol instance manages. The policy will affect
comment|/// other configuration settings. The corresponding Data is of type
comment|/// EFI_IP6_CONFIG_POLICY.
comment|///
name|Ip6ConfigDataTypePolicy
block|,
comment|///
comment|/// The number of consecutive
comment|/// Neighbor Solicitation messages sent while performing Duplicate
comment|/// Address Detection on a tentative address. A value of zero
comment|/// indicates that Duplicate Address Detection will not be performed
comment|/// on tentative addresses. The corresponding Data is of type
comment|/// EFI_IP6_CONFIG_DUP_ADDR_DETECT_TRANSMITS.
comment|///
name|Ip6ConfigDataTypeDupAddrDetectTransmits
block|,
comment|///
comment|/// The station addresses set manually for the EFI
comment|/// IPv6 network stack. It is only configurable when the policy is
comment|/// Ip6ConfigPolicyManual. The corresponding Data is a
comment|/// pointer to an array of EFI_IPv6_ADDRESS instances.
comment|///
name|Ip6ConfigDataTypeManualAddress
block|,
comment|///
comment|/// The gateway addresses set manually for the EFI IPv6
comment|/// network stack running on the communication device this EFI
comment|/// IPv6 Configuration Protocol manages. It is not configurable when
comment|/// the policy is Ip6ConfigPolicyAutomatic. The gateway
comment|/// addresses must be unicast IPv6 addresses. The corresponding
comment|/// Data is a pointer to an array of EFI_IPv6_ADDRESS instances.
comment|///
name|Ip6ConfigDataTypeGateway
block|,
comment|///
comment|/// The DNS server list for the EFI IPv6 network stack
comment|/// running on the communication device this EFI IPv6
comment|/// Configuration Protocol manages. It is not configurable when the
comment|/// policy is Ip6ConfigPolicyAutomatic.The DNS server
comment|/// addresses must be unicast IPv6 addresses. The corresponding
comment|/// Data is a pointer to an array of EFI_IPv6_ADDRESS instances.
comment|///
name|Ip6ConfigDataTypeDnsServer
block|,
comment|///
comment|/// The number of this enumeration memebers.
comment|///
name|Ip6ConfigDataTypeMaximum
block|}
name|EFI_IP6_CONFIG_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_INTERFACE_INFO
end_comment

begin_comment
comment|/// describes the operational state of the interface this
end_comment

begin_comment
comment|/// EFI IPv6 Configuration Protocol instance manages.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The name of the interface. It is a NULL-terminated string.
comment|///
name|CHAR16
name|Name
index|[
literal|32
index|]
decl_stmt|;
comment|///
comment|/// The interface type of the network interface.
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
comment|/// Number of EFI_IP6_ADDRESS_INFO structures pointed to by AddressInfo.
comment|///
name|UINT32
name|AddressInfoCount
decl_stmt|;
comment|///
comment|/// Pointer to an array of EFI_IP6_ADDRESS_INFO instances
comment|/// which contain the local IPv6 addresses and the corresponding
comment|/// prefix length information. Set to NULL if AddressInfoCount
comment|/// is zero.
comment|///
name|EFI_IP6_ADDRESS_INFO
modifier|*
name|AddressInfo
decl_stmt|;
comment|///
comment|/// Number of route table entries in the following RouteTable.
comment|///
name|UINT32
name|RouteCount
decl_stmt|;
comment|///
comment|/// The route table of the IPv6 network stack runs on this interface.
comment|/// Set to NULL if RouteCount is zero.
comment|///
name|EFI_IP6_ROUTE_TABLE
modifier|*
name|RouteTable
decl_stmt|;
block|}
name|EFI_IP6_CONFIG_INTERFACE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_INTERFACE_ID
end_comment

begin_comment
comment|/// describes the 64-bit interface ID.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Id
index|[
literal|8
index|]
decl_stmt|;
block|}
name|EFI_IP6_CONFIG_INTERFACE_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_POLICY
end_comment

begin_comment
comment|/// defines the general configuration policy the EFI IPv6
end_comment

begin_comment
comment|/// Configuration Protocol supports.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Under this policy, the IpI6ConfigDataTypeManualAddress,
comment|/// Ip6ConfigDataTypeGateway and Ip6ConfigDataTypeDnsServer
comment|/// configuration data are required to be set manually.
comment|/// The EFI IPv6 Protocol will get all required configuration
comment|/// such as address, prefix and gateway settings from the EFI
comment|/// IPv6 Configuration protocol.
comment|///
name|Ip6ConfigPolicyManual
block|,
comment|///
comment|/// Under this policy, the IpI6ConfigDataTypeManualAddress,
comment|/// Ip6ConfigDataTypeGateway and Ip6ConfigDataTypeDnsServer
comment|/// configuration data are not allowed to set via SetData().
comment|/// All of these configurations are retrieved from some auto
comment|/// configuration mechanism.
comment|/// The EFI IPv6 Protocol will use the IPv6 stateless address
comment|/// autoconfiguration mechanism and/or the IPv6 stateful address
comment|/// autoconfiguration mechanism described in the related RFCs to
comment|/// get address and other configuration information
comment|///
name|Ip6ConfigPolicyAutomatic
block|}
name|EFI_IP6_CONFIG_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_DUP_ADDR_DETECT_TRANSMITS
end_comment

begin_comment
comment|/// describes the number of consecutive Neighbor Solicitation messages sent
end_comment

begin_comment
comment|/// while performing Duplicate Address Detection on a tentative address.
end_comment

begin_comment
comment|/// The default value for a newly detected communication device is 1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|DupAddrDetectTransmits
decl_stmt|;
comment|///< The number of consecutive Neighbor Solicitation messages sent.
block|}
name|EFI_IP6_CONFIG_DUP_ADDR_DETECT_TRANSMITS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_MANUAL_ADDRESS
end_comment

begin_comment
comment|/// is used to set the station address information for the EFI IPv6 network
end_comment

begin_comment
comment|/// stack manually when the policy is Ip6ConfigPolicyManual.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IPv6_ADDRESS
name|Address
decl_stmt|;
comment|///< The IPv6 unicast address.
name|BOOLEAN
name|IsAnycast
decl_stmt|;
comment|///< Set to TRUE if Address is anycast.
name|UINT8
name|PrefixLength
decl_stmt|;
comment|///< The length, in bits, of the prefix associated with this Address.
block|}
name|EFI_IP6_CONFIG_MANUAL_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/**   Set the configuration for the EFI IPv6 network stack running on the communication   device this EFI IPv6 Configuration Protocol instance manages.      This function is used to set the configuration data of type DataType for the EFI    IPv6 network stack running on the communication device this EFI IPv6 Configuration   Protocol instance manages.    The DataSize is used to calculate the count of structure instances in the Data for    some DataType that multiple structure instances are allowed.      This function is always non-blocking. When setting some type of configuration data,   an asynchronous process is invoked to check the correctness of the data, such as    doing Duplicate Address Detection on the manually set local IPv6 addresses.    EFI_NOT_READY is returned immediately to indicate that such an asynchronous process   is invoked and the process is not finished yet. The caller willing to get the result   of the asynchronous process is required to call RegisterDataNotify() to register an   event on the specified configuration data. Once the event is signaled, the caller    can call GetData() to get back the configuration data in order to know the result.   For other types of configuration data that do not require an asynchronous configuration    process, the result of the operation is immediately returned.    @param[in]     This           Pointer to the EFI_IP6_CONFIG_PROTOCOL instance.   @param[in]     DataType       The type of data to set.     @param[in]     DataSize       Size of the buffer pointed to by Data in bytes.   @param[in]     Data           The data buffer to set. The type of the data buffer is                                 associated with the DataType.      @retval EFI_SUCCESS           The specified configuration data for the EFI IPv6                                  network stack is set successfully.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.                                 - Data is NULL.                                 - One or more fields in Data do not match the requirement of the                                    data type indicated by DataType.    @retval EFI_WRITE_PROTECTED   The specified configuration data is read-only or the specified                                  configuration data can not be set under the current policy   @retval EFI_ACCESS_DENIED     Another set operation on the specified configuration                                  data is already in process.   @retval EFI_NOT_READY         An asynchronous process is invoked to set the specified                                 configuration data and the process is not finished yet.   @retval EFI_BAD_BUFFER_SIZE   The DataSize does not match the size of the type                                  indicated by DataType.   @retval EFI_UNSUPPORTED       This DataType is not supported.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR      An unexpected system error or network error occurred.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CONFIG_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_CONFIG_DATA_TYPE
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
comment|/**   Get the configuration data for the EFI IPv6 network stack running on the communication   device this EFI IPv6 Configuration Protocol instance manages.      This function returns the configuration data of type DataType for the EFI IPv6 network   stack running on the communication device this EFI IPv6 Configuration Protocol instance   manages.    The caller is responsible for allocating the buffer used to return the specified   configuration data and the required size will be returned to the caller if the size of   the buffer is too small.       EFI_NOT_READY is returned if the specified configuration data is not ready due to an    already in progress asynchronous configuration process. The caller can call RegisterDataNotify()   to register an event on the specified configuration data. Once the asynchronous configuration   process is finished, the event will be signaled and a subsequent GetData() call will return    the specified configuration data.    @param[in]     This           Pointer to the EFI_IP6_CONFIG_PROTOCOL instance.   @param[in]     DataType       The type of data to get.     @param[in,out] DataSize       On input, in bytes, the size of Data. On output, in bytes, the                                  size of buffer required to store the specified configuration data.   @param[in]     Data           The data buffer in which the configuration data is returned. The                                  type of the data buffer is associated with the DataType.      @retval EFI_SUCCESS           The specified configuration data is got successfully.   @retval EFI_INVALID_PARAMETER One or more of the followings are TRUE:                                 - This is NULL.                                 - DataSize is NULL.                                 - Data is NULL if *DataSize is not zero.   @retval EFI_BUFFER_TOO_SMALL  The size of Data is too small for the specified configuration data                                  and the required size is returned in DataSize.   @retval EFI_NOT_READY         The specified configuration data is not ready due to an already in                                  progress asynchronous configuration process.   @retval EFI_NOT_FOUND         The specified configuration data is not found.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CONFIG_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_CONFIG_DATA_TYPE
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
comment|/**   Register an event that is to be signaled whenever a configuration process on the specified   configuration data is done.      This function registers an event that is to be signaled whenever a configuration process   on the specified configuration data is done. An event can be registered for different DataType   simultaneously and the caller is responsible for determining which type of configuration data   causes the signaling of the event in such case.    @param[in]     This           Pointer to the EFI_IP6_CONFIG_PROTOCOL instance.   @param[in]     DataType       The type of data to unregister the event for.     @param[in]     Event          The event to register.       @retval EFI_SUCCESS           The notification event for the specified configuration data is                                  registered.   @retval EFI_INVALID_PARAMETER This is NULL or Event is NULL.   @retval EFI_UNSUPPORTED       The configuration data type specified by DataType is not                                  supported.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_ACCESS_DENIED     The Event is already registered for the DataType.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CONFIG_REGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove a previously registered event for the specified configuration data.      This function removes a previously registered event for the specified configuration data.    @param[in]     This           Pointer to the EFI_IP6_CONFIG_PROTOCOL instance.   @param[in]     DataType       The type of data to remove the previously registered event for.     @param[in]     Event          The event to unregister.      @retval EFI_SUCCESS           The event registered for the specified configuration data is removed.   @retval EFI_INVALID_PARAMETER This is NULL or Event is NULL.   @retval EFI_NOT_FOUND         The Event has not been registered for the specified                                  DataType.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CONFIG_UNREGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_CONFIG_DATA_TYPE
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
comment|/// The EFI_IP6_CONFIG_PROTOCOL provides the mechanism to set and get various
end_comment

begin_comment
comment|/// types of configurations for the EFI IPv6 network stack.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IP6_CONFIG_PROTOCOL
block|{
name|EFI_IP6_CONFIG_SET_DATA
name|SetData
decl_stmt|;
name|EFI_IP6_CONFIG_GET_DATA
name|GetData
decl_stmt|;
name|EFI_IP6_CONFIG_REGISTER_NOTIFY
name|RegisterDataNotify
decl_stmt|;
name|EFI_IP6_CONFIG_UNREGISTER_NOTIFY
name|UnregisterDataNotify
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIp6ConfigProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

