begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Iostreams base classes -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
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
comment|/** @file basic_ios.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_BASICIOS_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_BASICIOS_H
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
file|<bits/streambuf_iterator.h>
end_include

begin_include
include|#
directive|include
file|<bits/locale_facets.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// 27.4.5  Template class basic_ios
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Traits
operator|>
name|class
name|basic_ios
operator|:
name|public
name|ios_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|_CharT
name|char_type
typedef|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|int_type
name|int_type
expr_stmt|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|pos_type
name|pos_type
expr_stmt|;
typedef|typedef
name|typename
name|_Traits
operator|::
name|off_type
name|off_type
expr_stmt|;
typedef|typedef
name|_Traits
name|traits_type
typedef|;
comment|// Non-standard Types:
typedef|typedef
name|ctype
operator|<
name|_CharT
operator|>
name|__ctype_type
expr_stmt|;
typedef|typedef
name|ostreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__ostreambuf_iter
expr_stmt|;
typedef|typedef
name|num_put
operator|<
name|_CharT
operator|,
name|__ostreambuf_iter
operator|>
name|__numput_type
expr_stmt|;
typedef|typedef
name|istreambuf_iterator
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
name|__istreambuf_iter
expr_stmt|;
typedef|typedef
name|num_get
operator|<
name|_CharT
operator|,
name|__istreambuf_iter
operator|>
name|__numget_type
expr_stmt|;
comment|// Data members:
name|protected
label|:
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|_M_tie
expr_stmt|;
name|mutable
name|char_type
name|_M_fill
decl_stmt|;
name|mutable
name|bool
name|_M_fill_init
decl_stmt|;
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|_M_streambuf
expr_stmt|;
comment|// Cached use_facet<ctype>, which is based on the current locale info.
specifier|const
name|__ctype_type
modifier|*
name|_M_fctype
decl_stmt|;
comment|// From ostream.
specifier|const
name|__numput_type
modifier|*
name|_M_fnumput
decl_stmt|;
comment|// From istream.
specifier|const
name|__numget_type
modifier|*
name|_M_fnumget
decl_stmt|;
name|public
label|:
name|operator
name|void
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|fail
argument_list|()
operator|?
literal|0
operator|:
name|const_cast
operator|<
name|basic_ios
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|fail
argument_list|()
return|;
block|}
name|iostate
name|rdstate
argument_list|()
specifier|const
block|{
return|return
name|_M_streambuf_state
return|;
block|}
name|void
name|clear
parameter_list|(
name|iostate
name|__state
init|=
name|goodbit
parameter_list|)
function_decl|;
name|void
name|setstate
parameter_list|(
name|iostate
name|__state
parameter_list|)
block|{
name|this
operator|->
name|clear
argument_list|(
name|this
operator|->
name|rdstate
argument_list|()
operator||
name|__state
argument_list|)
expr_stmt|;
block|}
name|bool
name|good
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|rdstate
argument_list|()
operator|==
literal|0
return|;
block|}
name|bool
name|eof
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
name|eofbit
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|fail
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
operator|(
name|badbit
operator||
name|failbit
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|bad
argument_list|()
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|rdstate
argument_list|()
operator|&
name|badbit
operator|)
operator|!=
literal|0
return|;
block|}
name|iostate
name|exceptions
argument_list|()
specifier|const
block|{
return|return
name|_M_exception
return|;
block|}
name|void
name|exceptions
parameter_list|(
name|iostate
name|__except
parameter_list|)
block|{
name|_M_exception
operator|=
name|__except
expr_stmt|;
name|this
operator|->
name|clear
argument_list|(
name|_M_streambuf_state
argument_list|)
expr_stmt|;
block|}
comment|// Constructor/destructor:
name|explicit
name|basic_ios
argument_list|(
name|basic_streambuf
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|*
name|__sb
argument_list|)
range|:
name|ios_base
argument_list|()
block|{
name|this
operator|->
name|init
argument_list|(
name|__sb
argument_list|)
block|; }
name|virtual
operator|~
name|basic_ios
argument_list|()
block|{ }
comment|// Members:
name|basic_ostream
operator|<
name|_CharT
decl_stmt|,
name|_Traits
decl|>
modifier|*
name|tie
argument_list|()
decl|const
block|{
return|return
name|_M_tie
return|;
block|}
name|basic_ostream
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|tie
argument_list|(
argument|basic_ostream<_CharT
argument_list|,
argument|_Traits>* __tiestr
argument_list|)
block|{
name|basic_ostream
operator|<
name|_CharT
block|,
name|_Traits
operator|>
operator|*
name|__old
operator|=
name|_M_tie
block|;
name|_M_tie
operator|=
name|__tiestr
block|;
return|return
name|__old
return|;
block|}
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|_M_streambuf
return|;
block|}
name|basic_streambuf
operator|<
name|_CharT
operator|,
name|_Traits
operator|>
operator|*
name|rdbuf
argument_list|(
name|basic_streambuf
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|*
name|__sb
argument_list|)
expr_stmt|;
name|basic_ios
modifier|&
name|copyfmt
parameter_list|(
specifier|const
name|basic_ios
modifier|&
name|__rhs
parameter_list|)
function_decl|;
name|char_type
name|fill
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|_M_fill_init
condition|)
block|{
name|_M_fill
operator|=
name|this
operator|->
name|widen
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|_M_fill_init
operator|=
name|true
expr_stmt|;
block|}
return|return
name|_M_fill
return|;
block|}
name|char_type
name|fill
parameter_list|(
name|char_type
name|__ch
parameter_list|)
block|{
name|char_type
name|__old
init|=
name|this
operator|->
name|fill
argument_list|()
decl_stmt|;
name|_M_fill
operator|=
name|__ch
expr_stmt|;
return|return
name|__old
return|;
block|}
comment|// Locales:
name|locale
name|imbue
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
name|char
name|narrow
argument_list|(
name|char_type
name|__c
argument_list|,
name|char
name|__dfault
argument_list|)
decl|const
decl_stmt|;
name|char_type
name|widen
argument_list|(
name|char
name|__c
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|// 27.4.5.1  basic_ios constructors
name|basic_ios
argument_list|()
operator|:
name|ios_base
argument_list|()
block|{ }
name|void
name|init
argument_list|(
name|basic_streambuf
operator|<
name|_CharT
argument_list|,
name|_Traits
operator|>
operator|*
name|__sb
argument_list|)
expr_stmt|;
name|bool
name|_M_check_facet
argument_list|(
specifier|const
name|locale
operator|::
name|facet
operator|*
name|__f
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|__f
condition|)
name|__throw_bad_cast
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|void
name|_M_cache_facets
parameter_list|(
specifier|const
name|locale
modifier|&
name|__loc
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_NO_TEMPLATE_EXPORT
end_ifdef

begin_define
define|#
directive|define
name|export
end_define

begin_include
include|#
directive|include
file|<bits/basic_ios.tcc>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPP_BITS_BASICIOS_H */
end_comment

end_unit

