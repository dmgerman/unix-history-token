begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fblocks -triple x86_64-apple-darwin10 -emit-llvm -o %t %s&&
end_comment

begin_comment
comment|// RUN: grep '%call = call i32 (...)\* @rhs()' %t | count 1&&
end_comment

begin_comment
comment|// If this fails, see about sliding %4, %5, %6 and %7...
end_comment

begin_comment
comment|// RUN: grep '%forwarding1 = getelementptr %0\* %i, i32 0, i32 1' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%4 = bitcast i8\*\* %forwarding1 to %0\*\*' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%5 = load %0\*\* %4' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%call2 = call i32 (...)\* @rhs()' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%forwarding3 = getelementptr %0\* %i, i32 0, i32 1' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%6 = bitcast i8\*\* %forwarding3 to %0\*\*' %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep '%7 = load %0\*\* %6' %t | count 1
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

