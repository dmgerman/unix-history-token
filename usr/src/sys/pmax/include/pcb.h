begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pcb.h 1.13 89/04/23$  *  *	@(#)pcb.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * PMAX process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|int
name|pcb_regs
index|[
literal|69
index|]
decl_stmt|;
comment|/* saved CPU and floating point registers */
name|label_t
name|pcb_context
decl_stmt|;
comment|/* kernel context for resume */
name|int
name|pcb_onfault
decl_stmt|;
comment|/* for copyin/copyout faults */
name|void
modifier|*
name|pcb_segtab
decl_stmt|;
comment|/* copy of pmap pm_segtab */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the PMAX, there is nothing to add.  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|long
name|md_pad
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

