begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)proc.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for hp300.  */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
name|int
modifier|*
name|md_regs
decl_stmt|;
comment|/* registers on current frame */
name|int
name|md_flags
decl_stmt|;
comment|/* machine-dependent flags */
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

begin_define
define|#
directive|define
name|MDP_HPUX
value|0x0002
end_define

begin_comment
comment|/* HP-UX process */
end_comment

begin_define
define|#
directive|define
name|MDP_HPUXTRACE
value|0x0004
end_define

begin_comment
comment|/* being traced by HP-UX process */
end_comment

begin_define
define|#
directive|define
name|MDP_HPUXMMAP
value|0x0008
end_define

begin_comment
comment|/* VA space is multiply mapped */
end_comment

begin_define
define|#
directive|define
name|MDP_CCBDATA
value|0x0010
end_define

begin_comment
comment|/* copyback caching of data (68040) */
end_comment

begin_define
define|#
directive|define
name|MDP_CCBSTACK
value|0x0020
end_define

begin_comment
comment|/* copyback caching of stack (68040) */
end_comment

end_unit

