begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_CON_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_CON_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      eficon.h  Abstract:      EFI console protocols    Revision History  --*/
end_comment

begin_comment
comment|/*  * Text output protocol  */
end_comment

begin_define
define|#
directive|define
name|SIMPLE_TEXT_OUTPUT_PROTOCOL
define|\
value|{ 0x387477c2, 0x69c7, 0x11d2, 0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b }
end_define

begin_expr_stmt
name|INTERFACE_DECL
argument_list|(
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TEXT_OUTPUT_STRING
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ModeNumber
parameter_list|)
function_decl|;
end_typedef

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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Attribute
parameter_list|)
function_decl|;
end_typedef

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
value|(EFI_BRIGHT)
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

begin_define
define|#
directive|define
name|EFI_TEXT_ATTR
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|((f) | ((b)<< 4))
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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
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
name|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Enable
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT32
name|MaxMode
decl_stmt|;
comment|/* current settings */
name|INT32
name|Mode
decl_stmt|;
name|INT32
name|Attribute
decl_stmt|;
name|INT32
name|CursorColumn
decl_stmt|;
name|INT32
name|CursorRow
decl_stmt|;
name|BOOLEAN
name|CursorVisible
decl_stmt|;
block|}
name|SIMPLE_TEXT_OUTPUT_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SIMPLE_TEXT_OUTPUT_INTERFACE
block|{
name|EFI_TEXT_RESET
name|Reset
decl_stmt|;
name|EFI_TEXT_OUTPUT_STRING
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
comment|/* Current mode */
name|SIMPLE_TEXT_OUTPUT_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
name|SIMPLE_TEXT_OUTPUT_INTERFACE
typedef|;
end_typedef

begin_comment
comment|/*  * Define's for required EFI Unicode Box Draw character  */
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
comment|/*  * EFI Required Block Elements Code Chart  */
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
comment|/*  * EFI Required Geometric Shapes Code Chart  */
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
comment|/*  * EFI Required Arrow shapes  */
end_comment

begin_define
define|#
directive|define
name|ARROW_UP
value|0x2191
end_define

begin_define
define|#
directive|define
name|ARROW_DOWN
value|0x2193
end_define

begin_comment
comment|/*  * Text input protocol  */
end_comment

begin_define
define|#
directive|define
name|SIMPLE_TEXT_INPUT_PROTOCOL
define|\
value|{ 0x387477c1, 0x69c7, 0x11d2, 0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b }
end_define

begin_expr_stmt
name|INTERFACE_DECL
argument_list|(
name|_SIMPLE_INPUT_INTERFACE
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/*  * Baseline unicode control chars  */
end_comment

begin_define
define|#
directive|define
name|CHAR_NULL
value|0x0000
end_define

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
comment|/*  * Scan codes for base line keys  */
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
name|struct
name|_SIMPLE_INPUT_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

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
name|struct
name|_SIMPLE_INPUT_INTERFACE
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

begin_typedef
typedef|typedef
struct|struct
name|_SIMPLE_INPUT_INTERFACE
block|{
name|EFI_INPUT_RESET
name|Reset
decl_stmt|;
name|EFI_INPUT_READ_KEY
name|ReadKeyStroke
decl_stmt|;
name|EFI_EVENT
name|WaitForKey
decl_stmt|;
block|}
name|SIMPLE_INPUT_INTERFACE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

