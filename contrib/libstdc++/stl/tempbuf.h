begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_TEMPBUF_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_TEMPBUF_H
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

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPE_TRAITS_H
end_ifndef

begin_include
include|#
directive|include
file|<type_traits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_CONSTRUCT_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_construct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_TEMPBUF_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_tempbuf.h>
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
name|get_temporary_buffer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|return_temporary_buffer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|temporary_buffer
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
comment|/* __SGI_STL_TEMPBUF_H */
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

