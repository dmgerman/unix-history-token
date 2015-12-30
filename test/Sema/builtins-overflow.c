begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|__builtin_add_overflow
argument_list|)
end_if

begin_warning
warning|#
directive|warning
warning|defined as expected
end_warning

begin_comment
comment|// expected-warning@-1 {{defined as expected}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|r
decl_stmt|;
specifier|const
name|char
modifier|*
name|c
decl_stmt|;
name|float
name|f
decl_stmt|;
specifier|const
name|unsigned
name|q
decl_stmt|;
name|__builtin_add_overflow
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected 3, have 0}}
name|__builtin_add_overflow
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call, expected 3, have 4}}
name|__builtin_add_overflow
argument_list|(
name|c
argument_list|,
literal|1
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
comment|// expected-error {{operand argument to overflow builtin must be an integer ('const char *' invalid)}}
name|__builtin_add_overflow
argument_list|(
literal|1
argument_list|,
name|c
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
comment|// expected-error {{operand argument to overflow builtin must be an integer ('const char *' invalid)}}
name|__builtin_add_overflow
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error {{result argument to overflow builtin must be a pointer to a non-const integer ('int' invalid)}}
name|__builtin_add_overflow
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
operator|&
name|f
argument_list|)
expr_stmt|;
comment|// expected-error {{result argument to overflow builtin must be a pointer to a non-const integer ('float *' invalid)}}
name|__builtin_add_overflow
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|// expected-error {{result argument to overflow builtin must be a pointer to a non-const integer ('const unsigned int *' invalid)}}
block|}
end_function

end_unit

