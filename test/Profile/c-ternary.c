begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.11.0 -x c %s -o - -emit-llvm -fprofile-instrument=clang | FileCheck %s
end_comment

begin_comment
comment|// PR32019: Clang can lower some ternary operator expressions to select
end_comment

begin_comment
comment|// instructions. Make sure we only increment the profile counter for the
end_comment

begin_comment
comment|// condition when the condition evaluates to true.
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: [[TOBOOL:%.*]] = icmp ne i32 %{{.*}}, 0
comment|// CHECK-NEXT: [[STEP:%.*]] = zext i1 [[TOBOOL]] to i64
comment|// CHECK-NEXT: [[COUNTER:%.*]] = load i64, i64* getelementptr inbounds ([2 x i64], [2 x i64]* @__profc_f1, i64 0, i64 1)
comment|// CHECK-NEXT: add i64 [[COUNTER]], [[STEP]]
comment|// CHECK: [[COND:%.*]] = select i1 [[TOBOOL]], i32 0, i32 1
return|return
name|x
condition|?
literal|0
else|:
literal|1
return|;
comment|// CHECK: ret i32 [[COND]]
block|}
end_function

end_unit

