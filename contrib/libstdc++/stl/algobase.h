begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_ALGOBASE_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_ALGOBASE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_PAIR_H
end_ifndef

begin_include
include|#
directive|include
file|<pair.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_ITERATOR_H
end_ifndef

begin_include
include|#
directive|include
file|<iterator.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ALGOBASE_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_algobase.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_UNINITIALIZED_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_uninitialized.h>
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

begin_comment
comment|// Names from stl_algobase.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|iter_swap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|swap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|min
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|max
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|copy_backward
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|copy_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|fill
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|fill_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|mismatch
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|equal
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|lexicographical_compare
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|lexicographical_compare_3way
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_uninitialized.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|uninitialized_copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|uninitialized_copy_n
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|uninitialized_fill
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|uninitialized_fill_n
expr_stmt|;
end_expr_stmt

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
comment|/* __SGI_STL_ALGOBASE_H */
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

