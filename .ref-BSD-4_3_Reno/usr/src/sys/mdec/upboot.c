begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)upboot.c	7.3 (Berkeley) 2/21/87" */
end_comment

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_expr_stmt
operator|.
name|set
name|MAJOR
operator|,
literal|2
comment|/* major("/dev/up0a") */
comment|/*  * UP 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  * Always reads from drive 0.  */
operator|.
name|set
name|BOOTSIZE
operator|,
literal|15
comment|/* size of boot in sectors */
operator|.
name|set
name|RELOC
operator|,
literal|0x50000
operator|.
name|set
name|UPBPSECT
operator|,
literal|512
comment|/* bytes per sector */
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
comment|/* UP registers and bits */
operator|.
name|set
name|UP_cs1
operator|,
literal|0
comment|/* control and status */
operator|.
name|set
name|UP_wc
operator|,
literal|2
comment|/* word count */
operator|.
name|set
name|UP_ba
operator|,
literal|4
comment|/* bus address */
operator|.
name|set
name|UP_da
operator|,
literal|6
comment|/* disk address */
operator|.
name|set
name|UP_cs2
operator|,
literal|010
comment|/* cs2 register */
operator|.
name|set
name|UP_of
operator|,
literal|032
comment|/* offset register */
operator|.
name|set
name|UP_dc
operator|,
literal|034
comment|/* desired cylinder */
operator|.
name|set
name|UP_hr
operator|,
literal|036
comment|/* holding register */
operator|.
name|set
name|UP_GO
operator|,
literal|1
comment|/* go bit */
operator|.
name|set
name|UP_PACK
operator|,
literal|022
comment|/* pack acknowledge */
operator|.
name|set
name|UP_DCLR
operator|,
literal|010
comment|/* drive clear */
operator|.
name|set
name|UP_PRESET
operator|,
literal|020
comment|/* read-in-preset */
operator|.
name|set
name|UP_RCOM
operator|,
literal|070
comment|/* read command */
operator|.
name|set
name|UPCS2_CLR
operator|,
literal|040
operator|.
name|set
name|UP_pRDY
operator|,
literal|7
comment|/* position of ready bit */
operator|.
name|set
name|UP_pERR
operator|,
literal|15
comment|/* position of error bit */
operator|.
name|set
name|UP_FMT22
operator|,
literal|010000
name|init
operator|:
comment|/* r9   UBA address */
comment|/* r8	UP addr */
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

begin_decl_stmt
name|movl
name|$MAJOR
decl_stmt|,
name|r10
comment|/* major("/dev/xx0a") */
name|extzv
name|$18
decl_stmt|,
name|$1
decl_stmt|,
name|r1
decl_stmt|,
name|r9
comment|/* get UBA number from R1 */
name|xorb2
name|$0x01
decl_stmt|,
name|r9
comment|/* complement bit */
name|insv
name|r9
decl_stmt|,
name|$24
decl_stmt|,
name|$8
decl_stmt|,
name|r10
comment|/* set UBA number */
name|insv
name|r3
decl_stmt|,
name|$16
decl_stmt|,
name|$8
decl_stmt|,
name|r10
comment|/* drive number */
name|extzv
name|$12
decl_stmt|,
name|$4
decl_stmt|,
name|r5
decl_stmt|,
name|r4
comment|/* get partition from r5 */
name|bicw2
name|$0xf000
decl_stmt|,
name|r5
comment|/* remove from r5 */
name|insv
name|r4
decl_stmt|,
name|$8
decl_stmt|,
name|$8
decl_stmt|,
name|r10
comment|/* set partition */
name|movl
name|r5
decl_stmt|,
name|r11
comment|/* boot flags */
name|movl
name|r2
decl_stmt|,
name|r8
comment|/* boot device CSR */
name|brw
name|start0
comment|/*  * Leave space for pack label.  */
name|pad
range|:
operator|.
name|space
name|LABELOFFSET
operator|-
operator|(
name|pad
operator|-
name|init
operator|)
name|packlabel
operator|:
operator|.
name|space
name|d_end_
name|start0
operator|:
name|movl
name|physUBA
index|[
name|r9
index|]
decl_stmt|,
name|r9
comment|/* UNIBUS adaptor address */
name|movl
name|r3
decl_stmt|,
name|r7
comment|/* unit number */
name|movl
name|$RELOC
decl_stmt|,
name|sp
name|moval
name|init
decl_stmt|,
name|r4
name|movc3
name|$end
decl_stmt|,
argument_list|(
name|r4
argument_list|)
decl_stmt|,
argument_list|(
name|sp
argument_list|)
comment|/* init up, set vv in drive; if any errors, give up */
comment|/* probably unneeded: rom should have already done this */
name|bisw3
name|r7
decl_stmt|,
name|$UPCS2_CLR
decl_stmt|,
name|UP_cs2
argument_list|(
name|r8
argument_list|)
name|movw
name|$UP_DCLR
decl|+
name|UP_GO
decl_stmt|,
name|UP_cs1
argument_list|(
name|r8
argument_list|)
name|movw
name|$UP_PRESET
decl|+
name|UP_GO
decl_stmt|,
name|UP_cs1
argument_list|(
name|r8
argument_list|)
name|movw
name|$UP_FMT22
decl_stmt|,
name|UP_of
argument_list|(
name|r8
argument_list|)
decl|1
range|:
name|movw
name|UP_cs1
argument_list|(
name|r8
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$UP_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
comment|/* relocate to high core */
name|start
range|:
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
operator|.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTSIZE
operator|*
name|UPBPSECT
argument_list|)
name|start2
range|:
name|movw
name|$0
decl_stmt|,
name|UP_dc
argument_list|(
name|r8
argument_list|)
name|movw
name|$1
decl_stmt|,
name|UP_da
argument_list|(
name|r8
argument_list|)
name|movw
name|$
decl|-
name|PROGSIZE
decl|/2
decl_stmt|,
name|UP_wc
argument_list|(
name|r8
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
name|UP_ba
argument_list|(
name|r8
argument_list|)
name|movw
name|$UP_RCOM
decl|+
name|UP_GO
decl_stmt|,
name|UP_cs1
argument_list|(
name|r8
argument_list|)
name|uprdy
range|:
name|movw
name|UP_cs1
argument_list|(
name|r8
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$UP_pRDY
decl_stmt|,
name|r0
decl_stmt|,
name|uprdy
name|clear
range|:
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
literal|0xf30000
comment|/* uba0 */
operator|.
name|long
literal|0xf32000
comment|/* uba1 */
name|end
operator|:
end_decl_stmt

end_unit

