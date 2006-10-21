begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and multiple processors.  *  * atomic_set_char(P, V)	(*(u_char*)(P) |= (V))  * atomic_clear_char(P, V)	(*(u_char*)(P)&= ~(V))  * atomic_add_char(P, V)	(*(u_char*)(P) += (V))  * atomic_subtract_char(P, V)	(*(u_char*)(P) -= (V))  *  * atomic_set_short(P, V)	(*(u_short*)(P) |= (V))  * atomic_clear_short(P, V)	(*(u_short*)(P)&= ~(V))  * atomic_add_short(P, V)	(*(u_short*)(P) += (V))  * atomic_subtract_short(P, V)	(*(u_short*)(P) -= (V))  *  * atomic_set_int(P, V)		(*(u_int*)(P) |= (V))  * atomic_clear_int(P, V)	(*(u_int*)(P)&= ~(V))  * atomic_add_int(P, V)		(*(u_int*)(P) += (V))  * atomic_subtract_int(P, V)	(*(u_int*)(P) -= (V))  * atomic_readandclear_int(P)	(return  *(u_int*)P; *(u_int*)P = 0;)  *  * atomic_set_long(P, V)	(*(u_long*)(P) |= (V))  * atomic_clear_long(P, V)	(*(u_long*)(P)&= ~(V))  * atomic_add_long(P, V)	(*(u_long*)(P) += (V))  * atomic_subtract_long(P, V)	(*(u_long*)(P) -= (V))  * atomic_readandclear_long(P)	(return  *(u_long*)P; *(u_long*)P = 0;)  */
end_comment

begin_comment
comment|/*  * The above functions are expanded inline in the statically-linked  * kernel.  Lock prefixes are generated if an SMP kernel is being  * built.  *  * Kernel modules call real functions which are built into the kernel.  * This allows kernel modules to be portable between UP and SMP systems.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_ASM
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|OP
parameter_list|,
name|V
parameter_list|)
define|\
value|extern void atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KLD_MODULE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|MPLOCKED
value|"lock ; "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MPLOCKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The assembly is volatilized to demark potential before-and-after side  * effects if an interrupt or SMP collision were to occur.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_ASM
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|OP
parameter_list|,
name|V
parameter_list|)
define|\
value|static __inline void					\ atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(MPLOCKED OP			\ 			 : "+m" (*p)			\ 			 : "ir" (V));			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLD_MODULE */
end_comment

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|char
argument_list|,
literal|"orb %b1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|char
argument_list|,
literal|"andb %b1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|char
argument_list|,
literal|"addb %b1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|char
argument_list|,
literal|"subb %b1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|short
argument_list|,
literal|"orw %w1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|short
argument_list|,
literal|"andw %w1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|short
argument_list|,
literal|"addw %w1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|short
argument_list|,
literal|"subw %w1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|int
argument_list|,
literal|"orl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|int
argument_list|,
literal|"andl %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|int
argument_list|,
literal|"addl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|int
argument_list|,
literal|"subl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|long
argument_list|,
literal|"orl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|long
argument_list|,
literal|"andl %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|long
argument_list|,
literal|"addl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|long
argument_list|,
literal|"subl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_define
define|#
directive|define
name|atomic_readandclear_32
value|atomic_readandclear_int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WANT_FUNCTIONS
end_ifndef

begin_function
specifier|static
name|__inline
name|u_int
name|atomic_readandclear_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|addr
parameter_list|)
block|{
name|u_int
name|result
decl_stmt|;
asm|__asm __volatile (
literal|"	xorl	%0,%0 ;		"
literal|"	xchgl	%1,%0 ;		"
literal|"# atomic_readandclear_int"
operator|:
literal|"=&r"
operator|(
name|result
operator|)
comment|/* 0 (result) */
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 1 (addr) */
end_comment

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
name|u_long
name|result
decl_stmt|;
asm|__asm __volatile (
literal|"	xorl	%0,%0 ;		"
literal|"	xchgl	%1,%0 ;		"
literal|"# atomic_readandclear_int"
operator|:
literal|"=&r"
operator|(
name|result
operator|)
comment|/* 0 (result) */
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 1 (addr) */
end_comment

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

