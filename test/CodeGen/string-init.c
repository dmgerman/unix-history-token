begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o %t
end_comment

begin_comment
comment|// RUN: grep 'private constant \[10 x i8\]' %t
end_comment

begin_comment
comment|// RUN: not grep -F "[5 x i8]" %t
end_comment

begin_comment
comment|// RUN: not grep "store " %t
end_comment

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"asdf"
decl_stmt|;
name|char
name|b
index|[
literal|10
index|]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
block|}
end_function

end_unit

