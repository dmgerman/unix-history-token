begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  * You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_RAW_STORAGE_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_RAW_STORAGE_ITERATOR_H
end_define

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
name|class
name|raw_storage_iterator
block|{
name|protected
operator|:
name|_ForwardIterator
name|_M_iter
block|;
name|public
operator|:
typedef|typedef
name|output_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|reference
typedef|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|raw_storage_iterator
argument_list|(
argument|_ForwardIterator __x
argument_list|)
end_macro

begin_macro
unit|:
name|_M_iter
argument_list|(
argument|__x
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_function
name|raw_storage_iterator
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_function

begin_decl_stmt
name|raw_storage_iterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|_Tp
operator|&
name|__element
operator|)
block|{
name|construct
argument_list|(
operator|&
operator|*
name|_M_iter
argument_list|,
name|__element
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|raw_storage_iterator
operator|<
name|_ForwardIterator
operator|,
name|_Tp
operator|>
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|_M_iter
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|raw_storage_iterator
operator|<
name|_ForwardIterator
operator|,
name|_Tp
operator|>
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|raw_storage_iterator
operator|<
name|_ForwardIterator
block|,
name|_Tp
operator|>
name|__tmp
operator|=
operator|*
name|this
block|;
operator|++
name|_M_iter
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifndef

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|output_iterator_tag
name|iterator_category
argument_list|(
argument|const raw_storage_iterator<_ForwardIterator
argument_list|,
argument|_Tp>&
argument_list|)
block|{
return|return
name|output_iterator_tag
argument_list|()
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_macro
name|__STL_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_RAW_STORAGE_ITERATOR_H */
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

