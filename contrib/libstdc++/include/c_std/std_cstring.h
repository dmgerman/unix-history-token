begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- forwarding header.
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002
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
comment|// ISO C++ 14882: 20.4.6  C library
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file cstring  *  This is a Standard C++ Library file.  You should @c #include this file  *  in your programs, rather than any of the "*.h" implementation files.  *  *  This is the C++ version of the Standard C Library header @c string.h,  *  and its contents are (mostly) the same as that header, but are all  *  contained in the namespace @c std.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_CSTRING
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_CSTRING
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
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|// Get rid of those macros defined in<string.h> in lieu of real functions.
end_comment

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_undef
undef|#
directive|undef
name|memmove
end_undef

begin_undef
undef|#
directive|undef
name|strcpy
end_undef

begin_undef
undef|#
directive|undef
name|strncpy
end_undef

begin_undef
undef|#
directive|undef
name|strcat
end_undef

begin_undef
undef|#
directive|undef
name|strncat
end_undef

begin_undef
undef|#
directive|undef
name|memcmp
end_undef

begin_undef
undef|#
directive|undef
name|strcmp
end_undef

begin_undef
undef|#
directive|undef
name|strcoll
end_undef

begin_undef
undef|#
directive|undef
name|strncmp
end_undef

begin_undef
undef|#
directive|undef
name|strxfrm
end_undef

begin_undef
undef|#
directive|undef
name|memchr
end_undef

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_undef
undef|#
directive|undef
name|strcspn
end_undef

begin_undef
undef|#
directive|undef
name|strpbrk
end_undef

begin_undef
undef|#
directive|undef
name|strrchr
end_undef

begin_undef
undef|#
directive|undef
name|strspn
end_undef

begin_undef
undef|#
directive|undef
name|strstr
end_undef

begin_undef
undef|#
directive|undef
name|strtok
end_undef

begin_undef
undef|#
directive|undef
name|memset
end_undef

begin_undef
undef|#
directive|undef
name|strerror
end_undef

begin_undef
undef|#
directive|undef
name|strlen
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
name|using
operator|::
name|memcpy
expr_stmt|;
name|using
operator|::
name|memmove
expr_stmt|;
name|using
operator|::
name|strcpy
expr_stmt|;
name|using
operator|::
name|strncpy
expr_stmt|;
name|using
operator|::
name|strcat
expr_stmt|;
name|using
operator|::
name|strncat
expr_stmt|;
name|using
operator|::
name|memcmp
expr_stmt|;
name|using
operator|::
name|strcmp
expr_stmt|;
name|using
operator|::
name|strcoll
expr_stmt|;
name|using
operator|::
name|strncmp
expr_stmt|;
name|using
operator|::
name|strxfrm
expr_stmt|;
name|using
operator|::
name|strcspn
expr_stmt|;
name|using
operator|::
name|strspn
expr_stmt|;
name|using
operator|::
name|strtok
expr_stmt|;
name|using
operator|::
name|memset
expr_stmt|;
name|using
operator|::
name|strerror
expr_stmt|;
name|using
operator|::
name|strlen
expr_stmt|;
name|using
operator|::
name|memchr
expr_stmt|;
specifier|inline
name|void
modifier|*
name|memchr
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|int
name|__c
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
return|return
name|memchr
argument_list|(
name|const_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|__p
operator|)
argument_list|,
name|__c
argument_list|,
name|__n
argument_list|)
return|;
block|}
name|using
operator|::
name|strchr
expr_stmt|;
specifier|inline
name|char
modifier|*
name|strchr
parameter_list|(
name|char
modifier|*
name|__s1
parameter_list|,
name|int
name|__n
parameter_list|)
block|{
return|return
name|__builtin_strchr
argument_list|(
name|const_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__n
argument_list|)
return|;
block|}
name|using
operator|::
name|strpbrk
expr_stmt|;
specifier|inline
name|char
modifier|*
name|strpbrk
parameter_list|(
name|char
modifier|*
name|__s1
parameter_list|,
specifier|const
name|char
modifier|*
name|__s2
parameter_list|)
block|{
return|return
name|__builtin_strpbrk
argument_list|(
name|const_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__s2
argument_list|)
return|;
block|}
name|using
operator|::
name|strrchr
expr_stmt|;
specifier|inline
name|char
modifier|*
name|strrchr
parameter_list|(
name|char
modifier|*
name|__s1
parameter_list|,
name|int
name|__n
parameter_list|)
block|{
return|return
name|__builtin_strrchr
argument_list|(
name|const_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__n
argument_list|)
return|;
block|}
name|using
operator|::
name|strstr
expr_stmt|;
specifier|inline
name|char
modifier|*
name|strstr
parameter_list|(
name|char
modifier|*
name|__s1
parameter_list|,
specifier|const
name|char
modifier|*
name|__s2
parameter_list|)
block|{
return|return
name|__builtin_strstr
argument_list|(
name|const_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|__s1
operator|)
argument_list|,
name|__s2
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

