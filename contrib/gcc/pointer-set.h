begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set operations on pointers    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POINTER_SET_H
end_ifndef

begin_define
define|#
directive|define
name|POINTER_SET_H
end_define

begin_struct_decl
struct_decl|struct
name|pointer_set_t
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|pointer_set_t
modifier|*
name|pointer_set_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pointer_set_destroy
parameter_list|(
name|struct
name|pointer_set_t
modifier|*
name|pset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pointer_set_contains
parameter_list|(
name|struct
name|pointer_set_t
modifier|*
name|pset
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pointer_set_insert
parameter_list|(
name|struct
name|pointer_set_t
modifier|*
name|pset
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POINTER_SET_H  */
end_comment

end_unit

