begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
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
name|ForwardIterator
operator|,
name|class
name|T
operator|>
name|class
name|raw_storage_iterator
block|{
name|protected
operator|:
name|ForwardIterator
name|iter
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
argument|ForwardIterator x
argument_list|)
end_macro

begin_macro
unit|:
name|iter
argument_list|(
argument|x
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|raw_storage_iterator
operator|<
name|ForwardIterator
operator|,
name|T
operator|>
operator|&
name|operator
operator|*
operator|(
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|raw_storage_iterator
operator|<
name|ForwardIterator
operator|,
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|T
operator|&
name|element
operator|)
block|{
name|construct
argument_list|(
operator|&
operator|*
name|iter
argument_list|,
name|element
argument_list|)
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
name|ForwardIterator
operator|,
name|T
operator|>
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|iter
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
name|ForwardIterator
operator|,
name|T
operator|>
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|raw_storage_iterator
operator|<
name|ForwardIterator
block|,
name|T
operator|>
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
name|iter
block|;
return|return
name|tmp
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
name|ForwardIterator
operator|,
name|class
name|T
operator|>
specifier|inline
name|output_iterator_tag
name|iterator_category
argument_list|(
argument|const raw_storage_iterator<ForwardIterator
argument_list|,
argument|T>&
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_RAW_STORAGE_ITERATOR_H */
end_comment

begin_macro
name|__STL_END_NAMESPACE
end_macro

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

