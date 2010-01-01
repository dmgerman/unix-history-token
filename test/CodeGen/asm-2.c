begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t -triple i386-pc-linux-gnu -O2
end_comment

begin_comment
comment|// RUN: not grep "load" %t
end_comment

begin_comment
comment|//<rdar://problem/6841383>
end_comment

begin_function
name|int
name|cpuid
parameter_list|(
name|unsigned
name|data
parameter_list|)
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
asm|asm("xyz" :"=a"(a), "=d"(b) : "a"(data));
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

end_unit

