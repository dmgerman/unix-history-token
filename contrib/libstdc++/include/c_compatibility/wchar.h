begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- compatibility header.
end_comment

begin_comment
comment|// Copyright (C) 2002, 2003 Free Software Foundation, Inc.
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
name|_GLIBCXX_WCHAR_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_WCHAR_H
value|1
end_define

begin_include
include|#
directive|include
file|<cwchar>
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|mbstate_t
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_USE_WCHAR_T
end_if

begin_expr_stmt
name|using
name|std
operator|::
name|wint_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|btowc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wctob
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgetwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgetwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fgetws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fputwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fputws
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fwide
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fwprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|fwscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|swprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|swscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
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
name|std
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
name|std
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
name|std
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
name|std
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
name|std
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
name|std
operator|::
name|wprintf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wscanf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|getwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|getwchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbsinit
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbrlen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbrtowc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|mbsrtowcs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsrtombs
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|putwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|putwchar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ungetwc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcrtomb
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
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
name|std
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
name|std
operator|::
name|wcstol
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcstoul
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcscpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsncpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcscat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsncat
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcscmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcscoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsncmmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsxfrm
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcschr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcscspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcslen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcspbrk
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsrchr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsspn
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsstr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcstok
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wmemchr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wmemcmp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wmemcpy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wmemmove
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wmemset
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcsftime
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|_GLIBCXX_USE_C99
end_if

begin_expr_stmt
name|using
name|std
operator|::
name|wcstold
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcstoll
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|wcstoull
expr_stmt|;
end_expr_stmt

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

