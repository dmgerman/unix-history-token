begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Driver Diagnostics2 Protocol    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DRIVER_DIAGNOSTICS2_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DRIVER_DIAGNOSTICS2_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/DriverDiagnostics.h>
end_include

begin_define
define|#
directive|define
name|EFI_DRIVER_DIAGNOSTICS2_PROTOCOL_GUID
define|\
value|{ \     0x4d330321, 0x025f, 0x4aac, {0x90, 0xd8, 0x5e, 0xd9, 0x00, 0x17, 0x3b, 0x63 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DRIVER_DIAGNOSTICS2_PROTOCOL
name|EFI_DRIVER_DIAGNOSTICS2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Runs diagnostics on a controller.    @param  This             A pointer to the EFI_DRIVER_DIAGNOSTICS2_PROTOCOL instance.   @param  ControllerHandle The handle of the controller to run diagnostics on.   @param  ChildHandle      The handle of the child controller to run diagnostics on                            This is an optional parameter that may be NULL.  It will                            be NULL for device drivers.  It will also be NULL for                             bus drivers that wish to run diagnostics on the bus                            controller.  It will not be NULL for a bus driver that                            wishes to run diagnostics on one of its child controllers.   @param  DiagnosticType   Indicates the type of diagnostics to perform on the controller                            specified by ControllerHandle and ChildHandle.   See                            "Related Definitions" for the list of supported types.   @param  Language         A pointer to a Null-terminated ASCII string                            array indicating the language. This is the                            language of the driver name that the caller                            is requesting, and it must match one of the                            languages specified in SupportedLanguages.                            The number of languages supported by a                            driver is up to the driver writer. Language                            is specified in RFC 4646 language code format.   @param  ErrorType        A GUID that defines the format of the data returned in Buffer.   @param  BufferSize       The size, in bytes, of the data returned in Buffer.   @param  Buffer           A buffer that contains a Null-terminated Unicode string                            plus some additional data whose format is defined by                            ErrorType.  Buffer is allocated by this function with                            AllocatePool(), and it is the caller's responsibility                            to free it with a call to FreePool().    @retval EFI_SUCCESS           The controller specified by ControllerHandle and                                 ChildHandle passed the diagnostic.   @retval EFI_ACCESS_DENIED     The request for initiating diagnostics was unable                                 to be complete due to some underlying hardware or                                 software state.   @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.   @retval EFI_INVALID_PARAMETER ChildHandle is not NULL and it is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER Language is NULL.   @retval EFI_INVALID_PARAMETER ErrorType is NULL.   @retval EFI_INVALID_PARAMETER BufferType is NULL.   @retval EFI_INVALID_PARAMETER Buffer is NULL.   @retval EFI_UNSUPPORTED       The driver specified by This does not support                                 running diagnostics for the controller specified                                 by ControllerHandle and ChildHandle.   @retval EFI_UNSUPPORTED       The driver specified by This does not support the                                 type of diagnostic specified by DiagnosticType.   @retval EFI_UNSUPPORTED       The driver specified by This does not support the                                 language specified by Language.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to complete                                 the diagnostics.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to return                                 the status information in ErrorType, BufferSize,                                 and Buffer.   @retval EFI_DEVICE_ERROR      The controller specified by ControllerHandle and                                 ChildHandle did not pass the diagnostic.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_DIAGNOSTICS2_RUN_DIAGNOSTICS
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_DIAGNOSTICS2_PROTOCOL
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
name|EFI_DRIVER_DIAGNOSTIC_TYPE
name|DiagnosticType
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
modifier|*
name|ErrorType
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to perform diagnostics on a controller that an EFI Driver is managing.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DRIVER_DIAGNOSTICS2_PROTOCOL
block|{
name|EFI_DRIVER_DIAGNOSTICS2_RUN_DIAGNOSTICS
name|RunDiagnostics
decl_stmt|;
comment|///
comment|/// A Null-terminated ASCII string that contains one or more RFC 4646
comment|/// language codes.  This is the list of language codes that this protocol supports.
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
name|gEfiDriverDiagnostics2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

