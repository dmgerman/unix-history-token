begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The protocol provides information about the version of the EFI   specification that a driver is following. This protocol is   required for EFI drivers that are on PCI and other plug-in   cards.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DRIVER_SUPPORTED_EFI_VERSION_H__
end_ifndef

begin_define
define|#
directive|define
name|__DRIVER_SUPPORTED_EFI_VERSION_H__
end_define

begin_define
define|#
directive|define
name|EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL_GUID
define|\
value|{ 0x5c198761, 0x16a8, 0x4e69, { 0x97, 0x2c, 0x89, 0xd6, 0x79, 0x54, 0xf8, 0x1d } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL provides a
end_comment

begin_comment
comment|/// mechanism for an EFI driver to publish the version of the EFI
end_comment

begin_comment
comment|/// specification it conforms to. This protocol must be placed on
end_comment

begin_comment
comment|/// the driver's image handle when the driver's entry point is
end_comment

begin_comment
comment|/// called.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL
block|{
comment|///
comment|/// The size, in bytes, of the entire structure. Future versions of this
comment|/// specification may grow the size of the structure.
comment|///
name|UINT32
name|Length
decl_stmt|;
comment|///
comment|/// The latest version of the UEFI specification that this driver conforms to.
comment|///
name|UINT32
name|FirmwareVersion
decl_stmt|;
block|}
name|EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDriverSupportedEfiVersionProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

