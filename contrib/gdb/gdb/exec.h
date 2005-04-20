begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Work with executable files, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXEC_H
end_ifndef

begin_define
define|#
directive|define
name|EXEC_H
end_define

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_struct_decl
struct_decl|struct
name|section_table
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bfd
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
name|exec_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Builds a section table, given args BFD, SECTABLE_PTR, SECEND_PTR.    Returns 0 if OK, 1 on error.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|build_section_table
parameter_list|(
name|struct
name|bfd
modifier|*
parameter_list|,
name|struct
name|section_table
modifier|*
modifier|*
parameter_list|,
name|struct
name|section_table
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

