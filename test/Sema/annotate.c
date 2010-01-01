begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"foo"
argument_list|)
operator|)
argument_list|)
name|foo
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{
name|__attribute__
argument_list|(
argument|(annotate(
literal|"bar"
argument|))
argument_list|)
name|int
name|x
decl_stmt|;
name|__attribute__
argument_list|(
argument|(annotate(
literal|1
argument|))
argument_list|)
name|int
name|y
decl_stmt|;
comment|// expected-error {{argument to annotate attribute was not a string literal}}
name|__attribute__
argument_list|(
argument|(annotate(
literal|"bar"
argument|,
literal|1
argument|))
argument_list|)
name|int
name|z
decl_stmt|;
comment|// expected-error {{attribute requires 1 argument(s)}}
block|}
end_decl_stmt

end_unit

