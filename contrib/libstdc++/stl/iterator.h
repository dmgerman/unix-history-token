begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_ITERATOR_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_FUNCTION_H
end_ifndef

begin_include
include|#
directive|include
file|<function.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ITERATOR_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_iterator.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|__SGI_STL_INTERNAL_RAW_STORAGE_ITERATOR_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_raw_storage_iter.h>
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
comment|// Names from stl_iterator.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|input_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|output_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|forward_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|bidirectional_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|random_access_iterator_tag
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|using __STD::iterator;
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
name|__STD
operator|::
name|input_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|output_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|forward_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|bidirectional_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|random_access_iterator
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifdef

begin_expr_stmt
name|using
name|__STD
operator|::
name|iterator_traits
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
name|__STD
operator|::
name|iterator_category
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|distance_type
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|value_type
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|distance
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|advance
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|front_insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|back_insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|front_inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|back_inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|reverse_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|reverse_bidirectional_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|istream_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|ostream_iterator
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_construct.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|construct
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__STD
operator|::
name|destroy
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_raw_storage_iter.h
end_comment

begin_expr_stmt
name|using
name|__STD
operator|::
name|raw_storage_iterator
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
comment|/* __SGI_STL_ITERATOR_H */
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

