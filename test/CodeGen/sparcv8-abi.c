begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define { float, float } @p({ float, float }* byval align 4 %a, { float, float }* byval align 4 %b) #0 {
end_comment

begin_function
name|float
name|__complex__
name|p
parameter_list|(
name|float
name|__complex__
name|a
parameter_list|,
name|float
name|__complex__
name|b
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define { double, double } @q({ double, double }* byval align 8 %a, { double, double }* byval align 8 %b) #0 {
end_comment

begin_function
name|double
name|__complex__
name|q
parameter_list|(
name|double
name|__complex__
name|a
parameter_list|,
name|double
name|__complex__
name|b
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define { i64, i64 } @r({ i64, i64 }* byval align 8 %a, { i64, i64 }* byval align 8 %b) #0 {
end_comment

begin_function
name|long
name|long
name|__complex__
name|r
parameter_list|(
name|long
name|long
name|__complex__
name|a
parameter_list|,
name|long
name|long
name|__complex__
name|b
parameter_list|)
block|{ }
end_function

end_unit

