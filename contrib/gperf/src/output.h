begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Output routines.     Copyright (C) 1989-1998, 2000, 2002-2003 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|output_h
end_ifndef

begin_define
define|#
directive|define
name|output_h
value|1
end_define

begin_include
include|#
directive|include
file|"keyword-list.h"
end_include

begin_include
include|#
directive|include
file|"positions.h"
end_include

begin_comment
comment|/* OSF/1 cxx needs these forward declarations. */
end_comment

begin_struct_decl
struct_decl|struct
name|Output_Constants
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Output_Compare
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|Output
block|{
name|public
label|:
comment|/* Constructor.  */
name|Output
argument_list|(
argument|KeywordExt_List *head
argument_list|,
argument|const char *struct_decl
argument_list|,
argument|unsigned int struct_decl_lineno
argument_list|,
argument|const char *return_type
argument_list|,
argument|const char *struct_tag
argument_list|,
argument|const char *verbatim_declarations
argument_list|,
argument|const char *verbatim_declarations_end
argument_list|,
argument|unsigned int verbatim_declarations_lineno
argument_list|,
argument|const char *verbatim_code
argument_list|,
argument|const char *verbatim_code_end
argument_list|,
argument|unsigned int verbatim_code_lineno
argument_list|,
argument|bool charset_dependent
argument_list|,
argument|int total_keys
argument_list|,
argument|int max_key_len
argument_list|,
argument|int min_key_len
argument_list|,
argument|const Positions& positions
argument_list|,
argument|const unsigned int *alpha_inc
argument_list|,
argument|int total_duplicates
argument_list|,
argument|unsigned int alpha_size
argument_list|,
argument|const int *asso_values
argument_list|)
empty_stmt|;
comment|/* Generates the hash function and the key word recognizer function.  */
name|void
name|output
parameter_list|()
function_decl|;
name|private
label|:
comment|/* Computes the minimum and maximum hash values, and stores them      in _min_hash_value and _max_hash_value.  */
name|void
name|compute_min_max
parameter_list|()
function_decl|;
comment|/* Returns the number of different hash values.  */
name|int
name|num_hash_values
argument_list|()
specifier|const
expr_stmt|;
comment|/* Outputs the maximum and minimum hash values etc.  */
name|void
name|output_constants
argument_list|(
expr|struct
name|Output_Constants
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/* Generates a C expression for an asso_values[] reference.  */
name|void
name|output_asso_values_ref
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
comment|/* Generates C code for the hash function that returns the      proper encoding for each keyword.  */
name|void
name|output_hash_function
argument_list|()
specifier|const
expr_stmt|;
comment|/* Prints out a table of keyword lengths, for use with the      comparison code in generated function 'in_word_set'.  */
name|void
name|output_keylength_table
argument_list|()
specifier|const
expr_stmt|;
comment|/* Prints out the string pool, containing the strings of the keyword table.    */
name|void
name|output_string_pool
argument_list|()
specifier|const
expr_stmt|;
comment|/* Prints out the array containing the keywords for the hash function.  */
name|void
name|output_keyword_table
argument_list|()
specifier|const
expr_stmt|;
comment|/* Generates the large, sparse table that maps hash values into      the smaller, contiguous range of the keyword table.  */
name|void
name|output_lookup_array
argument_list|()
specifier|const
expr_stmt|;
comment|/* Generate all pools needed for the lookup function.  */
name|void
name|output_lookup_pools
argument_list|()
specifier|const
expr_stmt|;
comment|/* Generate all the tables needed for the lookup function.  */
name|void
name|output_lookup_tables
argument_list|()
specifier|const
expr_stmt|;
comment|/* Generates C code to perform the keyword lookup.  */
name|void
name|output_lookup_function_body
argument_list|(
specifier|const
expr|struct
name|Output_Compare
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/* Generates C code for the lookup function.  */
name|void
name|output_lookup_function
argument_list|()
specifier|const
expr_stmt|;
comment|/* Linked list of keywords.  */
name|KeywordExt_List
modifier|*
name|_head
decl_stmt|;
comment|/* Declaration of struct type for a keyword and its attributes.  */
specifier|const
name|char
modifier|*
specifier|const
name|_struct_decl
decl_stmt|;
name|unsigned
name|int
specifier|const
name|_struct_decl_lineno
decl_stmt|;
comment|/* Pointer to return type for lookup function. */
specifier|const
name|char
modifier|*
name|_return_type
decl_stmt|;
comment|/* Shorthand for user-defined struct tag type. */
specifier|const
name|char
modifier|*
name|_struct_tag
decl_stmt|;
comment|/* Element type of keyword array.  */
specifier|const
name|char
modifier|*
name|_wordlist_eltype
decl_stmt|;
comment|/* The C code from the declarations section.  */
specifier|const
name|char
modifier|*
specifier|const
name|_verbatim_declarations
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|_verbatim_declarations_end
decl_stmt|;
name|unsigned
name|int
specifier|const
name|_verbatim_declarations_lineno
decl_stmt|;
comment|/* The C code from the end of the file.  */
specifier|const
name|char
modifier|*
specifier|const
name|_verbatim_code
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|_verbatim_code_end
decl_stmt|;
name|unsigned
name|int
specifier|const
name|_verbatim_code_lineno
decl_stmt|;
comment|/* Whether the keyword chars would have different values in a different      character set.  */
name|bool
name|_charset_dependent
decl_stmt|;
comment|/* Total number of keys, counting duplicates. */
name|int
specifier|const
name|_total_keys
decl_stmt|;
comment|/* Maximum length of the longest keyword. */
name|int
specifier|const
name|_max_key_len
decl_stmt|;
comment|/* Minimum length of the shortest keyword. */
name|int
specifier|const
name|_min_key_len
decl_stmt|;
comment|/* Key positions.  */
name|Positions
specifier|const
name|_key_positions
decl_stmt|;
comment|/* Adjustments to add to bytes add specific key positions.  */
specifier|const
name|unsigned
name|int
modifier|*
specifier|const
name|_alpha_inc
decl_stmt|;
comment|/* Total number of duplicate hash values. */
name|int
specifier|const
name|_total_duplicates
decl_stmt|;
comment|/* Minimum hash value for all keywords. */
name|int
name|_min_hash_value
decl_stmt|;
comment|/* Maximum hash value for all keywords. */
name|int
name|_max_hash_value
decl_stmt|;
comment|/* Size of alphabet. */
name|unsigned
name|int
specifier|const
name|_alpha_size
decl_stmt|;
comment|/* Value associated with each character. */
specifier|const
name|int
modifier|*
specifier|const
name|_asso_values
decl_stmt|;
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

