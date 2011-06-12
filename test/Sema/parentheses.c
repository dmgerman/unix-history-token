begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wparentheses -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wparentheses -fixit %s -o - | %clang_cc1 -Wparentheses -Werror -
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
comment|// expected-note{{use '==' to turn this assignment into an equality comparison}} \
comment|// expected-note{{place parentheses around the assignment to silence this warning}}
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
comment|// expected-note{{place parentheses around the& expression to evaluate it first}} \
comment|// expected-note{{place parentheses around the == expression to silence this warning}}
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
comment|// expected-note{{place parentheses around the& expression to evaluate it first}} \
comment|// expected-note{{place parentheses around the == expression to silence this warning}}
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
comment|// expected-note{{place parentheses around the& expression to evaluate it first}} \
comment|// expected-note{{place parentheses around the< expression to silence this warning}}
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
operator|||
name|i
operator|&&
name|i
argument_list|)
expr_stmt|;
comment|// expected-warning {{'&&' within '||'}} \
comment|// expected-note {{place parentheses around the '&&' expression to silence this warning}}
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
comment|// expected-warning {{?: has lower precedence than +}} \
comment|// expected-note {{place parentheses around the ?: expression to evaluate it first}} \
comment|// expected-note {{place parentheses around the + expression to silence this warning}}
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
comment|// expected-warning {{?: has lower precedence than -}} \
comment|// expected-note {{place parentheses around the ?: expression to evaluate it first}} \
comment|// expected-note {{place parentheses around the - expression to silence this warning}}
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
comment|// expected-warning {{?: has lower precedence than *}} \
comment|// expected-note {{place parentheses around the ?: expression to evaluate it first}} \
comment|// expected-note {{place parentheses around the * expression to silence this warning}}
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
comment|// expected-warning {{?: has lower precedence than /}} \
comment|// expected-note {{place parentheses around the ?: expression to evaluate it first}} \
comment|// expected-note {{place parentheses around the / expression to silence this warning}}
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
comment|// RUN: %clang_cc1 -fsyntax-only -Wparentheses -Werror -fdiagnostics-show-option %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: using the result of an assignment as a condition without parentheses [-Werror,-Wparentheses]
end_comment

end_unit

