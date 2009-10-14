begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
specifier|extern
name|__inline
name|long
name|int
name|__strtol_l
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|long
name|int
name|__strtol_l
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

