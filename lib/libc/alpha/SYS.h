begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: SYS.h,v 1.5 1997/05/02 18:15:15 kleink Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_include
include|#
directive|include
file|<sys/netbsd_syscall.h>
end_include

begin_define
define|#
directive|define
name|CALLSYS_ERROR
parameter_list|(
name|name
parameter_list|)
define|\
value|CALLSYS_NOERROR(name);					\ 	br	gp, LLABEL(name,0);				\ LLABEL(name,0):							\ 	LDGP(gp);						\ 	beq	a3, LLABEL(name,1);				\ 	jmp	zero, cerror;					\ LLABEL(name,1):
end_define

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|name
parameter_list|)
define|\
value|LEAF(name,0);
comment|/* XXX # of args? */
value|\ 	CALLSYS_ERROR(name)
end_define

begin_define
define|#
directive|define
name|SYSCALL_NOERROR
parameter_list|(
name|name
parameter_list|)
define|\
value|LEAF(name,0);
comment|/* XXX # of args? */
value|\ 	CALLSYS_NOERROR(name)
end_define

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|name
parameter_list|)
define|\
value|SYSCALL(name);						\ 	RET;							\ END(name)
end_define

begin_define
define|#
directive|define
name|RSYSCALL_NOERROR
parameter_list|(
name|name
parameter_list|)
define|\
value|SYSCALL_NOERROR(name);					\ 	RET;							\ END(name)
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|label
parameter_list|,
name|name
parameter_list|)
define|\
value|LEAF(label,0);
comment|/* XXX # of args? */
value|\ 	CALLSYS_ERROR(name);					\ 	RET;							\ END(label);
end_define

begin_define
define|#
directive|define
name|PSEUDO_NOERROR
parameter_list|(
name|label
parameter_list|,
name|name
parameter_list|)
define|\
value|LEAF(label,0);
comment|/* XXX # of args? */
value|\ 	CALLSYS_NOERROR(name);					\ 	RET;							\ END(label);
end_define

begin_define
define|#
directive|define
name|PRSYSCALL
parameter_list|(
name|x
parameter_list|)
value|RSYSCALL(x)
end_define

begin_define
define|#
directive|define
name|PPSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|PSEUDO(x,y)
end_define

end_unit

