begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Hash table used to check for duplicate keyword entries.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

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
name|public
label|:
name|Hash_Table
argument_list|(
argument|List_Node **t
argument_list|,
argument|int s
argument_list|)
empty_stmt|;
operator|~
name|Hash_Table
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|List_Node
operator|*
name|operator
argument_list|()
operator|(
name|List_Node
operator|*
name|item
operator|,
name|int
name|ignore_length
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

