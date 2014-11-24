begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fms-extensions -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|__assume
argument_list|(
name|a
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

