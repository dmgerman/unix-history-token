begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Driver Configuration Protocol    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DRIVER_CONFIGURATION_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DRIVER_CONFIGURATION_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/DriverConfiguration2.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Driver Configuration Protocol defined in EFI 1.1
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DRIVER_CONFIGURATION_PROTOCOL_GUID
define|\
value|{ \     0x107a772b, 0xd5e1, 0x11d4, {0x9a, 0x46, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DRIVER_CONFIGURATION_PROTOCOL
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Allows the user to set controller specific options for a controller that a    driver is currently managing.    @param  This             A pointer to the EFI_DRIVER_CONFIGURATION_PROTOCOL instance.   @param  ControllerHandle The handle of the controller to set options on.   @param  ChildHandle      The handle of the child controller to set options on.  This                            is an optional parameter that may be NULL.  It will be NULL                            for device drivers, and for bus drivers that wish to set                            options for the bus controller.  It will not be NULL for a                            bus driver that wishes to set options for one of its child                            controllers.   @param  Language         A pointer to a three character ISO 639-2 language identifier.                            This is the language of the user interface that should be                            presented to the user, and it must match one of the languages                            specified in SupportedLanguages.  The number of languages                            supported by a driver is up to the driver writer.   @param  ActionRequired   A pointer to the action that the calling agent is required                            to perform when this function returns.  See "Related                            Definitions" for a list of the actions that the calling                            agent is required to perform prior to accessing                            ControllerHandle again.    @retval EFI_SUCCESS           The driver specified by This successfully set the                                 configuration options for the controller specified                                 by ControllerHandle..   @retval EFI_INVALID_PARAMETER ControllerHandle is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ActionRequired is NULL.   @retval EFI_UNSUPPORTED       The driver specified by This does not support setting                                 configuration options for the controller specified by                                 ControllerHandle and ChildHandle.   @retval EFI_UNSUPPORTED       The driver specified by This does not support the                                 language specified by Language.   @retval EFI_DEVICE_ERROR      A device error occurred while attempt to set the                                 configuration options for the controller specified                                 by ControllerHandle and ChildHandle.   @retval EFI_OUT_RESOURCES     There are not enough resources available to set the                                 configuration options for the controller specified                                 by ControllerHandle and ChildHandle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_CONFIGURATION_SET_OPTIONS
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|OUT
name|EFI_DRIVER_CONFIGURATION_ACTION_REQUIRED
modifier|*
name|ActionRequired
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Tests to see if a controller's current configuration options are valid.    @param  This             A pointer to the EFI_DRIVER_CONFIGURATION_PROTOCOL instance.   @param  ControllerHandle The handle of the controller to test if it's current                            configuration options are valid.   @param  ChildHandle      The handle of the child controller to test if it's current                            configuration options are valid.  This is an optional                            parameter that may be NULL.  It will be NULL for device                            drivers.  It will also be NULL for bus drivers that wish                            to test the configuration options for the bus controller.                            It will not be NULL for a bus driver that wishes to test                            configuration options for one of its child controllers.    @retval EFI_SUCCESS           The controller specified by ControllerHandle and                                 ChildHandle that is being managed by the driver                                 specified by This has a valid set of  configuration                                 options.   @retval EFI_INVALID_PARAMETER ControllerHandle is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it is not a valid EFI_HANDLE.   @retval EFI_UNSUPPORTED       The driver specified by This is not currently                                 managing the controller specified by ControllerHandle                                 and ChildHandle.   @retval EFI_DEVICE_ERROR      The controller specified by ControllerHandle and                                 ChildHandle that is being managed by the driver                                 specified by This has an invalid set of configuration                                 options.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_CONFIGURATION_OPTIONS_VALID
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Forces a driver to set the default configuration options for a controller.    @param  This             A pointer to the EFI_DRIVER_CONFIGURATION_PROTOCOL instance.   @param  ControllerHandle The handle of the controller to force default configuration options on.   @param  ChildHandle      The handle of the child controller to force default configuration options on  This is an optional parameter that may be NULL.  It will be NULL for device drivers.  It will also be NULL for bus drivers that wish to force default configuration options for the bus controller.  It will not be NULL for a bus driver that wishes to force default configuration options for one of its child controllers.   @param  DefaultType      The type of default configuration options to force on the controller specified by ControllerHandle and ChildHandle.  See Table 9-1 for legal values.  A DefaultType of 0x00000000 must be supported by this protocol.   @param  ActionRequired   A pointer to the action that the calling agent is required to perform when this function returns.  See "Related Definitions" in Section 9.1 for a list of the actions that the calling agent is required to perform prior to accessing ControllerHandle again.    @retval EFI_SUCCESS           The driver specified by This successfully forced the default configuration options on the controller specified by ControllerHandle and ChildHandle.   @retval EFI_INVALID_PARAMETER ControllerHandle is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ActionRequired is NULL.   @retval EFI_UNSUPPORTED       The driver specified by This does not support forcing the default configuration options on the controller specified by ControllerHandle and ChildHandle.   @retval EFI_UNSUPPORTED       The driver specified by This does not support the configuration type specified by DefaultType.   @retval EFI_DEVICE_ERROR      A device error occurred while attempt to force the default configuration options on the controller specified by  ControllerHandle and ChildHandle.   @retval EFI_OUT_RESOURCES     There are not enough resources available to force the default configuration options on the controller specified by ControllerHandle and ChildHandle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_CONFIGURATION_FORCE_DEFAULTS
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|IN
name|UINT32
name|DefaultType
parameter_list|,
name|OUT
name|EFI_DRIVER_CONFIGURATION_ACTION_REQUIRED
modifier|*
name|ActionRequired
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to set configuration options for a controller that an EFI Driver is managing.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DRIVER_CONFIGURATION_PROTOCOL
block|{
name|EFI_DRIVER_CONFIGURATION_SET_OPTIONS
name|SetOptions
decl_stmt|;
name|EFI_DRIVER_CONFIGURATION_OPTIONS_VALID
name|OptionsValid
decl_stmt|;
name|EFI_DRIVER_CONFIGURATION_FORCE_DEFAULTS
name|ForceDefaults
decl_stmt|;
comment|///
comment|/// A Null-terminated ASCII string that contains one or more
comment|/// ISO 639-2 language codes.  This is the list of language
comment|/// codes that this protocol supports.
comment|///
name|CHAR8
modifier|*
name|SupportedLanguages
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDriverConfigurationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

