begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Abicpsw.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|bicpsw
argument_list|(
argument|infop
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Bits clear in PSW. /* /*************************************/
end_comment

begin_block
block|{
specifier|register
name|int
name|mask
decl_stmt|;
name|mask
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
expr_stmt|;
name|psl
operator|&=
operator|~
operator|(
name|mask
operator|&
literal|0x7f
operator|)
expr_stmt|;
block|}
end_block

end_unit

