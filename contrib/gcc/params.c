begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* params.c - Run-time parameters.    Copyright (C) 2001 Free Software Foundation, Inc.    Written by Mark Mitchell<mark@codesourcery.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_comment
comment|/* An array containing the compiler parameters and their current    values.  */
end_comment

begin_decl_stmt
name|param_info
modifier|*
name|compiler_params
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of entries in the table.  */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|num_compiler_params
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add the N PARAMS to the current list of compiler parameters.  */
end_comment

begin_function
name|void
name|add_params
parameter_list|(
name|params
parameter_list|,
name|n
parameter_list|)
specifier|const
name|param_info
name|params
index|[]
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
comment|/* Allocate enough space for the new parameters.  */
name|compiler_params
operator|=
operator|(
operator|(
name|param_info
operator|*
operator|)
name|xrealloc
argument_list|(
name|compiler_params
argument_list|,
operator|(
name|num_compiler_params
operator|+
name|n
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|param_info
argument_list|)
argument_list|)
operator|)
expr_stmt|;
comment|/* Copy them into the table.  */
name|memcpy
argument_list|(
name|compiler_params
operator|+
name|num_compiler_params
argument_list|,
name|params
argument_list|,
name|n
operator|*
sizeof|sizeof
argument_list|(
name|param_info
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Keep track of how many parameters we have.  */
name|num_compiler_params
operator|+=
name|n
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set the VALUE associated with the parameter given by NAME.  */
end_comment

begin_function
name|void
name|set_param_value
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
block|{
name|size_t
name|i
decl_stmt|;
comment|/* Make sure nobody tries to set a parameter to an invalid value.  */
if|if
condition|(
name|value
operator|==
name|INVALID_PARAM_VAL
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* Scan the parameter table to find a matching entry.  */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_compiler_params
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|compiler_params
index|[
name|i
index|]
operator|.
name|option
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
name|compiler_params
index|[
name|i
index|]
operator|.
name|value
operator|=
name|value
expr_stmt|;
return|return;
block|}
comment|/* If we didn't find this parameter, issue an error message.  */
name|error
argument_list|(
literal|"invalid parameter `%s'"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

