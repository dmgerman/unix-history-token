begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Aadwc.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|adwc
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
comment|/* /*	Add with carry. /*	Note : the play with 'tmp' just before the 'asm' line makes /*		sure that when the adwc opcode is executed, the current /*		carry in psl is the same as the 'offending' process'. /*		Don't change unless you know exactly what you're doing. /* /*****************************/
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
specifier|register
name|long
name|Register_10
decl_stmt|;
specifier|register
name|long
name|tmp
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
name|data
expr_stmt|;
name|Register_11
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
if|if
condition|(
name|carry
condition|)
comment|/* If process' carry set */
name|tmp
operator|=
operator|-
literal|1
expr_stmt|;
else|else
name|tmp
operator|=
literal|0
expr_stmt|;
name|tmp
operator|++
expr_stmt|;
comment|/* 0 => carry set.  1 => carry clear */
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
asm|asm("	adwc	r11,r12");
asm|asm("	movpsl	r11");
name|New_cc
argument_list|(
name|Register_11
argument_list|)
expr_stmt|;
name|write_back
argument_list|(
name|infop
argument_list|,
name|Register_12
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

