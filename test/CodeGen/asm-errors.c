begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple i386-apple-darwin10 -emit-obj %s> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|// CHECK: error: unrecognized instruction
asm|__asm__ ("abc incl    %0" : "+r" (X));
return|return
name|X
return|;
block|}
end_function

end_unit

