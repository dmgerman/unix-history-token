begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv6-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|test0
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" :: );
block|}
end_function

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "cc", "memory" );
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "r0", "r1", "r2", "r3");
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "r4", "r5", "r6", "r8");
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "a1", "a2", "a3", "a4");
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "v1", "v2", "v3", "v5");
block|}
end_function

begin_comment
comment|// {} should not be treated as asm variants.
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK: @test4
comment|// CHECK: call void asm sideeffect "vld1.32 {d8[],d9[]},
asm|__asm__
specifier|volatile
asm|(                     "vld1.32 {d8[],d9[]}, [%1,:32] \n\t"                     "vst1.32 {q4},        [%0,:128] \n\t"                     :: "r"(a), "r"(b));
block|}
end_function

end_unit

