begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI Domain Name Service Binding Protocol interface. It is split   into the following two main sections:   DNSv4 Service Binding Protocol (DNSv4SB)   DNSv4 Protocol (DNSv4)    Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DNS4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DNS4_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_DNS4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xb625b186, 0xe063, 0x44f7, {0x89, 0x5, 0x6a, 0x74, 0xdc, 0x6f, 0x52, 0xb4 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_DNS4_PROTOCOL_GUID
define|\
value|{ \     0xae3d28cc, 0xe05b, 0x4fa1, {0xa0, 0x11, 0x7e, 0xb5, 0x5a, 0x3f, 0x14, 0x1 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DNS4_PROTOCOL
name|EFI_DNS4_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DNS4_CONFIG_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Count of the DNS servers. When used with GetModeData(),
comment|/// this field is the count of originally configured servers when
comment|/// Configure() was called for this instance. When used with
comment|/// Configure() this is the count of caller-supplied servers. If the
comment|/// DnsServerListCount is zero, the DNS server configuration
comment|/// will be retrieved from DHCP server automatically.
comment|///
name|UINTN
name|DnsServerListCount
decl_stmt|;
comment|///
comment|/// Pointer to DNS server list containing DnsServerListCount entries or NULL
comment|/// if DnsServerListCountis 0. For Configure(), this will be NULL when there are
comment|/// no caller supplied server addresses, and, the DNS instance will retrieve
comment|/// DNS server from DHCP Server. The provided DNS server list is
comment|/// recommended to be filled up in the sequence of preference. When
comment|/// used with GetModeData(), the buffer containing the list will
comment|/// be allocated by the driver implementing this protocol and must be
comment|/// freed by the caller. When used with Configure(), the buffer
comment|/// containing the list will be allocated and released by the caller.
comment|///
name|EFI_IPv4_ADDRESS
modifier|*
name|DnsServerList
decl_stmt|;
comment|///
comment|/// Set to TRUE to use the default IP address/subnet mask and default routing table.
comment|///
name|BOOLEAN
name|UseDefaultSetting
decl_stmt|;
comment|///
comment|/// If TRUE, enable DNS cache function for this DNS instance. If FALSE, all DNS
comment|/// query will not lookup local DNS cache.
comment|///
name|BOOLEAN
name|EnableDnsCache
decl_stmt|;
comment|///
comment|/// Use the protocol number defined in "Links to UEFI-Related
comment|/// Documents"(http://uefi.org/uefi) under the heading "IANA
comment|/// Protocol Numbers". Only TCP or UDP are supported, and other
comment|/// protocol values are invalid. An implementation can choose to
comment|/// support only UDP, or both TCP and UDP.
comment|///
name|UINT8
name|Protocol
decl_stmt|;
comment|///
comment|/// If UseDefaultSetting is FALSE indicates the station address to use.
comment|///
name|EFI_IPv4_ADDRESS
name|StationIp
decl_stmt|;
comment|///
comment|/// If UseDefaultSetting is FALSE indicates the subnet mask to use.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// Local port number. Set to zero to use the automatically assigned port number.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// Retry number if no response received after RetryInterval.
comment|///
name|UINT32
name|RetryCount
decl_stmt|;
comment|///
comment|/// Minimum interval of retry is 2 second. If the retry interval is less than 2
comment|/// seconds, then use the 2 seconds.
comment|///
name|UINT32
name|RetryInterval
decl_stmt|;
block|}
name|EFI_DNS4_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DNS4_CACHE_ENTRY
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Host name.
comment|///
name|CHAR16
modifier|*
name|HostName
decl_stmt|;
comment|///
comment|/// IP address of this host.
comment|///
name|EFI_IPv4_ADDRESS
modifier|*
name|IpAddress
decl_stmt|;
comment|///
comment|/// Time in second unit that this entry will remain in DNS cache. A value of zero
comment|/// means that this entry is permanent. A nonzero value will override the existing
comment|/// one if this entry to be added is dynamic entry. Implementations may set its
comment|/// default timeout value for the dynamically created DNS cache entry after one DNS
comment|/// resolve succeeds.
comment|///
name|UINT32
name|Timeout
decl_stmt|;
block|}
name|EFI_DNS4_CACHE_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DNS4_MODE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The configuration data of this instance.
comment|///
name|EFI_DNS4_CONFIG_DATA
name|DnsConfigData
decl_stmt|;
comment|///
comment|/// Number of configured DNS server. Each DNS instance has its own DNS server
comment|/// configuration.
comment|///
name|UINT32
name|DnsServerCount
decl_stmt|;
comment|///
comment|/// Pointer to common list of addresses of all configured DNS server
comment|/// used by EFI_DNS4_PROTOCOL instances. List will include
comment|/// DNS servers configured by this or any other EFI_DNS4_PROTOCOL instance.
comment|/// The storage for this list is allocated by the driver publishing this
comment|/// protocol, and must be freed by the caller.
comment|///
name|EFI_IPv4_ADDRESS
modifier|*
name|DnsServerList
decl_stmt|;
comment|///
comment|/// Number of DNS Cache entries. The DNS Cache is shared among all DNS instances.
comment|///
name|UINT32
name|DnsCacheCount
decl_stmt|;
comment|///
comment|/// Pointer to a buffer containing DnsCacheCount DNS Cache
comment|/// entry structures. The storage for this list is allocated by the driver
comment|/// publishing this protocol and must be freed by caller.
comment|///
name|EFI_DNS4_CACHE_ENTRY
modifier|*
name|DnsCacheList
decl_stmt|;
block|}
name|EFI_DNS4_MODE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DNS_HOST_TO_ADDR_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Number of the returned IP addresses.
comment|///
name|UINT32
name|IpCount
decl_stmt|;
comment|///
comment|/// Pointer to the all the returned IP addresses.
comment|///
name|EFI_IPv4_ADDRESS
modifier|*
name|IpList
decl_stmt|;
block|}
name|DNS_HOST_TO_ADDR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DNS_ADDR_TO_HOST_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Pointer to the primary name for this host address. It's the caller's
comment|/// responsibility to free the response memory.
comment|///
name|CHAR16
modifier|*
name|HostName
decl_stmt|;
block|}
name|DNS_ADDR_TO_HOST_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DNS_RESOURCE_RECORD
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Owner name.
comment|///
name|CHAR8
modifier|*
name|QName
decl_stmt|;
comment|///
comment|/// The Type Code of this RR.
comment|///
name|UINT16
name|QType
decl_stmt|;
comment|///
comment|/// The CLASS code of this RR.
comment|///
name|UINT16
name|QClass
decl_stmt|;
comment|///
comment|/// 32 bit integer which specify the time interval that the resource record may be
comment|/// cached before the source of the information should again be consulted. Zero means
comment|/// this RR can not be cached.
comment|///
name|UINT32
name|TTL
decl_stmt|;
comment|///
comment|/// 16 big integer which specify the length of RData.
comment|///
name|UINT16
name|DataLength
decl_stmt|;
comment|///
comment|/// A string of octets that describe the resource, the format of this information
comment|/// varies according to QType and QClass difference.
comment|///
name|CHAR8
modifier|*
name|RData
decl_stmt|;
block|}
name|DNS_RESOURCE_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DNS_GENERAL_LOOKUP_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Number of returned matching RRs.
comment|///
name|UINTN
name|RRCount
decl_stmt|;
comment|///
comment|/// Pointer to the all the returned matching RRs. It's caller responsibility to free
comment|/// the allocated memory to hold the returned RRs.
comment|///
name|DNS_RESOURCE_RECORD
modifier|*
name|RRList
decl_stmt|;
block|}
name|DNS_GENERAL_LOOKUP_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DNS4_COMPLETION_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI DNS
comment|/// protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   EFI_SUCCESS:      The host name to address translation completed successfully.
comment|///   EFI_NOT_FOUND:    No matching Resource Record (RR) is found.
comment|///   EFI_TIMEOUT:      No DNS server reachable, or RetryCount was exhausted without
comment|///                     response from all specified DNS servers.
comment|///   EFI_DEVICE_ERROR: An unexpected system or network error occurred.
comment|///   EFI_NO_MEDIA:     There was a media error.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Retry number if no response received after RetryInterval. If zero, use the
comment|/// parameter configured through Dns.Configure() interface.
comment|///
name|UINT32
name|RetryCount
decl_stmt|;
comment|///
comment|/// Minimum interval of retry is 2 second. If the retry interval is less than 2
comment|/// seconds, then use the 2 seconds. If zero, use the parameter configured through
comment|/// Dns.Configure() interface.
name|UINT32
name|RetryInterval
decl_stmt|;
comment|///
comment|/// DNSv4 completion token data
comment|///
union|union
block|{
comment|///
comment|/// When the Token is used for host name to address translation, H2AData is a pointer
comment|/// to the DNS_HOST_TO_ADDR_DATA.
comment|///
name|DNS_HOST_TO_ADDR_DATA
modifier|*
name|H2AData
decl_stmt|;
comment|///
comment|/// When the Token is used for host address to host name translation, A2HData is a
comment|/// pointer to the DNS_ADDR_TO_HOST_DATA.
comment|///
name|DNS_ADDR_TO_HOST_DATA
modifier|*
name|A2HData
decl_stmt|;
comment|///
comment|/// When the Token is used for a general lookup function, GLookupDATA is a pointer to
comment|/// the DNS_GENERAL_LOOKUP_DATA.
comment|///
name|DNS_GENERAL_LOOKUP_DATA
modifier|*
name|GLookupData
decl_stmt|;
block|}
name|RspData
union|;
block|}
name|EFI_DNS4_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Retrieve mode data of this DNS instance.    This function is used to retrieve DNS mode data for this DNS instance.    @param[in]   This               Pointer to EFI_DNS4_PROTOCOL instance.   @param[out]  DnsModeData        Point to the mode data.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_NOT_STARTED         When DnsConfigData is queried, no configuration data                                   is available because this instance has not been                                   configured.   @retval EFI_INVALID_PARAMETER   This is NULL or DnsModeData is NULL.   @retval EFI_OUT_OF_RESOURCES    Failed to allocate needed resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_DNS4_MODE_DATA
modifier|*
name|DnsModeData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Configure this DNS instance.    This function is used to configure DNS mode data for this DNS instance.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  DnsConfigData       Point to the Configuration data.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_UNSUPPORTED         The designated protocol is not supported.   @retval EFI_INVALID_PARAMETER   This is NULL.                                   The StationIp address provided in DnsConfigData is not a                                    valid unicast.                                   DnsServerList is NULL while DnsServerListCount                                   is not ZERO.                                   DnsServerListCount is ZERO while DnsServerList                                   is not NULL   @retval EFI_OUT_OF_RESOURCES    The DNS instance data or required space could not be                                   allocated.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred. The                                   EFI DNSv4 Protocol instance is not configured.   @retval EFI_ALREADY_STARTED     Second call to Configure() with DnsConfigData. To                                    reconfigure the instance the caller must call Configure()                                    with NULL first to return driver to unconfigured state. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DNS4_CONFIG_DATA
modifier|*
name|DnsConfigData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Host name to host address translation.    The HostNameToIp () function is used to translate the host name to host IP address. A   type A query is used to get the one or more IP addresses for this host.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  HostName            Host name.   @param[in]  Token               Point to the completion token to translate host name                                   to host address.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Token is NULL.                                   Token.Event is NULL.                                   HostName is NULL. HostName string is unsupported format.   @retval EFI_NO_MAPPING          There's no source address is available for use.   @retval EFI_NOT_STARTED         This instance has not been started. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_HOST_NAME_TO_IP
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|HostName
parameter_list|,
name|IN
name|EFI_DNS4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   IPv4 address to host name translation also known as Reverse DNS lookup.    The IpToHostName() function is used to translate the host address to host name. A type PTR    query is used to get the primary name of the host. Support of this function is optional.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  IpAddress           Ip Address.   @param[in]  Token               Point to the completion token to translate host                                   address to host name.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_UNSUPPORTED         This function is not supported.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Token is NULL.                                   Token.Event is NULL.                                   IpAddress is not valid IP address .   @retval EFI_NO_MAPPING          There's no source address is available for use.   @retval EFI_ALREADY_STARTED     This Token is being used in another DNS session.   @retval EFI_OUT_OF_RESOURCES    Failed to allocate needed resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_IP_TO_HOST_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPv4_ADDRESS
name|IpAddress
parameter_list|,
name|IN
name|EFI_DNS4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieve arbitrary information from the DNS server.     This GeneralLookup() function retrieves arbitrary information from the DNS. The caller   supplies a QNAME, QTYPE, and QCLASS, and all of the matching RRs are returned. All   RR content (e.g., TTL) was returned. The caller need parse the returned RR to get   required information. The function is optional.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  QName               Pointer to Query Name.   @param[in]  QType               Query Type.   @param[in]  QClass              Query Name.   @param[in]  Token               Point to the completion token to retrieve arbitrary                                   information.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_UNSUPPORTED         This function is not supported. Or the requested                                   QType is not supported   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Token is NULL.                                   Token.Event is NULL.                                   QName is NULL.   @retval EFI_NO_MAPPING          There's no source address is available for use.   @retval EFI_ALREADY_STARTED     This Token is being used in another DNS session.   @retval EFI_OUT_OF_RESOURCES    Failed to allocate needed resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_GENERAL_LOOKUP
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|QName
parameter_list|,
name|IN
name|UINT16
name|QType
parameter_list|,
name|IN
name|UINT16
name|QClass
parameter_list|,
name|IN
name|EFI_DNS4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function is to update the DNS Cache.    The UpdateDnsCache() function is used to add/delete/modify DNS cache entry. DNS cache   can be normally dynamically updated after the DNS resolve succeeds. This function   provided capability to manually add/delete/modify the DNS cache.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  DeleteFlag          If FALSE, this function is to add one entry to the                                   DNS Cahce. If TRUE, this function will delete                                   matching DNS Cache entry.   @param[in]  Override            If TRUE, the maching DNS cache entry will be                                   overwritten with the supplied parameter. If FALSE,                                   EFI_ACCESS_DENIED will be returned if the entry to                                   be added is already existed.   @param[in]  DnsCacheEntry       Pointer to DNS Cache entry.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   DnsCacheEntry.HostName is NULL.                                   DnsCacheEntry.IpAddress is NULL.                                   DnsCacheEntry.Timeout is zero.   @retval EFI_ACCESS_DENIED       The DNS cache entry already exists and Override is                                   not TRUE. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_UPDATE_DNS_CACHE
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|DeleteFlag
parameter_list|,
name|IN
name|BOOLEAN
name|Override
parameter_list|,
name|IN
name|EFI_DNS4_CACHE_ENTRY
name|DnsCacheEntry
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    The Poll() function can be used by network drivers and applications to increase the   rate that data packets are moved between the communications device and the transmit   and receive queues.   In some systems, the periodic timer event in the managed network driver may not poll   the underlying communications device fast enough to transmit and/or receive all data   packets without missing incoming packets or dropping outgoing packets. Drivers and   applications that are experiencing packet loss should try calling the Poll()   function more often.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.    @retval EFI_SUCCESS             Incoming or outgoing data was processed.   @retval EFI_NOT_STARTED         This EFI DNS Protocol instance has not been started.   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred.   @retval EFI_TIMEOUT             Data was dropped out of the transmit and/or receive                                   queue. Consider increasing the polling rate. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Abort an asynchronous DNS operation, including translation between IP and Host, and   general look up behavior.    The Cancel() function is used to abort a pending resolution request. After calling   this function, Token.Status will be set to EFI_ABORTED and then Token.Event will be   signaled. If the token is not in one of the queues, which usually means that the   asynchronous operation has completed, this function will not signal the token and   EFI_NOT_FOUND is returned.    @param[in]  This                Pointer to EFI_DNS4_PROTOCOL instance.   @param[in]  Token               Pointer to a token that has been issued by                                   EFI_DNS4_PROTOCOL.HostNameToIp (),                                   EFI_DNS4_PROTOCOL.IpToHostName() or                                   EFI_DNS4_PROTOCOL.GeneralLookup().                                   If NULL, all pending tokens are aborted.    @retval EFI_SUCCESS             Incoming or outgoing data was processed.   @retval EFI_NOT_STARTED         This EFI DNS4 Protocol instance has not been started.   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_NOT_FOUND           When Token is not NULL, and the asynchronous DNS                                   operation was not found in the transmit queue. It                                   was either completed or was not issued by                                   HostNameToIp(), IpToHostName() or GeneralLookup(). **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DNS4_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_DNS4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DNS4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_DNS4_Protocol provides the function to get the host name and address
end_comment

begin_comment
comment|/// mapping, also provides pass through interface to retrieve arbitrary information
end_comment

begin_comment
comment|/// from DNS.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DNS4_PROTOCOL
block|{
name|EFI_DNS4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_DNS4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_DNS4_HOST_NAME_TO_IP
name|HostNameToIp
decl_stmt|;
name|EFI_DNS4_IP_TO_HOST_NAME
name|IpToHostName
decl_stmt|;
name|EFI_DNS4_GENERAL_LOOKUP
name|GeneralLookUp
decl_stmt|;
name|EFI_DNS4_UPDATE_DNS_CACHE
name|UpdateDnsCache
decl_stmt|;
name|EFI_DNS4_POLL
name|Poll
decl_stmt|;
name|EFI_DNS4_CANCEL
name|Cancel
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDns4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDns4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

