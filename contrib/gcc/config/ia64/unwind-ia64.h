begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Andrew MacLeod<amacleod@cygnus.com>                   Andrew Haley<aph@cygnus.com>     This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct
struct|struct
name|unw_table_entry
block|{
name|unsigned
name|long
name|start_offset
decl_stmt|;
name|unsigned
name|long
name|end_offset
decl_stmt|;
name|unsigned
name|long
name|info_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|unw_table_entry
modifier|*
name|_Unwind_FindTableEntry
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|,
name|unsigned
name|long
modifier|*
name|segment_base
parameter_list|,
name|unsigned
name|long
modifier|*
name|gp
parameter_list|)
function_decl|;
end_function_decl

end_unit

