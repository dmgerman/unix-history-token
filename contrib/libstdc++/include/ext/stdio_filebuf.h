begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// File descriptor layer for filebuf -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2002 Free Software Foundation, Inc.
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
comment|/** @file ext/stdio_filebuf.h  *  This file is a GNU extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXT_STDIO_FILEBUF
end_ifndef

begin_define
define|#
directive|define
name|_EXT_STDIO_FILEBUF
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
file|<fstream>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|/**    *  @class stdio_filebuf ext/stdio_filebuf.h<ext/stdio_filebuf.h>    *  @brief Provides a layer of compatibility for C/POSIX.    *    *  This GNU extension provides extensions for working with standard C    *  FILE*'s and POSIX file descriptors.  It must be instantiated by the    *  user with the type of character used in the file stream, e.g.,    *  stdio_filebuf<char>.   */
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|=
name|std
operator|::
name|char_traits
operator|<
name|_CharT
operator|>
expr|>
name|class
name|stdio_filebuf
operator|:
name|public
name|std
operator|::
name|basic_filebuf
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
name|protected
label|:
comment|// Stack-based buffer for unbuffered input.
name|char_type
name|_M_unbuf
index|[
literal|4
index|]
decl_stmt|;
name|public
label|:
comment|/**        *  @param  fd  An open file descriptor.        *  @param  mode  Same meaning as in a standard filebuf.        *  @param  del  Whether to close the file on destruction.        *  @param  size  Optimal or preferred size of internal buffer, in bytes.        *        *  This constructor associates a file stream buffer with an open        *  POSIX file descriptor.  Iff @a del is true, then the associated        *  file will be closed when the stdio_filebuf is closed/destroyed.       */
name|stdio_filebuf
argument_list|(
argument|int __fd
argument_list|,
argument|std::ios_base::openmode __mode
argument_list|,
argument|bool __del
argument_list|,
argument|int_type __size
argument_list|)
empty_stmt|;
comment|/**        *  @param  f  An open @c FILE*.        *  @param  mode  Same meaning as in a standard filebuf.        *  @param  size  Optimal or preferred size of internal buffer, in bytes.        *                Defaults to system's @c BUFSIZ.        *        *  This constructor associates a file stream buffer with an open        *  C @c FILE*.  The @c FILE* will not be automatically closed when the        *  stdio_filebuf is closed/destroyed.       */
name|stdio_filebuf
argument_list|(
argument|std::__c_file* __f
argument_list|,
argument|std::ios_base::openmode __mode
argument_list|,
argument|int_type __size = static_cast<int_type>(BUFSIZ)
argument_list|)
empty_stmt|;
comment|/**        *  Possibly closes the external data stream, in the case of the file        *  descriptor constructor and @c del @c == @c true.       */
name|virtual
operator|~
name|stdio_filebuf
argument_list|()
expr_stmt|;
comment|/**        *  @return  The underlying file descriptor.        *        *  Once associated with an external data stream, this function can be        *  used to access the underlying POSIX file descriptor.  Note that        *  there is no way for the library to track what you do with the        *  descriptor, so be careful.       */
name|int
name|fd
parameter_list|()
block|{
return|return
name|_M_file
operator|.
name|fd
argument_list|()
return|;
block|}
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
operator|,
name|typename
name|_Traits
operator|>
name|stdio_filebuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|::
operator|~
name|stdio_filebuf
argument_list|()
block|{ }
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|stdio_filebuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|::
name|stdio_filebuf
argument_list|(
argument|int __fd
argument_list|,
argument|std::ios_base::openmode __mode
argument_list|,
argument|bool __del
argument_list|,
argument|int_type __size
argument_list|)
block|{
name|_M_file
operator|.
name|sys_open
argument_list|(
name|__fd
argument_list|,
name|__mode
argument_list|,
name|__del
argument_list|)
block|;
if|if
condition|(
name|this
operator|->
name|is_open
argument_list|()
condition|)
block|{
name|_M_mode
operator|=
name|__mode
expr_stmt|;
if|if
condition|(
name|__size
operator|>
literal|0
operator|&&
name|__size
operator|<
literal|4
condition|)
block|{
comment|// Specify unbuffered.
name|_M_buf
operator|=
name|_M_unbuf
expr_stmt|;
name|_M_buf_size
operator|=
name|__size
expr_stmt|;
name|_M_buf_size_opt
operator|=
literal|0
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|_M_buf_size_opt
operator|=
name|__size
expr_stmt|;
name|_M_allocate_internal_buffer
argument_list|()
expr_stmt|;
block|}
end_else

begin_expr_stmt
name|_M_set_indeterminate
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}     }
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|stdio_filebuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|::
name|stdio_filebuf
argument_list|(
argument|std::__c_file* __f
argument_list|,
argument|std::ios_base::openmode __mode
argument_list|,
argument|int_type __size
argument_list|)
block|{
name|_M_file
operator|.
name|sys_open
argument_list|(
name|__f
argument_list|,
name|__mode
argument_list|)
block|;
if|if
condition|(
name|this
operator|->
name|is_open
argument_list|()
condition|)
block|{
name|_M_mode
operator|=
name|__mode
expr_stmt|;
if|if
condition|(
name|__size
operator|>
literal|0
operator|&&
name|__size
operator|<
literal|4
condition|)
block|{
comment|// Specify unbuffered.
name|_M_buf
operator|=
name|_M_unbuf
expr_stmt|;
name|_M_buf_size
operator|=
name|__size
expr_stmt|;
name|_M_buf_size_opt
operator|=
literal|0
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|_M_buf_size_opt
operator|=
name|__size
expr_stmt|;
name|_M_allocate_internal_buffer
argument_list|()
expr_stmt|;
block|}
end_else

begin_expr_stmt
name|_M_set_indeterminate
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}     } }
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EXT_STDIO_FILEBUF */
end_comment

end_unit

