begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|wdleng
argument_list|()
end_macro

begin_comment
comment|/* returns number of bits in a machine integer */
end_comment

begin_comment
comment|/* written so kernighan can tell where he is running */
end_comment

begin_block
block|{
name|int
name|k
decl_stmt|,
name|leng
decl_stmt|;
name|k
operator|=
name|leng
operator|=
literal|1
expr_stmt|;
while|while
condition|(
name|k
operator|=
operator|<<
literal|1
condition|)
name|leng
operator|++
expr_stmt|;
return|return
operator|(
name|leng
operator|)
return|;
block|}
end_block

end_unit

