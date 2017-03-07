begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides services that allow information about an   absolute pointer device to be retrieved.      Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ABSOLUTE_POINTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__ABSOLUTE_POINTER_H__
end_define

begin_define
define|#
directive|define
name|EFI_ABSOLUTE_POINTER_PROTOCOL_GUID
define|\
value|{ 0x8D59D32B, 0xC655, 0x4AE9, { 0x9B, 0x15, 0xF2, 0x59, 0x04, 0x99, 0x2A, 0x43 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ABSOLUTE_POINTER_PROTOCOL
name|EFI_ABSOLUTE_POINTER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//*******************************************************
end_comment

begin_comment
comment|// EFI_ABSOLUTE_POINTER_MODE
end_comment

begin_comment
comment|//*******************************************************
end_comment

begin_comment
comment|/**   The following data values in the EFI_ABSOLUTE_POINTER_MODE   interface are read-only and are changed by using the appropriate   interface functions. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|AbsoluteMinX
decl_stmt|;
comment|///< The Absolute Minimum of the device on the x-axis
name|UINT64
name|AbsoluteMinY
decl_stmt|;
comment|///< The Absolute Minimum of the device on the y axis.
name|UINT64
name|AbsoluteMinZ
decl_stmt|;
comment|///< The Absolute Minimum of the device on the z-axis
name|UINT64
name|AbsoluteMaxX
decl_stmt|;
comment|///< The Absolute Maximum of the device on the x-axis. If 0, and the
comment|///< AbsoluteMinX is 0, then the pointer device does not support a xaxis
name|UINT64
name|AbsoluteMaxY
decl_stmt|;
comment|///< The Absolute Maximum of the device on the y -axis. If 0, and the
comment|///< AbsoluteMinX is 0, then the pointer device does not support a yaxis.
name|UINT64
name|AbsoluteMaxZ
decl_stmt|;
comment|///< The Absolute Maximum of the device on the z-axis. If 0 , and the
comment|///< AbsoluteMinX is 0, then the pointer device does not support a zaxis
name|UINT32
name|Attributes
decl_stmt|;
comment|///< The following bits are set as needed (or'd together) to indicate the
comment|///< capabilities of the device supported. The remaining bits are undefined
comment|///< and should be 0
block|}
name|EFI_ABSOLUTE_POINTER_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, indicates this device supports an alternate button input.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ABSP_SupportsAltActive
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, indicates this device returns pressure data in parameter CurrentZ.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ABSP_SupportsPressureAsZ
value|0x00000002
end_define

begin_comment
comment|/**   This function resets the pointer device hardware. As part of   initialization process, the firmware/device will make a quick   but reasonable attempt to verify that the device is   functioning. If the ExtendedVerification flag is TRUE the   firmware may take an extended amount of time to verify the   device is operating on reset. Otherwise the reset operation is   to occur as quickly as possible. The hardware verification   process is not defined by this specification and is left up to   the platform firmware or driver to implement.    @param This                 A pointer to the EFI_ABSOLUTE_POINTER_PROTOCOL                               instance.    @param ExtendedVerification Indicates that the driver may                               perform a more exhaustive                               verification operation of the                               device during reset.    @retval EFI_SUCCESS       The device was reset.      @retval EFI_DEVICE_ERROR  The device is not functioning                             correctly and could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ABSOLUTE_POINTER_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_ABSOLUTE_POINTER_PROTOCOL
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
comment|///
end_comment

begin_comment
comment|/// This bit is set if the touch sensor is active.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ABSP_TouchActive
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This bit is set if the alt sensor, such as pen-side button, is active
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ABS_AltActive
value|0x00000002
end_define

begin_comment
comment|/**   Definition of EFI_ABSOLUTE_POINTER_STATE. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The unsigned position of the activation on the x axis. If the AboluteMinX
comment|/// and the AboluteMaxX fields of the EFI_ABSOLUTE_POINTER_MODE structure are
comment|/// both 0, then this pointer device does not support an x-axis, and this field
comment|/// must be ignored.
comment|///
name|UINT64
name|CurrentX
decl_stmt|;
comment|///
comment|/// The unsigned position of the activation on the y axis. If the AboluteMinY
comment|/// and the AboluteMaxY fields of the EFI_ABSOLUTE_POINTER_MODE structure are
comment|/// both 0, then this pointer device does not support an y-axis, and this field
comment|/// must be ignored.
comment|///
name|UINT64
name|CurrentY
decl_stmt|;
comment|///
comment|/// The unsigned position of the activation on the z axis, or the pressure
comment|/// measurement. If the AboluteMinZ and the AboluteMaxZ fields of the
comment|/// EFI_ABSOLUTE_POINTER_MODE structure are both 0, then this pointer device
comment|/// does not support an z-axis, and this field must be ignored.
comment|///
name|UINT64
name|CurrentZ
decl_stmt|;
comment|///
comment|/// Bits are set to 1 in this structure item to indicate that device buttons are
comment|/// active.
comment|///
name|UINT32
name|ActiveButtons
decl_stmt|;
block|}
name|EFI_ABSOLUTE_POINTER_STATE
typedef|;
end_typedef

begin_comment
comment|/**   The GetState() function retrieves the current state of a pointer   device. This includes information on the active state associated   with the pointer device and the current position of the axes   associated with the pointer device. If the state of the pointer   device has not changed since the last call to GetState(), then   EFI_NOT_READY is returned. If the state of the pointer device   has changed since the last call to GetState(), then the state   information is placed in State, and EFI_SUCCESS is returned. If   a device error occurs while attempting to retrieve the state   information, then EFI_DEVICE_ERROR is returned.     @param This   A pointer to the EFI_ABSOLUTE_POINTER_PROTOCOL                 instance.    @param State  A pointer to the state information on the                 pointer device.    @retval EFI_SUCCESS       The state of the pointer device was                             returned in State.    @retval EFI_NOT_READY     The state of the pointer device has not                             changed since the last call to GetState().    @retval EFI_DEVICE_ERROR  A device error occurred while                             attempting to retrieve the pointer                             device's current state.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ABSOLUTE_POINTER_GET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_ABSOLUTE_POINTER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_ABSOLUTE_POINTER_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_ABSOLUTE_POINTER_PROTOCOL provides a set of services
end_comment

begin_comment
comment|/// for a pointer device that can be used as an input device from an
end_comment

begin_comment
comment|/// application written to this specification. The services include
end_comment

begin_comment
comment|/// the ability to: reset the pointer device, retrieve the state of
end_comment

begin_comment
comment|/// the pointer device, and retrieve the capabilities of the pointer
end_comment

begin_comment
comment|/// device. The service also provides certain data items describing the device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ABSOLUTE_POINTER_PROTOCOL
block|{
name|EFI_ABSOLUTE_POINTER_RESET
name|Reset
decl_stmt|;
name|EFI_ABSOLUTE_POINTER_GET_STATE
name|GetState
decl_stmt|;
comment|///
comment|/// Event to use with WaitForEvent() to wait for input from the pointer device.
comment|///
name|EFI_EVENT
name|WaitForInput
decl_stmt|;
comment|///
comment|/// Pointer to EFI_ABSOLUTE_POINTER_MODE data.
comment|///
name|EFI_ABSOLUTE_POINTER_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAbsolutePointerProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

