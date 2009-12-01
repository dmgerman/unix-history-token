begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 1
end_comment

begin_comment
comment|// RUN: grep "ret i32 3" %t | count 1
end_comment

begin_function
name|int
name|f2
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
return|return
literal|3
return|;
case|case
literal|0xFFFFFFFF
operator|...
literal|1
case|:
comment|// This range should be empty because x is unsigned.
return|return
literal|0
return|;
block|}
block|}
end_function

end_unit

