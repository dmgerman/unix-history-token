begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)proc.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for hp300.  */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
name|int
name|md_flags
decl_stmt|;
comment|/* machine-dependent flags */
name|int
modifier|*
name|md_regs
decl_stmt|;
comment|/* registers on current frame */
block|}
struct|;
end_struct

begin_comment
comment|/* md_flags */
end_comment

begin_define
define|#
directive|define
name|MDP_AST
value|0x0001
end_define

begin_comment
comment|/* async trap pending */
end_comment

end_unit

