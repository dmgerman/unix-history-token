begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_StoreBox_c
init|=
literal|"$Header: StoreBox.c,v 10.4 86/11/19 16:24:44 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  *			COPYRIGHT 1985, 1986  *		   DIGITAL EQUIPMENT CORPORATION  *		       MAYNARD, MASSACHUSETTS  *			ALL RIGHTS RESERVED.  *  * THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND  * SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL EQUIPMENT CORPORATION.  * DIGITAL MAKES NO REPRESENTATIONS ABOUT THE SUITIBILITY OF THIS SOFTWARE FOR  * ANY PURPOSE.  IT IS SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.  *  * IF THE SOFTWARE IS MODIFIED IN A MANNER CREATING DERIVATIVE COPYRIGHT RIGHTS,  * APPROPRIATE LEGENDS MAY BE PLACED ON THE DERIVATIVE WORK IN ADDITION TO THAT  * SET FORTH ABOVE.  *  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting documentation,  * and that the name of Digital Equipment Corporation not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission.  *  */
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)StoreBox.c	3.8	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	StoreBox - This subroutine is used by the X Window Manager (xwm)  *	to store the vertices for the resize / movement box in a vertex list.  */
end_comment

begin_include
include|#
directive|include
file|"uwm.h"
end_include

begin_comment
comment|/*  * Store the vertices for the resize movement box in a vertex list.  */
end_comment

begin_function
name|int
name|StoreBox
parameter_list|(
name|box
parameter_list|,
name|ulx
parameter_list|,
name|uly
parameter_list|,
name|lrx
parameter_list|,
name|lry
parameter_list|)
specifier|register
name|Vertex
name|box
index|[]
decl_stmt|;
name|int
name|ulx
decl_stmt|;
comment|/* Upper left X coordinate. */
name|int
name|uly
decl_stmt|;
comment|/* Upper left Y coordinate. */
name|int
name|lrx
decl_stmt|;
comment|/* Lower right X coordinate. */
name|int
name|lry
decl_stmt|;
comment|/* Lower right Y coordinate. */
block|{
comment|/*      * Xor in.      */
name|box
index|[
literal|0
index|]
operator|.
name|x
operator|=
name|box
index|[
literal|3
index|]
operator|.
name|x
operator|=
name|box
index|[
literal|4
index|]
operator|.
name|x
operator|=
name|ulx
expr_stmt|;
name|box
index|[
literal|0
index|]
operator|.
name|y
operator|=
name|box
index|[
literal|1
index|]
operator|.
name|y
operator|=
name|box
index|[
literal|4
index|]
operator|.
name|y
operator|=
name|uly
expr_stmt|;
name|box
index|[
literal|1
index|]
operator|.
name|x
operator|=
name|box
index|[
literal|2
index|]
operator|.
name|x
operator|=
name|lrx
expr_stmt|;
name|box
index|[
literal|2
index|]
operator|.
name|y
operator|=
name|box
index|[
literal|3
index|]
operator|.
name|y
operator|=
name|lry
expr_stmt|;
name|box
index|[
literal|0
index|]
operator|.
name|flags
operator|=
name|VertexDontDraw
expr_stmt|;
comment|/*      * If we freeze the screen, don't bother to xor out.      */
if|if
condition|(
name|Freeze
condition|)
return|return
operator|(
literal|5
operator|)
return|;
comment|/*      * Xor out.      */
name|box
index|[
literal|7
index|]
operator|.
name|x
operator|=
name|box
index|[
literal|8
index|]
operator|.
name|x
operator|=
name|ulx
expr_stmt|;
name|box
index|[
literal|5
index|]
operator|.
name|y
operator|=
name|box
index|[
literal|8
index|]
operator|.
name|y
operator|=
name|uly
expr_stmt|;
name|box
index|[
literal|5
index|]
operator|.
name|x
operator|=
name|box
index|[
literal|6
index|]
operator|.
name|x
operator|=
name|lrx
expr_stmt|;
name|box
index|[
literal|6
index|]
operator|.
name|y
operator|=
name|box
index|[
literal|7
index|]
operator|.
name|y
operator|=
name|lry
expr_stmt|;
comment|/*      * Total number of vertices is 9.      */
return|return
operator|(
literal|9
operator|)
return|;
block|}
end_function

end_unit

