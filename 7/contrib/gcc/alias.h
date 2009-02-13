begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Exported functions from alias.c    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_ALIAS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_ALIAS_H
end_define

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|new_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_varargs_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_frame_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|component_uses_parent_alias_set
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This alias set can be used to force a memory to conflict with all    other memories, creating a barrier across which no memory reference    can move.  Note that there are other legacy ways to create such    memory barriers, including an address of SCRATCH.  */
end_comment

begin_define
define|#
directive|define
name|ALIAS_SET_MEMORY_BARRIER
value|((HOST_WIDE_INT) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_ALIAS_H */
end_comment

end_unit

