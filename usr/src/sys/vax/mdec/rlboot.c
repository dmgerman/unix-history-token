begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	rlboot.c	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * RL02 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  * Always reads from drive 0.  * 	UNTESTED  */
end_comment

begin_expr_stmt
operator|.
name|set
name|BOOTSIZE
operator|,
literal|15
comment|/* 15 ``sectors'' */
operator|.
name|set
name|RELOC
operator|,
literal|0x50000
operator|.
name|set
name|SID
operator|,
literal|62
comment|/* system ID register */
comment|/* UBA registers */
operator|.
name|set
name|UBA_CNFGR
operator|,
literal|0
comment|/* UBA configuration register */
operator|.
name|set
name|UBA_CR
operator|,
literal|4
comment|/* UBA control register offset */
operator|.
name|set
name|UBA_MAP
operator|,
literal|0x800
comment|/* UBA offset to map reg's */
operator|.
name|set
name|UBAinit
operator|,
literal|1
comment|/* UBA init bit in UBA control reg */
operator|.
name|set
name|pUBIC
operator|,
literal|16
comment|/* Unibus init complete */
comment|/* RL11 registers and bits */
operator|.
name|set
name|HL
operator|,
literal|0174400
operator|-
literal|0160000
comment|/* address of RL11 */
operator|.
name|set
name|HLBPSECT
operator|,
literal|512
comment|/* sector size in bytes (kludge) */
operator|.
name|set
name|HL_cs
operator|,
name|HL
operator|+
literal|0
comment|/* control and status */
operator|.
name|set
name|HL_ba
operator|,
name|HL
operator|+
literal|2
comment|/* bus address */
operator|.
name|set
name|HL_da
operator|,
name|HL
operator|+
literal|4
comment|/* disk address */
operator|.
name|set
name|HL_wc
operator|,
name|HL
operator|+
literal|6
comment|/* word count */
operator|.
name|set
name|HL_GO
operator|,
literal|0
comment|/* go bit */
operator|.
name|set
name|HL_RCOM
operator|,
literal|014
comment|/* read command */
operator|.
name|set
name|HL_SEEK
operator|,
literal|06
comment|/* seek */
operator|.
name|set
name|HL_RESET
operator|,
literal|013
comment|/* reset drive */
operator|.
name|set
name|HL_GSTAT
operator|,
literal|04
comment|/* get status command */
operator|.
name|set
name|HL_pRDY
operator|,
literal|7
comment|/* position of ready bit */
operator|.
name|set
name|HL_pERR
operator|,
literal|15
comment|/* position of error bit */
name|init
operator|:
comment|/* r9   UBA address */
comment|/* r10  umem addr */
operator|.
name|word
literal|0
comment|/* entry mask for dec monitor */
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nop
comment|/* some no-ops for 750 boot to skip */
name|nop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get cpu type and find the first uba */
end_comment

begin_decl_stmt
name|mfpr
name|$SID
decl_stmt|,
name|r0
name|extzv
name|$24
decl_stmt|,
name|$8
decl_stmt|,
name|r0
decl_stmt|,
name|r0
comment|/* get cpu type */
name|ashl
name|$2
decl_stmt|,
name|r0
decl_stmt|,
name|r1
name|movab
name|physUBA
decl_stmt|,
name|r2
comment|/* get physUBA[cpu] */
name|addl2
name|r1
decl_stmt|,
name|r2
name|movl
argument_list|(
name|r2
argument_list|)
decl_stmt|,
name|r9
name|movab
name|physUMEM
decl_stmt|,
name|r2
comment|/* get physUMEM[cpu] */
name|addl2
name|r1
decl_stmt|,
name|r2
name|movl
argument_list|(
name|r2
argument_list|)
decl_stmt|,
name|r10
comment|/* if 780, init uba */
name|cmpl
name|r0
decl_stmt|,
name|$1
name|bneq
decl|2f
name|movl
name|$UBAinit
decl_stmt|,
name|UBA_CR
argument_list|(
name|r9
argument_list|)
decl|1
range|:
name|bbc
name|$pUBIC
decl_stmt|,
name|UBA_CNFGR
argument_list|(
name|r9
argument_list|)
decl_stmt|,1b 2
range|:
comment|/* init rl11, and drive 0, don't check for any errors now */
name|movw
name|$HL_RESET
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
name|movw
name|$HL_GSTAT
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
comment|/* relocate to high core */
name|start
range|:
name|movl
name|r5
decl_stmt|,
name|r11
comment|/* save boot flags */
name|movl
name|$RELOC
decl_stmt|,
name|sp
name|moval
name|init
decl_stmt|,
name|r6
name|movc3
name|$end
decl_stmt|,
argument_list|(
name|r6
argument_list|)
decl_stmt|,
argument_list|(
name|sp
argument_list|)
name|jmp
modifier|*
name|$RELOC
decl|+
name|start2
comment|/* now running relocated */
comment|/* read in the boot program */
operator|.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTSIZE
operator|*
name|HLBPSECT
argument_list|)
name|start2
range|:
name|movw
name|$1
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
comment|/* seek to cylinder 0 */
name|movw
name|$HL_SEEK
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
decl|1
range|:
name|movw
name|HL_cs
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HL_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
name|bbs
name|$HL_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|hlerr
comment|/* Rl has 256 byte sectors */
name|movw
name|$2
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
comment|/* read program */
name|movw
name|$
decl|-
name|PROGSIZE
decl|/2
decl_stmt|,
name|HL_wc
argument_list|(
name|r10
argument_list|)
name|clrl
name|r0
decl|1
range|:
name|bisl3
name|$0x80000000
decl_stmt|,
name|r0
decl_stmt|,
name|UBA_MAP
argument_list|(
name|r9
argument_list|)
name|addl2
name|$4
decl_stmt|,
name|r9
name|aobleq
name|$BOOTSIZE
decl_stmt|,
name|r0
decl_stmt|,1b
name|clrw
name|HL_ba
argument_list|(
name|r10
argument_list|)
name|movw
name|$HL_RCOM
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
decl|1
range|:
name|movw
name|HL_cs
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HL_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
name|bbs
name|$HL_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|hlerr
name|brw
name|done
name|hlerr
range|:
name|halt
comment|/* ungraceful */
name|done
operator|:
name|movl
name|$PROGSIZE
decl_stmt|,
name|r3
name|clrcor
range|:
name|clrq
argument_list|(
argument|r3
argument_list|)
name|acbl
name|$RELOC
decl_stmt|,
name|$8
decl_stmt|,
name|r3
decl_stmt|,
name|clrcor
comment|/* run loaded program */
name|movl
name|$14
decl_stmt|,
name|r10
comment|/* major("/dev/hl0a") */
name|calls
name|$0
decl_stmt|,
modifier|*
name|$0
name|brw
name|start2
name|physUBA
range|:
operator|.
name|long
literal|0
operator|.
name|long
literal|0x20006000
comment|/* 11/780 */
operator|.
name|long
literal|0xf30000
comment|/* 11/750 */
operator|.
name|long
literal|0xf26000
comment|/* 11/730 */
name|physUMEM
operator|:
operator|.
name|long
literal|0
operator|.
name|long
literal|0x2013e000
comment|/* 11/780 */
operator|.
name|long
literal|0xffe000
comment|/* 11/750 */
operator|.
name|long
literal|0xffe000
comment|/* 11/730 */
name|end
operator|:
end_decl_stmt

end_unit

