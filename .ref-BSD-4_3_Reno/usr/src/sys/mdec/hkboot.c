begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* @(#)hkboot.c	7.2 (Berkeley) 8/28/86 */
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
literal|3
comment|/* major("/dev/hk0a") */
comment|/*  * RK07 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  */
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
comment|/* RK611 registers and bits */
operator|.
name|set
name|HK_cs1
operator|,
literal|0
comment|/* control and status */
operator|.
name|set
name|HK_wc
operator|,
literal|2
comment|/* word count */
operator|.
name|set
name|HK_ba
operator|,
literal|4
comment|/* bus address */
operator|.
name|set
name|HK_da
operator|,
literal|6
comment|/* disk address */
operator|.
name|set
name|HK_cs2
operator|,
literal|8
comment|/* control and status */
operator|.
name|set
name|HK_dc
operator|,
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
comment|/* r8	HK addr */
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
name|r2
decl_stmt|,
name|r8
comment|/* boot device CSR */
name|movl
name|r3
decl_stmt|,
name|r7
comment|/* unit number */
comment|/* select unit, init rk611, set vv in drive; if any errors, give up */
name|movw
name|r7
decl_stmt|,
name|HK_cs2
argument_list|(
name|r8
argument_list|)
name|movw
name|$HK_SEL7
decl|+
name|HK_GO
decl_stmt|,
name|HK_cs1
argument_list|(
name|r8
argument_list|)
decl|1
range|:
name|movw
name|HK_cs1
argument_list|(
name|r8
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
name|r8
argument_list|)
decl|1
range|:
name|movw
name|HK_cs1
argument_list|(
name|r8
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
name|r8
argument_list|)
name|movw
name|$1
decl_stmt|,
name|HK_da
argument_list|(
name|r8
argument_list|)
name|movw
name|$
decl|-
name|PROGSIZE
decl|/2
decl_stmt|,
name|HK_wc
argument_list|(
name|r8
argument_list|)
name|clrl
name|r0
decl|1
range|:
comment|/*	bisl3	$0x80000000,r0,UBA_MAP(r9) */
comment|/*	addl2	$4,r9 */
comment|/*	aobleq	$BOOTSIZE,r0,1b */
name|clrw
name|HK_ba
argument_list|(
argument|r8
argument_list|)
name|movw
name|$HK_SEL7
operator|+
name|HK_RCOM
operator|+
name|HK_GO
decl_stmt|,
name|HK_cs1
argument_list|(
name|r8
argument_list|)
name|hkrdy
range|:
name|movw
name|HK_cs1
argument_list|(
name|r8
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

