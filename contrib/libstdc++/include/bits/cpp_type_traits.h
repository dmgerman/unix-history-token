begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The  -*- C++ -*- type traits classes for internal use in libstdc++
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|/** @file cpp_type_traits.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Written by Gabriel Dos Reis<dosreis@cmla.ens-cachan.fr>
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_TYPE_TRAITS_H
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
comment|//
end_comment

begin_comment
comment|// This file provides some compile-time information about various types.
end_comment

begin_comment
comment|// These representations were designed, on purpose, to be constant-expressions
end_comment

begin_comment
comment|// and not types as found in<bits/type_traits.h>.  In particular, they
end_comment

begin_comment
comment|// can be used in control structures and the optimizer hopefully will do
end_comment

begin_comment
comment|// the obvious thing.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Why integral expressions, and not functions nor types?
end_comment

begin_comment
comment|// Firstly, these compile-time entities are used as template-arguments
end_comment

begin_comment
comment|// so function return values won't work:  We need compile-time entities.
end_comment

begin_comment
comment|// We're left with types and constant  integral expressions.
end_comment

begin_comment
comment|// Secondly, from the point of view of ease of use, type-based compile-time
end_comment

begin_comment
comment|// information is -not- *that* convenient.  On has to write lots of
end_comment

begin_comment
comment|// overloaded functions and to hope that the compiler will select the right
end_comment

begin_comment
comment|// one. As a net effect, the overall structure isn't very clear at first
end_comment

begin_comment
comment|// glance.
end_comment

begin_comment
comment|// Thirdly, partial ordering and overload resolution (of function templates)
end_comment

begin_comment
comment|// is highly costly in terms of compiler-resource.  It is a Good Thing to
end_comment

begin_comment
comment|// keep these resource consumption as least as possible.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See valarray_array.h for a case use.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -- Gaby (dosreis@cmla.ens-cachan.fr) 2000-03-06.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Update 2005: types are also provided and<bits/type_traits.h> has been
end_comment

begin_comment
comment|// removed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Forward declaration hack, should really include this from somewhere.
end_comment

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_expr_stmt
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
end_expr_stmt

begin_function
name|_GLIBCXX_END_NAMESPACE
name|_GLIBCXX_BEGIN_NAMESPACE
parameter_list|(
name|std
parameter_list|)
ifdef|#
directive|ifdef
name|__clang__
comment|// When using clang, suppress warnings about possible keywords (such as
comment|// __is_void, __is_pod, etc) being used as identifiers.
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wkeyword-compat"
endif|#
directive|endif
name|namespace
name|__detail
decl_stmt|{
comment|// NB: g++ can not compile these if declared within the class
comment|// __is_pod itself.
decl_stmt|typedef char __one;
end_function

begin_typedef
typedef|typedef
name|char
name|__two
index|[
literal|2
index|]
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|__one
name|__test_type
argument_list|(
argument|int _Tp::*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|__two
operator|&
name|__test_type
argument_list|(
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace __detail
end_comment

begin_macro
unit|struct
name|__true_type
end_macro

begin_block
block|{ }
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|__false_type
block|{ }
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|bool
operator|>
expr|struct
name|__truth_type
block|{
typedef|typedef
name|__false_type
name|__type
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
name|__truth_type
operator|<
name|true
operator|>
block|{
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// N.B. The conversions to bool are needed due to the issue
end_comment

begin_comment
comment|// explained in c++/19404.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Sp
operator|,
name|class
name|_Tp
operator|>
expr|struct
name|__traitor
block|{       enum
block|{
name|__value
operator|=
name|bool
argument_list|(
name|_Sp
operator|::
name|__value
argument_list|)
operator|||
name|bool
argument_list|(
argument|_Tp::__value
argument_list|)
block|}
block|;
typedef|typedef
name|typename
name|__truth_type
operator|<
name|__value
operator|>
operator|::
name|__type
name|__type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Compare for equality of types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|,
name|typename
operator|>
expr|struct
name|__are_same
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
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
name|__are_same
operator|<
name|_Tp
operator|,
name|_Tp
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Holds if the template-argument is a void type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_void
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
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
name|__is_void
operator|<
name|void
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Integer types
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_integer
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Thirteen specializations (yes there are eleven standard integer
end_comment

begin_comment
comment|// types; 'long long' and 'unsigned long long' are supported as
end_comment

begin_comment
comment|// extensions)
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__is_integer
operator|<
name|bool
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|char
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|signed
name|char
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|unsigned
name|char
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__is_integer
operator|<
name|wchar_t
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__is_integer
operator|<
name|short
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|unsigned
name|short
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|int
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|unsigned
name|int
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|long
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|unsigned
name|long
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|long
name|long
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_integer
operator|<
name|unsigned
name|long
name|long
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Floating point types
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_floating
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// three specializations (float, double and 'long double')
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__is_floating
operator|<
name|float
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_floating
operator|<
name|double
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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
name|__is_floating
operator|<
name|long
name|double
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Pointer types
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_pointer
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
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
name|__is_pointer
operator|<
name|_Tp
operator|*
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Normal iterator type
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_normal_iterator
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
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
name|_Iterator
operator|,
name|typename
name|_Container
operator|>
expr|struct
name|__is_normal_iterator
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
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// An arithmetic type is an integer type or a floating point type
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_arithmetic
operator|:
name|public
name|__traitor
operator|<
name|__is_integer
operator|<
name|_Tp
operator|>
operator|,
name|__is_floating
operator|<
name|_Tp
operator|>
expr|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// A fundamental type is `void' or and arithmetic type
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_fundamental
operator|:
name|public
name|__traitor
operator|<
name|__is_void
operator|<
name|_Tp
operator|>
operator|,
name|__is_arithmetic
operator|<
name|_Tp
operator|>
expr|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// A scalar type is an arithmetic type or a pointer type
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_scalar
operator|:
name|public
name|__traitor
operator|<
name|__is_arithmetic
operator|<
name|_Tp
operator|>
operator|,
name|__is_pointer
operator|<
name|_Tp
operator|>
expr|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For the immediate use, the following is a good approximation.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_pod
block|{       enum
block|{
name|__value
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|__detail
operator|::
name|__test_type
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|__detail
operator|::
name|__one
argument_list|)
operator|)
block|}
block|;     }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// A stripped-down version of std::tr1::is_empty
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_empty
block|{
name|private
operator|:
name|template
operator|<
name|typename
operator|>
expr|struct
name|__first
block|{ }
block|;
name|template
operator|<
name|typename
name|_Up
operator|>
expr|struct
name|__second
operator|:
name|public
name|_Up
block|{ }
block|;
name|public
operator|:
expr|enum
block|{
name|__value
operator|=
sizeof|sizeof
argument_list|(
name|__first
operator|<
name|_Tp
operator|>
argument_list|)
operator|==
expr|sizeof
operator|(
name|__second
operator|<
name|_Tp
operator|>
operator|)
block|}
block|;     }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// For use in std::copy and std::find overloads for streambuf iterators.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_char
block|{       enum
block|{
name|__value
operator|=
literal|0
block|}
block|;
typedef|typedef
name|__false_type
name|__type
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
name|__is_char
operator|<
name|char
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__is_char
operator|<
name|wchar_t
operator|>
block|{       enum
block|{
name|__value
operator|=
literal|1
block|}
block|;
typedef|typedef
name|__true_type
name|__type
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

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_CPP_TYPE_TRAITS_H
end_comment

end_unit

