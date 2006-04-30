begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Stream iterators
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
comment|/** @file stream_iterator.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STREAM_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_STREAM_ITERATOR_H
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
file|<debug/debug.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/// Provides input iterator semantics for streams.
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_CharT
operator|=
name|char
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
name|_Dist
operator|=
name|ptrdiff_t
operator|>
name|class
name|istream_iterator
operator|:
name|public
name|iterator
operator|<
name|input_iterator_tag
operator|,
name|_Tp
operator|,
name|_Dist
operator|,
specifier|const
name|_Tp
operator|*
operator|,
specifier|const
name|_Tp
operator|&
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
typedef|typedef
name|_Traits
name|traits_type
typedef|;
typedef|typedef
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|istream_type
expr_stmt|;
name|private
label|:
name|istream_type
modifier|*
name|_M_stream
decl_stmt|;
name|_Tp
name|_M_value
decl_stmt|;
name|bool
name|_M_ok
decl_stmt|;
name|public
label|:
comment|///  Construct end of input stream iterator.
name|istream_iterator
argument_list|()
operator|:
name|_M_stream
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_ok
argument_list|(
argument|false
argument_list|)
block|{}
comment|///  Construct start of input stream iterator.
name|istream_iterator
argument_list|(
name|istream_type
operator|&
name|__s
argument_list|)
operator|:
name|_M_stream
argument_list|(
argument|&__s
argument_list|)
block|{
name|_M_read
argument_list|()
block|; }
name|istream_iterator
argument_list|(
specifier|const
name|istream_iterator
operator|&
name|__obj
argument_list|)
operator|:
name|_M_stream
argument_list|(
name|__obj
operator|.
name|_M_stream
argument_list|)
operator|,
name|_M_value
argument_list|(
name|__obj
operator|.
name|_M_value
argument_list|)
operator|,
name|_M_ok
argument_list|(
argument|__obj._M_ok
argument_list|)
block|{ }
specifier|const
name|_Tp
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|__glibcxx_requires_cond
argument_list|(
name|_M_ok
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_deref_istream
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
return|return
name|_M_value
return|;
block|}
specifier|const
name|_Tp
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
operator|(
name|operator
operator|*
operator|(
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|istream_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|__glibcxx_requires_cond
argument_list|(
name|_M_ok
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_inc_istream
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
name|_M_read
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|istream_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|__glibcxx_requires_cond
argument_list|(
name|_M_ok
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_inc_istream
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
name|istream_iterator
name|__tmp
operator|=
operator|*
name|this
block|;
name|_M_read
argument_list|()
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|_M_equal
argument_list|(
specifier|const
name|istream_iterator
operator|&
name|__x
argument_list|)
decl|const
block|{
return|return
operator|(
name|_M_ok
operator|==
name|__x
operator|.
name|_M_ok
operator|)
operator|&&
operator|(
operator|!
name|_M_ok
operator|||
name|_M_stream
operator|==
name|__x
operator|.
name|_M_stream
operator|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function
name|void
name|_M_read
parameter_list|()
block|{
name|_M_ok
operator|=
operator|(
name|_M_stream
operator|&&
operator|*
name|_M_stream
operator|)
condition|?
name|true
else|:
name|false
expr_stmt|;
if|if
condition|(
name|_M_ok
condition|)
block|{
operator|*
name|_M_stream
operator|>>
name|_M_value
expr_stmt|;
name|_M_ok
operator|=
operator|*
name|_M_stream
condition|?
name|true
else|:
name|false
expr_stmt|;
block|}
block|}
end_function

begin_comment
unit|};
comment|///  Return true if x and y are both end or not end, or x and y are the same.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Dist
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|istream_iterator
operator|<
name|_Tp
operator|,
name|_CharT
operator|,
name|_Traits
operator|,
name|_Dist
operator|>
operator|&
name|__x
operator|,
specifier|const
name|istream_iterator
operator|<
name|_Tp
operator|,
name|_CharT
operator|,
name|_Traits
operator|,
name|_Dist
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|_M_equal
argument_list|(
name|__y
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|///  Return false if x and y are both end or not end, or x and y are the same.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_CharT
operator|,
name|class
name|_Traits
operator|,
name|class
name|_Dist
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|istream_iterator
operator|<
name|_Tp
operator|,
name|_CharT
operator|,
name|_Traits
operator|,
name|_Dist
operator|>
operator|&
name|__x
operator|,
specifier|const
name|istream_iterator
operator|<
name|_Tp
operator|,
name|_CharT
operator|,
name|_Traits
operator|,
name|_Dist
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
name|__x
operator|.
name|_M_equal
argument_list|(
name|__y
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Provides output iterator semantics for streams.    *    *  This class provides an iterator to write to an ostream.  The type Tp is    *  the only type written by this iterator and there must be an    *  operator<<(Tp) defined.    *    *  @param  Tp  The type to write to the ostream.    *  @param  CharT  The ostream char_type.    *  @param  Traits  The ostream char_traits.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_CharT
operator|=
name|char
operator|,
name|typename
name|_Traits
operator|=
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|ostream_iterator
operator|:
name|public
name|iterator
operator|<
name|output_iterator_tag
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|,
name|void
operator|>
block|{
name|public
operator|:
comment|//@{
comment|/// Public typedef
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_Traits
name|traits_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|ostream_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|ostream_type
modifier|*
name|_M_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_string
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Construct from an ostream.
end_comment

begin_expr_stmt
name|ostream_iterator
argument_list|(
name|ostream_type
operator|&
name|__s
argument_list|)
operator|:
name|_M_stream
argument_list|(
operator|&
name|__s
argument_list|)
operator|,
name|_M_string
argument_list|(
literal|0
argument_list|)
block|{}
comment|/**        *  Construct from an ostream.        *        *  The delimiter string @a c is written to the stream after every Tp        *  written to the stream.  The delimiter is not copied, and thus must        *  not be destroyed while this iterator is in use.        *        *  @param  s  Underlying ostream to write to.        *  @param  c  CharT delimiter string to insert.       */
name|ostream_iterator
argument_list|(
name|ostream_type
operator|&
name|__s
argument_list|,
specifier|const
name|_CharT
operator|*
name|__c
argument_list|)
operator|:
name|_M_stream
argument_list|(
operator|&
name|__s
argument_list|)
operator|,
name|_M_string
argument_list|(
argument|__c
argument_list|)
block|{ }
comment|/// Copy constructor.
name|ostream_iterator
argument_list|(
specifier|const
name|ostream_iterator
operator|&
name|__obj
argument_list|)
operator|:
name|_M_stream
argument_list|(
name|__obj
operator|.
name|_M_stream
argument_list|)
operator|,
name|_M_string
argument_list|(
argument|__obj._M_string
argument_list|)
block|{ }
comment|/// Writes @a value to underlying ostream using operator<<.  If
comment|/// constructed with delimiter string, writes delimiter to ostream.
name|ostream_iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|_Tp
operator|&
name|__value
operator|)
block|{
name|__glibcxx_requires_cond
argument_list|(
name|_M_stream
operator|!=
literal|0
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_output_ostream
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
operator|*
name|_M_stream
operator|<<
name|__value
block|;
if|if
condition|(
name|_M_string
condition|)
operator|*
name|_M_stream
operator|<<
name|_M_string
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}        ostream_iterator
operator|&
name|operator
operator|*
operator|(
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ostream_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ostream_iterator
operator|&
name|operator
operator|++
operator|(
name|int
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
unit|}; }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

