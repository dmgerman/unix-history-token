begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Simple Pointer protocol from the UEFI 2.0 specification.    Abstraction of a very simple pointer device like a mouse or trackball.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_POINTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_POINTER_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_POINTER_PROTOCOL_GUID
define|\
value|{ \     0x31878c87, 0xb75, 0x11d5, {0x9a, 0x4f, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_POINTER_PROTOCOL
name|EFI_SIMPLE_POINTER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Data structures
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The signed distance in counts that the pointer device has been moved along the x-axis.
comment|///
name|INT32
name|RelativeMovementX
decl_stmt|;
comment|///
comment|/// The signed distance in counts that the pointer device has been moved along the y-axis.
comment|///
name|INT32
name|RelativeMovementY
decl_stmt|;
comment|///
comment|/// The signed distance in counts that the pointer device has been moved along the z-axis.
comment|///
name|INT32
name|RelativeMovementZ
decl_stmt|;
comment|///
comment|/// If TRUE, then the left button of the pointer device is being
comment|/// pressed. If FALSE, then the left button of the pointer device is not being pressed.
comment|///
name|BOOLEAN
name|LeftButton
decl_stmt|;
comment|///
comment|/// If TRUE, then the right button of the pointer device is being
comment|/// pressed. If FALSE, then the right button of the pointer device is not being pressed.
comment|///
name|BOOLEAN
name|RightButton
decl_stmt|;
block|}
name|EFI_SIMPLE_POINTER_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The resolution of the pointer device on the x-axis in counts/mm.
comment|/// If 0, then the pointer device does not support an x-axis.
comment|///
name|UINT64
name|ResolutionX
decl_stmt|;
comment|///
comment|/// The resolution of the pointer device on the y-axis in counts/mm.
comment|/// If 0, then the pointer device does not support an x-axis.
comment|///
name|UINT64
name|ResolutionY
decl_stmt|;
comment|///
comment|/// The resolution of the pointer device on the z-axis in counts/mm.
comment|/// If 0, then the pointer device does not support an x-axis.
comment|///
name|UINT64
name|ResolutionZ
decl_stmt|;
comment|///
comment|/// TRUE if a left button is present on the pointer device. Otherwise FALSE.
comment|///
name|BOOLEAN
name|LeftButton
decl_stmt|;
comment|///
comment|/// TRUE if a right button is present on the pointer device. Otherwise FALSE.
comment|///
name|BOOLEAN
name|RightButton
decl_stmt|;
block|}
name|EFI_SIMPLE_POINTER_MODE
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Resets the pointer device hardware.        @param  This                  A pointer to the EFI_SIMPLE_POINTER_PROTOCOL                                 instance.                                      @param  ExtendedVerification  Indicates that the driver may perform a more exhaustive                                 verification operation of the device during reset.                                                                           @retval EFI_SUCCESS           The device was reset.   @retval EFI_DEVICE_ERROR      The device is not functioning correctly and could not be reset.                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_POINTER_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_POINTER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the current state of a pointer device.        @param  This                  A pointer to the EFI_SIMPLE_POINTER_PROTOCOL                                 instance.                                      @param  State                 A pointer to the state information on the pointer device.                                    @retval EFI_SUCCESS           The state of the pointer device was returned in State.   @retval EFI_NOT_READY         The state of the pointer device has not changed since the last call to                                 GetState().                                                              @retval EFI_DEVICE_ERROR      A device error occurred while attempting to retrieve the pointer device's                                 current state.                                                                                                **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_POINTER_GET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_POINTER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_SIMPLE_POINTER_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SIMPLE_POINTER_PROTOCOL provides a set of services for a pointer
end_comment

begin_comment
comment|/// device that can use used as an input device from an application written
end_comment

begin_comment
comment|/// to this specification. The services include the ability to reset the
end_comment

begin_comment
comment|/// pointer device, retrieve get the state of the pointer device, and
end_comment

begin_comment
comment|/// retrieve the capabilities of the pointer device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIMPLE_POINTER_PROTOCOL
block|{
name|EFI_SIMPLE_POINTER_RESET
name|Reset
decl_stmt|;
name|EFI_SIMPLE_POINTER_GET_STATE
name|GetState
decl_stmt|;
comment|///
comment|/// Event to use with WaitForEvent() to wait for input from the pointer device.
comment|///
name|EFI_EVENT
name|WaitForInput
decl_stmt|;
comment|///
comment|/// Pointer to EFI_SIMPLE_POINTER_MODE data.
comment|///
name|EFI_SIMPLE_POINTER_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimplePointerProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

