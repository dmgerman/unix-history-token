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
comment|// ISO C++ 14882:
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CWCTYPE
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CWCTYPE
value|1
end_define

begin_include
include|#
directive|include
file|<bits/std_cwchar.h>
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
empty|#     include_next<wctype.h>
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|wctype_t
end_undef

begin_undef
undef|#
directive|undef
name|wctrans_t
end_undef

begin_undef
undef|#
directive|undef
name|iswalpha
end_undef

begin_undef
undef|#
directive|undef
name|iswupper
end_undef

begin_undef
undef|#
directive|undef
name|iswlower
end_undef

begin_undef
undef|#
directive|undef
name|iswdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswxdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswalnum
end_undef

begin_undef
undef|#
directive|undef
name|iswspace
end_undef

begin_undef
undef|#
directive|undef
name|iswpunct
end_undef

begin_undef
undef|#
directive|undef
name|iswprint
end_undef

begin_undef
undef|#
directive|undef
name|iswgraph
end_undef

begin_undef
undef|#
directive|undef
name|iswcntrl
end_undef

begin_undef
undef|#
directive|undef
name|iswctype
end_undef

begin_undef
undef|#
directive|undef
name|towctrans
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
name|wctrans
end_undef

begin_undef
undef|#
directive|undef
name|wctype
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
name|using
name|_C_legacy
operator|::
name|wctype_t
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|wctrans_t
expr_stmt|;
specifier|inline
name|int
name|iswalpha
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswalpha
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswupper
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswupper
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswlower
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswlower
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswdigit
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswdigit
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswxdigit
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswxdigit
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswalnum
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswalnum
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswspace
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswspace
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswpunct
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswpunct
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswprint
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswprint
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswgraph
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswgraph
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswcntrl
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswcntrl
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|towlower
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|towlower
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|towupper
parameter_list|(
name|wint_t
name|__wc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|towupper
argument_list|(
name|__wc
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iswctype
parameter_list|(
name|wint_t
name|__wc
parameter_list|,
name|wctype_t
name|__desc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|iswctype
argument_list|(
name|__wc
argument_list|,
name|__desc
argument_list|)
return|;
block|}
specifier|inline
name|wint_t
name|towctrans
parameter_list|(
name|wint_t
name|__wc
parameter_list|,
name|wctrans_t
name|__desc
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|towctrans
argument_list|(
name|__wc
argument_list|,
name|__desc
argument_list|)
return|;
block|}
specifier|inline
name|wctrans_t
name|wctrans
parameter_list|(
specifier|const
name|char
modifier|*
name|__property
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|wctrans
argument_list|(
name|__property
argument_list|)
return|;
block|}
specifier|inline
name|wctype_t
name|wctype
parameter_list|(
name|char
specifier|const
modifier|*
name|__property
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|wctype
argument_list|(
name|__property
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

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

