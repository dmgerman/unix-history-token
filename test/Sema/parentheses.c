begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wparentheses -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wparentheses -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Test the various warnings under -Wparentheses
end_comment

begin_function
name|void
name|if_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|i
operator|=
literal|4
condition|)
block|{}
comment|// expected-warning {{assignment as a condition}} \
comment|// expected-note{{place parentheses around the assignment to silence this warning}} \
comment|// expected-note{{use '==' to turn this assignment into an equality comparison}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:7-[[@LINE-3]]:7}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:12-[[@LINE-4]]:12}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:9-[[@LINE-5]]:10}:"=="
if|if
condition|(
operator|(
name|i
operator|=
literal|4
operator|)
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|bitwise_rel
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
call|(
name|void
call|)
argument_list|(
name|i
operator|&
literal|0x2
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{& has lower precedence than ==}} \
comment|// expected-note{{place parentheses around the '==' expression to silence this warning}} \
comment|// expected-note{{place parentheses around the& expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:14-[[@LINE-3]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:22-[[@LINE-4]]:22}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:10-[[@LINE-5]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:17-[[@LINE-6]]:17}:")"
call|(
name|void
call|)
argument_list|(
literal|0
operator|==
name|i
operator|&
literal|0x2
argument_list|)
expr_stmt|;
comment|// expected-warning {{& has lower precedence than ==}} \
comment|// expected-note{{place parentheses around the '==' expression to silence this warning}} \
comment|// expected-note{{place parentheses around the& expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:10-[[@LINE-3]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:16-[[@LINE-4]]:16}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:15-[[@LINE-5]]:15}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:22-[[@LINE-6]]:22}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator|&
literal|0xff
operator|<
literal|30
argument_list|)
expr_stmt|;
comment|// expected-warning {{& has lower precedence than<}} \
comment|// expected-note{{place parentheses around the '<' expression to silence this warning}} \
comment|// expected-note{{place parentheses around the& expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:14-[[@LINE-3]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:23-[[@LINE-4]]:23}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:10-[[@LINE-5]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:18-[[@LINE-6]]:18}:")"
call|(
name|void
call|)
argument_list|(
operator|(
name|i
operator|&
literal|0x2
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|i
operator|&
operator|(
literal|0x2
operator|==
literal|0
operator|)
argument_list|)
expr_stmt|;
comment|// Eager logical op
call|(
name|void
call|)
argument_list|(
name|i
operator|==
literal|1
operator||
name|i
operator|==
literal|2
operator||
name|i
operator|==
literal|3
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|i
operator|!=
literal|1
operator|&
name|i
operator|!=
literal|2
operator|&
name|i
operator|!=
literal|3
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|i
operator|&
name|i
operator||
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&' within '|'}} \
comment|// expected-note {{place parentheses around the '&' expression to silence this warning}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:10-[[@LINE-2]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:15-[[@LINE-3]]:15}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator||
name|i
operator|&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&' within '|'}} \
comment|// expected-note {{place parentheses around the '&' expression to silence this warning}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:14-[[@LINE-2]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:19-[[@LINE-3]]:19}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator|||
name|i
operator|&&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&&' within '||'}} \
comment|// expected-note {{place parentheses around the '&&' expression to silence this warning}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:14-[[@LINE-2]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:20-[[@LINE-3]]:20}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator|||
name|i
operator|&&
literal|"w00t"
argument_list|)
expr_stmt|;
comment|// no warning.
call|(
name|void
call|)
argument_list|(
literal|"w00t"
operator|&&
name|i
operator|||
name|i
argument_list|)
expr_stmt|;
comment|// no warning.
call|(
name|void
call|)
argument_list|(
name|i
operator|||
name|i
operator|&&
literal|"w00t"
operator|||
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&&' within '||'}} \
comment|// expected-note {{place parentheses around the '&&' expression to silence this warning}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:15-[[@LINE-2]]:15}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:26-[[@LINE-3]]:26}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator|||
literal|"w00t"
operator|&&
name|i
operator|||
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&&' within '||'}} \
comment|// expected-note {{place parentheses around the '&&' expression to silence this warning}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-2]]:15-[[@LINE-2]]:15}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:26-[[@LINE-3]]:26}:")"
call|(
name|void
call|)
argument_list|(
name|i
operator|&&
name|i
operator|||
literal|0
argument_list|)
expr_stmt|;
comment|// no warning.
call|(
name|void
call|)
argument_list|(
literal|0
operator|||
name|i
operator|&&
name|i
argument_list|)
expr_stmt|;
comment|// no warning.
block|}
end_function

begin_function_decl
name|_Bool
name|someConditionFunc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|conditional_op
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|_Bool
name|b
parameter_list|)
block|{
call|(
name|void
call|)
argument_list|(
name|x
operator|+
name|someConditionFunc
argument_list|()
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{operator '?:' has lower precedence than '+'}} \
comment|// expected-note {{place parentheses around the '+' expression to silence this warning}} \
comment|// expected-note {{place parentheses around the '?:' expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:10-[[@LINE-3]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:33-[[@LINE-4]]:33}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:14-[[@LINE-5]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:41-[[@LINE-6]]:41}:")"
call|(
name|void
call|)
argument_list|(
operator|(
name|x
operator|+
name|someConditionFunc
argument_list|()
operator|)
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// no warning
call|(
name|void
call|)
argument_list|(
name|x
operator|-
name|b
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{operator '?:' has lower precedence than '-'}} \
comment|// expected-note {{place parentheses around the '-' expression to silence this warning}} \
comment|// expected-note {{place parentheses around the '?:' expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:10-[[@LINE-3]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:15-[[@LINE-4]]:15}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:14-[[@LINE-5]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:23-[[@LINE-6]]:23}:")"
call|(
name|void
call|)
argument_list|(
name|x
operator|*
operator|(
name|x
operator|==
name|y
operator|)
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{operator '?:' has lower precedence than '*'}} \
comment|// expected-note {{place parentheses around the '*' expression to silence this warning}} \
comment|// expected-note {{place parentheses around the '?:' expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:10-[[@LINE-3]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:22-[[@LINE-4]]:22}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:14-[[@LINE-5]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:30-[[@LINE-6]]:30}:")"
call|(
name|void
call|)
argument_list|(
name|x
operator|/
operator|!
name|x
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning {{operator '?:' has lower precedence than '/'}} \
comment|// expected-note {{place parentheses around the '/' expression to silence this warning}} \
comment|// expected-note {{place parentheses around the '?:' expression to evaluate it first}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-3]]:10-[[@LINE-3]]:10}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:16-[[@LINE-4]]:16}:")"
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-5]]:14-[[@LINE-5]]:14}:"("
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-6]]:24-[[@LINE-6]]:24}:")"
call|(
name|void
call|)
argument_list|(
name|x
operator|%
literal|2
condition|?
literal|1
else|:
literal|2
argument_list|)
expr_stmt|;
comment|// no warning
block|}
end_function

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -Wparentheses -Werror -fdiagnostics-show-option %s 2>&1 | FileCheck %s -check-prefix=CHECK-FLAG
end_comment

begin_comment
comment|// CHECK-FLAG: error: using the result of an assignment as a condition without parentheses [-Werror,-Wparentheses]
end_comment

end_unit

