begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Apusha.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|pusha
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
comment|/* /*	Push address of the operand /* /**************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|new_address
decl_stmt|;
name|new_address
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|address
expr_stmt|;
if|if
condition|(
name|new_address
operator|<
literal|0
condition|)
name|negative_1
expr_stmt|;
else|else
name|negative_0
expr_stmt|;
if|if
condition|(
name|new_address
operator|==
literal|0
condition|)
name|zero_1
expr_stmt|;
else|else
name|zero_0
expr_stmt|;
name|overflow_0
expr_stmt|;
name|carry_1
expr_stmt|;
name|push
argument_list|(
name|infop
argument_list|,
name|new_address
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

