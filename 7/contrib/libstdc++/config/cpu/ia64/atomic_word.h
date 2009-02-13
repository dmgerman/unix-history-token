begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Low-level type for atomic operations -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2004, 2005, 2006, 2007 Free Software Foundation, Inc.
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
name|_GLIBCXX_ATOMIC_WORD_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_ATOMIC_WORD_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/cxxabi_tweaks.h>
end_include

begin_typedef
typedef|typedef
name|int
name|_Atomic_word
typedef|;
end_typedef

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|// Test the first byte of __g and ensure that no loads are hoisted across
comment|// the test.
specifier|inline
name|bool
name|__test_and_acquire
argument_list|(
name|__cxxabiv1
operator|::
name|__guard
operator|*
name|__g
argument_list|)
block|{
name|unsigned
name|char
name|__c
decl_stmt|;
name|unsigned
name|char
modifier|*
name|__p
init|=
name|reinterpret_cast
operator|<
name|unsigned
name|char
operator|*
operator|>
operator|(
name|__g
operator|)
decl_stmt|;
comment|// ldN.acq is a load with an implied hoist barrier.
comment|// would ld8+mask be faster than just doing an ld1?
asm|__asm __volatile ("ld1.acq %0 = %1" : "=r"(__c) : "m"(*__p) : "memory");
return|return
name|__c
operator|!=
literal|0
return|;
block|}
comment|// Set the first byte of __g to 1 and ensure that no stores are sunk
comment|// across the store.
specifier|inline
name|void
name|__set_and_release
argument_list|(
name|__cxxabiv1
operator|::
name|__guard
operator|*
name|__g
argument_list|)
block|{
name|unsigned
name|char
modifier|*
name|__p
init|=
name|reinterpret_cast
operator|<
name|unsigned
name|char
operator|*
operator|>
operator|(
name|__g
operator|)
decl_stmt|;
comment|// stN.rel is a store with an implied sink barrier.
comment|// could load word, set flag, and CAS it back
asm|__asm __volatile ("st1.rel %0 = %1" : "=m"(*__p) : "r"(1) : "memory");
block|}
comment|// We don't define the _BARRIER macros on ia64 because the barriers are
comment|// included in the test and set, above.
define|#
directive|define
name|_GLIBCXX_GUARD_TEST_AND_ACQUIRE
parameter_list|(
name|G
parameter_list|)
value|__gnu_cxx::__test_and_acquire (G)
define|#
directive|define
name|_GLIBCXX_GUARD_SET_AND_RELEASE
parameter_list|(
name|G
parameter_list|)
value|__gnu_cxx::__set_and_release (G)
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

