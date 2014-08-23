begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Streambuf iterators
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006
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
comment|/** @file streambuf_iterator.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STREAMBUF_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_STREAMBUF_ITERATOR_H
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
file|<streambuf>
end_include

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|// 24.5.3 Template class istreambuf_iterator
end_comment

begin_comment
comment|/// Provides input iterator semantics for streambufs.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|istreambuf_iterator
operator|:
name|public
name|iterator
operator|<
name|input_iterator_tag
operator|,
name|_CharT
operator|,
name|typename
name|_Traits
operator|::
name|off_type
operator|,
name|_CharT
operator|*
operator|,
name|_CharT
operator|&
operator|>
block|{
name|public
operator|:
comment|// Types:
comment|//@{
comment|/// Public typedefs
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
name|typename
name|_Traits
operator|::
name|int_type
name|int_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|streambuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|istream_type
expr_stmt|;
end_typedef

begin_comment
comment|//@}
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT2
operator|>
name|friend
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT2
operator|>
expr|>
operator|::
name|__type
name|copy
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|ostreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT2
operator|>
name|friend
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|_CharT2
operator|*
operator|>
operator|::
name|__type
name|__copy_aux
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|_CharT2
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT2
operator|>
name|friend
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
expr|>
operator|::
name|__type
name|find
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
specifier|const
name|_CharT2
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// 24.5.3 istreambuf_iterator
end_comment

begin_comment
comment|// p 1
end_comment

begin_comment
comment|// If the end of stream is reached (streambuf_type::sgetc()
end_comment

begin_comment
comment|// returns traits_type::eof()), the iterator becomes equal to
end_comment

begin_comment
comment|// the "end of stream" iterator value.
end_comment

begin_comment
comment|// NB: This implementation assumes the "end of stream" value
end_comment

begin_comment
comment|// is EOF, or -1.
end_comment

begin_decl_stmt
name|mutable
name|streambuf_type
modifier|*
name|_M_sbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|int_type
name|_M_c
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|///  Construct end of input stream iterator.
end_comment

begin_macro
name|istreambuf_iterator
argument_list|()
end_macro

begin_expr_stmt
name|throw
argument_list|()
operator|:
name|_M_sbuf
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_c
argument_list|(
argument|traits_type::eof()
argument_list|)
block|{ }
comment|///  Construct start of input stream iterator.
name|istreambuf_iterator
argument_list|(
argument|istream_type& __s
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_sbuf
argument_list|(
name|__s
operator|.
name|rdbuf
argument_list|()
argument_list|)
operator|,
name|_M_c
argument_list|(
argument|traits_type::eof()
argument_list|)
block|{ }
comment|///  Construct start of streambuf iterator.
name|istreambuf_iterator
argument_list|(
argument|streambuf_type* __s
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_sbuf
argument_list|(
name|__s
argument_list|)
operator|,
name|_M_c
argument_list|(
argument|traits_type::eof()
argument_list|)
block|{ }
comment|///  Return the current character pointed to by iterator.  This returns
comment|///  streambuf.sgetc().  It cannot be assigned.  NB: The result of
comment|///  operator*() on an end of stream is undefined.
name|char_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|_GLIBCXX_DEBUG_PEDANTIC
comment|// Dereferencing a past-the-end istreambuf_iterator is a
comment|// libstdc++ extension
name|__glibcxx_requires_cond
argument_list|(
operator|!
name|_M_at_eof
argument_list|()
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_deref_istreambuf
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
endif|#
directive|endif
return|return
name|traits_type
operator|::
name|to_char_type
argument_list|(
name|_M_get
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Advance the iterator.  Calls streambuf.sbumpc().
end_comment

begin_expr_stmt
name|istreambuf_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|__glibcxx_requires_cond
argument_list|(
operator|!
name|_M_at_eof
argument_list|()
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_inc_istreambuf
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|_M_sbuf
condition|)
block|{
name|_M_sbuf
operator|->
name|sbumpc
argument_list|()
expr_stmt|;
name|_M_c
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// Advance the iterator.  Calls streambuf.sbumpc().
end_comment

begin_expr_stmt
unit|istreambuf_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|__glibcxx_requires_cond
argument_list|(
operator|!
name|_M_at_eof
argument_list|()
argument_list|,
name|_M_message
argument_list|(
name|__gnu_debug
operator|::
name|__msg_inc_istreambuf
argument_list|)
operator|.
name|_M_iterator
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
block|;
name|istreambuf_iterator
name|__old
operator|=
operator|*
name|this
block|;
if|if
condition|(
name|_M_sbuf
condition|)
block|{
name|__old
operator|.
name|_M_c
operator|=
name|_M_sbuf
operator|->
name|sbumpc
argument_list|()
expr_stmt|;
name|_M_c
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__old
return|;
end_return

begin_comment
unit|}
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 110 istreambuf_iterator::equal not const
end_comment

begin_comment
comment|// NB: there is also number 111 (NAD, Future) pending on this function.
end_comment

begin_comment
comment|/// Return true both iterators are end or both are not end.
end_comment

begin_macro
unit|bool
name|equal
argument_list|(
argument|const istreambuf_iterator& __b
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
specifier|const
name|bool
name|__thiseof
operator|=
name|_M_at_eof
argument_list|()
block|;
specifier|const
name|bool
name|__beof
operator|=
name|__b
operator|.
name|_M_at_eof
argument_list|()
block|;
return|return
operator|(
operator|(
name|__thiseof
operator|&&
name|__beof
operator|)
operator|||
operator|(
operator|!
name|__thiseof
operator|&&
operator|!
name|__beof
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|int_type
name|_M_get
argument_list|()
specifier|const
block|{
specifier|const
name|int_type
name|__eof
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
block|;
name|int_type
name|__ret
operator|=
name|__eof
block|;
if|if
condition|(
name|_M_sbuf
condition|)
block|{
if|if
condition|(
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|_M_c
argument_list|,
name|__eof
argument_list|)
condition|)
name|__ret
operator|=
name|_M_c
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
operator|(
name|__ret
operator|=
name|_M_sbuf
operator|->
name|sgetc
argument_list|()
operator|)
argument_list|,
name|__eof
argument_list|)
condition|)
name|_M_c
operator|=
name|__ret
expr_stmt|;
else|else
name|_M_sbuf
operator|=
literal|0
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__ret
return|;
end_return

begin_macro
unit|}        bool
name|_M_at_eof
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
specifier|const
name|int_type
name|__eof
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
block|;
return|return
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|_M_get
argument_list|()
argument_list|,
name|__eof
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__a
operator|,
specifier|const
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__b
operator|)
block|{
return|return
name|__a
operator|.
name|equal
argument_list|(
name|__b
argument_list|)
return|;
block|}
end_expr_stmt

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
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__a
operator|,
specifier|const
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|__b
operator|)
block|{
return|return
operator|!
name|__a
operator|.
name|equal
argument_list|(
name|__b
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Provides output iterator semantics for streambufs.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|ostreambuf_iterator
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
comment|// Types:
comment|//@{
comment|/// Public typedefs
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
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|streambuf_type
expr_stmt|;
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

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT2
operator|>
name|friend
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT2
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT2
operator|>
expr|>
operator|::
name|__type
name|copy
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|,
name|ostreambuf_iterator
operator|<
name|_CharT2
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|streambuf_type
modifier|*
name|_M_sbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|_M_failed
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|///  Construct output iterator from ostream.
end_comment

begin_macro
name|ostreambuf_iterator
argument_list|(
argument|ostream_type& __s
argument_list|)
end_macro

begin_expr_stmt
name|throw
argument_list|()
operator|:
name|_M_sbuf
argument_list|(
name|__s
operator|.
name|rdbuf
argument_list|()
argument_list|)
operator|,
name|_M_failed
argument_list|(
argument|!_M_sbuf
argument_list|)
block|{ }
comment|///  Construct output iterator from streambuf.
name|ostreambuf_iterator
argument_list|(
argument|streambuf_type* __s
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_sbuf
argument_list|(
name|__s
argument_list|)
operator|,
name|_M_failed
argument_list|(
argument|!_M_sbuf
argument_list|)
block|{ }
comment|///  Write character to streambuf.  Calls streambuf.sputc().
name|ostreambuf_iterator
operator|&
name|operator
operator|=
operator|(
name|_CharT
name|__c
operator|)
block|{
if|if
condition|(
operator|!
name|_M_failed
operator|&&
name|_Traits
operator|::
name|eq_int_type
argument_list|(
name|_M_sbuf
operator|->
name|sputc
argument_list|(
name|__c
argument_list|)
argument_list|,
name|_Traits
operator|::
name|eof
argument_list|()
argument_list|)
condition|)
name|_M_failed
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// Return *this.
end_comment

begin_expr_stmt
unit|ostreambuf_iterator
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

begin_comment
comment|/// Return *this.
end_comment

begin_expr_stmt
name|ostreambuf_iterator
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
comment|/// Return *this.
end_comment

begin_expr_stmt
name|ostreambuf_iterator
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

begin_comment
comment|/// Return true if previous operator=() failed.
end_comment

begin_expr_stmt
name|bool
name|failed
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_failed
return|;
block|}
end_expr_stmt

begin_function
name|ostreambuf_iterator
modifier|&
name|_M_put
parameter_list|(
specifier|const
name|_CharT
modifier|*
name|__ws
parameter_list|,
name|streamsize
name|__len
parameter_list|)
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
operator|!
name|_M_failed
argument_list|,
name|true
argument_list|)
operator|&&
name|__builtin_expect
argument_list|(
name|this
operator|->
name|_M_sbuf
operator|->
name|sputn
argument_list|(
name|__ws
argument_list|,
name|__len
argument_list|)
operator|!=
name|__len
argument_list|,
name|false
argument_list|)
condition|)
name|_M_failed
operator|=
name|true
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function

begin_comment
unit|};
comment|// Overloads for streambuf iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|copy
argument_list|(
argument|istreambuf_iterator<_CharT> __first
argument_list|,
argument|istreambuf_iterator<_CharT> __last
argument_list|,
argument|ostreambuf_iterator<_CharT> __result
argument_list|)
block|{
if|if
condition|(
name|__first
operator|.
name|_M_sbuf
operator|&&
operator|!
name|__last
operator|.
name|_M_sbuf
operator|&&
operator|!
name|__result
operator|.
name|_M_failed
condition|)
block|{
name|bool
name|__ineof
decl_stmt|;
name|__copy_streambufs_eof
argument_list|(
name|__first
operator|.
name|_M_sbuf
argument_list|,
name|__result
operator|.
name|_M_sbuf
argument_list|,
name|__ineof
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|__ineof
condition|)
name|__result
operator|.
name|_M_failed
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|__copy_aux
argument_list|(
argument|_CharT* __first
argument_list|,
argument|_CharT* __last
argument_list|,
argument|ostreambuf_iterator<_CharT> __result
argument_list|)
block|{
specifier|const
name|streamsize
name|__num
operator|=
name|__last
operator|-
name|__first
block|;
if|if
condition|(
name|__num
operator|>
literal|0
condition|)
name|__result
operator|.
name|_M_put
argument_list|(
name|__first
argument_list|,
name|__num
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|__copy_aux
argument_list|(
argument|const _CharT* __first
argument_list|,
argument|const _CharT* __last
argument_list|,
argument|ostreambuf_iterator<_CharT> __result
argument_list|)
block|{
specifier|const
name|streamsize
name|__num
operator|=
name|__last
operator|-
name|__first
block|;
if|if
condition|(
name|__num
operator|>
literal|0
condition|)
name|__result
operator|.
name|_M_put
argument_list|(
name|__first
argument_list|,
name|__num
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|_CharT
operator|*
operator|>
operator|::
name|__type
name|__copy_aux
argument_list|(
argument|istreambuf_iterator<_CharT> __first
argument_list|,
argument|istreambuf_iterator<_CharT> __last
argument_list|,
argument|_CharT* __result
argument_list|)
block|{
typedef|typedef
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
name|__is_iterator_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__is_iterator_type
operator|::
name|traits_type
name|traits_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|__is_iterator_type
operator|::
name|streambuf_type
name|streambuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|int_type
name|int_type
expr_stmt|;
end_typedef

begin_if
if|if
condition|(
name|__first
operator|.
name|_M_sbuf
operator|&&
operator|!
name|__last
operator|.
name|_M_sbuf
condition|)
block|{
name|streambuf_type
modifier|*
name|__sb
init|=
name|__first
operator|.
name|_M_sbuf
decl_stmt|;
name|int_type
name|__c
init|=
name|__sb
operator|->
name|sgetc
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|__c
argument_list|,
name|traits_type
operator|::
name|eof
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|streamsize
name|__n
init|=
name|__sb
operator|->
name|egptr
argument_list|()
operator|-
name|__sb
operator|->
name|gptr
argument_list|()
decl_stmt|;
if|if
condition|(
name|__n
operator|>
literal|1
condition|)
block|{
name|traits_type
operator|::
name|copy
argument_list|(
name|__result
argument_list|,
name|__sb
operator|->
name|gptr
argument_list|()
argument_list|,
name|__n
argument_list|)
expr_stmt|;
name|__sb
operator|->
name|gbump
argument_list|(
name|__n
argument_list|)
expr_stmt|;
name|__result
operator|+=
name|__n
expr_stmt|;
name|__c
operator|=
name|__sb
operator|->
name|underflow
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|*
name|__result
operator|++
operator|=
name|traits_type
operator|::
name|to_char_type
argument_list|(
name|__c
argument_list|)
expr_stmt|;
name|__c
operator|=
name|__sb
operator|->
name|snextc
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_if

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|find
argument_list|(
argument|istreambuf_iterator<_CharT> __first
argument_list|,
argument|istreambuf_iterator<_CharT> __last
argument_list|,
argument|const _CharT& __val
argument_list|)
block|{
typedef|typedef
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
name|__is_iterator_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__is_iterator_type
operator|::
name|traits_type
name|traits_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|__is_iterator_type
operator|::
name|streambuf_type
name|streambuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|int_type
name|int_type
expr_stmt|;
end_typedef

begin_if
if|if
condition|(
name|__first
operator|.
name|_M_sbuf
operator|&&
operator|!
name|__last
operator|.
name|_M_sbuf
condition|)
block|{
specifier|const
name|int_type
name|__ival
init|=
name|traits_type
operator|::
name|to_int_type
argument_list|(
name|__val
argument_list|)
decl_stmt|;
name|streambuf_type
modifier|*
name|__sb
init|=
name|__first
operator|.
name|_M_sbuf
decl_stmt|;
name|int_type
name|__c
init|=
name|__sb
operator|->
name|sgetc
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|__c
argument_list|,
name|traits_type
operator|::
name|eof
argument_list|()
argument_list|)
operator|&&
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|__c
argument_list|,
name|__ival
argument_list|)
condition|)
block|{
name|streamsize
name|__n
init|=
name|__sb
operator|->
name|egptr
argument_list|()
operator|-
name|__sb
operator|->
name|gptr
argument_list|()
decl_stmt|;
if|if
condition|(
name|__n
operator|>
literal|1
condition|)
block|{
specifier|const
name|_CharT
modifier|*
name|__p
init|=
name|traits_type
operator|::
name|find
argument_list|(
name|__sb
operator|->
name|gptr
argument_list|()
argument_list|,
name|__n
argument_list|,
name|__val
argument_list|)
decl_stmt|;
if|if
condition|(
name|__p
condition|)
name|__n
operator|=
name|__p
operator|-
name|__sb
operator|->
name|gptr
argument_list|()
expr_stmt|;
name|__sb
operator|->
name|gbump
argument_list|(
name|__n
argument_list|)
expr_stmt|;
name|__c
operator|=
name|__sb
operator|->
name|sgetc
argument_list|()
expr_stmt|;
block|}
else|else
name|__c
operator|=
name|__sb
operator|->
name|snextc
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|traits_type
operator|::
name|eq_int_type
argument_list|(
name|__c
argument_list|,
name|traits_type
operator|::
name|eof
argument_list|()
argument_list|)
condition|)
name|__first
operator|.
name|_M_c
operator|=
name|__c
expr_stmt|;
else|else
name|__first
operator|.
name|_M_sbuf
operator|=
literal|0
expr_stmt|;
block|}
end_if

begin_return
return|return
name|__first
return|;
end_return

begin_endif
unit|}  _GLIBCXX_END_NAMESPACE
endif|#
directive|endif
end_endif

end_unit

