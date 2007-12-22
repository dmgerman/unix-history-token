begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Buffer primitives for comparison operations.     Copyright (C) 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_function_decl
name|size_t
name|block_read
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|buffer_lcm
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

