begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// PR7477
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|E
block|{
name|Ea
operator|,
name|Eb
operator|,
name|Ec
operator|,
name|Ed
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_E
parameter_list|(
name|enum
name|E
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
condition|)
block|{
case|case
name|Ea
case|:
case|case
name|Eb
case|:
case|case
name|Ec
case|:
case|case
name|Ed
case|:
break|break;
block|}
block|}
end_function

end_unit

