begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* From: NetBSD: reg.h,v 1.3 1997/04/06 08:47:40 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_REG_H_
end_define

begin_comment
comment|/*  * XXX where did this info come from?  */
end_comment

begin_comment
comment|/*  * Struct reg, used for procfs and in signal contexts  * Note that in signal contexts, it's represented as an array.  * That array has to look exactly like 'struct reg' though.  */
end_comment

begin_define
define|#
directive|define
name|R_V0
value|0
end_define

begin_define
define|#
directive|define
name|R_T0
value|1
end_define

begin_define
define|#
directive|define
name|R_T1
value|2
end_define

begin_define
define|#
directive|define
name|R_T2
value|3
end_define

begin_define
define|#
directive|define
name|R_T3
value|4
end_define

begin_define
define|#
directive|define
name|R_T4
value|5
end_define

begin_define
define|#
directive|define
name|R_T5
value|6
end_define

begin_define
define|#
directive|define
name|R_T6
value|7
end_define

begin_define
define|#
directive|define
name|R_T7
value|8
end_define

begin_define
define|#
directive|define
name|R_S0
value|9
end_define

begin_define
define|#
directive|define
name|R_S1
value|10
end_define

begin_define
define|#
directive|define
name|R_S2
value|11
end_define

begin_define
define|#
directive|define
name|R_S3
value|12
end_define

begin_define
define|#
directive|define
name|R_S4
value|13
end_define

begin_define
define|#
directive|define
name|R_S5
value|14
end_define

begin_define
define|#
directive|define
name|R_S6
value|15
end_define

begin_define
define|#
directive|define
name|R_A0
value|16
end_define

begin_define
define|#
directive|define
name|R_A1
value|17
end_define

begin_define
define|#
directive|define
name|R_A2
value|18
end_define

begin_define
define|#
directive|define
name|R_A3
value|19
end_define

begin_define
define|#
directive|define
name|R_A4
value|20
end_define

begin_define
define|#
directive|define
name|R_A5
value|21
end_define

begin_define
define|#
directive|define
name|R_T8
value|22
end_define

begin_define
define|#
directive|define
name|R_T9
value|23
end_define

begin_define
define|#
directive|define
name|R_T10
value|24
end_define

begin_define
define|#
directive|define
name|R_T11
value|25
end_define

begin_define
define|#
directive|define
name|R_RA
value|26
end_define

begin_define
define|#
directive|define
name|R_T12
value|27
end_define

begin_define
define|#
directive|define
name|R_AT
value|28
end_define

begin_define
define|#
directive|define
name|R_GP
value|29
end_define

begin_define
define|#
directive|define
name|R_SP
value|30
end_define

begin_define
define|#
directive|define
name|R_ZERO
value|31
end_define

begin_struct
struct|struct
name|reg
block|{
name|u_int64_t
name|r_regs
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Floating point unit state. (also, register set used for ptrace.)  *  * The floating point registers for a process, saved only when  * necessary.  *  * Note that in signal contexts, it's represented as an array.  * That array has to look exactly like 'struct reg' though.  */
end_comment

begin_struct
struct|struct
name|fpreg
block|{
name|u_int64_t
name|fpr_regs
index|[
literal|32
index|]
decl_stmt|;
name|u_int64_t
name|fpr_cr
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|void
name|restorefpstate
name|__P
argument_list|(
operator|(
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|savefpstate
name|__P
argument_list|(
operator|(
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_REG_H_ */
end_comment

end_unit

