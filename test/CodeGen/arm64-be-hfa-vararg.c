begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN:  %clang_cc1 -triple aarch64_be-linux-gnu -ffreestanding -emit-llvm -O0 -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// A single member HFA must be aligned just like a non-HFA register argument.
end_comment

begin_function
name|double
name|callee
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: = add i64 %{{.*}}, 8
name|va_list
name|vl
decl_stmt|;
name|va_start
argument_list|(
name|vl
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|double
name|result
init|=
name|va_arg
argument_list|(
argument|vl
argument_list|,
argument|struct { double a; }
argument_list|)
operator|.
name|a
decl_stmt|;
name|va_end
argument_list|(
name|vl
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

