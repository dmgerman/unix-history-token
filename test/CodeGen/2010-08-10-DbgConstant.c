begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -emit-llvm -debug-info-kind=limited  %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariableExpression(var: [[VAR:.*]], expr: [[EXPR:![0-9]+]])
end_comment

begin_comment
comment|// CHECK: [[EXPR]] = !DIExpression(DW_OP_constu, 201, DW_OP_stack_value)
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|int
name|ro
init|=
literal|201
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|(
name|ro
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

