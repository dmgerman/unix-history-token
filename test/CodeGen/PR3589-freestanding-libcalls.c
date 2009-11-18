begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o - | grep 'declare i32 @printf' | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -O2 -emit-llvm %s -o - | grep 'declare i32 @puts' | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -ffreestanding -O2 -emit-llvm %s -o - | grep 'declare i32 @puts' | count 0
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|()
block|{
name|printf
argument_list|(
literal|"hello\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

