begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: We forcibly strip the names so that the test doesn't vary between
end_comment

begin_comment
comment|// builds with and without asserts. We need a better solution for this.
end_comment

begin_comment
comment|// RUN: clang-cc -fblocks -triple x86_64-apple-darwin10 -emit-llvm-bc -o - %s | opt -strip | llvm-dis> %t&&
end_comment

begin_comment
comment|// RUN: grep '%6 = call i32 (...)\* @rhs()' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%7 = getelementptr inbounds %0\* %1, i32 0, i32 1' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%8 = load %0\*\* %7' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%10 = call i32 (...)\* @rhs()' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%11 = getelementptr inbounds %0\* %1, i32 0, i32 1' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%12 = load %0\*\* %11' %t | count 1
end_comment

begin_function_decl
name|int
name|rhs
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
specifier|__block
name|int
name|i
decl_stmt|;
name|i
operator|=
name|rhs
argument_list|()
expr_stmt|;
name|i
operator|+=
name|rhs
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

