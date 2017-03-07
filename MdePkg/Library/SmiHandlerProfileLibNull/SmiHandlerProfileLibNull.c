begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   NULL instance of SmiHandlerProfile Library.    Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiSmm.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmiHandlerProfileLib.h>
end_include

begin_comment
comment|/**   This function is called by SmmChildDispatcher module to report   a new SMI handler is registered, to SmmCore.    @param HandlerGuid     The GUID to identify the type of the handler.                          For the SmmChildDispatch protocol, the HandlerGuid                          must be the GUID of SmmChildDispatch protocol.   @param Handler         The SMI handler.   @param CallerAddress   The address of the module who registers the SMI handler.   @param Context         The context of the SMI handler.                          For the SmmChildDispatch protocol, the Context                          must match the one defined for SmmChildDispatch protocol.   @param ContextSize     The size of the context in bytes.                          For the SmmChildDispatch protocol, the Context                          must match the one defined for SmmChildDispatch protocol.    @retval EFI_SUCCESS           The information is recorded.   @retval EFI_UNSUPPORTED       The feature is unsupported.   @retval EFI_OUT_OF_RESOURCES  There is no enough resource to record the information. **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|SmiHandlerProfileRegisterHandler
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|HandlerGuid
parameter_list|,
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|Handler
parameter_list|,
name|IN
name|PHYSICAL_ADDRESS
name|CallerAddress
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|ContextSize
name|OPTIONAL
parameter_list|)
block|{
return|return
name|EFI_UNSUPPORTED
return|;
block|}
end_function

begin_comment
comment|/**   This function is called by SmmChildDispatcher module to report   an existing SMI handler is unregistered, to SmmCore.    @param HandlerGuid     The GUID to identify the type of the handler.                          For the SmmChildDispatch protocol, the HandlerGuid                          must be the GUID of SmmChildDispatch protocol.   @param Handler         The SMI handler.    @retval EFI_SUCCESS           The original record is removed.   @retval EFI_UNSUPPORTED       The feature is unsupported.   @retval EFI_NOT_FOUND         There is no record for the HandlerGuid and handler. **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|SmiHandlerProfileUnregisterHandler
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|HandlerGuid
parameter_list|,
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|Handler
parameter_list|)
block|{
return|return
name|EFI_UNSUPPORTED
return|;
block|}
end_function

end_unit

