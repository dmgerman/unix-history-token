begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|test_eh_return_data_regno
parameter_list|()
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
comment|// CHECK: store volatile i32 3
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 4
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_builtin_ppc_get_timebase
end_comment

begin_function
name|long
name|long
name|test_builtin_ppc_get_timebase
parameter_list|()
block|{
comment|// CHECK: call i64 @llvm.readcyclecounter()
return|return
name|__builtin_ppc_get_timebase
argument_list|()
return|;
block|}
end_function

end_unit

