begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Data and function member declarations for the keyword list class.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The key word list is a useful abstraction that keeps track of    various pieces of information that enable that fast generation    of the Gen_Perf.hash function.  A Key_List is a singly-linked    list of List_Nodes. */
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

begin_include
include|#
directive|include
file|"read-line.h"
end_include

begin_decl_stmt
name|class
name|Key_List
range|:
name|private
name|Std_Err
decl_stmt|,
name|private
name|Read_Line
decl_stmt|,
name|public
name|Vectors
block|{
name|private
label|:
specifier|const
name|int
name|MAX_INT
init|=
operator|~
name|unsigned
argument_list|(
literal|0
argument_list|)
operator|>>
literal|1
decl_stmt|;
comment|/* Most positive integer value. */
specifier|const
name|int
name|MIN_INT
init|=
operator|~
name|unsigned
argument_list|(
literal|0
argument_list|)
operator|^
name|MAX_INT
decl_stmt|;
comment|/* Most negative integer value. */
specifier|const
name|int
name|MAX_SIGNED_CHAR
init|=
literal|127
decl_stmt|;
comment|/* Maximum value a signed char can take. */
specifier|const
name|int
name|MAX_UNSIGNED_CHAR
init|=
literal|255
decl_stmt|;
comment|/* Maximum value an unsigned char can take. */
specifier|const
name|int
name|MAX_UNSIGNED_SHORT
init|=
literal|65535
decl_stmt|;
comment|/* Maximum value an unsigned short can take. */
specifier|const
name|int
name|MAX_SIGNED_SHORT
init|=
literal|32767
decl_stmt|;
comment|/* Maximum value a signed short can take. */
specifier|const
name|int
name|MIN_SIGNED_SHORT
init|=
operator|-
literal|32768
decl_stmt|;
comment|/* Minimum value a signed short can take. */
specifier|const
name|int
name|TABLE_MULTIPLE
init|=
literal|10
decl_stmt|;
comment|/* Make the hash table 8 times larger than the number of keyword entries. */
name|char
modifier|*
specifier|const
name|default_array_type
init|=
literal|"char *"
decl_stmt|;
comment|/* Default type for generated code. */
name|char
modifier|*
specifier|const
name|default_return_type
init|=
literal|"char *"
decl_stmt|;
comment|/* in_word_set return type, by default. */
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
name|max_key_len
decl_stmt|;
comment|/* Maximum length of the longest keyword. */
name|int
name|min_key_len
decl_stmt|;
comment|/* Minimum length of the shortest keyword. */
name|int
name|min_hash_value
decl_stmt|;
comment|/* Minimum hash value for all keywords. */
name|int
name|max_hash_value
decl_stmt|;
comment|/* Maximum hash value for all keywords. */
name|int
name|occurrence_sort
decl_stmt|;
comment|/* True if sorting by occurrence. */
name|int
name|hash_sort
decl_stmt|;
comment|/* True if sorting by hash value. */
name|int
name|additional_code
decl_stmt|;
comment|/* True if any additional C code is included. */
name|int
name|list_len
decl_stmt|;
comment|/* Length of head's Key_List, not counting duplicates. */
name|int
name|total_keys
decl_stmt|;
comment|/* Total number of keys, counting duplicates. */
specifier|static
name|int
name|determined
index|[
name|ALPHA_SIZE
index|]
decl_stmt|;
comment|/* Used in function reorder, below. */
specifier|static
name|int
name|get_occurrence
parameter_list|(
name|List_Node
modifier|*
name|ptr
parameter_list|)
function_decl|;
specifier|static
name|int
name|strcspn
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|reject
parameter_list|)
function_decl|;
specifier|static
name|int
name|already_determined
parameter_list|(
name|List_Node
modifier|*
name|ptr
parameter_list|)
function_decl|;
specifier|static
name|void
name|set_determined
parameter_list|(
name|List_Node
modifier|*
name|ptr
parameter_list|)
function_decl|;
name|void
name|output_min_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_keyword_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_keylength_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_hash_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_lookup_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output_lookup_array
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|set_output_types
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|char
modifier|*
name|get_array_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|char
modifier|*
name|save_include_src
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|char
modifier|*
name|get_special_input
parameter_list|(
name|char
name|delimiter
parameter_list|)
function_decl|;
name|List_Node
modifier|*
name|merge
parameter_list|(
name|List_Node
modifier|*
name|list1
parameter_list|,
name|List_Node
modifier|*
name|list2
parameter_list|)
function_decl|;
name|List_Node
modifier|*
name|merge_sort
parameter_list|(
name|List_Node
modifier|*
name|head
parameter_list|)
function_decl|;
name|protected
label|:
name|List_Node
modifier|*
name|head
decl_stmt|;
comment|/* Points to the head of the linked list. */
name|int
name|total_duplicates
decl_stmt|;
comment|/* Total number of duplicate hash values. */
name|public
label|:
name|Key_List
argument_list|(
name|void
argument_list|)
expr_stmt|;
operator|~
name|Key_List
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|int
name|keyword_list_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|max_key_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|reorder
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|sort
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|read_keys
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|output
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

