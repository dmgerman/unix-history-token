begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Data and function members for defining values and operations of a list node.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"std-err.h"
end_include

begin_include
include|#
directive|include
file|"vectors.h"
end_include

begin_decl_stmt
name|struct
name|List_Node
range|:
name|private
name|Std_Err
decl_stmt|,
name|private
name|Vectors
block|{
name|List_Node
modifier|*
name|link
decl_stmt|;
comment|/* TRUE if key has an identical KEY_SET as another key. */
name|List_Node
modifier|*
name|next
decl_stmt|;
comment|/* Points to next element on the list. */
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Each keyword string stored here. */
name|char
modifier|*
name|rest
decl_stmt|;
comment|/* Additional information for building hash function. */
name|char
modifier|*
name|char_set
decl_stmt|;
comment|/* Set of characters to hash, specified by user. */
name|int
name|length
decl_stmt|;
comment|/* Length of the key. */
name|int
name|hash_value
decl_stmt|;
comment|/* Hash value for the key. */
name|int
name|occurrence
decl_stmt|;
comment|/* A metric for frequency of key set occurrences. */
name|int
name|index
decl_stmt|;
comment|/* Position of this node relative to other nodes. */
name|List_Node
argument_list|(
argument|char *key
argument_list|,
argument|int len
argument_list|)
empty_stmt|;
specifier|static
name|void
name|set_sort
parameter_list|(
name|char
modifier|*
name|base
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

