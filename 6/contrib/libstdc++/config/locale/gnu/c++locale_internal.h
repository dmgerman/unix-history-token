begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Prototypes for GLIBC thread locale __-prefixed functions -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2002, 2004 Free Software Foundation, Inc.
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
comment|// Written by Jakub Jelinek<jakub@redhat.com>
end_comment

begin_include
include|#
directive|include
file|<clocale>
end_include

begin_if
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
end_if

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|iswctype_l
argument_list|)
name|__iswctype_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|nl_langinfo_l
argument_list|)
name|__nl_langinfo_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strcoll_l
argument_list|)
name|__strcoll_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strftime_l
argument_list|)
name|__strftime_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strtod_l
argument_list|)
name|__strtod_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strtof_l
argument_list|)
name|__strtof_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strtold_l
argument_list|)
name|__strtold_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|strxfrm_l
argument_list|)
name|__strxfrm_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|towlower_l
argument_list|)
name|__towlower_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|towupper_l
argument_list|)
name|__towupper_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|wcscoll_l
argument_list|)
name|__wcscoll_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|wcsftime_l
argument_list|)
name|__wcsftime_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|wcsxfrm_l
argument_list|)
name|__wcsxfrm_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|wctype_l
argument_list|)
name|__wctype_l
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|newlocale
argument_list|)
name|__newlocale
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|freelocale
argument_list|)
name|__freelocale
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|duplocale
argument_list|)
name|__duplocale
expr_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|__typeof
argument_list|(
argument|uselocale
argument_list|)
name|__uselocale
expr_stmt|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GLIBC 2.3 and later
end_comment

end_unit

