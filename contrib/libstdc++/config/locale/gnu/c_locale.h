begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Wrapper for underlying C-language localization -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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
name|_CPP_BITS_C_LOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_C_LOCALE_H
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
file|<langinfo.h>
end_include

begin_comment
comment|// For codecvt
end_comment

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_comment
comment|// For codecvt using iconv, iconv_t
end_comment

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_comment
comment|// For messages
end_comment

begin_define
define|#
directive|define
name|_GLIBCPP_C_LOCALE_GNU
value|1
end_define

begin_define
define|#
directive|define
name|_GLIBCPP_NUM_CATEGORIES
value|6
end_define

begin_if
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
end_if

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|uselocale
argument_list|)
name|__uselocale
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|std
block|{
typedef|typedef
name|__locale_t
name|__c_locale
typedef|;
comment|// Convert numeric value of type _Tv to string and return length of
comment|// string.  If snprintf is available use it, otherwise fall back to
comment|// the unsafe sprintf which, in general, can be dangerous and should
comment|// be avoided.
name|template
operator|<
name|typename
name|_Tv
operator|>
name|int
name|__convert_from_v
argument_list|(
argument|char* __out
argument_list|,
argument|const int __size
argument_list|,
argument|const char* __fmt
argument_list|,
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
argument|_Tv __v
argument_list|,
argument|const __c_locale& __cloc
argument_list|,
argument|int __prec = -
literal|1
argument_list|)
block|{
name|__c_locale
name|__old
operator|=
name|__gnu_cxx
operator|::
name|__uselocale
argument_list|(
name|__cloc
argument_list|)
block|;
else|#
directive|else
name|_Tv
name|__v
block|,
specifier|const
name|__c_locale
operator|&
block|,
name|int
name|__prec
operator|=
operator|-
literal|1
block|)
block|{
name|char
operator|*
name|__old
operator|=
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|NULL
argument_list|)
block|;
name|char
operator|*
name|__sav
operator|=
name|static_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|malloc
argument_list|(
name|strlen
argument_list|(
name|__old
argument_list|)
operator|+
literal|1
argument_list|)
operator|)
block|;
if|if
condition|(
name|__sav
condition|)
name|strcpy
argument_list|(
name|__sav
argument_list|,
name|__old
argument_list|)
expr_stmt|;
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|"C"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|int
name|__ret
decl_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_C99
if|if
condition|(
name|__prec
operator|>=
literal|0
condition|)
name|__ret
operator|=
name|snprintf
argument_list|(
name|__out
argument_list|,
name|__size
argument_list|,
name|__fmt
argument_list|,
name|__prec
argument_list|,
name|__v
argument_list|)
expr_stmt|;
else|else
name|__ret
operator|=
name|snprintf
argument_list|(
name|__out
argument_list|,
name|__size
argument_list|,
name|__fmt
argument_list|,
name|__v
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|__prec
operator|>=
literal|0
condition|)
name|__ret
operator|=
name|sprintf
argument_list|(
name|__out
argument_list|,
name|__fmt
argument_list|,
name|__prec
argument_list|,
name|__v
argument_list|)
expr_stmt|;
else|else
name|__ret
operator|=
name|sprintf
argument_list|(
name|__out
argument_list|,
name|__fmt
argument_list|,
name|__v
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
name|__gnu_cxx
operator|::
name|__uselocale
argument_list|(
name|__old
argument_list|)
expr_stmt|;
else|#
directive|else
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|__sav
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|__sav
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|__ret
return|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

