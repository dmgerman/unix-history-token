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
comment|/*  * globals.c - X Window System window manager global data.  *  *	Modified:	ADF	29-May-85	Converted to X version 8.0  */
end_comment

begin_comment
comment|/* $Header: globals.c,v 10.3 86/02/01 16:10:30 tony Rel $ */
end_comment

begin_include
include|#
directive|include
file|"xwm.h"
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
name|Font
name|IFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon output font. */
end_comment

begin_decl_stmt
name|FontInfo
name|IFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon output font information. */
end_comment

begin_decl_stmt
name|Font
name|PFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up output font. */
end_comment

begin_decl_stmt
name|FontInfo
name|PFontInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop up output font information. */
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
name|Cursor
name|ArrowCrossCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Arrow cross cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|ULAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Upper left angle cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|LLAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lower left angle cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|LRAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lower right angle cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|URAngleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Upper right angle cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|TopTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top tee cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|LeftTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Left tee cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|BottomTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bottom tee cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|RightTeeCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Right tee cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|DotCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dot cursor. */
end_comment

begin_decl_stmt
name|Cursor
name|CircleCursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Circle Cursor. */
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
name|IPadding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon window padding. */
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
name|ButtonMask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global mouse button event mask. */
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
name|Bool
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global debug flag. */
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

end_unit

