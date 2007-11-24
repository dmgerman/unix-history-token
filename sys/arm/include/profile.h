begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)profile.h	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
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

begin_comment
comment|/*  * Config generates something to tell the compiler to align functions on 32   * byte boundaries.  A strict alignment is good for keeping the tables small.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|16
end_define

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_typedef
typedef|typedef
name|u_long
name|fptrdiff_t
typedef|;
end_typedef

begin_comment
comment|/*  * Cannot implement mcount in C as GCC will trash the ip register when it  * pushes a trapframe. Pity we cannot insert assembly before the function  * prologue.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PLTSYM
end_ifndef

begin_define
define|#
directive|define
name|PLTSYM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|__asm__(".text");						\ 	__asm__(".align	0");						\ 	__asm__(".type	_mcount ,%function");				\ 	__asm__(".global	_mcount");				\ 	__asm__("_mcount:");						\
comment|/*								\ 	 * Preserve registers that are trashed during mcount		\ 	 */
value|\ 	__asm__("stmfd	sp!, {r0-r3, ip, lr}");				\
comment|/*								\ 	 * find the return address for mcount,				\ 	 * and the return address for mcount's caller.			\ 	 *								\ 	 * frompcindex = pc pushed by call into self.			\ 	 */
value|\ 	__asm__("mov	r0, ip");					\
comment|/*								\ 	 * selfpc = pc pushed by mcount call				\ 	 */
value|\ 	__asm__("mov	r1, lr");					\
comment|/*								\ 	 * Call the real mcount code					\ 	 */
value|\ 	__asm__("bl	mcount");					\
comment|/*								\ 	 * Restore registers that were trashed during mcount		\ 	 */
value|\ 	__asm__("ldmfd	sp!, {r0-r3, lr, pc}");
end_define

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
value|((pc>= (uintfptr_t)btrap&& pc< (uintfptr_t)eintr) ?	\ 	    ((pc>= (uintfptr_t)bintr) ? (uintfptr_t)bintr :	\ 		(uintfptr_t)btrap) : ~0U)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|register_t s;
end_define

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * splhigh() and splx() are heavyweight, and call mcount().  Therefore  * we disabled interrupts (IRQ, but not FIQ) directly on the CPU.  *  * We're lucky that the CPSR and 's' both happen to be 'int's.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|{s = intr_disable(); }
end_define

begin_comment
comment|/* kill IRQ */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|{intr_restore(s); }
end_define

begin_comment
comment|/* restore old value */
end_comment

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

begin_typedef
typedef|typedef
name|u_int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PROFILE_H_ */
end_comment

end_unit

