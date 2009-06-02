begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fexceptions -emit-llvm -o - %s | grep "@foo() {" | count 1&&
end_comment

begin_comment
comment|// RUN: clang-cc -emit-llvm -o - %s | grep "@foo() nounwind {" | count 1
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

