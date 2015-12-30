begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -emit-llvm -o - %s -fsanitize=signed-integer-overflow,integer-divide-by-zero -fsanitize-trap=integer-divide-by-zero | FileCheck %s
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
comment|// CHECK: %[[B1:.*]] = icmp ne i32 %[[D:.*]], 0
comment|// CHECK: %[[B2:.*]] = icmp ne i32 %[[N:.*]], -2147483648
comment|// CHECK: %[[B3:.*]] = icmp ne i32 %[[D]], -1
comment|// CHECK: %[[B4:.*]] = or i1 %[[B2]], %[[B3]]
comment|// CHECK: br i1 %[[B1]], label %[[L1:[0-9a-z_.]*]], label %[[L2:[0-9a-z_.]*]]
comment|// {{^|:}} used to match both Debug form of the captured label
comment|// cont:
comment|// and Release form
comment|// ;<label>:14
comment|// But avoids false matches inside other numbers such as [114 x i8].
comment|// CHECK: {{^|:}}[[L2]]
comment|// CHECK-NEXT: call void @llvm.trap()
comment|// CHECK-NEXT: unreachable
comment|// CHECK: {{^|:}}[[L1]]
comment|// CHECK-NEXT: br i1 %[[B4]], label %[[L3:[0-9a-z_.]*]], label %[[L4:[0-9a-z_.]*]]
comment|// CHECK: {{^|:}}[[L4]]
comment|// CHECK-NEXT: zext
comment|// CHECK-NEXT: zext
comment|// CHECK-NEXT: __ubsan_handle_divrem_overflow
comment|// CHECK: {{^|:}}[[L3]]
comment|// CHECK-NEXT: sdiv i32 %[[N]], %[[D]]
return|return
name|x
operator|/
name|y
return|;
block|}
end_function

end_unit

