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
name|CONS
parameter_list|,
name|V
parameter_list|)
define|\
value|void atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v);
end_define

begin_function_decl
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
name|exp
parameter_list|,
name|u_int
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|,
name|LOP
parameter_list|,
name|SOP
parameter_list|)
define|\
value|u_##TYPE	atomic_load_acq_##TYPE(volatile u_##TYPE *p);	\ void		atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KLD_MODULE */
end_comment

begin_comment
comment|/*  * For userland, assume the SMP case and use lock prefixes so that  * the binaries will run on both types of systems.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
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
name|CONS
parameter_list|,
name|V
parameter_list|)
define|\
value|static __inline void					\ atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(MPLOCKED OP			\ 			 : "+m" (*p)			\ 			 : CONS (V));			\ }
end_define

begin_comment
comment|/*  * Atomic compare and set, used by the mutex functions  *  * if (*dst == exp) *dst = src (all 32 bit words)  *  * Returns 0 on failure, non-zero on success  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I386_CPU
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
name|exp
parameter_list|,
name|u_int
name|src
parameter_list|)
block|{
name|int
name|res
init|=
name|exp
decl_stmt|;
asm|__asm __volatile(
literal|"	pushfl ;		"
literal|"	cli ;			"
literal|"	cmpl	%0,%2 ;		"
literal|"	jne	1f ;		"
literal|"	movl	%1,%2 ;		"
literal|"1:				"
literal|"       sete	%%al;		"
literal|"	movzbl	%%al,%0 ;	"
literal|"	popfl ;			"
literal|"# atomic_cmpset_int"
operator|:
literal|"+a"
operator|(
name|res
operator|)
comment|/* 0 (result) */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 1 */
literal|"m"
operator|(
operator|*
operator|(
name|dst
operator|)
operator|)
comment|/* 2 */
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* defined(I386_CPU) */
end_comment

begin_function
unit|static
name|__inline
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
name|exp
parameter_list|,
name|u_int
name|src
parameter_list|)
block|{
name|int
name|res
init|=
name|exp
decl_stmt|;
asm|__asm __volatile (
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchgl %1,%2 ;	"
literal|"       setz	%%al ;		"
literal|"	movzbl	%%al,%0 ;	"
literal|"1:				"
literal|"# atomic_cmpset_int"
operator|:
literal|"+a"
operator|(
name|res
operator|)
comment|/* 0 (result) */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 1 */
literal|"m"
operator|(
operator|*
operator|(
name|dst
operator|)
operator|)
comment|/* 2 */
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(I386_CPU) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I386_CPU
argument_list|)
end_if

begin_comment
comment|/*  * We assume that a = b will do atomic loads and stores.  *  * XXX: This is _NOT_ safe on a P6 or higher because it does not guarantee  * memory ordering.  These should only be used on a 386.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|,
name|LOP
parameter_list|,
name|SOP
parameter_list|)
define|\
value|static __inline u_##TYPE				\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)		\ {							\ 	return (*p);					\ }							\ 							\ static __inline void					\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	*p = v;						\ 	__asm __volatile("" : : : "memory");		\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_STORE_LOAD
parameter_list|(
name|TYPE
parameter_list|,
name|LOP
parameter_list|,
name|SOP
parameter_list|)
define|\
value|static __inline u_##TYPE				\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)		\ {							\ 	u_##TYPE res;					\ 							\ 	__asm __volatile(MPLOCKED LOP			\ 	: "=a" (res),
comment|/* 0 (result) */
value|\ 	  "+m" (*p)
comment|/* 1 */
value|\ 	: : "memory");				 	\ 							\ 	return (res);					\ }							\ 							\
comment|/*							\  * The XCHG instruction asserts LOCK automagically.	\  */
value|\ static __inline void					\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(SOP				\ 	: "+m" (*p),
comment|/* 0 */
value|\ 	  "+r" (v)
comment|/* 1 */
value|\ 	: : "memory");				 	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(I386_CPU) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLD_MODULE */
end_comment

begin_expr_stmt
unit|ATOMIC_ASM
operator|(
name|set
operator|,
name|char
operator|,
literal|"orb %b1,%0"
operator|,
literal|"iq"
operator|,
name|v
operator|)
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|char
argument_list|,
literal|"andb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
argument|~v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|char
argument_list|,
literal|"addb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|char
argument_list|,
literal|"subb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|short
argument_list|,
literal|"orw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|short
argument_list|,
literal|"andw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|~v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|short
argument_list|,
literal|"addw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|short
argument_list|,
literal|"subw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|int
argument_list|,
literal|"orl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|int
argument_list|,
literal|"andl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|~v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|int
argument_list|,
literal|"addl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|int
argument_list|,
literal|"subl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|set
argument_list|,
argument|long
argument_list|,
literal|"orl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|clear
argument_list|,
argument|long
argument_list|,
literal|"andl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|~v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|add
argument_list|,
argument|long
argument_list|,
literal|"addl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_ASM
argument_list|(
argument|subtract
argument_list|,
argument|long
argument_list|,
literal|"subl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
argument|v
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|char
argument_list|,
literal|"cmpxchgb %b0,%1"
argument_list|,
literal|"xchgb %b1,%0"
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|short
argument_list|,
literal|"cmpxchgw %w0,%1"
argument_list|,
literal|"xchgw %w1,%0"
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|int
argument_list|,
literal|"cmpxchgl %0,%1"
argument_list|,
literal|"xchgl %1,%0"
argument_list|)
name|ATOMIC_STORE_LOAD
argument_list|(
argument|long
argument_list|,
literal|"cmpxchgl %0,%1"
argument_list|,
literal|"xchgl %1,%0"
argument_list|)
undef|#
directive|undef
name|ATOMIC_ASM
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
define|#
directive|define
name|atomic_set_acq_char
value|atomic_set_char
define|#
directive|define
name|atomic_set_rel_char
value|atomic_set_char
define|#
directive|define
name|atomic_clear_acq_char
value|atomic_clear_char
define|#
directive|define
name|atomic_clear_rel_char
value|atomic_clear_char
define|#
directive|define
name|atomic_add_acq_char
value|atomic_add_char
define|#
directive|define
name|atomic_add_rel_char
value|atomic_add_char
define|#
directive|define
name|atomic_subtract_acq_char
value|atomic_subtract_char
define|#
directive|define
name|atomic_subtract_rel_char
value|atomic_subtract_char
define|#
directive|define
name|atomic_set_acq_short
value|atomic_set_short
define|#
directive|define
name|atomic_set_rel_short
value|atomic_set_short
define|#
directive|define
name|atomic_clear_acq_short
value|atomic_clear_short
define|#
directive|define
name|atomic_clear_rel_short
value|atomic_clear_short
define|#
directive|define
name|atomic_add_acq_short
value|atomic_add_short
define|#
directive|define
name|atomic_add_rel_short
value|atomic_add_short
define|#
directive|define
name|atomic_subtract_acq_short
value|atomic_subtract_short
define|#
directive|define
name|atomic_subtract_rel_short
value|atomic_subtract_short
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_int
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_int
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_int
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_int
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_int
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_int
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_int
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_int
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_int
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_int
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_long
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_long
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_long
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_long
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_long
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_long
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_long
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_long
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_int
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_int
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_int
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_ptr
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_ptr
define|#
directive|define
name|atomic_set_8
value|atomic_set_char
define|#
directive|define
name|atomic_set_acq_8
value|atomic_set_acq_char
define|#
directive|define
name|atomic_set_rel_8
value|atomic_set_rel_char
define|#
directive|define
name|atomic_clear_8
value|atomic_clear_char
define|#
directive|define
name|atomic_clear_acq_8
value|atomic_clear_acq_char
define|#
directive|define
name|atomic_clear_rel_8
value|atomic_clear_rel_char
define|#
directive|define
name|atomic_add_8
value|atomic_add_char
define|#
directive|define
name|atomic_add_acq_8
value|atomic_add_acq_char
define|#
directive|define
name|atomic_add_rel_8
value|atomic_add_rel_char
define|#
directive|define
name|atomic_subtract_8
value|atomic_subtract_char
define|#
directive|define
name|atomic_subtract_acq_8
value|atomic_subtract_acq_char
define|#
directive|define
name|atomic_subtract_rel_8
value|atomic_subtract_rel_char
define|#
directive|define
name|atomic_load_acq_8
value|atomic_load_acq_char
define|#
directive|define
name|atomic_store_rel_8
value|atomic_store_rel_char
define|#
directive|define
name|atomic_set_16
value|atomic_set_short
define|#
directive|define
name|atomic_set_acq_16
value|atomic_set_acq_short
define|#
directive|define
name|atomic_set_rel_16
value|atomic_set_rel_short
define|#
directive|define
name|atomic_clear_16
value|atomic_clear_short
define|#
directive|define
name|atomic_clear_acq_16
value|atomic_clear_acq_short
define|#
directive|define
name|atomic_clear_rel_16
value|atomic_clear_rel_short
define|#
directive|define
name|atomic_add_16
value|atomic_add_short
define|#
directive|define
name|atomic_add_acq_16
value|atomic_add_acq_short
define|#
directive|define
name|atomic_add_rel_16
value|atomic_add_rel_short
define|#
directive|define
name|atomic_subtract_16
value|atomic_subtract_short
define|#
directive|define
name|atomic_subtract_acq_16
value|atomic_subtract_acq_short
define|#
directive|define
name|atomic_subtract_rel_16
value|atomic_subtract_rel_short
define|#
directive|define
name|atomic_load_acq_16
value|atomic_load_acq_short
define|#
directive|define
name|atomic_store_rel_16
value|atomic_store_rel_short
define|#
directive|define
name|atomic_set_32
value|atomic_set_int
define|#
directive|define
name|atomic_set_acq_32
value|atomic_set_acq_int
define|#
directive|define
name|atomic_set_rel_32
value|atomic_set_rel_int
define|#
directive|define
name|atomic_clear_32
value|atomic_clear_int
define|#
directive|define
name|atomic_clear_acq_32
value|atomic_clear_acq_int
define|#
directive|define
name|atomic_clear_rel_32
value|atomic_clear_rel_int
define|#
directive|define
name|atomic_add_32
value|atomic_add_int
define|#
directive|define
name|atomic_add_acq_32
value|atomic_add_acq_int
define|#
directive|define
name|atomic_add_rel_32
value|atomic_add_rel_int
define|#
directive|define
name|atomic_subtract_32
value|atomic_subtract_int
define|#
directive|define
name|atomic_subtract_acq_32
value|atomic_subtract_acq_int
define|#
directive|define
name|atomic_subtract_rel_32
value|atomic_subtract_rel_int
define|#
directive|define
name|atomic_load_acq_32
value|atomic_load_acq_int
define|#
directive|define
name|atomic_store_rel_32
value|atomic_store_rel_int
define|#
directive|define
name|atomic_cmpset_32
value|atomic_cmpset_int
define|#
directive|define
name|atomic_cmpset_acq_32
value|atomic_cmpset_acq_int
define|#
directive|define
name|atomic_cmpset_rel_32
value|atomic_cmpset_rel_int
define|#
directive|define
name|atomic_readandclear_32
value|atomic_readandclear_int
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WANT_FUNCTIONS
argument_list|)
specifier|static
name|__inline
name|int
name|atomic_cmpset_ptr
argument_list|(
argument|volatile void *dst
argument_list|,
argument|void *exp
argument_list|,
argument|void *src
argument_list|)
block|{
return|return
operator|(
name|atomic_cmpset_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|dst
argument_list|,
operator|(
name|u_int
operator|)
name|exp
argument_list|,
operator|(
name|u_int
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|atomic_load_acq_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|atomic_load_acq_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|p
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|v
parameter_list|)
block|{
name|atomic_store_rel_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|p
argument_list|,
operator|(
name|u_int
operator|)
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ATOMIC_PTR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static __inline void					\ atomic_##NAME##_ptr(volatile void *p, uintptr_t v)	\ {							\ 	atomic_##NAME##_int((volatile u_int *)p, v);	\ }							\ 							\ static __inline void					\ atomic_##NAME##_acq_ptr(volatile void *p, uintptr_t v)	\ {							\ 	atomic_##NAME##_acq_int((volatile u_int *)p, v);\ }							\ 							\ static __inline void					\ atomic_##NAME##_rel_ptr(volatile void *p, uintptr_t v)	\ {							\ 	atomic_##NAME##_rel_int((volatile u_int *)p, v);\ }
end_define

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|set
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|clear
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|add
argument_list|)
end_macro

begin_macro
name|ATOMIC_PTR
argument_list|(
argument|subtract
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|ATOMIC_PTR
end_undef

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

begin_comment
comment|/* !defined(WANT_FUNCTIONS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

