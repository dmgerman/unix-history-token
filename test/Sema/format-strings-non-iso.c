begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-linux-gnu -fsyntax-only -verify -std=c99 -Wformat-non-iso %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|cp
decl_stmt|;
comment|// The 'q' length modifier.
name|printf
argument_list|(
literal|"%qd"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{'q' length modifier is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
name|scanf
argument_list|(
literal|"%qd"
argument_list|,
operator|(
name|long
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'q' length modifier is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
comment|// The 'm' length modifier.
name|scanf
argument_list|(
literal|"%ms"
argument_list|,
operator|&
name|cp
argument_list|)
expr_stmt|;
comment|// expected-warning{{'m' length modifier is not supported by ISO C}}
comment|// The 'S' and 'C' conversion specifiers.
name|printf
argument_list|(
literal|"%S"
argument_list|,
literal|L"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning{{'S' conversion specifier is not supported by ISO C}}
name|printf
argument_list|(
literal|"%C"
argument_list|,
literal|L'
expr|x'
argument_list|)
expr_stmt|;
comment|// expected-warning{{'C' conversion specifier is not supported by ISO C}}
comment|// Combining 'L' with an integer conversion specifier.
name|printf
argument_list|(
literal|"%Li"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{using length modifier 'L' with conversion specifier 'i' is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
name|printf
argument_list|(
literal|"%Lo"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{using length modifier 'L' with conversion specifier 'o' is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
name|printf
argument_list|(
literal|"%Lu"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{using length modifier 'L' with conversion specifier 'u' is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
name|printf
argument_list|(
literal|"%Lx"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{using length modifier 'L' with conversion specifier 'x' is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
name|printf
argument_list|(
literal|"%LX"
argument_list|,
operator|(
name|long
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{using length modifier 'L' with conversion specifier 'X' is not supported by ISO C}} expected-note{{did you mean to use 'll'?}}
comment|// Positional arguments.
name|printf
argument_list|(
literal|"%1$d"
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{positional arguments are not supported by ISO C}}
block|}
end_function

end_unit

