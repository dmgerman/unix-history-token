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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__OFFSETOF_MONITORBUF
end_ifndef

begin_comment
comment|/*  * __OFFSETOF_MONITORBUF == __pcpu_offset(pc_monitorbuf).  *  * The open-coded number is used instead of the symbolic expression to  * avoid a dependency on sys/pcpu.h in machine/atomic.h consumers.  * An assertion in i386/vm_machdep.c ensures that the value is correct.  */
end_comment

begin_define
define|#
directive|define
name|__OFFSETOF_MONITORBUF
value|0x80
end_define

begin_function
specifier|static
name|__inline
name|void
name|__mbk
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("lock; addl $0,%%fs:%0"
block|:
literal|"+m"
operator|(
operator|*
operator|(
name|u_int
operator|*
operator|)
name|__OFFSETOF_MONITORBUF
operator|)
operator|:
operator|:
literal|"memory"
operator|,
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|__mbu
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("lock; addl $0,(%%esp)" : : : "memory", "cc");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Various simple operations on memory, each of which is atomic in the  * presence of interrupts and multiple processors.  *  * atomic_set_char(P, V)	(*(u_char *)(P) |= (V))  * atomic_clear_char(P, V)	(*(u_char *)(P)&= ~(V))  * atomic_add_char(P, V)	(*(u_char *)(P) += (V))  * atomic_subtract_char(P, V)	(*(u_char *)(P) -= (V))  *  * atomic_set_short(P, V)	(*(u_short *)(P) |= (V))  * atomic_clear_short(P, V)	(*(u_short *)(P)&= ~(V))  * atomic_add_short(P, V)	(*(u_short *)(P) += (V))  * atomic_subtract_short(P, V)	(*(u_short *)(P) -= (V))  *  * atomic_set_int(P, V)		(*(u_int *)(P) |= (V))  * atomic_clear_int(P, V)	(*(u_int *)(P)&= ~(V))  * atomic_add_int(P, V)		(*(u_int *)(P) += (V))  * atomic_subtract_int(P, V)	(*(u_int *)(P) -= (V))  * atomic_swap_int(P, V)	(return (*(u_int *)(P)); *(u_int *)(P) = (V);)  * atomic_readandclear_int(P)	(return (*(u_int *)(P)); *(u_int *)(P) = 0;)  *  * atomic_set_long(P, V)	(*(u_long *)(P) |= (V))  * atomic_clear_long(P, V)	(*(u_long *)(P)&= ~(V))  * atomic_add_long(P, V)	(*(u_long *)(P) += (V))  * atomic_subtract_long(P, V)	(*(u_long *)(P) -= (V))  * atomic_swap_long(P, V)	(return (*(u_long *)(P)); *(u_long *)(P) = (V);)  * atomic_readandclear_long(P)	(return (*(u_long *)(P)); *(u_long *)(P) = 0;)  */
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
value|void atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v);	\ void atomic_##NAME##_barr_##TYPE(volatile u_##TYPE *p, u_##TYPE v)
end_define

begin_function_decl
name|int
name|atomic_cmpset_char
parameter_list|(
specifier|volatile
name|u_char
modifier|*
name|dst
parameter_list|,
name|u_char
name|expect
parameter_list|,
name|u_char
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atomic_cmpset_short
parameter_list|(
specifier|volatile
name|u_short
modifier|*
name|dst
parameter_list|,
name|u_short
name|expect
parameter_list|,
name|u_short
name|src
parameter_list|)
function_decl|;
end_function_decl

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
name|expect
parameter_list|,
name|u_int
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atomic_fcmpset_char
parameter_list|(
specifier|volatile
name|u_char
modifier|*
name|dst
parameter_list|,
name|u_char
modifier|*
name|expect
parameter_list|,
name|u_char
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atomic_fcmpset_short
parameter_list|(
specifier|volatile
name|u_short
modifier|*
name|dst
parameter_list|,
name|u_short
modifier|*
name|expect
parameter_list|,
name|u_short
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atomic_fcmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
modifier|*
name|expect
parameter_list|,
name|u_int
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

begin_function_decl
name|int
name|atomic_testandset_int
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

begin_function_decl
name|int
name|atomic_testandclear_int
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

begin_function_decl
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_thread_fence_acq_rel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_thread_fence_rel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_thread_fence_seq_cst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ATOMIC_LOAD
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|u_##TYPE	atomic_load_acq_##TYPE(volatile u_##TYPE *p)
end_define

begin_define
define|#
directive|define
name|ATOMIC_STORE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|void		atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)
end_define

begin_function_decl
name|int
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_load_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_store_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KLD_MODULE&& __GNUCLIKE_ASM */
end_comment

begin_comment
comment|/*  * For userland, always use lock prefixes so that the binaries will run  * on both SMP and !SMP systems.  */
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
comment|/*  * The assembly is volatilized to avoid code chunk removal by the compiler.  * GCC aggressively reorders operations and memory clobbering is necessary  * in order to avoid that for memory barriers.  */
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
value|static __inline void					\ atomic_##NAME##_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(MPLOCKED OP			\ 	: "+m" (*p)					\ 	: CONS (V)					\ 	: "cc");					\ }							\ 							\ static __inline void					\ atomic_##NAME##_barr_##TYPE(volatile u_##TYPE *p, u_##TYPE v)\ {							\ 	__asm __volatile(MPLOCKED OP			\ 	: "+m" (*p)					\ 	: CONS (V)					\ 	: "memory", "cc");				\ }							\ struct __hack
end_define

begin_comment
comment|/*  * Atomic compare and set, used by the mutex functions.  *  * cmpset:  *	if (*dst == expect)  *		*dst = src  *  * fcmpset:  *	if (*dst == *expect)  *		*dst = src  *	else  *		*expect = *dst  *  * Returns 0 on failure, non-zero on success.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_CMPSET
parameter_list|(
name|TYPE
parameter_list|,
name|CONS
parameter_list|)
define|\
value|static __inline int					\ atomic_cmpset_##TYPE(volatile u_##TYPE *dst, u_##TYPE expect, u_##TYPE src) \ {							\ 	u_char res;					\ 							\ 	__asm __volatile(				\ 	"	" MPLOCKED "		"		\ 	"	cmpxchg	%3,%1 ;		"		\ 	"	sete	%0 ;		"		\ 	"# atomic_cmpset_" #TYPE "	"		\ 	: "=q" (res),
comment|/* 0 */
value|\ 	  "+m" (*dst),
comment|/* 1 */
value|\ 	  "+a" (expect)
comment|/* 2 */
value|\ 	: CONS (src)
comment|/* 3 */
value|\ 	: "memory", "cc");				\ 	return (res);					\ }							\ 							\ static __inline int					\ atomic_fcmpset_##TYPE(volatile u_##TYPE *dst, u_##TYPE *expect, u_##TYPE src) \ {							\ 	u_char res;					\ 							\ 	__asm __volatile(				\ 	"	" MPLOCKED "		"		\ 	"	cmpxchg	%3,%1 ;		"		\ 	"	sete	%0 ;		"		\ 	"# atomic_fcmpset_" #TYPE "	"		\ 	: "=q" (res),
comment|/* 0 */
value|\ 	  "+m" (*dst),
comment|/* 1 */
value|\ 	  "+a" (*expect)
comment|/* 2 */
value|\ 	: CONS (src)
comment|/* 3 */
value|\ 	: "memory", "cc");				\ 	return (res);					\ }
end_define

begin_expr_stmt
name|ATOMIC_CMPSET
argument_list|(
name|char
argument_list|,
literal|"q"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_CMPSET
argument_list|(
name|short
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_CMPSET
argument_list|(
name|int
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Atomically add the value of v to the integer pointed to by p and return  * the previous value of *p.  */
end_comment

begin_function
specifier|static
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
asm|__asm __volatile(
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	xaddl	%0,%1 ;		"
literal|"# atomic_fetchadd_int"
operator|:
literal|"+r"
operator|(
name|v
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
comment|/* 1 */
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|atomic_testandset_int
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
name|u_char
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	btsl	%2,%1 ;		"
literal|"	setc	%0 ;		"
literal|"# atomic_testandset_int"
operator|:
literal|"=q"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
comment|/* 1 */
operator|:
literal|"Ir"
operator|(
name|v
operator|&
literal|0x1f
operator|)
comment|/* 2 */
operator|:
literal|"cc"
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
name|atomic_testandclear_int
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
name|u_char
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	btrl	%2,%1 ;		"
literal|"	setc	%0 ;		"
literal|"# atomic_testandclear_int"
operator|:
literal|"=q"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
comment|/* 1 */
operator|:
literal|"Ir"
operator|(
name|v
operator|&
literal|0x1f
operator|)
comment|/* 2 */
operator|:
literal|"cc"
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
comment|/*  * We assume that a = b will do atomic loads and stores.  Due to the  * IA32 memory model, a simple store guarantees release semantics.  *  * However, a load may pass a store if they are performed on distinct  * addresses, so we need Store/Load barrier for sequentially  * consistent fences in SMP kernels.  We use "lock addl $0,mem" for a  * Store/Load barrier, as recommended by the AMD Software Optimization  * Guide, and not mfence.  In the kernel, we use a private per-cpu  * cache line for "mem", to avoid introducing false data  * dependencies.  In user space, we use the word at the top of the  * stack.  *  * For UP kernels, however, the memory of the single processor is  * always consistent, so we only need to stop the compiler from  * reordering accesses in a way that violates the semantics of acquire  * and release.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

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
name|__storeload_barrier
parameter_list|()
value|__mbk()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL&& UP */
end_comment

begin_define
define|#
directive|define
name|__storeload_barrier
parameter_list|()
value|__compiler_membar()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|__storeload_barrier
parameter_list|()
value|__mbu()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL*/
end_comment

begin_define
define|#
directive|define
name|ATOMIC_LOAD
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|static __inline u_##TYPE					\ atomic_load_acq_##TYPE(volatile u_##TYPE *p)			\ {								\ 	u_##TYPE res;						\ 								\ 	res = *p;						\ 	__compiler_membar();					\ 	return (res);						\ }								\ struct __hack
end_define

begin_define
define|#
directive|define
name|ATOMIC_STORE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|static __inline void						\ atomic_store_rel_##TYPE(volatile u_##TYPE *p, u_##TYPE v)	\ {								\ 								\ 	__compiler_membar();					\ 	*p = v;							\ }								\ struct __hack
end_define

begin_function
unit|static
name|__inline
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
block|{
name|__compiler_membar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|__compiler_membar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_acq_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|__compiler_membar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_seq_cst
parameter_list|(
name|void
parameter_list|)
block|{
name|__storeload_barrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_FUNCTIONS
end_ifdef

begin_function_decl
name|int
name|atomic_cmpset_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atomic_cmpset_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_load_acq_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_load_acq_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_store_rel_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_store_rel_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_swap_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|atomic_swap_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I486 does not support SMP or CMPXCHG8B. */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|dst
parameter_list|,
name|uint64_t
name|expect
parameter_list|,
name|uint64_t
name|src
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|p
decl_stmt|;
name|u_char
name|res
decl_stmt|;
name|p
operator|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|dst
expr_stmt|;
asm|__asm __volatile(
literal|"	pushfl ;		"
literal|"	cli ;			"
literal|"	xorl	%1,%%eax ;	"
literal|"	xorl	%2,%%edx ;	"
literal|"	orl	%%edx,%%eax ;	"
literal|"	jne	1f ;		"
literal|"	movl	%4,%1 ;		"
literal|"	movl	%5,%2 ;		"
literal|"1:				"
literal|"	sete	%3 ;		"
literal|"	popfl"
operator|:
literal|"+A"
operator|(
name|expect
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
operator|,
comment|/* 1 */
literal|"+m"
operator|(
operator|*
operator|(
name|p
operator|+
literal|1
operator|)
operator|)
operator|,
comment|/* 2 */
literal|"=q"
operator|(
name|res
operator|)
comment|/* 3 */
operator|:
literal|"r"
operator|(
operator|(
name|uint32_t
operator|)
name|src
operator|)
operator|,
comment|/* 4 */
literal|"r"
operator|(
call|(
name|uint32_t
call|)
argument_list|(
name|src
operator|>>
literal|32
argument_list|)
operator|)
comment|/* 5 */
operator|:
literal|"memory"
operator|,
literal|"cc"
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
name|uint64_t
name|atomic_load_acq_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|q
decl_stmt|;
name|uint64_t
name|res
decl_stmt|;
name|q
operator|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
expr_stmt|;
asm|__asm __volatile(
literal|"	pushfl ;		"
literal|"	cli ;			"
literal|"	movl	%1,%%eax ;	"
literal|"	movl	%2,%%edx ;	"
literal|"	popfl"
operator|:
literal|"=&A"
operator|(
name|res
operator|)
comment|/* 0 */
operator|:
literal|"m"
operator|(
operator|*
name|q
operator|)
operator|,
comment|/* 1 */
literal|"m"
operator|(
operator|*
operator|(
name|q
operator|+
literal|1
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

begin_function
unit|}  static
name|__inline
name|void
name|atomic_store_rel_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|q
decl_stmt|;
name|q
operator|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
expr_stmt|;
asm|__asm __volatile(
literal|"	pushfl ;		"
literal|"	cli ;			"
literal|"	movl	%%eax,%0 ;	"
literal|"	movl	%%edx,%1 ;	"
literal|"	popfl"
operator|:
literal|"=m"
operator|(
operator|*
name|q
operator|)
operator|,
comment|/* 0 */
literal|"=m"
operator|(
operator|*
operator|(
name|q
operator|+
literal|1
operator|)
operator|)
comment|/* 1 */
operator|:
literal|"A"
operator|(
name|v
operator|)
comment|/* 2 */
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64_i386
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|q
decl_stmt|;
name|uint64_t
name|res
decl_stmt|;
name|q
operator|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
expr_stmt|;
asm|__asm __volatile(
literal|"	pushfl ;		"
literal|"	cli ;			"
literal|"	movl	%1,%%eax ;	"
literal|"	movl	%2,%%edx ;	"
literal|"	movl	%4,%2 ;		"
literal|"	movl	%3,%1 ;		"
literal|"	popfl"
operator|:
literal|"=&A"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|q
operator|)
operator|,
comment|/* 1 */
literal|"+m"
operator|(
operator|*
operator|(
name|q
operator|+
literal|1
operator|)
operator|)
comment|/* 2 */
operator|:
literal|"r"
operator|(
operator|(
name|uint32_t
operator|)
name|v
operator|)
operator|,
comment|/* 3 */
literal|"r"
operator|(
call|(
name|uint32_t
call|)
argument_list|(
name|v
operator|>>
literal|32
argument_list|)
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 4 */
end_comment

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
name|atomic_cmpset_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|dst
parameter_list|,
name|uint64_t
name|expect
parameter_list|,
name|uint64_t
name|src
parameter_list|)
block|{
name|u_char
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchg8b %1 ;		"
literal|"	sete	%0"
operator|:
literal|"=q"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|dst
operator|)
operator|,
comment|/* 1 */
literal|"+A"
operator|(
name|expect
operator|)
comment|/* 2 */
operator|:
literal|"b"
operator|(
operator|(
name|uint32_t
operator|)
name|src
operator|)
operator|,
comment|/* 3 */
literal|"c"
operator|(
call|(
name|uint32_t
call|)
argument_list|(
name|src
operator|>>
literal|32
argument_list|)
operator|)
comment|/* 4 */
operator|:
literal|"memory"
operator|,
literal|"cc"
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
name|uint64_t
name|atomic_load_acq_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"	movl	%%ebx,%%eax ;	"
literal|"	movl	%%ecx,%%edx ;	"
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchg8b %1"
operator|:
literal|"=&A"
operator|(
name|res
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
comment|/* 1 */
operator|:
operator|:
literal|"memory"
operator|,
literal|"cc"
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
name|void
name|atomic_store_rel_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
asm|__asm __volatile(
literal|"	movl	%%eax,%%ebx ;	"
literal|"	movl	%%edx,%%ecx ;	"
literal|"1:				"
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchg8b %0 ;		"
literal|"	jne	1b"
operator|:
literal|"+m"
operator|(
operator|*
name|p
operator|)
operator|,
comment|/* 0 */
literal|"+A"
operator|(
name|v
operator|)
comment|/* 1 */
operator|:
operator|:
literal|"ebx"
operator|,
literal|"ecx"
operator|,
literal|"memory"
operator|,
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64_i586
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
asm|__asm __volatile(
literal|"	movl	%%eax,%%ebx ;	"
literal|"	movl	%%edx,%%ecx ;	"
literal|"1:				"
literal|"	"
name|MPLOCKED
literal|"		"
literal|"	cmpxchg8b %0 ;		"
literal|"	jne	1b"
operator|:
literal|"+m"
operator|(
operator|*
name|p
operator|)
operator|,
comment|/* 0 */
literal|"+A"
operator|(
name|v
operator|)
comment|/* 1 */
operator|:
operator|:
literal|"ebx"
operator|,
literal|"ecx"
operator|,
literal|"memory"
operator|,
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|dst
parameter_list|,
name|uint64_t
name|expect
parameter_list|,
name|uint64_t
name|src
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CX8
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|atomic_cmpset_64_i386
argument_list|(
name|dst
argument_list|,
name|expect
argument_list|,
name|src
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|atomic_cmpset_64_i586
argument_list|(
name|dst
argument_list|,
name|expect
argument_list|,
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_load_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CX8
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|atomic_load_acq_64_i386
argument_list|(
name|p
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|atomic_load_acq_64_i586
argument_list|(
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CX8
operator|)
operator|==
literal|0
condition|)
name|atomic_store_rel_64_i386
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
else|else
name|atomic_store_rel_64_i586
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CX8
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|atomic_swap_64_i386
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|atomic_swap_64_i586
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLD_MODULE || !__GNUCLIKE_ASM */
end_comment

begin_expr_stmt
name|ATOMIC_ASM
argument_list|(
name|set
argument_list|,
name|char
argument_list|,
literal|"orb %b1,%0"
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
name|long
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
name|long
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
name|long
argument_list|,
literal|"subl %1,%0"
argument_list|,
literal|"ir"
argument_list|,
name|v
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ATOMIC_LOADSTORE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|ATOMIC_LOAD(TYPE);				\ 	ATOMIC_STORE(TYPE)
end_define

begin_expr_stmt
name|ATOMIC_LOADSTORE
argument_list|(
name|char
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_LOADSTORE
argument_list|(
name|short
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_LOADSTORE
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ATOMIC_LOADSTORE
argument_list|(
name|long
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
name|ATOMIC_LOAD
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_STORE
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_LOADSTORE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|WANT_FUNCTIONS
end_ifndef

begin_function
specifier|static
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
name|expect
parameter_list|,
name|u_long
name|src
parameter_list|)
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
name|expect
argument_list|,
operator|(
name|u_int
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|atomic_fetchadd_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_fetchadd_int
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
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_testandset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_testandset_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_testandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_testandclear_int
argument_list|(
operator|(
specifier|volatile
name|u_int
operator|*
operator|)
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Read the current value and store a new value in the destination. */
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
name|atomic_swap_int
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
asm|__asm __volatile(
literal|"	xchgl	%1,%0 ;		"
literal|"# atomic_swap_int"
operator|:
literal|"+r"
operator|(
name|v
operator|)
operator|,
comment|/* 0 */
literal|"+m"
operator|(
operator|*
name|p
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 1 */
end_comment

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|u_long
name|atomic_swap_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_swap_int
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
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUCLIKE_ASM */
end_comment

begin_function_decl
name|u_int
name|atomic_swap_int
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

begin_function_decl
name|u_long
name|atomic_swap_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
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

begin_define
define|#
directive|define
name|atomic_set_acq_char
value|atomic_set_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_char
value|atomic_set_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_char
value|atomic_clear_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_char
value|atomic_clear_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_char
value|atomic_add_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_char
value|atomic_add_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_char
value|atomic_subtract_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_char
value|atomic_subtract_barr_char
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_char
value|atomic_cmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_char
value|atomic_cmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_char
value|atomic_fcmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_char
value|atomic_fcmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_short
value|atomic_set_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_short
value|atomic_set_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_short
value|atomic_clear_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_short
value|atomic_clear_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_short
value|atomic_add_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_short
value|atomic_add_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_short
value|atomic_subtract_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_short
value|atomic_subtract_barr_short
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_short
value|atomic_cmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_short
value|atomic_cmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_short
value|atomic_fcmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_short
value|atomic_fcmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_barr_int
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_barr_int
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
name|atomic_fcmpset_acq_int
value|atomic_fcmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_int
value|atomic_fcmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_barr_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_barr_long
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

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_long
value|atomic_fcmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_long
value|atomic_fcmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
parameter_list|(
name|p
parameter_list|)
value|atomic_swap_int(p, 0)
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
parameter_list|(
name|p
parameter_list|)
value|atomic_swap_long(p, 0)
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

begin_define
define|#
directive|define
name|atomic_cmpset_8
value|atomic_cmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_8
value|atomic_cmpset_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_8
value|atomic_cmpset_rel_char
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_8
value|atomic_fcmpset_char
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_8
value|atomic_fcmpset_acq_char
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_8
value|atomic_fcmpset_rel_char
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

begin_define
define|#
directive|define
name|atomic_cmpset_16
value|atomic_cmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_16
value|atomic_cmpset_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_16
value|atomic_cmpset_rel_short
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_16
value|atomic_fcmpset_short
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_16
value|atomic_fcmpset_acq_short
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_16
value|atomic_fcmpset_rel_short
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
name|atomic_fcmpset_32
value|atomic_fcmpset_int
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_32
value|atomic_fcmpset_acq_int
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_32
value|atomic_fcmpset_rel_int
end_define

begin_define
define|#
directive|define
name|atomic_swap_32
value|atomic_swap_int
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

begin_define
define|#
directive|define
name|atomic_testandset_32
value|atomic_testandset_int
end_define

begin_define
define|#
directive|define
name|atomic_testandclear_32
value|atomic_testandclear_int
end_define

begin_comment
comment|/* Operations on pointers. */
end_comment

begin_define
define|#
directive|define
name|atomic_set_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_set_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_set_acq_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_set_rel_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_clear_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_clear_acq_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_clear_rel_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_add_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_add_acq_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_add_rel_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_subtract_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_subtract_acq_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_subtract_rel_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
parameter_list|(
name|p
parameter_list|)
define|\
value|atomic_load_acq_int((volatile u_int *)(p))
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_store_rel_int((volatile u_int *)(p), (v))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_int((volatile u_int *)(dst), (u_int)(old), (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_acq_int((volatile u_int *)(dst), (u_int)(old), \ 	    (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_cmpset_rel_int((volatile u_int *)(dst), (u_int)(old), \ 	    (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_fcmpset_int((volatile u_int *)(dst), (u_int *)(old), (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_fcmpset_acq_int((volatile u_int *)(dst), (u_int *)(old), \ 	    (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_ptr
parameter_list|(
name|dst
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|)
define|\
value|atomic_fcmpset_rel_int((volatile u_int *)(dst), (u_int *)(old), \ 	    (u_int)(new))
end_define

begin_define
define|#
directive|define
name|atomic_swap_ptr
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|atomic_swap_int((volatile u_int *)(p), (u_int)(v))
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
parameter_list|(
name|p
parameter_list|)
define|\
value|atomic_readandclear_int((volatile u_int *)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WANT_FUNCTIONS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__mbk()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__mbk()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__mbk()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__mbu()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__mbu()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__mbu()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ATOMIC_H_ */
end_comment

end_unit

