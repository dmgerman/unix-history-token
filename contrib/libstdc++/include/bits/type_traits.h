begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Type traits implementation -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file type_traits.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|_TYPE_TRAITS_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_comment
comment|/* This header file provides a framework for allowing compile time dispatch based on type attributes. This is useful when writing template code. For example, when making a copy of an array of an unknown type, it helps to know if the type has a trivial copy constructor or not, to help decide if a memcpy can be used.  The class template __type_traits provides a series of typedefs each of which is either __true_type or __false_type. The argument to __type_traits can be any type. The typedefs within this template will attain their correct values by one of these means:     1. The general instantiation contain conservative values which work        for all types.     2. Specializations may be declared to make distinctions between types.     3. Some compilers (such as the Silicon Graphics N32 and N64 compilers)        will automatically provide the appropriate specializations for all        types.  EXAMPLE:  //Copy an array of elements which have non-trivial copy constructors template<class _Tp> void   copy(_Tp* __source,_Tp* __destination,int __n,__false_type); //Copy an array of elements which have trivial copy constructors. Use memcpy. template<class _Tp> void   copy(_Tp* __source,_Tp* __destination,int __n,__true_type);  //Copy an array of any type by using the most efficient copy mechanism template<class _Tp> inline void copy(_Tp* __source,_Tp* __destination,int __n) {    copy(__source,__destination,__n,         typename __type_traits<_Tp>::has_trivial_copy_constructor()); } */
end_comment

begin_struct
struct|struct
name|__true_type
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|__false_type
block|{}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__type_traits
block|{
typedef|typedef
name|__true_type
name|this_dummy_member_must_be_first
typedef|;
end_expr_stmt

begin_comment
comment|/* Do not remove this member. It informs a compiler which        automatically specializes __type_traits that this        __type_traits template is special. It just makes sure that        things work if an implementation is using a template        called __type_traits for something unrelated. */
end_comment

begin_comment
comment|/* The following restrictions should be observed for the sake of       compilers which automatically produce type specific specializations       of this class:           - You may reorder the members below if you wish           - You may remove any of the members below if you wish           - You must not rename members without making the corresponding             name change in the compiler           - Members you add will be treated like regular members unless             you add the appropriate support in the compiler. */
end_comment

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_default_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|is_POD_type
typedef|;
end_typedef

begin_comment
unit|};
comment|// Provide some specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|bool
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|signed
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|unsigned
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|wchar_t
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|unsigned
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|unsigned
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|unsigned
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|float
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|double
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__type_traits
operator|<
name|long
name|double
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__type_traits
operator|<
name|_Tp
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_comment
unit|};
comment|// The following could be written in terms of numeric_limits.
end_comment

begin_comment
comment|// We're doing it separately to reduce the number of dependencies.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|_Is_integer
block|{
typedef|typedef
name|__false_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|bool
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|signed
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|unsigned
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|wchar_t
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|unsigned
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|unsigned
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|unsigned
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|_Is_integer
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_Is_normal_iterator
block|{
typedef|typedef
name|__false_type
name|_Normal
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Forward declaration hack, should really include this from somewhere.
end_comment

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Container
operator|>
name|class
name|__normal_iterator
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Container
operator|>
expr|struct
name|_Is_normal_iterator
operator|<
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|_Iterator
operator|,
name|_Container
operator|>
expr|>
block|{
typedef|typedef
name|__true_type
name|_Normal
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TYPE_TRAITS_H */
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

