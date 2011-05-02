begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: declare i32 @printf(i8*, ...)
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
comment|// CHECK: call void @exit
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

begin_comment
comment|// CHECK: call i8* @strstr{{.*}} nounwind
end_comment

begin_function
name|char
modifier|*
name|f2
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__builtin_strstr
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

