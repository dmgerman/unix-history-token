begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: S/390 version  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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

begin_ifndef
ifndef|#
directive|ifndef
name|_BITS_ATOMICITY_H
end_ifndef

begin_define
define|#
directive|define
name|_BITS_ATOMICITY_H
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|_Atomic_word
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|inline
name|_Atomic_word
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__exchange_and_add
argument_list|(
specifier|volatile
name|_Atomic_word
operator|*
name|__mem
argument_list|,
name|int
name|__val
argument_list|)
block|{
specifier|register
name|_Atomic_word
name|__old_val
decl_stmt|,
name|__new_val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("   l     %0,0(%2)\n"                         "0: lr    %1,%0\n"                         "   ar    %1,%3\n"                         "   cs    %0,%1,0(%2)\n"                         "   jl    0b"                         : "=&d" (__old_val), "=&d" (__new_val)                         : "a" (__mem), "d" (__val) : "cc", "memory" );
return|return
name|__old_val
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|__atomic_add
argument_list|(
specifier|volatile
name|_Atomic_word
operator|*
name|__mem
argument_list|,
name|int
name|__val
argument_list|)
block|{
name|__exchange_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atomicity.h */
end_comment

end_unit

