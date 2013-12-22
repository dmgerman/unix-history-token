begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|clear
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|ptr2
parameter_list|)
block|{
comment|// CHECK: clear
comment|// CHECK: load i8**
comment|// CHECK: load i8**
name|__clear_cache
argument_list|(
name|ptr
argument_list|,
name|ptr2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

