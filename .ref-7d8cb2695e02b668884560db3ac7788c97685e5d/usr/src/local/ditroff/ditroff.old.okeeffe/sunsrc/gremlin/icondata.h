begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)icondata.h	1.2	%G%  *  * References to memory pixrects used primarily as menu icons in  * the SUN Gremlin picture editor.  This file must be maintained  * consistently with icondata.c where the pixrects are actually  * defined.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|align_pr
decl_stmt|,
name|arc_pr
decl_stmt|,
name|arrow_pr
decl_stmt|,
name|bigblack_pr
decl_stmt|,
name|box_pr
decl_stmt|,
name|boxinc_pr
decl_stmt|,
name|copy_pr
decl_stmt|,
name|curve_pr
decl_stmt|,
name|erase_pr
decl_stmt|,
name|filecabinet_pr
decl_stmt|,
name|get1_pr
decl_stmt|,
name|get2_pr
decl_stmt|,
name|get3_pr
decl_stmt|,
name|get4_pr
decl_stmt|,
name|gravity_pr
decl_stmt|,
name|grid_pr
decl_stmt|,
name|hmirror_pr
decl_stmt|,
name|horizontal_pr
decl_stmt|,
name|horvert_pr
decl_stmt|,
name|include_pr
decl_stmt|,
name|includeset_pr
decl_stmt|,
name|justify_pr
decl_stmt|,
name|littlepoint_pr
decl_stmt|,
name|move_pr
decl_stmt|,
name|movepoint_pr
decl_stmt|,
name|polygon_pr
decl_stmt|,
name|bpolygon_pr
decl_stmt|,
name|put1_pr
decl_stmt|,
name|put2_pr
decl_stmt|,
name|put3_pr
decl_stmt|,
name|put4_pr
decl_stmt|,
name|question_pr
decl_stmt|,
name|rotate_pr
decl_stmt|,
name|scale_pr
decl_stmt|,
name|text_pr
decl_stmt|,
name|undo_pr
decl_stmt|,
name|vector_pr
decl_stmt|,
name|vertical_pr
decl_stmt|,
name|vmirror_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************** stipple data ****************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|openbox_pr
decl_stmt|,
name|white_pr
decl_stmt|,
name|gray_pr
decl_stmt|,
name|_50_pr
decl_stmt|,
name|black_pr
decl_stmt|,
name|stipple5_pr
decl_stmt|,
name|stipple6_pr
decl_stmt|,
name|stipple7_pr
decl_stmt|,
name|stipple8_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************  sizes  *********************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|size1_pr
decl_stmt|,
name|size2_pr
decl_stmt|,
name|size3_pr
decl_stmt|,
name|size4_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************  fonts  *********************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|roman_pr
decl_stmt|,
name|bold_pr
decl_stmt|,
name|italics_pr
decl_stmt|,
name|special_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************  lines  *********************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|broken_pr
decl_stmt|,
name|dashed_pr
decl_stmt|,
name|dotted_pr
decl_stmt|,
name|medium_pr
decl_stmt|,
name|narrow_pr
decl_stmt|,
name|thick_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************  misc   *********************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|point_pr
decl_stmt|,
name|uparrow_pr
decl_stmt|,
name|kbdcursor_pr
decl_stmt|,
name|diamond_pr
decl_stmt|,
name|bigopenbox_pr
decl_stmt|,
name|replgrid32_pr
decl_stmt|,
name|misc_pr
decl_stmt|,
name|linestyle_pr
decl_stmt|,
name|pan_pr
decl_stmt|,
name|dot_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************  gremlin tool icon   **************/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
name|gremlin_icon_pr
decl_stmt|;
end_decl_stmt

end_unit

