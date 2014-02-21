begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Wrapper for underlying C-language localization -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006
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
comment|/** @file c++locale.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 22.8  Standard locale categories.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Written by Benjamin Kosnik<bkoz@redhat.com>
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_C_LOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_C_LOCALE_H
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
file|<clocale>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_comment
comment|// get std::strlen
end_comment

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_comment
comment|// get std::vsnprintf or std::vsprintf
end_comment

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_CATEGORIES
value|0
end_define

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_typedef
typedef|typedef
name|int
modifier|*
name|__c_locale
typedef|;
end_typedef

begin_comment
comment|// Convert numeric value of type double and long double to string and
end_comment

begin_comment
comment|// return length of string.  If vsnprintf is available use it, otherwise
end_comment

begin_comment
comment|// fall back to the unsafe vsprintf which, in general, can be dangerous
end_comment

begin_comment
comment|// and should be avoided.
end_comment

begin_decl_stmt
specifier|inline
name|int
name|__convert_from_v
argument_list|(
specifier|const
name|__c_locale
operator|&
argument_list|,
name|char
operator|*
name|__out
argument_list|,
specifier|const
name|int
name|__size
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|,
specifier|const
name|char
operator|*
name|__fmt
argument_list|,
operator|...
argument_list|)
block|{
name|char
modifier|*
name|__old
init|=
name|std
operator|::
name|setlocale
argument_list|(
name|LC_NUMERIC
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|char
modifier|*
name|__sav
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|std
operator|::
name|strcmp
argument_list|(
name|__old
argument_list|,
literal|"C"
argument_list|)
condition|)
block|{
name|__sav
operator|=
name|new
name|char
index|[
name|std
operator|::
name|strlen
argument_list|(
name|__old
argument_list|)
operator|+
literal|1
index|]
expr_stmt|;
name|std
operator|::
name|strcpy
argument_list|(
name|__sav
argument_list|,
name|__old
argument_list|)
expr_stmt|;
name|std
operator|::
name|setlocale
argument_list|(
name|LC_NUMERIC
argument_list|,
literal|"C"
argument_list|)
expr_stmt|;
block|}
name|va_list
name|__args
decl_stmt|;
name|va_start
argument_list|(
name|__args
argument_list|,
name|__fmt
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_C99
specifier|const
name|int
name|__ret
init|=
name|std
operator|::
name|vsnprintf
argument_list|(
name|__out
argument_list|,
name|__size
argument_list|,
name|__fmt
argument_list|,
name|__args
argument_list|)
decl_stmt|;
else|#
directive|else
specifier|const
name|int
name|__ret
init|=
name|std
operator|::
name|vsprintf
argument_list|(
name|__out
argument_list|,
name|__fmt
argument_list|,
name|__args
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|__args
argument_list|)
expr_stmt|;
if|if
condition|(
name|__sav
condition|)
block|{
name|std
operator|::
name|setlocale
argument_list|(
name|LC_NUMERIC
argument_list|,
name|__sav
argument_list|)
expr_stmt|;
name|delete
index|[]
name|__sav
decl_stmt|;
block|}
return|return
name|__ret
return|;
block|}
end_decl_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

