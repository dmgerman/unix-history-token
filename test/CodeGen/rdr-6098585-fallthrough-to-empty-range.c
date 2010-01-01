begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32 %" %t
end_comment

begin_comment
comment|// Make sure return is not constant (if empty range is skipped or miscompiled)
end_comment

begin_function
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
case|case
literal|2
case|:
comment|// fallthrough empty range
case|case
literal|10
operator|...
literal|9
case|:
return|return
literal|10
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function

end_unit

