begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc_only -std=gnu99 %s -S |& grep {warning: alignment for}
end_comment

begin_comment
comment|// ppc does not support this feature, and gets a fatal error at runtime.
end_comment

begin_comment
comment|// XFAIL: powerpc
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|var
index|[
name|a
index|]
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
return|return
literal|4
return|;
block|}
end_function

end_unit

