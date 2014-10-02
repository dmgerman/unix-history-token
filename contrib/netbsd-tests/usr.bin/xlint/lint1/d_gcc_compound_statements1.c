begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GCC compound statements */
end_comment

begin_macro
name|foo
argument_list|(
argument|unsigned long z
argument_list|)
end_macro

begin_block
block|{
name|z
operator|=
operator|(
block|{
name|unsigned
name|long
name|tmp
block|;
name|tmp
operator|=
literal|1
block|;
name|tmp
block|; }
operator|)
expr_stmt|;
name|foo
argument_list|(
name|z
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

