begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_decl_stmt
name|class
name|common_output
range|:
name|public
name|output
block|{
name|private
operator|:
name|void
name|dash_line
argument_list|(
argument|const position&start
argument_list|,
argument|const position&end
argument_list|,
argument|const line_type&lt
argument_list|,
argument|double dash_width
argument_list|,
argument|double gap_width
argument_list|,
argument|double *offsetp
argument_list|)
block|;
name|void
name|dash_arc
argument_list|(
argument|const position&cent
argument_list|,
argument|double rad
argument_list|,
argument|double start_angle
argument_list|,
argument|double end_angle
argument_list|,
argument|const line_type&lt
argument_list|,
argument|double dash_width
argument_list|,
argument|double gap_width
argument_list|,
argument|double *offsetp
argument_list|)
block|;
name|void
name|dot_line
argument_list|(
argument|const position&start
argument_list|,
argument|const position&end
argument_list|,
argument|const line_type&lt
argument_list|,
argument|double gap_width
argument_list|,
argument|double *offsetp
argument_list|)
block|;
name|void
name|dot_arc
argument_list|(
argument|const position&cent
argument_list|,
argument|double rad
argument_list|,
argument|double start_angle
argument_list|,
argument|double end_angle
argument_list|,
argument|const line_type&lt
argument_list|,
argument|double gap_width
argument_list|,
argument|double *offsetp
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|dot
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
operator|=
literal|0
block|;
name|void
name|dashed_circle
argument_list|(
argument|const position&
argument_list|,
argument|double rad
argument_list|,
argument|const line_type&
argument_list|)
block|;
name|void
name|dotted_circle
argument_list|(
argument|const position&
argument_list|,
argument|double rad
argument_list|,
argument|const line_type&
argument_list|)
block|;
name|void
name|dashed_arc
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
block|;
name|void
name|dotted_arc
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
block|;
name|virtual
name|void
name|solid_arc
argument_list|(
argument|const position&cent
argument_list|,
argument|double rad
argument_list|,
argument|double start_angle
argument_list|,
argument|double end_angle
argument_list|,
argument|const line_type&lt
argument_list|)
block|;
name|void
name|dashed_rounded_box
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
name|double
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
block|;
name|void
name|dotted_rounded_box
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
name|double
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
block|;
name|void
name|solid_rounded_box
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
name|double
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
block|;
name|void
name|filled_rounded_box
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
name|double
argument_list|,
name|double
argument_list|)
block|;
name|public
operator|:
name|void
name|start_picture
argument_list|(
argument|double sc
argument_list|,
argument|const position&ll
argument_list|,
argument|const position&ur
argument_list|)
operator|=
literal|0
block|;
name|void
name|finish_picture
argument_list|()
operator|=
literal|0
block|;
name|void
name|circle
argument_list|(
argument|const position&
argument_list|,
argument|double rad
argument_list|,
argument|const line_type&
argument_list|,
argument|double
argument_list|)
operator|=
literal|0
block|;
name|void
name|text
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
name|text_piece
operator|*
argument_list|,
name|int
argument_list|,
name|double
argument_list|)
operator|=
literal|0
block|;
name|void
name|line
argument_list|(
argument|const position&
argument_list|,
argument|const position *
argument_list|,
argument|int n
argument_list|,
argument|const line_type&
argument_list|)
operator|=
literal|0
block|;
name|void
name|polygon
argument_list|(
argument|const position *
argument_list|,
argument|int n
argument_list|,
argument|const line_type&
argument_list|,
argument|double
argument_list|)
operator|=
literal|0
block|;
name|void
name|spline
argument_list|(
argument|const position&
argument_list|,
argument|const position *
argument_list|,
argument|int n
argument_list|,
argument|const line_type&
argument_list|)
operator|=
literal|0
block|;
name|void
name|arc
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|)
operator|=
literal|0
block|;
name|void
name|ellipse
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|,
name|double
argument_list|)
operator|=
literal|0
block|;
name|void
name|rounded_box
argument_list|(
specifier|const
name|position
operator|&
argument_list|,
specifier|const
name|distance
operator|&
argument_list|,
name|double
argument_list|,
specifier|const
name|line_type
operator|&
argument_list|,
name|double
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|compute_arc_center
parameter_list|(
specifier|const
name|position
modifier|&
name|start
parameter_list|,
specifier|const
name|position
modifier|&
name|cent
parameter_list|,
specifier|const
name|position
modifier|&
name|end
parameter_list|,
name|position
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

end_unit

