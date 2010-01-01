begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -Eonly -std=c89 -pedantic -verify */
end_comment

begin_comment
comment|/* PR3937 */
end_comment

begin_define
define|#
directive|define
name|zero
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|one
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|two
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|zero_dot
parameter_list|(
modifier|...
parameter_list|)
value|0
end_define

begin_comment
comment|/* expected-warning {{variadic macros were introduced in C99}} */
end_comment

begin_define
define|#
directive|define
name|one_dot
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|0
end_define

begin_comment
comment|/* expected-warning {{variadic macros were introduced in C99}} */
end_comment

begin_macro
name|zero
argument_list|()
end_macro

begin_expr_stmt
name|zero
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* expected-error {{too many arguments provided to function-like macro invocation}} */
end_comment

begin_expr_stmt
name|zero
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* expected-error {{too many arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|one
argument_list|()
end_macro

begin_comment
comment|/* ok */
end_comment

begin_macro
name|one
argument_list|(
argument|a
argument_list|)
end_macro

begin_macro
name|one
argument_list|(
argument|a
argument_list|,)
end_macro

begin_comment
comment|/* expected-error {{too many arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|one
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_comment
comment|/* expected-error {{too many arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|two
argument_list|()
end_macro

begin_comment
comment|/* expected-error {{too few arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|two
argument_list|(
argument|a
argument_list|)
end_macro

begin_comment
comment|/* expected-error {{too few arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|two
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_macro
name|two
argument_list|(
argument|a
argument_list|, )
end_macro

begin_comment
comment|/* expected-warning {{empty macro arguments were standardized in C99}} */
end_comment

begin_macro
name|two
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
end_macro

begin_comment
comment|/* expected-error {{too many arguments provided to function-like macro invocation}} */
end_comment

begin_macro
name|two
argument_list|(
argument_list|,
comment|/* expected-warning {{empty macro arguments were standardized in C99}} */
argument_list|,
comment|/* expected-warning {{empty macro arguments were standardized in C99}}  \              expected-error {{too many arguments provided to function-like macro invocation}} */
argument_list|)
end_macro

begin_macro
name|two
argument_list|(
argument_list|,)
end_macro

begin_comment
comment|/* expected-warning 2 {{empty macro arguments were standardized in C99}} */
end_comment

begin_comment
comment|/* PR4006& rdar://6807000 */
end_comment

begin_define
define|#
directive|define
name|e
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_comment
comment|/* expected-warning {{variadic macros were introduced in C99}} */
end_comment

begin_macro
name|e
argument_list|(
argument|x
argument_list|)
end_macro

begin_macro
name|e
argument_list|()
end_macro

begin_macro
name|zero_dot
argument_list|()
end_macro

begin_macro
name|one_dot
argument_list|(
argument|x
argument_list|)
end_macro

begin_comment
comment|/* empty ... argument: expected-warning {{varargs argument missing, but tolerated as an extension}}  */
end_comment

begin_macro
name|one_dot
argument_list|()
end_macro

begin_comment
comment|/* empty first argument, elided ...: expected-warning {{varargs argument missing, but tolerated as an extension}} */
end_comment

begin_comment
comment|/* rdar://6816766 - Crash with function-like macro test at end of directive. */
end_comment

begin_define
define|#
directive|define
name|E
parameter_list|()
value|(i == 0)
end_define

begin_if
if|#
directive|if
name|E
end_if

begin_endif
endif|#
directive|endif
end_endif

end_unit

