begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#	srt0.c	1.3	%G%
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
name|_end
operator|.
name|globl
name|_main
operator|.
name|globl
name|__rtt
operator|.
name|globl
name|_edata
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
name|PHYSUMEM
operator|,
literal|0x2013e000
operator|#
name|unibus
name|memory
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
name|$1
operator|,
name|PHYSUBA
operator|+
literal|4
operator|#
name|init
name|clr
case|:
end_case

begin_expr_stmt
name|clrl
argument_list|(
name|r0
argument_list|)
operator|+
name|cmpl
name|r0
operator|,
name|sp
name|jlss
name|clr
name|start
operator|:
name|movl
name|$RELOC
operator|-
literal|0x2000
operator|,
name|sp
name|calls
name|$0
operator|,
name|_main
name|jmp
name|start
name|__rtt
operator|:
operator|.
name|word
literal|0x0
name|jmp
name|start
end_expr_stmt

end_unit

