begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// String support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 21 Strings library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file stringfwd.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRINGFWD_H
end_ifndef

begin_define
define|#
directive|define
name|_STRINGFWD_H
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

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
name|_Alloc
operator|>
name|class
name|allocator
expr_stmt|;
name|template
operator|<
name|class
name|_CharT
operator|>
expr|struct
name|char_traits
expr_stmt|;
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|basic_string
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|char_traits
operator|<
name|char
operator|>
expr_stmt|;
typedef|typedef
name|basic_string
operator|<
name|char
operator|>
name|string
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
name|template
operator|<
operator|>
expr|struct
name|char_traits
operator|<
name|wchar_t
operator|>
expr_stmt|;
typedef|typedef
name|basic_string
operator|<
name|wchar_t
operator|>
name|wstring
expr_stmt|;
endif|#
directive|endif
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
comment|// _STRINGFWD_H
end_comment

end_unit

