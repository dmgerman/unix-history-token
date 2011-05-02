begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-darwin-apple -g -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Radar 9199234
end_comment

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|i
condition|)
block|{
name|j
operator|=
name|bar
argument_list|()
expr_stmt|;
comment|//CHECK: store i32
comment|//CHECK-NOT:  br label %{{%[a-zA-Z0-9\.]+}}, !dbg
block|}
else|else
block|{
name|j
operator|=
name|bar
argument_list|()
operator|+
literal|2
expr_stmt|;
block|}
return|return
name|j
return|;
block|}
end_function

end_unit

