begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_UNINITIALIZED_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_UNINITIALIZED_H
end_define

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
comment|// Valid if copy construction is equivalent to assignment, and if the
comment|//  destructor is trivial.
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_copy_aux
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|ForwardIterator result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|copy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|>
name|ForwardIterator
name|__uninitialized_copy_aux
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|ForwardIterator result
argument_list|,
argument|__false_type
argument_list|)
block|{
name|ForwardIterator
name|cur
operator|=
name|result
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
operator|,
operator|++
name|cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|cur
argument_list|,
operator|*
name|first
argument_list|)
expr_stmt|;
return|return
name|cur
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|result
argument_list|,
name|cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}   template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_copy
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|ForwardIterator result
argument_list|,
argument|T*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|T
operator|>
operator|::
name|is_POD_type
name|is_POD
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__uninitialized_copy_aux
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|>
specifier|inline
name|ForwardIterator
name|uninitialized_copy
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|ForwardIterator result
argument_list|)
block|{
return|return
name|__uninitialized_copy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|value_type
argument_list|(
name|result
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|char
modifier|*
name|uninitialized_copy
parameter_list|(
specifier|const
name|char
modifier|*
name|first
parameter_list|,
specifier|const
name|char
modifier|*
name|last
parameter_list|,
name|char
modifier|*
name|result
parameter_list|)
block|{
name|memmove
argument_list|(
name|result
argument_list|,
name|first
argument_list|,
name|last
operator|-
name|first
argument_list|)
expr_stmt|;
return|return
name|result
operator|+
operator|(
name|last
operator|-
name|first
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|wchar_t
modifier|*
name|uninitialized_copy
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|first
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|last
parameter_list|,
name|wchar_t
modifier|*
name|result
parameter_list|)
block|{
name|memmove
argument_list|(
name|result
argument_list|,
name|first
argument_list|,
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
operator|(
name|last
operator|-
name|first
operator|)
argument_list|)
expr_stmt|;
return|return
name|result
operator|+
operator|(
name|last
operator|-
name|first
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|Size
operator|,
name|class
name|ForwardIterator
operator|>
name|pair
operator|<
name|InputIterator
operator|,
name|ForwardIterator
operator|>
name|__uninitialized_copy_n
argument_list|(
argument|InputIterator first
argument_list|,
argument|Size count
argument_list|,
argument|ForwardIterator result
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
name|ForwardIterator
name|cur
operator|=
name|result
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|count
operator|>
literal|0
condition|;
operator|--
name|count
operator|,
operator|++
name|first
operator|,
operator|++
name|cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|cur
argument_list|,
operator|*
name|first
argument_list|)
expr_stmt|;
return|return
name|pair
operator|<
name|InputIterator
operator|,
name|ForwardIterator
operator|>
operator|(
name|first
operator|,
name|cur
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|result
argument_list|,
name|cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Size
operator|,
name|class
name|ForwardIterator
operator|>
specifier|inline
name|pair
operator|<
name|RandomAccessIterator
operator|,
name|ForwardIterator
operator|>
name|__uninitialized_copy_n
argument_list|(
argument|RandomAccessIterator first
argument_list|,
argument|Size count
argument_list|,
argument|ForwardIterator result
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|RandomAccessIterator
name|last
operator|=
name|first
operator|+
name|count
block|;
return|return
name|make_pair
argument_list|(
name|last
argument_list|,
name|uninitialized_copy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|Size
operator|,
name|class
name|ForwardIterator
operator|>
specifier|inline
name|pair
operator|<
name|InputIterator
operator|,
name|ForwardIterator
operator|>
name|uninitialized_copy_n
argument_list|(
argument|InputIterator first
argument_list|,
argument|Size count
argument_list|,
argument|ForwardIterator result
argument_list|)
block|{
return|return
name|__uninitialized_copy_n
argument_list|(
name|first
argument_list|,
name|count
argument_list|,
name|result
argument_list|,
name|iterator_category
argument_list|(
name|first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Valid if copy construction is equivalent to assignment, and if the
end_comment

begin_comment
comment|//  destructor is trivial.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
specifier|inline
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|const T& x
argument_list|,
argument|__true_type
argument_list|)
block|{
name|fill
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|x
argument_list|)
block|; }
name|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|const T& x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|ForwardIterator
name|cur
operator|=
name|first
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|cur
operator|!=
name|last
condition|;
operator|++
name|cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|cur
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|first
argument_list|,
name|cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|,
name|class
name|T1
operator|>
specifier|inline
name|void
name|__uninitialized_fill
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|const T& x
argument_list|,
argument|T1*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|T1
operator|>
operator|::
name|is_POD_type
name|is_POD
expr_stmt|;
name|__uninitialized_fill_aux
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|x
argument_list|,
name|is_POD
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
specifier|inline
name|void
name|uninitialized_fill
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|const T& x
argument_list|)
block|{
name|__uninitialized_fill
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|x
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
argument_list|)
block|; }
comment|// Valid if copy construction is equivalent to assignment, and if the
comment|//  destructor is trivial.
name|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Size
operator|,
name|class
name|T
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_fill_n_aux
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& x
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|fill_n
argument_list|(
name|first
argument_list|,
name|n
argument_list|,
name|x
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Size
operator|,
name|class
name|T
operator|>
name|ForwardIterator
name|__uninitialized_fill_n_aux
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|ForwardIterator
name|cur
operator|=
name|first
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|n
operator|>
literal|0
condition|;
operator|--
name|n
operator|,
operator|++
name|cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|cur
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|cur
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|first
argument_list|,
name|cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Size
operator|,
name|class
name|T
operator|,
name|class
name|T1
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_fill_n
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& x
argument_list|,
argument|T1*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|T1
operator|>
operator|::
name|is_POD_type
name|is_POD
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__uninitialized_fill_n_aux
argument_list|(
name|first
argument_list|,
name|n
argument_list|,
name|x
argument_list|,
name|is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Size
operator|,
name|class
name|T
operator|>
specifier|inline
name|ForwardIterator
name|uninitialized_fill_n
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& x
argument_list|)
block|{
return|return
name|__uninitialized_fill_n
argument_list|(
name|first
argument_list|,
name|n
argument_list|,
name|x
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Copies [first1, last1) into [result, result + (last1 - first1)), and
end_comment

begin_comment
comment|//  copies [first2, last2) into
end_comment

begin_comment
comment|//  [result, result + (last1 - first1) + (last2 - first2)).
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|,
name|class
name|ForwardIterator
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_copy_copy
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|InputIterator2 last2
argument_list|,
argument|ForwardIterator result
argument_list|)
block|{
name|ForwardIterator
name|mid
operator|=
name|uninitialized_copy
argument_list|(
name|first1
argument_list|,
name|last1
argument_list|,
name|result
argument_list|)
block|;
name|__STL_TRY
block|{
return|return
name|uninitialized_copy
argument_list|(
name|first2
argument_list|,
name|last2
argument_list|,
name|mid
argument_list|)
return|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|result
argument_list|,
name|mid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Fills [result, mid) with x, and copies [first, last) into
end_comment

begin_comment
comment|//  [mid, mid + (last - first)).
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|,
name|class
name|InputIterator
operator|>
specifier|inline
name|ForwardIterator
name|__uninitialized_fill_copy
argument_list|(
argument|ForwardIterator result
argument_list|,
argument|ForwardIterator mid
argument_list|,
argument|const T& x
argument_list|,
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|)
block|{
name|uninitialized_fill
argument_list|(
name|result
argument_list|,
name|mid
argument_list|,
name|x
argument_list|)
block|;
name|__STL_TRY
block|{
return|return
name|uninitialized_copy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|mid
argument_list|)
return|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|result
argument_list|,
name|mid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Copies [first1, last1) into [first2, first2 + (last1 - first1)), and
end_comment

begin_comment
comment|//  fills [first2 + (last1 - first1), last2) with x.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
specifier|inline
name|void
name|__uninitialized_copy_fill
argument_list|(
argument|InputIterator first1
argument_list|,
argument|InputIterator last1
argument_list|,
argument|ForwardIterator first2
argument_list|,
argument|ForwardIterator last2
argument_list|,
argument|const T& x
argument_list|)
block|{
name|ForwardIterator
name|mid2
operator|=
name|uninitialized_copy
argument_list|(
name|first1
argument_list|,
name|last1
argument_list|,
name|first2
argument_list|)
block|;
name|__STL_TRY
block|{
name|uninitialized_fill
argument_list|(
name|mid2
argument_list|,
name|last2
argument_list|,
name|x
argument_list|)
block|;   }
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|first2
argument_list|,
name|mid2
argument_list|)
argument_list|)
block|; }
name|__STL_END_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_UNINITIALIZED_H */
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

