begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O2 -S -o - %s | grep {llvm.cttz.i64} | count 2
end_comment

begin_comment
comment|// RUN: %llvmgcc -O2 -S -o - %s | not grep {lshr}
end_comment

begin_function
name|int
name|bork
parameter_list|(
name|unsigned
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|__builtin_ctzll
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

