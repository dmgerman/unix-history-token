begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALGOBASE_H
end_ifndef

begin_define
define|#
directive|define
name|ALGOBASE_H
end_define

begin_include
include|#
directive|include
file|<pair.h>
end_include

begin_include
include|#
directive|include
file|<iterator.h>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|ForwardIterator1
operator|,
name|class
name|ForwardIterator2
operator|,
name|class
name|T
operator|>
specifier|inline
name|void
name|__iter_swap
argument_list|(
argument|ForwardIterator1 a
argument_list|,
argument|ForwardIterator2 b
argument_list|,
argument|T*
argument_list|)
block|{
name|T
name|tmp
operator|=
operator|*
name|a
block|;
operator|*
name|a
operator|=
operator|*
name|b
block|;
operator|*
name|b
operator|=
name|tmp
block|; }
name|template
operator|<
name|class
name|ForwardIterator1
operator|,
name|class
name|ForwardIterator2
operator|>
specifier|inline
name|void
name|iter_swap
argument_list|(
argument|ForwardIterator1 a
argument_list|,
argument|ForwardIterator2 b
argument_list|)
block|{
name|__iter_swap
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|value_type
argument_list|(
name|a
argument_list|)
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|T& a
argument_list|,
argument|T& b
argument_list|)
block|{
name|T
name|tmp
operator|=
name|a
block|;
name|a
operator|=
name|b
block|;
name|b
operator|=
name|tmp
block|; }
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|min
argument_list|(
argument|const T& a
argument_list|,
argument|const T& b
argument_list|)
block|{
return|return
name|b
operator|<
name|a
operator|?
name|b
operator|:
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Compare
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|min
argument_list|(
argument|const T& a
argument_list|,
argument|const T& b
argument_list|,
argument|Compare comp
argument_list|)
block|{
return|return
name|comp
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
operator|?
name|b
operator|:
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|max
argument_list|(
argument|const T& a
argument_list|,
argument|const T& b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
operator|?
name|b
operator|:
name|a
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Compare
operator|>
specifier|inline
specifier|const
name|T
operator|&
name|max
argument_list|(
argument|const T& a
argument_list|,
argument|const T& b
argument_list|,
argument|Compare comp
argument_list|)
block|{
return|return
name|comp
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|?
name|b
operator|:
name|a
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
name|Distance
operator|>
name|void
name|__distance
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|Distance& n
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
operator|++
name|first
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Distance
operator|>
name|void
name|__distance
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|Distance& n
argument_list|,
argument|forward_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
operator|++
name|first
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BidirectionalIterator
operator|,
name|class
name|Distance
operator|>
name|void
name|__distance
argument_list|(
argument|BidirectionalIterator first
argument_list|,
argument|BidirectionalIterator last
argument_list|,
argument|Distance& n
argument_list|,
argument|bidirectional_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
operator|++
name|first
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Distance
operator|>
specifier|inline
name|void
name|__distance
argument_list|(
argument|RandomAccessIterator first
argument_list|,
argument|RandomAccessIterator last
argument_list|,
argument|Distance& n
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|n
operator|+=
name|last
operator|-
name|first
block|; }
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|Distance
operator|>
specifier|inline
name|void
name|distance
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|Distance& n
argument_list|)
block|{
name|__distance
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|n
argument_list|,
name|iterator_category
argument_list|(
name|first
argument_list|)
argument_list|)
block|; }
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|Distance
operator|>
name|void
name|__advance
argument_list|(
argument|InputIterator& i
argument_list|,
argument|Distance n
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|n
operator|--
condition|)
operator|++
name|i
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|Distance
operator|>
name|void
name|__advance
argument_list|(
argument|ForwardIterator& i
argument_list|,
argument|Distance n
argument_list|,
argument|forward_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|n
operator|--
condition|)
operator|++
name|i
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|BidirectionalIterator
operator|,
name|class
name|Distance
operator|>
name|void
name|__advance
argument_list|(
argument|BidirectionalIterator& i
argument_list|,
argument|Distance n
argument_list|,
argument|bidirectional_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|n
operator|>=
literal|0
condition|)
while|while
condition|(
name|n
operator|--
condition|)
operator|++
name|i
expr_stmt|;
else|else
while|while
condition|(
name|n
operator|++
condition|)
operator|--
name|i
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|RandomAccessIterator
operator|,
name|class
name|Distance
operator|>
specifier|inline
name|void
name|__advance
argument_list|(
argument|RandomAccessIterator& i
argument_list|,
argument|Distance n
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|i
operator|+=
name|n
block|; }
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|Distance
operator|>
specifier|inline
name|void
name|advance
argument_list|(
argument|InputIterator& i
argument_list|,
argument|Distance n
argument_list|)
block|{
name|__advance
argument_list|(
name|i
argument_list|,
name|n
argument_list|,
name|iterator_category
argument_list|(
name|i
argument_list|)
argument_list|)
block|; }
name|template
operator|<
name|class
name|ForwardIterator
operator|>
name|void
name|destroy
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
comment|/* Borland bug */
name|destroy
argument_list|(
operator|&
operator|*
name|first
argument_list|)
expr_stmt|;
operator|++
name|first
expr_stmt|;
comment|//destroy(&*first++);
block|}
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|ForwardIterator
operator|>
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
while|while
condition|(
name|first
operator|!=
name|last
condition|)
name|construct
argument_list|(
operator|&
operator|*
name|result
operator|++
argument_list|,
operator|*
name|first
operator|++
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
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
while|while
condition|(
name|first
operator|!=
name|last
condition|)
name|construct
argument_list|(
operator|&
operator|*
name|first
operator|++
argument_list|,
name|x
argument_list|)
expr_stmt|;
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
name|uninitialized_fill_n
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& x
argument_list|)
block|{
while|while
condition|(
name|n
operator|--
condition|)
name|construct
argument_list|(
operator|&
operator|*
name|first
operator|++
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|first
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|OutputIterator
operator|>
name|OutputIterator
name|copy
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
operator|*
name|result
operator|++
operator|=
operator|*
name|first
operator|++
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BidirectionalIterator1
operator|,
name|class
name|BidirectionalIterator2
operator|>
name|BidirectionalIterator2
name|copy_backward
argument_list|(
argument|BidirectionalIterator1 first
argument_list|,
argument|BidirectionalIterator1 last
argument_list|,
argument|BidirectionalIterator2 result
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
operator|*
operator|--
name|result
operator|=
operator|*
operator|--
name|last
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|,
name|class
name|T
operator|>
name|void
name|fill
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|const T& value
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
operator|*
name|first
operator|++
operator|=
name|value
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|OutputIterator
operator|,
name|class
name|Size
operator|,
name|class
name|T
operator|>
name|OutputIterator
name|fill_n
argument_list|(
argument|OutputIterator first
argument_list|,
argument|Size n
argument_list|,
argument|const T& value
argument_list|)
block|{
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
operator|*
name|first
operator|++
operator|=
name|value
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|first
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|>
name|pair
operator|<
name|InputIterator1
operator|,
name|InputIterator2
operator|>
name|mismatch
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|)
block|{
while|while
condition|(
name|first1
operator|!=
name|last1
operator|&&
operator|*
name|first1
operator|==
operator|*
name|first2
condition|)
block|{
operator|++
name|first1
expr_stmt|;
operator|++
name|first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|InputIterator1
operator|,
name|InputIterator2
operator|>
operator|(
name|first1
operator|,
name|first2
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|,
name|class
name|BinaryPredicate
operator|>
name|pair
operator|<
name|InputIterator1
operator|,
name|InputIterator2
operator|>
name|mismatch
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|BinaryPredicate binary_pred
argument_list|)
block|{
while|while
condition|(
name|first1
operator|!=
name|last1
operator|&&
name|binary_pred
argument_list|(
operator|*
name|first1
argument_list|,
operator|*
name|first2
argument_list|)
condition|)
block|{
operator|++
name|first1
expr_stmt|;
operator|++
name|first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|InputIterator1
operator|,
name|InputIterator2
operator|>
operator|(
name|first1
operator|,
name|first2
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|)
block|{
return|return
name|mismatch
argument_list|(
name|first1
argument_list|,
name|last1
argument_list|,
name|first2
argument_list|)
operator|.
name|first
operator|==
name|last1
return|;
block|}
end_expr_stmt

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
name|BinaryPredicate
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|BinaryPredicate binary_pred
argument_list|)
block|{
return|return
name|mismatch
argument_list|(
name|first1
argument_list|,
name|last1
argument_list|,
name|first2
argument_list|,
name|binary_pred
argument_list|)
operator|.
name|first
operator|==
name|last1
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|InputIterator2 last2
argument_list|)
block|{
while|while
condition|(
name|first1
operator|!=
name|last1
operator|&&
name|first2
operator|!=
name|last2
condition|)
block|{
if|if
condition|(
operator|*
name|first1
operator|<
operator|*
name|first2
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|*
name|first2
operator|++
operator|<
operator|*
name|first1
operator|++
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|first1
operator|==
name|last1
operator|&&
name|first2
operator|!=
name|last2
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator1
operator|,
name|class
name|InputIterator2
operator|,
name|class
name|Compare
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|InputIterator2 last2
argument_list|,
argument|Compare comp
argument_list|)
block|{
while|while
condition|(
name|first1
operator|!=
name|last1
operator|&&
name|first2
operator|!=
name|last2
condition|)
block|{
if|if
condition|(
name|comp
argument_list|(
operator|*
name|first1
argument_list|,
operator|*
name|first2
argument_list|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|comp
argument_list|(
operator|*
name|first2
operator|++
argument_list|,
operator|*
name|first1
operator|++
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|first1
operator|==
name|last1
operator|&&
name|first2
operator|!=
name|last2
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

