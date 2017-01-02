begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux -S -emit-llvm -debug-info-kind=limited  %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariable({{.*}}
end_comment

begin_comment
comment|// CHECK-NOT: expr:
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|__uint128_t
name|ro
init|=
literal|18446744073709551615
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|bar
parameter_list|(
name|__uint128_t
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

