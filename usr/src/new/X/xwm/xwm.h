begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * xwm - X Window System window manager header file.  *  *	File:		xwm.h  */
end_comment

begin_comment
comment|/* $Header: xwm.h,v 10.3 86/02/01 16:10:49 tony Rel $ */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_typedef
typedef|typedef
enum|enum
name|_bool
block|{
name|FALSE
block|,
name|TRUE
block|}
name|Bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<= (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)>= (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|DEF_BUTTON_MASK
value|MetaMask
end_define

begin_define
define|#
directive|define
name|DEF_KEY_MASK
value|MetaMask
end_define

begin_define
define|#
directive|define
name|DEF_DELTA
value|5
end_define

begin_define
define|#
directive|define
name|DEF_I_FONT
value|"6x10"
end_define

begin_define
define|#
directive|define
name|DEF_P_FONT
value|"6x10"
end_define

begin_define
define|#
directive|define
name|DEF_FUNC
value|GXcopy
end_define

begin_define
define|#
directive|define
name|DEF_ICON_BORDER_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DEF_ICON_PADDING
value|4
end_define

begin_define
define|#
directive|define
name|DEF_POP_BORDER_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DEF_POP_PADDING
value|4
end_define

begin_define
define|#
directive|define
name|INIT_PTEXT
value|{'0', '0', '0', 'x', '0', '0', '0'}
end_define

begin_define
define|#
directive|define
name|CURSOR_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|CURSOR_HEIGHT
value|16
end_define

begin_define
define|#
directive|define
name|MAX_ZAP_VECTORS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_BOX_VECTORS
value|26
end_define

begin_define
define|#
directive|define
name|DRAW_HEIGHT
value|1
end_define

begin_define
define|#
directive|define
name|DRAW_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DRAW_VALUE
value|~0
end_define

begin_define
define|#
directive|define
name|DRAW_FUNC
value|GXxor
end_define

begin_define
define|#
directive|define
name|DRAW_PLANES
value|1
end_define

begin_define
define|#
directive|define
name|FAILURE
value|0
end_define

begin_comment
comment|/*  * External variable definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Window
name|Pop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up dimension display window. */
end_comment

begin_decl_stmt
specifier|extern
name|Font
name|IFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon output font. */
end_comment

begin_decl_stmt
specifier|extern
name|FontInfo
name|IFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon output font information. */
end_comment

begin_decl_stmt
specifier|extern
name|Font
name|PFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up output font. */
end_comment

begin_decl_stmt
specifier|extern
name|FontInfo
name|PFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up output font information. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|GrayPixmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gray pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|IBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window border pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|IBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window background pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|PBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-Up Window border pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|PBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up Window background pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|ArrowCrossCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Arrow cross cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|ULAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Upper left angle cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|LLAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lower left angle cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|LRAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lower right angle cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|URAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Upper right angle cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|TopTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top tee cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|LeftTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Left tee cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|BottomTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bottom tee cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|RightTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Right tee cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|DotCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dot cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|CircleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Circle Cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|TextCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text cursor used in icon windows. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|IconCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon Cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ScreenWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display screen width. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ScreenHeight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display screen height. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|CursorFunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mouse cursor function. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|IconCursorFunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon Mouse Cursor function. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ITextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window text forground color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ITextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window text background color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|IBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window border width. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|IPadding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PTextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window text forground color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PTextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window text background color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window width (including borders). */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PHeight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window height (including borders). */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window border width. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PPadding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ButtonMask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global mouse button event mask. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Delta
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mouse movement slop. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global debug flag. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Grid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should the m/r box contain a 9 seg. grid. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Zap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should the the zap effect be used. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PText
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window dummy text. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PTextSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window dummy text size. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROFIL
end_ifdef

begin_function_decl
name|int
name|ptrap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * External routine typing.  */
end_comment

begin_function_decl
specifier|extern
name|Bool
name|Change
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|GetButton
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LowerIconify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|StoreCursors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|StoreBox
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|StoreGridBox
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|StoreZap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XError
parameter_list|()
function_decl|;
end_function_decl

end_unit

