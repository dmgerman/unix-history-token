begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: m68k version -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
file|<bits/atomicity.h>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__mc68020__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mc68030__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68040__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mc68060__
argument_list|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__mcpu32__
argument_list|)
comment|// These variants support compare-and-swap.
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
init|=
operator|*
name|__mem
decl_stmt|;
specifier|register
name|_Atomic_word
name|__temp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1: move%.l %0,%1\n\t" 			  "add%.l %3,%1\n\t" 			  "cas%.l %0,%1,%2\n\t" 			  "jne 1b" 			  : "=d" (__result), "=&d" (__temp), "=m" (*__mem) 			  : "d" (__val), "0" (__result), "m" (*__mem));
return|return
name|__result
return|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|__rtems__
argument_list|)
comment|// TAS/JBNE is unsafe on systems with strict priority-based scheduling.
comment|// Disable interrupts, which we can do only from supervisor mode.
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
name|_Atomic_word
name|__result
decl_stmt|;
name|short
name|__level
decl_stmt|,
name|__tmpsr
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("move%.w %%sr,%0\n\tor%.l %0,%1\n\tmove%.w %1,%%sr" 			  : "=d"(__level), "=d"(__tmpsr) : "1"(0x700));
name|__result
operator|=
operator|*
name|__mem
expr_stmt|;
operator|*
name|__mem
operator|=
name|__result
operator|+
name|__val
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|("move%.w %0,%%sr" : : "d"(__level));
return|return
name|__result
return|;
block|}
else|#
directive|else
name|template
operator|<
name|int
name|__inst
operator|>
expr|struct
name|_Atomicity_lock
block|{
specifier|static
specifier|volatile
name|unsigned
name|char
name|_S_atomicity_lock
block|;     }
expr_stmt|;
name|template
operator|<
name|int
name|__inst
operator|>
specifier|volatile
name|unsigned
name|char
name|_Atomicity_lock
operator|<
name|__inst
operator|>
operator|::
name|_S_atomicity_lock
operator|=
literal|0
expr_stmt|;
name|template
specifier|volatile
name|unsigned
name|char
name|_Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
expr_stmt|;
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
name|_Atomic_word
name|__result
decl_stmt|;
comment|// bset with no immediate addressing (not SMP-safe)
if|#
directive|if
name|defined
argument_list|(
name|__mcf5200__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mcf5300__
argument_list|)
asm|__asm__
specifier|__volatile__
asm|("1: bset.b #7,%0@\n\tjbne 1b" 			 :
comment|/* no outputs */
asm|: "a"(&_Atomicity_lock<0>::_S_atomicity_lock) 			 : "cc", "memory");
comment|// CPU32 and MCF5400 support test-and-set (SMP-safe).
elif|#
directive|elif
name|defined
argument_list|(
name|__mcpu32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mcf5400__
argument_list|)
asm|__asm__
specifier|__volatile__
asm|("1: tas %0\n\tjbne 1b" 			 : "+m"(_Atomicity_lock<0>::_S_atomicity_lock) 			 :
comment|/* none */
asm|: "cc");
comment|// Use bset with immediate addressing for 68000/68010 (not SMP-safe)
comment|// NOTE: TAS is available on the 68000, but unsupported by some Amiga
comment|// memory controllers.
else|#
directive|else
asm|__asm__
specifier|__volatile__
asm|("1: bset.b #7,%0\n\tjbne 1b" 			 : "+m"(_Atomicity_lock<0>::_S_atomicity_lock) 			 :
comment|/* none */
asm|: "cc");
endif|#
directive|endif
name|__result
operator|=
operator|*
name|__mem
expr_stmt|;
operator|*
name|__mem
operator|=
name|__result
operator|+
name|__val
expr_stmt|;
name|_Atomicity_lock
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
endif|#
directive|endif
comment|/* TAS / BSET */
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
comment|// Careful: using add.l with a memory destination is not
comment|// architecturally guaranteed to be atomic.
name|__exchange_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_cxx
end_comment

end_unit

