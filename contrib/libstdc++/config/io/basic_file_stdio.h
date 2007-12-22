begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Wrapper of C-language FILE struct -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005
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
name|_BASIC_FILE_STDIO_H
end_ifndef

begin_define
define|#
directive|define
name|_BASIC_FILE_STDIO_H
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

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|// Generic declaration.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__basic_file
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__basic_file
operator|<
name|char
operator|>
block|{
comment|// Underlying data source/sink.
name|__c_file
operator|*
name|_M_cfile
block|;
comment|// True iff we opened _M_cfile, and thus must close it ourselves.
name|bool
name|_M_cfile_created
block|;
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
name|__basic_file
operator|*
name|sys_open
argument_list|(
name|__c_file
operator|*
name|__file
argument_list|,
name|ios_base
operator|::
name|openmode
argument_list|)
block|;
name|__basic_file
operator|*
name|sys_open
argument_list|(
argument|int __fd
argument_list|,
argument|ios_base::openmode __mode
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
specifier|const
block|;
name|int
name|fd
argument_list|()
block|;
name|__c_file
operator|*
name|file
argument_list|()
block|;
operator|~
name|__basic_file
argument_list|()
block|;
name|streamsize
name|xsputn
argument_list|(
argument|const char* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
name|streamsize
name|xsputn_2
argument_list|(
argument|const char* __s1
argument_list|,
argument|streamsize __n1
argument_list|,
argument|const char* __s2
argument_list|,
argument|streamsize __n2
argument_list|)
block|;
name|streamsize
name|xsgetn
argument_list|(
argument|char* __s
argument_list|,
argument|streamsize __n
argument_list|)
block|;
name|streamoff
name|seekoff
argument_list|(
argument|streamoff __off
argument_list|,
argument|ios_base::seekdir __way
argument_list|)
block|;
name|int
name|sync
argument_list|()
block|;
name|streamsize
name|showmanyc
argument_list|()
block|;     }
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

