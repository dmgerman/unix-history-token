begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- header wrapper.
end_comment

begin_comment
comment|// Copyright (C) 1997-1999, 2000 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 21
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

begin_include
include|#
directive|include
file|<bits/std_cstdio.h>
end_include

begin_decl_stmt
name|namespace
name|_C_legacy
block|{
extern|extern
literal|"C"
block|{
define|#
directive|define
name|_IN_C_LEGACY_
pragma|#
directive|pragma
name|GCC
name|system_header
empty|#     include_next<wchar.h>
block|}
if|#
directive|if
literal|0
comment|// XXX
block|inline int    fwprintf(FILE* __stream, const wchar_t* __format, ...);     inline int    fwscanf(FILE* __stream, const wchar_t* __format, ...);     inline int    vfwprintf(FILE* __stream, const wchar_t* __format, va_list __arg);     inline int    vfwscanf(FILE* __stream, const wchar_t* __format, va_list __arg);    inline wint_t    _CPP_fgetwc_capture(FILE* __stream)   { return fgetwc(__stream); }    inline wchar_t*   _CPP_fgetws_capture(wchar_t* __s, int __n, FILE* __stream)   { return fgetws(__s, __n, __stream); }    inline wint_t    _CPP_fputwc_capture(wchar_t __c, FILE* __stream)   { return fputwc(__c, __stream); }    inline int    _CPP_fputws_capture(const wchar_t* __s, FILE* __stream)   { return fputws(__s, __stream); }    inline int    _CPP_fwide_capture(FILE* __stream, int __mode)    { return fwide(__stream, __mode); }    inline wint_t    _CPP_fgetwc_capture(FILE* __stream)   { return fgetwc(__stream); }    inline wint_t    _CPP_putwc_capture(wchar_t __c, FILE* __stream)   { return putwc(__c, __stream); }      inline wint_t    _CPP_ungetwc_capture(wint_t __c, FILE* __stream)   { return ungetwc(__c, __stream); }
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|wchar_t
end_undef

begin_undef
undef|#
directive|undef
name|wint_t
end_undef

begin_undef
undef|#
directive|undef
name|mbstate_t
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
name|wprintf
end_undef

begin_undef
undef|#
directive|undef
name|wscanf
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
name|ungetwc
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
name|wcstold
end_undef

begin_undef
undef|#
directive|undef
name|wcstol
end_undef

begin_undef
undef|#
directive|undef
name|wcstoll
end_undef

begin_undef
undef|#
directive|undef
name|wcstoul
end_undef

begin_undef
undef|#
directive|undef
name|wcstoull
end_undef

begin_undef
undef|#
directive|undef
name|wcscpy
end_undef

begin_undef
undef|#
directive|undef
name|wcsncpy
end_undef

begin_undef
undef|#
directive|undef
name|wcscat
end_undef

begin_undef
undef|#
directive|undef
name|wcsncat
end_undef

begin_undef
undef|#
directive|undef
name|wcsmp
end_undef

begin_undef
undef|#
directive|undef
name|wcscoll
end_undef

begin_undef
undef|#
directive|undef
name|wcsncmp
end_undef

begin_undef
undef|#
directive|undef
name|wcsxfrm
end_undef

begin_undef
undef|#
directive|undef
name|wcschr
end_undef

begin_undef
undef|#
directive|undef
name|wcscspn
end_undef

begin_undef
undef|#
directive|undef
name|wcslen
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
name|wcstok
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
name|wcsftime
end_undef

begin_undef
undef|#
directive|undef
name|btowc
end_undef

begin_undef
undef|#
directive|undef
name|wctob
end_undef

begin_undef
undef|#
directive|undef
name|mbsinit
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
name|wcrtomb
end_undef

begin_undef
undef|#
directive|undef
name|mbsrtowcs
end_undef

begin_undef
undef|#
directive|undef
name|wcsrtombs
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
name|using
name|_C_legacy
operator|::
name|wint_t
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbstate_t
expr_stmt|;
if|#
directive|if
literal|0
block|using _C_legacy::swprintf;   using _C_legacy::swscanf;   using _C_legacy::vswprintf;   using _C_legacy::vswscanf;   using _C_legacy::vwprintf;   using _C_legacy::vwscanf;   using _C_legacy::wprintf;   using _C_legacy::wscanf;   using _C_legacy::getwchar;   using _C_legacy::putwchar;
endif|#
directive|endif
name|using
name|_C_legacy
operator|::
name|wcstod
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstof
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstold
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstol
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstoll
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstoul
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstoull
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcscpy
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsncpy
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcscat
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsncat
expr_stmt|;
if|#
directive|if
literal|0
block|using _C_legacy::wcsmp;
endif|#
directive|endif
name|using
name|_C_legacy
operator|::
name|wcscoll
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsncmp
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsxfrm
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcschr
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcscspn
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcslen
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcspbrk
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsrchr
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsspn
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsstr
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcstok
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wmemchr
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wmemcmp
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wmemcpy
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wmemmove
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wmemset
expr_stmt|;
if|#
directive|if
literal|0
block|using _C_legacy::wcsftime;
endif|#
directive|endif
name|using
name|_C_legacy
operator|::
name|btowc
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wctob
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbsinit
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbrlen
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbrtowc
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcrtomb
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mbsrtowcs
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wcsrtombs
expr_stmt|;
if|#
directive|if
literal|0
comment|// XXX
block|inline int    fwprintf(FILE* __stream, const wchar_t* __format, ...);     inline int    fwscanf(FILE* __stream, const wchar_t* __format, ...);     inline int    vfwprintf(FILE* __stream, const wchar_t* __format, va_list __arg);     inline int    vfwscanf(FILE* __stream, const wchar_t* __format, va_list __arg);    inline wint_t    fgetwc(FILE* __stream)   { return _C_legacy::_CPP_fgetwc_capture(__stream); }    inline wchar_t*   fgetws(wchar_t* __s, int __n, FILE* __stream)    { return _C_legacy::_CPP_fgetws_capture(__s, __n, __stream); }    inline wint_t    fputwc(wchar_t __c, FILE* __stream)   { return _C_legacy::_CPP_fputwc_capture(__c, __stream); }    inline int    fputws(const wchar_t* __s, FILE* __stream)   { return _C_legacy::_CPP_fputws_capture(__s, __stream); }    inline int    fwide(FILE* __stream, int __mode)   { return _C_legacy::_CPP_fwide_capture(__stream, __mode); }    inline wint_t    getwc(FILE* __stream)   { return _C_legacy::_CPP_getwc_capture(__stream); }    inline wint_t    putwc(wchar_t __c, FILE* __stream)   { return _C_legacy::_CPP_putwc_capture(__c, __stream); }      inline wint_t    ungetwc(wint_t __c, FILE* __stream)   { return _C_legacy::_CPP_ungetwc_capture(__c, __stream); }
endif|#
directive|endif
block|}
end_decl_stmt

begin_undef
undef|#
directive|undef
name|_IN_C_LEGACY_
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

