begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	srt0.c	4.5	%G%	*/
end_comment

begin_include
include|#
directive|include
file|"../h/mtpr.h"
end_include

begin_comment
comment|/*  * Startup code for standalone system  * Non-relocating version -- for programs which are loaded by boot  */
end_comment

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
name|globl
name|_configure
operator|.
name|set
name|reloc
operator|,
name|RELOC
operator|.
name|set
name|HIGH
operator|,
literal|31
operator|#
name|mask
end_expr_stmt

begin_for
for|for total disable  entry:	.globl	entry 	.word	0x0 	mtpr	$HIGH
operator|,
name|$IPL
operator|#
name|just
name|in
end_for

begin_case
case|case
name|mtpr
name|$_Scbbase
operator|,
name|$SCBB
name|movl
name|$reloc
operator|-
literal|0x2400
operator|,
name|sp
name|start
case|:
end_case

begin_decl_stmt
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
name|calls
name|$0
decl_stmt|,
name|_configure
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
end_decl_stmt

end_unit

