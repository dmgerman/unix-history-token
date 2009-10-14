begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -emit-llvm -o %t
end_comment

begin_function
name|int
name|testBoolAssign
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ss
decl_stmt|;
if|if
condition|(
operator|(
name|ss
operator|=
name|ss
operator|&&
name|ss
operator|)
condition|)
block|{}
return|return
literal|1
return|;
block|}
end_function

end_unit

