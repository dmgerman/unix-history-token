begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_20 -O3 -S -o %t %s -emit-llvm
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_21 -O3 -S -o %t %s -emit-llvm
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_30 -O3 -S -o %t %s -emit-llvm
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -target-cpu sm_35 -O3 -S -o %t %s -emit-llvm
end_comment

begin_comment
comment|// Make sure clang accepts all supported architectures.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|)
block|{
name|a
index|[
literal|0
index|]
operator|=
name|b
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

end_unit

