begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: uwm.h,v 10.3 86/02/01 16:24:37 tony Rel $ */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1986 by				*  *		Digital Equipment Corporation, Maynard, MA		*  *		         All Rights Reserved.				*  *									*  *	Permission to use, copy, modify, and distribute this software	*  *	and its documentation is hereby granted only to licensees of 	*  *	The Regents of the University of California pursuant to their	*  *	license agreement for the Berkeley Software Distribution 	*  *	provided that the following appears on all copies.		*  *									*  *            "LICENSED FROM DIGITAL EQUIPMENT CORPORATION		*  *                      COPYRIGHT (C) 1986				*	  *                 DIGITAL EQUIPMENT CORPORATION			*  *                         MAYNARD, MA					*  *                     ALL RIGHTS RESERVED.				*  *									*  *      THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT	*   *	NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL	*  *	EQUIPMENT CORPORATION.  DIGITAL MAKES NO REPRESENTATIONS	*  *	ABOUT SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE. IT IS	*  *	SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.		*  *									*	  * 	IF THE UNIVERSITY OF CALIFORNIA OR ITS LICENSEES MODIFY 	*	  *	THE SOFTWARE IN A MANNER CREATING DERIVATIVE COPYRIGHT 		*	  *	RIGHTS APPROPRIATE COPYRIGHT LEGENDS MAY BE PLACED ON THE	*  *	DERIVATIVE WORK IN ADDITION TO THAT SET FORTH ABOVE."		*	  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
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
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_define
define|#
directive|define
name|MIN
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
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)>= (y) ? (x) : (y))
end_define

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
name|DEF_DELTA
value|1
end_define

begin_define
define|#
directive|define
name|DEF_FONT
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
name|DEF_MENU_BORDER_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DEF_MENU_PADDING
value|4
end_define

begin_define
define|#
directive|define
name|DEF_VOLUME
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
name|TEMPFILE
value|"/tmp/uwm.XXXXXX"
end_define

begin_define
define|#
directive|define
name|SYSFILE
value|"/usr/new/lib/X/uwm/system.uwmrc"
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
value|0xfd
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
name|ROOT
value|0x1
end_define

begin_define
define|#
directive|define
name|WINDOW
value|0x2
end_define

begin_define
define|#
directive|define
name|ICON
value|0x4
end_define

begin_define
define|#
directive|define
name|FAILURE
value|0
end_define

begin_define
define|#
directive|define
name|NAME_LEN
value|256
end_define

begin_comment
comment|/* Maximum length of filenames. */
end_comment

begin_define
define|#
directive|define
name|KeyMask
parameter_list|(
name|x
parameter_list|)
value|(x& (ControlMask|MetaMask|ShiftMask|ShiftLockMask))
end_define

begin_define
define|#
directive|define
name|EVENTMASK
value|(ButtonPressed | ButtonReleased)
end_define

begin_define
define|#
directive|define
name|ButtonValue
parameter_list|(
name|x
parameter_list|)
value|(x& (LeftMask|MiddleMask|RightMask)>> 9)
end_define

begin_define
define|#
directive|define
name|DrawBox
parameter_list|()
value|XDraw(RootWindow,box,num_vectors,DRAW_HEIGHT,DRAW_WIDTH,DRAW_VALUE,DRAW_FUNC,AllPlanes)
end_define

begin_define
define|#
directive|define
name|DrawZap
parameter_list|()
value|XDraw(RootWindow,zap,num_vectors,DRAW_HEIGHT,DRAW_WIDTH,DRAW_VALUE,DRAW_FUNC,AllPlanes)
end_define

begin_comment
comment|/*  * Keyword table entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_keyword
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
name|Bool
modifier|*
name|bptr
decl_stmt|;
name|int
modifier|*
name|nptr
decl_stmt|;
name|char
modifier|*
name|sptr
decl_stmt|;
name|Bool
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|()
function_decl|;
block|}
name|Keyword
typedef|;
end_typedef

begin_comment
comment|/*  * Keyword table type entry.  */
end_comment

begin_define
define|#
directive|define
name|IsString
value|1
end_define

begin_define
define|#
directive|define
name|IsBoolTrue
value|2
end_define

begin_define
define|#
directive|define
name|IsBoolFalse
value|3
end_define

begin_define
define|#
directive|define
name|IsFunction
value|4
end_define

begin_define
define|#
directive|define
name|IsMenuMap
value|5
end_define

begin_define
define|#
directive|define
name|IsMenu
value|6
end_define

begin_define
define|#
directive|define
name|IsDownFunction
value|7
end_define

begin_define
define|#
directive|define
name|IsParser
value|8
end_define

begin_define
define|#
directive|define
name|IsNumeric
value|9
end_define

begin_define
define|#
directive|define
name|IsQuitFunction
value|10
end_define

begin_comment
comment|/*  * Button/key binding type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_binding
block|{
name|struct
name|_binding
modifier|*
name|next
decl_stmt|;
name|int
name|context
decl_stmt|;
name|short
name|mask
decl_stmt|;
name|short
name|button
decl_stmt|;
name|Bool
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
name|char
modifier|*
name|menuname
decl_stmt|;
name|struct
name|_menuinfo
modifier|*
name|menu
decl_stmt|;
block|}
name|Binding
typedef|;
end_typedef

begin_comment
comment|/*  * Key expression type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_keyexpr
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|short
name|mask
decl_stmt|;
block|}
name|KeyExpr
typedef|;
end_typedef

begin_comment
comment|/*  * Context expression type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_contexpr
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|mask
decl_stmt|;
block|}
name|ContExpr
typedef|;
end_typedef

begin_comment
comment|/*  * Button modifier type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_buttonmodifier
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|short
name|mask
decl_stmt|;
block|}
name|ButtonModifier
typedef|;
end_typedef

begin_comment
comment|/*  * Button modifier mask definitions.  * Note: The upper byte definitions are found in<X/X.h>.  */
end_comment

begin_define
define|#
directive|define
name|DoubleClick
value|0x1
end_define

begin_define
define|#
directive|define
name|DeltaMotion
value|0x2
end_define

begin_define
define|#
directive|define
name|ButtonUp
value|0x4
end_define

begin_define
define|#
directive|define
name|ButtonDown
value|0x8
end_define

begin_define
define|#
directive|define
name|ButtonMods
value|0xf
end_define

begin_comment
comment|/*  * MenuInfo data type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_menuinfo
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this menu. */
name|Window
name|w
decl_stmt|;
comment|/* Menu window. */
name|int
name|iheight
decl_stmt|;
comment|/* Height of an item. */
name|int
name|width
decl_stmt|;
comment|/* Width of this menu. */
name|int
name|height
decl_stmt|;
comment|/* Height of this menu. */
name|Pixmap
name|image
decl_stmt|;
comment|/* Saved image of the menu. */
name|char
modifier|*
name|foreground
decl_stmt|;
comment|/* Name of foreground color. */
name|char
modifier|*
name|background
decl_stmt|;
comment|/* Name of background color. */
name|char
modifier|*
name|fghighlight
decl_stmt|;
comment|/* Name of hightlight foreground color. */
name|char
modifier|*
name|bghighlight
decl_stmt|;
comment|/* Name of highlight background color. */
name|Color
name|fg
decl_stmt|;
comment|/* Foreground color definition. */
name|Color
name|bg
decl_stmt|;
comment|/* Background color definition. */
name|Color
name|hlfg
decl_stmt|;
comment|/* Foreground highlight color definition. */
name|Color
name|hlbg
decl_stmt|;
comment|/* Background highlight color definition. */
name|struct
name|_menuline
modifier|*
name|line
decl_stmt|;
comment|/* Linked list of menu items. */
block|}
name|MenuInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Menu Line data type.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_menuline
block|{
name|struct
name|_menuline
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next line. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this line. */
name|int
name|type
decl_stmt|;
comment|/* IsShellCommand, IsText, IsTextNL... */
name|Window
name|w
decl_stmt|;
comment|/* Subwindow for this line. */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* Text string to be acted upon. */
name|Bool
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
comment|/* Window manager function to be invoked. */
name|struct
name|_menuinfo
modifier|*
name|menu
decl_stmt|;
comment|/* Menu to be invoked. */
name|char
modifier|*
name|foreground
decl_stmt|;
comment|/* Name of foreground color. */
name|char
modifier|*
name|background
decl_stmt|;
comment|/* Name of background color. */
name|Color
name|fg
decl_stmt|;
comment|/* Foreground color definition. */
name|Color
name|bg
decl_stmt|;
comment|/* Background color definition. */
block|}
name|MenuLine
typedef|;
end_typedef

begin_comment
comment|/*  * MenuLine->type definitions.  */
end_comment

begin_define
define|#
directive|define
name|IsShellCommand
value|1
end_define

begin_define
define|#
directive|define
name|IsText
value|2
end_define

begin_define
define|#
directive|define
name|IsTextNL
value|3
end_define

begin_define
define|#
directive|define
name|IsUwmFunction
value|4
end_define

begin_define
define|#
directive|define
name|IsMenuFunction
value|5
end_define

begin_define
define|#
directive|define
name|IsImmFunction
value|6
end_define

begin_comment
comment|/* Immediate (context-less) function. */
end_comment

begin_comment
comment|/*  * Menu Link data type.  Used by the parser when creating a linked list  * of menus.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_menulink
block|{
name|struct
name|_menulink
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to next MenuLink. */
name|struct
name|_menuinfo
modifier|*
name|menu
decl_stmt|;
comment|/* Pointer to the menu in this link. */
block|}
name|MenuLink
typedef|;
end_typedef

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
comment|/* Pop-up dimension display window. */
end_comment

begin_decl_stmt
specifier|extern
name|Window
name|Frozen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains window id of "gridded" window. */
end_comment

begin_decl_stmt
specifier|extern
name|Font
name|IFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon text font. */
end_comment

begin_decl_stmt
specifier|extern
name|Font
name|PFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up text font. */
end_comment

begin_decl_stmt
specifier|extern
name|Font
name|MFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu text font. */
end_comment

begin_decl_stmt
specifier|extern
name|FontInfo
name|IFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon text font information. */
end_comment

begin_decl_stmt
specifier|extern
name|FontInfo
name|PFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up text font information. */
end_comment

begin_decl_stmt
specifier|extern
name|FontInfo
name|MFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu text font information. */
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
name|Pixmap
name|MBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu Window border pixmap. */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|MBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu Window background pixmap. */
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
name|Cursor
name|MenuCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|MenuMaskCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu mask cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|LeftButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Left button main cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|MiddleButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Middle button main cursor. */
end_comment

begin_decl_stmt
specifier|extern
name|Cursor
name|RightButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Right button main cursor. */
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
name|MTextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window text forground color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MTextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window text background color. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window border width. */
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
name|Delay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delay between clicks of double click. */
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
name|int
name|HIconPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon horizontal padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|VIconPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon vertical padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|HMenuPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu horizontal padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|VMenuPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu vertical padding. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MaxColors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of colors to use. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Pushval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pixels to push window by. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Volume
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Audible alarm volume. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routine return status. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Maxfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum file descriptors for select(2). */
end_comment

begin_decl_stmt
specifier|extern
name|MenuLink
modifier|*
name|Menus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Linked list of menus. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Autoselect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warp mouse to default menu selection? */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Freeze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Freeze server during move/resize? */
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
name|NWindow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Normalize windows? */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|NIcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Normalize icons? */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Push
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relative=TRUE, Absolute=FALSE. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Reverse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reverse video? */
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

begin_decl_stmt
specifier|extern
name|int
name|Lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line count for parser. */
end_comment

begin_decl_stmt
specifier|extern
name|Bool
name|Startup_File_Error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Startup file error flag. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Startup_File
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Startup file name. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|IFontName
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon font name. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PFontName
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up font name. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MFontName
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu font name. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|Argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to command line parameters. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|Environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to environment. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DefaultBindings
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default bindings string array. */
end_comment

begin_decl_stmt
specifier|extern
name|Keyword
name|KeywordTable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keyword lookup table. */
end_comment

begin_decl_stmt
specifier|extern
name|Binding
modifier|*
name|Blist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Button/key bindings list. */
end_comment

begin_decl_stmt
specifier|extern
name|KeyExpr
name|KeyExprTbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key expression table. */
end_comment

begin_decl_stmt
specifier|extern
name|ContExpr
name|ContExprTbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Context expression table. */
end_comment

begin_decl_stmt
specifier|extern
name|ButtonModifier
name|ButtModTbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Button modifier table. */
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
name|Beep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|CircleDown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|CircleUp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Continue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Focus
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
name|Bool
name|Iconify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Lower
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Menu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|MoveOpaque
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|NewIconify
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Pause
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|PushDown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|PushLeft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|PushRight
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|PushUp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Raise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Refresh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|ResetBindings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|ResetMenus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|ResetVariables
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Resize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|Restart
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

begin_function_decl
specifier|extern
name|int
name|CreateMenus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|stash
parameter_list|()
function_decl|;
end_function_decl

end_unit

