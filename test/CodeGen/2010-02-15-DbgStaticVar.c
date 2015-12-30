begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Test to check intentionally empty linkage name for a static variable.
end_comment

begin_comment
comment|// Radar 7651244.
end_comment

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
specifier|static
name|int
name|b
init|=
literal|1
decl_stmt|;
return|return
name|b
operator|+
name|a
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|j
init|=
name|foo
argument_list|(
literal|1
argument_list|)
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: !DIGlobalVariable(name: "b",
end_comment

begin_comment
comment|// CHECK-NOT:               linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:              ){{$}}
end_comment

end_unit

