begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Backward-compat support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BACKWARD_ALGO_H
end_ifndef

begin_define
define|#
directive|define
name|_BACKWARD_ALGO_H
value|1
end_define

begin_include
include|#
directive|include
file|"backward_warning.h"
end_include

begin_include
include|#
directive|include
file|"algobase.h"
end_include

begin_include
include|#
directive|include
file|"tempbuf.h"
end_include

begin_include
include|#
directive|include
file|"iterator.h"
end_include

begin_include
include|#
directive|include
file|<bits/stl_algo.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_numeric.h>
end_include

begin_include
include|#
directive|include
file|<ext/algorithm>
end_include

begin_include
include|#
directive|include
file|<ext/numeric>
end_include

begin_comment
comment|// Names from<stl_algo.h>
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|for_each
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|find
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|find_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|adjacent_find
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|count
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|count_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|search
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|search_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|swap_ranges
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|transform
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|replace
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|replace_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|replace_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|replace_copy_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|generate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|generate_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|remove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|remove_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|remove_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|remove_copy_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|unique
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|unique_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|reverse
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|reverse_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|rotate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|rotate_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|random_shuffle
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|partition
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|stable_partition
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|stable_sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|partial_sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|partial_sort_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|nth_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|lower_bound
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|upper_bound
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|equal_range
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|binary_search
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|merge
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|inplace_merge
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|includes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|set_union
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|set_intersection
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|set_difference
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|set_symmetric_difference
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|min_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|max_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|next_permutation
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|prev_permutation
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|find_first_of
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|find_end
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_heap.h
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|push_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|pop_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|make_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|sort_heap
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_numeric.h
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|accumulate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|inner_product
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|partial_sum
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|adjacent_difference
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from ext/algorithm
end_comment

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|random_sample
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|random_sample_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|is_sorted
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|is_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|count
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Extension returning void
end_comment

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|count_if
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Extension returning void
end_comment

begin_comment
comment|// Names from ext/numeric
end_comment

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|power
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|iota
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BACKWARD_ALGO_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

