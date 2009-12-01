begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32 10" %t
end_comment

begin_comment
comment|// Ensure that this doesn't compile to infinite loop in g() due to
end_comment

begin_comment
comment|// miscompilation of fallthrough from default to a (tested) case
end_comment

begin_comment
comment|// range.
end_comment

begin_function
specifier|static
name|int
name|f0
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
default|default:
name|x
operator|+=
literal|1
expr_stmt|;
case|case
literal|10
operator|...
literal|0xFFFFFFFF
case|:
return|return
literal|0
return|;
block|}
block|}
end_function

begin_function
name|int
name|g
parameter_list|()
block|{
name|f0
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|10
return|;
block|}
end_function

end_unit

