begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: sparc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|test_eh_return_data_regno
parameter_list|(
name|void
parameter_list|)
block|{
specifier|volatile
name|int
name|res
decl_stmt|;
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 24
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 25
block|}
end_function

end_unit

