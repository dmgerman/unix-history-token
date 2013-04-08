begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|char
name|foo
index|[
literal|10
index|]
decl_stmt|;
name|int
name|bar
index|[
literal|20
index|]
decl_stmt|;
name|char
name|qux
index|[
literal|30
index|]
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|bar
operator|+
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{sizeof on pointer operation will return size of 'int *' instead of 'int [20]'}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|foo
operator|-
literal|20
argument_list|)
expr_stmt|;
comment|// expected-warning{{sizeof on pointer operation will return size of 'char *' instead of 'char [10]'}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|bar
operator|-
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{sizeof on pointer operation will return size of 'int *' instead of 'int [20]'}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|foo
operator|+
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{sizeof on pointer operation will return size of 'char *' instead of 'char [10]'}}
comment|// This is ptrdiff_t.
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|foo
operator|-
name|qux
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|foo
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|x
argument_list|,
name|foo
argument_list|)
expr_stmt|;
comment|// expected-warning{{sizeof on pointer operation will return size of 'char *' instead of 'char [10]'}}
block|}
end_function

end_unit

