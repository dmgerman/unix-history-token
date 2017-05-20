begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Simple Text Out protocol from the UEFI 2.0 specification.    Abstraction of a very simple text based output device like VGA text mode or   a serial terminal. The Simple Text Out protocol instance can represent   a single hardware device or a virtual device that is an aggregation   of multiple physical devices.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_TEXT_OUT_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_TEXT_OUT_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID
define|\
value|{ \     0x387477c2, 0x69c7, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SIMPLE_TEXT_OUTPUT_PROTOCOL
value|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Backward-compatible with EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
name|SIMPLE_TEXT_OUTPUT_INTERFACE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define's for required EFI Unicode Box Draw characters
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BOXDRAW_HORIZONTAL
value|0x2500
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL
value|0x2502
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_RIGHT
value|0x250c
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_LEFT
value|0x2510
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_RIGHT
value|0x2514
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_LEFT
value|0x2518
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_RIGHT
value|0x251c
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_LEFT
value|0x2524
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_HORIZONTAL
value|0x252c
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_HORIZONTAL
value|0x2534
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_HORIZONTAL
value|0x253c
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_HORIZONTAL
value|0x2550
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_VERTICAL
value|0x2551
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_RIGHT_DOUBLE
value|0x2552
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_DOUBLE_RIGHT
value|0x2553
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_DOWN_RIGHT
value|0x2554
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_LEFT_DOUBLE
value|0x2555
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_DOUBLE_LEFT
value|0x2556
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_DOWN_LEFT
value|0x2557
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_RIGHT_DOUBLE
value|0x2558
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_DOUBLE_RIGHT
value|0x2559
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_UP_RIGHT
value|0x255a
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_LEFT_DOUBLE
value|0x255b
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_DOUBLE_LEFT
value|0x255c
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_UP_LEFT
value|0x255d
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_RIGHT_DOUBLE
value|0x255e
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_DOUBLE_RIGHT
value|0x255f
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_VERTICAL_RIGHT
value|0x2560
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_LEFT_DOUBLE
value|0x2561
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_DOUBLE_LEFT
value|0x2562
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_VERTICAL_LEFT
value|0x2563
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_HORIZONTAL_DOUBLE
value|0x2564
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOWN_DOUBLE_HORIZONTAL
value|0x2565
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_DOWN_HORIZONTAL
value|0x2566
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_HORIZONTAL_DOUBLE
value|0x2567
end_define

begin_define
define|#
directive|define
name|BOXDRAW_UP_DOUBLE_HORIZONTAL
value|0x2568
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_UP_HORIZONTAL
value|0x2569
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE
value|0x256a
end_define

begin_define
define|#
directive|define
name|BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL
value|0x256b
end_define

begin_define
define|#
directive|define
name|BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL
value|0x256c
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Required Block Elements Code Chart
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BLOCKELEMENT_FULL_BLOCK
value|0x2588
end_define

begin_define
define|#
directive|define
name|BLOCKELEMENT_LIGHT_SHADE
value|0x2591
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Required Geometric Shapes Code Chart
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GEOMETRICSHAPE_UP_TRIANGLE
value|0x25b2
end_define

begin_define
define|#
directive|define
name|GEOMETRICSHAPE_RIGHT_TRIANGLE
value|0x25ba
end_define

begin_define
define|#
directive|define
name|GEOMETRICSHAPE_DOWN_TRIANGLE
value|0x25bc
end_define

begin_define
define|#
directive|define
name|GEOMETRICSHAPE_LEFT_TRIANGLE
value|0x25c4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Required Arrow shapes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ARROW_LEFT
value|0x2190
end_define

begin_define
define|#
directive|define
name|ARROW_UP
value|0x2191
end_define

begin_define
define|#
directive|define
name|ARROW_RIGHT
value|0x2192
end_define

begin_define
define|#
directive|define
name|ARROW_DOWN
value|0x2193
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Console Colours
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_BLACK
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_BLUE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GREEN
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_CYAN
value|(EFI_BLUE | EFI_GREEN)
end_define

begin_define
define|#
directive|define
name|EFI_RED
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_MAGENTA
value|(EFI_BLUE | EFI_RED)
end_define

begin_define
define|#
directive|define
name|EFI_BROWN
value|(EFI_GREEN | EFI_RED)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTGRAY
value|(EFI_BLUE | EFI_GREEN | EFI_RED)
end_define

begin_define
define|#
directive|define
name|EFI_BRIGHT
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_DARKGRAY
value|(EFI_BLACK | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTBLUE
value|(EFI_BLUE | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTGREEN
value|(EFI_GREEN | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTCYAN
value|(EFI_CYAN | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTRED
value|(EFI_RED | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_LIGHTMAGENTA
value|(EFI_MAGENTA | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_YELLOW
value|(EFI_BROWN | EFI_BRIGHT)
end_define

begin_define
define|#
directive|define
name|EFI_WHITE
value|(EFI_BLUE | EFI_GREEN | EFI_RED | EFI_BRIGHT)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Macro to accept color values in their raw form to create
end_comment

begin_comment
comment|// a value that represents both a foreground and background
end_comment

begin_comment
comment|// color in a single byte.
end_comment

begin_comment
comment|// For Foreground, and EFI_* value is valid from EFI_BLACK(0x00) to
end_comment

begin_comment
comment|// EFI_WHITE (0x0F).
end_comment

begin_comment
comment|// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN, EFI_CYAN,
end_comment

begin_comment
comment|// EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY are acceptable
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Do not use EFI_BACKGROUND_xxx values with this macro.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_TEXT_ATTR
parameter_list|(
name|Foreground
parameter_list|,
name|Background
parameter_list|)
value|((Foreground) | ((Background)<< 4))
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_BLACK
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_BLUE
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_GREEN
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_CYAN
value|(EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN)
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_RED
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_MAGENTA
value|(EFI_BACKGROUND_BLUE | EFI_BACKGROUND_RED)
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_BROWN
value|(EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
end_define

begin_define
define|#
directive|define
name|EFI_BACKGROUND_LIGHTGRAY
value|(EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// We currently define attributes from 0 - 7F for color manipulations
end_comment

begin_comment
comment|// To internally handle the local display characteristics for a particular character,
end_comment

begin_comment
comment|// Bit 7 signifies the local glyph representation for a character.  If turned on, glyphs will be
end_comment

begin_comment
comment|// pulled from the wide glyph database and will display locally as a wide character (16 X 19 versus 8 X 19)
end_comment

begin_comment
comment|// If bit 7 is off, the narrow glyph database will be used.  This does NOT affect information that is sent to
end_comment

begin_comment
comment|// non-local displays, such as serial or LAN consoles.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_WIDE_ATTRIBUTE
value|0x80
end_define

begin_comment
comment|/**   Reset the text output device hardware and optionaly run diagnostics    @param  This                 The protocol instance pointer.   @param  ExtendedVerification Driver may perform more exhaustive verification                                operation of the device during reset.    @retval EFI_SUCCESS          The text output device was reset.   @retval EFI_DEVICE_ERROR     The text output device is not functioning correctly and                                could not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
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
comment|/**   Write a string to the output device.    @param  This   The protocol instance pointer.   @param  String The NULL-terminated string to be displayed on the output                  device(s). All output devices must also support the Unicode                  drawing character codes defined in this file.    @retval EFI_SUCCESS             The string was output to the device.   @retval EFI_DEVICE_ERROR        The device reported an error while attempting to output                                   the text.   @retval EFI_UNSUPPORTED         The output device's mode is not currently in a                                   defined text mode.   @retval EFI_WARN_UNKNOWN_GLYPH  This warning code indicates that some of the                                   characters in the string could not be                                   rendered and were skipped.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_STRING
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Verifies that all characters in a string can be output to the    target device.    @param  This   The protocol instance pointer.   @param  String The NULL-terminated string to be examined for the output                  device(s).    @retval EFI_SUCCESS      The device(s) are capable of rendering the output string.   @retval EFI_UNSUPPORTED  Some of the characters in the string cannot be                            rendered by one or more of the output devices mapped                            by the EFI handle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_TEST_STRING
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information for an available text mode that the output device(s)   supports.    @param  This       The protocol instance pointer.   @param  ModeNumber The mode number to return information on.   @param  Columns    Returns the geometry of the text output device for the                      requested ModeNumber.   @param  Rows       Returns the geometry of the text output device for the                      requested ModeNumber.                                              @retval EFI_SUCCESS      The requested mode information was returned.   @retval EFI_DEVICE_ERROR The device had an error and could not complete the request.   @retval EFI_UNSUPPORTED  The mode number was not valid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_QUERY_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ModeNumber
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Columns
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Rows
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the output device(s) to a specified mode.    @param  This       The protocol instance pointer.   @param  ModeNumber The mode number to set.    @retval EFI_SUCCESS      The requested text mode was set.   @retval EFI_DEVICE_ERROR The device had an error and could not complete the request.   @retval EFI_UNSUPPORTED  The mode number was not valid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_SET_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ModeNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the background and foreground colors for the OutputString () and   ClearScreen () functions.    @param  This      The protocol instance pointer.   @param  Attribute The attribute to set. Bits 0..3 are the foreground color, and                     bits 4..6 are the background color. All other bits are undefined                     and must be zero. The valid Attributes are defined in this file.    @retval EFI_SUCCESS       The attribute was set.   @retval EFI_DEVICE_ERROR  The device had an error and could not complete the request.   @retval EFI_UNSUPPORTED   The attribute requested is not defined.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_SET_ATTRIBUTE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Attribute
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Clears the output device(s) display to the currently selected background    color.    @param  This              The protocol instance pointer.                               @retval  EFI_SUCCESS      The operation completed successfully.   @retval  EFI_DEVICE_ERROR The device had an error and could not complete the request.   @retval  EFI_UNSUPPORTED  The output device is not in a valid text mode.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_CLEAR_SCREEN
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the current coordinates of the cursor position    @param  This        The protocol instance pointer.   @param  Column      The position to set the cursor to. Must be greater than or                       equal to zero and less than the number of columns and rows                       by QueryMode ().   @param  Row         The position to set the cursor to. Must be greater than or                       equal to zero and less than the number of columns and rows                       by QueryMode ().    @retval EFI_SUCCESS      The operation completed successfully.   @retval EFI_DEVICE_ERROR The device had an error and could not complete the request.   @retval EFI_UNSUPPORTED  The output device is not in a valid text mode, or the                            cursor position is invalid for the current mode.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_SET_CURSOR_POSITION
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Column
parameter_list|,
name|IN
name|UINTN
name|Row
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Makes the cursor visible or invisible    @param  This    The protocol instance pointer.   @param  Visible If TRUE, the cursor is set to be visible. If FALSE, the cursor is                   set to be invisible.    @retval EFI_SUCCESS      The operation completed successfully.   @retval EFI_DEVICE_ERROR The device had an error and could not complete the                            request, or the device does not support changing                            the cursor mode.   @retval EFI_UNSUPPORTED  The output device is not in a valid text mode.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_ENABLE_CURSOR
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Visible
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   @par Data Structure Description:   Mode Structure pointed to by Simple Text Out protocol. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The number of modes supported by QueryMode () and SetMode ().
comment|///
name|INT32
name|MaxMode
decl_stmt|;
comment|//
comment|// current settings
comment|//
comment|///
comment|/// The text mode of the output device(s).
comment|///
name|INT32
name|Mode
decl_stmt|;
comment|///
comment|/// The current character output attribute.
comment|///
name|INT32
name|Attribute
decl_stmt|;
comment|///
comment|/// The cursor's column.
comment|///
name|INT32
name|CursorColumn
decl_stmt|;
comment|///
comment|/// The cursor's row.
comment|///
name|INT32
name|CursorRow
decl_stmt|;
comment|///
comment|/// The cursor is currently visbile or not.
comment|///
name|BOOLEAN
name|CursorVisible
decl_stmt|;
block|}
name|EFI_SIMPLE_TEXT_OUTPUT_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The SIMPLE_TEXT_OUTPUT protocol is used to control text-based output devices.
end_comment

begin_comment
comment|/// It is the minimum required protocol for any handle supplied as the ConsoleOut
end_comment

begin_comment
comment|/// or StandardError device. In addition, the minimum supported text mode of such
end_comment

begin_comment
comment|/// devices is at least 80 x 25 characters.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
block|{
name|EFI_TEXT_RESET
name|Reset
decl_stmt|;
name|EFI_TEXT_STRING
name|OutputString
decl_stmt|;
name|EFI_TEXT_TEST_STRING
name|TestString
decl_stmt|;
name|EFI_TEXT_QUERY_MODE
name|QueryMode
decl_stmt|;
name|EFI_TEXT_SET_MODE
name|SetMode
decl_stmt|;
name|EFI_TEXT_SET_ATTRIBUTE
name|SetAttribute
decl_stmt|;
name|EFI_TEXT_CLEAR_SCREEN
name|ClearScreen
decl_stmt|;
name|EFI_TEXT_SET_CURSOR_POSITION
name|SetCursorPosition
decl_stmt|;
name|EFI_TEXT_ENABLE_CURSOR
name|EnableCursor
decl_stmt|;
comment|///
comment|/// Pointer to SIMPLE_TEXT_OUTPUT_MODE data.
comment|///
name|EFI_SIMPLE_TEXT_OUTPUT_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimpleTextOutProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

