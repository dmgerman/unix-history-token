begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// filebuf with __enc_traits state type -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2002, 2003 Free Software Foundation, Inc.
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

begin_include
include|#
directive|include
file|<fstream>
end_include

begin_include
include|#
directive|include
file|<locale>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|// Custom traits type with __enc_traits for the state type, and the
comment|// associated fpos<__enc_traits> for the position type, all other
comment|// bits equivalent to the required char_traits instantiations.
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|enc_char_traits
operator|:
name|public
name|std
operator|::
name|char_traits
operator|<
name|_CharT
operator|>
block|{
typedef|typedef
name|std
operator|::
name|__enc_traits
name|state_type
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|fpos
operator|<
name|state_type
operator|>
name|pos_type
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|enc_filebuf
operator|:
name|public
name|std
operator|::
name|basic_filebuf
operator|<
name|_CharT
operator|,
name|enc_char_traits
operator|<
name|_CharT
operator|>
expr|>
block|{
name|public
operator|:
typedef|typedef
name|enc_char_traits
operator|<
name|_CharT
operator|>
name|traits_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|state_type
name|state_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|enc_filebuf
argument_list|(
name|state_type
operator|&
name|__state
argument_list|)
operator|:
name|std
operator|::
name|basic_filebuf
operator|<
name|_CharT
operator|,
name|enc_char_traits
operator|<
name|_CharT
operator|>
expr|>
operator|(
operator|)
block|{
name|this
operator|->
name|_M_state_beg
operator|=
name|__state
block|;
name|this
operator|->
name|_M_state_beg
operator|.
name|_M_init
argument_list|()
block|;       }
name|private
operator|:
comment|// concept requirements:
comment|// Set state type to something useful.
comment|// Something more than copyconstructible is needed here, so
comment|// require default and copy constructible + assignment operator.
name|__glibcxx_class_requires
argument_list|(
argument|state_type
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
end_expr_stmt

begin_comment
unit|}; }
comment|// namespace __gnu_cxx
end_comment

end_unit

