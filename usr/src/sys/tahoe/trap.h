begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)trap.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * Trap type values  * also known in trap.c for name strings  */
end_comment

begin_define
define|#
directive|define
name|T_RESADFLT
value|0
end_define

begin_comment
comment|/* reserved addressing */
end_comment

begin_define
define|#
directive|define
name|T_PRIVINFLT
value|1
end_define

begin_comment
comment|/* privileged instruction */
end_comment

begin_define
define|#
directive|define
name|T_RESOPFLT
value|2
end_define

begin_comment
comment|/* reserved operand */
end_comment

begin_define
define|#
directive|define
name|T_BPTFLT
value|3
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|T_SYSCALL
value|5
end_define

begin_comment
comment|/* system call (kcall) */
end_comment

begin_define
define|#
directive|define
name|T_ARITHTRAP
value|6
end_define

begin_comment
comment|/* arithmetic trap */
end_comment

begin_define
define|#
directive|define
name|T_ASTFLT
value|7
end_define

begin_comment
comment|/* system forced exception */
end_comment

begin_define
define|#
directive|define
name|T_SEGFLT
value|8
end_define

begin_comment
comment|/* segmentation (limit) fault */
end_comment

begin_define
define|#
directive|define
name|T_PROTFLT
value|9
end_define

begin_comment
comment|/* protection fault */
end_comment

begin_define
define|#
directive|define
name|T_TRCTRAP
value|10
end_define

begin_comment
comment|/* trace trap */
end_comment

begin_define
define|#
directive|define
name|T_PAGEFLT
value|12
end_define

begin_comment
comment|/* page fault */
end_comment

begin_define
define|#
directive|define
name|T_TABLEFLT
value|13
end_define

begin_comment
comment|/* page table fault */
end_comment

begin_define
define|#
directive|define
name|T_ALIGNFLT
value|14
end_define

begin_comment
comment|/* alignment fault */
end_comment

begin_define
define|#
directive|define
name|T_KSPNOTVAL
value|15
end_define

begin_comment
comment|/* kernel stack pointer not valid */
end_comment

begin_define
define|#
directive|define
name|T_BUSERR
value|16
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|T_KDBTRAP
value|17
end_define

begin_comment
comment|/* kernel debugger trap */
end_comment

begin_comment
comment|/* definitions for<sys/signal.h> */
end_comment

begin_define
define|#
directive|define
name|ILL_RESAD_FAULT
value|T_RESADFLT
end_define

begin_define
define|#
directive|define
name|ILL_PRIVIN_FAULT
value|T_PRIVINFLT
end_define

begin_define
define|#
directive|define
name|ILL_RESOP_FAULT
value|T_RESOPFLT
end_define

begin_define
define|#
directive|define
name|ILL_ALIGN_FAULT
value|T_ALIGNFLT
end_define

begin_comment
comment|/* codes for SIGFPE/ARITHTRAP */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF_TRAP
value|0x1
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV_TRAP
value|0x2
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV_TRAP
value|0x3
end_define

begin_comment
comment|/* floating/decimal divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF_TRAP
value|0x4
end_define

begin_comment
comment|/* floating overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND_TRAP
value|0x5
end_define

begin_comment
comment|/* floating underflow */
end_comment

end_unit

