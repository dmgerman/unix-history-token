begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	fort.h	4.1	85/03/19	*/
end_comment

begin_comment
comment|/*	machine dependent file  */
end_comment

begin_macro
name|label
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"L%d:\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tlabel
argument_list|()
end_macro

begin_block
block|{
name|lccopy
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|":\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

