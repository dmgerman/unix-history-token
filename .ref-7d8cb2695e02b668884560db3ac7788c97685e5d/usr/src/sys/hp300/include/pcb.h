begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pcb.h 1.14 91/03/25$  *  *	@(#)pcb.h	7.7 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * HP300 process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|short
name|pcb_flags
decl_stmt|;
comment|/* misc. process flags */
name|short
name|pcb_ps
decl_stmt|;
comment|/* processor status word */
name|int
name|pcb_ustp
decl_stmt|;
comment|/* user segment table pointer */
name|int
name|pcb_usp
decl_stmt|;
comment|/* user stack pointer */
name|int
name|pcb_regs
index|[
literal|12
index|]
decl_stmt|;
comment|/* D2-D7, A2-A7 */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* for copyin/out faults */
name|struct
name|fpframe
name|pcb_fpregs
decl_stmt|;
comment|/* 68881/2 context save area */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the hp300, this includes an HP-UX exec header  * which is dumped for HP-UX processes.  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|int
name|md_exec
index|[
literal|16
index|]
decl_stmt|;
comment|/* exec structure for HP-UX core dumps */
block|}
struct|;
end_struct

end_unit

