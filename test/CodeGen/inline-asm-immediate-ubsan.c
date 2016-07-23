begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:     -fsanitize=signed-integer-overflow \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// Verify we emit constants for "immediate" inline assembly arguments.
end_comment

begin_comment
comment|// Emitting a scalar expression can make the immediate be generated as
end_comment

begin_comment
comment|// overflow intrinsics, if the overflow sanitizer is enabled.
end_comment

begin_comment
comment|// Check both 'i' and 'I':
end_comment

begin_comment
comment|// - 'i' accepts symbolic constants.
end_comment

begin_comment
comment|// - 'I' doesn't, and is really an immediate-required constraint.
end_comment

begin_comment
comment|// See also PR23517.
end_comment

begin_comment
comment|// CHECK-LABEL: @test_inlineasm_i
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int $0", "i{{.*}}"(i32 2)
end_comment

begin_function
name|void
name|test_inlineasm_i
parameter_list|()
block|{
asm|__asm__
specifier|__volatile__
asm|("int %0" :: "i"(1 + 1));
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_inlineasm_I
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int $0", "I{{.*}}"(i32 2)
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int $0", "I{{.*}}"(i32 3)
end_comment

begin_function
name|void
name|test_inlineasm_I
parameter_list|()
block|{
asm|__asm__
specifier|__volatile__
asm|("int %0" :: "I"(1 + 1));
comment|// Also check a C non-ICE.
specifier|static
specifier|const
name|int
name|N
init|=
literal|1
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("int %0" :: "I"(N + 2));
block|}
end_function

end_unit

