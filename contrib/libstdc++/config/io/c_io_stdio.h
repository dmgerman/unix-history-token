begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// underlying io library  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
comment|// c_io_stdio.h - Defines for using "C" stdio.h
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_C_IO_STDIO_H
end_ifndef

begin_define
define|#
directive|define
name|_C_IO_STDIO_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<cstddef>
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
typedef|typedef
name|__gthread_mutex_t
name|__c_lock
typedef|;
comment|// for basic_file.h
typedef|typedef
name|FILE
name|__c_file
typedef|;
comment|// XXX GLIBCXX_ABI Deprecated
comment|// for ios_base.h
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
literal|0x0001
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_dec
init|=
literal|0x0002
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_fixed
init|=
literal|0x0004
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_hex
init|=
literal|0x0008
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_internal
init|=
literal|0x0010
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_left
init|=
literal|0x0020
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_oct
init|=
literal|0x0040
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_right
init|=
literal|0x0080
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_scientific
init|=
literal|0x0100
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showbase
init|=
literal|0x0200
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showpoint
init|=
literal|0x0400
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_showpos
init|=
literal|0x0800
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_skipws
init|=
literal|0x1000
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_unitbuf
init|=
literal|0x2000
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_uppercase
init|=
literal|0x4000
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_adjustfield
init|=
literal|0x0020
operator||
literal|0x0080
operator||
literal|0x0010
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_basefield
init|=
literal|0x0002
operator||
literal|0x0040
operator||
literal|0x0008
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_floatfield
init|=
literal|0x0100
operator||
literal|0x0004
decl_stmt|;
comment|// 27.4.2.1.3  Type ios_base::iostate
specifier|static
specifier|const
name|__int_type
name|_S_badbit
init|=
literal|0x01
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_eofbit
init|=
literal|0x02
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_failbit
init|=
literal|0x04
decl_stmt|;
comment|// 27.4.2.1.4  Type openmode
specifier|static
specifier|const
name|__int_type
name|_S_app
init|=
literal|0x01
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_ate
init|=
literal|0x02
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_bin
init|=
literal|0x04
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_in
init|=
literal|0x08
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_out
init|=
literal|0x10
decl_stmt|;
specifier|static
specifier|const
name|__int_type
name|_S_trunc
init|=
literal|0x20
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

