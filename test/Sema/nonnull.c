begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar://9584012
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|str
decl_stmt|;
block|}
name|Class
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Class
modifier|*
name|object
decl_stmt|;
block|}
name|Instance
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_macro
name|__attribute__
argument_list|(
argument|(nonnull(
literal|1
argument|))
argument_list|)
end_macro

begin_function
name|void
name|Class_init
parameter_list|(
name|Instance
name|this
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
block|{
name|this
operator|.
name|object
operator|->
name|str
operator|=
name|str
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|Class
modifier|*
name|obj
decl_stmt|;
name|Class_init
argument_list|(
literal|0
argument_list|,
literal|"Hello World"
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|Class_init
argument_list|(
name|obj
argument_list|,
literal|"Hello World"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|"foo"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'nonnull' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'nonnull' attribute only applies to pointer arguments}} expected-warning {{'nonnull' attribute applied to function with no pointer arguments}}
end_comment

begin_decl_stmt
name|void
name|baz
argument_list|(
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
specifier|const
name|char
operator|*
name|str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|baz2
argument_list|(
name|__attribute__
argument_list|(
argument|(nonnull(
literal|1
argument|))
argument_list|)
specifier|const
name|char
operator|*
name|str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'nonnull' attribute when used on parameters takes no arguments}}
end_comment

begin_decl_stmt
name|void
name|baz3
argument_list|(
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
name|int
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'nonnull' attribute only applies to pointer arguments}}
end_comment

begin_function
name|void
name|test_baz
parameter_list|()
block|{
name|baz
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|baz2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|baz3
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function_decl
name|void
name|test_void_returns_nonnull
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(returns_nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'returns_nonnull' attribute only applies to return values that are pointers}}
end_comment

begin_function_decl
name|int
name|test_int_returns_nonnull
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(returns_nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'returns_nonnull' attribute only applies to return values that are pointers}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_ptr_returns_nonnull
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(returns_nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
name|int
name|i
name|__attribute__
argument_list|(
operator|(
name|nonnull
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'nonnull' attribute only applies to functions, methods, and parameters}}
end_comment

begin_decl_stmt
name|int
name|j
name|__attribute__
argument_list|(
operator|(
name|returns_nonnull
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'returns_nonnull' attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(returns_nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
modifier|*
name|test_with_fn_proto
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(returns_nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(returns_nonnull)
argument_list|)
end_macro

begin_function
name|void
modifier|*
name|test_bad_returns_null
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
comment|// expected-warning {{null returned from function that requires a non-null return value}}
block|}
end_function

begin_decl_stmt
name|void
name|PR18795
argument_list|(
name|int
argument_list|(
argument|*g
argument_list|)
operator|(
specifier|const
name|char
operator|*
name|h
operator|,
operator|...
operator|)
name|__attribute__
argument_list|(
argument|(nonnull(
literal|1
argument|))
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|nonnull
operator|)
argument_list|)
argument_list|)
block|{
name|g
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed to a callee that requires a non-null argument}}
block|}
end_decl_stmt

begin_function
name|void
name|PR18795_helper
parameter_list|()
block|{
name|PR18795
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed to a callee that requires a non-null argument}}
block|}
end_function

begin_function_decl
name|void
name|vararg1
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|vararg1_test
parameter_list|()
block|{
name|vararg1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vararg1
argument_list|(
literal|1
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
name|vararg1
argument_list|(
literal|2
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
name|vararg1
argument_list|(
literal|2
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|vararg1
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|vararg2
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
operator|,
function_decl|nonnull
operator|,
function_decl|nonnull
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|vararg2_test
parameter_list|()
block|{
name|vararg2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vararg2
argument_list|(
literal|1
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
name|vararg2
argument_list|(
literal|2
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning 2{{null passed}}
block|}
end_function

begin_function_decl
name|void
name|vararg3
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
operator|,
function_decl|nonnull
parameter_list|(
function_decl|2
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|nonnull
argument_list|(
literal|3
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|vararg3_test
parameter_list|()
block|{
name|vararg3
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|vararg3
argument_list|(
literal|1
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
name|vararg3
argument_list|(
literal|2
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning 2{{null passed}}
block|}
end_function

begin_function_decl
name|void
name|redecl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|redecl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|redecl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|redecl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|redecl_test
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|redecl
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
name|redecl
argument_list|(
literal|0
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed}}
block|}
end_function

begin_comment
comment|// rdar://18712242
end_comment

begin_define
define|#
directive|define
name|NULL
value|(void*)0
end_define

begin_macro
name|__attribute__
argument_list|(
argument|(__nonnull__)
argument_list|)
end_macro

begin_comment
comment|// expected-note 2{{declared 'nonnull' here}}
end_comment

begin_function
name|int
name|evil_nonnull_func
parameter_list|(
name|int
modifier|*
name|pointer
parameter_list|,
name|void
modifier|*
name|pv
parameter_list|)
block|{
if|if
condition|(
name|pointer
operator|==
name|NULL
condition|)
block|{
comment|// expected-warning {{comparison of nonnull parameter 'pointer' equal to a null pointer is 'false' on first encounter}}
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
operator|*
name|pointer
return|;
block|}
name|pointer
operator|=
name|pv
expr_stmt|;
if|if
condition|(
operator|!
name|pointer
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|*
name|pointer
return|;
if|if
condition|(
name|pv
operator|==
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of nonnull parameter 'pv' equal to a null pointer is 'false' on first encounter}}
block|}
end_function

begin_function_decl
name|void
name|set_param_to_null
parameter_list|(
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|another_evil_nonnull_func
parameter_list|(
name|int
modifier|*
name|pointer
parameter_list|,
name|char
name|ch
parameter_list|,
name|void
modifier|*
name|pv
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2{{declared 'nonnull' here}}
end_comment

begin_function
name|int
name|another_evil_nonnull_func
parameter_list|(
name|int
modifier|*
name|pointer
parameter_list|,
name|char
name|ch
parameter_list|,
name|void
modifier|*
name|pv
parameter_list|)
block|{
if|if
condition|(
name|pointer
operator|==
name|NULL
condition|)
block|{
comment|// expected-warning {{comparison of nonnull parameter 'pointer' equal to a null pointer is 'false' on first encounter}}
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
operator|*
name|pointer
return|;
block|}
name|set_param_to_null
argument_list|(
operator|&
name|pointer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pointer
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|*
name|pointer
return|;
if|if
condition|(
name|pv
operator|==
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of nonnull parameter 'pv' equal to a null pointer is 'false' on first encounter}}
block|}
end_function

begin_function_decl
specifier|extern
name|void
modifier|*
name|returns_null
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FOO
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FEE
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|pv
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(__nonnull__)
argument_list|)
end_macro

begin_comment
comment|// expected-note {{declared 'nonnull' here}}
end_comment

begin_function
name|void
name|yet_another_evil_nonnull_func
parameter_list|(
name|int
modifier|*
name|pointer
parameter_list|)
block|{
while|while
condition|(
name|pv
condition|)
block|{
comment|// This comparison will not be optimized away.
if|if
condition|(
name|pointer
condition|)
block|{
comment|// expected-warning {{nonnull parameter 'pointer' will evaluate to 'true' on first encounter}}
name|FOO
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|FEE
argument_list|()
expr_stmt|;
block|}
name|pointer
operator|=
name|returns_null
argument_list|(
operator|&
name|pv
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_decl_stmt
name|void
name|pr21668_1
argument_list|(
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
specifier|const
name|char
operator|*
name|p
argument_list|,
specifier|const
name|char
operator|*
name|s
argument_list|)
block|{
comment|// expected-note {{declared 'nonnull' here}}
if|if
condition|(
name|p
condition|)
comment|// expected-warning {{nonnull parameter 'p' will evaluate to 'true' on first encounter}}
empty_stmt|;
if|if
condition|(
name|s
condition|)
comment|// No warning
empty_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|pr21668_2
argument_list|(
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
specifier|const
name|char
operator|*
name|p
argument_list|)
block|{
name|p
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|p
condition|)
comment|// No warning
empty_stmt|;
block|}
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(returns_nonnull)
argument_list|)
end_macro

begin_function_decl
name|void
modifier|*
name|returns_nonnull_whee
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 6{{declared 'returns_nonnull' here}}
end_comment

begin_function
name|void
name|returns_nonnull_warning_tests
parameter_list|()
block|{
if|if
condition|(
name|returns_nonnull_whee
argument_list|()
operator|==
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of nonnull function call 'returns_nonnull_whee()' equal to a null pointer is 'false' on first encounter}}
if|if
condition|(
name|returns_nonnull_whee
argument_list|()
operator|!=
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of nonnull function call 'returns_nonnull_whee()' not equal to a null pointer is 'true' on first encounter}}
if|if
condition|(
name|returns_nonnull_whee
argument_list|()
condition|)
block|{}
comment|// expected-warning {{nonnull function call 'returns_nonnull_whee()' will evaluate to 'true' on first encounter}}
if|if
condition|(
operator|!
name|returns_nonnull_whee
argument_list|()
condition|)
block|{}
comment|// expected-warning {{nonnull function call 'returns_nonnull_whee()' will evaluate to 'true' on first encounter}}
name|int
name|and_again
init|=
operator|!
name|returns_nonnull_whee
argument_list|()
decl_stmt|;
comment|// expected-warning {{nonnull function call 'returns_nonnull_whee()' will evaluate to 'true' on first encounter}}
name|and_again
operator|=
operator|!
name|returns_nonnull_whee
argument_list|()
expr_stmt|;
comment|// expected-warning {{nonnull function call 'returns_nonnull_whee()' will evaluate to 'true' on first encounter}}
block|}
end_function

begin_decl_stmt
name|void
name|pr30828
argument_list|(
name|char
operator|*
name|p
name|__attribute__
argument_list|(
operator|(
name|nonnull
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|pr30828
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{}
end_function

begin_function
name|void
name|call_pr30828
parameter_list|()
block|{
name|pr30828
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
block|}
end_function

end_unit

