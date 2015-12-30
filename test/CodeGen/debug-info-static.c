begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  -debug-info-kind=limited -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariable({{.*}}variable: i32* @f.xyzzy
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|xyzzy
decl_stmt|;
name|xyzzy
operator|+=
literal|3
expr_stmt|;
block|}
end_function

end_unit

