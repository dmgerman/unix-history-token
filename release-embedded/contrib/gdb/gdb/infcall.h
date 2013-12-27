begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Perform an inferior function call, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFCALL_H
end_ifndef

begin_define
define|#
directive|define
name|INFCALL_H
end_define

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|find_function_addr
parameter_list|(
name|struct
name|value
modifier|*
name|function
parameter_list|,
name|struct
name|type
modifier|*
modifier|*
name|retval_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Perform a function call in the inferior.     ARGS is a vector of values of arguments (NARGS of them).  FUNCTION    is a value, the function to be called.  Returns a value    representing what the function returned.  May fail to return, if a    breakpoint or signal is hit during the execution of the function.     ARGS is modified to contain coerced values. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|value
modifier|*
name|call_function_by_hand
parameter_list|(
name|struct
name|value
modifier|*
name|function
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

