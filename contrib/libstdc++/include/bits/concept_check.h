begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Concept-checking control -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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
comment|/** @file concept_check.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_CONCEPT_CHECK
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCPP_CONCEPT_CHECK
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
comment|// All places in libstdc++-v3 where these are used, or /might/ be used, or
end_comment

begin_comment
comment|// don't need to be used, or perhaps /should/ be used, are commented with
end_comment

begin_comment
comment|// "concept requirements" (and maybe some more text).  So grep like crazy
end_comment

begin_comment
comment|// if you're looking for additional places to use these.
end_comment

begin_comment
comment|// Concept-checking code is off by default unless users turn it on via
end_comment

begin_comment
comment|// configure options or editing c++config.h.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_CONCEPT_CHECKS
end_ifndef

begin_define
define|#
directive|define
name|__glibcpp_function_requires
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires2
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires3
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires4
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_e
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// the checks are on
end_comment

begin_include
include|#
directive|include
file|<bits/boost_concept_check.h>
end_include

begin_comment
comment|// Note that the obvious and elegant approach of
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//#define glibcpp_function_requires(C) boost::function_requires< boost::C>()
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// won't work due to concept templates with more than one parameter, e.g.,
end_comment

begin_comment
comment|// BinaryPredicateConcept.  The preprocessor tries to split things up on
end_comment

begin_comment
comment|// the commas in the template argument list.  We can't use an inner pair of
end_comment

begin_comment
comment|// parenthesis to hide the commas, because "boost::(Temp<Foo,Bar>)" isn't
end_comment

begin_comment
comment|// a valid instantiation pattern.  Thus, we steal a feature from C99.
end_comment

begin_define
define|#
directive|define
name|__glibcpp_function_requires
parameter_list|(
modifier|...
parameter_list|)
define|\
value|__gnu_cxx::__function_requires< __gnu_cxx::__VA_ARGS__>();
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires
parameter_list|(
name|_a
parameter_list|,
name|_C
parameter_list|)
define|\
value|_GLIBCPP_CLASS_REQUIRES(_a, __gnu_cxx, _C);
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires2
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_C
parameter_list|)
define|\
value|_GLIBCPP_CLASS_REQUIRES2(_a, _b, __gnu_cxx, _C);
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires3
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_C
parameter_list|)
define|\
value|_GLIBCPP_CLASS_REQUIRES3(_a, _b, _c, __gnu_cxx, _C);
end_define

begin_define
define|#
directive|define
name|__glibcpp_class_requires4
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|,
name|_C
parameter_list|)
define|\
value|_GLIBCPP_CLASS_REQUIRES4(_a, _b, _c, _d, __gnu_cxx, _C);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// enable/disable
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCPP_CONCEPT_CHECK
end_comment

end_unit

