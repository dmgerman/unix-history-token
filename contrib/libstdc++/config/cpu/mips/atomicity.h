begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: MIPS version  -*- C++ -*-
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
asm|("/* Inline exchange& add */\n\t"        "1:\n\t"        ".set	push\n\t"
if|#
directive|if
name|_MIPS_SIM
operator|==
name|_ABIO32
asm|".set	mips2\n\t"
endif|#
directive|endif
asm|"ll	%0,%3\n\t"        "addu	%1,%4,%0\n\t"        "sc	%1,%2\n\t"        ".set	pop\n\t"        "beqz	%1,1b\n\t"        "/* End exchange& add */"        : "=&r"(__result), "=&r"(__tmp), "=m"(*__mem)        : "m" (*__mem), "r"(__val));
return|return
name|__result
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
name|_Atomic_word
name|__result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("/* Inline atomic add */\n\t"        "1:\n\t"        ".set	push\n\t"
if|#
directive|if
name|_MIPS_SIM
operator|==
name|_ABIO32
asm|".set	mips2\n\t"
endif|#
directive|endif
asm|"ll	%0,%2\n\t"        "addu	%0,%3,%0\n\t"        "sc	%0,%1\n\t"        ".set	pop\n\t"        "beqz	%0,1b\n\t"        "/* End atomic add */"        : "=&r"(__result), "=m"(*__mem)      : "m" (*__mem), "r"(__val));
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __gnu_cxx
end_comment

end_unit

