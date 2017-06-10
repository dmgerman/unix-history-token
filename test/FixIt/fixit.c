begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pedantic -Wunused-label -verify -x c %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -pedantic -Wunused-label -fixit -x c %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Wunused-label -Werror -x c %t
end_comment

begin_comment
comment|// RUN: grep -v CHECK %t | FileCheck %t
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_comment
comment|// FIXME: FIX-IT should add #include<string.h>?
end_comment

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{';'}}
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
empty_stmt|;
comment|// expected-warning {{extra ';'}}
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: _Complex double cd;
end_comment

begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{assuming '_Complex double'}}
end_comment

begin_comment
comment|// CHECK: struct s s0 = { .y = 5 };
end_comment

begin_decl_stmt
name|struct
name|s
name|s0
init|=
block|{
name|y
operator|:
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{GNU old-style}}
end_comment

begin_comment
comment|// CHECK: int array0[5] = { [3] = 3 };
end_comment

begin_decl_stmt
name|int
name|array0
index|[
literal|5
index|]
init|=
block|{
index|[
literal|3
index|]
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{GNU 'missing ='}}
end_comment

begin_comment
comment|// CHECK: int x
end_comment

begin_comment
comment|// CHECK: int y
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
comment|// expected-warning 2{{defaulting to type 'int'}}
block|{ }
end_function

begin_decl_stmt
name|int
name|i0
init|=
block|{
literal|17
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ONE
value|1
end_define

begin_define
define|#
directive|define
name|TWO
value|2
end_define

begin_function
name|int
name|test_cond
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|fooBar
parameter_list|)
block|{
comment|// expected-note {{here}}
comment|// CHECK: int x = y ? 1 : 4+fooBar;
name|int
name|x
init|=
name|y
condition|?
literal|1
literal|4
operator|+
name|foobar
decl_stmt|;
comment|// expected-error {{expected ':'}} expected-error {{undeclared identifier}} expected-note {{to match}}
comment|// CHECK: x = y ? ONE : TWO;
name|x
operator|=
name|y
condition|?
name|ONE
name|TWO
expr_stmt|;
comment|// expected-error {{':'}} expected-note {{to match}}
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: const typedef int int_t;
end_comment

begin_expr_stmt
specifier|const
end_expr_stmt

begin_typedef
typedef|typedef
typedef|typedef
name|int
name|int_t
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{duplicate 'typedef'}}
end_comment

begin_comment
comment|//<rdar://problem/7159693>
end_comment

begin_enum
enum|enum
name|Color
block|{
name|Red
comment|// expected-error{{missing ',' between enumerators}}
name|Green
init|=
literal|17
comment|// expected-error{{missing ',' between enumerators}}
name|Blue
block|, }
enum|;
end_enum

begin_comment
comment|// rdar://9295072
end_comment

begin_struct
struct|struct
name|test_struct
block|{
comment|// CHECK: struct test_struct *struct_ptr;
name|test_struct
modifier|*
name|struct_ptr
decl_stmt|;
comment|// expected-error {{must use 'struct' tag to refer to type 'test_struct'}}
block|}
struct|;
end_struct

begin_function
name|void
name|removeUnusedLabels
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|L0
comment|/*removed comment*/
label|:
name|c
operator|++
expr_stmt|;
comment|// expected-warning {{unused label}}
name|removeUnusedLabels
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|L1
label|:
comment|// expected-warning {{unused label}}
name|c
operator|++
expr_stmt|;
comment|/*preserved comment*/
name|L2
label|:
name|c
operator|++
expr_stmt|;
comment|// expected-warning {{unused label}}
name|LL
comment|// expected-warning {{unused label}}
label|:
name|c
operator|++
expr_stmt|;
name|c
operator|=
name|c
operator|+
literal|3
expr_stmt|;
name|L4
label|:
return|return;
comment|// expected-warning {{unused label}}
block|}
end_function

begin_decl_stmt
name|int
name|oopsAComma
init|=
literal|0
decl_stmt|,
comment|// expected-error {{';'}}
name|void
name|oopsMoreCommas
argument_list|()
block|{
specifier|static
name|int
name|a
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|}
decl_stmt|,
comment|// expected-error {{';'}}
decl_stmt|static
name|int
name|b
index|[]
init|=
block|{
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|,
comment|// expected-error {{';'}}
modifier|&
name|a
decl|==
modifier|&
name|b
decl|?
name|oopsMoreCommas
argument_list|()
range|:
name|removeUnusedLabels
argument_list|(
name|a
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|commaAtEndOfStatement
parameter_list|()
block|{
name|int
name|a
init|=
literal|1
decl_stmt|;
name|a
operator|=
literal|5
operator|,
comment|// expected-error {{';'}}
name|int
name|m
operator|=
literal|5
operator|,
comment|// expected-error {{';'}}
return|return
literal|0
operator|,
comment|// expected-error {{';'}}
block|}
end_function

begin_function
name|int
name|noSemiAfterLabel
parameter_list|(
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
default|default:
return|return
name|n
operator|%
literal|4
return|;
case|case
literal|0
case|:
case|case
literal|1
case|:
case|case
literal|2
case|:
comment|// CHECK: /*FOO*/ case 3: ;
comment|/*FOO*/
case|case
literal|3
case|:
comment|// expected-error {{expected statement}}
block|}
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|2
case|:
return|return
literal|0
return|;
comment|// CHECK: /*BAR*/ default: ;
comment|/*BAR*/
default|default:
comment|// expected-error {{expected statement}}
block|}
return|return
literal|1
return|;
block|}
end_function

begin_macro
unit|struct
name|noSemiAfterStruct
end_macro

begin_comment
comment|// expected-error {{expected ';' after struct}}
end_comment

begin_struct
struct|struct
name|noSemiAfterStruct
block|{
name|int
name|n
comment|// expected-warning {{';'}}
block|}
comment|// expected-error {{expected ';' after struct}}
decl|enum
name|noSemiAfterEnum
block|{
name|e1
block|}
comment|// expected-error {{expected ';' after enum}}
name|int
name|PR17175
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
name|hidden
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// expected-error {{'visibility' attribute requires a string}}
end_comment

end_unit

