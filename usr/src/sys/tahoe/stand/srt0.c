begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	srt0.c	1.2	86/07/13	*/
end_comment

begin_include
include|#
directive|include
file|"../machine/mtpr.h"
end_include

begin_define
define|#
directive|define
name|LOCORE
end_define

begin_comment
comment|/*  * Startup code for standalone system  */
end_comment

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
name|_openfirst
operator|.
name|globl
name|_start
operator|.
name|set
name|HIGH
operator|,
literal|31
operator|#
name|mask
end_expr_stmt

begin_for
for|for total disable
ifndef|#
directive|ifndef
name|REL
for|.word	0x00			# 'call' by relsrt0.
endif|#
directive|endif
for|_start: 	mtpr	$HIGH
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
operator|,
name|sp
name|movl
name|$0x800
decl_stmt|,
name|r0
comment|/* source address to copy from */
name|movl
name|$RELOC
decl_stmt|,
name|r1
comment|/* destination address */
name|movl
name|aend
decl_stmt|,
name|r2
comment|/* length */
name|addl2
name|r2
decl_stmt|,
name|r0
name|addl2
name|r2
decl_stmt|,
name|r1
name|mvloop
range|:
name|decl
name|r0
name|decl
name|r1
name|movb
argument_list|(
name|r0
argument_list|)
decl_stmt|,
argument_list|(
name|r1
argument_list|)
name|decl
name|r2
name|bgeq
name|mvloop
name|mtpr
name|$0
decl_stmt|,
name|$PACC
name|jmp
modifier|*
name|abegin
name|begin
range|:
name|movl
name|$1
decl_stmt|,
name|_openfirst
name|callf
name|$4
decl_stmt|,
name|_main
name|jmp
name|begin
name|__rtt
range|:
operator|.
name|word
literal|0x0
name|jmp
name|begin
operator|.
name|data
name|abegin
case|:
end_case

begin_expr_stmt
operator|.
name|long
name|begin
name|aend
operator|:
operator|.
name|long
name|_end
operator|-
name|RELOC
operator|-
literal|0x800
name|aedata
operator|:
operator|.
name|long
name|_edata
operator|-
name|RELOC
operator|-
literal|0x800
operator|.
name|globl
name|_entry
operator|.
name|set
name|_entry
operator|,
literal|0x800
end_expr_stmt

end_unit

