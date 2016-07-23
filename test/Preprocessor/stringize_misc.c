begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_comment
comment|// RUN: %clang_cc1 -E %s -DTEST1 | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|M
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|#x #y
end_define

begin_macro
name|M
argument_list|(
argument|f(
literal|1
argument|,
literal|2
argument|)
argument_list|,
argument|g((x=y++, y))
argument_list|)
end_macro

begin_comment
comment|// CHECK: "f(1, 2)" "g((x=y++, y))"
end_comment

begin_macro
name|M
argument_list|(
argument|{a=
literal|1
argument_list|,
argument|b=
literal|2
argument|;}
argument_list|)
end_macro

begin_comment
comment|/* A semicolon is not a comma */
end_comment

begin_comment
comment|// CHECK: "{a=1" "b=2;}"
end_comment

begin_macro
name|M
argument_list|(
argument|<
argument_list|,
argument|[
argument_list|)
end_macro

begin_comment
comment|/* Passes the arguments< and [ */
end_comment

begin_comment
comment|// CHECK: "<" "["
end_comment

begin_macro
name|M
argument_list|(
argument|(,)
argument_list|,
argument|(...)
argument_list|)
end_macro

begin_comment
comment|/* Passes the arguments (,) and (...) */
end_comment

begin_comment
comment|// CHECK: "(,)" "(...)"
end_comment

begin_define
define|#
directive|define
name|START_END
parameter_list|(
name|start
parameter_list|,
name|end
parameter_list|)
value|start c=3; end
end_define

begin_macro
name|START_END
argument_list|(
argument|{a=
literal|1
argument_list|,
argument|b=
literal|2
argument|;}
argument_list|)
end_macro

begin_comment
comment|/* braces are not parentheses */
end_comment

begin_comment
comment|// CHECK: {a=1 c=3; b=2;}
end_comment

begin_comment
comment|/*   * To pass a comma token as an argument it is   * necessary to write:   */
end_comment

begin_define
define|#
directive|define
name|COMMA
value|,
end_define

begin_macro
name|M
argument_list|(
argument|a COMMA b
argument_list|,
argument|(a, b)
argument_list|)
end_macro

begin_comment
comment|// CHECK: "a COMMA b" "(a, b)"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST2
end_ifdef

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST2
end_comment

begin_define
define|#
directive|define
name|HASH
value|#
end_define

begin_define
define|#
directive|define
name|INVALID
parameter_list|()
value|#
end_define

begin_comment
comment|// expected-error@-1{{'#' is not followed by a macro parameter}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

