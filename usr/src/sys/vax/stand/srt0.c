begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#	srt0.c	4.2	%G%
end_empty

begin_empty
empty|# Startup code for standalone system
end_empty

begin_empty
empty|# Non-relocating version -- for programs which are loaded by boot
end_empty

begin_expr_stmt
operator|.
name|globl
name|_edata
operator|.
name|globl
name|_main
operator|.
name|globl
name|__rtt
operator|.
name|set
name|PHYSUBA
operator|,
literal|0x20006000
operator|#
name|uba
literal|0
operator|.
name|set
name|HIGH
operator|,
literal|31
operator|#
name|mask
end_expr_stmt

begin_for
for|for total disable  	.word	0x0 	mtpr	$HIGH
operator|,
name|$IPL
operator|#
name|just
name|in
end_for

begin_case
case|case
name|movl
name|$RELOC
operator|-
literal|0x2000
operator|,
name|sp
name|movl
name|$1
decl_stmt|,
name|PHYSUBA
decl|+4		#
name|init
name|ubic
range|:
name|movl
operator|*
name|$PHYSUBA
decl_stmt|,
name|r0
decl|# while
argument_list|(
operator|(
name|up
operator|->
name|uba_cnfgr
operator|&
name|UBIC
operator|)
operator|==
literal|0
argument_list|)
name|bitl
name|$0x10000
decl_stmt|,
name|r0
decl|# 	continue
decl_stmt|;
name|jeql
name|ubic
name|movab
name|_edata
decl_stmt|,
name|r0
name|clr
range|:
name|clrl
argument_list|(
name|r0
argument_list|)
operator|+
name|cmpl
name|r0
decl_stmt|,
name|sp
name|jlss
name|clr
name|start
range|:
name|calls
name|$0
decl_stmt|,
name|_main
name|jmp
name|start
name|__rtt
range|:
operator|.
name|word
literal|0x0
name|jmp
name|start
end_case

end_unit

