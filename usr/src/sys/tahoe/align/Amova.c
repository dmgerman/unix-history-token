begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Amova.c	1.2	90/12/04	*/
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_macro
name|mova
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
comment|/* /*	Move operand address /* /****************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|long
name|Register_11
decl_stmt|;
name|Register_12
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
name|Register_11
operator|=
name|psl
expr_stmt|;
name|Set_psl
argument_list|(
name|r11
argument_list|)
expr_stmt|;
comment|/* restore the user psl */
asm|asm ("	movab	(r12),r11");
comment|/* Moves original addr to r11 */
asm|asm ("	movpsl	r12");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|Register_11
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

