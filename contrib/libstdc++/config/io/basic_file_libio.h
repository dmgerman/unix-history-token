begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Wrapper of C-language FILE struct -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.
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
comment|/** @file basic_file.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BASIC_FILE
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BASIC_FILE
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

begin_include
include|#
directive|include
file|<ios>
end_include

begin_include
include|#
directive|include
file|<libioP.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Ulrich is going to make some detailed comment here, explaining
comment|// all this unpleasantness, providing detailed performance analysis
comment|// as to why we have to do all this lame vtable hacking instead of a
comment|// sane, function-based approach. This verbiage will provide a clear
comment|// and detailed description of the whole object-layout,
comment|// vtable-swapping, sordid history of this hack.
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|__basic_file_base
operator|:
name|public
name|__c_file_type
block|{
name|virtual
operator|~
name|__basic_file_base
argument_list|()
block|{ }
block|;
name|virtual
name|int
name|overflow
argument_list|(
argument|int __c = EOF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|underflow
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|uflow
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int __c
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamsize
name|xsputn
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamsize
name|xsgetn
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamoff
name|seekoff
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|,
argument|ios_base::openmode __mode = ios_base::in | ios_base::out
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamoff
name|seekpos
argument_list|(
argument|streamoff __pos
argument_list|,
argument|ios_base::openmode __mode = ios_base::in | ios_base::out
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|_CharT* __b
argument_list|,
argument|int __len
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|sync
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|doallocate
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|streamsize
name|sys_read
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamsize
name|sys_write
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|streamoff
name|sys_seek
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|sys_close
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|sys_stat
argument_list|(
name|void
operator|*
name|__v
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|showmanyc
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|imbue
argument_list|(
name|void
operator|*
name|__v
argument_list|)
operator|=
literal|0
block|;     }
expr_stmt|;
comment|// Some of these member functions are based on libio/filebuf.cc.
comment|// Also note that the order and number of virtual functions has to precisely
comment|// match the order and number in the _IO_jump_t struct defined in libioP.h.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__basic_file
operator|:
name|public
name|__basic_file_base
operator|<
name|_CharT
operator|>
block|{
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
name|__c_wfile_type
name|_M_wfile
block|;
endif|#
directive|endif
name|public
operator|:
name|__basic_file
argument_list|(
name|__c_lock
operator|*
name|__lock
operator|=
literal|0
argument_list|)
block|;
name|void
name|_M_open_mode
argument_list|(
argument|ios_base::openmode __mode
argument_list|,
argument|int& __p_mode
argument_list|,
argument|int& __rw_mode
argument_list|,
argument|char* __c_mode
argument_list|)
block|;
comment|// Equivalent to the normal fopen function.
name|__basic_file
operator|*
name|open
argument_list|(
argument|const char* __name
argument_list|,
argument|ios_base::openmode __mode
argument_list|,
argument|int __prot =
literal|0664
argument_list|)
block|;
comment|// Used for opening the standard streams, cin, cout, cerr, clog,
comment|// and their wide-stream equivalents. Instead of calling open, it
comment|// just sets
comment|//  - for libio:  __c_file_type->_fileno and the respective _flags bits
comment|//  - for stdio:  _M_cfile = __file and some internal flags
comment|// and returns.
name|__basic_file
operator|*
name|sys_open
argument_list|(
argument|__c_file_type* __file
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
block|;
name|_CharT
name|sys_getc
argument_list|()
block|;
name|_CharT
name|sys_ungetc
argument_list|(
name|_CharT
argument_list|)
block|;
name|__basic_file
operator|*
name|close
argument_list|()
block|;
name|bool
name|is_open
argument_list|()
block|;
name|int
name|fd
argument_list|()
block|;
comment|// NB: Must match FILE specific jump table starting here--this
comment|// means all virtual functions starting with the dtor must match,
comment|// slot by slot. For glibc-based dystems, this means the _IO_FILE
comment|// as the FILE struct and _IO_jump_t as the jump table.
name|virtual
operator|~
name|__basic_file
argument_list|()
block|;
comment|// Takes the place of __finish.
name|virtual
name|int
name|overflow
argument_list|(
argument|int __c = EOF
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|uflow
argument_list|()
block|;
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int __c
argument_list|)
block|;
comment|// A complex "write" function that sets all of __c_file_type's
comment|// pointers and associated data members correctly and manages its
comment|// relation to the external byte sequence.
name|virtual
name|streamsize
name|xsputn
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
comment|// A complex "read" function that sets all of __c_file_type's
comment|// pointers and associated data members correctly and manages its
comment|// relation to the external byte sequence.
name|virtual
name|streamsize
name|xsgetn
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
comment|// A complex "seekoff" function that sets all of __c_file_type's
comment|// pointers and associated data members correctly and manages its
comment|// relation to the external byte sequence.
name|virtual
name|streamoff
name|seekoff
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|,
argument|ios_base::openmode __mode = ios_base::in | ios_base::out
argument_list|)
block|;
comment|// A complex "seekpos" function that sets all of __c_file_type's
comment|// pointers and associated data members correctly and manages its
comment|// relation to the external byte sequence.
name|virtual
name|streamoff
name|seekpos
argument_list|(
argument|streamoff __pos
argument_list|,
argument|ios_base::openmode __mode = ios_base::in | ios_base::out
argument_list|)
block|;
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|_CharT* __b
argument_list|,
argument|int __len
argument_list|)
block|;
name|virtual
name|int
name|sync
argument_list|()
block|;
name|virtual
name|int
name|doallocate
argument_list|()
block|;
comment|// A simple read function for the external byte sequence, that
comment|// does no mucking around with or setting of the pointers or flags
comment|// in __c_file_type.
name|virtual
name|streamsize
name|sys_read
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
comment|// A simple write function for the external byte sequence, that
comment|// does no mucking around with or setting of the pointers or flags
comment|// in __c_file_type.
name|virtual
name|streamsize
name|sys_write
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
comment|// A simple seek function for the external byte sequence, that
comment|// does no mucking around with or setting of the pointers or flags
comment|// in __c_file_type.
name|virtual
name|streamoff
name|sys_seek
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|)
block|;
name|virtual
name|int
name|sys_close
argument_list|()
block|;
name|virtual
name|int
name|sys_stat
argument_list|(
name|void
operator|*
name|__v
argument_list|)
block|;
name|virtual
name|int
name|showmanyc
argument_list|()
block|;
name|virtual
name|void
name|imbue
argument_list|(
name|void
operator|*
name|__v
argument_list|)
block|;     }
expr_stmt|;
comment|// __basic_file<char> specializations
name|template
operator|<
operator|>
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|__basic_file
argument_list|(
name|__c_lock
operator|*
name|__lock
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|overflow
argument_list|(
argument|int __c
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|underflow
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|uflow
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|pbackfail
argument_list|(
argument|int __c
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamsize
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|xsputn
argument_list|(
argument|const char* __s
argument_list|,
argument|streamsize __n
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamoff
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|seekoff
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamoff
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|seekpos
argument_list|(
argument|streamoff __pos
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streambuf
operator|*
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|setbuf
argument_list|(
argument|char* __b
argument_list|,
argument|int __len
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|sync
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|char
operator|>
operator|::
name|doallocate
argument_list|()
expr_stmt|;
comment|// __basic_file<wchar_t> specializations
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
name|template
operator|<
operator|>
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|__basic_file
argument_list|(
name|__c_lock
operator|*
name|__lock
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|overflow
argument_list|(
argument|int __c
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|underflow
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|uflow
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|pbackfail
argument_list|(
argument|int __c
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamsize
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|xsputn
argument_list|(
argument|const wchar_t* __s
argument_list|,
argument|streamsize __n
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamoff
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|seekoff
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streamoff
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|seekpos
argument_list|(
argument|streamoff __pos
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|streambuf
operator|*
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|setbuf
argument_list|(
argument|wchar_t* __b
argument_list|,
argument|int __len
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|sync
argument_list|()
expr_stmt|;
name|template
operator|<
operator|>
name|int
name|__basic_file
operator|<
name|wchar_t
operator|>
operator|::
name|doallocate
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
operator|~
name|__basic_file
argument_list|()
block|{
name|_IO_file_finish
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_CharT
operator|>
name|void
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|_M_open_mode
argument_list|(
argument|ios_base::openmode __mode
argument_list|,
argument|int& __p_mode
argument_list|,
argument|int& __rw_mode
argument_list|,
argument|char*
comment|/*__c_mode*/
argument_list|)
block|{
ifdef|#
directive|ifdef
name|O_BINARY
name|bool
name|__testb
operator|=
name|__mode
operator|&
name|ios_base
operator|::
name|binary
block|;
endif|#
directive|endif
name|bool
name|__testi
operator|=
name|__mode
operator|&
name|ios_base
operator|::
name|in
block|;
name|bool
name|__testo
operator|=
name|__mode
operator|&
name|ios_base
operator|::
name|out
block|;
name|bool
name|__testt
operator|=
name|__mode
operator|&
name|ios_base
operator|::
name|trunc
block|;
name|bool
name|__testa
operator|=
name|__mode
operator|&
name|ios_base
operator|::
name|app
block|;
if|if
condition|(
operator|!
name|__testi
operator|&&
name|__testo
operator|&&
operator|!
name|__testt
operator|&&
operator|!
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_WRONLY
operator||
name|O_TRUNC
operator||
name|O_CREAT
expr_stmt|;
name|__rw_mode
operator|=
name|_IO_NO_READS
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|__testi
operator|&&
name|__testo
operator|&&
operator|!
name|__testt
operator|&&
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_WRONLY
operator||
name|O_APPEND
operator||
name|O_CREAT
expr_stmt|;
name|__rw_mode
operator|=
name|_IO_NO_READS
operator||
name|_IO_IS_APPENDING
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|__testi
operator|&&
name|__testo
operator|&&
name|__testt
operator|&&
operator|!
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_WRONLY
operator||
name|O_TRUNC
operator||
name|O_CREAT
expr_stmt|;
name|__rw_mode
operator|=
name|_IO_NO_READS
expr_stmt|;
block|}
if|if
condition|(
name|__testi
operator|&&
operator|!
name|__testo
operator|&&
operator|!
name|__testt
operator|&&
operator|!
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_RDONLY
expr_stmt|;
name|__rw_mode
operator|=
name|_IO_NO_WRITES
expr_stmt|;
block|}
if|if
condition|(
name|__testi
operator|&&
name|__testo
operator|&&
operator|!
name|__testt
operator|&&
operator|!
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_RDWR
expr_stmt|;
name|__rw_mode
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|__testi
operator|&&
name|__testo
operator|&&
name|__testt
operator|&&
operator|!
name|__testa
condition|)
block|{
name|__p_mode
operator|=
name|O_RDWR
operator||
name|O_TRUNC
operator||
name|O_CREAT
expr_stmt|;
name|__rw_mode
operator|=
literal|0
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|O_BINARY
if|if
condition|(
name|__testb
condition|)
name|__p_mode
operator||=
name|O_BINARY
expr_stmt|;
endif|#
directive|endif
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__basic_file
operator|<
name|_CharT
operator|>
operator|*
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_open
argument_list|(
argument|__c_file_type* __f
argument_list|,
argument|ios_base::openmode __mode
argument_list|)
block|{
name|__basic_file
operator|*
name|__ret
operator|=
name|NULL
block|;
name|int
name|__fd
operator|=
name|fileno
argument_list|(
name|__f
argument_list|)
block|;
name|int
name|__p_mode
operator|=
literal|0
block|;
name|int
name|__rw_mode
operator|=
name|_IO_NO_READS
operator|+
name|_IO_NO_WRITES
block|;
name|char
name|__c_mode
index|[
literal|4
index|]
block|;
name|_M_open_mode
argument_list|(
name|__mode
argument_list|,
name|__p_mode
argument_list|,
name|__rw_mode
argument_list|,
name|__c_mode
argument_list|)
block|;
if|if
condition|(
operator|!
name|_IO_file_is_open
argument_list|(
name|this
argument_list|)
condition|)
block|{
name|_fileno
operator|=
name|__fd
expr_stmt|;
name|_flags
operator|&=
operator|~
operator|(
name|_IO_NO_READS
operator|+
name|_IO_NO_WRITES
operator|)
expr_stmt|;
name|_flags
operator||=
name|_IO_DELETE_DONT_CLOSE
expr_stmt|;
name|_offset
operator|=
name|_IO_pos_BAD
expr_stmt|;
name|int
name|__mask
init|=
name|_IO_NO_READS
operator|+
name|_IO_NO_WRITES
operator|+
name|_IO_IS_APPENDING
decl_stmt|;
name|_IO_mask_flags
argument_list|(
name|this
argument_list|,
name|__rw_mode
argument_list|,
name|__mask
argument_list|)
expr_stmt|;
block|}
return|return
name|__ret
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__basic_file
operator|<
name|_CharT
operator|>
operator|*
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|open
argument_list|(
argument|const char* __name
argument_list|,
argument|ios_base::openmode __mode
argument_list|,
argument|int __prot
argument_list|)
block|{
name|__basic_file
operator|*
name|__ret
operator|=
name|NULL
block|;
name|int
name|__p_mode
operator|=
literal|0
block|;
name|int
name|__rw_mode
operator|=
name|_IO_NO_READS
operator|+
name|_IO_NO_WRITES
block|;
name|char
name|__c_mode
index|[
literal|4
index|]
block|;
name|_M_open_mode
argument_list|(
name|__mode
argument_list|,
name|__p_mode
argument_list|,
name|__rw_mode
argument_list|,
name|__c_mode
argument_list|)
block|;
if|if
condition|(
operator|!
name|_IO_file_is_open
argument_list|(
name|this
argument_list|)
condition|)
block|{
name|__c_file_type
modifier|*
name|__f
decl_stmt|;
name|__f
operator|=
name|_IO_file_open
argument_list|(
name|this
argument_list|,
name|__name
argument_list|,
name|__p_mode
argument_list|,
name|__prot
argument_list|,
name|__rw_mode
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__ret
operator|=
name|__f
condition|?
name|this
else|:
name|NULL
expr_stmt|;
block|}
return|return
name|__ret
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
name|bool
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|is_open
argument_list|()
block|{
return|return
name|_fileno
operator|>=
literal|0
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
name|__basic_file
operator|<
name|_CharT
operator|>
operator|*
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|close
argument_list|()
block|{
return|return
name|_IO_file_close_it
argument_list|(
name|this
argument_list|)
operator|?
name|static_cast
operator|<
name|__basic_file
operator|*
operator|>
operator|(
name|NULL
operator|)
operator|:
name|this
return|;
block|}
name|template
operator|<
name|typename
name|_CharT
operator|>
name|streamsize
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|xsgetn
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|{
return|return
name|_IO_file_xsgetn
argument_list|(
name|this
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|streamsize
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_read
argument_list|(
argument|_CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|{
return|return
name|_IO_file_read
argument_list|(
name|this
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|streamsize
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_write
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|{
return|return
name|_IO_file_write
argument_list|(
name|this
argument_list|,
name|__s
argument_list|,
name|__n
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|streamoff
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_seek
argument_list|(
argument|streamoff __pos
argument_list|,
argument|ios_base::seekdir __way
argument_list|)
block|{
return|return
name|_IO_file_seek
argument_list|(
name|this
argument_list|,
name|__pos
argument_list|,
name|__way
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|int
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_close
argument_list|()
block|{
return|return
name|_IO_file_close
argument_list|(
name|this
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|int
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|sys_stat
argument_list|(
argument|void* __v
argument_list|)
block|{
return|return
name|_IO_file_stat
argument_list|(
name|this
argument_list|,
name|__v
argument_list|)
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|int
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|showmanyc
argument_list|()
block|{
return|return
name|EOF
return|;
block|}
comment|// NB: Unused.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|void
name|__basic_file
operator|<
name|_CharT
operator|>
operator|::
name|imbue
argument_list|(
argument|void*
comment|/*__v*/
argument_list|)
block|{ }
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
comment|// _CPP_BASIC_FILE
end_comment

end_unit

