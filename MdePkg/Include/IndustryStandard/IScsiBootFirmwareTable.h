begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The definition for iSCSI Boot Firmware Table, it's defined in Microsoft's   iSCSI Boot Firmware Table(iBFT) as Defined in ACPI 3.0b Specification.       Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISCSI_BOOT_FIRMWARE_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISCSI_BOOT_FIRMWARE_TABLE_H_
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_REVISION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_ALIGNMENT
value|8
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure Type/ID
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_RESERVED_STRUCTURE_ID
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_CONTROL_STRUCTURE_ID
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_INITIATOR_STRUCTURE_ID
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE_ID
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_ID
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_EXTERNSIONS_STRUCTURE_ID
value|5
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// from the definition of IP_PREFIX_ORIGIN Enumeration in MSDN,
end_comment

begin_comment
comment|/// not defined in Microsoft iBFT document.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IpPrefixOriginOther
init|=
literal|0
block|,
name|IpPrefixOriginManual
block|,
name|IpPrefixOriginWellKnown
block|,
name|IpPrefixOriginDhcp
block|,
name|IpPrefixOriginRouterAdvertisement
block|,
name|IpPrefixOriginUnchanged
init|=
literal|16
block|}
name|IP_PREFIX_VALUE
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// iBF Table Header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|OemTableId
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common Header of Boot Firmware Table Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|StructureId
decl_stmt|;
name|UINT8
name|Version
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Index
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Control Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Extensions
decl_stmt|;
name|UINT16
name|InitiatorOffset
decl_stmt|;
name|UINT16
name|NIC0Offset
decl_stmt|;
name|UINT16
name|Target0Offset
decl_stmt|;
name|UINT16
name|NIC1Offset
decl_stmt|;
name|UINT16
name|Target1Offset
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_CONTROL_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_CONTROL_STRUCTURE_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_CONTROL_STRUCTURE_FLAG_BOOT_FAILOVER
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initiator Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|ISnsServer
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|SlpServer
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|PrimaryRadiusServer
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|SecondaryRadiusServer
decl_stmt|;
name|UINT16
name|IScsiNameLength
decl_stmt|;
name|UINT16
name|IScsiNameOffset
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_INITIATOR_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_INITIATOR_STRUCTURE_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_INITIATOR_STRUCTURE_FLAG_BLOCK_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_INITIATOR_STRUCTURE_FLAG_BOOT_SELECTED
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// NIC Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|Ip
decl_stmt|;
name|UINT8
name|SubnetMaskPrefixLength
decl_stmt|;
name|UINT8
name|Origin
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|Gateway
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|PrimaryDns
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|SecondaryDns
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|DhcpServer
decl_stmt|;
name|UINT16
name|VLanTag
decl_stmt|;
name|UINT8
name|Mac
index|[
literal|6
index|]
decl_stmt|;
name|UINT16
name|PciLocation
decl_stmt|;
name|UINT16
name|HostNameLength
decl_stmt|;
name|UINT16
name|HostNameOffset
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE_FLAG_BLOCK_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE_FLAG_BOOT_SELECTED
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_NIC_STRUCTURE_FLAG_GLOBAL
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Target Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|Ip
decl_stmt|;
name|UINT16
name|Port
decl_stmt|;
name|UINT8
name|BootLun
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|CHAPType
decl_stmt|;
name|UINT8
name|NicIndex
decl_stmt|;
name|UINT16
name|IScsiNameLength
decl_stmt|;
name|UINT16
name|IScsiNameOffset
decl_stmt|;
name|UINT16
name|CHAPNameLength
decl_stmt|;
name|UINT16
name|CHAPNameOffset
decl_stmt|;
name|UINT16
name|CHAPSecretLength
decl_stmt|;
name|UINT16
name|CHAPSecretOffset
decl_stmt|;
name|UINT16
name|ReverseCHAPNameLength
decl_stmt|;
name|UINT16
name|ReverseCHAPNameOffset
decl_stmt|;
name|UINT16
name|ReverseCHAPSecretLength
decl_stmt|;
name|UINT16
name|ReverseCHAPSecretOffset
decl_stmt|;
block|}
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_FLAG_BLOCK_VALID
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_FLAG_BOOT_SELECTED
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_FLAG_RADIUS_CHAP
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_FLAG_RADIUS_RCHAP
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_CHAP_TYPE_NO_CHAP
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_CHAP_TYPE_CHAP
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_ISCSI_BOOT_FIRMWARE_TABLE_TARGET_STRUCTURE_CHAP_TYPE_MUTUAL_CHAP
value|2
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

