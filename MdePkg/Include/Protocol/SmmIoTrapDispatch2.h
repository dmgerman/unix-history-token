begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM IO Trap Dispatch2 Protocol as defined in PI 1.1 Specification   Volume 4 System Management Mode Core Interface.    This protocol provides a parent dispatch service for IO trap SMI sources.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This protocol is from PI Version 1.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_IO_TRAP_DISPATCH2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_IO_TRAP_DISPATCH2_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiSmmCis.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL_GUID
define|\
value|{ \     0x58dc368d, 0x7bfa, 0x4e77, {0xab, 0xbc, 0xe, 0x29, 0x41, 0x8d, 0xf9, 0x30 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Trap valid types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|WriteTrap
block|,
name|ReadTrap
block|,
name|ReadWriteTrap
block|,
name|IoTrapTypeMaximum
block|}
name|EFI_SMM_IO_TRAP_DISPATCH_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Trap context structure containing information about the
end_comment

begin_comment
comment|/// IO trap event that should invoke the handler
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Address
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|EFI_SMM_IO_TRAP_DISPATCH_TYPE
name|Type
decl_stmt|;
block|}
name|EFI_SMM_IO_TRAP_REGISTER_CONTEXT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Trap context structure containing information about the IO trap that occurred
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|WriteData
decl_stmt|;
block|}
name|EFI_SMM_IO_TRAP_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL
name|EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Register an IO trap SMI child handler for a specified SMI.    This service registers a function (DispatchFunction) which will be called when an SMI is    generated because of an access to an I/O port specified by RegisterContext. On return,    DispatchHandle contains a unique handle which may be used later to unregister the function    using UnRegister(). If the base of the I/O range specified is zero, then an I/O range with the    specified length and characteristics will be allocated and the Address field in RegisterContext    updated. If no range could be allocated, then EFI_OUT_OF_RESOURCES will be returned.     The service will not perform GCD allocation if the base address is non-zero or    EFI_SMM_READY_TO_LOCK has been installed.  In this case, the caller is responsible for the    existence and allocation of the specific IO range.   An error may be returned if some or all of the requested resources conflict with an existing IO trap    child handler.    It is not required that implementations will allow multiple children for a single IO trap SMI source.     Some implementations may support multiple children.   The DispatchFunction will be called with Context updated to contain information    concerning the I/O action that actually happened and is passed in RegisterContext, with    CommBuffer pointing to the data actually written and CommBufferSize pointing to the size of    the data in CommBuffer.    @param[in]  This               Pointer to the EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL instance.   @param[in]  DispatchFunction   Function to register for handler when I/O trap location is accessed.   @param[in]  RegisterContext    Pointer to the dispatch function's context.  The caller fills this                                  context in before calling the register function to indicate to the register                                  function the IO trap SMI source for which the dispatch function should be invoked.   @param[out] DispatchHandle     Handle of the dispatch function, for when interfacing with the parent SMM driver.    @retval EFI_SUCCESS            The dispatch function has been successfully registered.   @retval EFI_DEVICE_ERROR       The driver was unable to complete due to hardware error.   @retval EFI_OUT_OF_RESOURCES   Insufficient resources are available to fulfill the IO trap range request.   @retval EFI_INVALID_PARAMETER  RegisterContext is invalid.  The input value is not within a valid range. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_IO_TRAP_DISPATCH2_REGISTER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|DispatchFunction
parameter_list|,
name|IN
name|OUT
name|EFI_SMM_IO_TRAP_REGISTER_CONTEXT
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
comment|/**   Unregister a child SMI source dispatch function with a parent SMM driver.    This service removes a previously installed child dispatch handler. This does not guarantee that the    system resources will be freed from the GCD.    @param[in] This                Pointer to the EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL instance.    @param[in] DispatchHandle      Handle of the child service to remove.    @retval EFI_SUCCESS            The dispatch function has been successfully unregistered.   @retval EFI_INVALID_PARAMETER  The DispatchHandle was not valid. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_IO_TRAP_DISPATCH2_UNREGISTER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL
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
comment|/// Interface structure for the SMM IO Trap Dispatch2 Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides a parent dispatch service for IO trap SMI sources.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_IO_TRAP_DISPATCH2_PROTOCOL
block|{
name|EFI_SMM_IO_TRAP_DISPATCH2_REGISTER
name|Register
decl_stmt|;
name|EFI_SMM_IO_TRAP_DISPATCH2_UNREGISTER
name|UnRegister
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmIoTrapDispatch2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

