begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Search algorithm.     Copyright (C) 1989-1998, 2000, 2002 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|search_h
end_ifndef

begin_define
define|#
directive|define
name|search_h
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

begin_include
include|#
directive|include
file|"bool-array.h"
end_include

begin_struct_decl
struct_decl|struct
name|EquivalenceClass
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|Search
block|{
name|public
label|:
name|Search
argument_list|(
name|KeywordExt_List
operator|*
name|list
argument_list|)
expr_stmt|;
operator|~
name|Search
argument_list|()
expr_stmt|;
name|void
name|optimize
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|prepare
parameter_list|()
function_decl|;
comment|/* Computes the upper bound on the indices passed to asso_values[],      assuming no alpha_increments.  */
name|unsigned
name|int
name|compute_alpha_size
argument_list|()
specifier|const
expr_stmt|;
comment|/* Computes the unification rules between different asso_values[c],      assuming no alpha_increments.  */
name|unsigned
name|int
operator|*
name|compute_alpha_unify
argument_list|()
specifier|const
expr_stmt|;
comment|/* Initializes each keyword's _selchars array.  */
name|void
name|init_selchars_tuple
argument_list|(
specifier|const
name|Positions
operator|&
name|positions
argument_list|,
specifier|const
name|unsigned
name|int
operator|*
name|alpha_unify
argument_list|)
decl|const
decl_stmt|;
comment|/* Deletes each keyword's _selchars array.  */
name|void
name|delete_selchars
argument_list|()
specifier|const
expr_stmt|;
comment|/* Count the duplicate keywords that occur with a given set of positions.  */
name|unsigned
name|int
name|count_duplicates_tuple
argument_list|(
specifier|const
name|Positions
operator|&
name|positions
argument_list|,
specifier|const
name|unsigned
name|int
operator|*
name|alpha_unify
argument_list|)
decl|const
decl_stmt|;
comment|/* Find good key positions.  */
name|void
name|find_positions
parameter_list|()
function_decl|;
comment|/* Count the duplicate keywords that occur with the found set of positions.  */
name|unsigned
name|int
name|count_duplicates_tuple
argument_list|()
specifier|const
expr_stmt|;
comment|/* Computes the upper bound on the indices passed to asso_values[].  */
name|unsigned
name|int
name|compute_alpha_size
argument_list|(
specifier|const
name|unsigned
name|int
operator|*
name|alpha_inc
argument_list|)
decl|const
decl_stmt|;
comment|/* Computes the unification rules between different asso_values[c].  */
name|unsigned
name|int
modifier|*
name|compute_alpha_unify
argument_list|(
specifier|const
name|Positions
operator|&
name|positions
argument_list|,
specifier|const
name|unsigned
name|int
operator|*
name|alpha_inc
argument_list|)
decl|const
decl_stmt|;
comment|/* Initializes each keyword's _selchars array.  */
name|void
name|init_selchars_multiset
argument_list|(
specifier|const
name|Positions
operator|&
name|positions
argument_list|,
specifier|const
name|unsigned
name|int
operator|*
name|alpha_unify
argument_list|,
specifier|const
name|unsigned
name|int
operator|*
name|alpha_inc
argument_list|)
decl|const
decl_stmt|;
comment|/* Count the duplicate keywords that occur with the given set of positions      and a given alpha_inc[] array.  */
name|unsigned
name|int
name|count_duplicates_multiset
argument_list|(
specifier|const
name|unsigned
name|int
operator|*
name|alpha_inc
argument_list|)
decl|const
decl_stmt|;
comment|/* Find good _alpha_inc[].  */
name|void
name|find_alpha_inc
parameter_list|()
function_decl|;
comment|/* Initializes the asso_values[] related parameters.  */
name|void
name|prepare_asso_values
parameter_list|()
function_decl|;
name|EquivalenceClass
modifier|*
name|compute_partition
argument_list|(
name|bool
operator|*
name|undetermined
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|int
name|count_possible_collisions
argument_list|(
name|EquivalenceClass
operator|*
name|partition
argument_list|,
name|unsigned
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
name|bool
name|unchanged_partition
argument_list|(
name|EquivalenceClass
operator|*
name|partition
argument_list|,
name|unsigned
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
comment|/* Finds some _asso_values[] that fit.  */
name|void
name|find_asso_values
parameter_list|()
function_decl|;
comment|/* Computes a keyword's hash value, relative to the current _asso_values[],      and stores it in keyword->_hash_value.  */
name|int
name|compute_hash
argument_list|(
name|KeywordExt
operator|*
name|keyword
argument_list|)
decl|const
decl_stmt|;
comment|/* Finds good _asso_values[].  */
name|void
name|find_good_asso_values
parameter_list|()
function_decl|;
comment|/* Sorts the keyword list by hash value.  */
name|void
name|sort
parameter_list|()
function_decl|;
name|public
label|:
comment|/* Linked list of keywords.  */
name|KeywordExt_List
modifier|*
name|_head
decl_stmt|;
comment|/* Total number of keywords, counting duplicates.  */
name|int
name|_total_keys
decl_stmt|;
comment|/* Maximum length of the longest keyword.  */
name|int
name|_max_key_len
decl_stmt|;
comment|/* Minimum length of the shortest keyword.  */
name|int
name|_min_key_len
decl_stmt|;
comment|/* User-specified or computed key positions.  */
name|Positions
name|_key_positions
decl_stmt|;
comment|/* Adjustments to add to bytes add specific key positions.  */
name|unsigned
name|int
modifier|*
name|_alpha_inc
decl_stmt|;
comment|/* Size of alphabet.  */
name|unsigned
name|int
name|_alpha_size
decl_stmt|;
comment|/* Alphabet character unification, either the identity or a mapping from      upper case characters to lower case characters (and maybe more).  */
name|unsigned
name|int
modifier|*
name|_alpha_unify
decl_stmt|;
comment|/* Maximum _selchars_length over all keywords.  */
name|unsigned
name|int
name|_max_selchars_length
decl_stmt|;
comment|/* Total number of duplicates that have been moved to _duplicate_link lists      (not counting their representatives which stay on the main list).  */
name|int
name|_total_duplicates
decl_stmt|;
comment|/* Counts occurrences of each key set character.      _occurrences[c] is the number of times that c occurs among the _selchars      of a keyword.  */
name|int
modifier|*
name|_occurrences
decl_stmt|;
comment|/* Value associated with each character. */
name|int
modifier|*
name|_asso_values
decl_stmt|;
name|private
label|:
comment|/* Length of _head list.  Number of keywords, not counting duplicates.  */
name|int
name|_list_len
decl_stmt|;
comment|/* Exclusive upper bound for every _asso_values[c].  A power of 2.  */
name|unsigned
name|int
name|_asso_value_max
decl_stmt|;
comment|/* Initial value for asso_values table.  -1 means random.  */
name|int
name|_initial_asso_value
decl_stmt|;
comment|/* Jump length when trying alternative values.  0 means random.  */
name|int
name|_jump
decl_stmt|;
comment|/* Maximal possible hash value.  */
name|int
name|_max_hash_value
decl_stmt|;
comment|/* Sparse bit vector for collision detection.  */
name|Bool_Array
modifier|*
name|_collision_detector
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

