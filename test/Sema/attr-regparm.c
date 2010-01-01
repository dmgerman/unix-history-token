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
name|x
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
name|x
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'regparm' attribute requires integer constant}}
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
name|x
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
name|x
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
name|x
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{attribute requires 1 argument(s)}}
end_comment

end_unit

