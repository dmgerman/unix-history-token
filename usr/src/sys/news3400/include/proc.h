begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)proc.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for DEC Station.  */
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
name|int
name|md_upte
index|[
name|UPAGES
index|]
decl_stmt|;
comment|/* ptes for mapping u page */
name|int
name|md_ss_addr
decl_stmt|;
comment|/* single step address for ptrace */
name|int
name|md_ss_instr
decl_stmt|;
comment|/* single step instruction for ptrace */
block|}
struct|;
end_struct

begin_comment
comment|/* md_flags */
end_comment

begin_define
define|#
directive|define
name|MDP_FPUSED
value|0x0001
end_define

begin_comment
comment|/* floating point coprocessor used */
end_comment

begin_define
define|#
directive|define
name|MDP_ULTRIX
value|0x0002
end_define

begin_comment
comment|/* ULTRIX process (ULTRIXCOMPAT) */
end_comment

end_unit

