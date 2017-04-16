begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks -Wunreachable-code-aggressive -Wno-unused-value -Wno-covered-switch-default -I %S/Inputs
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fblocks -Wunreachable-code-aggressive -Wno-unused-value -Wno-covered-switch-default -fdiagnostics-parseable-fixits -I %S/Inputs %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"warn-unreachable.h"
end_include

begin_function_decl
name|int
name|halt
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|live
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dead
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|()
block|{
goto|goto
name|c
goto|;
name|d
label|:
goto|goto
name|e
goto|;
comment|// expected-warning {{will never be executed}}
name|c
label|:
empty_stmt|;
name|int
name|i
decl_stmt|;
return|return;
goto|goto
name|b
goto|;
comment|// expected-warning {{will never be executed}}
goto|goto
name|a
goto|;
comment|// expected-warning {{will never be executed}}
name|b
label|:
name|i
operator|=
literal|1
expr_stmt|;
name|a
label|:
name|i
operator|=
literal|2
expr_stmt|;
goto|goto
name|f
goto|;
name|e
label|:
goto|goto
name|d
goto|;
name|f
label|:
empty_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|live
argument_list|()
condition|)
block|{
case|case
literal|1
case|:
name|halt
argument_list|()
operator|,
name|dead
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
case|case
literal|2
case|:
name|live
argument_list|()
operator|,
name|halt
argument_list|()
operator|,
name|dead
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
case|case
literal|3
case|:
name|live
argument_list|()
operator|+
comment|// expected-warning {{will never be executed}}
name|halt
argument_list|()
expr_stmt|;
name|dead
argument_list|()
expr_stmt|;
case|case
literal|4
case|:
name|a4
label|:
name|live
argument_list|()
operator|,
name|halt
argument_list|()
expr_stmt|;
goto|goto
name|a4
goto|;
comment|// expected-warning {{will never be executed}}
case|case
literal|5
case|:
goto|goto
name|a5
goto|;
name|c5
label|:
name|dead
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
goto|goto
name|b5
goto|;
name|a5
label|:
name|live
argument_list|()
operator|,
name|halt
argument_list|()
expr_stmt|;
name|b5
label|:
goto|goto
name|c5
goto|;
case|case
literal|6
case|:
if|if
condition|(
name|live
argument_list|()
condition|)
goto|goto
name|e6
goto|;
name|live
argument_list|()
operator|,
name|halt
argument_list|()
expr_stmt|;
name|d6
label|:
name|dead
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
goto|goto
name|b6
goto|;
name|c6
label|:
name|dead
argument_list|()
expr_stmt|;
goto|goto
name|b6
goto|;
name|e6
label|:
name|live
argument_list|()
operator|,
name|halt
argument_list|()
expr_stmt|;
name|b6
label|:
goto|goto
name|c6
goto|;
case|case
literal|7
case|:
name|halt
argument_list|()
operator|+
name|dead
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
operator|-
comment|// expected-warning {{will never be executed}}
name|halt
argument_list|()
expr_stmt|;
case|case
literal|8
case|:
name|i
operator|+=
comment|// expected-warning {{will never be executed}}
name|halt
argument_list|()
expr_stmt|;
case|case
literal|9
case|:
name|halt
argument_list|()
condition|?
comment|// expected-warning {{will never be executed}}
name|dead
argument_list|()
else|:
name|dead
argument_list|()
expr_stmt|;
case|case
literal|10
case|:
operator|(
comment|// expected-warning {{will never be executed}}
name|float
operator|)
name|halt
argument_list|()
expr_stmt|;
case|case
literal|11
case|:
block|{
name|int
name|a
index|[
literal|5
index|]
decl_stmt|;
name|live
argument_list|()
operator|,
name|a
index|[
name|halt
argument_list|()
index|]
expr_stmt|;
comment|// expected-warning {{will never be executed}}
block|}
block|}
block|}
end_function

begin_enum
enum|enum
name|Cases
block|{
name|C1
block|,
name|C2
block|,
name|C3
block|}
enum|;
end_enum

begin_function
name|int
name|test_enum_cases
parameter_list|(
name|enum
name|Cases
name|C
parameter_list|)
block|{
switch|switch
condition|(
name|C
condition|)
block|{
case|case
name|C1
case|:
case|case
name|C2
case|:
case|case
name|C3
case|:
return|return
literal|1
return|;
default|default:
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// no-warning
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
block|}
block|}
block|}
end_function

begin_comment
comment|// Handle unreachable code triggered by macro expansions.
end_comment

begin_function_decl
name|void
name|__myassert_rtn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|myassert
parameter_list|(
name|e
parameter_list|)
define|\
value|(__builtin_expect(!(e), 0) ? __myassert_rtn(__func__, __FILE__, __LINE__, #e) : (void)0)
end_define

begin_function
name|void
name|test_assert
parameter_list|()
block|{
name|myassert
argument_list|(
literal|0
operator|&&
literal|"unreachable"
argument_list|)
expr_stmt|;
return|return;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Test case for PR 9774.  Tests that dead code in macros aren't warned about.
end_comment

begin_define
define|#
directive|define
name|MY_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>= (b) ? (a) : (b))
end_define

begin_function
name|void
name|PR9774
parameter_list|(
name|int
modifier|*
name|s
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|MY_MAX
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
condition|;
name|i
operator|++
control|)
comment|// no-warning
name|s
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test case for<rdar://problem/11005770>.  We should treat code guarded
end_comment

begin_comment
comment|// by 'x& 0' and 'x * 0' as unreachable.
end_comment

begin_function_decl
name|int
name|calledFun
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_mul_and_zero
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|&
literal|0
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
if|if
condition|(
literal|0
operator|&
name|x
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
if|if
condition|(
name|x
operator|*
literal|0
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
if|if
condition|(
literal|0
operator|*
name|x
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
block|}
end_function

begin_function_decl
name|void
name|raze
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|warn_here
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test_break_preceded_by_noreturn
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
name|raze
argument_list|()
expr_stmt|;
break|break;
comment|// expected-warning {{'break' will never be executed}}
case|case
literal|2
case|:
name|raze
argument_list|()
expr_stmt|;
break|break;
comment|// expected-warning {{'break' will never be executed}}
name|warn_here
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
case|case
literal|3
case|:
return|return
literal|1
return|;
break|break;
comment|// expected-warning {{will never be executed}}
default|default:
break|break;
break|break;
comment|// expected-warning {{will never be executed}}
block|}
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|// Don't warn about unreachable 'default' cases, as that is covered
end_comment

begin_comment
comment|// by -Wcovered-switch-default.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Value1
init|=
literal|1
block|}
name|MyEnum
typedef|;
end_typedef

begin_function
name|void
name|unreachable_default
parameter_list|(
name|MyEnum
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
condition|)
block|{
case|case
name|Value1
case|:
name|calledFun
argument_list|()
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|// expected-warning {{case value not in enumerated type 'MyEnum'}}
name|calledFun
argument_list|()
expr_stmt|;
break|break;
default|default:
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
block|}
block|}
end_function

begin_function
name|void
name|unreachable_in_default
parameter_list|(
name|MyEnum
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
condition|)
block|{
default|default:
name|raze
argument_list|()
expr_stmt|;
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
break|break;
block|}
block|}
end_function

begin_comment
comment|// Don't warn about trivial dead returns.
end_comment

begin_function
name|int
name|trivial_dead_return
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return
operator|(
operator|(
literal|0
operator|)
operator|)
return|;
comment|// expected-warning {{'return' will never be executed}}
block|}
end_function

begin_function
name|void
name|trivial_dead_return_void
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return;
comment|// expected-warning {{'return' will never be executed}}
block|}
end_function

begin_function
name|MyEnum
name|trivial_dead_return_enum
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return
name|Value1
return|;
comment|// expected-warning {{'return' will never be executed}}
block|}
end_function

begin_function
name|MyEnum
name|trivial_dead_return_enum_2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|1
return|;
case|case
literal|2
case|:
return|return
literal|2
return|;
case|case
literal|3
case|:
return|return
literal|3
return|;
default|default:
return|return
literal|4
return|;
block|}
return|return
literal|2
return|;
comment|// expected-warning {{will never be executed}}
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|trivial_dead_return_cstr
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return
literal|""
return|;
comment|// expected-warning {{return' will never be executed}}
block|}
end_function

begin_function
name|char
name|trivial_dead_return_char
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return
literal|' '
return|;
comment|// expected-warning {{return' will never be executed}}
block|}
end_function

begin_function
name|MyEnum
name|nontrivial_dead_return_enum_2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
return|return
literal|1
return|;
case|case
literal|2
case|:
return|return
literal|2
return|;
case|case
literal|3
case|:
return|return
literal|3
return|;
default|default:
return|return
literal|4
return|;
block|}
return|return
name|calledFun
argument_list|()
return|;
comment|// expected-warning {{will never be executed}}
block|}
end_function

begin_enum
enum|enum
name|X
block|{
name|A
block|,
name|B
block|,
name|C
block|}
enum|;
end_enum

begin_function
name|int
name|covered_switch
parameter_list|(
name|enum
name|X
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
name|A
case|:
return|return
literal|1
return|;
case|case
name|B
case|:
return|return
literal|2
return|;
case|case
name|C
case|:
return|return
literal|3
return|;
block|}
return|return
literal|4
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Test unreachable code depending on configuration values
end_comment

begin_define
define|#
directive|define
name|CONFIG_CONSTANT
value|1
end_define

begin_function
name|int
name|test_config_constant
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
operator|!
name|CONFIG_CONSTANT
condition|)
block|{
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
if|if
condition|(
operator|!
literal|1
condition|)
block|{
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
return|return
literal|1
return|;
block|}
if|if
condition|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|char
argument_list|)
condition|)
block|{
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
if|if
condition|(
name|x
operator|>
literal|10
condition|)
return|return
name|CONFIG_CONSTANT
condition|?
name|calledFun
argument_list|()
else|:
name|calledFun
argument_list|()
return|;
comment|// no-warning
else|else
return|return
literal|1
condition|?
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|calledFun
argument_list|()
else|:
name|calledFun
argument_list|()
return|;
comment|// expected-warning {{will never be executed}}
block|}
end_function

begin_function
name|int
name|sizeof_int
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// no-warning
if|if
condition|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
return|return
literal|0
return|;
comment|// no-warning
if|if
condition|(
name|x
operator|&&
name|y
operator|&&
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|char
argument_list|)
condition|)
return|return
literal|0
return|;
comment|// no-warning
return|return
literal|2
return|;
comment|// no-warning
block|}
end_function

begin_enum
enum|enum
name|MyEnum2
block|{
name|ME_A
init|=
name|CONFIG_CONSTANT
block|,
name|ME_B
init|=
literal|1
block|}
enum|;
end_enum

begin_function
name|int
name|test_MyEnum
parameter_list|()
block|{
if|if
condition|(
operator|!
name|ME_A
condition|)
return|return
literal|1
return|;
comment|// no-warning
if|if
condition|(
name|ME_A
condition|)
return|return
literal|2
return|;
comment|// no-warning
if|if
condition|(
name|ME_B
condition|)
return|return
literal|3
return|;
if|if
condition|(
operator|!
name|ME_B
condition|)
comment|// expected-warning {{will never be executed}}
return|return
literal|4
return|;
comment|// expected-warning {{will never be executed}}
return|return
literal|5
return|;
block|}
end_function

begin_comment
comment|// Test for idiomatic do..while.
end_comment

begin_function
name|int
name|test_do_while
parameter_list|(
name|int
name|x
parameter_list|)
block|{
do|do
block|{
if|if
condition|(
name|x
operator|==
name|calledFun
argument_list|()
condition|)
break|break;
operator|++
name|x
expr_stmt|;
break|break;
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// no-warning
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|test_do_while_nontrivial_cond
parameter_list|(
name|int
name|x
parameter_list|)
block|{
do|do
block|{
if|if
condition|(
name|x
operator|==
name|calledFun
argument_list|()
condition|)
break|break;
operator|++
name|x
expr_stmt|;
break|break;
block|}
do|while
condition|(
name|calledFun
argument_list|()
condition|)
do|;
comment|// expected-warning {{will never be executed}}
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Diagnostic control: -Wunreachable-code-return.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wunreachable-code-return"
end_pragma

begin_function
name|void
name|trivial_dead_return_void_SUPPRESSED
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return;
comment|// no-warning
block|}
end_function

begin_function
name|MyEnum
name|trivial_dead_return_enum_SUPPRESSED
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
return|return
name|Value1
return|;
comment|// no-warning
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// Diagnostic control: -Wunreachable-code-break.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wunreachable-code-break"
end_pragma

begin_function
name|int
name|test_break_preceded_by_noreturn_SUPPRESSED
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
name|raze
argument_list|()
expr_stmt|;
break|break;
comment|// no-warning
case|case
literal|2
case|:
name|raze
argument_list|()
expr_stmt|;
break|break;
comment|// no-warning
name|warn_here
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
case|case
literal|3
case|:
return|return
literal|1
return|;
break|break;
comment|// no-warning
default|default:
break|break;
break|break;
comment|// no-warning
block|}
return|return
name|i
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// Test "silencing" with parentheses.
end_comment

begin_function
name|void
name|test_with_paren_silencing
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
literal|0
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}} expected-note {{silence by adding parentheses to mark code as explicitly dead}}
if|if
condition|(
operator|(
literal|0
operator|)
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
if|if
condition|(
literal|1
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|calledFun
argument_list|()
expr_stmt|;
else|else
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{will never be executed}}
if|if
condition|(
operator|(
literal|1
operator|)
condition|)
name|calledFun
argument_list|()
expr_stmt|;
else|else
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
if|if
condition|(
operator|!
literal|1
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|calledFun
argument_list|()
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
else|else
name|calledFun
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
operator|!
literal|1
operator|)
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
else|else
name|calledFun
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
literal|1
operator|)
condition|)
name|calledFun
argument_list|()
expr_stmt|;
comment|// no-warning
else|else
name|calledFun
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://24570531
end_comment

begin_struct
struct|struct
name|StructWithPointer
block|{
name|void
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|emitJustOneWarningForOr
parameter_list|(
name|struct
name|StructWithPointer
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
literal|1
operator|||
operator|!
name|s
operator|->
name|p
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
return|return;
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:7-[[@LINE-1]]:7}:"/* DISABLES CODE */ ("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:8-[[@LINE-2]]:8}:")"
name|emitJustOneWarningForOr
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|void
name|emitJustOneWarningForOrSilenced
parameter_list|(
name|struct
name|StructWithPointer
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
operator|(
literal|1
operator|)
operator|||
operator|!
name|s
operator|->
name|p
condition|)
return|return;
name|emitJustOneWarningForOrSilenced
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// no warning
block|}
end_function

begin_function
name|void
name|emitJustOneWarningForOr2
parameter_list|(
name|struct
name|StructWithPointer
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
literal|1
operator|||
operator|!
name|s
operator|->
name|p
condition|)
comment|// expected-warning {{code will never be executed}}
return|return;
comment|// expected-note@-1 {{silence by adding parentheses to mark code as explicitly dead}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:7-[[@LINE-2]]:7}:"/* DISABLES CODE */ ("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:8-[[@LINE-3]]:8}:")"
block|}
end_function

begin_function
name|void
name|wrapOneInFixit
parameter_list|(
name|struct
name|StructWithPointer
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
name|s
operator|->
name|p
operator|||
literal|1
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
return|return;
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:16-[[@LINE-1]]:16}:"/* DISABLES CODE */ ("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:17-[[@LINE-2]]:17}:")"
name|wrapOneInFixit
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|void
name|unaryOpNoFixit
parameter_list|()
block|{
if|if
condition|(
operator|-
literal|1
condition|)
return|return;
comment|// CHECK-NOT: fix-it:"{{.*}}":{[[@LINE-1]]
name|unaryOpNoFixit
argument_list|()
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|void
name|unaryOpStrictFixit
parameter_list|(
name|struct
name|StructWithPointer
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|s
operator|->
name|p
operator|&&
literal|0
operator|)
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
return|return;
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:17-[[@LINE-1]]:17}:"/* DISABLES CODE */ ("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:18-[[@LINE-2]]:18}:")"
name|unaryOpStrictFixit
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|void
name|unaryOpFixitCastSubExpr
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|int
operator|)
literal|0
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
return|return;
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:7-[[@LINE-1]]:7}:"/* DISABLES CODE */ ("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:15-[[@LINE-2]]:15}:")"
name|unaryOpFixitCastSubExpr
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_function
name|void
name|testTrueFalseMacros
parameter_list|()
block|{
if|if
condition|(
name|false
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|testTrueFalseMacros
argument_list|()
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
if|if
condition|(
operator|!
name|true
condition|)
comment|// expected-note {{silence by adding parentheses to mark code as explicitly dead}}
name|testTrueFalseMacros
argument_list|()
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|int
name|pr13910_foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|==
literal|1
condition|)
return|return
literal|0
return|;
else|else
return|return
name|x
return|;
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// expected no warning
block|}
end_function

begin_function
name|int
name|pr13910_bar
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
name|x
operator|+
literal|1
return|;
block|}
name|pr13910_foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|int
name|pr13910_bar2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|==
literal|1
condition|)
return|return
literal|0
return|;
else|else
return|return
name|x
return|;
name|pr13910_foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// expected no warning
name|pr13910_foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{code will never be executed}}
block|}
end_function

begin_function
name|void
name|pr13910_noreturn
parameter_list|()
block|{
name|raze
argument_list|()
expr_stmt|;
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// expected no warning
block|}
end_function

begin_function
name|void
name|pr13910_assert
parameter_list|()
block|{
name|myassert
argument_list|(
literal|0
operator|&&
literal|"unreachable"
argument_list|)
expr_stmt|;
return|return;
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// expected no warning
block|}
end_function

end_unit

