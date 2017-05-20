begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Simple Text Input Ex protocol from the UEFI 2.0 specification.    This protocol defines an extension to the EFI_SIMPLE_TEXT_INPUT_PROTOCOL   which exposes much more state and modifier information from the input device,   also allows one to register a notification for a particular keystroke.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_TEXT_IN_EX_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_TEXT_IN_EX_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/SimpleTextIn.h>
end_include

begin_define
define|#
directive|define
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_GUID
define|\
value|{0xdd9e7534, 0x7762, 0x4698, { 0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The Reset() function resets the input device hardware. As part   of initialization process, the firmware/device will make a quick   but reasonable attempt to verify that the device is functioning.   If the ExtendedVerification flag is TRUE the firmware may take   an extended amount of time to verify the device is operating on   reset. Otherwise the reset operation is to occur as quickly as   possible. The hardware verification process is not defined by   this specification and is left up to the platform firmware or   driver to implement.    @param This                 A pointer to the EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL instance.    @param ExtendedVerification Indicates that the driver may                               perform a more exhaustive                               verification operation of the                               device during reset.     @retval EFI_SUCCESS       The device was reset.    @retval EFI_DEVICE_ERROR  The device is not functioning                             correctly and could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INPUT_RESET_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
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
comment|/// EFI_KEY_TOGGLE_STATE. The toggle states are defined.
end_comment

begin_comment
comment|/// They are: EFI_TOGGLE_STATE_VALID, EFI_SCROLL_LOCK_ACTIVE
end_comment

begin_comment
comment|/// EFI_NUM_LOCK_ACTIVE, EFI_CAPS_LOCK_ACTIVE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|EFI_KEY_TOGGLE_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_KEY_STATE
block|{
comment|///
comment|/// Reflects the currently pressed shift
comment|/// modifiers for the input device. The
comment|/// returned value is valid only if the high
comment|/// order bit has been set.
comment|///
name|UINT32
name|KeyShiftState
decl_stmt|;
comment|///
comment|/// Reflects the current internal state of
comment|/// various toggled attributes. The returned
comment|/// value is valid only if the high order
comment|/// bit has been set.
comment|///
name|EFI_KEY_TOGGLE_STATE
name|KeyToggleState
decl_stmt|;
block|}
name|EFI_KEY_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The EFI scan code and Unicode value returned from the input device.
comment|///
name|EFI_INPUT_KEY
name|Key
decl_stmt|;
comment|///
comment|/// The current state of various toggled attributes as well as input modifier values.
comment|///
name|EFI_KEY_STATE
name|KeyState
decl_stmt|;
block|}
name|EFI_KEY_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Any Shift or Toggle State that is valid should have
end_comment

begin_comment
comment|// high order bit set.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Shift state
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SHIFT_STATE_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_SHIFT_PRESSED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_SHIFT_PRESSED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_CONTROL_PRESSED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_CONTROL_PRESSED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_ALT_PRESSED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_ALT_PRESSED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_LOGO_PRESSED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_LOGO_PRESSED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EFI_MENU_KEY_PRESSED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EFI_SYS_REQ_PRESSED
value|0x00000200
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Toggle state
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_TOGGLE_STATE_VALID
value|0x80
end_define

begin_define
define|#
directive|define
name|EFI_KEY_STATE_EXPOSED
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_SCROLL_LOCK_ACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_NUM_LOCK_ACTIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_CAPS_LOCK_ACTIVE
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Scan codes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SCAN_F11
value|0x0015
end_define

begin_define
define|#
directive|define
name|SCAN_F12
value|0x0016
end_define

begin_define
define|#
directive|define
name|SCAN_PAUSE
value|0x0048
end_define

begin_define
define|#
directive|define
name|SCAN_F13
value|0x0068
end_define

begin_define
define|#
directive|define
name|SCAN_F14
value|0x0069
end_define

begin_define
define|#
directive|define
name|SCAN_F15
value|0x006A
end_define

begin_define
define|#
directive|define
name|SCAN_F16
value|0x006B
end_define

begin_define
define|#
directive|define
name|SCAN_F17
value|0x006C
end_define

begin_define
define|#
directive|define
name|SCAN_F18
value|0x006D
end_define

begin_define
define|#
directive|define
name|SCAN_F19
value|0x006E
end_define

begin_define
define|#
directive|define
name|SCAN_F20
value|0x006F
end_define

begin_define
define|#
directive|define
name|SCAN_F21
value|0x0070
end_define

begin_define
define|#
directive|define
name|SCAN_F22
value|0x0071
end_define

begin_define
define|#
directive|define
name|SCAN_F23
value|0x0072
end_define

begin_define
define|#
directive|define
name|SCAN_F24
value|0x0073
end_define

begin_define
define|#
directive|define
name|SCAN_MUTE
value|0x007F
end_define

begin_define
define|#
directive|define
name|SCAN_VOLUME_UP
value|0x0080
end_define

begin_define
define|#
directive|define
name|SCAN_VOLUME_DOWN
value|0x0081
end_define

begin_define
define|#
directive|define
name|SCAN_BRIGHTNESS_UP
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCAN_BRIGHTNESS_DOWN
value|0x0101
end_define

begin_define
define|#
directive|define
name|SCAN_SUSPEND
value|0x0102
end_define

begin_define
define|#
directive|define
name|SCAN_HIBERNATE
value|0x0103
end_define

begin_define
define|#
directive|define
name|SCAN_TOGGLE_DISPLAY
value|0x0104
end_define

begin_define
define|#
directive|define
name|SCAN_RECOVERY
value|0x0105
end_define

begin_define
define|#
directive|define
name|SCAN_EJECT
value|0x0106
end_define

begin_comment
comment|/**   The function reads the next keystroke from the input device. If   there is no pending keystroke the function returns   EFI_NOT_READY. If there is a pending keystroke, then   KeyData.Key.ScanCode is the EFI scan code defined in Error!   Reference source not found. The KeyData.Key.UnicodeChar is the   actual printable character or is zero if the key does not   represent a printable character (control key, function key,   etc.). The KeyData.KeyState is shift state for the character   reflected in KeyData.Key.UnicodeChar or KeyData.Key.ScanCode .   When interpreting the data from this function, it should be   noted that if a class of printable characters that are   normally adjusted by shift modifiers (e.g. Shift Key + "f"   key) would be presented solely as a KeyData.Key.UnicodeChar   without the associated shift state. So in the previous example   of a Shift Key + "f" key being pressed, the only pertinent   data returned would be KeyData.Key.UnicodeChar with the value   of "F". This of course would not typically be the case for   non-printable characters such as the pressing of the Right   Shift Key + F10 key since the corresponding returned data   would be reflected both in the KeyData.KeyState.KeyShiftState   and KeyData.Key.ScanCode values. UEFI drivers which implement   the EFI_SIMPLE_TEXT_INPUT_EX protocol are required to return   KeyData.Key and KeyData.KeyState values. These drivers must   always return the most current state of   KeyData.KeyState.KeyShiftState and   KeyData.KeyState.KeyToggleState. It should also be noted that   certain input devices may not be able to produce shift or toggle   state information, and in those cases the high order bit in the   respective Toggle and Shift state fields should not be active.     @param This     A pointer to the EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL instance.    @param KeyData  A pointer to a buffer that is filled in with                   the keystroke state data for the key that was                   pressed.     @retval EFI_SUCCESS     The keystroke information was                           returned.    @retval EFI_NOT_READY   There was no keystroke data available.                           EFI_DEVICE_ERROR The keystroke                           information was not returned due to                           hardware errors.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INPUT_READ_KEY_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_KEY_DATA
modifier|*
name|KeyData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The SetState() function allows the input device hardware to   have state settings adjusted.    @param This           A pointer to the EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL instance.    @param KeyToggleState Pointer to the EFI_KEY_TOGGLE_STATE to                         set the state for the input device.     @retval EFI_SUCCESS       The device state was set appropriately.    @retval EFI_DEVICE_ERROR  The device is not functioning                             correctly and could not have the                             setting adjusted.    @retval EFI_UNSUPPORTED   The device does not support the                             ability to have its state set.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_KEY_TOGGLE_STATE
modifier|*
name|KeyToggleState
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The function will be called when the key sequence is typed specified by KeyData.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_KEY_NOTIFY_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_KEY_DATA
modifier|*
name|KeyData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The RegisterKeystrokeNotify() function registers a function   which will be called when a specified keystroke will occur.    @param This                     A pointer to the EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL instance.    @param KeyData                  A pointer to a buffer that is filled in with                                   the keystroke information for the key that was                                   pressed.    @param KeyNotificationFunction  Points to the function to be                                   called when the key sequence                                   is typed specified by KeyData.     @param NotifyHandle             Points to the unique handle assigned to                                   the registered notification.    @retval EFI_SUCCESS           The device state was set                                 appropriately.    @retval EFI_OUT_OF_RESOURCES  Unable to allocate necessary                                 data structures.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REGISTER_KEYSTROKE_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_KEY_DATA
modifier|*
name|KeyData
parameter_list|,
name|IN
name|EFI_KEY_NOTIFY_FUNCTION
name|KeyNotificationFunction
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|NotifyHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The UnregisterKeystrokeNotify() function removes the   notification which was previously registered.    @param This               A pointer to the EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL instance.    @param NotificationHandle The handle of the notification                             function being unregistered.    @retval EFI_SUCCESS The device state was set appropriately.    @retval EFI_INVALID_PARAMETER The NotificationHandle is                                 invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNREGISTER_KEYSTROKE_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|NotificationHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL is used on the ConsoleIn
end_comment

begin_comment
comment|/// device. It is an extension to the Simple Text Input protocol
end_comment

begin_comment
comment|/// which allows a variety of extended shift state information to be
end_comment

begin_comment
comment|/// returned.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL
block|{
name|EFI_INPUT_RESET_EX
name|Reset
decl_stmt|;
name|EFI_INPUT_READ_KEY_EX
name|ReadKeyStrokeEx
decl_stmt|;
comment|///
comment|/// Event to use with WaitForEvent() to wait for a key to be available.
comment|///
name|EFI_EVENT
name|WaitForKeyEx
decl_stmt|;
name|EFI_SET_STATE
name|SetState
decl_stmt|;
name|EFI_REGISTER_KEYSTROKE_NOTIFY
name|RegisterKeyNotify
decl_stmt|;
name|EFI_UNREGISTER_KEYSTROKE_NOTIFY
name|UnregisterKeyNotify
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimpleTextInputExProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

