begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_EFLAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_EFLAGS_H_
end_define

begin_comment
comment|/*  *	i386 flags register  */
end_comment

begin_define
define|#
directive|define
name|EFL_CF
value|0x00000001
end_define

begin_comment
comment|/* carry */
end_comment

begin_define
define|#
directive|define
name|EFL_PF
value|0x00000004
end_define

begin_comment
comment|/* parity of low 8 bits */
end_comment

begin_define
define|#
directive|define
name|EFL_AF
value|0x00000010
end_define

begin_comment
comment|/* carry out of bit 3 */
end_comment

begin_define
define|#
directive|define
name|EFL_ZF
value|0x00000040
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|EFL_SF
value|0x00000080
end_define

begin_comment
comment|/* sign */
end_comment

begin_define
define|#
directive|define
name|EFL_TF
value|0x00000100
end_define

begin_comment
comment|/* trace trap */
end_comment

begin_define
define|#
directive|define
name|EFL_IF
value|0x00000200
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EFL_DF
value|0x00000400
end_define

begin_comment
comment|/* direction */
end_comment

begin_define
define|#
directive|define
name|EFL_OF
value|0x00000800
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|EFL_IOPL
value|0x00003000
end_define

begin_comment
comment|/* IO privilege level: */
end_comment

begin_define
define|#
directive|define
name|EFL_IOPL_KERNEL
value|0x00000000
end_define

begin_comment
comment|/* kernel */
end_comment

begin_define
define|#
directive|define
name|EFL_IOPL_USER
value|0x00003000
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|EFL_NT
value|0x00004000
end_define

begin_comment
comment|/* nested task */
end_comment

begin_define
define|#
directive|define
name|EFL_RF
value|0x00010000
end_define

begin_comment
comment|/* resume without tracing */
end_comment

begin_define
define|#
directive|define
name|EFL_VM
value|0x00020000
end_define

begin_comment
comment|/* virtual 8086 mode */
end_comment

begin_define
define|#
directive|define
name|EFL_USER_SET
value|(EFL_IF)
end_define

begin_define
define|#
directive|define
name|EFL_USER_CLEAR
value|(EFL_IOPL|EFL_NT|EFL_RF)
end_define

begin_endif
endif|#
directive|endif
endif|_I386_EFLAGS_H_
end_endif

end_unit

