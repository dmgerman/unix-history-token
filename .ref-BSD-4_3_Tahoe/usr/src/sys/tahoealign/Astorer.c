begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Astorer.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_macro
name|storer
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
comment|/* /*	Store multiple registers. /* /***************************************/
end_comment

begin_block
block|{
specifier|register
name|int
name|mask
decl_stmt|,
name|next_register
decl_stmt|,
name|new_address
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
operator|&
literal|0x3fff
expr_stmt|;
comment|/* Bits 0 to 13 only */
name|new_address
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|address
expr_stmt|;
name|next_register
operator|=
literal|0
expr_stmt|;
comment|/* Register # */
while|while
condition|(
name|next_register
operator|<=
literal|13
condition|)
block|{
if|if
condition|(
name|mask
operator|&
literal|1
operator|<<
name|next_register
condition|)
block|{
name|put_longword
argument_list|(
name|infop
argument_list|,
name|Register
argument_list|(
name|infop
argument_list|,
name|next_register
argument_list|)
argument_list|,
name|new_address
argument_list|)
expr_stmt|;
name|new_address
operator|+=
literal|4
expr_stmt|;
block|}
name|next_register
operator|++
expr_stmt|;
block|}
block|}
end_block

end_unit

