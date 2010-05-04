begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o /dev/null
end_comment

begin_comment
comment|// PR4332
end_comment

begin_decl_stmt
specifier|static
name|int
name|highly_aligned
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4096
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
name|highly_aligned
return|;
block|}
end_function

end_unit

