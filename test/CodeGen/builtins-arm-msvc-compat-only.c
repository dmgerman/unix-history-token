begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fms-extensions -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-MSVC
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-eabi -emit-llvm %s -o /dev/null 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix CHECK-EABI
end_comment

begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_function
name|void
name|emit
parameter_list|()
block|{
name|__emit
argument_list|(
literal|0xdefe
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call void asm sideeffect ".inst.n 0xDEFE", ""()
end_comment

begin_comment
comment|// CHECK-EABI: warning: implicit declaration of function '__emit' is invalid in C99
end_comment

begin_function
name|void
name|emit_truncated
parameter_list|()
block|{
name|__emit
argument_list|(
literal|0x11110000
argument_list|)
expr_stmt|;
comment|// movs r0, r0
block|}
end_function

begin_comment
comment|// CHECK-MSVC: call void asm sideeffect ".inst.n 0x0", ""()
end_comment

end_unit

