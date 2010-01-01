begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"abc"
decl_stmt|;
name|void
modifier|*
name|foo
init|=
literal|L"AB"
decl_stmt|;
block|}
end_function

end_unit

