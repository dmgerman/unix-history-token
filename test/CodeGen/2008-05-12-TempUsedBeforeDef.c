begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -emit-llvm -o /dev/null %s
end_comment

begin_comment
comment|// PR2264.
end_comment

begin_decl_stmt
name|unsigned
name|foo
init|=
literal|8L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|bar
init|=
literal|0L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|char
name|baz
init|=
literal|6L
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
name|char
name|qux
init|=
literal|1L
decl_stmt|;
for|for
control|(
init|;
name|baz
operator|>=
operator|-
literal|29
condition|;
name|baz
operator|--
control|)
name|bork
argument_list|(
name|bar
operator|&&
name|foo
argument_list|,
name|qux
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

