begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980,1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)raboot.c	7.2 (Berkeley) 8/28/86" */
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
literal|9
comment|/* major("/dev/ra0a") */
comment|/*  * 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  * Except for MAJOR definition above, should work  * with any disk using 750 boot rom.  */
operator|.
name|set
name|RELOC
operator|,
literal|0x50000
operator|.
name|set
name|BOOTLAST
operator|,
literal|15
comment|/* last boot sector */
operator|.
name|set
name|RABPSECT
operator|,
literal|512
comment|/* bytes per sector */
name|init
operator|:
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

begin_label
name|start
label|:
end_label

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
name|r4
comment|/* get UBA number from R1 */
name|xorb2
name|$0x01
decl_stmt|,
name|r4
comment|/* complement bit */
name|insv
name|r4
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
name|r1
decl_stmt|,
name|r9
comment|/* UNIBUS I/O page address */
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
name|movl
name|r9
decl_stmt|,
name|r1
comment|/* UNIBUS I/O page address */
name|movl
name|r8
decl_stmt|,
name|r2
comment|/* boot device CSR */
name|movl
name|r7
decl_stmt|,
name|r3
comment|/* unit number */
name|jmp
modifier|*
name|$RELOC
decl|+
name|start2
comment|/* now running relocated */
comment|/* bring in the boot program */
name|start2
range|:
comment|/* running relocated */
name|pushr
name|$0xffff
comment|/* BEGIN FIREWALL */
name|movl
name|$1
decl_stmt|,
name|r4
comment|/* first boot sector */
name|clrl
name|r5
comment|/* transfer address */
name|clrl
decl|-
argument_list|(
name|sp
argument_list|)
comment|/* transfer address */
decl|1
range|:
name|movl
name|r4
decl_stmt|,
name|r8
comment|/* requested sector # */
name|jsb
argument_list|(
name|r6
argument_list|)
comment|/* call ROM-based driver */
name|blbs
name|r0
decl_stmt|,2f
name|halt
comment|/* read error */
decl|2
range|:
name|addl2
name|$RABPSECT
decl_stmt|,
name|r5
comment|/* bump address */
name|movl
name|r5
decl_stmt|,
argument_list|(
name|sp
argument_list|)
name|aobleq
name|$BOOTLAST
decl_stmt|,
name|r4
decl_stmt|,1b  	.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTLAST
operator|*
name|RABPSECT
argument_list|)
name|done
range|:
name|tstl
argument_list|(
name|sp
argument_list|)
operator|+
comment|/* pop address */
name|popr
name|$0xffff
comment|/* END FIREWALL */
name|movl
name|$PROGSIZE
decl_stmt|,
name|r4
name|clrcor
range|:
name|clrq
argument_list|(
argument|r4
argument_list|)
name|acbl
name|$RELOC
decl_stmt|,
name|$8
decl_stmt|,
name|r4
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
name|end
range|:
end_decl_stmt

end_unit

