begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support (codecvt) -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 22.2.1.5 Template class codecvt
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Written by Benjamin Kosnik<bkoz@cygnus.com>
end_comment

begin_comment
comment|/** @file codecvt.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_CODECVT_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_CODECVT_H
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_comment
comment|//  22.2.1.5  Template class codecvt
end_comment

begin_decl_stmt
name|class
name|codecvt_base
block|{
name|public
label|:
enum|enum
name|result
block|{
name|ok
block|,
name|partial
block|,
name|error
block|,
name|noconv
block|}
enum|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Template class __codecvt_abstract_base
end_comment

begin_comment
comment|// NB: An abstract base class that fills in the public inlines, so
end_comment

begin_comment
comment|// that the specializations don't have to re-copy the public
end_comment

begin_comment
comment|// interface.
end_comment

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
name|__codecvt_abstract_base
operator|:
name|public
name|locale
operator|::
name|facet
operator|,
name|public
name|codecvt_base
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|codecvt_base
operator|::
name|result
name|result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InternT
name|intern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_ExternT
name|extern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_StateT
name|state_type
typedef|;
end_typedef

begin_comment
comment|// 22.2.1.5.1 codecvt members
end_comment

begin_decl_stmt
name|result
name|out
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|intern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_out
argument_list|(
name|__state
argument_list|,
name|__from
argument_list|,
name|__from_end
argument_list|,
name|__from_next
argument_list|,
name|__to
argument_list|,
name|__to_end
argument_list|,
name|__to_next
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|result
name|unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_unshift
argument_list|(
name|__state
argument_list|,
name|__to
argument_list|,
name|__to_end
argument_list|,
name|__to_next
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|result
name|in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_in
argument_list|(
name|__state
argument_list|,
name|__from
argument_list|,
name|__from_end
argument_list|,
name|__from_next
argument_list|,
name|__to
argument_list|,
name|__to_end
argument_list|,
name|__to_next
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|int
name|encoding
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|this
operator|->
name|do_encoding
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|this
operator|->
name|do_always_noconv
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|int
name|length
argument_list|(
specifier|const
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
block|{
return|return
name|this
operator|->
name|do_length
argument_list|(
name|__state
argument_list|,
name|__from
argument_list|,
name|__end
argument_list|,
name|__max
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|int
name|max_length
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|this
operator|->
name|do_max_length
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|__codecvt_abstract_base
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
name|virtual
operator|~
name|__codecvt_abstract_base
argument_list|()
block|{ }
name|virtual
name|result
name|do_out
argument_list|(
argument|state_type& __state
argument_list|,
argument|const intern_type* __from
argument_list|,
argument|const intern_type* __from_end
argument_list|,
argument|const intern_type*& __from_next
argument_list|,
argument|extern_type* __to
argument_list|,
argument|extern_type* __to_end
argument_list|,
argument|extern_type*& __to_next
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|result
name|do_unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|bool
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|int
name|do_length
argument_list|(
specifier|const
name|state_type
operator|&
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// 22.2.1.5 Template class codecvt
end_comment

begin_comment
comment|// NB: Generic, mostly useless implementation.
end_comment

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
operator|:
name|public
name|__codecvt_abstract_base
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|_StateT
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|codecvt_base
operator|::
name|result
name|result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InternT
name|intern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_ExternT
name|extern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_StateT
name|state_type
typedef|;
end_typedef

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
name|codecvt
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|__codecvt_abstract_base
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|_StateT
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|codecvt
argument_list|()
block|{ }
name|virtual
name|result
name|do_out
argument_list|(
argument|state_type& __state
argument_list|,
argument|const intern_type* __from
argument_list|,
argument|const intern_type* __from_end
argument_list|,
argument|const intern_type*& __from_next
argument_list|,
argument|extern_type* __to
argument_list|,
argument|extern_type* __to_end
argument_list|,
argument|extern_type*& __to_next
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|result
name|do_unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|bool
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|int
name|do_length
argument_list|(
specifier|const
name|state_type
operator|&
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
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
name|locale
operator|::
name|id
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|_StateT
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// codecvt<char, char, mbstate_t> required specialization
end_comment

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
operator|:
name|public
name|__codecvt_abstract_base
operator|<
name|char
operator|,
name|char
operator|,
name|mbstate_t
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|char
name|intern_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|char
name|extern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mbstate_t
name|state_type
typedef|;
end_typedef

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
name|codecvt
parameter_list|(
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
name|codecvt
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|result
name|do_out
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|intern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|bool
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|int
name|do_length
argument_list|(
specifier|const
name|state_type
operator|&
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_comment
comment|// codecvt<wchar_t, char, mbstate_t> required specialization
end_comment

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
operator|:
name|public
name|__codecvt_abstract_base
operator|<
name|wchar_t
operator|,
name|char
operator|,
name|mbstate_t
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|wchar_t
name|intern_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|char
name|extern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mbstate_t
name|state_type
typedef|;
end_typedef

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
name|codecvt
parameter_list|(
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
name|codecvt
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|result
name|do_out
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from
argument_list|,
specifier|const
name|intern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|intern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|bool
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|int
name|do_length
argument_list|(
specifier|const
name|state_type
operator|&
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|//_GLIBCPP_USE_WCHAR_T
end_comment

begin_comment
comment|// 22.2.1.6  Template class codecvt_byname
end_comment

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
operator|:
name|public
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|_StateT
operator|>
block|{
name|public
operator|:
name|explicit
name|codecvt_byname
argument_list|(
argument|const char*
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|codecvt
operator|<
name|_InternT
block|,
name|_ExternT
block|,
name|_StateT
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|codecvt_byname
argument_list|()
block|{ }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Include host and configuration specific partial specializations
end_comment

begin_comment
comment|// with additional functionality, if possible.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_WCHAR_T
end_ifdef

begin_include
include|#
directive|include
file|<bits/codecvt_specializations.h>
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
comment|// _CPP_BITS_CODECVT_H
end_comment

end_unit

