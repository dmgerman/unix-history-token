begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=standalone \
end_comment

begin_comment
comment|// RUN:      -triple %itanium_abi_triple %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Debug info for a global constant whose address is taken should be emitted
end_comment

begin_comment
comment|// exactly once.
end_comment

begin_comment
comment|// CHECK: @i = internal constant i32 1, align 4, !dbg ![[I:[0-9]+]]
end_comment

begin_comment
comment|// CHECK: ![[I]] = !DIGlobalVariableExpression(var: ![[VAR:.*]], expr: ![[EXPR:[0-9]+]])
end_comment

begin_comment
comment|// CHECK: ![[VAR]] = distinct !DIGlobalVariable(name: "i",
end_comment

begin_comment
comment|// CHECK: !DICompileUnit({{.*}}globals: ![[GLOBALS:[0-9]+]])
end_comment

begin_comment
comment|// CHECK: ![[GLOBALS]] = !{![[I]]}
end_comment

begin_comment
comment|// CHECK: ![[EXPR]] = !DIExpression(DW_OP_constu, 1, DW_OP_stack_value)
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|i
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|g
parameter_list|(
specifier|const
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|()
block|{
name|g
argument_list|(
operator|&
name|i
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

