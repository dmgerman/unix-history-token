begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/libis/RCS/Xis.h,v $  *	$Header: Xis.h,v 1.1 86/11/17 14:34:54 swick Rel $  */
end_comment

begin_include
include|#
directive|include
file|"is-copyright.h"
end_include

begin_comment
comment|/*  *	Xis.h  *  *      Copyright (c) 1986, Integrated Solutions, Inc.  */
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
file|<vt/vt_hdrs.h>
end_include

begin_include
include|#
directive|include
file|<vt/vt_output.h>
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
name|NOGIPSTRUCTS
end_define

begin_include
include|#
directive|include
file|<gip.h>
end_include

begin_comment
comment|/*  *	misc useful stuff  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_typedef
typedef|typedef
name|short
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|TRUE
value|(!FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TILE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|TILE_HEIGHT
value|16
end_define

begin_define
define|#
directive|define
name|CanBeTiled
value|1
end_define

begin_comment
comment|/* this pixmap can be tiled		*/
end_comment

begin_define
define|#
directive|define
name|CannotBeTiled
value|0
end_define

begin_comment
comment|/* this pixmap cannont be tiled		*/
end_comment

begin_comment
comment|/*  *	FontPriv  */
end_comment

begin_define
define|#
directive|define
name|FONTPIXMAPS
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_fontpriv
block|{
name|BITMAP
modifier|*
name|mask
decl_stmt|;
name|short
modifier|*
name|xpos
decl_stmt|;
name|short
modifier|*
name|widths
decl_stmt|;
struct|struct
name|_font_pixmaps
block|{
name|int
name|fore
decl_stmt|,
name|back
decl_stmt|;
name|PIXMAP
modifier|*
name|p
decl_stmt|;
block|}
name|font_pixmaps
index|[
name|FONTPIXMAPS
index|]
struct|;
name|int
name|next_pixmap
decl_stmt|;
block|}
name|FontPriv
typedef|;
end_typedef

begin_comment
comment|/*  *	CursPriv  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
name|PIXMAP
modifier|*
name|image
decl_stmt|;
name|BITMAP
modifier|*
name|mask
decl_stmt|;
name|PIXMAP
modifier|*
name|save
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|fore
decl_stmt|,
name|back
decl_stmt|;
block|}
name|CursPriv
typedef|;
end_typedef

begin_comment
comment|/*  *	Macros to extract "private" data from system structs  */
end_comment

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
name|PDATA
parameter_list|(
name|x
parameter_list|)
value|((BITMAP *) x->data)
end_define

begin_define
define|#
directive|define
name|CDATA
parameter_list|(
name|x
parameter_list|)
value|((CursPriv *) x->data)
end_define

begin_function_decl
specifier|extern
name|CLIP
name|Intersection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|Xalloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|BITMAP
name|ScreenBitmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PIXMAP
name|ScreenPixmap
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|D_None
value|(0L)
end_define

begin_define
define|#
directive|define
name|D_All
value|(~0L)
end_define

begin_define
define|#
directive|define
name|D_Misc
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|D_Bitmaps
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|D_Color
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|D_CopyArea
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|D_Cursor
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|D_DrawCurve
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|D_Font
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|D_FontPixmap
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|D_PixFill
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|D_PixFill_data
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|D_Pixmaps
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|D_Text
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|D_TileFill
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|D_TileFill_data
value|(1<< 13)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

