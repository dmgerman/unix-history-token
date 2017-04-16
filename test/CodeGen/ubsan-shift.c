begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin -fsanitize=shift-exponent,shift-base -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f1
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|c
parameter_list|,
name|int
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i32 %{{.*}}, 31, !nosanitize
comment|// CHECK: icmp ule i32 %{{.*}}, 31, !nosanitize
return|return
literal|1
operator|<<
operator|(
name|c
operator|<<
name|shamt
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f2
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|long
name|c
parameter_list|,
name|int
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i32 %{{.*}}, 63, !nosanitize
comment|// CHECK: icmp ule i64 %{{.*}}, 31, !nosanitize
return|return
literal|1
operator|<<
operator|(
name|c
operator|<<
name|shamt
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f3
end_comment

begin_function
name|unsigned
name|f3
parameter_list|(
name|unsigned
name|c
parameter_list|,
name|int
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i32 %{{.*}}, 31, !nosanitize
comment|// CHECK: icmp ule i32 %{{.*}}, 31, !nosanitize
return|return
literal|1U
operator|<<
operator|(
name|c
operator|<<
name|shamt
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f4
end_comment

begin_function
name|unsigned
name|f4
parameter_list|(
name|unsigned
name|long
name|c
parameter_list|,
name|int
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i32 %{{.*}}, 63, !nosanitize
comment|// CHECK: icmp ule i64 %{{.*}}, 31, !nosanitize
return|return
literal|1U
operator|<<
operator|(
name|c
operator|<<
name|shamt
operator|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f5
end_comment

begin_function
name|int
name|f5
parameter_list|(
name|int
name|c
parameter_list|,
name|long
name|long
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i64 %{{[0-9]+}}, 31, !nosanitize
comment|//
comment|// CHECK: sub nuw nsw i32 31, %sh_prom, !nosanitize
comment|// CHECK: lshr i32 %{{.*}}, %shl.zeros, !nosanitize
return|return
name|c
operator|<<
name|shamt
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f6
end_comment

begin_function
name|int
name|f6
parameter_list|(
name|int
name|c
parameter_list|,
name|int
name|shamt
parameter_list|)
block|{
comment|// CHECK: icmp ule i32 %[[WIDTH:.*]], 31, !nosanitize
comment|//
comment|// CHECK: sub nuw nsw i32 31, %[[WIDTH]], !nosanitize
comment|// CHECK: lshr i32 %{{.*}}, %shl.zeros, !nosanitize
return|return
name|c
operator|<<
name|shamt
return|;
block|}
end_function

end_unit

