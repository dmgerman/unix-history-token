begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_comment
comment|// PR1824
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|short
name|y
parameter_list|)
block|{
return|return
name|x
condition|?
else|:
name|y
return|;
block|}
end_function

begin_comment
comment|// rdar://6586493
end_comment

begin_function
name|float
name|test
parameter_list|(
name|float
name|x
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|Y
operator|!=
literal|0
condition|?
else|:
name|x
return|;
block|}
end_function

end_unit

