begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Simple lookup table abstraction implemented as an Iteration Number Array.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define and implement a simple boolean array abstraction,    uses an Iteration Numbering implementation to save on initialization time. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LO_CAL
end_ifdef

begin_comment
comment|/* If we are on a memory diet then we'll only make these use a limited    amount of storage space. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|STORAGE_TYPE
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|STORAGE_TYPE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|Bool_Array
block|{
name|private
label|:
specifier|static
name|STORAGE_TYPE
modifier|*
name|storage_array
decl_stmt|;
comment|/* Initialization of the index space. */
specifier|static
name|STORAGE_TYPE
name|iteration_number
decl_stmt|;
comment|/* Keep track of the current iteration. */
specifier|static
name|int
name|size
decl_stmt|;
comment|/* Keep track of array size. */
name|public
label|:
name|Bool_Array
argument_list|(
name|void
argument_list|)
expr_stmt|;
operator|~
name|Bool_Array
argument_list|(
name|void
argument_list|)
expr_stmt|;
specifier|static
name|void
name|init
parameter_list|(
name|STORAGE_TYPE
modifier|*
name|buffer
parameter_list|,
name|STORAGE_TYPE
name|s
parameter_list|)
function_decl|;
specifier|static
name|int
name|find
parameter_list|(
name|int
name|hash_value
parameter_list|)
function_decl|;
specifier|static
name|void
name|reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_comment
comment|/* efficiency hack! */
end_comment

begin_expr_stmt
specifier|inline
name|Bool_Array
operator|::
name|Bool_Array
argument_list|(
argument|void
argument_list|)
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Bool_Array::Bool_Array"
argument|);
argument_list|)
name|storage_array
operator|=
literal|0
block|;
name|iteration_number
operator|=
name|size
operator|=
literal|0
block|; }
specifier|inline
name|void
name|Bool_Array
operator|::
name|init
argument_list|(
argument|STORAGE_TYPE *buffer
argument_list|,
argument|STORAGE_TYPE s
argument_list|)
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Bool_Array::init"
argument|);
argument_list|)
name|size
operator|=
name|s
block|;
name|iteration_number
operator|=
literal|1
block|;
name|storage_array
operator|=
name|buffer
block|;
name|bzero
argument_list|(
name|storage_array
argument_list|,
name|s
operator|*
sizeof|sizeof
expr|*
name|storage_array
argument_list|)
block|;
if|if
condition|(
name|option
index|[
name|DEBUG
index|]
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nbool array size = %d, total bytes = %d\n"
argument_list|,
name|size
argument_list|,
name|size
operator|*
sizeof|sizeof
expr|*
name|storage_array
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Bool_Array
operator|::
name|find
argument_list|(
argument|int index
argument_list|)
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Bool_Array::find"
argument|);
argument_list|)
if|if
condition|(
name|storage_array
index|[
name|index
index|]
operator|==
name|iteration_number
condition|)
return|return
literal|1
return|;
else|else
block|{
name|storage_array
index|[
name|index
index|]
operator|=
name|iteration_number
expr_stmt|;
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  inline
name|void
name|Bool_Array
operator|::
name|reset
argument_list|(
argument|void
argument_list|)
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Bool_Array::reset"
argument|);
argument_list|)
if|if
condition|(
operator|++
name|iteration_number
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|option
index|[
name|DEBUG
index|]
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"(re-initializing bool_array)..."
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
block|}
name|iteration_number
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bzero
argument_list|(
name|storage_array
argument_list|,
name|size
operator|*
sizeof|sizeof
expr|*
name|storage_array
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|option
index|[
name|DEBUG
index|]
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"done\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
block|}
end_if

begin_endif
unit|} }
endif|#
directive|endif
end_endif

end_unit

