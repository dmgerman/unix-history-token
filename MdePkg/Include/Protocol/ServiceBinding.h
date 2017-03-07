begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file     UEFI Service Binding Protocol is defined in UEFI specification.    The file defines the generic Service Binding Protocol functions.   It provides services that are required to create and destroy child    handles that support a given set of protocols.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SERVICE_BINDING_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SERVICE_BINDING_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward reference for pure ANSI compatability
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_SERVICE_BINDING_PROTOCOL
name|EFI_SERVICE_BINDING_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Creates a child handle and installs a protocol.      The CreateChild() function installs a protocol on ChildHandle.    If ChildHandle is a pointer to NULL, then a new handle is created and returned in ChildHandle.    If ChildHandle is not a pointer to NULL, then the protocol installs on the existing ChildHandle.    @param  This        Pointer to the EFI_SERVICE_BINDING_PROTOCOL instance.   @param  ChildHandle Pointer to the handle of the child to create. If it is NULL,                       then a new handle is created. If it is a pointer to an existing UEFI handle,                        then the protocol is added to the existing UEFI handle.    @retval EFI_SUCCES            The protocol was added to ChildHandle.   @retval EFI_INVALID_PARAMETER ChildHandle is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to create                                 the child   @retval other                 The child handle was not created  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERVICE_BINDING_CREATE_CHILD
function_decl|)
parameter_list|(
name|IN
name|EFI_SERVICE_BINDING_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|ChildHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Destroys a child handle with a protocol installed on it.      The DestroyChild() function does the opposite of CreateChild(). It removes a protocol    that was installed by CreateChild() from ChildHandle. If the removed protocol is the    last protocol on ChildHandle, then ChildHandle is destroyed.    @param  This        Pointer to the EFI_SERVICE_BINDING_PROTOCOL instance.   @param  ChildHandle Handle of the child to destroy    @retval EFI_SUCCES            The protocol was removed from ChildHandle.   @retval EFI_UNSUPPORTED       ChildHandle does not support the protocol that is being removed.   @retval EFI_INVALID_PARAMETER Child handle is NULL.   @retval EFI_ACCESS_DENIED     The protocol could not be removed from the ChildHandle                                 because its services are being used.   @retval other                 The child handle was not destroyed  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERVICE_BINDING_DESTROY_CHILD
function_decl|)
parameter_list|(
name|IN
name|EFI_SERVICE_BINDING_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SERVICE_BINDING_PROTOCOL provides member functions to create and destroy
end_comment

begin_comment
comment|/// child handles. A driver is responsible for adding protocols to the child handle
end_comment

begin_comment
comment|/// in CreateChild() and removing protocols in DestroyChild(). It is also required
end_comment

begin_comment
comment|/// that the CreateChild() function opens the parent protocol BY_CHILD_CONTROLLER
end_comment

begin_comment
comment|/// to establish the parent-child relationship, and closes the protocol in DestroyChild().
end_comment

begin_comment
comment|/// The pseudo code for CreateChild() and DestroyChild() is provided to specify the
end_comment

begin_comment
comment|/// required behavior, not to specify the required implementation. Each consumer of
end_comment

begin_comment
comment|/// a software protocol is responsible for calling CreateChild() when it requires the
end_comment

begin_comment
comment|/// protocol and calling DestroyChild() when it is finished with that protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SERVICE_BINDING_PROTOCOL
block|{
name|EFI_SERVICE_BINDING_CREATE_CHILD
name|CreateChild
decl_stmt|;
name|EFI_SERVICE_BINDING_DESTROY_CHILD
name|DestroyChild
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

