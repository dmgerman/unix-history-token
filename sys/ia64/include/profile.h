begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: profile.h,v 1.9 1997/04/06 08:47:37 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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
name|FUNCTION_ALIGNMENT
value|32
end_define

begin_typedef
typedef|typedef
name|u_long
name|fptrdiff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MCOUNT
value|__asm ("							\n\ 	.globl	_mcount							\n\ 	.proc	_mcount							\n\ _mcount:								\n\ 	alloc	loc0=ar.pfs,8,7,2,0	// space to save r8-r11,rp,b7	\n\ 	add	sp=-8*16,sp		// space to save f8-f15		\n\ 	mov	loc1=rp			// caller's return address	\n\ 	mov	loc2=b7			// our return back to caller	\n\ 	;;								\n\ 	add	r17=16,sp		// leave 16 bytes for mcount	\n\ 	add	r18=32,sp						\n\ 	;;								\n\ 	mov	loc3=r8			// structure return address	\n\ 	mov	loc4=r9			// language specific		\n\ 	mov	loc5=r10		// language specific		\n\ 	mov	loc6=r11		// language specific		\n\ 	;;								\n\ 	stf.spill [r17]=f8,32		// save float arguments		\n\ 	stf.spill [r18]=f9,32						\n\ 	mov	out0=rp			// frompc			\n\ 	;;								\n\ 	stf.spill [r17]=f10,32						\n\ 	stf.spill [r18]=f11,32						\n\ 	mov	out1=b7			// selfpc			\n\ 	;;								\n\ 	stf.spill [r17]=f12,32						\n\ 	stf.spill [r18]=f13,32						\n\ 	;;								\n\ 	stf.spill [r17]=f14,32						\n\ 	stf.spill [r18]=f15,32						\n\ 	;;								\n\ 	br.call.sptk.many rp=mcount					\n\ 	;;								\n\ 	add	r17=16,sp						\n\ 	add	r18=32,sp						\n\ 	;;								\n\ 	ldf.fill f8=[r17],32						\n\ 	ldf.fill f9=[r18],32						\n\ 	mov	r8=loc3			// restore structure pointer	\n\ 	;;								\n\ 	ldf.fill f10=[r17],32		// restore float arguments	\n\ 	ldf.fill f11=[r18],32						\n\ 	mov	r9=loc4							\n\ 	;;								\n\ 	ldf.fill f12=[r17],32		// etc.				\n\ 	ldf.fill f13=[r18],32						\n\ 	mov	r10=loc5						\n\ 	;;								\n\ 	ldf.fill f14=[r17],32						\n\ 	ldf.fill f15=[r18],32						\n\ 	mov	r11=loc6						\n\ 	;;								\n\ 	mov	b7=loc2			// clean up			\n\ 	mov	rp=loc1							\n\ 	mov	ar.pfs=loc0						\n\ 	;;								\n\ 	alloc	r14=ar.pfs,0,0,8,0	// drop our register frame	\n\ 	br.sptk.many b7			// back to caller		\n\ 									\n\ 	.end	_mcount");
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
parameter_list|(
name|s
parameter_list|)
value|\n\ 	_c = intr_disable()
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
parameter_list|(
name|s
parameter_list|)
value|\n\ 	intr_restore(_c)
end_define

begin_define
define|#
directive|define
name|MCOUNT_DECL
parameter_list|(
name|s
parameter_list|)
value|register_t c;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_struct_decl
struct_decl|struct
name|gmonparam
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|nullfunc_loop_profiled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nullfunc_profiled
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|startguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stopguprof
parameter_list|(
name|struct
name|gmonparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|startguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|stopguprof
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
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

end_unit

