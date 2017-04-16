begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -Wunused-variable -analyzer-checker=core,deadcode.DeadStores -fblocks -verify -Wno-unreachable-code -analyzer-opt-analyze-nested-blocks %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -Wunused-variable -analyzer-checker=core,deadcode.DeadStores -analyzer-store=region -fblocks -verify -Wno-unreachable-code -analyzer-opt-analyze-nested-blocks %s
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
comment|// expected-warning{{unused variable 'k'}} expected-warning{{unused variable 'y'}}
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
comment|// expected-warning {{never read}} expected-warning{{unused variable 'idx'}}
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
comment|// expected-warning {{never read}} expected-warning{{unused variable 'd'}}
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function 'printf' with type 'int (const char *, ...)'}} \
comment|// expected-note{{include the header<stdio.h> or explicitly provide a declaration for 'printf'}}
block|}
end_function

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

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
comment|// expected-warning{{never read}} expected-warning{{unused variable 'p'}}
block|}
end_function

begin_comment
comment|//
end_comment

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
comment|// no-warning
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
name|f7b
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// This is allowed for defensive programming.
name|p
operator|=
operator|(
literal|0
operator|)
expr_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|f7c
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// This is allowed for defensive programming.
name|p
operator|=
operator|(
name|void
operator|*
operator|)
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
name|f7d
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// This is allowed for defensive programming.
name|p
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
literal|0
operator|)
expr_stmt|;
comment|// no-warning
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// Don't warn for dead stores in nested expressions.  We have yet
end_comment

begin_comment
comment|// to see a real bug in this scenario.
end_comment

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
comment|// no-warning
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
comment|// expected-warning{{unused variable 'x'}}
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

begin_function
name|int
name|f12c
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// Allow initialiation of scalar variables by parameters as a form of
comment|// defensive programming.
name|int
name|x
init|=
name|y
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
comment|// expected-warning{{unused variable 'z'}}
block|}
end_function

begin_comment
comment|// Don't warn for dead stores in nested expressions.  We have yet
end_comment

begin_comment
comment|// to see a real bug in this scenario.
end_comment

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
comment|// unreachable.
do|do
name|x
operator|=
literal|10
expr_stmt|;
comment|// no-warning
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
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f18_a
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|// no-warning
return|return
operator|(
name|x
operator|=
literal|10
operator|)
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f18_b
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
block|}
end_function

begin_function
name|void
name|f18_c
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|1
condition|)
name|x
operator|=
literal|10
expr_stmt|;
comment|// expected-warning{{Value stored to 'x' is never read}}
block|}
end_function

begin_function
name|void
name|f18_d
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
comment|// no-warning
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
name|x
operator|=
name|x
operator|+
literal|1
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
name|x
operator|=
name|x
operator|+
literal|1
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

begin_comment
comment|// expected-warning {{expression result unused}}
end_comment

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

begin_comment
comment|// expected-warning {{expression result unused}}
end_comment

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

begin_function_decl
unit|} }
name|void
name|f23_aux
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f23
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|shouldLog
init|=
operator|(
name|argc
operator|>
literal|1
operator|)
decl_stmt|;
comment|// no-warning
lambda|^
block|{
if|if
condition|(
name|shouldLog
condition|)
name|f23_aux
argument_list|(
literal|"I did too use it!\n"
argument_list|)
expr_stmt|;
else|else
name|f23_aux
argument_list|(
literal|"I shouldn't log.  Wait.. d'oh!\n"
argument_list|)
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f23_pos
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|shouldLog
init|=
operator|(
name|argc
operator|>
literal|1
operator|)
decl_stmt|;
comment|// expected-warning{{Value stored to 'shouldLog' during its initialization is never read}} expected-warning{{unused variable 'shouldLog'}}
lambda|^
block|{
name|f23_aux
argument_list|(
literal|"I did too use it!\n"
argument_list|)
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f24_A
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// FIXME: One day this should be reported as dead since 'z = x + y' is dead.
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
comment|// no-warning
lambda|^
block|{
name|int
name|z
init|=
name|x
operator|+
name|y
decl_stmt|;
comment|// expected-warning{{Value stored to 'z' during its initialization is never read}} expected-warning{{unused variable 'z'}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f24_B
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// FIXME: One day this should be reported as dead since 'x' is just overwritten.
specifier|__block
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
comment|// no-warning
lambda|^
block|{
comment|// FIXME: This should eventually be a dead store since it is never read either.
name|x
operator|=
literal|5
expr_stmt|;
comment|// no-warning
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|f24_C
parameter_list|(
name|int
name|y
parameter_list|)
block|{
comment|// FIXME: One day this should be reported as dead since 'x' is just overwritten.
specifier|__block
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
comment|// no-warning
lambda|^
block|{
name|x
operator|=
literal|5
expr_stmt|;
comment|// no-warning
block|}
argument_list|()
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|f24_D
parameter_list|(
name|int
name|y
parameter_list|)
block|{
specifier|__block
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
comment|// no-warning
lambda|^
block|{
if|if
condition|(
name|y
operator|>
literal|4
condition|)
name|x
operator|=
literal|5
expr_stmt|;
comment|// no-warning
block|}
argument_list|()
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// This example shows that writing to a variable captured by a block means that it might
end_comment

begin_comment
comment|// not be dead.
end_comment

begin_function
name|int
name|f25
parameter_list|(
name|int
name|y
parameter_list|)
block|{
specifier|__block
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
specifier|__block
name|int
name|z
init|=
literal|0
decl_stmt|;
name|void
function_decl|(
modifier|^
name|foo
function_decl|)
parameter_list|()
init|=
lambda|^
block|{
name|z
operator|=
name|x
operator|+
name|y
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|x
operator|=
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// no-warning
end_comment

begin_expr_stmt
name|foo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|z
return|;
end_return

begin_comment
unit|}
comment|// This test is mostly the same as 'f25', but shows that the heuristic of pruning out dead
end_comment

begin_comment
comment|// stores for variables that are just marked '__block' is overly conservative.
end_comment

begin_macro
unit|int
name|f25_b
argument_list|(
argument|int y
argument_list|)
end_macro

begin_block
block|{
comment|// FIXME: we should eventually report a dead store here.
specifier|__block
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
specifier|__block
name|int
name|z
init|=
literal|0
decl_stmt|;
name|x
operator|=
literal|4
expr_stmt|;
comment|// no-warning
return|return
name|z
return|;
block|}
end_block

begin_function
name|int
name|f26_nestedblocks
parameter_list|()
block|{
name|int
name|z
decl_stmt|;
name|z
operator|=
literal|1
expr_stmt|;
specifier|__block
name|int
name|y
init|=
literal|0
decl_stmt|;
lambda|^
block|{
name|int
name|k
decl_stmt|;
name|k
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Value stored to 'k' is never read}}
lambda|^
block|{
name|y
operator|=
name|z
operator|+
literal|1
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// The FOREACH macro in QT uses 'break' statements within statement expressions
end_comment

begin_comment
comment|// placed within the increment code of for loops.
end_comment

begin_function
name|void
name|rdar8014335
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
literal|10
condition|;
operator|(
block|{
break|break;
block|}
control|)
block|)
block|{
for|for
control|(
init|;
condition|;
operator|(
block|{
operator|++
name|i
block|;
break|break;
block|}
control|)
block|)
function|;
end_function

begin_comment
comment|// expected-warning {{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_comment
comment|// Note that the next value stored to 'i' is never executed
end_comment

begin_comment
comment|// because the next statement to be executed is the 'break'
end_comment

begin_comment
comment|// in the increment code of the first loop.
end_comment

begin_expr_stmt
name|i
operator|=
name|i
operator|*
literal|3
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning{{Value stored to 'i' is never read}}
end_comment

begin_comment
unit|} }
comment|//<rdar://problem/8320674> NullStmts followed by do...while() can lead to disconnected CFG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This previously caused bogus dead-stores warnings because the body of the first do...while was
end_comment

begin_comment
comment|// disconnected from the entry of the function.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|r
decl_stmt|;
name|float
name|i
decl_stmt|;
block|}
name|s_rdar8320674
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|s_rdar8320674
name|x
index|[
literal|1
index|]
decl_stmt|;
block|}
name|s2_rdar8320674
typedef|;
end_typedef

begin_function
name|void
name|rdar8320674
parameter_list|(
name|s_rdar8320674
modifier|*
name|z
parameter_list|,
name|unsigned
name|y
parameter_list|,
name|s2_rdar8320674
modifier|*
name|st
parameter_list|,
name|int
name|m
parameter_list|)
block|{
name|s_rdar8320674
modifier|*
name|z2
decl_stmt|;
name|s_rdar8320674
modifier|*
name|tw1
init|=
name|st
operator|->
name|x
decl_stmt|;
name|s_rdar8320674
name|t
decl_stmt|;
name|z2
operator|=
name|z
operator|+
name|m
expr_stmt|;
do|do
block|{
empty_stmt|;
empty_stmt|;
do|do
block|{
operator|(
name|t
operator|)
operator|.
name|r
operator|=
operator|(
operator|*
name|z2
operator|)
operator|.
name|r
operator|*
operator|(
operator|*
name|tw1
operator|)
operator|.
name|r
operator|-
operator|(
operator|*
name|z2
operator|)
operator|.
name|i
operator|*
operator|(
operator|*
name|tw1
operator|)
operator|.
name|i
expr_stmt|;
operator|(
name|t
operator|)
operator|.
name|i
operator|=
operator|(
operator|*
name|z2
operator|)
operator|.
name|r
operator|*
operator|(
operator|*
name|tw1
operator|)
operator|.
name|i
operator|+
operator|(
operator|*
name|z2
operator|)
operator|.
name|i
operator|*
operator|(
operator|*
name|tw1
operator|)
operator|.
name|r
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
name|tw1
operator|+=
name|y
expr_stmt|;
do|do
block|{
operator|(
operator|*
name|z2
operator|)
operator|.
name|r
operator|=
operator|(
operator|*
name|z
operator|)
operator|.
name|r
operator|-
operator|(
name|t
operator|)
operator|.
name|r
expr_stmt|;
operator|(
operator|*
name|z2
operator|)
operator|.
name|i
operator|=
operator|(
operator|*
name|z
operator|)
operator|.
name|i
operator|-
operator|(
name|t
operator|)
operator|.
name|i
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
do|do
block|{
operator|(
operator|*
name|z
operator|)
operator|.
name|r
operator|+=
operator|(
name|t
operator|)
operator|.
name|r
expr_stmt|;
operator|(
operator|*
name|z
operator|)
operator|.
name|i
operator|+=
operator|(
name|t
operator|)
operator|.
name|i
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
operator|++
name|z2
expr_stmt|;
operator|++
name|z
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|m
condition|)
do|;
block|}
end_function

begin_comment
comment|// Avoid dead stores resulting from an assignment (and use) being unreachable.
end_comment

begin_function_decl
name|void
name|rdar8405222_aux
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|rdar8405222
parameter_list|()
block|{
specifier|const
name|int
name|show
init|=
literal|0
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|show
condition|)
name|i
operator|=
literal|5
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|show
condition|)
name|rdar8405222_aux
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Look through chains of assignements, e.g.: int x = y = 0, when employing
end_comment

begin_comment
comment|// silencing heuristics.
end_comment

begin_function
name|int
name|radar11185138_foo
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|x
operator|=
name|y
operator|=
literal|0
expr_stmt|;
comment|// expected-warning {{never read}}
return|return
name|y
return|;
block|}
end_function

begin_function
name|int
name|rdar11185138_bar
parameter_list|()
block|{
name|int
name|y
decl_stmt|;
name|int
name|x
init|=
name|y
operator|=
literal|0
decl_stmt|;
comment|// no-warning
name|x
operator|=
literal|2
expr_stmt|;
name|y
operator|=
literal|2
expr_stmt|;
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|radar11185138_baz
parameter_list|()
block|{
name|int
modifier|*
name|x
decl_stmt|,
modifier|*
name|y
decl_stmt|;
name|x
operator|=
name|y
operator|=
literal|0
expr_stmt|;
comment|// no-warning
return|return
name|y
return|;
block|}
end_function

begin_function_decl
name|int
name|getInt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|getPtr
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|testBOComma
parameter_list|()
block|{
name|int
name|x0
init|=
operator|(
name|getInt
argument_list|()
expr|,
literal|0
operator|)
decl_stmt|;
comment|// expected-warning{{unused variable 'x0'}}
name|int
name|x1
init|=
operator|(
name|getInt
argument_list|()
expr|,
name|getInt
argument_list|()
operator|)
decl_stmt|;
comment|// expected-warning {{Value stored to 'x1' during its initialization is never read}} // expected-warning{{unused variable 'x1'}}
name|int
name|x2
init|=
operator|(
name|getInt
argument_list|()
expr|,
name|getInt
argument_list|()
expr|,
name|getInt
argument_list|()
operator|)
decl_stmt|;
comment|//expected-warning{{Value stored to 'x2' during its initialization is never read}} // expected-warning{{unused variable 'x2'}}
name|int
name|x3
decl_stmt|;
name|x3
operator|=
operator|(
name|getInt
argument_list|()
operator|,
name|getInt
argument_list|()
operator|,
literal|0
operator|)
expr_stmt|;
comment|// expected-warning{{Value stored to 'x3' is never read}}
name|int
name|x4
init|=
operator|(
name|getInt
argument_list|()
expr|,
operator|(
name|getInt
argument_list|()
expr|,
literal|0
operator|)
operator|)
decl_stmt|;
comment|// expected-warning{{unused variable 'x4'}}
name|int
name|y
decl_stmt|;
name|int
name|x5
init|=
operator|(
name|getInt
argument_list|()
expr|,
operator|(
name|y
operator|=
literal|0
operator|)
operator|)
decl_stmt|;
comment|// expected-warning{{unused variable 'x5'}}
name|int
name|x6
init|=
operator|(
name|getInt
argument_list|()
expr|,
operator|(
name|y
operator|=
name|getInt
argument_list|()
operator|)
operator|)
decl_stmt|;
comment|//expected-warning {{Value stored to 'x6' during its initialization is never read}} // expected-warning{{unused variable 'x6'}}
name|int
name|x7
init|=
literal|0
decl_stmt|,
name|x8
init|=
name|getInt
argument_list|()
decl_stmt|;
comment|//expected-warning {{Value stored to 'x8' during its initialization is never read}} // expected-warning{{unused variable 'x8'}} // expected-warning{{unused variable 'x7'}}
name|int
name|x9
init|=
name|getInt
argument_list|()
decl_stmt|,
name|x10
init|=
literal|0
decl_stmt|;
comment|//expected-warning {{Value stored to 'x9' during its initialization is never read}} // expected-warning{{unused variable 'x9'}}  // expected-warning{{unused variable 'x10'}}
name|int
name|m
init|=
name|getInt
argument_list|()
decl_stmt|,
name|mm
decl_stmt|,
name|mmm
decl_stmt|;
comment|//expected-warning {{Value stored to 'm' during its initialization is never read}} // expected-warning{{unused variable 'm'}} // expected-warning{{unused variable 'mm'}} // expected-warning{{unused variable 'mmm'}}
name|int
name|n
decl_stmt|,
name|nn
init|=
name|getInt
argument_list|()
decl_stmt|;
comment|//expected-warning {{Value stored to 'nn' during its initialization is never read}} // expected-warning{{unused variable 'n'}} // expected-warning{{unused variable 'nn'}}
name|int
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|(
name|getPtr
argument_list|()
operator|,
operator|(
name|int
operator|*
operator|)
literal|0
operator|)
expr_stmt|;
comment|// no warning
block|}
end_function

begin_function
name|void
name|testVolatile
parameter_list|()
block|{
specifier|volatile
name|int
name|v
decl_stmt|;
name|v
operator|=
literal|0
expr_stmt|;
comment|// no warning
block|}
end_function

end_unit

