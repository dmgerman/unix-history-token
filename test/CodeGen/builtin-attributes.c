begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple arm-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: declare arm_aapcscc i32 @printf(i8*, ...)
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|printf
argument_list|(
literal|"a\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call arm_aapcscc void @exit
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

