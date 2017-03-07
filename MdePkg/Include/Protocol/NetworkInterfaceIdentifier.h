begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Network Interface Identifier Protocol.  Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in EFI Specification 1.10.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_NETWORK_INTERFACE_IDENTIFER_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_NETWORK_INTERFACE_IDENTIFER_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// GUID retired from UEFI Specification 2.1b
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL_GUID
define|\
value|{ \     0xE18541CD, 0xF755, 0x4f73, {0x92, 0x8D, 0x64, 0x3C, 0x8A, 0x79, 0xB2, 0x29 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// GUID intruduced in UEFI Specification 2.1b
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL_GUID_31
define|\
value|{ \     0x1ACED566, 0x76ED, 0x4218, {0xBC, 0x81, 0x76, 0x7F, 0x1F, 0x97, 0x7A, 0x89 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Revision defined in UEFI Specification 2.4
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL_REVISION
value|0x00020000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Revision defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_INTERFACE_REVISION
value|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward reference for pure ANSI compatability.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL
name|EFI_NETWORK_INTERFACE_IDENTIFIER_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An optional protocol that is used to describe details about the software
end_comment

begin_comment
comment|/// layer that is used to produce the Simple Network Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL
block|{
name|UINT64
name|Revision
decl_stmt|;
comment|///< The revision of the EFI_NETWORK_INTERFACE_IDENTIFIER protocol.
name|UINT64
name|Id
decl_stmt|;
comment|///< The address of the first byte of the identifying structure for this network
comment|///< interface. This is only valid when the network interface is started
comment|///< (see Start()). When the network interface is not started, this field is set to zero.
name|UINT64
name|ImageAddr
decl_stmt|;
comment|///< The address of the first byte of the identifying structure for this
comment|///< network interface.  This is set to zero if there is no structure.
name|UINT32
name|ImageSize
decl_stmt|;
comment|///< The size of unrelocated network interface image.
name|CHAR8
name|StringId
index|[
literal|4
index|]
decl_stmt|;
comment|///< A four-character ASCII string that is sent in the class identifier field of
comment|///< option 60 in DHCP. For a Type of EfiNetworkInterfaceUndi, this field is UNDI.
name|UINT8
name|Type
decl_stmt|;
comment|///< Network interface type. This will be set to one of the values
comment|///< in EFI_NETWORK_INTERFACE_TYPE.
name|UINT8
name|MajorVer
decl_stmt|;
comment|///< Major version number.
name|UINT8
name|MinorVer
decl_stmt|;
comment|///< Minor version number.
name|BOOLEAN
name|Ipv6Supported
decl_stmt|;
comment|///< TRUE if the network interface supports IPv6; otherwise FALSE.
name|UINT16
name|IfNum
decl_stmt|;
comment|///< The network interface number that is being identified by this Network
comment|///< Interface Identifier Protocol. This field must be less than or
comment|///< equal to the (IFcnt | IFcntExt<<8 ) fields in the !PXE structure.
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|///*******************************************************
end_comment

begin_comment
comment|/// EFI_NETWORK_INTERFACE_TYPE
end_comment

begin_comment
comment|///*******************************************************
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiNetworkInterfaceUndi
init|=
literal|1
block|}
name|EFI_NETWORK_INTERFACE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward reference for pure ANSI compatability.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|undiconfig_table
name|UNDI_CONFIG_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format of the configuration table for UNDI
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|undiconfig_table
block|{
name|UINT32
name|NumberOfInterfaces
decl_stmt|;
comment|///< The number of NIC devices
comment|///< that this UNDI controls.
name|UINT32
name|reserved
decl_stmt|;
name|UNDI_CONFIG_TABLE
modifier|*
name|nextlink
decl_stmt|;
comment|///< A pointer to the next UNDI
comment|///< configuration table.
comment|///
comment|/// The length of this array is given in the NumberOfInterfaces field.
comment|///
struct|struct
block|{
name|VOID
modifier|*
name|NII_InterfacePointer
decl_stmt|;
comment|///< Pointer to the NII interface structure.
name|VOID
modifier|*
name|DevicePathPointer
decl_stmt|;
comment|///< Pointer to the device path for this NIC.
block|}
name|NII_entry
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiNetworkInterfaceIdentifierProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiNetworkInterfaceIdentifierProtocolGuid_31
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

