begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pcb.h	4.2	%G%	*/
end_comment

begin_comment
comment|/*  * VAX process control block  *  * THE SIZE OF THE pcb, AS INFLUENCED BY THE SIZE OF THE SOFTWARE  * EXTENSION, IS KNOWN IN THE #ifdef FASTVAX'ed DEFINITIONS OF THE  * OFFSETS OF U_ARG and U_QSAV IN THE FILE user.h.  */
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
name|int
name|pcb_r13
decl_stmt|;
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
literal|3
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
name|aston
parameter_list|()
define|\
value|{ \ 		u.u_pcb.pcb_p0lr = (u.u_pcb.pcb_p0lr&~ AST_CLR) | AST_USER; \ 		mtpr(ASTLVL, ASTLVL_USER); \ 	}
end_define

begin_define
define|#
directive|define
name|astoff
parameter_list|()
define|\
value|{ \ 		u.u_pcb.pcb_p0lr = (u.u_pcb.pcb_p0lr&~ AST_CLR) | AST_NONE; \ 		mtpr(ASTLVL, ASTLVL_NONE); \ 	}
end_define

end_unit

