begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// String based streams -*- C++ -*-
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
comment|/** @file sstream  *  This is a Standard C++ Library header.  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.7  String-based streams
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_SSTREAM
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_SSTREAM
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
file|<istream>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|// [27.7.1] template class basic_stringbuf
end_comment

begin_comment
comment|/**    *  @brief  The actual work of input and output (for std::string).    *    *  This class associates either or both of its input and output sequences    *  with a sequence of characters, which can be initialized from, or made    *  available as, a @c std::basic_string.  (Paraphrased from [27.7.1]/1.)    *    *  For this class, open modes (of type @c ios_base::openmode) have    *  @c in set if the input sequence can be read, and @c out set if the    *  output sequence can be written.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|basic_stringbuf
operator|:
name|public
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
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

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 251. basic_stringbuf missing allocator_type
end_comment

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
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

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|off_type
name|off_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_streambuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__streambuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|char_type
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|__string_type
operator|::
name|size_type
name|__size_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|/**        *  @if maint        *  Place to stash in || out || in | out settings for current stringbuf.        *  @endif       */
end_comment

begin_expr_stmt
name|ios_base
operator|::
name|openmode
name|_M_mode
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Data Members:
end_comment

begin_decl_stmt
name|__string_type
name|_M_string
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Constructors:
end_comment

begin_comment
comment|/**        *  @brief  Starts with an empty string buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  The default constructor initializes the parent class using its        *  own default ctor.       */
end_comment

begin_decl_stmt
name|explicit
name|basic_stringbuf
argument_list|(
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
operator||
name|ios_base
operator|::
name|out
argument_list|)
range|:
name|__streambuf_type
argument_list|()
decl_stmt|,
name|_M_mode
argument_list|(
name|__mode
argument_list|)
decl_stmt|,
name|_M_string
argument_list|()
block|{ }
end_decl_stmt

begin_comment
comment|/**        *  @brief  Starts with an existing string buffer.        *  @param  str  A string to copy as a starting buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  This constructor initializes the parent class using its        *  own default ctor.       */
end_comment

begin_decl_stmt
name|explicit
name|basic_stringbuf
argument_list|(
specifier|const
name|__string_type
operator|&
name|__str
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
operator||
name|ios_base
operator|::
name|out
argument_list|)
range|:
name|__streambuf_type
argument_list|()
decl_stmt|,
name|_M_mode
argument_list|()
decl_stmt|,
name|_M_string
argument_list|(
name|__str
operator|.
name|data
argument_list|()
argument_list|,
name|__str
operator|.
name|size
argument_list|()
argument_list|)
block|{
name|_M_stringbuf_init
argument_list|(
name|__mode
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Get and set:
end_comment

begin_comment
comment|/**        *  @brief  Copying out the string buffer.        *  @return  A copy of one of the underlying sequences.        *        *  "If the buffer is only created in input mode, the underlying        *  character sequence is equal to the input sequence; otherwise, it        *  is equal to the output sequence." [27.7.1.2]/1       */
end_comment

begin_expr_stmt
name|__string_type
name|str
argument_list|()
specifier|const
block|{
name|__string_type
name|__ret
block|;
if|if
condition|(
name|this
operator|->
name|pptr
argument_list|()
condition|)
block|{
comment|// The current egptr() may not be the actual string end.
if|if
condition|(
name|this
operator|->
name|pptr
argument_list|()
operator|>
name|this
operator|->
name|egptr
argument_list|()
condition|)
name|__ret
operator|=
name|__string_type
argument_list|(
name|this
operator|->
name|pbase
argument_list|()
argument_list|,
name|this
operator|->
name|pptr
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|__ret
operator|=
name|__string_type
argument_list|(
name|this
operator|->
name|pbase
argument_list|()
argument_list|,
name|this
operator|->
name|egptr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
name|__ret
operator|=
name|_M_string
expr_stmt|;
end_else

begin_return
return|return
name|__ret
return|;
end_return

begin_comment
unit|}
comment|/**        *  @brief  Setting a new buffer.        *  @param  s  The string to use as a new sequence.        *        *  Deallocates any previous stored sequence, then copies @a s to        *  use as a new one.       */
end_comment

begin_macro
unit|void
name|str
argument_list|(
argument|const __string_type& __s
argument_list|)
end_macro

begin_block
block|{
comment|// Cannot use _M_string = __s, since v3 strings are COW.
name|_M_string
operator|.
name|assign
argument_list|(
name|__s
operator|.
name|data
argument_list|()
argument_list|,
name|__s
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|_M_stringbuf_init
argument_list|(
name|_M_mode
argument_list|)
expr_stmt|;
block|}
end_block

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Common initialization code goes here.
end_comment

begin_decl_stmt
name|void
name|_M_stringbuf_init
argument_list|(
name|ios_base
operator|::
name|openmode
name|__mode
argument_list|)
block|{
name|_M_mode
operator|=
name|__mode
expr_stmt|;
name|__size_type
name|__len
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_M_mode
operator|&
operator|(
name|ios_base
operator|::
name|ate
operator||
name|ios_base
operator|::
name|app
operator|)
condition|)
name|__len
operator|=
name|_M_string
operator|.
name|size
argument_list|()
expr_stmt|;
name|_M_sync
argument_list|(
name|const_cast
operator|<
name|char_type
operator|*
operator|>
operator|(
name|_M_string
operator|.
name|data
argument_list|()
operator|)
argument_list|,
literal|0
argument_list|,
name|__len
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|virtual
name|streamsize
name|showmanyc
parameter_list|()
block|{
name|streamsize
name|__ret
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
condition|)
block|{
name|_M_update_egptr
argument_list|()
expr_stmt|;
name|__ret
operator|=
name|this
operator|->
name|egptr
argument_list|()
operator|-
name|this
operator|->
name|gptr
argument_list|()
expr_stmt|;
block|}
return|return
name|__ret
return|;
block|}
end_function

begin_function_decl
name|virtual
name|int_type
name|underflow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|int_type
name|pbackfail
parameter_list|(
name|int_type
name|__c
init|=
name|traits_type
operator|::
name|eof
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|int_type
name|overflow
parameter_list|(
name|int_type
name|__c
init|=
name|traits_type
operator|::
name|eof
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Manipulates the buffer.        *  @param  s  Pointer to a buffer area.        *  @param  n  Size of @a s.        *  @return  @c this        *        *  If no buffer has already been created, and both @a s and @a n are        *  non-zero, then @c s is used as a buffer; see        *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#2        *  for more.       */
end_comment

begin_function
name|virtual
name|__streambuf_type
modifier|*
name|setbuf
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
block|{
if|if
condition|(
name|__s
operator|&&
name|__n
operator|>=
literal|0
condition|)
block|{
comment|// This is implementation-defined behavior, and assumes
comment|// that an external char_type array of length __n exists
comment|// and has been pre-allocated. If this is not the case,
comment|// things will quickly blow up.
comment|// Step 1: Destroy the current internal array.
name|_M_string
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Step 2: Use the external array.
name|_M_sync
argument_list|(
name|__s
argument_list|,
name|__n
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|this
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|pos_type
name|seekoff
argument_list|(
name|off_type
name|__off
argument_list|,
name|ios_base
operator|::
name|seekdir
name|__way
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
operator||
name|ios_base
operator|::
name|out
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|pos_type
name|seekpos
argument_list|(
name|pos_type
name|__sp
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
operator||
name|ios_base
operator|::
name|out
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Internal function for correctly updating the internal buffer
end_comment

begin_comment
comment|// for a particular _M_string, due to initialization or re-sizing
end_comment

begin_comment
comment|// of an existing _M_string.
end_comment

begin_function_decl
name|void
name|_M_sync
parameter_list|(
name|char_type
modifier|*
name|__base
parameter_list|,
name|__size_type
name|__i
parameter_list|,
name|__size_type
name|__o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Internal function for correctly updating egptr() to the actual
end_comment

begin_comment
comment|// string end.
end_comment

begin_function
name|void
name|_M_update_egptr
parameter_list|()
block|{
specifier|const
name|bool
name|__testin
init|=
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|pptr
argument_list|()
operator|&&
name|this
operator|->
name|pptr
argument_list|()
operator|>
name|this
operator|->
name|egptr
argument_list|()
condition|)
block|{
if|if
condition|(
name|__testin
condition|)
name|this
operator|->
name|setg
argument_list|(
name|this
operator|->
name|eback
argument_list|()
argument_list|,
name|this
operator|->
name|gptr
argument_list|()
argument_list|,
name|this
operator|->
name|pptr
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|this
operator|->
name|setg
argument_list|(
name|this
operator|->
name|pptr
argument_list|()
argument_list|,
name|this
operator|->
name|pptr
argument_list|()
argument_list|,
name|this
operator|->
name|pptr
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
unit|};
comment|// [27.7.2] Template class basic_istringstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling input for std::string.    *    *  This class supports reading from objects of type std::basic_string,    *  using the inherited functions from std::basic_istream.  To control    *  the associated sequence, an instance of std::basic_stringbuf is used,    *  which this page refers to as @c sb.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|basic_istringstream
operator|:
name|public
name|basic_istream
operator|<
name|_CharT
operator|,
name|_Traits
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

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 251. basic_stringbuf missing allocator_type
end_comment

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
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

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|off_type
name|off_type
expr_stmt|;
end_typedef

begin_comment
comment|// Non-standard types:
end_comment

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_stringbuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__stringbuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_istream
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__istream_type
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|__stringbuf_type
name|_M_stringbuf
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Constructors:
end_comment

begin_comment
comment|/**        *  @brief  Default constructor starts with an empty string buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  @c ios_base::in is automatically included in @a mode.        *        *  Initializes @c sb using @c mode|in, and passes @c&sb to the base        *  class initializer.  Does not allocate any buffer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_istringstream
argument_list|(
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
argument_list|)
range|:
name|__istream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__mode
operator||
name|ios_base
operator|::
name|in
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Starts with an existing string buffer.        *  @param  str  A string to copy as a starting buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  @c ios_base::in is automatically included in @a mode.        *        *  Initializes @c sb using @a str and @c mode|in, and passes @c&sb        *  to the base class initializer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_istringstream
argument_list|(
specifier|const
name|__string_type
operator|&
name|__str
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|in
argument_list|)
range|:
name|__istream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__str
argument_list|,
name|__mode
operator||
name|ios_base
operator|::
name|in
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  The destructor does nothing.        *        *  The buffer is deallocated by the stringbuf object, not the        *  formatting stream.       */
end_comment

begin_expr_stmt
operator|~
name|basic_istringstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_stringbuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__stringbuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__stringbuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_stringbuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Copying out the string buffer.        *  @return  @c rdbuf()->str()       */
end_comment

begin_expr_stmt
name|__string_type
name|str
argument_list|()
specifier|const
block|{
return|return
name|_M_stringbuf
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Setting a new buffer.        *  @param  s  The string to use as a new sequence.        *        *  Calls @c rdbuf()->str(s).       */
end_comment

begin_function
name|void
name|str
parameter_list|(
specifier|const
name|__string_type
modifier|&
name|__s
parameter_list|)
block|{
name|_M_stringbuf
operator|.
name|str
argument_list|(
name|__s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|// [27.7.3] Template class basic_ostringstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling output for std::string.    *    *  This class supports writing to objects of type std::basic_string,    *  using the inherited functions from std::basic_ostream.  To control    *  the associated sequence, an instance of std::basic_stringbuf is used,    *  which this page refers to as @c sb.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|basic_ostringstream
operator|:
name|public
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
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

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 251. basic_stringbuf missing allocator_type
end_comment

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
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

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|off_type
name|off_type
expr_stmt|;
end_typedef

begin_comment
comment|// Non-standard types:
end_comment

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_stringbuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__stringbuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_ostream
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__ostream_type
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|__stringbuf_type
name|_M_stringbuf
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Constructors/destructor:
end_comment

begin_comment
comment|/**        *  @brief  Default constructor starts with an empty string buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  @c ios_base::out is automatically included in @a mode.        *        *  Initializes @c sb using @c mode|out, and passes @c&sb to the base        *  class initializer.  Does not allocate any buffer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_ostringstream
argument_list|(
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|out
argument_list|)
range|:
name|__ostream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__mode
operator||
name|ios_base
operator|::
name|out
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Starts with an existing string buffer.        *  @param  str  A string to copy as a starting buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  @c ios_base::out is automatically included in @a mode.        *        *  Initializes @c sb using @a str and @c mode|out, and passes @c&sb        *  to the base class initializer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_ostringstream
argument_list|(
specifier|const
name|__string_type
operator|&
name|__str
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|out
argument_list|)
range|:
name|__ostream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__str
argument_list|,
name|__mode
operator||
name|ios_base
operator|::
name|out
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  The destructor does nothing.        *        *  The buffer is deallocated by the stringbuf object, not the        *  formatting stream.       */
end_comment

begin_expr_stmt
operator|~
name|basic_ostringstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_stringbuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__stringbuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__stringbuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_stringbuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Copying out the string buffer.        *  @return  @c rdbuf()->str()       */
end_comment

begin_expr_stmt
name|__string_type
name|str
argument_list|()
specifier|const
block|{
return|return
name|_M_stringbuf
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Setting a new buffer.        *  @param  s  The string to use as a new sequence.        *        *  Calls @c rdbuf()->str(s).       */
end_comment

begin_function
name|void
name|str
parameter_list|(
specifier|const
name|__string_type
modifier|&
name|__s
parameter_list|)
block|{
name|_M_stringbuf
operator|.
name|str
argument_list|(
name|__s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|// [27.7.4] Template class basic_stringstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling input and output for std::string.    *    *  This class supports reading from and writing to objects of type    *  std::basic_string, using the inherited functions from    *  std::basic_iostream.  To control the associated sequence, an instance    *  of std::basic_stringbuf is used, which this page refers to as @c sb.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|basic_stringstream
operator|:
name|public
name|basic_iostream
operator|<
name|_CharT
operator|,
name|_Traits
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

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 251. basic_stringbuf missing allocator_type
end_comment

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
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

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|traits_type
operator|::
name|off_type
name|off_type
expr_stmt|;
end_typedef

begin_comment
comment|// Non-standard Types:
end_comment

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_stringbuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
name|__stringbuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_iostream
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__iostream_type
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|__stringbuf_type
name|_M_stringbuf
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Constructors/destructors
end_comment

begin_comment
comment|/**        *  @brief  Default constructor starts with an empty string buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  Initializes @c sb using @c mode, and passes @c&sb to the base        *  class initializer.  Does not allocate any buffer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_stringstream
argument_list|(
name|ios_base
operator|::
name|openmode
name|__m
operator|=
name|ios_base
operator|::
name|out
operator||
name|ios_base
operator|::
name|in
argument_list|)
range|:
name|__iostream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__m
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Starts with an existing string buffer.        *  @param  str  A string to copy as a starting buffer.        *  @param  mode  Whether the buffer can read, or write, or both.        *        *  Initializes @c sb using @a str and @c mode, and passes @c&sb        *  to the base class initializer.        *        *  @if maint        *  That's a lie.  We initialize the base class with NULL, because the        *  string class does its own memory management.        *  @endif       */
end_comment

begin_decl_stmt
name|explicit
name|basic_stringstream
argument_list|(
specifier|const
name|__string_type
operator|&
name|__str
argument_list|,
name|ios_base
operator|::
name|openmode
name|__m
operator|=
name|ios_base
operator|::
name|out
operator||
name|ios_base
operator|::
name|in
argument_list|)
range|:
name|__iostream_type
argument_list|()
decl_stmt|,
name|_M_stringbuf
argument_list|(
name|__str
argument_list|,
name|__m
argument_list|)
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_stringbuf
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  The destructor does nothing.        *        *  The buffer is deallocated by the stringbuf object, not the        *  formatting stream.       */
end_comment

begin_expr_stmt
operator|~
name|basic_stringstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_stringbuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__stringbuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__stringbuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_stringbuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Copying out the string buffer.        *  @return  @c rdbuf()->str()       */
end_comment

begin_expr_stmt
name|__string_type
name|str
argument_list|()
specifier|const
block|{
return|return
name|_M_stringbuf
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Setting a new buffer.        *  @param  s  The string to use as a new sequence.        *        *  Calls @c rdbuf()->str(s).       */
end_comment

begin_function
name|void
name|str
parameter_list|(
specifier|const
name|__string_type
modifier|&
name|__s
parameter_list|)
block|{
name|_M_stringbuf
operator|.
name|str
argument_list|(
name|__s
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
unit|};
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_EXPORT_TEMPLATE
end_ifndef

begin_include
include|#
directive|include
file|<bits/sstream.tcc>
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
comment|/* _GLIBCXX_SSTREAM */
end_comment

end_unit

