begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|clear0
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK: clear0
comment|// CHECK-NOT: load i8**
name|__clear_cache
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|clear1
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK: clear1
comment|// CHECK: load i8**
comment|// CHECK-NOT: load i8**
name|__clear_cache
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|clear2
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
comment|// CHECK: clear2
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

