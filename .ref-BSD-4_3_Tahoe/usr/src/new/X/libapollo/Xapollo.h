begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: Xapollo.h,v 10.1 86/11/29 13:53:26 jg Rel $ */
end_comment

begin_comment
comment|/*      Copyright 1986 by the University of Utah      Permission to use, copy, modify, and distribute this     software and its documentation for any purpose and without     fee is hereby granted, provided that the above copyright     notice appear in all copies and that both that copyright     notice and this permission notice appear in supporting     documentation, and that the name of the University of Utah     not be used in advertising or publicity pertaining to      distribution of the software without specific, written      prior permission. The University of Utah makes no     representations about the suitability of this software for     any purpose.  It is provided "as is" without express or     implied warranty.      */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"/sys/ins/base.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/error.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/gpr.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/pad.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/streams.ins.c"
end_include

begin_include
include|#
directive|include
file|"/sys/ins/ms.ins.c"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<X/X.h>
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

begin_define
define|#
directive|define
name|dprintf
value|if(Xdbg) fprintf
end_define

begin_define
define|#
directive|define
name|ConstantPixmap
value|0x0
end_define

begin_comment
comment|/* kinds of pixmaps on apollo, constant */
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
name|ZColorPixmap
value|0x2
end_define

begin_comment
comment|/* and (up to) 8-bit color ones */
end_comment

begin_define
define|#
directive|define
name|XYColorPixmap
value|0x3
end_define

begin_comment
comment|/* in both styles (but they're not done yet) */
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
enum|enum
block|{
name|apollo_bitmap
block|,
name|memory_bitmap
block|}
name|BitmapType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BM_TYPE
parameter_list|(
name|bm
parameter_list|)
value|( (BitmapType)((bm)->kind) )
end_define

begin_define
define|#
directive|define
name|A_BITMAP
parameter_list|(
name|bm
parameter_list|)
value|( (int)((bm)->data ) )
end_define

begin_define
define|#
directive|define
name|M_BITMAP
parameter_list|(
name|bm
parameter_list|)
value|( (short *)((bm)->data) )
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
name|boolean
name|ap_font
decl_stmt|;
comment|/* true->Apollo format font	   */
name|int
name|ap_font_id
decl_stmt|;
comment|/* the font id returned by gpr_$load_font */
name|int
name|ap_font_id_inv
decl_stmt|;
comment|/* ditto for the inverse font      */
name|BITMAP
modifier|*
name|strike
decl_stmt|;
comment|/* the font bitmap (not for Apollo format) */
name|long
modifier|*
name|chrs
decl_stmt|;
comment|/* chars in independent bitmaps	   */
block|}
name|FontPriv
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
name|BITMAP
modifier|*
name|bits
decl_stmt|;
comment|/* the cursor image	*/
name|BITMAP
modifier|*
name|mask
decl_stmt|;
comment|/* the mask bitmap	*/
name|BITMAP
modifier|*
name|save
decl_stmt|;
comment|/* a place to save what the cursor covers */
name|int
name|fore
decl_stmt|,
name|back
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
name|GetNextClip
parameter_list|(
name|clips
parameter_list|,
name|win
parameter_list|)
define|\
value|win.x_coord = clips->left; \ 	win.y_coord = clips->top; \ 	win.x_size = clips->width; \ 	win.y_size = clips->height; \ 	clips++;
end_define

begin_define
define|#
directive|define
name|OverLap
parameter_list|(
name|win
parameter_list|,
name|x2
parameter_list|,
name|y2
parameter_list|,
name|w2
parameter_list|,
name|h2
parameter_list|)
define|\
value|((win.x_coord< x2+w2)&& (win.y_coord< y2+h2)&& \ 	 (x2< win.x_coord+win.x_size)&& (y2< win.y_coord+win.y_size))
end_define

begin_define
define|#
directive|define
name|imin
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|((i)<(j)?(i):(j))
end_define

begin_define
define|#
directive|define
name|imax
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|((i)>(j)?(i):(j))
end_define

begin_define
define|#
directive|define
name|set_zmask
parameter_list|(
name|zmask
parameter_list|)
define|\
value|{ extern long old_zmask; \         if (old_zmask != zmask) { \ 	  gpr_$set_plane_mask((gpr_$mask_t)(zmask& Screen.plane_mask), status); \ 	  old_zmask = zmask; \ 	  } \ 	}
end_define

begin_define
define|#
directive|define
name|set_op
parameter_list|(
name|op
parameter_list|)
define|\
value|{ extern int old_op; \     if (old_op != op) { \        for (i=0; i<Screen.depth; i++) \ 	  gpr_$set_raster_op( (gpr_$plane_t)i, (gpr_$raster_op_t)op, status ); \        old_op = op; \        } \      }
end_define

begin_define
define|#
directive|define
name|CheckCursor
parameter_list|(
name|basex
parameter_list|,
name|basey
parameter_list|,
name|w
parameter_list|,
name|h
parameter_list|)
define|\
value|{ extern int CursorDisplayed; \       extern DEVICE *CurrentDevice; \       extern CURSOR *CurrentCursor; \       int mousex = CurrentDevice->mouse->x; \       int mousey = CurrentDevice->mouse->y; \       if (CursorDisplayed&& \ 	  (basex< mousex+CurrentCursor->width)&& \ 	  (basey< mousey+CurrentCursor->height)&& \ 	  (mousex< basex+w)&& (mousey< basey+h)) \ 	    DisplayCursor(NULL); \     }
end_define

begin_define
define|#
directive|define
name|RestoreCursor
parameter_list|()
define|\
value|{ extern int CursorDisplayed; \       extern CURSOR *CurrentCursor; \       extern DisplayCursor(); \       if (!CursorDisplayed) \     	DisplayCursor(CurrentCursor); \     }
end_define

begin_struct
specifier|extern
struct|struct
name|Scr
block|{
name|gpr_$plane_t
name|depth
decl_stmt|;
name|gpr_$mask_t
name|plane_mask
decl_stmt|;
name|short
name|width
decl_stmt|;
comment|/*  screen width */
name|short
name|height
decl_stmt|;
comment|/*  screen height */
name|short
name|line_width
decl_stmt|;
comment|/*  halfwords between scan lines */
name|caddr_t
name|ptr
decl_stmt|;
comment|/*  memory ptr to bitmap */
name|stream_$id_t
name|fd
decl_stmt|;
comment|/*  file descriptor for screen pad */
name|gpr_$bitmap_desc_t
name|bm
decl_stmt|;
comment|/*  bitmap descriptor */
name|gpr_$attribute_desc_t
name|ab
decl_stmt|;
comment|/*  attribute descriptor */
block|}
name|Screen
struct|;
end_struct

begin_function_decl
name|BITMAP
modifier|*
name|make_bitmap
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|Xdbg
decl_stmt|;
end_decl_stmt

end_unit

