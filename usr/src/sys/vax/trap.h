begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)trap.h	7.3 (Berkeley) 7/11/87  */
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
comment|/* reserved addressing fault */
end_comment

begin_define
define|#
directive|define
name|T_PRIVINFLT
value|1
end_define

begin_comment
comment|/* privileged instruction fault */
end_comment

begin_define
define|#
directive|define
name|T_RESOPFLT
value|2
end_define

begin_comment
comment|/* reserved operand fault */
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

begin_comment
comment|/* CHME, CHMS, CHMU are not yet given back to users reasonably */
end_comment

begin_define
define|#
directive|define
name|T_BPTFLT
value|3
end_define

begin_comment
comment|/* bpt instruction fault */
end_comment

begin_define
define|#
directive|define
name|T_XFCFLT
value|4
end_define

begin_comment
comment|/* xfc instruction fault */
end_comment

begin_define
define|#
directive|define
name|T_SYSCALL
value|5
end_define

begin_comment
comment|/* chmk instruction (syscall trap) */
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
comment|/* software level 2 trap (ast deliv) */
end_comment

begin_define
define|#
directive|define
name|T_SEGFLT
value|8
end_define

begin_comment
comment|/* segmentation fault */
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
name|T_COMPATFLT
value|11
end_define

begin_comment
comment|/* compatibility mode fault */
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
name|T_KDBTRAP
value|14
end_define

begin_comment
comment|/* kernel debugger trap */
end_comment

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
name|FPE_FLTOVF_TRAP
value|0x3
end_define

begin_comment
comment|/* floating overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV_TRAP
value|0x4
end_define

begin_comment
comment|/* floating/decimal divide by zero */
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

begin_define
define|#
directive|define
name|FPE_DECOVF_TRAP
value|0x6
end_define

begin_comment
comment|/* decimal overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_SUBRNG_TRAP
value|0x7
end_define

begin_comment
comment|/* subscript out of range */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF_FAULT
value|0x8
end_define

begin_comment
comment|/* floating overflow fault */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV_FAULT
value|0x9
end_define

begin_comment
comment|/* divide by zero floating fault */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND_FAULT
value|0xa
end_define

begin_comment
comment|/* floating underflow fault */
end_comment

end_unit

