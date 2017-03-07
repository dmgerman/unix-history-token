begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Dynamic Host Configuration Protocol 6 Definition, which is used to get IPv6   addresses and other configuration parameters from DHCPv6 servers.    Copyright (c) 2008 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                                                                                                            THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.     @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DHCP6_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DHCP6_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_DHCP6_PROTOCOL_GUID
define|\
value|{ \     0x87c8bad7, 0x595, 0x4053, {0x82, 0x97, 0xde, 0xde, 0x39, 0x5f, 0x5d, 0x5b } \   }
end_define

begin_define
define|#
directive|define
name|EFI_DHCP6_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x9fb9a8a1, 0x2f4a, 0x43a6, {0x88, 0x9c, 0xd0, 0xf7, 0xb6, 0xc4, 0x7a, 0xd5 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DHCP6_PROTOCOL
name|EFI_DHCP6_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The EFI DHCPv6 Protocol instance is configured, and start() needs
comment|/// to be called
comment|///
name|Dhcp6Init
init|=
literal|0x0
block|,
comment|///
comment|/// A Solicit packet is sent out to discover DHCPv6 server, and the EFI
comment|/// DHCPv6 Protocol instance is collecting Advertise packets.
comment|///
name|Dhcp6Selecting
init|=
literal|0x1
block|,
comment|///
comment|/// A Request is sent out to the DHCPv6 server, and the EFI DHCPv6
comment|/// Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Requesting
init|=
literal|0x2
block|,
comment|///
comment|/// A Decline packet is sent out to indicate one or more addresses of the
comment|/// configured IA are in use by another node, and the EFI DHCPv6.
comment|/// Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Declining
init|=
literal|0x3
block|,
comment|///
comment|/// A Confirm packet is sent out to confirm the IPv6 addresses of the
comment|/// configured IA, and the EFI DHCPv6 Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Confirming
init|=
literal|0x4
block|,
comment|///
comment|/// A Release packet is sent out to release one or more IPv6 addresses of
comment|/// the configured IA, and the EFI DHCPv6 Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Releasing
init|=
literal|0x5
block|,
comment|///
comment|/// The DHCPv6 S.A.R.R process is completed for the configured IA.
comment|///
name|Dhcp6Bound
init|=
literal|0x6
block|,
comment|///
comment|/// A Renew packet is sent out to extend lifetime for the IPv6 addresses of
comment|/// the configured IA, and the EFI DHCPv6 Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Renewing
init|=
literal|0x7
block|,
comment|///
comment|/// A Rebind packet is sent out to extend lifetime for the IPv6 addresses of
comment|/// the configured IA, and the EFI DHCPv6 Protocol instance is waiting for Reply packet.
comment|///
name|Dhcp6Rebinding
init|=
literal|0x8
block|}
name|EFI_DHCP6_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A Solicit packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6SendSolicit
init|=
literal|0x0
block|,
comment|///
comment|/// An Advertise packet is received and will be passed to Dhcp6Callback.
comment|///
name|Dhcp6RcvdAdvertise
init|=
literal|0x1
block|,
comment|///
comment|/// It is time for Dhcp6Callback to determine whether select the default Advertise
comment|/// packet by RFC 3315 policy, or overwrite it by specific user policy.
comment|///
name|Dhcp6SelectAdvertise
init|=
literal|0x2
block|,
comment|///
comment|/// A Request packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6SendRequest
init|=
literal|0x3
block|,
comment|///
comment|/// A Reply packet is received and will be passed to Dhcp6Callback.
comment|///
name|Dhcp6RcvdReply
init|=
literal|0x4
block|,
comment|///
comment|/// A Reconfigure packet is received and will be passed to Dhcp6Callback.
comment|///
name|Dhcp6RcvdReconfigure
init|=
literal|0x5
block|,
comment|///
comment|/// A Decline packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6SendDecline
init|=
literal|0x6
block|,
comment|///
comment|/// A Confirm packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6SendConfirm
init|=
literal|0x7
block|,
comment|///
comment|/// A Release packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6SendRelease
init|=
literal|0x8
block|,
comment|///
comment|/// A Renew packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6EnterRenewing
init|=
literal|0x9
block|,
comment|///
comment|/// A Rebind packet is about to be sent. The packet is passed to Dhcp6Callback and
comment|/// can be modified or replaced in Dhcp6Callback.
comment|///
name|Dhcp6EnterRebinding
init|=
literal|0xa
block|}
name|EFI_DHCP6_EVENT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An IA which carries assigned not temporary address.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DHCP6_IA_TYPE_NA
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// An IA which carries assigned temporary address.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DHCP6_IA_TYPE_TA
value|4
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DHCP6_PACKET_OPTION
end_comment

begin_comment
comment|/// defines the format of the DHCPv6 option, See RFC 3315 for more information.
end_comment

begin_comment
comment|/// This data structure is used to reference option data that is packed in the DHCPv6 packet.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The DHCPv6 option code, stored in network order.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// Length of the DHCPv6 option data, stored in network order.
comment|/// From the first byte to the last byte of the Data field.
comment|///
name|UINT16
name|OpLen
decl_stmt|;
comment|///
comment|/// The data for the DHCPv6 option, stored in network order.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_DHCP6_PACKET_OPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DHCP6_HEADER
end_comment

begin_comment
comment|/// defines the format of the DHCPv6 header. See RFC 3315 for more information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The DHCPv6 transaction ID.
comment|///
name|UINT32
name|MessageType
range|:
literal|8
decl_stmt|;
comment|///
comment|/// The DHCPv6 message type.
comment|///
name|UINT32
name|TransactionId
range|:
literal|24
decl_stmt|;
block|}
name|EFI_DHCP6_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DHCP6_PACKET
end_comment

begin_comment
comment|/// defines the format of the DHCPv6 packet. See RFC 3315 for more information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Size of the EFI_DHCP6_PACKET buffer.
comment|///
name|UINT32
name|Size
decl_stmt|;
comment|///
comment|/// Length of the EFI_DHCP6_PACKET from the first byte of the Header field to the last
comment|/// byte of the Option[] field.
comment|///
name|UINT32
name|Length
decl_stmt|;
struct|struct
block|{
comment|///
comment|/// The DHCPv6 packet header.
comment|///
name|EFI_DHCP6_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Start of the DHCPv6 packed option data.
comment|///
name|UINT8
name|Option
index|[
literal|1
index|]
decl_stmt|;
block|}
name|Dhcp6
struct|;
block|}
name|EFI_DHCP6_PACKET
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Length of DUID in octects.
comment|///
name|UINT16
name|Length
decl_stmt|;
comment|///
comment|/// Array of DUID octects.
comment|///
name|UINT8
name|Duid
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_DHCP6_DUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Initial retransmission timeout.
comment|///
name|UINT32
name|Irt
decl_stmt|;
comment|///
comment|/// Maximum retransmission count for one packet. If Mrc is zero, there's no upper limit
comment|/// for retransmission count.
comment|///
name|UINT32
name|Mrc
decl_stmt|;
comment|///
comment|/// Maximum retransmission timeout for each retry. It's the upper bound of the number of
comment|/// retransmission timeout. If Mrt is zero, there is no upper limit for retransmission
comment|/// timeout.
comment|///
name|UINT32
name|Mrt
decl_stmt|;
comment|///
comment|/// Maximum retransmission duration for one packet. It's the upper bound of the numbers
comment|/// the client may retransmit a message. If Mrd is zero, there's no upper limit for
comment|/// retransmission duration.
comment|///
name|UINT32
name|Mrd
decl_stmt|;
block|}
name|EFI_DHCP6_RETRANSMISSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The IPv6 address.
comment|///
name|EFI_IPv6_ADDRESS
name|IpAddress
decl_stmt|;
comment|///
comment|/// The preferred lifetime in unit of seconds for the IPv6 address.
comment|///
name|UINT32
name|PreferredLifetime
decl_stmt|;
comment|///
comment|/// The valid lifetime in unit of seconds for the IPv6 address.
comment|///
name|UINT32
name|ValidLifetime
decl_stmt|;
block|}
name|EFI_DHCP6_IA_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
comment|///< Type for an IA.
name|UINT32
name|IaId
decl_stmt|;
comment|///< The identifier for an IA.
block|}
name|EFI_DHCP6_IA_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The descriptor for IA.
comment|///
name|EFI_DHCP6_IA_DESCRIPTOR
name|Descriptor
decl_stmt|;
comment|///
comment|/// The state of the configured IA.
comment|///
name|EFI_DHCP6_STATE
name|State
decl_stmt|;
comment|///
comment|/// Pointer to the cached latest Reply packet. May be NULL if no packet is cached.
comment|///
name|EFI_DHCP6_PACKET
modifier|*
name|ReplyPacket
decl_stmt|;
comment|///
comment|/// Number of IPv6 addresses of the configured IA.
comment|///
name|UINT32
name|IaAddressCount
decl_stmt|;
comment|///
comment|/// List of the IPv6 addresses of the configured IA. When the state of the configured IA is
comment|/// in Dhcp6Bound, Dhcp6Renewing and Dhcp6Rebinding, the IPv6 addresses are usable.
comment|///
name|EFI_DHCP6_IA_ADDRESS
name|IaAddress
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_DHCP6_IA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Pointer to the DHCPv6 unique identifier. The caller is responsible for freeing this buffer.
comment|///
name|EFI_DHCP6_DUID
modifier|*
name|ClientId
decl_stmt|;
comment|///
comment|/// Pointer to the configured IA of current instance. The caller can free this buffer after
comment|/// using it.
comment|///
name|EFI_DHCP6_IA
modifier|*
name|Ia
decl_stmt|;
block|}
name|EFI_DHCP6_MODE_DATA
typedef|;
end_typedef

begin_comment
comment|/**   EFI_DHCP6_CALLBACK is provided by the consumer of the EFI DHCPv6 Protocol instance to    intercept events that occurs in the DHCPv6 S.A.R.R process.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance that is used to configure this                                  callback function.   @param[in]  Context           Pointer to the context that is initialized by EFI_DHCP6_PROTOCOL.Configure().   @param[in]  CurrentState      The current state of the configured IA.   @param[in]  Dhcp6Event        The event that occurs in the current state, which usually means a state transition.   @param[in]  Packet            Pointer to the DHCPv6 packet that is about to be sent or has been received.                                 The EFI DHCPv6 Protocol instance is responsible for freeing the buffer.    @param[out] NewPacket         Pointer to the new DHCPv6 packet to overwrite the Packet. NewPacket can not                                  share the buffer with Packet. If *NewPacket is not NULL, the EFI DHCPv6                                  Protocol instance is responsible for freeing the buffer.    @retval EFI_SUCCESS           Tell the EFI DHCPv6 Protocol instance to continue the DHCPv6 S.A.R.R process.   @retval EFI_ABORTED           Tell the EFI DHCPv6 Protocol instance to abort the DHCPv6 S.A.R.R process,                                  and the state of the configured IA will be transferred to Dhcp6Init.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_DHCP6_STATE
name|CurrentState
parameter_list|,
name|IN
name|EFI_DHCP6_EVENT
name|Dhcp6Event
parameter_list|,
name|IN
name|EFI_DHCP6_PACKET
modifier|*
name|Packet
parameter_list|,
name|OUT
name|EFI_DHCP6_PACKET
modifier|*
modifier|*
name|NewPacket
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The callback function is to intercept various events that occur in the DHCPv6 S.A.R.R
comment|/// process. Set to NULL to ignore all those events.
comment|///
name|EFI_DHCP6_CALLBACK
name|Dhcp6Callback
decl_stmt|;
comment|///
comment|/// Pointer to the context that will be passed to Dhcp6Callback.
comment|///
name|VOID
modifier|*
name|CallbackContext
decl_stmt|;
comment|///
comment|/// Number of the DHCPv6 options in the OptionList.
comment|///
name|UINT32
name|OptionCount
decl_stmt|;
comment|///
comment|/// List of the DHCPv6 options to be included in Solicit and Request packet. The buffer
comment|/// can be freed after EFI_DHCP6_PROTOCOL.Configure() returns. Ignored if
comment|/// OptionCount is zero. OptionList should not contain Client Identifier option
comment|/// and any IA option, which will be appended by EFI DHCPv6 Protocol instance
comment|/// automatically.
comment|///
name|EFI_DHCP6_PACKET_OPTION
modifier|*
modifier|*
name|OptionList
decl_stmt|;
comment|///
comment|/// The descriptor for the IA of the EFI DHCPv6 Protocol instance.
comment|///
name|EFI_DHCP6_IA_DESCRIPTOR
name|IaDescriptor
decl_stmt|;
comment|///
comment|/// If not NULL, the event will be signaled when any IPv6 address information of the
comment|/// configured IA is updated, including IPv6 address, preferred lifetime and valid
comment|/// lifetime, or the DHCPv6 S.A.R.R process fails. Otherwise, Start(),
comment|/// renewrebind(), decline(), release() and stop() will be blocking
comment|/// operations, and they will wait for the exchange process completion or failure.
comment|///
name|EFI_EVENT
name|IaInfoEvent
decl_stmt|;
comment|///
comment|/// If TRUE, the EFI DHCPv6 Protocol instance is willing to accept Reconfigure packet.
comment|/// Otherwise, it will ignore it. Reconfigure Accept option can not be specified through
comment|/// OptionList parameter.
comment|///
name|BOOLEAN
name|ReconfigureAccept
decl_stmt|;
comment|///
comment|/// If TRUE, the EFI DHCPv6 Protocol instance will send Solicit packet with Rapid
comment|/// Commit option. Otherwise, Rapid Commit option will not be included in Solicit
comment|/// packet. Rapid Commit option can not be specified through OptionList parameter.
comment|///
name|BOOLEAN
name|RapidCommit
decl_stmt|;
comment|///
comment|/// Parameter to control Solicit packet retransmission behavior. The
comment|/// buffer can be freed after EFI_DHCP6_PROTOCOL.Configure() returns.
comment|///
name|EFI_DHCP6_RETRANSMISSION
modifier|*
name|SolicitRetransmission
decl_stmt|;
block|}
name|EFI_DHCP6_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|/**   EFI_DHCP6_INFO_CALLBACK is provided by the consumer of the EFI DHCPv6 Protocol    instance to intercept events that occurs in the DHCPv6 Information Request exchange process.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance that is used to configure this                                  callback function.   @param[in]  Context           Pointer to the context that is initialized in the EFI_DHCP6_PROTOCOL.InfoRequest().   @param[in]  Packet            Pointer to Reply packet that has been received. The EFI DHCPv6 Protocol instance is                                  responsible for freeing the buffer.    @retval EFI_SUCCESS           Tell the EFI DHCPv6 Protocol instance to finish Information Request exchange process.   @retval EFI_NOT_READY         Tell the EFI DHCPv6 Protocol instance to continue Information Request exchange process.   @retval EFI_ABORTED           Tell the EFI DHCPv6 Protocol instance to abort the Information Request exchange process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_INFO_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_DHCP6_PACKET
modifier|*
name|Packet
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieve the current operating mode data and configuration data for the EFI DHCPv6 Protocol instance.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.   @param[out] Dhcp6ModeData     Pointer to the DHCPv6 mode data structure. The caller is responsible for freeing this                                  structure and each reference buffer.   @param[out] Dhcp6ConfigData   Pointer to the DHCPv6 configuration data structure. The caller is responsible for                                  freeing this structure and each reference buffer.    @retval EFI_SUCCESS           The mode data was returned.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Protocol instance has not been configured when Dhcp6ConfigData is not NULL.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE:                                 - This is NULL.                                  - Both Dhcp6ConfigData and Dhcp6ModeData are NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_DHCP6_MODE_DATA
modifier|*
name|Dhcp6ModeData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_DHCP6_CONFIG_DATA
modifier|*
name|Dhcp6ConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initialize or clean up the configuration data for the EFI DHCPv6 Protocol instance.    The Configure() function is used to initialize or clean up the configuration data of the EFI    DHCPv6 Protocol instance.   - When Dhcp6CfgData is not NULL and Configure() is called successfully, the      configuration data will be initialized in the EFI DHCPv6 Protocol instance and the state of the      configured IA will be transferred into Dhcp6Init.   - When Dhcp6CfgData is NULL and Configure() is called successfully, the configuration      data will be cleaned up and no IA will be associated with the EFI DHCPv6 Protocol instance.    To update the configuration data for an EFI DCHPv6 Protocol instance, the original data must be    cleaned up before setting the new configuration data.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.   @param[in]  Dhcp6CfgData      Pointer to the DHCPv6 configuration data structure.    @retval EFI_SUCCESS           The mode data was returned.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE                                 - This is NULL.                                  - OptionCount> 0 and OptionList is NULL.                                 - OptionList is not NULL, and Client Id option, Reconfigure Accept option,                                   Rapid Commit option or any IA option is specified in the OptionList.                                 - IaDescriptor.Type is neither EFI_DHCP6_IA_TYPE_NA nor EFI_DHCP6_IA_TYPE_NA.                                 - IaDescriptor is not unique.                                 - Both IaInfoEvent and SolicitRetransimssion are NULL.                                 - SolicitRetransmission is not NULL, and both SolicitRetransimssion->Mrc and                                    SolicitRetransmission->Mrd are zero.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Protocol instance has been already configured                                  when Dhcp6CfgData is not NULL.                                 The EFI DHCPv6 Protocol instance has already started the                                  DHCPv6 S.A.R.R when Dhcp6CfgData is NULL.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP6_CONFIG_DATA
modifier|*
name|Dhcp6CfgData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Start the DHCPv6 S.A.R.R process.    The Start() function starts the DHCPv6 S.A.R.R process. This function can be called only when    the state of the configured IA is in the Dhcp6Init state. If the DHCPv6 S.A.R.R process completes   successfully, the state of the configured IA will be transferred through Dhcp6Selecting and    Dhcp6Requesting to Dhcp6Bound state. The update of the IPv6 addresses will be notified through    EFI_DHCP6_CONFIG_DATA.IaInfoEvent. At the time when each event occurs in this process, the    callback function set by EFI_DHCP6_PROTOCOL.Configure() will be called and the user can take    this opportunity to control the process. If EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL, the    Start() function call is a blocking operation. It will return after the DHCPv6 S.A.R.R process   completes or aborted by users. If the process is aborted by system or network error, the state of   the configured IA will be transferred to Dhcp6Init. The Start() function can be called again to   restart the process.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.    @retval EFI_SUCCESS           The DHCPv6 S.A.R.R process is completed and at least one IPv6                                  address has been bound to the configured IA when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL.                                  The DHCPv6 S.A.R.R process is started when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is not NULL.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Child instance hasn't been configured.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_ALREADY_STARTED   The DHCPv6 S.A.R.R process has already started.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_NO_RESPONSE       The DHCPv6 S.A.R.R process failed because of no response.   @retval EFI_NO_MAPPING        No IPv6 address has been bound to the configured IA after the                                  DHCPv6 S.A.R.R process.   @retval EFI_ABORTED           The DHCPv6 S.A.R.R process aborted by user.   @retval EFI_NO_MEDIA          There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_START
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Request configuration information without the assignment of any IA addresses of the client.    The InfoRequest() function is used to request configuration information without the assignment   of any IPv6 address of the client. Client sends out Information Request packet to obtain    the required configuration information, and DHCPv6 server responds with Reply packet containing    the information for the client. The received Reply packet will be passed to the user by    ReplyCallback function. If user returns EFI_NOT_READY from ReplyCallback, the EFI DHCPv6   Protocol instance will continue to receive other Reply packets unless timeout according to    the Retransmission parameter. Otherwise, the Information Request exchange process will be    finished successfully if user returns EFI_SUCCESS from ReplyCallback.    @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.   @param[in]  SendClientId      If TRUE, the EFI DHCPv6 Protocol instance will build Client                                 Identifier option and include it into Information Request                                 packet. If FALSE, Client Identifier option will not be included.                                 Client Identifier option can not be specified through OptionList                                  parameter.   @param[in]  OptionRequest     Pointer to the Option Request option in the Information Request                                 packet. Option Request option can not be specified through                                 OptionList parameter.   @param[in]  OptionCount       Number of options in OptionList.   @param[in]  OptionList        List of other DHCPv6 options. These options will be appended                                 to the Option Request option. The caller is responsible for                                 freeing this buffer. Type is defined in EFI_DHCP6_PROTOCOL.GetModeData().   @param[in]  Retransmission    Parameter to control Information Request packet retransmission                                 behavior. The buffer can be freed after EFI_DHCP6_PROTOCOL.InfoRequest()                                 returns.   @param[in]  TimeoutEvent      If not NULL, this event is signaled when the information request                                 exchange aborted because of no response. If NULL, the function                                 call is a blocking operation; and it will return after the                                  information-request exchange process finish or aborted by users.   @param[in]  ReplyCallback     The callback function is to intercept various events that occur                                 in the Information Request exchange process. It should not be                                 set to NULL.   @param[in]  CallbackContext   Pointer to the context that will be passed to ReplyCallback.    @retval EFI_SUCCESS           The DHCPv6 S.A.R.R process is completed and at least one IPv6    @retval EFI_SUCCESS           The DHCPv6 information request exchange process completed                                  when TimeoutEvent is NULL. Information Request packet has been                                 sent to DHCPv6 server when TimeoutEvent is not NULL.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE:                                 - This is NULL.                                  - OptionRequest is NULL or OptionRequest->OpCode is invalid.                                 - OptionCount> 0 and OptionList is NULL.                                 - OptionList is not NULL, and Client Identify option or                                    Option Request option is specified in the OptionList.                                 - Retransimssion is NULL.                                 - Both Retransimssion->Mrc and Retransmission->Mrd are zero.                                 - ReplyCallback is NULL.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_NO_RESPONSE       The DHCPv6 information request exchange process failed                                  because of no response, or not all requested-options are                                  responded by DHCPv6 servers when Timeout happened.   @retval EFI_ABORTED           The DHCPv6 information request exchange process aborted by user.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_INFO_REQUEST
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|SendClientId
parameter_list|,
name|IN
name|EFI_DHCP6_PACKET_OPTION
modifier|*
name|OptionRequest
parameter_list|,
name|IN
name|UINT32
name|OptionCount
parameter_list|,
name|IN
name|EFI_DHCP6_PACKET_OPTION
modifier|*
name|OptionList
index|[]
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_DHCP6_RETRANSMISSION
modifier|*
name|Retransmission
parameter_list|,
name|IN
name|EFI_EVENT
name|TimeoutEvent
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_DHCP6_INFO_CALLBACK
name|ReplyCallback
parameter_list|,
name|IN
name|VOID
modifier|*
name|CallbackContext
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Manually extend the valid and preferred lifetimes for the IPv6 addresses of the configured   IA and update other configuration parameters by sending Renew or Rebind packet.    The RenewRebind() function is used to manually extend the valid and preferred lifetimes for the    IPv6 addresses of the configured IA and update other configuration parameters by sending Renew or    Rebind packet.    - When RebindRequest is FALSE and the state of the configured IA is Dhcp6Bound, it    will send Renew packet to the previously DHCPv6 server and transfer the state of the configured    IA to Dhcp6Renewing. If valid Reply packet received, the state transfers to Dhcp6Bound    and the valid and preferred timer restarts. If fails, the state transfers to Dhcp6Bound but the    timer continues.    - When RebindRequest is TRUE and the state of the configured IA is Dhcp6Bound, it will    send Rebind packet. If valid Reply packet received, the state transfers to Dhcp6Bound and the    valid and preferred timer restarts. If fails, the state transfers to Dhcp6Init and the IA can't   be used.    @param[in]  This              Pointer to the EFI_DHCP4_PROTOCOL instance.   @param[in]  RebindRequest     If TRUE, it will send Rebind packet and enter the Dhcp6Rebinding state.                                  Otherwise, it will send Renew packet and enter the Dhcp6Renewing state.    @retval EFI_SUCCESS           The DHCPv6 renew/rebind exchange process has completed and at                                  least one IPv6 address of the configured IA has been bound again                                 when EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL.                                  The EFI DHCPv6 Protocol instance has sent Renew or Rebind packet                                  when EFI_DHCP6_CONFIG_DATA.IaInfoEvent is not NULL.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Child instance hasn't been configured, or the state                                 of the configured IA is not in Dhcp6Bound.   @retval EFI_ALREADY_STARTED   The state of the configured IA has already entered Dhcp6Renewing                                  when RebindRequest is FALSE.                                  The state of the configured IA has already entered Dhcp6Rebinding                                  when RebindRequest is TRUE.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_DEVICE_ERROR      An unexpected system or system error occurred.   @retval EFI_NO_RESPONSE       The DHCPv6 renew/rebind exchange process failed because of no response.   @retval EFI_NO_MAPPING        No IPv6 address has been bound to the configured IA after the DHCPv6                                  renew/rebind exchange process.   @retval EFI_ABORTED           The DHCPv6 renew/rebind exchange process aborted by user.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_RENEW_REBIND
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|RebindRequest
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Inform that one or more IPv6 addresses assigned by a server are already in use by   another node.    The Decline() function is used to manually decline the assignment of IPv6 addresses, which    have been already used by another node. If all IPv6 addresses of the configured IA are declined    through this function, the state of the IA will switch through Dhcp6Declining to Dhcp6Init,    otherwise, the state of the IA will restore to Dhcp6Bound after the declining process. The    Decline() can only be called when the IA is in Dhcp6Bound state. If the    EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL, this function is a blocking operation. It    will return after the declining process finishes, or aborted by user.    @param[in]  This              Pointer to the EFI_DHCP4_PROTOCOL instance.   @param[in]  AddressCount      Number of declining IPv6 addresses.    @param[in]  Addresses         Pointer to the buffer stored all the declining IPv6 addresses.    @retval EFI_SUCCESS           The DHCPv6 decline exchange process has completed when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL.                                 The EFI DHCPv6 Protocol instance has sent Decline packet when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is not NULL.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE                                 - This is NULL.                                   - AddressCount is zero or Addresses is NULL.   @retval EFI_NOT_FOUND         Any specified IPv6 address is not correlated with the configured IA                                  for this instance.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Child instance hasn't been configured, or the                                  state of the configured IA is not in Dhcp6Bound.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_ABORTED           The DHCPv6 decline exchange process aborted by user.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_DECLINE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|AddressCount
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|Addresses
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Release one or more IPv6 addresses associated with the configured IA for current instance.    The Release() function is used to manually release the one or more IPv6 address. If AddressCount   is zero, it will release all IPv6 addresses of the configured IA. If all IPv6 addresses of the IA   are released through this function, the state of the IA will switch through Dhcp6Releasing to    Dhcp6Init, otherwise, the state of the IA will restore to Dhcp6Bound after the releasing process.   The Release() can only be called when the IA is in Dhcp6Bound state. If the   EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL, the function is a blocking operation. It will return   after the releasing process finishes, or aborted by user.     @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.   @param[in]  AddressCount      Number of releasing IPv6 addresses.    @param[in]  Addresses         Pointer to the buffer stored all the releasing IPv6 addresses.                                 Ignored if AddressCount is zero.   @retval EFI_SUCCESS           The DHCPv6 release exchange process has completed when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL.                                 The EFI DHCPv6 Protocol instance has sent Release packet when                                  EFI_DHCP6_CONFIG_DATA.IaInfoEvent is not NULL.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE                                 - This is NULL.                                   - AddressCount is not zero or Addresses is NULL.   @retval EFI_NOT_FOUND         Any specified IPv6 address is not correlated with the configured                                 IA for this instance.   @retval EFI_ACCESS_DENIED     The EFI DHCPv6 Child instance hasn't been configured, or the                                  state of the configured IA is not in Dhcp6Bound.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_ABORTED           The DHCPv6 release exchange process aborted by user.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_RELEASE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|AddressCount
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|Addresses
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Stop the DHCPv6 S.A.R.R process.    The Stop() function is used to stop the DHCPv6 S.A.R.R process. If this function is called   successfully, all the IPv6 addresses of the configured IA will be released and the state of   the configured IA will be transferred to Dhcp6Init.       @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.    @retval EFI_SUCCESS           The DHCPv6 S.A.R.R process has been stopped when                                 EFI_DHCP6_CONFIG_DATA.IaInfoEvent is NULL.                                 The EFI DHCPv6 Protocol instance has sent Release packet if                                 need release or has been stopped if needn't, when                                 EFI_DHCP6_CONFIG_DATA.IaInfoEvent is not NULL.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Parse the option data in the DHCPv6 packet.    The Parse() function is used to retrieve the option list in the DHCPv6 packet.     @param[in]  This              Pointer to the EFI_DHCP6_PROTOCOL instance.    @param[in]  Packet            Pointer to packet to be parsed.   @param[in]  OptionCount       On input, the number of entries in the PacketOptionList.                                 On output, the number of DHCPv6 options in the Packet.   @param[in]  PacketOptionList  List of pointers to the DHCPv6 options in the Packet.                                 The OpCode and OpLen in EFI_DHCP6_PACKET_OPTION are                                 both stored in network byte order.   @retval EFI_SUCCESS           The packet was successfully parsed.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE                                 - This is NULL.                                 - Packet is NULL.                                 - Packet is not a well-formed DHCPv6 packet.                                 - OptionCount is NULL.                                 - *OptionCount is not zero and PacketOptionList is NULL.   @retval EFI_BUFFER_TOO_SMALL  *OptionCount is smaller than the number of options that were                                  found in the Packet.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP6_PARSE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP6_PACKET
modifier|*
name|Packet
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|OptionCount
parameter_list|,
name|OUT
name|EFI_DHCP6_PACKET_OPTION
modifier|*
name|PacketOptionList
index|[]
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI DHCPv6 Protocol is used to get IPv6 addresses and other configuration parameters
end_comment

begin_comment
comment|/// from DHCPv6 servers.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DHCP6_PROTOCOL
block|{
name|EFI_DHCP6_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_DHCP6_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_DHCP6_START
name|Start
decl_stmt|;
name|EFI_DHCP6_INFO_REQUEST
name|InfoRequest
decl_stmt|;
name|EFI_DHCP6_RENEW_REBIND
name|RenewRebind
decl_stmt|;
name|EFI_DHCP6_DECLINE
name|Decline
decl_stmt|;
name|EFI_DHCP6_RELEASE
name|Release
decl_stmt|;
name|EFI_DHCP6_STOP
name|Stop
decl_stmt|;
name|EFI_DHCP6_PARSE
name|Parse
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDhcp6ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDhcp6ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

