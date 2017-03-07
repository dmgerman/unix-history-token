begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI IPSEC Protocol Definition   The EFI_IPSEC_PROTOCOL is used to abstract the ability to deal with the individual   packets sent and received by the host and provide packet-level security for IP    datagram.   The EFI_IPSEC2_PROTOCOL is used to abstract the ability to deal with the individual   packets sent and received by the host and provide packet-level security for IP    datagram. In addition, it supports the Option (extension header) processing in    IPsec which doesn't support in EFI_IPSEC_PROTOCOL. It is also recommended to    use EFI_IPSEC2_PROTOCOL instead of EFI_IPSEC_PROTOCOL especially for IPsec Tunnel    Mode.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             The EFI_IPSEC2_PROTOCOL is introduced in UEFI Specification 2.3D.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IPSEC_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IPSEC_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/IpSecConfig.h>
end_include

begin_define
define|#
directive|define
name|EFI_IPSEC_PROTOCOL_GUID
define|\
value|{ \     0xdfb386f7, 0xe100, 0x43ad, {0x9c, 0x9a, 0xed, 0x90, 0xd0, 0x8a, 0x5e, 0x12 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_IPSEC2_PROTOCOL_GUID
define|\
value|{ \     0xa3979e64, 0xace8, 0x4ddc, {0xbc, 0x7, 0x4d, 0x66, 0xb8, 0xfd, 0x9, 0x77 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IPSEC_PROTOCOL
name|EFI_IPSEC_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_IPSEC2_PROTOCOL
name|EFI_IPSEC2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_FRAGMENT_DATA
end_comment

begin_comment
comment|/// defines the instances of packet fragments.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_FRAGMENT_DATA
block|{
name|UINT32
name|FragmentLength
decl_stmt|;
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
block|}
name|EFI_IPSEC_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Handles IPsec packet processing for inbound and outbound IP packets.     The EFI_IPSEC_PROCESS process routine handles each inbound or outbound packet.   The behavior is that it can perform one of the following actions:    bypass the packet, discard the packet, or protect the packet.           @param[in]      This             Pointer to the EFI_IPSEC_PROTOCOL instance.   @param[in]      NicHandle        Instance of the network interface.   @param[in]      IpVer            IPV4 or IPV6.   @param[in, out] IpHead           Pointer to the IP Header.   @param[in]      LastHead         The protocol of the next layer to be processed by IPsec.   @param[in]      OptionsBuffer    Pointer to the options buffer.    @param[in]      OptionsLength    Length of the options buffer.   @param[in, out] FragmentTable    Pointer to a list of fragments.    @param[in]      FragmentCount    Number of fragments.   @param[in]      TrafficDirection Traffic direction.   @param[out]     RecycleSignal    Event for recycling of resources.     @retval EFI_SUCCESS              The packet was bypassed and all buffers remain the same.   @retval EFI_SUCCESS              The packet was protected.   @retval EFI_ACCESS_DENIED        The packet was discarded.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_PROCESS
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|NicHandle
parameter_list|,
name|IN
name|UINT8
name|IpVer
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|IpHead
parameter_list|,
name|IN
name|UINT8
modifier|*
name|LastHead
parameter_list|,
name|IN
name|VOID
modifier|*
name|OptionsBuffer
parameter_list|,
name|IN
name|UINT32
name|OptionsLength
parameter_list|,
name|IN
name|OUT
name|EFI_IPSEC_FRAGMENT_DATA
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
name|EFI_IPSEC_TRAFFIC_DIR
name|TrafficDirection
parameter_list|,
name|OUT
name|EFI_EVENT
modifier|*
name|RecycleSignal
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_PROTOCOL
end_comment

begin_comment
comment|/// provides the ability for  securing IP communications by authenticating
end_comment

begin_comment
comment|/// and/or encrypting each IP packet in a data stream.
end_comment

begin_comment
comment|//  EFI_IPSEC_PROTOCOL can be consumed by both the IPv4 and IPv6 stack.
end_comment

begin_comment
comment|//  A user can employ this protocol for IPsec package handling in both IPv4
end_comment

begin_comment
comment|//  and IPv6 environment.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IPSEC_PROTOCOL
block|{
name|EFI_IPSEC_PROCESS
name|Process
decl_stmt|;
comment|///< Handle the IPsec message.
name|EFI_EVENT
name|DisabledEvent
decl_stmt|;
comment|///< Event signaled when the interface is disabled.
name|BOOLEAN
name|DisabledFlag
decl_stmt|;
comment|///< State of the interface.
block|}
struct|;
end_struct

begin_comment
comment|/**   Handles IPsec processing for both inbound and outbound IP packets. Compare with    Process() in EFI_IPSEC_PROTOCOL, this interface has the capability to process    Option(Extension Header).     The EFI_IPSEC2_PROCESS process routine handles each inbound or outbound packet.   The behavior is that it can perform one of the following actions:    bypass the packet, discard the packet, or protect the packet.      @param[in]       This               Pointer to the EFI_IPSEC2_PROTOCOL instance.   @param[in]       NicHandle          Instance of the network interface.    @param[in]       IpVer              IP version.IPv4 or IPv6.   @param[in, out]  IpHead             Pointer to the IP Header it is either                                        the EFI_IP4_HEADER or EFI_IP6_HEADER.                                       On input, it contains the IP header.                                        On output, 1) in tunnel mode and the                                        traffic direction is inbound, the buffer                                        will be reset to zero by IPsec; 2) in                                        tunnel mode and the traffic direction                                        is outbound, the buffer will reset to                                        be the tunnel IP header.3) in transport                                        mode, the related fielders (like payload                                        length, Next header) in IP header will                                        be modified according to the condition.   @param[in, out]  LastHead           For IP4, it is the next protocol in IP                                       header. For IP6 it is the Next Header                                        of the last extension header.   @param[in, out]  OptionsBuffer      On input, it contains the options                                        (extensions header) to be processed by                                        IPsec. On output, 1) in tunnel mode and                                       the traffic direction is outbound, it                                        will be set to NULL, and that means this                                        contents was wrapped after inner header                                        and should not be concatenated after                                        tunnel header again; 2) in transport                                        mode and the traffic direction is inbound,                                        if there are IP options (extension headers)                                        protected by IPsec, IPsec will concatenate                                        the those options after the input options                                        (extension headers); 3) on other situations,                                        the output of contents of OptionsBuffer                                        might be same with input's. The caller                                        should take the responsibility to free                                        the buffer both on input and on output.   @param[in, out]  OptionsLength      On input, the input length of the options                                        buffer. On output, the output length of                                        the options buffer.   @param[in, out]  FragmentTable      Pointer to a list of fragments. On input,                                        these fragments contain the IP payload.                                        On output, 1) in tunnel mode and the traffic                                        direction is inbound, the fragments contain                                        the whole IP payload which is from the                                        IP inner header to the last byte of the                                        packet; 2) in tunnel mode and the traffic                                        direction is the outbound, the fragments                                        contains the whole encapsulated payload                                        which encapsulates the whole IP payload                                        between the encapsulated header and                                        encapsulated trailer fields. 3) in transport                                        mode and the traffic direction is inbound,                                        the fragments contains the IP payload                                        which is from the next layer protocol to                                        the last byte of the packet; 4) in transport                                        mode and the traffic direction is outbound,                                        the fragments contains the whole encapsulated                                        payload which encapsulates the next layer                                        protocol information between the encapsulated                                        header and encapsulated trailer fields.   @param[in, out]  FragmentCount      Number of fragments.   @param[in]       TrafficDirection   Traffic direction.   @param[out]      RecycleSignal      Event for recycling of resources.    @retval      EFI_SUCCESS           The packet was processed by IPsec successfully.   @retval      EFI_ACCESS_DENIED     The packet was discarded.   @retval      EFI_NOT_READY         The IKE negotiation is invoked and the packet                                       was discarded.   @retval      EFI_INVALID_PARAMETER One or more of following are TRUE:                                      If OptionsBuffer is NULL;                                      If OptionsLength is NULL;                                      If FragmentTable is NULL;                                      If FragmentCount is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_PROCESSEXT
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|NicHandle
parameter_list|,
name|IN
name|UINT8
name|IpVer
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|IpHead
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|LastHead
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|OptionsBuffer
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|OptionsLength
parameter_list|,
name|IN
name|OUT
name|EFI_IPSEC_FRAGMENT_DATA
modifier|*
modifier|*
name|FragmentTable
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|FragmentCount
parameter_list|,
name|IN
name|EFI_IPSEC_TRAFFIC_DIR
name|TrafficDirection
parameter_list|,
name|OUT
name|EFI_EVENT
modifier|*
name|RecycleSignal
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC2_PROTOCOL
end_comment

begin_comment
comment|/// supports the Option (extension header) processing in IPsec which doesn't support
end_comment

begin_comment
comment|/// in EFI_IPSEC_PROTOCOL. It is also recommended to use EFI_IPSEC2_PROTOCOL instead
end_comment

begin_comment
comment|/// of EFI_IPSEC_PROTOCOL especially for IPsec Tunnel Mode.
end_comment

begin_comment
comment|/// provides the ability for securing IP communications by authenticating and/or
end_comment

begin_comment
comment|/// encrypting each IP packet in a data stream.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IPSEC2_PROTOCOL
block|{
name|EFI_IPSEC_PROCESSEXT
name|ProcessExt
decl_stmt|;
name|EFI_EVENT
name|DisabledEvent
decl_stmt|;
name|BOOLEAN
name|DisabledFlag
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIpSecProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIpSec2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

