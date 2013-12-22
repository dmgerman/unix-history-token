begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|test0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"hidden"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"internal"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// rdar://problem/10753392
end_comment

begin_function_decl
name|void
name|test3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"protected"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{target does not support 'protected' visibility; using 'default'}}
end_comment

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|test4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_struct_decl
struct_decl|struct
name|test4
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|test4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{visibility does not match previous declaration}}
end_comment

begin_struct_decl
struct_decl|struct
name|test5
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|test5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|test5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{visibility does not match previous declaration}}
end_comment

begin_function_decl
name|void
name|test6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"hidden"
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_expr_stmt
name|visibility
argument_list|(
literal|"default"
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{visibility does not match previous declaration}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test7
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous attribute is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|test7
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{visibility does not match previous declaration}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|bar
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{'visibility' attribute ignored}}
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|type_visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'type_visibility' attribute only applies to types and namespaces}}
end_comment

begin_decl_stmt
name|int
name|PR17105
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
name|hidden
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'visibility' attribute requires a string}}
end_comment

end_unit

