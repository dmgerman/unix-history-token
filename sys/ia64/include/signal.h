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
name|_MACHINE_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGNAL_H_
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
comment|/* portable macros for SIGFPE/ARITHTRAP */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF
value|1
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV
value|2
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV
value|3
end_define

begin_comment
comment|/* floating point divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF
value|4
end_define

begin_comment
comment|/* floating point overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND
value|5
end_define

begin_comment
comment|/* floating point underflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTRES
value|6
end_define

begin_comment
comment|/* floating point inexact result */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTINV
value|7
end_define

begin_comment
comment|/* invalid floating point operation */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTSUB
value|8
end_define

begin_comment
comment|/* subscript out of range */
end_comment

begin_define
define|#
directive|define
name|BUS_SEGM_FAULT
value|30
end_define

begin_comment
comment|/* segment protection base */
end_comment

begin_comment
comment|/*  * Minimum signal stack size. The current signal frame  * for IA-64 is 2656 bytes large.  */
end_comment

begin_define
define|#
directive|define
name|MINSIGSTKSZ
value|(3072 * 4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IA64_FPREG_DEFINED
end_ifndef

begin_struct
struct|struct
name|ia64_fpreg
block|{
name|unsigned
name|long
name|fpr_bits
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|_IA64_FPREG_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

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
block|{}
struct|;
end_struct

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
name|unsigned
name|long
name|sc_onstack
decl_stmt|;
name|unsigned
name|long
name|sc_flags
decl_stmt|;
name|unsigned
name|long
name|sc_nat
decl_stmt|;
name|unsigned
name|long
name|sc_sp
decl_stmt|;
name|unsigned
name|long
name|sc_ip
decl_stmt|;
name|unsigned
name|long
name|sc_cfm
decl_stmt|;
name|unsigned
name|long
name|sc_um
decl_stmt|;
name|unsigned
name|long
name|sc_ar_rsc
decl_stmt|;
name|unsigned
name|long
name|sc_ar_bsp
decl_stmt|;
name|unsigned
name|long
name|sc_ar_rnat
decl_stmt|;
name|unsigned
name|long
name|sc_ar_ccv
decl_stmt|;
name|unsigned
name|long
name|sc_ar_unat
decl_stmt|;
name|unsigned
name|long
name|sc_ar_fpsr
decl_stmt|;
name|unsigned
name|long
name|sc_ar_pfs
decl_stmt|;
name|unsigned
name|long
name|sc_pr
decl_stmt|;
name|unsigned
name|long
name|sc_br
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|sc_gr
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|ia64_fpreg
name|sc_fr
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* !_MACHINE_SIGNAL_H_*/
end_comment

end_unit

