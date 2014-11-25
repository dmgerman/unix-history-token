begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	from: NetBSD: profile.h,v 1.9 1997/04/06 08:47:37 cgd Exp  *	from: FreeBSD: src/sys/alpha/include/profile.h,v 1.4 1999/12/29  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void __mcount
end_define

begin_define
define|#
directive|define
name|FUNCTION_ALIGNMENT
value|4
end_define

begin_typedef
typedef|typedef
name|__ptrdiff_t
name|fptrdiff_t
typedef|;
end_typedef

begin_comment
comment|/*  * The mcount trampoline macro, expanded in libc/gmon/mcount.c  *  * For PowerPC SVR4 ABI profiling, the compiler will insert  * a data declaration and code sequence at the start of a routine of the form  *  * .function_mc:       	.data  *			.align	2  *			.long	0  *			.text  *  * function:		mflr	%r0  *			addis	%r11,%r0, .function_mc@ha  *			stw	%r0,4(%r1)  *			addi	%r0,%r11, .function_mc@l  *			bl	_mcount  *  * The link register is saved in the LR save word in the caller's  * stack frame, r0 is set up to point to the allocated longword,  * and control is transferred to _mcount.  *  * On return from _mcount, the routine should function as it would  * with no profiling so _mcount must restore register state to that upon  * entry. Any routine called by the _mcount trampoline will save  * callee-save registers, so _mcount must make sure it saves volatile  * registers that may have state after it returns i.e. parameter registers.  *  * The FreeBSD libc mcount routine ignores the r0 longword pointer, but  * instead requires as parameters the current PC and called PC. The current  * PC is obtained from the link register, as a result of "bl _mcount" in  * the stub, while the caller's PC is obtained from the LR save word.  *  * On return from libc mcount, the return is done indirectly with the  * ctr register rather than the link register, to allow the link register  * to be restored to what it was on entry to the profiled routine.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|__asm(	"	.text				\n" \ 	"	.align	2			\n" \ 	"	.globl	_mcount			\n" \ 	"	.section \".opd\",\"aw\"	\n" \ 	"	.align	3			\n" \ 	"_mcount:				\n" \ 	"	.quad .L._mcount,.TOC.@tocbase,0\n" \ 	"	.previous			\n" \ 	"	.size   _mcount,24		\n" \ 	"	.type	_mcount,@function	\n" \ 	"	.align	4			\n" \ 	".L._mcount:				\n" \ 	"	stdu	%r1,-(288+128)(%r1)	\n" \ 	"	std	%r3,48(%r1)		\n" \ 	"	std	%r4,56(%r1)		\n" \ 	"	std	%r5,64(%r1)		\n" \ 	"	std	%r6,72(%r1)		\n" \ 	"	std	%r7,80(%r1)		\n" \ 	"	std	%r8,88(%r1)		\n" \ 	"	std	%r9,96(%r1)		\n" \ 	"	std	%r10,104(%r1)		\n" \ 	"	mflr	%r4			\n" \ 	"	std	%r4,112(%r1)		\n" \ 	"	ld	%r3,0(%r1)		\n" \ 	"	ld	%r3,0(%r3)		\n" \ 	"	ld	%r3,16(%r3)		\n" \ 	"	bl	__mcount		\n" \ 	"	nop				\n" \ 	"	ld	%r4,112(%r1)		\n" \ 	"	mtlr	%r4			\n" \ 	"	ld	%r3,48(%r1)		\n" \ 	"	ld	%r4,56(%r1)		\n" \ 	"	ld	%r5,64(%r1)		\n" \ 	"	ld	%r6,72(%r1)		\n" \ 	"	ld	%r7,80(%r1)		\n" \ 	"	ld	%r8,88(%r1)		\n" \ 	"	ld	%r9,96(%r1)		\n" \ 	"	ld	%r10,104(%r1)		\n" \ 	"	addi	%r1,%r1,(288+128)	\n" \ 	"	blr				\n");
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|_PLT
value|"@plt"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PLT
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
value|__asm(	"	.globl	_mcount			\n" \ 	"	.type	_mcount,@function	\n" \ 	"	.align	4			\n" \ 	"_mcount:				\n" \ 	"	stwu	%r1,-64(%r1)		\n" \ 	"	stw	%r3,16(%r1)		\n" \ 	"	stw	%r4,20(%r1)		\n" \ 	"	stw	%r5,24(%r1)		\n" \ 	"	stw	%r6,28(%r1)		\n" \ 	"	stw	%r7,32(%r1)		\n" \ 	"	stw	%r8,36(%r1)		\n" \ 	"	stw	%r9,40(%r1)		\n" \ 	"	stw	%r10,44(%r1)		\n" \ 	"	mflr	%r4			\n" \ 	"	stw	%r4,48(%r1)		\n" \ 	"	lwz	%r3,68(%r1)		\n" \ 	"	bl	__mcount" _PLT "	\n" \ 	"	lwz	%r3,68(%r1)		\n" \ 	"	mtlr	%r3			\n" \ 	"	lwz	%r4,48(%r1)		\n" \ 	"	mtctr	%r4			\n" \ 	"	lwz	%r3,16(%r1)		\n" \ 	"	lwz	%r4,20(%r1)		\n" \ 	"	lwz	%r5,24(%r1)		\n" \ 	"	lwz	%r6,28(%r1)		\n" \ 	"	lwz	%r7,32(%r1)		\n" \ 	"	lwz	%r8,36(%r1)		\n" \ 	"	lwz	%r9,40(%r1)		\n" \ 	"	lwz	%r10,44(%r1)		\n" \ 	"	addi	%r1,%r1,64		\n" \ 	"	bctr				\n" \ 	"_mcount_end:				\n" \ 	"	.size	_mcount,_mcount_end-_mcount");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|s = intr_disable()
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|intr_restore(s)
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|register_t s;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|COMPILING_LINT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|AIM
end_ifdef

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_BASE
value|EXC_RST
end_define

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_TOP
value|(EXC_LAST + 0x100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIM */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BOOKE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
name|interrupt_vector_base
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|interrupt_vector_top
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_BASE
value|(uintfptr_t)interrupt_vector_base
end_define

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_TOP
value|(uintfptr_t)interrupt_vector_top
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BOOKE_E500 || BOOKE_PPC4XX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !COMPILING_LINT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PROFILE_VECTOR_BASE
end_ifndef

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_BASE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__PROFILE_VECTOR_TOP
end_ifndef

begin_define
define|#
directive|define
name|__PROFILE_VECTOR_TOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|powerpc_profile_interrupt
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|powerpc_profile_userspace
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_USER
parameter_list|(
name|pc
parameter_list|)
define|\
value|((pc< (uintfptr_t)VM_MAXUSER_ADDRESS) ?	\ 	    (uintfptr_t)powerpc_profile_userspace : pc)
end_define

begin_define
define|#
directive|define
name|MCOUNT_FROMPC_INTR
parameter_list|(
name|pc
parameter_list|)
define|\
value|((pc>= __PROFILE_VECTOR_BASE&&		\ 	  pc< __PROFILE_VECTOR_TOP) ?			\ 	    (uintfptr_t)powerpc_profile_interrupt : ~0U)
end_define

begin_function_decl
name|void
name|__mcount
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

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_typedef
typedef|typedef
name|u_long
name|uintfptr_t
typedef|;
end_typedef

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

