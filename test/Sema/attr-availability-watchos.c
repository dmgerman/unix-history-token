begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 "-triple" "arm64-apple-watchos3.0" -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|f0
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|2.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f0' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f2' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f3
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f4
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.1
parameter_list|,
name|deprecated
init|=
literal|10.3
parameter_list|,
name|obsoleted
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|2.1
parameter_list|,
name|obsoleted
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{explicitly marked unavailable}}
end_comment

begin_function_decl
name|void
name|f5
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|ios
argument_list|,
name|deprecated
operator|=
literal|3.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note {{'f5' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|12.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// OK - not deprecated for watchOS
end_comment

begin_function_decl
name|void
name|f7
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|8.3
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f7' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f8
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|obsoleted
init|=
literal|10.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{explicitly marked unavailable}}
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f0' is deprecated: first deprecated in watchOS 2.0}}
name|f1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f2' is deprecated: first deprecated in watchOS 2.0}}
name|f3
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f4
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{f4' is unavailable: obsoleted in watchOS 2.0}}
name|f5
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f5' is deprecated: first deprecated in watchOS 2.0}}
name|f6
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f7
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f7' is deprecated: first deprecated in watchOS 2.0}}
name|f8
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{'f8' is unavailable: obsoleted in watchOS 3.0}}
block|}
end_function

begin_comment
comment|// Test watchOS specific attributes.
end_comment

begin_function_decl
name|void
name|f0_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|2.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f0_watchos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f1_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f2_watchos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f3_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f4_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.1
parameter_list|,
name|deprecated
init|=
literal|10.3
parameter_list|,
name|obsoleted
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|,
name|deprecated
init|=
literal|2.1
parameter_list|,
name|obsoleted
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{explicitly marked unavailable}}
end_comment

begin_function_decl
name|void
name|f5_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|ios
argument_list|,
name|deprecated
operator|=
literal|3.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|f5_attr_reversed_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|watchos
argument_list|,
name|introduced
operator|=
literal|2.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|f5b_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|watchos
argument_list|,
name|deprecated
operator|=
literal|3.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note {{'f5b_watchos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f5c_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|availability
argument_list|(
name|ios
argument_list|,
name|deprecated
operator|=
literal|3.0
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note {{'f5c_watchos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f6_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f6_watchos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|watchos
parameter_list|,
name|introduced
init|=
literal|2.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'f6_watchos' has been explicitly marked deprecated here}}
end_comment

begin_function
name|void
name|test_watchos
parameter_list|()
block|{
name|f0_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f0_watchos' is deprecated: first deprecated in watchOS 2.1}}
name|f1_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f2_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f2_watchos' is deprecated: first deprecated in watchOS 3.0}}
name|f3_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f4_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{'f4_watchos' is unavailable: obsoleted in watchOS 3.0}}
comment|// We get no warning here because any explicit 'watchos' availability causes
comment|// the ios availablity to not implicitly become 'watchos' availability.  Otherwise we'd get
comment|// a deprecated warning.
name|f5_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|f5_attr_reversed_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// We get a deprecated warning here because both attributes are explicitly 'watchos'.
name|f5b_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f5b_watchos' is deprecated: first deprecated in watchOS 3.0}}
comment|// We get a deprecated warning here because both attributes are 'ios' (both get mapped to 'watchos').
name|f5c_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f5c_watchos' is deprecated: first deprecated in watchOS 2.0}}
name|f6_watchos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f6_watchos' is deprecated: first deprecated in watchOS 3.0}}
block|}
end_function

end_unit

