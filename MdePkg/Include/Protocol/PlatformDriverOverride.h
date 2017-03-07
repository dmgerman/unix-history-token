begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Platform Driver Override protocol as defined in the UEFI 2.1 specification.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Platform Driver Override Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL_GUID
define|\
value|{ \     0x6b30c738, 0xa391, 0x11d4, {0x9a, 0x3b, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
name|EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Prototypes for the Platform Driver Override Protocol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                    Retrieves the image handle of the platform override driver for a controller in the system.        @param  This                  A pointer to the EFI_PLATFORM_DRIVER_OVERRIDE_                                 PROTOCOL instance.                               @param  ControllerHandle      The device handle of the controller to check if a driver override                                 exists.                                                             @param  DriverImageHandle     On input, a pointer to the previous driver image handle returned                                 by GetDriver(). On output, a pointer to the next driver                                          image handle.                                                                                       @retval EFI_SUCCESS           The driver override for ControllerHandle was returned in                                 DriverImageHandle.                                         @retval EFI_NOT_FOUND         A driver override for ControllerHandle was not found.   @retval EFI_INVALID_PARAMETER The handle specified by ControllerHandle is NULL.   @retval EFI_INVALID_PARAMETER DriverImageHandle is not a handle that was returned on a                                 previous call to GetDriver().                                                                **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PLATFORM_DRIVER_OVERRIDE_GET_DRIVER
function_decl|)
parameter_list|(
name|IN
name|EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
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
comment|/**                                                                    Retrieves the device path of the platform override driver for a controller in the system.        @param  This                  A pointer to the EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL instance.   @param  ControllerHandle      The device handle of the controller to check if a driver override                                 exists.                                                             @param  DriverImagePath       On input, a pointer to the previous driver device path returned by                                 GetDriverPath(). On output, a pointer to the next driver                                 device path. Passing in a pointer to NULL will return the first                                 driver device path for ControllerHandle.                                    @retval EFI_SUCCESS           The driver override for ControllerHandle was returned in                                 DriverImageHandle.                                         @retval EFI_UNSUPPORTED       The operation is not supported.                                   @retval EFI_NOT_FOUND         A driver override for ControllerHandle was not found.   @retval EFI_INVALID_PARAMETER The handle specified by ControllerHandle is NULL.   @retval EFI_INVALID_PARAMETER DriverImagePath is not a device path that was returned on a                                 previous call to GetDriverPath().                                                               **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PLATFORM_DRIVER_OVERRIDE_GET_DRIVER_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DriverImagePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Used to associate a driver image handle with a device path that was returned on a prior call to the   GetDriverPath() service. This driver image handle will then be available through the                  GetDriver() service.                                                                                       @param  This                  A pointer to the EFI_PLATFORM_DRIVER_OVERRIDE_                                 PROTOCOL instance.                               @param  ControllerHandle      The device handle of the controller.                                                                @param  DriverImagePath       A pointer to the driver device path that was returned in a prior                                 call to GetDriverPath().                                                                           @param  DriverImageHandle     The driver image handle that was returned by LoadImage()                                 when the driver specified by DriverImagePath was loaded                                  into memory.                                                                                @retval EFI_SUCCESS           The association between DriverImagePath and                                                    DriverImageHandle was established for the controller specified                                 by ControllerHandle.                                                                               @retval EFI_UNSUPPORTED       The operation is not supported.                                   @retval EFI_NOT_FOUND         DriverImagePath is not a device path that was returned on a prior                                 call to GetDriverPath() for the controller specified by                                           ControllerHandle.                                                   @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.   @retval EFI_INVALID_PARAMETER DriverImagePath is not a valid device path.   @retval EFI_INVALID_PARAMETER DriverImageHandle is not a valid image handle.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PLATFORM_DRIVER_OVERRIDE_DRIVER_LOADED
function_decl|)
parameter_list|(
name|IN
name|EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DriverImagePath
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverImageHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol matches one or more drivers to a controller. A platform driver
end_comment

begin_comment
comment|/// produces this protocol, and it is installed on a separate handle. This protocol
end_comment

begin_comment
comment|/// is used by the ConnectController() boot service to select the best driver
end_comment

begin_comment
comment|/// for a controller. All of the drivers returned by this protocol have a higher
end_comment

begin_comment
comment|/// precedence than drivers found from an EFI Bus Specific Driver Override Protocol
end_comment

begin_comment
comment|/// or drivers found from the general UEFI driver Binding search algorithm. If more
end_comment

begin_comment
comment|/// than one driver is returned by this protocol, then the drivers are returned in
end_comment

begin_comment
comment|/// order from highest precedence to lowest precedence.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL
block|{
name|EFI_PLATFORM_DRIVER_OVERRIDE_GET_DRIVER
name|GetDriver
decl_stmt|;
name|EFI_PLATFORM_DRIVER_OVERRIDE_GET_DRIVER_PATH
name|GetDriverPath
decl_stmt|;
name|EFI_PLATFORM_DRIVER_OVERRIDE_DRIVER_LOADED
name|DriverLoaded
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPlatformDriverOverrideProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

