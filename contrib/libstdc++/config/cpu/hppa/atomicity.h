begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Low-level functions for atomic operations.  PA-RISC version. -*- C++ -*-    Copyright 2002 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
name|int
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
name|int
name|__Atomicity_lock
operator|<
name|__inst
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
end_expr_stmt

begin_comment
comment|/* Because of the lack of weak support when using the hpux    som linker, we explicitly instantiate the atomicity lock    in src/misc-inst.cc when _GLIBCPP_INST_ATOMICITY_LOCK    is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_INST_ATOMICITY_LOCK
end_ifndef

begin_expr_stmt
name|template
specifier|volatile
name|int
name|__Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|inline
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
name|__Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldcw 0(%1),%0\n\t" 			"cmpib,<>,n 0,%0,.+20\n\t" 			"ldw 0(%1),%0\n\t" 			"cmpib,= 0,%0,.-4\n\t" 			"nop\n\t" 			"b,n .-20" 			: "=&r" (tmp) 			: "r" (&lock));
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
asm|("stw,ma %1,0(%0)" 			: : "r" (&lock), "r" (tmp) : "memory");
return|return
name|result
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
name|__Atomicity_lock
operator|<
literal|0
operator|>
operator|::
name|_S_atomicity_lock
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldcw 0(%1),%0\n\t" 			"cmpib,<>,n 0,%0,.+20\n\t" 			"ldw 0(%1),%0\n\t" 			"cmpib,= 0,%0,.-4\n\t" 			"nop\n\t" 			"b,n .-20" 			: "=&r" (tmp) 			: "r" (&lock));
operator|*
name|__mem
operator|+=
name|__val
expr_stmt|;
comment|/* Reset lock with PA 2.0 "ordered" store.  */
asm|__asm__
specifier|__volatile__
asm|("stw,ma %1,0(%0)" 			: : "r" (&lock), "r" (tmp) : "memory");
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

