begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: makemask.h,v 10.1 86/11/19 10:45:51 jg Exp $ */
end_comment

begin_comment
comment|/* makemask.h -  Defines, constants, structures and globals  *               use by MakeMask()  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Edge table entry  */
end_comment

begin_struct
specifier|static
struct|struct
name|edge
block|{
name|struct
name|edge
modifier|*
name|NextEdge
decl_stmt|;
comment|/* pointer to next edge */
name|long
name|Delta_X
decl_stmt|;
comment|/* change in x per scan line */
name|long
name|Min_X
decl_stmt|;
comment|/* current x value */
name|short
name|Max_Y
decl_stmt|;
comment|/* last scan line of edge */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ploygon   */
end_comment

begin_struct
specifier|static
struct|struct
name|Polygon
block|{
name|Vertex
modifier|*
name|PolyPoints
decl_stmt|;
comment|/* pointer to list of points */
name|int
name|PolyCount
decl_stmt|;
comment|/* number of points in polygon */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Left and right mask values used by FillMask()  */
end_comment

begin_decl_stmt
specifier|static
name|long
name|LeftMasks
index|[]
init|=
block|{
literal|0x80000000
block|,
literal|0xC0000000
block|,
literal|0xE0000000
block|,
literal|0xF0000000
block|,
literal|0xF8000000
block|,
literal|0xFC000000
block|,
literal|0xFE000000
block|,
literal|0xFF000000
block|,
literal|0xFF800000
block|,
literal|0xFFC00000
block|,
literal|0xFFE00000
block|,
literal|0xFFF00000
block|,
literal|0xFFF80000
block|,
literal|0xFFFC0000
block|,
literal|0xFFFE0000
block|,
literal|0xFFFF0000
block|,
literal|0xFFFF8000
block|,
literal|0xFFFFC000
block|,
literal|0xFFFFE000
block|,
literal|0xFFFFF000
block|,
literal|0xFFFFF800
block|,
literal|0xFFFFFC00
block|,
literal|0xFFFFFE00
block|,
literal|0xFFFFFF00
block|,
literal|0xFFFFFF80
block|,
literal|0xFFFFFFC0
block|,
literal|0xFFFFFFE0
block|,
literal|0xFFFFFFF0
block|,
literal|0xFFFFFFF8
block|,
literal|0xFFFFFFFC
block|,
literal|0xFFFFFFFE
block|,
literal|0xFFFFFFFF
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|RightMasks
index|[]
init|=
block|{
literal|0xFFFFFFFF
block|,
literal|0x7FFFFFFF
block|,
literal|0x3FFFFFFF
block|,
literal|0x1FFFFFFF
block|,
literal|0x0FFFFFFF
block|,
literal|0x07FFFFFF
block|,
literal|0x03FFFFFF
block|,
literal|0x01FFFFFF
block|,
literal|0x00FFFFFF
block|,
literal|0x007FFFFF
block|,
literal|0x003FFFFF
block|,
literal|0x001FFFFF
block|,
literal|0x000FFFFF
block|,
literal|0x0007FFFF
block|,
literal|0x0003FFFF
block|,
literal|0x0001FFFF
block|,
literal|0x0000FFFF
block|,
literal|0x00007FFF
block|,
literal|0x00003FFF
block|,
literal|0x00001FFF
block|,
literal|0x00000FFF
block|,
literal|0x000007FF
block|,
literal|0x000003FF
block|,
literal|0x000001FF
block|,
literal|0x000000FF
block|,
literal|0x0000007F
block|,
literal|0x0000003F
block|,
literal|0x0000001F
block|,
literal|0x0000000F
block|,
literal|0x00000007
block|,
literal|0x00000003
block|,
literal|0x00000001
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * global variables  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|EdgeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|edge
modifier|*
modifier|*
name|EdgeTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|edge
modifier|*
name|Edges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|Direction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ShortenStartOfEdge
decl_stmt|;
end_decl_stmt

end_unit

