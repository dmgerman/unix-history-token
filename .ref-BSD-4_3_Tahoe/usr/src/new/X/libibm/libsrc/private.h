begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: private.h,v 10.1 86/11/19 10:46:15 jg Exp $ */
end_comment

begin_comment
comment|/* Copyright 1985 Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* private.h - Defines and macros to access private data structures  *  *  	Changes and modifications by:  *  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"vsinput.h"
end_include

begin_include
include|#
directive|include
file|"Xdev.h"
end_include

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tbioctl.h>
end_include

begin_include
include|#
directive|include
file|<machineio/mouseio.h>
end_include

begin_include
include|#
directive|include
file|<machinecons/xio.h>
end_include

begin_define
define|#
directive|define
name|ConstantPixmap
value|0
end_define

begin_comment
comment|/* kinds of pixmaps, constant         */
end_comment

begin_define
define|#
directive|define
name|BitmapPixmap
value|1
end_define

begin_comment
comment|/*   and ones with associated bitmaps */
end_comment

begin_define
define|#
directive|define
name|CanBeTiled
value|1
end_define

begin_comment
comment|/* this pixmap can be tiled */
end_comment

begin_define
define|#
directive|define
name|CannotBeTiled
value|0
end_define

begin_comment
comment|/* this pixmap cannont be tiled */
end_comment

begin_define
define|#
directive|define
name|InvertFlag
value|0x10
end_define

begin_comment
comment|/* pixmap source should be inverted   */
end_comment

begin_define
define|#
directive|define
name|PTYPE
parameter_list|(
name|x
parameter_list|)
value|(((int) (x)->kind)& 0xF)
end_define

begin_comment
comment|/* get type */
end_comment

begin_define
define|#
directive|define
name|PINVERT
parameter_list|(
name|x
parameter_list|)
value|(((int) (x)->kind)>> 4)
end_define

begin_comment
comment|/* get invert flag */
end_comment

begin_define
define|#
directive|define
name|TILE_SIZE
value|16
end_define

begin_comment
comment|/* tile size in shorts */
end_comment

begin_define
define|#
directive|define
name|TILE_WIDTH
value|16
end_define

begin_comment
comment|/* tile width in bits */
end_comment

begin_define
define|#
directive|define
name|TILE_HEIGHT
value|16
end_define

begin_comment
comment|/* tile height in bits */
end_comment

begin_define
define|#
directive|define
name|CURSOR_SIZE
value|16
end_define

begin_comment
comment|/* cursor size in shorts */
end_comment

begin_define
define|#
directive|define
name|CURSOR_WIDTH
value|16
end_define

begin_comment
comment|/* cursor width in bits */
end_comment

begin_define
define|#
directive|define
name|CURSOR_HEIGHT
value|16
end_define

begin_comment
comment|/* cursor height in bits */
end_comment

begin_define
define|#
directive|define
name|CDATA
parameter_list|(
name|x
parameter_list|)
value|((CursPriv *) x->data)
end_define

begin_comment
comment|/* get pntr to private cursor data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
comment|/* private data struct for cursor */
name|u_short
name|data
index|[
name|CURSOR_SIZE
index|]
decl_stmt|;
comment|/* cursor image */
name|u_short
name|mask
index|[
name|CURSOR_SIZE
index|]
decl_stmt|;
comment|/* cursor mask */
struct|struct
block|{
comment|/* cursor hot spot */
name|short
name|y
decl_stmt|;
name|short
name|x
decl_stmt|;
block|}
name|hotspot
struct|;
block|}
name|CursPriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FDATA
parameter_list|(
name|x
parameter_list|)
value|((FontPriv *) x->data)
end_define

begin_comment
comment|/* get pntr to private font data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_fontpriv
block|{
comment|/* private font data */
name|int
name|maxwidth
decl_stmt|;
comment|/* maximum width found in the font */
name|short
modifier|*
name|widths
decl_stmt|;
comment|/* width table (in pixels)         */
name|short
modifier|*
name|leftarray
decl_stmt|;
comment|/* leftarray                       */
name|BITMAP
modifier|*
name|chrs
decl_stmt|;
comment|/* individual character bitmaps    */
name|BITMAP
modifier|*
name|offscr
decl_stmt|;
comment|/* the font offscreen bitmap       */
block|}
name|FontPriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BDATA
parameter_list|(
name|x
parameter_list|)
value|((u_short *) x->data)
end_define

begin_comment
comment|/* get pntr to private bitmap data */
end_comment

begin_define
define|#
directive|define
name|PDATA
parameter_list|(
name|x
parameter_list|)
value|((BITMAP *) x->data)
end_define

begin_comment
comment|/* get pntr to private pixmap data */
end_comment

begin_comment
comment|/*  * Define for the global text offscreen array of unsigned shorts.  * Each offscr BITMAP.data structure will point to this array.  * When each font is opened, it uses this buffer which is designed to  * be as wide as the widest display and 128 bits high.  * This is roughly 20K.  (For all fonts.)  * (We are assuming some day one will have a 1280x1024 screen.)  */
end_comment

begin_define
define|#
directive|define
name|MAX_OFFSCR_WD
value|1280
end_define

begin_define
define|#
directive|define
name|MAX_OFFSCR_HT
value|128
end_define

begin_define
define|#
directive|define
name|TEXT_BUFFER_SIZE
value|((MAX_OFFSCR_WD * MAX_OFFSCR_HT)>> 4)
end_define

begin_define
define|#
directive|define
name|CH_THRESHOLD
value|3
end_define

begin_comment
comment|/*  * Path list type flags  */
end_comment

begin_define
define|#
directive|define
name|DRAW_PATH_LIST
value|0
end_define

begin_define
define|#
directive|define
name|FILL_PATH_LIST
value|1
end_define

begin_comment
comment|/*  * These macors are used in place of floating point  * code to get precision to the second decimal place  * using interger math.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_LEFT_16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)< 0) ? -(-(x)<< 16) : (x)<< 16)
end_define

begin_define
define|#
directive|define
name|ROUND_16
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)< 0) ? -((-(x) + 32768)>> 16) : (((x) + 32768)>> 16))
end_define

begin_define
define|#
directive|define
name|PERCENT_16
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|,
name|d
parameter_list|)
define|\
value|(((x)< 0) ? -((-(x) / d) * n) : (((x) / d) * n))
end_define

begin_comment
comment|/*  * Macro to obtain address of the screens  * BITMAP structure  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_BITMAP
value|&pbm
end_define

begin_comment
comment|/*  * Externs and declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|BITMAP
name|pbm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BITMAP
name|txtbm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|ConstantTiles
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PIXMAP
name|constpix0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PIXMAP
name|constpix1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|FBMap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|SSMap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|BITMAP
modifier|*
name|CharBitmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|BITMAP
modifier|*
name|MakeMask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PIXMAP
modifier|*
name|MakePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|Xalloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

end_unit

