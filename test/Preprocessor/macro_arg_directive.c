begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_define
define|#
directive|define
name|a
parameter_list|(
name|x
parameter_list|)
value|enum { x }
end_define

begin_expr_stmt
name|a
argument_list|(
name|n
operator|=
undef|#
directive|undef
name|a
define|#
directive|define
name|a
value|5
name|a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_assert
assert|_Static_assert
argument_list|(
name|n
operator|==
literal|5
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_define
define|#
directive|define
name|M
parameter_list|(
name|A
parameter_list|)
end_define

begin_macro
name|M
argument_list|(
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
comment|// expected-error {{embedding a #pragma directive within macro arguments is not supported}}
argument_list|)
end_macro

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

