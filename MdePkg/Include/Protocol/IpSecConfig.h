begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI IPsec Configuration Protocol Definition   The EFI_IPSEC_CONFIG_PROTOCOL provides the mechanism to set and retrieve security and    policy related information for the EFI IPsec protocol driver.    Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IPSE_CCONFIG_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IPSE_CCONFIG_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_IPSEC_CONFIG_PROTOCOL_GUID
define|\
value|{ \     0xce5e5929, 0xc7a3, 0x4602, {0xad, 0x9e, 0xc9, 0xda, 0xf9, 0x4e, 0xbf, 0xcf } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IPSEC_CONFIG_PROTOCOL
name|EFI_IPSEC_CONFIG_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_CONFIG_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The IPsec Security Policy Database (aka SPD) setting.  In IPsec,
comment|/// an essential element of Security Association (SA) processing is
comment|/// underlying SPD that specifies what services are to be offered to
comment|/// IP datagram and in what fashion. The SPD must be consulted
comment|/// during the processing of all traffic (inbound and outbound),
comment|/// including traffic not protected by IPsec, that traverses the IPsec
comment|/// boundary. With this DataType, SetData() function is to set
comment|/// the SPD entry information, which may add one new entry, delete
comment|/// one existed entry or flush the whole database according to the
comment|/// parameter values. The corresponding Data is of type
comment|/// EFI_IPSEC_SPD_DATA
comment|///
name|IPsecConfigDataTypeSpd
block|,
comment|///
comment|/// The IPsec Security Association Database (aka SAD) setting. A
comment|/// SA is a simplex connection that affords security services to the
comment|/// traffic carried by it. Security services are afforded to an SA by the
comment|/// use of AH, or ESP, but not both. The corresponding Data is of
comment|/// type EFI_IPSEC_SAD_DATA.
comment|///
name|IPsecConfigDataTypeSad
block|,
comment|///
comment|/// The IPsec Peer Authorization Database (aka PAD) setting, which
comment|/// provides the link between the SPD and a security association
comment|/// management protocol. The PAD entry specifies the
comment|/// authentication protocol (e.g. IKEv1, IKEv2) method used and the
comment|/// authentication data. The corresponding Data is of type
comment|/// EFI_IPSEC_PAD_DATA.
comment|///
name|IPsecConfigDataTypePad
block|,
name|IPsecConfigDataTypeMaximum
block|}
name|EFI_IPSEC_CONFIG_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP_ADDRESS_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IP_ADDRESS_INFO
block|{
name|EFI_IP_ADDRESS
name|Address
decl_stmt|;
comment|///< The IPv4 or IPv6 address
name|UINT8
name|PrefixLength
decl_stmt|;
comment|///< The length of the prefix associated with the Address.
block|}
name|EFI_IP_ADDRESS_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SPD_SELECTOR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SPD_SELECTOR
block|{
comment|///
comment|/// Specifies the actual number of entries in LocalAddress.
comment|///
name|UINT32
name|LocalAddressCount
decl_stmt|;
comment|///
comment|/// A list of ranges of IPv4 or IPv6 addresses, which refers to the
comment|/// addresses being protected by IPsec policy.
comment|///
name|EFI_IP_ADDRESS_INFO
modifier|*
name|LocalAddress
decl_stmt|;
comment|///
comment|/// Specifies the actual number of entries in RemoteAddress.
comment|///
name|UINT32
name|RemoteAddressCount
decl_stmt|;
comment|///
comment|/// A list of ranges of IPv4 or IPv6 addresses, which are peer entities
comment|/// to LocalAddress.
comment|///
name|EFI_IP_ADDRESS_INFO
modifier|*
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// Next layer protocol. Obtained from the IPv4 Protocol or the IPv6
comment|/// Next Header fields. The next layer protocol is whatever comes
comment|/// after any IP extension headers that are present. A zero value is a
comment|/// wildcard that matches any value in NextLayerProtocol field.
comment|///
name|UINT16
name|NextLayerProtocol
decl_stmt|;
comment|///
comment|/// Local Port if the Next Layer Protocol uses two ports (as do TCP,
comment|/// UDP, and others). A zero value is a wildcard that matches any
comment|/// value in LocalPort field.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// A designed port range size. The start port is LocalPort, and
comment|/// the total number of ports is described by LocalPortRange.
comment|/// This field is ignored if NextLayerProtocol does not use
comment|/// ports.
comment|///
name|UINT16
name|LocalPortRange
decl_stmt|;
comment|///
comment|/// Remote Port if the Next Layer Protocol uses two ports. A zero
comment|/// value is a wildcard that matches any value in RemotePort field.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
comment|///
comment|/// A designed port range size. The start port is RemotePort, and
comment|/// the total number of ports is described by RemotePortRange.
comment|/// This field is ignored if NextLayerProtocol does not use ports.
comment|///
name|UINT16
name|RemotePortRange
decl_stmt|;
block|}
name|EFI_IPSEC_SPD_SELECTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_TRAFFIC_DIR
end_comment

begin_comment
comment|/// represents the directionality in an SPD entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The EfiIPsecInBound refers to traffic entering an IPsec implementation via
comment|/// the unprotected interface or emitted by the implementation on the unprotected
comment|/// side of the boundary and directed towards the protected interface.
comment|///
name|EfiIPsecInBound
block|,
comment|///
comment|/// The EfiIPsecOutBound refers to traffic entering the implementation via
comment|/// the protected interface, or emitted by the implementation on the protected side
comment|/// of the boundary and directed toward the unprotected interface.
comment|///
name|EfiIPsecOutBound
block|}
name|EFI_IPSEC_TRAFFIC_DIR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_ACTION
end_comment

begin_comment
comment|/// represents three possible processing choices.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Refers to traffic that is not allowed to traverse the IPsec boundary.
comment|///
name|EfiIPsecActionDiscard
block|,
comment|///
comment|/// Refers to traffic that is allowed to cross the IPsec boundary
comment|/// without protection.
comment|///
name|EfiIPsecActionBypass
block|,
comment|///
comment|/// Refers to traffic that is afforded IPsec protection, and for such
comment|/// traffic the SPD must specify the security protocols to be
comment|/// employed, their mode, security service options, and the
comment|/// cryptographic algorithms to be used.
comment|///
name|EfiIPsecActionProtect
block|}
name|EFI_IPSEC_ACTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SA_LIFETIME
end_comment

begin_comment
comment|/// defines the lifetime of an SA, which represents when a SA must be
end_comment

begin_comment
comment|/// replaced or terminated. A value of all 0 for each field removes
end_comment

begin_comment
comment|/// the limitation of a SA lifetime.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SA_LIFETIME
block|{
comment|///
comment|/// The number of bytes to which the IPsec cryptographic algorithm
comment|/// can be applied. For ESP, this is the encryption algorithm and for
comment|/// AH, this is the authentication algorithm. The ByteCount
comment|/// includes pad bytes for cryptographic operations.
comment|///
name|UINT64
name|ByteCount
decl_stmt|;
comment|///
comment|/// A time interval in second that warns the implementation to
comment|/// initiate action such as setting up a replacement SA.
comment|///
name|UINT64
name|SoftLifetime
decl_stmt|;
comment|///
comment|/// A time interval in second when the current SA ends and is
comment|/// destroyed.
comment|///
name|UINT64
name|HardLifetime
decl_stmt|;
block|}
name|EFI_IPSEC_SA_LIFETIME
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_MODE
end_comment

begin_comment
comment|/// There are two modes of IPsec operation: transport mode and tunnel mode. In
end_comment

begin_comment
comment|/// EfiIPsecTransport mode, AH and ESP provide protection primarily for next layer protocols;
end_comment

begin_comment
comment|/// In EfiIPsecTunnel mode, AH and ESP are applied to tunneled IP packets.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiIPsecTransport
block|,
name|EfiIPsecTunnel
block|}
name|EFI_IPSEC_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_TUNNEL_DF_OPTION
end_comment

begin_comment
comment|/// The option of copying the DF bit from an outbound package to
end_comment

begin_comment
comment|/// the tunnel mode header that it emits, when traffic is carried
end_comment

begin_comment
comment|/// via a tunnel mode SA. This applies to SAs where both inner and
end_comment

begin_comment
comment|/// outer headers are IPv4.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiIPsecTunnelClearDf
block|,
comment|///< Clear DF bit from inner header.
name|EfiIPsecTunnelSetDf
block|,
comment|///< Set DF bit from inner header.
name|EfiIPsecTunnelCopyDf
comment|///< Copy DF bit from inner header.
block|}
name|EFI_IPSEC_TUNNEL_DF_OPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_TUNNEL_OPTION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_TUNNEL_OPTION
block|{
comment|///
comment|/// Local tunnel address when IPsec mode is EfiIPsecTunnel.
comment|///
name|EFI_IP_ADDRESS
name|LocalTunnelAddress
decl_stmt|;
comment|///
comment|/// Remote tunnel address when IPsec mode is EfiIPsecTunnel.
comment|///
name|EFI_IP_ADDRESS
name|RemoteTunnelAddress
decl_stmt|;
comment|///
comment|/// The option of copying the DF bit from an outbound package
comment|/// to the tunnel mode header that it emits, when traffic is
comment|/// carried via a tunnel mode SA.
comment|///
name|EFI_IPSEC_TUNNEL_DF_OPTION
name|DF
decl_stmt|;
block|}
name|EFI_IPSEC_TUNNEL_OPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_PROTOCOL_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiIPsecAH
block|,
comment|///< IP Authentication Header protocol which is specified in RFC 4302.
name|EfiIPsecESP
comment|///< IP Encapsulating Security Payload which is specified in RFC 4303.
block|}
name|EFI_IPSEC_PROTOCOL_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_PROCESS_POLICY
end_comment

begin_comment
comment|/// describes a policy list for traffic processing.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_PROCESS_POLICY
block|{
comment|///
comment|/// Extended Sequence Number. Is this SA using extended sequence
comment|/// numbers. 64 bit counter is used if TRUE.
comment|///
name|BOOLEAN
name|ExtSeqNum
decl_stmt|;
comment|///
comment|/// A flag indicating whether overflow of the sequence number
comment|/// counter should generate an auditable event and prevent
comment|/// transmission of additional packets on the SA, or whether rollover
comment|/// is permitted.
comment|///
name|BOOLEAN
name|SeqOverflow
decl_stmt|;
comment|///
comment|/// Is this SA using stateful fragment checking. TRUE represents
comment|/// stateful fragment checking.
comment|///
name|BOOLEAN
name|FragCheck
decl_stmt|;
comment|///
comment|/// A time interval after which a SA must be replaced with a new SA
comment|/// (and new SPI) or terminated.
comment|///
name|EFI_IPSEC_SA_LIFETIME
name|SaLifetime
decl_stmt|;
comment|///
comment|/// IPsec mode: tunnel or transport.
comment|///
name|EFI_IPSEC_MODE
name|Mode
decl_stmt|;
comment|///
comment|/// Tunnel Option. TunnelOption is ignored if Mode is EfiIPsecTransport.
comment|///
name|EFI_IPSEC_TUNNEL_OPTION
modifier|*
name|TunnelOption
decl_stmt|;
comment|///
comment|/// IPsec protocol: AH or ESP
comment|///
name|EFI_IPSEC_PROTOCOL_TYPE
name|Proto
decl_stmt|;
comment|///
comment|/// Cryptographic algorithm type used for authentication.
comment|///
name|UINT8
name|AuthAlgoId
decl_stmt|;
comment|///
comment|/// Cryptographic algorithm type used for encryption. EncAlgo is
comment|/// NULL when IPsec protocol is AH. For ESP protocol, EncAlgo
comment|/// can also be used to describe the algorithm if a combined mode
comment|/// algorithm is used.
comment|///
name|UINT8
name|EncAlgoId
decl_stmt|;
block|}
name|EFI_IPSEC_PROCESS_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SA_ID
end_comment

begin_comment
comment|/// A triplet to identify an SA, consisting of the following members.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SA_ID
block|{
comment|///
comment|/// Security Parameter Index (aka SPI).  An arbitrary 32-bit value
comment|/// that is used by a receiver to identity the SA to which an incoming
comment|/// package should be bound.
comment|///
name|UINT32
name|Spi
decl_stmt|;
comment|///
comment|/// IPsec protocol: AH or ESP
comment|///
name|EFI_IPSEC_PROTOCOL_TYPE
name|Proto
decl_stmt|;
comment|///
comment|/// Destination IP address.
comment|///
name|EFI_IP_ADDRESS
name|DestAddress
decl_stmt|;
block|}
name|EFI_IPSEC_SA_ID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PEERID_LEN
value|128
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SPD_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SPD_DATA
block|{
comment|///
comment|/// A null-terminated ASCII name string which is used as a symbolic
comment|/// identifier for an IPsec Local or Remote address.
comment|///
name|UINT8
name|Name
index|[
name|MAX_PEERID_LEN
index|]
decl_stmt|;
comment|///
comment|/// Bit-mapped list describing Populate from Packet flags. When
comment|/// creating a SA, if PackageFlag bit is set to TRUE, instantiate
comment|/// the selector from the corresponding field in the package that
comment|/// triggered the creation of the SA, else from the value(s) in the
comment|/// corresponding SPD entry. The PackageFlag bit setting for
comment|/// corresponding selector field of EFI_IPSEC_SPD_SELECTOR:
comment|///     Bit 0: EFI_IPSEC_SPD_SELECTOR.LocalAddress
comment|///     Bit 1: EFI_IPSEC_SPD_SELECTOR.RemoteAddress
comment|///     Bit 2:
comment|/// EFI_IPSEC_SPD_SELECTOR.NextLayerProtocol
comment|///     Bit 3: EFI_IPSEC_SPD_SELECTOR.LocalPort
comment|///     Bit 4: EFI_IPSEC_SPD_SELECTOR.RemotePort
comment|///     Others: Reserved.
comment|///
name|UINT32
name|PackageFlag
decl_stmt|;
comment|///
comment|/// The traffic direction of data gram.
comment|///
name|EFI_IPSEC_TRAFFIC_DIR
name|TrafficDirection
decl_stmt|;
comment|///
comment|/// Processing choices to indicate which action is required by this
comment|/// policy.
comment|///
name|EFI_IPSEC_ACTION
name|Action
decl_stmt|;
comment|///
comment|/// The policy and rule information for a SPD entry.
comment|///
name|EFI_IPSEC_PROCESS_POLICY
modifier|*
name|ProcessingPolicy
decl_stmt|;
comment|///
comment|/// Specifies the actual number of entries in SaId list.
comment|///
name|UINTN
name|SaIdCount
decl_stmt|;
comment|///
comment|/// The SAD entry used for the traffic processing. The
comment|/// existed SAD entry links indicate this is the manual key case.
comment|///
name|EFI_IPSEC_SA_ID
name|SaId
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IPSEC_SPD_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_AH_ALGO_INFO
end_comment

begin_comment
comment|/// The security algorithm selection for IPsec AH authentication.
end_comment

begin_comment
comment|/// The required authentication algorithm is specified in RFC 4305.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_AH_ALGO_INFO
block|{
name|UINT8
name|AuthAlgoId
decl_stmt|;
name|UINTN
name|AuthKeyLength
decl_stmt|;
name|VOID
modifier|*
name|AuthKey
decl_stmt|;
block|}
name|EFI_IPSEC_AH_ALGO_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_ESP_ALGO_INFO
end_comment

begin_comment
comment|/// The security algorithm selection for IPsec ESP encryption and authentication.
end_comment

begin_comment
comment|/// The required authentication algorithm is specified in RFC 4305.
end_comment

begin_comment
comment|/// EncAlgoId fields can also specify an ESP combined mode algorithm
end_comment

begin_comment
comment|/// (e.g. AES with CCM mode, specified in RFC 4309), which provides both
end_comment

begin_comment
comment|/// confidentiality and authentication services.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_ESP_ALGO_INFO
block|{
name|UINT8
name|EncAlgoId
decl_stmt|;
name|UINTN
name|EncKeyLength
decl_stmt|;
name|VOID
modifier|*
name|EncKey
decl_stmt|;
name|UINT8
name|AuthAlgoId
decl_stmt|;
name|UINTN
name|AuthKeyLength
decl_stmt|;
name|VOID
modifier|*
name|AuthKey
decl_stmt|;
block|}
name|EFI_IPSEC_ESP_ALGO_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_ALGO_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_IPSEC_AH_ALGO_INFO
name|AhAlgoInfo
decl_stmt|;
name|EFI_IPSEC_ESP_ALGO_INFO
name|EspAlgoInfo
decl_stmt|;
block|}
name|EFI_IPSEC_ALGO_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SA_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SA_DATA
block|{
comment|///
comment|/// IPsec mode: tunnel or transport.
comment|///
name|EFI_IPSEC_MODE
name|Mode
decl_stmt|;
comment|///
comment|/// Sequence Number Counter. A 64-bit counter used to generate the
comment|/// sequence number field in AH or ESP headers.
comment|///
name|UINT64
name|SNCount
decl_stmt|;
comment|///
comment|/// Anti-Replay Window. A 64-bit counter and a bit-map used to
comment|/// determine whether an inbound AH or ESP packet is a replay.
comment|///
name|UINT8
name|AntiReplayWindows
decl_stmt|;
comment|///
comment|/// AH/ESP cryptographic algorithm, key and parameters.
comment|///
name|EFI_IPSEC_ALGO_INFO
name|AlgoInfo
decl_stmt|;
comment|///
comment|/// Lifetime of this SA.
comment|///
name|EFI_IPSEC_SA_LIFETIME
name|SaLifetime
decl_stmt|;
comment|///
comment|/// Any observed path MTU and aging variables. The Path MTU
comment|/// processing is defined in section 8 of RFC 4301.
comment|///
name|UINT32
name|PathMTU
decl_stmt|;
comment|///
comment|/// Link to one SPD entry.
comment|///
name|EFI_IPSEC_SPD_SELECTOR
modifier|*
name|SpdSelector
decl_stmt|;
comment|///
comment|/// Indication of whether it's manually set or negotiated automatically.
comment|/// If ManualSet is FALSE, the corresponding SA entry is inserted through
comment|/// IKE protocol negotiation.
comment|///
name|BOOLEAN
name|ManualSet
decl_stmt|;
block|}
name|EFI_IPSEC_SA_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_SA_DATA2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_SA_DATA2
block|{
comment|///
comment|/// IPsec mode: tunnel or transport
comment|///
name|EFI_IPSEC_MODE
name|Mode
decl_stmt|;
comment|///
comment|/// Sequence Number Counter. A 64-bit counter used to generate the sequence
comment|/// number field in AH or ESP headers.
comment|///
name|UINT64
name|SNCount
decl_stmt|;
comment|///
comment|/// Anti-Replay Window. A 64-bit counter and a bit-map used to determine
comment|/// whether an inbound AH or ESP packet is a replay.
comment|///
name|UINT8
name|AntiReplayWindows
decl_stmt|;
comment|///
comment|/// AH/ESP cryptographic algorithm, key and parameters.
comment|///
name|EFI_IPSEC_ALGO_INFO
name|AlgoInfo
decl_stmt|;
comment|///
comment|/// Lifetime of this SA.
comment|///
name|EFI_IPSEC_SA_LIFETIME
name|SaLifetime
decl_stmt|;
comment|///
comment|/// Any observed path MTU and aging variables. The Path MTU processing is
comment|/// defined in section 8 of RFC 4301.
comment|///
name|UINT32
name|PathMTU
decl_stmt|;
comment|///
comment|/// Link to one SPD entry
comment|///
name|EFI_IPSEC_SPD_SELECTOR
modifier|*
name|SpdSelector
decl_stmt|;
comment|///
comment|/// Indication of whether it's manually set or negotiated automatically.
comment|/// If ManualSet is FALSE, the corresponding SA entry is inserted through IKE
comment|/// protocol negotiation
comment|///
name|BOOLEAN
name|ManualSet
decl_stmt|;
comment|///
comment|/// The tunnel header IP source address.
comment|///
name|EFI_IP_ADDRESS
name|TunnelSourceAddress
decl_stmt|;
comment|///
comment|/// The tunnel header IP destination address.
comment|///
name|EFI_IP_ADDRESS
name|TunnelDestinationAddress
decl_stmt|;
block|}
name|EFI_IPSEC_SA_DATA2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_PAD_ID
end_comment

begin_comment
comment|/// specifies the identifier for PAD entry, which is also used for SPD lookup.
end_comment

begin_comment
comment|/// IpAddress Pointer to the IPv4 or IPv6 address range.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_PAD_ID
block|{
comment|///
comment|/// Flag to identify which type of PAD Id is used.
comment|///
name|BOOLEAN
name|PeerIdValid
decl_stmt|;
union|union
block|{
comment|///
comment|/// Pointer to the IPv4 or IPv6 address range.
comment|///
name|EFI_IP_ADDRESS_INFO
name|IpAddress
decl_stmt|;
comment|///
comment|/// Pointer to a null terminated ASCII string
comment|/// representing the symbolic names. A PeerId can be a DNS
comment|/// name, Distinguished Name, RFC 822 email address or Key ID
comment|/// (specified in section 4.4.3.1 of RFC 4301)
comment|///
name|UINT8
name|PeerId
index|[
name|MAX_PEERID_LEN
index|]
decl_stmt|;
block|}
name|Id
union|;
block|}
name|EFI_IPSEC_PAD_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_CONFIG_SELECTOR
end_comment

begin_comment
comment|/// describes the expected IPsec configuration data selector
end_comment

begin_comment
comment|/// of type EFI_IPSEC_CONFIG_DATA_TYPE.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_IPSEC_SPD_SELECTOR
name|SpdSelector
decl_stmt|;
name|EFI_IPSEC_SA_ID
name|SaId
decl_stmt|;
name|EFI_IPSEC_PAD_ID
name|PadId
decl_stmt|;
block|}
name|EFI_IPSEC_CONFIG_SELECTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_AUTH_PROTOCOL_TYPE
end_comment

begin_comment
comment|/// defines the possible authentication protocol for IPsec
end_comment

begin_comment
comment|/// security association management.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiIPsecAuthProtocolIKEv1
block|,
name|EfiIPsecAuthProtocolIKEv2
block|,
name|EfiIPsecAuthProtocolMaximum
block|}
name|EFI_IPSEC_AUTH_PROTOCOL_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_AUTH_METHOD
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Using Pre-shared Keys for manual security associations.
comment|///
name|EfiIPsecAuthMethodPreSharedSecret
block|,
comment|///
comment|/// IKE employs X.509 certificates for SA establishment.
comment|///
name|EfiIPsecAuthMethodCertificates
block|,
name|EfiIPsecAuthMethodMaximum
block|}
name|EFI_IPSEC_AUTH_METHOD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IPSEC_PAD_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IPSEC_PAD_DATA
block|{
comment|///
comment|/// Authentication Protocol for IPsec security association  management.
comment|///
name|EFI_IPSEC_AUTH_PROTOCOL_TYPE
name|AuthProtocol
decl_stmt|;
comment|///
comment|/// Authentication method used.
comment|///
name|EFI_IPSEC_AUTH_METHOD
name|AuthMethod
decl_stmt|;
comment|///
comment|/// The IKE ID payload will be used as a symbolic name for SPD
comment|/// lookup if IkeIdFlag is TRUE. Otherwise, the remote IP
comment|/// address provided in traffic selector playloads will be used.
comment|///
name|BOOLEAN
name|IkeIdFlag
decl_stmt|;
comment|///
comment|/// The size of Authentication data buffer, in bytes.
comment|///
name|UINTN
name|AuthDataSize
decl_stmt|;
comment|///
comment|/// Buffer for Authentication data, (e.g., the pre-shared secret or the
comment|/// trust anchor relative to which the peer's certificate will be
comment|/// validated).
comment|///
name|VOID
modifier|*
name|AuthData
decl_stmt|;
comment|///
comment|/// The size of RevocationData, in bytes
comment|///
name|UINTN
name|RevocationDataSize
decl_stmt|;
comment|///
comment|/// Pointer to CRL or OCSP data, if certificates are used for
comment|/// authentication method.
comment|///
name|VOID
modifier|*
name|RevocationData
decl_stmt|;
block|}
name|EFI_IPSEC_PAD_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Set the security association, security policy and peer authorization configuration   information for the EFI IPsec driver.     This function is used to set the IPsec configuration information of type DataType for   the EFI IPsec driver.   The IPsec configuration data has a unique selector/identifier separately to identify   a data entry. The selector structure depends on DataType's definition.   Using SetData() with a Data of NULL causes the IPsec configuration data entry identified   by DataType and Selector to be deleted.            @param[in] This               Pointer to the EFI_IPSEC_CONFIG_PROTOCOL instance.   @param[in] DataType           The type of data to be set.   @param[in] Selector           Pointer to an entry selector on operated configuration data                                  specified by DataType. A NULL Selector causes the entire                                  specified-type configuration information to be flushed.   @param[in] Data               The data buffer to be set. The structure of the data buffer is                                  associated with the DataType.   @param[in] InsertBefore       Pointer to one entry selector which describes the expected                                 position the new data entry will be added. If InsertBefore is NULL,                                 the new entry will be appended the end of database.     @retval EFI_SUCCESS           The specified configuration entry data is set successfully.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.   @retval EFI_UNSUPPORTED       The specified DataType is not supported.   @retval EFI_OUT_OF_RESOURCED  The required system resource could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_CONFIG_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_SELECTOR
modifier|*
name|Selector
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_SELECTOR
modifier|*
name|InsertBefore
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return the configuration value for the EFI IPsec driver.     This function lookup the data entry from IPsec database or IKEv2 configuration   information. The expected data type and unique identification are described in   DataType and Selector parameters.            @param[in]      This          Pointer to the EFI_IPSEC_CONFIG_PROTOCOL instance.   @param[in]      DataType      The type of data to retrieve.   @param[in]      Selector      Pointer to an entry selector which is an identifier of the IPsec                                  configuration data entry.   @param[in, out] DataSize      On output the size of data returned in Data.   @param[out]     Data          The buffer to return the contents of the IPsec configuration data.                                  The type of the data buffer is associated with the DataType.      @retval EFI_SUCCESS           The specified configuration data is got successfully.   @retval EFI_INVALID_PARAMETER One or more of the followings are TRUE:                                 - This is NULL.                                 - Selector is NULL.                                 - DataSize is NULL.                                 - Data is NULL and *DataSize is not zero   @retval EFI_NOT_FOUND         The configuration data specified by Selector is not found.   @retval EFI_UNSUPPORTED       The specified DataType is not supported.   @retval EFI_BUFFER_TOO_SMALL  The DataSize is too small for the result. DataSize has been                                 updated with the size needed to complete the request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_CONFIG_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_SELECTOR
modifier|*
name|Selector
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enumerates the current selector for IPsec configuration data entry.     This function is called multiple times to retrieve the entry Selector in IPsec   configuration database. On each call to GetNextSelector(), the next entry    Selector are retrieved into the output interface.     If the entire IPsec configuration database has been iterated, the error    EFI_NOT_FOUND is returned.   If the Selector buffer is too small for the next Selector copy, an    EFI_BUFFER_TOO_SMALL error is returned, and SelectorSize is updated to reflect    the size of buffer needed.    On the initial call to GetNextSelector() to start the IPsec configuration database   search, a pointer to the buffer with all zero value is passed in Selector. Calls    to SetData() between calls to GetNextSelector may produce unpredictable results.             @param[in]      This          Pointer to the EFI_IPSEC_CONFIG_PROTOCOL instance.   @param[in]      DataType      The type of IPsec configuration data to retrieve.   @param[in, out] SelectorSize  The size of the Selector buffer.   @param[in, out] Selector      On input, supplies the pointer to last Selector that was                                  returned by GetNextSelector().                                 On output, returns one copy of the current entry Selector                                 of a given DataType.      @retval EFI_SUCCESS           The specified configuration data is got successfully.   @retval EFI_INVALID_PARAMETER One or more of the followings are TRUE:                                 - This is NULL.                                 - SelectorSize is NULL.                                 - Selector is NULL.   @retval EFI_NOT_FOUND         The next configuration data entry was not found.   @retval EFI_UNSUPPORTED       The specified DataType is not supported.   @retval EFI_BUFFER_TOO_SMALL  The SelectorSize is too small for the result. This parameter                                 has been updated with the size needed to complete the search                                  request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_CONFIG_GET_NEXT_SELECTOR
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|SelectorSize
parameter_list|,
name|IN
name|OUT
name|EFI_IPSEC_CONFIG_SELECTOR
modifier|*
name|Selector
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register an event that is to be signaled whenever a configuration process on the   specified IPsec configuration information is done.     This function registers an event that is to be signaled whenever a configuration   process on the specified IPsec configuration data is done (e.g. IPsec security    policy database configuration is ready). An event can be registered for different   DataType simultaneously and the caller is responsible for determining which type    of configuration data causes the signaling of the event in such case.            @param[in] This               Pointer to the EFI_IPSEC_CONFIG_PROTOCOL instance.   @param[in] DataType           The type of data to be registered the event for.   @param[in] Event              The event to be registered.     @retval EFI_SUCCESS           The event is registered successfully.   @retval EFI_INVALID_PARAMETER This is NULL or Event is NULL.   @retval EFI_ACCESS_DENIED     The Event is already registered for the DataType.   @retval EFI_UNSUPPORTED       The notify registration unsupported or the specified                                 DataType is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_CONFIG_REGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove the specified event that is previously registered on the specified IPsec   configuration data.     This function removes a previously registered event for the specified configuration data.            @param[in] This               Pointer to the EFI_IPSEC_CONFIG_PROTOCOL instance.   @param[in] DataType           The configuration data type to remove the registered event for.   @param[in] Event              The event to be unregistered.     @retval EFI_SUCCESS           The event is removed successfully.   @retval EFI_NOT_FOUND         The Event specified by DataType could not be found in the                                  database.   @retval EFI_INVALID_PARAMETER This is NULL or Event is NULL.   @retval EFI_UNSUPPORTED       The notify registration unsupported or the specified                                 DataType is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IPSEC_CONFIG_UNREGISTER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_IPSEC_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IPSEC_CONFIG_DATA_TYPE
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
comment|/// EFI_IPSEC_CONFIG_PROTOCOL
end_comment

begin_comment
comment|/// provides the ability to set and lookup the IPsec SAD (Security Association Database),
end_comment

begin_comment
comment|/// SPD (Security Policy Database) data entry and configure the security association
end_comment

begin_comment
comment|/// management protocol such as IKEv2. This protocol is used as the central
end_comment

begin_comment
comment|/// repository of any policy-specific configuration for EFI IPsec driver.
end_comment

begin_comment
comment|/// EFI_IPSEC_CONFIG_PROTOCOL can be bound to both IPv4 and IPv6 stack. User can use this
end_comment

begin_comment
comment|/// protocol for IPsec configuration in both IPv4 and IPv6 environment.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IPSEC_CONFIG_PROTOCOL
block|{
name|EFI_IPSEC_CONFIG_SET_DATA
name|SetData
decl_stmt|;
name|EFI_IPSEC_CONFIG_GET_DATA
name|GetData
decl_stmt|;
name|EFI_IPSEC_CONFIG_GET_NEXT_SELECTOR
name|GetNextSelector
decl_stmt|;
name|EFI_IPSEC_CONFIG_REGISTER_NOTIFY
name|RegisterDataNotify
decl_stmt|;
name|EFI_IPSEC_CONFIG_UNREGISTER_NOTIFY
name|UnregisterDataNotify
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIpSecConfigProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

