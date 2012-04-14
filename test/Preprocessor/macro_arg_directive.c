begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// header1.h
end_comment

begin_function_decl
name|void
name|fail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MUNCH
parameter_list|(
modifier|...
parameter_list|)
define|\
value|({ int result = 0; __VA_ARGS__; if (!result) { fail(#__VA_ARGS__); }; result })
end_define

begin_function
specifier|static
specifier|inline
name|int
name|f
parameter_list|(
name|int
name|k
parameter_list|)
block|{
return|return
name|MUNCH
argument_list|(
comment|// expected-error {{expected ')'}} expected-note {{to match this '('}} expected-error {{returning 'void'}}
argument|if (k<
literal|3
argument|)       result =
literal|24
argument|;     else if (k>
literal|4
argument|)       result = k -
literal|4
argument|; }
include|#
directive|include
file|"macro_arg_directive.h"
comment|// expected-error {{embedding a #include directive within macro arguments is not supported}}
argument|int g(int k) {   return f(k) + f(k-
literal|1
argument|)
argument_list|)
return|;
block|}
end_function

end_unit

