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
comment|// ISO C++ 14882: 22
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CCTYPE
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CCTYPE
value|1
end_define

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
empty|#     include_next<ctype.h>
block|}
specifier|inline
name|int
name|_CPP_isalnum_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isalnum
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isalpha_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isalpha
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_iscntrl_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|iscntrl
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isdigit_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isdigit
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isgraph_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isgraph
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_islower_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|islower
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isprint_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isprint
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_ispunct_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|ispunct
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isspace_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isspace
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isupper_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isupper
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_isxdigit_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|isxdigit
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_tolower_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|tolower
argument_list|(
name|c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|_CPP_toupper_capture
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
name|toupper
argument_list|(
name|c
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|isalnum
end_undef

begin_undef
undef|#
directive|undef
name|isalpha
end_undef

begin_undef
undef|#
directive|undef
name|iscntrl
end_undef

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_undef
undef|#
directive|undef
name|isgraph
end_undef

begin_undef
undef|#
directive|undef
name|islower
end_undef

begin_undef
undef|#
directive|undef
name|isprint
end_undef

begin_undef
undef|#
directive|undef
name|ispunct
end_undef

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_undef
undef|#
directive|undef
name|isupper
end_undef

begin_undef
undef|#
directive|undef
name|isxdigit
end_undef

begin_undef
undef|#
directive|undef
name|tolower
end_undef

begin_undef
undef|#
directive|undef
name|toupper
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
specifier|inline
name|int
name|isalnum
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isalnum_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isalpha
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isalpha_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|iscntrl
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_iscntrl_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isdigit
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isdigit_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isgraph
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isgraph_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|islower
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_islower_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isprint
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isprint_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|ispunct
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_ispunct_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isspace
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isspace_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isupper
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isupper_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|isxdigit
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_isxdigit_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|tolower
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_tolower_capture
argument_list|(
name|__c
argument_list|)
return|;
block|}
specifier|inline
name|int
name|toupper
parameter_list|(
name|int
name|__c
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|_CPP_toupper_capture
argument_list|(
name|__c
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

