begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Acmpf2.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|cmpf2
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
comment|/* /*	Compare operand 1 with operand2 (float). /* /*************************************************/
end_comment

begin_block
block|{
specifier|register
name|float
modifier|*
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|float
modifier|*
name|Register_11
decl_stmt|;
specifier|register
name|long
name|Register_10
decl_stmt|;
name|Register_12
operator|=
operator|(
name|float
operator|*
operator|)
operator|&
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
expr_stmt|;
name|Register_11
operator|=
operator|(
name|float
operator|*
operator|)
operator|&
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data
expr_stmt|;
if|if
condition|(
name|reserved
argument_list|(
operator|*
operator|(
name|long
operator|*
operator|)
name|Register_12
argument_list|)
operator|||
name|reserved
argument_list|(
operator|*
operator|(
name|long
operator|*
operator|)
name|Register_11
argument_list|)
condition|)
block|{
name|exception
argument_list|(
name|infop
argument_list|,
name|ILL_OPRND
argument_list|)
expr_stmt|;
block|}
name|Register_10
operator|=
name|psl
expr_stmt|;
name|Set_psl
argument_list|(
name|r10
argument_list|)
expr_stmt|;
comment|/* restore the user psl */
asm|asm ("	cmpf2	(r12),(r11)");
asm|asm ("	movpsl	r10");
name|New_cc
argument_list|(
name|Register_10
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

