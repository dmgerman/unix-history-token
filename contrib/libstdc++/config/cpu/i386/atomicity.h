begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: x86, x>= 3 version  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003 Free Software Foundation, Inc.
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

begin_expr_stmt
name|template
operator|<
name|int
name|__inst
operator|>
expr|struct
name|__Atomicity_lock
block|{
specifier|static
specifier|volatile
name|_Atomic_word
name|_S_atomicity_lock
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|__inst
operator|>
specifier|volatile
name|_Atomic_word
name|__Atomicity_lock
operator|<
name|__inst
operator|>
operator|::
name|_S_atomicity_lock
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
specifier|volatile
name|_Atomic_word
name|__Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
expr_stmt|;
end_expr_stmt

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
name|__result
decl_stmt|,
name|__tmp
init|=
literal|1
decl_stmt|;
comment|/* obtain the atomic exchange/add spin lock */
do|do
block|{
asm|__asm__
specifier|__volatile__
asm|("xchg{l} {%0,%1|%1,%0}" 			  : "+m" (__Atomicity_lock<0>::_S_atomicity_lock), 			    "+r" (__tmp));
block|}
do|while
condition|(
name|__tmp
condition|)
do|;
name|__result
operator|=
operator|*
name|__mem
expr_stmt|;
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
comment|/* release spin lock */
name|__Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
operator|=
literal|0
expr_stmt|;
return|return
name|__result
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

