begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsanitize=shift-base -emit-llvm %s -o - -triple x86_64-linux-gnu -fwrapv | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: @lsh_overflow
end_comment

begin_function
name|int
name|lsh_overflow
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-NOT: br
comment|// CHECK-NOT: call void @__ubsan_
comment|// CHECK-NOT: call void @llvm.trap
comment|// CHECK:      %[[RET:.*]] = shl i32
comment|// CHECK-NEXT: ret i32 %[[RET]]
return|return
name|a
operator|<<
name|b
return|;
block|}
end_function

end_unit

