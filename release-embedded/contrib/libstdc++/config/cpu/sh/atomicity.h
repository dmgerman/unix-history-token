begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level functions for atomic operations: sh version  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1999, 2001, 2002, 2003, 2004, 2005, 2006
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

begin_ifdef
ifdef|#
directive|ifdef
name|__SH4A__
end_ifdef

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
name|_Atomic_word
name|__result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("0:\n"      "\tmovli.l\t@%2,r0\n"      "\tmov\tr0,%1\n"      "\tadd\t%3,r0\n"      "\tmovco.l\tr0,@%2\n"      "\tbf\t0b"      : "+m" (*__mem), "=r" (__result)      : "r" (__mem), "rI08" (__val)      : "r0");
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
asm|asm("0:\n"       "\tmovli.l\t@%1,r0\n"       "\tadd\t%2,r0\n"       "\tmovco.l\tr0,@%1\n"       "\tbf\t0b"       : "+m" (*__mem)       : "r" (__mem), "rI08" (__val)       : "r0");
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__SH4A__ */
end_comment

begin_comment
comment|/* This is generic/atomicity.h */
end_comment

begin_include
include|#
directive|include
file|<ext/atomicity.h>
end_include

begin_include
include|#
directive|include
file|<ext/concurrence.h>
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
name|__gnu_cxx
operator|::
name|__mutex
name|atomic_mutex
expr_stmt|;
block|}
end_block

begin_comment
comment|// anonymous namespace
end_comment

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

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
name|__gnu_cxx
operator|::
name|__scoped_lock
name|sentry
argument_list|(
name|atomic_mutex
argument_list|)
expr_stmt|;
name|_Atomic_word
name|__result
decl_stmt|;
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
name|__exchange_and_add
argument_list|(
name|__mem
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__SH4A__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atomicity.h */
end_comment

end_unit

