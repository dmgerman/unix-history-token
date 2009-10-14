begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -warn-dead-stores -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=basic -analyzer-constraints=basic -warn-dead-stores -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=basic -analyzer-constraints=range -warn-dead-stores -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=region -analyzer-constraints=basic -warn-dead-stores -verify %s&&
end_comment

begin_comment
comment|// RUN: clang-cc -analyze -checker-cfref -analyzer-store=region -analyzer-constraints=range -warn-dead-stores -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
name|int
name|k
decl_stmt|,
name|y
decl_stmt|;
name|int
name|abc
init|=
literal|1
decl_stmt|;
name|long
name|idx
init|=
name|abc
operator|+
literal|3
operator|*
literal|5
decl_stmt|;
comment|// expected-warning {{never read}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
modifier|*
name|b
parameter_list|)
block|{
name|char
modifier|*
name|c
init|=
operator|(
name|char
operator|*
operator|)
name|b
decl_stmt|;
comment|// no-warning
name|char
modifier|*
name|d
init|=
name|b
operator|+
literal|1
decl_stmt|;
comment|// expected-warning {{never read}}
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring C library function 'printf' with type 'int (char const *, ...)'}} \
comment|// expected-note{{please include the header<stdio.h> or explicitly provide a declaration for 'printf'}}
block|}
end_function

begin_function
name|void
name|f3
parameter_list|()
block|{
name|int
name|r
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|=
name|f
argument_list|()
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// no-warning
name|int
name|y
init|=
name|r
decl_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"the error is: %d\n"
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|f4
parameter_list|(
name|int
name|k
parameter_list|)
block|{
name|k
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|k
condition|)
name|f1
argument_list|()
expr_stmt|;
name|k
operator|=
literal|2
expr_stmt|;
comment|// expected-warning {{never read}}
block|}
end_function

begin_function
name|void
name|f5
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
comment|// no-warning
name|int
modifier|*
name|p
init|=
operator|&
name|x
decl_stmt|;
comment|// expected-warning{{never read}}
block|}
end_function

begin_function
name|int
name|f6
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
operator|++
name|x
expr_stmt|;
comment|// expected-warning{{never read}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f7
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// This is allowed for defensive programming.
name|p
operator|=
literal|0
expr_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f8
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
specifier|extern
name|int
modifier|*
name|baz
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|p
operator|=
name|baz
argument_list|()
operator|)
condition|)
comment|// expected-warning{{Although the value}}
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|f9
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
name|x
operator|=
name|x
operator|+
literal|10
expr_stmt|;
comment|// expected-warning{{never read}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f10
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
name|x
operator|=
literal|10
operator|+
name|x
expr_stmt|;
comment|// expected-warning{{never read}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f11
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
return|return
name|x
operator|++
return|;
comment|// expected-warning{{never read}}
block|}
end_function

begin_function
name|int
name|f11b
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
return|return
operator|(
operator|(
operator|(
operator|(
operator|++
name|x
operator|)
operator|)
operator|)
operator|)
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f12a
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|int
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning{{never read}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f12b
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
init|=
name|y
decl_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// Filed with PR 2630.  This code should produce no warnings.
end_comment

begin_function
name|int
name|f13
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
init|=
literal|1
decl_stmt|;
name|int
name|b
decl_stmt|,
name|c
init|=
name|b
operator|=
name|a
operator|+
name|a
decl_stmt|;
if|if
condition|(
name|b
operator|>
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|a
operator|+
name|b
operator|+
name|c
operator|)
return|;
block|}
end_function

begin_comment
comment|// Filed with PR 2763.
end_comment

begin_function
name|int
name|f14
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|int
name|index
decl_stmt|,
name|nextLineIndex
decl_stmt|;
for|for
control|(
name|index
operator|=
literal|0
init|;
name|index
operator|<
name|count
condition|;
name|index
operator|=
name|nextLineIndex
operator|+
literal|1
control|)
block|{
name|nextLineIndex
operator|=
name|index
operator|+
literal|1
expr_stmt|;
comment|// no-warning
continue|continue;
block|}
return|return
name|index
return|;
block|}
end_function

begin_comment
comment|// Test case for<rdar://problem/6248086>
end_comment

begin_function
name|void
name|f15
parameter_list|(
name|unsigned
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|)
block|{
name|int
name|count
init|=
name|x
operator|*
name|y
decl_stmt|;
comment|// no-warning
name|int
name|z
index|[
name|count
index|]
decl_stmt|;
block|}
end_function

begin_function
name|int
name|f16
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|x
operator|=
name|x
operator|*
literal|2
expr_stmt|;
name|x
operator|=
sizeof|sizeof
argument_list|(
name|int
index|[
name|x
operator|=
operator|(
name|x
operator|||
name|x
operator|+
literal|1
operator|)
operator|*
literal|2
index|]
argument_list|)
comment|// expected-warning{{Although the value stored to 'x' is used}}
condition|?
literal|5
else|:
literal|8
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Self-assignments should not be flagged as dead stores.
end_comment

begin_function
name|void
name|f17
parameter_list|()
block|{
name|int
name|x
init|=
literal|1
decl_stmt|;
name|x
operator|=
name|x
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//<rdar://problem/6506065>
end_comment

begin_comment
comment|// The values of dead stores are only "consumed" in an enclosing expression
end_comment

begin_comment
comment|// what that value is actually used.  In other words, don't say "Although the
end_comment

begin_comment
comment|// value stored to 'x' is used...".
end_comment

begin_function
name|int
name|f18
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|// no-warning
if|if
condition|(
literal|1
condition|)
name|x
operator|=
literal|10
expr_stmt|;
comment|// expected-warning{{Value stored to 'x' is never read}}
while|while
condition|(
literal|1
condition|)
name|x
operator|=
literal|10
expr_stmt|;
comment|// expected-warning{{Value stored to 'x' is never read}}
do|do
name|x
operator|=
literal|10
expr_stmt|;
comment|// expected-warning{{Value stored to 'x' is never read}}
do|while
condition|(
literal|1
condition|)
do|;
return|return
operator|(
name|x
operator|=
literal|10
operator|)
return|;
comment|// expected-warning{{Although the value stored to 'x' is used in the enclosing expression, the value is never actually read from 'x'}}
block|}
end_function

begin_comment
comment|// PR 3514: false positive `dead initialization` warning for init to global
end_comment

begin_comment
comment|//  http://llvm.org/bugs/show_bug.cgi?id=3514
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|MyConstant
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f19
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
name|MyConstant
decl_stmt|;
comment|// no-warning
name|x
operator|=
literal|1
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|f19b
parameter_list|(
name|void
parameter_list|)
block|{
comment|// This case is the same as f19.
specifier|const
name|int
name|MyConstant
init|=
literal|0
decl_stmt|;
name|int
name|x
init|=
name|MyConstant
decl_stmt|;
comment|// no-warning
name|x
operator|=
literal|1
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|f20
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
literal|1
decl_stmt|;
comment|// no-warning
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
block|}
end_function

begin_function_decl
name|void
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

begin_function
name|int
name|f21
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
operator|++
name|x
expr_stmt|;
comment|// expected-warning{{never read}}
if|if
condition|(
literal|1
condition|)
block|{
name|halt
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f22
parameter_list|()
block|{
name|int
name|x
init|=
literal|4
decl_stmt|;
name|int
name|y1
init|=
literal|4
decl_stmt|;
name|int
name|y2
init|=
literal|4
decl_stmt|;
name|int
name|y3
init|=
literal|4
decl_stmt|;
name|int
name|y4
init|=
literal|4
decl_stmt|;
name|int
name|y5
init|=
literal|4
decl_stmt|;
name|int
name|y6
init|=
literal|4
decl_stmt|;
name|int
name|y7
init|=
literal|4
decl_stmt|;
name|int
name|y8
init|=
literal|4
decl_stmt|;
name|int
name|y9
init|=
literal|4
decl_stmt|;
name|int
name|y10
init|=
literal|4
decl_stmt|;
name|int
name|y11
init|=
literal|4
decl_stmt|;
name|int
name|y12
init|=
literal|4
decl_stmt|;
name|int
name|y13
init|=
literal|4
decl_stmt|;
name|int
name|y14
init|=
literal|4
decl_stmt|;
name|int
name|y15
init|=
literal|4
decl_stmt|;
name|int
name|y16
init|=
literal|4
decl_stmt|;
name|int
name|y17
init|=
literal|4
decl_stmt|;
name|int
name|y18
init|=
literal|4
decl_stmt|;
name|int
name|y19
init|=
literal|4
decl_stmt|;
name|int
name|y20
init|=
literal|4
decl_stmt|;
operator|++
name|x
expr_stmt|;
comment|// expected-warning{{never read}}
operator|++
name|y1
expr_stmt|;
operator|++
name|y2
expr_stmt|;
operator|++
name|y3
expr_stmt|;
operator|++
name|y4
expr_stmt|;
operator|++
name|y5
expr_stmt|;
operator|++
name|y6
expr_stmt|;
operator|++
name|y7
expr_stmt|;
operator|++
name|y8
expr_stmt|;
operator|++
name|y9
expr_stmt|;
operator|++
name|y10
expr_stmt|;
operator|++
name|y11
expr_stmt|;
operator|++
name|y12
expr_stmt|;
operator|++
name|y13
expr_stmt|;
operator|++
name|y14
expr_stmt|;
operator|++
name|y15
expr_stmt|;
operator|++
name|y16
expr_stmt|;
operator|++
name|y17
expr_stmt|;
operator|++
name|y18
expr_stmt|;
operator|++
name|y19
expr_stmt|;
operator|++
name|y20
expr_stmt|;
switch|switch
condition|(
name|j
condition|)
block|{
case|case
literal|1
case|:
if|if
condition|(
literal|0
condition|)
operator|(
name|void
operator|)
name|x
expr_stmt|;
if|if
condition|(
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|y1
expr_stmt|;
return|return;
block|}
operator|(
name|void
operator|)
name|x
expr_stmt|;
break|break;
case|case
literal|2
case|:
if|if
condition|(
literal|0
condition|)
operator|(
name|void
operator|)
name|x
expr_stmt|;
else|else
block|{
operator|(
name|void
operator|)
name|y2
expr_stmt|;
return|return;
block|}
operator|(
name|void
operator|)
name|x
expr_stmt|;
break|break;
case|case
literal|3
case|:
if|if
condition|(
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|y3
expr_stmt|;
return|return;
block|}
else|else
operator|(
name|void
operator|)
name|x
expr_stmt|;
operator|(
name|void
operator|)
name|x
expr_stmt|;
break|break;
case|case
literal|4
case|:
literal|0
condition|?
else|:
operator|(
operator|(
name|void
operator|)
name|y4
operator|,
operator|(
block|{
return|return;
block|}
block|)
block|)
function|;
end_function

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|5
case|:
end_case

begin_expr_stmt
literal|1
condition|?
else|:
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_expr_stmt
literal|0
condition|?
operator|(
name|void
operator|)
name|x
else|:
operator|(
operator|(
name|void
operator|)
name|y5
operator|,
operator|(
block|{
return|return;
block|}
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|6
case|:
end_case

begin_expr_stmt
literal|1
condition|?
operator|(
operator|(
name|void
operator|)
name|y6
operator|,
operator|(
block|{
return|return;
block|}
end_expr_stmt

begin_expr_stmt
unit|)) :
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|7
case|:
end_case

begin_expr_stmt
call|(
name|void
call|)
argument_list|(
literal|0
operator|&&
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|y7
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
operator|(
literal|0
operator|||
operator|(
name|y8
operator|,
operator|(
block|{
return|return;
block|}
end_expr_stmt

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
literal|1
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|8
case|:
end_case

begin_expr_stmt
operator|(
name|void
operator|)
operator|(
literal|1
operator|&&
operator|(
name|y9
operator|,
operator|(
block|{
return|return;
block|}
end_expr_stmt

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
literal|1
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|9
case|:
end_case

begin_expr_stmt
call|(
name|void
call|)
argument_list|(
literal|1
operator|||
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|y10
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|10
case|:
end_case

begin_while
while|while
condition|(
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_while

begin_expr_stmt
operator|(
name|void
operator|)
name|y11
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|11
case|:
end_case

begin_while
while|while
condition|(
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|y12
expr_stmt|;
block|}
end_while

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|12
case|:
end_case

begin_do
do|do
block|{
operator|(
name|void
operator|)
name|y13
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
end_do

begin_expr_stmt
operator|(
name|void
operator|)
name|y14
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|13
case|:
end_case

begin_do
do|do
block|{
operator|(
name|void
operator|)
name|y15
expr_stmt|;
block|}
do|while
condition|(
literal|1
condition|)
do|;
end_do

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|14
case|:
end_case

begin_for
for|for
control|(
init|;
condition|;
control|)
block|{
operator|(
name|void
operator|)
name|y16
expr_stmt|;
block|}
end_for

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|15
case|:
end_case

begin_for
for|for
control|(
init|;
literal|1
condition|;
control|)
block|{
operator|(
name|void
operator|)
name|y17
expr_stmt|;
block|}
end_for

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|16
case|:
end_case

begin_for
for|for
control|(
init|;
literal|0
condition|;
control|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_for

begin_expr_stmt
operator|(
name|void
operator|)
name|y18
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|17
case|:
end_case

begin_macro
name|__builtin_choose_expr
argument_list|(
literal|0
argument_list|,
argument|(void)x
argument_list|,
argument|((void)y19, ({ return; }))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

begin_case
case|case
literal|19
case|:
end_case

begin_macro
name|__builtin_choose_expr
argument_list|(
literal|1
argument_list|,
argument|((void)y20, ({ return; }))
argument_list|,
argument|(void)x
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|x
expr_stmt|;
end_expr_stmt

begin_break
break|break;
end_break

unit|} }
end_unit

