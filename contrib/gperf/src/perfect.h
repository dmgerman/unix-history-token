begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Provides high-level routines to manipulate the keyword list    structures the code generation output.      Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_perfect_h
end_ifndef

begin_define
define|#
directive|define
name|_perfect_h
end_define

begin_include
include|#
directive|include
file|"prototype.h"
end_include

begin_include
include|#
directive|include
file|"keylist.h"
end_include

begin_include
include|#
directive|include
file|"boolarray.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|perfect
block|{
name|KEY_LIST
name|list
decl_stmt|;
comment|/* List of key words provided by the user. */
name|BOOL_ARRAY
name|duplicate
decl_stmt|;
comment|/* Speeds up check for redundant hash values. */
name|int
name|max_hash_value
decl_stmt|;
comment|/* Maximum possible hash value. */
name|int
name|fewest_collisions
decl_stmt|;
comment|/* Records fewest # of collisions for asso value. */
name|int
name|num_done
decl_stmt|;
comment|/* Number of keywords processed without a collision. */
block|}
name|PERFECT
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|perfect_init
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
name|void
name|perfect_destroy
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
name|int
name|perfect_generate
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
name|void
name|perfect_print
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
comment|/* _perfect_h */
end_comment

end_unit

