begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// File based streams -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
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
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 27.8  File-based streams
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file fstream  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_FSTREAM
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_FSTREAM
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

begin_include
include|#
directive|include
file|<locale>
end_include

begin_comment
comment|// For codecvt
end_comment

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_comment
comment|// For SEEK_SET, SEEK_CUR, SEEK_END, BUFSIZ
end_comment

begin_include
include|#
directive|include
file|<bits/basic_file.h>
end_include

begin_include
include|#
directive|include
file|<bits/gthr.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// [27.8.1.1] template class basic_filebuf
comment|/**    *  @brief  The actual work of input and output (for files).    *    *  This class associates both its input and output sequence with an    *  external disk file, and maintains a joint file position for both    *  sequences.  Many of its sematics are described in terms of similar    *  behavior in the Standard C Library's @c FILE streams.   */
comment|// Requirements on traits_type, specific to this class:
comment|// traits_type::pos_type must be fpos<traits_type::state_type>
comment|// traits_type::off_type must be streamoff
comment|// traits_type::state_type must be Assignable and DefaultConstructable,
comment|// and traits_type::state_type() must be the initial state for codecvt.
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|basic_filebuf
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
typedef|typedef
name|_Traits
name|traits_type
typedef|;
typedef|typedef
name|typename
name|traits_type
operator|::
name|int_type
name|int_type
expr_stmt|;
typedef|typedef
name|typename
name|traits_type
operator|::
name|pos_type
name|pos_type
expr_stmt|;
typedef|typedef
name|typename
name|traits_type
operator|::
name|off_type
name|off_type
expr_stmt|;
comment|//@{
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
typedef|typedef
name|basic_streambuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__streambuf_type
expr_stmt|;
typedef|typedef
name|basic_filebuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__filebuf_type
expr_stmt|;
typedef|typedef
name|__basic_file
operator|<
name|char
operator|>
name|__file_type
expr_stmt|;
typedef|typedef
name|typename
name|traits_type
operator|::
name|state_type
name|__state_type
expr_stmt|;
typedef|typedef
name|codecvt
operator|<
name|char_type
operator|,
name|char
operator|,
name|__state_type
operator|>
name|__codecvt_type
expr_stmt|;
comment|//@}
name|friend
name|class
name|ios_base
decl_stmt|;
comment|// For sync_with_stdio.
name|protected
label|:
comment|// Data Members:
comment|// MT lock inherited from libio or other low-level io library.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|__c_lock
name|_M_lock
decl_stmt|;
comment|// External buffer.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|__file_type
name|_M_file
decl_stmt|;
comment|/**        *  @if maint        *  Place to stash in || out || in | out settings for current filebuf.        *  @endif       */
name|ios_base
operator|::
name|openmode
name|_M_mode
expr_stmt|;
comment|// Beginning state type for codecvt.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|__state_type
name|_M_state_beg
decl_stmt|;
comment|// During output, the state that corresponds to pptr(),
comment|// during input, the state that corresponds to egptr() and
comment|// _M_ext_next.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|__state_type
name|_M_state_cur
decl_stmt|;
comment|// Not used for output. During input, the state that corresponds
comment|// to eback() and _M_ext_buf.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|__state_type
name|_M_state_last
decl_stmt|;
comment|/**        *  @if maint        *  Pointer to the beginning of internal buffer.        *  @endif       */
name|char_type
modifier|*
name|_M_buf
decl_stmt|;
comment|/**        *  @if maint        *  Actual size of internal buffer. This number is equal to the size        *  of the put area + 1 position, reserved for the overflow char of        *  a full area.        *  @endif       */
name|size_t
name|_M_buf_size
decl_stmt|;
comment|// Set iff _M_buf is allocated memory from _M_allocate_internal_buffer.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|bool
name|_M_buf_allocated
decl_stmt|;
comment|/**        *  @if maint        *  _M_reading == false&& _M_writing == false for 'uncommitted' mode;          *  _M_reading == true for 'read' mode;        *  _M_writing == true for 'write' mode;        *        *  NB: _M_reading == true&& _M_writing == true is unused.        *  @endif       */
name|bool
name|_M_reading
decl_stmt|;
name|bool
name|_M_writing
decl_stmt|;
comment|//@{
comment|/**        *  @if maint        *  Necessary bits for putback buffer management.        *        *  @note pbacks of over one character are not currently supported.        *  @endif       */
name|char_type
name|_M_pback
decl_stmt|;
name|char_type
modifier|*
name|_M_pback_cur_save
decl_stmt|;
name|char_type
modifier|*
name|_M_pback_end_save
decl_stmt|;
name|bool
name|_M_pback_init
decl_stmt|;
comment|//@}
comment|// Cached codecvt facet.
specifier|const
name|__codecvt_type
modifier|*
name|_M_codecvt
decl_stmt|;
comment|/**        *  @if maint        *  Buffer for external characters. Used for input when        *  codecvt::always_noconv() == false. When valid, this corresponds        *  to eback().        *  @endif       */
name|char
modifier|*
name|_M_ext_buf
decl_stmt|;
comment|/**        *  @if maint        *  Size of buffer held by _M_ext_buf.        *  @endif       */
name|streamsize
name|_M_ext_buf_size
decl_stmt|;
comment|/**        *  @if maint        *  Pointers into the buffer held by _M_ext_buf that delimit a        *  subsequence of bytes that have been read but not yet converted.        *  When valid, _M_ext_next corresponds to egptr().        *  @endif       */
specifier|const
name|char
modifier|*
name|_M_ext_next
decl_stmt|;
name|char
modifier|*
name|_M_ext_end
decl_stmt|;
comment|/**        *  @if maint        *  Initializes pback buffers, and moves normal buffers to safety.        *  Assumptions:        *  _M_in_cur has already been moved back        *  @endif       */
name|void
name|_M_create_pback
parameter_list|()
block|{
if|if
condition|(
operator|!
name|_M_pback_init
condition|)
block|{
name|_M_pback_cur_save
operator|=
name|this
operator|->
name|gptr
argument_list|()
expr_stmt|;
name|_M_pback_end_save
operator|=
name|this
operator|->
name|egptr
argument_list|()
expr_stmt|;
name|this
operator|->
name|setg
argument_list|(
operator|&
name|_M_pback
argument_list|,
operator|&
name|_M_pback
argument_list|,
operator|&
name|_M_pback
operator|+
literal|1
argument_list|)
expr_stmt|;
name|_M_pback_init
operator|=
name|true
expr_stmt|;
block|}
block|}
comment|/**        *  @if maint        *  Deactivates pback buffer contents, and restores normal buffer.        *  Assumptions:        *  The pback buffer has only moved forward.        *  @endif       */
name|void
name|_M_destroy_pback
parameter_list|()
function|throw
parameter_list|()
block|{
if|if
condition|(
name|_M_pback_init
condition|)
block|{
comment|// Length _M_in_cur moved in the pback buffer.
name|_M_pback_cur_save
operator|+=
name|this
operator|->
name|gptr
argument_list|()
operator|!=
name|this
operator|->
name|eback
argument_list|()
expr_stmt|;
name|this
operator|->
name|setg
argument_list|(
name|this
operator|->
name|_M_buf
argument_list|,
name|_M_pback_cur_save
argument_list|,
name|_M_pback_end_save
argument_list|)
expr_stmt|;
name|_M_pback_init
operator|=
name|false
expr_stmt|;
block|}
block|}
name|public
label|:
comment|// Constructors/destructor:
comment|/**        *  @brief  Does not open any files.        *        *  The default constructor initializes the parent class using its        *  own default ctor.       */
name|basic_filebuf
argument_list|()
expr_stmt|;
comment|/**        *  @brief  The destructor closes the file first.       */
name|virtual
operator|~
name|basic_filebuf
argument_list|()
block|{
name|this
operator|->
name|close
argument_list|()
block|; }
comment|// Members:
comment|/**        *  @brief  Returns true if the external file is open.       */
name|bool
name|is_open
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_file
operator|.
name|is_open
argument_list|()
return|;
block|}
comment|/**        *  @brief  Opens an external file.        *  @param  s  The name of the file.        *  @param  mode  The open mode flags.        *  @return  @c this on success, NULL on failure        *        *  If a file is already open, this function immediately fails.        *  Otherwise it tries to open the file named @a s using the flags        *  given in @a mode.        *        *  [Table 92 gives the relation between openmode combinations and the        *  equivalent fopen() flags, but the table has not been copied yet.]       */
name|__filebuf_type
modifier|*
name|open
argument_list|(
specifier|const
name|char
operator|*
name|__s
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
argument_list|)
decl_stmt|;
comment|/**        *  @brief  Closes the currently associated file.        *  @return  @c this on success, NULL on failure        *        *  If no file is currently open, this function immediately fails.        *        *  If a "put buffer area" exists, @c overflow(eof) is called to flush        *  all the characters.  The file is then closed.        *        *  If any operations fail, this function also fails.       */
name|__filebuf_type
modifier|*
name|close
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
name|protected
label|:
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|void
name|_M_allocate_internal_buffer
parameter_list|()
function_decl|;
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|void
name|_M_destroy_internal_buffer
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
comment|// [27.8.1.4] overridden virtual functions
comment|// [documentation is inherited]
name|virtual
name|streamsize
name|showmanyc
parameter_list|()
function_decl|;
comment|// Stroustrup, 1998, p. 628
comment|// underflow() and uflow() functions are called to get the next
comment|// charater from the real input source when the buffer is empty.
comment|// Buffered input uses underflow()
comment|// [documentation is inherited]
name|virtual
name|int_type
name|underflow
parameter_list|()
function_decl|;
comment|// [documentation is inherited]
name|virtual
name|int_type
name|pbackfail
parameter_list|(
name|int_type
name|__c
init|=
name|_Traits
operator|::
name|eof
argument_list|()
parameter_list|)
function_decl|;
comment|// Stroustrup, 1998, p 648
comment|// The overflow() function is called to transfer characters to the
comment|// real output destination when the buffer is full. A call to
comment|// overflow(c) outputs the contents of the buffer plus the
comment|// character c.
comment|// 27.5.2.4.5
comment|// Consume some sequence of the characters in the pending sequence.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|virtual
name|int_type
name|overflow
parameter_list|(
name|int_type
name|__c
init|=
name|_Traits
operator|::
name|eof
argument_list|()
parameter_list|)
function_decl|;
comment|// Convert internal byte sequence to external, char-based
comment|// sequence via codecvt.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|bool
name|_M_convert_to_external
parameter_list|(
name|char_type
modifier|*
parameter_list|,
name|streamsize
parameter_list|)
function_decl|;
comment|/**        *  @brief  Manipulates the buffer.        *  @param  s  Pointer to a buffer area.        *  @param  n  Size of @a s.        *  @return  @c this        *        *  If no file has been opened, and both @a s and @a n are zero, then        *  the stream becomes unbuffered.  Otherwise, @c s is used as a        *  buffer; see        *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#2        *  for more.       */
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
function_decl|;
comment|// [documentation is inherited]
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
comment|// [documentation is inherited]
name|virtual
name|pos_type
name|seekpos
argument_list|(
name|pos_type
name|__pos
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
comment|// Common code for seekoff and seekpos
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|pos_type
name|_M_seek
argument_list|(
name|off_type
name|__off
argument_list|,
name|ios_base
operator|::
name|seekdir
name|__way
argument_list|,
name|__state_type
name|__state
argument_list|)
decl_stmt|;
comment|// [documentation is inherited]
name|virtual
name|int
name|sync
parameter_list|()
function_decl|;
comment|// [documentation is inherited]
name|virtual
name|void
name|imbue
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
comment|// [documentation is inherited]
name|virtual
name|streamsize
name|xsgetn
parameter_list|(
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
function_decl|;
comment|// [documentation is inherited]
name|virtual
name|streamsize
name|xsputn
parameter_list|(
specifier|const
name|char_type
modifier|*
name|__s
parameter_list|,
name|streamsize
name|__n
parameter_list|)
function_decl|;
comment|// Flushes output buffer, then writes unshift sequence.
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
name|bool
name|_M_terminate_output
parameter_list|()
function_decl|;
comment|/**        *  @if maint         *  This function sets the pointers of the internal buffer, both get        *  and put areas. Typically:        *        *   __off == egptr() - eback() upon underflow/uflow ('read' mode);        *   __off == 0 upon overflow ('write' mode);        *   __off == -1 upon open, setbuf, seekoff/pos ('uncommitted' mode).        *         *  NB: epptr() - pbase() == _M_buf_size - 1, since _M_buf_size        *  reflects the actual allocated memory and the last cell is reserved        *  for the overflow char of a full put area.        *  @endif       */
name|void
name|_M_set_buffer
parameter_list|(
name|streamsize
name|__off
parameter_list|)
block|{
specifier|const
name|bool
name|__testin
init|=
name|this
operator|->
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
decl_stmt|;
specifier|const
name|bool
name|__testout
init|=
name|this
operator|->
name|_M_mode
operator|&
name|ios_base
operator|::
name|out
decl_stmt|;
if|if
condition|(
name|__testin
operator|&&
name|__off
operator|>
literal|0
condition|)
name|this
operator|->
name|setg
argument_list|(
name|this
operator|->
name|_M_buf
argument_list|,
name|this
operator|->
name|_M_buf
argument_list|,
name|this
operator|->
name|_M_buf
operator|+
name|__off
argument_list|)
expr_stmt|;
else|else
name|this
operator|->
name|setg
argument_list|(
name|this
operator|->
name|_M_buf
argument_list|,
name|this
operator|->
name|_M_buf
argument_list|,
name|this
operator|->
name|_M_buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|__testout
operator|&&
name|__off
operator|==
literal|0
operator|&&
name|this
operator|->
name|_M_buf_size
operator|>
literal|1
condition|)
name|this
operator|->
name|setp
argument_list|(
name|this
operator|->
name|_M_buf
argument_list|,
name|this
operator|->
name|_M_buf
operator|+
name|this
operator|->
name|_M_buf_size
operator|-
literal|1
argument_list|)
expr_stmt|;
else|else
name|this
operator|->
name|setp
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// [27.8.1.5] Template class basic_ifstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling input for files.    *    *  This class supports reading from named files, using the inherited    *  functions from std::basic_istream.  To control the associated    *  sequence, an instance of std::basic_filebuf is used, which this page    *  refers to as @c sb.   */
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
name|basic_ifstream
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
name|basic_filebuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__filebuf_type
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

begin_comment
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
end_comment

begin_decl_stmt
name|__filebuf_type
name|_M_filebuf
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Constructors/Destructors:
end_comment

begin_comment
comment|/**        *  @brief  Default constructor.        *        *  Initializes @c sb using its default constructor, and passes        *  @c&sb to the base class initializer.  Does not open any files        *  (you haven't given it a filename to open).       */
end_comment

begin_expr_stmt
name|basic_ifstream
argument_list|()
operator|:
name|__istream_type
argument_list|()
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|; }
comment|/**        *  @brief  Create an input file stream.        *  @param  s  Null terminated string specifying the filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  @c ios_base::in is automatically included in @a mode.        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
name|explicit
name|basic_ifstream
argument_list|(
argument|const char* __s
argument_list|,
argument|ios_base::openmode __mode = ios_base::in
argument_list|)
operator|:
name|__istream_type
argument_list|()
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|;
name|this
operator|->
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
argument_list|)
block|;       }
comment|/**        *  @brief  The destructor does nothing.        *        *  The file is closed by the filebuf object, not the formatting        *  stream.       */
operator|~
name|basic_ifstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_filebuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__filebuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__filebuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_filebuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Wrapper to test for an open file.        *  @return  @c rdbuf()->is_open()       */
end_comment

begin_function
name|bool
name|is_open
parameter_list|()
block|{
return|return
name|_M_filebuf
operator|.
name|is_open
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Opens an external file.        *  @param  s  The name of the file.        *  @param  mode  The open mode flags.        *        *  Calls @c std::basic_filebuf::open(s,mode|in).  If that function        *  fails, @c failbit is set in the stream's error state.        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
end_comment

begin_decl_stmt
name|void
name|open
argument_list|(
specifier|const
name|char
operator|*
name|__s
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
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
operator||
name|ios_base
operator|::
name|in
argument_list|)
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Close the file.        *        *  Calls @c std::basic_filebuf::close().  If that function        *  fails, @c failbit is set in the stream's error state.       */
end_comment

begin_function
name|void
name|close
parameter_list|()
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|close
argument_list|()
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|// [27.8.1.8] Template class basic_ofstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling output for files.    *    *  This class supports reading from named files, using the inherited    *  functions from std::basic_ostream.  To control the associated    *  sequence, an instance of std::basic_filebuf is used, which this page    *  refers to as @c sb.   */
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
name|basic_ofstream
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
name|basic_filebuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__filebuf_type
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

begin_comment
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
end_comment

begin_decl_stmt
name|__filebuf_type
name|_M_filebuf
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
comment|/**        *  @brief  Default constructor.        *        *  Initializes @c sb using its default constructor, and passes        *  @c&sb to the base class initializer.  Does not open any files        *  (you haven't given it a filename to open).       */
end_comment

begin_expr_stmt
name|basic_ofstream
argument_list|()
operator|:
name|__ostream_type
argument_list|()
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|; }
comment|/**        *  @brief  Create an output file stream.        *  @param  s  Null terminated string specifying the filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  @c ios_base::out|ios_base::trunc is automatically included in        *  @a mode.        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
name|explicit
name|basic_ofstream
argument_list|(
argument|const char* __s
argument_list|,
argument|ios_base::openmode __mode = ios_base::out|ios_base::trunc
argument_list|)
operator|:
name|__ostream_type
argument_list|()
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|;
name|this
operator|->
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
argument_list|)
block|;       }
comment|/**        *  @brief  The destructor does nothing.        *        *  The file is closed by the filebuf object, not the formatting        *  stream.       */
operator|~
name|basic_ofstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_filebuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__filebuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__filebuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_filebuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Wrapper to test for an open file.        *  @return  @c rdbuf()->is_open()       */
end_comment

begin_function
name|bool
name|is_open
parameter_list|()
block|{
return|return
name|_M_filebuf
operator|.
name|is_open
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Opens an external file.        *  @param  s  The name of the file.        *  @param  mode  The open mode flags.        *        *  Calls @c std::basic_filebuf::open(s,mode|out|trunc).  If that        *  function fails, @c failbit is set in the stream's error state.        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
end_comment

begin_decl_stmt
name|void
name|open
argument_list|(
specifier|const
name|char
operator|*
name|__s
argument_list|,
name|ios_base
operator|::
name|openmode
name|__mode
operator|=
name|ios_base
operator|::
name|out
operator||
name|ios_base
operator|::
name|trunc
argument_list|)
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
operator||
name|ios_base
operator|::
name|out
argument_list|)
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Close the file.        *        *  Calls @c std::basic_filebuf::close().  If that function        *  fails, @c failbit is set in the stream's error state.       */
end_comment

begin_function
name|void
name|close
parameter_list|()
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|close
argument_list|()
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|// [27.8.1.11] Template class basic_fstream
end_comment

begin_comment
comment|/**    *  @brief  Controlling intput and output for files.    *    *  This class supports reading from and writing to named files, using    *  the inherited functions from std::basic_iostream.  To control the    *  associated sequence, an instance of std::basic_filebuf is used, which    *  this page refers to as @c sb.   */
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
name|basic_fstream
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
name|basic_filebuf
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__filebuf_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_ios
operator|<
name|char_type
operator|,
name|traits_type
operator|>
name|__ios_type
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

begin_comment
comment|/**        *  @if maint        *  @doctodo        *  @endif       */
end_comment

begin_decl_stmt
name|__filebuf_type
name|_M_filebuf
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
comment|/**        *  @brief  Default constructor.        *        *  Initializes @c sb using its default constructor, and passes        *  @c&sb to the base class initializer.  Does not open any files        *  (you haven't given it a filename to open).       */
end_comment

begin_expr_stmt
name|basic_fstream
argument_list|()
operator|:
name|__iostream_type
argument_list|()
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|; }
comment|/**        *  @brief  Create an input/output file stream.        *  @param  s  Null terminated string specifying the filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
name|explicit
name|basic_fstream
argument_list|(
argument|const char* __s
argument_list|,
argument|ios_base::openmode __mode = ios_base::in | ios_base::out
argument_list|)
operator|:
name|__iostream_type
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_filebuf
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
operator|&
name|_M_filebuf
argument_list|)
block|;
name|this
operator|->
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
argument_list|)
block|;       }
comment|/**        *  @brief  The destructor does nothing.        *        *  The file is closed by the filebuf object, not the formatting        *  stream.       */
operator|~
name|basic_fstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Accessing the underlying buffer.        *  @return  The current basic_filebuf buffer.        *        *  This hides both signatures of std::basic_ios::rdbuf().       */
name|__filebuf_type
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|__filebuf_type
operator|*
operator|>
operator|(
operator|&
name|_M_filebuf
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Wrapper to test for an open file.        *  @return  @c rdbuf()->is_open()       */
end_comment

begin_function
name|bool
name|is_open
parameter_list|()
block|{
return|return
name|_M_filebuf
operator|.
name|is_open
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Opens an external file.        *  @param  s  The name of the file.        *  @param  mode  The open mode flags.        *        *  Calls @c std::basic_filebuf::open(s,mode).  If that        *  function fails, @c failbit is set in the stream's error state.        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
end_comment

begin_decl_stmt
name|void
name|open
argument_list|(
specifier|const
name|char
operator|*
name|__s
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
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|open
argument_list|(
name|__s
argument_list|,
name|__mode
argument_list|)
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  @brief  Close the file.        *        *  Calls @c std::basic_filebuf::close().  If that function        *  fails, @c failbit is set in the stream's error state.       */
end_comment

begin_function
name|void
name|close
parameter_list|()
block|{
if|if
condition|(
operator|!
name|_M_filebuf
operator|.
name|close
argument_list|()
condition|)
name|this
operator|->
name|setstate
argument_list|(
name|ios_base
operator|::
name|failbit
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|}; }
comment|// namespace std
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_EXPORT_TEMPLATE
end_ifndef

begin_include
include|#
directive|include
file|<bits/fstream.tcc>
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
comment|/* _GLIBCXX_FSTREAM */
end_comment

end_unit

