begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 "-triple" "x86_64-apple-ios3.0" -fsyntax-only -verify %s
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
name|ios
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
comment|// expected-warning{{'f0' is deprecated: first deprecated in iOS 2.1}}
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
comment|// expected-warning{{'f2' is deprecated: first deprecated in iOS 3.0}}
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
comment|// expected-error{{f4' is unavailable: obsoleted in iOS 3.0}}
name|f5
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f5' is deprecated: first deprecated in iOS 3.0}}
name|f6
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{'f6' is deprecated: first deprecated in iOS 3.0}}
block|}
end_function

end_unit

