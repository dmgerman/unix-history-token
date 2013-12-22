begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7m-apple-darwin-eabi -ast-dump %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: CallExpr {{.*}} 'int'
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
do|do
block|{   }
do|while
condition|(
name|__builtin_arm_strex
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
condition|)
do|;
block|}
end_function

end_unit

