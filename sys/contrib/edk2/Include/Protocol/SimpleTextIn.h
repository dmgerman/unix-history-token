begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Simple Text Input protocol from the UEFI 2.0 specification.    Abstraction of a very simple input device like a keyboard or serial   terminal.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_TEXT_IN_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_TEXT_IN_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID
define|\
value|{ \     0x387477c1, 0x69c7, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_TEXT_INPUT_PROTOCOL
name|EFI_SIMPLE_TEXT_INPUT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SIMPLE_INPUT_PROTOCOL
value|EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol name in EFI1.1 for backward-compatible.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_TEXT_INPUT_PROTOCOL
name|SIMPLE_INPUT_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The keystroke information for the key that was pressed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|ScanCode
decl_stmt|;
name|CHAR16
name|UnicodeChar
decl_stmt|;
block|}
name|EFI_INPUT_KEY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Required unicode control chars
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CHAR_BACKSPACE
value|0x0008
end_define

begin_define
define|#
directive|define
name|CHAR_TAB
value|0x0009
end_define

begin_define
define|#
directive|define
name|CHAR_LINEFEED
value|0x000A
end_define

begin_define
define|#
directive|define
name|CHAR_CARRIAGE_RETURN
value|0x000D
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
name|SCAN_NULL
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCAN_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCAN_DOWN
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCAN_RIGHT
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCAN_LEFT
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCAN_HOME
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCAN_END
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCAN_INSERT
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCAN_DELETE
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCAN_PAGE_UP
value|0x0009
end_define

begin_define
define|#
directive|define
name|SCAN_PAGE_DOWN
value|0x000A
end_define

begin_define
define|#
directive|define
name|SCAN_F1
value|0x000B
end_define

begin_define
define|#
directive|define
name|SCAN_F2
value|0x000C
end_define

begin_define
define|#
directive|define
name|SCAN_F3
value|0x000D
end_define

begin_define
define|#
directive|define
name|SCAN_F4
value|0x000E
end_define

begin_define
define|#
directive|define
name|SCAN_F5
value|0x000F
end_define

begin_define
define|#
directive|define
name|SCAN_F6
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCAN_F7
value|0x0011
end_define

begin_define
define|#
directive|define
name|SCAN_F8
value|0x0012
end_define

begin_define
define|#
directive|define
name|SCAN_F9
value|0x0013
end_define

begin_define
define|#
directive|define
name|SCAN_F10
value|0x0014
end_define

begin_define
define|#
directive|define
name|SCAN_ESC
value|0x0017
end_define

begin_comment
comment|/**   Reset the input device and optionally run diagnostics    @param  This                 Protocol instance pointer.   @param  ExtendedVerification Driver may perform diagnostics on reset.    @retval EFI_SUCCESS          The device was reset.   @retval EFI_DEVICE_ERROR     The device is not functioning properly and could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INPUT_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_PROTOCOL
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
comment|/**   Reads the next keystroke from the input device. The WaitForKey Event can   be used to test for existence of a keystroke via WaitForEvent () call.    @param  This  Protocol instance pointer.   @param  Key   A pointer to a buffer that is filled in with the keystroke                 information for the key that was pressed.    @retval EFI_SUCCESS      The keystroke information was returned.   @retval EFI_NOT_READY    There was no keystroke data available.   @retval EFI_DEVICE_ERROR The keystroke information was not returned due to                            hardware errors.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INPUT_READ_KEY
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_INPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_INPUT_KEY
modifier|*
name|Key
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SIMPLE_TEXT_INPUT_PROTOCOL is used on the ConsoleIn device.
end_comment

begin_comment
comment|/// It is the minimum required protocol for ConsoleIn.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIMPLE_TEXT_INPUT_PROTOCOL
block|{
name|EFI_INPUT_RESET
name|Reset
decl_stmt|;
name|EFI_INPUT_READ_KEY
name|ReadKeyStroke
decl_stmt|;
comment|///
comment|/// Event to use with WaitForEvent() to wait for a key to be available
comment|///
name|EFI_EVENT
name|WaitForKey
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimpleTextInProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

