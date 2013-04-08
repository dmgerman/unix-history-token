begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -triple x86_64-apple-darwin10 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: [[Vi:%.+]] = alloca %struct.__block_byref_i, align 8
end_comment

begin_comment
comment|// CHECK: call i32 (...)* @rhs()
end_comment

begin_comment
comment|// CHECK: [[V7:%.+]] = getelementptr inbounds %struct.__block_byref_i* [[Vi]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: load %struct.__block_byref_i** [[V7]]
end_comment

begin_comment
comment|// CHECK: call i32 (...)* @rhs()
end_comment

begin_comment
comment|// CHECK: [[V11:%.+]] = getelementptr inbounds %struct.__block_byref_i* [[Vi]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: load %struct.__block_byref_i** [[V11]]
end_comment

begin_function_decl
name|int
name|rhs
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
specifier|__block
name|int
name|i
decl_stmt|;
name|i
operator|=
name|rhs
argument_list|()
expr_stmt|;
name|i
operator|+=
name|rhs
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

