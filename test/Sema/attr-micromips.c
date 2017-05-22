begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -fsyntax-only -verify %s
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(nomicromips(
literal|0
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|foo1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'nomicromips' attribute takes no arguments}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(micromips(
literal|1
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|foo2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'micromips' attribute takes no arguments}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(nomicromips)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{attribute only applies to functions}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(micromips)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{attribute only applies to functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(micromips,mips16)
argument_list|)
end_macro

begin_function_decl
name|void
name|foo5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'micromips' and 'mips16' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(mips16,micromips)
argument_list|)
end_macro

begin_function_decl
name|void
name|foo6
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'mips16' and 'micromips' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(micromips)
argument_list|)
end_macro

begin_function_decl
name|void
name|foo7
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute
argument_list|(
argument|(nomicromips)
argument_list|)
end_macro

begin_function_decl
name|void
name|foo8
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(mips16)
argument_list|)
end_macro

begin_function_decl
name|void
name|foo9
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(micromips
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'micromips' and 'mips16' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note {{conflicting attribute is here}}
end_comment

end_unit

