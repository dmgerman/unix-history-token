begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_ALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_ALLOC_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_CONFIG_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ALLOC_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_alloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_NAMESPACES
end_ifdef

begin_expr_stmt
name|using
name|__STD
operator|::
name|__malloc_alloc_template
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|malloc_alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|simple_alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|debug_alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|__default_alloc_template
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|single_client_alloc
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
end_ifdef

begin_expr_stmt
name|using
name|__STD
operator|::
name|__malloc_alloc_oom_handler
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_STATIC_TEMPLATE_MEMBER_BUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_STD_ALLOCATORS
end_ifdef

begin_expr_stmt
name|using
name|__STD
operator|::
name|allocator
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_USE_STD_ALLOCATORS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_USE_NAMESPACES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_ALLOC_H */
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

