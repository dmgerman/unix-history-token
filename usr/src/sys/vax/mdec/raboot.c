begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	raboot.c	4.2	83/02/20	*/
end_comment

begin_comment
comment|/*  * UDA50 1st level boot program: loads next 7.5Kbytes from  * boot sector of file system and sets it up to run.  *	UNTESTED  */
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
name|r9
name|movc3
name|$end
decl_stmt|,
argument_list|(
name|r9
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
name|start2
range|:
comment|/* running relocated */
name|clrl
name|r9
comment|/* transfer counter */
name|clrl
name|r5
comment|/* transfer address */
name|movl
name|$1
decl_stmt|,
name|r8
comment|/* requested sector # */
decl|1
range|:
name|pushr
name|$0xffff
comment|/* BEGIN FIREWALL */
name|calls
name|$0
decl_stmt|,
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
name|popr
name|$0xffff
comment|/* END FIREWALL */
name|incl
name|r8
comment|/* bump sector */
name|addl2
name|$RABPSECT
decl_stmt|,
name|r5
comment|/* bump memory location */
name|aobleq
name|BOOTSIZE
decl_stmt|,
name|r9
decl_stmt|,1b  	.
name|set
name|PROGSIZE
decl_stmt|,
argument_list|(
name|BOOTSIZE
operator|*
name|RABPSECT
argument_list|)
name|done
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
comment|/* start loaded program */
name|movl
name|$9
decl_stmt|,
name|r10
comment|/* major("/dev/ra0a") */
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

