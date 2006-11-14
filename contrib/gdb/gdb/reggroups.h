begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register groupings for GDB, the GNU debugger.     Copyright 2002 Free Software Foundation, Inc.     Contributed by Red Hat.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGGROUPS_H
end_ifndef

begin_define
define|#
directive|define
name|REGGROUPS_H
end_define

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reggroup
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|reggroup_type
block|{
name|USER_REGGROUP
block|,
name|INTERNAL_REGGROUP
block|}
enum|;
end_enum

begin_comment
comment|/* Pre-defined, user visible, register groups.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|general_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|float_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|system_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|vector_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|all_reggroup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pre-defined, internal, register groups.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|save_reggroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reggroup
modifier|*
specifier|const
name|restore_reggroup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a new local register group.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|reggroup
modifier|*
name|reggroup_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|enum
name|reggroup_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a register group (with attribute values) to the pre-defined list.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|reggroup_add
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|reggroup
modifier|*
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register group attributes.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|reggroup_name
parameter_list|(
name|struct
name|reggroup
modifier|*
name|reggroup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|reggroup_type
name|reggroup_type
parameter_list|(
name|struct
name|reggroup
modifier|*
name|reggroup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interator for the architecture's register groups.  Pass in NULL,    returns the first group.  Pass in a group, returns the next group,    or NULL when the last group is reached.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|reggroup
modifier|*
name|reggroup_next
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|reggroup
modifier|*
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is REGNUM a member of REGGROUP?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|default_register_reggroup_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|reggroup
modifier|*
name|reggroup
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

