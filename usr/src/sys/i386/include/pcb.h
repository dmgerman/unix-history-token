begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)pcb.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Intel 386 process control block  */
end_comment

begin_include
include|#
directive|include
file|"tss.h"
end_include

begin_include
include|#
directive|include
file|"fpu.h"
end_include

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|i386tss
name|pcbtss
decl_stmt|;
define|#
directive|define
name|pcb_ksp
value|pcbtss.tss_esp0
define|#
directive|define
name|pcb_ptd
value|pcbtss.tss_cr3
define|#
directive|define
name|pcb_pc
value|pcbtss.tss_eip
define|#
directive|define
name|pcb_psl
value|pcbtss.tss_eflags
define|#
directive|define
name|pcb_usp
value|pcbtss.tss_esp
define|#
directive|define
name|pcb_fp
value|pcbtss.tss_ebp
comment|/*  * Software pcb (extension)  */
name|int
name|pcb_fpsav
decl_stmt|;
define|#
directive|define
name|FP_NEEDSAVE
value|0x1
comment|/* need save on next context switch */
define|#
directive|define
name|FP_NEEDRESTORE
value|0x2
comment|/* need restore on next DNA fault */
name|struct
name|save87
name|pcb_savefpu
decl_stmt|;
name|struct
name|pte
modifier|*
name|pcb_p0br
decl_stmt|;
name|struct
name|pte
modifier|*
name|pcb_p1br
decl_stmt|;
name|int
name|pcb_p0lr
decl_stmt|;
name|int
name|pcb_p1lr
decl_stmt|;
name|int
name|pcb_szpt
decl_stmt|;
comment|/* number of pages of user page table */
name|int
name|pcb_cmap2
decl_stmt|;
name|int
modifier|*
name|pcb_sswap
decl_stmt|;
name|long
name|pcb_sigc
index|[
literal|5
index|]
decl_stmt|;
comment|/* sigcode actually 19 bytes */
block|}
struct|;
end_struct

end_unit

