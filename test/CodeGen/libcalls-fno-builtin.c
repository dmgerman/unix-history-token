begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -O3 -fno-builtin -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar://10551066
end_comment

begin_function_decl
name|double
name|ceil
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|copysign
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|floor
parameter_list|(
name|double
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|t1
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|ceil
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t1
end_comment

begin_comment
comment|// CHECK: ceil
end_comment

begin_function
name|double
name|t2
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
return|return
name|copysign
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t2
end_comment

begin_comment
comment|// CHECK: copysign
end_comment

begin_function
name|double
name|t3
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|cos
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t3
end_comment

begin_comment
comment|// CHECK: cos
end_comment

begin_function
name|double
name|t4
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t4
end_comment

begin_comment
comment|// CHECK: fabs
end_comment

begin_function
name|double
name|t5
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|floor
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: t5
end_comment

begin_comment
comment|// CHECK: floor
end_comment

end_unit

