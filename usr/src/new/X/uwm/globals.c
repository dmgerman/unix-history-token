begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_globals_c
init|=
literal|"$Header: globals.c,v 10.4 86/11/19 16:25:04 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  *			COPYRIGHT 1985, 1986  *		   DIGITAL EQUIPMENT CORPORATION  *		       MAYNARD, MASSACHUSETTS  *			ALL RIGHTS RESERVED.  *  * THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND  * SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL EQUIPMENT CORPORATION.  * DIGITAL MAKES NO REPRESENTATIONS ABOUT THE SUITIBILITY OF THIS SOFTWARE FOR  * ANY PURPOSE.  IT IS SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.  *  * IF THE SOFTWARE IS MODIFIED IN A MANNER CREATING DERIVATIVE COPYRIGHT RIGHTS,  * APPROPRIATE LEGENDS MAY BE PLACED ON THE DERIVATIVE WORK IN ADDITION TO THAT  * SET FORTH ABOVE.  *  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting documentation,  * and that the name of Digital Equipment Corporation not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission.  *  */
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)globals.c	3.8	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * globals.c - window manager global data  *  */
end_comment

begin_include
include|#
directive|include
file|"uwm.h"
end_include

begin_decl_stmt
name|Window
name|Pop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up dimension display window. */
end_comment

begin_decl_stmt
name|Window
name|Frozen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains window id of "gridded" window. */
end_comment

begin_decl_stmt
name|Font
name|IFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon text font. */
end_comment

begin_decl_stmt
name|Font
name|PFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up text font. */
end_comment

begin_decl_stmt
name|Font
name|MFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu text font. */
end_comment

begin_decl_stmt
name|FontInfo
name|IFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon text font information. */
end_comment

begin_decl_stmt
name|FontInfo
name|PFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up text font information. */
end_comment

begin_decl_stmt
name|FontInfo
name|MFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu text font information. */
end_comment

begin_decl_stmt
name|Pixmap
name|GrayPixmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gray pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|IBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window border pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|IBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window background pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|PBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-Up Window border pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|PBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up Window background pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|MBorder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu Window border pixmap. */
end_comment

begin_decl_stmt
name|Pixmap
name|MBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu Window background pixmap. */
end_comment

begin_decl_stmt
name|Cursor
name|ArrowCrossCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Arrow cross cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|TextCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text cursor used in icon windows. */
end_comment

begin_decl_stmt
name|Cursor
name|IconCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon Cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|MenuCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|MenuMaskCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu mask cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|LeftButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Left button main cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|MiddleButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Middle button main cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|RightButtonCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Right button main cursor. */
end_comment

begin_decl_stmt
name|int
name|ScreenWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display screen width. */
end_comment

begin_decl_stmt
name|int
name|ScreenHeight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display screen height. */
end_comment

begin_decl_stmt
name|int
name|CursorFunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mouse cursor function. */
end_comment

begin_decl_stmt
name|int
name|IconCursorFunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon Mouse Cursor function. */
end_comment

begin_decl_stmt
name|int
name|ITextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window text forground color. */
end_comment

begin_decl_stmt
name|int
name|ITextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window text background color. */
end_comment

begin_decl_stmt
name|int
name|IBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window border width. */
end_comment

begin_decl_stmt
name|int
name|PTextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window text forground color. */
end_comment

begin_decl_stmt
name|int
name|PTextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window text background color. */
end_comment

begin_decl_stmt
name|int
name|MTextForground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window text forground color. */
end_comment

begin_decl_stmt
name|int
name|MTextBackground
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window text background color. */
end_comment

begin_decl_stmt
name|int
name|PWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window width. */
end_comment

begin_decl_stmt
name|int
name|PHeight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window height. */
end_comment

begin_decl_stmt
name|int
name|PBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window border width. */
end_comment

begin_decl_stmt
name|int
name|PPadding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window padding. */
end_comment

begin_decl_stmt
name|int
name|MBorderWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window border width. */
end_comment

begin_decl_stmt
name|int
name|MPadding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu window padding. */
end_comment

begin_decl_stmt
name|int
name|ButtonMask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global mouse button event mask. */
end_comment

begin_decl_stmt
name|int
name|Delay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delay between clicks of a double click. */
end_comment

begin_decl_stmt
name|int
name|Delta
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mouse movement slop. */
end_comment

begin_decl_stmt
name|int
name|HIconPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon horizontal padding. */
end_comment

begin_decl_stmt
name|int
name|VIconPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon vertical padding. */
end_comment

begin_decl_stmt
name|int
name|HMenuPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu horizontal padding. */
end_comment

begin_decl_stmt
name|int
name|VMenuPad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu vertical padding. */
end_comment

begin_decl_stmt
name|int
name|MaxColors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of colors to use. */
end_comment

begin_decl_stmt
name|int
name|Pushval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of pixels to push window by. */
end_comment

begin_decl_stmt
name|int
name|Volume
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Audible alarm volume. */
end_comment

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routine return status. */
end_comment

begin_decl_stmt
name|int
name|Maxfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum file descriptors for select(2). */
end_comment

begin_decl_stmt
name|MenuLink
modifier|*
name|Menus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Linked list of menus. */
end_comment

begin_decl_stmt
name|Binding
modifier|*
name|Blist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Button/key binding list. */
end_comment

begin_decl_stmt
name|Bool
name|Autoselect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warp mouse to default menu selection? */
end_comment

begin_decl_stmt
name|Bool
name|Freeze
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Freeze server during move/resize? */
end_comment

begin_decl_stmt
name|Bool
name|Grid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should the m/r box contain a 9 seg. grid. */
end_comment

begin_decl_stmt
name|Bool
name|NWindow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Normalize windows? */
end_comment

begin_decl_stmt
name|Bool
name|NIcon
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Normalize icons? */
end_comment

begin_decl_stmt
name|Bool
name|Push
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relative=TRUE, Absolute=FALSE. */
end_comment

begin_decl_stmt
name|Bool
name|Reverse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reverse video? */
end_comment

begin_decl_stmt
name|Bool
name|Zap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should the the zap effect be used. */
end_comment

begin_decl_stmt
name|char
name|PText
index|[
literal|7
index|]
init|=
name|INIT_PTEXT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window dummy text. */
end_comment

begin_decl_stmt
name|int
name|PTextSize
init|=
sizeof|sizeof
argument_list|(
name|PText
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up window dummy text size. */
end_comment

begin_decl_stmt
name|int
name|Lineno
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line count for parser. */
end_comment

begin_decl_stmt
name|Bool
name|Startup_File_Error
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Startup file error flag. */
end_comment

begin_decl_stmt
name|char
name|Startup_File
index|[
name|NAME_LEN
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Startup file name. */
end_comment

begin_decl_stmt
name|char
name|IFontName
index|[
name|NAME_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon font name. */
end_comment

begin_decl_stmt
name|char
name|PFontName
index|[
name|NAME_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop-up font name. */
end_comment

begin_decl_stmt
name|char
name|MFontName
index|[
name|NAME_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Menu font name. */
end_comment

begin_decl_stmt
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
name|char
modifier|*
modifier|*
name|Environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to environment. */
end_comment

begin_comment
comment|/*  * Keyword lookup table for parser.  */
end_comment

begin_decl_stmt
name|Keyword
name|KeywordTable
index|[]
init|=
block|{
block|{
literal|"autoselect"
block|,
name|IsBoolTrue
block|,
operator|&
name|Autoselect
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"delay"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|Delay
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"delta"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|Delta
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"freeze"
block|,
name|IsBoolTrue
block|,
operator|&
name|Freeze
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"iconfont"
block|,
name|IsString
block|,
literal|0
block|,
literal|0
block|,
name|IFontName
block|,
literal|0
block|}
block|,
block|{
literal|"f.beep"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Beep
block|}
block|,
block|{
literal|"f.circledown"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|CircleDown
block|}
block|,
block|{
literal|"f.circleup"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|CircleUp
block|}
block|,
block|{
literal|"f.continue"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Continue
block|}
block|,
block|{
literal|"f.focus"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Focus
block|}
block|,
block|{
literal|"f.iconify"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Iconify
block|}
block|,
block|{
literal|"f.lower"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Lower
block|}
block|,
block|{
literal|"f.menu"
block|,
name|IsMenuMap
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Menu
block|}
block|,
block|{
literal|"f.move"
block|,
name|IsDownFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Move
block|}
block|,
block|{
literal|"f.moveopaque"
block|,
name|IsDownFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|MoveOpaque
block|}
block|,
block|{
literal|"f.newiconify"
block|,
name|IsDownFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|NewIconify
block|}
block|,
block|{
literal|"f.pause"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Pause
block|}
block|,
block|{
literal|"f.pushdown"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|PushDown
block|}
block|,
block|{
literal|"f.pushleft"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|PushLeft
block|}
block|,
block|{
literal|"f.pushright"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|PushRight
block|}
block|,
block|{
literal|"f.pushup"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|PushUp
block|}
block|,
block|{
literal|"f.raise"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Raise
block|}
block|,
block|{
literal|"f.refresh"
block|,
name|IsFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Refresh
block|}
block|,
block|{
literal|"f.resize"
block|,
name|IsDownFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Resize
block|}
block|,
block|{
literal|"f.restart"
block|,
name|IsQuitFunction
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Restart
block|}
block|,
block|{
literal|"grid"
block|,
name|IsBoolTrue
block|,
operator|&
name|Grid
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"hiconpad"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|HIconPad
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"hmenupad"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|HMenuPad
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"maxcolors"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|MaxColors
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"menu"
block|,
name|IsMenu
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"menufont"
block|,
name|IsString
block|,
literal|0
block|,
literal|0
block|,
name|MFontName
block|,
literal|0
block|}
block|,
block|{
literal|"noautoselect"
block|,
name|IsBoolFalse
block|,
operator|&
name|Autoselect
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"nofreeze"
block|,
name|IsBoolFalse
block|,
operator|&
name|Freeze
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"nogrid"
block|,
name|IsBoolFalse
block|,
operator|&
name|Grid
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"nonormali"
block|,
name|IsBoolFalse
block|,
operator|&
name|NIcon
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"nonormalw"
block|,
name|IsBoolFalse
block|,
operator|&
name|NWindow
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"noreverse"
block|,
name|IsBoolFalse
block|,
operator|&
name|Reverse
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"normali"
block|,
name|IsBoolTrue
block|,
operator|&
name|NIcon
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"normalw"
block|,
name|IsBoolTrue
block|,
operator|&
name|NWindow
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"nozap"
block|,
name|IsBoolFalse
block|,
operator|&
name|Zap
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"push"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|Pushval
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"pushabsolute"
block|,
name|IsBoolFalse
block|,
operator|&
name|Push
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"pushrelative"
block|,
name|IsBoolTrue
block|,
operator|&
name|Push
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"resetbindings"
block|,
name|IsParser
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ResetBindings
block|}
block|,
block|{
literal|"resetmenus"
block|,
name|IsParser
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ResetMenus
block|}
block|,
block|{
literal|"resetvariables"
block|,
name|IsParser
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ResetVariables
block|}
block|,
block|{
literal|"resizefont"
block|,
name|IsString
block|,
literal|0
block|,
literal|0
block|,
name|PFontName
block|,
literal|0
block|}
block|,
block|{
literal|"reverse"
block|,
name|IsBoolTrue
block|,
operator|&
name|Reverse
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"viconpad"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|VIconPad
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"vmenupad"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|VMenuPad
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"volume"
block|,
name|IsNumeric
block|,
literal|0
block|,
operator|&
name|Volume
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"zap"
block|,
name|IsBoolTrue
block|,
operator|&
name|Zap
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Key expression table for parser.  */
end_comment

begin_decl_stmt
name|KeyExpr
name|KeyExprTbl
index|[]
init|=
block|{
block|{
literal|"ctrl"
block|,
name|ControlMask
block|}
block|,
block|{
literal|"c"
block|,
name|ControlMask
block|}
block|,
block|{
literal|"lock"
block|,
name|ShiftLockMask
block|}
block|,
block|{
literal|"l"
block|,
name|ShiftLockMask
block|}
block|,
block|{
literal|"meta"
block|,
name|MetaMask
block|}
block|,
block|{
literal|"m"
block|,
name|MetaMask
block|}
block|,
block|{
literal|"shift"
block|,
name|ShiftMask
block|}
block|,
block|{
literal|"s"
block|,
name|ShiftMask
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Context expression table for parser.  */
end_comment

begin_decl_stmt
name|ContExpr
name|ContExprTbl
index|[]
init|=
block|{
block|{
literal|"icon"
block|,
name|ICON
block|}
block|,
block|{
literal|"i"
block|,
name|ICON
block|}
block|,
block|{
literal|"root"
block|,
name|ROOT
block|}
block|,
block|{
literal|"r"
block|,
name|ROOT
block|}
block|,
block|{
literal|"window"
block|,
name|WINDOW
block|}
block|,
block|{
literal|"w"
block|,
name|WINDOW
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Button expression table for parser.  */
end_comment

begin_decl_stmt
name|ButtonModifier
name|ButtModTbl
index|[]
init|=
block|{
block|{
literal|"left"
block|,
name|LeftMask
block|}
block|,
block|{
literal|"leftbutton"
block|,
name|LeftMask
block|}
block|,
block|{
literal|"l"
block|,
name|LeftMask
block|}
block|,
block|{
literal|"middle"
block|,
name|MiddleMask
block|}
block|,
block|{
literal|"middlebutton"
block|,
name|MiddleMask
block|}
block|,
block|{
literal|"m"
block|,
name|MiddleMask
block|}
block|,
block|{
literal|"right"
block|,
name|RightMask
block|}
block|,
block|{
literal|"rightbutton"
block|,
name|RightMask
block|}
block|,
block|{
literal|"r"
block|,
name|RightMask
block|}
block|,
comment|/*      * The following are for double-clicking the mouse.  It's a future!      */
comment|/***     { "double", DoubleClick },     { "doubleclick", DoubleClick },     { "dclick", DoubleClick },     ***/
block|{
literal|"move"
block|,
name|DeltaMotion
block|}
block|,
block|{
literal|"motion"
block|,
name|DeltaMotion
block|}
block|,
block|{
literal|"delta"
block|,
name|DeltaMotion
block|}
block|,
block|{
literal|"down"
block|,
name|ButtonDown
block|}
block|,
block|{
literal|"d"
block|,
name|ButtonDown
block|}
block|,
block|{
literal|"up"
block|,
name|ButtonUp
block|}
block|,
block|{
literal|"u"
block|,
name|ButtonUp
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

