begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pcb.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * VAX process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|int
name|pcb_ksp
decl_stmt|;
comment|/* kernel stack pointer */
name|int
name|pcb_esp
decl_stmt|;
comment|/* exec stack pointer */
name|int
name|pcb_ssp
decl_stmt|;
comment|/* supervisor stack pointer */
name|int
name|pcb_usp
decl_stmt|;
comment|/* user stack pointer */
name|int
name|pcb_r0
decl_stmt|;
name|int
name|pcb_r1
decl_stmt|;
name|int
name|pcb_r2
decl_stmt|;
name|int
name|pcb_r3
decl_stmt|;
name|int
name|pcb_r4
decl_stmt|;
name|int
name|pcb_r5
decl_stmt|;
name|int
name|pcb_r6
decl_stmt|;
name|int
name|pcb_r7
decl_stmt|;
name|int
name|pcb_r8
decl_stmt|;
name|int
name|pcb_r9
decl_stmt|;
name|int
name|pcb_r10
decl_stmt|;
name|int
name|pcb_r11
decl_stmt|;
name|int
name|pcb_r12
decl_stmt|;
define|#
directive|define
name|pcb_ap
value|pcb_r12
name|int
name|pcb_r13
decl_stmt|;
define|#
directive|define
name|pcb_fp
value|pcb_r13
name|int
name|pcb_pc
decl_stmt|;
comment|/* program counter */
name|int
name|pcb_psl
decl_stmt|;
comment|/* program status longword */
name|struct
name|pte
modifier|*
name|pcb_p0br
decl_stmt|;
comment|/* seg 0 base register */
name|int
name|pcb_p0lr
decl_stmt|;
comment|/* seg 0 length register and astlevel */
name|struct
name|pte
modifier|*
name|pcb_p1br
decl_stmt|;
comment|/* seg 1 base register */
name|int
name|pcb_p1lr
decl_stmt|;
comment|/* seg 1 length register and pme */
comment|/*  * Software pcb (extension)  */
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
name|int
name|pcb_sigc
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AST_NONE
value|0x04000000
end_define

begin_comment
comment|/* ast level */
end_comment

begin_define
define|#
directive|define
name|AST_USER
value|0x03000000
end_define

begin_comment
comment|/* ast for user mode */
end_comment

begin_define
define|#
directive|define
name|ASTLVL_NONE
value|4
end_define

begin_define
define|#
directive|define
name|ASTLVL_USER
value|3
end_define

begin_define
define|#
directive|define
name|AST_CLR
value|0x07000000
end_define

begin_define
define|#
directive|define
name|PME_CLR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|aston
parameter_list|()
define|\
value|{ \ 		mtpr(ASTLVL, ASTLVL_USER); \ 	}
end_define

begin_define
define|#
directive|define
name|astoff
parameter_list|()
define|\
value|{ \ 		mtpr(ASTLVL, ASTLVL_NONE); \ 	}
end_define

end_unit

