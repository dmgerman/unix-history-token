begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	 DDX FILL INTERFACE						*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	written by : MATT CORKUM  09-25-85				*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	 The ddx fill interface code					*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Modification History:						*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	8511.04 (Carver) When filling with constant make sure to mask	*/
end_comment

begin_comment
comment|/*			 srcpix to one bit.				*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	8509.30 (Corkum) Make the code work in a test environment.	*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"ddxqvss.h"
end_include

begin_include
include|#
directive|include
file|"qvss.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_include
include|#
directive|include
file|"vstagbl.h"
end_include

begin_decl_stmt
specifier|extern
name|BITMAP
name|pbm
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|DrawFilled
argument_list|(
argument|verts
argument_list|,
argument|vertcount
argument_list|,
argument|xbase
argument_list|,
argument|ybase
argument_list|,
argument|srcpix
argument_list|,
argument|tile
argument_list|,
argument|xoff
argument_list|,
argument|yoff
argument_list|,
argument|clips
argument_list|,
argument|clipcount
argument_list|,
argument|func
argument_list|,
argument|zmask
argument_list|)
end_macro

begin_decl_stmt
name|Vertex
modifier|*
name|verts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|PIXMAP
modifier|*
name|tile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vertcount
decl_stmt|,
name|xbase
decl_stmt|,
name|ybase
decl_stmt|,
name|srcpix
decl_stmt|,
name|xoff
decl_stmt|,
name|yoff
decl_stmt|,
name|clipcount
decl_stmt|,
name|zmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CLIP
modifier|*
name|clips
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|error
decl_stmt|;
comment|/* error value to be returned*/
name|short
modifier|*
name|newvert
decl_stmt|;
comment|/* new vertex list 	     */
name|int
name|newvertcnt
decl_stmt|;
comment|/* new vertex count	     */
name|int
name|src
decl_stmt|,
name|src_type
decl_stmt|;
comment|/* source information 	     */
if|if
condition|(
operator|!
operator|(
name|zmask
operator|&
literal|0x0001
operator|)
condition|)
return|return;
comment|/* pre-process the specified path list ..... create another one  	   containing only absolute straight line drawing */
comment|/* for a fill operation the destination offsets are zero, however we 		call the pathlist converter routine to make an absolute, 		(pertaining to not relative), and straight line pathlist */
name|error
operator|=
name|path_list_converter
argument_list|(
operator|&
name|verts
argument_list|,
operator|&
name|vertcount
argument_list|,
name|xbase
argument_list|,
name|ybase
argument_list|,
operator|&
name|newvert
argument_list|,
operator|&
name|newvertcnt
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|tile
operator|==
literal|0
condition|)
comment|/* if no halftone pattern exists then use the 				constant source to perform the fill */
block|{
name|src_type
operator|=
name|VSTA$K_SRC_CONST
expr_stmt|;
name|error
operator|=
name|fillhalf
argument_list|(
name|src_type
argument_list|,
operator|(
name|srcpix
operator|&
literal|1
operator|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|(
name|short
operator|*
operator|)
name|pbm
operator|.
name|data
argument_list|,
name|pbm
operator|.
name|width
argument_list|,
name|pbm
operator|.
name|height
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* fill with a halftone */
block|{
specifier|register
name|BITMAP
modifier|*
name|bm
init|=
operator|(
name|BITMAP
operator|*
operator|)
name|tile
operator|->
name|data
decl_stmt|;
name|src_type
operator|=
name|VSTA$K_SRC_HT_BITMAP
expr_stmt|;
name|error
operator|=
name|fillhalf
argument_list|(
name|src_type
argument_list|,
operator|(
name|short
operator|*
operator|)
name|bm
operator|->
name|data
argument_list|,
name|bm
operator|->
name|width
argument_list|,
name|bm
operator|->
name|height
argument_list|,
name|xoff
argument_list|,
name|yoff
argument_list|,
operator|(
name|short
operator|*
operator|)
name|pbm
operator|.
name|data
argument_list|,
name|pbm
operator|.
name|width
argument_list|,
name|pbm
operator|.
name|height
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_block

end_unit

