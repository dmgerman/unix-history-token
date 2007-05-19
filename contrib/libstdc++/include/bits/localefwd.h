begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2005, 2006
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
comment|/** @file localefwd.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCALE_FWD_H
end_ifndef

begin_define
define|#
directive|define
name|_LOCALE_FWD_H
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
file|<bits/c++locale.h>
end_include

begin_comment
comment|// Defines __c_locale, config-specific includes
end_comment

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_comment
comment|// For ostreambuf_iterator, istreambuf_iterator
end_comment

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|// 22.1.1 Locale
end_comment

begin_decl_stmt
name|class
name|locale
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 22.1.3 Convenience interfaces
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isspace
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isprint
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|iscntrl
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isupper
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|islower
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isalpha
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isdigit
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|ispunct
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isxdigit
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isalnum
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|bool
name|isgraph
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|_CharT
name|toupper
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|_CharT
name|tolower
argument_list|(
name|_CharT
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.1 and 22.2.1.3 ctype
end_comment

begin_decl_stmt
name|class
name|ctype_base
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|char
operator|>
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|wchar_t
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// NB: Specialized for char and wchar_t in locale_facets.h.
end_comment

begin_decl_stmt
name|class
name|codecvt_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|__enc_traits
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|,
name|typename
name|_StateT
operator|>
name|class
name|codecvt
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|codecvt
operator|<
name|char
operator|,
name|char
operator|,
name|mbstate_t
operator|>
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|codecvt
operator|<
name|wchar_t
operator|,
name|char
operator|,
name|mbstate_t
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|,
name|typename
name|_StateT
operator|>
name|class
name|codecvt_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.2 and 22.2.3 numeric
end_comment

begin_expr_stmt
name|_GLIBCXX_BEGIN_LDBL_NAMESPACE
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|=
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|num_get
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|=
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|num_put
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_END_LDBL_NAMESPACE
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|numpunct
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|numpunct_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.4 collation
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|collate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|collate_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.5 date and time
end_comment

begin_decl_stmt
name|class
name|time_base
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|=
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|time_get
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|=
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|time_get_byname
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|=
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|time_put
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|=
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|time_put_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.6 money
end_comment

begin_decl_stmt
name|class
name|money_base
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|_GLIBCXX_BEGIN_LDBL_NAMESPACE
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|=
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|money_get
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|=
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|money_put
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_GLIBCXX_END_LDBL_NAMESPACE
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|=
name|false
operator|>
name|class
name|moneypunct
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|=
name|false
operator|>
name|class
name|moneypunct_byname
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.7 message retrieval
end_comment

begin_decl_stmt
name|class
name|messages_base
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|messages
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|messages_byname
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Facet
operator|>
name|bool
name|has_facet
argument_list|(
argument|const locale& __loc
argument_list|)
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Facet
operator|>
specifier|const
name|_Facet
operator|&
name|use_facet
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Facet
operator|>
specifier|inline
specifier|const
name|_Facet
operator|&
name|__check_facet
argument_list|(
argument|const _Facet* __f
argument_list|)
block|{
if|if
condition|(
operator|!
name|__f
condition|)
name|__throw_bad_cast
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|__f
return|;
end_return

begin_endif
unit|}  _GLIBCXX_END_NAMESPACE
endif|#
directive|endif
end_endif

end_unit

