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
name|__SGI_STL_INTERNAL_NUMERIC_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_NUMERIC_H
end_define

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|T
operator|>
name|T
name|accumulate
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|T init
argument_list|)
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
control|)
name|init
operator|=
name|init
operator|+
operator|*
name|first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|init
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|InputIterator
operator|,
name|class
name|T
operator|,
name|class
name|BinaryOperation
operator|>
name|T
name|accumulate
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|T init
argument_list|,
argument|BinaryOperation binary_op
argument_list|)
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
control|)
name|init
operator|=
name|binary_op
argument_list|(
name|init
argument_list|,
operator|*
name|first
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|init
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
name|T
operator|>
name|T
name|inner_product
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|T init
argument_list|)
block|{
for|for
control|(
init|;
name|first1
operator|!=
name|last1
condition|;
operator|++
name|first1
operator|,
operator|++
name|first2
control|)
name|init
operator|=
name|init
operator|+
operator|(
operator|*
name|first1
operator|*
operator|*
name|first2
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|init
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
name|T
operator|,
name|class
name|BinaryOperation1
operator|,
name|class
name|BinaryOperation2
operator|>
name|T
name|inner_product
argument_list|(
argument|InputIterator1 first1
argument_list|,
argument|InputIterator1 last1
argument_list|,
argument|InputIterator2 first2
argument_list|,
argument|T init
argument_list|,
argument|BinaryOperation1 binary_op1
argument_list|,
argument|BinaryOperation2 binary_op2
argument_list|)
block|{
for|for
control|(
init|;
name|first1
operator|!=
name|last1
condition|;
operator|++
name|first1
operator|,
operator|++
name|first2
control|)
name|init
operator|=
name|binary_op1
argument_list|(
name|init
argument_list|,
name|binary_op2
argument_list|(
operator|*
name|first1
argument_list|,
operator|*
name|first2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|init
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
operator|,
name|class
name|T
operator|>
name|OutputIterator
name|__partial_sum
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|T*
argument_list|)
block|{
name|T
name|value
operator|=
operator|*
name|first
block|;
while|while
condition|(
operator|++
name|first
operator|!=
name|last
condition|)
block|{
name|value
operator|=
name|value
operator|+
operator|*
name|first
expr_stmt|;
operator|*
operator|++
name|result
operator|=
name|value
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|result
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
name|partial_sum
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return
name|result
return|;
operator|*
name|result
operator|=
operator|*
name|first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__partial_sum
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
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
name|OutputIterator
operator|,
name|class
name|T
operator|,
name|class
name|BinaryOperation
operator|>
name|OutputIterator
name|__partial_sum
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|T*
argument_list|,
argument|BinaryOperation binary_op
argument_list|)
block|{
name|T
name|value
operator|=
operator|*
name|first
block|;
while|while
condition|(
operator|++
name|first
operator|!=
name|last
condition|)
block|{
name|value
operator|=
name|binary_op
argument_list|(
name|value
argument_list|,
operator|*
name|first
argument_list|)
expr_stmt|;
operator|*
operator|++
name|result
operator|=
name|value
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|result
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
operator|,
name|class
name|BinaryOperation
operator|>
name|OutputIterator
name|partial_sum
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|BinaryOperation binary_op
argument_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return
name|result
return|;
operator|*
name|result
operator|=
operator|*
name|first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__partial_sum
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
argument_list|,
name|binary_op
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
name|OutputIterator
operator|,
name|class
name|T
operator|>
name|OutputIterator
name|__adjacent_difference
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|T*
argument_list|)
block|{
name|T
name|value
operator|=
operator|*
name|first
block|;
while|while
condition|(
operator|++
name|first
operator|!=
name|last
condition|)
block|{
name|T
name|tmp
init|=
operator|*
name|first
decl_stmt|;
operator|*
operator|++
name|result
operator|=
name|tmp
operator|-
name|value
expr_stmt|;
name|value
operator|=
name|tmp
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|result
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
name|adjacent_difference
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return
name|result
return|;
operator|*
name|result
operator|=
operator|*
name|first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__adjacent_difference
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
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
name|OutputIterator
operator|,
name|class
name|T
operator|,
name|class
name|BinaryOperation
operator|>
name|OutputIterator
name|__adjacent_difference
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|T*
argument_list|,
argument|BinaryOperation binary_op
argument_list|)
block|{
name|T
name|value
operator|=
operator|*
name|first
block|;
while|while
condition|(
operator|++
name|first
operator|!=
name|last
condition|)
block|{
name|T
name|tmp
init|=
operator|*
name|first
decl_stmt|;
operator|*
operator|++
name|result
operator|=
name|binary_op
argument_list|(
name|tmp
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|value
operator|=
name|tmp
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|result
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
operator|,
name|class
name|BinaryOperation
operator|>
name|OutputIterator
name|adjacent_difference
argument_list|(
argument|InputIterator first
argument_list|,
argument|InputIterator last
argument_list|,
argument|OutputIterator result
argument_list|,
argument|BinaryOperation binary_op
argument_list|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
return|return
name|result
return|;
operator|*
name|result
operator|=
operator|*
name|first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__adjacent_difference
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|result
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
argument_list|,
name|binary_op
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// Returns x ** n, where n>= 0.  Note that "multiplication"
end_comment

begin_comment
comment|//  is required to be associative, but not necessarily commutative.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|,
name|class
name|Integer
operator|,
name|class
name|MonoidOperation
operator|>
name|T
name|power
argument_list|(
argument|T x
argument_list|,
argument|Integer n
argument_list|,
argument|MonoidOperation op
argument_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
name|identity_element
argument_list|(
name|op
argument_list|)
return|;
else|else
block|{
while|while
condition|(
operator|(
name|n
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
name|n
operator|>>=
literal|1
expr_stmt|;
name|x
operator|=
name|op
argument_list|(
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
name|T
name|result
operator|=
name|x
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|n
operator|>>=
literal|1
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|x
operator|=
name|op
argument_list|(
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|n
operator|&
literal|1
operator|)
operator|!=
literal|0
condition|)
name|result
operator|=
name|op
argument_list|(
name|result
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|n
operator|>>=
literal|1
expr_stmt|;
block|}
end_while

begin_return
return|return
name|result
return|;
end_return

begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Integer
operator|>
specifier|inline
name|T
name|power
argument_list|(
argument|T x
argument_list|,
argument|Integer n
argument_list|)
block|{
return|return
name|power
argument_list|(
name|x
argument_list|,
name|n
argument_list|,
name|multiplies
operator|<
name|T
operator|>
operator|(
operator|)
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
name|T
operator|>
name|void
name|iota
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|T value
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
operator|++
expr_stmt|;
block|}
end_expr_stmt

begin_macro
name|__STL_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_NUMERIC_H */
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

