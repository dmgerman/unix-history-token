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
name|_InputIterator
operator|,
name|class
name|_Tp
operator|>
name|_Tp
name|accumulate
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_Tp __init
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__first
control|)
name|__init
operator|=
name|__init
operator|+
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_Tp
operator|,
name|class
name|_BinaryOperation
operator|>
name|_Tp
name|accumulate
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_Tp __init
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__first
control|)
name|__init
operator|=
name|__binary_op
argument_list|(
name|__init
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator1
operator|,
name|class
name|_InputIterator2
operator|,
name|class
name|_Tp
operator|>
name|_Tp
name|inner_product
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_Tp __init
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
name|__init
operator|=
name|__init
operator|+
operator|(
operator|*
name|__first1
operator|*
operator|*
name|__first2
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator1
operator|,
name|class
name|_InputIterator2
operator|,
name|class
name|_Tp
operator|,
name|class
name|_BinaryOperation1
operator|,
name|class
name|_BinaryOperation2
operator|>
name|_Tp
name|inner_product
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_Tp __init
argument_list|,
argument|_BinaryOperation1 __binary_op1
argument_list|,
argument|_BinaryOperation2 __binary_op2
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
name|__init
operator|=
name|__binary_op1
argument_list|(
name|__init
argument_list|,
name|__binary_op2
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_Tp
operator|>
name|_OutputIterator
name|__partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_Tp*
argument_list|)
block|{
name|_Tp
name|__value
operator|=
operator|*
name|__first
block|;
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|__value
operator|=
name|__value
operator|+
operator|*
name|__first
expr_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__value
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|>
name|_OutputIterator
name|partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__partial_sum
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_Tp
operator|,
name|class
name|_BinaryOperation
operator|>
name|_OutputIterator
name|__partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_Tp*
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
name|_Tp
name|__value
operator|=
operator|*
name|__first
block|;
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|__value
operator|=
name|__binary_op
argument_list|(
name|__value
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__value
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_BinaryOperation
operator|>
name|_OutputIterator
name|partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__partial_sum
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|,
name|__binary_op
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_Tp
operator|>
name|_OutputIterator
name|__adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_Tp*
argument_list|)
block|{
name|_Tp
name|__value
operator|=
operator|*
name|__first
block|;
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|_Tp
name|__tmp
init|=
operator|*
name|__first
decl_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__tmp
operator|-
name|__value
expr_stmt|;
name|__value
operator|=
name|__tmp
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|>
name|_OutputIterator
name|adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__adjacent_difference
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_Tp
operator|,
name|class
name|_BinaryOperation
operator|>
name|_OutputIterator
name|__adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_Tp*
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
name|_Tp
name|__value
operator|=
operator|*
name|__first
block|;
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|_Tp
name|__tmp
init|=
operator|*
name|__first
decl_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__binary_op
argument_list|(
name|__tmp
argument_list|,
name|__value
argument_list|)
expr_stmt|;
name|__value
operator|=
name|__tmp
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIterator
operator|,
name|class
name|_OutputIterator
operator|,
name|class
name|_BinaryOperation
operator|>
name|_OutputIterator
name|adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__adjacent_difference
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|,
name|__binary_op
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// Returns __x ** __n, where __n>= 0.  _Note that "multiplication"
end_comment

begin_comment
comment|// is required to be associative, but not necessarily commutative.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Integer
operator|,
name|class
name|_MonoidOperation
operator|>
name|_Tp
name|__power
argument_list|(
argument|_Tp __x
argument_list|,
argument|_Integer __n
argument_list|,
argument|_MonoidOperation __oper
argument_list|)
block|{
if|if
condition|(
name|__n
operator|==
literal|0
condition|)
return|return
name|identity_element
argument_list|(
name|__oper
argument_list|)
return|;
else|else
block|{
while|while
condition|(
operator|(
name|__n
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
name|__n
operator|>>=
literal|1
expr_stmt|;
name|__x
operator|=
name|__oper
argument_list|(
name|__x
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
name|_Tp
name|__result
operator|=
name|__x
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__n
operator|>>=
literal|1
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|__n
operator|!=
literal|0
condition|)
block|{
name|__x
operator|=
name|__oper
argument_list|(
name|__x
argument_list|,
name|__x
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|__n
operator|&
literal|1
operator|)
operator|!=
literal|0
condition|)
name|__result
operator|=
name|__oper
argument_list|(
name|__result
argument_list|,
name|__x
argument_list|)
expr_stmt|;
name|__n
operator|>>=
literal|1
expr_stmt|;
block|}
end_while

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Integer
operator|>
specifier|inline
name|_Tp
name|__power
argument_list|(
argument|_Tp __x
argument_list|,
argument|_Integer __n
argument_list|)
block|{
return|return
name|__power
argument_list|(
name|__x
argument_list|,
name|__n
argument_list|,
name|multiplies
operator|<
name|_Tp
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Alias for the internal name __power.  Note that power is an extension,
end_comment

begin_comment
comment|// not part of the C++ standard.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Integer
operator|,
name|class
name|_MonoidOperation
operator|>
specifier|inline
name|_Tp
name|power
argument_list|(
argument|_Tp __x
argument_list|,
argument|_Integer __n
argument_list|,
argument|_MonoidOperation __oper
argument_list|)
block|{
return|return
name|__power
argument_list|(
name|__x
argument_list|,
name|__n
argument_list|,
name|__oper
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Integer
operator|>
specifier|inline
name|_Tp
name|power
argument_list|(
argument|_Tp __x
argument_list|,
argument|_Integer __n
argument_list|)
block|{
return|return
name|__power
argument_list|(
name|__x
argument_list|,
name|__n
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// iota is not part of the C++ standard.  It is an extension.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
name|void
name|iota
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|_Tp __value
argument_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
condition|)
operator|*
name|__first
operator|++
operator|=
name|__value
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

