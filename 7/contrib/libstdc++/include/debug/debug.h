begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Debugging support implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2005, 2006
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
comment|/** @file debug/debug.h  *  This file is a GNU debug extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEBUG_MACRO_SWITCH_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_MACRO_SWITCH_H
value|1
end_define

begin_comment
comment|/** Macros and namespaces used by the implementation outside of debug  *  wrappers to verify certain properties. The __glibcxx_requires_xxx  *  macros are merely wrappers around the __glibcxx_check_xxx wrappers  *  when we are compiling with debug mode, but disappear when we are  *  in release mode so that there is no checking performed in, e.g.,  *  the standard library algorithms. */
end_comment

begin_comment
comment|// Debug mode namespaces.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|namespace
name|__debug
block|{ }
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|namespace
name|__debug
block|{ }
empty_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|__gnu_debug
block|{
name|using
name|namespace
name|std
operator|::
name|__debug
expr_stmt|;
name|using
name|namespace
name|__gnu_cxx
operator|::
name|__debug
expr_stmt|;
block|}
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_ASSERT
parameter_list|(
name|_Condition
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_PEDASSERT
parameter_list|(
name|_Condition
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_ONLY
parameter_list|(
name|_Statement
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_cond
parameter_list|(
name|_Cond
parameter_list|,
name|_Msg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_valid_range
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_sorted
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_sorted_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_partitioned
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_partitioned_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|,
name|_Pred
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_heap
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_heap_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_nonempty
parameter_list|()
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_string
parameter_list|(
name|_String
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_string_len
parameter_list|(
name|_String
parameter_list|,
name|_Len
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_subscript
parameter_list|(
name|_N
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<debug/macros.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|namespace
name|__debug
block|{
comment|// Avoid the use of assert, because we're trying to keep the<cassert>
comment|// include out of the mix.
specifier|inline
name|void
name|__replacement_assert
parameter_list|(
specifier|const
name|char
modifier|*
name|__file
parameter_list|,
name|int
name|__line
parameter_list|,
specifier|const
name|char
modifier|*
name|__function
parameter_list|,
specifier|const
name|char
modifier|*
name|__condition
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s:%d: %s: Assertion '%s' failed.\n"
argument_list|,
name|__file
argument_list|,
name|__line
argument_list|,
name|__function
argument_list|,
name|__condition
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
comment|// namespace __debug
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_ASSERT
parameter_list|(
name|_Condition
parameter_list|)
define|\
value|do 									    \   {									    \     if (! (_Condition))                                                     \       std::__debug::__replacement_assert(__FILE__, __LINE__,		    \ 					 __PRETTY_FUNCTION__, #_Condition); \   } while (false)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_DEBUG_PEDANTIC
end_ifdef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_PEDASSERT
parameter_list|(
name|_Condition
parameter_list|)
value|_GLIBCXX_DEBUG_ASSERT(_Condition)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_PEDASSERT
parameter_list|(
name|_Condition
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_ONLY
parameter_list|(
name|_Statement
parameter_list|)
value|_Statement
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_cond
parameter_list|(
name|_Cond
parameter_list|,
name|_Msg
parameter_list|)
value|_GLIBCXX_DEBUG_VERIFY(_Cond,_Msg)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_valid_range
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_sorted
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_sorted(_First,_Last)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_sorted_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_sorted_pred(_First,_Last,_Pred)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_partitioned
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|)
define|\
value|__glibcxx_check_partitioned(_First,_Last,_Value)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_partitioned_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_partitioned_pred(_First,_Last,_Value,_Pred)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_heap
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_heap(_First,_Last)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_heap_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_heap_pred(_First,_Last,_Pred)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_nonempty
parameter_list|()
value|__glibcxx_check_nonempty()
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_string
parameter_list|(
name|_String
parameter_list|)
value|__glibcxx_check_string(_String)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_string_len
parameter_list|(
name|_String
parameter_list|,
name|_Len
parameter_list|)
define|\
value|__glibcxx_check_string_len(_String,_Len)
end_define

begin_define
define|#
directive|define
name|__glibcxx_requires_subscript
parameter_list|(
name|_N
parameter_list|)
value|__glibcxx_check_subscript(_N)
end_define

begin_include
include|#
directive|include
file|<debug/functions.h>
end_include

begin_include
include|#
directive|include
file|<debug/formatter.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCXX_DEBUG_MACRO_SWITCH_H
end_comment

end_unit

