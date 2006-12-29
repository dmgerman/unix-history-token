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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

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
operator|||
operator|!
name|defined
argument_list|(
name|__GNUCLIKE_ASM
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
value|void atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v)
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

begin_function_decl
name|int
name|atomic_cmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
name|exp
parameter_list|,
name|u_long
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|atomic_fetchadd_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|v
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
value|u_##TYPE	atomic_load_acq_##TYPE(volatile u_##TYPE *p);	\ void		atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KLD_MODULE&& __GNUCLIKE_ASM */
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
value|static __inline void					\ atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(MPLOCKED OP			\ 			 : "=m" (*p)			\ 			 : CONS (V), "m" (*p));		\ }							\ struct __hack
end_define

begin_comment
comment|/*  * Atomic compare and set, used by the mutex functions  *  * if (*dst == exp) *dst = src (all 32 bit words)  *  * Returns 0 on failure, non-zero on success  */
end_comment

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
name|u_char
name|res
decl_stmt|;
asm|__asm __volatile (
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchgl %2,%1 ;	"
literal|"       sete	%0 ;		"
literal|"1:				"
literal|"# atomic_cmpset_int"
operator|:
literal|"=a"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"=m"
operator|(
operator|*
name|dst
operator|)
comment|/* 1 */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 2 */
literal|"a"
operator|(
name|exp
operator|)
operator|,
comment|/* 3 */
literal|"m"
operator|(
operator|*
name|dst
operator|)
comment|/* 4 */
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

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
name|exp
parameter_list|,
name|u_long
name|src
parameter_list|)
block|{
name|u_char
name|res
decl_stmt|;
asm|__asm __volatile (
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchgq %2,%1 ;	"
literal|"       sete	%0 ;		"
literal|"1:				"
literal|"# atomic_cmpset_long"
operator|:
literal|"=a"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"=m"
operator|(
operator|*
name|dst
operator|)
comment|/* 1 */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 2 */
literal|"a"
operator|(
name|exp
operator|)
operator|,
comment|/* 3 */
literal|"m"
operator|(
operator|*
name|dst
operator|)
comment|/* 4 */
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

begin_comment
unit|}
comment|/*  * Atomically add the value of v to the integer pointed to by p and return  * the previous value of *p.  */
end_comment

begin_function
unit|static
name|__inline
name|u_int
name|atomic_fetchadd_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
asm|__asm __volatile (
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	xaddl	%0, %1 ;	"
literal|"# atomic_fetchadd_int"
operator|:
literal|"+r"
operator|(
name|v
operator|)
operator|,
comment|/* 0 (result) */
literal|"=m"
operator|(
operator|*
name|p
operator|)
comment|/* 1 */
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 2 */
end_comment

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_comment
comment|/*  * We assume that a = b will do atomic loads and stores.  However, on a  * PentiumPro or higher, reads may pass writes, so for that case we have  * to use a serializing instruction (i.e. with LOCK) to do the load in  * SMP kernels.  For UP kernels, however, the cache of the single processor  * is always consistent, so we don't need any memory barriers.  */
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
value|static __inline u_##TYPE				\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)		\ {							\ 	return (*p);					\ }							\ 							\ static __inline void					\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	*p = v;						\ }							\ struct __hack
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(SMP) */
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
value|static __inline u_##TYPE				\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)		\ {							\ 	u_##TYPE res;					\ 							\ 	__asm __volatile(MPLOCKED LOP			\ 	: "=a" (res),
comment|/* 0 (result) */
value|\ 	  "=m" (*p)
comment|/* 1 */
value|\ 	: "m" (*p)
comment|/* 2 */
value|\ 	: "memory");					\ 							\ 	return (res);					\ }							\ 							\
comment|/*							\  * The XCHG instruction asserts LOCK automagically.	\  */
value|\ static __inline void					\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(SOP				\ 	: "=m" (*p),
comment|/* 0 */
value|\ 	  "+r" (v)
comment|/* 1 */
value|\ 	: "m" (*p));
comment|/* 2 */
value|\ }							\ struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLD_MODULE || !__GNUCLIKE_ASM */
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|clear
argument_list|,
name|char
argument_list|,
literal|"andb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
operator|~
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|add
argument_list|,
name|char
argument_list|,
literal|"addb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|subtract
argument_list|,
name|char
argument_list|,
literal|"subb %b1,%0"
argument_list|,
literal|"iq"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|set
argument_list|,
name|short
argument_list|,
literal|"orw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|clear
argument_list|,
name|short
argument_list|,
literal|"andw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
operator|~
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|add
argument_list|,
name|short
argument_list|,
literal|"addw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|subtract
argument_list|,
name|short
argument_list|,
literal|"subw %w1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|set
argument_list|,
name|int
argument_list|,
literal|"orl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|clear
argument_list|,
name|int
argument_list|,
literal|"andl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
operator|~
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|add
argument_list|,
name|int
argument_list|,
literal|"addl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|subtract
argument_list|,
name|int
argument_list|,
literal|"subl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|set
argument_list|,
name|long
argument_list|,
literal|"orq %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|clear
argument_list|,
name|long
argument_list|,
literal|"andq %1,%0"
argument_list|,
literal|"ir"
argument_list|,
operator|~
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|add
argument_list|,
name|long
argument_list|,
literal|"addq %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|subtract
argument_list|,
name|long
argument_list|,
literal|"subq %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_STORE_LOAD
argument_list|(
name|char
argument_list|,
literal|"cmpxchgb %b0,%1"
argument_list|,
literal|"xchgb %b1,%0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_STORE_LOAD
argument_list|(
name|short
argument_list|,
literal|"cmpxchgw %w0,%1"
argument_list|,
literal|"xchgw %w1,%0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_STORE_LOAD
argument_list|(
name|int
argument_list|,
literal|"cmpxchgl %0,%1"
argument_list|,
literal|"xchgl %1,%0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_STORE_LOAD
argument_list|(
name|long
argument_list|,
literal|"cmpxchgq %0,%1"
argument_list|,
literal|"xchgq %1,%0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|ATOMIC_ASM
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_STORE_LOAD
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WANT_FUNCTIONS
argument_list|)
end_if

begin_comment
comment|/* Read the current value and store a zero in the destination. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
end_ifdef

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
name|result
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile (
literal|"	xchgl	%1,%0 ;		"
literal|"# atomic_readandclear_int"
operator|:
literal|"+r"
operator|(
name|result
operator|)
operator|,
comment|/* 0 (result) */
literal|"=m"
operator|(
operator|*
name|addr
operator|)
comment|/* 1 (addr) */
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

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
name|result
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile (
literal|"	xchgq	%1,%0 ;		"
literal|"# atomic_readandclear_long"
operator|:
literal|"+r"
operator|(
name|result
operator|)
operator|,
comment|/* 0 (result) */
literal|"=m"
operator|(
operator|*
name|addr
operator|)
comment|/* 1 (addr) */
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUCLIKE_ASM */
end_comment

begin_expr_stmt
unit|u_int
name|atomic_readandclear_int
argument_list|(
specifier|volatile
name|u_int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE_ASM */
end_comment

begin_comment
comment|/* Acquire and release variants are identical to the normal ones. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_acq_char
value|atomic_set_char
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
value|atomic_set_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
value|atomic_clear_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
value|atomic_clear_char
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
value|atomic_add_char
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
value|atomic_add_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
value|atomic_subtract_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
value|atomic_subtract_char
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
value|atomic_set_short
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
value|atomic_set_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
value|atomic_clear_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
value|atomic_clear_short
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
value|atomic_add_short
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
value|atomic_add_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
value|atomic_subtract_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
value|atomic_subtract_short
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_int
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_int
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_int
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_long
end_define

begin_comment
comment|/* Operations on 8-bit bytes. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_8
value|atomic_set_char
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_8
value|atomic_set_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_8
value|atomic_set_rel_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_8
value|atomic_clear_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_8
value|atomic_clear_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_8
value|atomic_clear_rel_char
end_define

begin_define
define|#
directive|define
name|atomic_add_8
value|atomic_add_char
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_8
value|atomic_add_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_8
value|atomic_add_rel_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_8
value|atomic_subtract_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_8
value|atomic_subtract_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_8
value|atomic_subtract_rel_char
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_8
value|atomic_load_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_8
value|atomic_store_rel_char
end_define

begin_comment
comment|/* Operations on 16-bit words. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_16
value|atomic_set_short
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_16
value|atomic_set_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_16
value|atomic_set_rel_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_16
value|atomic_clear_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_16
value|atomic_clear_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_16
value|atomic_clear_rel_short
end_define

begin_define
define|#
directive|define
name|atomic_add_16
value|atomic_add_short
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_16
value|atomic_add_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_16
value|atomic_add_rel_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_16
value|atomic_subtract_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_16
value|atomic_subtract_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_16
value|atomic_subtract_rel_short
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_16
value|atomic_load_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_16
value|atomic_store_rel_short
end_define

begin_comment
comment|/* Operations on 32-bit double words. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_32
value|atomic_set_int
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_32
value|atomic_set_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_32
value|atomic_set_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_32
value|atomic_clear_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_32
value|atomic_clear_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_32
value|atomic_clear_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_add_32
value|atomic_add_int
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_32
value|atomic_add_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_32
value|atomic_add_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_32
value|atomic_subtract_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_32
value|atomic_subtract_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_32
value|atomic_subtract_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_32
value|atomic_load_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_32
value|atomic_store_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_32
value|atomic_cmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_32
value|atomic_cmpset_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_32
value|atomic_cmpset_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_32
value|atomic_readandclear_int
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_32
value|atomic_fetchadd_int
end_define

begin_comment
comment|/* Operations on 64-bit quad words. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_64
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_64
value|atomic_set_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_64
value|atomic_set_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_64
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_64
value|atomic_clear_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_64
value|atomic_clear_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_add_64
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_64
value|atomic_add_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_64
value|atomic_add_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_64
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_64
value|atomic_subtract_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_64
value|atomic_subtract_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_64
value|atomic_load_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_64
value|atomic_store_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_64
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_64
value|atomic_cmpset_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_64
value|atomic_cmpset_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_64
value|atomic_readandclear_long
end_define

begin_comment
comment|/* Operations on pointers. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_clear_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_long
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_long
end_define

begin_endif
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

