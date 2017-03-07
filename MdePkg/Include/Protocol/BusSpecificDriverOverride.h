begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Bus Specific Driver Override protocol as defined in the UEFI 2.0 specification.    Bus drivers that have a bus specific algorithm for matching drivers to controllers are   required to produce this protocol for each controller. For example, a PCI Bus Driver will produce an   instance of this protocol for every PCI controller that has a PCI option ROM that contains one or   more UEFI drivers. The protocol instance is attached to the handle of the PCI controller.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Bus Specific Driver Override Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL_GUID
define|\
value|{ \     0x3bc1b285, 0x8a15, 0x4a82, {0xaa, 0xbf, 0x4d, 0x7d, 0x13, 0xfb, 0x32, 0x65 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL
name|EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Prototypes for the Bus Specific Driver Override Protocol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                      Uses a bus specific algorithm to retrieve a driver image handle for a controller.        @param  This                  A pointer to the EFI_BUS_SPECIFIC_DRIVER_                                 OVERRIDE_PROTOCOL instance.                 @param  DriverImageHandle     On input, a pointer to the previous driver image handle returned                                 by GetDriver(). On output, a pointer to the next driver                                          image handle. Passing in a NULL, will return the first driver                                    image handle.    @retval EFI_SUCCESS           A bus specific override driver is returned in DriverImageHandle.   @retval EFI_NOT_FOUND         The end of the list of override drivers was reached.                                 A bus specific override driver is not returned in DriverImageHandle.   @retval EFI_INVALID_PARAMETER DriverImageHandle is not a handle that was returned on a                                 previous call to GetDriver().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_GET_DRIVER
function_decl|)
parameter_list|(
name|IN
name|EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|DriverImageHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol matches one or more drivers to a controller. This protocol is produced by a bus driver,
end_comment

begin_comment
comment|/// and it is installed on the child handles of buses that require a bus specific algorithm for matching
end_comment

begin_comment
comment|/// drivers to controllers.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL
block|{
name|EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_GET_DRIVER
name|GetDriver
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBusSpecificDriverOverrideProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

