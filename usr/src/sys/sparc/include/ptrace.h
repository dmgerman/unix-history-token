begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)ptrace.h	7.3 (Berkeley) %G%  *  * from: $Header: ptrace.h,v 1.6 92/11/26 02:04:43 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SPARC-dependent ptrace definitions.  */
end_comment

begin_define
define|#
directive|define
name|PT_GETREGS
value|(PT_FIRSTMACH + 0)
end_define

begin_define
define|#
directive|define
name|PT_SETREGS
value|(PT_FIRSTMACH + 1)
end_define

begin_define
define|#
directive|define
name|PT_GETFPREGS
value|(PT_FIRSTMACH + 2)
end_define

begin_define
define|#
directive|define
name|PT_SETFPREGS
value|(PT_FIRSTMACH + 3)
end_define

end_unit

