begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_ALGO_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_ALGO_H
end_define

begin_include
include|#
directive|include
file|<algobase.h>
end_include

begin_include
include|#
directive|include
file|<tempbuf.h>
end_include

begin_include
include|#
directive|include
file|<stl_algo.h>
end_include

begin_include
include|#
directive|include
file|<stl_numeric.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_NAMESPACES
end_ifdef

begin_comment
comment|// Names from<stl_algo.h>
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|for_each
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|find
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|find_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|adjacent_find
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|count
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|count_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|search
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|search_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|swap_ranges
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|transform
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|replace
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|replace_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|replace_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|replace_copy_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|generate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|generate_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|remove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|remove_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|remove_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|remove_copy_if
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|unique
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|unique_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|reverse
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|reverse_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|rotate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|rotate_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|random_shuffle
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|random_sample
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|random_sample_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|partition
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|stable_partition
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|stable_sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|partial_sort
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|partial_sort_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|nth_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|lower_bound
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|upper_bound
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|equal_range
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|binary_search
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|merge
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|inplace_merge
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|includes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|set_union
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|set_intersection
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|set_difference
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|set_symmetric_difference
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|min_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|max_element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|next_permutation
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|prev_permutation
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|find_first_of
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|find_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|is_sorted
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|is_heap
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_heap.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|push_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|pop_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|make_heap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|sort_heap
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from<stl_numeric.h>
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|accumulate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|inner_product
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|partial_sum
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|adjacent_difference
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|power
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|iota
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_USE_NAMESPACES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_ALGO_H */
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

