begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: pathlist.h,v 10.1 86/11/19 10:46:00 jg Exp $ */
end_comment

begin_comment
comment|/* pathlist.h - Constants, macros, typedefs and globals  *              used by PathListConverter()  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Path list Segment structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_Segment
block|{
name|int
name|Index
decl_stmt|;
name|int
name|Type
decl_stmt|;
name|int
name|Count
decl_stmt|;
block|}
name|Segment
typedef|;
end_typedef

begin_comment
comment|/*  * Segment types  */
end_comment

begin_define
define|#
directive|define
name|LINE_SEGMENT
value|0
end_define

begin_define
define|#
directive|define
name|OPEN_CURVE_SEGMENT
value|1
end_define

begin_define
define|#
directive|define
name|CLOSED_CURVE_SEGMENT
value|2
end_define

begin_comment
comment|/*  * Default values for segemnt allocation  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_SEGMENTS
value|1024
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_SEGMENTS
value|512
end_define

begin_comment
comment|/*  * This macro starts a new segment and when required   * expands the size of the segment table  */
end_comment

begin_define
define|#
directive|define
name|StartNewSegment
parameter_list|(
name|type
parameter_list|,
name|index
parameter_list|,
name|count
parameter_list|)
value|{				   \     if(++SegmentIndex == MaxSegments) {				   	   \ 	Segment *TempSeg;						   \ 									   \ 	MaxSegments += 1 + ADDITIONAL_SEGMENTS;	   			   \ 	TempSeg = (Segment *)realloc((caddr_t)SegmentTable,	 	   \ 	             (unsigned)(MaxSegments * sizeof(Segment)));	   \ 	if(TempSeg == NULL) {   					   \ 	   return(NULL);						   \ 	}								   \         CurrentSegment =&((SegmentTable = TempSeg)[SegmentIndex]); 	   \     } else {								   \ 	CurrentSegment++;						   \     }									   \     CurrentSegment->Index = (index);				 	   \     CurrentSegment->Type = (type);				 	   \     CurrentSegment->Count = (count);				 	   \ }
end_define

begin_comment
comment|/*  * Defaults for spline vertex buffer allocation  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_SPLINE_VERTS
value|4096
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_SPLINE_VERTS
value|1024
end_define

begin_comment
comment|/*  * This macro increases the size of the spline vertex buffer  * if it is to small to handle "VertexCount" entries.  */
end_comment

begin_define
define|#
directive|define
name|GrowSplineVertexBuffer
parameter_list|(
name|CurrentVertex
parameter_list|,
name|VertexCount
parameter_list|)
value|{		   \ 	if((SplineVertexIndex + (VertexCount))> MaxSplineVerts) {	   \ 	    Vertex *TempVerts;						   \ 	    								   \ 	    MaxSplineVerts += ((VertexCount) - (MaxSplineVerts -	   \ 			SplineVertexIndex)) + ADDITIONAL_SPLINE_VERTS;	   \ 				    		      			   \ 	    TempVerts = (Vertex *)realloc((caddr_t)SplineVertexBuffer,	   \ 		    (unsigned)(MaxSplineVerts * sizeof(Vertex)));	   \             if(TempVerts == NULL) {					   \ 	        return(NULL);						   \             }								   \ 	    (CurrentVertex) =						   \&((SplineVertexBuffer = TempVerts)[SplineVertexIndex]);    \ 	}								   \ }
end_define

begin_comment
comment|/*  * Vertex type flags  */
end_comment

begin_define
define|#
directive|define
name|VERTEX_TYPE_MASK
value|0x001C
end_define

begin_define
define|#
directive|define
name|LINE
value|0x0000
end_define

begin_define
define|#
directive|define
name|CURVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|START_CLOSED_CURVE
value|0x000C
end_define

begin_define
define|#
directive|define
name|END_CLOSED_CURVE
value|0x0014
end_define

begin_define
define|#
directive|define
name|START_OF_CLOSED_POLY
value|0x8000
end_define

begin_comment
comment|/*  * glocal variables  */
end_comment

begin_decl_stmt
specifier|static
name|Vertex
modifier|*
name|SplineVertexBuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|SplineVertexIndex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|MaxSplineVerts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|SplineUsed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Segment
modifier|*
name|SegmentTable
decl_stmt|;
end_decl_stmt

end_unit

