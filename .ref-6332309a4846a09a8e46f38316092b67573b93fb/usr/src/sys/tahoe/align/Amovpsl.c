begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Amovpsl.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|movpsl
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
comment|/* /*	Move PSL to some place. /* /************************************/
end_comment

begin_block
block|{
name|write_back
argument_list|(
name|infop
argument_list|,
name|psl
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

