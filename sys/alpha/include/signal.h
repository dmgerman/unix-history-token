begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: signal.h,v 1.3 1997/04/06 08:47:43 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_SIGNAL_H_
end_define

begin_typedef
typedef|typedef
name|long
name|sig_atomic_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_comment
comment|/*  * Minimum signal stack size. The current signal frame  * for Alpha is 808 bytes large.  */
end_comment

begin_define
define|#
directive|define
name|MINSIGSTKSZ
value|(1024 * 4)
end_define

begin_comment
comment|/*  * Only the kernel should need these old type definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  *  * Note that sc_regs[] and sc_fpregs[]+sc_fpcr are inline  * representations of 'struct reg' and 'struct fpreg', respectively.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|osigset_t
typedef|;
end_typedef

begin_struct
struct|struct
name|osigcontext
block|{
name|long
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|long
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|long
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|long
name|sc_ps
decl_stmt|;
comment|/* ps to restore */
name|unsigned
name|long
name|sc_regs
index|[
literal|32
index|]
decl_stmt|;
comment|/* integer register set (see above) */
name|long
name|sc_ownedfp
decl_stmt|;
comment|/* fp has been used */
name|unsigned
name|long
name|sc_fpregs
index|[
literal|32
index|]
decl_stmt|;
comment|/* FP register set (see above) */
name|unsigned
name|long
name|sc_fpcr
decl_stmt|;
comment|/* FP control register (see above) */
name|unsigned
name|long
name|sc_fp_control
decl_stmt|;
comment|/* FP software control word */
name|long
name|sc_reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* XXX */
name|long
name|sc_xxx1
index|[
literal|2
index|]
decl_stmt|;
comment|/* sc_ssize, sc_sbase on DUX */
name|unsigned
name|long
name|sc_traparg_a0
decl_stmt|;
comment|/* a0 argument to trap at exception */
name|unsigned
name|long
name|sc_traparg_a1
decl_stmt|;
comment|/* a1 argument to trap at exception */
name|unsigned
name|long
name|sc_traparg_a2
decl_stmt|;
comment|/* a2 argument to trap at exception */
name|long
name|sc_xxx2
index|[
literal|3
index|]
decl_stmt|;
comment|/* sc_fp_trap_pc, sc_fp_trigger_sum, sc_fp_trigger_inst */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The sequence of the fields should match those in  * mcontext_t. Keep them in sync!  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
name|sigset_t
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|long
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|unsigned
name|long
name|sc_regs
index|[
literal|32
index|]
decl_stmt|;
comment|/* integer register set (see above) */
name|long
name|sc_ps
decl_stmt|;
comment|/* ps to restore */
name|long
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|unsigned
name|long
name|sc_traparg_a0
decl_stmt|;
comment|/* a0 argument to trap at exception */
name|unsigned
name|long
name|sc_traparg_a1
decl_stmt|;
comment|/* a1 argument to trap at exception */
name|unsigned
name|long
name|sc_traparg_a2
decl_stmt|;
comment|/* a2 argument to trap at exception */
name|unsigned
name|long
name|sc_fpregs
index|[
literal|32
index|]
decl_stmt|;
comment|/* FP register set (see above) */
name|unsigned
name|long
name|sc_fpcr
decl_stmt|;
comment|/* FP control register (see above) */
name|unsigned
name|long
name|sc_fp_control
decl_stmt|;
comment|/* FP software control word */
name|long
name|sc_ownedfp
decl_stmt|;
comment|/* fp has been used */
name|long
name|sc_xxx1
index|[
literal|2
index|]
decl_stmt|;
comment|/* sc_ssize, sc_sbase on DUX */
name|long
name|sc_xxx2
index|[
literal|3
index|]
decl_stmt|;
comment|/* sc_fp_trap_pc, sc_fp_trigger_sum, sc_fp_trigger_inst */
name|long
name|sc_reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* XXX */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_sp
value|sc_regs[R_SP]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALPHA_SIGNAL_H_*/
end_comment

end_unit

