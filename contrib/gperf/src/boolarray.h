begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Simple lookup table abstraction implemented as a Guilmette Array.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define and implement a simple boolean array abstraction,    uses a Guilmette array implementation to save on initialization time. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_boolarray_h
end_ifndef

begin_define
define|#
directive|define
name|_boolarray_h
end_define

begin_include
include|#
directive|include
file|"prototype.h"
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

begin_typedef
typedef|typedef
struct|struct
name|bool_array
block|{
name|STORAGE_TYPE
modifier|*
name|storage_array
decl_stmt|;
comment|/* Initialization of the index space. */
name|STORAGE_TYPE
name|iteration_number
decl_stmt|;
comment|/* Keep track of the current iteration. */
name|int
name|size
decl_stmt|;
comment|/* Size of the entire array (dynamically initialized). */
block|}
name|BOOL_ARRAY
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|bool_array_init
name|P
argument_list|(
operator|(
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bool_array_destroy
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lookup
name|P
argument_list|(
operator|(
name|int
name|hash_value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bool_array_reset
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _boolarray_h */
end_comment

end_unit

