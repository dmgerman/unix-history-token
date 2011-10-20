begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
modifier|*
name|P
parameter_list|)
block|{
comment|// CHECK: llvm.prefetch
name|__builtin_prefetch
argument_list|(
name|P
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|P
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

