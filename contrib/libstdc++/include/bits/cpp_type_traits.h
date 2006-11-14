begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The  -*- C++ -*- type traits classes for internal use in libstdc++
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
comment|// Written by Gabriel Dos Reis<dosreis@cmla.ens-cachan.fr>
end_comment

begin_comment
comment|/** @file cpp_type_traits.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
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
comment|// and not types as found in<stl/bits/type_traits.h>.  In particular, they
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
comment|// NB: g++ can not compile these if declared within the class
end_comment

begin_comment
comment|// __is_pod itself.
end_comment

begin_decl_stmt
name|namespace
name|__gnu_internal
block|{
typedef|typedef
name|char
name|__one
typedef|;
typedef|typedef
name|char
name|__two
index|[
literal|2
index|]
typedef|;
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
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_internal
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Compare for equality of types.
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
name|_M_type
operator|=
literal|0
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
comment|// Define a nested type if some predicate holds.
name|template
operator|<
name|typename
operator|,
name|bool
operator|>
expr|struct
name|__enable_if
block|{     }
expr_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__enable_if
operator|<
name|_Tp
operator|,
name|true
operator|>
block|{
typedef|typedef
name|_Tp
name|_M_type
typedef|;
block|}
empty_stmt|;
comment|// Holds if the template-argument is a void type.
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_void
block|{       enum
block|{
name|_M_type
operator|=
literal|0
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
comment|//
comment|// Integer types
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_integer
block|{       enum
block|{
name|_M_type
operator|=
literal|0
block|}
block|;     }
expr_stmt|;
comment|// Thirteen specializations (yes there are eleven standard integer
comment|// types; 'long long' and 'unsigned long long' are supported as
comment|// extensions)
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
endif|#
directive|endif
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
comment|//
comment|// Floating point types
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_floating
block|{       enum
block|{
name|_M_type
operator|=
literal|0
block|}
block|;     }
expr_stmt|;
comment|// three specializations (float, double and 'long double')
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
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
name|_M_type
operator|=
literal|1
block|}
block|;     }
expr_stmt|;
comment|//
comment|// An arithmetic type is an integer type or a floating point type
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_arithmetic
block|{       enum
block|{
name|_M_type
operator|=
name|__is_integer
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|||
name|__is_floating
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
block|}
block|;     }
expr_stmt|;
comment|//
comment|// A fundamental type is `void' or and arithmetic type
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_fundamental
block|{       enum
block|{
name|_M_type
operator|=
name|__is_void
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
operator|||
name|__is_arithmetic
operator|<
name|_Tp
operator|>
operator|::
name|_M_type
block|}
block|;     }
expr_stmt|;
comment|//
comment|// For the immediate use, the following is a good approximation
comment|//
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__is_pod
block|{       enum
block|{
name|_M_type
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|__gnu_internal
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
name|__gnu_internal
operator|::
name|__one
argument_list|)
operator|)
block|}
block|;     }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_CPP_TYPE_TRAITS_H
end_comment

end_unit

