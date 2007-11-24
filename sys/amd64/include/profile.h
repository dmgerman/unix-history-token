begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)profile.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROFILE_H_
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

begin_comment
comment|/*  * Config generates something to tell the compiler to align functions on 16  * byte boundaries.  A strict alignment is good for keeping the tables small.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|16
end_define

begin_comment
comment|/*  * The kernel uses assembler stubs instead of unportable inlines.  * This is mainly to save a little time when profiling is not enabled,  * which is the usual case for the kernel.  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_OVERHEAD
parameter_list|(
name|label
parameter_list|)
define|\
value|__asm __volatile("pushq %0; call __mcount; popq %%rcx"		\ 			 :						\ 			 : "i" (profil)					\ 			 : "ax", "dx", "cx", "di", "si", "r8", "r9", "memory")
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT_OVERHEAD
parameter_list|()
define|\
value|__asm __volatile("call .mexitcount; 1:"				\ 			 : :						\ 			 : "ax", "dx", "cx", "di", "si", "r8", "r9", "memory")
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT_OVERHEAD_GETLABEL
parameter_list|(
name|labelp
parameter_list|)
define|\
value|__asm __volatile("movq $1b,%0" : "=rm" (labelp))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|lint
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MCOUNT_OVERHEAD
parameter_list|(
name|label
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT_OVERHEAD
parameter_list|()
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT_OVERHEAD_GETLABEL
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|this file needs to be ported to your compiler
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNUCLIKE_ASM */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !GUPROF */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|u_long s;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|mcount_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{ s = read_rflags(); disable_intr(); \  			  while (!atomic_cmpset_acq_int(&mcount_lock, 0, 1)) \
comment|/* nothing */
value|; }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|{ atomic_store_rel_int(&mcount_lock, 0); \ 			  write_rflags(s); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{ s = read_rflags(); disable_intr(); }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|(write_rflags(s))
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
comment|/* GUPROF */
end_comment

begin_function_decl
name|void
name|bintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|btrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_USER
parameter_list|(
name|pc
parameter_list|)
define|\
value|((pc< (uintfptr_t)VM_MAXUSER_ADDRESS) ? (uintfptr_t)user : pc)
end_define

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_INTR
parameter_list|(
name|pc
parameter_list|)
define|\
value|((pc>= (uintfptr_t)btrap&& pc< (uintfptr_t)eintr) ?	\ 	    ((pc>= (uintfptr_t)bintr) ? (uintfptr_t)bintr :	\ 		(uintfptr_t)btrap) : ~0UL)
end_define

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
name|FUNCTION_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|_MCOUNT_DECL
define|\
value|static void _mcount(uintfptr_t frompc, uintfptr_t selfpc) __used; \ static void _mcount
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
value|__asm("			\n\ 	.globl	.mcount			\n\ 	.type	.mcount @function	\n\ .mcount:				\n\ 	pushq	%rbp			\n\ 	movq	%rsp,%rbp		\n\ 	pushq	%rdi			\n\ 	pushq	%rsi			\n\ 	pushq	%rdx			\n\ 	pushq	%rcx			\n\ 	pushq	%r8			\n\ 	pushq	%r9			\n\ 	pushq	%rax			\n\ 	movq	8(%rbp),%rsi		\n\ 	movq	(%rbp),%rdi		\n\ 	movq	8(%rdi),%rdi		\n\ 	call	_mcount			\n\ 	popq	%rax			\n\ 	popq	%r9			\n\ 	popq	%r8			\n\ 	popq	%rcx			\n\ 	popq	%rdx			\n\ 	popq	%rsi			\n\ 	popq	%rdi			\n\ 	leave				\n\ 	ret				\n\ 	.size	.mcount, . - .mcount");
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * We could use this, except it doesn't preserve the registers that were  * being passed with arguments to the function that we were inserted  * into.  I've left it here as documentation of what the code above is  * supposed to do.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|void									\ mcount()								\ {									\ 	uintfptr_t selfpc, frompc;					\
comment|/*								\ 	 * Find the return address for mcount,				\ 	 * and the return address for mcount's caller.			\ 	 *								\ 	 * selfpc = pc pushed by call to mcount				\ 	 */
value|\ 	__asm("movq 8(%%rbp),%0" : "=r" (selfpc));			\
comment|/*								\ 	 * frompc = pc pushed by call to mcount's caller.		\ 	 * The caller's stack frame has already been built, so %rbp is	\ 	 * the caller's frame pointer.  The caller's raddr is in the	\ 	 * caller's frame following the caller's caller's frame pointer.\ 	 */
value|\ 	__asm("movq (%%rbp),%0" : "=r" (frompc));			\ 	frompc = ((uintfptr_t *)frompc)[1];				\ 	_mcount(frompc, selfpc);					\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUCLIKE_ASM */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|void									\ mcount()								\ {									\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE_ASM */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|uintfptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * An unsigned integral type that can hold non-negative difference between  * function pointers.  */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|fptrdiff_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|mcount
parameter_list|(
name|uintfptr_t
name|frompc
parameter_list|,
name|uintfptr_t
name|selfpc
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
name|void
name|mcount
argument_list|(
name|void
argument_list|)
asm|__asm(".mcount");
endif|#
directive|endif
name|__END_DECLS
end_decl_stmt

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
comment|/* !_MACHINE_PROFILE_H_ */
end_comment

end_unit

