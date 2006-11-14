begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Backward-compat support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2004 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BACKWARD_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_BACKWARD_ITERATOR_H
value|1
end_define

begin_include
include|#
directive|include
file|"backward_warning.h"
end_include

begin_include
include|#
directive|include
file|"function.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"iostream.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<bits/stl_construct.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_raw_storage_iter.h>
end_include

begin_include
include|#
directive|include
file|<ext/iterator>
end_include

begin_comment
comment|// For 3-parameter distance extension
end_comment

begin_comment
comment|// Names from stl_iterator.h
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|input_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|output_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|forward_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|bidirectional_iterator_tag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
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
unit|using std::iterator;
endif|#
directive|endif
end_endif

begin_comment
comment|// The base classes input_iterator, output_iterator, forward_iterator,
end_comment

begin_comment
comment|// bidirectional_iterator, and random_access_iterator are not part of
end_comment

begin_comment
comment|// the C++ standard.  (They have been replaced by struct iterator.)
end_comment

begin_comment
comment|// They are included for backward compatibility with the HP STL.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Distance
operator|>
expr|struct
name|input_iterator
block|{
typedef|typedef
name|input_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Distance
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_struct
unit|};
struct|struct
name|output_iterator
block|{
typedef|typedef
name|output_iterator_tag
name|iterator_category
typedef|;
typedef|typedef
name|void
name|value_type
typedef|;
typedef|typedef
name|void
name|difference_type
typedef|;
typedef|typedef
name|void
name|pointer
typedef|;
typedef|typedef
name|void
name|reference
typedef|;
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Distance
operator|>
expr|struct
name|forward_iterator
block|{
typedef|typedef
name|forward_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Distance
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Distance
operator|>
expr|struct
name|bidirectional_iterator
block|{
typedef|typedef
name|bidirectional_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Distance
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Distance
operator|>
expr|struct
name|random_access_iterator
block|{
typedef|typedef
name|random_access_iterator_tag
name|iterator_category
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Distance
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|using
name|std
operator|::
name|iterator_traits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Iter
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|iterator_category
name|iterator_category
argument_list|(
argument|const _Iter& __i
argument_list|)
block|{
return|return
name|__iterator_category
argument_list|(
name|__i
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Iter
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|difference_type
operator|*
name|distance_type
argument_list|(
argument|const _Iter&
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|difference_type
operator|*
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Iter
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|value_type
operator|*
name|value_type
argument_list|(
argument|const _Iter& __i
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|typename
name|iterator_traits
operator|<
name|_Iter
operator|>
operator|::
name|value_type
operator|*
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|distance
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__gnu_cxx
operator|::
name|distance
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 3-parameter extension
end_comment

begin_expr_stmt
name|using
name|std
operator|::
name|advance
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|front_insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|back_insert_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|front_inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|back_inserter
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|reverse_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|istream_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ostream_iterator
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Names from stl_construct.h
end_comment

begin_expr_stmt
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
name|std
operator|::
name|_Construct
argument_list|(
name|__p
argument_list|,
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
name|std
operator|::
name|_Construct
argument_list|(
name|__p
argument_list|)
block|; }
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
name|std
operator|::
name|_Destroy
argument_list|(
name|__pointer
argument_list|)
block|; }
name|template
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
name|std
operator|::
name|_Destroy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|// Names from stl_raw_storage_iter.h
name|using
name|std
operator|::
name|raw_storage_iterator
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BACKWARD_ITERATOR_H */
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

