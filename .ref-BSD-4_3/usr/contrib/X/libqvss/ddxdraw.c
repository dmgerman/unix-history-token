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
comment|/*	 DDX DRAW CURVE INTERFACE					*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	written by : MATT CORKUM  09-12-85				*/
end_comment

begin_comment
comment|/*      modified 09-23-85:  make it look like the ddx interface		*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	 The ddx draw curve interface code				*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	MODIFICATION HISTORY						*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Carver  8510.21 Fixed "bwidth, bwidth" to be "bwidth, bheight"  */
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Carver  8510.21 Put in single plane code.			*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Carver  8510.09 Fixed "if (mode = 1)" to be "if (mode == 1)"	*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Carver  8510.03 Bad idea... after a few infinite loops we don't */
end_comment

begin_comment
comment|/*   			ignore errors returned by the path list		*/
end_comment

begin_comment
comment|/*			converter anymore.				*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	Carver	8509.25	Removed error handling code			*/
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

begin_comment
comment|/* THERE IS A CONFLICT BETWEEN ddxqvss.h and qvss.h (wpitch) SO MAKE SURE    TO INCLUDE ddxqvss.h FIRST */
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

begin_macro
name|DrawCurve
argument_list|(
argument|verts
argument_list|,
argument|vertcnt
argument_list|,
argument|xbase
argument_list|,
argument|ybase
argument_list|,
argument|srcpix
argument_list|,
argument|altpix
argument_list|,
argument|mode
argument_list|,
argument|bwidth
argument_list|,
argument|bheight
argument_list|,
argument|pat
argument_list|,
argument|patlen
argument_list|,
argument|patmult
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

begin_comment
comment|/* vertexes and flags	   	*/
end_comment

begin_decl_stmt
name|int
name|vertcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vertex count 	   	*/
end_comment

begin_decl_stmt
name|int
name|xbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination offset in x      */
end_comment

begin_decl_stmt
name|int
name|ybase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination offset in y      */
end_comment

begin_decl_stmt
name|int
name|srcpix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source pixel		   	*/
end_comment

begin_decl_stmt
name|int
name|altpix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alternate source pixel  	*/
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0:solid 1:dashed 2:patterned */
end_comment

begin_decl_stmt
name|int
name|bwidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* brush width			*/
end_comment

begin_decl_stmt
name|int
name|bheight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* brush height			*/
end_comment

begin_decl_stmt
name|int
name|pat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pattern			*/
end_comment

begin_decl_stmt
name|int
name|patlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pattern length		*/
end_comment

begin_decl_stmt
name|int
name|patmult
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pattern repeat count		*/
end_comment

begin_decl_stmt
name|CLIP
modifier|*
name|clips
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clipping rectangles		*/
end_comment

begin_decl_stmt
name|int
name|clipcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of clipping rectangles */
end_comment

begin_decl_stmt
name|int
name|func
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GX display function 		*/
end_comment

begin_decl_stmt
name|int
name|zmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* plane mask			*/
end_comment

begin_block
block|{
name|long
name|error
decl_stmt|;
comment|/* error value to be returned*/
name|char
name|s_pixel_flag
decl_stmt|;
comment|/* single pixel flag         */
name|short
modifier|*
name|newvert
decl_stmt|;
comment|/* new vertex list 	     */
name|int
name|newvertcnt
decl_stmt|;
comment|/* new vertex count	     */
comment|/* LIMIT THE DRAW OPERATION TO ONE PLANE */
if|if
condition|(
operator|(
name|zmask
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
return|return;
name|srcpix
operator|=
name|srcpix
operator|&
literal|1
expr_stmt|;
name|altpix
operator|=
name|altpix
operator|&
literal|1
expr_stmt|;
comment|/* pre-process the specified path list ..... create another one  	   containing only absolute straight line drawing */
name|error
operator|=
name|path_list_converter
argument_list|(
operator|&
name|verts
argument_list|,
operator|&
name|vertcnt
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
block|{
name|DeviceError
argument_list|(
literal|"DrawCurve failure\n"
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/* are we in single pixel mode or not ? */
if|if
condition|(
operator|(
name|bwidth
operator|==
literal|1
operator|)
operator|&&
operator|(
name|bheight
operator|==
literal|1
operator|)
condition|)
name|s_pixel_flag
operator|=
literal|1
expr_stmt|;
else|else
name|s_pixel_flag
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|mode
operator|==
literal|0
operator|)
operator|&&
operator|(
name|s_pixel_flag
operator|)
condition|)
comment|/* solid single pixel */
comment|/* call the solid single pixel draw command */
name|error
operator|=
name|draw_cons_solid_spix_line
argument_list|(
name|srcpix
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
elseif|else
if|if
condition|(
name|mode
operator|==
literal|0
condition|)
comment|/* solid mode */
comment|/* s_pixel_flag = 0 ( multiple pixel )     */
comment|/* call the solid multi-pixel draw command */
name|error
operator|=
name|draw_cons_solid_mpix_line
argument_list|(
name|srcpix
argument_list|,
name|bwidth
argument_list|,
name|bheight
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
elseif|else
if|if
condition|(
operator|(
name|mode
operator|==
literal|1
operator|)
operator|&&
operator|(
name|s_pixel_flag
operator|)
condition|)
comment|/* dashed mode */
comment|/* call dashed single pixel draw curve */
name|error
operator|=
name|draw_cons_pat_spix_line
argument_list|(
name|srcpix
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
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|patlen
argument_list|,
name|pat
argument_list|,
name|patmult
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|mode
operator|==
literal|1
condition|)
comment|/* dashed mode */
comment|/* s_pixel_flag = 0 ( multiple pixel )     */
comment|/* call multiple pixel dashed draw command */
name|error
operator|=
name|draw_cons_pat_mpix_line
argument_list|(
name|srcpix
argument_list|,
name|bwidth
argument_list|,
name|bheight
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
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|patlen
argument_list|,
name|pat
argument_list|,
name|patmult
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|mode
operator|==
literal|2
operator|)
operator|&&
operator|(
name|s_pixel_flag
operator|)
condition|)
comment|/* patterned mode */
block|{
name|error
operator|=
name|draw_2_src_cons_spix_line
argument_list|(
name|srcpix
argument_list|,
name|altpix
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
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|patlen
argument_list|,
name|pat
argument_list|,
name|patmult
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
block|}
comment|/* end of patterned single pixel */
elseif|else
if|if
condition|(
name|mode
operator|==
literal|2
condition|)
comment|/* patterned lines */
block|{
name|error
operator|=
name|draw_2_src_mpix_line
argument_list|(
name|srcpix
argument_list|,
name|altpix
argument_list|,
name|bwidth
argument_list|,
name|bheight
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
name|func
argument_list|,
name|newvertcnt
argument_list|,
name|newvert
argument_list|,
name|patlen
argument_list|,
name|pat
argument_list|,
name|patmult
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|clipcount
argument_list|,
name|clips
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

