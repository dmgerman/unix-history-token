begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|unsigned
name|long
name|do_csum
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|buff
parameter_list|,
name|int
name|len
parameter_list|,
name|unsigned
name|long
name|result
parameter_list|)
block|{
if|if
condition|(
literal|2
operator|&
operator|(
name|unsigned
name|long
operator|)
name|buff
condition|)
name|result
operator|+=
literal|1
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

