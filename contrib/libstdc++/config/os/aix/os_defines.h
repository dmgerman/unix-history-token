begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Specific definitions for AIX  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2002 Free Software Foundation, Inc.
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_OS_DEFINES
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCPP_OS_DEFINES
end_define

begin_comment
comment|// System-specific #define, typedefs, corrections, etc, go here.  This
end_comment

begin_comment
comment|// file will come before all others.
end_comment

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE
end_undef

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
value|500
end_define

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE_EXTENDED
end_undef

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
end_define

begin_comment
comment|// off64_t
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LARGE_FILE_API
end_ifndef

begin_define
define|#
directive|define
name|_LARGE_FILE_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// atomic types
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__off_t
value|off_t
end_define

begin_define
define|#
directive|define
name|__off64_t
value|off64_t
end_define

begin_define
define|#
directive|define
name|__ssize_t
value|ssize_t
end_define

begin_undef
undef|#
directive|undef
name|_G_USING_THUNKS
end_undef

begin_define
define|#
directive|define
name|_G_USING_THUNKS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

