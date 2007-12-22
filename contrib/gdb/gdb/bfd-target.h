begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Very simple "bfd" target, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|BFD_TARGET_H
end_define

begin_struct_decl
struct_decl|struct
name|bfd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Given an existing BFD, re-open it as a "struct target_ops".  On    close, it will also close the corresponding BFD (which is like    freopen and fdopen).  */
end_comment

begin_function_decl
name|struct
name|target_ops
modifier|*
name|target_bfd_reopen
parameter_list|(
name|struct
name|bfd
modifier|*
name|bfd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map over ABFD's sections, creating corresponding entries in the    target's section table.  */
end_comment

begin_function_decl
name|void
name|build_target_sections_from_bfd
parameter_list|(
name|struct
name|target_ops
modifier|*
name|targ
parameter_list|,
name|struct
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

