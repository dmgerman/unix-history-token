begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 "-triple" "x86_64-apple-tvos3.0" -fsyntax-only -verify %s
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
name|tvos
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
name|tvos
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
name|tvos
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
name|tvos
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
name|tvos
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
name|tvos
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
name|tvos
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
name|tvos
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
name|f6
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
comment|// expected-note {{'f6' has been explicitly marked deprecated here}}
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
comment|// expected-warning{{'f0' is deprecated: first deprecated in tvOS 2.1}}
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
comment|// expected-warning{{'f2' is deprecated: first deprecated in tvOS 3.0}}
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
comment|// expected-error{{f4' is unavailable: obsoleted in tvOS 3.0}}
name|f5
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f5' is deprecated: first deprecated in tvOS 3.0}}
name|f6
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f6' is deprecated: first deprecated in tvOS 3.0}}
block|}
end_function

begin_comment
comment|// Anything iOS later than 8 does not apply to tvOS.
end_comment

begin_function_decl
name|void
name|f9
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
literal|9.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_transcribed_availability
parameter_list|()
block|{
name|f9
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(availability(ios,introduced=
literal|9_0
argument|,deprecated=
literal|9_0
argument|,message=
literal|""
argument|))
argument_list|)
end_macro

begin_comment
comment|// expected-note{{previous attribute is here}} \
end_comment

begin_comment
comment|// expected-note{{previous attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(availability(ios,introduced=
literal|7_0
argument|))
argument_list|)
end_macro

begin_comment
comment|// expected-warning{{availability does not match previous declaration}} \
end_comment

begin_comment
comment|// expected-warning{{availability does not match previous declaration}}
end_comment

begin_function_decl
name|void
name|f10
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Test tvOS specific attributes.
end_comment

begin_function_decl
name|void
name|f0_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
comment|// expected-note {{'f0_tvos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f1_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
name|f2_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
comment|// expected-note {{'f2_tvos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f3_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
name|f4_tvos
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
name|tvos
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
name|f5_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
name|f5_attr_reversed_tvos
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
name|tvos
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
name|f5b_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
name|tvos
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
comment|// expected-note {{'f5b_tvos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f5c_tvos
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
comment|// expected-note {{'f5c_tvos' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|f6_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
name|f6_tvos
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|tvos
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
comment|// expected-note {{'f6_tvos' has been explicitly marked deprecated here}}
end_comment

begin_function
name|void
name|test_tvos
parameter_list|()
block|{
name|f0_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f0_tvos' is deprecated: first deprecated in tvOS 2.1}}
name|f1_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f2_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f2_tvos' is deprecated: first deprecated in tvOS 3.0}}
name|f3_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|f4_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{'f4_tvos' is unavailable: obsoleted in tvOS 3.0}}
comment|// We get no warning here because any explicit 'tvos' availability causes
comment|// the ios availablity to not implicitly become 'tvos' availability.  Otherwise we'd get
comment|// a deprecated warning.
name|f5_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|f5_attr_reversed_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// We get a deprecated warning here because both attributes are explicitly 'tvos'.
name|f5b_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f5b_tvos' is deprecated: first deprecated in tvOS 3.0}}
comment|// We get a deprecated warning here because both attributes are 'ios' (both get mapped to 'tvos').
name|f5c_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{'f5c_tvos' is deprecated: first deprecated in tvOS 3.0}}
name|f6_tvos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f6_tvos' is deprecated: first deprecated in tvOS 3.0}}
block|}
end_function

end_unit

