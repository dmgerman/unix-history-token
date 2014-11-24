begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fms-compatibility -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-MSVC
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple armv7-eabi -Werror -S -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s -check-prefix CHECK-EABI
end_comment

begin_function
name|void
name|check__dmb
parameter_list|(
name|void
parameter_list|)
block|{
name|__dmb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.dmb(i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '__dmb'
end_comment

begin_function
name|void
name|check__dsb
parameter_list|(
name|void
parameter_list|)
block|{
name|__dsb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.dsb(i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '__dsb'
end_comment

begin_function
name|void
name|check__isb
parameter_list|(
name|void
parameter_list|)
block|{
name|__isb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.isb(i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '__isb'
end_comment

begin_function
name|__INT64_TYPE__
name|check__ldrexd
parameter_list|(
name|void
parameter_list|)
block|{
name|__INT64_TYPE__
name|i64
decl_stmt|;
return|return
name|__ldrexd
argument_list|(
operator|&
name|i64
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.ldrexd(i8* {{.*}})
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '__ldrexd'
end_comment

begin_function
name|unsigned
name|int
name|check_MoveFromCoprocessor
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|_MoveFromCoprocessor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.mrc(i32 0, i32 0, i32 0, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '_MoveFromCoprocessor'
end_comment

begin_function
name|unsigned
name|int
name|check_MoveFromCoprocessor2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|_MoveFromCoprocessor2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.mrc2(i32 0, i32 0, i32 0, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '_MoveFromCoprocessor2'
end_comment

begin_function
name|void
name|check_MoveToCoprocessor
parameter_list|(
name|void
parameter_list|)
block|{
name|_MoveToCoprocessor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.mcr(i32 0, i32 0, i32 0, i32 0, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '_MoveToCoprocessor'
end_comment

begin_function
name|void
name|check_MoveToCoprocessor2
parameter_list|(
name|void
parameter_list|)
block|{
name|_MoveToCoprocessor2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-MSVC: @llvm.arm.mcr2(i32 0, i32 0, i32 0, i32 0, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK-EABI: error: implicit declaration of function '_MoveToCoprocessor2'
end_comment

end_unit

