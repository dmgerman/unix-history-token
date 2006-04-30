begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2001 Free Software Foundation, Inc.      Written by Gaius Mulley<gaius@glam.ac.uk>  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

begin_function_decl
name|int
name|adjust_arc_center
parameter_list|(
specifier|const
name|int
modifier|*
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_output_arc_limits
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|xv1
parameter_list|,
name|int
name|yv1
parameter_list|,
name|int
name|xv2
parameter_list|,
name|int
name|yv2
parameter_list|,
name|double
name|c0
parameter_list|,
name|double
name|c1
parameter_list|,
name|int
modifier|*
name|minx
parameter_list|,
name|int
modifier|*
name|maxx
parameter_list|,
name|int
modifier|*
name|miny
parameter_list|,
name|int
modifier|*
name|maxy
parameter_list|)
function_decl|;
end_function_decl

end_unit

