begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Per-frame user registers, for GDB, the GNU debugger.     Copyright 2002, 2003 Free Software Foundation, Inc.     Contributed by Red Hat.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USER_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|USER_REGS_H
end_define

begin_comment
comment|/* Implement both builtin, and architecture specific, per-frame user    visible registers.     Builtin registers apply to all architectures, where as architecture    specific registers are present when the architecture is selected.     These registers are assigned register numbers outside the    architecture's register range [0 .. NUM_REGS + NUM_PSEUDO_REGS).    Their values should be constructed using per-frame information.  */
end_comment

begin_comment
comment|/* TODO: cagney/2003-06-27: Need to think more about how these    registers are added, read, and modified.  At present they are kind    of assumed to be read-only.  Should it, for instance, return a    register descriptor that contains all the relvent access methods.  */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_comment
comment|/* Given an architecture, map a user visible register name onto its    index.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|user_reg_map_name_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|user_reg_map_regnum_to_name
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the value of the frame register in the specified frame.     Note; These methods return a "struct value" instead of the raw    bytes as, at the time the register is being added, the type needed    to describe the register has not bee initialized.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|value
modifier|*
function_decl|(
name|user_reg_read_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|value
modifier|*
name|value_of_user_reg
parameter_list|(
name|int
name|regnum
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a builtin register (present in all architectures).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|user_reg_add_builtin
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|user_reg_read_ftype
modifier|*
name|read
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a per-architecture frame register.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|user_reg_add
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|user_reg_read_ftype
modifier|*
name|read
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

