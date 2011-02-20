begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fblocks -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// rdar: // 7860965
end_comment

begin_function_decl
specifier|extern
name|void
name|PRINTF
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|B
parameter_list|(
name|void
function_decl|(
modifier|^
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|PRINTF
argument_list|(
name|__func__
argument_list|)
expr_stmt|;
name|B
argument_list|(
lambda|^
block|{
name|PRINTF
argument_list|(
name|__func__
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|// not reached
block|}
end_function

begin_comment
comment|// CHECK: @__func__.__main_block_invoke_0 = private unnamed_addr constant [22 x i8] c"__main_block_invoke_0\00"
end_comment

begin_comment
comment|// CHECK: call void @PRINTF({{.*}}@__func__.__main_block_invoke_
end_comment

end_unit

