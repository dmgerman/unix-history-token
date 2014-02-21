begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2004, 2006
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
comment|/** @file ctype_noninline.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
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
comment|// Information as gleaned from /usr/include/ctype.h
end_comment

begin_expr_stmt
specifier|const
name|ctype_base
operator|::
name|mask
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|classic_table
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__C_ctype_b
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ctype
operator|<
name|char
operator|>
operator|::
name|ctype
argument_list|(
argument|__c_locale
argument_list|,
argument|const mask* __table
argument_list|,
argument|bool __del
argument_list|,
argument|size_t __refs
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_ctype
argument_list|(
name|_S_get_c_locale
argument_list|()
argument_list|)
operator|,
name|_M_del
argument_list|(
name|__table
operator|!=
literal|0
operator|&&
name|__del
argument_list|)
operator|,
name|_M_widen_ok
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_narrow_ok
argument_list|(
literal|0
argument_list|)
block|{
name|_M_toupper
operator|=
name|__C_ctype_toupper
block|;
name|_M_tolower
operator|=
name|__C_ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|__C_ctype_b
block|;
name|memset
argument_list|(
name|_M_widen
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_widen
argument_list|)
argument_list|)
block|;
name|memset
argument_list|(
name|_M_narrow
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_narrow
argument_list|)
argument_list|)
block|;   }
name|ctype
operator|<
name|char
operator|>
operator|::
name|ctype
argument_list|(
argument|const mask* __table
argument_list|,
argument|bool __del
argument_list|,
argument|size_t __refs
argument_list|)
operator|:
name|facet
argument_list|(
name|__refs
argument_list|)
operator|,
name|_M_c_locale_ctype
argument_list|(
name|_S_get_c_locale
argument_list|()
argument_list|)
operator|,
name|_M_del
argument_list|(
name|__table
operator|!=
literal|0
operator|&&
name|__del
argument_list|)
operator|,
name|_M_widen_ok
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_narrow_ok
argument_list|(
literal|0
argument_list|)
block|{
name|_M_toupper
operator|=
name|__C_ctype_toupper
block|;
name|_M_tolower
operator|=
name|__C_ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|__C_ctype_b
block|;
name|memset
argument_list|(
name|_M_widen
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_widen
argument_list|)
argument_list|)
block|;
name|memset
argument_list|(
name|_M_narrow
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|_M_narrow
argument_list|)
argument_list|)
block|;   }
name|char
name|ctype
operator|<
name|char
operator|>
operator|::
name|do_toupper
argument_list|(
argument|char __c
argument_list|)
specifier|const
block|{
return|return
name|_M_toupper
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|do_toupper
argument_list|(
argument|char* __low
argument_list|,
argument|const char* __high
argument_list|)
specifier|const
block|{
while|while
condition|(
name|__low
operator|<
name|__high
condition|)
block|{
operator|*
name|__low
operator|=
name|_M_toupper
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|*
name|__low
operator|)
index|]
expr_stmt|;
operator|++
name|__low
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__high
return|;
end_return

begin_expr_stmt
unit|}    char
name|ctype
operator|<
name|char
operator|>
operator|::
name|do_tolower
argument_list|(
argument|char __c
argument_list|)
specifier|const
block|{
return|return
name|_M_tolower
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|do_tolower
argument_list|(
argument|char* __low
argument_list|,
argument|const char* __high
argument_list|)
specifier|const
block|{
while|while
condition|(
name|__low
operator|<
name|__high
condition|)
block|{
operator|*
name|__low
operator|=
name|_M_tolower
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|*
name|__low
operator|)
index|]
expr_stmt|;
operator|++
name|__low
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__high
return|;
end_return

unit|}
end_unit

