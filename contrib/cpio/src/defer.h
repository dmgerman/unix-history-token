begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* defer.h    Copyright (C) 1993, 2001, 2004, 2006 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with this program; if not, write to the Free    Software Foundation, Inc., 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301 USA.  */
end_comment

begin_struct
struct|struct
name|deferment
block|{
name|struct
name|deferment
modifier|*
name|next
decl_stmt|;
name|struct
name|cpio_file_stat
name|header
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|deferment
modifier|*
name|create_deferment
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_deferment
parameter_list|(
name|struct
name|deferment
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

end_unit

