begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sdbout.h - Various declarations for functions found in sdbout.c    Copyright (C) 1998, 2000, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sdbout_symbol
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sdbout_types
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

end_unit

