begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// File based streams -*- C++ -*-
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
name|_CPP_FSTREAM
end_ifndef

begin_define
define|#
directive|define
name|_CPP_FSTREAM
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
comment|// Non-standard Types:
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
typedef|typedef
name|typename
name|__codecvt_type
operator|::
name|result
name|__res_type
expr_stmt|;
typedef|typedef
name|ctype
operator|<
name|char_type
operator|>
name|__ctype_type
expr_stmt|;
name|friend
name|class
name|ios_base
decl_stmt|;
comment|// For sync_with_stdio.
name|protected
label|:
comment|// Data Members:
comment|// MT lock inherited from libio or other low-level io library.
name|__c_lock
name|_M_lock
decl_stmt|;
comment|// External buffer.
name|__file_type
name|_M_file
decl_stmt|;
comment|// Current and beginning state type for codecvt.
name|__state_type
name|_M_state_cur
decl_stmt|;
name|__state_type
name|_M_state_beg
decl_stmt|;
comment|// Set iff _M_buf is allocated memory from _M_allocate_internal_buffer.
name|bool
name|_M_buf_allocated
decl_stmt|;
comment|// XXX Needed?
name|bool
name|_M_last_overflowed
decl_stmt|;
comment|// The position in the buffer corresponding to the external file
comment|// pointer.
name|char_type
modifier|*
name|_M_filepos
decl_stmt|;
name|public
label|:
comment|// Constructors/destructor:
name|basic_filebuf
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|basic_filebuf
argument_list|()
block|{
name|this
operator|->
name|close
argument_list|()
block|;
name|_M_last_overflowed
operator|=
name|false
block|;       }
comment|// Members:
name|bool
name|is_open
argument_list|()
specifier|const
block|{
return|return
name|_M_file
operator|.
name|is_open
argument_list|()
return|;
block|}
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
name|__filebuf_type
modifier|*
name|close
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|_M_allocate_internal_buffer
parameter_list|()
function_decl|;
name|void
name|_M_destroy_internal_buffer
parameter_list|()
function_decl|;
comment|// Overridden virtual functions:
name|virtual
name|streamsize
name|showmanyc
parameter_list|()
function_decl|;
comment|// Stroustrup, 1998, p. 628
comment|// underflow() and uflow() functions are called to get the next
comment|// charater from the real input source when the buffer is empty.
comment|// Buffered input uses underflow()
comment|// The only difference between underflow() and uflow() is that the
comment|// latter bumps _M_in_cur after the read.  In the sync_with_stdio
comment|// case, this is important, as we need to unget the read character in
comment|// the underflow() case in order to maintain synchronization.  So
comment|// instead of calling underflow() from uflow(), we create a common
comment|// subroutine to do the real work.
name|int_type
name|_M_underflow_common
parameter_list|(
name|bool
name|__bump
parameter_list|)
function_decl|;
name|virtual
name|int_type
name|underflow
parameter_list|()
block|{
return|return
name|_M_underflow_common
argument_list|(
name|false
argument_list|)
return|;
block|}
name|virtual
name|int_type
name|uflow
parameter_list|()
block|{
return|return
name|_M_underflow_common
argument_list|(
name|true
argument_list|)
return|;
block|}
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
comment|// NB: For what the standard expects of the overflow function,
comment|// see _M_really_overflow(), below. Because basic_streambuf's
comment|// sputc/sputn call overflow directly, and the complications of
comment|// this implementation's setting of the initial pointers all
comment|// equal to _M_buf when initializing, it seems essential to have
comment|// this in actuality be a helper function that checks for the
comment|// eccentricities of this implementation, and then call
comment|// overflow() if indeed the buffer is full.
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
comment|// Stroustrup, 1998, p 648
comment|// The overflow() function is called to transfer characters to the
comment|// real output destination when the buffer is full. A call to
comment|// overflow(c) outputs the contents of the buffer plus the
comment|// character c.
comment|// 27.5.2.4.5
comment|// Consume some sequence of the characters in the pending sequence.
name|int_type
name|_M_really_overflow
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
name|void
name|_M_convert_to_external
parameter_list|(
name|char_type
modifier|*
parameter_list|,
name|streamsize
parameter_list|,
name|streamsize
modifier|&
parameter_list|,
name|streamsize
modifier|&
parameter_list|)
function_decl|;
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
name|virtual
name|int
name|sync
parameter_list|()
block|{
name|bool
name|__testput
init|=
name|_M_out_cur
operator|&&
name|_M_out_beg
operator|<
name|_M_out_end
decl_stmt|;
comment|// Make sure that the internal buffer resyncs its idea of
comment|// the file position with the external file.
if|if
condition|(
name|__testput
condition|)
block|{
comment|// Need to restore current position after the write.
name|off_type
name|__off
init|=
name|_M_out_cur
operator|-
name|_M_out_end
decl_stmt|;
name|_M_really_overflow
argument_list|()
expr_stmt|;
comment|// _M_file.sync() will be called within
if|if
condition|(
name|__off
condition|)
name|_M_file
operator|.
name|seekoff
argument_list|(
name|__off
argument_list|,
name|ios_base
operator|::
name|cur
argument_list|)
expr_stmt|;
block|}
else|else
name|_M_file
operator|.
name|sync
argument_list|()
expr_stmt|;
name|_M_last_overflowed
operator|=
name|false
expr_stmt|;
return|return
literal|0
return|;
block|}
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
block|{
name|streamsize
name|__ret
init|=
literal|0
decl_stmt|;
comment|// Clear out pback buffer before going on to the real deal...
if|if
condition|(
name|_M_pback_init
condition|)
block|{
while|while
condition|(
name|__ret
operator|<
name|__n
operator|&&
name|_M_in_cur
operator|<
name|_M_in_end
condition|)
block|{
operator|*
name|__s
operator|=
operator|*
name|_M_in_cur
expr_stmt|;
operator|++
name|__ret
expr_stmt|;
operator|++
name|__s
expr_stmt|;
operator|++
name|_M_in_cur
expr_stmt|;
block|}
name|_M_pback_destroy
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|__ret
operator|<
name|__n
condition|)
name|__ret
operator|+=
name|__streambuf_type
operator|::
name|xsgetn
argument_list|(
name|__s
argument_list|,
name|__n
operator|-
name|__ret
argument_list|)
expr_stmt|;
return|return
name|__ret
return|;
block|}
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
block|{
name|_M_pback_destroy
argument_list|()
expr_stmt|;
return|return
name|__streambuf_type
operator|::
name|xsputn
argument_list|(
name|__s
argument_list|,
name|__n
argument_list|)
return|;
block|}
name|void
name|_M_output_unshift
parameter_list|()
function_decl|;
comment|// These three functions are used to clarify internal buffer
comment|// maintenance. After an overflow, or after a seekoff call that
comment|// started at beg or end, or possibly when the stream becomes
comment|// unbuffered, and a myrid other obscure corner cases, the
comment|// internal buffer does not truly reflect the contents of the
comment|// external buffer. At this point, for whatever reason, it is in
comment|// an indeterminate state.
name|void
name|_M_set_indeterminate
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
condition|)
name|this
operator|->
name|setg
argument_list|(
name|_M_buf
argument_list|,
name|_M_buf
argument_list|,
name|_M_buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|_M_mode
operator|&
name|ios_base
operator|::
name|out
condition|)
name|this
operator|->
name|setp
argument_list|(
name|_M_buf
argument_list|,
name|_M_buf
argument_list|)
expr_stmt|;
name|_M_filepos
operator|=
name|_M_buf
expr_stmt|;
block|}
name|void
name|_M_set_determinate
parameter_list|(
name|off_type
name|__off
parameter_list|)
block|{
name|bool
name|__testin
init|=
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
decl_stmt|;
name|bool
name|__testout
init|=
name|_M_mode
operator|&
name|ios_base
operator|::
name|out
decl_stmt|;
if|if
condition|(
name|__testin
condition|)
name|this
operator|->
name|setg
argument_list|(
name|_M_buf
argument_list|,
name|_M_buf
argument_list|,
name|_M_buf
operator|+
name|__off
argument_list|)
expr_stmt|;
if|if
condition|(
name|__testout
condition|)
name|this
operator|->
name|setp
argument_list|(
name|_M_buf
argument_list|,
name|_M_buf
operator|+
name|__off
argument_list|)
expr_stmt|;
name|_M_filepos
operator|=
name|_M_buf
operator|+
name|__off
expr_stmt|;
block|}
name|bool
name|_M_is_indeterminate
parameter_list|(
name|void
parameter_list|)
block|{
name|bool
name|__ret
init|=
name|false
decl_stmt|;
comment|// Don't return true if unbuffered.
if|if
condition|(
name|_M_buf
condition|)
block|{
if|if
condition|(
name|_M_mode
operator|&
name|ios_base
operator|::
name|in
condition|)
name|__ret
operator|=
name|_M_in_beg
operator|==
name|_M_in_cur
operator|&&
name|_M_in_cur
operator|==
name|_M_in_end
expr_stmt|;
if|if
condition|(
name|_M_mode
operator|&
name|ios_base
operator|::
name|out
condition|)
name|__ret
operator|=
name|_M_out_beg
operator|==
name|_M_out_cur
operator|&&
name|_M_out_cur
operator|==
name|_M_out_end
expr_stmt|;
block|}
return|return
name|__ret
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Explicit specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|basic_filebuf
operator|<
name|char
operator|>
operator|::
name|int_type
name|basic_filebuf
operator|<
name|char
operator|>
operator|::
name|_M_underflow_common
argument_list|(
argument|bool __bump
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|basic_filebuf
operator|<
name|wchar_t
operator|>
operator|::
name|int_type
name|basic_filebuf
operator|<
name|wchar_t
operator|>
operator|::
name|_M_underflow_common
argument_list|(
argument|bool __bump
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// 27.8.1.5  Template class basic_ifstream
end_comment

begin_comment
comment|/**    *  Derivation of general input streams, specific to files.   */
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
comment|/** Default constructor.  Create an input file stream.  */
end_comment

begin_expr_stmt
name|basic_ifstream
argument_list|()
operator|:
name|__istream_type
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
block|; }
comment|/**        *  @brief Create an input file stream.        *  @param  s  Null terminated string specifying filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
name|explicit
name|basic_ifstream
argument_list|(
argument|const char* __s
argument_list|,
argument|ios_base::openmode __mode = ios_base::in
argument_list|)
operator|:
name|__istream_type
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
operator|~
name|basic_ifstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Get a pointer to the file stream's buffer.        *  @return Pointer to basic_filebuf.       */
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
comment|/** Close the file.  */
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
comment|// 27.8.1.8  Template class basic_ofstream
end_comment

begin_comment
comment|/**    *  Derivation of general output streams, specific to files.   */
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
comment|/** Default constructor for output file_stream.  */
end_comment

begin_expr_stmt
name|basic_ofstream
argument_list|()
operator|:
name|__ostream_type
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
block|; }
comment|/**        *  @brief  Create an output stream.        *  @param  s  Null terminated string specifying filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
name|explicit
name|basic_ofstream
argument_list|(
argument|const char* __s
argument_list|,
argument|ios_base::openmode __mode = ios_base::out|ios_base::trunc
argument_list|)
operator|:
name|__ostream_type
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
operator|~
name|basic_ofstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Get a pointer to the file stream's buffer.        *  @return Pointer to basic_filebuf.       */
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
comment|/**        *  @brief Query to see if file stream is open.        *  @return True if stream is open.       */
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
comment|/**        *  @brief Specify a file to open for output.        *  @param  s  Null terminated string specifying filename.        *  @param  mode  Mode in which to open file (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
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
comment|/** Close the file stream.  */
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
comment|// 27.8.1.11  Template class basic_fstream
end_comment

begin_comment
comment|/**    *  Derivation of general input/output streams, specific to files.   */
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
comment|/** Default constructor.  Create a file stream.  */
end_comment

begin_expr_stmt
name|basic_fstream
argument_list|()
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
block|; }
comment|/**        *  @brief Create an input/output stream.        *  @param  s  Null terminated string specifying filename.        *  @param  mode  Open file in specified mode (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
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
operator|~
name|basic_fstream
argument_list|()
block|{ }
comment|// Members:
comment|/**        *  @brief  Get a pointer to the file stream's buffer.        *  @return Pointer to basic_filebuf.       */
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
comment|/**        *  @brief Query to see if file stream is open.        *  @return True if stream is open.       */
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
comment|/**        *  @brief Specify a file to open for input and/or output.        *  @param  s  Null terminated string specifying filename.        *  @param  mode  Mode in which to open file (see std::ios_base).        *        *  Tip:  When using std::string to hold the filename, you must use        *  .c_str() before passing it to this constructor.       */
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
comment|/** Close the file stream.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_NO_TEMPLATE_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|export
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_FULLY_COMPLIANT_HEADERS
end_ifdef

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

end_unit

