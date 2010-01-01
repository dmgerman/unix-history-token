begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -fwritable-strings %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
modifier|*
name|str
init|=
literal|"abc"
decl_stmt|;
name|str
index|[
literal|0
index|]
operator|=
literal|'1'
expr_stmt|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

