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

end_unit

