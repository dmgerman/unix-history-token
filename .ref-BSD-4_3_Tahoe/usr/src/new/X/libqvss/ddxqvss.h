begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
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
file|"../X/vsinput.h"
end_include

begin_include
include|#
directive|include
file|"../X/Xdev.h"
end_include

begin_include
include|#
directive|include
file|"../X/X.h"
end_include

begin_define
define|#
directive|define
name|XSIZE
value|128
end_define

begin_comment
comment|/* number of bytes/line for qvss display */
end_comment

begin_define
define|#
directive|define
name|YSIZE
value|864
end_define

begin_comment
comment|/* 864 visible lines on the screen	 */
end_comment

begin_define
define|#
directive|define
name|CURSOR_WIDTH
value|16
end_define

begin_comment
comment|/* hardware cursor width              */
end_comment

begin_define
define|#
directive|define
name|CURSOR_HEIGHT
value|16
end_define

begin_comment
comment|/* hardware cursor height             */
end_comment

begin_define
define|#
directive|define
name|ConstantPixmap
value|0x0
end_define

begin_comment
comment|/* kinds of pixmaps on qvss, constant */
end_comment

begin_define
define|#
directive|define
name|BitmapPixmap
value|0x1
end_define

begin_comment
comment|/* and ones with associated bitmaps   */
end_comment

begin_define
define|#
directive|define
name|CanBeTiled
value|1
end_define

begin_comment
comment|/* this pixmap can be tiled	      */
end_comment

begin_define
define|#
directive|define
name|CannotBeTiled
value|0
end_define

begin_comment
comment|/* this pixmap cannont be tiled	      */
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
value|(((int) (x)->kind)& 0xf)
end_define

begin_define
define|#
directive|define
name|PINVERT
parameter_list|(
name|x
parameter_list|)
value|(((int) (x)->kind)>> 4)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
name|short
name|cbits
index|[
literal|16
index|]
decl_stmt|;
comment|/* braindamaged 16x16 cursor on qvss */
name|short
name|map
decl_stmt|;
block|}
name|CursPriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CDATA
parameter_list|(
name|x
parameter_list|)
value|((CursPriv *) x->data)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_fontpriv
block|{
name|int
name|maxwidth
decl_stmt|;
comment|/* maximum width found in the font */
name|int
name|wpitch
decl_stmt|;
comment|/* number of bytes/line in strike  */
name|short
modifier|*
name|widths
decl_stmt|;
comment|/* width table (in pixels)	   */
name|short
modifier|*
name|leftarray
decl_stmt|;
comment|/* leftarray			   */
name|BITMAP
modifier|*
name|strike
decl_stmt|;
comment|/* the font stike bitmap itself	   */
name|long
modifier|*
name|chrs
decl_stmt|;
comment|/* chars in independent bitmaps	   */
name|char
modifier|*
modifier|*
name|fltable
decl_stmt|;
comment|/* beginning of each strike line   */
block|}
name|FontPriv
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

begin_define
define|#
directive|define
name|BDATA
parameter_list|(
name|x
parameter_list|)
value|((VSArea *) x->data)
end_define

begin_define
define|#
directive|define
name|PDATA
parameter_list|(
name|x
parameter_list|)
value|((BITMAP *) x->data)
end_define

end_unit

