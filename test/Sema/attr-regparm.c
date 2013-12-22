begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(regparm(
literal|2
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|x0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute
argument_list|(
argument|(regparm(
literal|1.0
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|x1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'regparm' attribute requires an integer constant}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(regparm(-
literal|1
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|x2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'regparm' parameter must be between 0 and 3 inclusive}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(regparm(
literal|5
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|x3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'regparm' parameter must be between 0 and 3 inclusive}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(regparm(
literal|5
argument|,
literal|3
argument|))
argument_list|)
end_macro

begin_function_decl
name|int
name|x4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'regparm' attribute takes one argument}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
name|x5
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|x5
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
name|x5
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{function declared with regparm(2) attribute was previously declared with the regparm(3) attribute}}
end_comment

end_unit

