begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Data and function members for defining values and operations of a list node.     Copyright (C) 1989-1998, 2000 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|list_node_h
end_ifndef

begin_define
define|#
directive|define
name|list_node_h
value|1
end_define

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
name|Vectors
block|{
name|List_Node
operator|*
name|link
block|;
comment|/* TRUE if key has an identical KEY_SET as another key. */
name|List_Node
operator|*
name|next
block|;
comment|/* Points to next element on the list. */
specifier|const
name|char
operator|*
name|key
block|;
comment|/* Each keyword string stored here. */
name|int
name|key_length
block|;
comment|/* Length of the key. */
specifier|const
name|char
operator|*
name|rest
block|;
comment|/* Additional information for building hash function. */
specifier|const
name|char
operator|*
name|char_set
block|;
comment|/* Set of characters to hash, specified by user. */
name|int
name|char_set_length
block|;
comment|/* Length of char_set. */
name|int
name|hash_value
block|;
comment|/* Hash value for the key. */
name|int
name|occurrence
block|;
comment|/* A metric for frequency of key set occurrences. */
name|int
name|index
block|;
comment|/* Position of this node relative to other nodes. */
name|List_Node
argument_list|(
argument|const char *key
argument_list|,
argument|int len
argument_list|,
argument|const char *rest
argument_list|)
block|;
specifier|static
name|void
name|set_sort
argument_list|(
argument|char *base
argument_list|,
argument|int len
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

