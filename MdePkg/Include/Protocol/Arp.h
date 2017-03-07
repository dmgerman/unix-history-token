begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file     EFI ARP Protocol Definition      The EFI ARP Service Binding Protocol is used to locate EFI   ARP Protocol drivers to create and destroy child of the   driver to communicate with other host using ARP protocol.   The EFI ARP Protocol provides services to map IP network   address to hardware address used by a data link protocol.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:             This Protocol was introduced in UEFI Specification 2.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_ARP_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_ARP_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_ARP_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xf44c00ee, 0x1f2c, 0x4a00, {0xaa, 0x9, 0x1c, 0x9f, 0x3e, 0x8, 0x0, 0xa3 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ARP_PROTOCOL_GUID
define|\
value|{ \     0xf4b427bb, 0xba21, 0x4f16, {0xbc, 0x4e, 0x43, 0xe4, 0x16, 0xab, 0x61, 0x9c } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ARP_PROTOCOL
name|EFI_ARP_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Length in bytes of this entry.
comment|///
name|UINT32
name|Size
decl_stmt|;
comment|///
comment|/// Set to TRUE if this entry is a "deny" entry.
comment|/// Set to FALSE if this entry is a "normal" entry.
comment|///
name|BOOLEAN
name|DenyFlag
decl_stmt|;
comment|///
comment|/// Set to TRUE if this entry will not time out.
comment|/// Set to FALSE if this entry will time out.
comment|///
name|BOOLEAN
name|StaticFlag
decl_stmt|;
comment|///
comment|/// 16-bit ARP hardware identifier number.
comment|///
name|UINT16
name|HwAddressType
decl_stmt|;
comment|///
comment|/// 16-bit protocol type number.
comment|///
name|UINT16
name|SwAddressType
decl_stmt|;
comment|///
comment|/// The length of the hardware address.
comment|///
name|UINT8
name|HwAddressLength
decl_stmt|;
comment|///
comment|/// The length of the protocol address.
comment|///
name|UINT8
name|SwAddressLength
decl_stmt|;
block|}
name|EFI_ARP_FIND_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// 16-bit protocol type number in host byte order.
comment|///
name|UINT16
name|SwAddressType
decl_stmt|;
comment|///
comment|/// The length in bytes of the station's protocol address to register.
comment|///
name|UINT8
name|SwAddressLength
decl_stmt|;
comment|///
comment|/// The pointer to the first byte of the protocol address to register. For
comment|/// example, if SwAddressType is 0x0800 (IP), then
comment|/// StationAddress points to the first byte of this station's IP
comment|/// address stored in network byte order.
comment|///
name|VOID
modifier|*
name|StationAddress
decl_stmt|;
comment|///
comment|/// The timeout value in 100-ns units that is associated with each
comment|/// new dynamic ARP cache entry. If it is set to zero, the value is
comment|/// implementation-specific.
comment|///
name|UINT32
name|EntryTimeOut
decl_stmt|;
comment|///
comment|/// The number of retries before a MAC address is resolved. If it is
comment|/// set to zero, the value is implementation-specific.
comment|///
name|UINT32
name|RetryCount
decl_stmt|;
comment|///
comment|/// The timeout value in 100-ns units that is used to wait for the ARP
comment|/// reply packet or the timeout value between two retries. Set to zero
comment|/// to use implementation-specific value.
comment|///
name|UINT32
name|RetryTimeOut
decl_stmt|;
block|}
name|EFI_ARP_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|/**   This function is used to assign a station address to the ARP cache for this instance   of the ARP driver.      Each ARP instance has one station address. The EFI_ARP_PROTOCOL driver will    respond to ARP requests that match this registered station address. A call to    this function with the ConfigData field set to NULL will reset this ARP instance.      Once a protocol type and station address have been assigned to this ARP instance,    all the following ARP functions will use this information. Attempting to change    the protocol type or station address to a configured ARP instance will result in errors.    @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.   @param  ConfigData             The pointer to the EFI_ARP_CONFIG_DATA structure.    @retval EFI_SUCCESS            The new station address was successfully                                  registered.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  * This is NULL.                                   * SwAddressLength is zero when ConfigData is not NULL.                                   * StationAddress is NULL when ConfigData is not NULL.   @retval EFI_ACCESS_DENIED      The SwAddressType, SwAddressLength, or                                  StationAddress is different from the one that is                                  already registered.   @retval EFI_OUT_OF_RESOURCES   Storage for the new StationAddress could not be                                  allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_ARP_CONFIG_DATA
modifier|*
name|ConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function is used to insert entries into the ARP cache.    ARP cache entries are typically inserted and updated by network protocol drivers    as network traffic is processed. Most ARP cache entries will time out and be    deleted if the network traffic stops. ARP cache entries that were inserted    by the Add() function may be static (will not time out) or dynamic (will time out).   Default ARP cache timeout values are not covered in most network protocol    specifications (although RFC 1122 comes pretty close) and will only be    discussed in general terms in this specification. The timeout values that are    used in the EFI Sample Implementation should be used only as a guideline.    Final product implementations of the EFI network stack should be tuned for    their expected network environments.      @param  This                   Pointer to the EFI_ARP_PROTOCOL instance.   @param  DenyFlag               Set to TRUE if this entry is a deny entry. Set to                                  FALSE if this  entry is a normal entry.   @param  TargetSwAddress        Pointer to a protocol address to add (or deny).                                  May be set to NULL if DenyFlag is TRUE.   @param  TargetHwAddress        Pointer to a hardware address to add (or deny).                                  May be set to NULL if DenyFlag is TRUE.   @param  TimeoutValue           Time in 100-ns units that this entry will remain                                  in the ARP cache. A value of zero means that the                                  entry is permanent. A nonzero value will override                                  the one given by Configure() if the entry to be                                  added is a dynamic entry.   @param  Overwrite              If TRUE, the matching cache entry will be                                  overwritten with the supplied parameters. If                                  FALSE, EFI_ACCESS_DENIED is returned if the                                  corresponding cache entry already exists.    @retval EFI_SUCCESS            The entry has been added or updated.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  * This is NULL.                                   * DenyFlag is FALSE and TargetHwAddress is NULL.                                   * DenyFlag is FALSE and TargetSwAddress is NULL.                                   * TargetHwAddress is NULL and TargetSwAddress is NULL.                                   * Neither TargetSwAddress nor TargetHwAddress are NULL when DenyFlag is                                  TRUE.   @retval EFI_OUT_OF_RESOURCES   The new ARP cache entry could not be allocated.   @retval EFI_ACCESS_DENIED      The ARP cache entry already exists and Overwrite                                  is not true.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_ADD
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|DenyFlag
parameter_list|,
name|IN
name|VOID
modifier|*
name|TargetSwAddress
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|TargetHwAddress
name|OPTIONAL
parameter_list|,
name|IN
name|UINT32
name|TimeoutValue
parameter_list|,
name|IN
name|BOOLEAN
name|Overwrite
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function searches the ARP cache for matching entries and allocates a buffer into   which those entries are copied.      The first part of the allocated buffer is EFI_ARP_FIND_DATA, following which    are protocol address pairs and hardware address pairs.   When finding a specific protocol address (BySwAddress is TRUE and AddressBuffer    is not NULL), the ARP cache timeout for the found entry is reset if Refresh is    set to TRUE. If the found ARP cache entry is a permanent entry, it is not    affected by Refresh.      @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.   @param  BySwAddress            Set to TRUE to look for matching software protocol                                  addresses. Set to FALSE to look for matching                                  hardware protocol addresses.   @param  AddressBuffer          The pointer to the address buffer. Set to NULL                                   to match all addresses.   @param  EntryLength            The size of an entry in the entries buffer.   @param  EntryCount             The number of ARP cache entries that are found by                                  the specified criteria.   @param  Entries                The pointer to the buffer that will receive the ARP                                  cache entries.   @param  Refresh                Set to TRUE to refresh the timeout value of the                                  matching ARP cache entry.    @retval EFI_SUCCESS            The requested ARP cache entries were copied into                                  the buffer.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  This is NULL. Both EntryCount and EntryLength are                                  NULL, when Refresh is FALSE.   @retval EFI_NOT_FOUND          No matching entries were found.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_FIND
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|BySwAddress
parameter_list|,
name|IN
name|VOID
modifier|*
name|AddressBuffer
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|EntryLength
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|EntryCount
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_ARP_FIND_DATA
modifier|*
modifier|*
name|Entries
name|OPTIONAL
parameter_list|,
name|IN
name|BOOLEAN
name|Refresh
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function removes specified ARP cache entries.    @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.   @param  BySwAddress            Set to TRUE to delete matching protocol addresses.                                  Set to FALSE to delete matching hardware                                  addresses.   @param  AddressBuffer          The pointer to the address buffer that is used as a                                  key to look for the cache entry. Set to NULL to                                  delete all entries.    @retval EFI_SUCCESS            The entry was removed from the ARP cache.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_FOUND          The specified deletion key was not found.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_DELETE
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|BySwAddress
parameter_list|,
name|IN
name|VOID
modifier|*
name|AddressBuffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function delete all dynamic entries from the ARP cache that match the specified   software protocol type.    @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.    @retval EFI_SUCCESS            The cache has been flushed.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_FOUND          There are no matching dynamic cache entries.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function tries to resolve the TargetSwAddress and optionally returns a   TargetHwAddress if it already exists in the ARP cache.    @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.   @param  TargetSwAddress        The pointer to the protocol address to resolve.   @param  ResolvedEvent          The pointer to the event that will be signaled when                                  the address is resolved or some error occurs.   @param  TargetHwAddress        The pointer to the buffer for the resolved hardware                                  address in network byte order.    @retval EFI_SUCCESS            The data is copied from the ARP cache into the                                  TargetHwAddress buffer.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  This is NULL. TargetHwAddress is NULL.   @retval EFI_ACCESS_DENIED      The requested address is not present in the normal                                  ARP cache but is present in the deny address list.                                  Outgoing traffic to that address is forbidden.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.   @retval EFI_NOT_READY          The request has been started and is not finished.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_REQUEST
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|TargetSwAddress
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_EVENT
name|ResolvedEvent
name|OPTIONAL
parameter_list|,
name|OUT
name|VOID
modifier|*
name|TargetHwAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function aborts the previous ARP request (identified by This, TargetSwAddress   and ResolvedEvent) that is issued by EFI_ARP_PROTOCOL.Request().      If the request is in the internal ARP request queue, the request is aborted    immediately and its ResolvedEvent is signaled. Only an asynchronous address    request needs to be canceled. If TargeSwAddress and ResolveEvent are both    NULL, all the pending asynchronous requests that have been issued by This    instance will be cancelled and their corresponding events will be signaled.      @param  This                   The pointer to the EFI_ARP_PROTOCOL instance.   @param  TargetSwAddress        The pointer to the protocol address in previous                                  request session.   @param  ResolvedEvent          Pointer to the event that is used as the                                  notification event in previous request session.    @retval EFI_SUCCESS            The pending request session(s) is/are aborted and                                  corresponding event(s) is/are signaled.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  This is NULL. TargetSwAddress is not NULL and                                  ResolvedEvent is NULL. TargetSwAddress is NULL and                                  ResolvedEvent is not NULL.   @retval EFI_NOT_STARTED        The ARP driver instance has not been configured.   @retval EFI_NOT_FOUND          The request is not issued by                                  EFI_ARP_PROTOCOL.Request().   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ARP_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_ARP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|TargetSwAddress
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_EVENT
name|ResolvedEvent
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARP is used to resolve local network protocol addresses into
end_comment

begin_comment
comment|/// network hardware addresses.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ARP_PROTOCOL
block|{
name|EFI_ARP_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_ARP_ADD
name|Add
decl_stmt|;
name|EFI_ARP_FIND
name|Find
decl_stmt|;
name|EFI_ARP_DELETE
name|Delete
decl_stmt|;
name|EFI_ARP_FLUSH
name|Flush
decl_stmt|;
name|EFI_ARP_REQUEST
name|Request
decl_stmt|;
name|EFI_ARP_CANCEL
name|Cancel
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiArpServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiArpProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

