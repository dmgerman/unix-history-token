begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|z
parameter_list|)
block|{
while|while
condition|(
name|z
condition|)
block|{
default|default:
name|z
operator|--
expr_stmt|;
comment|// expected-error {{statement not in switch}}
block|}
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|X
parameter_list|)
block|{
switch|switch
condition|(
name|X
condition|)
block|{
case|case
literal|42
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|5000000000LL
case|:
comment|// expected-warning {{overflow}}
case|case
literal|42
case|:
comment|// expected-error {{duplicate case value}}
empty_stmt|;
case|case
literal|100
operator|...
literal|99
case|:
empty_stmt|;
comment|// expected-warning {{empty case range}}
case|case
literal|43
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|43
operator|...
literal|45
case|:
empty_stmt|;
comment|// expected-error {{duplicate case value}}
case|case
literal|100
operator|...
literal|20000
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|15000
operator|...
literal|40000000
case|:
empty_stmt|;
comment|// expected-error {{duplicate case value}}
block|}
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// empty switch;
switch|switch
condition|(
literal|0
condition|)
empty_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test4
parameter_list|()
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|0
operator|&&
name|g
argument_list|()
case|:
case|case
literal|1
operator|||
name|g
argument_list|()
case|:
break|break;
block|}
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
name|g
argument_list|()
case|:
comment|// expected-error {{expression is not an integer constant expression}}
case|case
literal|0
operator|...
name|g
argument_list|()
case|:
comment|// expected-error {{expression is not an integer constant expression}}
break|break;
block|}
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|0
operator|&&
name|g
argument_list|()
operator|...
literal|1
operator|||
name|g
argument_list|()
case|:
break|break;
block|}
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
name|g
argument_list|()
operator|&&
literal|0
case|:
comment|// expected-error {{expression is not an integer constant expression}} // expected-note {{subexpression not valid in an integer constant expression}}
break|break;
block|}
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|0
operator|...
name|g
argument_list|()
operator|||
literal|1
case|:
comment|// expected-error {{expression is not an integer constant expression}} // expected-note {{subexpression not valid in an integer constant expression}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test5
parameter_list|(
name|int
name|z
parameter_list|)
block|{
switch|switch
condition|(
name|z
condition|)
block|{
default|default:
comment|// expected-note {{previous case defined here}}
default|default:
comment|// expected-error {{multiple default labels in one switch}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
specifier|const
name|char
name|ch
init|=
literal|'a'
decl_stmt|;
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|1234
case|:
comment|// expected-warning {{overflow converting case value}}
break|break;
block|}
block|}
end_function

begin_comment
comment|// PR5606
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
name|var
parameter_list|)
block|{
switch|switch
condition|(
name|va
condition|)
block|{
comment|// expected-error{{use of undeclared identifier 'va'}}
case|case
literal|1
case|:
break|break;
case|case
literal|2
case|:
return|return
literal|1
return|;
block|}
return|return
literal|2
return|;
block|}
end_function

end_unit

