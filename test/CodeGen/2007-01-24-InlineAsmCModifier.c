begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that the %c modifier works and strips off any prefixes from
end_comment

begin_comment
comment|// immediates.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: i32 789514
asm|__asm__
specifier|volatile
asm|("/* " "pickANumber" ": %c0 */"::"i"(0xC0C0A));
comment|// Check that non-c modifiers work also
comment|// CHECK: i32 123
asm|__asm__
specifier|volatile
asm|("/* " "pickANumber2 " ": %0 */"::"i"(123));
block|}
end_function

end_unit

