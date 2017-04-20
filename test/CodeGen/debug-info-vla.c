begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited -triple x86_64-apple-darwin %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|testVLAwithSize
parameter_list|(
name|int
name|s
parameter_list|)
block|{
comment|// CHECK: dbg.declare
comment|// CHECK: dbg.declare({{.*}}, metadata ![[VAR:.*]], metadata ![[EXPR:.*]])
comment|// CHECK: ![[EXPR]] = !DIExpression()
comment|// CHECK: ![[VAR]] = !DILocalVariable(name: "vla",{{.*}} line: [[@LINE+1]]
name|int
name|vla
index|[
name|s
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|s
condition|;
name|i
operator|++
control|)
block|{
name|vla
index|[
name|i
index|]
operator|=
name|i
operator|*
name|i
expr_stmt|;
block|}
block|}
end_function

end_unit

