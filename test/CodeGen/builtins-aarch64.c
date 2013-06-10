begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -O3 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
name|__clear_cache
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}} @__clear_cache
block|}
end_function

end_unit

