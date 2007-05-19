begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Helpers for ostream inserters -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2007 Free Software Foundation, Inc.
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
comment|/** @file ostream_insert.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSTREAM_INSERT_H
end_ifndef

begin_define
define|#
directive|define
name|_OSTREAM_INSERT_H
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
file|<iosfwd>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|void
name|__ostream_write
argument_list|(
argument|basic_ostream<_CharT
argument_list|,
argument|_Traits>& __out
argument_list|,
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|{
typedef|typedef
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostream_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__ostream_type
operator|::
name|ios_base
name|__ios_base
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|streamsize
name|__put
init|=
name|__out
operator|.
name|rdbuf
argument_list|()
operator|->
name|sputn
argument_list|(
name|__s
argument_list|,
name|__n
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|__put
operator|!=
name|__n
condition|)
name|__out
operator|.
name|setstate
argument_list|(
name|__ios_base
operator|::
name|badbit
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|void
name|__ostream_fill
argument_list|(
argument|basic_ostream<_CharT
argument_list|,
argument|_Traits>& __out
argument_list|,
argument|streamsize __n
argument_list|)
block|{
typedef|typedef
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostream_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__ostream_type
operator|::
name|ios_base
name|__ios_base
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|_CharT
name|__c
init|=
name|__out
operator|.
name|fill
argument_list|()
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
block|{
specifier|const
name|typename
name|_Traits
operator|::
name|int_type
name|__put
operator|=
name|__out
operator|.
name|rdbuf
argument_list|()
operator|->
name|sputc
argument_list|(
name|__c
argument_list|)
expr_stmt|;
if|if
condition|(
name|_Traits
operator|::
name|eq_int_type
argument_list|(
name|__put
argument_list|,
name|_Traits
operator|::
name|eof
argument_list|()
argument_list|)
condition|)
block|{
name|__out
operator|.
name|setstate
argument_list|(
name|__ios_base
operator|::
name|badbit
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_for

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__ostream_insert
argument_list|(
argument|basic_ostream<_CharT
argument_list|,
argument|_Traits>& __out
argument_list|,
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|{
typedef|typedef
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostream_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__ostream_type
operator|::
name|ios_base
name|__ios_base
expr_stmt|;
end_typedef

begin_expr_stmt
name|typename
name|__ostream_type
operator|::
name|sentry
name|__cerb
argument_list|(
name|__out
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__cerb
condition|)
block|{
name|try
block|{
specifier|const
name|streamsize
name|__w
init|=
name|__out
operator|.
name|width
argument_list|()
decl_stmt|;
if|if
condition|(
name|__w
operator|>
name|__n
condition|)
block|{
specifier|const
name|bool
name|__left
init|=
operator|(
operator|(
name|__out
operator|.
name|flags
argument_list|()
operator|&
name|__ios_base
operator|::
name|adjustfield
operator|)
operator|==
name|__ios_base
operator|::
name|left
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|__left
condition|)
name|__ostream_fill
argument_list|(
name|__out
argument_list|,
name|__w
operator|-
name|__n
argument_list|)
expr_stmt|;
if|if
condition|(
name|__out
operator|.
name|good
argument_list|()
condition|)
name|__ostream_write
argument_list|(
name|__out
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
expr_stmt|;
if|if
condition|(
name|__left
operator|&&
name|__out
operator|.
name|good
argument_list|()
condition|)
name|__ostream_fill
argument_list|(
name|__out
argument_list|,
name|__w
operator|-
name|__n
argument_list|)
expr_stmt|;
block|}
else|else
name|__ostream_write
argument_list|(
name|__out
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
expr_stmt|;
name|__out
operator|.
name|width
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|__out
operator|.
name|_M_setstate
argument_list|(
name|__ios_base
operator|::
name|badbit
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_return
return|return
name|__out
return|;
end_return

begin_endif
unit|}  _GLIBCXX_END_NAMESPACE
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSTREAM_INSERT_H */
end_comment

end_unit

