begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * Copyright (c) 1996,1997  * Silicon Graphics  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_RELOPS
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_RELOPS
end_define

begin_expr_stmt
name|__STL_BEGIN_RELOPS_NAMESPACE
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|&
name|x
operator|,
specifier|const
name|T
operator|&
name|y
operator|)
block|{
return|return
operator|!
operator|(
name|x
operator|==
name|y
operator|)
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
name|bool
name|operator
operator|>
operator|(
specifier|const
name|T
operator|&
name|x
operator|,
specifier|const
name|T
operator|&
name|y
operator|)
block|{
return|return
name|y
operator|<
name|x
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
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|T
operator|&
name|x
operator|,
specifier|const
name|T
operator|&
name|y
operator|)
block|{
return|return
operator|!
operator|(
name|y
operator|<
name|x
operator|)
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
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|T
operator|&
name|x
operator|,
specifier|const
name|T
operator|&
name|y
operator|)
block|{
return|return
operator|!
operator|(
name|x
operator|<
name|y
operator|)
return|;
block|}
end_expr_stmt

begin_macro
name|__STL_END_RELOPS_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_RELOPS */
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

