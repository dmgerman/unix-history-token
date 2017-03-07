begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM Sx Dispatch Protocol as defined in PI 1.2 Specification   Volume 4 System Management Mode Core Interface.    Provides the parent dispatch service for a given Sx-state source generator.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_SX_DISPATCH2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_SX_DISPATCH2_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiSmmCis.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_SX_DISPATCH2_PROTOCOL_GUID
define|\
value|{ \     0x456d2859, 0xa84b, 0x4e47, {0xa2, 0xee, 0x32, 0x76, 0xd8, 0x86, 0x99, 0x7d } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sleep states S0-S5
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SxS0
block|,
name|SxS1
block|,
name|SxS2
block|,
name|SxS3
block|,
name|SxS4
block|,
name|SxS5
block|,
name|EfiMaximumSleepType
block|}
name|EFI_SLEEP_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sleep state phase: entry or exit
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SxEntry
block|,
name|SxExit
block|,
name|EfiMaximumPhase
block|}
name|EFI_SLEEP_PHASE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The dispatch function's context
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_SLEEP_TYPE
name|Type
decl_stmt|;
name|EFI_SLEEP_PHASE
name|Phase
decl_stmt|;
block|}
name|EFI_SMM_SX_REGISTER_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_SX_DISPATCH2_PROTOCOL
name|EFI_SMM_SX_DISPATCH2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Provides the parent dispatch service for a given Sx source generator.    This service registers a function (DispatchFunction) which will be called when the sleep state    event specified by RegisterContext is detected. On return, DispatchHandle contains a    unique handle which may be used later to unregister the function using UnRegister().   The DispatchFunction will be called with Context set to the same value as was passed into    this function in RegisterContext and with CommBuffer and CommBufferSize set to    NULL and 0 respectively.    @param[in] This                Pointer to the EFI_SMM_SX_DISPATCH2_PROTOCOL instance.   @param[in] DispatchFunction    Function to register for handler when the specified sleep state event occurs.   @param[in] RegisterContext     Pointer to the dispatch function's context.                                  The caller fills this context in before calling                                  the register function to indicate to the register                                  function which Sx state type and phase the caller                                  wishes to be called back on. For this intertace,                                  the Sx driver will call the registered handlers for                                  all Sx type and phases, so the Sx state handler(s)                                  must check the Type and Phase field of the Dispatch                                  context and act accordingly.   @param[out]  DispatchHandle    Handle of dispatch function, for when interfacing                                  with the parent Sx state SMM driver.    @retval EFI_SUCCESS            The dispatch function has been successfully                                  registered and the SMI source has been enabled.   @retval EFI_UNSUPPORTED        The Sx driver or hardware does not support that                                  Sx Type/Phase.   @retval EFI_DEVICE_ERROR       The Sx driver was unable to enable the SMI source.   @retval EFI_INVALID_PARAMETER  RegisterContext is invalid. Type& Phase are not                                  within valid range.   @retval EFI_OUT_OF_RESOURCES   There is not enough memory (system or SMM) to manage this                                  child. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_SX_REGISTER2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_SX_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|DispatchFunction
parameter_list|,
name|IN
name|CONST
name|EFI_SMM_SX_REGISTER_CONTEXT
modifier|*
name|RegisterContext
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Unregisters an Sx-state service.    This service removes the handler associated with DispatchHandle so that it will no longer be    called in response to sleep event.    @param[in] This                Pointer to the EFI_SMM_SX_DISPATCH2_PROTOCOL instance.   @param[in] DispatchHandle      Handle of the service to remove.     @retval EFI_SUCCESS            The service has been successfully removed.   @retval EFI_INVALID_PARAMETER  The DispatchHandle was not valid. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_SX_UNREGISTER2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_SX_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interface structure for the SMM Sx Dispatch Protocol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SMM_SX_DISPATCH2_PROTOCOL provides the ability to install child handlers to
end_comment

begin_comment
comment|/// respond to sleep state related events.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_SX_DISPATCH2_PROTOCOL
block|{
name|EFI_SMM_SX_REGISTER2
name|Register
decl_stmt|;
name|EFI_SMM_SX_UNREGISTER2
name|UnRegister
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmSxDispatch2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

