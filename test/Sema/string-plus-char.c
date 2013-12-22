begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|char
modifier|*
name|str
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|str2
init|=
name|str
operator|+
literal|'c'
decl_stmt|;
comment|// expected-warning {{adding 'char' to a string pointer does not append to the string}} expected-note {{use array indexing to silence this warning}}
specifier|const
name|char
modifier|*
name|constStr
init|=
name|s
operator|+
literal|'c'
decl_stmt|;
comment|// expected-warning {{adding 'char' to a string pointer does not append to the string}} expected-note {{use array indexing to silence this warning}}
name|str
operator|=
literal|'c'
operator|+
name|str
expr_stmt|;
comment|// expected-warning {{adding 'char' to a string pointer does not append to the string}} expected-note {{use array indexing to silence this warning}}
comment|// no-warning
name|char
name|c
init|=
literal|'c'
decl_stmt|;
name|str
operator|=
name|str
operator|+
name|c
expr_stmt|;
name|str
operator|=
name|c
operator|+
name|str
expr_stmt|;
block|}
end_function

end_unit

