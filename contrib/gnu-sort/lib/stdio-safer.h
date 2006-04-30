begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Invoke stdio functions, but avoid some glitches.     Copyright (C) 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|FILE
modifier|*
name|fopen_safer
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

