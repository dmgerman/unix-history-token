begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Control various target specific ABI tweaks.  Generic version.
end_comment

begin_comment
comment|// Copyright (C) 2004, 2006 Free Software Foundation, Inc.
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
comment|/** @file cxxabi_tweaks.h  *  The header provides an CPU-variable interface to the C++ ABI.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CXXABI_TWEAKS_H
end_ifndef

begin_define
define|#
directive|define
name|_CXXABI_TWEAKS_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_decl_stmt
name|namespace
name|__cxxabiv1
block|{
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// The generic ABI uses the first byte of a 64-bit guard variable.
define|#
directive|define
name|_GLIBCXX_GUARD_TEST
parameter_list|(
name|x
parameter_list|)
value|(*(char *) (x) != 0)
define|#
directive|define
name|_GLIBCXX_GUARD_SET
parameter_list|(
name|x
parameter_list|)
value|*(char *) (x) = 1
name|__extension__
typedef|typedef
name|int
name|__guard
name|__attribute__
typedef|((
name|mode
typedef|(
name|__DI__
typedef|)));
comment|// __cxa_vec_ctor has void return type.
typedef|typedef
name|void
name|__cxa_vec_ctor_return_type
typedef|;
define|#
directive|define
name|_GLIBCXX_CXA_VEC_CTOR_RETURN
parameter_list|(
name|x
parameter_list|)
value|return
comment|// Constructors and destructors do not return a value.
typedef|typedef
name|void
name|__cxa_cdtor_return_type
typedef|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __cxxabiv1
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

