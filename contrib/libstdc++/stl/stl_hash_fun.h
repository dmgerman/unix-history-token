begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_HASH_FUN_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_HASH_FUN_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|_Key
operator|>
expr|struct
name|hash
block|{ }
expr_stmt|;
end_expr_stmt

begin_function
specifier|inline
name|size_t
name|__stl_hash_string
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
block|{
name|unsigned
name|long
name|__h
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
operator|*
name|__s
condition|;
operator|++
name|__s
control|)
name|__h
operator|=
literal|5
operator|*
name|__h
operator|+
operator|*
name|__s
expr_stmt|;
return|return
name|size_t
argument_list|(
name|__h
argument_list|)
return|;
block|}
end_function

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|char
operator|*
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|__s
operator|)
specifier|const
block|{
return|return
name|__stl_hash_string
argument_list|(
name|__s
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
specifier|const
name|char
operator|*
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|__s
operator|)
specifier|const
block|{
return|return
name|__stl_hash_string
argument_list|(
name|__s
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|unsigned
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|signed
name|char
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|char
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|short
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|short
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|unsigned
name|short
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|short
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|int
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|int
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|unsigned
name|int
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|int
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|long
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|long
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|hash
operator|<
name|unsigned
name|long
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|unsigned
name|long
name|__x
operator|)
specifier|const
block|{
return|return
name|__x
return|;
block|}
end_expr_stmt

begin_macro
unit|};
name|__STL_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_HASH_FUN_H */
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

