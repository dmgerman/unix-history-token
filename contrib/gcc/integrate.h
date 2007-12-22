begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Function integration definitions for GCC    Copyright (C) 1990, 1995, 1998, 1999, 2000, 2001, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_function_decl
specifier|extern
name|rtx
name|get_hard_reg_initial_val
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|has_hard_reg_initial_val
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If a pseudo represents an initial hard reg (or expression), return    it, else return NULL_RTX.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|get_hard_reg_initial_reg
parameter_list|(
name|struct
name|function
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Called from rest_of_compilation.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|emit_initial_value_sets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|allocate_initial_values
parameter_list|(
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check whether there's any attribute in a function declaration that    makes the function uninlinable.  Returns false if it finds any,    true otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|function_attribute_inlinable_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

end_unit

