begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep "hello" %t | count 3
end_comment

begin_comment
comment|// RUN: grep 'c"hello\\00"' %t | count 2
end_comment

begin_comment
comment|// RUN: grep 'c"hello\\00\\00\\00"' %t | count 1
end_comment

begin_comment
comment|// RUN: grep 'c"ola"' %t | count 1
end_comment

begin_comment
comment|/* Should be 3 hello string, two global (of different sizes), the rest    are shared. */
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|bar
argument_list|(
literal|"hello"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|x
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
specifier|static
name|char
name|x
index|[]
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f3
parameter_list|()
block|{
specifier|static
name|char
name|x
index|[
literal|8
index|]
init|=
literal|"hello"
decl_stmt|;
name|bar
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f4
parameter_list|()
block|{
specifier|static
struct|struct
name|s
block|{
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|x
init|=
block|{
literal|"hello"
block|}
struct|;
name|gaz
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|char
name|x
index|[
literal|3
index|]
init|=
literal|"ola"
decl_stmt|;
end_decl_stmt

end_unit

