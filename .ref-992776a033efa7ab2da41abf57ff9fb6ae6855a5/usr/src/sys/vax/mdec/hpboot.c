begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hpboot.c	4.2	83/02/27	*/
end_comment

begin_comment
comment|/*  * RP??/RM?? 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  * Always reads from drive 0.  */
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
comment|/* Drive information */
operator|.
name|set
name|RP
operator|,
literal|0x400
comment|/* start of drive registers */
operator|.
name|set
name|RP_cr
operator|,
name|RP
operator|+
literal|0
comment|/* control status register */
operator|.
name|set
name|RP_sr
operator|,
name|RP
operator|+
literal|4
comment|/* drive status reg */
operator|.
name|set
name|RP_stk
operator|,
name|RP
operator|+
literal|0x14
comment|/* desired track/sector reg */
operator|.
name|set
name|RP_dt
operator|,
name|RP
operator|+
literal|0x18
comment|/* drive type reg */
operator|.
name|set
name|RP_off
operator|,
name|RP
operator|+
literal|0x24
comment|/* RP offset reg */
operator|.
name|set
name|RP_cyl
operator|,
name|RP
operator|+
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
name|movl
name|r5
decl_stmt|,
name|r11
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
comment|/* get cpu type */
operator|.
name|set
name|SID
decl_stmt|,0x3e
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
name|ashl
name|$2
decl_stmt|,
name|r0
decl_stmt|,
name|r1
comment|/* get mba location and init it */
name|moval
name|physMBA
decl_stmt|,
name|r2
name|addl3
name|r1
decl_stmt|,
name|r2
decl_stmt|,
name|r3
name|movl
argument_list|(
name|r3
argument_list|)
decl_stmt|,
name|r9
name|movl
name|$MBAinit
decl_stmt|,
name|M_cr
argument_list|(
name|r9
argument_list|)
comment|/* read-in-preset the drive and set format */
name|movl
name|$RP_RIP
decl|+
name|RP_GO
decl_stmt|,
name|RP_cr
argument_list|(
name|r9
argument_list|)
name|movl
name|$RP_FMT
decl_stmt|,
name|RP_off
argument_list|(
name|r9
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
name|r9
argument_list|)
name|movl
name|$1
decl_stmt|,
name|RP_stk
argument_list|(
name|r9
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
name|r9
argument_list|)
name|rprdy
range|:
name|movl
name|RP_sr
argument_list|(
name|r9
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
name|clrl
name|r3
comment|/* Eagle's are too fast for the controller. Slow the thing down. */
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
name|clrl
name|r10
comment|/* major("/dev/hp0a") */
name|calls
name|$0
decl_stmt|,
modifier|*
name|$0
name|brw
name|start2
operator|.
name|align
decl|2
name|physMBA
range|:
operator|.
name|long
literal|0
operator|.
name|long
literal|0x20010000
operator|.
name|long
literal|0xf28000
name|end
operator|:
end_decl_stmt

end_unit

