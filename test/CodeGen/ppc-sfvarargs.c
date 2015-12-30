begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -O0 --target=powerpc-unknown-linux-gnu -EB -msoft-float -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|void
name|test
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|va_arg
argument_list|(
name|ap
argument_list|,
name|double
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|double
name|a
decl_stmt|;
name|test
argument_list|(
literal|"test"
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: %{{[0-9]+}} = add i8 %{{[0-9]+|numUsedRegs}}, 1
end_comment

begin_comment
comment|// CHECK: %{{[0-9]+}} = and i8 %{{[0-9]+}}, -2
end_comment

begin_comment
comment|// CHECK: %{{[0-9]+}} = mul i8 %{{[0-9]+}}, 4
end_comment

end_unit

