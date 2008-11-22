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
comment|// ISO C++ 14882:<cwctype>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file cwctype  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c wctype.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CWCTYPE
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CWCTYPE
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

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_WCTYPE_H
end_if

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Get rid of those macros defined in<wctype.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|iswalnum
end_undef

begin_undef
undef|#
directive|undef
name|iswalpha
end_undef

begin_if
if|#
directive|if
name|_GLIBCXX_HAVE_ISWBLANK
end_if

begin_undef
undef|#
directive|undef
name|iswblank
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|iswcntrl
end_undef

begin_undef
undef|#
directive|undef
name|iswdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswgraph
end_undef

begin_undef
undef|#
directive|undef
name|iswlower
end_undef

begin_undef
undef|#
directive|undef
name|iswprint
end_undef

begin_undef
undef|#
directive|undef
name|iswprint
end_undef

begin_undef
undef|#
directive|undef
name|iswpunct
end_undef

begin_undef
undef|#
directive|undef
name|iswspace
end_undef

begin_undef
undef|#
directive|undef
name|iswupper
end_undef

begin_undef
undef|#
directive|undef
name|iswxdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswctype
end_undef

begin_undef
undef|#
directive|undef
name|towlower
end_undef

begin_undef
undef|#
directive|undef
name|towupper
end_undef

begin_undef
undef|#
directive|undef
name|towctrans
end_undef

begin_undef
undef|#
directive|undef
name|wctrans
end_undef

begin_undef
undef|#
directive|undef
name|wctype
end_undef

begin_if
if|#
directive|if
name|_GLIBCXX_USE_WCHAR_T
end_if

begin_decl_stmt
name|namespace
name|std
block|{
name|using
operator|::
name|wint_t
expr_stmt|;
comment|// cwchar
name|using
operator|::
name|wctype_t
expr_stmt|;
name|using
operator|::
name|wctrans_t
expr_stmt|;
name|using
operator|::
name|iswalnum
expr_stmt|;
name|using
operator|::
name|iswalpha
expr_stmt|;
if|#
directive|if
name|_GLIBCXX_HAVE_ISWBLANK
name|using
operator|::
name|iswblank
expr_stmt|;
endif|#
directive|endif
name|using
operator|::
name|iswcntrl
expr_stmt|;
name|using
operator|::
name|iswdigit
expr_stmt|;
name|using
operator|::
name|iswgraph
expr_stmt|;
name|using
operator|::
name|iswlower
expr_stmt|;
name|using
operator|::
name|iswprint
expr_stmt|;
name|using
operator|::
name|iswprint
expr_stmt|;
name|using
operator|::
name|iswpunct
expr_stmt|;
name|using
operator|::
name|iswspace
expr_stmt|;
name|using
operator|::
name|iswupper
expr_stmt|;
name|using
operator|::
name|iswxdigit
expr_stmt|;
name|using
operator|::
name|iswctype
expr_stmt|;
name|using
operator|::
name|towlower
expr_stmt|;
name|using
operator|::
name|towupper
expr_stmt|;
name|using
operator|::
name|towctrans
expr_stmt|;
name|using
operator|::
name|wctrans
expr_stmt|;
name|using
operator|::
name|wctype
expr_stmt|;
block|}
end_decl_stmt

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

