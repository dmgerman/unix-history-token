begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pcb.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * TAHOE process control block  */
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
name|struct
name|pte
modifier|*
name|pcb_p2br
decl_stmt|;
comment|/* seg 2 base register */
name|int
name|pcb_p2lr
decl_stmt|;
comment|/* seg 2 length register and pme */
name|int
name|pcb_ach
decl_stmt|;
comment|/* accumulator - high order longword */
name|int
name|pcb_acl
decl_stmt|;
comment|/* accumulator - low order longword */
define|#
directive|define
name|ACH
value|pcb_ach
define|#
directive|define
name|ACL
value|pcb_acl
name|int
name|pcb_hfs
decl_stmt|;
comment|/* fp status register */
comment|/*  * Software pcb (extension)  */
union|union
block|{
name|float
modifier|*
name|faddr
decl_stmt|;
comment|/* address of single precision accumulator */
name|double
modifier|*
name|daddr
decl_stmt|;
comment|/* address of double precision accumulator */
block|}
name|pcb_savacc
union|;
define|#
directive|define
name|FSAVACC
value|pcb_savacc.faddr
define|#
directive|define
name|DSAVACC
value|pcb_savacc.daddr
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

begin_decl_stmt
specifier|extern
name|long
modifier|*
name|user_psl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|aston
parameter_list|()
value|{ \ 	u.u_pcb.pcb_psl |= PSL_SFE; \ 	if ((int)user_psl != 0) \ 		*user_psl |= PSL_SFE; \ }
end_define

begin_define
define|#
directive|define
name|astoff
parameter_list|()
value|{ \ 	u.u_pcb.pcb_psl&= ~ PSL_SFE; \ 	if ((int)user_psl != 0) \ 		*user_psl&= ~PSL_SFE; \ }
end_define

end_unit

