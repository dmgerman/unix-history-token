begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify
end_comment

begin_function_decl
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_takes
parameter_list|(
function_decl|"foo"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_takes' attribute requires parameter 1 to be an identifier}}
end_comment

begin_function_decl
name|void
modifier|*
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_returns
parameter_list|(
name|foo
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_returns' attribute takes no more than 1 argument}}
end_comment

begin_function_decl
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_holds' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|f4
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_returns
parameter_list|(
name|foo
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f5
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_holds' attribute takes at least 2 arguments}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|1
operator|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_holds' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
name|f7
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_takes
parameter_list|(
name|foo
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_takes' attribute takes at least 2 arguments}}
end_comment

begin_function_decl
name|void
name|f8
parameter_list|(
name|int
modifier|*
name|i
parameter_list|,
name|int
modifier|*
name|j
parameter_list|,
name|int
name|k
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|1
operator|,
function_decl|2
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_holds' attribute parameter 3 is out of bounds}}
end_comment

begin_decl_stmt
name|int
name|f9
name|__attribute__
argument_list|(
operator|(
name|ownership_takes
argument_list|(
name|foo
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'ownership_takes' attribute only applies to functions}}
end_comment

begin_function_decl
name|void
name|f10
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_holds' attribute only applies to pointer arguments}}
end_comment

begin_function_decl
name|void
modifier|*
name|f11
parameter_list|(
name|float
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_returns
parameter_list|(
name|foo
parameter_list|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_returns' attribute only applies to integer arguments}}
end_comment

begin_function_decl
name|void
modifier|*
name|f12
parameter_list|(
name|float
name|i
parameter_list|,
name|int
name|k
parameter_list|,
name|int
name|f
parameter_list|,
name|int
modifier|*
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_returns
parameter_list|(
name|foo
parameter_list|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'ownership_returns' attribute only applies to integer arguments}}
end_comment

begin_function_decl
name|void
name|f13
parameter_list|(
name|int
modifier|*
name|i
parameter_list|,
name|int
modifier|*
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|1
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|ownership_takes
argument_list|(
name|foo
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|f14
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
modifier|*
name|k
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(ownership_holds
parameter_list|(
name|foo
parameter_list|,
function_decl|3
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|ownership_takes
argument_list|(
name|foo
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'ownership_holds' and 'ownership_takes' attributes are not compatible}}
end_comment

end_unit

