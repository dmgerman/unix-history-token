begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hkboot.c	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * RK07 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  * Always reads from drive 0.  */
end_comment

begin_expr_stmt
operator|.
name|set
name|RELOC
operator|,
literal|0x50000
operator|.
name|set
name|BOOTSIZE
operator|,
literal|15
comment|/* size of boot in sectors */
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
comment|/* RK611 registers and bits */
operator|.
name|set
name|HK
operator|,
literal|0177440
operator|-
literal|0160000
comment|/* address of RK611 */
operator|.
name|set
name|HK_cs1
operator|,
name|HK
operator|+
literal|0
comment|/* control and status */
operator|.
name|set
name|HK_wc
operator|,
name|HK
operator|+
literal|2
comment|/* word count */
operator|.
name|set
name|HK_ba
operator|,
name|HK
operator|+
literal|4
comment|/* bus address */
operator|.
name|set
name|HK_da
operator|,
name|HK
operator|+
literal|6
comment|/* disk address */
operator|.
name|set
name|HK_dc
operator|,
name|HK
operator|+
literal|020
comment|/* desired cylinder */
operator|.
name|set
name|HKBPSECT
operator|,
literal|512
comment|/* bytes per sector */
operator|.
name|set
name|HK_GO
operator|,
literal|1
comment|/* go bit */
operator|.
name|set
name|HK_PACK
operator|,
literal|2
comment|/* pack acknowledge */
operator|.
name|set
name|HK_RCOM
operator|,
literal|020
comment|/* read command */
operator|.
name|set
name|HK_SEL7
operator|,
literal|02000
comment|/* select RK07 disk */
operator|.
name|set
name|HK_pRDY
operator|,
literal|7
comment|/* position of ready bit */
operator|.
name|set
name|HK_pERR
operator|,
literal|15
comment|/* position of error bit */
name|init
operator|:
comment|/* r9	UBA address */
comment|/* r10	umem addr */
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
comment|/* init rk611, set vv in drive 0; if any errors, give up */
name|movw
name|$HK_SEL7
operator|+
name|HK_GO
decl_stmt|,
name|HK_cs1
argument_list|(
name|r10
argument_list|)
decl|1
range|:
name|movw
name|HK_cs1
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HK_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
name|bbs
name|$HK_pERR
decl_stmt|,
name|r0
decl_stmt|,9f
name|movw
name|$HK_SEL7
decl|+
name|HK_PACK
decl|+
name|HK_GO
decl_stmt|,
name|HK_cs1
argument_list|(
name|r10
argument_list|)
decl|1
range|:
name|movw
name|HK_cs1
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HK_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
name|bbc
name|$HK_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|start
decl|9
range|:
name|halt
comment|/* relocate to high core */
name|start
operator|:
name|movl
name|r5
decl_stmt|,
name|r11
comment|/* boot flags */
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
comment|/* bring in the boot program */
operator|.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTSIZE
operator|*
name|HKBPSECT
argument_list|)
name|start2
range|:
name|movw
name|$0
decl_stmt|,
name|HK_dc
argument_list|(
name|r10
argument_list|)
name|movw
name|$1
decl_stmt|,
name|HK_da
argument_list|(
name|r10
argument_list|)
name|movw
name|$
decl|-
name|PROGSIZE
decl|/2
decl_stmt|,
name|HK_wc
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
name|HK_ba
argument_list|(
name|r10
argument_list|)
name|movw
name|$HK_SEL7
decl|+
name|HK_RCOM
decl|+
name|HK_GO
decl_stmt|,
name|HK_cs1
argument_list|(
name|r10
argument_list|)
name|hkrdy
range|:
name|movw
name|HK_cs1
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HK_pRDY
decl_stmt|,
name|r0
decl_stmt|,
name|hkrdy
name|bbs
name|$HK_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|hkerr
name|brw
name|done
name|hkerr
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
comment|/* start loaded program */
name|movl
name|$3
decl_stmt|,
name|r10
comment|/* major("/dev/hk0a") */
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

