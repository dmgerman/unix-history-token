begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm -o - -x c %s | FileCheck %s
end_comment

begin_comment
comment|// Reproduce the crash in PR19760.
end_comment

begin_function
specifier|static
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"foo"
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: @bar = hidden alias void ()* @foo
end_comment

begin_comment
comment|// CHECK: define internal void @foo()
end_comment

end_unit

