begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fms-compatibility -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-MSVC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-eabi -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-EABI
end_comment

begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_function
name|void
name|test_yield_intrinsic
parameter_list|()
block|{
name|__yield
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call void @llvm.arm.hint(i32 1)
end_comment

begin_comment
comment|// CHECK-EABI-NOT: call void @llvm.arm.hint(i32 1)
end_comment

begin_function
name|void
name|wfe
parameter_list|()
block|{
name|__wfe
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call {{.*}} @llvm.arm.hint(i32 2)
end_comment

begin_comment
comment|// CHECK-EABI-NOT: call {{.*}} @llvm.arm.hint(i32 2)
end_comment

begin_function
name|void
name|wfi
parameter_list|()
block|{
name|__wfi
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call {{.*}} @llvm.arm.hint(i32 3)
end_comment

begin_comment
comment|// CHECK-EABI-NOT: call {{.*}} @llvm.arm.hint(i32 3)
end_comment

begin_function
name|void
name|sev
parameter_list|()
block|{
name|__sev
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call {{.*}} @llvm.arm.hint(i32 4)
end_comment

begin_comment
comment|// CHECK-EABI-NOT: call {{.*}} @llvm.arm.hint(i32 4)
end_comment

begin_function
name|void
name|sevl
parameter_list|()
block|{
name|__sevl
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call {{.*}} @llvm.arm.hint(i32 5)
end_comment

begin_comment
comment|// CHECK-EABI-NOT: call {{.*}} @llvm.arm.hint(i32 5)
end_comment

end_unit

