begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)rlboot.c	7.3 (Berkeley) 2/21/87" */
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
literal|14
comment|/* major("/dev/rl0a") */
comment|/*  * RL02 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  */
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
name|HL_RDY
operator|,
literal|0200
comment|/* READY  */
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
comment|/* r8	RL addr */
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
name|cvtbl
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
name|ashl
name|$8
decl_stmt|,
name|r3
decl_stmt|,
name|r7
comment|/* unit number, shifted for HL_cs */
comment|/* init rl11, and drive, don't check for any errors now */
name|movw
name|$HL_RESET
decl_stmt|,
name|HL_da
argument_list|(
name|r8
argument_list|)
name|bisw3
name|r7
decl_stmt|,
name|$HL_GSTAT
decl_stmt|,
name|HL_cs
argument_list|(
name|r8
argument_list|)
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
name|r8
argument_list|)
comment|/* seek to cylinder 0 */
name|bisw3
name|r7
decl_stmt|,
name|$HL_SEEK
decl_stmt|,
name|HL_cs
argument_list|(
name|r8
argument_list|)
decl|1
range|:
name|movw
name|HL_cs
argument_list|(
name|r8
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
name|r8
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
name|HL_ba
argument_list|(
name|r8
argument_list|)
name|bisw3
name|r7
decl_stmt|,
name|$HL_RCOM
decl_stmt|,
name|HL_cs
argument_list|(
name|r8
argument_list|)
decl|1
range|:
name|movw
name|HL_cs
argument_list|(
name|r8
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HL_pRDY
decl_stmt|,
name|r0
decl_stmt|,1b
name|bbc
name|$HL_pERR
decl_stmt|,
name|r0
decl_stmt|,
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

