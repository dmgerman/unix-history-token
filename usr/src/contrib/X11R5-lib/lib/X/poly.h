begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: poly.h,v 1.3 91/03/08 13:44:31 rws Exp $ */
end_comment

begin_comment
comment|/************************************************************************ Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ************************************************************************/
end_comment

begin_comment
comment|/*  *     This file contains a few macros to help track  *     the edge of a filled object.  The object is assumed  *     to be filled in scanline order, and thus the  *     algorithm used is an extension of Bresenham's line  *     drawing algorithm which assumes that y is always the  *     major axis.  *     Since these pieces of code are the same for any filled shape,  *     it is more convenient to gather the library in one  *     place, but since these pieces of code are also in  *     the inner loops of output primitives, procedure call  *     overhead is out of the question.  *     See the author for a derivation if needed.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *  In scan converting polygons, we want to choose those pixels  *  which are inside the polygon.  Thus, we add .5 to the starting  *  x coordinate for both left and right edges.  Now we choose the  *  first pixel which is inside the pgon for the left edge and the  *  first pixel which is outside the pgon for the right edge.  *  Draw the left pixel, but not the right.  *  *  How to add .5 to the starting x coordinate:  *      If the edge is moving to the right, then subtract dy from the  *  error term from the general form of the algorithm.  *      If the edge is moving to the left, then add dy to the error term.  *  *  The reason for the difference between edges moving to the left  *  and edges moving to the right is simple:  If an edge is moving  *  to the right, then we want the algorithm to flip immediately.  *  If it is moving to the left, then we don't want it to flip until  *  we traverse an entire pixel.  */
end_comment

begin_define
define|#
directive|define
name|BRESINITPGON
parameter_list|(
name|dy
parameter_list|,
name|x1
parameter_list|,
name|x2
parameter_list|,
name|xStart
parameter_list|,
name|d
parameter_list|,
name|m
parameter_list|,
name|m1
parameter_list|,
name|incr1
parameter_list|,
name|incr2
parameter_list|)
value|{ \     int dx;
comment|/* local storage */
value|\ \
comment|/* \      *  if the edge is horizontal, then it is ignored \      *  and assumed not to be processed.  Otherwise, do this stuff. \      */
value|\     if ((dy) != 0) { \         xStart = (x1); \         dx = (x2) - xStart; \         if (dx< 0) { \             m = dx / (dy); \             m1 = m - 1; \             incr1 = -2 * dx + 2 * (dy) * m1; \             incr2 = -2 * dx + 2 * (dy) * m; \             d = 2 * m * (dy) - 2 * dx - 2 * (dy); \         } else { \             m = dx / (dy); \             m1 = m + 1; \             incr1 = 2 * dx - 2 * (dy) * m1; \             incr2 = 2 * dx - 2 * (dy) * m; \             d = -2 * m * (dy) + 2 * dx; \         } \     } \ }
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|BRESINCRPGON
parameter_list|(
name|d
parameter_list|,
name|minval
parameter_list|,
name|m
parameter_list|,
name|m1
parameter_list|,
name|incr1
parameter_list|,
name|incr2
parameter_list|)
value|{ \     if (m1> 0) { \         if (d> 0) { \             minval += m1; \             d += incr1; \         } \         else { \             minval += m; \             d += incr2; \         } \     } else {\         if (d>= 0) { \             minval += m1; \             d += incr1; \         } \         else { \             minval += m; \             d += incr2; \         } \     } \ }
end_define

begin_escape
end_escape

begin_comment
comment|/*  *     This structure contains all of the information needed  *     to run the bresenham algorithm.  *     The variables may be hardcoded into the declarations  *     instead of using this structure to make use of  *     register declarations.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|minor_axis
decl_stmt|;
comment|/* minor axis        */
name|int
name|d
decl_stmt|;
comment|/* decision variable */
name|int
name|m
decl_stmt|,
name|m1
decl_stmt|;
comment|/* slope and slope+1 */
name|int
name|incr1
decl_stmt|,
name|incr2
decl_stmt|;
comment|/* error increments */
block|}
name|BRESINFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BRESINITPGONSTRUCT
parameter_list|(
name|dmaj
parameter_list|,
name|min1
parameter_list|,
name|min2
parameter_list|,
name|bres
parameter_list|)
define|\
value|BRESINITPGON(dmaj, min1, min2, bres.minor_axis, bres.d, \                      bres.m, bres.m1, bres.incr1, bres.incr2)
end_define

begin_define
define|#
directive|define
name|BRESINCRPGONSTRUCT
parameter_list|(
name|bres
parameter_list|)
define|\
value|BRESINCRPGON(bres.d, bres.minor_axis, bres.m, bres.m1, bres.incr1, bres.incr2)
end_define

begin_comment
comment|/*  *     These are the data structures needed to scan  *     convert regions.  Two different scan conversion  *     methods are available -- the even-odd method, and  *     the winding number method.  *     The even-odd rule states that a point is inside  *     the polygon if a ray drawn from that point in any  *     direction will pass through an odd number of  *     path segments.  *     By the winding number rule, a point is decided  *     to be inside the polygon if a ray drawn from that  *     point in any direction passes through a different  *     number of clockwise and counter-clockwise path  *     segments.  *  *     These data structures are adapted somewhat from  *     the algorithm in (Foley/Van Dam) for scan converting  *     polygons.  *     The basic algorithm is to start at the top (smallest y)  *     of the polygon, stepping down to the bottom of  *     the polygon by incrementing the y coordinate.  We  *     keep a list of edges which the current scanline crosses,  *     sorted by x.  This list is called the Active Edge Table (AET)  *     As we change the y-coordinate, we update each entry in   *     in the active edge table to reflect the edges new xcoord.  *     This list must be sorted at each scanline in case  *     two edges intersect.  *     We also keep a data structure known as the Edge Table (ET),  *     which keeps track of all the edges which the current  *     scanline has not yet reached.  The ET is basically a  *     list of ScanLineList structures containing a list of  *     edges which are entered at a given scanline.  There is one  *     ScanLineList per scanline at which an edge is entered.  *     When we enter a new edge, we move it from the ET to the AET.  *  *     From the AET, we can implement the even-odd rule as in  *     (Foley/Van Dam).  *     The winding number rule is a little trickier.  We also  *     keep the EdgeTableEntries in the AET linked by the  *     nextWETE (winding EdgeTableEntry) link.  This allows  *     the edges to be linked just as before for updating  *     purposes, but only uses the edges linked by the nextWETE  *     link as edges representing spans of the polygon to  *     drawn (as with the even-odd rule).  */
end_comment

begin_comment
comment|/*  * for the winding number rule  */
end_comment

begin_define
define|#
directive|define
name|CLOCKWISE
value|1
end_define

begin_define
define|#
directive|define
name|COUNTERCLOCKWISE
value|-1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EdgeTableEntry
block|{
name|int
name|ymax
decl_stmt|;
comment|/* ycoord at which we exit this edge. */
name|BRESINFO
name|bres
decl_stmt|;
comment|/* Bresenham info to run the edge     */
name|struct
name|_EdgeTableEntry
modifier|*
name|next
decl_stmt|;
comment|/* next in the list     */
name|struct
name|_EdgeTableEntry
modifier|*
name|back
decl_stmt|;
comment|/* for insertion sort   */
name|struct
name|_EdgeTableEntry
modifier|*
name|nextWETE
decl_stmt|;
comment|/* for winding num rule */
name|int
name|ClockWise
decl_stmt|;
comment|/* flag for winding number rule       */
block|}
name|EdgeTableEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ScanLineList
block|{
name|int
name|scanline
decl_stmt|;
comment|/* the scanline represented */
name|EdgeTableEntry
modifier|*
name|edgelist
decl_stmt|;
comment|/* header node              */
name|struct
name|_ScanLineList
modifier|*
name|next
decl_stmt|;
comment|/* next in the list       */
block|}
name|ScanLineList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|ymax
decl_stmt|;
comment|/* ymax for the polygon     */
name|int
name|ymin
decl_stmt|;
comment|/* ymin for the polygon     */
name|ScanLineList
name|scanlines
decl_stmt|;
comment|/* header node              */
block|}
name|EdgeTable
typedef|;
end_typedef

begin_comment
comment|/*  * Here is a struct to help with storage allocation  * so we can allocate a big chunk at a time, and then take  * pieces from this heap when we need to.  */
end_comment

begin_define
define|#
directive|define
name|SLLSPERBLOCK
value|25
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ScanLineListBlock
block|{
name|ScanLineList
name|SLLs
index|[
name|SLLSPERBLOCK
index|]
decl_stmt|;
name|struct
name|_ScanLineListBlock
modifier|*
name|next
decl_stmt|;
block|}
name|ScanLineListBlock
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/*  *  *     a few macros for the inner loops of the fill code where  *     performance considerations don't allow a procedure call.  *  *     Evaluate the given edge at the given scanline.  *     If the edge has expired, then we leave it and fix up  *     the active edge table; otherwise, we increment the  *     x value to be ready for the next scanline.  *     The winding number rule is in effect, so we must notify  *     the caller when the edge has been removed so he  *     can reorder the Winding Active Edge Table.  */
end_comment

begin_define
define|#
directive|define
name|EVALUATEEDGEWINDING
parameter_list|(
name|pAET
parameter_list|,
name|pPrevAET
parameter_list|,
name|y
parameter_list|,
name|fixWAET
parameter_list|)
value|{ \    if (pAET->ymax == y) {
comment|/* leaving this edge */
value|\       pPrevAET->next = pAET->next; \       pAET = pPrevAET->next; \       fixWAET = 1; \       if (pAET) \          pAET->back = pPrevAET; \    } \    else { \       BRESINCRPGONSTRUCT(pAET->bres); \       pPrevAET = pAET; \       pAET = pAET->next; \    } \ }
end_define

begin_comment
comment|/*  *     Evaluate the given edge at the given scanline.  *     If the edge has expired, then we leave it and fix up  *     the active edge table; otherwise, we increment the  *     x value to be ready for the next scanline.  *     The even-odd rule is in effect.  */
end_comment

begin_define
define|#
directive|define
name|EVALUATEEDGEEVENODD
parameter_list|(
name|pAET
parameter_list|,
name|pPrevAET
parameter_list|,
name|y
parameter_list|)
value|{ \    if (pAET->ymax == y) {
comment|/* leaving this edge */
value|\       pPrevAET->next = pAET->next; \       pAET = pPrevAET->next; \       if (pAET) \          pAET->back = pPrevAET; \    } \    else { \       BRESINCRPGONSTRUCT(pAET->bres); \       pPrevAET = pAET; \       pAET = pAET->next; \    } \ }
end_define

end_unit

