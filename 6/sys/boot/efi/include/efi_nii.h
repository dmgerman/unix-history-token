begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_NII_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_NII_H
end_define

begin_comment
comment|/*++ Copyright (c) 2000  Intel Corporation  Module name:     efi_nii.h  Abstract:  Revision history:     2000-Feb-18 M(f)J   GUID updated.                 Structure order changed for machine word alignment.                 Added StringId[4] to structure.                      2000-Feb-14 M(f)J   Genesis. --*/
end_comment

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL
define|\
value|{ 0xE18541CD, 0xF755, 0x4f73, 0x92, 0x8D, 0x64, 0x3C, 0x8A, 0x79, 0xB2, 0x29 }
end_define

begin_define
define|#
directive|define
name|EFI_NETWORK_INTERFACE_IDENTIFIER_INTERFACE_REVISION
value|0x00010000
end_define

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

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Revision of the network interface identifier protocol interface. */
name|UINT64
name|Revision
decl_stmt|;
comment|/* 	 * Address of the first byte of the identifying structure for this 	 * network interface.  This is set to zero if there is no structure. 	 * For PXE/UNDI this is the first byte of the !PXE structure. 	 */
name|UINT64
name|ID
decl_stmt|;
comment|/* 	 * Address of the UNrelocated driver/ROM image.  This is set 	 * to zero if there is no driver/ROM image. 	 * For 16-bit UNDI, this is the first byte of the option ROM in 	 * upper memory. 	 * For 32/64-bit S/W UNDI, this is the first byte of the EFI ROM 	 * image. 	 * For H/W UNDI, this is set to zero. 	 */
name|UINT64
name|ImageAddr
decl_stmt|;
comment|/* 	 * Size of the UNrelocated driver/ROM image of this network interface. 	 * This is set to zero if there is no driver/ROM image. 	 */
name|UINT32
name|ImageSize
decl_stmt|;
comment|/* 	 * 4 char ASCII string to go in class identifier (option 60) in DHCP 	 * and Boot Server discover packets. 	 * For EfiNetworkInterfaceUndi this field is "UNDI". 	 * For EfiNetworkInterfaceSnp this field is "SNPN". 	 */
name|CHAR8
name|StringId
index|[
literal|4
index|]
decl_stmt|;
comment|/* 	 * Information to be placed into the PXE DHCP and Discover packets. 	 * This is the network interface type and version number that will 	 * be placed into DHCP option 94 (client network interface identifier). 	 */
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|MajorVer
decl_stmt|;
name|UINT8
name|MinorVer
decl_stmt|;
name|BOOLEAN
name|Ipv6Supported
decl_stmt|;
name|UINT8
name|IfNum
decl_stmt|;
comment|/* interface number to be used with pxeid structure */
block|}
name|EFI_NETWORK_INTERFACE_IDENTIFIER_INTERFACE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|NetworkInterfaceIdentifierProtocol
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EFI_NII_H */
end_comment

end_unit

