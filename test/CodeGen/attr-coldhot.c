begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|int
name|test1
parameter_list|()
function|__attribute__
parameter_list|(
function|(__cold__
end_function

begin_block
unit|))
block|{
return|return
literal|42
return|;
comment|// Check that we set the optsize attribute on the function.
comment|// CHECK: @test1{{.*}}[[ATTR:#[0-9]+]]
comment|// CHECK: ret
block|}
end_block

begin_comment
comment|// CHECK: attributes [[ATTR]] = { {{.*}}cold{{.*}}optsize{{.*}} }
end_comment

end_unit

