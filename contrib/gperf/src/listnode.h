begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data and function members for defining values and operations of a list node.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_listnode_h
end_ifndef

begin_define
define|#
directive|define
name|_listnode_h
end_define

begin_include
include|#
directive|include
file|"prototype.h"
end_include

begin_define
define|#
directive|define
name|ALPHABET_SIZE
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|list_node
block|{
name|struct
name|list_node
modifier|*
name|link
decl_stmt|;
comment|/* TRUE if key has an identical KEY_SET as another key. */
name|struct
name|list_node
modifier|*
name|next
decl_stmt|;
comment|/* Points to next element on the list. */
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
name|char
modifier|*
name|key
decl_stmt|;
comment|/* Key string. */
name|char
modifier|*
name|rest
decl_stmt|;
comment|/* Additional information for building hash function. */
name|char
name|char_set
index|[
literal|1
index|]
decl_stmt|;
comment|/* Set of characters to hash, specified by user. */
block|}
name|LIST_NODE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|LIST_NODE
modifier|*
name|make_list_node
name|P
argument_list|(
operator|(
name|char
operator|*
name|k
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|_listnode_h
end_endif

end_unit

