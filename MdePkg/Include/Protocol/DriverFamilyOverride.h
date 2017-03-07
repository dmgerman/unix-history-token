begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Driver Family Protocol  Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DRIVER_FAMILY_OVERRIDE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DRIVER_FAMILY_OVERRIDE_H__
end_define

begin_define
define|#
directive|define
name|EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL_GUID
define|\
value|{ \     0xb1ee129e, 0xda36, 0x4181, { 0x91, 0xf8, 0x4, 0xa4, 0x92, 0x37, 0x66, 0xa7 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL
name|EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Prototypes for the Driver Family Override Protocol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                    This function returns the version value associated with the driver specified by This.    Retrieves the version of the driver that is used by the EFI Boot Service ConnectController()   to sort the set of Driver Binding Protocols in order from highest priority to lowest priority.   For drivers that support the Driver Family Override Protocol, those drivers are sorted so that   the drivers with higher values returned by GetVersion() are higher priority than drivers that   return lower values from GetVersion().    @param  This                  A pointer to the EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL instance.                                                                @return The version value associated with the driver specified by This.                                                                       **/
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_FAMILY_OVERRIDE_GET_VERSION
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// When installed, the Driver Family Override Protocol produces a GUID that represents
end_comment

begin_comment
comment|/// a family of drivers.  Drivers with the same GUID are members of the same family
end_comment

begin_comment
comment|/// When drivers are connected to controllers, drivers with a higher revision value
end_comment

begin_comment
comment|/// in the same driver family are connected with a higher priority than drivers
end_comment

begin_comment
comment|/// with a lower revision value in the same driver family.  The EFI Boot Service
end_comment

begin_comment
comment|/// Connect Controller uses five rules to build a prioritized list of drivers when
end_comment

begin_comment
comment|/// a request is made to connect a driver to a controller.  The Driver Family Protocol
end_comment

begin_comment
comment|/// rule is between the Platform Specific Driver Override Protocol and above the
end_comment

begin_comment
comment|/// Bus Specific Driver Override Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL
block|{
name|EFI_DRIVER_FAMILY_OVERRIDE_GET_VERSION
name|GetVersion
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDriverFamilyOverrideProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

