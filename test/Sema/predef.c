begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|abcdefghi12
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|char
argument_list|(
operator|*
name|ss
argument_list|)
index|[
literal|12
index|]
operator|=
operator|&
name|__func__
expr_stmt|;
specifier|static
name|int
name|arr
index|[
sizeof|sizeof
argument_list|(
name|__func__
argument_list|)
operator|==
literal|12
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|char
modifier|*
name|X
init|=
name|__func__
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{predefined identifier is only valid}} \
end_comment

begin_expr_stmt
name|expected
operator|-
name|warning
block|{
block|{
name|initializing
literal|'char const [1]'
name|discards
name|qualifiers
block|,
name|expected
literal|'char *'
block|}
block|}
name|void
name|a
argument_list|()
block|{
name|__func__
index|[
literal|0
index|]
operator|=
literal|'a'
block|;
comment|// expected-error {{variable is not assignable}}
block|}
comment|// rdar://6097892 - GCC permits this insanity.
specifier|const
name|char
operator|*
name|b
operator|=
name|__func__
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{predefined identifier is only valid}}
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|c
init|=
name|__FUNCTION__
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{predefined identifier is only valid}}
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|d
init|=
name|__PRETTY_FUNCTION__
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{predefined identifier is only valid}}
end_comment

end_unit

