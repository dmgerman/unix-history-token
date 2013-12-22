begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fms-extensions -triple i686-pc-win32 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_alloca
end_comment

begin_function_decl
name|void
name|capture
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_alloca
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|capture
argument_list|(
name|_alloca
argument_list|(
name|n
argument_list|)
argument_list|)
expr_stmt|;
comment|// CHECK: %[[arg:.*]] = alloca i8, i32 %
comment|// CHECK: call void @capture(i8* %[[arg]])
block|}
end_function

end_unit

