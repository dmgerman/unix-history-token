begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    VAX process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|int
name|pcb_ksp
decl_stmt|,
comment|/* kernal stack pointer */
name|pcb_esp
decl_stmt|,
comment|/* exec stack pointer */
name|pcb_ssp
decl_stmt|,
comment|/* supervisor stack pointer */
name|pcb_usp
decl_stmt|,
comment|/* user stack pointer */
name|pcb_r0
decl_stmt|,
name|pcb_r1
decl_stmt|,
name|pcb_r2
decl_stmt|,
name|pcb_r3
decl_stmt|,
name|pcb_r4
decl_stmt|,
name|pcb_r5
decl_stmt|,
name|pcb_r6
decl_stmt|,
name|pcb_r7
decl_stmt|,
name|pcb_r8
decl_stmt|,
name|pcb_r9
decl_stmt|,
name|pcb_r10
decl_stmt|,
name|pcb_r11
decl_stmt|,
name|pcb_r12
decl_stmt|,
name|pcb_r13
decl_stmt|,
name|pcb_pc
decl_stmt|,
comment|/* program counter */
name|pcb_psl
decl_stmt|,
comment|/* program status longword */
name|pcb_p0br
decl_stmt|,
comment|/* seg 0 base register */
name|pcb_p0lr
decl_stmt|,
comment|/* seg 0 length register and astlevel */
name|pcb_p1br
decl_stmt|,
comment|/* seg 1 base register */
name|pcb_p1lr
decl_stmt|,
comment|/* seg 1 length register and pme */
comment|/*    Software pcb (extension)  */
name|pcb_szpt
decl_stmt|;
comment|/* number of pages of user page table */
block|}
struct|;
end_struct

end_unit

