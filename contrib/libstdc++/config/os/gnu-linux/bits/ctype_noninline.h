begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
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
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Information as gleaned from /usr/include/ctype.h
end_comment

begin_if
if|#
directive|if
name|_GLIBCPP_C_LOCALE_GNU
end_if

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
name|locale
operator|::
name|classic
argument_list|()
block|;
return|return
name|_S_c_locale
operator|->
name|__ctype_b
return|;
block|}
end_expr_stmt

begin_else
else|#
directive|else
end_else

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
specifier|const
name|ctype_base
operator|::
name|mask
operator|*
name|__ret
block|;
name|char
operator|*
name|__old
operator|=
name|strdup
argument_list|(
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|NULL
argument_list|)
argument_list|)
block|;
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|"C"
argument_list|)
block|;
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
name|__ret
operator|=
operator|*
name|__ctype_b_loc
argument_list|()
block|;
else|#
directive|else
name|__ret
operator|=
name|__ctype_b
block|;
endif|#
directive|endif
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|__old
argument_list|)
block|;
name|free
argument_list|(
name|__old
argument_list|)
block|;
return|return
name|__ret
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_GLIBCPP_C_LOCALE_GNU
end_if

begin_expr_stmt
name|ctype
operator|<
name|char
operator|>
operator|::
name|ctype
argument_list|(
argument|__c_locale __cloc
argument_list|,
argument|const mask* __table
argument_list|,
argument|bool __del
argument_list|,
argument|size_t __refs
argument_list|)
operator|:
name|__ctype_abstract_base
operator|<
name|char
operator|>
operator|(
name|__refs
operator|)
operator|,
name|_M_del
argument_list|(
argument|__table !=
literal|0
argument|&& __del
argument_list|)
block|{
name|_M_c_locale_ctype
operator|=
name|_S_clone_c_locale
argument_list|(
name|__cloc
argument_list|)
block|;
name|_M_toupper
operator|=
name|_M_c_locale_ctype
operator|->
name|__ctype_toupper
block|;
name|_M_tolower
operator|=
name|_M_c_locale_ctype
operator|->
name|__ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|_M_c_locale_ctype
operator|->
name|__ctype_b
block|;   }
else|#
directive|else
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
name|__ctype_abstract_base
operator|<
name|char
operator|>
operator|(
name|__refs
operator|)
operator|,
name|_M_del
argument_list|(
argument|__table !=
literal|0
argument|&& __del
argument_list|)
block|{
name|char
operator|*
name|__old
operator|=
name|strdup
argument_list|(
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|NULL
argument_list|)
argument_list|)
block|;
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|"C"
argument_list|)
block|;
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
name|_M_toupper
operator|=
operator|*
name|__ctype_toupper_loc
argument_list|()
block|;
name|_M_tolower
operator|=
operator|*
name|__ctype_tolower_loc
argument_list|()
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
operator|*
name|__ctype_b_loc
argument_list|()
block|;
else|#
directive|else
name|_M_toupper
operator|=
name|__ctype_toupper
block|;
name|_M_tolower
operator|=
name|__ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|__ctype_b
block|;
endif|#
directive|endif
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|__old
argument_list|)
block|;
name|free
argument_list|(
name|__old
argument_list|)
block|;
name|_M_c_locale_ctype
operator|=
name|_S_c_locale
block|;   }
endif|#
directive|endif
if|#
directive|if
name|_GLIBCPP_C_LOCALE_GNU
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
name|__ctype_abstract_base
operator|<
name|char
operator|>
operator|(
name|__refs
operator|)
operator|,
name|_M_del
argument_list|(
argument|__table !=
literal|0
argument|&& __del
argument_list|)
block|{
name|_M_c_locale_ctype
operator|=
name|_S_c_locale
block|;
name|_M_toupper
operator|=
name|_M_c_locale_ctype
operator|->
name|__ctype_toupper
block|;
name|_M_tolower
operator|=
name|_M_c_locale_ctype
operator|->
name|__ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|_M_c_locale_ctype
operator|->
name|__ctype_b
block|;   }
else|#
directive|else
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
name|__ctype_abstract_base
operator|<
name|char
operator|>
operator|(
name|__refs
operator|)
operator|,
name|_M_del
argument_list|(
argument|__table !=
literal|0
argument|&& __del
argument_list|)
block|{
name|char
operator|*
name|__old
operator|=
name|strdup
argument_list|(
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|NULL
argument_list|)
argument_list|)
block|;
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|"C"
argument_list|)
block|;
if|#
directive|if
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
name|_M_toupper
operator|=
operator|*
name|__ctype_toupper_loc
argument_list|()
block|;
name|_M_tolower
operator|=
operator|*
name|__ctype_tolower_loc
argument_list|()
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
operator|*
name|__ctype_b_loc
argument_list|()
block|;
else|#
directive|else
name|_M_toupper
operator|=
name|__ctype_toupper
block|;
name|_M_tolower
operator|=
name|__ctype_tolower
block|;
name|_M_table
operator|=
name|__table
condition|?
name|__table
else|:
name|__ctype_b
block|;
endif|#
directive|endif
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
name|__old
argument_list|)
block|;
name|free
argument_list|(
name|__old
argument_list|)
block|;
name|_M_c_locale_ctype
operator|=
name|_S_c_locale
block|;   }
endif|#
directive|endif
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

