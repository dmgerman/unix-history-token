begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980,1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)hpboot.c	7.2 (Berkeley) 8/28/86" */
end_comment

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_comment
comment|/*  * RP??/RM?? 1st level boot program: loads next 7.5Kbytes from  * boot sectors of file system and sets it up to run.  * Reads from the controller and drive passed in from the boot  * rom.  *   R1:  address of the boot device's adapter  *   R2:  controller number of the boot device  *   R3:  unit number of the boot device  *   R5:  software boot control flags  *   R6:  address of driver subroutine from ROM  *   SP:  base address of usable memory + 0x200  */
end_comment

begin_expr_stmt
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
literal|0x70000
comment|/* MBA registers */
operator|.
name|set
name|M_cr
operator|,
literal|4
comment|/* MBA control reg */
operator|.
name|set
name|M_sr
operator|,
literal|8
comment|/* MBA status reg */
operator|.
name|set
name|M_var
operator|,
literal|12
comment|/* MBA virt addr reg */
operator|.
name|set
name|M_bc
operator|,
literal|16
comment|/* MBA byte count reg */
operator|.
name|set
name|M_map
operator|,
literal|0x800
comment|/* start of MBA map reg's */
operator|.
name|set
name|MBAinit
operator|,
literal|1
comment|/* MBA init bit in MBA control reg */
operator|.
name|set
name|MBABUSY
operator|,
literal|0x80000000
comment|/* MBA SR: data transfer busy */
operator|.
name|set
name|pMBABUSY
operator|,
literal|31
comment|/* bit position of  MBABUSY */
comment|/* Drive information */
operator|.
name|set
name|RP
operator|,
literal|0x400
comment|/* start of drive registers */
operator|.
name|set
name|RPDR
operator|,
literal|0x80
comment|/* offset per drive unit */
operator|.
name|set
name|RP_cr
operator|,
literal|0
comment|/* control status register */
operator|.
name|set
name|RP_sr
operator|,
literal|4
comment|/* drive status reg */
operator|.
name|set
name|RP_stk
operator|,
literal|0x14
comment|/* desired track/sector reg */
operator|.
name|set
name|RP_dt
operator|,
literal|0x18
comment|/* drive type reg */
operator|.
name|set
name|RP_off
operator|,
literal|0x24
comment|/* RP offset reg */
operator|.
name|set
name|RP_cyl
operator|,
literal|0x28
comment|/* desired cyl reg */
operator|.
name|set
name|RPBPSECT
operator|,
literal|512
comment|/* bytes per sector */
comment|/* RP?? function codes, status bits  */
operator|.
name|set
name|RP_GO
operator|,
literal|1
comment|/* go */
operator|.
name|set
name|RP_RED
operator|,
literal|070
comment|/* read */
operator|.
name|set
name|RP_DC
operator|,
literal|010
comment|/* drive clear */
operator|.
name|set
name|RP_RIP
operator|,
literal|020
comment|/* read in preset */
operator|.
name|set
name|RP_FMT
operator|,
literal|0x1000
comment|/* format 22 */
operator|.
name|set
name|RP_MOL
operator|,
literal|0x1000
comment|/* medium on line */
operator|.
name|set
name|RP_DRY
operator|,
literal|0200
comment|/* drive ready */
operator|.
name|set
name|RP_ERR
operator|,
literal|040000
comment|/* composite error */
operator|.
name|set
name|RP_pDRY
operator|,
literal|7
comment|/* bit position of RP_DRY */
operator|.
name|set
name|RP_pERR
operator|,
literal|14
comment|/* bit position of RP_ERR */
name|init
operator|:
operator|.
name|word
literal|0
comment|/* entry mask for DEC monitor */
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

begin_label
name|start
label|:
end_label

begin_decl_stmt
name|clrl
name|r10
comment|/* major("/dev/hp0a") */
name|extzv
name|$13
decl_stmt|,
name|$2
decl_stmt|,
name|r1
decl_stmt|,
name|r4
comment|/* get MBA number from R1 */
name|insv
name|r4
decl_stmt|,
name|$24
decl_stmt|,
name|$8
decl_stmt|,
name|r10
comment|/* set MBA number */
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
name|$4
decl_stmt|,
name|r10
comment|/* set partition */
name|movl
name|r5
decl_stmt|,
name|r11
name|movl
name|r1
decl_stmt|,
name|r9
comment|/* save adaptor address */
name|movl
name|r3
decl_stmt|,
name|r8
comment|/* and unit number */
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
name|start1
comment|/* running relocated */
name|start1
range|:
name|movl
name|$MBAinit
decl_stmt|,
name|M_cr
argument_list|(
name|r9
argument_list|)
comment|/* read-in-preset the drive and set format */
name|mull2
name|$RPDR
decl_stmt|,
name|r8
name|movab
name|RP
argument_list|(
name|r9
argument_list|)
decl|[
name|r8
decl|]
decl_stmt|,
name|r8
name|movl
name|$RP_RIP
decl|+
name|RP_GO
decl_stmt|,
name|RP_cr
argument_list|(
name|r8
argument_list|)
name|movl
name|$RP_FMT
decl_stmt|,
name|RP_off
argument_list|(
name|r8
argument_list|)
decl|.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTSIZE
operator|*
name|RPBPSECT
argument_list|)
name|start2
range|:
name|movl
name|$0
decl_stmt|,
name|RP_cyl
argument_list|(
name|r8
argument_list|)
name|movl
name|$1
decl_stmt|,
name|RP_stk
argument_list|(
name|r8
argument_list|)
name|movl
name|$
decl|-
name|PROGSIZE
decl_stmt|,
name|M_bc
argument_list|(
name|r9
argument_list|)
comment|/* set up MASSBUS map for DMA */
name|clrl
name|r0
decl|1
range|:
name|bisl3
name|$0x80000000
decl_stmt|,
name|r0
decl_stmt|,
name|M_map
argument_list|(
name|r9
argument_list|)
decl|[
name|r0
decl|]
name|aobleq
name|$BOOTSIZE
decl_stmt|,
name|r0
decl_stmt|,1b
name|clrl
name|M_var
argument_list|(
name|r9
argument_list|)
name|movl
name|$RP_RED
decl|+
name|RP_GO
decl_stmt|,
name|RP_cr
argument_list|(
name|r8
argument_list|)
name|rprdy
range|:
name|movl
name|RP_sr
argument_list|(
name|r8
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$RP_pDRY
decl_stmt|,
name|r0
decl_stmt|,
name|rprdy
name|bbs
name|$RP_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|rperr
name|rprdy2
range|:
name|bbs
name|$pMBABUSY
decl_stmt|,
name|M_sr
argument_list|(
name|r9
argument_list|)
decl_stmt|,
name|rprdy2
comment|/* Eagles are too fast for the controller. Slow the thing down. */
comment|/* (May not be needed with wait for mba above.) */
name|clrl
name|r3
name|buzz
range|:
name|acbl
name|$2000
decl_stmt|,
name|$1
decl_stmt|,
name|r3
decl_stmt|,
name|buzz
name|bicpsw
name|$2
name|jbr
name|clear
name|rperr
range|:
name|halt
comment|/* clear core and execute program */
name|clear
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
name|end
range|:
end_decl_stmt

end_unit

