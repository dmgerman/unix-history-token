begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// expected-error {{'#pragma clang attribute pop' with no matching '#pragma clang attribute push'}}
end_comment

begin_comment
comment|// Don't verify unused attributes.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-warning {{unused attribute 'annotate' in '#pragma clang attribute push' region}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// expected-note {{'#pragma clang attribute push' regions ends here}}
end_comment

begin_comment
comment|// Ensure we only report any errors once.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-error 4 {{'annotate' attribute takes one argument}}
end_comment

begin_function_decl
name|void
name|test5_begin
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{when applied to this declaration}}
end_comment

begin_function_decl
name|void
name|test5_1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{when applied to this declaration}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|(
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-error 2 {{'annotate' attribute takes one argument}}
end_comment

begin_function_decl
name|void
name|test5_2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 2 {{when applied to this declaration}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|(
literal|"hello"
name|,
literal|"world"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-error {{'annotate' attribute takes one argument}}
end_comment

begin_function_decl
name|void
name|test5_3
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note 3 {{when applied to this declaration}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// Verify that the warnings are reported for each receiver declaration
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|optnone
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-note 2 {{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
name|void
name|optnone1
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning {{'always_inline' attribute ignored}}
end_comment

begin_comment
comment|// expected-note@-1 {{when applied to this declaration}}
end_comment

begin_function
name|void
name|optnone2
parameter_list|()
block|{ }
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
name|void
name|optnone3
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-warning {{'always_inline' attribute ignored}}
end_comment

begin_comment
comment|// expected-note@-1 {{when applied to this declaration}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|[
name|[
name|]
name|]
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// A noop
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|pop
end_pragma

begin_comment
comment|// expected-error {{'#pragma clang attribute pop' with no matching '#pragma clang attribute push'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|attribute
name|push
name|(
name|__attribute__
name|(
name|(
name|annotate
name|(
literal|"func"
name|)
name|)
name|)
name|,
name|apply_to
name|=
name|function
name|)
end_pragma

begin_comment
comment|// expected-error {{unterminated '#pragma clang attribute push' at end of file}}
end_comment

begin_function_decl
name|void
name|function
parameter_list|()
function_decl|;
end_function_decl

end_unit

