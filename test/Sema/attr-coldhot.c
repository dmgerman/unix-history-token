begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__hot__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__cold__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|var1
name|__attribute__
argument_list|(
operator|(
name|__cold__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'__cold__' attribute only applies to functions}}
end_comment

begin_decl_stmt
name|int
name|var2
name|__attribute__
argument_list|(
operator|(
name|__hot__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'__hot__' attribute only applies to functions}}
end_comment

begin_function_decl
name|int
name|qux
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__hot__
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|__cold__
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error{{'__hot__' and 'cold' attributes are not compatible}}
end_comment

begin_function_decl
name|int
name|baz
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__cold__
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|__hot__
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error{{'__cold__' and 'hot' attributes are not compatible}}
end_comment

end_unit

