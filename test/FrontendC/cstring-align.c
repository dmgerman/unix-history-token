begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -Os -o - | llc -march=x86 -mtriple=i386-apple-darwin10 | FileCheck %s
end_comment

begin_function_decl
specifier|extern
name|void
name|func
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|long_function_name
parameter_list|()
block|{
name|func
argument_list|(
literal|"%s: the function name"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: .align 4
end_comment

begin_comment
comment|// CHECK: ___func__.
end_comment

begin_comment
comment|// CHECK: .asciz "long_function_name"
end_comment

end_unit

