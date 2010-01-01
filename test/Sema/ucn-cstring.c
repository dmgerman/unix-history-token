begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
index|[
sizeof|sizeof
argument_list|(
literal|"hello \u2192 \u2603 \u2190 world"
argument_list|)
operator|==
literal|24
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"%s (%d)\n"
argument_list|,
literal|"hello \u2192 \u2603 \u2190 world"
argument_list|,
sizeof|sizeof
argument_list|(
literal|"hello \u2192 \u2603 \u2190 world"
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s (%d)\n"
argument_list|,
literal|"\U00010400\U0001D12B"
argument_list|,
sizeof|sizeof
argument_list|(
literal|"\U00010400\U0001D12B"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Some error conditions...
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
literal|"\U"
argument_list|)
expr_stmt|;
comment|// expected-error{{\u used with no following hex digits}}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
literal|"\U00"
argument_list|)
expr_stmt|;
comment|// expected-error{{incomplete universal character name}}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
literal|"\U0001"
argument_list|)
expr_stmt|;
comment|// expected-error{{incomplete universal character name}}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
literal|"\u0001"
argument_list|)
expr_stmt|;
comment|// expected-error{{invalid universal character}}
return|return
literal|0
return|;
block|}
end_function

end_unit

