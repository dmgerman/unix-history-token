begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Streambuf iterators
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002
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
comment|// XXX Should specialize copy, find algorithms for streambuf iterators.
end_comment

begin_comment
comment|/** @file streambuf_iterator.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_STREAMBUF_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_STREAMBUF_ITERATOR_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_decl_stmt
name|namespace
name|std
block|{
comment|// 24.5.3 Template class istreambuf_iterator
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
typedef|typedef
name|_CharT
name|char_type
typedef|;
typedef|typedef
name|_Traits
name|traits_type
typedef|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|int_type
name|int_type
expr_stmt|;
typedef|typedef
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|streambuf_type
expr_stmt|;
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
comment|// 24.5.3 istreambuf_iterator
comment|// p 1
comment|// If the end of stream is reached (streambuf_type::sgetc()
comment|// returns traits_type::eof()), the iterator becomes equal to
comment|// the "end of stream" iterator value.
comment|// NB: This implementation assumes the "end of stream" value
comment|// is EOF, or -1.
name|mutable
name|streambuf_type
modifier|*
name|_M_sbuf
decl_stmt|;
name|int_type
name|_M_c
decl_stmt|;
name|public
label|:
name|istreambuf_iterator
argument_list|()
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
argument|-
literal|2
argument_list|)
block|{ }
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
argument|-
literal|2
argument_list|)
block|{ }
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
argument|-
literal|2
argument_list|)
block|{ }
comment|// NB: The result of operator*() on an end of stream is undefined.
name|char_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
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
name|istreambuf_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
if|if
condition|(
name|_M_sbuf
operator|&&
name|_M_sbuf
operator|->
name|sbumpc
argument_list|()
operator|==
name|traits_type
operator|::
name|eof
argument_list|()
condition|)
name|_M_sbuf
operator|=
literal|0
expr_stmt|;
else|else
name|_M_c
operator|=
operator|-
literal|2
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|istreambuf_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|istreambuf_iterator
name|__old
operator|=
operator|*
name|this
block|;
if|if
condition|(
name|_M_sbuf
operator|&&
operator|(
name|__old
operator|.
name|_M_c
operator|=
name|_M_sbuf
operator|->
name|sbumpc
argument_list|()
operator|)
operator|==
name|traits_type
operator|::
name|eof
argument_list|()
condition|)
name|_M_sbuf
operator|=
literal|0
expr_stmt|;
else|else
name|_M_c
operator|=
operator|-
literal|2
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__old
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|_GLIBCPP_RESOLVE_LIB_DEFECTS
end_ifdef

begin_comment
comment|// 110 istreambuf_iterator::equal not const
end_comment

begin_comment
comment|// NB: there is also number 111 (NAD, Future) pending on this function.
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
name|int_type
name|__eof
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
block|;
name|bool
name|__thiseof
operator|=
name|_M_get
argument_list|()
operator|==
name|__eof
block|;
name|bool
name|__beof
operator|=
name|__b
operator|.
name|_M_get
argument_list|()
operator|==
name|__eof
block|;
return|return
operator|(
name|__thiseof
operator|&&
name|__beof
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

begin_endif
endif|#
directive|endif
end_endif

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
name|int_type
name|__ret
operator|=
name|traits_type
operator|::
name|eof
argument_list|()
block|;
if|if
condition|(
name|_M_sbuf
condition|)
block|{
if|if
condition|(
name|_M_c
operator|!=
name|static_cast
operator|<
name|int_type
operator|>
operator|(
operator|-
literal|2
operator|)
condition|)
name|__ret
operator|=
name|_M_c
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|__ret
operator|=
name|_M_sbuf
operator|->
name|sgetc
argument_list|()
operator|)
operator|==
name|traits_type
operator|::
name|eof
argument_list|()
condition|)
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

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

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

begin_expr_stmt
specifier|inline
name|ostreambuf_iterator
argument_list|(
argument|ostream_type& __s
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
name|_M_failed
argument_list|(
argument|!_M_sbuf
argument_list|)
block|{ }
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
name|ostreambuf_iterator
operator|&
name|operator
operator|=
operator|(
name|_CharT
name|__c
operator|)
expr_stmt|;
end_expr_stmt

begin_function
name|ostreambuf_iterator
modifier|&
name|operator
modifier|*
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_function

begin_expr_stmt
name|ostreambuf_iterator
operator|&
name|operator
operator|++
operator|(
name|int
operator|)
name|throw
argument_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ostreambuf_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
name|throw
argument_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

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
name|ostreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|&
name|ostreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|::
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
unit|} }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

