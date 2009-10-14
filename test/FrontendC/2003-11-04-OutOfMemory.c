begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|schedule_timeout
parameter_list|(
name|signed
name|long
name|timeout
parameter_list|)
block|{
switch|switch
condition|(
name|timeout
condition|)
block|{
case|case
operator|(
call|(
name|long
call|)
argument_list|(
operator|~
literal|0UL
operator|>>
literal|1
argument_list|)
operator|)
case|:
break|break;
block|}
block|}
end_function

end_unit

