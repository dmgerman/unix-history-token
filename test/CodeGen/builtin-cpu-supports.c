begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// Test that we have the structure definition, the gep offsets, the name of the
end_comment

begin_comment
comment|// global, the bit grab, and the icmp correct.
end_comment

begin_function_decl
specifier|extern
name|void
name|a
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
literal|"sse4.2"
argument_list|)
condition|)
name|a
argument_list|(
literal|"sse4.2"
argument_list|)
expr_stmt|;
comment|// CHECK: [[LOAD:%[^ ]+]] = load i32, i32* getelementptr inbounds ({ i32, i32, i32, [1 x i32] }, { i32, i32, i32, [1 x i32] }* @__cpu_model, i32 0, i32 3, i32 0)
comment|// CHECK: [[AND:%[^ ]+]] = and i32 [[LOAD]], 256
comment|// CHECK: = icmp ne i32 [[AND]], 0
return|return
literal|0
return|;
block|}
end_function

end_unit

