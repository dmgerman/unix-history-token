begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The Sun X drivers are a product of Sun Microsystems, Inc. and are provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify these drivers without charge, but are not authorized  * to license or distribute them to anyone else except as part of a product or  * program developed by the user.  *   * THE SUN X DRIVERS ARE PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND  * INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A  * PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE  * PRACTICE.  *  * The Sun X Drivers are provided with no support and without any obligation  * on the part of Sun Microsystems, Inc. to assist in their use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THE SUN X  * DRIVERS OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*-  * Copyright 1985, Massachusetts Institute of Technology  * Copyright (c) 1986 by Sun Microsystems,  Inc.  *  * @(#)Xsun.h 2.1 86/01/28  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<X/X.h>
end_include

begin_include
include|#
directive|include
file|<pixrect/pixrect_hs.h>
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
name|ConstantPixmap
value|0x0
end_define

begin_comment
comment|/* kinds of pixmaps on sun, constant */
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
comment|/* and 8-bit color ones */
end_comment

begin_define
define|#
directive|define
name|XYColorPixmap
value|0x3
end_define

begin_comment
comment|/* in both styles */
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

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
name|struct
name|pixrect
modifier|*
name|top
decl_stmt|;
comment|/* The cursor image */
name|BITMAP
modifier|*
name|top_bit
decl_stmt|;
name|struct
name|pixrect
modifier|*
name|bot
decl_stmt|;
comment|/* The cursor image */
name|BITMAP
modifier|*
name|bot_bit
decl_stmt|;
name|struct
name|pixrect
modifier|*
name|sv
decl_stmt|;
comment|/* The pixels underneath */
name|int
name|fore
decl_stmt|,
name|back
decl_stmt|,
name|c_func
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
name|F_DATA
parameter_list|(
name|x
parameter_list|)
value|((struct pixfont *) x->data)
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

begin_define
define|#
directive|define
name|SUN_FROM_X_OP
parameter_list|(
name|func
parameter_list|)
value|(Sun_From_X_Op[func])
end_define

begin_define
define|#
directive|define
name|SUN_FROM_X_OP_INVERT
parameter_list|(
name|func
parameter_list|)
value|(Sun_From_X_Op[SSMap[func|0x10]])
end_define

begin_decl_stmt
specifier|extern
name|char
name|SSMap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|Sun_From_X_Op
index|[]
decl_stmt|;
end_decl_stmt

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
name|cleft
parameter_list|,
name|ctop
parameter_list|,
name|cwidth
parameter_list|,
name|cheight
parameter_list|)
define|\
value|{ \ 	CLIP       *cl = clips++; \ 	cleft = cl->left; \ 	ctop = cl->top; \ 	cwidth = cl->width; \ 	cheight = cl->height; \     }
end_define

begin_define
define|#
directive|define
name|OverLap
parameter_list|(
name|x1
parameter_list|,
name|y1
parameter_list|,
name|w1
parameter_list|,
name|h1
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
value|((x1< x2+w2)&& (y1< y2+h2)&& (x2< x1+w1)&& (y2< y1+h1))
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
value|(i<j?i:j)
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
value|(i>j?i:j)
end_define

begin_define
define|#
directive|define
name|SetZmask
parameter_list|(
name|pr
parameter_list|,
name|zm
parameter_list|)
value|{ \ 	extern private_czmask; \ 	if (*(char *)(zm) != (char)private_czmask) { \ 		pr_putattributes(pr, (zm)); \ 		private_czmask = *(zm); \ 	}}
end_define

end_unit

