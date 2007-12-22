begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: Sparc version  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1999, 2000, 2001, 2002, 2004, 2005
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

begin_ifdef
ifdef|#
directive|ifdef
name|__arch64__
end_ifdef

begin_decl_stmt
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
name|__tmp1
decl_stmt|,
name|__tmp2
decl_stmt|;
name|_Atomic_word
name|__val_extended
init|=
name|__val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:	ldx	[%3], %0\n\t" 			 "	add	%0, %4, %1\n\t" 			 "	casx	[%3], %0, %1\n\t" 			 "	sub	%0, %1, %0\n\t" 			 "	brnz,pn	%0, 1b\n\t" 			 "	 nop" 			 : "=&r" (__tmp1), "=&r" (__tmp2), "=m" (*__mem) 			 : "r" (__mem), "r" (__val_extended), "m" (*__mem));
return|return
name|__tmp2
return|;
block|}
end_decl_stmt

begin_decl_stmt
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
name|_Atomic_word
name|__tmp1
decl_stmt|,
name|__tmp2
decl_stmt|;
name|_Atomic_word
name|__val_extended
init|=
name|__val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:	ldx	[%3], %0\n\t" 			 "	add	%0, %4, %1\n\t" 			 "	casx	[%3], %0, %1\n\t" 			 "	sub	%0, %1, %0\n\t" 			 "	brnz,pn	%0, 1b\n\t" 			 "	 nop" 			 : "=&r" (__tmp1), "=&r" (__tmp2), "=m" (*__mem) 			 : "r" (__mem), "r" (__val_extended), "m" (*__mem));
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __arch32__ */
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|__inst
operator|>
expr|struct
name|_Atomicity_lock
block|{
specifier|static
name|unsigned
name|char
name|_S_atomicity_lock
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|__inst
operator|>
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
end_expr_stmt

begin_expr_stmt
name|template
name|unsigned
name|char
name|_Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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
decl_stmt|,
name|__tmp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:	ldstub	[%1], %0\n\t" 			 "	cmp	%0, 0\n\t" 			 "	bne	1b\n\t" 			 "	 nop" 			 : "=&r" (__tmp) 			 : "r" (&_Atomicity_lock<0>::_S_atomicity_lock) 			 : "memory");
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
asm|__asm__
specifier|__volatile__
asm|("stb	%%g0, [%0]" 			 :
comment|/* no outputs */
asm|: "r" (&_Atomicity_lock<0>::_S_atomicity_lock) 			 : "memory");
return|return
name|__result
return|;
block|}
end_decl_stmt

begin_decl_stmt
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
name|_Atomic_word
name|__tmp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("1:	ldstub	[%1], %0\n\t" 			 "	cmp	%0, 0\n\t" 			 "	bne	1b\n\t" 			 "	 nop" 			 : "=&r" (__tmp) 			 : "r" (&_Atomicity_lock<0>::_S_atomicity_lock) 			 : "memory");
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|("stb	%%g0, [%0]" 			 :
comment|/* no outputs */
asm|: "r" (&_Atomicity_lock<0>::_S_atomicity_lock) 			 : "memory");
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __arch32__ */
end_comment

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

end_unit

