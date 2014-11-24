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
comment|// expected-warning {{null passed to a callee which requires a non-null argument}}
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
comment|// expected-warning {{null passed to a callee which requires a non-null argument}}
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
comment|// expected-warning{{null passed to a callee which requires a non-null argument}}
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
comment|// expected-warning{{null passed to a callee which requires a non-null argument}}
block|}
end_function

end_unit

