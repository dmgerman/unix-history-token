begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: region.h,v 11.13 91/09/10 08:21:49 rws Exp $ */
end_comment

begin_comment
comment|/************************************************************************ Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XREGION_H
end_ifndef

begin_define
define|#
directive|define
name|_XREGION_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x1
decl_stmt|,
name|x2
decl_stmt|,
name|y1
decl_stmt|,
name|y2
decl_stmt|;
block|}
name|Box
operator|,
name|BOX
operator|,
name|BoxRec
operator|,
typedef|*
name|BoxPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|,
name|width
decl_stmt|,
name|height
decl_stmt|;
block|}
name|RECTANGLE
operator|,
name|RectangleRec
operator|,
typedef|*
name|RectanglePtr
typedef|;
end_typedef

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

begin_define
define|#
directive|define
name|MAXSHORT
value|32767
end_define

begin_define
define|#
directive|define
name|MINSHORT
value|-MAXSHORT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   *   clip region  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XRegion
block|{
name|long
name|size
decl_stmt|;
name|long
name|numRects
decl_stmt|;
name|BOX
modifier|*
name|rects
decl_stmt|;
name|BOX
name|extents
decl_stmt|;
block|}
name|REGION
typedef|;
end_typedef

begin_comment
comment|/* Xutil.h contains the declaration:   * typedef struct _XRegion *Region;   */
end_comment

begin_comment
comment|/*  1 if two BOXs overlap.  *  0 if two BOXs do not overlap.  *  Remember, x2 and y2 are not in the region   */
end_comment

begin_define
define|#
directive|define
name|EXTENTCHECK
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|)
define|\
value|((r1)->x2> (r2)->x1&& \ 	 (r1)->x1< (r2)->x2&& \ 	 (r1)->y2> (r2)->y1&& \ 	 (r1)->y1< (r2)->y2)
end_define

begin_comment
comment|/*  *  update region extents  */
end_comment

begin_define
define|#
directive|define
name|EXTENTS
parameter_list|(
name|r
parameter_list|,
name|idRect
parameter_list|)
value|{\             if((r)->x1< (idRect)->extents.x1)\               (idRect)->extents.x1 = (r)->x1;\             if((r)->y1< (idRect)->extents.y1)\               (idRect)->extents.y1 = (r)->y1;\             if((r)->x2> (idRect)->extents.x2)\               (idRect)->extents.x2 = (r)->x2;\             if((r)->y2> (idRect)->extents.y2)\               (idRect)->extents.y2 = (r)->y2;\         }
end_define

begin_comment
comment|/*  *   Check to see if there is enough memory in the present region.  */
end_comment

begin_define
define|#
directive|define
name|MEMCHECK
parameter_list|(
name|reg
parameter_list|,
name|rect
parameter_list|,
name|firstrect
parameter_list|)
value|{\         if ((reg)->numRects>= ((reg)->size - 1)){\           (firstrect) = (BOX *) Xrealloc \           ((char *)(firstrect), (unsigned) (2 * (sizeof(BOX)) * ((reg)->size)));\           if ((firstrect) == 0)\             return(0);\           (reg)->size *= 2;\           (rect) =&(firstrect)[(reg)->numRects];\          }\        }
end_define

begin_comment
comment|/*  this routine checks to see if the previous rectangle is the same  *  or subsumes the new rectangle to add.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_PREVIOUS
parameter_list|(
name|Reg
parameter_list|,
name|R
parameter_list|,
name|Rx1
parameter_list|,
name|Ry1
parameter_list|,
name|Rx2
parameter_list|,
name|Ry2
parameter_list|)
define|\
value|(!(((Reg)->numRects> 0)&&\                   ((R-1)->y1 == (Ry1))&&\                   ((R-1)->y2 == (Ry2))&&\                   ((R-1)->x1<= (Rx1))&&\                   ((R-1)->x2>= (Rx2))))
end_define

begin_comment
comment|/*  add a rectangle to the given Region */
end_comment

begin_define
define|#
directive|define
name|ADDRECT
parameter_list|(
name|reg
parameter_list|,
name|r
parameter_list|,
name|rx1
parameter_list|,
name|ry1
parameter_list|,
name|rx2
parameter_list|,
name|ry2
parameter_list|)
value|{\     if (((rx1)< (rx2))&& ((ry1)< (ry2))&&\         CHECK_PREVIOUS((reg), (r), (rx1), (ry1), (rx2), (ry2))){\               (r)->x1 = (rx1);\               (r)->y1 = (ry1);\               (r)->x2 = (rx2);\               (r)->y2 = (ry2);\               EXTENTS((r), (reg));\               (reg)->numRects++;\               (r)++;\             }\         }
end_define

begin_comment
comment|/*  add a rectangle to the given Region */
end_comment

begin_define
define|#
directive|define
name|ADDRECTNOX
parameter_list|(
name|reg
parameter_list|,
name|r
parameter_list|,
name|rx1
parameter_list|,
name|ry1
parameter_list|,
name|rx2
parameter_list|,
name|ry2
parameter_list|)
value|{\             if ((rx1< rx2)&& (ry1< ry2)&&\                 CHECK_PREVIOUS((reg), (r), (rx1), (ry1), (rx2), (ry2))){\               (r)->x1 = (rx1);\               (r)->y1 = (ry1);\               (r)->x2 = (rx2);\               (r)->y2 = (ry2);\               (reg)->numRects++;\               (r)++;\             }\         }
end_define

begin_define
define|#
directive|define
name|EMPTY_REGION
parameter_list|(
name|pReg
parameter_list|)
value|pReg->numRects = 0
end_define

begin_define
define|#
directive|define
name|REGION_NOT_EMPTY
parameter_list|(
name|pReg
parameter_list|)
value|pReg->numRects
end_define

begin_define
define|#
directive|define
name|INBOX
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|( ( ((r).x2>  x))&& \         ( ((r).x1<= x))&& \         ( ((r).y2>  y))&& \         ( ((r).y1<= y)) )
end_define

begin_comment
comment|/*  * number of points to buffer before sending them off  * to scanlines() :  Must be an even number  */
end_comment

begin_define
define|#
directive|define
name|NUMPTSTOBUFFER
value|200
end_define

begin_comment
comment|/*  * used to allocate buffers for points and link  * the buffers together  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_POINTBLOCK
block|{
name|XPoint
name|pts
index|[
name|NUMPTSTOBUFFER
index|]
decl_stmt|;
name|struct
name|_POINTBLOCK
modifier|*
name|next
decl_stmt|;
block|}
name|POINTBLOCK
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

