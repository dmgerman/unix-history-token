begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
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
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file locale_facets.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_LOCFACETS_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_LOCFACETS_H
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
file|<ctime>
end_include

begin_comment
comment|// For struct tm
end_comment

begin_include
include|#
directive|include
file|<cwctype>
end_include

begin_comment
comment|// For wctype_t
end_comment

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<bits/ios_base.h>
end_include

begin_comment
comment|// For ios_base, ios_base::iostate
end_comment

begin_include
include|#
directive|include
file|<streambuf>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// NB: Don't instantiate required wchar_t facets if no wchar_t support.
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
define|#
directive|define
name|_GLIBCPP_NUM_FACETS
value|28
else|#
directive|else
define|#
directive|define
name|_GLIBCPP_NUM_FACETS
value|14
endif|#
directive|endif
comment|// Convert string to numeric value of type _Tv and store results.
comment|// NB: This is specialized for all required types, there is no
comment|// generic definition.
name|template
operator|<
name|typename
name|_Tv
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char* __in
argument_list|,
argument|_Tv& __out
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|const __c_locale& __cloc
argument_list|,
argument|int __base =
literal|10
argument_list|)
expr_stmt|;
comment|// Explicit specializations for required types.
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|long
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
specifier|const
name|__c_locale
operator|&
argument_list|,
name|int
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char*
argument_list|,
argument|unsigned long&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|const __c_locale&
argument_list|,
argument|int
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char*
argument_list|,
argument|long long&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|const __c_locale&
argument_list|,
argument|int
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char*
argument_list|,
argument|unsigned long long&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|const __c_locale&
argument_list|,
argument|int
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|float
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
specifier|const
name|__c_locale
operator|&
argument_list|,
name|int
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|double
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
specifier|const
name|__c_locale
operator|&
argument_list|,
name|int
argument_list|)
expr_stmt|;
name|template
operator|<
operator|>
name|void
name|__convert_to_v
argument_list|(
argument|const char*
argument_list|,
argument|long double&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|const __c_locale&
argument_list|,
argument|int
argument_list|)
expr_stmt|;
comment|// NB: __pad is a struct, rather than a function, so it can be
comment|// partially-specialized.
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
expr|struct
name|__pad
block|{
specifier|static
name|void
name|_S_pad
argument_list|(
argument|ios_base& __io
argument_list|,
argument|_CharT __fill
argument_list|,
argument|_CharT* __news
argument_list|,
argument|const _CharT* __olds
argument_list|,
argument|const streamsize __newlen
argument_list|,
argument|const streamsize __oldlen
argument_list|,
argument|const bool __num
argument_list|)
block|;     }
expr_stmt|;
comment|// Used by both numeric and monetary facets.
comment|// Check to make sure that the __grouping_tmp string constructed in
comment|// money_get or num_get matches the canonical grouping for a given
comment|// locale.
comment|// __grouping_tmp is parsed L to R
comment|// 1,222,444 == __grouping_tmp of "\1\3\3"
comment|// __grouping is parsed R to L
comment|// 1,222,444 == __grouping of "\3" == "\3\3\3"
name|template
operator|<
name|typename
name|_CharT
operator|>
name|bool
name|__verify_grouping
argument_list|(
specifier|const
name|basic_string
operator|<
name|_CharT
operator|>
operator|&
name|__grouping
argument_list|,
name|basic_string
operator|<
name|_CharT
operator|>
operator|&
name|__grouping_tmp
argument_list|)
expr_stmt|;
comment|// Used by both numeric and monetary facets.
comment|// Inserts "group separator" characters into an array of characters.
comment|// It's recursive, one iteration per group.  It moves the characters
comment|// in the buffer this way: "xxxx12345" -> "12,345xxx".  Call this
comment|// only with __gbeg != __gend.
name|template
operator|<
name|typename
name|_CharT
operator|>
name|_CharT
operator|*
name|__add_grouping
argument_list|(
argument|_CharT* __s
argument_list|,
argument|_CharT __sep
argument_list|,
argument|const char* __gbeg
argument_list|,
argument|const char* __gend
argument_list|,
argument|const _CharT* __first
argument_list|,
argument|const _CharT* __last
argument_list|)
expr_stmt|;
comment|// This template permits specializing facet output code for
comment|// ostreambuf_iterator.  For ostreambuf_iterator, sputn is
comment|// significantly more efficient than incrementing iterators.
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
name|__write
argument_list|(
argument|ostreambuf_iterator<_CharT> __s
argument_list|,
argument|const _CharT* __ws
argument_list|,
argument|int __len
argument_list|)
block|{
name|__s
operator|.
name|_M_put
argument_list|(
name|__ws
argument_list|,
name|__len
argument_list|)
block|;
return|return
name|__s
return|;
block|}
comment|// This is the unspecialized form of the template.
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
specifier|inline
name|_OutIter
name|__write
argument_list|(
argument|_OutIter __s
argument_list|,
argument|const _CharT* __ws
argument_list|,
argument|int __len
argument_list|)
block|{
for|for
control|(
name|int
name|__j
init|=
literal|0
init|;
name|__j
operator|<
name|__len
condition|;
name|__j
operator|++
operator|,
operator|++
name|__s
control|)
operator|*
name|__s
operator|=
name|__ws
index|[
name|__j
index|]
expr_stmt|;
return|return
name|__s
return|;
block|}
end_decl_stmt

begin_comment
comment|// 22.2.1.1  Template class ctype
end_comment

begin_comment
comment|// Include host and configuration specific ctype enums for ctype_base.
end_comment

begin_include
include|#
directive|include
file|<bits/ctype_base.h>
end_include

begin_comment
comment|// Common base for ctype<_CharT>.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__ctype_abstract_base
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|ctype_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
name|bool
name|is
argument_list|(
argument|mask __m
argument_list|,
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_is
argument_list|(
name|__m
argument_list|,
name|__c
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|is
argument_list|(
argument|const char_type *__lo
argument_list|,
argument|const char_type *__hi
argument_list|,
argument|mask *__vec
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_is
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__vec
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|scan_is
argument_list|(
argument|mask __m
argument_list|,
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_scan_is
argument_list|(
name|__m
argument_list|,
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|scan_not
argument_list|(
argument|mask __m
argument_list|,
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_scan_not
argument_list|(
name|__m
argument_list|,
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
name|char_type
name|toupper
argument_list|(
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|toupper
argument_list|(
argument|char_type *__lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_toupper
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
name|char_type
name|tolower
argument_list|(
argument|char_type __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|tolower
argument_list|(
argument|char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_tolower
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
name|char_type
name|widen
argument_list|(
argument|char __c
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|const
name|char
operator|*
name|widen
argument_list|(
argument|const char* __lo
argument_list|,
argument|const char* __hi
argument_list|,
argument|char_type* __to
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_widen
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__to
argument_list|)
return|;
block|}
name|char
name|narrow
argument_list|(
argument|char_type __c
argument_list|,
argument|char __dfault
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_narrow
argument_list|(
name|__c
argument_list|,
name|__dfault
argument_list|)
return|;
block|}
specifier|const
name|char_type
operator|*
name|narrow
argument_list|(
argument|const char_type* __lo
argument_list|,
argument|const char_type* __hi
argument_list|,
argument|char __dfault
argument_list|,
argument|char *__to
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_narrow
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|,
name|__dfault
argument_list|,
name|__to
argument_list|)
return|;
block|}
name|protected
operator|:
name|explicit
name|__ctype_abstract_base
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|virtual
operator|~
name|__ctype_abstract_base
argument_list|()
block|{ }
name|virtual
name|bool
name|do_is
argument_list|(
argument|mask __m
argument_list|,
argument|char_type __c
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// NB: Generic, mostly useless implementation.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype
operator|:
name|public
name|__ctype_abstract_base
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ctype
operator|::
name|mask
name|mask
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|ctype
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|__ctype_abstract_base
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|bool
name|do_is
argument_list|(
name|mask
name|__m
argument_list|,
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|ctype
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.1.3  ctype<char> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|char
operator|>
operator|:
name|public
name|__ctype_abstract_base
operator|<
name|char
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|char
name|char_type
typedef|;
name|protected
operator|:
comment|// Data Members:
name|__c_locale
name|_M_c_locale_ctype
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|_M_del
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__to_type
name|_M_toupper
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__to_type
name|_M_tolower
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|mask
modifier|*
name|_M_table
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|table_size
init|=
literal|1
operator|+
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|explicit
name|ctype
parameter_list|(
specifier|const
name|mask
modifier|*
name|__table
init|=
literal|0
parameter_list|,
name|bool
name|__del
init|=
name|false
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|mask
modifier|*
name|__table
init|=
literal|0
parameter_list|,
name|bool
name|__del
init|=
name|false
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|inline
name|bool
name|is
argument_list|(
name|mask
name|__m
argument_list|,
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|is
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
specifier|const
name|mask
operator|*
name|table
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_table
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|static
specifier|const
name|mask
modifier|*
name|classic_table
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|bool
name|do_is
argument_list|(
name|mask
name|__m
argument_list|,
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
specifier|const
name|ctype
operator|<
name|char
operator|>
operator|&
name|use_facet
operator|<
name|ctype
operator|<
name|char
operator|>
expr|>
operator|(
specifier|const
name|locale
operator|&
name|__loc
operator|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_comment
comment|// 22.2.1.3  ctype<wchar_t> specialization
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|ctype
operator|<
name|wchar_t
operator|>
operator|:
name|public
name|__ctype_abstract_base
operator|<
name|wchar_t
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|wchar_t
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|wctype_t
name|__wmask_type
typedef|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__c_locale
name|_M_c_locale_ctype
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// Data Members:
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|explicit
name|ctype
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__wmask_type
name|_M_convert_to_wmask
argument_list|(
specifier|const
name|mask
name|__m
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
operator|~
name|ctype
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|bool
name|do_is
argument_list|(
name|mask
name|__m
argument_list|,
name|char_type
name|__c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_is
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|mask
operator|*
name|__vec
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_is
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_scan_not
argument_list|(
name|mask
name|__m
argument_list|,
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_toupper
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_toupper
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_tolower
argument_list|(
name|char_type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_tolower
argument_list|(
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char_type
name|do_widen
argument_list|(
name|char
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char
modifier|*
name|do_widen
argument_list|(
specifier|const
name|char
operator|*
name|__lo
argument_list|,
specifier|const
name|char
operator|*
name|__hi
argument_list|,
name|char_type
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|char
name|do_narrow
argument_list|(
name|char_type
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
specifier|const
name|char_type
modifier|*
name|do_narrow
argument_list|(
specifier|const
name|char_type
operator|*
name|__lo
argument_list|,
specifier|const
name|char_type
operator|*
name|__hi
argument_list|,
name|char
name|__dfault
argument_list|,
name|char
operator|*
name|__dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
specifier|const
name|ctype
operator|<
name|wchar_t
operator|>
operator|&
name|use_facet
operator|<
name|ctype
operator|<
name|wchar_t
operator|>
expr|>
operator|(
specifier|const
name|locale
operator|&
name|__loc
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_GLIBCPP_USE_WCHAR_T
end_comment

begin_comment
comment|// Include host and configuration specific ctype inlines.
end_comment

begin_include
include|#
directive|include
file|<bits/ctype_inline.h>
end_include

begin_comment
comment|// 22.2.1.2  Template class ctype_byname
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|ctype_byname
operator|:
name|public
name|ctype
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
name|explicit
name|ctype_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|ctype_byname
argument_list|()
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// 22.2.1.4  Class ctype_byname specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|ctype_byname
operator|<
name|char
operator|>
operator|::
name|ctype_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t refs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|ctype_byname
operator|<
name|wchar_t
operator|>
operator|::
name|ctype_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t refs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.2.1.5  Template class codecvt
end_comment

begin_include
include|#
directive|include
file|<bits/codecvt.h>
end_include

begin_comment
comment|// 22.2.2  The numeric category.
end_comment

begin_decl_stmt
name|class
name|__num_base
block|{
name|public
label|:
comment|// NB: Code depends on the order of _S_atoms_out elements.
comment|// Below are the indices into _S_atoms_out.
enum|enum
block|{
name|_S_minus
block|,
name|_S_plus
block|,
name|_S_x
block|,
name|_S_X
block|,
name|_S_digits
block|,
name|_S_digits_end
init|=
name|_S_digits
operator|+
literal|16
block|,
name|_S_udigits
init|=
name|_S_digits_end
block|,
name|_S_udigits_end
init|=
name|_S_udigits
operator|+
literal|16
block|,
name|_S_e
init|=
name|_S_digits
operator|+
literal|14
block|,
comment|// For scientific notation, 'e'
name|_S_E
init|=
name|_S_udigits
operator|+
literal|14
block|,
comment|// For scientific notation, 'E'
name|_S_end
init|=
name|_S_udigits_end
block|}
enum|;
comment|// A list of valid numeric literals for output.  This array
comment|// contains chars that will be passed through the current locale's
comment|// ctype<_CharT>.widen() and then used to render numbers.
comment|// For the standard "C" locale, this is
comment|// "-+xX0123456789abcdef0123456789ABCDEF".
specifier|static
specifier|const
name|char
modifier|*
name|_S_atoms_out
decl_stmt|;
name|protected
label|:
comment|// String literal of acceptable (narrow) input, for num_get.
comment|// "0123456789eEabcdfABCDF"
specifier|static
specifier|const
name|char
modifier|*
name|_S_atoms_in
decl_stmt|;
enum|enum
block|{
name|_M_zero
block|,
name|_M_e
init|=
name|_M_zero
operator|+
literal|10
block|,
name|_M_E
init|=
name|_M_zero
operator|+
literal|11
block|,
name|_M_size
init|=
literal|21
operator|+
literal|1
block|}
enum|;
comment|// num_put
comment|// Construct and return valid scanf format for floating point types.
specifier|static
name|void
name|_S_format_float
parameter_list|(
specifier|const
name|ios_base
modifier|&
name|__io
parameter_list|,
name|char
modifier|*
name|__fptr
parameter_list|,
name|char
name|__mod
parameter_list|,
name|streamsize
name|__prec
parameter_list|)
function_decl|;
comment|// Construct and return valid scanf format for integer types.
specifier|static
name|void
name|_S_format_int
parameter_list|(
specifier|const
name|ios_base
modifier|&
name|__io
parameter_list|,
name|char
modifier|*
name|__fptr
parameter_list|,
name|char
name|__mod
parameter_list|,
name|char
name|__modl
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__locale_cache
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|numpunct
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|friend
name|class
name|__locale_cache
operator|<
name|numpunct
operator|<
name|_CharT
operator|>
expr|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|char_type
name|_M_decimal_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char_type
name|_M_thousands_sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_M_grouping
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|_M_truename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|_M_falsename
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|numpunct
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_initialize_numpunct
argument_list|()
block|; }
name|explicit
name|numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_initialize_numpunct
argument_list|(
name|__cloc
argument_list|)
block|; }
name|char_type
name|decimal_point
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_decimal_point
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|char_type
name|thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_thousands_sep
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string
name|grouping
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_grouping
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string_type
name|truename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_truename
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string_type
name|falsename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_falsename
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|char_type
name|do_decimal_point
argument_list|()
specifier|const
block|{
return|return
name|_M_decimal_point
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|char_type
name|do_thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|_M_thousands_sep
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string
name|do_grouping
argument_list|()
specifier|const
block|{
return|return
name|_M_grouping
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string_type
name|do_truename
argument_list|()
specifier|const
block|{
return|return
name|_M_truename
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string_type
name|do_falsename
argument_list|()
specifier|const
block|{
return|return
name|_M_falsename
return|;
block|}
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_numpunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|numpunct
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|numpunct
operator|<
name|char
operator|>
operator|::
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|numpunct
operator|<
name|char
operator|>
operator|::
name|_M_initialize_numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|numpunct
operator|<
name|wchar_t
operator|>
operator|::
operator|~
name|numpunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|numpunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_initialize_numpunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
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
name|numpunct_byname
operator|:
name|public
name|numpunct
operator|<
name|_CharT
operator|>
block|{
comment|// Data Member.
name|__c_locale
name|_M_c_locale_numpunct
block|;
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|numpunct_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|numpunct
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{
name|_S_create_c_locale
argument_list|(
name|_M_c_locale_numpunct
argument_list|,
name|__s
argument_list|)
block|;
name|_M_initialize_numpunct
argument_list|(
name|_M_c_locale_numpunct
argument_list|)
block|;	       }
name|protected
operator|:
name|virtual
operator|~
name|numpunct_byname
argument_list|()
block|{
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_numpunct
argument_list|)
block|; }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|class
name|num_get
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|__num_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|num_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|iter_type
name|get
argument_list|(
argument|iter_type __in
argument_list|,
argument|iter_type __end
argument_list|,
argument|ios_base& __io
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|bool& __v
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|short
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|int
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
name|long
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|float
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|double
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__in
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|void
operator|*
operator|&
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__in
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|num_get
argument_list|()
block|{ }
name|iter_type
name|_M_extract_float
argument_list|(
argument|iter_type
argument_list|,
argument|iter_type
argument_list|,
argument|ios_base&
argument_list|,
argument|ios_base::iostate&
argument_list|,
argument|string& __xtrc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iter_type
name|_M_extract_int
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
name|string
operator|&
name|__xtrc
argument_list|,
name|int
operator|&
name|__base
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
name|bool
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
argument_list|,
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|short
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|int
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|unsigned
name|long
name|long
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|float
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|long
name|double
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
argument_list|,
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|void
operator|*
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|num_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// Partial specialization for istreambuf_iterator, so can use traits_type.
end_comment

begin_endif
unit|template<typename _CharT>     class num_get<_CharT, istreambuf_iterator<_CharT>>;        iter_type        _M_extract_float(iter_type, iter_type, ios_base&, ios_base::iostate&,  		       string& __xtrc) const;        iter_type        _M_extract_int(iter_type, iter_type, ios_base&, ios_base::iostate&,  		     string& __xtrc, int& __base) const;        virtual iter_type        do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, bool&) const;
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|num_put
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|__num_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|num_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|iter_type
name|put
argument_list|(
argument|iter_type __s
argument_list|,
argument|ios_base& __f
argument_list|,
argument|char_type __fill
argument_list|,
argument|bool __v
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|long
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|double
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__f
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|void
operator|*
name|__v
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__f
argument_list|,
name|__fill
argument_list|,
name|__v
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_convert_float
argument_list|(
argument|iter_type
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|char __mod
argument_list|,
argument|_ValueT __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|_M_group_float
argument_list|(
specifier|const
name|string
operator|&
name|__grouping
argument_list|,
name|char_type
name|__sep
argument_list|,
specifier|const
name|char_type
operator|*
name|__p
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_convert_int
argument_list|(
argument|iter_type
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|_ValueT __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|_M_group_int
argument_list|(
specifier|const
name|string
operator|&
name|__grouping
argument_list|,
name|char_type
name|__sep
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_M_pad
argument_list|(
name|char_type
name|__fill
argument_list|,
name|streamsize
name|__w
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
operator|*
name|__new
argument_list|,
specifier|const
name|char_type
operator|*
name|__cs
argument_list|,
name|int
operator|&
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated, compatibility only.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ValueT
operator|>
name|iter_type
name|_M_convert_int
argument_list|(
argument|iter_type
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|char __mod
argument_list|,
argument|char __modl
argument_list|,
argument|_ValueT __v
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iter_type
name|_M_widen_float
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
name|char
operator|*
name|__cs
argument_list|,
name|int
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|iter_type
name|_M_widen_int
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
name|char
operator|*
name|__cs
argument_list|,
name|int
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|iter_type
name|_M_insert
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|char_type
operator|*
name|__ws
argument_list|,
name|int
name|__len
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|virtual
operator|~
name|num_put
argument_list|()
block|{ }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|bool
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_LONG_LONG
end_ifdef

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|long
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|unsigned
name|long
name|long
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
name|long
name|double
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
argument_list|,
name|ios_base
operator|&
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|void
operator|*
name|__v
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|num_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|collate
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Underlying "C" library locale information saved from
end_comment

begin_comment
comment|// initialization, needed by collate_byname as well.
end_comment

begin_decl_stmt
name|__c_locale
name|_M_c_locale_collate
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|collate
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_c_locale_collate
operator|=
name|_S_c_locale
block|; }
name|explicit
name|collate
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_c_locale_collate
operator|=
name|_S_clone_c_locale
argument_list|(
name|__cloc
argument_list|)
block|; }
name|int
name|compare
argument_list|(
argument|const _CharT* __lo1
argument_list|,
argument|const _CharT* __hi1
argument_list|,
argument|const _CharT* __lo2
argument_list|,
argument|const _CharT* __hi2
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_compare
argument_list|(
name|__lo1
argument_list|,
name|__hi1
argument_list|,
name|__lo2
argument_list|,
name|__hi2
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|string_type
name|transform
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_transform
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|long
name|hash
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_hash
argument_list|(
name|__lo
argument_list|,
name|__hi
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Used to abstract out _CharT bits in virtual member functions, below.
end_comment

begin_decl_stmt
name|int
name|_M_compare
argument_list|(
specifier|const
name|_CharT
operator|*
argument_list|,
specifier|const
name|_CharT
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|_M_transform
argument_list|(
name|_CharT
operator|*
argument_list|,
specifier|const
name|_CharT
operator|*
argument_list|,
name|size_t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|collate
argument_list|()
block|{
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_collate
argument_list|)
block|; }
name|virtual
name|int
name|do_compare
argument_list|(
argument|const _CharT* __lo1
argument_list|,
argument|const _CharT* __hi1
argument_list|,
argument|const _CharT* __lo2
argument_list|,
argument|const _CharT* __hi2
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|string_type
name|do_transform
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|long
name|do_hash
argument_list|(
specifier|const
name|_CharT
operator|*
name|__lo
argument_list|,
specifier|const
name|_CharT
operator|*
name|__hi
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|collate
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|int
name|collate
operator|<
name|char
operator|>
operator|::
name|_M_compare
argument_list|(
argument|const char*
argument_list|,
argument|const char*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|size_t
name|collate
operator|<
name|char
operator|>
operator|::
name|_M_transform
argument_list|(
argument|char*
argument_list|,
argument|const char*
argument_list|,
argument|size_t
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|int
name|collate
operator|<
name|wchar_t
operator|>
operator|::
name|_M_compare
argument_list|(
argument|const wchar_t*
argument_list|,
argument|const wchar_t*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|size_t
name|collate
operator|<
name|wchar_t
operator|>
operator|::
name|_M_transform
argument_list|(
argument|wchar_t*
argument_list|,
argument|const wchar_t*
argument_list|,
argument|size_t
argument_list|)
specifier|const
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
name|collate_byname
operator|:
name|public
name|collate
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|collate_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|collate
operator|<
name|_CharT
operator|>
operator|(
name|__refs
operator|)
block|{
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_collate
argument_list|)
block|;
name|_S_create_c_locale
argument_list|(
name|_M_c_locale_collate
argument_list|,
name|__s
argument_list|)
block|;        }
name|protected
operator|:
name|virtual
operator|~
name|collate_byname
argument_list|()
block|{ }
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|time_base
block|{
name|public
label|:
enum|enum
name|dateorder
block|{
name|no_order
block|,
name|dmy
block|,
name|mdy
block|,
name|ymd
block|,
name|ydm
block|}
enum|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__timepunct
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|__char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// List of all known timezones, with GMT first.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|_CharT
modifier|*
name|_S_timezones
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|__c_locale
name|_M_c_locale_timepunct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|_M_name_timepunct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_date_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_date_era_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_time_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_time_era_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_date_time_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_date_time_era_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_am
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_pm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_am_pm_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Day names, starting with "C"'s Sunday.
end_comment

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Abbreviated day names, starting with "C"'s Sun.
end_comment

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_day_a7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Month names, starting with "C"'s January.
end_comment

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month01
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month02
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month03
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month04
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month05
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month06
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month07
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month08
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month09
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month11
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month12
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Abbreviated month names, starting with "C"'s Jan.
end_comment

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a01
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a02
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a03
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a04
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a05
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a06
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a07
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a08
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a09
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a11
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_month_a12
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
name|explicit
name|__timepunct
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|explicit
name|__timepunct
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|_M_put
argument_list|(
name|_CharT
operator|*
name|__s
argument_list|,
name|size_t
name|__maxlen
argument_list|,
specifier|const
name|_CharT
operator|*
name|__format
argument_list|,
specifier|const
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_M_date_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__date
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__date
index|[
literal|0
index|]
operator|=
name|_M_date_format
expr_stmt|;
name|__date
index|[
literal|1
index|]
operator|=
name|_M_date_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_time_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__time
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__time
index|[
literal|0
index|]
operator|=
name|_M_time_format
expr_stmt|;
name|__time
index|[
literal|1
index|]
operator|=
name|_M_time_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_ampm
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__ampm
argument_list|)
decl|const
block|{
name|__ampm
index|[
literal|0
index|]
operator|=
name|_M_am
expr_stmt|;
name|__ampm
index|[
literal|1
index|]
operator|=
name|_M_pm
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_date_time_formats
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__dt
argument_list|)
decl|const
block|{
comment|// Always have default first.
name|__dt
index|[
literal|0
index|]
operator|=
name|_M_date_time_format
expr_stmt|;
name|__dt
index|[
literal|1
index|]
operator|=
name|_M_date_time_era_format
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_days
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__days
argument_list|)
decl|const
block|{
name|__days
index|[
literal|0
index|]
operator|=
name|_M_day1
expr_stmt|;
name|__days
index|[
literal|1
index|]
operator|=
name|_M_day2
expr_stmt|;
name|__days
index|[
literal|2
index|]
operator|=
name|_M_day3
expr_stmt|;
name|__days
index|[
literal|3
index|]
operator|=
name|_M_day4
expr_stmt|;
name|__days
index|[
literal|4
index|]
operator|=
name|_M_day5
expr_stmt|;
name|__days
index|[
literal|5
index|]
operator|=
name|_M_day6
expr_stmt|;
name|__days
index|[
literal|6
index|]
operator|=
name|_M_day7
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_days_abbreviated
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__days
argument_list|)
decl|const
block|{
name|__days
index|[
literal|0
index|]
operator|=
name|_M_day_a1
expr_stmt|;
name|__days
index|[
literal|1
index|]
operator|=
name|_M_day_a2
expr_stmt|;
name|__days
index|[
literal|2
index|]
operator|=
name|_M_day_a3
expr_stmt|;
name|__days
index|[
literal|3
index|]
operator|=
name|_M_day_a4
expr_stmt|;
name|__days
index|[
literal|4
index|]
operator|=
name|_M_day_a5
expr_stmt|;
name|__days
index|[
literal|5
index|]
operator|=
name|_M_day_a6
expr_stmt|;
name|__days
index|[
literal|6
index|]
operator|=
name|_M_day_a7
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_months
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__months
argument_list|)
decl|const
block|{
name|__months
index|[
literal|0
index|]
operator|=
name|_M_month01
expr_stmt|;
name|__months
index|[
literal|1
index|]
operator|=
name|_M_month02
expr_stmt|;
name|__months
index|[
literal|2
index|]
operator|=
name|_M_month03
expr_stmt|;
name|__months
index|[
literal|3
index|]
operator|=
name|_M_month04
expr_stmt|;
name|__months
index|[
literal|4
index|]
operator|=
name|_M_month05
expr_stmt|;
name|__months
index|[
literal|5
index|]
operator|=
name|_M_month06
expr_stmt|;
name|__months
index|[
literal|6
index|]
operator|=
name|_M_month07
expr_stmt|;
name|__months
index|[
literal|7
index|]
operator|=
name|_M_month08
expr_stmt|;
name|__months
index|[
literal|8
index|]
operator|=
name|_M_month09
expr_stmt|;
name|__months
index|[
literal|9
index|]
operator|=
name|_M_month10
expr_stmt|;
name|__months
index|[
literal|10
index|]
operator|=
name|_M_month11
expr_stmt|;
name|__months
index|[
literal|11
index|]
operator|=
name|_M_month12
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|_M_months_abbreviated
argument_list|(
specifier|const
name|_CharT
operator|*
operator|*
name|__months
argument_list|)
decl|const
block|{
name|__months
index|[
literal|0
index|]
operator|=
name|_M_month_a01
expr_stmt|;
name|__months
index|[
literal|1
index|]
operator|=
name|_M_month_a02
expr_stmt|;
name|__months
index|[
literal|2
index|]
operator|=
name|_M_month_a03
expr_stmt|;
name|__months
index|[
literal|3
index|]
operator|=
name|_M_month_a04
expr_stmt|;
name|__months
index|[
literal|4
index|]
operator|=
name|_M_month_a05
expr_stmt|;
name|__months
index|[
literal|5
index|]
operator|=
name|_M_month_a06
expr_stmt|;
name|__months
index|[
literal|6
index|]
operator|=
name|_M_month_a07
expr_stmt|;
name|__months
index|[
literal|7
index|]
operator|=
name|_M_month_a08
expr_stmt|;
name|__months
index|[
literal|8
index|]
operator|=
name|_M_month_a09
expr_stmt|;
name|__months
index|[
literal|9
index|]
operator|=
name|_M_month_a10
expr_stmt|;
name|__months
index|[
literal|10
index|]
operator|=
name|_M_month_a11
expr_stmt|;
name|__months
index|[
literal|11
index|]
operator|=
name|_M_month_a12
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|__timepunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_timepunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
specifier|const
name|char
operator|*
name|__timepunct
operator|<
name|char
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|char
operator|>
operator|::
name|_M_initialize_timepunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|char
operator|>
operator|::
name|_M_put
argument_list|(
argument|char*
argument_list|,
argument|size_t
argument_list|,
argument|const char*
argument_list|,
argument|const tm*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
specifier|const
name|wchar_t
operator|*
name|__timepunct
operator|<
name|wchar_t
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_initialize_timepunct
argument_list|(
argument|__c_locale __cloc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|__timepunct
operator|<
name|wchar_t
operator|>
operator|::
name|_M_put
argument_list|(
argument|wchar_t*
argument_list|,
argument|size_t
argument_list|,
argument|const wchar_t*
argument_list|,
argument|const tm*
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Generic.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|const
name|_CharT
operator|*
name|__timepunct
operator|<
name|_CharT
operator|>
operator|::
name|_S_timezones
index|[
literal|14
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Include host and configuration specific timepunct functions.
end_comment

begin_include
include|#
directive|include
file|<bits/time_members.h>
end_include

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|class
name|time_get
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|time_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|__string_type
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|time_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|dateorder
name|date_order
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_date_order
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|iter_type
name|get_time
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_time
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get_date
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_date
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get_weekday
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_weekday
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get_monthname
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_monthname
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|iter_type
name|get_year
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get_year
argument_list|(
name|__beg
argument_list|,
name|__end
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__tm
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|time_get
argument_list|()
block|{ }
name|virtual
name|dateorder
name|do_date_order
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get_time
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get_date
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get_weekday
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get_monthname
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get_year
argument_list|(
name|iter_type
name|__beg
argument_list|,
name|iter_type
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Extract numeric component of length __len.
end_comment

begin_decl_stmt
name|void
name|_M_extract_num
argument_list|(
name|iter_type
operator|&
name|__beg
argument_list|,
name|iter_type
operator|&
name|__end
argument_list|,
name|int
operator|&
name|__member
argument_list|,
name|int
name|__min
argument_list|,
name|int
name|__max
argument_list|,
name|size_t
name|__len
argument_list|,
specifier|const
name|ctype
operator|<
name|_CharT
operator|>
operator|&
name|__ctype
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Extract day or month name, or any unique array of string
end_comment

begin_comment
comment|// literals in a const _CharT* array.
end_comment

begin_decl_stmt
name|void
name|_M_extract_name
argument_list|(
name|iter_type
operator|&
name|__beg
argument_list|,
name|iter_type
operator|&
name|__end
argument_list|,
name|int
operator|&
name|__member
argument_list|,
specifier|const
name|_CharT
operator|*
operator|*
name|__names
argument_list|,
name|size_t
name|__indexlen
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Extract on a component-by-component basis, via __format argument.
end_comment

begin_decl_stmt
name|void
name|_M_extract_via_format
argument_list|(
name|iter_type
operator|&
name|__beg
argument_list|,
name|iter_type
operator|&
name|__end
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|tm
operator|*
name|__tm
argument_list|,
specifier|const
name|_CharT
operator|*
name|__format
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
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
operator|>
name|class
name|time_get_byname
operator|:
name|public
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|time_get_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|time_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|time_get_byname
argument_list|()
block|{ }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|class
name|time_put
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|time_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|time_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|iter_type
name|put
argument_list|(
argument|iter_type __s
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|const tm* __tm
argument_list|,
argument|const _CharT* __beg
argument_list|,
argument|const _CharT* __end
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|tm
operator|*
name|__tm
argument_list|,
name|char
name|__format
argument_list|,
name|char
name|__mod
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__tm
argument_list|,
name|__format
argument_list|,
name|__mod
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|time_put
argument_list|()
block|{ }
name|virtual
name|iter_type
name|do_put
argument_list|(
argument|iter_type __s
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|const tm* __tm
argument_list|,
argument|char __format
argument_list|,
argument|char __mod
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
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
operator|>
name|class
name|time_put_byname
operator|:
name|public
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_macro
name|explicit
end_macro

begin_macro
name|time_put_byname
argument_list|(
argument|const char*
comment|/*__s*/
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|time_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|(
name|__refs
operator|)
block|{ }
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|time_put_byname
argument_list|()
block|{ }
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|money_base
block|{
name|public
label|:
enum|enum
name|part
block|{
name|none
block|,
name|space
block|,
name|symbol
block|,
name|sign
block|,
name|value
block|}
enum|;
struct|struct
name|pattern
block|{
name|char
name|field
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
specifier|static
specifier|const
name|pattern
name|_S_default_pattern
decl_stmt|;
comment|// Construct and return valid pattern consisting of some combination of:
comment|// space none symbol sign value
specifier|static
name|pattern
name|_S_construct_pattern
parameter_list|(
name|char
name|__precedes
parameter_list|,
name|char
name|__space
parameter_list|,
name|char
name|__posn
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|class
name|moneypunct
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|money_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|intl
init|=
name|_Intl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_M_grouping
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char_type
name|_M_decimal_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char_type
name|_M_thousands_sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|_M_curr_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|_M_positive_sign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char_type
modifier|*
name|_M_negative_sign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_M_frac_digits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pattern
name|_M_pos_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pattern
name|_M_neg_format
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|moneypunct
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_initialize_moneypunct
argument_list|()
block|; }
name|explicit
name|moneypunct
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{
name|_M_initialize_moneypunct
argument_list|(
name|__cloc
argument_list|,
name|__s
argument_list|)
block|; }
name|char_type
name|decimal_point
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_decimal_point
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|char_type
name|thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_thousands_sep
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string
name|grouping
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_grouping
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string_type
name|curr_symbol
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_curr_symbol
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string_type
name|positive_sign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_positive_sign
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|string_type
name|negative_sign
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_negative_sign
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|int
name|frac_digits
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_frac_digits
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pattern
name|pos_format
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_pos_format
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pattern
name|neg_format
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|do_neg_format
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|char_type
name|do_decimal_point
argument_list|()
specifier|const
block|{
return|return
name|_M_decimal_point
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|char_type
name|do_thousands_sep
argument_list|()
specifier|const
block|{
return|return
name|_M_thousands_sep
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string
name|do_grouping
argument_list|()
specifier|const
block|{
return|return
name|_M_grouping
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string_type
name|do_curr_symbol
argument_list|()
specifier|const
block|{
return|return
name|_M_curr_symbol
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string_type
name|do_positive_sign
argument_list|()
specifier|const
block|{
return|return
name|_M_positive_sign
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|string_type
name|do_negative_sign
argument_list|()
specifier|const
block|{
return|return
name|_M_negative_sign
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|int
name|do_frac_digits
argument_list|()
specifier|const
block|{
return|return
name|_M_frac_digits
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|pattern
name|do_pos_format
argument_list|()
specifier|const
block|{
return|return
name|_M_pos_format
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|pattern
name|do_neg_format
argument_list|()
specifier|const
block|{
return|return
name|_M_neg_format
return|;
block|}
end_expr_stmt

begin_comment
comment|// For use at construction time only.
end_comment

begin_function_decl
name|void
name|_M_initialize_moneypunct
parameter_list|(
name|__c_locale
name|__cloc
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|__name
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
name|locale
operator|::
name|id
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|id
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
operator|>
specifier|const
name|bool
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|intl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|char
operator|,
name|true
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|char
operator|,
name|false
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|char
operator|,
name|true
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|char
operator|,
name|false
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|wchar_t
operator|,
name|true
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|moneypunct
operator|<
name|wchar_t
operator|,
name|false
operator|>
operator|::
operator|~
name|moneypunct
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|wchar_t
operator|,
name|true
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|void
name|moneypunct
operator|<
name|wchar_t
operator|,
name|false
operator|>
operator|::
name|_M_initialize_moneypunct
argument_list|(
name|__c_locale
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
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
operator|,
name|bool
name|_Intl
operator|>
name|class
name|moneypunct_byname
operator|:
name|public
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
block|{
name|__c_locale
name|_M_c_locale_moneypunct
block|;
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|intl
init|=
name|_Intl
decl_stmt|;
end_decl_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|moneypunct_byname
argument_list|(
argument|const char* __s
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|moneypunct
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|(
name|__refs
operator|)
block|{
name|_S_create_c_locale
argument_list|(
name|_M_c_locale_moneypunct
argument_list|,
name|__s
argument_list|)
block|;
name|_M_initialize_moneypunct
argument_list|(
name|_M_c_locale_moneypunct
argument_list|)
block|;	       }
name|protected
operator|:
name|virtual
operator|~
name|moneypunct_byname
argument_list|()
block|{
name|_S_destroy_c_locale
argument_list|(
name|_M_c_locale_moneypunct
argument_list|)
block|; }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|bool
name|_Intl
operator|>
specifier|const
name|bool
name|moneypunct_byname
operator|<
name|_CharT
operator|,
name|_Intl
operator|>
operator|::
name|intl
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
operator|>
name|class
name|money_get
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InIter
name|iter_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|money_get
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|iter_type
name|get
argument_list|(
argument|iter_type __s
argument_list|,
argument|iter_type __end
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|long double& __units
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__s
argument_list|,
name|__end
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__units
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|iter_type
name|get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__s
argument_list|,
name|__end
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__err
argument_list|,
name|__digits
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|money_get
argument_list|()
block|{ }
name|virtual
name|iter_type
name|do_get
argument_list|(
argument|iter_type __s
argument_list|,
argument|iter_type __end
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|ios_base::iostate& __err
argument_list|,
argument|long double& __units
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_get
argument_list|(
name|iter_type
name|__s
argument_list|,
name|iter_type
name|__end
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|ios_base
operator|::
name|iostate
operator|&
name|__err
argument_list|,
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_InIter
operator|>
name|locale
operator|::
name|id
name|money_get
operator|<
name|_CharT
operator|,
name|_InIter
operator|>
operator|::
name|id
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
operator|>
name|class
name|money_put
operator|:
name|public
name|locale
operator|::
name|facet
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_OutIter
name|iter_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|money_put
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|locale
operator|::
name|facet
argument_list|(
argument|__refs
argument_list|)
block|{ }
name|iter_type
name|put
argument_list|(
argument|iter_type __s
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|long double __units
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__units
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|iter_type
name|put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_put
argument_list|(
name|__s
argument_list|,
name|__intl
argument_list|,
name|__io
argument_list|,
name|__fill
argument_list|,
name|__digits
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|money_put
argument_list|()
block|{ }
name|virtual
name|iter_type
name|do_put
argument_list|(
argument|iter_type __s
argument_list|,
argument|bool __intl
argument_list|,
argument|ios_base& __io
argument_list|,
argument|char_type __fill
argument_list|,
argument|long double __units
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|iter_type
name|do_put
argument_list|(
name|iter_type
name|__s
argument_list|,
name|bool
name|__intl
argument_list|,
name|ios_base
operator|&
name|__io
argument_list|,
name|char_type
name|__fill
argument_list|,
specifier|const
name|string_type
operator|&
name|__digits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_OutIter
operator|>
name|locale
operator|::
name|id
name|money_put
operator|<
name|_CharT
operator|,
name|_OutIter
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|messages_base
block|{
typedef|typedef
name|int
name|catalog
typedef|;
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|messages
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|messages_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Underlying "C" library locale information saved from
end_comment

begin_comment
comment|// initialization, needed by messages_byname as well.
end_comment

begin_decl_stmt
name|__c_locale
name|_M_c_locale_messages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|_M_name_messages
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_function_decl
name|explicit
name|messages
parameter_list|(
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Non-standard.
end_comment

begin_function_decl
name|explicit
name|messages
parameter_list|(
name|__c_locale
name|__cloc
parameter_list|,
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|catalog
name|open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
name|__s
argument_list|,
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_open
argument_list|(
name|__s
argument_list|,
name|__loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Non-standard and unorthodox, yet effective.
end_comment

begin_decl_stmt
name|catalog
name|open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
argument_list|,
specifier|const
name|locale
operator|&
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|string_type
name|get
argument_list|(
name|catalog
name|__c
argument_list|,
name|int
name|__set
argument_list|,
name|int
name|__msgid
argument_list|,
specifier|const
name|string_type
operator|&
name|__s
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_get
argument_list|(
name|__c
argument_list|,
name|__set
argument_list|,
name|__msgid
argument_list|,
name|__s
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|close
argument_list|(
name|catalog
name|__c
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_close
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|messages
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|catalog
name|do_open
argument_list|(
specifier|const
name|basic_string
operator|<
name|char
operator|>
operator|&
argument_list|,
specifier|const
name|locale
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|string_type
name|do_get
argument_list|(
name|catalog
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
specifier|const
name|string_type
operator|&
name|__dfault
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|do_close
argument_list|(
name|catalog
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns a locale and codeset-converted string, given a char* message.
end_comment

begin_decl_stmt
name|char
modifier|*
name|_M_convert_to_char
argument_list|(
specifier|const
name|string_type
operator|&
name|__msg
argument_list|)
decl|const
block|{
comment|// XXX
return|return
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|_CharT
operator|*
operator|>
operator|(
name|__msg
operator|.
name|c_str
argument_list|()
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns a locale and codeset-converted string, given a char* message.
end_comment

begin_decl_stmt
name|string_type
name|_M_convert_from_char
argument_list|(
name|char
operator|*
name|__msg
argument_list|)
decl|const
block|{
comment|// Length of message string without terminating null.
name|size_t
name|__len
init|=
name|char_traits
operator|<
name|char
operator|>
operator|::
name|length
argument_list|(
name|__msg
argument_list|)
operator|-
literal|1
decl_stmt|;
comment|// "everybody can easily convert the string using
comment|// mbsrtowcs/wcsrtombs or with iconv()"
if|#
directive|if
literal|0
comment|// Convert char* to _CharT in locale used to open catalog.
comment|// XXX need additional template parameter on messages class for this..
comment|// typedef typename codecvt<char, _CharT, _StateT> __codecvt_type;
block|typedef typename codecvt<char, _CharT, mbstate_t> __codecvt_type;        	__codecvt_type::state_type __state;
comment|// XXX may need to initialize state.
comment|//initialize_state(__state._M_init());
block|char* __from_next;
comment|// XXX what size for this string?
block|_CharT* __to = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 	const __codecvt_type& __cvt = use_facet<__codecvt_type>(_M_locale_conv); 	__cvt.out(__state, __msg, __msg + __len, __from_next, 		  __to, __to + __len + 1, __to_next); 	return string_type(__to);
endif|#
directive|endif
if|#
directive|if
literal|0
block|typedef ctype<_CharT> __ctype_type;
comment|// const __ctype_type& __cvt = use_facet<__ctype_type>(_M_locale_msg);
block|const __ctype_type& __cvt = use_facet<__ctype_type>(locale());
comment|// XXX Again, proper length of converted string an issue here.
comment|// For now, assume the converted length is not larger.
block|_CharT* __dest = static_cast<_CharT*>(__builtin_alloca(__len + 1)); 	__cvt.widen(__msg, __msg + __len, __dest); 	return basic_string<_CharT>(__dest);
endif|#
directive|endif
return|return
name|string_type
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_CharT
operator|>
name|locale
operator|::
name|id
name|messages
operator|<
name|_CharT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specializations for required instantiations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|string
name|messages
operator|<
name|char
operator|>
operator|::
name|do_get
argument_list|(
argument|catalog
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|const string&
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_expr_stmt
name|template
operator|<
operator|>
name|wstring
name|messages
operator|<
name|wchar_t
operator|>
operator|::
name|do_get
argument_list|(
argument|catalog
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|const wstring&
argument_list|)
specifier|const
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
name|messages_byname
operator|:
name|public
name|messages
operator|<
name|_CharT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_function_decl
name|explicit
name|messages_byname
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|size_t
name|__refs
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|messages_byname
argument_list|()
block|{ }
end_expr_stmt

begin_comment
unit|};
comment|// Include host and configuration specific messages functions.
end_comment

begin_include
include|#
directive|include
file|<bits/messages_members.h>
end_include

begin_comment
comment|// Subclause convenience interfaces, inlines.
end_comment

begin_comment
comment|// NB: These are inline because, when used in a loop, some compilers
end_comment

begin_comment
comment|// can hoist the body out of the loop; then it's just as fast as the
end_comment

begin_comment
comment|// C is*() function.
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|space
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|print
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|cntrl
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|upper
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|lower
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|alpha
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|digit
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|punct
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|xdigit
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|alnum
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|is
argument_list|(
name|ctype_base
operator|::
name|graph
argument_list|,
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|toupper
argument_list|(
name|__c
argument_list|)
return|;
block|}
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
argument|_CharT __c
argument_list|,
argument|const locale& __loc
argument_list|)
block|{
return|return
name|use_facet
operator|<
name|ctype
operator|<
name|_CharT
operator|>
expr|>
operator|(
name|__loc
operator|)
operator|.
name|tolower
argument_list|(
name|__c
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    * @if maint    * __locale_cache objects hold information extracted from facets in    * a form optimized for parsing and formatting.  They are stored in    * a locale's facet array and accessed via __use_cache<_Facet>.    *    * The intent twofold: to avoid the costs of creating a locale    * object and to avoid calling the virtual functions in a locale's    * facet to look up data.    * @endif    */
end_comment

begin_decl_stmt
name|class
name|__locale_cache_base
block|{
name|friend
name|class
name|std
operator|::
name|locale
operator|::
name|_Impl
expr_stmt|;
name|friend
name|class
name|locale
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|__locale_cache_base
argument_list|()
block|{ }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This template doesn't really get used for anything except a
end_comment

begin_comment
comment|// placeholder for specializations
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Facet
operator|>
name|class
name|__locale_cache
operator|:
name|public
name|__locale_cache_base
block|{
comment|// ctor
name|__locale_cache
argument_list|(
argument|const locale&
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|class
name|__locale_cache
operator|<
name|numpunct
operator|<
name|_CharT
operator|>
expr|>
operator|:
name|public
name|__locale_cache_base
block|{
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|char_traits
operator|<
name|_CharT
operator|>
name|traits_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|basic_string
operator|<
name|_CharT
operator|>
name|string_type
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_comment
comment|// Data Members:
end_comment

begin_comment
comment|// The sign used to separate decimal values: for standard US
end_comment

begin_comment
comment|// locales, this would usually be: "."  Abstracted from
end_comment

begin_comment
comment|// numpunct::decimal_point().
end_comment

begin_decl_stmt
name|_CharT
name|_M_decimal_point
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The sign used to separate groups of digits into smaller
end_comment

begin_comment
comment|// strings that the eye can parse with less difficulty: for
end_comment

begin_comment
comment|// standard US locales, this would usually be: "," Abstracted
end_comment

begin_comment
comment|// from numpunct::thousands_sep().
end_comment

begin_decl_stmt
name|_CharT
name|_M_thousands_sep
decl_stmt|;
end_decl_stmt

begin_comment
comment|// However the US's "false" and "true" are translated.  From
end_comment

begin_comment
comment|// numpunct::truename() and numpunct::falsename(), respectively.
end_comment

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_truename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|_CharT
modifier|*
name|_M_falsename
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If we are checking groupings. This should be equivalent to
end_comment

begin_comment
comment|// numpunct::groupings().size() != 0
end_comment

begin_decl_stmt
name|bool
name|_M_use_grouping
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If we are using numpunct's groupings, this is the current
end_comment

begin_comment
comment|// grouping string in effect (from numpunct::grouping()).
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|_M_grouping
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A list of valid numeric literals: for the standard "C"
end_comment

begin_comment
comment|// locale, this is "-+xX0123456789abcdef0123456789ABCDEF".  This
end_comment

begin_comment
comment|// array contains the chars after having been passed through the
end_comment

begin_comment
comment|// current locale's ctype<_CharT>.widen().
end_comment

begin_comment
comment|// Copied here from __locale_cache<ctype> to save multiple cache
end_comment

begin_comment
comment|// access in num_put functions.
end_comment

begin_decl_stmt
name|_CharT
name|_M_atoms_out
index|[
name|__num_base
operator|::
name|_S_end
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ctor
end_comment

begin_expr_stmt
name|__locale_cache
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__locale_cache
argument_list|(
specifier|const
name|locale
operator|&
name|__loc
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|__locale_cache
argument_list|()
block|{
name|delete
index|[]
name|_M_truename
block|;
name|delete
index|[]
name|_M_falsename
block|;
name|delete
index|[]
name|_M_grouping
block|;       }
end_expr_stmt

begin_comment
unit|}; }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

