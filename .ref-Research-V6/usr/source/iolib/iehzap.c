begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|IEHzap
argument_list|(
argument|s
argument_list|)
end_macro

begin_block
block|{
name|write
argument_list|(
literal|2
argument_list|,
name|s
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|": argument count wrong\n"
argument_list|,
literal|23
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|"That's all, folks\n"
argument_list|,
literal|18
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

