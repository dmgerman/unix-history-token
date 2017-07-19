begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-windows-msvc -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|int
name|simple_int
parameter_list|(
name|va_list
name|ap
parameter_list|)
block|{
comment|// CHECK-LABEL: define i32 @simple_int
return|return
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
return|;
comment|// CHECK: [[ADDR:%[a-z_0-9]+]] = bitcast i8* %argp.cur to i32*
comment|// CHECK: [[RESULT:%[a-z_0-9]+]] = load i32, i32* [[ADDR]]
comment|// CHECK: ret i32 [[RESULT]]
block|}
end_function

end_unit

