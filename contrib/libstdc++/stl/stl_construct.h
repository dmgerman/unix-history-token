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
name|__SGI_STL_INTERNAL_CONSTRUCT_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_CONSTRUCT_H
end_define

begin_include
include|#
directive|include
file|<new.h>
end_include

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|destroy
argument_list|(
argument|T* pointer
argument_list|)
block|{
name|pointer
operator|->
expr|~
name|T
argument_list|()
block|; }
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
specifier|inline
name|void
name|construct
argument_list|(
argument|T1* p
argument_list|,
argument|const T2& value
argument_list|)
block|{
name|new
argument_list|(
argument|p
argument_list|)
name|T1
argument_list|(
name|value
argument_list|)
block|; }
name|template
operator|<
name|class
name|ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|,
argument|__false_type
argument_list|)
block|{
for|for
control|(
init|;
name|first
operator|<
name|last
condition|;
operator|++
name|first
control|)
name|destroy
argument_list|(
operator|&
operator|*
name|first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|ForwardIterator
argument_list|,
argument|ForwardIterator
argument_list|,
argument|__true_type
argument_list|)
block|{}
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
name|__destroy
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
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
name|has_trivial_destructor
name|trivial_destructor
expr_stmt|;
name|__destroy_aux
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|trivial_destructor
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|ForwardIterator
operator|>
specifier|inline
name|void
name|destroy
argument_list|(
argument|ForwardIterator first
argument_list|,
argument|ForwardIterator last
argument_list|)
block|{
name|__destroy
argument_list|(
name|first
argument_list|,
name|last
argument_list|,
name|value_type
argument_list|(
name|first
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|destroy
argument_list|(
argument|char*
argument_list|,
argument|char*
argument_list|)
block|{}
specifier|inline
name|void
name|destroy
argument_list|(
argument|wchar_t*
argument_list|,
argument|wchar_t*
argument_list|)
block|{}
name|__STL_END_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_CONSTRUCT_H */
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

