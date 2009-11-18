begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown --emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "ret i32 10" %t | count 1
end_comment

begin_comment
comment|// Ensure that default after a case range is not ignored.
end_comment

begin_function
specifier|static
name|int
name|f1
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|10
operator|...
literal|0xFFFFFFFF
case|:
return|return
literal|0
return|;
default|default:
return|return
literal|10
return|;
block|}
block|}
end_function

begin_function
name|int
name|g
parameter_list|()
block|{
return|return
name|f1
argument_list|(
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

