begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* From: NetBSD: frame.h,v 1.4 1997/04/06 08:47:27 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_FRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_FRAME_H_
end_define

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_comment
comment|/*  * Software trap, exception, and syscall frame.  *  * Includes "hardware" (PALcode) frame.  *  * PALcode puts ALPHA_HWFRAME_* fields on stack.  We have to add  * all of the general-purpose registers except for zero, for sp  * (which is automatically saved in the PCB's USP field for entries  * from user mode, and which is implicitly saved and restored by the  * calling conventions for entries from kernel mode), and (on traps  * and exceptions) for a0, a1, and a2 (which are saved by PALcode).  */
end_comment

begin_comment
comment|/* Quadword offsets of the registers to be saved. */
end_comment

begin_define
define|#
directive|define
name|FRAME_V0
value|0
end_define

begin_define
define|#
directive|define
name|FRAME_T0
value|1
end_define

begin_define
define|#
directive|define
name|FRAME_T1
value|2
end_define

begin_define
define|#
directive|define
name|FRAME_T2
value|3
end_define

begin_define
define|#
directive|define
name|FRAME_T3
value|4
end_define

begin_define
define|#
directive|define
name|FRAME_T4
value|5
end_define

begin_define
define|#
directive|define
name|FRAME_T5
value|6
end_define

begin_define
define|#
directive|define
name|FRAME_T6
value|7
end_define

begin_define
define|#
directive|define
name|FRAME_T7
value|8
end_define

begin_define
define|#
directive|define
name|FRAME_S0
value|9
end_define

begin_define
define|#
directive|define
name|FRAME_S1
value|10
end_define

begin_define
define|#
directive|define
name|FRAME_S2
value|11
end_define

begin_define
define|#
directive|define
name|FRAME_S3
value|12
end_define

begin_define
define|#
directive|define
name|FRAME_S4
value|13
end_define

begin_define
define|#
directive|define
name|FRAME_S5
value|14
end_define

begin_define
define|#
directive|define
name|FRAME_S6
value|15
end_define

begin_define
define|#
directive|define
name|FRAME_A3
value|16
end_define

begin_define
define|#
directive|define
name|FRAME_A4
value|17
end_define

begin_define
define|#
directive|define
name|FRAME_A5
value|18
end_define

begin_define
define|#
directive|define
name|FRAME_T8
value|19
end_define

begin_define
define|#
directive|define
name|FRAME_T9
value|20
end_define

begin_define
define|#
directive|define
name|FRAME_T10
value|21
end_define

begin_define
define|#
directive|define
name|FRAME_T11
value|22
end_define

begin_define
define|#
directive|define
name|FRAME_RA
value|23
end_define

begin_define
define|#
directive|define
name|FRAME_T12
value|24
end_define

begin_define
define|#
directive|define
name|FRAME_AT
value|25
end_define

begin_define
define|#
directive|define
name|FRAME_SP
value|26
end_define

begin_define
define|#
directive|define
name|FRAME_SW_SIZE
value|(FRAME_SP + 1)
end_define

begin_define
define|#
directive|define
name|FRAME_HW_OFFSET
value|FRAME_SW_SIZE
end_define

begin_define
define|#
directive|define
name|FRAME_PS
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_PS)
end_define

begin_define
define|#
directive|define
name|FRAME_PC
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_PC)
end_define

begin_define
define|#
directive|define
name|FRAME_GP
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_GP)
end_define

begin_define
define|#
directive|define
name|FRAME_A0
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_A0)
end_define

begin_define
define|#
directive|define
name|FRAME_A1
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_A1)
end_define

begin_define
define|#
directive|define
name|FRAME_A2
value|(FRAME_HW_OFFSET + ALPHA_HWFRAME_A2)
end_define

begin_define
define|#
directive|define
name|FRAME_HW_SIZE
value|ALPHA_HWFRAME_SIZE
end_define

begin_define
define|#
directive|define
name|FRAME_SIZE
value|(FRAME_HW_OFFSET + FRAME_HW_SIZE)
end_define

begin_struct
struct|struct
name|trapframe
block|{
name|unsigned
name|long
name|tf_regs
index|[
name|FRAME_SIZE
index|]
decl_stmt|;
comment|/* See above */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_FRAME_H_ */
end_comment

end_unit

