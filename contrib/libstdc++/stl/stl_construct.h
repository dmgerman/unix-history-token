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
comment|// construct and destroy.  These functions are not part of the C++ standard,
comment|// and are provided for backward compatibility with the HP STL.
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|destroy
argument_list|(
argument|_Tp* __pointer
argument_list|)
block|{
name|__pointer
operator|->
expr|~
name|_Tp
argument_list|()
block|; }
name|template
operator|<
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|void
name|construct
argument_list|(
argument|_T1* __p
argument_list|,
argument|const _T2& __value
argument_list|)
block|{
name|new
argument_list|(
argument|__p
argument_list|)
name|_T1
argument_list|(
name|__value
argument_list|)
block|; }
name|template
operator|<
name|class
name|_T1
operator|>
specifier|inline
name|void
name|construct
argument_list|(
argument|_T1* __p
argument_list|)
block|{
name|new
argument_list|(
argument|__p
argument_list|)
name|_T1
argument_list|()
block|; }
name|template
operator|<
name|class
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|__false_type
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
name|destroy
argument_list|(
operator|&
operator|*
name|__first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|__destroy_aux
argument_list|(
argument|_ForwardIterator
argument_list|,
argument|_ForwardIterator
argument_list|,
argument|__true_type
argument_list|)
block|{}
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|__destroy
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
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
name|has_trivial_destructor
name|_Trivial_destructor
expr_stmt|;
name|__destroy_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Trivial_destructor
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_ForwardIterator
operator|>
specifier|inline
name|void
name|destroy
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
block|{
name|__destroy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__first
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

