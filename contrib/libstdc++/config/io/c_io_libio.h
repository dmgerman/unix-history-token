begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// underlying io library  -*- C++ -*-
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
comment|// c_io_libio.h - Defines for using the GNU libio
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_IO_LIBIO_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_IO_LIBIO_H
value|1
end_define

begin_include
include|#
directive|include
file|<libio.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// from fpos.h
typedef|typedef
name|_IO_ssize_t
name|streamsize
typedef|;
comment|// Signed integral type
typedef|typedef
name|_IO_ssize_t
name|wstreamsize
typedef|;
if|#
directive|if
name|defined
argument_list|(
name|_G_IO_IO_FILE_VERSION
argument_list|)
operator|&&
name|_G_IO_IO_FILE_VERSION
operator|==
literal|0x20001
typedef|typedef
name|_IO_off64_t
name|streamoff
typedef|;
typedef|typedef
name|_IO_fpos64_t
name|__c_streampos
typedef|;
else|#
directive|else
typedef|typedef
name|_IO_off_t
name|streamoff
typedef|;
typedef|typedef
name|_IO_fpos_t
name|__c_streampos
typedef|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_THREADS
typedef|typedef
name|_IO_lock_t
name|__c_lock
typedef|;
else|#
directive|else
typedef|typedef
name|int
name|__c_lock
typedef|;
endif|#
directive|endif
comment|// from basic_file.h
typedef|typedef
name|_IO_FILE
name|__c_file_type
typedef|;
typedef|typedef
name|_IO_wide_data
name|__c_wfile_type
typedef|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
extern|extern
literal|"C"
name|_IO_codecvt
name|__c_libio_codecvt
decl_stmt|;
endif|#
directive|endif
comment|// from ios_base.h
struct|struct
name|__ios_flags
block|{
typedef|typedef
name|short
name|__int_type
typedef|;
specifier|static
specifier|const
name|__int_type
name|_S_boolalpha
init|=
name|_IO_BAD_SEEN
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_dec
init|=
name|_IO_DEC
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_fixed
init|=
name|_IO_FIXED
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_hex
init|=
name|_IO_HEX
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_internal
init|=
name|_IO_INTERNAL
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_left
init|=
name|_IO_LEFT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_oct
init|=
name|_IO_OCT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_right
init|=
name|_IO_RIGHT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_scientific
init|=
name|_IO_SCIENTIFIC
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showbase
init|=
name|_IO_SHOWBASE
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showpoint
init|=
name|_IO_SHOWPOINT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showpos
init|=
name|_IO_SHOWPOS
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_skipws
init|=
name|_IO_SKIPWS
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_unitbuf
init|=
name|_IO_UNITBUF
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_uppercase
init|=
name|_IO_UPPERCASE
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_adjustfield
init|=
name|_IO_LEFT
operator||
name|_IO_RIGHT
operator||
name|_IO_INTERNAL
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_basefield
init|=
name|_IO_DEC
operator||
name|_IO_OCT
operator||
name|_IO_HEX
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_floatfield
init|=
name|_IO_SCIENTIFIC
operator||
name|_IO_FIXED
decl_stmt|;
comment|// 27.4.2.1.3  Type ios_base::iostate
specifier|static
specifier|const
name|__int_type
name|_S_badbit
init|=
name|_IO_BAD_SEEN
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_eofbit
init|=
name|_IO_EOF_SEEN
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_failbit
init|=
name|_IO_ERR_SEEN
decl_stmt|;
comment|// 27.4.2.1.4  Type openmode
specifier|static
specifier|const
name|__int_type
name|_S_app
init|=
name|_IOS_APPEND
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_ate
init|=
name|_IOS_ATEND
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_bin
init|=
name|_IOS_BIN
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_in
init|=
name|_IOS_INPUT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_out
init|=
name|_IOS_OUTPUT
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_trunc
init|=
name|_IOS_TRUNC
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _CPP_IO_LIBIO_H
end_comment

end_unit

