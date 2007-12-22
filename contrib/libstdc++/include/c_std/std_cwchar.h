begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005
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
comment|/** @file include/cwchar  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c wchar.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std (except for names which are defined  *  as macros in C).  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CWCHAR
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CWCHAR
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
name|_GLIBCXX_HAVE_WCHAR_H
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
name|_GLIBCXX_HAVE_MBSTATE_T
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

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_expr_stmt
name|using
operator|::
name|mbstate_t
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
comment|// Get rid of those macros defined in<wchar.h> in lieu of real functions.
undef|#
directive|undef
name|btowc
undef|#
directive|undef
name|fgetwc
undef|#
directive|undef
name|fgetws
undef|#
directive|undef
name|fputwc
undef|#
directive|undef
name|fputws
undef|#
directive|undef
name|fwide
undef|#
directive|undef
name|fwprintf
undef|#
directive|undef
name|fwscanf
undef|#
directive|undef
name|getwc
undef|#
directive|undef
name|getwchar
undef|#
directive|undef
name|mbrlen
undef|#
directive|undef
name|mbrtowc
undef|#
directive|undef
name|mbsinit
undef|#
directive|undef
name|mbsrtowcs
undef|#
directive|undef
name|putwc
undef|#
directive|undef
name|putwchar
undef|#
directive|undef
name|swprintf
undef|#
directive|undef
name|swscanf
undef|#
directive|undef
name|ungetwc
undef|#
directive|undef
name|vfwprintf
if|#
directive|if
name|_GLIBCXX_HAVE_VFWSCANF
undef|#
directive|undef
name|vfwscanf
endif|#
directive|endif
undef|#
directive|undef
name|vswprintf
if|#
directive|if
name|_GLIBCXX_HAVE_VSWSCANF
undef|#
directive|undef
name|vswscanf
endif|#
directive|endif
undef|#
directive|undef
name|vwprintf
if|#
directive|if
name|_GLIBCXX_HAVE_VWSCANF
undef|#
directive|undef
name|vwscanf
endif|#
directive|endif
undef|#
directive|undef
name|wcrtomb
undef|#
directive|undef
name|wcscat
undef|#
directive|undef
name|wcschr
undef|#
directive|undef
name|wcscmp
undef|#
directive|undef
name|wcscoll
undef|#
directive|undef
name|wcscpy
undef|#
directive|undef
name|wcscspn
undef|#
directive|undef
name|wcsftime
undef|#
directive|undef
name|wcslen
undef|#
directive|undef
name|wcsncat
undef|#
directive|undef
name|wcsncmp
undef|#
directive|undef
name|wcsncpy
undef|#
directive|undef
name|wcspbrk
undef|#
directive|undef
name|wcsrchr
undef|#
directive|undef
name|wcsrtombs
undef|#
directive|undef
name|wcsspn
undef|#
directive|undef
name|wcsstr
undef|#
directive|undef
name|wcstod
if|#
directive|if
name|_GLIBCXX_HAVE_WCSTOF
undef|#
directive|undef
name|wcstof
endif|#
directive|endif
undef|#
directive|undef
name|wcstok
undef|#
directive|undef
name|wcstol
undef|#
directive|undef
name|wcstoul
undef|#
directive|undef
name|wcsxfrm
undef|#
directive|undef
name|wctob
undef|#
directive|undef
name|wmemchr
undef|#
directive|undef
name|wmemcmp
undef|#
directive|undef
name|wmemcpy
undef|#
directive|undef
name|wmemmove
undef|#
directive|undef
name|wmemset
undef|#
directive|undef
name|wprintf
undef|#
directive|undef
name|wscanf
if|#
directive|if
name|_GLIBCXX_USE_WCHAR_T
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
name|using
decl|::
name|wint_t
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
operator|::
name|btowc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fgetwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fgetws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fputwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fputws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fwide
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fwprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|fwscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|getwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|getwchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbrlen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbrtowc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbsinit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|mbsrtowcs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|putwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|putwchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|swprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|swscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|ungetwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|vfwprintf
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_VFWSCANF
end_if

begin_expr_stmt
name|using
operator|::
name|vfwscanf
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|vswprintf
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_VSWSCANF
end_if

begin_expr_stmt
name|using
operator|::
name|vswscanf
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|vwprintf
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_VWSCANF
end_if

begin_expr_stmt
name|using
operator|::
name|vwscanf
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|wcrtomb
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcscat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcscmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcscoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcscpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcscspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsftime
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcslen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsncat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsncmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsncpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsrtombs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcstod
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_WCSTOF
end_if

begin_expr_stmt
name|using
operator|::
name|wcstof
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|using
operator|::
name|wcstok
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcstol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcstoul
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcsxfrm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wctob
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wmemcmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wmemcpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wmemmove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wmemset
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcschr
expr_stmt|;
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|using
operator|::
name|wcspbrk
expr_stmt|;
end_expr_stmt

begin_function
specifier|inline
name|wchar_t
modifier|*
name|wcspbrk
parameter_list|(
name|wchar_t
modifier|*
name|__s1
parameter_list|,
specifier|const
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
end_function

begin_expr_stmt
name|using
operator|::
name|wcsrchr
expr_stmt|;
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|using
operator|::
name|wcsstr
expr_stmt|;
end_expr_stmt

begin_function
specifier|inline
name|wchar_t
modifier|*
name|wcsstr
parameter_list|(
name|wchar_t
modifier|*
name|__s1
parameter_list|,
specifier|const
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
end_function

begin_expr_stmt
name|using
operator|::
name|wmemchr
expr_stmt|;
end_expr_stmt

begin_function
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
end_function

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
if|#
directive|if
name|_GLIBCXX_USE_C99
undef|#
directive|undef
name|wcstold
undef|#
directive|undef
name|wcstoll
undef|#
directive|undef
name|wcstoull
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|__gnu_cxx
argument_list|)
if|#
directive|if
name|_GLIBCXX_USE_C99_CHECK
operator|||
name|_GLIBCXX_USE_C99_DYNAMIC
decl|extern "C"
name|long
name|double
argument_list|(
name|wcstold
argument_list|)
argument_list|(
specifier|const
name|wchar_t
operator|*
specifier|restrict
argument_list|,
name|wchar_t
operator|*
operator|*
specifier|restrict
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|wcstold
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99_LONG_LONG_CHECK
operator|||
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_extern
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
end_extern

begin_extern
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
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
end_if

begin_expr_stmt
name|using
operator|::
name|wcstoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|wcstoull
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|_GLIBCXX_END_NAMESPACE
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
name|using
decl|::
name|__gnu_cxx
decl|::
name|wcstold
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|wcstoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
operator|::
name|__gnu_cxx
operator|::
name|wcstoull
expr_stmt|;
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_GLIBCXX_USE_WCHAR_T
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

