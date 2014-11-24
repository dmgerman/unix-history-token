begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only -verify %s */
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
break|break;
comment|/* expected-error {{'break' statement not in loop or switch statement}} */
block|}
end_function

begin_function
name|void
name|foo2
parameter_list|()
block|{
continue|continue;
comment|/* expected-error {{'continue' statement not in loop statement}} */
block|}
end_function

begin_function
name|int
name|pr8880_9
parameter_list|(
name|int
name|first
parameter_list|)
block|{
switch|switch
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
literal|1
expr_stmt|;
block|}
block|)
end_function

begin_block
unit|)
block|{
comment|// expected-error {{'break' statement not in loop or switch statement}}
case|case
literal|2
case|:
return|return
literal|2
return|;
default|default:
return|return
literal|0
return|;
block|}
end_block

begin_macro
unit|}  void
name|pr8880_24
argument_list|()
end_macro

begin_block
block|{
for|for
control|(
operator|(
block|{
break|break;
block|}
control|)
empty_stmt|;
empty_stmt|;
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'break' statement not in loop or switch statement}}
end_comment

begin_macro
unit|}  void
name|pr8880_25
argument_list|()
end_macro

begin_block
block|{
for|for
control|(
operator|(
block|{
continue|continue;
block|}
control|)
empty_stmt|;
empty_stmt|;
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'continue' statement not in loop statement}}
end_comment

unit|}
end_unit

