begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_DHCP4_PROTOCOL as defined in UEFI 2.0.   EFI_DHCP4_SERVICE_BINDING_PROTOCOL as defined in UEFI 2.0.   These protocols are used to collect configuration information for the EFI IPv4 Protocol   drivers and to provide DHCPv4 server and PXE boot server discovery services.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol was introduced in UEFI Specification 2.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DHCP4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DHCP4_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_DHCP4_PROTOCOL_GUID
define|\
value|{ \     0x8a219718, 0x4ef5, 0x4761, {0x91, 0xc8, 0xc0, 0xf0, 0x4b, 0xda, 0x9e, 0x56 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_DHCP4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x9d9a39d8, 0xbd42, 0x4a73, {0xa4, 0xd5, 0x8e, 0xe9, 0x4b, 0xe1, 0x13, 0x80 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DHCP4_PROTOCOL
name|EFI_DHCP4_PROTOCOL
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// DHCP option code.
comment|///
name|UINT8
name|OpCode
decl_stmt|;
comment|///
comment|/// Length of the DHCP option data. Not present if OpCode is 0 or 255.
comment|///
name|UINT8
name|Length
decl_stmt|;
comment|///
comment|/// Start of the DHCP option data. Not present if OpCode is 0 or 255 or if Length is zero.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_DHCP4_PACKET_OPTION
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

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
comment|/// EFI_DHCP4_PACKET defines the format of DHCPv4 packets. See RFC 2131 for more information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|OpCode
decl_stmt|;
name|UINT8
name|HwType
decl_stmt|;
name|UINT8
name|HwAddrLen
decl_stmt|;
name|UINT8
name|Hops
decl_stmt|;
name|UINT32
name|Xid
decl_stmt|;
name|UINT16
name|Seconds
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|ClientAddr
decl_stmt|;
comment|///< Client IP address from client.
name|EFI_IPv4_ADDRESS
name|YourAddr
decl_stmt|;
comment|///< Client IP address from server.
name|EFI_IPv4_ADDRESS
name|ServerAddr
decl_stmt|;
comment|///< IP address of next server in bootstrap.
name|EFI_IPv4_ADDRESS
name|GatewayAddr
decl_stmt|;
comment|///< Relay agent IP address.
name|UINT8
name|ClientHwAddr
index|[
literal|16
index|]
decl_stmt|;
comment|///< Client hardware address.
name|CHAR8
name|ServerName
index|[
literal|64
index|]
decl_stmt|;
name|CHAR8
name|BootFileName
index|[
literal|128
index|]
decl_stmt|;
block|}
name|EFI_DHCP4_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Size of the EFI_DHCP4_PACKET buffer.
comment|///
name|UINT32
name|Size
decl_stmt|;
comment|///
comment|/// Length of the EFI_DHCP4_PACKET from the first byte of the Header field
comment|/// to the last byte of the Option[] field.
comment|///
name|UINT32
name|Length
decl_stmt|;
struct|struct
block|{
comment|///
comment|/// DHCP packet header.
comment|///
name|EFI_DHCP4_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// DHCP magik cookie in network byte order.
comment|///
name|UINT32
name|Magik
decl_stmt|;
comment|///
comment|/// Start of the DHCP packed option data.
comment|///
name|UINT8
name|Option
index|[
literal|1
index|]
decl_stmt|;
block|}
name|Dhcp4
struct|;
block|}
name|EFI_DHCP4_PACKET
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
enum|enum
block|{
comment|///
comment|/// The EFI DHCPv4 Protocol driver is stopped.
comment|///
name|Dhcp4Stopped
init|=
literal|0x0
block|,
comment|///
comment|/// The EFI DHCPv4 Protocol driver is inactive.
comment|///
name|Dhcp4Init
init|=
literal|0x1
block|,
comment|///
comment|/// The EFI DHCPv4 Protocol driver is collecting DHCP offer packets from DHCP servers.
comment|///
name|Dhcp4Selecting
init|=
literal|0x2
block|,
comment|///
comment|/// The EFI DHCPv4 Protocol driver has sent the request to the DHCP server and is waiting for a response.
comment|///
name|Dhcp4Requesting
init|=
literal|0x3
block|,
comment|///
comment|/// The DHCP configuration has completed.
comment|///
name|Dhcp4Bound
init|=
literal|0x4
block|,
comment|///
comment|/// The DHCP configuration is being renewed and another request has
comment|/// been sent out, but it has not received a response from the server yet.
comment|///
name|Dhcp4Renewing
init|=
literal|0x5
block|,
comment|///
comment|/// The DHCP configuration has timed out and the EFI DHCPv4
comment|/// Protocol driver is trying to extend the lease time.
comment|///
name|Dhcp4Rebinding
init|=
literal|0x6
block|,
comment|///
comment|/// The EFI DHCPv4 Protocol driver was initialized with a previously
comment|/// allocated or known IP address.
comment|///
name|Dhcp4InitReboot
init|=
literal|0x7
block|,
comment|///
comment|/// The EFI DHCPv4 Protocol driver is seeking to reuse the previously
comment|/// allocated IP address by sending a request to the DHCP server.
comment|///
name|Dhcp4Rebooting
init|=
literal|0x8
block|}
name|EFI_DHCP4_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The packet to start the configuration sequence is about to be sent.
comment|///
name|Dhcp4SendDiscover
init|=
literal|0x01
block|,
comment|///
comment|/// A reply packet was just received.
comment|///
name|Dhcp4RcvdOffer
init|=
literal|0x02
block|,
comment|///
comment|/// It is time for Dhcp4Callback to select an offer.
comment|///
name|Dhcp4SelectOffer
init|=
literal|0x03
block|,
comment|///
comment|/// A request packet is about to be sent.
comment|///
name|Dhcp4SendRequest
init|=
literal|0x04
block|,
comment|///
comment|/// A DHCPACK packet was received and will be passed to Dhcp4Callback.
comment|///
name|Dhcp4RcvdAck
init|=
literal|0x05
block|,
comment|///
comment|/// A DHCPNAK packet was received and will be passed to Dhcp4Callback.
comment|///
name|Dhcp4RcvdNak
init|=
literal|0x06
block|,
comment|///
comment|/// A decline packet is about to be sent.
comment|///
name|Dhcp4SendDecline
init|=
literal|0x07
block|,
comment|///
comment|/// The DHCP configuration process has completed. No packet is associated with this event.
comment|///
name|Dhcp4BoundCompleted
init|=
literal|0x08
block|,
comment|///
comment|/// It is time to enter the Dhcp4Renewing state and to contact the server
comment|/// that originally issued the network address. No packet is associated with this event.
comment|///
name|Dhcp4EnterRenewing
init|=
literal|0x09
block|,
comment|///
comment|/// It is time to enter the Dhcp4Rebinding state and to contact any server.
comment|/// No packet is associated with this event.
comment|///
name|Dhcp4EnterRebinding
init|=
literal|0x0a
block|,
comment|///
comment|/// The configured IP address was lost either because the lease has expired,
comment|/// the user released the configuration, or a DHCPNAK packet was received in
comment|/// the Dhcp4Renewing or Dhcp4Rebinding state. No packet is associated with this event.
comment|///
name|Dhcp4AddressLost
init|=
literal|0x0b
block|,
comment|///
comment|/// The DHCP process failed because a DHCPNAK packet was received or the user
comment|/// aborted the DHCP process at a time when the configuration was not available yet.
comment|/// No packet is associated with this event.
comment|///
name|Dhcp4Fail
init|=
literal|0x0c
block|}
name|EFI_DHCP4_EVENT
typedef|;
end_typedef

begin_comment
comment|/**   Callback routine.      EFI_DHCP4_CALLBACK is provided by the consumer of the EFI DHCPv4 Protocol driver   to intercept events that occurred in the configuration process. This structure   provides advanced control of each state transition of the DHCP process. The   returned status code determines the behavior of the EFI DHCPv4 Protocol driver.   There are three possible returned values, which are described in the following   table.    @param  This                  The pointer to the EFI DHCPv4 Protocol instance that is used to                                 configure this callback function.   @param  Context               The pointer to the context that is initialized by                                 EFI_DHCP4_PROTOCOL.Configure().   @param  CurrentState          The current operational state of the EFI DHCPv4 Protocol                                 driver.   @param  Dhcp4Event            The event that occurs in the current state, which usually means a                                 state transition.   @param  Packet                The DHCP packet that is going to be sent or already received.   @param  NewPacket             The packet that is used to replace the above Packet.    @retval EFI_SUCCESS           Tells the EFI DHCPv4 Protocol driver to continue the DHCP process.                                 When it is in the Dhcp4Selecting state, it tells the EFI DHCPv4 Protocol                                 driver to stop collecting additional packets. The driver will exit                                 the Dhcp4Selecting state and enter the Dhcp4Requesting state.   @retval EFI_NOT_READY         Only used in the Dhcp4Selecting state. The EFI DHCPv4 Protocol                                 driver will continue to wait for more packets until the retry                                 timeout expires.   @retval EFI_ABORTED           Tells the EFI DHCPv4 Protocol driver to abort the current process and                                 return to the Dhcp4Init or Dhcp4InitReboot state.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_DHCP4_STATE
name|CurrentState
parameter_list|,
name|IN
name|EFI_DHCP4_EVENT
name|Dhcp4Event
parameter_list|,
name|IN
name|EFI_DHCP4_PACKET
modifier|*
name|Packet
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_DHCP4_PACKET
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
comment|/// The number of times to try sending a packet during the Dhcp4SendDiscover
comment|/// event and waiting for a response during the Dhcp4RcvdOffer event.
comment|/// Set to zero to use the default try counts and timeout values.
comment|///
name|UINT32
name|DiscoverTryCount
decl_stmt|;
comment|///
comment|/// The maximum amount of time (in seconds) to wait for returned packets in each
comment|/// of the retries. Timeout values of zero will default to a timeout value
comment|/// of one second. Set to NULL to use default timeout values.
comment|///
name|UINT32
modifier|*
name|DiscoverTimeout
decl_stmt|;
comment|///
comment|/// The number of times to try sending a packet during the Dhcp4SendRequest event
comment|/// and waiting for a response during the Dhcp4RcvdAck event before accepting
comment|/// failure. Set to zero to use the default try counts and timeout values.
comment|///
name|UINT32
name|RequestTryCount
decl_stmt|;
comment|///
comment|/// The maximum amount of time (in seconds) to wait for return packets in each of the retries.
comment|/// Timeout values of zero will default to a timeout value of one second.
comment|/// Set to NULL to use default timeout values.
comment|///
name|UINT32
modifier|*
name|RequestTimeout
decl_stmt|;
comment|///
comment|/// For a DHCPDISCOVER, setting this parameter to the previously allocated IP
comment|/// address will cause the EFI DHCPv4 Protocol driver to enter the Dhcp4InitReboot state.
comment|/// And set this field to 0.0.0.0 to enter the Dhcp4Init state.
comment|/// For a DHCPINFORM this parameter should be set to the client network address
comment|/// which was assigned to the client during a DHCPDISCOVER.
comment|///
name|EFI_IPv4_ADDRESS
name|ClientAddress
decl_stmt|;
comment|///
comment|/// The callback function to intercept various events that occurred in
comment|/// the DHCP configuration process. Set to NULL to ignore all those events.
comment|///
name|EFI_DHCP4_CALLBACK
name|Dhcp4Callback
decl_stmt|;
comment|///
comment|/// The pointer to the context that will be passed to Dhcp4Callback when it is called.
comment|///
name|VOID
modifier|*
name|CallbackContext
decl_stmt|;
comment|///
comment|/// Number of DHCP options in the OptionList.
comment|///
name|UINT32
name|OptionCount
decl_stmt|;
comment|///
comment|/// List of DHCP options to be included in every packet that is sent during the
comment|/// Dhcp4SendDiscover event. Pad options are appended automatically by DHCP driver
comment|/// in outgoing DHCP packets. If OptionList itself contains pad option, they are
comment|/// ignored by the driver. OptionList can be freed after EFI_DHCP4_PROTOCOL.Configure()
comment|/// returns. Ignored if OptionCount is zero.
comment|///
name|EFI_DHCP4_PACKET_OPTION
modifier|*
modifier|*
name|OptionList
decl_stmt|;
block|}
name|EFI_DHCP4_CONFIG_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The EFI DHCPv4 Protocol driver operating state.
comment|///
name|EFI_DHCP4_STATE
name|State
decl_stmt|;
comment|///
comment|/// The configuration data of the current EFI DHCPv4 Protocol driver instance.
comment|///
name|EFI_DHCP4_CONFIG_DATA
name|ConfigData
decl_stmt|;
comment|///
comment|/// The client IP address that was acquired from the DHCP server. If it is zero,
comment|/// the DHCP acquisition has not completed yet and the following fields in this structure are undefined.
comment|///
name|EFI_IPv4_ADDRESS
name|ClientAddress
decl_stmt|;
comment|///
comment|/// The local hardware address.
comment|///
name|EFI_MAC_ADDRESS
name|ClientMacAddress
decl_stmt|;
comment|///
comment|/// The server IP address that is providing the DHCP service to this client.
comment|///
name|EFI_IPv4_ADDRESS
name|ServerAddress
decl_stmt|;
comment|///
comment|/// The router IP address that was acquired from the DHCP server.
comment|/// May be zero if the server does not offer this address.
comment|///
name|EFI_IPv4_ADDRESS
name|RouterAddress
decl_stmt|;
comment|///
comment|/// The subnet mask of the connected network that was acquired from the DHCP server.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// The lease time (in 1-second units) of the configured IP address.
comment|/// The value 0xFFFFFFFF means that the lease time is infinite.
comment|/// A default lease of 7 days is used if the DHCP server does not provide a value.
comment|///
name|UINT32
name|LeaseTime
decl_stmt|;
comment|///
comment|/// The cached latest DHCPACK or DHCPNAK or BOOTP REPLY packet. May be NULL if no packet is cached.
comment|///
name|EFI_DHCP4_PACKET
modifier|*
name|ReplyPacket
decl_stmt|;
block|}
name|EFI_DHCP4_MODE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Alternate listening address. It can be a unicast, multicast, or broadcast address.
comment|///
name|EFI_IPv4_ADDRESS
name|ListenAddress
decl_stmt|;
comment|///
comment|/// The subnet mask of above listening unicast/broadcast IP address.
comment|/// Ignored if ListenAddress is a multicast address.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// Alternate station source (or listening) port number.
comment|/// If zero, then the default station port number (68) will be used.
comment|///
name|UINT16
name|ListenPort
decl_stmt|;
block|}
name|EFI_DHCP4_LISTEN_POINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The completion status of transmitting and receiving.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// If not NULL, the event that will be signaled when the collection process
comment|/// completes. If NULL, this function will busy-wait until the collection process competes.
comment|///
name|EFI_EVENT
name|CompletionEvent
decl_stmt|;
comment|///
comment|/// The pointer to the server IP address. This address may be a unicast, multicast, or broadcast address.
comment|///
name|EFI_IPv4_ADDRESS
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// The server listening port number. If zero, the default server listening port number (67) will be used.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
comment|///
comment|/// The pointer to the gateway address to override the existing setting.
comment|///
name|EFI_IPv4_ADDRESS
name|GatewayAddress
decl_stmt|;
comment|///
comment|/// The number of entries in ListenPoints. If zero, the default station address and port number 68 are used.
comment|///
name|UINT32
name|ListenPointCount
decl_stmt|;
comment|///
comment|/// An array of station address and port number pairs that are used as receiving filters.
comment|/// The first entry is also used as the source address and source port of the outgoing packet.
comment|///
name|EFI_DHCP4_LISTEN_POINT
modifier|*
name|ListenPoints
decl_stmt|;
comment|///
comment|/// The number of seconds to collect responses. Zero is invalid.
comment|///
name|UINT32
name|TimeoutValue
decl_stmt|;
comment|///
comment|/// The pointer to the packet to be transmitted.
comment|///
name|EFI_DHCP4_PACKET
modifier|*
name|Packet
decl_stmt|;
comment|///
comment|/// Number of received packets.
comment|///
name|UINT32
name|ResponseCount
decl_stmt|;
comment|///
comment|/// The pointer to the allocated list of received packets.
comment|///
name|EFI_DHCP4_PACKET
modifier|*
name|ResponseList
decl_stmt|;
block|}
name|EFI_DHCP4_TRANSMIT_RECEIVE_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Returns the current operating mode and cached data packet for the EFI DHCPv4 Protocol driver.      The GetModeData() function returns the current operating mode and cached data   packet for the EFI DHCPv4 Protocol driver.    @param  This          The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  Dhcp4ModeData The pointer to storage for the EFI_DHCP4_MODE_DATA structure.    @retval EFI_SUCCESS           The mode data was returned.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_DHCP4_MODE_DATA
modifier|*
name|Dhcp4ModeData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initializes, changes, or resets the operational settings for the EFI DHCPv4 Protocol driver.    The Configure() function is used to initialize, change, or reset the operational   settings of the EFI DHCPv4 Protocol driver for the communication device on which   the EFI DHCPv4 Service Binding Protocol is installed. This function can be   successfully called only if both of the following are true:   * This instance of the EFI DHCPv4 Protocol driver is in the Dhcp4Stopped, Dhcp4Init,     Dhcp4InitReboot, or Dhcp4Bound states.   * No other EFI DHCPv4 Protocol driver instance that is controlled by this EFI     DHCPv4 Service Binding Protocol driver instance has configured this EFI DHCPv4     Protocol driver.   When this driver is in the Dhcp4Stopped state, it can transfer into one of the   following two possible initial states:   * Dhcp4Init   * Dhcp4InitReboot.   The driver can transfer into these states by calling Configure() with a non-NULL   Dhcp4CfgData. The driver will transfer into the appropriate state based on the   supplied client network address in the ClientAddress parameter and DHCP options   in the OptionList parameter as described in RFC 2131.   When Configure() is called successfully while Dhcp4CfgData is set to NULL, the   default configuring data will be reset in the EFI DHCPv4 Protocol driver and   the state of the EFI DHCPv4 Protocol driver will not be changed. If one instance   wants to make it possible for another instance to configure the EFI DHCPv4 Protocol   driver, it must call this function with Dhcp4CfgData set to NULL.    @param  This                   The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  Dhcp4CfgData           The pointer to the EFI_DHCP4_CONFIG_DATA.    @retval EFI_SUCCESS           The EFI DHCPv4 Protocol driver is now in the Dhcp4Init or                                 Dhcp4InitReboot state, if the original state of this driver                                 was Dhcp4Stopped, Dhcp4Init,Dhcp4InitReboot, or Dhcp4Bound                                 and the value of Dhcp4CfgData was not NULL.                                 Otherwise, the state was left unchanged.   @retval EFI_ACCESS_DENIED     This instance of the EFI DHCPv4 Protocol driver was not in the                                 Dhcp4Stopped, Dhcp4Init, Dhcp4InitReboot, or Dhcp4Bound state;                                 Or onother instance of this EFI DHCPv4 Protocol driver is already                                 in a valid configured state.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE:                                 This is NULL.                                 DiscoverTryCount> 0 and DiscoverTimeout is NULL                                 RequestTryCount> 0 and RequestTimeout is NULL.                                 OptionCount>0 and OptionList is NULL.                                 ClientAddress is not a valid unicast address.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP4_CONFIG_DATA
modifier|*
name|Dhcp4CfgData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Starts the DHCP configuration process.    The Start() function starts the DHCP configuration process. This function can   be called only when the EFI DHCPv4 Protocol driver is in the Dhcp4Init or   Dhcp4InitReboot state.   If the DHCP process completes successfully, the state of the EFI DHCPv4 Protocol   driver will be transferred through Dhcp4Selecting and Dhcp4Requesting to the   Dhcp4Bound state. The CompletionEvent will then be signaled if it is not NULL.   If the process aborts, either by the user or by some unexpected network error,   the state is restored to the Dhcp4Init state. The Start() function can be called   again to restart the process.   Refer to RFC 2131 for precise state transitions during this process. At the   time when each event occurs in this process, the callback function that was set   by EFI_DHCP4_PROTOCOL.Configure() will be called and the user can take this   opportunity to control the process.      @param  This            The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  CompletionEvent If not NULL, it indicates the event that will be signaled when the                           EFI DHCPv4 Protocol driver is transferred into the                           Dhcp4Bound state or when the DHCP process is aborted.                           EFI_DHCP4_PROTOCOL.GetModeData() can be called to                           check the completion status. If NULL,                           EFI_DHCP4_PROTOCOL.Start() will wait until the driver                           is transferred into the Dhcp4Bound state or the process fails.    @retval EFI_SUCCESS           The DHCP configuration process has started, or it has completed                                 when CompletionEvent is NULL.   @retval EFI_NOT_STARTED       The EFI DHCPv4 Protocol driver is in the Dhcp4Stopped                                 state. EFI_DHCP4_PROTOCOL. Configure() needs to be called.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_TIMEOUT           The DHCP configuration process failed because no response was                                 received from the server within the specified timeout value.   @retval EFI_ABORTED           The user aborted the DHCP process.   @retval EFI_ALREADY_STARTED   Some other EFI DHCPv4 Protocol instance already started the                                 DHCP process.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval EFI_NO_MEDIA          There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_START
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EVENT
name|CompletionEvent
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Extends the lease time by sending a request packet.      The RenewRebind() function is used to manually extend the lease time when the   EFI DHCPv4 Protocol driver is in the Dhcp4Bound state, and the lease time has   not expired yet. This function will send a request packet to the previously   found server (or to any server when RebindRequest is TRUE) and transfer the   state into the Dhcp4Renewing state (or Dhcp4Rebinding when RebindingRequest is   TRUE). When a response is received, the state is returned to Dhcp4Bound.   If no response is received before the try count is exceeded (the RequestTryCount   field that is specified in EFI_DHCP4_CONFIG_DATA) but before the lease time that   was issued by the previous server expires, the driver will return to the Dhcp4Bound   state, and the previous configuration is restored. The outgoing and incoming packets   can be captured by the EFI_DHCP4_CALLBACK function.    @param  This            The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  RebindRequest   If TRUE, this function broadcasts the request packets and enters                           the Dhcp4Rebinding state. Otherwise, it sends a unicast                           request packet and enters the Dhcp4Renewing state.   @param  CompletionEvent If not NULL, this event is signaled when the renew/rebind phase                           completes or some error occurs.                           EFI_DHCP4_PROTOCOL.GetModeData() can be called to                           check the completion status. If NULL,                           EFI_DHCP4_PROTOCOL.RenewRebind() will busy-wait                           until the DHCP process finishes.    @retval EFI_SUCCESS           The EFI DHCPv4 Protocol driver is now in the                                 Dhcp4Renewing state or is back to the Dhcp4Bound state.   @retval EFI_NOT_STARTED       The EFI DHCPv4 Protocol driver is in the Dhcp4Stopped                                 state. EFI_DHCP4_PROTOCOL.Configure() needs to                                 be called.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_TIMEOUT           There was no response from the server when the try count was                                 exceeded.   @retval EFI_ACCESS_DENIED     The driver is not in the Dhcp4Bound state.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_RENEW_REBIND
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|RebindRequest
parameter_list|,
name|IN
name|EFI_EVENT
name|CompletionEvent
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Releases the current address configuration.    The Release() function releases the current configured IP address by doing either   of the following:   * Sending a DHCPRELEASE packet when the EFI DHCPv4 Protocol driver is in the     Dhcp4Bound state   * Setting the previously assigned IP address that was provided with the     EFI_DHCP4_PROTOCOL.Configure() function to 0.0.0.0 when the driver is in     Dhcp4InitReboot state   After a successful call to this function, the EFI DHCPv4 Protocol driver returns   to the Dhcp4Init state, and any subsequent incoming packets will be discarded silently.    @param  This                  The pointer to the EFI_DHCP4_PROTOCOL instance.    @retval EFI_SUCCESS           The EFI DHCPv4 Protocol driver is now in the Dhcp4Init phase.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_ACCESS_DENIED     The EFI DHCPv4 Protocol driver is not Dhcp4InitReboot state.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_RELEASE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Stops the current address configuration.      The Stop() function is used to stop the DHCP configuration process. After this   function is called successfully, the EFI DHCPv4 Protocol driver is transferred   into the Dhcp4Stopped state. EFI_DHCP4_PROTOCOL.Configure() needs to be called   before DHCP configuration process can be started again. This function can be   called when the EFI DHCPv4 Protocol driver is in any state.    @param  This                  The pointer to the EFI_DHCP4_PROTOCOL instance.    @retval EFI_SUCCESS           The EFI DHCPv4 Protocol driver is now in the Dhcp4Stopped phase.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Builds a DHCP packet, given the options to be appended or deleted or replaced.    The Build() function is used to assemble a new packet from the original packet   by replacing or deleting existing options or appending new options. This function   does not change any state of the EFI DHCPv4 Protocol driver and can be used at   any time.    @param  This        The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  SeedPacket  Initial packet to be used as a base for building new packet.   @param  DeleteCount Number of opcodes in the DeleteList.   @param  DeleteList  List of opcodes to be deleted from the seed packet.                       Ignored if DeleteCount is zero.   @param  AppendCount Number of entries in the OptionList.   @param  AppendList  The pointer to a DHCP option list to be appended to SeedPacket.                       If SeedPacket also contains options in this list, they are                       replaced by new options (except pad option). Ignored if                       AppendCount is zero. Type EFI_DHCP4_PACKET_OPTION   @param  NewPacket   The pointer to storage for the pointer to the new allocated packet.                       Use the EFI Boot Service FreePool() on the resulting pointer                       when done with the packet.    @retval EFI_SUCCESS           The new packet was built.   @retval EFI_OUT_OF_RESOURCES  Storage for the new packet could not be allocated.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 This is NULL.                                 SeedPacket is NULL.                                 SeedPacket is not a well-formed DHCP packet.                                 AppendCount is not zero and AppendList is NULL.                                 DeleteCount is not zero and DeleteList is NULL.                                 NewPacket is NULL                                 Both DeleteCount and AppendCount are zero and                                 NewPacket is not NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_BUILD
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP4_PACKET
modifier|*
name|SeedPacket
parameter_list|,
name|IN
name|UINT32
name|DeleteCount
parameter_list|,
name|IN
name|UINT8
modifier|*
name|DeleteList
name|OPTIONAL
parameter_list|,
name|IN
name|UINT32
name|AppendCount
parameter_list|,
name|IN
name|EFI_DHCP4_PACKET_OPTION
modifier|*
name|AppendList
index|[]
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_DHCP4_PACKET
modifier|*
modifier|*
name|NewPacket
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Transmits a DHCP formatted packet and optionally waits for responses.      The TransmitReceive() function is used to transmit a DHCP packet and optionally   wait for the response from servers. This function does not change the state of   the EFI DHCPv4 Protocol driver. It can be used at any time because of this.    @param  This    The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  Token   The pointer to the EFI_DHCP4_TRANSMIT_RECEIVE_TOKEN structure.    @retval EFI_SUCCESS           The packet was successfully queued for transmission.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 This is NULL.                                 Token.RemoteAddress is zero.                                 Token.Packet is NULL.                                 Token.Packet is not a well-formed DHCP packet.                                 The transaction ID in Token.Packet is in use by another DHCP process.   @retval EFI_NOT_READY         The previous call to this function has not finished yet. Try to call                                 this function after collection process completes.   @retval EFI_NO_MAPPING        The default station address is not available yet.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_UNSUPPORTED       The implementation doesn't support this function   @retval Others                Some other unexpected error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_TRANSMIT_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP4_TRANSMIT_RECEIVE_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Parses the packed DHCP option data.      The Parse() function is used to retrieve the option list from a DHCP packet.   If *OptionCount isn't zero, and there is enough space for all the DHCP options   in the Packet, each element of PacketOptionList is set to point to somewhere in   the Packet->Dhcp4.Option where a new DHCP option begins. If RFC3396 is supported,   the caller should reassemble the parsed DHCP options to get the final result.   If *OptionCount is zero or there isn't enough space for all of them, the number   of DHCP options in the Packet is returned in OptionCount.    @param  This             The pointer to the EFI_DHCP4_PROTOCOL instance.   @param  Packet           The pointer to packet to be parsed.   @param  OptionCount      On input, the number of entries in the PacketOptionList.                            On output, the number of entries that were written into the                            PacketOptionList.   @param  PacketOptionList A list of packet option entries to be filled in. End option or pad                            options are not included.    @retval EFI_SUCCESS           The packet was successfully parsed.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 This is NULL.                                 The packet is NULL.                                 The packet is not a well-formed DHCP packet.                                 OptionCount is NULL.   @retval EFI_BUFFER_TOO_SMALL  One or more of the following conditions is TRUE:                                 1) *OptionCount is smaller than the number of options that                                 were found in the Packet.                                 2) PacketOptionList is NULL.   @retval EFI_OUT_OF_RESOURCE   The packet failed to parse because of a resource shortage.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DHCP4_PARSE
function_decl|)
parameter_list|(
name|IN
name|EFI_DHCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DHCP4_PACKET
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
name|EFI_DHCP4_PACKET_OPTION
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
comment|/// This protocol is used to collect configuration information for the EFI IPv4 Protocol drivers
end_comment

begin_comment
comment|/// and to provide DHCPv4 server and PXE boot server discovery services.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DHCP4_PROTOCOL
block|{
name|EFI_DHCP4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_DHCP4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_DHCP4_START
name|Start
decl_stmt|;
name|EFI_DHCP4_RENEW_REBIND
name|RenewRebind
decl_stmt|;
name|EFI_DHCP4_RELEASE
name|Release
decl_stmt|;
name|EFI_DHCP4_STOP
name|Stop
decl_stmt|;
name|EFI_DHCP4_BUILD
name|Build
decl_stmt|;
name|EFI_DHCP4_TRANSMIT_RECEIVE
name|TransmitReceive
decl_stmt|;
name|EFI_DHCP4_PARSE
name|Parse
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDhcp4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDhcp4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

