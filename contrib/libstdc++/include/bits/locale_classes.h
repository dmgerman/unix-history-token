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
comment|/** @file localefwd.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_LOCALE_CLASSES_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_LOCALE_CLASSES_H
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
file|<bits/localefwd.h>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_comment
comment|// For strcmp.
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<bits/atomicity.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|class
name|__locale_cache_base
decl_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|class
name|__locale_cache
expr_stmt|;
comment|// 22.1.1 Class locale
name|class
name|locale
block|{
name|public
label|:
comment|// Types:
typedef|typedef
name|unsigned
name|int
name|category
typedef|;
comment|// Forward decls and friends:
name|class
name|facet
decl_stmt|;
name|class
name|id
decl_stmt|;
name|class
name|_Impl
decl_stmt|;
name|friend
name|class
name|facet
decl_stmt|;
name|friend
name|class
name|_Impl
decl_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
specifier|const
name|_Facet
operator|&
name|use_facet
argument_list|(
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
name|bool
name|has_facet
argument_list|(
argument|const locale&
argument_list|)
name|throw
argument_list|()
expr_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
specifier|const
name|__locale_cache
operator|<
name|_Facet
operator|>
operator|&
name|__use_cache
argument_list|(
specifier|const
name|locale
operator|&
argument_list|)
expr_stmt|;
comment|// Category values:
comment|// NB: Order must match _S_facet_categories definition in locale.cc
specifier|static
specifier|const
name|category
name|none
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|category
name|ctype
init|=
literal|1L
operator|<<
literal|0
decl_stmt|;
specifier|static
specifier|const
name|category
name|numeric
init|=
literal|1L
operator|<<
literal|1
decl_stmt|;
specifier|static
specifier|const
name|category
name|collate
init|=
literal|1L
operator|<<
literal|2
decl_stmt|;
specifier|static
specifier|const
name|category
name|time
init|=
literal|1L
operator|<<
literal|3
decl_stmt|;
specifier|static
specifier|const
name|category
name|monetary
init|=
literal|1L
operator|<<
literal|4
decl_stmt|;
specifier|static
specifier|const
name|category
name|messages
init|=
literal|1L
operator|<<
literal|5
decl_stmt|;
specifier|static
specifier|const
name|category
name|all
init|=
operator|(
name|ctype
operator||
name|numeric
operator||
name|collate
operator||
name|time
operator||
name|monetary
operator||
name|messages
operator|)
decl_stmt|;
comment|// Construct/copy/destroy:
name|locale
argument_list|()
name|throw
argument_list|()
expr_stmt|;
name|locale
argument_list|(
argument|const locale& __other
argument_list|)
name|throw
argument_list|()
expr_stmt|;
name|explicit
name|locale
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
name|locale
argument_list|(
argument|const locale& __base
argument_list|,
argument|const char* __s
argument_list|,
argument|category __cat
argument_list|)
empty_stmt|;
name|locale
argument_list|(
argument|const locale& __base
argument_list|,
argument|const locale& __add
argument_list|,
argument|category __cat
argument_list|)
empty_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|locale
argument_list|(
specifier|const
name|locale
operator|&
name|__other
argument_list|,
name|_Facet
operator|*
name|__f
argument_list|)
expr_stmt|;
operator|~
name|locale
argument_list|()
name|throw
argument_list|()
expr_stmt|;
specifier|const
name|locale
modifier|&
name|operator
init|=
operator|(
specifier|const
name|locale
operator|&
name|__other
operator|)
name|throw
argument_list|()
decl_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|locale
name|combine
argument_list|(
argument|const locale& __other
argument_list|)
specifier|const
expr_stmt|;
comment|// Locale operations:
name|string
name|name
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|locale
operator|&
name|__other
operator|)
specifier|const
name|throw
argument_list|()
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|locale
operator|&
name|__other
operator|)
specifier|const
name|throw
argument_list|()
block|{
return|return
operator|!
operator|(
name|this
operator|->
name|operator
operator|==
operator|(
name|__other
operator|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|_Char
operator|,
name|typename
name|_Traits
operator|,
name|typename
name|_Alloc
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|basic_string
operator|<
name|_Char
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__s1
operator|,
specifier|const
name|basic_string
operator|<
name|_Char
operator|,
name|_Traits
operator|,
name|_Alloc
operator|>
operator|&
name|__s2
operator|)
specifier|const
expr_stmt|;
comment|// Global locale objects:
specifier|static
name|locale
name|global
parameter_list|(
specifier|const
name|locale
modifier|&
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|locale
modifier|&
name|classic
parameter_list|()
function_decl|;
name|private
label|:
comment|// The (shared) implementation
name|_Impl
modifier|*
name|_M_impl
decl_stmt|;
comment|// The "C" reference locale
specifier|static
name|_Impl
modifier|*
name|_S_classic
decl_stmt|;
comment|// Current global locale
specifier|static
name|_Impl
modifier|*
name|_S_global
decl_stmt|;
comment|// Number of standard categories. For C++, these categories are
comment|// collate, ctype, monetary, numeric, time, and messages. These
comment|// directly correspond to ISO C99 macros LC_COLLATE, LC_CTYPE,
comment|// LC_MONETARY, LC_NUMERIC, and LC_TIME. In addition, POSIX (IEEE
comment|// 1003.1-2001) specifies LC_MESSAGES.
specifier|static
specifier|const
name|size_t
name|_S_categories_size
init|=
literal|6
decl_stmt|;
comment|// In addition to the standard categories, the underlying
comment|// operating system is allowed to define extra LC_*
comment|// macros. For GNU systems, the following are also valid:
comment|// LC_PAPER, LC_NAME, LC_ADDRESS, LC_TELEPHONE, LC_MEASUREMENT,
comment|// and LC_IDENTIFICATION.
specifier|static
specifier|const
name|size_t
name|_S_extra_categories_size
init|=
name|_GLIBCPP_NUM_CATEGORIES
decl_stmt|;
comment|// Names of underlying locale categories.
comment|// NB: locale::global() has to know how to modify all the
comment|// underlying categories, not just the ones required by the C++
comment|// standard.
specifier|static
specifier|const
name|char
modifier|*
name|_S_categories
index|[
name|_S_categories_size
operator|+
name|_S_extra_categories_size
index|]
decl_stmt|;
name|explicit
name|locale
parameter_list|(
name|_Impl
modifier|*
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
specifier|static
specifier|inline
name|void
name|_S_initialize
parameter_list|()
block|{
if|if
condition|(
operator|!
name|_S_classic
condition|)
name|classic
argument_list|()
expr_stmt|;
block|}
specifier|static
name|category
name|_S_normalize_category
parameter_list|(
name|category
parameter_list|)
function_decl|;
name|void
name|_M_coalesce
parameter_list|(
specifier|const
name|locale
modifier|&
name|__base
parameter_list|,
specifier|const
name|locale
modifier|&
name|__add
parameter_list|,
name|category
name|__cat
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|// Implementation object for locale
name|class
name|locale
operator|::
name|_Impl
block|{
name|public
operator|:
comment|// Friends.
name|friend
name|class
name|locale
block|;
name|friend
name|class
name|locale
operator|::
name|facet
block|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
specifier|const
name|_Facet
operator|&
name|use_facet
argument_list|(
specifier|const
name|locale
operator|&
argument_list|)
block|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
name|bool
name|has_facet
argument_list|(
argument|const locale&
argument_list|)
name|throw
argument_list|()
block|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
specifier|const
name|__locale_cache
operator|<
name|_Facet
operator|>
operator|&
name|__use_cache
argument_list|(
specifier|const
name|locale
operator|&
argument_list|)
block|;
name|private
operator|:
comment|// Data Members.
name|_Atomic_word
name|_M_references
block|;
name|facet
operator|*
operator|*
name|_M_facets
block|;
name|size_t
name|_M_facets_size
block|;
name|char
operator|*
name|_M_names
index|[
name|_S_categories_size
operator|+
name|_S_extra_categories_size
index|]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_ctype
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_numeric
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_collate
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_time
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_monetary
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
name|_S_id_messages
index|[]
block|;
specifier|static
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
operator|*
specifier|const
name|_S_facet_categories
index|[]
block|;
specifier|inline
name|void
name|_M_add_reference
argument_list|()
name|throw
argument_list|()
block|{
name|__atomic_add
argument_list|(
operator|&
name|_M_references
argument_list|,
literal|1
argument_list|)
block|; }
specifier|inline
name|void
name|_M_remove_reference
argument_list|()
name|throw
argument_list|()
block|{
if|if
condition|(
name|__exchange_and_add
argument_list|(
operator|&
name|_M_references
argument_list|,
operator|-
literal|1
argument_list|)
operator|==
literal|1
condition|)
block|{
name|try
block|{
name|delete
name|this
decl_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
block|}
block|}
block|}
name|_Impl
argument_list|(
specifier|const
name|_Impl
operator|&
argument_list|,
name|size_t
argument_list|)
expr_stmt|;
name|_Impl
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
expr_stmt|;
name|_Impl
argument_list|(
name|facet
operator|*
operator|*
argument_list|,
name|size_t
argument_list|,
name|bool
argument_list|)
expr_stmt|;
operator|~
name|_Impl
argument_list|()
name|throw
argument_list|()
expr_stmt|;
name|_Impl
argument_list|(
specifier|const
name|_Impl
operator|&
argument_list|)
expr_stmt|;
comment|// Not defined.
name|void
name|operator
init|=
operator|(
specifier|const
name|_Impl
operator|&
operator|)
decl_stmt|;
comment|// Not defined.
specifier|inline
name|bool
name|_M_check_same_name
parameter_list|()
block|{
name|bool
name|__ret
init|=
name|true
decl_stmt|;
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__ret
operator|&&
name|__i
operator|<
name|_S_categories_size
operator|+
name|_S_extra_categories_size
operator|-
literal|1
condition|;
operator|++
name|__i
control|)
name|__ret
operator|&=
operator|(
name|strcmp
argument_list|(
name|_M_names
index|[
name|__i
index|]
argument_list|,
name|_M_names
index|[
name|__i
operator|+
literal|1
index|]
argument_list|)
operator|==
literal|0
operator|)
expr_stmt|;
return|return
name|__ret
return|;
block|}
name|void
name|_M_replace_categories
parameter_list|(
specifier|const
name|_Impl
modifier|*
parameter_list|,
name|category
parameter_list|)
function_decl|;
name|void
name|_M_replace_category
argument_list|(
specifier|const
name|_Impl
operator|*
argument_list|,
specifier|const
name|locale
operator|::
name|id
operator|*
specifier|const
operator|*
argument_list|)
decl_stmt|;
name|void
name|_M_replace_facet
argument_list|(
specifier|const
name|_Impl
operator|*
argument_list|,
specifier|const
name|locale
operator|::
name|id
operator|*
argument_list|)
decl_stmt|;
name|void
name|_M_install_facet
argument_list|(
specifier|const
name|locale
operator|::
name|id
operator|*
argument_list|,
name|facet
operator|*
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|_Facet
operator|>
specifier|inline
name|void
name|_M_init_facet
argument_list|(
argument|_Facet* __facet
argument_list|)
block|{
name|_M_install_facet
argument_list|(
operator|&
name|_Facet
operator|::
name|id
argument_list|,
name|__facet
argument_list|)
block|;  }
comment|// Retrieve the cache at __index.  0 is returned if the cache is
comment|// missing.  Cache is actually located at __index +
comment|// _M_facets_size.  __index must be< _M_facets_size.
specifier|inline
name|__locale_cache_base
operator|*
name|_M_get_cache
argument_list|(
argument|size_t __index
argument_list|)
block|{
return|return
operator|(
name|__locale_cache_base
operator|*
operator|)
name|_M_facets
index|[
name|__index
operator|+
name|_M_facets_size
index|]
return|;
block|}
comment|// Save the supplied cache at __id.  Assumes _M_get_cache has been
comment|// called.
name|void
name|_M_install_cache
parameter_list|(
name|__locale_cache_base
modifier|*
name|__cache
parameter_list|,
name|int
name|__id
parameter_list|)
block|{
name|_M_facets
index|[
name|__id
operator|+
name|_M_facets_size
index|]
operator|=
name|reinterpret_cast
operator|<
name|locale
operator|::
name|facet
operator|*
operator|>
operator|(
name|__cache
operator|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Facet
operator|>
name|locale
operator|::
name|locale
argument_list|(
argument|const locale& __other
argument_list|,
argument|_Facet* __f
argument_list|)
block|{
name|_M_impl
operator|=
name|new
name|_Impl
argument_list|(
operator|*
name|__other
operator|.
name|_M_impl
argument_list|,
literal|1
argument_list|)
block|;
name|_M_impl
operator|->
name|_M_install_facet
argument_list|(
operator|&
name|_Facet
operator|::
name|id
argument_list|,
name|__f
argument_list|)
block|;
for|for
control|(
name|size_t
name|__i
init|=
literal|0
init|;
name|__i
operator|<
name|_S_categories_size
operator|+
name|_S_extra_categories_size
condition|;
operator|++
name|__i
control|)
block|{
name|delete
index|[]
name|_M_impl
operator|->
name|_M_names
index|[
name|__i
index|]
decl_stmt|;
name|char
modifier|*
name|__new
init|=
name|new
name|char
index|[
literal|2
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|__new
argument_list|,
literal|"*"
argument_list|)
expr_stmt|;
name|_M_impl
operator|->
name|_M_names
index|[
name|__i
index|]
operator|=
name|__new
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// 22.1.1.1.2  Class locale::facet
end_comment

begin_expr_stmt
unit|class
name|locale
operator|::
name|facet
block|{
name|private
operator|:
name|friend
name|class
name|locale
block|;
name|friend
name|class
name|locale
operator|::
name|_Impl
block|;
name|_Atomic_word
name|_M_references
block|;
name|protected
operator|:
comment|// Contains data from the underlying "C" library for the classic locale.
specifier|static
name|__c_locale
name|_S_c_locale
block|;
comment|// String literal for the name of the classic locale.
specifier|static
name|char
name|_S_c_name
index|[
literal|2
index|]
block|;
name|explicit
name|facet
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
name|throw
argument_list|()
block|;
name|virtual
operator|~
name|facet
argument_list|()
block|;
specifier|static
name|void
name|_S_create_c_locale
argument_list|(
argument|__c_locale& __cloc
argument_list|,
argument|const char* __s
argument_list|,
argument|__c_locale __old =
literal|0
argument_list|)
block|;
specifier|static
name|__c_locale
name|_S_clone_c_locale
argument_list|(
name|__c_locale
operator|&
name|__cloc
argument_list|)
block|;
specifier|static
name|void
name|_S_destroy_c_locale
argument_list|(
name|__c_locale
operator|&
name|__cloc
argument_list|)
block|;
name|private
operator|:
name|void
name|_M_add_reference
argument_list|()
name|throw
argument_list|()
block|;
name|void
name|_M_remove_reference
argument_list|()
name|throw
argument_list|()
block|;
name|facet
argument_list|(
specifier|const
name|facet
operator|&
argument_list|)
block|;
comment|// Not defined.
name|void
name|operator
operator|=
operator|(
specifier|const
name|facet
operator|&
operator|)
block|;
comment|// Not defined.
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// 22.1.1.1.3 Class locale::id
end_comment

begin_expr_stmt
name|class
name|locale
operator|::
name|id
block|{
name|private
operator|:
name|friend
name|class
name|locale
block|;
name|friend
name|class
name|locale
operator|::
name|_Impl
block|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
specifier|const
name|_Facet
operator|&
name|use_facet
argument_list|(
specifier|const
name|locale
operator|&
argument_list|)
block|;
name|template
operator|<
name|typename
name|_Facet
operator|>
name|friend
name|bool
name|has_facet
argument_list|(
argument|const locale&
argument_list|)
name|throw
argument_list|()
block|;
comment|// NB: There is no accessor for _M_index because it may be used
comment|// before the constructor is run; the effect of calling a member
comment|// function (even an inline) would be undefined.
name|mutable
name|size_t
name|_M_index
block|;
comment|// Last id number assigned.
specifier|static
name|_Atomic_word
name|_S_highwater
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|id
operator|&
operator|)
block|;
comment|// Not defined.
name|id
argument_list|(
specifier|const
name|id
operator|&
argument_list|)
block|;
comment|// Not defined.
name|public
operator|:
comment|// NB: This class is always a static data member, and thus can be
comment|// counted on to be zero-initialized.
name|id
argument_list|()
block|;
specifier|inline
name|size_t
name|_M_id
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|_M_index
condition|)
name|_M_index
operator|=
literal|1
operator|+
name|__exchange_and_add
argument_list|(
operator|&
name|_S_highwater
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|_M_index
operator|-
literal|1
return|;
block|}
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

