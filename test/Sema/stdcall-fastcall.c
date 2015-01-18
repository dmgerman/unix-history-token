begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-apple-darwin10 %s
end_comment

begin_comment
comment|// CC qualifier can be applied only to functions
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|var1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'stdcall' only applies to function types; type here is 'int'}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|var2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'fastcall' only applies to function types; type here is 'int'}}
end_comment

begin_comment
comment|// Different CC qualifiers are not compatible
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|,
name|fastcall
operator|)
argument_list|)
name|foo3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{fastcall and stdcall attributes are not compatible}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|foo4
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous declaration is here}} expected-warning{{function with no prototype cannot use the stdcall calling convention}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo4
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{function declared 'fastcall' here was previously declared 'stdcall'}}
end_comment

begin_comment
comment|// rdar://8876096
end_comment

begin_function_decl
name|void
name|rdar8876096foo1
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(fastcall
operator|,
function_decl|cdecl
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo2
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(fastcall
operator|,
function_decl|stdcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo3
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(fastcall
operator|,
function_decl|regparm
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo4
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(stdcall
operator|,
function_decl|cdecl
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo5
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(stdcall
operator|,
function_decl|fastcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo6
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(cdecl
operator|,
function_decl|fastcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo7
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(cdecl
operator|,
function_decl|stdcall
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

begin_function_decl
name|void
name|rdar8876096foo8
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(regparm
parameter_list|(
function_decl|2
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|fastcall
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{not compatible}}
end_comment

end_unit

