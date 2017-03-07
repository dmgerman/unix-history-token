begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides a definition of the EFI IPv4 Configuration   Protocol.  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.      @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IP4CONFIG_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IP4CONFIG_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip4.h>
end_include

begin_define
define|#
directive|define
name|EFI_IP4_CONFIG_PROTOCOL_GUID
define|\
value|{ \     0x3b95aa31, 0x3793, 0x434b, {0x86, 0x67, 0xc8, 0x07, 0x08, 0x92, 0xe0, 0x5e } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IP4_CONFIG_PROTOCOL
name|EFI_IP4_CONFIG_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IP4_CONFIG_VARIABLE_ATTRIBUTES
define|\
value|(EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP4_IPCONFIG_DATA contains the minimum IPv4 configuration data
end_comment

begin_comment
comment|/// that is needed to start basic network communication. The StationAddress
end_comment

begin_comment
comment|/// and SubnetMask must be a valid unicast IP address and subnet mask.
end_comment

begin_comment
comment|/// If RouteTableSize is not zero, then RouteTable contains a properly
end_comment

begin_comment
comment|/// formatted routing table for the StationAddress/SubnetMask, with the
end_comment

begin_comment
comment|/// last entry in the table being the default route.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Default station IP address, stored in network byte order.
comment|///
name|EFI_IPv4_ADDRESS
name|StationAddress
decl_stmt|;
comment|///
comment|/// Default subnet mask, stored in network byte order.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// Number of entries in the following RouteTable. May be zero.
comment|///
name|UINT32
name|RouteTableSize
decl_stmt|;
comment|///
comment|/// Default routing table data (stored in network byte order).
comment|/// Ignored if RouteTableSize is zero.
comment|///
name|EFI_IP4_ROUTE_TABLE
modifier|*
name|RouteTable
decl_stmt|;
block|}
name|EFI_IP4_IPCONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Starts running the configuration policy for the EFI IPv4 Protocol driver.      The Start() function is called to determine and to begin the platform    configuration policy by the EFI IPv4 Protocol driver. This determination may    be as simple as returning EFI_UNSUPPORTED if there is no EFI IPv4 Protocol    driver configuration policy. It may be as involved as loading some defaults    from nonvolatile storage, downloading dynamic data from a DHCP server, and    checking permissions with a site policy server.   Starting the configuration policy is just the beginning. It may finish almost    instantly or it may take several minutes before it fails to retrieve configuration    information from one or more servers. Once the policy is started, drivers    should use the DoneEvent parameter to determine when the configuration policy    has completed. EFI_IP4_CONFIG_PROTOCOL.GetData() must then be called to    determine if the configuration succeeded or failed.   Until the configuration completes successfully, EFI IPv4 Protocol driver instances    that are attempting to use default configurations must return EFI_NO_MAPPING.   Once the configuration is complete, the EFI IPv4 Configuration Protocol driver    signals DoneEvent. The configuration may need to be updated in the future.    Note that in this case the EFI IPv4 Configuration Protocol driver must signal    ReconfigEvent, and all EFI IPv4 Protocol driver instances that are using default    configurations must return EFI_NO_MAPPING until the configuration policy has    been rerun.    @param  This                   The pointer to the EFI_IP4_CONFIG_PROTOCOL instance.   @param  DoneEvent              Event that will be signaled when the EFI IPv4                                   Protocol driver configuration policy completes                                   execution. This event must be of type EVT_NOTIFY_SIGNAL.   @param  ReconfigEvent          Event that will be signaled when the EFI IPv4                                   Protocol driver configuration needs to be updated.                                   This event must be of type EVT_NOTIFY_SIGNAL.      @retval EFI_SUCCESS            The configuration policy for the EFI IPv4 Protocol                                   driver is now running.   @retval EFI_INVALID_PARAMETER  One or more of the following parameters is NULL:                                   This                                   DoneEvent                                   ReconfigEvent   @retval EFI_OUT_OF_RESOURCES   Required system resources could not be allocated.   @retval EFI_ALREADY_STARTED    The configuration policy for the EFI IPv4 Protocol                                   driver was already started.   @retval EFI_DEVICE_ERROR       An unexpected system error or network error occurred.   @retval EFI_UNSUPPORTED        This interface does not support the EFI IPv4 Protocol                                   driver configuration.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG_START
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EVENT
name|DoneEvent
parameter_list|,
name|IN
name|EFI_EVENT
name|ReconfigEvent
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Stops running the configuration policy for the EFI IPv4 Protocol driver.      The Stop() function stops the configuration policy for the EFI IPv4 Protocol driver.    All configuration data will be lost after calling Stop().    @param  This                   The pointer to the EFI_IP4_CONFIG_PROTOCOL instance.    @retval EFI_SUCCESS            The configuration policy for the EFI IPv4 Protocol                                   driver has been stopped.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_STARTED        The configuration policy for the EFI IPv4 Protocol                                   driver was not started.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the default configuration data (if any) for the EFI IPv4 Protocol driver.    The GetData() function returns the current configuration data for the EFI IPv4    Protocol driver after the configuration policy has completed.      @param  This                   The pointer to the EFI_IP4_CONFIG_PROTOCOL instance.   @param  IpConfigDataSize       On input, the size of the IpConfigData buffer.                                   On output, the count of bytes that were written                                   into the IpConfigData buffer.   @param  IpConfigData           The pointer to the EFI IPv4 Configuration Protocol                                   driver configuration data structure.                                   Type EFI_IP4_IPCONFIG_DATA is defined in                                   "Related Definitions" below.    @retval EFI_SUCCESS            The EFI IPv4 Protocol driver configuration has been returned.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_STARTED        The configuration policy for the EFI IPv4 Protocol                                   driver is not running.   @retval EFI_NOT_READY EFI      IPv4 Protocol driver configuration is still running.   @retval EFI_ABORTED EFI        IPv4 Protocol driver configuration could not complete.   @retval EFI_BUFFER_TOO_SMALL   *IpConfigDataSize is smaller than the configuration                                   data buffer or IpConfigData is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP4_CONFIG_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP4_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|IpConfigDataSize
parameter_list|,
name|OUT
name|EFI_IP4_IPCONFIG_DATA
modifier|*
name|IpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_IP4_CONFIG_PROTOCOL driver performs platform-dependent and policy-dependent
end_comment

begin_comment
comment|/// configurations for the EFI IPv4 Protocol driver.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IP4_CONFIG_PROTOCOL
block|{
name|EFI_IP4_CONFIG_START
name|Start
decl_stmt|;
name|EFI_IP4_CONFIG_STOP
name|Stop
decl_stmt|;
name|EFI_IP4_CONFIG_GET_DATA
name|GetData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIp4ConfigProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

