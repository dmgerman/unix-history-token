begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Specific definitions for GNU/Linux  -*- C++ -*-
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_OS_DEFINES
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCPP_OS_DEFINES
value|1
end_define

begin_comment
comment|// System-specific #define, typedefs, corrections, etc, go here.  This
end_comment

begin_comment
comment|// file will come before all others.
end_comment

begin_comment
comment|// This keeps isanum, et al from being propagated as macros.
end_comment

begin_define
define|#
directive|define
name|__NO_CTYPE
value|1
end_define

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|+
literal|0
operator|==
literal|0
operator|)
end_if

begin_comment
comment|// The types __off_t and __off64_t are not defined through<sys/types.h>
end_comment

begin_comment
comment|// as _G_config assumes.  For libc5 and glibc 2.0 instead use
end_comment

begin_comment
comment|//<gnu/types.h> and the old name for __off64_t.
end_comment

begin_include
include|#
directive|include
file|<gnu/types.h>
end_include

begin_typedef
typedef|typedef
name|__loff_t
name|__off64_t
typedef|;
end_typedef

begin_comment
comment|// These systems have declarations mismatching those in libio.h by
end_comment

begin_comment
comment|// omitting throw qualifiers.  Cleanest way out is to not provide
end_comment

begin_comment
comment|// throw-qualifiers at all.  Defining it as empty here will make libio.h
end_comment

begin_comment
comment|// not define it.
end_comment

begin_undef
undef|#
directive|undef
name|__THROW
end_undef

begin_define
define|#
directive|define
name|__THROW
end_define

begin_comment
comment|// Tell Glibc not to try to provide its own inline versions of
end_comment

begin_comment
comment|// some math functions.  Those cause assembly-time clashes with
end_comment

begin_comment
comment|// our definitions.
end_comment

begin_define
define|#
directive|define
name|__NO_MATH_INLINES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|__GLIBC__
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_comment
comment|// We must not see the optimized string functions GNU libc defines.
end_comment

begin_define
define|#
directive|define
name|__NO_STRING_INLINES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

