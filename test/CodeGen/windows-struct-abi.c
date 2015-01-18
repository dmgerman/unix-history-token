begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows-itanium -emit-llvm -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|f1
block|{
name|float
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|f1
name|return_f1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define i32 @return_f1()
end_comment

begin_function
name|void
name|receive_f1
parameter_list|(
name|struct
name|f1
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @receive_f1(%struct.f1* byval align 4 %a0)
end_comment

begin_struct
struct|struct
name|f2
block|{
name|float
name|f
decl_stmt|;
name|float
name|g
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|f2
name|return_f2
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @return_f2()
end_comment

begin_function
name|void
name|receive_f2
parameter_list|(
name|struct
name|f2
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @receive_f2(%struct.f2* byval align 4 %a0)
end_comment

begin_struct
struct|struct
name|f4
block|{
name|float
name|f
decl_stmt|;
name|float
name|g
decl_stmt|;
name|float
name|h
decl_stmt|;
name|float
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|f4
name|return_f4
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @return_f4(%struct.f4* noalias sret %agg.result)
end_comment

begin_function
name|void
name|receive_f4
parameter_list|(
name|struct
name|f4
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @receive_f4(%struct.f4* byval align 4 %a0)
end_comment

end_unit

