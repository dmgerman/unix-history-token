begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
comment|// size_t
name|printf
argument_list|(
literal|"%zu"
argument_list|,
operator|(
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'size_t' (aka 'unsigned long') but the argument has type 'double'}}
comment|// intmax_t / uintmax_t
name|printf
argument_list|(
literal|"%jd"
argument_list|,
operator|(
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'intmax_t' (aka 'long') but the argument has type 'double'}}
name|printf
argument_list|(
literal|"%ju"
argument_list|,
operator|(
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'uintmax_t' (aka 'unsigned long') but the argument has type 'double'}}
comment|// ptrdiff_t
name|printf
argument_list|(
literal|"%td"
argument_list|,
operator|(
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{format specifies type 'ptrdiff_t' (aka 'long') but the argument has type 'double'}}
block|}
end_function

end_unit

