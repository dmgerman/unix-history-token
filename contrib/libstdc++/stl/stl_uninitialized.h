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
comment|// uninitialized_copy
comment|// Valid if copy construction is equivalent to assignment, and if the
comment|//  destructor is trivial.
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_copy_aux
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_ForwardIter __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_ForwardIter
operator|>
name|_ForwardIter
name|__uninitialized_copy_aux
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_ForwardIter __result
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIter
name|__cur
operator|=
name|__result
block|;
name|__STL_TRY
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
operator|,
operator|++
name|__cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
return|return
name|__cur
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__result
argument_list|,
name|__cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}   template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_ForwardIter __result
argument_list|,
argument|_Tp*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Tp
operator|>
operator|::
name|is_POD_type
name|_Is_POD
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__uninitialized_copy_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|_ForwardIter
name|uninitialized_copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_ForwardIter __result
argument_list|)
block|{
return|return
name|__uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__result
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
name|__first
parameter_list|,
specifier|const
name|char
modifier|*
name|__last
parameter_list|,
name|char
modifier|*
name|__result
parameter_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
name|__last
operator|-
name|__first
argument_list|)
expr_stmt|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
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
name|__first
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__last
parameter_list|,
name|wchar_t
modifier|*
name|__result
parameter_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
operator|(
name|__last
operator|-
name|__first
operator|)
argument_list|)
expr_stmt|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
operator|)
return|;
block|}
end_function

begin_comment
comment|// uninitialized_copy_n (not part of the C++ standard)
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_ForwardIter
operator|>
name|pair
operator|<
name|_InputIter
operator|,
name|_ForwardIter
operator|>
name|__uninitialized_copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_ForwardIter __result
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
name|_ForwardIter
name|__cur
operator|=
name|__result
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|__count
operator|>
literal|0
condition|;
operator|--
name|__count
operator|,
operator|++
name|__first
operator|,
operator|++
name|__cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
return|return
name|pair
operator|<
name|_InputIter
operator|,
name|_ForwardIter
operator|>
operator|(
name|__first
operator|,
name|__cur
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__result
argument_list|,
name|__cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_RandomAccessIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|pair
operator|<
name|_RandomAccessIter
operator|,
name|_ForwardIter
operator|>
name|__uninitialized_copy_n
argument_list|(
argument|_RandomAccessIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_ForwardIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|_RandomAccessIter
name|__last
operator|=
name|__first
operator|+
name|__count
block|;
return|return
name|pair
operator|<
name|_RandomAccessIter
operator|,
name|_ForwardIter
operator|>
operator|(
name|__last
operator|,
name|uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|pair
operator|<
name|_InputIter
operator|,
name|_ForwardIter
operator|>
name|__uninitialized_copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_ForwardIter __result
argument_list|)
block|{
return|return
name|__uninitialized_copy_n
argument_list|(
name|__first
argument_list|,
name|__count
argument_list|,
name|__result
argument_list|,
name|__ITERATOR_CATEGORY
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|pair
operator|<
name|_InputIter
operator|,
name|_ForwardIter
operator|>
name|uninitialized_copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_ForwardIter __result
argument_list|)
block|{
return|return
name|__uninitialized_copy_n
argument_list|(
name|__first
argument_list|,
name|__count
argument_list|,
name|__result
argument_list|,
name|__ITERATOR_CATEGORY
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Valid if copy construction is equivalent to assignment, and if the
end_comment

begin_comment
comment|// destructor is trivial.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__true_type
argument_list|)
block|{
name|fill
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__x
argument_list|)
block|; }
name|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIter
name|__cur
operator|=
name|__first
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|__cur
operator|!=
name|__last
condition|;
operator|++
name|__cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__first
argument_list|,
name|__cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|>
specifier|inline
name|void
name|__uninitialized_fill
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|_Tp1*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Tp1
operator|>
operator|::
name|is_POD_type
name|_Is_POD
expr_stmt|;
name|__uninitialized_fill_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__x
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|uninitialized_fill
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
name|__uninitialized_fill
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__x
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
block|; }
comment|// Valid if copy construction is equivalent to assignment, and if the
comment|//  destructor is trivial.
name|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_fill_n_aux
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|fill_n
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_Tp
operator|>
name|_ForwardIter
name|__uninitialized_fill_n_aux
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIter
name|__cur
operator|=
name|__first
block|;
name|__STL_TRY
block|{
for|for
control|(
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
operator|,
operator|++
name|__cur
control|)
name|construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
name|__x
argument_list|)
expr_stmt|;
return|return
name|__cur
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__first
argument_list|,
name|__cur
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_Tp
operator|,
name|class
name|_Tp1
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_fill_n
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|_Tp1*
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Tp1
operator|>
operator|::
name|is_POD_type
name|_Is_POD
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__uninitialized_fill_n_aux
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|_ForwardIter
name|uninitialized_fill_n
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
return|return
name|__uninitialized_fill_n
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Extensions: __uninitialized_copy_copy, __uninitialized_copy_fill,
end_comment

begin_comment
comment|// __uninitialized_fill_copy.
end_comment

begin_comment
comment|// __uninitialized_copy_copy
end_comment

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
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|,
name|class
name|_ForwardIter
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_copy_copy
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|,
argument|_ForwardIter __result
argument_list|)
block|{
name|_ForwardIter
name|__mid
operator|=
name|uninitialized_copy
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|,
name|__result
argument_list|)
block|;
name|__STL_TRY
block|{
return|return
name|uninitialized_copy
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|,
name|__mid
argument_list|)
return|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// __uninitialized_fill_copy
end_comment

begin_comment
comment|// Fills [result, mid) with x, and copies [first, last) into
end_comment

begin_comment
comment|//  [mid, mid + (last - first)).
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|,
name|class
name|_InputIter
operator|>
specifier|inline
name|_ForwardIter
name|__uninitialized_fill_copy
argument_list|(
argument|_ForwardIter __result
argument_list|,
argument|_ForwardIter __mid
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|)
block|{
name|uninitialized_fill
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|,
name|__x
argument_list|)
block|;
name|__STL_TRY
block|{
return|return
name|uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__mid
argument_list|)
return|;
block|}
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// __uninitialized_copy_fill
end_comment

begin_comment
comment|// Copies [first1, last1) into [first2, first2 + (last1 - first1)), and
end_comment

begin_comment
comment|//  fills [first2 + (last1 - first1), last2) with x.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|__uninitialized_copy_fill
argument_list|(
argument|_InputIter __first1
argument_list|,
argument|_InputIter __last1
argument_list|,
argument|_ForwardIter __first2
argument_list|,
argument|_ForwardIter __last2
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
name|_ForwardIter
name|__mid2
operator|=
name|uninitialized_copy
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|,
name|__first2
argument_list|)
block|;
name|__STL_TRY
block|{
name|uninitialized_fill
argument_list|(
name|__mid2
argument_list|,
name|__last2
argument_list|,
name|__x
argument_list|)
block|;   }
name|__STL_UNWIND
argument_list|(
name|destroy
argument_list|(
name|__first2
argument_list|,
name|__mid2
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

