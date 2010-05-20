begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Duplicate a bounded initial segment of a string, with out-of-memory    checking.    Copyright (C) 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Return a newly allocated copy of at most N bytes of STRING.    In other words, return a copy of the initial segment of length N of    STRING.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrndup
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

end_unit

