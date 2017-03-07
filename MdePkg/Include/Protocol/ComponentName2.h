begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Component Name 2 Protocol as defined in the UEFI 2.1 specification.   This protocol is used to retrieve user readable names of drivers    and controllers managed by UEFI Drivers.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_COMPONENT_NAME2_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_COMPONENT_NAME2_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Component Name Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_COMPONENT_NAME2_PROTOCOL_GUID
define|\
value|{0x6a7a5cff, 0xe8d9, 0x4f70, { 0xba, 0xda, 0x75, 0xab, 0x30, 0x25, 0xce, 0x14 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_COMPONENT_NAME2_PROTOCOL
name|EFI_COMPONENT_NAME2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves a string that is the user readable name of   the EFI Driver.    @param  This       A pointer to the                      EFI_COMPONENT_NAME2_PROTOCOL instance.      @param  Language   A pointer to a Null-terminated ASCII string                      array indicating the language. This is the                      language of the driver name that the caller                      is requesting, and it must match one of the                      languages specified in SupportedLanguages.                      The number of languages supported by a                      driver is up to the driver writer. Language                      is specified in RFC 4646 language code                      format.      @param  DriverName A pointer to the string to return.                      This string is the name of the                      driver specified by This in the language                      specified by Language.    @retval EFI_SUCCESS           The string for the                                 Driver specified by This and the                                 language specified by Language                                 was returned in DriverName.      @retval EFI_INVALID_PARAMETER Language is NULL.      @retval EFI_INVALID_PARAMETER DriverName is NULL.      @retval EFI_UNSUPPORTED       The driver specified by This                                 does not support the language                                 specified by Language.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_COMPONENT_NAME2_GET_DRIVER_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_COMPONENT_NAME2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|DriverName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves a string that is the user readable name of   the controller that is being managed by an EFI Driver.    @param  This             A pointer to the                            EFI_COMPONENT_NAME2_PROTOCOL instance.    @param  ControllerHandle The handle of a controller that the                            driver specified by This is managing.                            This handle specifies the controller                            whose name is to be returned.    @param  ChildHandle      The handle of the child controller to                            retrieve the name of.  This is an                            optional parameter that may be NULL.                            It will be NULL for device drivers.                            It will also be NULL for bus                            drivers that wish to retrieve the                            name of the bus controller.  It will                            not be NULL for a bus driver that                            wishes to retrieve the name of a                            child controller.    @param  Language         A pointer to a Null-terminated ASCII                            string array indicating the language.                            This is the language of the driver                            name that the caller is requesting,                            and it must match one of the                            languages specified in                            SupportedLanguages. The number of                            languages supported by a driver is up                            to the driver writer. Language is                            specified in RFC 4646 language code                            format.    @param  ControllerName   A pointer to the string to return.                            This string is the name of the controller                            specified by ControllerHandle and ChildHandle                            in the language specified by Language                            from the point of view of the driver                            specified by This.    @retval EFI_SUCCESS           The string for the user                                 readable name in the language                                 specified by Language for the                                 driver specified by This was                                 returned in DriverName.    @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.    @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it                                 is not a valid EFI_HANDLE.    @retval EFI_INVALID_PARAMETER Language is NULL.    @retval EFI_INVALID_PARAMETER ControllerName is NULL.    @retval EFI_UNSUPPORTED       The driver specified by This is                                 not currently managing the                                 controller specified by                                 ControllerHandle and                                 ChildHandle.    @retval EFI_UNSUPPORTED       The driver specified by This                                 does not support the language                                 specified by Language.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_COMPONENT_NAME2_GET_CONTROLLER_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_COMPONENT_NAME2_PROTOCOL
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
name|CHAR16
modifier|*
modifier|*
name|ControllerName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is used to retrieve user readable names of drivers
end_comment

begin_comment
comment|/// and controllers managed by UEFI Drivers.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_COMPONENT_NAME2_PROTOCOL
block|{
name|EFI_COMPONENT_NAME2_GET_DRIVER_NAME
name|GetDriverName
decl_stmt|;
name|EFI_COMPONENT_NAME2_GET_CONTROLLER_NAME
name|GetControllerName
decl_stmt|;
comment|///
comment|/// A Null-terminated ASCII string array that contains one or more
comment|/// supported language codes. This is the list of language codes that
comment|/// this protocol supports. The number of languages supported by a
comment|/// driver is up to the driver writer. SupportedLanguages is
comment|/// specified in RFC 4646 format.
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
name|gEfiComponentName2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

