begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
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
comment|// ISO C++ 14882: 21.4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file cwchar  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c wchar.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CWCHAR
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CWCHAR
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
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_if
if|#
directive|if
name|_GLIBCPP_HAVE_WCHAR_H
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Need to do a bit of trickery here with mbstate_t as char_traits
end_comment

begin_comment
comment|// assumes it is in wchar.h, regardless of wchar_t specializations.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_HAVE_MBSTATE_T
end_ifndef

begin_extern
extern|extern
literal|"C"
block|{
typedef|typedef
struct|struct
block|{
name|int
name|__fill
index|[
literal|6
index|]
decl_stmt|;
block|}
name|mbstate_t
typedef|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|std
block|{
name|using
operator|::
name|mbstate_t
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Get rid of those macros defined in<wchar.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|btowc
end_undef

begin_undef
undef|#
directive|undef
name|fgetwc
end_undef

begin_undef
undef|#
directive|undef
name|fgetws
end_undef

begin_undef
undef|#
directive|undef
name|fputwc
end_undef

begin_undef
undef|#
directive|undef
name|fputws
end_undef

begin_undef
undef|#
directive|undef
name|fwide
end_undef

begin_undef
undef|#
directive|undef
name|fwprintf
end_undef

begin_undef
undef|#
directive|undef
name|fwscanf
end_undef

begin_undef
undef|#
directive|undef
name|getwc
end_undef

begin_undef
undef|#
directive|undef
name|getwchar
end_undef

begin_undef
undef|#
directive|undef
name|mbrlen
end_undef

begin_undef
undef|#
directive|undef
name|mbrtowc
end_undef

begin_undef
undef|#
directive|undef
name|mbsinit
end_undef

begin_undef
undef|#
directive|undef
name|mbsrtowcs
end_undef

begin_undef
undef|#
directive|undef
name|putwc
end_undef

begin_undef
undef|#
directive|undef
name|putwchar
end_undef

begin_undef
undef|#
directive|undef
name|swprintf
end_undef

begin_undef
undef|#
directive|undef
name|swscanf
end_undef

begin_undef
undef|#
directive|undef
name|ungetwc
end_undef

begin_undef
undef|#
directive|undef
name|vfwprintf
end_undef

begin_undef
undef|#
directive|undef
name|vfwscanf
end_undef

begin_undef
undef|#
directive|undef
name|vswprintf
end_undef

begin_undef
undef|#
directive|undef
name|vswscanf
end_undef

begin_undef
undef|#
directive|undef
name|vwprintf
end_undef

begin_undef
undef|#
directive|undef
name|vwscanf
end_undef

begin_undef
undef|#
directive|undef
name|wcrtomb
end_undef

begin_undef
undef|#
directive|undef
name|wcscat
end_undef

begin_undef
undef|#
directive|undef
name|wcschr
end_undef

begin_undef
undef|#
directive|undef
name|wcscmp
end_undef

begin_undef
undef|#
directive|undef
name|wcscoll
end_undef

begin_undef
undef|#
directive|undef
name|wcscpy
end_undef

begin_undef
undef|#
directive|undef
name|wcscspn
end_undef

begin_undef
undef|#
directive|undef
name|wcsftime
end_undef

begin_undef
undef|#
directive|undef
name|wcslen
end_undef

begin_undef
undef|#
directive|undef
name|wcsncat
end_undef

begin_undef
undef|#
directive|undef
name|wcsncmp
end_undef

begin_undef
undef|#
directive|undef
name|wcsncpy
end_undef

begin_undef
undef|#
directive|undef
name|wcspbrk
end_undef

begin_undef
undef|#
directive|undef
name|wcsrchr
end_undef

begin_undef
undef|#
directive|undef
name|wcsrtombs
end_undef

begin_undef
undef|#
directive|undef
name|wcsspn
end_undef

begin_undef
undef|#
directive|undef
name|wcsstr
end_undef

begin_undef
undef|#
directive|undef
name|wcstod
end_undef

begin_undef
undef|#
directive|undef
name|wcstof
end_undef

begin_undef
undef|#
directive|undef
name|wcstok
end_undef

begin_undef
undef|#
directive|undef
name|wcstol
end_undef

begin_undef
undef|#
directive|undef
name|wcstoul
end_undef

begin_undef
undef|#
directive|undef
name|wcsxfrm
end_undef

begin_undef
undef|#
directive|undef
name|wctob
end_undef

begin_undef
undef|#
directive|undef
name|wmemchr
end_undef

begin_undef
undef|#
directive|undef
name|wmemcmp
end_undef

begin_undef
undef|#
directive|undef
name|wmemcpy
end_undef

begin_undef
undef|#
directive|undef
name|wmemmove
end_undef

begin_undef
undef|#
directive|undef
name|wmemset
end_undef

begin_undef
undef|#
directive|undef
name|wprintf
end_undef

begin_undef
undef|#
directive|undef
name|wscanf
end_undef

begin_if
if|#
directive|if
name|_GLIBCPP_USE_WCHAR_T
end_if

begin_decl_stmt
name|namespace
name|std
block|{
name|using
operator|::
name|wint_t
expr_stmt|;
name|using
operator|::
name|btowc
expr_stmt|;
name|using
operator|::
name|fgetwc
expr_stmt|;
name|using
operator|::
name|fgetws
expr_stmt|;
name|using
operator|::
name|fputwc
expr_stmt|;
name|using
operator|::
name|fputws
expr_stmt|;
name|using
operator|::
name|fwide
expr_stmt|;
name|using
operator|::
name|fwprintf
expr_stmt|;
name|using
operator|::
name|fwscanf
expr_stmt|;
name|using
operator|::
name|getwc
expr_stmt|;
name|using
operator|::
name|getwchar
expr_stmt|;
name|using
operator|::
name|mbrlen
expr_stmt|;
name|using
operator|::
name|mbrtowc
expr_stmt|;
name|using
operator|::
name|mbsinit
expr_stmt|;
name|using
operator|::
name|mbsrtowcs
expr_stmt|;
name|using
operator|::
name|putwc
expr_stmt|;
name|using
operator|::
name|putwchar
expr_stmt|;
name|using
operator|::
name|swprintf
expr_stmt|;
name|using
operator|::
name|swscanf
expr_stmt|;
name|using
operator|::
name|ungetwc
expr_stmt|;
name|using
operator|::
name|vfwprintf
expr_stmt|;
name|using
operator|::
name|vfwscanf
expr_stmt|;
name|using
operator|::
name|vswprintf
expr_stmt|;
name|using
operator|::
name|vswscanf
expr_stmt|;
name|using
operator|::
name|vwprintf
expr_stmt|;
name|using
operator|::
name|vwscanf
expr_stmt|;
name|using
operator|::
name|wcrtomb
expr_stmt|;
name|using
operator|::
name|wcscat
expr_stmt|;
name|using
operator|::
name|wcscmp
expr_stmt|;
name|using
operator|::
name|wcscoll
expr_stmt|;
name|using
operator|::
name|wcscpy
expr_stmt|;
name|using
operator|::
name|wcscspn
expr_stmt|;
name|using
operator|::
name|wcsftime
expr_stmt|;
name|using
operator|::
name|wcslen
expr_stmt|;
name|using
operator|::
name|wcsncat
expr_stmt|;
name|using
operator|::
name|wcsncmp
expr_stmt|;
name|using
operator|::
name|wcsncpy
expr_stmt|;
name|using
operator|::
name|wcsrtombs
expr_stmt|;
name|using
operator|::
name|wcsspn
expr_stmt|;
name|using
operator|::
name|wcstod
expr_stmt|;
name|using
operator|::
name|wcstof
expr_stmt|;
name|using
operator|::
name|wcstok
expr_stmt|;
name|using
operator|::
name|wcstol
expr_stmt|;
name|using
operator|::
name|wcstoul
expr_stmt|;
name|using
operator|::
name|wcsxfrm
expr_stmt|;
name|using
operator|::
name|wctob
expr_stmt|;
name|using
operator|::
name|wmemcmp
expr_stmt|;
name|using
operator|::
name|wmemcpy
expr_stmt|;
name|using
operator|::
name|wmemmove
expr_stmt|;
name|using
operator|::
name|wmemset
expr_stmt|;
name|using
operator|::
name|wprintf
expr_stmt|;
name|using
operator|::
name|wscanf
expr_stmt|;
name|using
operator|::
name|wcschr
expr_stmt|;
specifier|inline
name|wchar_t
modifier|*
name|wcschr
parameter_list|(
name|wchar_t
modifier|*
name|__p
parameter_list|,
name|wchar_t
name|__c
parameter_list|)
block|{
return|return
name|wcschr
argument_list|(
name|const_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|__p
operator|)
argument_list|,
name|__c
argument_list|)
return|;
block|}
name|using
operator|::
name|wcspbrk
expr_stmt|;
specifier|inline
name|wchar_t
modifier|*
name|wcspbrk
parameter_list|(
name|wchar_t
modifier|*
name|__s1
parameter_list|,
name|wchar_t
modifier|*
name|__s2
parameter_list|)
block|{
return|return
name|wcspbrk
argument_list|(
name|const_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__s2
argument_list|)
return|;
block|}
name|using
operator|::
name|wcsrchr
expr_stmt|;
specifier|inline
name|wchar_t
modifier|*
name|wcsrchr
parameter_list|(
name|wchar_t
modifier|*
name|__p
parameter_list|,
name|wchar_t
name|__c
parameter_list|)
block|{
return|return
name|wcsrchr
argument_list|(
name|const_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|__p
operator|)
argument_list|,
name|__c
argument_list|)
return|;
block|}
name|using
operator|::
name|wcsstr
expr_stmt|;
specifier|inline
name|wchar_t
modifier|*
name|wcsstr
parameter_list|(
name|wchar_t
modifier|*
name|__s1
parameter_list|,
name|wchar_t
modifier|*
name|__s2
parameter_list|)
block|{
return|return
name|wcsstr
argument_list|(
name|const_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__s2
argument_list|)
return|;
block|}
name|using
operator|::
name|wmemchr
expr_stmt|;
specifier|inline
name|wchar_t
modifier|*
name|wmemchr
parameter_list|(
name|wchar_t
modifier|*
name|__p
parameter_list|,
name|wchar_t
name|__c
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
return|return
name|wmemchr
argument_list|(
name|const_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|__p
operator|)
argument_list|,
name|__c
argument_list|,
name|__n
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_if
if|#
directive|if
name|_GLIBCPP_USE_C99
end_if

begin_undef
undef|#
directive|undef
name|wcstold
end_undef

begin_undef
undef|#
directive|undef
name|wcstoll
end_undef

begin_undef
undef|#
directive|undef
name|wcstoull
end_undef

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
if|#
directive|if
name|_GLIBCPP_USE_C99_CHECK
operator|||
name|_GLIBCPP_USE_C99_DYNAMIC
extern|extern
literal|"C"
name|long
name|double
function_decl|(
name|wcstold
function_decl|)
parameter_list|(
specifier|const
name|wchar_t
modifier|*
specifier|restrict
parameter_list|,
name|wchar_t
modifier|*
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_DYNAMIC
name|using
operator|::
name|wcstold
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|_GLIBCPP_USE_C99_LONG_LONG_CHECK
operator|||
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
extern|extern
literal|"C"
name|long
name|long
name|int
function_decl|(
name|wcstoll
function_decl|)
parameter_list|(
specifier|const
name|wchar_t
modifier|*
specifier|restrict
parameter_list|,
name|wchar_t
modifier|*
modifier|*
specifier|restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
extern|extern
literal|"C"
name|unsigned
name|long
name|long
name|int
function_decl|(
name|wcstoull
function_decl|)
parameter_list|(
specifier|const
name|wchar_t
modifier|*
specifier|restrict
parameter_list|,
name|wchar_t
modifier|*
modifier|*
specifier|restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|_GLIBCPP_USE_C99_LONG_LONG_DYNAMIC
name|using
operator|::
name|wcstoll
expr_stmt|;
name|using
operator|::
name|wcstoull
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|std
block|{
name|using
name|__gnu_cxx
operator|::
name|wcstold
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|wcstoll
expr_stmt|;
name|using
name|__gnu_cxx
operator|::
name|wcstoull
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_GLIBCPP_USE_WCHAR_T
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

