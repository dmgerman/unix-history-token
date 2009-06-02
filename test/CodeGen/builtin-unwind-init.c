begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s -o - | grep -F "llvm.eh.unwind.init"
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|__builtin_unwind_init
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

