begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Aadda.c	1.2	90/12/04	*/
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|adda
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
comment|/* /*	Add address. /* /************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|result
decl_stmt|;
name|result
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data
operator|+
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|result
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

