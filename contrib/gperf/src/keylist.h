begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data and function member declarations for the keyword list class.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The key word list is a useful abstraction that keeps track of    various pieces of information that enable that fast generation    of the Perfect.hash function.  A Key_List is a singly-linked    list of List_Nodes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_keylist_h
end_ifndef

begin_define
define|#
directive|define
name|_keylist_h
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"listnode.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|key_list
block|{
name|LIST_NODE
modifier|*
name|head
decl_stmt|;
comment|/* Points to the head of the linked list. */
name|char
modifier|*
name|array_type
decl_stmt|;
comment|/* Pointer to the type for word list. */
name|char
modifier|*
name|return_type
decl_stmt|;
comment|/* Pointer to return type for lookup function. */
name|char
modifier|*
name|struct_tag
decl_stmt|;
comment|/* Shorthand for user-defined struct tag type. */
name|char
modifier|*
name|include_src
decl_stmt|;
comment|/* C source code to be included verbatim. */
name|int
name|list_len
decl_stmt|;
comment|/* Length of head's Key_List, not counting duplicates. */
name|int
name|total_keys
decl_stmt|;
comment|/* Total number of keys, counting duplicates. */
name|int
name|max_key_len
decl_stmt|;
comment|/* Maximum length of the longest keyword. */
name|int
name|min_key_len
decl_stmt|;
comment|/* Minimum length of the shortest keyword. */
name|bool
name|occurrence_sort
decl_stmt|;
comment|/* True if sorting by occurrence. */
name|bool
name|hash_sort
decl_stmt|;
comment|/* True if sorting by hash value. */
name|bool
name|additional_code
decl_stmt|;
comment|/* True if any additional C code is included. */
block|}
name|KEY_LIST
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|key_list_init
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
name|key_list_destroy
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
name|print_output
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
name|keyword_list_length
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
name|max_key_length
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
name|KEY_LIST
name|key_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _keylist_h */
end_comment

end_unit

