begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Aemul.c	1.2	90/12/04	*/
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|emul
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
comment|/* /*	Extended precision multiplication. /* /***************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* multiplicand */
specifier|register
name|long
name|Register_11
decl_stmt|;
comment|/* product least */
specifier|register
name|long
name|Register_10
decl_stmt|;
comment|/* product most */
specifier|register
name|long
name|Register_9
decl_stmt|;
comment|/* addend */
specifier|register
name|long
name|Register_8
decl_stmt|;
comment|/* multiplier */
name|quadword
name|result
decl_stmt|;
name|Register_8
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
name|Register_12
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|data
expr_stmt|;
name|Register_9
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|2
argument_list|)
operator|->
name|data
expr_stmt|;
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
asm|asm ("	emul	r8,r12,r9,r10");
asm|asm ("	movpsl	r8");
name|New_cc
argument_list|(
name|Register_8
argument_list|)
expr_stmt|;
name|result
operator|.
name|high
operator|=
name|Register_10
expr_stmt|;
name|result
operator|.
name|low
operator|=
name|Register_11
expr_stmt|;
name|write_quadword
argument_list|(
name|infop
argument_list|,
name|result
argument_list|,
name|operand
argument_list|(
name|infop
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

