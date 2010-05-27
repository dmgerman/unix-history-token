begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Radar 8026855
end_comment

begin_function
name|int
name|test
parameter_list|(
name|void
modifier|*
name|src
parameter_list|)
block|{
specifier|register
name|int
name|w0
name|asm
argument_list|(
literal|"0"
argument_list|)
decl_stmt|;
comment|// CHECK: call i32 asm sideeffect
asm|asm ("ldr %0, [%1]": "=r" (w0): "r" (src));
comment|// The asm to read the value of w0 has a sideeffect for a different reason
comment|// (see 2010-05-18-asmsched.c) but that's not what this is testing for.
comment|// CHECK: call i32 asm
return|return
name|w0
return|;
block|}
end_function

end_unit

