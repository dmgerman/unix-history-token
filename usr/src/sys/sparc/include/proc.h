begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)proc.h	7.1 (Berkeley) %G%  *  * from: $Header: proc.h,v 1.5 92/06/17 06:10:23 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for SPARC.  */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
name|struct
name|trapframe
modifier|*
name|md_tf
decl_stmt|;
comment|/* trap/syscall registers */
name|struct
name|fpstate
modifier|*
name|md_fpstate
decl_stmt|;
comment|/* fpu state, if any; always resident */
block|}
struct|;
end_struct

end_unit

