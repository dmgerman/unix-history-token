begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -x c++ -Werror %s
end_comment

begin_function
name|int
name|pr8880_1
parameter_list|()
block|{
name|int
name|first
init|=
literal|1
decl_stmt|;
for|for
control|(
init|;
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
literal|0
expr|;
control|}
block|)
function|;
end_function

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
literal|1
return|;
end_return

begin_macro
unit|}  void
name|pr8880_2
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
break|break;
block|}
literal|0
expr|;
control|}
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_block
unit|)
block|{}
end_block

begin_macro
unit|}  void
name|pr8880_3
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
condition|;
operator|(
name|void
operator|)
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
literal|0
expr|;
control|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_macro
unit|}  void
name|pr8880_4
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
condition|;
operator|(
name|void
operator|)
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
break|break;
block|}
literal|0
expr|;
control|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_macro
unit|}  void
name|pr8880_5
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
literal|0
expr_stmt|;
block|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_macro
unit|}  void
name|pr8880_6
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
break|break;
block|}
literal|0
expr_stmt|;
block|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_macro
unit|}  void
name|pr8880_7
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
do|do
block|{}
do|while
condition|(
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
literal|0
expr_stmt|;
block|}
block|)
end_block

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_macro
unit|}  void
name|pr8880_8
argument_list|(
argument|int first
argument_list|)
end_macro

begin_block
block|{
do|do
block|{}
do|while
condition|(
operator|(
block|{
if|if
condition|(
name|first
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
break|break;
block|}
literal|0
expr_stmt|;
block|}
block|)
end_block

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_macro
unit|}  void
name|pr8880_10
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
for|for
control|(
init|;
condition|;
operator|(
name|void
operator|)
operator|(
block|{
operator|++
name|i
block|;
continue|continue;
name|i
expr|;
control|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'continue' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_11
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
for|for
control|(
init|;
condition|;
operator|(
name|void
operator|)
operator|(
block|{
operator|++
name|i
block|;
break|break;
name|i
expr|;
control|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_12
argument_list|(
argument|int i
argument_list|,
argument|int j
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
for|for
control|(
init|;
operator|(
block|{
if|if
condition|(
name|i
condition|)
continue|continue;
name|i
expr|;
control|}
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|j
operator|++
end_expr_stmt

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning {{'continue' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_13
argument_list|(
argument|int i
argument_list|,
argument|int j
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
for|for
control|(
init|;
operator|(
block|{
if|if
condition|(
name|i
condition|)
break|break;
name|i
expr|;
control|}
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|j
operator|++
end_expr_stmt

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_14
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
while|while
condition|(
operator|(
block|{
if|if
condition|(
name|i
condition|)
break|break;
name|i
expr_stmt|;
block|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning {{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_15
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
operator|--
name|i
condition|)
while|while
condition|(
operator|(
block|{
if|if
condition|(
name|i
condition|)
continue|continue;
name|i
expr_stmt|;
block|}
block|)
end_block

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning {{'continue' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_16
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
do|do
block|{}
do|while
condition|(
operator|(
block|{
if|if
condition|(
name|i
condition|)
break|break;
name|i
expr_stmt|;
block|}
block|)
end_block

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_17
argument_list|(
argument|int i
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
do|do
block|{}
do|while
condition|(
operator|(
block|{
if|if
condition|(
name|i
condition|)
continue|continue;
name|i
expr_stmt|;
block|}
block|)
end_block

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'continue' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_macro
unit|}  void
name|pr8880_18
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
name|x
operator|>
literal|0
condition|)
switch|switch
condition|(
operator|(
block|{
if|if
condition|(
name|y
condition|)
break|break;
name|y
expr_stmt|;
block|}
block|)
end_block

begin_block
unit|)
block|{
case|case
literal|2
case|:
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
unit|}  void
name|pr8880_19
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
end_macro

begin_block
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
switch|switch
condition|(
operator|(
block|{
if|if
condition|(
name|y
condition|)
break|break;
name|y
expr_stmt|;
block|}
block|)
block|)
end_block

begin_block
block|{
case|case
literal|2
case|:
name|x
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_function
unit|} }
name|void
name|pr8880_20
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
while|while
condition|(
operator|(
block|{
if|if
condition|(
name|y
condition|)
break|break;
name|y
expr_stmt|;
block|}
block|)
block|)
block|{}
end_function

begin_comment
comment|//expected-warning {{'break' is bound to loop, GCC binds it to switch}}
end_comment

begin_function
unit|} }
name|void
name|pr8880_21
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
do|do
block|{}
do|while
condition|(
operator|(
block|{
if|if
condition|(
name|y
condition|)
break|break;
name|y
expr_stmt|;
block|}
block|)
block|)
function|;
end_function

begin_comment
comment|//expected-warning {{'break' is bound to loop, GCC binds it to switch}}
end_comment

begin_function
unit|} }
name|void
name|pr8880_22
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
condition|;
operator|(
name|void
operator|)
operator|(
block|{
operator|++
name|y
block|;
break|break;
name|y
expr|;
control|}
block|)
block|)
block|{}
end_function

begin_comment
comment|// expected-warning{{'break' is bound to loop, GCC binds it to switc}}
end_comment

begin_function
unit|} }
name|void
name|pr8880_23
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
break|break;
name|y
expr|;
control|}
block|)
empty_stmt|;
operator|++
name|y
block|)
block|{}
end_function

begin_comment
comment|// expected-warning{{'break' is bound to loop, GCC binds it to switch}}
end_comment

begin_function
unit|} }
name|void
name|pr32648_1
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
switch|switch
condition|(
name|y
condition|)
block|{
case|case
literal|0
case|:
break|break;
block|}
name|y
expr|;
control|}
block|)
empty_stmt|;
operator|++
name|y
block|)
block|{}
end_function

begin_comment
comment|// no warning
end_comment

begin_function
unit|} }
name|void
name|pr32648_2
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
while|while
condition|(
name|x
condition|)
block|{
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
switch|switch
condition|(
name|y
condition|)
block|{
case|case
literal|0
case|:
continue|continue;
block|}
name|y
expr|;
control|}
block|)
empty_stmt|;
operator|++
name|y
block|)
block|{}
end_function

begin_comment
comment|// expected-warning {{'continue' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_function
unit|} }
name|void
name|pr32648_3
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
for|for
control|(
init|;
name|y
condition|;
name|y
operator|++
control|)
block|{
break|break;
block|}
name|y
expr|;
control|}
block|)
empty_stmt|;
operator|++
name|y
block|)
block|{}
end_function

begin_comment
comment|// no warning
end_comment

begin_function
unit|} }
name|void
name|pr32648_4
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
for|for
control|(
operator|(
block|{
break|break;
block|}
operator|)
condition|;
name|y
incr|;
control|y++)
block|{ }
name|y
expr_stmt|;
block|}
block|)
function|;
end_function

begin_expr_stmt
operator|++
name|y
end_expr_stmt

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'break' is bound to loop, GCC binds it to switch}}
end_comment

begin_function
unit|} }
name|void
name|pr32648_5
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
while|while
condition|(
operator|(
block|{
break|break;
name|y
expr_stmt|;
block|}
operator|)
control|)
block|{}
name|y
expr_stmt|;
block|}
block|)
function|;
end_function

begin_expr_stmt
operator|++
name|y
end_expr_stmt

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_function
unit|} }
name|void
name|pr32648_6
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
do|do
block|{
block|}
while|while
condition|(
operator|(
block|{
break|break;
name|y
expr_stmt|;
block|}
control|)
block|)
empty_stmt|;
name|y
expr_stmt|;
block|}
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|++
name|y
end_expr_stmt

begin_block
unit|)
block|{}
end_block

begin_comment
comment|// expected-warning{{'break' is bound to current loop, GCC binds it to the enclosing loop}}
end_comment

begin_function
unit|} }
name|void
name|pr32648_7
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
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
for|for
control|(
init|;
operator|(
block|{
operator|++
name|y
block|;
do|do
block|{
break|break;
block|}
while|while
condition|(
name|y
condition|)
empty_stmt|;
name|y
incr|;
control|}
block|)
empty_stmt|;
operator|++
name|y
block|)
block|{}
end_function

begin_comment
comment|// no warning
end_comment

unit|} }
end_unit

