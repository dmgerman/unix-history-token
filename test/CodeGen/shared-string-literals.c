begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_decl_stmt
name|char
modifier|*
name|globalString
init|=
literal|"abc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|globalStringArray
index|[
literal|5
index|]
init|=
block|{
literal|"123"
block|,
literal|"abc"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|anotherGlobalString
init|=
literal|"123"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"123"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

