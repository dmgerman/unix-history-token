begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: PA-RISC version  -*- C++ -*-
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

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<bits/atomicity.h>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|template
operator|<
name|int
name|_Inst
operator|>
expr|struct
name|_Atomicity_lock
block|{
specifier|static
specifier|volatile
name|int
name|_S_atomicity_lock
block|;     }
expr_stmt|;
name|template
operator|<
name|int
name|_Inst
operator|>
specifier|volatile
name|int
name|_Atomicity_lock
operator|<
name|_Inst
operator|>
operator|::
name|_S_atomicity_lock
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
operator|=
literal|1
expr_stmt|;
comment|// Because of the lack of weak support when using the hpux som
comment|// linker, we explicitly instantiate the atomicity lock.
name|template
specifier|volatile
name|int
name|_Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
expr_stmt|;
name|int
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
name|_Atomic_word
name|result
decl_stmt|;
name|int
name|tmp
decl_stmt|;
specifier|volatile
name|int
modifier|&
name|lock
init|=
name|_Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldcw 0(%1),%0\n\t" 			  "cmpib,<>,n 0,%0,.+20\n\t" 			  "ldw 0(%1),%0\n\t" 			  "cmpib,= 0,%0,.-4\n\t" 			  "nop\n\t" 			  "b,n .-20" 			  : "=&r" (tmp) 			  : "r" (&lock));
name|result
operator|=
operator|*
name|__mem
expr_stmt|;
operator|*
name|__mem
operator|=
name|result
operator|+
name|__val
expr_stmt|;
comment|/* Reset lock with PA 2.0 "ordered" store.  */
asm|__asm__
specifier|__volatile__
asm|("stw,ma %1,0(%0)" 			  : : "r" (&lock), "r" (tmp) : "memory");
return|return
name|result
return|;
block|}
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
name|int
name|tmp
decl_stmt|;
specifier|volatile
name|int
modifier|&
name|lock
init|=
name|_Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldcw 0(%1),%0\n\t" 			  "cmpib,<>,n 0,%0,.+20\n\t" 			  "ldw 0(%1),%0\n\t" 			  "cmpib,= 0,%0,.-4\n\t" 			  "nop\n\t" 			  "b,n .-20" 			  : "=&r" (tmp) 			  : "r" (&lock));
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
comment|/* Reset lock with PA 2.0 "ordered" store.  */
asm|__asm__
specifier|__volatile__
asm|("stw,ma %1,0(%0)" 			  : : "r" (&lock), "r" (tmp) : "memory");
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_cxx
end_comment

end_unit

