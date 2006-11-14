begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Simple lookup table abstraction implemented as an Iteration Number Array.     Copyright (C) 1989-1998 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* Define and implement a simple boolean array abstraction,    uses an Iteration Numbering implementation to save on initialization time. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bool_array_h
end_ifndef

begin_define
define|#
directive|define
name|bool_array_h
value|1
end_define

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
name|unsigned
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
name|unsigned
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
name|unsigned
name|int
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_include
include|#
directive|include
file|"bool-array.icc"
end_include

begin_undef
undef|#
directive|undef
name|INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

