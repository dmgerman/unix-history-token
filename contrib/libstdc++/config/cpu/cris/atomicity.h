begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: CRIS version  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2003, 2004, 2005 Free Software Foundation, Inc.
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

begin_include
include|#
directive|include
file|<ext/atomicity.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_function
name|_Atomic_word
name|__exchange_and_add
parameter_list|(
specifier|volatile
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
name|int
name|__tmp
decl_stmt|;
name|_Atomic_word
name|__result
decl_stmt|;
if|#
directive|if
operator|(
name|__CRIS_arch_version
operator|>=
literal|10
operator|)
asm|__asm__
specifier|__volatile__
asm|(" clearf		\n" 			"0:			\n" 			" move.d %4,%2		\n" 			" move.d [%3],%0	\n" 			" add.d %0,%2		\n" 			" ax			\n" 			" move.d %2,[%3]	\n" 			" bwf 0b		\n" 			" clearf		\n" 			:  "=&r" (__result), "=Q" (*__mem), "=&r" (__tmp) 			: "r" (__mem), "g" (__val), "Q" (*__mem)
comment|/* The memory clobber must stay, regardless of 			   current uses of this function.  */
asm|: "memory");
else|#
directive|else
asm|__asm__
specifier|__volatile__
asm|(" move $ccr,$r9	\n" 			" di			\n" 			" move.d %4,%2		\n" 			" move.d [%3],%0	\n" 			" add.d %0,%2		\n" 			" move.d %2,[%3]	\n" 			" move $r9,$ccr		\n" 			:  "=&r" (__result), "=Q" (*__mem), "=&r" (__tmp) 			: "r" (__mem), "g" (__val), "Q" (*__mem) 			: "r9",
comment|/* The memory clobber must stay, regardless of 			     current uses of this function.  */
asm|"memory");
endif|#
directive|endif
return|return
name|__result
return|;
block|}
end_function

begin_function
name|void
name|__atomic_add
parameter_list|(
specifier|volatile
name|_Atomic_word
modifier|*
name|__mem
parameter_list|,
name|int
name|__val
parameter_list|)
block|{
name|__exchange_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

end_unit

