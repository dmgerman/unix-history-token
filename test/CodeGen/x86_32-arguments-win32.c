begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -triple i386-pc-win32 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define i64 @f1_1()
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f1_2(%struct.s1* byval align 4 %a0)
end_comment

begin_struct
struct|struct
name|s1
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s1
name|f1_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f1_2
parameter_list|(
name|struct
name|s1
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f2_1()
end_comment

begin_struct
struct|struct
name|s2
block|{
name|short
name|a
decl_stmt|;
name|short
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s2
name|f2_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @f3_1()
end_comment

begin_struct
struct|struct
name|s3
block|{
name|char
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s3
name|f3_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @f4_1()
end_comment

begin_struct
struct|struct
name|s4
block|{
name|char
name|a
range|:
literal|4
decl_stmt|;
name|char
name|b
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s4
name|f4_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @f5_1()
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f5_2(%struct.s5* byval align 4)
end_comment

begin_struct
struct|struct
name|s5
block|{
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s5
name|f5_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f5_2
parameter_list|(
name|struct
name|s5
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f6_1()
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f6_2(%struct.s6* byval align 4 %a0)
end_comment

begin_struct
struct|struct
name|s6
block|{
name|float
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s6
name|f6_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f6_2
parameter_list|(
name|struct
name|s6
name|a0
parameter_list|)
block|{}
end_function

end_unit

