begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Hash table used to check for duplicate keyword entries.     Copyright (C) 1989-1998, 2000 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hash_table_h
end_ifndef

begin_define
define|#
directive|define
name|hash_table_h
value|1
end_define

begin_include
include|#
directive|include
file|"list-node.h"
end_include

begin_decl_stmt
name|class
name|Hash_Table
block|{
name|private
label|:
name|List_Node
modifier|*
modifier|*
name|table
decl_stmt|;
comment|/* Vector of pointers to linked lists of List_Node's. */
name|int
name|size
decl_stmt|;
comment|/* Size of the vector. */
name|int
name|collisions
decl_stmt|;
comment|/* Find out how well our double hashing is working! */
name|int
name|ignore_length
decl_stmt|;
name|public
label|:
name|Hash_Table
argument_list|(
argument|List_Node **t
argument_list|,
argument|int s
argument_list|,
argument|int ignore_len
argument_list|)
empty_stmt|;
operator|~
name|Hash_Table
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|List_Node
modifier|*
name|insert
parameter_list|(
name|List_Node
modifier|*
name|item
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

