begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 2
end_comment

begin_comment
comment|// RUN: grep "ret i32 3" %t | count 2
end_comment

begin_comment
comment|// This generated incorrect code because of poor switch chaining.
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
literal|3
return|;
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

begin_comment
comment|// This just asserted because of the way case ranges were calculated.
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
literal|3
return|;
case|case
literal|10
operator|...
operator|-
literal|1
case|:
return|return
literal|0
return|;
block|}
block|}
end_function

end_unit

