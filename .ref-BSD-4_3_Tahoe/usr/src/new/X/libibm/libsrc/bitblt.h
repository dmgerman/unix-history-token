begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bitblt.h,v 10.1 86/11/19 10:45:27 jg Exp $ */
end_comment

begin_comment
comment|/* bitblt.h - typedefs, macros, and constants required to  *	      interface to bitblt()  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|"../bitblt/bitblt_ext.h"
end_include

begin_comment
comment|/*  * Line structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|StartX
decl_stmt|;
name|short
name|StartY
decl_stmt|;
name|short
name|StopX
decl_stmt|;
name|short
name|StopY
decl_stmt|;
name|short
name|BrushX
decl_stmt|;
name|short
name|BrushY
decl_stmt|;
name|u_short
name|Pattern
decl_stmt|;
name|short
name|PatternLength
decl_stmt|;
name|short
name|PatternMultiplier
decl_stmt|;
name|short
name|DrawMode
decl_stmt|;
name|Blt_Tile
modifier|*
name|AlternateTile
decl_stmt|;
name|Blt
name|blt
decl_stmt|;
block|}
name|Blt_Line
typedef|;
end_typedef

begin_comment
comment|/*  * Macros to determine if the given rule refers to a tile  * or a source bitmap.  */
end_comment

begin_define
define|#
directive|define
name|IS_RULE_SRC
parameter_list|(
name|rule
parameter_list|)
value|((rule)<= GXset)
end_define

begin_define
define|#
directive|define
name|IS_RULE_TILE
parameter_list|(
name|rule
parameter_list|)
value|(!IS_RULE_SRC(rule))
end_define

begin_comment
comment|/*  * macros to convert combination rules  *  * NOTE: These Macros depend on the order of the rules above.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_TILE_RULE
parameter_list|(
name|src_rule
parameter_list|)
value|((src_rule) + GXset + 1)
end_define

begin_define
define|#
directive|define
name|MAKE_SRC_RULE
parameter_list|(
name|tile_rule
parameter_list|)
value|((tile_rule) - GXset - 1)
end_define

begin_comment
comment|/*  * Macros for fast min/max.  */
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_comment
comment|/*  * misc constants  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/*  * macros used to fill in blt structure for bitblt()  */
end_comment

begin_define
define|#
directive|define
name|BitimageToBitmap
parameter_list|(
name|bitimage
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|,
name|bitmap
parameter_list|)
define|\
value|{							   \ 		(bitmap)->base = bitimage;			   \ 		(bitmap)->rect.origin_y = y;			   \ 		(bitmap)->rect.origin_x = x;	  		   \ 		(bitmap)->rect.corner_y = y + height; 		   \ 		(bitmap)->rect.corner_x = x + width;		   \ 		(bitmap)->nshorts = ((width) + 15) / 16;	   \ 	}
end_define

begin_define
define|#
directive|define
name|ClipToRect
parameter_list|(
name|clip
parameter_list|,
name|rect
parameter_list|)
define|\
value|{							 \ 		(rect)->origin_y = (clip)->top;			 \ 		(rect)->origin_x = (clip)->left;		 \ 		(rect)->corner_y = (clip)->top + (clip)->height; \ 		(rect)->corner_x = (clip)->left + (clip)->width; \ 	}
end_define

begin_define
define|#
directive|define
name|FillInRect
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|,
name|rect
parameter_list|)
define|\
value|{					   \                 (rect)->origin_y = y;              \                 (rect)->origin_x = x;              \                 (rect)->corner_y = (y) + (height); \                 (rect)->corner_x = (x) + (width);  \ 	}
end_define

begin_comment
comment|/*  * test if rectangle one lies within the bounds of rectangle two  */
end_comment

begin_define
define|#
directive|define
name|InsideBounds
parameter_list|(
name|rect1
parameter_list|,
name|rect2
parameter_list|)
define|\
value|(((rect1)->origin_x>= (rect2)->origin_x&&	\ 	  (rect1)->origin_x<= (rect2)->corner_x&& 	\ 	  (rect1)->origin_y>= (rect2)->origin_y&&	\ 	  (rect1)->origin_y<= (rect2)->corner_y)&&	\ 	((rect1)->corner_x>= (rect2)->origin_x&&	\ 	  (rect1)->corner_x<= (rect2)->corner_x&& 	\ 	  (rect1)->corner_y>= (rect2)->origin_y&&	\ 	  (rect1)->corner_y<= (rect2)->corner_y))
end_define

begin_comment
comment|/*  * NILS  */
end_comment

begin_define
define|#
directive|define
name|NILRECT
value|((Blt_Rectangle *) 0)
end_define

begin_define
define|#
directive|define
name|NILCLIP
value|((CLIP *) 0)
end_define

begin_define
define|#
directive|define
name|NILBITMAP
value|((BITMAP *) 0)
end_define

begin_define
define|#
directive|define
name|NILMASK
value|((u_short *) 0)
end_define

begin_define
define|#
directive|define
name|NILBITS
value|((u_short *) 0)
end_define

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_comment
comment|/*  * Externs and statics used to interface to bitblt()  */
end_comment

begin_decl_stmt
specifier|static
name|Blt_Rectangle
name|SrcRect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Blt_Rectangle
name|DstRect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Blt
name|bltdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Blt_Rectangle
name|changed_rect
decl_stmt|;
end_decl_stmt

end_unit

