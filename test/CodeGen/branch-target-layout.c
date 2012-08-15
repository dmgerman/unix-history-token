begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PR13214
end_comment

begin_comment
comment|// No assumption may be made about the order that a frontend emits branch
end_comment

begin_comment
comment|// targets (basic blocks). However, the backend's basic block layout makes an
end_comment

begin_comment
comment|// attempt to preserve source order of control flow, and any bias toward source
end_comment

begin_comment
comment|// order must start with the frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that the frontend inverts branches to simplify the condition, so the
end_comment

begin_comment
comment|// order of a branch instruction's labels cannot be used as a source order bias.
end_comment

begin_function_decl
name|void
name|calla
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: @test1
end_comment

begin_comment
comment|// CHECK: @calla
end_comment

begin_comment
comment|// CHECK: @callb
end_comment

begin_comment
comment|// CHECK: @callc
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
name|calla
argument_list|()
expr_stmt|;
else|else
name|callb
argument_list|()
expr_stmt|;
name|callc
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK: @callb
end_comment

begin_comment
comment|// CHECK: @calla
end_comment

begin_comment
comment|// CHECK: @callc
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
operator|!
name|a
condition|)
name|callb
argument_list|()
expr_stmt|;
else|else
name|calla
argument_list|()
expr_stmt|;
name|callc
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

